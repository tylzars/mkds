#pragma once

#include "types.h"

typedef struct DigitRecord DigitRecord;

// 16 bytes. Filled by FormatWideParseSpec from the text after a '%', read by FormatWideWithPutFunc and passed by value
// (one word in r3, three on the stack) to FormatWideDouble, FormatWideInt64 and FormatWideInt32. Byte 0x05 is never
// accessed.
typedef struct FormatWideSpec {
    /* 00 */ u8 mPadKind;
    /* 01 */ u8 mSignKind;
    /* 02 */ u8 mHasDot;
    /* 03 */ u8 mHash;
    /* 04 */ u8 mArgKind;
    /* 06 */ u16 mSpecChar;
    /* 08 */ s32 mMinLength;
    /* 0c */ s32 mUnk_0c;
} FormatWideSpec;

// u16 table indexed by characters below 0x80; FormatWideParseSpec tests bit 3, FormatWideDouble bit 9.
extern const u16 data_0215d384[];

int FormatWideWithPutFunc(void *(*a)(void *, const u16 *, u32), void *b, const u16 *c, char *d);
u16 *FormatWideDouble(double v, u16 *end, FormatWideSpec s);
void FormatWideRoundDigitChars(DigitRecord *a, int k);
u16 *FormatWideInt64(u64 v, u16 *end, FormatWideSpec s);
u16 *FormatWideInt32(unsigned long v, u16 *end, FormatWideSpec s);
const u16 *FormatWideParseSpec(const u16 *a, char **b, FormatWideSpec *c);
