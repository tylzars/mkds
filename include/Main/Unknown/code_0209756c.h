#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject, Unk020e6fd4
#include "code_0201c528.h" // Unk0201ca6c
#include "code_02012b30.h" // Unk02012f58

// Object of kind 0x1a9 (Flipper), up to 0xed4 bytes plus a table of words from 0xed4. mUnk_ebc is also written
// through Unk0209753c.
typedef struct Flipper {
    /* 000 */ MapObject mUnk_00;
    /* 0a0 */ s32 mUnk_a0;
    /* 0a4 */ s32 mUnk_a4;
    /* 0a8 */ Unk02012f58 mUnk_a8[30];
    /* 648 */ Unk02012f58 mUnk_648[30];
    /* be8 */ Vec3 mUnk_be8[30];
    /* d50 */ Vec3 mUnk_d50[30];
    /* eb8 */ s32 mUnk_eb8;
    /* ebc */ s32 mUnk_ebc;
    /* ec0 */ s32 mUnk_ec0;
    /* ec4 */ u16 mUnk_ec4;
    /* ec6 */ u16 mUnk_ec6;
    /* ec8 */ s32 mUnk_ec8;
    /* State number of this kind's own per-frame switch in UpdateFlipper; this object does not use
       MapObject.mUnk_80's state machine */
    /* ecc */ s32 mState;
    /* ed0 */ Unk0201ca6c *mUnk_ed0;
    /* ed4 */ s32 mUnk_ed4[1];
} Flipper;

void *func_0209756c(void);
void *func_0209758c(void);
void func_020975ac(void);
void UpdateFlipper(void *a, Flipper *p); /* skipped for objects with mFlags & 4 (parked pool objects) */
void func_020979c8(Unk020e6fd4 *a);
void DrawFlipper(void *a, Flipper *p);
void CreateFlipper(void *a);
u32 func_02097ed0(Flipper *p, Vec3 *a, s32 b, Vec3 *c);
u32 func_020980ec(Flipper *p, Kart *q, void *b, u8 *c);
void InitFlipper(Flipper *p); /* sets flag 0x200 and the ground matrix (func_020d2450) */
