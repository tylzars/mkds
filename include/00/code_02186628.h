#pragma once

#include "types.h"

// Declared here until the code that defines them is decompiled.

typedef struct Unk021868a4Entry {
    /* 00 */ void *mFirst;
    /* 04 */ void *mSecond;
} Unk021868a4Entry;

typedef struct Unk021868a4 {
    /* 00 */ Unk021868a4Entry *mEntries;
    /* 04 */ s32 mCapacity;
    /* 08 */ s32 mCount;
} Unk021868a4;

#include "code_0200e0ec.h" // Unk0200db5c

// Growing buffer: mUnk_00 is its start, mUnk_04 the write position, mUnk_08 the end and mUnk_0c the size.
typedef struct Unk02186998 {
    /* 00 */ char *mUnk_00;
    /* 04 */ char *mUnk_04;
    /* 08 */ char *mUnk_08;
    /* 0c */ s32 mUnk_0c;
} Unk02186998;

// 0x1a60 bytes; mUnk_014 and mUnk_018 allocate and release the memory of its buffers.
typedef struct Unk021868d0 {
    /* 000 */ u8 mUnk_000[8];
    /* 008 */ s32 mUnk_008;
    /* 00c */ s32 mUnk_00c;
    /* 010 */ u8 mUnk_010[4];
    /* 014 */ void *(*mUnk_014)(const void *, s32);
    /* 018 */ void (*mUnk_018)(const void *, void *, s32);
    /* 01c */ u8 mUnk_01c[8];
    /* 024 */ s32 mUnk_024;
    /* 028 */ u8 mUnk_028[0x80];
    /* 0a8 */ u8 *mUnk_0a8;
    /* 0ac */ u8 *mUnk_0ac;
    /* 0b0 */ s32 mUnk_0b0;
    /* 0b4 */ u8 mUnk_0b4[0x868];
    /* 91c */ void *mUnk_91c;
    /* 920 */ void *mUnk_920;
    /* 924 */ s32 mUnk_924;
    /* 928 */ Unk02186998 mUnk_928;
    /* 938 */ Unk02186998 mUnk_938;
    /* 948 */ u8 mUnk_948[0x20];
    /* 968 */ Unk0200db5c mUnk_968;
    /* a20 */ u8 mUnk_a20[0x1040];
} Unk021868d0;

void func_ov000_02186628(const void *a);
s32 func_ov000_02186634(Unk021868a4Entry *a, s32 b, const u8 *c, char *d, s32 e);
s32 func_ov000_02186674(Unk021868a4Entry *a, s32 b, const u8 *c, char *d, s32 e);
void *func_ov000_021866b8(Unk021868a4Entry *a, s32 b, const u8 *c);
s32 func_ov000_021866fc(Unk021868a4Entry *a, s32 b, s32 c, const u8 *d);
s32 func_ov000_021868a4(Unk021868a4 *list, void *first, void *second);
s32 func_ov000_021868d0(Unk021868d0 *a, const u8 *b);
u32 func_ov000_02186998(Unk021868d0 *a, Unk02186998 *b, int c);
void func_ov000_02186a10(Unk021868d0 *a, Unk02186998 *b);
u32 func_ov000_02186a38(Unk021868d0 *a, Unk02186998 *b, int c);
u32 func_ov000_02186a84(u32 value);
