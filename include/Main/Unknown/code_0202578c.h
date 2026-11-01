#pragma once

#include "types.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/unk_02174000.h"

// 12-byte entries of the table at data_usa_02153918.
typedef struct Unk02153918 {
    /* 00 */ s16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ s16 mUnk_06;
    /* 08 */ s32 mUnk_08;
} Unk02153918;

u32 func_0202578c(u32 a);
void func_02025854(u32 a, void *b, const char *c, const char *d, const char *e, s32 f, void *(*g)(const char *) );
void func_02025884(void *a, const char *b, const char *c, const char *d, s32 e, void *(*f)(const char *) );
void func_020258d4(u32 a, void *b, const char *c, const char *d, const char *e, s32 f, void *(*g)(const char *) );
void func_02025904(void *a, const char *b, const char *c, const char *d, s32 e, void *(*f)(const char *) );
void func_02025954(u32 a, void *b, u32 c);
s32 func_02025a00(u32 a, void *b, void *c, void *d, s32 e);
void func_02025a50(u32 a, void *b, void *c);
void func_02025abc(void *a, const char *b, const char *c, const char *d, const char *e, const char *f, const char *g,
                   void *(*h)(const char *) );
void func_02025b20(void *a, const char *b, const char *c, const char *d, const char *e, const char *f, const char *g,
                   void *(*h)(const char *) );
