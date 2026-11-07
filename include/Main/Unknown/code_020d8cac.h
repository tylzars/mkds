#pragma once

#include "types.h"

typedef struct Unk020e0144_00_0 Unk020e0144_00_0;
typedef struct Unk020e0144 Unk020e0144;

s32 func_020d8cac(Unk020e0144 *p);
void func_020d91dc(Unk020e0144_00_0 *segment, s32 fraction, Vec3 *result);
void func_020d9270(Unk020e0144_00_0 *segment, s32 fraction, s32 scale, Vec3 *firstResult, Vec3 *secondResult);
BOOL func_020d8cc8(Unk020e0144 *path);
void func_020d90a8(Unk020e0144 *path, u16 follower, s32 entryIndex);
