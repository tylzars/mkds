#pragma once

#include "types.h"

// First argument of FormatDate.
typedef struct DateBytes {
    /* 00 */ u8 mYear;
    /* 01 */ u8 mMonth;
    /* 02 */ u8 mDay;
} DateBytes;

// First argument of FormatMinuteSecondMillisecondTime.
typedef struct Unk02116b98 {
    /* 00 */ u16 mMillisecond;
    /* 02 */ u8 mMinute;
    /* 03 */ u8 mSecond;
} Unk02116b98;

typedef s16 Unk0215c5b4[2][7];

extern const Unk0215c5b4 gIndexChangeOffsets;

void FormatDate(DateBytes *date, u16 *text);
void FormatTwoDigitNumber(u32 number, u16 *text);
void func_02116b80(void *in, void *out);
void func_02116b8c(void *time, u16 *text);
void FormatMinuteSecondMillisecondTime(Unk02116b98 *time, u16 *text, s32 variant);
void func_02116cb0(u16 *text, s32 variant);
void func_02116ccc(u16 *text, s32 variant);
void func_02116ce8(s32 number, u16 *text, s32 variant);
s16 LookupIndexChangeOffset(s32 step, s32 row);
