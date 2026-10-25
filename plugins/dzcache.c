/*
 * dzcache: Cortex-A9 + PL310 cache and timing model for the Deluge, as a QEMU TCG plugin.
 *
 * Cache model. Simulates L1 I/D (32 KiB, 4-way, pseudo-random replacement) and the PL310 L2 (128 KiB, 8-way,
 * round-robin) from the guest's instruction fetches and data accesses, with the A9 L1 stride prefetcher and PL310
 * next-line prefetch optional. Cacheability comes from the firmware's own first-level translation table, read live
 * (so runtime remaps such as L2CacheMapRangeInnerOnly() are followed), and the firmware's cache maintenance is
 * applied: CP15 c7 by MVA and set/way (L1) and the PL310 maintenance, enable and lockdown registers (L2). DMA is
 * invisible to plugins, but the firmware invalidates around every DMA read.
 *
 * Time model (timectl=1, without -icount; needs qemu-patches/0007). The guest clock follows modelled CPU cycles at
 * hz rather than the host clock: cycles = cpi * instructions + pi * L1I misses + pd * L1D misses (cachesim=1), or
 * cpi * instructions (cachesim=0, much faster). A flat cpi=1.45 reproduces a Deluge playing a CPU-bound song (render
 * load, culling, voices); see tools/perf/README.md. The clock is frozen while the vCPU is halted (WFE/WFI), so
 * firmware that idles in WFE (the Rust/Embassy BSP) needs -icount instead.
 *
 * Reports. SLICE lines every `slice` instructions (counts, render instructions/frames, cycles); a MARK line whenever
 * `mark` executes; an R line per call of `render` (the audio routine) with frames from `timer`
 * (AudioEngine::audioSampleTimer); inclusive SCOPE totals for up to six functions (s0..s5) once `warm` instructions
 * past the first mark; and at exit the instructions causing the most misses (INSN) and a data-miss map (HEAT).
 *
 * Args: ttb l2c mark slice phasea render timer|head fn0..fn3=lo-hi s0..s5 warm itrace itskip itlen
 *       l1size l1assoc l2size l2assoc line l1repl l2repl (0 LRU, 1 random, 2 round-robin)
 *       pfstreams pfdist l2pf timectl lean cachesim cpi pi pd pdev pnc hz quantum
 * Build: scripts/build-plugins.sh
 */
#include <glib.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <qemu-plugin.h>

QEMU_PLUGIN_EXPORT int qemu_plugin_version = QEMU_PLUGIN_VERSION;

/* ---- cache ---- */

typedef struct {
    int sets, assoc, line_bits;
    uint32_t *tag;
    uint8_t *valid, *dirty;
    uint64_t *stamp;
    uint64_t clock;
    uint32_t alloc_mask; /* ways allowed to allocate (lockdown) */
    int repl;            /* REPL_* */
    uint8_t *rr;         /* round-robin pointer per set */
    uint32_t lfsr;
} Cache;

enum { REPL_LRU, REPL_RANDOM, REPL_RR };

static Cache *cache_new(int size, int assoc, int line)
{
    Cache *c = g_new0(Cache, 1);
    int n;

    c->assoc = assoc;
    c->line_bits = __builtin_ctz(line);
    c->sets = size / (assoc * line);
    n = c->sets * assoc;
    c->tag = g_new0(uint32_t, n);
    c->valid = g_new0(uint8_t, n);
    c->dirty = g_new0(uint8_t, n);
    c->stamp = g_new0(uint64_t, n);
    c->alloc_mask = (1u << assoc) - 1;
    c->rr = g_new0(uint8_t, c->sets);
    c->lfsr = 0xACE1u;
    return c;
}

static inline int cache_set(Cache *c, uint32_t addr)
{
    return (addr >> c->line_bits) & (c->sets - 1);
}

static inline uint32_t cache_tag(Cache *c, uint32_t addr)
{
    return addr >> c->line_bits; /* full line address: simple and exact */
}

/* Returns the way holding addr, or -1. */
static int cache_find(Cache *c, uint32_t addr)
{
    int base = cache_set(c, addr) * c->assoc;
    uint32_t t = cache_tag(c, addr);

    for (int w = 0; w < c->assoc; w++) {
        if (c->valid[base + w] && c->tag[base + w] == t) {
            return w;
        }
    }
    return -1;
}

/*
 * Look up addr; on a miss allocate if `allocate`. Returns 1 for a hit. If a
 * dirty line is evicted, *evicted gets its address and the return has bit 1.
 */
static int cache_access(Cache *c, uint32_t addr, bool write, bool allocate, uint32_t *evicted)
{
    int base = cache_set(c, addr) * c->assoc;
    int w = cache_find(c, addr);
    int victim = -1;
    uint64_t oldest = UINT64_MAX;

    c->clock++;
    if (w >= 0) {
        c->stamp[base + w] = c->clock;
        if (write) {
            c->dirty[base + w] = 1;
        }
        return 1;
    }
    if (!allocate) {
        return 0;
    }
    for (int i = 0; i < c->assoc; i++) {
        if ((c->alloc_mask & (1u << i)) && !c->valid[base + i]) {
            victim = i; /* an empty way first, whatever the policy */
            break;
        }
    }
    if (victim < 0 && c->alloc_mask) {
        if (c->repl == REPL_LRU) {
            for (int i = 0; i < c->assoc; i++) {
                if ((c->alloc_mask & (1u << i)) && c->stamp[base + i] < oldest) {
                    oldest = c->stamp[base + i];
                    victim = i;
                }
            }
        } else {
            int set = base / c->assoc;
            do {
                if (c->repl == REPL_RANDOM) {
                    c->lfsr = (c->lfsr >> 1) ^ (-(c->lfsr & 1u) & 0xB400u); /* 16-bit Galois LFSR */
                    victim = c->lfsr % c->assoc;
                } else {
                    victim = c->rr[set];
                    c->rr[set] = (c->rr[set] + 1) % c->assoc;
                }
            } while (!(c->alloc_mask & (1u << victim)));
        }
    }
    if (victim < 0) {
        return 0; /* every way locked */
    }
    int ret = 0;
    int i = base + victim;
    if (c->valid[i] && c->dirty[i]) {
        *evicted = c->tag[i] << c->line_bits;
        ret = 2;
    }
    c->tag[i] = cache_tag(c, addr);
    c->valid[i] = 1;
    c->dirty[i] = write;
    c->stamp[i] = c->clock;
    return ret;
}

