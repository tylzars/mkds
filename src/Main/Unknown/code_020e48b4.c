#include "Main/Unknown/code_020e48b4.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020d4c28.h"

#include "Main/Unknown/code_020e48e0.h"
#include "Main/Unknown/code_020e55b4.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020ec000.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/code_020e4934.h"
#include "Main/Unknown/code_020e4990.h"
#include "Main/Unknown/code_020e49c0.h"
#include "Main/Unknown/code_020e4a18.h"
#include "Main/Unknown/code_020e4a34.h"
#include "Main/Unknown/code_020df85c.h" // MapObjectFlagsView
#include "Main/Unknown/code_020e4a68.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_020e4ab4.h"
#include "Main/Unknown/code_020e4ad0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020e337c.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020e4dec.h"
#include "Main/Unknown/code_020e4df8.h"
#include "Main/Unknown/code_020e4e08.h"
#include "Main/Unknown/code_020e5000.h"
#include "Main/Unknown/code_020e5634.h"
#include "Main/Unknown/code_020e4e9c.h"
#include "Main/Unknown/code_020e4ea8.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/unk_0217b000.h"

PukupukuKindData *CreatePukupukuKindData(void) {
    PukupukuKindData *kindData;
    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = *(PukupukuKindData *) data_02159070;
    return kindData;
}

PukupukuDrawList *CreatePukupukuDrawList(void) {
    PukupukuDrawList *drawList;
    drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    gPukupukuDrawList = drawList;
    *drawList = *(PukupukuDrawList *) data_02159044;
    func_020d49d8(&gPukupukuDrawList);
    return gPukupukuDrawList;
}

PukupukuShadowDrawList *CreatePukupukuShadowDrawList(void) {
    PukupukuShadowDrawList *shadowDrawList;
    shadowDrawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    gPukupukuShadowDrawList = shadowDrawList;
    *shadowDrawList = *(PukupukuShadowDrawList *) data_02159018;
    func_020d49d8(&gPukupukuShadowDrawList);
    return gPukupukuShadowDrawList;
}

PukupukuUpdateList *CreatePukupukuUpdateList(void) {
    PukupukuUpdateList *updateList;
    updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    gPukupukuUpdateList = updateList;
    *updateList = *(PukupukuUpdateList *) data_02158ff0;
    SetUpdateListSlot(&gPukupukuUpdateList);
    return gPukupukuUpdateList;
}

void SetupDrawPukupuku(void) {
    func_020e6a18(gPukupuku);
}

void DrawPukupuku(u32 a, Unk020e43a8 *pukupuku, u32 b, u16 alpha) {
    NsbmdModel *model;
    s32 mirrored;
    u32 v;

    if (pukupuku->mUnk_00.mStateMachine.mState == 0) {
        MtxFx43 *matrix;
        mirrored = pukupuku->mUnk_00.mCollisionSlotIndex & 1;
        matrix = SetViewTransposeMatrixPos(&pukupuku->mUnk_00.mPos);
        model = gPukupuku;
        model->mUnk_14 = model->mUnk_14 | 0xc0;
        gPukupukuDrawScale = pukupuku->mUnk_00.mScale;
        if (mirrored) {
            gPukupukuDrawScale.x = -gPukupukuDrawScale.x;
        }
        func_020e67c4(model, matrix, &gPukupukuDrawScale, 0, alpha);
    } else {
        MtxFx43 *matrix;
        mirrored = pukupuku->mUnk_00.mCollisionSlotIndex & 1;
        v = *(u16 *) &pukupuku->mUnk_a0.mUnk_0c.x;
        matrix = SetViewTransposeMatrixPos(&pukupuku->mUnk_00.mPos);
        model = gPukupuku;
        model->mUnk_14 = model->mUnk_14 | 0xc0;
        gPukupukuDrawScale = pukupuku->mUnk_00.mScale;
        if (mirrored) {
            gPukupukuDrawScale.x = -gPukupukuDrawScale.x;
        }
        func_020e66e4(model, matrix, v, &gPukupukuDrawScale, 0, alpha);
    }
}

void func_020e4e9c(void) {
    u32 value12;
    func_020e55b4();
}

