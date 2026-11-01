#include "00/code_0219d14c.h"
#include "00/code_0219d630.h"
#include "00/code_0219d934.h"
#include "Main/Unknown/code_02152000.h"
#include "Main/Unknown/code_02152468.h"
#include "Main/Unknown/code_02152a1c.h"
#include "code_0214d018.h"

void func_ov000_0219d288(Unk02152490 *a, s32 b, s32 c) {
    if (data_ov000_021b5664 != 0) {
        func_0214d168(&a[b], 0, 12);
        if (data_ov000_021b5664->mUnk_3c != 0) {
            data_ov000_021b5664->mUnk_3c(b, c, data_ov000_021b5664->mUnk_40);
        }
    }
}

s32 func_ov000_0219d210(Unk02152490 *a, s32 b, s32 c) {
    s32 i;
    s32 j;
    for (i = 0; i < b; i++) {
        j = func_ov000_0219d630(i);
        if (j != 0 && j == c) {
            if (func_02152a24(&a[b]) != 0 && func_02152a24(&a[i]) == 0) {
                func_ov000_0219d288(a, i, b);
            } else {
                func_ov000_0219d288(a, b, i);
            }
            data_ov000_021b5664->mUnk_1d = 1;
            return 1;
        }
    }
    return 0;
}

s32 func_ov000_0219d14c(Unk02152490 *a, s32 b, s32 c) {
    s32 l;
    s32 i;
    s32 j;
    s32 k;
    Unk02152490 *p;
    Unk02152490 *q;
    Unk02152490 *r;
    i = 0;
    l = -1;
    if (b - 1 > 0) {
        p = a;
        q = a;
        do {
            k = func_ov000_0219d630(i);
            if (k != 0) {
                if (k == c) {
                    l = i;
                }
                j = i + 1;
                if (j < b) {
                    r = &a[j];
                    do {
                        if (k == func_ov000_0219d630(j)) {
                            if (func_02152a1c(p) == 2 && func_02152a1c(r) == 3) {
                                func_02152468(q, k);
                            }
                            if (func_02152a24(r) != 0) {
                                func_021529bc(q);
                            }
                            func_ov000_0219d288(a, j, i);
                            data_ov000_021b5664->mUnk_1d = 1;
                        }
                        r++;
                        j++;
                    } while (j < b);
                }
            }
            p++;
            q++;
            i++;
        } while (i < b - 1);
    }
    return l;
}
