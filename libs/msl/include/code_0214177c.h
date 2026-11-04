#pragma once

#include "types.h"
#include "code_0213ee6c.h" // DigitRecord

// Byte table indexed by bytes below 0x80; read by StrcmpMapped.
extern const u8 data_0215d184[];

void DigitsPowerOfTwo(DigitRecord *out, int n);
void DigitsFromString(DigitRecord *out, const char *s, int n);
void DigitsMultiply(DigitRecord *out, const DigitRecord *a, const DigitRecord *b);
void DigitsFromU64(DigitRecord *out, u64 v);
void DigitsRoundTo(DigitRecord *a, int n);
void DigitsIncrement(DigitRecord *a, int n);
int DigitsRoundCompare(const DigitRecord *a, int n);
int CountLowZeroBits(u32 a);
int func_02142368(const char *a, const char *b);
int StrcmpMapped(const char *a, const char *b);
