#include "Main/Unknown/code_02116a4c.h"

#include "Main/Unknown/code_02124f4c.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_02016468.h"
#include "code_0214cfe4.h"

#pragma thumb on

const Unk0215c5b4 gIndexChangeOffsets = {
    0, -2, -4, -5, -4, -2, 0, 0, -1, -2, -2, -2, -1, 0,
};

s16 LookupIndexChangeOffset(s32 step, s32 row) {
    return gIndexChangeOffsets[row][step];
}

void func_02116ce8(s32 number, u16 *text, s32 variant) {
    switch (variant) {
        case 0:
            func_02124fac(number, text);
            break;
        case 1:
            func_02124f4c(number, text);
            break;
    }
}

void func_02116ccc(u16 *text, s32 variant) {
    switch (variant) {
        case 0:
            *text = 0x3a;
            break;
        case 1:
            *text = 0xff1a;
            break;
    }
}

void func_02116cb0(u16 *text, s32 variant) {
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
void FormatMinuteSecondMillisecondTime(Unk02116b98 *time, u16 *text, s32 variant) {
    u16 i;
    u16 buf[0x12];

    i = 0;
    func_02116ce8(time->mMinute, text, variant);
    i++;
    if (time->mMinute >= 10) {
        i++;
    }
    func_02116ccc(text + i, variant);
    func_02116ce8(time->mSecond, buf, variant);
    if (time->mSecond >= 10) {
        MIi_CpuCopy16(buf, text + (u16) (i + 1), 4);
        i += 3;
    } else {
        func_02116cb0(text + (u16) (i + 1), variant);
        MIi_CpuCopy16(buf, text + (u16) (i + 2), 2);
        i += 3;
    }
    func_02116ccc(text + i, variant);
    func_02116ce8(time->mMillisecond, buf, variant);
    if (time->mMillisecond >= 100) {
        MIi_CpuCopy16(buf, text + (u16) (i + 1), 6);
        i += 4;
    } else if (time->mMillisecond >= 10) {
        func_02116cb0(text + (u16) (i + 1), variant);
        MIi_CpuCopy16(buf, text + (u16) (i + 2), 4);
        i += 4;
    } else {
        func_02116cb0(text + (u16) (i + 1), variant);
        func_02116cb0(text + (u16) (i + 2), variant);
        MIi_CpuCopy16(buf, text + (u16) (i + 3), 2);
        i += 4;
    }
    text[i] = 0;
}

void func_02116b8c(void *time, u16 *text) {
    FormatMinuteSecondMillisecondTime(time, text, 0);
}

void func_02116b80(void *in, void *out) {
    FormatMinuteSecondMillisecondTime(in, out, 1);
}

void FormatTwoDigitNumber(u32 number, u16 *text) {
    if (number >= 10) {
        func_02124fac(number, text);
    } else {
        func_02124fac(0, text);
        func_02124fac(number, text + 1);
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
