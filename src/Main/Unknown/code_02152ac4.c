#include "Main/Unknown/code_02152ac4.h"
#include "code_02152490.h"

#pragma thumb on

u32 GetFriendDataPlayerId(const DWCAccFriendData *friendData) {
    return friendData->mUnk_08;
}

#pragma thumb off
