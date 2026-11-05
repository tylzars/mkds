// Compiler probe (docs/compiler.md): an ARM 64-bit multiply in main. Matches on 1.2 b56 to sp2p3, no 2.0 build.
// python3 tools/probe_compilers.py docs/probes/arm_long_multiply.c --flags="-O4,p -inline on,noauto"

typedef struct {
    char pad0[0x90];
    short mUnk_90;
    short mUnk_92;
    char pad94[0xc4 - 0x94];
    int mUnk_c4;
} Obj020dac00;

// PROBE: UpdateKuriboState2 main 0x020dac00
void UpdateKuriboState2(Obj020dac00 *obj) {
    obj->mUnk_c4 = (int) (((long long) obj->mUnk_c4 * 0x1266) >> 12);
    if (obj->mUnk_c4 > 0x1800) {
        obj->mUnk_90 = 3;
        obj->mUnk_92 = 1;
    }
}
