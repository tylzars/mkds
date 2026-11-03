#pragma once

#include "types.h"

// Read by func_021385a0: a pointer to the next byte, and a flag word.
typedef struct Unk0213a460 {
    /* 00 */ const char *mUnk_00;
    /* 04 */ int mUnk_04;
} Unk0213a460;

// Called through a pointer by func_02138618 and func_0213a550: (their second argument, value, 0/1/2).
typedef int (*Unk02138618Func)(void *a, int b, int c);

// u16 per byte value 0x00-0x7f; func_0213770c tests bit 3. Also read by func_02139400.
extern const u16 data_0215d284[];
// 0x80 entries, indexed by byte values 0x00-0x7f by func_0213a550.
extern const u8 data_0215d204[];
// Read by func_0213a550.
extern const double data_0216eca0;
// Used by three functions of this file, by func_0213ee6c (which stores 33 there) and by overlay 0.
extern int data_0217ee90;

double strtod(const char *s, const char **end);
long func_0213bf90(const char *s);
long strtol(const char *s, const char **end, int base);
u32 strtoul(const char *s, const char **end, int base);
double func_0213a550(int a, Unk02138618Func f, void *p, int *q, int *r);
u64 func_0213c110(int a, int b, Unk02138618Func f, void *p, int *q, int *r, int *s);
u32 func_0213c560(int a, int b, Unk02138618Func f, void *p, int *q, int *r, int *s);
