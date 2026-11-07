/*
 * dzstack: exact call-stack instruction profile of the Deluge firmware, for flame graphs, as a QEMU TCG plugin.
 *
 * Keeps a shadow call stack and charges every executed instruction to the stack it ran under. A BL/BLX (found from the
 * disassembly) pushes a frame for whatever block runs next, with the call's return address; a frame is popped when
 * execution reaches its return address, whatever instruction got it there (BX LR, POP {PC}, LDM, exception return).
 * Entering `irq` or `fiq` (the handlers, which start with SUB LR, LR, #4) pushes a frame that returns to LR - 4.
 * Reaching one of the function entries in `funcs` without a call is a tail call: it renames the current frame (but not
 * an exception frame). A frame popped also pops the frames below it returning to the same place, as an interrupt
 * taken just after a return pushes one before the return is seen.
 *
 * Counting starts the first time `start` executes (e.g. PlaybackHandler::playButtonPressed) and stops `limit`
 * instructions later, when the profile is written to `out` as folded stacks of function entry addresses
 * ("0x200..;0x200.. count"); the emulator keeps running. Symbolize with scripts/dz_flame.py.
 *
 * Args: out funcs irq fiq start limit
 * Build: scripts/build-plugins.sh
 */
#include <glib.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <qemu-plugin.h>

QEMU_PLUGIN_EXPORT int qemu_plugin_version = QEMU_PLUGIN_VERSION;

typedef struct Node {
    uint32_t func;
    struct Node *parent;
    GHashTable *kids; /* func -> Node */
    uint64_t self;
} Node;

typedef struct {
    Node *node;
    uint32_t ret;
    bool exception; /* irq/fiq entry: keeps its name, as handlers branch to labels that look like function entries */
} Frame;

typedef struct {
    uint32_t pc;
    uint32_t insns;
    bool entry;     /* pc is in funcs */
    bool exception; /* pc is irq or fiq */
} Block;

#define MAX_DEPTH 256

static Node root;
static Frame stack[MAX_DEPTH];
static int depth;
static uint32_t pending_ret; /* return address of a call that has just executed; 0 if none */
static GHashTable *funcs;
static uint32_t irq_addr, fiq_addr, start_addr;
static uint64_t limit = UINT64_MAX, counted;
static bool counting, done;
static char *out_path;
static struct qemu_plugin_register *lr_reg;
static uint64_t overflows;

static Node *child(Node *parent, uint32_t func)
{
    Node *n;

    if (!parent->kids) {
        parent->kids = g_hash_table_new(NULL, NULL);
    }
    n = g_hash_table_lookup(parent->kids, GUINT_TO_POINTER(func));
    if (!n) {
        n = g_new0(Node, 1);
        n->func = func;
        n->parent = parent;
        g_hash_table_insert(parent->kids, GUINT_TO_POINTER(func), n);
    }
    return n;
}

static void push(uint32_t func, uint32_t ret, bool exception)
{
    if (depth + 1 >= MAX_DEPTH) {
        overflows++;
        return;
    }
    stack[depth + 1].node = child(stack[depth].node, func);
    stack[depth + 1].ret = ret;
    stack[depth + 1].exception = exception;
    depth++;
}

static uint32_t read_lr(void)
{
    GByteArray *b = g_byte_array_new();
    uint32_t lr = 0;

    if (lr_reg && qemu_plugin_read_register(lr_reg, b) && b->len >= 4) {
        memcpy(&lr, b->data, 4);
    }
    g_byte_array_free(b, TRUE);
    return lr;
}

static void write_node(FILE *f, Node *n, GString *path)
{
    gsize len = path->len;
    GHashTableIter it;
    gpointer k, v;

    if (n != &root) {
        g_string_append_printf(path, "%s0x%08" PRIx32, path->len ? ";" : "", n->func);
    }
    if (n->self) {
        fprintf(f, "%s %" PRIu64 "\n", path->len ? path->str : "[root]", n->self);
    }
    if (n->kids) {
        g_hash_table_iter_init(&it, n->kids);
        while (g_hash_table_iter_next(&it, &k, &v)) {
            write_node(f, v, path);
        }
    }
    g_string_truncate(path, len);
}

static void write_profile(void)
{
    FILE *f = fopen(out_path, "w");
    GString *path = g_string_new(NULL);
    char msg[256];

    if (!f) {
        qemu_plugin_outs("dzstack: can't write the profile\n");
        return;
    }
    write_node(f, &root, path);
    fclose(f);
    g_string_free(path, TRUE);
    snprintf(msg, sizeof(msg), "dzstack: wrote %" PRIu64 " instructions to %s (%" PRIu64 " stack overflows)\n", counted,
             out_path, overflows);
    qemu_plugin_outs(msg);
}

static void vcpu_tb_exec(unsigned int cpu, void *udata)
{
    Block *b = udata;
    uint32_t pc = b->pc;

    if (pending_ret) {
        if (pc != pending_ret) { /* else a conditional call not taken */
            push(pc, pending_ret, false);
        }
        pending_ret = 0;
    } else {
        for (int d = depth; d > 0; d--) {
            if (stack[d].ret == pc) {
                /* An interrupt taken just after a return pushes a frame with the same return address as the frame
                 * returning: pop both */
                while (d > 1 && stack[d - 1].ret == pc) {
                    d--;
                }
                depth = d - 1;
                break;
            }
        }
        if (b->exception) {
            push(pc, (read_lr() - 4) & ~1u, true);
        } else if (b->entry && depth > 0 && !stack[depth].exception && stack[depth].node->func != pc) {
            stack[depth].node = child(stack[depth - 1].node, pc);
        }
    }

    if (!done && !counting && pc == start_addr) {
        counting = true;
    }
    if (counting) {
        stack[depth].node->self += b->insns;
        counted += b->insns;
        if (counted >= limit) {
            counting = false;
            done = true;
            write_profile();
        }
    }
}

