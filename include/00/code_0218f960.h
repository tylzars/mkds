#pragma once

#include "types.h"
#include "00/types_021937c0.h"
#include "00/types_021906e4.h"

struct GpConnection;

struct GpConnection;

// List at 0x428 of GpiConnection: the object and the number of entries added to it.
typedef struct Unk0218f960_428 {
    /* 00 */ void *mTable;
    /* 04 */ s32 mUnk_04;
} Unk0218f960_428;

// Object behind GpConnection.mUnk_00: func_ov000_0218f960 passes the address of 0x1f4 to func_ov000_02190b80 and
// func_ov000_02190b58, reads 0x198 and decrements 0x430.
typedef struct GpiConnection {
    /* 000 */ u8 mErrorMessage[0x100];
    /* 100 */ s32 mUnk_100;
    /* 104 */ s32 mUnk_104;
    /* 108 */ u32 mUnk_108;
    /* 10c */ s32 mFirewall;
    /* 110 */ u8 mNick[0x1f];
    /* 12f */ s8 mUniquenick[0x15];
    /* 144 */ u8 mEmail[0x33];
    /* 177 */ s8 mPassword[0x21];
    /* 198 */ u32 mSesskey;
    /* 19c */ u32 mUserId;
    /* 1a0 */ u32 mProfileId;
    /* 1a4 */ Unk02190ed4Cb mCallbacks[6];
    /* 1d4 */ s32 mConnectSocket;
    /* 1d8 */ s32 mConnectState;
    /* 1dc */ u8 *mInputBuffer;
    /* 1e0 */ s32 mInputBufferCapacity;
    /* 1e4 */ s32 mInputBufferLength;
    /* 1e8 */ s32 mUnk_1e8;
    /* 1ec */ void *mCommandBuffer;
    /* 1f0 */ s32 mCommandBufferCapacity;
    /* 1f4 */ Unk021906e4 mOutputBuffer;
    /* 204 */ s32 mListenSocket;
    /* 208 */ u32 mPort;
    /* 20c */ s32 mNextOperationId;
    /* 210 */ s32 mSearchCount;
    /* 214 */ s32 mStatus;
    /* 218 */ u8 mStatusString[0x100];
    /* 318 */ u8 mLocationString[0x100];
    /* 418 */ u32 mErrorNumber;
    /* 41c */ s32 mFatal;
    /* 420 */ s32 mUnk_420;
    /* 424 */ Unk021937c0Node *mOperationList;
    /* 428 */ Unk0218f960_428 mProfileList;
    /* 430 */ s32 mBuddyCount;
    /* 434 */ Unk02193f2cNode *mPeerList;
    /* 438 */ Unk02190ed4Node *mCallbackQueueHead;
    /* 43c */ Unk02190ed4Node *mCallbackQueueTail;
    /* 440 */ void *mUpdateproBuffer;
    /* 444 */ s32 mUpdateproBufferCapacity;
    /* 448 */ s32 mUpdateproBufferLength;
    /* 44c */ s32 mUnk_44c;
    /* 450 */ void *mUpdateuiBuffer;
    /* 454 */ s32 mUpdateuiBufferCapacity;
    /* 458 */ s32 mUpdateuiBufferLength;
    /* 45c */ s32 mUnk_45c;
    /* 460 */ void *mUnk_460;
    /* 464 */ u8 mUnk_464[8];
    /* 46c */ s32 mProductId;
    /* 470 */ s32 mNamespaceId;
    /* 474 */ s8 mUnk_474[0x19];
} GpiConnection;

// Object passed to func_ov000_0218f960 as its first argument.
typedef struct GpConnection {
    /* 00 */ GpiConnection *mGpiConnection;
} GpConnection;

typedef struct Unk0218fa98 {
    /* 00 */ u8 pad_00[8];
    /* 08 */ s32 *mUnk_08;
} Unk0218fa98;

u32 func_ov000_0218f960(GpConnection *p, u32 b);
s32 func_ov000_0218fa98(void *unused, Unk0218fa98 *object, s32 minimum);
u32 func_ov000_0218faac(GpConnection *a, u32 b);
u32 func_ov000_0218fb3c(GpConnection *a, s32 b, s32 c, const u8 *d);
u32 func_ov000_0218fbe0(GpConnection *a, s32 b, s32 c, const u8 *d);
