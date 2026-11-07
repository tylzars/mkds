#pragma once

#include "types.h"

struct Unk0208fd8c;
struct Unk020888b4;

// Entry of the tables at gBattleItemInUseEntries, data_0217ae34 and data_0217ae38, 0xc bytes: a function called with
// the Unk0208fd8c and the Unk020888b4 at 0x00 and halfwords at 0x08 and 0x0a.
typedef struct Unk0208fd8c_08 {
    /* 00 */ void (*mUnk_00)(struct Unk0208fd8c *a, struct Unk020888b4 *b);
    /* 04 */ s32 mThenBitKind;
    /* 08 */ u16 mTimerBase;
    /* 0a */ u16 mTimerRandomLimit;
} Unk0208fd8c_08;

// Object of 0x24 bytes at 0x11c of the object Unk020888b4 starts: pointers to entries of the tables at data_0217ae38
// (0x04) and gBattleItemInUseEntries or data_0217ae34 (0x08).
typedef struct Unk0208fd8c {
    /* 00 */ s16 mHeldItemTimer;
    /* 02 */ s16 mItemInUseTimer;
    /* 04 */ Unk0208fd8c_08 *mHeldItemEntry;
    /* 08 */ Unk0208fd8c_08 *mItemInUseEntry;
    /* 0c */ s32 mUnk_0c;
// While non-zero, the item bits are requested on every call.
    /* 10 */ s32 mItemBitsEveryCall;
    /* 14 */ s32 mBit6Pending;
    /* 18 */ s32 mBit7Pending;
    /* 1c */ s16 mBit6Timer;
    /* 1e */ s16 mBit7Timer;
    /* 20 */ s32 mRandomValue;
} Unk0208fd8c;

void SetupBattleItemInUseEntry(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0208fdcc(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0208fe1c(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0208fe58(Unk0208fd8c *a, struct Unk020888b4 *b);
void func_0208fefc(Unk0208fd8c *a, struct Unk020888b4 *b);
