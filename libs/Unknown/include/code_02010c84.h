#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx43

typedef struct MtxFx43 MtxFx43;
typedef struct Unk0201290c Unk0201290c;

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
    /* 28 */ MtxFx43 mUnk_28;
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

typedef struct Unk02010c84 Unk02010c84;

// Leading words of the object func_02010cec compares with the entries of data_021617f4.
typedef struct Unk02010cec_08 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mUnk_02;
} Unk02010cec_08;

// Entry of data_021617f4 (8 bytes).
typedef struct Unk021617f4 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04[4];
} Unk021617f4;

// Entry of data_021617f8 (8 bytes).
typedef struct Unk021617f8 {
    /* 00 */ void (*mUnk_00)(Unk02010c84 *, const Unk02010cec_08 *, u32);
    /* 04 */ u8 mUnk_04[4];
} Unk021617f8;

struct Unk02010c84 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ const Unk02010cec_08 *mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u8 mUnk_18;
    /* 19 */ u8 mUnk_19[3];
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u8 mUnk_20[0x34];
};

// Second argument of func_02010d98; the bytes at 0x17 and 0x18 are read.
typedef struct Unk02010d98 {
    /* 00 */ u8 mUnk_00[0x17];
    /* 17 */ u8 mUnk_17;
    /* 18 */ u8 mUnk_18;
} Unk02010d98;

// Object at data_0217029c.
typedef struct Unk0217029c {
    /* 000 */ u32 mUnk_00;
    /* 004 */ u32 mUnk_04;
    /* 008 */ s32 mUnk_08[16];
    /* 048 */ u32 mUnk_48;
    /* 04c */ MtxFx43 mUnk_4c;
    /* 07c */ u32 mUnk_7c;
    /* 080 */ u32 mUnk_80;
    /* 084 */ u32 mUnk_84;
    /* 088 */ u32 mUnk_88;
    /* 08c */ u32 mUnk_8c;
    /* 090 */ u32 mUnk_90;
    /* 094 */ u32 mUnk_94;
    /* 098 */ u32 mUnk_98;
    /* 09c */ u32 mUnk_9c;
    /* 0a0 */ u32 mUnk_a0;
    /* 0a4 */ u32 mUnk_a4;
    /* 0a8 */ u32 mUnk_a8;
    /* 0ac */ u32 mUnk_ac;
    /* 0b0 */ u32 mUnk_b0;
    /* 0b4 */ u32 mUnk_b4;
    /* 0b8 */ u32 mUnk_b8;
    /* 0bc */ MtxFx43 mUnk_bc;
    /* 0ec */ Vec3 mUnk_ec;
    /* 0f8 */ u32 mUnk_f8;
    /* 0fc */ u32 mUnk_fc;
    /* 100 */ MtxFx43 mUnk_100[3];
    /* 190 */ u8 mUnk_190[0xb0];
    /* 240 */ u32 mUnk_240;
    /* 244 */ u32 mUnk_244;
    /* 248 */ u32 mUnk_248;
    /* 24c */ u32 mUnk_24c;
    /* 250 */ u32 mUnk_250;
    /* 254 */ u32 mUnk_254;
    /* 258 */ u32 mUnk_258;
    /* 25c */ u32 mUnk_25c;
    /* 260 */ u32 mUnk_260;
} Unk0217029c;

void func_02010c84(Unk02010c84 *a, u32 b);
void func_02010cec(Unk02010c84 *a, const Unk02010cec_08 *b, u32 c, u32 d);
u32 func_02010d98(const u8 *a, const Unk02010d98 *b);
MtxFx43 *func_02010de8(void);
MtxFx43 *func_02010e2c(void);
void func_02010e70(void);
MtxFx43 *func_02010ed4(void);
void func_02010f24(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);
void func_02010f50(u32 a, u32 b, u32 c);
void func_02010f74(u32 a, u32 b, u32 c);
void func_02010f98(u32 arg0, u32 arg1);
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
