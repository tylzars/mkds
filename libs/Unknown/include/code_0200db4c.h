#pragma once

#include "types.h"

typedef struct Unk0200df9c Unk0200df9c;

#include "code_0200e77c.h"
#include "code_0200f7a0.h" // Unk0200fb08

// Linked through mUnk_68 from data_0216ff5c.mUnk_08 in increasing mUnk_70 (func_0200e52c); set up by func_0200e28c.
typedef struct Unk0200db5c {
    /* 00 */ u32 mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u32 mUnk_24;
    /* 28 */ u32 mUnk_28;
    /* 2c */ u32 mUnk_2c;
    /* 30 */ u32 mUnk_30;
    /* 34 */ u32 mUnk_34;
    /* 38 */ u32 mUnk_38;
    /* 3c */ void (*mUnk_3c)(void);
    /* 40 */ u32 mUnk_40;
    /* 44 */ u32 mUnk_44;
    /* 48 */ u8 mUnk_48[0x1c]; // its address goes to the functions called by func_0200e6ec and func_0200e738
    /* 64 */ u32 mUnk_64;
    /* 68 */ struct Unk0200db5c *mUnk_68;
    /* 6c */ u32 mUnk_6c;
    /* 70 */ u32 mUnk_70;
    /* 74 */ u32 mUnk_74;
    /* 78 */ Unk0200df9c *mUnk_78;
    /* 7c */ struct Unk0200db5c *mUnk_7c;
    /* 80 */ struct Unk0200db5c *mUnk_80;
    /* 84 */ Unk0200edc0 *mUnk_84; // set by func_0200ed34 around its call to func_0200e01c
    /* 88 */ Unk0200e594 mUnk_88;
    /* 90 */ u8 *mUnk_90;
    /* 94 */ u8 *mUnk_94;
    /* 98 */ u32 mUnk_98;
    /* 9c */ Unk0200df9c mUnk_9c;
    /* a4 */ u8 mUnk_a4[0xc];
    /* b0 */ Unk0200fb08 *mUnk_b0;
    /* b4 */ void (*mUnk_b4)(void *);
} Unk0200db5c;

// Object at data_0216ff5c; func_0200e388 stores the address of mUnk_04 in data_0216ff54.
typedef struct Unk0200dce0 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ Unk0200db5c *mUnk_04;
    /* 08 */ Unk0200db5c *mUnk_08;
    /* 0c */ void (*mUnk_0c)(Unk0200db5c *, Unk0200db5c *);
} Unk0200dce0;

void (*func_0200dbe8(void (*arg0)(Unk0200db5c *, Unk0200db5c *)))(Unk0200db5c *, Unk0200db5c *);

u32 func_0200db4c(void);
void func_0200db5c(Unk0200db5c *t, void (*f)(void *));
u32 func_0200db64(void);
u32 func_0200db9c(void);
void func_0200dbd4(void *a);
void func_0200dc1c(Unk0200db5c **arg0);
void func_0200dc3c(u32 n);
u32 func_0200dcd8(Unk0200db5c *t);
s32 func_0200dce0(Unk0200db5c *t, u32 v);
void func_0200dd94(void);
void func_0200de50(void);
Unk0200db5c *func_0200df3c(void);
void func_0200df68(Unk0200db5c *t);
void func_0200df9c(Unk0200df9c *q);
void func_0200e01c(Unk0200df9c *q);
s32 func_0200e070(Unk0200db5c *t);
void func_0200e084(Unk0200db5c *t);
void func_0200e0c0(Unk0200db5c *arg0);
void func_0200e0ec(Unk0200db5c *t);
void func_0200e160(void);
void func_0200e1ac(void *a);
void func_0200e1f0(Unk0200db5c *t, void *a);
void func_0200e260(void);
void func_0200e28c(Unk0200db5c *t, void (*f)(void *), void *a, u8 *p, u32 n, u32 v);
void func_0200e388(void);
void func_0200e4e4(Unk0200db5c *t);
void func_0200e52c(Unk0200db5c *t);
Unk0200edc0 *func_0200e594(Unk0200e594 *q);
Unk0200db5c *func_0200e5c4(Unk0200df9c *q);
void func_0200e5f8(Unk0200df9c *q, Unk0200db5c *t);
u32 func_0200e670(void);
