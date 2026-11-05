#pragma once

#include "types.h"
#include "00/code_02190000.h"
#include "code_02139f70.h"
#include "00/code_021906e4.h"
#include "00/code_021947e4.h"
#include "00/unk_021b2000.h"
#include "00/unk_021b3000.h"
#include "00/unk_021b4000.h"
#include "string.h"
#include "code_02134398.h"
#include "00/code_02196594.h"
#include "00/code_021965a0.h"
#include "00/code_021a3690.h"
#include "00/code_02196590.h"
#include "code_0213a460.h"
#include "00/code_021948f8.h"
#include "00/code_0218e0fc.h"
#include "00/code_02191200.h"
#include "00/code_02196480.h"
#include "00/code_02192d64.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/code_0218d818.h"
#include "00/code_02196000.h"
#include "00/code_0218f960.h"
#include "00/code_0218e2dc.h"
#include "00/code_021a3a18.h"
#include "00/code_0219488c.h"

// Object of 0x308 bytes that GpiStartConnect allocates and fills.
typedef struct Unk021919ac_q {
    /* 000 */ char mUnk_000[0x80];
    /* 080 */ char mUnk_080[0x21];
    /* 0a1 */ char mUnk_0a1[0x21];
    /* 0c2 */ s8 mUnk_0c2[0x100];
    /* 1c2 */ s8 mUnk_1c2[0x100];
    /* 2c2 */ char mUnk_2c2[0x41];
    /* 303 */ u8 mUnk_303;
    /* 304 */ s32 mUnk_304;
} Unk021919ac_q;

// Object of 0xf0 bytes that func_ov000_0219218c copies.
typedef struct Unk021919ac_f0 {
    /* 00 */ void *mUnk_00[6];
    /* 18 */ u8 mUnk_18[0xb0];
    /* c8 */ void *mUnk_c8;
    /* cc */ u8 mUnk_cc[0x24];
} Unk021919ac_f0;

// Object that GpiCreateOperation returns through its fourth argument.
typedef struct Unk021919ac_node {
    /* 00 */ u32 mType;
    /* 04 */ u32 mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ Unk021919ac_f0 *mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mId;
    /* 1c */ u32 mUnk_1c;
} Unk021919ac_node;

// Object of 0x204 bytes that func_ov000_0219222c allocates.
typedef struct Unk021919ac_m {
    /* 000 */ u32 mUnk_000;
    /* 004 */ u32 mUnk_004;
    /* 008 */ u8 mUnk_008[0x1fc];
} Unk021919ac_m;

// Two words that func_ov000_0219488c returns through its last argument.
typedef struct Unk021919ac_h {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
} Unk021919ac_h;

// Address of 8 bytes that GpiOpenSockets passes on.
typedef union Unk021919ac_sa {
    struct {
        /* 00 */ u8 mUnk_00;
        /* 01 */ u8 mUnk_01;
        /* 02 */ u16 mUnk_02;
        /* 04 */ u32 mUnk_04;
    } f;
    u32 w[2];
} Unk021919ac_sa;

// Declared here until the code that defines them is decompiled.

void func_ov000_021920d8(s8 *p, s32 n);
u32 GpiWriteLogin(GpConnection *p, Unk021919ac_q *q);
u32 GpiStartConnect(GpConnection *p, const char *a, const char *b, const char *c, const char *d, const s8 *e,
                    const s8 *f, const char *g, s32 h, s32 i, s32 j, s32 k, s32 l);
u32 GpiOpenSockets(GpConnection *p, Unk021919ac_node *n);
