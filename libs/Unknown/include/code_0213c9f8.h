#pragma once

#include "types.h"

// 12 bytes. Filled by vswprintf and read by func_0213ca94: output buffer, its length in u16 units, and the
// count written.
typedef struct Unk0213c9f8 {
    /* 00 */ u16 *mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
} Unk0213c9f8;

int vswprintf(u16 *buf, u32 n, const u16 *fmt, char *va);
int swprintf(u16 *buf, u32 n, const u16 *fmt, ...);
void *func_0213ca94(void *p, const u16 *s, u32 n);
