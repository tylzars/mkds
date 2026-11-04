#pragma once

#include "types.h"

typedef struct Unk021b3bb8 {
    /* 00 */ s8 mUnk_00[0x24];
} Unk021b3bb8;

// 0x1d bytes written into the buffer of func_ov000_02197a9c when the two strings are too long.
typedef struct Unk021b3e44 {
    /* 00 */ s8 mUnk_00[0x1d];
} Unk021b3e44;

extern u32 data_ov000_021b3b34;
extern const Unk021b3bb8 data_ov000_021b3bb8;
extern const char data_ov000_021b3c48[];
extern const char data_ov000_021b3e14[];
extern const char data_ov000_021b3e34[];
extern const char data_ov000_021b3e40[];
extern const Unk021b3e44 data_ov000_021b3e44;
extern const char data_ov000_021b3e64[];
extern u32 data_ov000_021b4e48;
extern s32 data_ov000_021b4e54;
extern s8 *data_ov000_021b4e58;
extern s32 data_ov000_021b4e60;
extern u32 data_ov000_021b4e64;
extern s32 data_ov000_021b4e68;
extern s8 *data_ov000_021b4e6c;
extern s32 data_ov000_021b4e74;
extern s8 data_ov000_021b4e78[];

BOOL func_ov000_0218e80c(s32 a, s32 b);
void func_ov000_02196960(void);
void func_ov000_0219742c(void);
BOOL func_ov000_0219746c(void);
void func_ov000_02197558(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
void func_ov000_02197594(s32 a, s32 b, s32 c, UnkFunc *d, s32 e);
s8 *func_ov000_021975f4(s8 *a);
void func_ov000_02197634(void);
s32 func_ov000_02197690(s32 a);
s32 func_ov000_021976bc(void);
s32 func_ov000_02197924(s32 a, s32 b);
s8 *func_ov000_02197a9c(const char *a, const char *b, s8 *c);
