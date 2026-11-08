#include "Main/Unknown/code_020df890.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8cac.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/code_020d8000.h"
#include "Main/Unknown/code_020d9000.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e43a8.h"
#include "Main/Unknown/code_020e0680.h"
#include "Main/Unknown/code_020e516c.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_020ea514.h"
#include "Main/Unknown/code_020ea588.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0216b000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02146000.h"

#pragma thumb off

void UpdateKoopaBlockState2(Unk020e005c *koopaBlock) {
    GroupFollower *follower;
    s32 progress;
    s32 speed;
    u16 angle;
    s32 sine;

    follower = &koopaBlock->mUnk_144;
    progress = GetGroupFollowerProgress(follower);
    angle = (s32) (((s64) progress * 0x40000) >> 12);
    sine = gPairsByAngle[(angle >> 4) * 2];
    speed = ((s64) -sine * koopaBlock->mUnk_168) >> 12;
    follower->mSpeed = speed > 0x200 ? speed : 0x200;
    if (speed <= 0x200) {
        speed = 0x200;
    }
    follower->mProgressStep =
        ((s64) speed * follower->mPath->mSegments[follower->mSegmentIndex].mInverseProgressLength) >> 12;
}

void DrawAllKoopaBlocks(void *viewMatrix) {
    func_020e1e38(data_0217b784, viewMatrix, func_020e1dec);
}

u32 IsKoopaBlockKind(u32 kind) {
    switch (kind) {
        case 0xca:
            return 1;
        default:
            return 0;
    }
}

s32 func_020dff4c(Unk020e005c *koopaBlock) {
    s32 progress;
    GroupFollower *follower;

    follower = &koopaBlock->mUnk_144;
    progress = GetGroupFollowerProgress(follower);
    if (follower->mForward == 0) {
        progress = 0x1000 - progress;
    }
    return progress;
}

#pragma thumb on
void CreateKoopaBlock(void) {
    void *file;

    file = FindCourseMapObjFile("koopa_block.nsbmd");
    CreateNsbmd(&gKoopaBlock, file, NULL);
    func_02084968(gKoopaBlock, 0x3f, 2, 0x294a);
    SetMapObjectsModel(data_0217b784, gKoopaBlock);
}

void InitKoopaBlock(Unk020e005c *koopaBlock, CourseMapRow *courseRow) {
    InitStateMachine(&koopaBlock->mStateMachine, data_0216bff8, 3, koopaBlock);
    koopaBlock->mUnk_168 = (courseRow->mUnk_28 << 12) / 100;
    InitGroupFollower(&koopaBlock->mUnk_144, courseRow, koopaBlock->mUnk_168);
    koopaBlock->mUnk_16c = 0;
    *(Unk020e43a8_28 *) &koopaBlock->mUnk_0a0 = *(Unk020e43a8_28 *) &koopaBlock->mUnk_028;
    koopaBlock->mUnk_124.x = 0;
    koopaBlock->mUnk_124.y = 0;
    koopaBlock->mUnk_124.z = 0;
    koopaBlock->mUnk_130 = FALSE;
    koopaBlock->mUnk_100 = ((s64) koopaBlock->mUnk_01c * 0x190000) >> 12;
    koopaBlock->mUnk_104 = (s32) (((s64) koopaBlock->mUnk_020 * 0x64000) >> 12) >> 1;
    koopaBlock->mUnk_108 = ((s64) koopaBlock->mUnk_024 * 0xaf000) >> 12;
    koopaBlock->mUnk_10c = ((s64) koopaBlock->mUnk_024 * 0xaf000) >> 12;
    koopaBlock->mUnk_110 = 0;
    koopaBlock->mUnk_114.x = 1;
    koopaBlock->mUnk_114.y = 0;
    koopaBlock->mUnk_114.z = 0;
    koopaBlock->mUnk_120 = 0x800;
    SetupGroupFollowerAtEntry(&koopaBlock->mUnk_144, 0, 1);
    GetGroupFollowerLinearPosStep(&koopaBlock->mUnk_144, &koopaBlock->mPos, &koopaBlock->mUnk_010);
    koopaBlock->mUnk_0e8 = koopaBlock->mPos;
    koopaBlock->mUnk_134 = 0;
    koopaBlock->mUnk_138 = 0;
    koopaBlock->mFlags |= data_0215881c;
    koopaBlock->mFlags &= ~2;
    koopaBlock->mFlags &= ~8;
    koopaBlock->mAlpha = 0x1f;
    koopaBlock->mStateMachine.mNextState = 0;
    koopaBlock->mStateMachine.mNextStateRequested = 1;
    koopaBlock->mFarDistanceSquared = gSoundFalloffs[3].mUnk_20;
}
#pragma thumb off

MapObjectKindData *CreateMkdEfBubbleKindData(void) {
    MapObjectKindData *kindData;

    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = data_021587dc;
    return kindData;
}

MapObjectDrawList *CreateMkdEfBubbleDrawList(void) {
    data_0217b774 = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    *data_0217b774 = data_021587b0;
    func_020d49d8(&data_0217b774);
    return data_0217b774;
}

Unk020dfc44 *CreateMkdEfBubbleUpdateList(void) {
    data_0217b76c = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    *data_0217b76c = data_02158784;
    SetUpdateListSlot(&data_0217b76c);
    data_0217b76c->mUnk_28 = FX_Div(0x4000000, 0x1333);
    return data_0217b76c;
}

