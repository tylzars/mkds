#pragma once

#include "types.h"
#include "Main/Unknown/code_020ec1fc.h"

// Second argument of func_020ec538 and func_020ec6e4: vectors at 0x50, 0x5c and 0x80, words at 0xa4 and 0xac.
typedef struct Unk020ec6e4 {
    /* 000 */ u8 mUnk_000[0x50];
    /* 050 */ Vec3 mUnk_050;
    /* 05c */ Vec3 mUnk_05c;
    /* 068 */ u8 mUnk_068[0x18];
    /* 080 */ Vec3 mUnk_080;
    /* 08c */ u8 mUnk_08c[0x18];
    /* 0a4 */ s32 mUnk_0a4;
    /* 0a8 */ u8 mUnk_0a8[4];
    /* 0ac */ s32 mUnk_0ac;
} Unk020ec6e4;

extern const Vec3 data_0215957c;
extern const Vec3 data_02159588;
extern const Vec3 data_02159594;

void func_020ec538(Unk020e43a8 *object, const Unk020ec6e4 *other);
void func_020ec6e4(Unk020e43a8 *object, Unk020ec6e4 *other);
BOOL func_020ec7e8(Unk020e43a8 *object);
void func_020ec854(Unk020e43a8 *object, s32 lowestY, u32 gravity, u16 angleStep, u32 upwardSpeed, s32 pushSpeed);
