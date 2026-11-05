#pragma once

#include "types.h"

// Pair of masks followed by the data that WM_GetSharedDataAddress returns the address of.
typedef struct Unk0214461c {
    /* 00 */ u16 mUnk_00;
    // Second halfword of each 0x200-byte block of a sharing object: bit n is set when member n's data has arrived in
    // the block (SetMemberData sets it, the block fill clears it). WM_GetSharedDataAddress returns an address only for
    // a member whose bit is set here and in the first halfword; the game reads it from the current block. (The first
    // halfword is not named: it holds the members still expected while the block fills and the whole member mask once
    // the block is finished.)
    /* 02 */ u16 mArrivedMembers;
    /* 04 */ u8 mUnk_04[0x1fc];
} Unk0214461c;

// 0x820 bytes set up by WM_StartDataSharing: four 0x200-byte blocks, then the words at mUnk_800.
typedef struct Unk021450ec {
    /* 000 */ Unk0214461c mUnk_000[4];
    /* 800 */ u16 mUnk_800[4];
    /* 808 */ u16 mUnk_808;
    /* 80a */ u16 mUnk_80a;
    /* 80c */ u16 mUnk_80c;
    // Halfword at +0x80e of a sharing object: the mask given to WM_StartDataSharing with the bit of the own member
    // index added, bit n for member n; 0 means no sharing is running (WM_EndDataSharing clears it and tests it).
    /* 80e */ u16 mMemberMask;
    // Halfword at +0x810: the byte size of one member's data (the fourth argument of WM_StartDataSharing);
    // SetMemberData copies this many bytes and GetMemberDataInBlock steps by it.
    /* 810 */ u16 mMemberDataSize;
    /* 812 */ u16 mUnk_812;
    /* 814 */ u16 mUnk_814;
    // Halfword at +0x816: the port the sharing uses (the second argument of WM_StartDataSharing); the index into the
    // port tables and the port given to WM_SetMPDataToPortEx.
    /* 816 */ u16 mPort;
    /* 818 */ u16 mUnk_818;
    /* 81a */ u16 mUnk_81a;
    // Halfword at +0x81c: 1 after WM_StartDataSharing (and after WM_StepDataSharing accepted a retry), 0 after
    // WM_EndDataSharing, 4 when ReceiveBlockSendResult got the code 10, 5 after a failed send or a message with a
    // non-zero code (WM_StepDataSharing then returns 1).
    /* 81c */ u16 mStatus;
    /* 81e */ u16 mUnk_81e;
} Unk021450ec;

// Argument of the functions that WM_SetPortCallback is given and that WM_StartDataSharing stores; WM_SetMPDataToPortEx
// passes it back.
typedef struct Unk02144920 {
    // Same bytes as the mCommand member of Unk021425e8.
    /* 00 */ u16 mCommand;
    // Same bytes as the mResultCode member of Unk021425e8.
    /* 02 */ u16 mResultCode;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 *mUnk_0c;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
    /* 14 */ u8 mUnk_14[6];
    /* 1a */ u16 mUnk_1a;
    /* 1c */ Unk021450ec *mUnk_1c;
    /* 20 */ Unk021450ec *mUnk_20;
} Unk02144920;