/* Clean and/or invalidate the line holding addr. Returns 1 if it was dirty. */
static int cache_maint_addr(Cache *c, uint32_t addr, bool clean, bool inval)
{
    int w = cache_find(c, addr);
    int i, was_dirty;

    if (w < 0) {
        return 0;
    }
    i = cache_set(c, addr) * c->assoc + w;
    was_dirty = c->dirty[i];
    if (clean) {
        c->dirty[i] = 0;
    }
    if (inval) {
        c->valid[i] = 0;
        c->dirty[i] = 0;
    }
    return clean && was_dirty;
}

static int cache_maint_line(Cache *c, int set, int way, bool clean, bool inval)
{
    int i = set * c->assoc + way;
    int was_dirty = c->valid[i] && c->dirty[i];

    if (clean) {
        c->dirty[i] = 0;
    }
    if (inval) {
        c->valid[i] = 0;
        c->dirty[i] = 0;
    }
    return clean && was_dirty;
}

/* ---- state ---- */

enum { ATTR_SO, ATTR_DEV, ATTR_NC, ATTR_CACHE };

typedef struct {
    uint8_t type;      /* ATTR_* */
    bool inner;        /* L1 cacheable */
    bool inner_wa;     /* L1 write-allocate */
    bool outer;        /* L2 cacheable */
    bool outer_wa;
} Attr;

typedef struct {
    uint64_t insns;
    uint64_t l1i_acc, l1i_miss;
    uint64_t l1d_rd, l1d_wr, l1d_rd_miss, l1d_wr_miss;
    uint64_t l1d_wb;          /* dirty L1 lines written back to L2 / memory */
    uint64_t l2_acc, l2_miss; /* L2 lookups from L1 misses and write-backs */
    uint64_t nc, dev;         /* Normal-uncached, and strongly-ordered/device data accesses */
    uint64_t l1_maint, l2_maint;
} Stats;

typedef struct {
    uint32_t vaddr;
    uint64_t l1d_miss[3], l2_miss[3], nc[3]; /* phase 0 before mark, A, B */
    uint64_t l1i_miss[3];
    uint64_t l2_miss_sdram[3];               /* of l2_miss, data in SDRAM (0x08000000-0x0FFFFFFF) */
} InsnStats;

/* Data misses by 64 KiB block of address space, after the mark. */
static uint64_t heat_l1d[65536], heat_l2[65536];

typedef struct {
    uint32_t vaddr;
    InsnStats *st;
    int maint;        /* 0, or the c7 op: (CRm << 4) | opc2 */
    int rt;
    int range;        /* index into fn[], or -1 */
} Insn;

/* Per audio-routine-call accounting (render=, head=, fnN=). */
#define NFN 4
static uint64_t render_addr, head_addr;
static bool head_is_timer; /* head= is AudioEngine::audioSampleTimer (frames rendered), not the output ring */
static uint64_t render_insns_total, render_frames_total;
static uint32_t fn_lo[NFN], fn_hi[NFN];
static bool in_render;
static uint32_t render_ret, head0;
static Stats render_start;
static uint64_t fn_ins[NFN], fn_l1d[NFN], fn_l2[NFN];
static struct qemu_plugin_register *lr_reg;

/* Inclusive per-function accounting (sN=<addr>): from entry until the return address is reached */
#define NSCOPE 6
static uint32_t scope_addr[NSCOPE], scope_ret[NSCOPE];
static bool scope_active[NSCOPE];
static uint64_t scope_ins0[NSCOPE];
static double scope_cyc0[NSCOPE];
static uint64_t scope_calls[NSCOPE], scope_ins[NSCOPE];
static double scope_cyc[NSCOPE];
static uint64_t warm_insns; /* only count scopes once this many instructions past the mark */

/*
 * Instruction-fetch trace (itrace=<file>): from itskip instructions past the first mark, for itlen instructions, one
 * u32 per change of 32-byte line: the line's address, bit 0 set if it isn't the line after the previous one (a jump).
 * For replaying the L1I stream under other models offline (tools/perf/icache_replay.c).
 */
static FILE *itrace;
static uint64_t itrace_skip, itrace_len = 200000000;
static uint32_t itrace_buf[65536];
static size_t itrace_n;
static uint64_t mark_insns;

static Cache *l1i, *l1d, *l2;

/*
 * Time control (timectl=1, run without -icount): the guest clock follows modelled CPU cycles,
 *   cycles = cpi0 * instructions + pi * L1I misses + pd * L1D demand misses
 * at hz, rather than the host's clock. Defaults are fitted to a Deluge (RZ/A1L, 400 MHz) render: 1.37 cycles per
 * instruction overall, 3.9% of cycles stalled on the I-cache and 11.6% on the D-cache.
 */
static bool timectl;
static const void *time_handle;
/*
 * Defaults fitted to a Deluge: pi/pd from the PMU's I/D-cache stall cycles per render instruction divided by the
 * model's demand misses (not the PMU refill counts, which include fetch-ahead), pdev a typical strongly-ordered
 * access, and cpi the base that makes the emulator cull like the hardware on a CPU-bound song.
 */
