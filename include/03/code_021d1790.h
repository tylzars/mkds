#pragma once

#include "types.h"

typedef struct OamRange OamRange;

void func_ov003_021d1790(OamRange *range, s32 index, u32 param_3);
void SetOamRangePosition(OamRange *range, s32 index, u32 xPos, u32 yPos);
void func_ov003_021d1890(OamRange *range, s32 index, u32 param_3, u32 param_4);
void SetOamRangeEffect(OamRange *range, s32 index, u32 effect, u32 affineIndex);
