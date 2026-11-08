#pragma once

#include "types.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"

// Object of 0xb0 bytes: the MapObject it starts with, then four words.
typedef struct Unk02094e8c {
    /* 00 */ MapObject mUnk_00;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ BOOL mUnk_a4;
    /* a8 */ s32 mUnk_a8;
    /* ac */ s32 mUnk_ac;
} Unk02094e8c;

#include "Main/Unknown/code_020d22c0.h"

void func_02094e1c(void);
u32 func_02094e3c(void);
void func_02094e8c(void *a, Unk02094e8c *o);
s16 func_0209516c(s32 a);
s32 func_0209518c(s32 a, s32 b);
s16 func_0209519c(s32 a);
u16 func_020951b4(RandomState64 *randomState64);
RandomState64 *GetRaceLocalRandom(void);
void func_02095228(MapObjectList *mapObjectList);
void func_020952dc(Unk02094e8c *a, s32 teresaCountLimit, s32 spawnCount, s32 distanceLimit, s32 timerLimit);
void func_020954e4(u32 mapObject);
