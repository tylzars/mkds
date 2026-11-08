#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_020e005c.h"
#include "Main/Unknown/code_020e516c.h"

// Object of kinds 0x1b0 and 0x1b3 (IronBall; kind 0x1b3 has only Init and Draw, no update or collision group), 0x134
// bytes: the shared MapObject part, a GroupFollower at 0xc4 and a ShadowMatrix at 0xe8.
typedef struct IronBall {
    /* 000 */ MapObject mUnk_000;
    /* 0a0 */ s32 mUnk_0a0;
    /* 0a4 */ s32 mUnk_0a4;
    /* 0a8 */ s32 mUnk_0a8;
    /* 0ac */ s32 mUnk_0ac;
    /* 0b0 */ s32 mUnk_0b0;
    /* 0b4 */ s32 mUnk_0b4;
    /* 0b8 */ s32 mUnk_0b8;
    /* 0bc */ s32 mUnk_0bc;
    /* 0c0 */ s32 mUnk_0c0;
    /* 0c4 */ GroupFollower mUnk_0c4;
    /* 0e8 */ ShadowMatrix mUnk_0e8;
    /* 11c */ Vec3 mUnk_11c;
    /* 128 */ s32 mUnk_128;
    /* 12c */ s32 mUnk_12c;
    /* 130 */ s32 mUnk_130;
} IronBall;

// Array of object pointers: pointer to the array and the number of entries (InitIronBallObjects).
typedef struct Unk020a9a5c {
    /* 00 */ IronBall **mUnk_00;
    /* 04 */ u16 mUnk_04;
} Unk020a9a5c;

// Object returned by CreateMapObjectKindData, with words at 0x38, 0x3c and 0xc0 (func_020a9224, func_020a9de4).
typedef struct Unk020a9224 {
    /* 00 */ u8 mUnk_00[0x38];
    /* 38 */ s32 mUnk_38;
    /* 3c */ s32 mUnk_3c;
    /* 40 */ u8 mUnk_40[0x80];
    /* c0 */ s32 mUnk_c0;
} Unk020a9224;

#include "Main/Unknown/code_020a826c.h" // Unk020a826c_a0

void func_020a8ed8(Unk020a826c_a0 *a, Vec3 *b);
void *func_020a91c0(void);
void *func_020a91e0(void);
void *func_020a9204(void);
void func_020a9224(void);
void UpdateIronBall(void *a, IronBall *p); /* kind 0x1b0 only */
void InitIronBallObjects(Unk020a9a5c *p);
void func_020a9c54(void *a, IronBall *p, u32 c, u32 d);
unsigned int func_020a9cd0(unsigned int p0);
