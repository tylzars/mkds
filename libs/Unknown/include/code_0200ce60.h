#pragma once

#include "types.h"

// 8-byte slot at a fixed address; SwapLockGetHolderId reads its halfword at 4, SwapLockTry and SwapLockUnlockEx swap
// and clear its words.
typedef struct SwapLockSlot {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u16 mHolderId;
    /* 06 */ u16 mUnk_06;
} SwapLockSlot;

extern s32 data_0216ff40;

s32 func_0200ce60(u32 a);
s32 func_0200ce80(u32 a);
s32 SwapLockTry(u32 a, SwapLockSlot *p, u32 (*f)(void), s32 k);
s32 SwapLockUnlock(u32 a, SwapLockSlot *p, u32 (*f)(void));
s32 SwapLockUnlockEx(u32 a, SwapLockSlot *p, u32 (*f)(void), s32 k);
s32 SwapLockSpin(u32 a, SwapLockSlot *p, u32 (*f)(void));
s32 SwapLockSpinEx(u32 a, SwapLockSlot *p, u32 (*f)(void), s32 k);
void func_0200d028(void);