static double cpi0 = 1.30, pen_i = 9.0, pen_d = 25.6, hz = 400e6;
static double pen_dev = 60.0, pen_nc = 0.0; /* per strongly-ordered/device access, per Normal uncached access */
static double cycles, cycles_at_update;
static double quantum = 4000; /* cycles between clock updates (10 us at 400 MHz) */
static bool cachesim = true;
static bool l2_enabled;
static uint64_t ttb = 0x20020000, l2c = 0x3FFFF000, mark_addr;
static uint64_t slice = 100000000, phasea = 250;
static Attr attr_cache[4096];
static bool attr_valid[4096];
static Stats tot, last;
static uint64_t next_slice;
static int64_t mark_slice = -1; /* slice index at the first mark */
static uint32_t last_iline = UINT32_MAX;
static GHashTable *insn_stats; /* vaddr -> InsnStats */
static struct qemu_plugin_register *regs[16];
static GByteArray *regbuf;

static int phase_now(void)
{
    uint64_t s = tot.insns / slice;

    if (mark_slice < 0) {
        return 0;
    }
    return (s < (uint64_t)mark_slice + phasea) ? 1 : 2;
}

static Attr decode_section(uint32_t d)
{
    Attr a = { ATTR_NC };
    int tex = (d >> 12) & 7, c = (d >> 3) & 1, b = (d >> 2) & 1;

    if ((d & 3) != 2) {
        return a; /* fault or page table: Deluge uses sections only */
    }
    if (tex & 4) {
        int in = (c << 1) | b, out = tex & 3; /* 00 NC, 01 WBWA, 10 WT, 11 WB */
        a.type = (in || out) ? ATTR_CACHE : ATTR_NC;
        a.inner = in != 0;
        a.inner_wa = in == 1;
        a.outer = out != 0;
        a.outer_wa = out == 1;
        return a;
    }
    switch ((tex << 2) | (c << 1) | b) {
    case 0x0: a.type = ATTR_SO; break;
    case 0x1: a.type = ATTR_DEV; break;
    case 0x2: /* WT */
    case 0x3: /* WB, no write-allocate */
        a.type = ATTR_CACHE; a.inner = a.outer = true; break;
    case 0x4: a.type = ATTR_NC; break;
    case 0x7: a.type = ATTR_CACHE; a.inner = a.outer = a.inner_wa = a.outer_wa = true; break;
    case 0x8: a.type = ATTR_DEV; break;
    default: a.type = ATTR_NC; break;
    }
    return a;
}

static Attr attr_for(uint32_t addr)
{
    int sec = addr >> 20;

    if (!attr_valid[sec]) {
        GByteArray *buf = g_byte_array_sized_new(4);
        uint32_t d = 0;

        g_byte_array_set_size(buf, 4);
        if (qemu_plugin_read_memory_hwaddr(ttb + sec * 4, buf, 4) == QEMU_PLUGIN_HWADDR_OPERATION_OK) {
            memcpy(&d, buf->data, 4);
        }
        g_byte_array_free(buf, TRUE);
        attr_cache[sec] = decode_section(d);
        attr_valid[sec] = true;
    }
    return attr_cache[sec];
}

static InsnStats *insn_stats_for(uint32_t vaddr)
{
    InsnStats *s = g_hash_table_lookup(insn_stats, GUINT_TO_POINTER(vaddr));

    if (!s) {
        s = g_new0(InsnStats, 1);
        s->vaddr = vaddr;
        g_hash_table_insert(insn_stats, GUINT_TO_POINTER(vaddr), s);
    }
    return s;
}

static uint64_t last_render_insns, last_render_frames;
static void print_slice(void)
{
    Stats d;
    g_autoptr(GString) out = g_string_new("");

#define D(f) d.f = tot.f - last.f
    D(insns); D(l1i_acc); D(l1i_miss); D(l1d_rd); D(l1d_wr); D(l1d_rd_miss); D(l1d_wr_miss);
    D(l1d_wb); D(l2_acc); D(l2_miss); D(nc); D(dev); D(l1_maint); D(l2_maint);
#undef D
    g_string_printf(out, "SLICE %" PRIu64 " insns=%" PRIu64 " l1i_miss=%" PRIu64 " l1d_rd=%" PRIu64
                    " l1d_wr=%" PRIu64 " l1d_rd_miss=%" PRIu64 " l1d_wr_miss=%" PRIu64 " l1d_wb=%" PRIu64
                    " l2_acc=%" PRIu64 " l2_miss=%" PRIu64 " nc=%" PRIu64 " dev=%" PRIu64
                    " l1_maint=%" PRIu64 " l2_maint=%" PRIu64 "\n",
                    tot.insns / slice - 1, d.insns, d.l1i_miss, d.l1d_rd, d.l1d_wr, d.l1d_rd_miss,
                    d.l1d_wr_miss, d.l1d_wb, d.l2_acc, d.l2_miss, d.nc, d.dev, d.l1_maint, d.l2_maint);
    g_string_truncate(out, out->len - 1); /* drop the newline */
    g_string_append_printf(out, " render_ins=%" PRIu64 " render_frames=%" PRIu64 " cycles=%.0f\n",
                           render_insns_total - last_render_insns, render_frames_total - last_render_frames, cycles);
    last_render_insns = render_insns_total;
    last_render_frames = render_frames_total;
    qemu_plugin_outs(out->str);
    last = tot;
}

/* An L1 miss or write-back goes to L2 if the memory is outer cacheable. */
static int cur_range = -1;

static int l2pf;
static void l2_fill(uint32_t addr, Attr a);

