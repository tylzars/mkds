#pragma once

#include "types.h"
#include "Main/Unknown/code_020e0680.h"

// Object holding a pointer at 0x0 and two vectors.
typedef struct Unk020e04b0 {
    /* 00 */ Unk020e005c *mUnk_00;
    /* 04 */ Vec3 mUnk_04;
    /* 10 */ Vec3 mUnk_10;
} Unk020e04b0;

// Object holding a pointer at 0x0 and a vector at 0x4.
typedef struct Unk020e0448 {
    /* 00 */ Unk020e3ef4 *mUnk_00;
    /* 04 */ Vec3 mUnk_04;
} Unk020e0448;

void UpdateKoopaBlock(void *a0, Unk020e005c *koopaBlock);
void *CreateKoopaBlockUpdateList(void);
void *CreateKoopaBlockDrawList(void);
void *CreateKoopaBlockKindData(void);
s32 func_020e0448(Unk020e0448 *link);
BOOL func_020e04b0(Unk020e04b0 *link, Vec3 *outPosition, Vec3 *outVelocity);
void func_020e0538(Unk020e04b0 *link, Vec3 *outPosition);
void func_020e0584(Unk020e005c *object, Vec3 *position, Vec3 *velocity, Unk020e04b0 *link);
