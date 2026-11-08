#include "Main/Unknown/code_020e0058.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_020d8cac.h"

#include "Main/Unknown/code_020e005c.h"
#include "Main/Unknown/code_020d8000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020e01ec.h"
#include "Main/Unknown/code_020e01f0.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e337c.h"
#include "Main/Unknown/code_020e3618.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_0210b000.h"
#include "Main/Unknown/unk_0217c000.h"

void func_020e0584(Unk020e005c *object, Vec3 *position, Vec3 *velocity, Unk020e04b0 *link) {
    Vec3 offset;
    s32 f;
    s32 g;

    VEC_Subtract(position, &object->mPos, &offset);
    f = Vec3DotUnrounded(&offset, &object->mUnk_040);
    g = Vec3DotUnrounded(&offset, &object->mUnk_034);
    link->mUnk_04.x = Vec3DotUnrounded(&offset, &object->mUnk_028);
    link->mUnk_04.y = g;
    link->mUnk_04.z = f;
    if (velocity != NULL && object->mUnk_130 != FALSE) {
        f = Vec3DotUnrounded(velocity, &object->mUnk_040);
        g = Vec3DotUnrounded(velocity, &object->mUnk_034);
        link->mUnk_10.x = Vec3DotUnrounded(velocity, &object->mUnk_028);
        link->mUnk_10.y = g;
        link->mUnk_10.z = f;
    } else {
        link->mUnk_10.x = 0;
        link->mUnk_10.y = 0;
        link->mUnk_10.z = 0;
    }
    link->mUnk_00 = object;
}

void func_020e0538(Unk020e04b0 *link, Vec3 *outPosition) {
    Unk020e005c *object = link->mUnk_00;

    if (object == NULL) {
        return;
    }
    MTX_MultVec33(&link->mUnk_04, &object->mUnk_028.x, outPosition);
    VEC_Add(&object->mPos, outPosition, outPosition);
}

BOOL func_020e04b0(Unk020e04b0 *link, Vec3 *outPosition, Vec3 *outVelocity) {
    Unk020e005c *object = link->mUnk_00;

    if (object != NULL) {
        MTX_MultVec33(&link->mUnk_04, &object->mUnk_028.x, outPosition);
        VEC_Add(&object->mPos, outPosition, outPosition);
        if (object->mUnk_130 != FALSE) {
            MTX_MultVec33(&link->mUnk_10, &object->mUnk_028.x, outVelocity);
            if (outVelocity->y < object->mUnk_120) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

s32 func_020e0448(Unk020e0448 *link) {
    Unk020e3ef4 *object = link->mUnk_00;
    s64 horizontalDistanceSquared;
    s64 limitSquared;

    if (object->mUnk_138 != 0 && object->mUnk_000.mKind == 0xcb) {
        horizontalDistanceSquared = (s64) link->mUnk_04.x * link->mUnk_04.x + (s64) link->mUnk_04.z * link->mUnk_04.z;
        limitSquared = (s64) object->mUnk_154 * object->mUnk_154;
        return horizontalDistanceSquared >= limitSquared;
    }
    return object->mUnk_138;
}

void *CreateKoopaBlockKindData(void) {
    void *kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);

    *(Unk020e03f8 *) kindData = *(const Unk020e03f8 *) data_021588a8;
    return kindData;
}

void *CreateKoopaBlockDrawList(void) {
    void *drawList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);

    data_0217b784 = drawList;
    *(Unk020e039c *) drawList = *(const Unk020e039c *) data_0215887c;
    func_020d49d8(&data_0217b784);
    return data_0217b784;
}

void *CreateKoopaBlockUpdateList(void) {
    void *updateList = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);

    data_0217b780 = updateList;
    *(Unk020e0340 *) updateList = *(const Unk020e0340 *) data_02158854;
    func_020e6f50(&data_0217b780);
    return data_0217b780;
}

