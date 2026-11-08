#include "Main/Unknown/code_020ada7c.h"

#include "Main/Unknown/code_020ada94.h"
#include "Main/Unknown/code_020ae5e4.h"
#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on

void func_020ada94(void) {
    gTitleScene->mStateHandlers[gTitleScene->mState].mUnk_00();
    gTitleScene->mStateChanged = FALSE;
    func_021258f0();
    UploadOamLists(&gTitleScene->mMainOam, &gTitleScene->mSubOam);
}

#pragma thumb off

void IncrementCounterSaturating(int *counter) {
    u32 value;
    value = *(u32 *) counter;
    if ((s32) value < 0x7fffffff) {
        *counter = value + 1;
    }
}