void DrawPukupukuShadow(u32 a, Unk020e43a8 *pukupuku, u32 b, u32 alpha) {
    Unk020e4e08 shadowParams;

    if (pukupuku->mUnk_00.mStateMachine.mState != 0 && pukupuku->mUnk_00.mStateMachine.mState != 1) {
        return;
    }
    shadowParams.mUnk_00 = pukupuku->mUnk_00.mPos.y - pukupuku->mUnk_a0.mUnk_18.y;
    shadowParams.mUnk_00 = 0x1000 - (shadowParams.mUnk_00 >> 6);
    shadowParams.mUnk_04 = pukupuku->mUnk_00.mPos;
    shadowParams.mUnk_04.y = pukupuku->mUnk_f4.z + pukupuku->mUnk_100;
    SetShadowPositionRaised((ShadowMatrix *) &pukupuku->mUnk_c8, &shadowParams.mUnk_04);
    func_020e54e4((ShadowMatrix *) &pukupuku->mUnk_c8, &shadowParams, 0, alpha);
}

void func_020e4df8(u32 arg0, u32 arg1) {
    u32 value0;
    u32 value1 = arg1;
    u32 value12;
    value0 = (value1) + (0x80u);
    AdvanceStateMachine((void *) value0);
}

void EnterPukupukuState0(Unk020e4dec *pukupuku) {
    pukupuku->mUnk_ac = 0x0u;
}

static inline u32 func_020e4ad0_inline(RandomState64 *random, u32 range) {
    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
    if (range == 0) {
        return random->mValue >> 32;
    } else {
        return ((random->mValue >> 32) * range) >> 32;
    }
}

void UpdatePukupukuState0(Unk020e43a8 *pukupuku) {
    s32 y;

    pukupuku->mUnk_00.mUnk_10.y -= 0x385;
    VEC_Add(&pukupuku->mUnk_00.mPos, &pukupuku->mUnk_00.mUnk_10, &pukupuku->mUnk_00.mPos);
    y = 0;
    y += (s32) (((s64) pukupuku->mUnk_104 * (pukupuku->mUnk_00.mPos.x - pukupuku->mUnk_a0.mUnk_18.x)) >> 12);
    y += (s32) (((s64) pukupuku->mUnk_108 * (pukupuku->mUnk_00.mPos.z - pukupuku->mUnk_a0.mUnk_18.z)) >> 12);
    pukupuku->mUnk_100 = y;
    y = pukupuku->mUnk_a0.mUnk_18.y + pukupuku->mUnk_100;
    if (pukupuku->mUnk_00.mPos.y >= y) {
        return;
    }
    if (!(pukupuku->mUnk_00.mDistanceSquaredAndFlags & 4)) {
        Unk0210b7a8 soundRequest;
        u32 falloffIndex;

        if (pukupuku->mUnk_00.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
            falloffIndex = 2;
        } else if (pukupuku->mUnk_00.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
            falloffIndex = 3;
        } else {
            falloffIndex = 4;
        }
        soundRequest.mSoundId = 0x10b;
        soundRequest.mPositionSource = &pukupuku->mUnk_00.mPos;
        soundRequest.mUnk_08 = falloffIndex;
        soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&pukupuku->mUnk_00.mPos);
        func_0210b7a8(&soundRequest);
    }
    pukupuku->mUnk_00.mPos.y = y;
    pukupuku->mUnk_c4 = pukupuku->mUnk_c4 - 1;
    if (pukupuku->mUnk_c4 == 0) {
        RandomState64 *random;

        pukupuku->mUnk_00.mUnk_10.y = 0x3199;
        random = GetMapObjectRandom();
        pukupuku->mUnk_c4 = (u16) func_020e4ad0_inline(random, 3) + 4;
    } else {
        RandomState64 *random;

        pukupuku->mUnk_00.mUnk_10.y = 0x2000;
        random = GetMapObjectRandom();
        pukupuku->mUnk_00.mUnk_10.y = pukupuku->mUnk_00.mUnk_10.y + func_020e4ad0_inline(random, 0x800);
    }
    if (pukupuku->mUnk_00.mPos.x > pukupuku->mUnk_a0.mUnk_18.x + 0x14000) {
        pukupuku->mUnk_00.mUnk_10.x = -0xccc;
    } else if (pukupuku->mUnk_00.mPos.x < pukupuku->mUnk_a0.mUnk_18.x - 0x14000) {
        pukupuku->mUnk_00.mUnk_10.x = 0xccc;
    } else {
        RandomState64 *random;

        random = GetMapObjectRandom();
        pukupuku->mUnk_00.mUnk_10.x = func_020e4ad0_inline(random, 0x1998) - 0xccc;
    }
    if (pukupuku->mUnk_00.mPos.z > pukupuku->mUnk_a0.mUnk_18.z + 0x14000) {
        pukupuku->mUnk_00.mUnk_10.z = -0xccc;
        return;
    }
    if (pukupuku->mUnk_00.mPos.z < pukupuku->mUnk_a0.mUnk_18.z - 0x14000) {
        pukupuku->mUnk_00.mUnk_10.z = 0xccc;
        return;
    }
    {
        RandomState64 *random;

        random = GetMapObjectRandom();
        pukupuku->mUnk_00.mUnk_10.z = func_020e4ad0_inline(random, 0x1998) - 0xccc;
    }
}

