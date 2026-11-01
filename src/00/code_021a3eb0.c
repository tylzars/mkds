#include "00/code_021a3eb0.h"
#include "00/unk_021b4000.h"
// non-matching: the four bytes are written to [sp, #8..#11] from [r0, #6..#9] (original: add r1, sp, #8 and adds r2,
// r0, #6 with offsets 0..3 and 1..3); size 0xc4 against 0xc8
void func_ov000_021a3eb0(Unk021a3a18 *a, u8 *b, s32 c) {
    Unk021a3eb0 s = data_ov000_021b4270;
    s32 i;
    s32 k = 1;
    u32 x;
    u8 *p;
    if (c >= 10) {
        for (i = 0; i < 6; i++) {
            if (s.mUnk_00[i] != b[i]) {
                k = 0;
                break;
            }
        }
    } else {
        k = 0;
    }
    if (k != 0) {
        p = b + 6;
        *(Unk021a3c14 *) &x = *(Unk021a3c14 *) p;
        if (a->mUnk_a0 != 0) {
            a->mUnk_a0(((x << 24) & 0xff000000) | (((x << 8) & 0xff0000) | (((x >> 24) & 0xff) | ((x >> 8) & 0xff00))),
                       a->mUnk_10c);
        }
    } else if (a->mUnk_a4 != 0) {
        a->mUnk_a4((s8 *) b, c, a->mUnk_10c);
    }
}
