#pragma once

#include "types.h"

typedef struct MissionRecord MissionRecord;

// Two bytes: a flag and a value.
typedef struct Unk02056a2c {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
} Unk02056a2c;

// Two bytes and a halfword that GetKartFinishTime and GetKartLapTime fill.
typedef struct Unk02056750_c {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mUnk_02;
} Unk02056750_c;

void func_02056700(u32 a);
void func_02056750(s32 a, u16 b);
void func_020569a8(void *a);
s32 func_020569dc(s32 a, s32 b, Unk02056a2c *c);
void func_02056a04(s32 a, s32 b, Unk02056a2c *c);
void func_02056a2c(MissionRecord *a, Unk02056a2c *b);
void func_02056a4c(MissionRecord *a, Unk02056a2c *b);
