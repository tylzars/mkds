#pragma once

#include "types.h"

typedef struct Unk02022aa8 Unk02022aa8;

// Four bytes read by func_020adc24 and written by MemCopy.
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
