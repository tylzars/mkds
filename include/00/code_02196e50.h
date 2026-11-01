#pragma once

#include "types.h"
#include "00/code_021a4654.h"
#include "00/code_02196960.h"
#include "00/code_021971ec.h"
#include "00/code_0218e368.h"
#include "00/code_0218d000.h"
#include "00/code_021a3668.h"
#include "00/code_021a3690.h"
#include "00/unk_021b3000.h"
#include "code_02134d30.h"
#include "code_02135014.h"

// Record appended to the list at data_ov000_021b4e5c by func_ov000_02197020.
typedef struct Unk02197020 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ UnkFunc *mUnk_18;
} Unk02197020;

// Declared here until the code that defines them is decompiled.
void func_ov000_02197634(void);

typedef struct Unk021b3c08 {
    /* 00 */ s8 mUnk_00[0x3f];
} Unk021b3c08;

typedef struct Unk021b3b68 {
    /* 00 */ s8 mUnk_00[0x10];
} Unk021b3b68;

extern const Unk021b3c08 data_ov000_021b3c08;
extern const Unk021b3b68 data_ov000_021b3b68;

void func_ov000_02196e50(s32 a, s32 b, s32 c, s32 d, const u8 *e, s32 f, UnkFunc *g, s32 h, s32 i);
void func_ov000_02196f8c(s8 *a, s32 b, s32 c, UnkFunc *d, s32 e);
void func_ov000_02197020(s32 a, s32 b, s32 c, s32 d, s32 e, UnkFunc *f, s32 g);
s32 func_ov000_02197064(const s8 *a, u32 b, u8 *c, Unk021a8f84 **d);
