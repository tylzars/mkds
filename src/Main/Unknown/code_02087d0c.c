#include "Main/Unknown/code_02087d0c.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02087934.h"
#include "code_020109c4.h"
#include "code_02010c84.h"

#include "Main/Unknown/code_02087cd0.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_02036bec.h"
#include "code_02013740.h"
#include "code_02013bdc.h"

u32 func_0208832c(Unk020882fc *anmObj) {
    return anmObj->mUnk_08->mFrameCount;
}

u32 func_02088320(Unk020882fc *anmObj) {
    return anmObj->mUnk_08->mFrameCount;
}

u32 func_02088314(Unk020882fc *anmObj) {
    return anmObj->mUnk_08->mFrameCount;
}

u32 func_02088308(Unk020882fc *anmObj) {
    return anmObj->mUnk_08->mFrameCount;
}

u32 func_020882fc(Unk020882fc *anmObj) {
    return anmObj->mUnk_08->mFrameCount;
}

void InitModelAnimation(u32 kind, void *animation, void *renderObject, u32 anmObjCount, void *heap, void *f) {
    ModelAnimation *modelAnimation = animation;
    NNSG3dRenderObj *renderObj = renderObject;
    u16 i;

    if (anmObjCount != 0) {
        i = 0;
        if (heap != NULL) {
            modelAnimation->mAnmObjs = HeapAlloc(heap, anmObjCount * 4);
            modelAnimation->mLoopFlags = HeapAlloc(heap, anmObjCount * 4);
            for (; i < anmObjCount; i++) {
                modelAnimation->mAnmObjs[i] = NULL;
                modelAnimation->mLoopFlags[i] = 0;
            }
        }
    }
    ResetModelAnimationLooping(modelAnimation, 0);
    renderObj->mUnk_58 = 0;
    modelAnimation->mRenderObj = renderObj;
    modelAnimation->mAnmObjCount = anmObjCount;
    modelAnimation->mCurrentIndex = 0;
    modelAnimation->mKind = kind;
    modelAnimation->mBlending = FALSE;
    modelAnimation->mBlendRatioStep = 0x19a;
    modelAnimation->mPreviousAnmObj = NULL;
}

void InitModelAnimationEntry(void *animation, s32 entryIndex, void *anmResource, u32 loopFlag, void *heap) {
    ModelAnimation *modelAnimation = animation;
    NNSG3dAnmObj *anmObj;

    if (heap == NULL) {
        anmObj = modelAnimation->mAnmObjs[entryIndex];
        modelAnimation->mLoopFlags[entryIndex] = loopFlag;
    } else {
        gAnmObjSizeRequired = NNS_G3dAnmObjCalcSizeRequired(anmResource, modelAnimation->mRenderObj->mResMdl);
        anmObj = HeapAlloc(heap, gAnmObjSizeRequired);
        modelAnimation->mAnmObjs[entryIndex] = anmObj;
        modelAnimation->mLoopFlags[entryIndex] = loopFlag;
    }
    NNS_G3dAnmObjInit(anmObj, anmResource, modelAnimation->mRenderObj->mResMdl,
                      (void *) modelAnimation->mRenderObj->mUnk_68);
}

void InitModelAnimationEntries(void *animation, void *anmFile, void *heap) {
    ModelAnimation *modelAnimation = animation;
    void *anmResource = NULL;
    u8 i = 0;
    NNSG3dAnmObj *anmObj;

    for (i = 0; i < modelAnimation->mAnmObjCount; i++) {
        switch (modelAnimation->mKind) {
            case MODEL_ANIMATION_KIND_JOINT:
                anmResource = NNS_G3dGetJntAnmByIdx(NNS_G3dGetJntAnmSet(anmFile), i);
                break;
            case MODEL_ANIMATION_KIND_TEX_PAT:
                anmResource = NNS_G3dGetTexPatAnmByIdx(NNS_G3dGetTexPatAnmSet(anmFile), i);
                break;
            case MODEL_ANIMATION_KIND_TEX_SRT:
                anmResource = NNS_G3dGetTexSRTAnmByIdx(NNS_G3dGetTexSRTAnmSet(anmFile), i);
                break;
            case MODEL_ANIMATION_KIND_VIS:
                anmResource = NNS_G3dGetVisAnmByIdx(NNS_G3dGetVisAnmSet(anmFile), i);
                break;
            case MODEL_ANIMATION_KIND_MAT_C:
                anmResource = NNS_G3dGetMatCAnmByIdx(NNS_G3dGetMatCAnmSet(anmFile), i);
                break;
        }
        if (heap != NULL) {
            gAnmObjSizeRequired = NNS_G3dAnmObjCalcSizeRequired(anmResource, modelAnimation->mRenderObj->mResMdl);
            anmObj = HeapAlloc(heap, gAnmObjSizeRequired);
            modelAnimation->mAnmObjs[i] = anmObj;
            modelAnimation->mLoopFlags[i] = 0;
        } else {
            anmObj = modelAnimation->mAnmObjs[i];
            modelAnimation->mLoopFlags[i] = 0;
        }
        NNS_G3dAnmObjInit(anmObj, anmResource, modelAnimation->mRenderObj->mResMdl,
                          (void *) modelAnimation->mRenderObj->mUnk_68);
    }
}

