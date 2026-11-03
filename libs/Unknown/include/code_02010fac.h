#pragma once

#include "types.h"
#include "code_02012b30.h" // Unk02012f58
#include "code_02012b30.h"

// Linked through mUnk_10. Bit 8 and bit 9 of mUnk_1a[n] are tested; the low byte is passed on to the function at
// mUnk_0c, which is called with a pointer to its result, this object and that byte.
typedef struct Unk020111e0 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ s32 mUnk_04;
    /* 08 */ u8 mUnk_08[4];
    /* 0c */ void (*mUnk_0c)(void *, struct Unk020111e0 *, u32);
    /* 10 */ struct Unk020111e0 *mUnk_10;
    /* 14 */ u8 mUnk_14[6];
    /* 1a */ u16 mUnk_1a[1];
} Unk020111e0;

// Result of func_02011254.
typedef struct Unk02011254 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ Vec3 mUnk_04[3];
    /* 28 */ Unk02012f58 mUnk_28;
} Unk02011254;

typedef struct Unk02011c58_04_04 {
    /* 00 */ u8 mUnk_00[0x10];
    /* 10 */ u32 mUnk_10; // byte offset from this struct to an array of 0x54-byte entries
} Unk02011c58_04_04;

typedef struct Unk02011c58_04 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ Unk02011c58_04_04 *mUnk_04;
} Unk02011c58_04;

// Object at mUnk_b0 of Unk02011624.
typedef struct Unk02011624_b0 {
    /* 00 */ u8 mUnk_00[0x10];
    /* 10 */ u32 mUnk_10; // bits 30 and 31 are read and set
    /* 14 */ u8 mUnk_14[0x18];
    /* 2c */ u16 mUnk_2c;
    /* 2e */ u16 mUnk_2e;
} Unk02011624_b0;

// Object whose mUnk_00 points into a byte sequence that the functions advance.
typedef struct Unk02011624 {
    /* 00 */ u8 *mUnk_00;
    /* 04 */ Unk02011c58_04 *mUnk_04;
    /* 08 */ u32 mUnk_08; // bit 0, bit 6, bit 8 and bit 9 are tested
    /* 0c */ u8 mUnk_0c[0x1c];
    /* 28 */ void (*mUnk_28)(struct Unk02011624 *);
    /* 2c */ void (*mUnk_2c)(struct Unk02011624 *);
    /* 30 */ u8 mUnk_30[4];
    /* 34 */ void (*mUnk_34)(struct Unk02011624 *);
    /* 38 */ u8 mUnk_38[4];
    /* 3c */ void (*mUnk_3c)(struct Unk02011624 *);
    /* 40 */ void (*mUnk_40)(struct Unk02011624 *);
    /* 44 */ u8 mUnk_44[0x4f];
    /* 93 */ u8 mUnk_93;
    /* 94 */ u8 mUnk_94;
    /* 95 */ u8 mUnk_95;
    /* 96 */ u8 mUnk_96;
    /* 97 */ u8 mUnk_97;
    /* 98 */ u8 mUnk_98;
    /* 99 */ u8 mUnk_99;
    /* 9a */ u8 mUnk_9a[0x16];
    /* b0 */ Unk02011624_b0 *mUnk_b0;
    /* b4 */ u8 mUnk_b4[0x18];
    /* cc */ u32 mUnk_cc[3]; // bit set indexed by a byte value (word = value >> 5)
    /* d8 */ u8 *mUnk_d8;
} Unk02011624;

// Local of func_02011c58, zero-filled as one 0x54-byte block.
typedef struct Unk02011c58_38 {
    /* 00 */ s32 mUnk_00[12];
    /* 30 */ s32 mUnk_30[9];
} Unk02011c58_38;

// Entry of the table at mUnk_0c of Unk0201290c.
typedef struct Unk0201290c_0c {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ u32 mUnk_08; // byte offset from this struct
    /* 0c */ u32 mUnk_0c; // second argument of func_01ff9144
} Unk0201290c_0c;

// Argument of the functions in data_0216185c.
typedef struct Unk0201290c_1c {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c; // bits 16-20 are tested
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ s32 mUnk_18[2];
    /* 20 */ s16 mUnk_20[2];
    /* 24 */ u32 mUnk_24[2];
    /* 2c */ u16 mUnk_2c;
    /* 2e */ u16 mUnk_2e;
    /* 30 */ s32 mUnk_30;
    /* 34 */ s32 mUnk_34;
} Unk0201290c_1c;

void func_02010fac(u32 a, s32 b, s32 c, s32 d);
void func_02010fe4(const Vec3 *a);
void func_0201100c(const Vec3 *a);
void func_02011034(void);
void func_02011074(void);
s32 func_020111e0(u32 *a, Unk020111e0 *b, u32 c);
s32 func_02011254(Unk02011254 *a, Unk020111e0 *b, u32 c);
void func_02011558(Vec3 *a, const Vec3 *b, s32 c, u32 d);
s32 func_020115c8(void *a, Unk020111e0 *b, u32 c);
void func_02011624(Unk02011624 *a);
void func_02011928(Unk02011624 *a);
void func_02011bbc(Unk02011624 *a);
void func_02011c58(Unk02011624 *a);
void func_020122cc(Unk02011624 *a, u32 b);
void func_0201261c(Unk02011624 *a, u32 b);
void func_0201290c(Unk0201290c *a, u32 b, u32 c, s32 d);
