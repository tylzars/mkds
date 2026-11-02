#pragma once

#include "types.h"

// List node; the next node is at offset 0x28.
typedef struct Unk02007014 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ u8 mUnk_08[0x20];
    /* 28 */ struct Unk02007014 *mUnk_28;
    /* 2c */ u8 *mUnk_2c;
    /* 30 */ u16 mUnk_30;
    /* 32 */ u16 mUnk_32;
} Unk02007014;

#include "Main/Unknown/code_0200589c.h"

u32 func_02006954(s32 a, s32 b);
void func_02006974(void);
void func_02006a10(void (*a)(Unk0216f3dc_9c *));
void func_02006aac(s32 a, s32 b, void (*c)(Unk0216f3dc_9c *));
void func_02006b50(s32 a, s32 b);
void func_02006bec(const u8 *a, u32 b);
void func_02006c0c(u32 a, const u8 *b, int c);
s32 func_02006c2c(s32 a, s32 b);
u32 func_02006d3c(u16 a, const void *b, s32 c, void (*d)(void));
u32 func_02006d78(u16 a, u32 b, const void *c, u32 d, const void *e, void (*f)(Unk0216f3dc_9c *));
u32 func_02006db0(u16 a, u32 b, const void *c, void (*d)(Unk0216f3dc_9c *));
u32 func_02006ddc(u16 a, void (*b)(Unk0216f3dc_9c *));
Unk02007014 *func_02006df8(u32 a);
s32 func_02006e74(Unk02007014 *a, u32 b, const void *c, u8 *d, u32 e, u16 f);
int func_02006ef8(void);
u32 func_02006f14(s32 a, s32 b);
s32 func_02006f50(u32 a, s32 b, s32 *c, s32 *d);
u32 func_02006f98(s32 a);
s32 func_02006fdc(s32 a);
unsigned int func_02006ffc(void);
void func_02007008(unsigned int p0);
Unk02007014 *func_02007014(u32 a);
void func_02007034(unsigned int p0);
Unk02007014 *func_02007040(void);
u32 func_0200704c(const Unk0216f3dc_9c *a);
unsigned int func_020070b0(void);
Unk0216f3dc *func_020070b8(void);
void func_020070c0(unsigned int p0);
void func_020070cc(unsigned int p0);
unsigned int func_020070d8(void);
unsigned int func_020070e4(void);
