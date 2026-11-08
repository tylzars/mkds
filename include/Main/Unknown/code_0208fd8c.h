#pragma once

#include "types.h"

struct KartAiItemUse;
struct KartAi;

// Entry of the tables at gBattleItemInUseEntries, gCurrentItemInUseEntries and gCurrentHeldItemEntries, 0xc bytes: a
// function called with the KartAiItemUse and the KartAi at 0x00 and halfwords at 0x08 and 0x0a.
typedef struct KartAiItemUseEntry {
    /* 00 */ void (*mHandler)(struct KartAiItemUse *a, struct KartAi *b);
// 0: item bits only; 1: then the bit 0x40 (ITEM_THROW_FORWARD_BIT); 2: then the bit 0x80.
    /* 04 */ s32 mThenBitKind;
    /* 08 */ u16 mTimerBase;
    /* 0a */ u16 mTimerRandomLimit;
} KartAiItemUseEntry;

// Object of 0x24 bytes at 0x11c of the object KartAi starts: pointers to entries of the tables at
// gCurrentHeldItemEntries (0x04) and gBattleItemInUseEntries or gCurrentItemInUseEntries (0x08).
typedef struct KartAiItemUse {
    /* 00 */ s16 mHeldItemTimer;
    /* 02 */ s16 mItemInUseTimer;
    /* 04 */ KartAiItemUseEntry *mHeldItemEntry;
    /* 08 */ KartAiItemUseEntry *mItemInUseEntry;
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
} KartAiItemUse;

void SetupBattleItemInUseEntry(KartAiItemUse *itemUse, struct KartAi *kartAi);
void func_0208fdcc(KartAiItemUse *itemUse, struct KartAi *kartAi);
void func_0208fe1c(KartAiItemUse *itemUse, struct KartAi *kartAi);
void func_0208fe58(KartAiItemUse *itemUse, struct KartAi *kartAi);
void func_0208fefc(KartAiItemUse *itemUse, struct KartAi *kartAi);
