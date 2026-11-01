#include "Main/Unknown/code_020e2fe4.h"
#include "Main/Unknown/code_020f8000.h"

#include "code_02147cd8.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/unk_021759c0.h"

void func_020e3238(Unk020e1e98 *a) {
    a->mUnk_000.mUnk_10.y -= 0x266;
    a->mUnk_000.mUnk_04.y = a->mUnk_000.mUnk_04.y + a->mUnk_000.mUnk_10.y;
    if (a->mUnk_000.mUnk_04.y < a->mUnk_0b0) {
        Unk020e005c_080 *p = &a->mUnk_000.mUnk_80;

        p->mUnk_10 = 5;
        p->mUnk_12 = 1;
    }
    if (a->mUnk_0b4.mUnk_00 != 0) {
        a->mUnk_0b4.mUnk_04 += 0x400;
    } else {
        a->mUnk_0b4.mUnk_04 -= 0x400;
    }
}

u8 func_020e311c(Unk020e1e98 *a, Unk0206bcb0 *b, u8 *c, u8 *d) {
    Vec3 v;

    switch (c[0]) {
        case 2:
            if (data_021759c0->mUnk_68[b->mUnk_74].mUnk_08.mUnk_00 == 2) {
                return d[0];
            }
            if (a->mUnk_000.mUnk_80.mUnk_0e == 7) {
                return d[0];
            }
            a->mUnk_000.mUnk_80.mUnk_10 = 7;
            a->mUnk_000.mUnk_80.mUnk_12 = 1;
            func_020d26f8(&a->mUnk_000, b);
            break;
        case 1:
            func_021484d0(&a->mUnk_000.mUnk_04, &b->mUnk_80, &v);
            if ((s64) v.z * b->mUnk_a4.x - (s64) v.x * b->mUnk_a4.z < 0) {
                a->mUnk_0b4.mUnk_00 = 1;
            } else {
                a->mUnk_0b4.mUnk_00 = 0;
            }
            a->mUnk_000.mUnk_10.y = 0x4000;
            a->mUnk_000.mUnk_80.mUnk_10 = 6;
            a->mUnk_000.mUnk_80.mUnk_12 = 1;
            a->mUnk_000.mUnk_02 |= data_02158bb4;
            func_020d26f8(&a->mUnk_000, b);
            break;
    }
    return d[0];
}

u8 func_020e2fe4(Unk020e1e98 *a, Unk020e246c *b, u8 *c, u8 *d) {
    Vec3 v;
    Vec3 w;

    if (c[0] == 1) {
        if (b != 0) {
            func_021484d0(&a->mUnk_000.mUnk_04, &b->mUnk_050, &v);
            if ((s64) v.z * b->mUnk_05c - (s64) v.x * b->mUnk_064 < 0) {
                a->mUnk_0b4.mUnk_00 = 1;
            } else {
                a->mUnk_0b4.mUnk_00 = 0;
            }
            a->mUnk_000.mUnk_10.y = 0x4000;
            a->mUnk_000.mUnk_80.mUnk_10 = 6;
            a->mUnk_000.mUnk_80.mUnk_12 = 1;
            a->mUnk_000.mUnk_02 |= data_02158bb4;
            func_020f8ddc(b);
        } else {
            func_021484d0(&a->mUnk_000.mUnk_04, &a->mUnk_000.mUnk_04, &w);
            if ((s64) w.z * data_02158c7c.x - (s64) w.x * data_02158c7c.z < 0) {
                a->mUnk_0b4.mUnk_00 = 1;
            } else {
                a->mUnk_0b4.mUnk_00 = 0;
            }
            a->mUnk_000.mUnk_10.y = 0x4000;
            a->mUnk_000.mUnk_80.mUnk_10 = 6;
            a->mUnk_000.mUnk_80.mUnk_12 = 1;
            a->mUnk_000.mUnk_02 |= data_02158bb4;
        }
    }
    return d[0];
}