static void vcpu_call_exec(unsigned int cpu, void *udata)
{
    pending_ret = GPOINTER_TO_UINT(udata);
}

static bool is_call(const char *disas)
{
    static const char *conds[] = {"eq", "ne", "cs", "hs", "cc", "lo", "mi", "pl", "vs",
                                  "vc", "hi", "ls", "ge", "lt", "gt", "le", "al"};
    char m[16];
    size_t n = 0;
    char *dot;

    while (*disas == ' ' || *disas == '\t') {
        disas++;
    }
    while (disas[n] && disas[n] != ' ' && disas[n] != '\t' && n < sizeof(m) - 1) {
        m[n] = disas[n];
        n++;
    }
    m[n] = 0;
    dot = strchr(m, '.');
    if (dot) {
        *dot = 0; /* bl.w */
    }
    if (strncmp(m, "bl", 2)) {
        return false;
    }
    const char *rest = m + 2;
    if (*rest == 'x') {
        rest++;
    }
    if (!*rest) {
        return true;
    }
    for (size_t i = 0; i < G_N_ELEMENTS(conds); i++) {
        if (!strcmp(rest, conds[i])) {
            return true;
        }
    }
    return false;
}

static void vcpu_tb_trans(qemu_plugin_id_t id, struct qemu_plugin_tb *tb)
{
    Block *b = g_new0(Block, 1);
    size_t n = qemu_plugin_tb_n_insns(tb);

    b->pc = (uint32_t)qemu_plugin_tb_vaddr(tb);
    b->insns = n;
    b->entry = g_hash_table_contains(funcs, GUINT_TO_POINTER(b->pc));
    b->exception = b->pc == irq_addr || b->pc == fiq_addr;
    qemu_plugin_register_vcpu_tb_exec_cb(tb, vcpu_tb_exec, b->exception ? QEMU_PLUGIN_CB_R_REGS : QEMU_PLUGIN_CB_NO_REGS,
                                         b);

    for (size_t i = 0; i < n; i++) {
        struct qemu_plugin_insn *insn = qemu_plugin_tb_get_insn(tb, i);
        char *d = qemu_plugin_insn_disas(insn);
        if (d && is_call(d)) {
            uint32_t ret = (uint32_t)(qemu_plugin_insn_vaddr(insn) + qemu_plugin_insn_size(insn));
            qemu_plugin_register_vcpu_insn_exec_cb(insn, vcpu_call_exec, QEMU_PLUGIN_CB_NO_REGS,
                                                   GUINT_TO_POINTER(ret));
        }
        g_free(d);
    }
}

static void vcpu_init(qemu_plugin_id_t id, unsigned int vcpu)
{
    g_autoptr(GArray) r = qemu_plugin_get_registers();

    for (guint i = 0; i < r->len; i++) {
        qemu_plugin_reg_descriptor *d = &g_array_index(r, qemu_plugin_reg_descriptor, i);
        if (!strcmp(d->name, "lr") || !strcmp(d->name, "r14")) {
            lr_reg = d->handle;
        }
    }
}

static void plugin_exit(qemu_plugin_id_t id, void *p)
{
    if (counting) {
        write_profile(); /* QEMU quit before the limit */
    }
}

static void load_funcs(const char *path)
{
    FILE *f = fopen(path, "r");
    char line[64];

    if (!f) {
        return;
    }
    while (fgets(line, sizeof(line), f)) {
        uint32_t a = strtoul(line, NULL, 16);
        if (a) {
            g_hash_table_add(funcs, GUINT_TO_POINTER(a));
        }
    }
    fclose(f);
}

QEMU_PLUGIN_EXPORT int qemu_plugin_install(qemu_plugin_id_t id, const qemu_info_t *info, int argc, char **argv)
{
    funcs = g_hash_table_new(NULL, NULL);
    root.func = 0;
    stack[0].node = &root;
    out_path = g_strdup("dzstack.folded");

    for (int i = 0; i < argc; i++) {
        g_auto(GStrv) kv = g_strsplit(argv[i], "=", 2);
        if (!kv[0] || !kv[1]) {
            continue;
        }
        if (!strcmp(kv[0], "out")) {
            g_free(out_path);
            out_path = g_strdup(kv[1]);
        } else if (!strcmp(kv[0], "funcs")) {
            load_funcs(kv[1]);
        } else if (!strcmp(kv[0], "irq")) {
            irq_addr = strtoul(kv[1], NULL, 0);
        } else if (!strcmp(kv[0], "fiq")) {
            fiq_addr = strtoul(kv[1], NULL, 0);
        } else if (!strcmp(kv[0], "start")) {
            start_addr = strtoul(kv[1], NULL, 0);
        } else if (!strcmp(kv[0], "limit")) {
            limit = strtoull(kv[1], NULL, 0);
        } else {
            fprintf(stderr, "dzstack: unknown option %s\n", kv[0]);
            return -1;
        }
    }
    counting = !start_addr;

    qemu_plugin_register_vcpu_init_cb(id, vcpu_init);
    qemu_plugin_register_vcpu_tb_trans_cb(id, vcpu_tb_trans);
    qemu_plugin_register_atexit_cb(id, plugin_exit, NULL);
    return 0;
}
