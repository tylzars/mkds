#pragma once

#include "types.h"
#include "code_0213ee6c.h" // DigitRecord

// 16 bytes. Filled by FormatParseSpec; FormatWithPutFunc passes it by value (moved as four words) to
// FormatDouble, FormatDoubleHex, FormatInt64 and FormatInt32.
typedef struct FormatSpec {
    /* 00 */ u8 mPadKind;
    /* 01 */ u8 mSignKind;
    /* 02 */ u8 mHasDot;
    /* 03 */ u8 mHash;
    /* 04 */ u8 mArgKind;
    /* 05 */ u8 mSpecChar;
    /* 08 */ s32 mMinLength;
    /* 0c */ s32 mUnk_0c;
} FormatSpec;

// Strings passed to strcpy by FormatDouble and FormatDoubleHex.
extern char gFormatMinusInfUpper[];
extern char gFormatMinusInfLower[];
extern char gFormatInfUpper[];
extern char gFormatInfLower[];
extern char gFormatMinusNanUpper[];
extern char gFormatMinusNanLower[];
extern char gFormatNanUpper[];
extern char gFormatNanLower[];
// String passed to strcpy by FormatDoubleHex.
extern char gFormatHexZero[];

int FormatWithPutFunc(void *(*f)(void *, const char *, u32), void *a, const char *b, char *c);
char *FormatDouble(double v, char *end, FormatSpec spec);
void FormatRoundDigitChars(DigitRecord *a, int k);
char *FormatDoubleHex(double v, char *end, FormatSpec spec);
char *FormatInt64(u64 v, char *end, FormatSpec spec);
char *FormatInt32(unsigned long v, char *end, FormatSpec spec);
const char *FormatParseSpec(const char *p, char **b, FormatSpec *buf);
