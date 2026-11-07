#pragma once

#include "types.h"

struct Unk0208fd8c;
struct KartAi;

// Entry of the tables at gBattleItemInUseEntries, data_0217ae34 and data_0217ae38, 0xc bytes: a function called with
// the Unk0208fd8c and the KartAi at 0x00 and halfwords at 0x08 and 0x0a.
typedef struct Unk0208fd8c_08 {
    /* 00 */ void (*mUnk_00)(struct Unk0208fd8c *a, struct KartAi *b);
// 0: item bits only; 1: then the bit 0x40 (ITEM_THROW_FORWARD_BIT); 2: then the bit 0x80.
    /* 04 */ s32 mThenBitKind;
    /* 08 */ u16 mTimerBase;
    /* 0a */ u16 mTimerRandomLimit;
} Unk0208fd8c_08;

// Object of 0x24 bytes at 0x11c of the object KartAi starts: pointers to entries of the tables at data_0217ae38
// (0x04) and gBattleItemInUseEntries or data_0217ae34 (0x08).
typedef struct Unk0208fd8c {
    /* 00 */ s16 mHeldItemTimer;
    /* 02 */ s16 mItemInUseTimer;
    /* 04 */ Unk0208fd8c_08 *mHeldItemEntry;
    /* 08 */ Unk0208fd8c_08 *mItemInUseEntry;
    /* 0c */ s32 mUnk_0c;
// While non-zero, the item bits are requested on every call.
    /* 10 */ s32 mItemBitsEveryCall;
// While set, AdvanceItemBitRequests sends ITEM_THROW_FORWARD_BIT on its calls that do not run the entry function;
// mBit6Timer (set to 2) counts those calls down.
    /* 14 */ s32 mThrowForwardPending;
// While set, AdvanceItemBitRequests sends the item bit 0x80 on its calls that do not run the entry function and no
// bit 0x40 is pending; mBit7Timer (set to 2) counts those calls down.
    /* 18 */ s32 mThrowBehindPending;
    /* 1c */ s16 mThrowForwardTimer;
    /* 1e */ s16 mThrowBehindTimer;
    /* 20 */ s32 mRandomValue;
} Unk0208fd8c;

void SetupBattleItemInUseEntry(Unk0208fd8c *a, struct KartAi *b);
void func_0208fdcc(Unk0208fd8c *a, struct KartAi *b);
void func_0208fe1c(Unk0208fd8c *a, struct KartAi *b);
void func_0208fe58(Unk0208fd8c *a, struct KartAi *b);
void func_0208fefc(Unk0208fd8c *a, struct KartAi *b);
