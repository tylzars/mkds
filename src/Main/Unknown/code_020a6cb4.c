#include "Main/Unknown/code_020a6cb4.h"

#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a1218.h"
#include "Main/Unknown/code_020a49d4.h"
#include "Main/Unknown/code_020ac524.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061f7c.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020a7148.h"

void func_020a7148(Unk020e71a0 *param_1) {
    if (func_020d3bf8(0x6a) == 0) {
        func_020ac588(0x6a, 0x14, param_1);
        func_020ac588(0x70, data_021759c0->mUnk_3d0, param_1);
        func_020a233c(func_020a72c8);
        func_020a2328(func_020a7270);
        func_020a2314(func_020a71c8);
        return;
    }
    func_020d2398(param_1);
}

s32 func_020a6f94(Unk02100094 *a) {
    s32 i;
    s32 v1;
    Unk020a6cb4 *e;
    s32 f;
    u32 n;
    u32 m;
    u32 r;
    u16 v2;
    u32 k;
    Unk020f41c4_B *g;

    v1 = 0;
    if (a != 0) {
        for (i = 0; i < a->mUnk_04 && (e = a->mUnk_00[i]) != 0; i++) {
            f = 0;
            if (e->mUnk_a0 == 0) {
                if (e->mUnk_a4 == 0) {
                    f = 1;
                }
            }
            v1 += f;
        }
    }
    if (v1 > 0) {
        n = (u16) v1;
        if (n == 0x10000) {
            g = func_020d22d0();
            g->mUnk_00 = (s64) g->mUnk_08 * (s64) g->mUnk_00 + g->mUnk_10;
            v2 = (u16) (((u64) (u32) (g->mUnk_00 >> 32) * 0x10000) >> 32);
        } else {
            g = func_020d22d0();
            if ((u16) n == 0) {
                r = 0;
            } else {
                g->mUnk_00 = (s64) g->mUnk_08 * (s64) g->mUnk_00 + g->mUnk_10;
                m = (u16) n;
                if (m == 0) {
                    r = g->mUnk_00 >> 32;
                } else {
                    r = ((g->mUnk_00 >> 32) * m) >> 32;
                }
            }
            v2 = r;
        }
        k = v2;
        if (a != 0) {
            for (i = 0; i < a->mUnk_04 && (e = a->mUnk_00[i]) != 0; i++) {
                if (e->mUnk_a0 == 0 && e->mUnk_a4 == 0) {
                    if (k-- == 0) {
                        func_020a5744(&e->mUnk_00.mUnk_04, i, 1);
                        e->mUnk_a0 = 1;
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

void func_020a6e70(Unk02100094 *a) {
    s32 i;
    s32 n;
    s32 j;
    s32 v;
    s32 f;
    Unk020a6cb4 *e;

    n = data_021759c0->mUnk_3d0;
    for (i = 0; i < n; i++) {
        if (i == data_021759c0->mUnk_62) {
            f = 0;
            v = data_021759c0->mUnk_68[(u16) i].mUnk_08.mUnk_00;
            if ((u32) v <= 3) {
                if ((1 << v) & 0xd) {
                    f = 1;
                }
            }
            if (f != 0) {
                continue;
            }
        }
        func_020ac5e4(func_0207a974((u16) i));
    }
    if (a == 0) {
        return;
    }
    for (j = 0; j < a->mUnk_04 && (e = a->mUnk_00[j]) != 0; j++) {
        e->mUnk_a4 = 1;
        if (e->mUnk_00.mUnk_9c->mUnk_28 != 0) {
            n = data_021759c0->mUnk_3d0;
            v = func_020a1238();
            if (v + func_020a119c() < n + 1) {
                func_020a5744(&e->mUnk_00.mUnk_04, j, func_02062ec4());
                e->mUnk_a0 = 1;
            }
        }
    }
}

void func_020a6d8c(Unk02100094 *a, Unk020a6cb4 *b) {
    s32 n;
    s32 v;

    if (func_020a1238() >= 3) {
        return;
    }
    n = data_021759c0->mUnk_3d0;
    v = func_020a1238();
    if (v + func_020a119c() >= n + 1) {
        return;
    }
    b->mUnk_a8 += 1;
    if (b->mUnk_a8 <= 0x5a) {
        return;
    }
    b->mUnk_a8 = 0;
    while (func_020a1238() < 3 && (n = data_021759c0->mUnk_3d0, v = func_020a1238(), v + func_020a119c() < n + 1)) {
        if (func_020a6f94(a) == 0) {
            return;
        }
    }
}

s32 func_020a6d40(void) {
    if (data_021759c0->mUnk_08 == 2 && data_021759c0->mUnk_18 == 1) {
        return func_0209bf8c();
    }
    return 0;
}

void *func_020a6d20(void) {
    return (void *) func_0209bf48(func_020a6e70, func_020a6d8c, 0);
}

void func_020a6cb4(s32 a) {
    Unk02100094 *v1;
    Unk020a6cb4 *e;
    s32 i;

    v1 = func_02100138(0x6b);
    if (v1 == 0) {
        return;
    }
    for (i = 0; i < v1->mUnk_04 && (e = v1->mUnk_00[i]) != 0; i++) {
        if (i == a) {
            e->mUnk_a0 = 0;
            e->mUnk_a4 = 1;
        } else {
            e->mUnk_a4 = 0;
        }
    }
}
