#include "code_02152934.h"
#include "code_02152a24.h"
#include "code_020205b0.h"
#include "Main/Unknown/code_02152000.h"
#include "Main/Unknown/code_02152a04.h"
#include "Main/Unknown/code_02152a6c.h"

#pragma thumb on

void DWCi_SetBuddyFriendData(DWCAccFriendData *frienddata) {
    u32 flags;
    if (DWCi_Acc_GetFlag_DataType(frienddata) == 3) {
        flags = func_02152a6c(frienddata) | 4;
        func_02152a04(frienddata, flags);
    }
}

u64 DWC_Acc_CreateFriendKey(int gsProfileId, u32 gamecode) {
    u32 code[2];
    u8 table[0x100];
    u64 crc;

    code[0] = gsProfileId;
    code[1] = gamecode;
    Crc8InitTable(table, 7);
    crc = Crc8(table, code, 8) & 0x7f;
    crc <<= 32;
    crc |= (u32) gsProfileId;
    return crc;
}

BOOL DWC_Acc_CheckFriendKey(u64 friendkey, u32 gamecode) {
    u32 code[2];
    u8 table[0x100];
    s32 crc;

    code[0] = friendkey;
    code[1] = gamecode;
    Crc8InitTable(table, 7);
    crc = Crc8(table, code, 8) & 0x7f;
    return crc == (friendkey >> 32);
}

int DWC_Acc_FriendKeyToGsProfileId(u64 friendkey, u32 gamecode) {
    u32 result;

    if (DWC_Acc_CheckFriendKey(friendkey, gamecode) != 0) {
        result = friendkey & ~0xffffffff00000000ull;
    } else {
        result = 0;
    }
    return result;
}

#pragma thumb off
