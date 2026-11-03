#pragma once

#include "types.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_02117224.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_02127000.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_0211de40.h"
#include "Main/Unknown/code_0211df44.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0201ea58.h"
#include "code_0212df7c.h"

// Object with a pointer at offset 0xc.
typedef struct Unk021a9bf4Block {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ u8 *mUnk_0c;
} Unk021a9bf4Block;

// Object behind data_ov001_021a9bf4.
typedef struct Unk021a9bf4 {
    /* 00 */ struct Unk02021dc8 *mUnk_00;
    /* 04 */ Unk0201ea30 *mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ struct Unk02021dc8 *mUnk_0c;
    /* 10 */ Unk0201ea30 *mUnk_10;
    /* 14 */ void *mUnk_14;
    /* 18 */ void *mUnk_18;
    /* 1c */ Unk020b4a44 *mUnk_1c;
    /* 20 */ void *mUnk_20;
    /* 24 */ void *mUnk_24;
    /* 28 */ Unk021a9bf4Block *mUnk_28;
    /* 2c */ void *mUnk_2c;
    /* 30 */ Unk02124b1c *mUnk_30;
    /* 34 */ Unk02124b1c *mUnk_34;
    /* 38 */ void *mUnk_38;
    /* 3c */ void *mUnk_3c;
    /* 40 */ void *mUnk_40;
    /* 44 */ void *mUnk_44;
    /* 48 */ s32 mUnk_48;
    /* 4c */ s32 mUnk_4c;
    /* 50 */ s32 mUnk_50;
    /* 54 */ s16 mUnk_54[2];
    /* 58 */ s32 mUnk_58;
    /* 5c */ s32 mUnk_5c;
    /* 60 */ s32 mUnk_60;
    /* 64 */ u32 mUnk_64;
    /* 68 */ u32 mUnk_68;
    /* 6c */ s32 mUnk_6c;
} Unk021a9bf4;

#include "01/code_0219c000.h"
#include "Main/Unknown/code_0212775c.h"
#include "01/code_021956dc.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_0211d000.h"
#include "Main/Unknown/code_0212b000.h"
#include "00/code_02182fdc.h"
#include "01/unk_021a8000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_02105000.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_02175628.h"

extern u16 data_ov001_021a6b38[];
extern u16 data_ov001_021a6b3c[];
extern u16 data_ov001_021a6b40[];
extern u16 data_ov001_021a6b48[];
extern u16 data_ov001_021a6b54[];
extern u16 data_ov001_021a6b60[];
extern u16 data_ov001_021a6b6c[];
extern u32 data_ov001_021a6b78[];
extern u16 data_ov001_021a6b88[];
extern u32 data_ov001_021a6ba4[];
extern Unk021a9bf4 *data_ov001_021a9bf4;

void func_ov001_0219b540(void);
int func_ov001_0219b574(void);
void func_ov001_0219b64c(void);
void func_ov001_0219b7c8(void);
void func_ov001_0219b81c(void);
void func_ov001_0219b834(void);
void func_ov001_0219b84c(void);
void func_ov001_0219b874(void);
void func_ov001_0219b9dc(void);
void func_ov001_0219ba3c(void);
void func_ov001_0219baf4(void);
void func_ov001_0219bb48(u32 a, u32 b, u32 c);
void func_ov001_0219be5c(void);
void func_ov001_0219bfc0(void);
void func_ov001_0219bff4(void);
void func_ov001_0219c058(void);
void func_ov001_0219c0bc(void);
void func_ov001_0219c2a4(void);
void func_ov001_0219c358(void);
void func_ov001_0219c3a8(void);
void func_ov001_0219c3bc(void);
void func_ov001_0219c3d8(void);
void func_ov001_0219c3ec(void);
void func_ov001_0219c428(void);
void func_ov001_0219c458(void);
void func_ov001_0219c46c(void);
void func_ov001_0219c480(void);
void func_ov001_0219c544(void);
void func_ov001_0219c6f0(void);
