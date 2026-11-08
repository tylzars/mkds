#include "Main/Unknown/code_02116a4c.h"

#include "Main/Unknown/code_02124f4c.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_02016468.h"
#include "code_0214cfe4.h"

#pragma thumb on

const IndexChangeOffsets gIndexChangeOffsets = {
    0, -2, -4, -5, -4, -2, 0, 0, -1, -2, -2, -2, -1, 0,
};

s16 LookupIndexChangeOffset(s32 step, s32 row) {
    return gIndexChangeOffsets[row][step];
}

void FormatNumberByVariant(s32 number, u16 *text, s32 variant) {
    switch (variant) {
        case 0:
            FormatAsciiNumber(number, text);
            break;
        case 1:
            func_02124f4c(number, text);
            break;
    }
}

void WriteColonByVariant(u16 *text, s32 variant) {
    switch (variant) {
        case 0:
            *text = 0x3a;
            break;
        case 1:
            *text = 0xff1a;
            break;
    }
}

void WriteZeroDigitByVariant(u16 *text, s32 variant) {
    switch (variant) {
        case 0:
            *text = 0x30;
            break;
        case 1:
            *text = 0xff10;
            break;
    }
}

// Writes the time as minute, second and millisecond text; c picks which digit and separator characters.
void FormatMinuteSecondMillisecondTime(MinuteSecondMillisecondTime *time, u16 *text, s32 variant) {
    u16 length;
    u16 digitText[0x12];

    length = 0;
    FormatNumberByVariant(time->mMinute, text, variant);
    length++;
    if (time->mMinute >= 10) {
        length++;
    }
    WriteColonByVariant(text + length, variant);
    FormatNumberByVariant(time->mSecond, digitText, variant);
    if (time->mSecond >= 10) {
        MIi_CpuCopy16(digitText, text + (u16) (length + 1), 4);
        length += 3;
    } else {
        WriteZeroDigitByVariant(text + (u16) (length + 1), variant);
        MIi_CpuCopy16(digitText, text + (u16) (length + 2), 2);
        length += 3;
    }
    WriteColonByVariant(text + length, variant);
    FormatNumberByVariant(time->mMillisecond, digitText, variant);
    if (time->mMillisecond >= 100) {
        MIi_CpuCopy16(digitText, text + (u16) (length + 1), 6);
        length += 4;
    } else if (time->mMillisecond >= 10) {
        WriteZeroDigitByVariant(text + (u16) (length + 1), variant);
        MIi_CpuCopy16(digitText, text + (u16) (length + 2), 4);
        length += 4;
    } else {
        WriteZeroDigitByVariant(text + (u16) (length + 1), variant);
        WriteZeroDigitByVariant(text + (u16) (length + 2), variant);
        MIi_CpuCopy16(digitText, text + (u16) (length + 3), 2);
        length += 4;
    }
    text[length] = 0;
}

void FormatTimeAscii(void *time, u16 *text) {
    FormatMinuteSecondMillisecondTime(time, text, 0);
}

void func_02116b80(void *time, void *text) {
    FormatMinuteSecondMillisecondTime(time, text, 1);
}

void FormatTwoDigitNumber(u32 number, u16 *text) {
    if (number >= 10) {
        FormatAsciiNumber(number, text);
    } else {
        FormatAsciiNumber(0, text);
        FormatAsciiNumber(number, text + 1);
    }
}

// Writes the year, month and day as text in the order data_021759d0->mUnk_00 selects.
void FormatDate(DateBytes *date, u16 *text) {
    switch (data_021759d0->mUnk_00) {
        case 0:
            FormatTwoDigitNumber(0x14, text);
            FormatTwoDigitNumber(date->mYear, text + 2);
            text[4] = 0x2f;
            FormatTwoDigitNumber(date->mMonth, text + 5);
            text[7] = 0x2f;
            FormatTwoDigitNumber(date->mDay, text + 8);
            text[10] = 0;
            break;
        case 1:
            FormatTwoDigitNumber(date->mMonth, text);
            text[2] = 0x2f;
            FormatTwoDigitNumber(date->mDay, text + 3);
            text[5] = 0x2f;
            FormatTwoDigitNumber(0x14, text + 6);
            FormatTwoDigitNumber(date->mYear, text + 8);
            text[10] = 0;
            break;
        case 2:
            if (data_021759d0->mUnk_04 == 3) {
                FormatTwoDigitNumber(date->mDay, text);
                text[2] = 0x2e;
                FormatTwoDigitNumber(date->mMonth, text + 3);
                text[5] = 0x2e;
                FormatTwoDigitNumber(0x14, text + 6);
                FormatTwoDigitNumber(date->mYear, text + 8);
                text[10] = 0;
            } else {
                FormatTwoDigitNumber(date->mDay, text);
                text[2] = 0x2f;
                FormatTwoDigitNumber(date->mMonth, text + 3);
                text[5] = 0x2f;
                FormatTwoDigitNumber(0x14, text + 6);
                FormatTwoDigitNumber(date->mYear, text + 8);
                text[10] = 0;
            }
    }
}

#pragma thumb off
