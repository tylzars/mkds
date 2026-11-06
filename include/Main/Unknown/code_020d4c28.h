#pragma once

#include "types.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020f36d8.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"

// Object func_020d4f94 reads: a vector at 0x24.
typedef struct Unk020d4f94 {
    /* 00 */ u8 mUnk_00[0x24];
    /* 24 */ Vec3 mUnk_24;
} Unk020d4f94;

void func_020d4f94(Unk020d4f94 *p);
u32 func_020d4f34(Vec3 *a, s32 b, s32 c, s32 d);
s32 func_020d4ef4(Vec3 *p);
void func_020d4e28(ItemObject *p, Vec3 *v, u32 a);
BOOL func_020d4ddc(MapObject *p);
BOOL func_020d4d60(MapObject *p, s32 a);
void func_020d4d44(MtxFx43 *p);
void DrawMapObjectList(MapObjectList *p, MtxFx43 *a);
