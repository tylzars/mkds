#pragma once

#include "types.h"
#include "00/code_0218f960.h"
#include "00/code_02194000.h"
#include "00/code_0218e8d4.h"
#include "00/code_0219c93c.h"
#include "00/unk_021b5000.h"
#include "00/code_0219cc00.h"
#include "00/code_0219d128.h"
#include "00/code_021988e8.h"
#include "00/code_0219b580.h"
#include "00/code_0219d000.h"
#include "00/code_0219e000.h"
#include "00/code_0219f000.h"
#include "00/code_021a0000.h"

// 8-byte local of func_ov000_021a01dc passed to func_ov000_0219db18.
typedef struct Unk021a01dc {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u16 mUnk_02;
    /* 04 */ u32 mUnk_04;
} Unk021a01dc;

s32 func_ov000_021a01dc(s32 a, u32 b, u32 c, u16 d, u32 *e, s32 f);
void func_ov000_021a1a38(s32 a, s32 b);
u64 func_ov000_021a350c(void);
