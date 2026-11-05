#pragma once

#include "types.h"
#include "code_0200d118.h"
#include "code_0200f5ac.h"
#include "string.h"
#include "code_02134398.h"
#include "code_0213a460.h"
#include "code_0214d018.h"
#include "00/code_0218a000.h"
#include "00/code_0218b000.h"
#include "00/code_0218c000.h"
#include "00/code_021a3000.h"
#include "00/code_0218aea4.h"
#include "00/code_0219887c.h"
#include "00/code_0219a000.h"
#include "00/code_0219b580.h"
#include "00/code_0219c384.h"
#include "00/unk_021b5000.h"
#include "00/code_0219d000.h"
#include "00/code_0219de5c.h"
#include "00/code_0219e000.h"
#include "00/code_0219f000.h"
#include "00/code_0219f9bc.h"
#include "00/code_021a0000.h"
#include "00/code_021a1000.h"
#include "00/code_021a17bc.h"
#include "00/code_021a1ac0.h"
#include "00/code_021a4000.h"
#include "00/unk_021b4000.h"
#include "00/code_021a3a18.h"
#include "00/code_0218e2dc.h"

// Block built by func_ov000_021a1e40.
typedef struct Unk021a1e40 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u32 mUnk_04;
} Unk021a1e40;

void func_ov000_021a1ae0(u32 param_1, u32 param_2, const char *param_3);
void func_ov000_021a1b2c(Unk0219887c *param_1, s32 param_2);
void func_ov000_021a1ca8(u32 param_1, Unk0219887c *param_2, u32 param_3, u32 param_4, s32 param_5, char *param_6);
u32 func_ov000_021a1e40(u32 param_1, u32 param_2, u16 param_3, u8 *param_4, u32 param_5);
void UpdateMatching(s32 param_1);
void func_ov000_021a2468(const void *param_1, s32 param_2, s32 param_3, s32 param_4, void *param_5, u32 param_6,
                         u32 param_7, u32 param_8);
void func_ov000_021a260c(u32 param_1, const void *param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6);
u32 func_ov000_021a2768(u32 param_1);
void InitMatching(WiFiMatching *param_1, GpConnection *param_2, void **param_3, void *param_4, void *param_5,
                  void *param_6, void *param_7, u32 param_8);

#include "00/code_021a3760.h"
