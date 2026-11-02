#pragma once

#include "types.h"

// Header of the file returned by FindCourseFile in CreateCourseMap: a word array at 0x08 holds offsets from 0x06's
// value.
typedef struct {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ s32 mUnk_08[1];
} Unk02042064;

extern s32 (*data_usa_0215407c[17])(void *a, ...);

#include "Main/Unknown/code_020b502c.h"

void CreateCourseMap(void *a);
s32 func_02042170(void *a, ...);
s32 func_02042280(void *a, ...);
void func_020422c4(void);
void func_02042320(void);
void func_0204236c(void);
Unk02175620_74 *func_020423fc(u32 a);