static void to_l2(uint32_t addr, bool write, Attr a, InsnStats *st, int ph)
{
    uint32_t ev;

    if (!a.outer || !l2_enabled) {
        if (st) {
            st->l2_miss[ph]++;
            if (addr >= 0x08000000 && addr < 0x10000000) {
                st->l2_miss_sdram[ph]++;
            }
            if (ph) {
                heat_l2[addr >> 16]++;
            }
        }
        tot.l2_miss++;
        if (in_render && cur_range >= 0) {
            fn_l2[cur_range]++;
        }
        return;
    }
    tot.l2_acc++;
    if (!(cache_access(l2, addr, write, !write || a.outer_wa, &ev) & 1)) {
        if (l2pf && !write) {
            l2_fill(addr + (1u << l2->line_bits), a);
        }
        tot.l2_miss++;
        if (st) {
            st->l2_miss[ph]++;
            if (addr >= 0x08000000 && addr < 0x10000000) {
                st->l2_miss_sdram[ph]++;
            }
            if (ph) {
                heat_l2[addr >> 16]++;
            }
        }
        if (in_render && cur_range >= 0) {
            fn_l2[cur_range]++;
        }
    }
}

/* ---- prefetch ---- */

/*
 * A9 L1 data prefetcher (approximate): tracks pf_streams streams of L1D demand
 * misses; a miss one stride (in lines, |stride| <= 4) on from a stream's last
 * miss confirms it, and from the second confirmation on, the next pf_dist lines
 * along it are fetched into L1D (and L2). PL310 next-line prefetch (l2pf=1): an
 * L2 miss also brings the following line into L2.
 */
static int pf_streams, pf_dist;
typedef struct {
    int32_t last; int32_t stride; int conf; uint64_t used;
} Stream;
static Stream streams[16];
static uint64_t pf_clock, pf_issued;

static void l2_fill(uint32_t addr, Attr a)
{
    uint32_t ev;
    if (a.outer && l2_enabled && cache_find(l2, addr) < 0) {
        tot.l2_acc++;
        cache_access(l2, addr, false, true, &ev);
    }
}

static void l1d_prefetch(uint32_t addr)
{
    Attr a = attr_for(addr);
    uint32_t ev;

    if (!a.inner || cache_find(l1d, addr) >= 0) {
        return;
    }
    pf_issued++;
    if (a.outer && l2_enabled && cache_find(l2, addr) < 0) {
        l2_fill(addr, a);
    }
    if (cache_access(l1d, addr, false, true, &ev) & 2) {
        tot.l1d_wb++;
    }
}

static void l1d_miss_train(uint32_t addr)
{
    int32_t line = addr >> l1d->line_bits;
    int best = -1;
    uint64_t oldest = UINT64_MAX;

    if (!pf_streams) {
        return;
    }
    pf_clock++;
    for (int i = 0; i < pf_streams; i++) {
        Stream *st = &streams[i];
        int32_t d = line - st->last;
        if (st->used && d != 0 && d >= -4 && d <= 4 && (st->conf == 0 || d == st->stride)) {
            st->conf = (st->conf == 0 || d != st->stride) ? 1 : st->conf + 1;
            st->stride = d;
            st->last = line;
            st->used = pf_clock;
            if (st->conf >= 2) {
                for (int k = 1; k <= pf_dist; k++) {
                    l1d_prefetch((uint32_t)(line + k * d) << l1d->line_bits);
                }
            }
            return;
        }
        if (st->used < oldest) {
            oldest = st->used;
            best = i;
        }
    }
    streams[best] = (Stream){ line, 0, 0, pf_clock };
}

/* ---- callbacks ---- */

static void vcpu_insn_exec(unsigned int cpu, void *udata)
{
    Insn *in = udata;
    uint32_t line;

    for (int i = 0; i < NSCOPE; i++) {
        if (scope_active[i] && in->vaddr == scope_ret[i]) {
            scope_active[i] = false;
            if (mark_insns && tot.insns >= mark_insns + warm_insns) {
                scope_calls[i]++;
                scope_ins[i] += tot.insns - scope_ins0[i];
                scope_cyc[i] += cycles - scope_cyc0[i];
            }
        }
    }
    if (in_render && in->vaddr == render_ret) {
        GByteArray *b = g_byte_array_new();
        uint32_t head1 = head0;
        GString *o = g_string_new("");

        if (qemu_plugin_read_memory_vaddr(head_addr, b, 4) && b->len >= 4) {
            memcpy(&head1, b->data, 4);
        }
        g_byte_array_free(b, TRUE);
#define RD(f) (tot.f - render_start.f)
        g_string_printf(o, "R %" PRIu64 " ins=%" PRIu64 " fr=%u l1i=%" PRIu64 " l1d=%" PRIu64 " l2acc=%" PRIu64
                        " l2=%" PRIu64 " nc=%" PRIu64 " dev=%" PRIu64,
                        render_start.insns, RD(insns), head_is_timer ? head1 - head0 : ((head1 - head0) & 0x3FF) / 8, RD(l1i_miss),
                        RD(l1d_rd_miss) + RD(l1d_wr_miss), RD(l2_acc), RD(l2_miss), RD(nc), RD(dev));
        render_insns_total += RD(insns);
        render_frames_total += head_is_timer ? head1 - head0 : ((head1 - head0) & 0x3FF) / 8;
#undef RD
        for (int i = 0; i < NFN; i++) {
            if (fn_hi[i]) {
                g_string_append_printf(o, " f%d=%" PRIu64 "/%" PRIu64 "/%" PRIu64, i, fn_ins[i], fn_l1d[i], fn_l2[i]);
            }
        }
        g_string_append_c(o, '\n');
        qemu_plugin_outs(o->str);
        g_string_free(o, TRUE);
        in_render = false;
    }
    cur_range = in->range;
    if (in_render && in->range >= 0) {
        fn_ins[in->range]++;
    }
    tot.insns++;
    if (timectl) {
        cycles += cpi0;
        if (cycles - cycles_at_update >= quantum) {
            cycles_at_update = cycles;
            qemu_plugin_update_ns(time_handle, (int64_t)(cycles * 1e9 / hz));
        }
    }
    line = in->vaddr >> l1i->line_bits;
    if (cachesim && line != last_iline) {
        Attr a = attr_for(in->vaddr);
        uint32_t ev;

        if (itrace && mark_insns && tot.insns >= mark_insns + itrace_skip &&
            tot.insns < mark_insns + itrace_skip + itrace_len) {
            itrace_buf[itrace_n++] = (line << l1i->line_bits) | (line != last_iline + 1);
            if (itrace_n == G_N_ELEMENTS(itrace_buf)) {
                fwrite(itrace_buf, 4, itrace_n, itrace);
                itrace_n = 0;
            }
        }
        last_iline = line;
        if (a.inner) {
            tot.l1i_acc++;
            if (!(cache_access(l1i, in->vaddr, false, true, &ev) & 1)) {
                tot.l1i_miss++;
                cycles += pen_i;
                in->st->l1i_miss[phase_now()]++;
                to_l2(in->vaddr, false, a, NULL, 0);
            }
        }
    }
    if (mark_addr && in->vaddr == (uint32_t)mark_addr) {
        g_autofree char *m = g_strdup_printf("MARK insns=%" PRIu64 " slice=%" PRIu64 "\n",
                                             tot.insns, tot.insns / slice);
        qemu_plugin_outs(m);
        if (mark_slice < 0) {
            mark_slice = tot.insns / slice;
            mark_insns = tot.insns;
        }
    }
    if (tot.insns >= next_slice) {
        next_slice += slice;
        print_slice();
    }
}

