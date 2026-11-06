#pragma once

#include "string.h"
#include "types.h"

// Output cursor of the formatter: room left, next write position, start of the output.
typedef struct dst_string {
    /* 00 */ size_t mLen;  // bytes still free; string_put_char stores only while this is nonzero
    /* 04 */ char *mCur; // next write position; moves on for every byte, stored or not
    /* 08 */ char *mBase; // start of the output (dst)
} dst_string;

int OS_VSNPrintf(char *dst, size_t len, const char *fmt, char *args);
int OS_SNPrintf(char *dst, size_t len, const char *fmt, ...);
int OS_VSPrintf(char *dst, const char *fmt, char *args);
int OS_SPrintf(char *dst, const char *fmt, ...);
void string_put_string(dst_string *str, const char *src, int len);
void string_fill_char(dst_string *str, char c, int len);
void string_put_char(dst_string *str, char c);
