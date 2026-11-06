#pragma once

#include "types.h"

// Two words filled by LockCartridgeAndDisableIrq and SaveAndSetExMemControlBits and read back by
// UnlockCartridgeAndRestoreIrq and RestoreExMemControlBits.
typedef struct Unk0200c4a4 {
    /* 00 */ vs32 mUnk_00;
    /* 04 */ vs32 mUnk_04;
} Unk0200c4a4;

// Two halfwords at the start of the first object this file defines.
typedef struct Unk0216fe04 {
    // Set to 1 by ReceiveCartridgeHeaderReply; InitCartridgeHeaderCopy waits until it is 1.
    /* 00 */ u16 mReplyReceived;
    // The OS_GetLockID result stored by InitCartridgeState; the first argument of every lock and unlock call of this
    // file.
    /* 02 */ u16 mLockId;
} Unk0216fe04;

// 0x40 bytes that InitCartridgeHeaderCopy flushes and fills with a copy, then reads fields from.
typedef struct Unk0216fea0 {
    /* 00 */ u8 mUnk_00[0x2c];
    /* 2c */ u32 mUnk_2c;
    /* 30 */ u16 mUnk_30;
    /* 32 */ u8 mUnk_32[3];
    /* 35 */ u8 mUnk_35[3];
    /* 38 */ u8 mUnk_38[6];
    /* 3e */ u16 mUnk_3e;
} Unk0216fea0;

typedef struct Unk0216fe20 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u8 mUnk_04[0x7c];
    // The 0x40 bytes copied from 0x08000080; InitCartridgeHeaderCopy reads the fields at +0x2c, +0x30, +0x35 and
    // +0x3e of it into the record.
    /* 80 */ Unk0216fea0 mHeaderTailCopy;
} Unk0216fe20;

// Fixed-address object written by InitCartridgeHeaderCopy and read by CTRDG_IsExisting.
typedef struct Unk027ffc30 {
    // Written by InitCartridgeHeaderCopy from +0xbe of the copy; CTRDG_IsExisting returns 0 when it is 0xffff and
    // compares it with the window.
    /* 00 */ u16 mIdHalfword;
    /* 02 */ u8 mUnk_02[3];
    /* 05 */ u8 mUnk_05_0 : 1;
    u8 mUnk_05_1 : 1;
    u8 mUnk_05_2 : 6;
    /* 06 */ u16 mUnk_06;
    // Written by InitCartridgeHeaderCopy from +0xac of the copy; CTRDG_IsExisting compares it with the word at
    // 0x080000ac.
    /* 08 */ u32 mIdWord;
} Unk027ffc30;

// Fixed-address object read by CTRDG_IsExisting.
typedef struct Unk08000000 {
    /* 00 */ u8 mUnk_00[0xac];
    // The word at 0x080000ac; CTRDG_IsExisting compares it with the word of the record at +8.
    /* ac */ u32 mIdWord;
    /* b0 */ u8 mUnk_b0[2];
    // The byte at 0x080000b2; CTRDG_IsExisting compares it with 0x96 to choose which halfword it compares with the
    // record.
    /* b2 */ u8 mIdSelector;
    /* b3 */ u8 mUnk_b3[0xb];
    // The halfword at 0x080000be; CTRDG_IsExisting compares it with the record's halfword at +0 when mIdSelector is
    // 0x96.
    /* be */ u16 mIdHalfword;
} Unk08000000;

// In the comments below, "the window" is the memory at 0x08000000, "the record" the object at 0x027ffc30 and "the
// copy" gCartridgeHeaderCopy.
// Two halfwords, mReplyReceived and mLockId; InitCartridgeState clears and fills them.
extern Unk0216fe04 gCartridgeState;
// Tested and set to 1 at the top of InitCartridgeHeaderCopy, which returns at once when it is not 0.
extern s32 gHeaderCopyStarted;
// Tested and set to 1 at the top of CTRDG_Init, which does nothing when it is not 0.
extern s32 gCartridgeInitStarted;
// Function pointer that ReceiveCartridgeRemovalMessage calls; CTRDG_Init sets it to 0 and nothing else writes it.
extern s32 (*gCartridgeRemovalCallback)(void);
// 0xc0 bytes: InitCartridgeHeaderCopy fills +4 with 0x9c bytes from 0xffff0020 and +0x80 with 0x40 bytes from
// 0x08000080, reads four fields from the second part, and sends the block's address on tag 13.
extern Unk0216fe20 gCartridgeHeaderCopy;

