#include "00/code_021a3eb0.h"
#include "00/unk_021b4000.h"
void func_ov000_021a3eb0(Unk021a3a18 *a, u8 *b, s32 c) {
    Unk021a3eb0 s = data_ov000_021b4270;
    s32 i;
    s32 k = 1;
    u32 x;
    u8 *p;
    u8 *t;
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
        t = (u8 *) &x;
        p = b + 6;
        t[0] = p[0];
        t[1] = p[1];
        t[2] = p[2];
        t[3] = p[3];
        if (a->mUnk_a0 != 0) {
            a->mUnk_a0(((x << 24) & 0xff000000) | (((x << 8) & 0xff0000) | (((x >> 24) & 0xff) | ((x >> 8) & 0xff00))),
                       a->mUnk_10c);
        }
    } else if (a->mUnk_a4 != 0) {
        a->mUnk_a4((s8 *) b, c, a->mUnk_10c);
    }
}
