#pragma once

#include "types.h"
#include "code_02142eac.h"
#include "code_021445e0.h"
#include "Main/Unknown/unk_0217e000.h"

// In the comments below, w is the work buffer (GetWorkBuffer()); the status area is the pointer at +4 of w, the
// request area the pointer at +0xc of w, and the callback table the words from +0x18 of w, one per command number.
// Returns 0 when GetErrorUnlessInitialized is not 0, otherwise the status area.
Unk02142988 *GetStatusArea(void);
void func_021425cc(void);
// Callback of tag 10 (the message pointer is the second argument); returns at once when the third argument is not 0.
// Invalidates the 0x100-byte message area and, when the halfword at +0x16 of w is 0, the 0x800 bytes of the status
// area; invalidates the message unless it is the message area. By the first halfword m of the message: 0x80 (notice):
// loops forever when the halfword at +2 is 0x13, otherwise calls the function at +0xc0 of w when it is not NULL; 0x82:
// when the function at the port number (halfword at +6) in the table at +0xc4 of w is not NULL, copies the matching
// argument of the table at +0x104 to +0x1c of the message, invalidates the bytes at the pointer at +8 (the size is the
// halfword at +0x46 of the status area) and calls the function; 0x81: stores 0xf in the first halfword and calls the
// function at +0x1c of the message when it is not NULL. A number below 0x2a is a command: for 14 with a halfword at +4
// of 11 or 12 and a result of 0 it invalidates the bytes at the pointer at +8 (the size at +0x46 of the status area);
// for 2 with a result of 0 it reads the entry of the callback table for 2, calls WM_Finish, calls the entry when it is
// not NULL and returns; for any other number it calls the entry of the callback table for the number when it is not
// NULL (and returns when the library is no longer set up afterwards). For 8 or 12 whose halfword at +8 is 7 or 9 it
// fills data_0217ef20 (0x82, result 0, the code in +4, six bytes copied from the message) and calls every function of
// the port table with it. At the end it invalidates the message area, clears bit 0 of the halfword at 0x027fff96 and,
// unless the message is the message area, sets bit 15 of its first halfword and stores it (DC_StoreRange).
void ReceiveCommandReply(u32 a, Unk021425e8 *m, s32 c);
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
// Takes the first message of the ring with OS_ReceiveMessage and returns 8 when there is none. Invalidates its
// first 2 bytes; when bit 15 of the first halfword is clear puts the message back at the front (OS_JamMessage)
// and returns 8. With a word count of 0 stores the 0x100-byte request area, invalidates the message and copies the
// request area into it with MI_DmaCopy32 (DMA number at +0x14 of w). Writes the command number to the first halfword
// and the words to +4 on, stores the 0x100 bytes (DC_StoreRange), sends the message address on tag 10 with
// PxiSendFifoWord, appends the message to the ring again and returns 8 when the send result is negative, otherwise
// 2.
s32 SendCommandMessage(u32 a, u16 b, ...);
// Stores the function at the slot of the command number in the callback table (w + 0x18 + 4 times the number).
u32 SetCommandCallback(u32 arg0, u32 arg1);
// Returns 3 when GetErrorUnlessInitialized is not 0 and the result of GetErrorUnlessStateIsOneOf(1, 0) when that is not
// 0. Clears bit 0 of the halfword at 0x027fff96, removes the callback of tag 10 (PxiCallbackSet(10, 0)) and stores 0 in
// data_0217eed4 and data_0217eed0. Returns 0.
s32 WM_Finish(void);
// Returns 3 when data_0217eed0 is not 0. Sets it to 1, then returns 6 (setting it back to 0) when the buffer is NULL,
// the DMA number is above 3 or the buffer is not 32-byte aligned. Calls PxiInit and returns 4 (setting it back to 0)
// when PxiCallbackBitIsSet(10, 1) is 0. Invalidates the size bytes at the buffer, fills them with zero by DMA, stores
// the buffer in data_0217eed4 and lays out the areas: the word at +0 of w is the buffer + 0x200, the status area is
// 0x300 after it, the request area 0x800 after that and the message area 0x100 after that. Clears bit 0 of the halfword
// at 0x027fff96, stores the DMA number at +0x14 and calls WM_SetPortCallback(i, 0, 0) for the ports 0 to 15.
// Initialises the ring (OS_InitMessageQueue, 10 entries), writes 0x8000 to the first halfword of each of the ten
// 0x100-byte messages, stores those 2 bytes (DC_StoreRange) and appends the message, and installs ReceiveCommandReply
// on tag 10 (PxiCallbackSet). Returns 0.
s32 InitWorkBufferWithSize(void *buf, u32 n, u32 size);
// Calls InitWorkBufferWithSize with its two arguments and the size 0xf00. When that returns 0, stores 0 in the halfword
// at +0x16 of w. Returns the result.
s32 WM_Init(void *buf, u32 n);
