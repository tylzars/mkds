#pragma once

#include "types.h"

// Login ID, friend key or GS profile ID record.
typedef struct DWCAccFriendData {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
} DWCAccFriendData;

typedef struct DWCAccUserData {
    /* 00 */ u32 mSize;
    /* 04 */ DWCAccFriendData mPseudo;
    /* 10 */ DWCAccFriendData mAuthentic;
    /* 1c */ u32 mGsProfileId;
    /* 20 */ u32 mFlag;
    /* 24 */ u32 mGamecode;
    /* 28 */ u8 mReserved[0x14];
    /* 3c */ u32 mCrc32;
} DWCAccUserData;

void DWC_CreateExchangeToken(const DWCAccUserData *userdata, DWCAccFriendData *token);
