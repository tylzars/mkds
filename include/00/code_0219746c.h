#pragma once

#include "types.h"
#include "00/code_021a4654.h"
#include "00/code_021971ec.h"
#include "00/code_0218e368.h"
#include "00/code_0218d000.h"
#include "00/code_021a3668.h"
#include "00/code_021a3690.h"
#include "00/unk_021b3000.h"
#include "code_02134d30.h"
#include "code_02135014.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "00/code_0218dc44.h"
#include "00/code_02196000.h"
#include "code_02139f70.h"
#include "00/code_02196960.h"
#include "03/code_021b94b8.h"
#include "00/code_0218e49c.h"
#include "00/code_0219742c.h"
#include "00/code_021a3678.h"
#include "00/unk_021b4000.h"

typedef struct Unk021b3bb8 {
    /* 00 */ s8 mUnk_00[0x24];
} Unk021b3bb8;

extern const Unk021b3bb8 data_ov000_021b3bb8;

// 0x1d bytes written into the buffer of func_ov000_02197a9c when the two strings are too long.
typedef struct Unk021b3e44 {
    /* 00 */ s8 mUnk_00[0x1d];
} Unk021b3e44;

// Declared here until the code that defines them is decompiled.
void func_ov000_02196960(void);
BOOL func_ov000_0218e80c(s32 a, s32 b);

extern s32 data_ov000_021b4e60;
extern s8 *data_ov000_021b4e58;
extern s32 data_ov000_021b4e54;
extern s32 data_ov000_021b4e74;
extern s32 data_ov000_021b4e68;
extern u32 data_ov000_021b4e48;
extern u32 data_ov000_021b4e64;
extern s8 *data_ov000_021b4e6c;
extern s8 data_ov000_021b4e78[];
extern const Unk021b3e44 data_ov000_021b3e44;
extern const u8 data_ov000_021b3e64[];
extern const u8 data_ov000_021b3e14[];
extern const u8 data_ov000_021b3e34[];
extern const u8 data_ov000_021b3e40[];
extern const u8 data_ov000_021b3c48[];
extern u32 data_ov000_021b3b34;

BOOL func_ov000_0219746c(void);
void func_ov000_02197558(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
void func_ov000_02197594(s32 a, s32 b, s32 c, UnkFunc *d, s32 e);
s8 *func_ov000_021975f4(s8 *a);
void func_ov000_02197634(void);
s32 func_ov000_02197690(s32 a);
s32 func_ov000_021976bc(void);
s32 func_ov000_02197924(s32 a, s32 b);
s8 *func_ov000_02197a9c(const u8 *a, const u8 *b, s8 *c);
