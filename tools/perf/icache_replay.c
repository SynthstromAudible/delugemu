/*
 * Replay an instruction-fetch trace (dzcache itrace=) through L1 I-cache models, to see which effects the plugin's
 * model is missing compared with the A9's PMU L1I refill count.
 *
 *   cc -O2 -o build/icache_replay tools/perf/icache_replay.c
 *   build/icache_replay itrace.bin <instructions in the trace> [size_kib ways repl ahead]
 *
 * repl: 0 LRU, 1 pseudo-random, 2 round-robin.
 * ahead: what the fetch unit requests besides the line being executed:
 *   0 nothing
 *   1 the next sequential line whenever it moves into a line (it streams ahead)
 *   2 the line after the one a jump left (the fall-through of a taken branch, fetched before the redirect)
 *   3 both
 * Each request that misses counts as a refill, as the PMU counts linefills, whether or not the line gets used.
 * With no size given, prints a table of the standard variants.
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int sets, ways;
    uint32_t *tag;
    uint64_t *stamp;
    uint8_t *rr;
    uint32_t lfsr;
    int repl;
    uint64_t clock;
} Cache;

static void init(Cache *c, int kib, int ways, int repl)
{
    c->ways = ways;
    c->sets = kib * 1024 / 32 / ways;
    c->tag = calloc((size_t)c->sets * ways, 4);
    c->stamp = calloc((size_t)c->sets * ways, 8);
    c->rr = calloc(c->sets, 1);
    c->lfsr = 0xACE1u;
    c->repl = repl;
    c->clock = 0;
    for (int i = 0; i < c->sets * ways; i++) {
        c->tag[i] = UINT32_MAX;
    }
}

/* Returns 1 on a miss (and fills the line) */
static int access_line(Cache *c, uint32_t line)
{
    int set = line & (c->sets - 1), base = set * c->ways, victim = 0;
    c->clock++;
    for (int w = 0; w < c->ways; w++) {
        if (c->tag[base + w] == line) {
            c->stamp[base + w] = c->clock;
            return 0;
        }
    }
    for (int w = 0; w < c->ways; w++) {
        if (c->tag[base + w] == UINT32_MAX) {
            victim = w;
            goto fill;
        }
    }
    if (c->repl == 0) {
        for (int w = 1; w < c->ways; w++) {
            if (c->stamp[base + w] < c->stamp[base + victim]) {
                victim = w;
            }
        }
    }
    else if (c->repl == 1) {
        c->lfsr = (c->lfsr >> 1) ^ (-(c->lfsr & 1u) & 0xB400u);
        victim = c->lfsr % c->ways;
    }
    else {
        victim = c->rr[set];
        c->rr[set] = (c->rr[set] + 1) % c->ways;
    }
fill:
    c->tag[base + victim] = line;
    c->stamp[base + victim] = c->clock;
    return 1;
}

static int depth = 1; /* how many sequential lines "next line" fetches ahead */

static double run(const uint32_t *t, size_t n, double insns, int kib, int ways, int repl, int ahead)
{
    Cache c;
    uint64_t misses = 0;
    uint32_t prev = UINT32_MAX;
    init(&c, kib, ways, repl);
    for (size_t i = 0; i < n; i++) {
        uint32_t line = t[i] >> 5;
        int jump = t[i] & 1;
        misses += access_line(&c, line);
        if ((ahead & 1)) {
            for (int d = 1; d <= depth; d++) {
                misses += access_line(&c, line + d);
            }
        }
        if ((ahead & 2) && jump && prev != UINT32_MAX) {
            misses += access_line(&c, prev + 1);
        }
        prev = line;
    }
    free(c.tag);
    free(c.stamp);
    free(c.rr);
    return 1000.0 * misses / insns;
}

int main(int argc, char **argv)
{
    if (argc < 3) {
        fprintf(stderr, "usage: %s itrace.bin instructions [size_kib ways repl ahead]\n", argv[0]);
        return 1;
    }
    FILE *f = fopen(argv[1], "rb");
    if (!f) {
        perror(argv[1]);
        return 1;
    }
    fseek(f, 0, SEEK_END);
    size_t n = ftell(f) / 4;
    fseek(f, 0, SEEK_SET);
    uint32_t *t = malloc(n * 4);
    if (fread(t, 4, n, f) != n) {
        perror("read");
        return 1;
    }
    fclose(f);
    double insns = atof(argv[2]);
    if (argc >= 7) {
        printf("%.2f\n", run(t, n, insns, atoi(argv[3]), atoi(argv[4]), atoi(argv[5]), atoi(argv[6])));
        return 0;
    }
    static const char *repls[] = {"LRU", "random", "round-robin"};
    static const char *aheads[] = {"none", "next line", "branch fall-through", "both"};
    printf("%zu line changes, %.0f instructions; L1I refills per 1,000 instructions\n\n", n, insns);
    printf("%-22s %8s %8s %8s %8s\n", "32 KiB 4-way", aheads[0], "next", "fallthru", "both");
    for (int r = 0; r < 3; r++) {
        printf("%-22s", repls[r]);
        for (int a = 0; a < 4; a++) {
            printf(" %8.2f", run(t, n, insns, 32, 4, r, a));
        }
        printf("\n");
    }
    printf("\nnext-line depth (random): ");
    for (depth = 1; depth <= 4; depth++) {
        printf(" %d: %.2f ", depth, run(t, n, insns, 32, 4, 1, 1));
    }
    depth = 1;
    printf("\nsize sensitivity (random, ahead none): ");
    for (int kib = 8; kib <= 64; kib *= 2) {
        printf(" %d KiB %.2f ", kib, run(t, n, insns, kib, 4, 1, 0));
    }
    printf("\n");
    return 0;
}
