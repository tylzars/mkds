#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart
#include "Main/Unknown/code_020653d0.h" // Unk020653d0

// Node of the list at 0x80 of a Unk0206bcb0_514: a halfword at 0x08 and an Unk020653d0 at 0x0c.
typedef struct Unk02066ac0 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ s16 mUnk_08;
    /* 0a */ u8 mUnk_0a[2];
    /* 0c */ Unk020653d0 mUnk_0c;
} Unk02066ac0;

// Table of 0x5c-byte entries; the code writes the word at 0x00.
typedef struct Unk02175664 {
    /* 00 */ s32 mSourceKind;
    /* 04 */ u8 mUnk_04[0x58];
} Unk02175664;

typedef struct Unk02165518 {
    /* 00 */ u32 mUnk_00[3];
} Unk02165518;

extern const u32 data_02154a64[];
extern const u32 data_usa_02154a84[];
extern const u32 data_02154aa4[];
extern const u32 data_usa_02154ac4[];
extern const u32 data_usa_02154ae4[];
extern const u32 data_02154b04[];
extern const u32 data_usa_02154b24[];
extern const u32 data_02154b44[];
extern const u32 data_02154bc4[];
extern const u16 data_021654c8;
extern const s32 data_021654cc;
extern const s32 data_021654f8;
extern const s32 data_021654fc;
extern const Unk02165518 data_02165518;
extern const s32 data_0216559c[];
extern const s32 data_021655b0[];
extern Unk02175664 data_02175664[];

void func_02066ac0(Kart *a);
void func_02066de8(Kart *a);
void func_02066fe0(Kart *a);
void func_02067488(Kart *a);
u32 func_020675b4(Kart *a);
s32 func_020675f8(Kart *a);
s32 func_02067630(Kart *a);
s32 func_020676c4(Kart *a);
s32 func_020676fc(Kart *a);
s32 func_02067778(Kart *a);
s32 func_02067834(Kart *a);
s32 func_020678d4(Kart *a);
s32 func_02067984(Kart *a);
s32 func_020679bc(Kart *a);
s32 func_020679f4(Kart *a);
s32 func_02067a2c(Kart *p);
s32 func_02067a64(Kart *p);
s32 func_02067a9c(Kart *p);
s32 func_02067ad4(Kart *p);
s32 func_02067b0c(Kart *a, s32 *b, s32 c);
s32 func_02067b60(Kart *a, s32 *b);
s32 func_02067bf4(Kart *a, s32 *b);
// Declared here until the code that defines them is decompiled.
