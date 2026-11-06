#include "Main/Unknown/code_020ada2c.h"
#include "Main/Unknown/code_020ada7c.h"
#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma optimize_for_size on
#pragma thumb on

void AdvanceTitleStates(s32 a) {
    enum { K0 } i;
    func_020ae6ac(&gTitleScene->mMainOam, &gTitleScene->mSubOam);
    i = gTitleScene->mState;
    gTitleScene->mStateHandlers[i].mUpdate(a);
    func_020ada7c((s32 *) gTitleScene);
    func_02125928();
    func_020ae630(&gTitleScene->mMainOam, &gTitleScene->mSubOam);
}

#pragma thumb off
