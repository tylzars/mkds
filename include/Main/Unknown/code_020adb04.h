#pragma once

#include "types.h"
#include "Main/Unknown/unk_021759c0.h" // MinuteSecondMillisecondTime

typedef struct Unk02022aa8 Unk02022aa8;

void InitTitleStateHandlers(void);
BOOL func_020adb34(void);
s32 func_020adbc4(void);
s32 func_020adbe4(void);
s32 func_020adc04(void);
BOOL func_020adc24(MinuteSecondMillisecondTime *a, MinuteSecondMillisecondTime *b);
s16 func_020adc64(s32 a);
s32 func_020adc7c(const u16 *a, u16 *b);
void func_020adce0(u32 *a, Unk02022aa8 *b, u32 c);
