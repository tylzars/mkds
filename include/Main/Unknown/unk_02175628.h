#pragma once

#include "types.h"

#define PAD_KEY_B 0x2
#define PAD_KEY_DOWN 0x80
#define PAD_KEY_L 0x200
#define PAD_KEY_LEFT 0x20
#define PAD_KEY_R 0x100
#define PAD_KEY_RIGHT 0x10
#define PAD_KEY_START 0x8
#define PAD_KEY_UP 0x40
#define PAD_KEY_X 0x400
#define PAD_KEY_Y 0x800
// Bits of the pad key word (the slots' mUnk_00, mBits, mRepeatBits ... and the keyboard's key word): one bit per key.
#define PAD_KEY_A 0x1
// The four direction keys together.
#define PAD_KEY_DIRECTIONS 0xf0
// Slot of data_02175628 that the code addresses through a constant.
typedef enum Unk02175628Index { UNK_02175628_INDEX_8 = 8 } Unk02175628Index;

typedef struct Unk02175650_buf {
    /* 000 */ u32 mUnk_00;
    /* 004 */ u8 mUnk_04[0xdc8];
} Unk02175650_buf;

typedef struct Unk02175650 {
    /* 00 */ Unk02175650_buf *mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ s32 mUnk_08;
    /* 0c */ BOOL mUnk_0c;
    /* 10 */ u8 mUnk_10[0x4c];
} Unk02175650;

// One 0x5c-byte element of the array at data_02175628.
typedef struct InputSlot {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mBits;
    /* 04 */ u16 mClearedBits;
    // The masked bits on the calls where the repeat fires: the first call of a hold (state 0 -> 1), then after
    // mRepeatDelayLimit calls, then every mRepeatIntervalLimit calls; 0 on other calls.
    /* 06 */ u16 mRepeatBits;
    /* 08 */ u16 mRepeatState;
    // Calls with a masked bit held since the last fire; compared with mRepeatDelayLimit in state 1 and
    // mRepeatIntervalLimit in state 2.
    /* 0a */ u16 mRepeatCallCount;
    /* 0c */ u16 mRepeatMask;
    /* 0e */ u16 mRepeatDelayLimit;
    /* 10 */ u16 mRepeatIntervalLimit;
    /* 12 */ u16 mUnk_12;
    /* 14 */ u16 mUnk_14;
    /* 16 */ u8 mUnk_16[0x2];
    /* 18 */ u64 mUnk_18;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ void *mUnk_28;
    /* 2c */ u16 mUnk_2c;
    /* 2e */ u16 mUnk_2e;
    /* 30 */ s32 mUnk_30;
    /* 34 */ u8 mUnk_34[0x8];
    /* 3c */ s32 mSourceKind;
    /* 40 */ u16 mRequestedBits;
    /* 42 */ u16 mBitMask;
    /* 44 */ s32 mUnk_44;
    /* 48 */ u16 mPairX;
    /* 4a */ u16 mPairY;
    /* 4c */ u16 mHasPair;
    /* 4e */ u16 mUnk_4e;
    /* 50 */ u16 mUnk_50;
    /* 52 */ u16 mUnk_52;
    /* 54 */ u16 mPrevHasPair;
    /* 56 */ u16 mUnk_56;
    /* 58 */ u16 mNoPairCount;
    /* 5a */ u8 mUnk_5a;
    /* 5b */ u8 mUnk_5b;
} InputSlot;

// The 0x14 bytes at 0x48 of an element of data_02175628 (the same bytes as its mUnk_48 to mUnk_5b).
typedef struct Unk02175628_48 {
    /* 00 */ u16 mPairX;
    /* 02 */ u16 mPairY;
    /* 04 */ u16 mHasPair;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 mPrevHasPair;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ u16 mNoPairCount;
    /* 12 */ u8 mUnk_12[0x2];
} Unk02175628_48;

extern InputSlot data_0217562c[];

extern InputSlot data_02175680[];

extern InputSlot data_0217567c[];

extern InputSlot data_02175674[];

extern InputSlot data_02175672[];

extern InputSlot data_02175670[];

extern InputSlot data_02175628[];
