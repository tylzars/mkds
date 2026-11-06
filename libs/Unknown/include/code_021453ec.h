#pragma once

#include "types.h"
#include "code_02142eac.h" // Unk021425e8Func

extern u8 data_0217f960[0x80];

// In the comments below, w is the work buffer (GetWorkBuffer()); the status area is the pointer at +4 of w, the
// request area the pointer at +0xc of w, and the callback table the words from +0x18 of w, one per command number.
// Needs state 7 or 9. Stores the first argument as the callback for command 33 and sends command 33 with one word,
// the second argument. Returns the send result.
int WM_SetEntry(Unk021425e8Func a, u32 b);
// Needs state 2. Stores the first argument as the callback for command 30, writes 30 to the first halfword of the
// request area and the four arguments after it as halfwords at +2, +4, +6 and +8, and sends command 30 with no
// words. Returns the send result.
int WM_MeasureChannel(Unk021425e8Func a, u16 b, u16 c, u16 d, u16 e);
// Returns the result of GetErrorUnlessStateAtLeast2 when it is not 0. Stores the first argument as the callback for
// command 29 and sends command 29 with four words, the four arguments after it. Returns the send result.
int WM_SetLifeTime(Unk021425e8Func a, u32 b, u32 c, u32 d, u16 e);
// Returns the result of GetErrorUnlessStateAtLeast2 when it is not 0. Returns 6 when the value is not 0 or 1. Stores
// the first argument as the callback for command 25 and sends command 25 with one word, the value. Returns the send
// result.
int WM_SetBeaconIndication(Unk021425e8Func a, u32 b);
// Needs state 7 or 9. Returns 6 when the data pointer is NULL or the size is above 0x70. Copies the size in bytes to
// data_0217f960 (MIi_CpuCopy16) and stores them (DC_StoreRange), stores the first argument as the callback for
// command 24 and sends command 24 with five words: the address of data_0217f960, the size, the fourth argument, the
// fifth (halfword) and the sixth (byte). Returns the send result.
int WM_SetGameInfo(Unk021425e8Func a, const void *b, u32 c, u32 d, u16 e, u8 f);
// Same checks and key store as WM_SetWEPKey. Stores the first argument as the callback for command 39 and sends
// command 39 with three words: the mode, the key pointer and the third argument. Returns the send result.
int WM_SetWEPKeyEx(u32 a, u32 b, u32 c, void *d);
// Returns the result of GetErrorUnlessStateAtLeast2 when it is not 0. Returns 6 when the mode is above 3, or when it
// is not 0 and the key pointer is NULL; for a mode that is not 0 stores 0x50 bytes at the key (DC_StoreRange).
// Stores the first argument as the callback for command 20 and sends command 20 with two words, the mode and the key
// pointer. Returns the send result.
int WM_SetWEPKey(u32 a, u32 b, void *c);