void UpdateKoopaBlock(void *a0, Unk020e005c *koopaBlock) {
    Unk020e0144 *follower = &koopaBlock->mUnk_144;

    if (koopaBlock->mUnk_16c != 0) {
        Unk0210b7a8 soundRequest;
        s32 falloffIndex;

        koopaBlock->mUnk_16c--;
        koopaBlock->mUnk_010.x = 0;
        koopaBlock->mUnk_010.y = 0;
        koopaBlock->mUnk_010.z = 0;
        if (koopaBlock->mUnk_16c != 0) {
            return;
        }
        if ((koopaBlock->mDistanceSquaredAndFlags & 4) != 0) {
            return;
        }
        falloffIndex = koopaBlock->mFarDistanceSquared == gSoundFalloffs[2].mUnk_20
                           ? 2
                           : (koopaBlock->mFarDistanceSquared == gSoundFalloffs[3].mUnk_20 ? 3 : 4);
        soundRequest.mUnk_00 = 0x17e;
        soundRequest.mUnk_04 = &koopaBlock->mPos;
        soundRequest.mUnk_08 = falloffIndex;
        soundRequest.mUnk_0c = GetHorizontalCameraDistanceSquared(&koopaBlock->mPos);
        func_0210b7a8(&soundRequest);
        return;
    }
    if (func_020d8cc8(follower) != FALSE) {
        if (koopaBlock->mStateMachine.mState == 2) {
            koopaBlock->mStateMachine.mNextState = 0;
            koopaBlock->mStateMachine.mNextStateRequested = 1;
        }
        koopaBlock->mUnk_16c = follower->mUnk_1c->mUnk_0e;
    }
    koopaBlock->mUnk_0e8 = koopaBlock->mPos;
    GetGroupFollowerLinearPosition(follower, &koopaBlock->mPos);
    AdvanceStateMachine(&koopaBlock->mStateMachine);
    VEC_Subtract(&koopaBlock->mPos, &koopaBlock->mUnk_0e8, &koopaBlock->mUnk_010);
    VEC_MultAdd(-koopaBlock->mUnk_104, &koopaBlock->mUnk_034, &koopaBlock->mPos, &koopaBlock->mUnk_0f4);
}

u32 func_020e01ec(u32 value) {
    return value;
}

void UpdateKoopaBlockState0(Unk020e005c *koopaBlock) {
    Unk020e0144 *follower = &koopaBlock->mUnk_144;
    s32 progress = func_020d8cac(follower);
    s32 angle = (u16) (((s64) progress << 18) >> 12);
    s16 sine = gPairsByAngle[(angle >> 4) * 2];
    s32 speed = ((s64) sine * koopaBlock->mUnk_168) >> 12;
    s32 m;

    follower->mUnk_04 = speed > 0x200 ? speed : 0x200;
    m = follower->mUnk_00->mUnk_00[follower->mUnk_0c].mUnk_34;
    if (speed <= 0x200) {
        speed = 0x200;
    }
    follower->mUnk_10 = ((s64) speed * m) >> 12;
    if (func_020d8cac(follower) >= 0x100) {
        koopaBlock->mStateMachine.mNextState = 1;
        koopaBlock->mStateMachine.mNextStateRequested = 1;
    }
}

void EnterKoopaBlockState1(Unk020e005c *koopaBlock) {
    s32 speed = koopaBlock->mUnk_168;

    koopaBlock->mUnk_144.mUnk_04 = speed;
    koopaBlock->mUnk_144.mUnk_10 =
        ((s64) speed * koopaBlock->mUnk_144.mUnk_00->mUnk_00[koopaBlock->mUnk_144.mUnk_0c].mUnk_34) >> 12;
}

void UpdateKoopaBlockState1(Unk020e005c *koopaBlock) {
    Unk020e0144 *follower = &koopaBlock->mUnk_144;

    if (follower->mUnk_20->mUnk_0e == 0) {
        Unk020e0144_00 *path = follower->mUnk_00;
        BOOL onEndSegment;
        BOOL onEndSegmentOfOpenPath = FALSE;

        if (path->mUnk_08 == 0) {
            if (follower->mUnk_18 != 0) {
                onEndSegment = follower->mUnk_0c == path->mUnk_04 - 1;
            } else {
                onEndSegment = follower->mUnk_0c == 0;
            }
            if (onEndSegment) {
                onEndSegmentOfOpenPath = TRUE;
            }
        }
        if (onEndSegmentOfOpenPath == FALSE) {
            return;
        }
    }
    if (func_020d8cac(follower) >= 0xf00) {
        koopaBlock->mStateMachine.mNextState = 2;
        koopaBlock->mStateMachine.mNextStateRequested = 1;
    }
}

u32 func_020e0058(u32 value) {
    return value;
}
