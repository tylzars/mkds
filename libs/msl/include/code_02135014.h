#pragma once

#include "types.h"

// 12 bytes. Filled by vsnprintf and read by FormatPutBuffer: output buffer, its length, and the count written.
typedef struct FormatPutTarget {
    /* 00 */ char *mBuffer;
    /* 04 */ u32 mSize;
    /* 08 */ u32 mWrittenCount;
} FormatPutTarget;

int sprintf(char *buf, const char *fmt, ...);
int snprintf(char *buf, u32 n, const char *fmt, ...);
int vsnprintf(char *buf, u32 n, const char *fmt, char *va);
int printf(const char *fmt, ...);
void *FormatPutBuffer(void *p, const char *b, u32 n);
void *FormatPutFwrite(void *a, const char *b, u32 n);
