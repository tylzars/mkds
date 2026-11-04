#pragma once

#include "types.h"

typedef struct Unk021b0cd4 Unk021b0cd4;

// Objects whose layout isn't known yet.
extern u8 data_ov000_021b05f8[][2];

extern Unk021b0cd4 gWiFiVSSettingCallbacks;

void RegisterWiFiVSSettingCallbacks(void);
void AdvanceWiFiVSSetting(void);

#include "Main/Unknown/code_0205e2cc.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_02077bc0.h"
#include "Main/Unknown/code_02124094.h" // Unk02124b1c

// Allocated by InitWiFiVSSetting and held in gWiFiVSSetting.
typedef struct Unk021b4c70 {
    /* 0000 */ s32 mState;
    /* 0004 */ s32 mNextState;
    /* 0008 */ s32 mUnk_08;
    /* 000c */ s32 mSettingIndex;
    /* 0010 */ s32 mStateFrames;
    /* 0014 */ s16 mUnk_14[3][2];
    /* 0020 */ s32 mPendingWiFiState;
    /* 0024 */ s32 mUnk_24;
    /* 0028 */ s32 mUnk_28;
    // Count down from 6 only while mUnk_08 == 1; a press sets them to 6. Nothing fires at 0: the cell flag and offset
    // they drive stop there.
    /* 002c */ s32 mIndexDecrementTimer;
    /* 0030 */ s32 mIndexIncrementTimer;
    /* 0034 */ s32 mUnk_34;
    /* 0038 */ u8 mNscrCopy[0x1000];
    /* 1038 */ void *mHeap;
    /* 103c */ Unk02124b1c *mUnk_103c;
    /* 1040 */ Unk02021dc8 *mWiFiVSSettingSNcer;
    /* 1044 */ Ncgr *mWiFiVSSettingSNcgr;
    /* 1048 */ Nclr *mWiFiVSSettingSONclr;
    /* 104c */ Unk0201ea30 *mWiFiVSSettingBncl;
    /* 1050 */ Unk0201ea30 *mWiFiVSSettingBnbl;
    /* 1054 */ void *mWiFiVSSettingBnll;
    /* 1058 */ void *mWiFiMessages;
    /* 105c */ void *mCommonMessages;
} Unk021b4c70;

// Object behind gWiFiVSMatching; mUnk_00 selects the handler run by AdvanceWiFiVSMatching.
typedef struct Unk021b4c74 {
    /* 0000 */ s32 mState;
    /* 0004 */ s32 mNextState;
    /* 0008 */ s32 mUnk_08;
    /* 000c */ s32 mUnk_0c;
    /* 0010 */ s16 mUnk_10;
    /* 0012 */ s16 mUnk_12[3];
    /* 0018 */ s16 mUnk_18[4];
    /* 0020 */ s32 mUnk_20;
    /* 0024 */ s32 mUnk_24[3];
    /* 0030 */ s32 mUnk_30;
    /* 0034 */ u8 mUnk_34[3];
    /* 0037 */ u8 pad_37;
    /* 0038 */ s32 mUnk_38;
    /* 003c */ s32 mUnk_3c;
    /* 0040 */ s32 mUnk_40;
    /* 0044 */ s32 mUnk_44;
    /* 0048 */ s32 mUnk_48;
    /* 004c */ u16 mUnk_4c[5];
    /* 0056 */ u8 pad_56[2];
    /* 0058 */ s32 mUnk_58[5][3];
    /* 0094 */ s32 mUnk_94[5][3];
    /* 00d0 */ void *mUnk_d0;
    /* 00d4 */ u8 mUnk_d4[0x1000];
    /* 10d4 */ Unk02124b1c *mUnk_10d4;
    /* 10d8 */ u8 mUnk_10d8[3][0x200];
    /* 16d8 */ s32 mUnk_16d8[3];
    /* 16e4 */ struct Unk02021dc8 *mWiFiVSMatchingSNcer;
    /* 16e8 */ Ncgr *mWiFiVSMatchingSNcgr;
    /* 16ec */ Nclr *mWiFiVSMatchingSONclr;
    /* 16f0 */ Unk0201ea30 *mWiFiVSMatchingBncl;
    /* 16f4 */ void *mWiFiVSMatchingBnbl;
    /* 16f8 */ void *mWiFiVSMatchingBnll;
    /* 16fc */ void *mWiFiMessages;
    /* 1700 */ void *mCommonMessages;
    /* 1704 */ u8 pad_1704[8];
} Unk021b4c74;

