#pragma once

#include "types.h"
#include "code_02022aa8.h"

// Four bytes read by func_020adc24 and written by func_0214d1fc.
typedef struct Unk020adc24 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
} Unk020adc24;

void func_020adb04(void);
BOOL func_020adb34(void);
s32 func_020adbc4(void);
s32 func_020adbe4(void);
s32 func_020adc04(void);
BOOL func_020adc24(Unk020adc24 *a, Unk020adc24 *b);
s16 func_020adc64(s32 a);
s32 func_020adc7c(const u16 *a, u16 *b);
void func_020adce0(u32 *a, Unk02022aa8 *b, u32 c);
