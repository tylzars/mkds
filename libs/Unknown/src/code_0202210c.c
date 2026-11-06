#include "code_0202210c.h"
#include "code_020222ec.h"
#include "code_02134398.h"

static inline void CallbackFuncHandling_(const Unk02022030 *pAnimCtrl, u16 currentFrameIdx) {
    switch (pAnimCtrl->mCallbackFunctor.mType) {
        case 2:
            if (currentFrameIdx == pAnimCtrl->mCallbackFunctor.mFrameIdx) {
                pAnimCtrl->mCallbackFunctor.mFunc(pAnimCtrl->mCallbackFunctor.mParam, currentFrameIdx);
            }
            break;
        case 3:
            pAnimCtrl->mCallbackFunctor.mFunc(pAnimCtrl->mCallbackFunctor.mParam, currentFrameIdx);
            break;
    }
}

static inline u32 ShouldAnmCtrlMoveNext_(Unk02022030 *pAnimCtrl) {
    if (pAnimCtrl->mUnk_08 != 0 && pAnimCtrl->mUnk_0c >= (((Unk02022188 *) pAnimCtrl->mUnk_00)->mUnk_04 << 12)) {
        return 1;
    }
    return 0;
}

u32 NNS_G2dTickAnimCtrl(Unk02022030 *pAnimCtrl, s32 frames) {
    u32 changedFrame;
    s32 atEdge;
    Unk02021e40 *next;
    u16 frameIdx;
    s32 *currentTime;

    changedFrame = 0;
    if (pAnimCtrl->mUnk_08 != 1) {
        return 0;
    }
    pAnimCtrl->mUnk_0c += Abs(((s64) pAnimCtrl->mUnk_10 * frames + 0x800) >> 12);
    currentTime = &pAnimCtrl->mUnk_0c;
    while (ShouldAnmCtrlMoveNext_(pAnimCtrl)) {
        changedFrame = 1;
        *currentTime = *currentTime - (((Unk02022188 *) pAnimCtrl->mUnk_00)->mUnk_04 << 12);
        if ((pAnimCtrl->mUnk_10 > 0) ^ pAnimCtrl->mUnk_04) {
            pAnimCtrl->mUnk_00++;
        } else {
            pAnimCtrl->mUnk_00--;
        }
        next = pAnimCtrl->mUnk_00;
        if ((pAnimCtrl->mUnk_10 > 0) ^ pAnimCtrl->mUnk_04) {
            atEdge = next >= &pAnimCtrl->mUnk_18->mUnk_0c[pAnimCtrl->mUnk_18->mUnk_00];
        } else {
            atEdge = next <= &pAnimCtrl->mUnk_18->mUnk_0c[pAnimCtrl->mUnk_18->mUnk_02] - 1;
        }
        if (atEdge) {
            SequenceEdgeHandle_(pAnimCtrl);
        }
        if (pAnimCtrl->mCallbackFunctor.mType != 0) {
            frameIdx = ((u32) pAnimCtrl->mUnk_00 - (u32) pAnimCtrl->mUnk_18->mUnk_0c) >> 3;
            CallbackFuncHandling_(pAnimCtrl, frameIdx);
        }
    }
    return changedFrame;
}

u32 NNS_G2dSetAnimCtrlCurrentFrame(Unk02022030 *pAnimCtrl, u32 index) {
    u32 result;

    result = SetAnimCtrlCurrentFrameImpl_(pAnimCtrl, index);
    if (result != 0) {
        pAnimCtrl->mUnk_0c = 0;
    }
    return result;
}
