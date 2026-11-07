#include "Main/Unknown/code_020a9cd4.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0209b634.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_020aa81c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020d278c.h"
#include "Main/Unknown/code_020d2090.h"
#include "Main/Unknown/code_02109110.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/code_020ab000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02167000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_02146cbc.h"

#pragma opt_propagation off

#pragma thumb on

void MoveKeyboardCursorToValue(u16 a) {
    KeyboardRect *p;
    u16 v;

    p = FindKeyboardRectByValue(a);
    if (p != NULL) {
        gKeyboardKeys.mCursorRect = p;
        if (gKeyboardKeys.mCursorCallback != NULL) {
            v = gKeyboardKeys.mCursorCallback(GetKeyboardRectValue(p), 0);
            if (v != 0) {
                gKeyboardKeys.mCursorRect = FindKeyboardRectByValue(v);
            }
        }
    }
}

s32 GetKeyboardCursorValue(void) {
    return GetKeyboardRectValue(gKeyboardKeys.mCursorRect);
}

s32 GetKeyboardChosenKeyValue(void) {
    return GetKeyboardValueForKeyId(data_0217b2b8[0]);
}

#pragma thumb off

void InitIronBall(IronBall *p) {
    Vec3 v = data_02167974;

    SetMapObjectScale(&p->mUnk_000, &v);
    p->mUnk_000.mSound = HeapAlloc(GetHeap(func_020364e8()), 0x44);
    InitSoundSource(&p->mUnk_000.mSound->mSoundSource, 10, &p->mUnk_000.mPos);
    p->mUnk_000.mFarDistanceSquared = gSoundFalloffs[10].mUnk_20;
    p->mUnk_128 = DecimalNonZeroDigitsToBitMask(p->mUnk_000.mCourseMapRow->mUnk_34);
}

u32 func_020a9de4(Unk020a9224 *p, void *a, u8 *b, u8 *c) {
    u32 x = *b;
    u32 y = *c;

    if (x == 1) {
        p->mUnk_c0 = 0xa000;
        return 0;
    }
    return (u8) y;
}

void CreateIronBall(void *a) {
    gIronBall = CreateMapObjectModelNsbmd(a, gIronBallNsbmdName);
    SetMapObjectModelPolygonId(gIronBall, 0x3f);
}

void SetupDrawIronBall(void *a) {
    func_0209bbd0(a, gIronBall);
}

void DrawIronBall(void *a, IronBall *p) {
    u32 v;
    u8 v1[0x28];
    s32 i;

    v = 0x1e;
    func_01ff9048(0x14, &v, 1);
    func_01ff9048(0x19, func_020e6cf8(&p->mUnk_000.mPos), 0xc);
    if (p->mUnk_0a0 != 0) {
        i = (u16) p->mUnk_0a0 >> 4;
        MTX_RotZ33_((s32 *) v1, gPairsByAngle[i * 2], gPairsByAngle[i * 2 + 1]);
        func_01ff9048(0x1a, v1, 9);
    }
    func_01ff9048(0x1b, &p->mUnk_000.mScale, 3);
    DrawMapObjectModel(a, gIronBall, p);
}
