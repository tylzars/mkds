#pragma once

#include "types.h"

typedef struct Unk021450ec Unk021450ec;

typedef struct Unk021425e8 Unk021425e8;
typedef void (*Unk021425e8Func)(Unk021425e8 *);

// InitWorkBufferWithSize sets up the object that data_0217eed4 points to. SetCommandCallback stores a word at offset
// 0x18 + 4 * n; WM_SetPortCallback stores a function and its argument at mPortCallbacks[n] and mPortCallbackArgs[n].
// The tables mCommandCallbacks, mPortCallbacks and mPortCallbackArgs are indexed by the value in mCommand of the object
// that ReceiveCommandReply takes.
typedef struct Unk02142aa8 {
    /* 000 */ void *mUnk_000;
    // Pointer to the status area (0x7bc bytes are copied by WM_ReadStatus); set by InitWorkBufferWithSize 0x300 bytes
    // after the first area. This code only reads it, after invalidating the cache lines.
    /* 004 */ struct Unk02142988 *mStatusArea;
    /* 008 */ u32 mUnk_008;
    // Pointer to the 0x100-byte request area, 0x800 bytes after the status area: the command functions write their
    // parameter record into it, and SendCommandMessage stores it and, for a send with no words, copies it into the
    // message.
    /* 00c */ u16 *mRequestArea;
    // Pointer to a 0x100-byte area of the message type, 0x100 bytes after the request area. Its address is the third
    // word of commands 0 and 3. ReceiveCommandReply invalidates it on entry and exit and does not mark a received
    // message as free when the message is this area.
    /* 010 */ Unk021425e8 *mMessageArea;
    /* 014 */ u16 mUnk_014;
    /* 016 */ u16 mUnk_016;
    // Table of 0x2a functions, one per command number: SetCommandCallback stores them, ReceiveCommandReply calls the
    // one for the command number of a message.
    /* 018 */ Unk021425e8Func mCommandCallbacks[0x2a];
    // Function stored by WM_SetIndCallback; ReceiveCommandReply calls it for a message numbered 0x80.
    /* 0c0 */ Unk021425e8Func mIndicationCallback;
    // 16 functions, one per port, stored by WM_SetPortCallback; ReceiveCommandReply calls the one at the port of a
    // message numbered 0x82 and calls each of them for replies to commands 8 and 12 whose halfword at +8 is 7 or 9.
    /* 0c4 */ UnkFunc *mPortCallbacks[16];
    // 16 words, one per port, stored by WM_SetPortCallback; copied to +0x1c of the message before the port function is
    // called.
    /* 104 */ void *mPortCallbackArgs[16];
} Unk02142aa8;

// 0x7bc bytes (WM_ReadStatus copies them); the members are the ones the code reads. Pointed to by the word
// GetWorkBuffer returns at mUnk_004.
typedef struct Unk02142988 {
    // First halfword of the status area: the state number. GetErrorUnlessStateIsOneOf and GetErrorUnlessStateAtLeast2
    // compare it, WM_GetLinkLevel switches on it (9, 10, 11) and the game's start-up code switches on it and waits for
    // 2. This code never writes it. The same bytes as seen through both typedefs.
    /* 000 */ u16 mState;
    /* 002 */ u8 mUnk_002[2];
    /* 004 */ void *mUnk_004;
    /* 008 */ u8 mUnk_008[4];
    /* 00c */ u32 mUnk_00c;
    /* 010 */ u32 mUnk_010;
    /* 014 */ u8 mUnk_014[0x32];
    /* 046 */ u16 mUnk_046;
    /* 048 */ u8 mUnk_048[8];
    /* 050 */ void *mUnk_050;
    /* 054 */ u8 mUnk_054[0x32];
    /* 086 */ u16 mUnk_086;
    /* 088 */ u8 mUnk_088[0x30];
    /* 0b8 */ u16 mUnk_0b8;
    /* 0ba */ u8 mUnk_0ba[8];
    /* 0c2 */ u16 mUnk_0c2;
    /* 0c4 */ u8 mUnk_0c4[0x30];
    /* 0f4 */ u16 mUnk_0f4;
    /* 0f6 */ u8 mUnk_0f6[0x88];
    // Halfword at +0x17e of the status area: a bitmap in which bit n belongs to member number n. WM_Disconnect,
    // WM_DisconnectChildren (with 0xfffe), WM_ReadMPData and WM_SetMPDataToPortEx test its bits and WM_GetLinkLevel
    // returns 0 in state 9 when it is 0. This code never writes it.
    /* 17e */ u16 mConnectedChildren;
    /* 180 */ u8 mUnk_180[4];
    // Halfword at +0x184 of the status area: 0 selects the parent paths (WM_GetMPReceiveBufferSize,
    // WM_StartDataSharing, WM_StepDataSharing), any other value is this station's bit position (1 << value) in the
    // member masks. This code never writes it.
    /* 184 */ u16 mOwnMemberIndex;
    /* 186 */ u8 mUnk_186[8];
    /* 18e */ u16 mUnk_18e;
    /* 190 */ u16 mUnk_190;
    /* 192 */ u8 mUnk_192[0x62a];
} Unk02142988;

