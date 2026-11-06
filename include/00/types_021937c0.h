#pragma once

#include "types.h"
#include "00/types_021906e4.h"

// Object behind GpiOperation.mUnk_04: GpiCreateSearch clears and fills it, GpiOpenSearchSocket sets the
// word at 0x04 and gives it the buffer at 0x08 of 0x0c bytes.
typedef struct Unk02196240 {
    /* 000 */ u32 mUnk_000;
    /* 004 */ s32 mUnk_004;
    /* 008 */ void *mUnk_008;
    /* 00c */ s32 mUnk_00c;
    /* 010 */ u32 mUnk_010;
    /* 014 */ u32 mUnk_014;
    /* 018 */ void *mUnk_018;
    /* 01c */ s32 mUnk_01c;
    /* 020 */ u32 mUnk_020;
    /* 024 */ u32 mUnk_024;
    /* 028 */ char mUnk_028[0x1f];
    /* 047 */ char mUnk_047[0x15];
    /* 05c */ char mUnk_05c[0x33];
    /* 08f */ char mUnk_08f[0x1f];
    /* 0ae */ char mUnk_0ae[0x1f];
    /* 0cd */ char mUnk_0cd[0x1f];
    /* 0ec */ char mUnk_0ec[0x44];
    /* 130 */ s32 mUnk_130;
    /* 134 */ s32 mUnk_134;
    /* 138 */ s32 mUnk_138;
    /* 13c */ s32 mUnk_13c;
    /* 140 */ s32 mUnk_140;
} Unk02196240;

typedef struct GpiOperation {
    /* 00 */ u32 mType;
    /* 04 */ Unk02196240 *mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ GpiCallback mUnk_0c;
    /* 14 */ s32 mUnk_14;
    /* 18 */ u32 mId;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ struct GpiOperation *mNext;
} GpiOperation;

typedef struct GpiPeer {
    /* 00 */ s32 mState;
    /* 04 */ u32 mUnk_04;
    /* 08 */ s32 mSocket;
    /* 0c */ u32 mProfileId;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ void *mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ BOOL mUnk_20;
    /* 24 */ u8 mUnk_24[4];
    /* 28 */ u8 mOutputBuffer[8];
    /* 30 */ s32 mOutputBufferLength;
    /* 34 */ u8 mUnk_34[4];
    /* 38 */ struct Darray *mQueuedMessages;
    /* 3c */ struct GpiPeer *mNext;
} GpiPeer;
