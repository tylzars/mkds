#pragma once

#include "types.h"

char *strstr(const char *a, const char *b);
char *strchr(const char *s, int c);
int strncmp(const char *a, const char *b, u32 n);
int strcmp(const char *a, const char *b);
char *strcat(char *dst, const char *src);
char *strncpy(char *dst, const char *src, u32 n);
char *strcpy(char *dst, const char *src);
u32 strlen(const char *s);
double atof(const char *s);
