#pragma once

#include "types.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "00/code_0218dc44.h"
#include "00/code_02196000.h"
#include "00/unk_021b3000.h"
#include "code_02139f70.h"
#include "code_02135014.h"
#include "00/code_02196960.h"
#include "00/unk_021b4000.h"
#include "00/code_0218e368.h"
#include "00/code_0218e49c.h"
#include "code_0213a460.h"

typedef struct Unk021b3bdc {
    /* 00 */ s8 mUnk_00[0x2c];
} Unk021b3bdc;

// Declared here until the code that defines them is decompiled.

extern s32 data_ov000_021b3b2c;
extern u32 data_ov000_021b3b34;
extern u8 data_ov000_021b3b38[];
extern u8 data_ov000_021b3b40[];
extern const Unk021b3bdc data_ov000_021b3bdc;
extern const u8 data_ov000_021b3e0c[];
extern char data_ov000_021b4f84[];
extern u8 data_ov000_021b4e84[];
extern u32 data_ov000_021b4e4c;

void func_ov000_021971ec(s8 *a, s32 b);
s32 func_ov000_02197220(s8 *a, s32 b);
s32 func_ov000_021972b4(void);
s32 func_ov000_0219735c(const s8 *a, u32 b);
