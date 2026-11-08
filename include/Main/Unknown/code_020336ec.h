#pragma once

#include "types.h"

// Halfwords the first three functions index with a count minus one or two.
extern u16 data_usa_02153ea0[];
extern u16 data_usa_02153eb0[];
// 8-byte entries.
extern u8 data_usa_02153e98[];
extern u8 data_usa_02153ec0[];

void func_020336ec(void *heap);
void func_02033840(void *heap);
void func_020338f8(void *heap);
void func_02033a0c(void *heap);
void func_02033ab8(s32 cellFileSetIndex, s32 entryIndex, s32 cellIndex, s32 d);
void func_02033b80(s32 entryIndex);
void func_02033c80(s32 entryIndex);
