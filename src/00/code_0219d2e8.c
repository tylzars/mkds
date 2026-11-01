#include "00/code_0219d2e8.h"
#include "00/code_0218ed44.h"
#include "00/code_0219c9c4.h"
#include "00/code_0219cfc0.h"
#include "00/code_0219d128.h"
#include "00/code_0219d14c.h"
#include "00/code_0219d630.h"
#include "Main/Unknown/code_02152000.h"
#include "Main/Unknown/code_02152468.h"

// non-matching: the loop entry computes `r7 = i * 12` then `r0 = a + r7` for the func_02152a24 argument and `r7 = a +
// r7` later; ours adds first (`r1 = i * 12`, `r7 = a + r1`, `r0 = r7`), 4 words differ, same size
void func_ov000_0219d2e8(Unk02152490 *a, s32 b) {
    s32 c;
    s32 d;
    s32 i;
    u8 e[0x18];
    Unk0218ec44 f;
    s32 g;
    if (data_ov000_021b5664->mUnk_1e == 0) {
        func_ov000_0219d034(func_ov000_0218ed44(data_ov000_021b5664->mUnk_04, &c));
        for (d = 0; d < c; d++) {
            func_ov000_0219d034(func_ov000_0218ec44(data_ov000_021b5664->mUnk_04, d, &f));
            for (i = 0; i < b; i++) {
                if (f.mUnk_000 == func_ov000_0219d630(i)) {
                    if (func_02152a24(&a[i]) == 0) {
                        func_02152468(&a[i], f.mUnk_000);
                        func_021529bc(&a[i]);
                        data_ov000_021b5664->mUnk_1d = 1;
                    }
                    break;
                }
            }
            if (i == b) {
                func_ov000_0219d034(func_ov000_0218eb44(data_ov000_021b5664->mUnk_04, f.mUnk_000));
                c--;
                d--;
            }
        }
        data_ov000_021b5664->mUnk_1e = 1;
    }
    for (; data_ov000_021b5664->mUnk_1c < b; data_ov000_021b5664->mUnk_1c++) {
        g = func_ov000_0219d630(data_ov000_021b5664->mUnk_1c);
        if (g != 0) {
            if (func_ov000_0219d210(a, data_ov000_021b5664->mUnk_1c, g) == 0 &&
                func_02152a24(&a[data_ov000_021b5664->mUnk_1c]) == 0) {
                func_ov000_0219d034(func_ov000_0218ebe8(data_ov000_021b5664->mUnk_04, g, &d));
                if (d == -1) {
                    func_ov000_0219d128(g);
                }
            }
        } else if (func_02152520((void *) func_ov000_0219c9c4(), &a[data_ov000_021b5664->mUnk_1c]) == -1) {
            func_02152458(func_ov000_0219c9c4(), &a[data_ov000_021b5664->mUnk_1c], e);
            func_ov000_0218f0a8(data_ov000_021b5664->mUnk_04, 0, 0, 0, 0, (s8 *) e, 0, 0,
                                (Unk0218f0a8Cb) func_ov000_0219ce48, data_ov000_021b5664->mUnk_1c);
            data_ov000_021b5664->mUnk_1e = 2;
            return;
        }
    }
}