/* CP15 c7 maintenance: read Rt and apply it to L1. */
static void vcpu_maint_exec(unsigned int cpu, void *udata)
{
    Insn *in = udata;
    uint32_t rt = 0;
    bool clean = false, inval = false, setway = false, icache_all = false;

    switch (in->maint) {
    case 0x50: icache_all = true; break;                  /* ICIALLU */
    case 0x61: inval = true; break;                       /* DCIMVAC */
    case 0x62: inval = true; setway = true; break;        /* DCISW */
    case 0xA1: case 0xB1: clean = true; break;            /* DCCMVAC, DCCMVAU */
    case 0xA2: clean = true; setway = true; break;        /* DCCSW */
    case 0xE1: clean = inval = true; break;               /* DCCIMVAC */
    case 0xE2: clean = inval = true; setway = true; break; /* DCCISW */
    default: return;
    }
    if (!icache_all && regs[in->rt]) {
        g_byte_array_set_size(regbuf, 0);
        if (qemu_plugin_read_register(regs[in->rt], regbuf) && regbuf->len >= 4) {
            memcpy(&rt, regbuf->data, 4);
        }
    }
    tot.l1_maint++;
    if (icache_all) {
        memset(l1i->valid, 0, l1i->sets * l1i->assoc);
        last_iline = UINT32_MAX;
    } else if (setway) {
        int way = rt >> (32 - __builtin_ctz(l1d->assoc));
        int set = (rt >> l1d->line_bits) & (l1d->sets - 1);
        tot.l1d_wb += cache_maint_line(l1d, set, way, clean, inval);
    } else {
        tot.l1d_wb += cache_maint_addr(l1d, rt, clean, inval);
    }
}

static void vcpu_render_entry(unsigned int cpu, void *udata)
{
    GByteArray *b = g_byte_array_new();
    uint32_t lr = 0;

    if (in_render || !lr_reg) {
        g_byte_array_free(b, TRUE);
        return; /* re-entered (it returns at once), or can't tell where it returns to */
    }
    if (qemu_plugin_read_register(lr_reg, b) && b->len >= 4) {
        memcpy(&lr, b->data, 4);
    }
    g_byte_array_set_size(b, 0);
    render_ret = lr & ~1u;
    head0 = 0;
    if (qemu_plugin_read_memory_vaddr(head_addr, b, 4) && b->len >= 4) {
        memcpy(&head0, b->data, 4);
    }
    render_start = tot;
    memset(fn_ins, 0, sizeof(fn_ins));
    memset(fn_l1d, 0, sizeof(fn_l1d));
    memset(fn_l2, 0, sizeof(fn_l2));
    in_render = true;
    g_byte_array_free(b, TRUE);
}

static void vcpu_scope_entry(unsigned int cpu, void *udata)
{
    Insn *in = udata;
    GByteArray *b = g_byte_array_new();
    uint32_t lr = 0;

    if (lr_reg && qemu_plugin_read_register(lr_reg, b) && b->len >= 4) {
        memcpy(&lr, b->data, 4);
    }
    g_byte_array_free(b, TRUE);
    for (int i = 0; i < NSCOPE; i++) {
        if (scope_addr[i] == in->vaddr && !scope_active[i]) {
            scope_active[i] = true;
            scope_ret[i] = lr & ~1u;
            scope_ins0[i] = tot.insns;
            scope_cyc0[i] = cycles;
        }
    }
}

static void l2c_store(uint32_t off, uint32_t val)
{
    tot.l2_maint++;
    switch (off) {
    case 0x100: l2_enabled = val & 1; break;               /* REG1_CONTROL */
    case 0x770: cache_maint_addr(l2, val, false, true); break; /* INV_PA */
    case 0x7B0: cache_maint_addr(l2, val, true, false); break; /* CLEAN_PA */
    case 0x7F0: cache_maint_addr(l2, val, true, true); break;  /* CLEAN_INV_PA */
    case 0x77C: case 0x7BC: case 0x7FC: {                  /* INV / CLEAN / CLEAN_INV _WAY */
        bool clean = off != 0x77C, inval = off != 0x7BC;
        for (int w = 0; w < l2->assoc; w++) {
            if (val & (1u << w)) {
                for (int s = 0; s < l2->sets; s++) {
                    cache_maint_line(l2, s, w, clean, inval);
                }
            }
        }
        break;
    }
    case 0x900: l2->alloc_mask = ~val & ((1u << l2->assoc) - 1); break; /* D lockdown (I shares it here) */
    default: tot.l2_maint--; break;
    }
}

