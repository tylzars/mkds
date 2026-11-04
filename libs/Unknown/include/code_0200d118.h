#pragma once

#include "types.h"

// Local of StringFormatArgsBounded (sp+0x54); its address is passed to StringFormatPutBytes, StringFormatPutRepeat and
// StringFormatPutChar.
typedef struct Unk0200d118 {
    /* 00 */ u32 mUnk_00;   // StringFormatPutChar stores a byte only while this is nonzero, and lowers it
    /* 04 */ char *mUnk_04; // where StringFormatPutChar stores; raised for every byte, stored or not
    /* 08 */ char *mUnk_08; // first argument of StringFormatArgsBounded
} Unk0200d118;

int StringFormatArgsBounded(char *buf, u32 n, const char *p, char *q);
int StringFormatBounded(char *buf, u32 n, const char *p, ...);
int StringFormatArgs(char *buf, const char *p, char *q);
int StringFormat(char *buf, const char *p, ...);
void StringFormatPutBytes(Unk0200d118 *s, const char *p, int n);
void StringFormatPutRepeat(Unk0200d118 *s, char c, int n);
void StringFormatPutChar(Unk0200d118 *s, char c);
