#pragma once

#include "types.h"

typedef struct SbServer SbServer;
typedef struct Unk0218b668 Unk0218b668;
typedef struct SbServerList SbServerList;

// Object func_ov000_0218ba88 builds.
typedef struct Unk0218ba88 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ u8 mUnk_04;
    /* 05 */ u8 mUnk_05[4];
    /* 09 */ u8 mUnk_09[2];
    /* 0b */ u8 mUnk_0b[8];
} Unk0218ba88;

typedef struct SbServerList SbServerList;

void func_ov000_0218b708(void *a, s32 b, SbServer *c, Unk0218b668 *d);
void func_ov000_0218b780(SbServerList *a, s32 b, SbServer *c, Unk0218b668 *d);
s32 func_ov000_0218b8e4(SbServerList *a);
s32 func_ov000_0218b928(SbServerList *a);
s32 func_ov000_0218ba10(SbServerList *a, u32 b, u16 c, u32 d);
s32 func_ov000_0218ba88(SbServerList *a, u32 b, u16 c, u8 *d, s32 e);
s32 func_ov000_0218bb44(SbServerList *a);
s32 func_ov000_0218bc08(SbServerList *slist);
s32 func_ov000_0218bd5c(SbServerList *a, u8 *b, s32 c);
s32 func_ov000_0218be10(SbServerList *a, u8 *b, s32 c);
s32 func_ov000_0218be68(SbServerList *a, u8 *b, s32 c);
s32 func_ov000_0218bf78(SbServerList *a, u8 *b, s32 c);
s32 func_ov000_0218c0bc(SbServerList *a, u8 *b, s32 c);
s32 func_ov000_0218c15c(SbServerList *a);
void func_ov000_0218c45c(SbServerList *a, char *b);
s32 func_ov000_0218c468(SbServerList *a, u8 *b, s32 c);
s32 func_ov000_0218c550(SbServerList *a, void *b, u8 *c, s32 d, s32 e);
void func_ov000_0218c744(SbServerList *a, u8 *b, s32 c, u8 *d, u16 *e);
BOOL func_ov000_0218c794(SbServerList *a, u8 *b, s32 c);
BOOL func_ov000_0218c84c(u8 *a, s32 b);
s32 func_ov000_0218c8ac(u32 a);
void func_ov000_0218c8e0(SbServerList *a, s8 *b, s32 c);
