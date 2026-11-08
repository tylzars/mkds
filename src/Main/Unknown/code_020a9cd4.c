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

void MoveKeyboardCursorToValue(u16 value) {
    KeyboardRect *foundRect;
    u16 callbackValue;

    foundRect = FindKeyboardRectByValue(value);
    if (foundRect != NULL) {
        gKeyboardKeys.mCursorRect = foundRect;
        if (gKeyboardKeys.mCursorCallback != NULL) {
            callbackValue = gKeyboardKeys.mCursorCallback(GetKeyboardRectValue(foundRect), 0);
            if (callbackValue != 0) {
                gKeyboardKeys.mCursorRect = FindKeyboardRectByValue(callbackValue);
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

void InitIronBall(IronBall *ironBall) {
    Vec3 scale = data_02167974;

    SetMapObjectScale(&ironBall->mUnk_000, &scale);
    ironBall->mUnk_000.mSound = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x44);
    InitSoundSource(&ironBall->mUnk_000.mSound->mSoundSource, 10, &ironBall->mUnk_000.mPos);
    ironBall->mUnk_000.mFarDistanceSquared = gSoundFalloffs[10].mUnk_20;
    ironBall->mUnk_128 = DecimalNonZeroDigitsToBitMask(ironBall->mUnk_000.mCourseMapRow->mUnk_34);
}

u32 CollideKartWithIronBall(Unk020a9224 *ironBall, void *kart, u8 *b, u8 *c) {
    u32 x = *b;
    u32 y = *c;

    if (x == 1) {
        ironBall->mUnk_c0 = 0xa000;
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

void DrawIronBall(void *a, IronBall *ironBall) {
    u32 v;
    u8 rotationMatrix[0x28];
    s32 pairIndex;

    v = 0x1e;
    func_01ff9048(0x14, &v, 1);
    func_01ff9048(0x19, SetViewTransposeMatrixPos(&ironBall->mUnk_000.mPos), 0xc);
    if (ironBall->mRotateZAngle != 0) {
        pairIndex = (u16) ironBall->mRotateZAngle >> 4;
        MTX_RotZ33_((s32 *) rotationMatrix, gPairsByAngle[pairIndex * 2], gPairsByAngle[pairIndex * 2 + 1]);
        func_01ff9048(0x1a, rotationMatrix, 9);
    }
    func_01ff9048(0x1b, &ironBall->mUnk_000.mScale, 3);
    DrawMapObjectModel(a, gIronBall, ironBall);
}
