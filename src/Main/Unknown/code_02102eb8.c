#include "Main/Unknown/code_02102eb8.h"
#include "Main/Unknown/code_0208ab98.h"
#include "Main/Unknown/code_020f81c0.h"

#include "Main/Unknown/code_0208a000.h"
#include "Main/Unknown/code_020f8000.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02102674.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f9c40.h"
#include "Main/Unknown/code_020f8e3c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0203c5e4.h"
#include "Main/Unknown/code_02073eb8.h"
#include "03/code_021b7000.h"
#include "03/unk_021d8000.h"
#include "Main/Unknown/code_02133000.h"
#include "03/code_021b7bb4.h"
#include "Main/Unknown/code_02077bc0.h"

void ResetItemGesso(ItemGesso *gesso) {
    s32 i;

    gesso->mKart = NULL;
    for (i = 0; i < 8; i++) {
        gesso->mUnk_130[i] = 0;
    }
    gesso->mStepIndex = -1;
    gesso->mUnk_000.mAlpha = 0x1f;
    gesso->mUnk_19c = 0;
    gesso->mUnk_160 = FALSE;
}

BOOL SetupNextItemGessoStep(ItemGesso *gesso) {
    ItemGessoStep *step;
    s32 stepIndex;
    BOOL f;

    gesso->mStepIndex = gesso->mStepIndex + 1;
    if (gesso->mStepIndex >= 0x11) {
        goto done;
    }
    step = &gItemGessoSteps[gesso->mStepIndex];
    gesso->mTargetVelocityX = step->mTargetVelocityX;
    gesso->mTargetVelocityY = step->mTargetVelocityY;
    gesso->mApproachRate = step->mApproachRate;
    gesso->mDamping = step->mDamping;
    gesso->mStepTimer = step->mUnk_08;
    gesso->mUnk_170 = step->mUnk_0a;
    stepIndex = gesso->mStepIndex;
    if (stepIndex != 0xc && stepIndex != 0xd) {
        if (gesso->mTargetVelocityY > 0) {
            gesso->mUnk_174 = 0xe66;
            gesso->mUnk_178 = 0x1266;
            gesso->mUnk_184.z = 0x4cd;
        } else if (stepIndex == 4) {
            gesso->mUnk_174 = 0x1000;
            gesso->mUnk_178 = 0x1000;
            gesso->mUnk_184.z = 0x1000;
        } else {
            gesso->mUnk_174 = 0x1333;
            gesso->mUnk_178 = 0xc29;
            gesso->mUnk_184.z = 0x28f;
        }
    } else if (stepIndex == 0xc) {
        gesso->mUnk_174 = 0x199a;
        gesso->mUnk_178 = 0x119a;
        gesso->mUnk_184.z = 0x800;
    } else {
        gesso->mUnk_174 = 0x800;
        gesso->mUnk_178 = 0x800;
        gesso->mUnk_184.z = 0x99a;
    }
    stepIndex = gesso->mStepIndex;
    f = TRUE;
    if (stepIndex != 2 && stepIndex != 0x10) {
        f = FALSE;
    }
    gesso->mUnk_194 = f;
    if (step->mTargetVelocityY > 0 && gesso->mStepIndex != 0 && gesso->mStepIndex != 0xe && gesso->mVisible != FALSE) {
        func_020f8e3c((u32) gesso->mKart, 0xf1);
    }
    return FALSE;
done:
    return TRUE;
}

u32 SetupItemGesso(ItemGesso *gesso, s32 fromData) {
    Unk020748a8 *camera;
    s32 entryIndex;
    s32 kartIndex;

    entryIndex = gRaceSetup->mEntryIndex;
    camera = GetChaseCamera();
    func_020f82a4(0);
    if (entryIndex < 0) {
        kartIndex = (u16) (gesso->mUnk_000.mUnk_78 & ~0xff00);
    } else {
        kartIndex = entryIndex;
    }
    gesso->mKart = GetKart(kartIndex);
    gesso->mUnk_000.mPos = gesso->mKart->mDrawMatrixPos;
    VEC_MultAdd(0x5800, &camera->mUp, &gesso->mUnk_000.mPos, &gesso->mUnk_000.mPos);
    VEC_MultAdd(func_0203c5e4() != 0 ? 0x5800 : 0xa800, &camera->mForward, &gesso->mUnk_000.mPos,
                &gesso->mUnk_000.mPos);
    VEC_Subtract(&gesso->mUnk_000.mPos, &camera->mPos, &gesso->mViewOffset);
    MTX_MultVec33(&gesso->mViewOffset, camera->mViewMatrix, &gesso->mViewOffset);
    if (fromData != 0) {
        if (gesso->mUnk_000.mFlags & 0x10000000) {
            SetupNextItemGessoStep(gesso);
            gesso->mStepTimer = gesso->mStepTimer - 1;
        }
    } else {
        SetupNextItemGessoStep(gesso);
    }
    gesso->mVelocityX = gesso->mTargetVelocityX;
    gesso->mVelocityY = gesso->mTargetVelocityY;
    gesso->mUnk_180 = gesso->mUnk_174;
    gesso->mUnk_184.x = gesso->mUnk_178;
    if ((gesso->mUnk_000.mUnk_78 & 0x8000) == 0) {
        kartIndex = (u16) (gesso->mUnk_000.mUnk_78 & ~0xff00);
    } else {
        kartIndex = 8;
    }
    gesso->mVisible = entryIndex == (u16) kartIndex;
    FreeItemObjectCollisionSlot((s32) gesso);
    return (u32) InitCourseColorBlend(&gesso->mUnk_000.mColorBlend, 1);
}
