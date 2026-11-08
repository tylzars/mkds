#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on

s32 GetFramesSinceMenuScreenSwitch(void) {
    return data_0217b43c->mFramesSinceScreenSwitch;
}

u32 func_020cccc0(void) {
    return (data_0217b43c->mUnk_004);
}

u32 GetPreviousMenuScreenNumber(void) {
    return (data_0217b43c->mPreviousScreenNumber);
}

u32 GetMenuScreenNumber(void) {
    return (data_0217b43c->mScreenNumber);
}

u32 GetNextMenuScreenNumber(void) {
    return (data_0217b43c->mNextScreenNumber);
}

#pragma thumb off
