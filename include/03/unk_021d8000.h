#pragma once

#include "types.h"
#include "code_0200db4c.h"
#include "03/unk_021d6000.h"

// Six bytes moved as one value.
typedef struct Unk021d8c54 {
    /* 0 */ u8 mUnk_00[6];
} Unk021d8c54;

// Eight bytes moved as one value.
typedef struct Unk021d8ca4 {
    /* 0 */ u8 mUnk_00[8];
} Unk021d8ca4;

// 0x40 bytes moved as one value.
typedef struct Unk021d8dc8_40 {
    /* 0 */ u32 mUnk_00[16];
} Unk021d8dc8_40;

// 0xe8 bytes.
typedef struct Unk021d8dc8 {
    /* 00 */ char mUnk_00[0x20];
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ u8 mUnk_28[4][0x20];
    /* a8 */ Unk021d8dc8_40 mUnk_a8;
} Unk021d8dc8;

// 0x60 bytes.
typedef struct Unk021d8fb0 {
    /* 00 */ char mUnk_00[0x2c];
    /* 2c */ u32 mUnk_2c;
    /* 30 */ s32 mUnk_30;
    /* 34 */ u8 mUnk_34[0x28];
    /* 5c */ s32 mUnk_5c;
} Unk021d8fb0;

// 0x48 bytes.
typedef struct Unk021d90ac {
    /* 00 */ Unk021d8dc8_40 mUnk_00;
    /* 40 */ u32 mUnk_40[2];
} Unk021d90ac;

// Entry of the list at data_ov003_021d8c2c, 0xc0 bytes.
typedef struct Unk021d8c2c {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ Unk021d8c54 mUnk_04;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u8 mUnk_0c[0x20];
    /* 2c */ u16 mUnk_2c;
    /* 2e */ u8 mUnk_2e[0x92];
} Unk021d8c2c;

// Objects whose layout isn't known yet.
extern UnkWordFunc *data_ov003_021d8bd4;
extern UnkFunc *data_ov003_021d8bdc;
extern s32 data_ov003_021d8be0;
extern u32 data_ov003_021d8bfc;
extern void *data_ov003_021d8c00;
extern s32 data_ov003_021d8c34;
extern s32 data_ov003_021d8c44;
extern Thread data_ov003_021d8d08;
extern s32 data_ov003_021d8c08;
extern s32 data_ov003_021d8c48;
extern UnkFunc *data_ov003_021d8c4c;
extern u8 data_ov003_021d8c8c[];
extern Unk021d8dc8 data_ov003_021d8dc8;
extern u8 data_ov003_021d8bd0;
extern u32 data_ov003_021d8be4;
extern u32 data_ov003_021d8be8;
extern u32 data_ov003_021d8bec;
extern u32 data_ov003_021d8bf0;
extern u32 data_ov003_021d8bf4;
extern u32 data_ov003_021d8c04;
extern u32 data_ov003_021d8c20;
extern Unk021d8c2c *data_ov003_021d8c2c;
extern s32 data_ov003_021d8c40;
extern Unk021d8c54 data_ov003_021d8c54;
extern Unk021d8c54 data_ov003_021d8c5c;
extern u8 data_ov003_021d8c7c[0x10];
extern u8 data_ov003_021d8ca4[];
extern char data_ov003_021d8ce4[];
extern u8 data_ov003_021d8cac[];
extern u32 data_ov003_021d8eb0[0x95];
extern Unk021d8fb0 data_ov003_021d8fb0;
extern u8 data_ov003_021d9014[];
extern Unk021d90ac data_ov003_021d90ac;
extern u8 data_ov003_021d9104[];
extern u8 data_ov003_021d9904[0x800];

typedef struct Unk021d8bd8 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
} Unk021d8bd8;

extern u8 *data_ov003_021d8bf8;
extern Unk021d8bd8 *data_ov003_021d8bd8;
extern void *data_ov003_021d8c0c;
extern u8 *data_ov003_021d8c14;
extern u8 *data_ov003_021d8c18;
extern u8 *data_ov003_021d8c1c;
extern u32 data_ov003_021d8c28;
extern u32 data_ov003_021d8c30;
extern UnkFunc *data_ov003_021d8c50;
extern u8 data_ov003_021d8c64[6];
extern u8 data_ov003_021d8cc4[0x20];
extern void *data_ov003_021d8c10;
extern void *data_ov003_021d8c24;
extern s32 data_ov003_021d8c38;
extern s32 data_ov003_021d8c3c;
extern u32 data_ov003_021d8c6c[4];

#include "03/code_021b94b8.h"
