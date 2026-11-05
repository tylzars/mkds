#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"

// 0x20-byte part of Teresa at 0xbc and 0xdc, written by func_02094000.
typedef struct Unk02094000_bc {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
} Unk02094000_bc;

// Object of kind 0x13b (Teresa), returned by func_0209bbfc for func_02100138(0x13b), filled by func_02094000. The
// pool objects are made by another kind's init (func_020954e4 in code_02094e1c.c); Unk02094db4 is a view of the
// draw group record, not of this object.
typedef struct Teresa {
    /* 000 */ MapObject mUnk_00;
    /* 0a0 */ Vec3 mUnk_a0;
    /* 0ac */ u16 mUnk_ac;
    /* 0ae */ u16 mUnk_ae;
    /* 0b0 */ u16 mUnk_b0;
    /* 0b2 */ u8 mUnk_b2[2];
    /* 0b4 */ s32 mUnk_b4;
    /* 0b8 */ s32 mUnk_b8;
    /* 0bc */ Unk02094000_bc mUnk_bc;
    /* 0dc */ Unk02094000_bc mUnk_dc;
    /* 0fc */ s32 mUnk_fc;
    /* 100 */ s32 mUnk_100;
    /* 104 */ s32 mUnk_104;
    /* 108 */ s32 mUnk_108;
    /* 10c */ s32 mUnk_10c;
    /* State number of this kind's own per-frame switch in UpdateTeresa; this object does not use
       MapObject.mUnk_80's state machine */
    /* 110 */ s32 mState;
} Teresa;

// Table of the objects of func_02100138(0x13b) and their number.
typedef struct Unk020946b8 {
    /* 00 */ Teresa **mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk020946b8;

// Object of CreateTeresa: the word at 0x1c is set.
typedef struct Unk02094db4 {
    /* 00 */ u8 mUnk_00[0x1c];
    /* 1c */ s32 mUnk_1c;
} Unk02094db4;

s32 func_02093ff0(void);
void func_02094000(Vec3 *a);
void func_020946b8(void);
void func_02094724(void);
void func_02094744(void);
void UpdateTeresa(void *a, Teresa *o); /* skipped for objects with mFlags & 4 (parked pool objects) */
s16 func_02094bd0(s32 a);
s32 func_02094bf0(s32 a, s32 b);
s16 func_02094c0c(s32 a);
void func_02094c24(Unk020946b8 *a);
void DrawTeresa(void *a, Teresa *b);
void func_02094d9c(void *a);
void CreateTeresa(Unk02094db4 *a); /* also sets word +0x1c of the group record to 1 */
u32 InitTeresa(u32 arg0); /* parks the pooled object (func_020d2398) and zeroes the live-Teresa count data_0217b0d8 */