// In the comments below, w is the work buffer (GetWorkBuffer()); the status area is the pointer at +4 of w, the
// request area the pointer at +0xc of w, and the callback table the words from +0x18 of w, one per command number.
// Returns base plus the halfword at +0x810 of the object times the number of set bits of mask below bit.
u8 *GetMemberDataInBlock(Unk021450ec *p, u32 mask, u8 *base, u32 bit);
// Returns 0 when the object or the block is NULL or when the bit given by the third argument is not set in both
// halfwords of the block; otherwise returns GetMemberDataInBlock(object, the first halfword, the block + 4, the bit).
u8 *WM_GetSharedDataAddress(Unk021450ec *p, Unk0214461c *q, u32 bit);
// With interrupts disabled: does nothing when the first halfword of the block at +0x808 is not 0. Otherwise reads the
// halfword at +0x86 of the status area, makes the next block (+0x808 plus 1, modulo 4) current, clears the block after
// it (two ahead when +0x818 is 1) and sets its first halfword to the member mask and (the +0x86 halfword | 1), then
// sets the first halfword of the block just left to the member mask (with bit 0 cleared when the second argument is 1)
// and enables interrupts. Calls WM_SetMPDataToPortEx(ReceiveBlockSendResult, the object, that block, +0x814, member
// mask and the +0x86 halfword, the port, 1): a result of 7 stores 0xffff in the block's entry at +0x800 and advances
// +0x80a; any other result except 0 and 2 stores 5 at +0x81c.
void SendBlockIfComplete(Unk021450ec *p, u32 f);
// Does nothing when the bit given by the second argument is not set in the member mask (+0x80e). Takes the block at
// +0x808; when the bit is not set in its first halfword it does nothing unless +0x818 is 1, in which case it takes the
// next block (modulo 4) and does nothing when the bit is not set there either. Copies the halfword at +0x810 bytes from
// the third argument to the member's place (GetMemberDataInBlock; zero when it is NULL) and, with interrupts disabled,
// clears the bit in the first halfword of the block and sets it in the second.
void SetMemberData(Unk021450ec *p, u32 bit, const void *src);
// The argument is the message of a port function; the object is the pointer at +0x1c. Returns when it is NULL. When the
// halfword at +2 is not 0 stores 5 at +0x81c of the object. Otherwise it only acts for 0x15 in the halfword at +4 (7
// and 9 and every other number return): takes the data pointer at +0xc and the length at +0x10 (limited to 0x200 when
// it differs from +0x814), returns when the length is below 4 or when the bit of this station's member index (the
// halfword at +0x184 of the status area) is not set in the first halfword of the data; copies the data to the block at
// +0x808, stores the halfword at +0x1a shifted right by 1 in the entry of +0x800 for that block and advances +0x808
// (modulo 4).
void ReceiveChildPortMessage(Unk02144920 *a);
// The argument is the message of a port function; the object is the pointer at +0x1c. Returns when it is NULL. When the
// halfword at +2 is not 0 stores 5 at +0x81c of the object. Otherwise by the halfword at +4: 0x15 calls
// SetMemberData(object, the halfword at +0x12, the pointer at +0xc) and SendBlockIfComplete(object, 0); 7 calls
// SendBlockIfComplete(object, 0); 9 clears the bit of the member number at +0x12 in the first halfword of the block at
// +0x808 (and of the next one when +0x818 is 1) with interrupts disabled and calls SendBlockIfComplete(object, 0)
// (twice when +0x818 is 1).
void ReceiveParentPortMessage(Unk02144920 *a);
// The argument is the message of a send result. Looks up the function and the argument at the port given by the
// halfword at +0xa in the tables at +0xc4 and +0x104 of w, and returns unless the function is ReceiveParentPortMessage
// or ReceiveChildPortMessage and the argument is not NULL and equals the pointer at +0x20 of the message. By the
// halfword at +2: 0 stores the halfword at +0x1a shifted right by 1 in the entry of +0x800 at +0x80a and advances
// +0x80a (only when the halfword at +0x184 of the status area is 0); 10 moves +0x80a back by one (modulo 4) when the
// halfword at +0x184 is not 0 and stores 4 at +0x81c; any other value stores 5 at +0x81c.
void ReceiveBlockSendResult(Unk02144920 *a);
// Needs state 9 or 10 (otherwise that result); returns 3 when the word at +0xc of the status area is 0 and 6 when the
// object or one of the other two arguments is NULL. Reads the halfword at +0x184 of the status area (and, when it is 0,
// the halfword at +0x86) and +0x81c of the object: returns 1 when it is 5 and 3 when it is neither 1 nor 4. For index
// 0: when it was 4 stores 1 and sends the previous block again (as SendBlockIfComplete does; a result of 7 stores
// 0xffff and advances +0x80a, another result except 0 and 2 stores 5 and returns 1); when the block at +0x80c is not
// the one at +0x80a it sets bit 0 of its first halfword, copies its 0x200 bytes to the third argument
// (MemCopyHalfwords), stores the entry of +0x800 at +0x81a, advances +0x80c and the result will be 0; then calls
// SendBlockIfComplete, and for a delivered block SetMemberData(object, 0, the second argument) and, when +0x818 is 0,
// SendBlockIfComplete again (its second argument is 1 when the +0x86 halfword is not 0 and the first halfword of the
// current block is 1). For another index: when it was 4 stores 1 and sends; otherwise, when +0x80c is not +0x808, sets
// bit 0 of the first halfword of that block or, when it was set, copies the block to the third argument, stores the
// entry at +0x81a, advances +0x80c and sends; sending copies the data size bytes of the second argument to offset 0x20
// of the block at +0x80a, calls WM_SetMPDataToPortEx(ReceiveBlockSendResult, the object, that data, the data size, the
// member mask, the port, 1) and advances +0x80a; a result other than 0 and 2 stores 5 and the call returns 1. Returns 0
// when a block was delivered, otherwise 5 (or 1 after a failed send).
int WM_StepDataSharing(Unk021450ec *p, void *a, Unk0214461c *b);
// Needs state 9 or 10 (otherwise that result). Returns 6 when the object is NULL, and 3 when the halfword at +0x80e is
// 0 or the function registered for the port at +0x816 (table at +0xc4 of w) is neither ReceiveParentPortMessage nor
// ReceiveChildPortMessage. Otherwise registers 0 and 0 for that port with WM_SetPortCallback, stores 0 at +0x80e and
// +0x81c and returns 0.
int WM_EndDataSharing(Unk021450ec *p);
// Needs state 9 or 10 (otherwise that result). Returns 3 when the word at +0xc of the status area is 0, and 6 when the
// object is NULL, the port is 16 or more or the member mask is 0. Reads the halfword at +0x184 of the status area (the
// own member index) and, when it is 0, the halfword at +0x86. Clears the 0x820 bytes of the object; stores the data
// size (fourth argument) at +0x810, the port at +0x816, the last argument != 0 at +0x818 and the member mask with the
// own bit added (mask | 1 << own index) at +0x80e; stores the number of set bits at +0x812 and the size times it plus 4
// at +0x814; when the size times the number is above 0x1fc clears +0x80e and returns 6. Stores 1 at +0x81c. For index
// 0: sets the first halfword of each of the four 0x200-byte blocks to the member mask and (the halfword at +0x86 | 1),
// registers ReceiveParentPortMessage (argument: the object) for the port with WM_SetPortCallback and sends one block
// (two when +0x818 is 1) with WM_SetMPDataToPortEx(ReceiveBlockSendResult, the object, the block, +0x814, member mask
// and the +0x86 halfword, the port, 1): a result of 7 stores 0xffff in the block's entry at +0x800 and advances +0x80a;
// any other result except 0 and 2 stores 5 at +0x81c and returns 1. For another index: stores 3 at +0x80a and registers
// ReceiveChildPortMessage. Returns 0.
int WM_StartDataSharing(Unk021450ec *p, u32 n, u32 mask, u32 k, u32 flag);
// Calls WM_EndDataSharing with its argument and returns its result.
int WM_EndKeySharing(Unk021450ec *p);
// Calls WM_StartDataSharing(object, port, 0xffff, 2, 1) and returns its result.
int WM_StartKeySharing(Unk021450ec *p, u32 n);
