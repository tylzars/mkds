#pragma once

#include "types.h"

typedef struct Unk02001d30 Unk02001d30;

// Object whose halfword at 0x04 func_02001a74 clears.
typedef struct Unk02001a74 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mUnk_04;
} Unk02001a74;

extern const char data_usa_ov001_021a768c[];
extern const char data_usa_ov001_021a76a8[];
extern const char data_usa_ov001_021a76c4[];
extern const char data_usa_ov001_021a76dc[];
extern const char data_usa_ov001_021a76f4[];
extern const char data_usa_ov001_021a770c[];
extern const char data_usa_ov001_021a7720[];

void func_020019b0(void);
void func_02001a44(void);
void func_02001a74(Unk02001a74 *a);
void func_02001abc(void);
void func_02001b38(void);
void func_02001ba0(void *a);
void func_02001d30(Unk02001d30 *a, s32 b, const char *c, const char *d, const char *e);
