#pragma once

#include "types.h"
#include "00/code_0219b1d4.h" // Unk0219b1d4
#include "00/code_021a4654.h" // Unk021a4654

// Six bytes at data_ov000_021b400c, written at the start of each buffer.
typedef struct Unk021b400c {
    /* 0 */ u8 mUnk_00[6];
} Unk021b400c;

// Message of 0x14 bytes; made of bytes so a copy of it is bytewise.
typedef struct Unk0219ade4 {
    /* 00 */ Unk021b400c mUnk_00;
    /* 06 */ u8 mUnk_06;
    /* 07 */ u8 mUnk_07;
    /* 08 */ u8 mUnk_08[4];
    /* 0c */ u8 mUnk_0c[4];
    /* 10 */ u8 mUnk_10[2];
    /* 12 */ u8 mUnk_12;
    /* 13 */ u8 mUnk_13;
} Unk0219ade4;

// Message of 0x15 bytes.
typedef struct Unk0219aa64 {
    /* 00 */ Unk021b400c mUnk_00;
    /* 06 */ u8 mUnk_06;
    /* 07 */ u8 mUnk_07;
    /* 08 */ u8 mUnk_08[4];
    /* 0c */ u8 mUnk_0c;
    /* 0d */ u8 mUnk_0d;
    /* 0e */ u8 mUnk_0e;
    /* 0f */ u8 mUnk_0f;
    /* 10 */ u8 mUnk_10;
    /* 11 */ u8 mUnk_11;
    /* 12 */ u8 mUnk_12;
    /* 13 */ u8 mUnk_13;
    /* 14 */ u8 mUnk_14;
} Unk0219aa64;

// Message of 0x15 bytes followed by a string.
typedef struct Unk0219aeb0 {
    /* 00 */ Unk021b400c mUnk_00;
    /* 06 */ u8 mUnk_06;
    /* 07 */ u8 mUnk_07;
    /* 08 */ u8 mUnk_08[4];
    /* 0c */ u8 mUnk_0c;
    /* 0d */ u8 mUnk_0d;
    /* 0e */ u8 mUnk_0e;
    /* 0f */ u8 mUnk_0f;
    /* 10 */ u8 mUnk_10;
    /* 11 */ u8 mUnk_11;
    /* 12 */ u8 mUnk_12;
    /* 13 */ u8 mUnk_13;
    /* 14 */ u8 mUnk_14;
    /* 15 */ char mUnk_15[0x40];
} Unk0219aeb0;

// Declared here until the code that defines them is decompiled.
BOOL func_ov000_0218e57c(u32 *a);

BOOL func_ov000_0219a654(const u8 *a, u32 *b, u16 *c);
u32 func_ov000_0219a760(u32 a, u32 b, u32 c);
void func_ov000_0219a7e4(u8 *a, s32 b, void *c);
void func_ov000_0219a8bc(Unk0219b1d4 *a, Unk0219aa64 *b, Unk021a4654 *c);
void func_ov000_0219a958(Unk0219b1d4 *a, Unk0219ade4 *b, Unk021a4654 *c);
void func_ov000_0219a9e4(Unk0219b1d4 *a, Unk0219ade4 *b, Unk021a4654 *c);
void func_ov000_0219aa64(Unk0219b1d4 *a, Unk021a4654 *b);
void func_ov000_0219aaec(void);
void func_ov000_0219ab24(Unk0219b1d4 *a);
void func_ov000_0219ac50(u32 a);
s32 func_ov000_0219ac7c(u32 a, u32 b, u32 c, void (*d)(s32 a, void *b), void (*e)(s32 a, s32 b, void *c, void *d),
                        void *f);
BOOL func_ov000_0219ad20(void);
u32 func_ov000_0219ad88(u8 *a, const u8 *b);
u32 func_ov000_0219adb4(const u8 *a);
void func_ov000_0219ade4(Unk0219b1d4 *a);
void func_ov000_0219aeb0(Unk0219b1d4 *a);
u16 func_ov000_0219b038(u32 a);
u32 func_ov000_0219b05c(void);
void func_ov000_0219b0b0(u32 a, u32 b, u16 c, void *d, s32 e);
BOOL func_ov000_0219b0ec(const u8 *a);
void func_ov000_0219b110(void);
void func_ov000_0219b130(Unk0219b1d4 *a);
Unk0219b1d4 *func_ov000_0219b178(void);
