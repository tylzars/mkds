#pragma once

#include "types.h"

// Read by ScanStringSourceOp: a pointer to the next byte, and a flag word.
typedef struct ScanStringSource {
    /* 00 */ const char *mNextChar;
    /* 04 */ int mAtEnd;
} ScanStringSource;

// Called through a pointer by ScanWithSourceFunc and ScanDouble: (their second argument, value, 0/1/2).
typedef int (*Unk02138618Func)(void *a, int b, int c);

// u16 per byte value 0x00-0x7f; FormatParseSpec tests bit 3. Also read by ScanParseSpec.
extern const u16 data_0215d284[];
// 0x80 entries, indexed by byte values 0x00-0x7f by ScanDouble.
extern const u8 data_0215d204[];
// Read by ScanDouble.
extern const double data_0216eca0;
// Used by three functions of this file, by PowBody (which stores 33 there) and by overlay 0.
extern int gLibErrorCode;

double strtod(const char *s, const char **end);
long StrtolBase10(const char *s);
long strtol(const char *s, const char **end, int base);
u32 strtoul(const char *s, const char **end, int base);
double ScanDouble(int a, Unk02138618Func f, void *p, int *q, int *r);
u64 ScanInt64(int a, int b, Unk02138618Func f, void *p, int *q, int *r, int *s);
u32 ScanInt32(int a, int b, Unk02138618Func f, ScanStringSource *p, int *q, int *r, int *s);
