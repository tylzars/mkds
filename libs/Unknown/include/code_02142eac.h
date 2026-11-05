#pragma once

#include "types.h"

typedef struct Unk021450ec Unk021450ec;

typedef struct Unk021425e8 Unk021425e8;
typedef void (*Unk021425e8Func)(Unk021425e8 *);

// func_02142c98 sets up the object that data_0217eed4 points to. SetCommandCallback stores a word at offset 0x18 + 4 *
// n; func_0214358c stores a function and its argument at mUnk_0c4[n] and mUnk_104[n]. The tables mUnk_018, mUnk_0c4 and
// mUnk_104 are indexed by the value in mUnk_00 of the object that func_021425e8 takes.
typedef struct Unk02142aa8 {
    /* 000 */ void *mUnk_000;
    /* 004 */ struct Unk02142988 *mUnk_004;
    /* 008 */ u32 mUnk_008;
    /* 00c */ u16 *mUnk_00c;
    /* 010 */ Unk021425e8 *mUnk_010;
    /* 014 */ u16 mUnk_014;
    /* 016 */ u16 mUnk_016;
    /* 018 */ Unk021425e8Func mUnk_018[0x2a];
    /* 0c0 */ Unk021425e8Func mUnk_0c0;
    /* 0c4 */ UnkFunc *mUnk_0c4[16];
    /* 104 */ void *mUnk_104[16];
} Unk02142aa8;

// 0x7bc bytes (func_02143520 copies them); the members are the ones the code reads. Pointed to by the word
// GetWorkBuffer returns at mUnk_004.
typedef struct Unk02142988 {
    /* 000 */ u16 mUnk_000;
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
    /* 17e */ u16 mUnk_17e;
    /* 180 */ u8 mUnk_180[4];
    /* 184 */ u16 mUnk_184;
    /* 186 */ u8 mUnk_186[8];
    /* 18e */ u16 mUnk_18e;
    /* 190 */ u16 mUnk_190;
    /* 192 */ u8 mUnk_192[0x62a];
} Unk02142988;

// Object func_021425e8 takes; the members are the ones the code reads.
struct Unk021425e8 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
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

// 0x84 bytes; mUnk_00 counts the entries of mUnk_04 that func_02142f24 fills.
typedef struct Unk02142f24 {
    /* 00 */ u8 mUnk_00;
    /* 04 */ struct {
        /* 00 */ u8 mUnk_00;
        /* 01 */ u8 mUnk_01;
        /* 04 */ const u8 *mUnk_04;
    } mUnk_04[16];
} Unk02142f24;

// Count at mUnk_04 and entry size at mUnk_06; the entries start at mUnk_0a and hold the value func_021432ac compares at
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
    /* 00 */ void *mUnk_00;
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

u16 func_02142eac(void);
Unk02142f24 func_02142f24(const u16 *a);
u16 func_02143090(void);
u16 func_02143134(void);
u16 func_021431d8(void);
u16 func_02143280(void);
void *func_021432ac(const Unk021432ac *a, u32 b);
s32 func_021433b0(void);
s32 func_0214349c(void);
s32 func_02143520(void *a);
s32 func_0214358c(u32 n, UnkFunc *f, Unk021450ec *p);
s32 func_021435e8(Unk021425e8Func a);
// In the comments below, w is the work buffer (GetWorkBuffer()); the status area is the pointer at +4 of w, the request
// area the pointer at +0xc of w, and the callback table the words from +0x18 of w, one per command number. Needs state
// 7 or 9. Returns 7 when the bitmap argument, the halfword at +0x17e of the status area and 0xfffe have no bit in
// common. Stores the first argument as the callback for command 13 and sends command 13 with one word, the bitmap.
// Returns the send result.
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
// Calls func_02142e78 with the first and third argument (the set-up of the work buffer) and returns its result when
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
// not 1, or when the word at +0xc is 1. Returns 6 when the third argument is below the result of func_021433b0 or is
// not a multiple of 0x40, or when the fifth argument is below the result of func_0214349c or is not a multiple of
// 0x20. Stores the first argument as the callback for command 14 and sends command 14 with ten words: the second
// argument, the third divided by 2, the fourth, the fifth and the six arguments after it. Returns the send result.
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
