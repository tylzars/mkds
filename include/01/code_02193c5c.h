#pragma once

#include "types.h"
#include "00/code_02182fdc.h"

// Object behind data_ov001_021a9bd4.
typedef struct Unk021a9bd4 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ void *mUnk_1c;
    /* 20 */ Unk02124b1c *mUnk_20;
    /* 24 */ struct Unk02021dc8 *mUnk_24;
    /* 28 */ Unk020b4934 *mUnk_28;
    /* 2c */ Unk020b4a44 *mUnk_2c;
    /* 30 */ void *mUnk_30;
    /* 34 */ void *mUnk_34;
    /* 38 */ void *mUnk_38;
    /* 3c */ void *mUnk_3c;
} Unk021a9bd4;

// Five callbacks handed over as one block.
typedef struct Unk021a8294 {
    /* 00 */ void (*mUnk_00[5])(void);
} Unk021a8294;

// Object behind Unk021a9bd8::mUnk_40.
typedef struct Unk021a9bd8_40 {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ u8 *mUnk_0c;
} Unk021a9bd8_40;

// Object behind data_ov001_021a9bd8.
typedef struct Unk021a9bd8 {
    /* 00 */ Unk020b4934 *mUnk_00;
    /* 04 */ struct Unk02021dc8 *mUnk_04;
    /* 08 */ Unk0201ea30 *mUnk_08;
    /* 0c */ u8 mUnk_0c[4];
    /* 10 */ Unk0201ea30 *mUnk_10;
    /* 14 */ Unk020b4934 *mUnk_14;
    /* 18 */ struct Unk02021dc8 *mUnk_18;
    /* 1c */ Unk0201ea30 *mUnk_1c;
    /* 20 */ void *mUnk_20;
    /* 24 */ Unk0201ea30 *mUnk_24;
    /* 28 */ Unk020b4934 *mUnk_28;
    /* 2c */ struct Unk02021dc8 *mUnk_2c;
    /* 30 */ Unk020b4a44 *mUnk_30;
    /* 34 */ void *mUnk_34;
    /* 38 */ void *mUnk_38;
    /* 3c */ void *mUnk_3c;
    /* 40 */ Unk021a9bd8_40 *mUnk_40;
    /* 44 */ void *mUnk_44;
    /* 48 */ Unk020b47d8 *mUnk_48;
    /* 4c */ void *mUnk_4c;
    /* 50 */ Unk02124b1c *mUnk_50;
    /* 54 */ Unk02124b1c *mUnk_54;
    /* 58 */ void *mUnk_58;
    /* 5c */ void *mUnk_5c;
    /* 60 */ s32 mUnk_60;
    /* 64 */ s32 mUnk_64;
    /* 68 */ s32 mUnk_68;
    /* 6c */ s32 mUnk_6c;
    /* 70 */ s32 mUnk_70;
    /* 74 */ s32 mUnk_74;
    /* 78 */ s32 mUnk_78;
    /* 7c */ s32 mUnk_7c;
    /* 80 */ s32 mUnk_80[2];
    /* 88 */ s32 mUnk_88;
    /* 8c */ s32 mUnk_8c;
    /* 90 */ s32 mUnk_90;
} Unk021a9bd8;

extern u8 data_ov001_021a65f0[][4];
extern const u16 data_ov001_021a66cc[4][3];
extern const u16 data_ov001_021a66b4[4][3];
extern const u16 data_ov001_021a6674[4][2];

#include "01/code_02192e78.h"
#include "01/code_021932e4.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217d068.h"
#include "01/code_02194000.h"
#include "01/code_0219e000.h"
#include "Main/Unknown/code_02111000.h"

#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_0212426c.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/code_0211d000.h"
#include "Main/Unknown/code_020472a8.h"

extern const u16 data_ov001_021a6614[4];
extern const u16 data_ov001_021a662c[4];
extern const u16 data_ov001_021a663c[4];
extern const u16 data_ov001_021a6654[4];
extern const u16 data_ov001_021a665c[4];
extern const u16 data_ov001_021a666c[4];
// Objects whose layout isn't known yet.
extern const Unk021a8294 data_ov001_021a8294;
extern const Unk021a8294 data_ov001_021a82d4;
extern Unk021a9bd8 *data_ov001_021a9bd8;

void func_ov001_02193c5c(void);
void func_ov001_02193c84(void);
void func_ov001_02193ccc(void);
void func_ov001_02193d14(void);
void func_ov001_02193da8(void);
void func_ov001_02193dec(void);
void func_ov001_02193f98(void);
void func_ov001_02194148(void);
void func_ov001_021942f8(void);
void func_ov001_021944e0(void);
void func_ov001_02194690(void);
void func_ov001_021946d0(void);
void func_ov001_02194730(void *heap);
void func_ov001_021949ac(void);
void func_ov001_021949c0(void);
void func_ov001_021949d4(void);
void func_ov001_02194a0c(void);
void func_ov001_02194a20(void);
void func_ov001_02194a34(void);
void func_ov001_02194a50(void);
u32 func_ov001_02194c9c(u32 a);
u32 func_ov001_02194d04(s32 a);
void func_ov001_02194d18(void);
void func_ov001_02194d48(void);
void func_ov001_02194d78(void);
void func_ov001_02194f20(void);
void func_ov001_02194fd8(s32 a);
void func_ov001_021950fc(s32 a);
void func_ov001_021953d0(void);
