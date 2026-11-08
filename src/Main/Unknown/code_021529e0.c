#include "Main/Unknown/code_021529e0.h"
#include "Main/Unknown/code_02152a04.h"
#include "Main/Unknown/code_02152a6c.h"

#pragma thumb on
void SetFriendDataType(DWCAccFriendData *friendData, u32 dataType) {
    u32 flags;
    u32 d;
    flags = GetFriendDataFlags(friendData);
    d = 3;
    flags = flags & ~d;
    d = flags;
    d = d | dataType;
    SetFriendDataFlags(friendData, d);
}
#pragma thumb off