static void vcpu_mem(unsigned int cpu, qemu_plugin_meminfo_t info, uint64_t vaddr, void *udata)
{
    Insn *in = udata;
    bool write = qemu_plugin_mem_is_store(info);
    struct qemu_plugin_hwaddr *hw = qemu_plugin_get_hwaddr(info, vaddr);
    uint64_t pa = hw ? qemu_plugin_hwaddr_phys_addr(hw) : vaddr;
    uint32_t addr = (uint32_t)vaddr;
    Attr a;
    int ph;

    ph = phase_now();
    if (write && pa >= ttb && pa < ttb + 0x4000) {
        attr_valid[(pa - ttb) / 4] = false;
    }
    if (write && pa >= l2c && pa < l2c + 0x1000) {
        qemu_plugin_mem_value v = qemu_plugin_mem_get_value(info);
        l2c_store(pa - l2c, v.data.u32);
    }
    a = attr_for(addr);
    if (a.type == ATTR_SO || a.type == ATTR_DEV) {
        tot.dev++;
        cycles += pen_dev;
    } else if (!a.inner) {
        tot.nc++;
        cycles += pen_nc;
        in->st->nc[ph]++;
        if (a.outer) {
            to_l2(addr, write, a, in->st, ph);
        }
    } else {
        uint32_t ev;
        int r;

        if (write) {
            tot.l1d_wr++;
        } else {
            tot.l1d_rd++;
        }
        r = cache_access(l1d, addr, write, !write || a.inner_wa, &ev);
        if (!(r & 1)) {
            if (write) {
                tot.l1d_wr_miss++;
            } else {
                tot.l1d_rd_miss++;
            }
            in->st->l1d_miss[ph]++;
            cycles += pen_d;
            if (ph) {
                heat_l1d[addr >> 16]++;
            }
            l1d_miss_train(addr);
            if (in_render && in->range >= 0) {
                fn_l1d[in->range]++;
            }
            to_l2(addr, write, a, in->st, ph);
        }
        if (r & 2) {
            tot.l1d_wb++;
            to_l2(ev, true, attr_for(ev), NULL, ph);
        }
    }
}

/* Decode an MCR p15, 0, Rt, c7, CRm, opc2 from an ARM word or a Thumb-2 pair. */
static bool decode_c7(uint32_t w, int *op, int *rt)
{
    if ((w & 0x0F100010) != 0x0E000010 || ((w >> 8) & 0xF) != 15 || ((w >> 16) & 0xF) != 7 ||
        ((w >> 21) & 7) != 0) {
        return false;
    }
    *op = ((w & 0xF) << 4) | ((w >> 5) & 7);
    *rt = (w >> 12) & 0xF;
    return true;
}

/*
 * Lean mode (lean=1, with timectl=1 and cachesim=0): no per-instruction callbacks. Instructions are counted with
 * inline per-block adds, and a conditional callback every `quantum` cycles' worth advances the clock and prints
 * slices, so a flat-CPI run goes at close to plain emulation speed. Only the mark instruction gets a callback; there
 * is no per-render or per-function accounting.
 */
static bool lean;
static struct qemu_plugin_scoreboard *lean_sb;
static qemu_plugin_u64 lean_count;
static uint64_t lean_quantum_insns;

static void lean_advance(void)
{
    uint64_t n = qemu_plugin_u64_get(lean_count, 0);

    qemu_plugin_u64_set(lean_count, 0, 0);
    tot.insns += n;
    cycles += n * cpi0;
    qemu_plugin_update_ns(time_handle, (int64_t)(cycles * 1e9 / hz));
    while (tot.insns >= next_slice) {
        next_slice += slice;
        print_slice();
    }
}

static void lean_quantum(unsigned int cpu, void *udata)
{
    lean_advance();
}

static void lean_mark(unsigned int cpu, void *udata)
{
    /* Bring the count up to date, including the instructions of this block before the mark */
    uint64_t pending = qemu_plugin_u64_get(lean_count, 0);
    g_autofree char *m = g_strdup_printf("MARK insns=%" PRIu64 " slice=%" PRIu64 "\n", tot.insns + pending,
                                         (tot.insns + pending) / slice);
    qemu_plugin_outs(m);
    if (mark_slice < 0) {
        mark_slice = (tot.insns + pending) / slice;
        mark_insns = tot.insns + pending;
    }
}

static void lean_tb_trans(struct qemu_plugin_tb *tb)
{
    size_t n = qemu_plugin_tb_n_insns(tb);

    qemu_plugin_register_vcpu_tb_exec_inline_per_vcpu(tb, QEMU_PLUGIN_INLINE_ADD_U64, lean_count, n);
    qemu_plugin_register_vcpu_tb_exec_cond_cb(tb, lean_quantum, QEMU_PLUGIN_CB_NO_REGS, QEMU_PLUGIN_COND_GE,
                                              lean_count, lean_quantum_insns, NULL);
    for (size_t i = 0; mark_addr && i < n; i++) {
        struct qemu_plugin_insn *insn = qemu_plugin_tb_get_insn(tb, i);
        if (qemu_plugin_insn_vaddr(insn) == (uint32_t)mark_addr) {
            qemu_plugin_register_vcpu_insn_exec_cb(insn, lean_mark, QEMU_PLUGIN_CB_NO_REGS, NULL);
        }
    }
}