// Four callbacks, passed to SetWiFiStateCallbacks by RegisterWiFiVSMatchingCallbacks.

// 0xc-byte element of the array at member 0x20 of Unk0217b488.
typedef struct Unk0217b488_20 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
} Unk0217b488_20;

// Object behind data_0217b488, 0x130 bytes (func_020cefa0 allocates it).
typedef struct Unk0217b488 {
    /* 000 */ s32 mUnk_00;
    /* 004 */ s32 mUnk_04;
    /* 008 */ s32 mUnk_08;
    /* 00c */ s32 mUnk_0c;
    /* 010 */ s32 mUnk_10;
    /* 014 */ s32 mUnk_14;
    /* 018 */ s32 mUnk_18;
    /* 01c */ s32 mUnk_1c;
    /* 020 */ Unk0217b488_20 mUnk_20[4];
    /* 050 */ s32 mUnk_50;
    /* 054 */ u8 mUnk_54;
    /* 055 */ u8 mUnk_55[0x3];
    /* 058 */ s32 mUnk_58;
    /* 05c */ s32 mUnk_5c[4];
    /* 06c */ s32 mUnk_6c;
    /* 070 */ s32 mUnk_70;
    /* 074 */ s32 mUnk_74;
    /* 078 */ s32 mUnk_78;
    /* 07c */ s32 mUnk_7c;
    /* 080 */ s32 mUnk_80;
    /* 084 */ s32 mUnk_84;
    /* 088 */ s32 mUnk_88;
    /* 08c */ s32 mUnk_8c;
    /* 090 */ s32 mUnk_90;
    /* 094 */ s32 mUnk_94;
    /* 098 */ Unk0217aa1c_144_00 mUnk_98[4];
    /* 0a8 */ u16 mUnk_a8;
    /* 0aa */ u8 mUnk_aa[0x2];
    /* 0ac */ s32 mUnk_ac[8];
    /* 0cc */ s32 mUnk_cc[8];
    /* 0ec */ s32 mUnk_ec[4];
    /* 0fc */ u8 mUnk_fc[0x10];
    /* 10c */ volatile s32 mUnk_10c[8];
    /* 12c */ s32 mUnk_12c;
} Unk0217b488;

// Object at member 0x8 of Unk0217d384.
typedef struct Unk0217d384_08 {
    /* 00 */ void *mUnk_00;
    /* 04 */ s32 mStateFrames;
    /* 08 */ s32 mUnk_08;
    /* 0c */ u8 mUnk_0c[0x2];
    /* 0e */ u16 mState;
    /* 10 */ u16 mNextState;
    /* 12 */ u16 mNextStateRequested;
} Unk0217d384_08;

// 0xc-byte elements of the table at member 0x19f0 of Unk0217d384.
typedef struct Unk0217d384_19f0 {
    /* 00 */ u8 mUnk_00[0xc];
} Unk0217d384_19f0;

// 0x10-byte object at member 0x1f20 of Unk0217d384.
typedef struct Unk0217d384_1f20 {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ s32 mStep;
} Unk0217d384_1f20;

// 0x44-byte elements of the tables at members 0x1d00 and 0x1e10 of Unk0217d384.
typedef struct Unk0217d384_1d00 {
    /* 00 */ s32 mKind;
    /* 04 */ s32 mSize;
    /* 08 */ u8 mFromIndex;
    /* 09 */ u8 mToIndex;
    /* 0a */ u8 mKartMask;
    /* 0b */ u8 mUnk_0b;
    /* 0c */ s32 mCharacterIndices[4];
    /* 1c */ s32 mKartIndices[4];
    /* 2c */ s32 mTalliedCourseId;
    /* 30 */ s32 mCharacterIndex;
    /* 34 */ s32 mKartIndex;
    /* 38 */ s32 mPickedCourseId;
    /* 3c */ u8 mUnk_3c[0x4];
    /* 40 */ s32 mUnk_40;
} Unk0217d384_1d00;

