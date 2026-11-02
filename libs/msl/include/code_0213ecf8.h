#pragma once

#include "types.h"

u16 *wcschr(const u16 *s, int c);
int wcsncmp(const u16 *a, const u16 *b, u32 n);
u16 *wcsncat(u16 *dst, const u16 *src, u32 n);
u16 *wcsncpy(u16 *dst, const u16 *src, u32 n);
u16 *wcscpy(u16 *dst, const u16 *src);
int wcslen(const u16 *s);
