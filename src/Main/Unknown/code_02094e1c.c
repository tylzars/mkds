#include "Main/Unknown/code_02094e1c.h"
#include "Main/Unknown/code_02061808.h"
#include "Main/Unknown/code_02093ff0.h"
#include "Main/Unknown/code_02094000.h"
#include "Main/Unknown/code_020946b8.h"
#include "Main/Unknown/code_02095228.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020918a8.h"
#include "Main/Unknown/code_0209520c.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020d26e0.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"

void func_02094e1c(void) {
    func_0209bf48((u32) func_02095228, (u32) func_02094e8c, 0);
}

u32 func_02094e3c(void) {
    s32 m;

    m = data_021759c0->mUnk_08;
    if (m == 3 || m == 5) {
        if (func_02061818() == 0) {
            return 0;
        }
    }
    return func_0209bf8c();
}

void func_02094e8c(void *a, Unk02094e8c *o) {
    s32 t;
    s32 c;
    s32 e;
    s32 v1;
    s32 v2;
    s32 i;
    s32 k;
    s32 x;
    s32 y;
    s32 z;
    float f;
    u32 r;
    u16 q;
    Unk0206bcb0 *g;
    Vec3 v;
    Vec3 *q2;

    t = o->mUnk_a0;
    o->mUnk_a0 = t - 1;
    if (t <= 0) {
        o->mUnk_a0 = 0xf;
        c = o->mUnk_00.mUnk_9c->mUnk_28;
        g = func_0207a974((u16) data_021759c0->mUnk_62);
        e = c << 12;
        q2 = &g->mUnk_80;
        v1 = q2->x - o->mUnk_00.mUnk_04.x;
        v2 = q2->z - o->mUnk_00.mUnk_04.z;
        if ((s64) v1 * v1 + (s64) v2 * v2 < (s64) e * e) {
            o->mUnk_a4 = 1;
        } else {
            o->mUnk_a4 = 0;
        }
    }
    switch (o->mUnk_ac) {
        case 0:
            k = 0;
            if (func_02061818() == 2) {
                for (i = 0; i < o->mUnk_00.mUnk_9c->mUnk_2a; i++) {
                    if (o->mUnk_00.mUnk_9c->mUnk_28 > 0) {
                        f = 0.5f + (float) (o->mUnk_00.mUnk_9c->mUnk_28 << 12);
                    } else {
                        f = (float) (o->mUnk_00.mUnk_9c->mUnk_28 << 12) - 0.5f;
                    }
                    z = o->mUnk_00.mUnk_04.z;
                    y = o->mUnk_00.mUnk_04.y;
                    x = o->mUnk_00.mUnk_04.x;
                    r = func_02091f6c(func_0209520c(), (s32) f);
                    q = func_020951b4(func_0209520c());
                    v.x = x + func_0209518c(r, func_0209519c(q));
                    v.y = y + func_02091f6c(func_0209520c(), k);
                    v.z = z + func_0209518c(r, func_0209516c(q));
                    func_02094000(&v);
                }
            }
            o->mUnk_ac = 1;
        case 1:
            if (func_02061818() == 2) {
                break;
            }
            if (o->mUnk_a4 == 0) {
                break;
            }
            if (func_02061818() != 0) {
                func_020952dc(o, 0x1e, 0x14, 0x1f4, 4);
            } else {
                func_020952dc(o, 6, 4, 0xa, 0x14);
            }
            o->mUnk_ac = 2;
            break;
        case 2:
            t = o->mUnk_a8;
            o->mUnk_a8 = t - 1;
            if (t > 0) {
                break;
            }
            if (o->mUnk_a4 != 0) {
                if (func_02061818() != 0) {
                    func_020952dc(o, 0x1e, 1, 0x1f4, 4);
                } else {
                    func_020952dc(o, 6, 1, 0xa, 0x14);
                }
            } else {
                func_020946b8();
                o->mUnk_ac = 1;
            }
            break;
    }
    if (func_02093ff0() > 0) {
        func_020d26e0(func_0207a974((u16) data_021759c0->mUnk_62), 0x11e);
    }
}

s16 func_0209516c(s32 a) {
    return data_0215d4b4[(a >> 4) * 2 + 1];
}

s32 func_0209518c(s32 a, s32 b) {
    return (s32) (((s64) a * b) >> 12);
}

s16 func_0209519c(s32 a) {
    return data_0215d4b4[(a >> 4) * 2];
}

u16 func_020951b4(Unk020f41c4_B *a) {
    a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
    return (u16) (((a->mUnk_00 >> 32) * 0x10000) >> 32);
}
