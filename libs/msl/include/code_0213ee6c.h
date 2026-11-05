#pragma once

#include "types.h"

// 0x26 bytes. Filled by DoubleToDigitChars (which caps mDigitCount at 32) and DigitsFromString (at most 32 bytes);
// mDigitCount counts the bytes used in mDigits. Read by FormatRoundDigitChars, FormatWideRoundDigitChars and
// DigitCharsToDouble (DigitCharsToDouble copies it as a whole).
typedef struct DigitRecord {
    /* 00 */ u8 mNegative;
    /* 01 */ u8 mUnk_01;
    /* 02 */ s16 mExponent;
    /* 04 */ u8 mDigitCount;
    /* 05 */ char mDigits[32];
} DigitRecord;

// First argument of DoubleToDigitChars (reads mDigitCount).
typedef struct Unk02140c28 {
    /* 00 */ u8 mUnk_00;
    /* 02 */ s16 mDigitCount;
} Unk02140c28;

// Read as a float by DigitCharsToDouble.
extern float data_0216ec98;
// Read as a float by PowBody and nan.
extern float data_0216ec9c;

// Two doubles each, indexed 0/1 by PowBody.
extern const double data_0215d484[2];
extern const double data_0215d494[2];
extern const double data_0215d4a4[2];
// Indexed 0-7 by DigitCharsToDouble.
extern double data_0216ef30[];
// Passed by DigitCharsToDouble to DigitsFromString.
extern char data_0216ef70[];

double PowBody(double a, double b);
double copysign(double a, double b);
double fabs(double a);
double frexp(double a, int *e);
double ldexp(double a, int n);
double pow(double a, double b);
double DigitCharsToDouble(const DigitRecord *d);
void DoubleToDigitChars(Unk02140c28 *a, double v, DigitRecord *b);
void DoubleToDigits(DigitRecord *out, double a);
void DigitsSubtract(DigitRecord *out, const DigitRecord *a, const DigitRecord *b);
int DigitsLess(const DigitRecord *a, const DigitRecord *b);
int DigitsEqual(const DigitRecord *a, const DigitRecord *b);
