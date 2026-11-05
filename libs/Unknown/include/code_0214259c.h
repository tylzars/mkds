#pragma once

#include "types.h"
#include "code_02142eac.h"
#include "code_021445e0.h"
#include "Main/Unknown/unk_0217e000.h"

Unk02142988 *func_0214259c(void);
void func_021425cc(void);
void func_021425e8(u32 a, Unk021425e8 *m, s32 c);
// In the comments below, w is the work buffer (GetWorkBuffer()); the status area is the pointer at +4 of w, the
// request area the pointer at +0xc of w, and the callback table the words from +0x18 of w, one per command number.
// Returns the result of GetErrorUnlessInitialized when it is not 0. Invalidates the first 2 bytes of the status
// area, then compares its first halfword (the state) with each of the n state numbers that follow the count and
// returns 0 when one is equal, otherwise 3.
s32 GetErrorUnlessStateIsOneOf(s32 n, ...);
// Returns the result of GetErrorUnlessInitialized when it is not 0. Invalidates the first 2 bytes of the status area
// and returns 3 when its first halfword (the state) is 0 or 1, otherwise 0.
s32 GetErrorUnlessStateAtLeast2(void);
// Returns 0 when the halfword data_0217eed0 is not 0, otherwise 3.
s32 GetErrorUnlessInitialized(void);
// Returns the work buffer pointer in data_0217eed4.
Unk02142aa8 *GetWorkBuffer(void);
// Takes the first message of the ring with RingQueueRemoveFront and returns 8 when there is none. Invalidates its
// first 2 bytes; when bit 15 of the first halfword is clear puts the message back at the front (RingQueuePrepend)
// and returns 8. With a word count of 0 stores the 0x100-byte request area, invalidates the message and copies the
// request area into it with MI_DmaCopy32 (DMA number at +0x14 of w). Writes the command number to the first halfword
// and the words to +4 on, stores the 0x100 bytes (DC_StoreRange), sends the message address on tag 10 with
// PxiSendFifoWord, appends the message to the ring again and returns 8 when the send result is negative, otherwise
// 2.
s32 SendCommandMessage(u32 a, u16 b, ...);
// Stores the function at the slot of the command number in the callback table (w + 0x18 + 4 times the number).
u32 SetCommandCallback(u32 arg0, u32 arg1);
s32 func_02142c24(void);
s32 func_02142c98(void *buf, u32 n, u32 size);
s32 func_02142e78(void *buf, u32 n);