void SetModelAnimation(void *animation, s32 entryIndex) {
    ModelAnimation *modelAnimation = animation;
    s32 frameCountFixed;

    if (modelAnimation->mAnmObjs[entryIndex] == NULL) {
        return;
    }
    modelAnimation->mBlending = FALSE;
    if (modelAnimation->mPreviousAnmObj != NULL) {
        NNS_G3dRenderObjRemoveAnmObj(modelAnimation->mRenderObj, modelAnimation->mPreviousAnmObj);
        modelAnimation->mPreviousAnmObj = NULL;
    }
    NNS_G3dRenderObjRemoveAnmObj(modelAnimation->mRenderObj, modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]);
    modelAnimation->mCurrentIndex = entryIndex;
    NNS_G3dRenderObjAddAnmObj(modelAnimation->mRenderObj, modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]);
    modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]->mRatio = 0x1000;
    frameCountFixed =
        gAnmFrameCountGetters[modelAnimation->mKind](modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]) << 12;
    ResetModelAnimationWithLoopFlag(modelAnimation, frameCountFixed,
                                    modelAnimation->mLoopFlags[modelAnimation->mCurrentIndex]);
}

// Switches to entry a by fading from the current one; does nothing when a is already playing.
void StartModelAnimationBlend(void *animation, u16 entryIndex) {
    ModelAnimation *modelAnimation = animation;
    s32 frameCountFixed;

    if (modelAnimation->mAnmObjs[entryIndex] == NULL) {
        return;
    }
    if (modelAnimation->mCurrentIndex == entryIndex) {
        return;
    }
    modelAnimation->mBlending = TRUE;
    if (modelAnimation->mPreviousAnmObj != NULL) {
        NNS_G3dRenderObjRemoveAnmObj(modelAnimation->mRenderObj, modelAnimation->mPreviousAnmObj);
        modelAnimation->mPreviousAnmObj = NULL;
    }
    modelAnimation->mPreviousAnmObj = modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex];
    modelAnimation->mPreviousAnmObj->mRatio = 0x1000;
    modelAnimation->mCurrentIndex = entryIndex;
    NNS_G3dRenderObjAddAnmObj(modelAnimation->mRenderObj, modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]);
    modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]->mRatio = 0;
    frameCountFixed =
        gAnmFrameCountGetters[modelAnimation->mKind](modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]) << 12;
    ResetModelAnimationWithLoopFlag(modelAnimation, frameCountFixed,
                                    modelAnimation->mLoopFlags[modelAnimation->mCurrentIndex]);
}

void AdvanceModelAnimation(void *animation) {
    ModelAnimation *modelAnimation = animation;

    if (modelAnimation->mBlending != FALSE) {
        modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]->mRatio += modelAnimation->mBlendRatioStep;
        modelAnimation->mPreviousAnmObj->mRatio -= modelAnimation->mBlendRatioStep;
        if (modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]->mRatio >= 0x1000) {
            modelAnimation->mBlending = FALSE;
            modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]->mRatio = 0x1000;
            NNS_G3dRenderObjRemoveAnmObj(modelAnimation->mRenderObj, modelAnimation->mPreviousAnmObj);
            modelAnimation->mPreviousAnmObj = NULL;
        }
    }
    AdvanceModelAnimationFrame(modelAnimation);
    modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]->mFrame = modelAnimation->mFrameIndex;
}

// Moves only the blend; the caller sets the frame.
void AdvanceModelAnimationBlend(ModelAnimation *modelAnimation) {
    if (modelAnimation->mBlending == FALSE) {
        return;
    }
    modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]->mRatio += modelAnimation->mBlendRatioStep;
    modelAnimation->mPreviousAnmObj->mRatio -= modelAnimation->mBlendRatioStep;
    if (modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]->mRatio >= 0x1000) {
        modelAnimation->mBlending = FALSE;
        modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]->mRatio = 0x1000;
        NNS_G3dRenderObjRemoveAnmObj(modelAnimation->mRenderObj, modelAnimation->mPreviousAnmObj);
        modelAnimation->mPreviousAnmObj = NULL;
    }
}

// Frame count of the playing entry in 20.12 fixed point.
s32 GetModelAnimationFrameCountFixed(void *animation) {
    ModelAnimation *modelAnimation = animation;
    enum { K0 } kind = modelAnimation->mKind;

    return gAnmFrameCountGetters[kind](modelAnimation->mAnmObjs[modelAnimation->mCurrentIndex]) << 12;
}
