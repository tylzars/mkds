#pragma once

#include "types.h"

// Two conversion functions called through data_0216eccc.mUnk_08: mUnk_00 has the shape of MbtowcSingleByte,
// mUnk_04 that of WctombSingleByte.
typedef struct Unk02134c94 {
    /* 00 */ int (*mUnk_00)(u16 *dst, const char *src, u32 n);
    /* 04 */ int (*mUnk_04)(char *dst, u16 c);
} Unk02134c94;

// wctomb and mbtowc read the pointer at 0x08.
typedef struct Unk0216eccc {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ Unk02134c94 *mUnk_08;
} Unk0216eccc;

extern Unk0216eccc data_0216eccc;

int wcstombs(char *dst, const u16 *src, u32 n);
int mbstowcs(u16 *dst, const char *src, u32 n);
int wctomb(char *dst, u16 c);
int WctombSingleByte(char *dst, u16 c);
int MbtowcSingleByte(u16 *dst, const char *src, u32 n);
int mbtowc(u16 *dst, const char *src, u32 n);
