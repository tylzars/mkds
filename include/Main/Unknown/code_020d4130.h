#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020e6b58.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"

// Object func_020d4418 and DrawMapObjects read: a MtxFx43 at 0x30.
typedef struct Unk020d4418 {
    /* 00 */ u8 mUnk_00[0x30];
    /* 30 */ MtxFx43 mUnk_30;
} Unk020d4418;

void UpdateMapObjectViewTests(void);
void RefreshMapObjectViewTests(void);
void UpdateMapObjects(void);
void DrawMapObjects(Unk020d4418 *p);
void func_020d4418(Unk020d4418 *p);
s32 FindMapObjectsTouchingKart(Kart *a, Vec3 *b, Vec3 *c);
s32 FindMapObjectsOfKindInRadius(Vec3 *a, s32 b, s32 c);
