#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

// Object up to 0x109 bytes.
typedef struct CoverPooHole {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ s32 mUnk_a4;
    /* a8 */ s32 mUnk_a8;
    /* ac */ s32 mTimer;
    /* b0 */ s32 mState;
    /* b4 */ s32 mUnk_b4;
    /* b8 */ s32 mUnk_b8;
    /* bc */ s32 mUnk_bc;
    /* c0 */ s32 mUnk_c0;
    /* c4 */ u16 mUnk_c4;
    /* c6 */ u8 mUnk_c6[2];
    /* c8 */ s32 mUnk_c8;
    /* cc */ s32 mUnk_cc;
    /* d0 */ s32 mUnk_d0;
    /* d4 */ s32 mUnk_d4;
    /* d8 */ s32 mUnk_d8;
    /* dc */ s32 mUnk_dc;
    /* e0 */ s32 mUnk_e0;
    /* e4 */ u16 mUnk_e4;
    /* e6 */ u8 mUnk_e6[2];
    /* e8 */ s32 mUnk_e8;
    /* ec */ s32 mUnk_ec;
    /* f0 */ s32 mUnk_f0;
    /* f4 */ s32 mUnk_f4;
    /* f8 */ s32 mUnk_f8;
    /* fc */ s32 mUnk_fc;
    /* 100 */ s32 mUnk_100;
    /* 104 */ s32 mUnk_104;
    /* 108 */ u8 mUnk_108;
} CoverPooHole;

// Pointer table with a halfword count behind it.
typedef struct Unk020968f4 {
    /* 00 */ CoverPooHole **mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk020968f4;

typedef struct Unk02097520 {
    /* 00 */ u8 mUnk_00[0x2];
    /* 02 */ u16 mUnk_02;
} Unk02097520;

// A second type for the kind 0x1a9 (Flipper) objects: only the prefix up to mUnk_ebc is used.
typedef struct Unk0209753c {
    /* 00 */ u8 mUnk_00[0xebc];
    /* ebc */ u32 mUnk_ebc;
} Unk0209753c;

#include "Main/Unknown/unk_0217b000.h" // Unk0217b498_00
#include "Main/Unknown/code_0206bcb0.h" // Kart

BOOL func_02095f38(Unk0217b498_00 *a);
u32 func_02095f5c(void);
u32 func_02095f7c(void);
void func_02095f9c(void);
void UpdateCoverPooHole(void *a, CoverPooHole *p); /* skipped for objects with mFlags & 4 (parked pool objects) */
s32 func_020968c0(s32 a, s32 b);
s32 func_020968dc(s32 a);
void func_020968f4(Unk020968f4 *p);
void DrawCoverPooHole(void *a, CoverPooHole *p);
void CreateCoverPooHole(void *a);
BOOL func_02096df0(CoverPooHole *p, const Vec3 *a, s32 b, Vec3 *c);
u32 func_02096f54(CoverPooHole *p, Kart *a, u8 *b, u8 *c);
u32 func_0209702c(CoverPooHole *p, Kart *a, u8 *b, u8 *c);
/* sets flag 0x200 through the prefix type Unk02097520, whose mUnk_02 is MapObject.mFlags */
void InitCoverPooHole(Unk02097520 *p0);
u32 func_0209753c(u32 a);
