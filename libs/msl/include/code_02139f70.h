#pragma once

#include "types.h"

u8 *strstr(const u8 *a, const u8 *b);
const u8 *strchr(const u8 *s, int c);
int strncmp(const u8 *a, const u8 *b, u32 n);
int strcmp(const u8 *a, const u8 *b);
char *strcat(char *dst, const u8 *src);
u8 *strncpy(u8 *dst, const u8 *src, u32 n);
char *strcpy(char *dst, const u8 *src);
u32 strlen(const u8 *s);
double atof(const u8 *s);