static void vcpu_tb_trans(qemu_plugin_id_t id, struct qemu_plugin_tb *tb)
{
    size_t n = qemu_plugin_tb_n_insns(tb);

    if (lean) {
        lean_tb_trans(tb);
        return;
    }

    for (size_t i = 0; i < n; i++) {
        struct qemu_plugin_insn *insn = qemu_plugin_tb_get_insn(tb, i);
        Insn *in = g_new0(Insn, 1);
        uint8_t b[4] = { 0 };
        size_t sz = qemu_plugin_insn_data(insn, b, sizeof(b));

        in->vaddr = qemu_plugin_insn_vaddr(insn);
        in->range = -1;
        for (int r = 0; r < NFN; r++) {
            if (fn_hi[r] && in->vaddr >= fn_lo[r] && in->vaddr < fn_hi[r]) {
                in->range = r;
            }
        }
        for (int i = 0; i < NSCOPE; i++) {
            if (scope_addr[i] && in->vaddr == scope_addr[i]) {
                qemu_plugin_register_vcpu_insn_exec_cb(insn, vcpu_scope_entry, QEMU_PLUGIN_CB_R_REGS, in);
                break;
            }
        }
        if (render_addr && in->vaddr == (uint32_t)render_addr) {
            qemu_plugin_register_vcpu_insn_exec_cb(insn, vcpu_render_entry, QEMU_PLUGIN_CB_R_REGS, in);
        }
            in->st = insn_stats_for(in->vaddr);
            if (sz == 4) {
            uint32_t arm = b[0] | b[1] << 8 | b[2] << 16 | (uint32_t)b[3] << 24;
            uint32_t thumb = (uint32_t)(b[0] | b[1] << 8) << 16 | (b[2] | b[3] << 8);
            if (decode_c7(arm, &in->maint, &in->rt) || decode_c7(thumb, &in->maint, &in->rt)) {
                qemu_plugin_register_vcpu_insn_exec_cb(insn, vcpu_maint_exec, QEMU_PLUGIN_CB_R_REGS, in);
            }
        }
        qemu_plugin_register_vcpu_insn_exec_cb(insn, vcpu_insn_exec, QEMU_PLUGIN_CB_NO_REGS, in);
        if (cachesim) {
            qemu_plugin_register_vcpu_mem_cb(insn, vcpu_mem, QEMU_PLUGIN_CB_NO_REGS, QEMU_PLUGIN_MEM_RW, in);
        }
    }
}

static void vcpu_idle(qemu_plugin_id_t id, unsigned int vcpu)
{
    static bool warned;
    if (timectl && !warned) {
        warned = true;
        qemu_plugin_outs("dzcache: the vCPU halted (WFE/WFI) under time control; the guest clock is frozen until it "
                         "runs again, so a halted guest waiting on a timer won't wake. Use -icount for such firmware.\n");
    }
}

static void vcpu_init(qemu_plugin_id_t id, unsigned int vcpu)
{
    g_autoptr(GArray) r = qemu_plugin_get_registers();

    for (guint i = 0; i < r->len; i++) {
        qemu_plugin_reg_descriptor *d = &g_array_index(r, qemu_plugin_reg_descriptor, i);
        int n;
        if (d->name[0] == 'r' && sscanf(d->name + 1, "%d", &n) == 1 && n >= 0 && n < 13) {
            regs[n] = d->handle;
        }
        if (!strcmp(d->name, "lr") || !strcmp(d->name, "r14")) {
            lr_reg = d->handle;
        }
    }
}

/* Rough stall weight after the mark: L1 misses (I and D) at 25, L2 misses and uncached at 100 more. */
static uint64_t weight(const InsnStats *x)
{
    uint64_t w = 0;
    for (int p = 1; p < 3; p++) {
        w += (x->l1d_miss[p] + x->l1i_miss[p]) * 25 + (x->l2_miss[p] + x->nc[p]) * 100;
    }
    return w;
}

static gint by_l1d_b(gconstpointer a, gconstpointer b)
{
    uint64_t xs = weight(*(InsnStats * const *)a), ys = weight(*(InsnStats * const *)b);
    return xs < ys ? 1 : xs > ys ? -1 : 0;
}

static void plugin_exit(qemu_plugin_id_t id, void *p)
{
    GPtrArray *all = g_ptr_array_new();
    GHashTableIter it;
    gpointer k, v;

    print_slice();
    if (itrace) {
        fwrite(itrace_buf, 4, itrace_n, itrace);
        fclose(itrace);
        itrace = NULL;
    }
    for (int i = 0; i < NSCOPE; i++) {
        if (scope_addr[i]) {
            g_autofree char *l = g_strdup_printf("SCOPE %d calls=%" PRIu64 " ins=%" PRIu64 " cyc=%.0f\n", i,
                                                 scope_calls[i], scope_ins[i], scope_cyc[i]);
            qemu_plugin_outs(l);
        }
    }
    g_hash_table_iter_init(&it, insn_stats);
    while (g_hash_table_iter_next(&it, &k, &v)) {
        g_ptr_array_add(all, v);
    }
    g_ptr_array_sort(all, by_l1d_b);
    for (guint i = 0; i < all->len && i < 3000; i++) {
        InsnStats *s = g_ptr_array_index(all, i);
        g_autofree char *line = g_strdup_printf(
            "INSN 0x%08x l1d_miss=%" PRIu64 ",%" PRIu64 ",%" PRIu64 " l2_miss=%" PRIu64 ",%" PRIu64 ",%" PRIu64
            " nc=%" PRIu64 ",%" PRIu64 ",%" PRIu64 " l1i_miss=%" PRIu64 ",%" PRIu64 ",%" PRIu64
            " l2_sdram=%" PRIu64 ",%" PRIu64 ",%" PRIu64 "\n",
            s->vaddr, s->l1d_miss[0], s->l1d_miss[1], s->l1d_miss[2], s->l2_miss[0], s->l2_miss[1],
            s->l2_miss[2], s->nc[0], s->nc[1], s->nc[2], s->l1i_miss[0], s->l1i_miss[1], s->l1i_miss[2],
            s->l2_miss_sdram[0], s->l2_miss_sdram[1], s->l2_miss_sdram[2]);
        qemu_plugin_outs(line);
    }
    for (int b = 0; b < 65536; b++) {
        if (heat_l1d[b] || heat_l2[b]) {
            g_autofree char *line = g_strdup_printf("HEAT 0x%08x l1d=%" PRIu64 " l2=%" PRIu64 "\n",
                                                    b << 16, heat_l1d[b], heat_l2[b]);
            qemu_plugin_outs(line);
        }
    }
    g_ptr_array_free(all, TRUE);
}

