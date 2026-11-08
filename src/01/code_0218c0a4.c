#include "01/code_0218c0a4.h"
#include "01/code_02187eb0.h"
#include "01/code_02188cd8.h"
#include "01/code_02188de0.h"
#include "01/code_02185ef4.h"
#include "01/code_02187000.h"
#include "01/code_02188000.h"
#include "01/code_02188218.h"
#include "01/code_02188e24.h"
#include "01/code_0218c584.h"
#include "01/code_0218c5fc.h"
#include "01/code_0219b1c4.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f49bc.h"
#include "01/code_02187d14.h"
#include "01/code_0218c000.h"
#include "Main/Unknown/code_020f4000.h"
#include "Main/Unknown/unk_0217c000.h"

void func_ov001_0218c490(Unk02188950 *a) {
    Kart *p = GetKart((u16) gRaceSetup->mEntryIndex);

    func_ov001_02187218(a, 2, func_ov001_0218c5d4);
    func_ov001_02188d64(a, a->mPrm->mUnk_104, a->mPrm->mUnk_108);
    func_ov001_0219b1c4(a->mNsbmd, a->mPrm->mUnk_10c, a->mPrm->mUnk_108, 0);
    func_ov001_02188cd8(a, a->mPrm->mUnk_110, a->mPrm->mUnk_114);
    func_ov001_02188c48(a, a->mPrm->mUnk_118, a->mPrm->mUnk_11c);
    SetAnglePointAndMoveAnglePoint(a, &p->mPos);
    func_ov001_02188e24(a, a->mPrm->mUnk_12c, NULL);
    func_ov001_0218c5fc(a);
}

void func_ov001_0218c3ac(Unk02188950 *a) {
    if (func_ov001_02188220(a) == 0) {
        func_ov001_02188cd8(a, a->mPrm->mUnk_0a4, a->mPrm->mUnk_0a8);
        func_ov001_02188c48(a, a->mPrm->mUnk_0ac, a->mPrm->mUnk_0b0);
    } else if (func_ov001_02188220(a) == 1) {
        func_ov001_02188cd8(a, a->mPrm->mUnk_0bc, a->mPrm->mUnk_0c0);
        func_ov001_02188c48(a, a->mPrm->mUnk_0c4, a->mPrm->mUnk_0c8);
    } else {
        func_ov001_02188cd8(a, a->mPrm->mUnk_0cc, a->mPrm->mUnk_0d0);
        func_ov001_02188c48(a, a->mPrm->mUnk_0d4, a->mPrm->mUnk_0d8);
    }
    SetAnglePointAndMoveAnglePoint(a, &func_ov001_02187fc0(a)->mPos);
    func_ov001_02188e24(a, a->mPrm->mUnk_0b8, NULL);
    func_ov001_02188de0(a, a->mPrm->mUnk_0b4, 0, &func_ov001_02187fc0(a)->mPos, NULL);
}

void func_ov001_0218c354(Unk02188950 *a) {
    func_ov001_02187218(a, 1, func_ov001_0218c5ac);
    func_ov001_02188d64(a, a->mPrm->mUnk_098, a->mPrm->mUnk_09c);
    func_ov001_0219b1c4(a->mNsbmd, a->mPrm->mUnk_0a0, a->mPrm->mUnk_09c, 0);
    func_ov001_0218c3ac(a);
    func_ov001_0218c5fc(a);
}

void func_ov001_0218c0a4(Unk02188950 *a) {
    MissionRunPrm *a0;
    RandomState64 *r;
    u32 n1;
    u32 n2;
    u32 m1;
    u32 m2;
    u32 t1;
    u32 t2;
    u16 res1;
    u16 res2;
    s32 sel;
    s32 angle;
    s32 radius;
    s32 i;

    a0 = a->mPrm;
    angle = a->mAngle - a0->mUnk_1a4 * (a->mUnk_138 / 2);
    n1 = a0->mUnk_1a8;
    if (n1 == 0x10000) {
        r = GetMapObjectRandom();
        r->mValue = r->mIncrement + (s64) r->mMultiplier * (s64) r->mValue;
        res1 = (r->mValue >> 32) * 0x10000 >> 32;
    } else {
        r = GetMapObjectRandom();
        if ((u16) n1 == 0) {
            t1 = 0;
        } else {
            r->mValue = r->mIncrement + (s64) r->mMultiplier * (s64) r->mValue;
            m1 = (u16) n1;
            if (m1 == 0) {
                t1 = r->mValue >> 32;
            } else {
                t1 = ((s64) (r->mValue >> 32) * m1) >> 32;
            }
        }
        res1 = t1;
    }
    if (res1 == 0) {
        n2 = a->mUnk_138;
        if (n2 == 0x10000) {
            r = GetMapObjectRandom();
            r->mValue = r->mIncrement + (s64) r->mMultiplier * (s64) r->mValue;
            res2 = (r->mValue >> 32) * 0x10000 >> 32;
        } else {
            r = GetMapObjectRandom();
            if ((u16) n2 == 0) {
                t2 = 0;
            } else {
                r->mValue = r->mIncrement + (s64) r->mMultiplier * (s64) r->mValue;
                m2 = (u16) n2;
                if (m2 == 0) {
                    t2 = r->mValue >> 32;
                } else {
                    t2 = ((s64) (r->mValue >> 32) * m2) >> 32;
                }
            }
            res2 = t2;
        }
        sel = res2;
    } else {
        sel = -1;
    }
    radius = a->mPrm->mUnk_198;
    for (i = 0; i < a->mUnk_138; i++) {
        Vec3 pos;
        Vec3 vel = {0, 0, 0};

        pos.x = a->mUnk_000.mPos.x + (((s64) radius * gPairsByAngle[((u16) angle >> 4) * 2]) >> 12);
        pos.y = a->mUnk_000.mPos.y + a->mPrm->mUnk_194;
        pos.z = a->mUnk_000.mPos.z + (((s64) radius * gPairsByAngle[((u16) angle >> 4) * 2 + 1]) >> 12);
        vel.x = ((s64) a->mPrm->mUnk_1a0 * gPairsByAngle[((u16) angle >> 4) * 2]) >> 12;
        vel.y = a->mPrm->mUnk_19c;
        vel.z = ((s64) a->mPrm->mUnk_1a0 * gPairsByAngle[((u16) angle >> 4) * 2 + 1]) >> 12;
        if (i == sel) {
            ThrowItemKinokoFromPosition(StartItemKinokoOrZero(), &pos, &vel, a->mPrm->mUnk_1ac);
        } else {
            ThrowItemBombFromPosition(StartItemBombWithParkedKuribo(), &pos, &vel, a->mPrm->mUnk_1b0);
        }
        angle += a->mPrm->mUnk_1a4;
        StartEffect(0x3f7, &pos);
        StartEffect(0x3f6, &pos);
    }
    StartMapObjectSound(&a->mUnk_000, 0x222);
}
