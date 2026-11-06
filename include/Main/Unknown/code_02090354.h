#pragma once

#include "types.h"
#include "Main/Unknown/code_02080b1c.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject

// Value at 0x00 (halfword), 0x02 and 0x03 (bytes) combined by func_020908d0.
typedef struct Unk020908d0 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
} Unk020908d0;

// Object of kind 0x19d (Sman: sman_top and sman_bottom models, DrawSmanTop and DrawSmanBottom): a MapObject at 0x00
// followed by words from 0xa0 to 0xc8. Its init sees it as the prefix type Unk0209188c (mFlags only).
typedef struct Sman {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ s32 mUnk_a4;
    /* a8 */ s32 mUnk_a8;
    /* ac */ s32 mUnk_ac;
    /* b0 */ s32 mUnk_b0;
    /* b4 */ s32 mUnk_b4;
    /* b8 */ s32 mUnk_b8;
    /* bc */ s32 mUnk_bc;
    /* c0 */ s32 mUnk_c0;
    /* c4 */ s32 mUnk_c4;
    /* State number of this kind's own per-frame switch in UpdateSman; this object does not use MapObject.mUnk_80's
       state machine; also written by the collision callbacks (1) */
    /* c8 */ s32 mState;
} Sman;

// Array of Sman pointers at 0x00, its count at 0x04.
typedef struct Unk0209151c {
    /* 00 */ Sman **mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk0209151c;

void func_02090354(void);
s32 func_020905a8(Unk020905a8 *a);
void func_02090638(Unk020905a8 *a);
void func_02090748(Unk020905a8 *a);
s32 func_0209081c(Unk020905a8 *a);
void func_02090838(Unk020905a8 *a, Unk02080b1c_00 *b);
void func_0209086c(Unk020905a8 *a, u32 b);
BOOL func_020908d0(u32 a, void *b);
void func_02090920(void *a);
BOOL func_02090940(void);
s32 func_020909cc(void);
u32 func_02090b24(void);
u32 func_02090cf8(void);
u32 func_02090ff4(void);
u32 func_0209119c(void);
u32 func_020911a8(void);
void *func_020911f4(void);
void *func_02091214(void);
void *func_02091238(void);
void func_0209125c(void);
void UpdateSman(void *a, Sman *b); /* skipped for objects with mFlags & 4 (parked pool objects) */
void func_0209151c(Unk0209151c *a);
void DrawSmanBottom(void *a, Sman *b);
void func_02091654(void *a);
void CreateSmanBottom(void *a);
void DrawSmanTop(void *a, Sman *b);
void func_02091784(void *a);
void CreateSmanTop(void *a);
