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

u32 func_0208832c(Unk020882fc *p0) {
    return p0->mUnk_08->mFrameCount;
}

u32 func_02088320(Unk020882fc *p0) {
    return p0->mUnk_08->mFrameCount;
}

u32 func_02088314(Unk020882fc *p0) {
    return p0->mUnk_08->mFrameCount;
}

u32 func_02088308(Unk020882fc *p0) {
    return p0->mUnk_08->mFrameCount;
}

u32 func_020882fc(Unk020882fc *p0) {
    return p0->mUnk_08->mFrameCount;
}

void InitModelAnimation(u32 a, void *b, void *c, u32 d, void *e, void *f) {
    ModelAnimation *p = b;
    NNSG3dRenderObj *q = c;
    u16 i;

    if (d != 0) {
        i = 0;
        if (e != NULL) {
            p->mAnmObjs = HeapAlloc(e, d * 4);
            p->mLoopFlags = HeapAlloc(e, d * 4);
            for (; i < d; i++) {
                p->mAnmObjs[i] = NULL;
                p->mLoopFlags[i] = 0;
            }
        }
    }
    func_02087cd0(p, 0);
    q->mUnk_58 = 0;
    p->mRenderObj = q;
    p->mAnmObjCount = d;
    p->mCurrentIndex = 0;
    p->mKind = a;
    p->mBlending = FALSE;
    p->mBlendRatioStep = 0x19a;
    p->mPreviousAnmObj = NULL;
}

void InitModelAnimationEntry(void *a, s32 b, void *c, u32 d, void *e) {
    ModelAnimation *p = a;
    NNSG3dAnmObj *x;

    if (e == NULL) {
        x = p->mAnmObjs[b];
        p->mLoopFlags[b] = d;
    } else {
        gAnmObjSizeRequired = NNS_G3dAnmObjCalcSizeRequired(c, p->mRenderObj->mResMdl);
        x = HeapAlloc(e, gAnmObjSizeRequired);
        p->mAnmObjs[b] = x;
        p->mLoopFlags[b] = d;
    }
    NNS_G3dAnmObjInit(x, c, p->mRenderObj->mResMdl, (void *) p->mRenderObj->mUnk_68);
}

void InitModelAnimationEntries(void *a, void *b, void *c) {
    ModelAnimation *p = a;
    void *v = NULL;
    u8 i = 0;
    NNSG3dAnmObj *x;

    for (i = 0; i < p->mAnmObjCount; i++) {
        switch (p->mKind) {
            case MODEL_ANIMATION_KIND_JOINT:
                v = NNS_G3dGetJntAnmByIdx(NNS_G3dGetJntAnmSet(b), i);
                break;
            case MODEL_ANIMATION_KIND_TEX_PAT:
                v = NNS_G3dGetTexPatAnmByIdx(NNS_G3dGetTexPatAnmSet(b), i);
                break;
            case MODEL_ANIMATION_KIND_TEX_SRT:
                v = NNS_G3dGetTexSRTAnmByIdx(NNS_G3dGetTexSRTAnmSet(b), i);
                break;
            case MODEL_ANIMATION_KIND_VIS:
                v = NNS_G3dGetVisAnmByIdx(NNS_G3dGetVisAnmSet(b), i);
                break;
            case MODEL_ANIMATION_KIND_MAT_C:
                v = NNS_G3dGetMatCAnmByIdx(NNS_G3dGetMatCAnmSet(b), i);
                break;
        }
        if (c != NULL) {
            gAnmObjSizeRequired = NNS_G3dAnmObjCalcSizeRequired(v, p->mRenderObj->mResMdl);
            x = HeapAlloc(c, gAnmObjSizeRequired);
            p->mAnmObjs[i] = x;
            p->mLoopFlags[i] = 0;
        } else {
            x = p->mAnmObjs[i];
            p->mLoopFlags[i] = 0;
        }
        NNS_G3dAnmObjInit(x, v, p->mRenderObj->mResMdl, (void *) p->mRenderObj->mUnk_68);
    }
}