// Object ReceiveCommandReply takes; the members are the ones the code reads.
struct Unk021425e8 {
    // First halfword of a message: the command number the message belongs to (below 0x2a), or 0x80, 0x81 or 0x82 for
    // the notices that ReceiveCommandReply handles. In a ring message bit 15 set means the message is free:
    // SendCommandMessage tests it and ReceiveCommandReply sets it after handling. ReceiveCommandReply rewrites 0x81 to
    // 0xf.
    /* 00 */ u16 mCommand;
    // Halfword at +2 of a message: 0 means success, every other value is an error number (the game switches on it and
    // passes it to its error reporter; the sharing functions store 5 in the object for any other value).
    /* 02 */ u16 mResultCode;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ union {
        struct {
            void *mUnk_08;
            void *mUnk_0c;
        };
        struct {
            u16 mUnk_08_0;
            u16 mUnk_08_2;
        };
        struct {
            u8 mUnk_08_b[2];
            u8 mUnk_0a[6];
        };
    };
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
    /* 14 */ u8 mUnk_14[6];
    /* 1a */ u16 mUnk_1a;
    /* 1c */ void *mUnk_1c;
    /* 20 */ u16 mUnk_20;
    /* 22 */ u8 mUnk_22[2];
    /* 24 */ u8 mUnk_24[0x12];
    /* 36 */ u16 mUnk_36;
    /* 38 */ struct {
        u32 mUnk_00[0x20];
    } mUnk_38;
};

// 0x84 bytes; mUnk_00 counts the entries of mUnk_04 that WM_GetOtherElements fills.
typedef struct Unk02142f24 {
    /* 00 */ u8 mUnk_00;
    /* 04 */ struct {
        /* 00 */ u8 mUnk_00;
        /* 01 */ u8 mUnk_01;
        /* 04 */ const u8 *mUnk_04;
    } mUnk_04[16];
} Unk02142f24;

// Count at mUnk_04 and entry size at mUnk_06; the entries start at mUnk_0a and hold the value WM_ReadMPData compares at
// +4.
typedef struct Unk021432ac {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u8 mUnk_08[2];
    /* 0a */ u8 mUnk_0a[1];
} Unk021432ac;

// Written to the buffer at mUnk_0c of an Unk02142aa8 by WM_StartConnectEx.
typedef struct Unk021437d8 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ u16 *mUnk_04;
    /* 08 */ u8 mUnk_08[0x18];
    /* 20 */ u32 mUnk_20;
    /* 24 */ u8 mUnk_24[2];
    /* 26 */ u16 mUnk_26;
} Unk021437d8;

// Taken by WM_StartScanEx.
typedef struct Unk021438f0 {
    /* 00 */ void *mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u8 mUnk_0a[6];
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
    /* 14 */ u8 mUnk_14[0x20];
    /* 34 */ u16 mUnk_34;
} Unk021438f0;

// Written to the buffer at mUnk_0c of an Unk02142aa8 by WM_StartScanEx.
typedef struct Unk021438f0_0c {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ void *mUnk_04;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u8 mUnk_0c[6];
    /* 12 */ u16 mUnk_12;
    /* 14 */ u16 mUnk_14;
    /* 16 */ u8 mUnk_16[0x20];
    /* 36 */ u16 mUnk_36;
} Unk021438f0_0c;

// Taken by WM_StartScan.
typedef struct Unk02143a78 {
    /* 00 */ void *mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u8 mUnk_08[6];
} Unk02143a78;

// Written to the buffer at mUnk_0c of an Unk02142aa8 by WM_StartScan.
typedef struct Unk02143a78_0c {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ void *mUnk_04;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u8 mUnk_0a[6];
} Unk02143a78_0c;

