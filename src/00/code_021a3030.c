#include "00/code_021a3030.h"
#include "00/code_0219b000.h"
#include "00/code_0219b9c4.h"
#include "00/code_0219bb50.h"
#include "00/code_021a2e7c.h"
#include "00/code_021a2eec.h"
#include "00/code_021a2ccc.h"
#include "00/code_021a2f98.h"
#include "00/unk_021b5000.h"
#include "code_0200f5ac.h"
#include "code_021329f8.h"

void func_ov000_021a317c(Unk0219887c *a, void *b, s32 c, u32 d) {
    if (data_ov000_021b5dd0 != 0) {
        if (d != 0) {
            func_ov000_021a2eec(a, b, c);
        } else {
            func_ov000_021a2e7c(a, (u32) b, c);
        }
    }
}

void func_ov000_021a314c(Unk0219887c *a, u32 b) {
    if (data_ov000_021b5dd0->mUnk_60c != 0) {
        data_ov000_021b5dd0->mUnk_60c(b, func_ov000_0219b9c4(a));
    }
}

void func_ov000_021a3030(void) {
    u8 *l;
    s32 n;
    s32 i;
    u8 d;
    Unk021a2d68 *e;
    s32 m;
    s32 k;
    u64 t;
    if (data_ov000_021b5dd0 != 0) {
        n = func_ov000_0219bb04(&l);
        for (i = 0; i < n; i++) {
            d = l[i];
            if (d != func_ov000_0219bb50() && func_ov000_021a2fc8(d) == 1) {
                e = (Unk021a2d68 *) func_ov000_021a2fdc(d);
                m = e->mUnk_14 - e->mUnk_0c;
                k = data_ov000_021b5dd0->mUnk_610;
                if (m <= k) {
                    k = m;
                }
                if (func_ov000_021a2d18(d) < k) {
                    continue;
                }
                func_ov000_021a2f98(d, (u32) (e->mUnk_00 + e->mUnk_0c), k, 1);
                e->mUnk_0c += k;
                if (e->mUnk_0c == e->mUnk_14) {
                    if (data_ov000_021b5dd0->mUnk_600 != 0) {
                        data_ov000_021b5dd0->mUnk_600(e->mUnk_14, d);
                    }
                    e->mUnk_1c = 0;
                    e->mUnk_00 = 0;
                    e->mUnk_0c = 0;
                    e->mUnk_14 = 0;
                }
            }
            if (func_ov000_0219bac8(d) != 0) {
                e = (Unk021a2d68 *) func_ov000_021a2fdc(d);
                if (data_ov000_021b5dd0->mUnk_608 != 0 && e->mUnk_2c != 0) {
                    t = func_0200f5ac();
                    if ((u32) _ll_udiv((t - e->mUnk_24) << 6, 0x82ea) > e->mUnk_2c) {
                        data_ov000_021b5dd0->mUnk_608(d);
                        e->mUnk_24 = t;
                    }
                }
            }
        }
    }
}
