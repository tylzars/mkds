#pragma once

#include "types.h"

typedef struct Unk021b0138 {
    /* 00 */ u8 pad_00[0xc];
    /* 0c */ u8 mUnk_0c[8];
} Unk021b0138;

extern u32 data_ov000_021b6380;
extern u32 data_ov000_021b639c;
extern u32 data_ov000_021b63b4;

BOOL func_ov000_021b0014(const u16 *first, const u16 *second);
BOOL func_ov000_021b003c(u32 address);
BOOL func_ov000_021b0094(u32 address);
s32 func_ov000_021b00b0(u32 address);
u32 func_ov000_021b00e0(u32 address);
BOOL func_ov000_021b00fc(u32 address);
BOOL func_ov000_021b0138(const void *buffer, u32 length, const Unk021b0138 *header, u32 sum);
u16 func_ov000_021b0188(const void *buffer, u32 length);
u16 func_ov000_021b01a0(u16 sum);
u32 func_ov000_021b01b4(const void *buffer, u32 length, u32 sum);