QEMU_PLUGIN_EXPORT int qemu_plugin_install(qemu_plugin_id_t id, const qemu_info_t *info, int argc,
                                           char **argv)
{
    int l1size = 32 * 1024, l1assoc = 4, l2size = 128 * 1024, l2assoc = 8, line = 32;
    int l1repl = REPL_RANDOM, l2repl = REPL_RR; /* A9 with SCTLR.RR clear; PL310 AUX bit 25 set on the Deluge */

    for (int i = 0; i < argc; i++) {
        g_auto(GStrv) t = g_strsplit(argv[i], "=", 2);
        uint64_t v = t[1] ? g_ascii_strtoull(t[1], NULL, 0) : 0;
        if (!strcmp(t[0], "ttb")) ttb = v;
        else if (!strcmp(t[0], "l2c")) l2c = v;
        else if (!strcmp(t[0], "mark")) mark_addr = v & ~1ull;
        else if (!strcmp(t[0], "slice")) slice = v;
        else if (!strcmp(t[0], "phasea")) phasea = v;
        else if (!strcmp(t[0], "l1size")) l1size = v;
        else if (!strcmp(t[0], "l1assoc")) l1assoc = v;
        else if (!strcmp(t[0], "l2size")) l2size = v;
        else if (!strcmp(t[0], "l2assoc")) l2assoc = v;
        else if (!strcmp(t[0], "line")) line = v;
        else if (!strcmp(t[0], "render")) render_addr = v & ~1ull;
        else if (!strcmp(t[0], "pfstreams")) pf_streams = MIN(v, 16);
        else if (!strcmp(t[0], "timectl")) timectl = v;
        else if (!strcmp(t[0], "lean")) lean = v;
        else if (!strcmp(t[0], "warm")) warm_insns = v;
        else if (!strcmp(t[0], "itrace")) itrace = fopen(t[1], "wb");
        else if (!strcmp(t[0], "itskip")) itrace_skip = v;
        else if (!strcmp(t[0], "itlen")) itrace_len = v;
        else if (t[0][0] == 's' && t[0][1] >= '0' && t[0][1] <= '5' && !t[0][2]) scope_addr[t[0][1] - '0'] = v & ~1u;
        else if (!strcmp(t[0], "cachesim")) cachesim = v;
        else if (!strcmp(t[0], "cpi")) cpi0 = g_ascii_strtod(t[1], NULL);
        else if (!strcmp(t[0], "pi")) pen_i = g_ascii_strtod(t[1], NULL);
        else if (!strcmp(t[0], "pd")) pen_d = g_ascii_strtod(t[1], NULL);
        else if (!strcmp(t[0], "pdev")) pen_dev = g_ascii_strtod(t[1], NULL);
        else if (!strcmp(t[0], "pnc")) pen_nc = g_ascii_strtod(t[1], NULL);
        else if (!strcmp(t[0], "hz")) hz = g_ascii_strtod(t[1], NULL);
        else if (!strcmp(t[0], "quantum")) quantum = v;
        else if (!strcmp(t[0], "l1repl")) l1repl = v;
        else if (!strcmp(t[0], "l2repl")) l2repl = v;
        else if (!strcmp(t[0], "pfdist")) pf_dist = v;
        else if (!strcmp(t[0], "l2pf")) l2pf = v;
        else if (!strcmp(t[0], "head")) head_addr = v;
        else if (!strcmp(t[0], "timer")) { head_addr = v; head_is_timer = true; }
        else if (t[0][0] == 'f' && t[0][1] == 'n' && t[1] && strchr(t[1], '-')) {
            int i = atoi(t[0] + 2);
            if (i >= 0 && i < NFN) {
                fn_lo[i] = g_ascii_strtoull(t[1], NULL, 0) & ~1u;
                fn_hi[i] = g_ascii_strtoull(strchr(t[1], '-') + 1, NULL, 0);
            }
        }
        else {
            fprintf(stderr, "dzcache: unknown option %s\n", argv[i]);
            return -1;
        }
    }
    l1i = cache_new(l1size, l1assoc, line);
    l1d = cache_new(l1size, l1assoc, line);
    l2 = cache_new(l2size, l2assoc, line);
    l1i->repl = l1d->repl = l1repl;
    l2->repl = l2repl;
    if (timectl) {
        time_handle = qemu_plugin_request_time_control();
        if (!time_handle) {
            fprintf(stderr, "dzcache: time control unavailable (another plugin has it, or -icount is on)\n");
            return -1;
        }
    }
    if (info->system_emulation && info->system.max_vcpus > 1) {
        fprintf(stderr, "dzcache: assumes a single vCPU (the Deluge has one core), and keeps no locks\n");
        return -1;
    }
    if (lean) {
        if (!timectl || cachesim) {
            fprintf(stderr, "dzcache: lean=1 needs timectl=1 and cachesim=0\n");
            return -1;
        }
        lean_sb = qemu_plugin_scoreboard_new(sizeof(uint64_t));
        lean_count = qemu_plugin_scoreboard_u64(lean_sb);
        lean_quantum_insns = MAX(1, (uint64_t)(quantum / cpi0));
    }
    next_slice = slice;
    insn_stats = g_hash_table_new(NULL, NULL);
    regbuf = g_byte_array_new();
    qemu_plugin_register_vcpu_init_cb(id, vcpu_init);
    qemu_plugin_register_vcpu_idle_cb(id, vcpu_idle);
    qemu_plugin_register_vcpu_tb_trans_cb(id, vcpu_tb_trans);
    qemu_plugin_register_atexit_cb(id, plugin_exit, NULL);
    return 0;
}
