#include "code_021526e4.h"
#include "code_0214d018.h"
#include "code_021519d4.h"
#include "code_02152490.h"
#include "code_02152500.h"
#include "code_02152a7c.h"
#include "code_02152ac8.h"
#include "code_020205b0.h"
#include "os_printf.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_02152000.h"
#include "Main/Unknown/code_021529e0.h"
#include "Main/Unknown/code_02152ac4.h"
#include "code_0200f5ac.h"
#include "Main/Unknown/unk_0216f000.h"

#pragma thumb on

u64 DWC_StringToFriendKey(const char *string) {
    const s8 *p = (const s8 *) string;
    u64 result;
    u64 dec;
    s32 i;

    result = 0;
    dec = 1;
    for (i = 0; i < 12; i++) {
        result += dec * (s64) (*(p + 11 - i) - 0x30);
        dec *= 10;
    }
    return result;
}

void DWCi_Acc_U64ToString32(u64 num, s32 bitnum, char *result) {
    s32 i;
    s32 len;
    const s8 *table;

    len = (bitnum + 4) / 5;
    table = data_0216f2b0;
    for (i = 0; i < len; i++) {
        *(result + len - 1 - i) = table[num & 0x1f];
        num = num >> 5;
    }
    result[len] = 0;
}

void DWCi_Acc_LoginIdToUserName(const DWCAccFriendData *loginid, u32 gamecode, char *username) {
    char userid[0x15];
    char playerid[0x15];

    DWCi_Acc_U64ToString32(DWCi_Acc_GetUserId(loginid), 0x2b, userid);
    DWCi_Acc_U64ToString32(func_02152ac4(loginid), 0x20, playerid);
    OS_SNPrintf(username, 0x15, data_0216f2a0, userid, (u8) (gamecode >> 24), (u8) (gamecode >> 16),
                (u8) (gamecode >> 8), (u8) gamecode, playerid);
}

void DWCi_Acc_CreateUserData(DWCAccUserData *userdata, u32 gamecode) {
    u32 crcTable[0x100];

    MI_CpuFill8(userdata, 0, 0x40);
    userdata->mSize = 0x40;
    userdata->mGsProfileId = 0;
    userdata->mGamecode = gamecode;
    DWCi_Acc_CreateTempLoginId(&userdata->mPseudo);
    func_021529e0(&userdata->mAuthentic, 0);
    Crc32InitTable(crcTable, 0xedb88320);
    userdata->mCrc32 = Crc32(crcTable, userdata, 0x3c);
    userdata->mFlag |= 1;
}

void DWCi_Acc_CreateTempLoginId(DWCAccFriendData *loginid) {
    u64 tick;
    u64 rand;
    DWCAuthWiFiId id;

    tick = OS_GetTick();
    DWC_Auth_GetId(&id);
    if (id.mFlag != 0) {
        DWCi_Acc_SetUserId(loginid, ((u32 *) &id)[0], ((u32 *) &id)[1]);
    } else {
        DWCi_Acc_SetUserId(loginid, ((u32 *) &id)[2], ((u32 *) &id)[3]);
    }
    rand = tick * 0x5d588b656c078965ull + 0x269ec3;
    DWCi_Acc_SetPlayerId(loginid, rand >> 32);
    func_021529e0(loginid, 1);
}

BOOL DWCi_Acc_CheckConsoleUserId(const DWCAccFriendData *loginid) {
    DWCAuthWiFiId id;

    DWC_Auth_GetId(&id);
    if (id.mFlag != 0) {
        if (DWCi_Acc_GetUserId(loginid) == id.mUId) {
            return 1;
        }
        return 0;
    }
    if (DWCi_Acc_GetUserId(loginid) == id.mNotAttestedId) {
        return 1;
    }
    return 0;
}

#pragma thumb off
