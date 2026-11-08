#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h" // MapObject
#include "Main/Unknown/code_020e005c.h" // GroupFollower

// Entry of the list behind the word at 0x08 of Unk0209905c_d0: a link at 0x00 and two halfwords at 0x24 and 0x26.
typedef struct Unk0209905c_d0_08 {
    /* 00 */ struct Unk0209905c_d0_08 *mUnk_00;
    /* 04 */ u8 mUnk_04[0x20];
    /* 24 */ u16 mUnk_24;
    /* 26 */ u16 mUnk_26;
} Unk0209905c_d0_08;

// Object behind the word at 0xd0 of Unk0209905c: a list at 0x08 and a flags word at 0x24.
typedef struct Unk0209905c_d0 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ Unk0209905c_d0_08 *mUnk_08;
    /* 0c */ u8 mUnk_0c[0x18];
    /* 24 */ u32 mUnk_24;
} Unk0209905c_d0;

// Object up to 0xd4 bytes: the shared part, an GroupFollower at 0xa0, then three words and a pointer.
typedef struct Unk0209905c {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ GroupFollower mFollower;
    /* c4 */ s32 mHeightOffset;
    /* c8 */ s32 mUnk_c8;
    /* cc */ s32 mState;
    /* d0 */ Unk0209905c_d0 *mEmitter;
} Unk0209905c;

#include "Main/Unknown/code_0206bcb0.h" // Kart

extern u16 data_usa_02156590;
extern u32 data_usa_02156594;

void func_02099020(void);
void func_0209905c(void *a, Unk0209905c *p);
u32 func_02099208(Unk0209905c *a, Kart *kart, u8 *c, u8 *d);
void func_02099278(unsigned int mapObject);
