#pragma once

#include "types.h"

// 12 bytes. Filled by vsnprintf and read by func_02135258: output buffer, its length, and the count written.
typedef struct Unk02135078 {
    /* 00 */ u8 *mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
} Unk02135078;

int sprintf(u8 *buf, const u8 *fmt, ...);
int snprintf(char *buf, u32 n, const char *fmt, ...);
int vsnprintf(u8 *buf, u32 n, const u8 *fmt, char *va);
int printf(const u8 *fmt, ...);
void *func_02135258(void *p, const u8 *b, u32 n);
void *func_021352a8(void *a, const u8 *b, u32 n);
