#include "code_020220f0.h"

u16 NNS_G2dGetAnimCtrlCurrentFrame(const Unk02022030 *pAnimCtrl) {
    return ((u32) pAnimCtrl->mUnk_00 - (u32) pAnimCtrl->mUnk_18->mUnk_0c) / sizeof(Unk02021e40);
}
