#include "code_020220b0.h"
#include "code_02022098.h"

void NNS_G2dInitAnimCtrl(Unk02022030 *pAnimCtrl) {
    NNS_G2dInitAnimCallBackFunctor(&pAnimCtrl->mCallbackFunctor);
    pAnimCtrl->mUnk_00 = 0;
    pAnimCtrl->mUnk_04 = 0;
    pAnimCtrl->mUnk_08 = 1;
    pAnimCtrl->mUnk_0c = 0;
    pAnimCtrl->mUnk_10 = 0x1000;
    pAnimCtrl->mUnk_14 = 0;
    pAnimCtrl->mUnk_18 = 0;
}
