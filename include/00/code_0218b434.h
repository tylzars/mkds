#pragma once

#include "types.h"

unsigned int func_ov000_0218b570(unsigned int p0, unsigned int p1, unsigned int p2, unsigned int p3, unsigned int p4,
                                 unsigned int p5, unsigned int p6);

#include "00/unk_021b4000.h"
#include "00/code_0218a9bc.h"

// Object of 0x638 bytes func_ov000_0218b668 allocates. func_ov000_0218acb0 passes 0x20 to func_ov000_0218e53c and
// the addresses of 0x14 and 0x08 to func_ov000_0218ae5c.
typedef struct Unk0218b668 {
    /* 000 */ Unk0218a9bc mUnk_000;
    /* 04c */ SbServerList mUnk_04c;
    /* 620 */ u32 mUnk_620;
    /* 624 */ u32 mUnk_624;
    /* 628 */ u32 mUnk_628;
    /* 62c */ u16 mUnk_62c;
    /* 62e */ u8 mUnk_62e[2];
    /* 630 */ UnkFunc *mUnk_630;
    /* 634 */ u32 mUnk_634;
} Unk0218b668;

Unk0218b668 *func_ov000_0218b668(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, s32 g, UnkFunc *h, u32 l);

struct Unk0218b668;

// Declared here until the code that defines them is decompiled.

#include "00/code_0218aea4.h"
#include "00/code_0218acb0.h"

void func_ov000_0218b434(u32 arg0);
s32 func_ov000_0218b440(const char *const *first, const char *const *second);
u32 func_ov000_0218b44c(Unk0218afac *entry, u32 modulus);
u32 func_ov000_0218b458(Unk0218b668 *a);
void func_ov000_0218b464(Unk0218b668 *p0, unsigned int p1, void *p2, unsigned int p3);
u32 func_ov000_0218b474(u32 arg0);
u32 func_ov000_0218b480(u32 arg0, u32 arg1);
void func_ov000_0218b48c(struct Unk0218b668 *p);
void func_ov000_0218b4a4(struct Unk0218b668 *p);
s32 func_ov000_0218b4bc(struct Unk0218b668 *p);
void func_ov000_0218b4d4(struct Unk0218b668 *p, s32 a);
s32 func_ov000_0218b4f8(Unk0218b668 *a, u32 b, s32 c, u32 d);
s32 func_ov000_0218b530(Unk0218b668 *a, u32 b, s32 c, u8 *d, s32 e);
s32 func_ov000_0218b590(Unk0218b668 *a, s32 b, u32 c, u8 *d, s32 e, const char *f, u32 g, u32 h);
void func_ov000_0218b64c(Unk0218b668 *p);
