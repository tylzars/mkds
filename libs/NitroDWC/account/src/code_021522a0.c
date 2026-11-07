#include "code_021522a0.h"
#include "hash2.h"
#include "code_02152490.h"
#include "code_021526e4.h"
#include "code_02152ab4.h"
#include "code_02152ac8.h"
#include "Main/Unknown/code_02152000.h"
#include "Main/Unknown/code_02152918.h"
#include "Main/Unknown/code_02152ab0.h"
#include "Main/Unknown/code_02152ac4.h"
#include "code_02152a24.h"

#pragma thumb on

void DWC_LoginIdToUserName(const DWCAccUserData *userdata, const DWCAccFriendData *frienddata, char *username) {
    DWCi_Acc_LoginIdToUserName(frienddata, userdata->mGamecode, username);
}

BOOL DWC_IsEqualFriendData(const DWCAccFriendData *frienddata1, const DWCAccFriendData *frienddata2) {
    u32 type;
    type = DWCi_Acc_GetFlag_DataType(frienddata1);
    if (type != DWCi_Acc_GetFlag_DataType(frienddata2)) {
        return 0;
    }
    if (type == 3) {
        if (func_02152ab0(frienddata1) == func_02152ab0(frienddata2)) {
            return 1;
        }
        return 0;
    }
    if (type == 1) {
        if (DWCi_Acc_GetUserId(frienddata1) == DWCi_Acc_GetUserId(frienddata2) &&
            func_02152ac4(frienddata1) == func_02152ac4(frienddata2)) {
            return 1;
        }
        return 0;
    }
    if (type == 2) {
        if (DWCi_Acc_GetFriendKey(frienddata1) == DWCi_Acc_GetFriendKey(frienddata2)) {
            return 1;
        }
        return 0;
    }
    return 0;
}

void DWC_ReportFriendData(const DWCAccUserData *userdata, const DWCAccFriendData *frienddata) {
    u8 name[0x24];
    u64 friendKey;
    if (DWCi_Acc_GetFlag_DataType(frienddata) != 3) {
        if (DWCi_Acc_GetFlag_DataType(frienddata) == 2) {
            friendKey = DWCi_Acc_GetFriendKey(frienddata);
            func_02152918(friendKey, friendKey >> 32, (u32) name);
            return;
        }
        if (DWCi_Acc_GetFlag_DataType(frienddata) == 1) {
            DWCi_Acc_LoginIdToUserName(frienddata, userdata->mGamecode, (char *) &name[0xd]);
        }
    }
}

void DWC_ReportUserData(const DWCAccUserData *userdata) {
    DWC_ReportFriendData(userdata, &userdata->mPseudo);
    DWC_ReportFriendData(userdata, &userdata->mAuthentic);
}

u32 IsMultipleOf4(u32 year) {
    if ((year & 3) == 0) {
        return 1;
    }
    return 0;
}

s32 func_021522a0(const u32 *date) {
    s32 dayNum;
    if (date[0] >= 100 || date[1] < 1 || date[1] > 12 || date[2] < 1 || date[2] > 31 || (s32) date[3] >= 7 ||
        date[1] < 1 || date[1] > 12) {
        return -1;
    }
    dayNum = date[2] - 1 + ((const u32 *) &data_0216f26c)[date[1]];
    if (date[1] >= 3 && IsMultipleOf4(date[0]) != 0) {
        dayNum++;
    }
    dayNum = dayNum + date[0] * 365;
    return dayNum + ((date[0] + 3) >> 2);
}

#pragma thumb off
