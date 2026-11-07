#include "01/code_0218b9b4.h"
#include "01/code_02188230.h"
#include "01/code_02188cd8.h"

#include "01/code_0218b298.h"
#include "01/code_0218b2dc.h"
#include "01/unk_021a6000.h"
#include "01/code_02188000.h"
#include "01/code_0218c000.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_020d4000.h"
#include "01/code_02185ef4.h"
#include "01/code_02187d14.h"
#include "Main/Unknown/code_020f4000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "01/code_02188158.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/code_020ac000.h"
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
#include "Main/Unknown/code_02109000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020f9c6c.h"

void func_ov001_0218bee4(Unk02188950 *a) {
    Kart *unk;

    unk = GetKart((u16) data_021759c0->mEntryIndex);
    func_ov001_02187218(a, 2, (s32(*)(Unk02188950 *)) func_ov001_0218c55c);
    func_ov001_02188d30(a, a->mPrm->mUnk_184, a->mPrm->mUnk_188, func_ov001_0218bfc8);
    func_ov001_0219b1c4(a->mNsbmd, a->mPrm->mUnk_18c, a->mPrm->mUnk_188, 0);
    func_ov001_02188cd8(a, 0, a->mPrm->mUnk_144);
    func_ov001_02188a30(a, 0, a->mPrm->mUnk_154, a->mPrm->mUnk_148, a->mPrm->mUnk_14c);
    SetAnglePoint(a, &unk->mPos);
    SetMoveAnglePoint(a, &func_ov001_02187fc0(a)->mUnk_00);
    func_ov001_02188e74(a, a->mPrm->mUnk_190, func_ov001_0218c0a4);
}

void func_ov001_0218bde8(Unk02188950 *a) {
    Kart *unk;

    unk = GetKart((u16) data_021759c0->mEntryIndex);
    func_ov001_02187218(a, 2, (s32(*)(Unk02188950 *)) func_ov001_0218c55c);
    func_ov001_02188d64(a, a->mPrm->mUnk_134, a->mPrm->mUnk_138);
    func_ov001_0219b1c4(a->mNsbmd, a->mPrm->mUnk_13c, a->mPrm->mUnk_138, 0);
    func_ov001_02188cd8(a, a->mPrm->mUnk_140, a->mPrm->mUnk_144);
    func_ov001_02188a30(a, a->mPrm->mUnk_150, a->mPrm->mUnk_154, a->mPrm->mUnk_148, a->mPrm->mUnk_14c);
    SetAnglePoint(a, &unk->mPos);
    SetMoveAnglePoint(a, &func_ov001_02187fc0(a)->mUnk_00);
    func_ov001_02188e24(a, a->mPrm->mUnk_158, func_ov001_0218bee4);
    a->mUnk_138 = func_ov001_02187f7c(a);
    func_ov001_0218c5fc(a);
}

void func_ov001_0218bd80(Unk02188950 *a) {
    func_ov001_02187218(a, 7, NULL);
    func_ov001_02188d30(a, a->mPrm->mUnk_1f8, a->mPrm->mUnk_1fc, NULL);
    func_ov001_0219b1c4(a->mNsbmd, a->mPrm->mUnk_200, a->mPrm->mUnk_1fc, 0);
    func_ov001_02188c90(a);
    func_ov001_02188cec(a, 0);
    a->mUnk_000.mFlags &= ~0x20;
}

void func_ov001_0218bcc4(Unk02188950 *a) {
    Vec3 local = {0, 0, 0};

    local.y = a->mPrm->mUnk_1f4;
    func_ov001_02187218(a, 7, NULL);
    func_ov001_02188d64(a, a->mPrm->mUnk_1e0, a->mPrm->mUnk_1e4);
    func_ov001_0219b1c4(a->mNsbmd, a->mPrm->mUnk_1e8, a->mPrm->mUnk_1e4, 0);
    SetVelocity(a, &local);
    func_ov001_02188c90(a);
    func_ov001_02188cd8(a, a->mPrm->mUnk_1ec, a->mPrm->mUnk_1f0);
    func_ov001_02188db8(a, func_ov001_0218bd80);
    StartMapObjectSound(&a->mUnk_000, 0x226);
    a->mUnk_000.mFlags |= data_ov001_021a65a8;
}