void EnterPukupukuState1(Unk020e43a8 *pukupuku) {
    pukupuku->mUnk_00.mFlags = (((pukupuku->mUnk_00.mFlags)) | ((data_02158fe4)));
}

void UpdatePukupukuState1(Unk020e43a8 *pukupuku) {
    if (AdvancePushedMotion(pukupuku) == FALSE) {
        return;
    }
    if (pukupuku->mUnk_00.mCourseMapRow->mUnk_28 == 0) {
        pukupuku->mUnk_00.mStateMachine.mNextState = 2;
        pukupuku->mUnk_00.mStateMachine.mNextStateRequested = 1;
        return;
    }
    ParkMapObject(&pukupuku->mUnk_00);
}

void EnterPukupukuState2(MapObjectFlagsView *pukupuku) {
    pukupuku->mUnk_02 |= data_02158fe8;
    pukupuku->mUnk_02 |= data_02158fec;
}

void UpdatePukupukuState2(Unk020e43a8 *pukupuku) {
    if (pukupuku->mUnk_00.mStateMachine.mStateFrames > 0x12c) {
        pukupuku->mUnk_00.mStateMachine.mNextState = 3;
        pukupuku->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

void EnterPukupukuState3(Unk020e49c0 *pukupuku) {
    pukupuku->mUnk_04 = pukupuku->mUnk_b8;
    pukupuku->mUnk_0c = pukupuku->mUnk_c0;
    pukupuku->mUnk_10 = 0x0u;
    pukupuku->mUnk_14 = 0x3199u;
    pukupuku->mUnk_18 = 0x0u;
    pukupuku->mUnk_02 = (((pukupuku->mUnk_02)) & ~(0x2u));
    pukupuku->mUnk_02 = (((pukupuku->mUnk_02)) & ~(0x8u));
    pukupuku->mUnk_66 = 0x1fu;
    pukupuku->mUnk_02 = (((pukupuku->mUnk_02)) & ~(0x1u));
}

void UpdatePukupukuState3(Unk020e43a8 *pukupuku) {
    pukupuku->mUnk_00.mPos.y = pukupuku->mUnk_00.mPos.y + pukupuku->mUnk_00.mUnk_10.y;
    if (pukupuku->mUnk_00.mPos.y > pukupuku->mUnk_a0.mUnk_18.y) {
        pukupuku->mUnk_00.mStateMachine.mNextState = 0;
        pukupuku->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}

u8 CollideKartWithPukupuku(Unk020e43a8 *pukupuku, Unk020ec6e4 *kart, u8 *c, u8 *d) {
    if (*c == 1) {
        SetPushedMotionFromKart(pukupuku, kart);
        pukupuku->mUnk_00.mStateMachine.mNextState = 1;
        pukupuku->mUnk_00.mStateMachine.mNextStateRequested = 1;
        pukupuku->mUnk_00.mFlags = pukupuku->mUnk_00.mFlags | (data_02158fe4);
        StartSoundIfKartStarOrKiller((void *) pukupuku, (void *) kart);
    }
    return *d;
}

s32 CollideItemObjectWithPukupuku(Unk020e43a8 *pukupuku, void *itemObject, u8 *b, u8 *c) {
    if (*b == 1) {
        SetPushedMotionFromItemObject(pukupuku, itemObject);
        pukupuku->mUnk_00.mFlags |= data_02158fe4;
        pukupuku->mUnk_00.mStateMachine.mNextState = 1;
        pukupuku->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
    return *c;
}

#pragma thumb on

void CreatePukupuku(void) {
    void *nsbmdFile;
    nsbmdFile = FindCourseMapObjFile(gPukupukuNsbmdName);
    func_020e6488((NsbmdModel **) (((u32 *) &gPukupuku)), nsbmdFile, 0, 0);
    func_020e6ab8(gPukupuku);
}

#pragma thumb off
