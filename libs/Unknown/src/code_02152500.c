#include "code_02152500.h"
#include "code_021519d4.h"
#include "code_02152490.h"
#include "code_021526e4.h"
#include "code_02152934.h"
#include "code_02152a24.h"
#include "code_02152a7c.h"
#include "code_02152ab4.h"
#include "code_02152ac8.h"
#include "code_020205b0.h"
#include "Main/Unknown/code_02000b44.h"
#include "Main/Unknown/code_02152000.h"
#include "Main/Unknown/code_02152ab0.h"

#pragma thumb on

void DWC_CreateUserData(DWCAccUserData *userdata, u32 gamecode) {
    DWCi_Acc_CreateUserData(userdata, gamecode);
}

BOOL DWC_CheckValidConsole(const DWCAccUserData *userdata) {
    DWCAuthWiFiId id;

    if (DWCi_Acc_GetFlag_DataType(&userdata->mAuthentic) == 0) {
        return 1;
    }
    DWC_Auth_GetId(&id);
    if (id.mFlag == 0) {
        return 0;
    }
    if (id.mUId == DWCi_Acc_GetUserId(&userdata->mAuthentic)) {
        return 1;
    }
    return 0;
}

void DWCi_Acc_SetLoginIdToUserData(DWCAccUserData *userdata, const DWCAccFriendData *loginid, int gsProfileId) {
    u32 crcTable[0x100];

    userdata->mAuthentic = *loginid;
    userdata->mGsProfileId = gsProfileId;
    Crc32InitTable(crcTable, 0xedb88320);
    userdata->mCrc32 = Crc32(crcTable, userdata, 0x3c);
    userdata->mFlag |= 1;
}

BOOL DWCi_Acc_IsDirty(const DWCAccUserData *userdata) {
    if ((userdata->mFlag & 1) == 1) {
        return 1;
    }
    return 0;
}

void DWCi_Acc_ClearDirty(DWCAccUserData *userdata) {
    u32 crcTable[0x100];

    userdata->mFlag &= ~1;
    Crc32InitTable(crcTable, 0xedb88320);
    userdata->mCrc32 = Crc32(crcTable, userdata, 0x3c);
}

u64 DWC_GetFriendKey(const DWCAccFriendData *frienddata) {
    if (DWCi_Acc_GetFlag_DataType(frienddata) == 2) {
        return DWCi_Acc_GetFriendKey(frienddata);
    }
    return 0;
}

int DWC_GetGsProfileId(const DWCAccUserData *userdata, const DWCAccFriendData *frienddata) {
    u64 friendKey;

    switch (DWCi_Acc_GetFlag_DataType(frienddata)) {
        case 2:
            friendKey = DWCi_Acc_GetFriendKey(frienddata);
            if (DWC_Acc_CheckFriendKey(friendKey, userdata->mGamecode) != 0) {
                return DWC_Acc_FriendKeyToGsProfileId(friendKey, userdata->mGamecode);
            }
            return 0;
        case 3:
            return func_02152ab0(frienddata);
        case 1:
            return -1;
        default:
            return 0;
    }
}

u64 DWC_CreateFriendKey(const DWCAccUserData *userdata) {
    u64 friendKey;

    friendKey = 0;
    if (userdata->mGsProfileId != 0) {
        friendKey = DWC_Acc_CreateFriendKey(userdata->mGsProfileId, userdata->mGamecode);
    }
    return friendKey;
}

#pragma thumb off