void DrawMkdEfBubble(void *a, MkdEfBubbleObject *bubble, void *c, s32 alpha) {
    s32 v;
    s32 w;
    s32 rotationMatrix[9];
    s32 n;

    if (bubble->mUnk_00.mStateMachine.mState != 0) {
        return;
    }
    w = 0x1e;
    func_01ff9048(0x14, &w, 1);
    func_01ff9048(0x19, SetViewTransposeMatrixPos(&bubble->mUnk_00.mPos), 0xc);
    if (bubble->mUnk_a8 != 0) {
        n = bubble->mUnk_a8 >> 4;
        MTX_RotZ33_(rotationMatrix, gPairsByAngle[n * 2], gPairsByAngle[n * 2 + 1]);
        func_01ff9048(0x1a, rotationMatrix, 9);
    }
    func_01ff9048(0x1b, &bubble->mUnk_00.mScale, 3);
    DrawNsbmdWithMaxAlpha(gMkdEfBubble, alpha);
    v = bubble->mUnk_00.mPos.y - bubble->mUnk_ac;
    if (v > 0x10000) {
        v = 0x1000 - ((v - 0x10000) >> 8);
        bubble->mUnk_b0.mUnk_030 = 0xd;
    } else {
        n = 0xd - ((0x10000 - v) >> 13);
        v = 0x1000;
        if (n < 1) {
            n = 1;
        }
        bubble->mUnk_b0.mUnk_030 = n;
    }
    if (v <= 0) {
        return;
    }
    func_020e53ac(&bubble->mUnk_b0, &v, 0, alpha);
}

void AdvanceMkdEfBubbleAnimation(void) {
    AdvanceModelAnimation(gMkdEfBubbleNsbta);
}

void UpdateMkdEfBubble(void *a, MkdEfBubbleObject *bubble) {
    AdvanceStateMachine(&bubble->mUnk_00.mStateMachine);
    if (bubble->mUnk_f0 != 0) {
        return;
    }
    if ((bubble->mUnk_00.mFlags & 0x12) != 0) {
        bubble->mUnk_e8->mUnk_24 |= 8;
        bubble->mUnk_ec->mUnk_24 |= 8;
        return;
    }
    bubble->mUnk_e8->mUnk_24 &= ~8;
    bubble->mUnk_ec->mUnk_24 &= ~8;
    PlaceEffect(bubble->mUnk_e8, &bubble->mUnk_00.mPos);
    PlaceEffect(bubble->mUnk_ec, &bubble->mUnk_00.mPos);
}

void EnterMkdEfBubbleState0(MkdEfBubbleObject *bubble) {
    Unk0210b7a8 soundRequest;
    s32 falloffIndex;
    BOOL effectMissing;

    bubble->mUnk_a8 = 0;
    bubble->mUnk_00.mPos.y = bubble->mUnk_a4;
    bubble->mUnk_00.mUnk_10.y = 0x4b33;
    bubble->mUnk_00.mFlags &= ~2;
    bubble->mUnk_00.mFlags &= ~8;
    bubble->mUnk_00.mAlpha = 0x1f;
    if ((bubble->mUnk_00.mDistanceSquaredAndFlags & 4) == 0) {
        if (bubble->mUnk_00.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
            falloffIndex = 2;
        } else if (bubble->mUnk_00.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
            falloffIndex = 3;
        } else {
            falloffIndex = 4;
        }
        soundRequest.mSoundId = 0x18c;
        soundRequest.mPositionSource = &bubble->mUnk_00.mPos;
        soundRequest.mUnk_08 = falloffIndex;
        soundRequest.mDistanceSquared = GetHorizontalCameraDistanceSquared(&bubble->mUnk_00.mPos);
        func_0210b7a8(&soundRequest);
    }
    bubble->mUnk_e4 = 0;
    if (bubble->mUnk_e8 == NULL) {
        bubble->mUnk_e8 = StartEffect(0x45, &bubble->mUnk_00.mPos);
    }
    if (bubble->mUnk_ec == NULL) {
        bubble->mUnk_ec = StartEffect(0x46, &bubble->mUnk_00.mPos);
    }
    if (bubble->mUnk_e8 == NULL || bubble->mUnk_ec == NULL) {
        effectMissing = TRUE;
    } else {
        effectMissing = FALSE;
    }
    bubble->mUnk_f0 = effectMissing;
}

void UpdateMkdEfBubbleState0(MkdEfBubbleObject *bubble) {
    if (bubble->mUnk_00.mUnk_10.y < 0x1333) {
        if (bubble->mUnk_00.mUnk_10.y <= -0x1333) {
            bubble->mUnk_a8 = 0x8000;
        } else {
            bubble->mUnk_a8 = (s32) (((s64) (0x1333 - bubble->mUnk_00.mUnk_10.y) * data_0217b76c->mUnk_28) >> 12) >> 12;
        }
    }
    bubble->mUnk_00.mUnk_10.y -= 0x199;
    if (bubble->mUnk_00.mUnk_10.y < -0x3000) {
        bubble->mUnk_00.mUnk_10.y = -0x3000;
    }
    bubble->mUnk_00.mPos.y += bubble->mUnk_00.mUnk_10.y;
    if (bubble->mUnk_00.mPos.y < bubble->mUnk_a4) {
        bubble->mUnk_00.mStateMachine.mNextState = 1;
        bubble->mUnk_00.mStateMachine.mNextStateRequested = 1;
    }
}
