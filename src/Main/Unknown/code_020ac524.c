#include "Main/Unknown/code_020ac524.h"

#include "Main/Unknown/code_020ac6a8.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_02100084.h"
#include "Main/Unknown/code_021000c8.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_020d2dec.h"
#include "Main/Unknown/code_020d22e0.h"
#include "Main/Unknown/code_020ac67c.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a2000.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020ac9fc.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"

void func_020ac9fc(u32 arg0) {
    u32 value0 = arg0;
    u32 value12;
    value12 = (u32) &func_020d2398;
    func_020d2398((void *) value0);
}

void CreateShineBalloon(void *a) {
    void *p;

    p = func_0209bd08(a, "shine_balloon.nsbmd");
    gShineBalloon = p;
    func_0209b940(p, 0x3f);
}

void func_020ac9b0(void *a) {
    func_0209bbd0(a, gShineBalloon);
}

void func_020ac890(void *a, Unk020ac5e4 *b) {
    s32 s0;
    Vec3 v1;
    Vec3 v2;
    Vec3 v3;
    Vec3 v4;
    s32 t;
    s32 v5;

    if (b->mUnk_ac->mUnk_384 == 0) {
        return;
    }
    s0 = 0x1e;
    func_01ff9048(0x14, &s0, 1);
    func_01ff9048(0x19, func_020e6cf8(&b->mUnk_00.mUnk_04), 0xc);
    v2.y = func_020a23a0(b->mUnk_ac) >> 4;
    v2.x = 0;
    v2.z = 0;
    func_01ff9048(0x1c, &v2, 3);
    t = b->mUnk_a0;
    if (t != 0x1000) {
        v3.x = t;
        v3.y = t;
        v3.z = t;
        func_01ff9048(0x1b, &v3, 3);
    }
    func_01ff9048(0x1b, &b->mUnk_00.mUnk_1c, 3);
    func_021484d0(&b->mUnk_00.mUnk_04, &((Unk02061808 *) func_02061808())->mUnk_024, &v1);
    v5 = func_021482cc(&v1);
    v4.x = v5;
    v4.y = v5;
    v4.z = v5;
    func_01ff9048(0x1b, &v4, 3);
    func_0209bb2c(a, gShineBalloon, b);
}

void func_020ac6a8(void *a, Unk020ac5e4 *b) {
    switch (b->mUnk_b0) {
        case 0:
            if (func_020a1154(b->mUnk_ac->mUnk_74) == 0) {
                return;
            }
            b->mUnk_a8 = 0x1e;
            b->mUnk_a4 = 0x19;
            b->mUnk_b0 = 1;
            b->mUnk_00.mUnk_02 &= ~2;
            b->mUnk_00.mUnk_02 &= ~8;
            b->mUnk_00.mUnk_66 = 0x1f;
            break;
        case 1:
            if (b->mUnk_a8-- > 0) {
                return;
            }
            b->mUnk_a8 = 0;
            b->mUnk_a0 += b->mUnk_a4;
            b->mUnk_a4 -= 4;
            if (b->mUnk_a4 < 0) {
                if (b->mUnk_a0 <= 0x4a) {
                    b->mUnk_a0 = 0x4a;
                    b->mUnk_b0 = 2;
                }
            }
            b->mUnk_00.mUnk_04 = b->mUnk_ac->mUnk_80;
            break;
        case 2:
            if (func_020a1154(b->mUnk_ac->mUnk_74) == 0) {
                b->mUnk_a8 = 0x1e;
                b->mUnk_a4 = 8;
                b->mUnk_b0 = 3;
            }
            b->mUnk_00.mUnk_04 = b->mUnk_ac->mUnk_80;
            break;
        case 3:
            if (b->mUnk_a8-- <= 0) {
                b->mUnk_a8 = 0;
                b->mUnk_a0 += b->mUnk_a4;
                b->mUnk_a4 -= 4;
                if (b->mUnk_a4 < 0) {
                    if (b->mUnk_a0 <= 0) {
                        b->mUnk_a0 = 0;
                        b->mUnk_b0 = 0;
                        b->mUnk_00.mUnk_02 |= data_02156838;
                        b->mUnk_00.mUnk_02 |= data_0215683c;
                    }
                }
            }
            b->mUnk_00.mUnk_04 = b->mUnk_ac->mUnk_80;
            break;
    }
}

void func_020ac67c(void) {
    func_0209bfa8(0, 0, 0, (u32) 1, (u16) 0);
}

void *func_020ac658(void) {
    return (void *) func_0209bef0(CreateShineBalloon, func_020ac890, func_020ac9b0);
}

void *func_020ac63c(void) {
    return (void *) func_0209bf48(0, func_020ac6a8, 0);
}

void func_020ac5e4(Unk0206bcb0 *a) {
    Unk020ac5e4 *o;

    o = func_0209bbfc(func_02100138(0x70));
    if (o == 0) {
        return;
    }
    o->mUnk_00.mUnk_04.x = 0;
    o->mUnk_00.mUnk_04.y = 0;
    o->mUnk_00.mUnk_04.z = 0;
    o->mUnk_00.mUnk_10.x = 0;
    o->mUnk_00.mUnk_10.y = 0;
    o->mUnk_00.mUnk_10.z = 0;
    o->mUnk_ac = a;
    o->mUnk_a0 = 0;
    o->mUnk_a4 = 0;
    o->mUnk_a8 = 0;
    o->mUnk_b0 = 0;
}

void func_020ac588(u32 a, s32 b, void *c) {
    s32 i;
    Unk020e71a0 *e;

    for (i = 0; i < b; i++) {
        e = func_020d34d4(c, a);
        if ((e->mUnk_02 & 0x100) == 0) {
            func_020d2398(e);
        }
    }
}

void *func_020ac524(s32 a) {
    Unk02100094 *v1;
    void **v2;
    s32 n;
    s32 i;
    Unk020e71a0 *e;

    v1 = func_02100138(a);
    v2 = func_0210008c(v1);
    n = func_021000c8(v1);
    for (i = 0; i < n; i++) {
        e = v2[i];
        if (e->mUnk_02 & 0x100) {
            return e;
        }
    }
    return 0;
}
