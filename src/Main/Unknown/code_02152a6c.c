#include "Main/Unknown/code_02152a6c.h"
#include "code_02152490.h"

#pragma thumb on
u32 GetFriendDataFlags(const DWCAccFriendData *friendData) {
    return (friendData->mUnk_00 >> 11) & 0x1fffff;
}
#pragma thumb off
