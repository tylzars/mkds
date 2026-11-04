#pragma once

#include "types.h"

void srand(u32 arg0);

// 0x28 bytes. Filled by ScanParseSpec from the text at its first argument, starting from a local copy with every
// byte zero and mUnk_04 = 0x7fffffff; ScanWithSourceFunc reads mUnk_08 one bit per byte value.
typedef struct ScanSpec {
    /* 00 */ u8 mStar;
    /* 01 */ u8 mHasMaxLength;
    /* 02 */ u8 mArgKind;
    /* 03 */ u8 mSpecChar;
    /* 04 */ s32 mMaxLength;
    /* 08 */ u8 mCharSet[32];
} ScanSpec;

u32 rand(void);
int sscanf(const char *a, const char *b, ...);
int vsscanf(const char *a, const char *b, char *c);

#include "code_0213a460.h"

int ScanStringSourceOp(void *a, int b, int c);
int ScanWithSourceFunc(Unk02138618Func f, void *a, const char *s, char *b);
const char *ScanParseSpec(const char *a, ScanSpec *b);