// Calls OS_UnLockCartridge(lockID) when the first word of p is 0, then OS_RestoreInterrupts with the second word of p.
void UnlockCartridgeAndRestoreIrq(u16 lockID, Unk0200c4a4 *p);
// Loops: stores OS_DisableInterrupts() in the second word of p and the owner id of the lock word at 0x027fffe8
// (OS_ReadOwnerOfLockWord) & 0x40 in the first word, and returns when that is not 0; otherwise calls
// OS_TryLockCartridge(lockID) and returns when it gives 0; else calls OS_RestoreInterrupts, WaitByLoop(1) and tries
// again. Returns with the interrupts disabled.
void LockCartridgeAndDisableIrq(u16 lockID, Unk0200c4a4 *p);
// Writes the first word of p (shifted left by 2) into bits 2 and 3 and the second word (shifted left by 4) into bit 4
// of the halfword at 0x04000204.
void RestoreExMemControlBits(Unk0200c4a4 *p);
// Stores bits 2 and 3 of the halfword at 0x04000204 (as 0 to 3) in the first word of the record p and bit 4 in the
// second word, then sets bits 2 and 3 and clears bit 4.
void SaveAndSetExMemControlBits(Unk0200c4a4 *p);
// Returns 0 when the halfword at 0x027ffc30 is 0xffff or bit 1 of the byte at 0x027ffc35 is set. Otherwise locks and
// compares the record with the window: the halfword at 0x080000be (0x0801fffe when the byte at 0x080000b2 is not 0x96)
// against the halfword at 0x027ffc30, and when bit 0 of the byte at 0x027ffc35 is set the word at 0x080000ac against
// the word at 0x027ffc38. On a difference sets bit 1 of that byte and returns 0, otherwise 1. Its only caller is
// PM_GoSleepMode.
s32 CTRDG_IsExisting(void);
// Zero-fills the 4 bytes of gCartridgeState (CpuSet, one word) and stores OS_GetLockID() in gCartridgeState.mLockId.
void InitCartridgeState(void);
// Sends the word 2 with SendTag13WordUntilAccepted, then calls OS_Terminate. Its only caller is
// ReceiveCartridgeRemovalMessage.
void CTRDG_TerminateForPulledOut(void);
// Tag 13 callback after CTRDG_Init: when the low 6 bits of the second argument are 0x11 calls gCartridgeRemovalCallback
// if it is not 0 (nothing in the game sets it, so the result is 0) and calls CTRDG_TerminateForPulledOut when the
// result is not 0; for any other value calls OS_Terminate. "Removal" rests on the name of its callee.
void ReceiveCartridgeRemovalMessage(u32 a, u32 b);
// Tag 13 callback while InitCartridgeHeaderCopy waits: when the low 6 bits of the second argument are 1 sets
// gCartridgeState.mReplyReceived to 1, otherwise calls OS_Terminate.
void ReceiveCartridgeHeaderReply(u32 a, u32 b);
// Runs once (gHeaderCopyStarted); returns when bit 0 of the halfword at 0x04000300 is 0. Under the cartridge lock
// copies the 0x40 bytes at 0x08000080 to the copy plus 0x80 (MI_DmaCopy16, channel 1), then fills the record from the
// copy, copies 0x9c bytes from 0xffff0020 to the copy plus 4, flushes the cache, sends ((copy - the start of main RAM)
// >> 5) << 6 | 1 on tag 13 and waits for mReplyReceived. Its only caller is CTRDG_Init.
void InitCartridgeHeaderCopy(void);
// Runs once (gCartridgeInitStarted). Calls InitCartridgeState and PxiInit, loops until PxiCallbackBitIsSet(13, 1) is
// not 0, installs ReceiveCartridgeHeaderReply as the tag 13 callback, calls InitCartridgeHeaderCopy, removes the
// callback (PxiCallbackSet(13, 0)), installs ReceiveCartridgeRemovalMessage as the tag 13 callback and sets
// gCartridgeRemovalCallback to 0. OS_Init calls it as its 13th call, before CARD_Init.
void CTRDG_Init(void);
