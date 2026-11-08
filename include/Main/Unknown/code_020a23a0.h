#pragma once

#include "types.h"

typedef struct Kart Kart;

s32 func_020a23a0(Kart *kart);
void DrawTrophy(void);
void AdvanceTrophy(void);
s32 func_020a2668(s32 a, s32 b);
s16 func_020a2684(s32 angle);
void InitTrophy(s32 modelIndex, u32 rankIndex);
void func_020a29cc(void);
