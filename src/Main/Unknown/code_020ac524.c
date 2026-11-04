#include "Main/Unknown/code_0209b634.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_020a10f0.h"
#include "Main/Unknown/code_020ac524.h"

#include "Main/Unknown/code_020ac6a8.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_02100084.h"
#include "Main/Unknown/code_021000c8.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_020d2dec.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020ac67c.h"
#include "ITCM/code_01ff8000.h"
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

void func_020ac890(void *a, ShineBalloonObject *b) {
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
    func_01ff9048(0x19, func_020e6cf8(&b->mUnk_00.mPos), 0xc);
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
    Vec3Sub(&b->mUnk_00.mPos, &((Unk02061808 *) func_02061808())->mUnk_024, &v1);
    v5 = Vec3Length(&v1);
    v4.x = v5;
    v4.y = v5;
    v4.z = v5;
    func_01ff9048(0x1b, &v4, 3);
    func_0209bb2c(a, gShineBalloon, b);
}

void func_020ac6a8(void *a, ShineBalloonObject *b) {
    switch (b->mState) {
        case 0:
            if (func_020a1154(b->mUnk_ac->mIndex) == 0) {
                return;
            }
            b->mTimer = 0x1e;
            b->mUnk_a4 = 0x19;
            b->mState = 1;
            b->mUnk_00.mFlags &= ~2;
            b->mUnk_00.mFlags &= ~8;
            b->mUnk_00.mUnk_66 = 0x1f;
            break;
        case 1:
            if (b->mTimer-- > 0) {
                return;
            }
            b->mTimer = 0;
            b->mUnk_a0 += b->mUnk_a4;
            b->mUnk_a4 -= 4;
            if (b->mUnk_a4 < 0) {
                if (b->mUnk_a0 <= 0x4a) {
                    b->mUnk_a0 = 0x4a;
                    b->mState = 2;
                }
            }
            b->mUnk_00.mPos = b->mUnk_ac->mPos;
            break;
        case 2:
            if (func_020a1154(b->mUnk_ac->mIndex) == 0) {
                b->mTimer = 0x1e;
                b->mUnk_a4 = 8;
                b->mState = 3;
            }
            b->mUnk_00.mPos = b->mUnk_ac->mPos;
            break;
        case 3:
            if (b->mTimer-- <= 0) {
                b->mTimer = 0;
                b->mUnk_a0 += b->mUnk_a4;
                b->mUnk_a4 -= 4;
                if (b->mUnk_a4 < 0) {
                    if (b->mUnk_a0 <= 0) {
                        b->mUnk_a0 = 0;
                        b->mState = 0;
                        b->mUnk_00.mFlags |= data_02156838;
                        b->mUnk_00.mFlags |= data_0215683c;
                    }
                }
            }
            b->mUnk_00.mPos = b->mUnk_ac->mPos;
            break;
    }
}

void func_020ac67c(void) {
    func_0209bfa8(NULL, NULL, NULL, (u32) 1, (u16) 0);
}

void *func_020ac658(void) {
    return (void *) func_0209bef0(CreateShineBalloon, func_020ac890, func_020ac9b0);
}

void *func_020ac63c(void) {
    return (void *) func_0209bf48(NULL, func_020ac6a8, NULL);
}

void func_020ac5e4(Kart *a) {
    ShineBalloonObject *o;

    o = func_0209bbfc(func_02100138(0x70));
    if (o == NULL) {
        return;
    }
    o->mUnk_00.mPos.x = 0;
    o->mUnk_00.mPos.y = 0;
    o->mUnk_00.mPos.z = 0;
    o->mUnk_00.mUnk_10.x = 0;
    o->mUnk_00.mUnk_10.y = 0;
    o->mUnk_00.mUnk_10.z = 0;
    o->mUnk_ac = a;
    o->mUnk_a0 = 0;
    o->mUnk_a4 = 0;
    o->mTimer = 0;
    o->mState = 0;
}

void func_020ac588(u32 a, s32 b, void *c) {
    s32 i;
    MapObject *e;

    for (i = 0; i < b; i++) {
        e = CreateMapObjectFromObject(c, a);
        if ((e->mFlags & 0x100) == 0) {
            func_020d2398(e);
        }
    }
}

void *func_020ac524(s32 a) {
    Unk02100094 *v1;
    void **v2;
    s32 n;
    s32 i;
    MapObject *e;

    v1 = func_02100138(a);
    v2 = func_0210008c(v1);
    n = func_021000c8(v1);
    for (i = 0; i < n; i++) {
        e = v2[i];
        if (e->mFlags & 0x100) {
            return e;
        }
    }
    return NULL;
}
