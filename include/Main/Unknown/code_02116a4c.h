#pragma once

#include "types.h"
#include "Main/Unknown/unk_021759c0.h" // MinuteSecondMillisecondTime

// First argument of FormatDate.
typedef struct DateBytes {
    /* 00 */ u8 mYear;
    /* 01 */ u8 mMonth;
    /* 02 */ u8 mDay;
} DateBytes;

typedef s16 IndexChangeOffsets[2][7];

extern const IndexChangeOffsets gIndexChangeOffsets;

void FormatDate(DateBytes *date, u16 *text);
void FormatTwoDigitNumber(u32 number, u16 *text);
void func_02116b80(void *time, void *text);
void FormatTimeAscii(void *time, u16 *text);
void FormatMinuteSecondMillisecondTime(MinuteSecondMillisecondTime *time, u16 *text, s32 variant);
void WriteZeroDigitByVariant(u16 *text, s32 variant);
void WriteColonByVariant(u16 *text, s32 variant);
void FormatNumberByVariant(s32 number, u16 *text, s32 variant);
s16 LookupIndexChangeOffset(s32 step, s32 row);