void SetModelAnimation(void *b, s32 a) {
    ModelAnimation *p = b;
    s32 v;

    if (p->mAnmObjs[a] == NULL) {
        return;
    }
    p->mBlending = FALSE;
    if (p->mPreviousAnmObj != NULL) {
        NNS_G3dRenderObjRemoveAnmObj(p->mRenderObj, p->mPreviousAnmObj);
        p->mPreviousAnmObj = NULL;
    }
    NNS_G3dRenderObjRemoveAnmObj(p->mRenderObj, p->mAnmObjs[p->mCurrentIndex]);
    p->mCurrentIndex = a;
    NNS_G3dRenderObjAddAnmObj(p->mRenderObj, p->mAnmObjs[p->mCurrentIndex]);
    p->mAnmObjs[p->mCurrentIndex]->mRatio = 0x1000;
    v = gAnmFrameCountGetters[p->mKind](p->mAnmObjs[p->mCurrentIndex]) << 12;
    func_02087c9c(p, v, p->mLoopFlags[p->mCurrentIndex]);
}

// Switches to entry a by fading from the current one; does nothing when a is already playing.
void StartModelAnimationBlend(void *b, u16 a) {
    ModelAnimation *p = b;
    s32 v;

    if (p->mAnmObjs[a] == NULL) {
        return;
    }
    if (p->mCurrentIndex == a) {
        return;
    }
    p->mBlending = TRUE;
    if (p->mPreviousAnmObj != NULL) {
        NNS_G3dRenderObjRemoveAnmObj(p->mRenderObj, p->mPreviousAnmObj);
        p->mPreviousAnmObj = NULL;
    }
    p->mPreviousAnmObj = p->mAnmObjs[p->mCurrentIndex];
    p->mPreviousAnmObj->mRatio = 0x1000;
    p->mCurrentIndex = a;
    NNS_G3dRenderObjAddAnmObj(p->mRenderObj, p->mAnmObjs[p->mCurrentIndex]);
    p->mAnmObjs[p->mCurrentIndex]->mRatio = 0;
    v = gAnmFrameCountGetters[p->mKind](p->mAnmObjs[p->mCurrentIndex]) << 12;
    func_02087c9c(p, v, p->mLoopFlags[p->mCurrentIndex]);
}

void AdvanceModelAnimation(void *a) {
    ModelAnimation *p = a;

    if (p->mBlending != FALSE) {
        p->mAnmObjs[p->mCurrentIndex]->mRatio += p->mBlendRatioStep;
        p->mPreviousAnmObj->mRatio -= p->mBlendRatioStep;
        if (p->mAnmObjs[p->mCurrentIndex]->mRatio >= 0x1000) {
            p->mBlending = FALSE;
            p->mAnmObjs[p->mCurrentIndex]->mRatio = 0x1000;
            NNS_G3dRenderObjRemoveAnmObj(p->mRenderObj, p->mPreviousAnmObj);
            p->mPreviousAnmObj = NULL;
        }
    }
    func_02087b78(p);
    p->mAnmObjs[p->mCurrentIndex]->mFrame = p->mFrameIndex;
}

// Moves only the blend; the caller sets the frame.
void AdvanceModelAnimationBlend(ModelAnimation *p) {
    if (p->mBlending == FALSE) {
        return;
    }
    p->mAnmObjs[p->mCurrentIndex]->mRatio += p->mBlendRatioStep;
    p->mPreviousAnmObj->mRatio -= p->mBlendRatioStep;
    if (p->mAnmObjs[p->mCurrentIndex]->mRatio >= 0x1000) {
        p->mBlending = FALSE;
        p->mAnmObjs[p->mCurrentIndex]->mRatio = 0x1000;
        NNS_G3dRenderObjRemoveAnmObj(p->mRenderObj, p->mPreviousAnmObj);
        p->mPreviousAnmObj = NULL;
    }
}

// Frame count of the playing entry in 20.12 fixed point.
s32 GetModelAnimationFrameCountFixed(void *a) {
    ModelAnimation *p = a;
    enum { K0 } k = p->mKind;

    return gAnmFrameCountGetters[k](p->mAnmObjs[p->mCurrentIndex]) << 12;
}