// 0x244-byte elements of the table at member 0x21c of Unk0217d384.
typedef struct Unk0217d384_021c {
    /* 000 */ s32 mKind;
    /* 004 */ s32 mSize;
    /* 008 */ u8 mFromIndex;
    /* 009 */ u8 mToIndex;
    // The sender's mKartMask; written, not read through this struct.
    /* 00a */ u8 mKartMask;
    /* 00b */ u8 mUnk_00b;
    /* 00c */ u8 mUnk_00c[0x14];
    /* 020 */ u8 mUnk_020[0x200];
    /* 220 */ u8 mUnk_220;
    /* 221 */ u8 mUnk_221[0x1];
    /* 222 */ s16 mElo;
    /* 224 */ u8 mUnk_224[0x10];
    /* 234 */ u8 mRegion : 4;
    /* 235 */ u8 mUnk_235;
    /* 236 */ u8 mUnk_236[0x2];
    /* 238 */ s32 mUnk_238;
    /* 23c */ s32 mUnk_23c;
    /* 240 */ s32 mSeed;
} Unk0217d384_021c;

// 0x18-byte object at member 0x1954 of Unk0217d384: three 64-bit values (x = x * [8] + [0x10] in func_02121af4).
typedef struct Unk0217d384_1954 {
    /* 00 */ u64 mValue;
    /* 08 */ u64 mMultiplier;
    /* 10 */ u64 mIncrement;
} Unk0217d384_1954;

// 8-byte object at member 0x18e0 of Unk0217d384.
typedef struct Unk0217d384_18e0 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ s32 mUnk_04;
} Unk0217d384_18e0;

// 0x18-byte elements of the table at member 0x18ec of Unk0217d384.
typedef struct Unk0217d384_18ec {
    /* 00 */ s32 mValue;
    /* 04 */ char mName[0x10];
    /* 14 */ u8 mId;
    /* 15 */ u8 pad_15[3];
} Unk0217d384_18ec;

// Object behind data_0217d384: 0x1f58 bytes allocated by func_021205ac.
typedef struct Unk0217d384 {
    /* 0000 */ void *mHeap;
    /* 0004 */ void *mHeapBuffer;
    /* 0008 */ Unk0217d384_08 mUnk_0008;
    /* 001c */ u8 mUnk_001c[4][0x80];
    /* 021c */ Unk0217d384_021c mUnk_021c[4];
    /* 0b2c */ u8 mUnk_0b2c[0xdb4];
    /* 18e0 */ Unk0217d384_18e0 mUnk_18e0;
    /* 18e8 */ s32 mStartStatus;
    /* 18ec */ Unk0217d384_18ec mKeys[4];
    /* 194c */ u8 mUnk_194c;
    /* 194d */ u8 mUnk_194d;
    /* 194e */ u8 mUnk_194e;
    /* 194f */ u8 mUnk_194f;
    /* 1950 */ s32 mStep;
    /* 1954 */ Unk0217d384_1954 mUnk_1954;
    /* 196c */ u8 mUnk_196c[0x14];
    // Calls of the step function in the current step; zeroed by every normal step change and by the timeout
    // (changes to step 11 that are not timeouts leave it as is).
    /* 1980 */ s32 mStepFrames;
    // Per kart: zeroed by the callback for that kart, counted up each step for every other kart in mKartMask; above
    // 300 it sets the kart's bit in mKartRemoveMask (while 2 < mStep < 9).
    /* 1984 */ s32 mSinceCallbackFrames[4];
    /* 1994 */ u8 mUnk_1994[0x5];
    /* 1999 */ u8 mUnk_1999;
    /* 199a */ u8 mUnk_199a[0x10];
    /* 19aa */ u8 mUnk_19aa;
    /* 19ab */ u8 mUnk_19ab;
    /* 19ac */ u8 mUnk_19ac;
    /* 19ad */ u8 mUnk_19ad;
    /* 19ae */ u8 mUnk_19ae[2];
    /* 19b0 */ u8 mUnk_19b0[0x20];
    /* 19d0 */ s32 mUnk_19d0;
    /* 19d4 */ s32 mUnk_19d4;
    /* 19d8 */ u8 mUnk_19d8[0x14];
    /* 19ec */ u32 mUnk_19ec;
    /* 19f0 */ Unk0217d384_19f0 mUnk_19f0[0x3c];
    /* 1cc0 */ u8 mUnk_1cc0[0x3c];
    /* 1cfc */ s32 mUnk_1cfc;
    /* 1d00 */ Unk0217d384_1d00 mUnk_1d00[4];
    /* 1e10 */ Unk0217d384_1d00 mUnk_1e10[4];
    /* 1f20 */ Unk0217d384_1f20 mUnk_1f20;
    /* 1f30 */ s32 mHeapCreated;
    /* 1f34 */ s32 mUnk_1f34;
    /* 1f38 */ s32 mUnk_1f38;
    /* 1f3c */ s32 mUnk_1f3c;
    /* 1f40 */ s32 mUnk_1f40;
    /* 1f44 */ s32 mUnk_1f44;
    /* 1f48 */ s32 mUnk_1f48;
    /* 1f4c */ u8 mUnk_1f4c;
    /* 1f4d */ u8 mUnk_1f4d;
    /* 1f4e */ s8 mUnk_1f4e[4];
    /* 1f52 */ u8 mKartCount;
    /* 1f53 */ u8 mStartKartCount;
    /* 1f54 */ u8 mKartCountCopy;
    /* 1f55 */ u8 mKartMask;
    /* 1f56 */ u8 mKartRemoveMask;
    /* 1f57 */ u8 mUnk_1f57;
} Unk0217d384;