// Taken by IsParentParameterInRange and WM_SetParentParameter.
typedef struct Unk02143c30 {
    /* 00 */ struct Unk0217aa00_24_50 *mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[6];
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u8 mUnk_12[2];
    /* 14 */ u16 mUnk_14;
    /* 16 */ u8 mUnk_16[2];
    /* 18 */ u16 mUnk_18;
    /* 1a */ u8 mUnk_1a[0x18];
    /* 32 */ u16 mUnk_32;
    /* 34 */ u16 mUnk_34;
    /* 36 */ u16 mUnk_36;
} Unk02143c30;

// In the comments below, w is the work buffer (GetWorkBuffer()); the status area is the pointer at +4 of w, the
// request area the pointer at +0xc of w, and the callback table the words from +0x18 of w, one per command number.
// When data_0216f06c is 0x10000, calls RTC_Init and RTC_GetTime and, when that returns 0, stores the third word of the
// time plus the second word shifted left by 8 (16 bit) in it. Adds 1 (16 bit), stores the sum in data_0216f06c and
// returns it.
u16 WM_GetNextTgid(void);
// Returns a 0x84-byte record: a count byte, then 16 entries of two bytes and a pointer. The count is 0 when the
// halfword at +0x3c of the argument is not 0; otherwise it is the halfword at +0x3e, at most 16. The entries are read
// from +0x40 of the argument one after another: the first byte, the second byte (the length) and the address of the
// bytes after those two; each entry takes its length plus 2 bytes. When the running total of those exceeds the halfword
// at +0 of the argument times 2 minus 0x40 (as a byte), the count is set to 0.
Unk02142f24 WM_GetOtherElements(const u16 *a);
// Adds the six bytes of OS_GetMacAddress and the word at 0x027ffc3c (16 bit), multiplies by 13 (16 bit) and returns the
// remainder after division by 10 plus 30.
u16 WM_GetDispersionScanPeriod(void);
// Adds the six bytes of OS_GetMacAddress and the word at 0x027ffc3c (16 bit), multiplies by 7 (16 bit) and returns the
// remainder after division by 20 plus 200.
u16 WM_GetDispersionBeaconPeriod(void);
// Returns 0 when GetErrorUnlessInitialized is not 0. Invalidates the first halfword of the status area (the state) and
// switches on it: for 9 it returns 0 when the halfword at +0x17e is 0, otherwise, and for 10 and 11, it returns the
// halfword at +0xb8; any other state returns 0.
u16 WM_GetLinkLevel(void);
// Returns 0x8000 when GetErrorUnlessInitialized is not 0, otherwise the halfword at 0x027ffcfa.
u16 WM_GetAllowedChannel(void);
// Returns 0 when GetErrorUnlessInitialized is not 0, when the second argument is not 1 to 15, when that bit of the
// halfword at +0x17e of the status area is clear or when the halfword at +4 of the first argument is 0. Otherwise walks
// the records of the first argument: the first at +10, each next one the halfword at +6 bytes after the previous, at
// most the halfword at +4 records; returns the record whose halfword at +4 equals the second argument, or 0.
void *WM_ReadMPData(const Unk021432ac *a, u32 b);
// Returns 0 when GetErrorUnlessStateIsOneOf(2, 7, 8) is not 0 or when the word at +0xc of the status area is 1. Reads
// the halfword at +0x190 as v. When the halfword at +0x184 is not 0 returns ((v + 0x51) & ~0x1f) << 1; when it is 0
// returns (((v + 0xc) * the halfword at +0xf4 + 0x29) & ~0x1f) << 1.
s32 WM_GetMPReceiveBufferSize(void);
// Returns 0 when GetErrorUnlessStateIsOneOf(2, 7, 8) is not 0 or when the word at +0xc of the status area is 1;
// otherwise returns (the halfword at +0x18e + 0x1f) & ~0x1f.
s32 WM_GetMPSendBufferSize(void);
// Returns the result of GetErrorUnlessInitialized when it is not 0 and 6 when the argument is NULL. Invalidates the
// 0x7bc bytes of the status area and copies them to the argument (MemCopyWordsByBlock). Returns 0.
s32 WM_ReadStatus(void *a);
// Disables interrupts, returns the result of GetErrorUnlessInitialized when it is not 0 (after restoring them). Stores
// the second argument at the index given by the first argument (not range checked) in the table at +0xc4 of w and the
// third argument at the same index in the table at +0x104, restores interrupts and returns 0.
s32 WM_SetPortCallback(u32 n, UnkFunc *f, Unk021450ec *p);
// Disables interrupts, returns the result of GetErrorUnlessInitialized when it is not 0 (after restoring them). Stores
// the argument at +0xc0 of w, restores interrupts and returns 0.
s32 WM_SetIndCallback(Unk021425e8Func a);
// Needs state 7 or 9. Returns 7 when the bitmap argument, the halfword at +0x17e of the status area and 0xfffe have no
// bit in common. Stores the first argument as the callback for command 13 and sends command 13 with one word, the
// bitmap. Returns the send result.
s32 WM_DisconnectChildren(Unk021425e8Func a, u32 b);
// Needs state 7, 9, 8, 10 or 11. In state 7 or 9 returns 6 when the id is not 1 to 15 and 7 when bit id of the
// halfword at +0x17e of the status area is clear; in the other states returns 6 when the id is not 0. Stores the
// first argument as the callback for command 13 and sends command 13 with one word, 1 shifted left by the id.
// Returns the send result.
s32 WM_Disconnect(Unk021425e8Func a, u32 b);
// Needs state 2. Returns 6 when the second argument is NULL. Stores 2 times the halfword at that pointer in bytes at
// it (DC_StoreRange), stores the first argument as the callback for command 12, writes 12 to the first halfword of
// the request area, the second argument to +4, 24 bytes of the third argument to +8 (24 zero bytes when it is NULL),
// the fourth argument to +32 and the fifth, as a halfword, to +38, and sends command 12 with no words. Returns the
// send result.
s32 WM_StartConnectEx(Unk021425e8Func a, u16 *b, void *c, u32 d, u16 e);
// Needs state 5. Stores the argument as the callback for command 11 and sends command 11 with no words. Returns the
// send result.
s32 WM_EndScan(Unk021425e8Func a);
// Needs state 2, 3 or 5. Returns 6 when the record pointer is NULL, the pointer at +0 is NULL, the halfword at +4 is
// above 0x400, the halfword at +0x12 is above 0x20, the halfword at +0x10 is above 3, or, when that halfword is 2 or
// 3, the halfword at +0x34 is above 0x20. Stores the first argument as the callback for command 38, writes 38 to the
// first halfword of the request area and fills it from the record (the pointer at +0, the halfwords at +4, +6, +8,
// +0x10, +0x12 and +0x34, 6 bytes from +10 and 32 bytes from +20, MemCopy), and sends command 38 with no words.
// Returns the send result.
s32 WM_StartScanEx(Unk021425e8Func a, Unk021438f0 *b);
// Needs state 2, 3 or 5. Returns 6 when the record pointer is NULL, the pointer at +0 is NULL or the halfword at +4
// is not 1 to 14. Stores the first argument as the callback for command 10, writes 10 to the first halfword of the
// request area, the halfword at +4 of the record to +2, the pointer at +0 to +4, the halfword at +6 to +8 and the
// six bytes from +8 to +10 of the request area, and sends command 10 with no words (SendCommandMessage copies the
// request area). Returns the send result.
s32 WM_StartScan(Unk021425e8Func a, Unk02143a78 *b);
// Needs state 7. Stores the argument as the callback for command 9 and sends command 9 with no words. Returns the
// send result.
s32 WM_EndParent(Unk021425e8Func a);
// Calls StartParentWithArgument(argument, 1).
s32 WM_StartParent(Unk021425e8Func a);
// Needs state 2. Stores the first argument as the callback for command 8 and sends command 8 with one word, the
// second argument (both callers pass 1). Returns the send result.
s32 StartParentWithArgument(Unk021425e8Func a, u32 b);
// Returns 0 when the halfword at +4 is above 0x70, the halfword at +0x18 is below 10 or above 1000, or the halfword
// at +0x32 is below 1 or above 14; otherwise returns 1. (Its only caller ignores the result.)
u32 IsParentParameterInRange(const Unk02143c30 *a);
// Needs state 2. Returns 6 when the record pointer is NULL, when the halfword at +4 is not 0 and the pointer at +0
// is NULL, or when the halfword at +0x34 plus 0x2a (0 when the halfword at +0x14 is 0) or the halfword at +0x36 plus
// 6 (0 when that halfword is 0) is above 0x200. Calls IsParentParameterInRange on the record and ignores the result.
// Stores the first argument as the callback for command 7, stores 0x40 bytes of the record and, when the halfword at
// +4 is not 0, that many bytes at the pointer at +0 (DC_StoreRange), and sends command 7 with one word, the record
// address. Returns the send result.
s32 WM_SetParentParameter(Unk021425e8Func a, Unk02143c30 *b);
// Needs state 2 (returns the result of GetErrorUnlessStateIsOneOf otherwise). Stores the argument as the callback
// for command 2 and sends command 2 with no words. Returns the send result.
s32 WM_End(Unk021425e8Func a);
// Returns GetErrorUnlessStateAtLeast2's result when it is not 0. Stores the argument as the callback for command 1
// and sends command 1 with no words. Returns the send result.
s32 WM_Reset(Unk021425e8Func a);
// Calls WM_Init with the first and third argument (the set-up of the work buffer) and returns its result when
// it is not 0. Stores the second argument as the callback for command 0 and sends command 0 with three words: the
// pointers at +0 and +4 and the word at +0x10 of w. Returns the send result.
s32 WM_Initialize(void *a, Unk021425e8Func b, u32 c);
// Needs state 2. Stores the argument as the callback for command 6 and sends command 6 with no words. Returns the
// send result.
s32 WM_PowerOff(Unk021425e8Func a);
// Needs state 1. Stores the argument as the callback for command 5 and sends command 5 with no words. Returns the
// send result.
s32 WM_PowerOn(Unk021425e8Func a);
// Needs state 1. Stores the argument as the callback for command 4 and sends command 4 with no words. Returns the
// send result.
s32 WM_Disable(Unk021425e8Func a);
// Needs state 0. Stores the argument as the callback for command 3 and sends command 3 with three words: the
// pointers at +0 and +4 and the word at +0x10 of w. Returns the send result.
s32 WM_Enable(Unk021425e8Func a);
// Needs state 9 or 10. Returns 3 when the word at +0xc of the status area is 0. Stores the argument as the callback
// for command 16 and sends command 16 with no words. Returns the send result.
s32 WM_EndMP(Unk021425e8Func a);
// Needs state 9 or 10. Reads the largest size from the halfword at +0x18e of the status area; when the halfword at
// +0x184 is 0 it also reads the halfword at +0x17e, otherwise it takes 1. Returns 6 when the data pointer is NULL, 7
// when that value is 0, 6 when the data pointer equals the word at +0x50 of the status area, 6 when the size plus 4
// (when the halfword at +0x184 is 0) or 2 is above the largest size, and 6 when the size is 0. Stores the data
// (DC_StoreRange) and sends command 15 with seven words: the data pointer, the size, the three halfword arguments
// after it, the first argument and the second argument. No callback is stored in the table. Returns the send result.
s32 WM_SetMPDataToPortEx(UnkFunc *a, Unk021450ec *b, void *c, s32 d, u16 e, u16 f, u16 g);
s32 func_021441d0(Unk021425e8Func a, u32 b);
// Needs state 7 or 8. Returns 3 when the halfword at +0x184 of the status area is not 0 and the halfword at +0xc2 is
// not 1, or when the word at +0xc is 1. Returns 6 when the third argument is below the result of
// WM_GetMPReceiveBufferSize or is not a multiple of 0x40, or when the fifth argument is below the result of
// WM_GetMPSendBufferSize or is not a multiple of 0x20. Stores the first argument as the callback for command 14 and
// sends command 14 with ten words: the second argument, the third divided by 2, the fourth, the fifth and the six
// arguments after it. Returns the send result.
s32 WM_StartMPEx(Unk021425e8Func a, u32 b, s32 c, u32 d, u16 e, u16 f, u16 g, u32 h, u32 i, u32 j, u32 k);
// Needs state 11. Returns 3 when the word at +0x10 of the status area is 0. Stores the argument as the callback for
// command 19 and sends command 19 with no words. Returns the send result.
s32 WM_EndDCF(Unk021425e8Func a);
// Needs state 11. Returns 3 when the word at +0x10 of the status area is 0, and 6 when the size is above 0x5e4.
// Stores the data (DC_StoreRange), stores the first argument as the callback for command 18, copies 6 bytes from the
// second argument (MemCopy) and sends command 18 with four words: the six bytes as two words, the data pointer and
// the size. Returns the send result.
s32 WM_SetDCFData(Unk021425e8Func a, const void *b, void *c, u32 d);
// Needs state 8. Returns 3 when the word at +0x10 of the status area is 1, and 6 when the size is below 0x10 or the
// buffer pointer is NULL. Stores the buffer (DC_StoreRange), stores the first argument as the callback for command
// 17 and sends command 17 with two words, the buffer pointer and the size. Returns the send result.
s32 WM_StartDCF(Unk021425e8Func a, void *b, u32 c);
