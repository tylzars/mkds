#include "code_02022030.h"

void NNS_G2dResetAnimCtrlState(Unk02022030 *pAnimCtrl) {
    if ((pAnimCtrl->mUnk_10 > 0) ^ pAnimCtrl->mUnk_04) {
        pAnimCtrl->mUnk_00 = &pAnimCtrl->mUnk_18->mUnk_0c[pAnimCtrl->mUnk_18->mUnk_02];
    } else {
        pAnimCtrl->mUnk_00 = &pAnimCtrl->mUnk_18->mUnk_0c[pAnimCtrl->mUnk_18->mUnk_00] - 1;
    }
    pAnimCtrl->mUnk_0c = 0;
}

void NNS_G2dBindAnimCtrl(Unk02022030 *pAnimCtrl, Unk02021dc8 *pAnimSequence) {
    pAnimCtrl->mUnk_18 = pAnimSequence;
    NNS_G2dResetAnimCtrlState(pAnimCtrl);
}