extern u8 data_ov000_021b060c[3][9];
extern s32 data_ov000_021b0628[3][4];
extern u8 data_ov000_021b0670[3][2];
extern u8 data_ov000_021b0678[3][2];
extern u8 data_ov000_021b068c[3][5];
extern Unk021b4c70 *gWiFiVSSetting;
extern Unk021b4c74 *gWiFiVSMatching;

void InitWiFiVSSetting(void *heap);
void RegisterWiFiVSMatchingCallbacks(void);
void AdvanceWiFiVSMatching(void);

#include "Main/Unknown/code_020ac2fc.h"
#include "Main/Unknown/code_0210895c.h"
#include "Main/Unknown/code_02108a40.h"
#include "Main/Unknown/code_02120294.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02124f4c.h"
#include "Main/Unknown/code_0212658c.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_0212b928.h"

void InitWiFiVSMatching(void *heap);

#include "Main/Unknown/code_0202b604.h"
#include "Main/Unknown/code_02120240.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_0212a910.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_02036c5c.h"

#include "00/code_ov000_021804e0.h"
#include "00/unk_021b4000.h"
#include "00/code_02180608.h"
#include "00/code_0219b580.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02125f88.h"
#include "Main/Unknown/code_02128210.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_0212426c.h"
#include "code_02016468.h"

extern Unk0217b488 *data_0217b488;
extern u8 data_ov000_021b05e8[3];
extern u8 data_ov000_021b05ec[];
extern u8 data_ov000_021b05f0[];
// Objects whose layout isn't known yet.
extern s32 data_ov000_021b0600[];
extern u8 data_ov000_021b066c[3];

void func_02036f10(s16);
void func_ov000_02181ff0(void);
void func_ov000_02182150(void);
void func_ov000_021821e0(void);
void func_ov000_02182270(void);
void AdvanceWiFiVSSettingState11(void);
void AdvanceWiFiVSSettingState10(void);
void AdvanceWiFiVSSettingState9(void);
void AdvanceWiFiVSSettingState8(void);
void AdvanceWiFiVSSettingState7(void);
void AdvanceWiFiVSSettingState6(void);
void AdvanceWiFiVSSettingState5(void);
void AdvanceWiFiVSSettingState4(void);
void AdvanceWiFiVSSettingState3(void);
void AdvanceWiFiVSSettingState2(void);
void AdvanceWiFiVSSettingState1(void);
void AdvanceWiFiVSSettingState0(void);
void func_ov000_02182de8(void);
void func_ov000_02182e18(void);
void func_ov000_02182f88(void);
BOOL func_ov000_021832f0(void);
void func_ov000_02184354(void);