void func_ov001_0218bc60(Unk02188950 *a) {
    func_ov001_02187218(a, 7, NULL);
    func_ov001_02188d30(a, a->mPrm->mUnk_1d4, a->mPrm->mUnk_1d8, func_ov001_0218bcc4);
    func_ov001_0219b1c4(a->mNsbmd, a->mPrm->mUnk_1dc, a->mPrm->mUnk_1d8, 0);
    func_ov001_02188c90(a);
    func_ov001_02188cec(a, 0);
}

void func_ov001_0218bbac(Unk02188950 *a) {
    func_ov001_02187218(a, 7, NULL);
    func_ov001_02188d64(a, a->mPrm->mUnk_1b4, a->mPrm->mUnk_1b8);
    func_ov001_0219b1c4(a->mNsbmd, a->mPrm->mUnk_1bc, a->mPrm->mUnk_1b8, 0);
    func_ov001_02188c48(a, a->mPrm->mUnk_1c8, a->mPrm->mUnk_1cc);
    SetAnglePointAndMoveAnglePoint(a, &a->mUnk_000.mCourseMapRow->mUnk_00);
    func_ov001_02188cd8(a, a->mPrm->mUnk_1c0, a->mPrm->mUnk_1c4);
    func_ov001_02188e24(a, a->mPrm->mUnk_1d0, func_ov001_0218bc60);
    func_ov001_0218c5fc(a);
}

int func_ov001_0218bb74(Unk02188950 *a) {
    if (func_ov001_02188220(a) == 1) {
        StartMapObjectSoundWhileRequested(&a->mUnk_000, 0x220);
    } else if (func_ov001_02188220(a) == 2) {
        StartMapObjectSoundWhileRequested(&a->mUnk_000, 0x221);
    }
    return 0;
}

void func_ov001_0218ba48(Unk02188950 *a) {
    func_ov001_02187218(a, 8, func_ov001_0218bb74);
    func_ov001_02188d64(a, a->mPrm->mUnk_0dc, a->mPrm->mUnk_0e0);
    func_ov001_0219b1c4(a->mNsbmd, a->mPrm->mUnk_0e4, a->mPrm->mUnk_0e0, 0);
    func_ov001_02188cd8(a, a->mPrm->mUnk_0e8, a->mPrm->mUnk_0ec);
    func_ov001_02188c48(a, a->mPrm->mUnk_0f0, a->mPrm->mUnk_0f4);
    SetAnglePointAndMoveAnglePoint(a, &func_ov001_02187fc0(a)->mUnk_00);
    func_ov001_02188e24(a, a->mPrm->mUnk_100, func_ov001_0218c354);
    func_ov001_02188d08(a, (a->mUnk_000.mScale.x + a->mPrm->mUnk_0f8), a->mPrm->mUnk_0fc);
    func_ov001_02188cec(a, 0);
    SetMapObjectModelNsbtpFrameIndex(a->mNsbmd, func_ov001_02188220(a));
    if (func_ov001_02188220(a) == 0) {
        func_ov001_0218c6b4(a);
        func_ov001_0218756c(a, 0, 0x1800, 0, 0x419, 0);
    } else if (func_ov001_02188220(a) == 1) {
        func_ov001_0218c63c(a);
        func_ov001_0218756c(a, 0, 0x1800, 0, 0x41a, 0);
    }
}

void func_ov001_0218ba34(Unk02188950 *a) {
    func_ov001_0218ba48(a);
    func_ov001_02188230(a);
}

void func_ov001_0218b9b4(Unk02188950 *a) {
    Kart *unk;

    unk = GetKart((u16) data_021759c0->mEntryIndex);
    func_ov001_02187218(a, 8, NULL);
    func_ov001_02188d64(a, a->mPrm->mUnk_078, a->mPrm->mUnk_07c);
    func_ov001_02188c48(a, a->mPrm->mUnk_20c, a->mPrm->mUnk_210);
    SetAnglePointAndMoveAnglePoint(a, &unk->mPos);
    func_ov001_02188cd8(a, a->mPrm->mUnk_204, a->mPrm->mUnk_208);
}
