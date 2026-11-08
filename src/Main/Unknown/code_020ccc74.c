#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma optimize_for_size on
#pragma thumb on
void SwitchMenuScreen(s32 screenNumber, s32 nextScreenNumber) {
    data_0217b43c->mFramesSinceScreenSwitch = 0;
    data_0217b43c->mUnk_004 = 1;
    data_0217b43c->mPreviousScreenNumber = data_0217b43c->mScreenNumber;
    data_0217b43c->mScreenNumber = screenNumber;
    data_0217b43c->mNextScreenNumber = nextScreenNumber;
}
#pragma thumb off
