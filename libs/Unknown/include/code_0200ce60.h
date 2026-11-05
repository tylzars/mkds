#pragma once

#include "types.h"

// 8-byte slot at a fixed address; SwapLockGetHolderId reads its halfword at 4, SwapLockTry and SwapLockUnlockEx swap
// and clear its words.
typedef struct SwapLockSlot {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u16 mHolderId;
    /* 06 */ u16 mUnk_06;
} SwapLockSlot;

// Set to 1 by the first call of OS_InitLock; later calls return at once.
extern s32 gLockInitialized;

// One try on the lock word at 0x027fffe8 for id a, with IRQ and FIQ disabled during the try; clears bit 0x80 of
// 0x04000204 once it is taken. Returns the result of the try, 0 when taken.
s32 OS_TryLockCartridge(u32 a);
// Releases the lock word at 0x027fffe8 when id a holds it, else returns -2. Sets bit 0x80 of 0x04000204, clears the
// owner id and the lock word with IRQ and FIQ disabled, returns 0.
s32 OS_UnlockCartridge(u32 a);
s32 SwapLockTry(u32 a, SwapLockSlot *p, u32 (*f)(void), s32 k);
s32 SwapLockUnlock(u32 a, SwapLockSlot *p, u32 (*f)(void));
s32 SwapLockUnlockEx(u32 a, SwapLockSlot *p, u32 (*f)(void), s32 k);
s32 SwapLockSpin(u32 a, SwapLockSlot *p, u32 (*f)(void));
s32 SwapLockSpinEx(u32 a, SwapLockSlot *p, u32 (*f)(void), s32 k);
// Runs once. Takes the lock word at 0x027ffff0 with id 0x7e and waits until its halfword at +6 is 0, writes
// 0xffffffff at 0x027fffb0 and 0xffff0000 at 0x027fffb4, clears 0x28 bytes at 0x027fffc0, sets bits 0x800 and 0x80
// of 0x04000204, releases the lock with id 0x7e and takes it again with id 0x7f.
void OS_InitLock(void);
