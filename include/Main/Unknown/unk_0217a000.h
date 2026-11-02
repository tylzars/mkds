#pragma once

#include "types.h"
#include "Main/Unknown/code_020d22c0.h" // Unk020f41c4_B
#include "code_02004dc0.h" // Unk020055f0, Unk02003024
#include "code_0212da38.h" // Unk02017328
#include "code_0200e0ec.h" // Unk0200db5c
#include "code_02142eac.h" // Unk021438f0, Unk02143a78, Unk02143c30
#include "code_021445e0.h" // Unk021450ec, Unk0214461c
#include "code_02147cd8.h" // Unk02148038
#include "code_0214a748.h" // Unk0214ad4c
#include "code_02012b30.h" // Unk02012f58
#include "Main/Unknown/code_02006954.h"
#include "Main/Unknown/code_0207b960.h" // Unk0207b960
#include "Main/Unknown/code_0207adf8.h" // Unk0207adf8
#include "Main/Unknown/code_020846c0.h" // Unk02084b2c
#include "Main/Unknown/code_02087d0c.h" // Unk02087d0c

// Objects whose layout isn't known yet.
// What data_0217aa08 points to.
typedef struct Unk0217aa08_00 {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ u8 mUnk_0c[0x14];
    /* 20 */ u8 mUnk_20[2];
    /* 22 */ u8 mUnk_22;
    /* 23 */ u8 mUnk_23;
    /* 24 */ u16 mUnk_24;
    /* 26 */ u8 mUnk_26[0x4];
    /* 2a */ u8 mUnk_2a[0x2];
    /* 2c */ u8 mUnk_2c[0x5];
    /* 31 */ union {
        u8 mUnk_31;
        struct {
            u8 mUnk_31_0 : 1;
            u8 mUnk_31_1 : 2;
            u8 mUnk_31_3 : 1;
            u8 mUnk_31_4 : 1;
            u8 mUnk_31_5 : 3;
        };
    };
    /* 32 */ u8 mUnk_32[0x2];
    /* 34 */ u32 mUnk_34;
    /* 38 */ u32 mUnk_38;
    /* 3c */ u32 mUnk_3c;
    /* 40 */ u32 mUnk_40;
    /* 44 */ u32 mUnk_44;
    /* 48 */ u32 mUnk_48;
    /* 4c */ u8 mUnk_4c[0x4];
    /* 50 */ s32 mUnk_50;
    /* 54 */ s32 mUnk_54;
    /* 58 */ s32 mUnk_58;
    /* 5c */ u8 mUnk_5c[0xc];
    /* 68 */ s32 mUnk_68;
    /* 6c */ u8 mUnk_6c[0x4];
    /* 70 */ s32 mUnk_70;
    /* 74 */ u8 mUnk_74[0x18];
} Unk0217aa08_00;

typedef struct Unk0217aa08_04 {
    /* 000 */ u8 mUnk_000[0x4];
    /* 004 */ u8 mUnk_004 : 1;
    /* 005 */ u8 mUnk_005[0x3];
    /* 008 */ u8 mUnk_008[0x200];
} Unk0217aa08_04;

// Entries of 0x1c bytes from 0x04 of Unk0217aa08_08, in rows of eight.
typedef struct Unk0217aa08_08_04 {
    /* 00 */ union {
        u32 mUnk_00;
        u8 mUnk_00_b[4];
        struct {
            u32 mUnk_00_0 : 1;
            u32 mUnk_00_1 : 7;
        };
    };
    /* 04 */ union {
        u32 mUnk_04;
        u8 mUnk_04_b[4];
        struct {
            u32 mUnk_04_0 : 8;
            u32 mUnk_04_8 : 7;
            u32 mUnk_04_15 : 7;
            u32 mUnk_04_22 : 10;
        };
    };
    /* 08 */ u8 mUnk_08[0x14];
} Unk0217aa08_08_04;

// What member 0x08 of Unk0217aa08 points to (the row count is not shown by the code).
typedef struct Unk0217aa08_08 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ Unk0217aa08_08_04 mUnk_04[1][8];
} Unk0217aa08_08;

// Entries of 0x1c bytes from 0x04 of Unk0217aa08_0c, in rows of 0x20.
typedef struct Unk0217aa08_0c_04 {
    /* 00 */ union {
        u32 mUnk_00;
        struct {
            u32 mUnk_00_0 : 1;
            u32 mUnk_00_1 : 7;
            u32 mUnk_00_8 : 7;
            u32 mUnk_00_15 : 7;
            u32 mUnk_00_22 : 10;
        };
    };
    /* 04 */ u8 mUnk_04;
    /* 05 */ u8 mUnk_05[3];
    /* 08 */ u8 mUnk_08[0x14];
} Unk0217aa08_0c_04;

// What member 0x0c of Unk0217aa08 points to (the row count is not shown by the code).
typedef struct Unk0217aa08_0c {
    /* 000 */ u8 mUnk_000[4];
    /* 004 */ Unk0217aa08_0c_04 mUnk_004[1][0x20];
} Unk0217aa08_0c;

// One byte of Unk0217aa08_10_04: a flag and seven more bits.
typedef struct Unk0217aa08_10_04 {
    /* 00 */ union {
        u8 mUnk_00;
        struct {
            u8 mUnk_00_0 : 1;
            u8 mUnk_00_1 : 7;
        };
    };
} Unk0217aa08_10_04;

// What member 0x10 of Unk0217aa08 points to: bytes from 0x04, read in rows of nine (the count is not shown by the
// code).
typedef struct Unk0217aa08_10 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ Unk0217aa08_10_04 mUnk_04[1];
} Unk0217aa08_10;

// The 0xe00 bytes behind members 0x14 and 0x18 of Unk0217aa08.
typedef struct Unk0217aa08_14 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ union {
        u32 mUnk_04;
        struct {
            u32 mUnk_04_0 : 4;
            u32 mUnk_04_4 : 6;
            u32 mUnk_04_10 : 6;
            u32 mUnk_04_16 : 7;
            u32 mUnk_04_23 : 4;
            u32 mUnk_04_27 : 5;
        };
    };
    /* 08 */ union {
        u32 mUnk_08;
        struct {
            u32 mUnk_08_0 : 1;
            u32 mUnk_08_1 : 1;
            u32 mUnk_08_2 : 2;
            u32 mUnk_08_4 : 4;
            u32 mUnk_08_8 : 7;
            u32 mUnk_08_15 : 7;
            u32 mUnk_08_22 : 10;
        };
    };
    /* 0c */ u8 mUnk_0c[0x14];
    /* 20 */ u8 mUnk_20[0xf];
    /* 2f */ union {
        u8 mUnk_2f;
        struct {
            u8 mUnk_2f_0 : 2;
        };
    };
    /* 30 */ u8 mUnk_30[0xdd0];
} Unk0217aa08_14;

// Entries of 0x24 bytes from 0x04 of Unk0217aa08_20.
typedef struct Unk0217aa08_20_04 {
    /* 00 */ u16 mUnk_00[3][2];
    /* 0c */ union {
        u16 mUnk_0c;
        struct {
            u16 mUnk_0c_0 : 7;
            u16 mUnk_0c_7 : 4;
            u16 mUnk_0c_11 : 5;
        };
    };
    /* 0e */ u8 mUnk_0e[0x14];
    /* 22 */ union {
        u8 mUnk_22;
        struct {
            u8 mUnk_22_0 : 1;
            u8 mUnk_22_1 : 1;
            u8 mUnk_22_2 : 1;
            u8 mUnk_22_3 : 1;
        };
    };
    /* 23 */ u8 mUnk_23;
} Unk0217aa08_20_04;

// What member 0x20 of Unk0217aa08 points to (the entry count is not shown by the code).
typedef struct Unk0217aa08_20 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ Unk0217aa08_20_04 mUnk_04[1];
} Unk0217aa08_20;

// 0xb00 bytes behind member 0x24 of Unk0217aa08: a byte at 0x04 and five 0x200-byte rows from 0x08.
typedef struct Unk0217aa08_24 {
    /* 000 */ u8 mUnk_000[4];
    /* 004 */ u8 mUnk_004;
    /* 005 */ u8 mUnk_005[3];
    /* 008 */ u8 mUnk_008[5][0x200];
    /* a08 */ u8 mUnk_a08[0xf8];
} Unk0217aa08_24;

typedef struct Unk0217aa08 {
    /* 00 */ Unk0217aa08_00 *mUnk_00;
    /* 04 */ Unk0217aa08_04 *mUnk_04;
    /* 08 */ Unk0217aa08_08 *mUnk_08;
    /* 0c */ Unk0217aa08_0c *mUnk_0c;
    /* 10 */ Unk0217aa08_10 *mUnk_10;
    /* 14 */ Unk0217aa08_14 *mUnk_14;
    /* 18 */ Unk0217aa08_14 *mUnk_18;
    /* 1c */ Unk0217aa08_14 *mUnk_1c;
    /* 20 */ Unk0217aa08_20 *mUnk_20;
    /* 24 */ Unk0217aa08_24 *mUnk_24;
    /* 28 */ u8 mUnk_28;
    /* 29 */ u8 mUnk_29;
    /* 2a */ u16 mUnk_2a;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ u8 mUnk_30[4];
    /* 34 */ u8 mUnk_34[4];
    /* 38 */ u8 mUnk_38;
    /* 39 */ u8 mUnk_39;
    /* 3a */ u8 mUnk_3a[2];
    /* 3c */ u8 mUnk_3c;
    /* 3d */ u8 mUnk_3d[3];
    /* 40 */ void *mUnk_40;
    /* 44 */ union {
        s32 mUnk_44;
        struct {
            s32 mUnk_44_0 : 1;
        };
    };
} Unk0217aa08;

// 0x2c bytes from 0x36 of Unk0217aa00_24_50_0e.
typedef struct Unk0217aa00_24_50_0e_36 {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u8 mUnk_02[0x14];
    /* 16 */ u8 mUnk_16[0x16];
} Unk0217aa00_24_50_0e_36;

// 0x62 bytes from 0xe of Unk0217aa00_24_50.
typedef struct Unk0217aa00_24_50_0e {
    /* 00 */ u8 mUnk_00[6];
    /* 06 */ union {
        u8 mUnk_06;
        struct {
            u8 mUnk_06_0 : 4;
            u8 mUnk_06_4 : 4;
        };
    };
    /* 07 */ union {
        u8 mUnk_07;
        struct {
            u8 mUnk_07_0 : 1;
            u8 mUnk_07_1 : 6;
        };
    };
    /* 08 */ u8 mUnk_08[2];
    /* 0a */ u8 mUnk_0a[4];
    /* 0e */ u8 mUnk_0e[0x28];
    /* 36 */ Unk0217aa00_24_50_0e_36 mUnk_36;
} Unk0217aa00_24_50_0e;

// 0x70 bytes at 0x50 of Unk0217aa00_24; the word at 0x38 of Unk0217aa00_44 points to one.
typedef struct Unk0217aa00_24_50 {
    union {
        struct {
            /* 00 */ u8 mUnk_00[7];
            /* 07 */ u8 mUnk_07;
            /* 08 */ u8 mUnk_08[2];
            /* 0a */ u8 mUnk_0a;
            /* 0b */ u8 mUnk_0b[3];
            /* 0e */ Unk0217aa00_24_50_0e mUnk_0e;
        };
        struct {
            /* 00 */ u8 mUnk_00_pad[0x18];
            /* 18 */ union {
                u32 mUnk_18;
                struct {
                    u32 mUnk_18_0 : 4;
                    u32 mUnk_18_4 : 5;
                    u32 mUnk_18_9 : 7;
                    u32 mUnk_18_16 : 6;
                    u32 mUnk_18_22 : 10;
                };
            };
            /* 1c */ u8 mUnk_1c[0x54];
        };
    };
} Unk0217aa00_24_50;

// 0xc0 bytes behind member 0x24 of Unk0217aa00; the first 0xc0 bytes of each Unk0217aa00_0ac have the same layout.
typedef struct Unk0217aa00_24 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02[0x3a];
    /* 3c */ u16 mUnk_3c;
    /* 3e */ u8 mUnk_3e[6];
    /* 44 */ u32 mUnk_44;
    /* 48 */ u16 mUnk_48;
    /* 4a */ u8 mUnk_4a;
    /* 4b */ u8 mUnk_4b;
    /* 4c */ u8 mUnk_4c[4];
    /* 50 */ Unk0217aa00_24_50 mUnk_50;
} Unk0217aa00_24;

// Object behind member 0x15c4 of Unk0217aa00.
typedef struct Unk0217aa00_15c4 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04;
    /* 05 */ u8 mUnk_05;
    /* 06 */ union {
        u8 mUnk_06;
        struct {
            u8 mUnk_06_0 : 7;
            u8 mUnk_06_7 : 1;
        };
    };
    /* 07 */ u8 mUnk_07;
} Unk0217aa00_15c4;

// 8-byte entries from 0x44 of Unk0217aa00.
typedef struct Unk0217aa00_44_00 {
    /* 00 */ u8 mUnk_00[6];
    /* 06 */ u16 mUnk_06;
} Unk0217aa00_44_00;

// 0x44 bytes from 0x44 of Unk0217aa00.
typedef struct Unk0217aa00_44 {
    /* 00 */ Unk0217aa00_44_00 mUnk_00[7];
    /* 38 */ Unk0217aa00_24_50 *mUnk_38;
    /* 3c */ u16 mUnk_3c;
    /* 3e */ u16 mUnk_3e;
    /* 40 */ u8 mUnk_40;
    /* 41 */ s8 mUnk_41;
    /* 42 */ u8 mUnk_42;
    /* 43 */ u8 mUnk_43;
} Unk0217aa00_44;

// 8-byte entries behind member 0x1e48 of data_0217aa00.
typedef struct Unk0217aa00_1e48 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
    /* 04 */ u8 mUnk_04;
    /* 05 */ u8 mUnk_05[1];
    /* 06 */ u16 mUnk_06;
} Unk0217aa00_1e48;

// Elements of the array at member 0x1e52 of data_0217aa00.
typedef struct Unk0217aa00_1e52 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02[6];
} Unk0217aa00_1e52;

// Part of Unk0217aa00 from 0x1608.
typedef struct Unk0217aa00_1608 {
    /* 00 */ void *mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
    /* 14 */ u16 mUnk_14;
    /* 16 */ u16 mUnk_16;
    /* 18 */ s16 mUnk_18;
    /* 1a */ u8 mUnk_1a;
    /* 1b */ u8 mUnk_1b[0x1];
} Unk0217aa00_1608;

// Object behind data_0217aa00.
// 0x88-byte entries from 0x16a0 of Unk0217aa00.
typedef struct Unk0217aa00_16a0 {
    /* 00 */ Unk02007014 mUnk_00;
    /* 34 */ u8 mUnk_34;
    /* 35 */ u8 mUnk_35[0x3f];
    /* 74 */ u32 *mUnk_74;
    /* 78 */ void *mUnk_78;
    /* 7c */ void **mUnk_7c;
    /* 80 */ void *mUnk_80;
    /* 84 */ union {
        s32 mUnk_84;
        struct {
            u32 mUnk_84_0 : 29;
            s32 mUnk_84_29 : 1;
            u32 mUnk_84_30 : 1;
            u32 mUnk_84_31 : 1;
        };
    };
} Unk0217aa00_16a0;

// Members from 0x16a0 of Unk0217aa00 as one object.
typedef struct Unk0217aa00_16a0_view {
    /* 000 */ Unk0217aa00_16a0 mUnk_000[12];
    /* 660 */ s32 mUnk_660;
    /* 664 */ u8 mUnk_664[4];
    /* 668 */ u16 mUnk_668;
    /* 66a */ s16 mUnk_66a;
    /* 66c */ u8 mUnk_66c[0x48];
    /* 6b4 */ u8 mUnk_6b4;
    /* 6b5 */ u8 mUnk_6b5[3];
    /* 6b8 */ void *mUnk_6b8;
    /* 6bc */ u8 mUnk_6bc[0xdc];
    /* 798 */ s32 mUnk_798;
    /* 79c */ s32 mUnk_79c;
    /* 7a0 */ u16 mUnk_7a0;
    /* 7a2 */ u16 mUnk_7a2;
    /* 7a4 */ u8 mUnk_7a4;
    /* 7a5 */ s8 mUnk_7a5;
    /* 7a6 */ u8 mUnk_7a6;
    /* 7a7 */ u8 mUnk_7a7[1];
} Unk0217aa00_16a0_view;

// 0x22c-byte entries from 0x45c of Unk0217aa00.
typedef struct Unk0217aa00_45c {
    /* 000 */ u8 mUnk_000[0x14];
    /* 014 */ u8 mUnk_014;
    /* 015 */ u8 mUnk_015[0x1ff];
    /* 214 */ u8 mUnk_214;
    /* 215 */ u8 mUnk_215;
    /* 216 */ u16 mUnk_216;
    /* 218 */ s32 mUnk_218;
    /* 21c */ s32 mUnk_21c;
    /* 220 */ s32 mUnk_220;
    /* 224 */ u8 mUnk_224[4];
    /* 228 */ union {
        u8 mUnk_228;
        struct {
            u8 mUnk_228_0 : 4;
            u8 mUnk_228_4 : 4;
        };
    };
    /* 229 */ u8 mUnk_229;
    /* 22a */ u8 mUnk_22a[2];
} Unk0217aa00_45c;

// Six bytes, compared and assigned as one object.
typedef struct Unk0217aa00_42c {
    /* 00 */ u8 mUnk_00[6];
} Unk0217aa00_42c;

// 0xe0-byte entries from 0xac of Unk0217aa00.
typedef struct Unk0217aa00_0ac {
    /* 00 */ u8 mUnk_00[0xc0];
    /* c0 */ union {
        u8 mUnk_c0[6];
        Unk0217aa00_42c mUnk_c0_42c;
    };
    /* c6 */ u8 mUnk_c6[0x14];
    /* da */ u8 mUnk_da;
    /* db */ u8 mUnk_db;
    /* dc */ union {
        u8 mUnk_dc;
        struct {
            u8 mUnk_dc_0 : 1;
            u8 mUnk_dc_1 : 4;
            u8 mUnk_dc_5 : 1;
            u8 mUnk_dc_6 : 1;
        };
    };
    /* dd */ u8 mUnk_dd[3];
} Unk0217aa00_0ac;

// The 0x3b0 bytes from 0xac of Unk0217aa00 as one object: the four entries, then the members up to 0x45c.
typedef struct Unk0217aa00_ac {
    /* 000 */ Unk0217aa00_0ac mUnk_000[4];
    /* 380 */ u8 mUnk_380[6];
    /* 386 */ u8 mUnk_386[2];
    /* 388 */ u16 mUnk_388;
    /* 38a */ u16 mUnk_38a;
    /* 38c */ u8 mUnk_38c;
    /* 38d */ u8 mUnk_38d;
    /* 38e */ u8 mUnk_38e;
    /* 38f */ s8 mUnk_38f;
    /* 390 */ u8 mUnk_390[0x20];
} Unk0217aa00_ac;

// 8-byte entries behind member 0xc of Unk0217aa00_15bc.
typedef struct Unk0217aa00_15c8 {
    /* 00 */ union {
        u8 mUnk_00[6];
        u16 mUnk_00_0;
    };
    /* 06 */ union {
        u8 mUnk_06;
        struct {
            u8 mUnk_06_0 : 7;
            u8 mUnk_06_7 : 1;
        };
    };
    /* 07 */ u8 mUnk_07;
} Unk0217aa00_15c8;

// Members 0x15bc to 0x1607 of Unk0217aa00 as one object.
typedef struct Unk0217aa00_15bc {
    /* 00 */ Unk021450ec *mUnk_00;
    /* 04 */ Unk0214461c *mUnk_04;
    /* 08 */ void *mUnk_08;
    /* 0c */ Unk0217aa00_15c8 *mUnk_0c;
    /* 10 */ s32 mUnk_10[8];
    /* 30 */ u8 mUnk_30;
    /* 31 */ u8 mUnk_31[3];
    /* 34 */ s32 mUnk_34;
    /* 38 */ u16 mUnk_38;
    /* 3a */ u8 mUnk_3a;
    /* 3b */ u8 mUnk_3b;
    /* 3c */ u16 mUnk_3c[7];
    /* 4a */ u8 mUnk_4a;
    /* 4b */ u8 mUnk_4b[1];
} Unk0217aa00_15bc;

// 8-byte entries from 0x1e4c of Unk0217aa00.
typedef struct Unk0217aa00_1e4c_00 {
    /* 00 */ u16 mUnk_00[3];
    /* 06 */ u16 mUnk_06;
} Unk0217aa00_1e4c_00;

// Members 0x1e4c to 0x1ecf of Unk0217aa00 as one object.
typedef struct Unk0217aa00_1e4c {
    /* 00 */ Unk0217aa00_1e4c_00 mUnk_00[8];
    /* 40 */ u8 mUnk_40[0x20];
    /* 60 */ u8 mUnk_60;
    /* 61 */ u8 mUnk_61[7];
    /* 68 */ u8 mUnk_68;
    /* 69 */ u8 mUnk_69[0x1b];
} Unk0217aa00_1e4c;

// Six words from 0x1eb8 of Unk0217aa00.
typedef struct Unk0217aa00_1eb8 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
} Unk0217aa00_1eb8;

// What member 0x1da0 of Unk0217aa00 points to.
typedef struct Unk0217aa00_1da0 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
} Unk0217aa00_1da0;

// Members 0x1658 to 0x169f of Unk0217aa00 as one object.
typedef struct Unk0217aa00_1658 {
    /* 00 */ void *mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ void *mUnk_0c;
    /* 10 */ void *mUnk_10;
    /* 14 */ s32 mUnk_14[8];
    /* 34 */ u32 mUnk_34;
    /* 38 */ u16 mUnk_38;
    /* 3a */ u16 mUnk_3a;
    /* 3c */ u8 mUnk_3c;
    /* 3d */ u8 mUnk_3d;
    /* 3e */ u8 mUnk_3e;
    /* 3f */ u8 mUnk_3f;
    /* 40 */ u8 mUnk_40;
    /* 41 */ u8 mUnk_41;
    /* 42 */ s8 mUnk_42;
    /* 43 */ u8 mUnk_43;
    /* 44 */ s32 mUnk_44;
} Unk0217aa00_1658;

typedef struct Unk0217aa00 {
    /* 0000 */ u32 mUnk_0000;
    /* 0004 */ s32 mUnk_0004;
    /* 0008 */ s32 mUnk_0008;
    /* 000c */ s32 mUnk_000c;
    /* 0010 */ s32 mUnk_0010;
    /* 0014 */ void *mUnk_0014;
    /* 0018 */ Unk02143c30 *mUnk_0018;
    /* 001c */ Unk02143a78 *mUnk_001c;
    /* 0020 */ Unk021438f0 *mUnk_0020;
    /* 0024 */ Unk0217aa00_24 *mUnk_0024;
    /* 0028 */ void *mUnk_0028;
    /* 002c */ void *mUnk_002c;
    /* 0030 */ s32 mUnk_0030;
    /* 0034 */ u32 mUnk_0034;
    /* 0038 */ s32 mUnk_0038;
    /* 003c */ u32 mUnk_003c;
    /* 0040 */ void *mUnk_0040;
    /* 0044 */ Unk0217aa00_44 mUnk_0044;
    /* 0088 */ s8 mUnk_0088;
    /* 0089 */ union {
        u8 mUnk_0089;
        struct {
            u8 mUnk_0089_0 : 4;
            u8 mUnk_0089_4 : 4;
        };
    };
    /* 008a */ u8 mUnk_008a;
    /* 008b */ u8 mUnk_008b;
    /* 008c */ s16 mUnk_008c[0xe];
    /* 00a8 */ u8 mUnk_00a8[4];
    /* 00ac */ union {
        struct {
            /* 00ac */ Unk0217aa00_0ac mUnk_00ac[4];
            /* 042c */ u8 mUnk_042c;
            /* 042d */ u8 mUnk_042d;
            /* 042e */ u8 mUnk_042e;
            /* 042f */ u8 mUnk_042f;
            /* 0430 */ u8 mUnk_0430;
            /* 0431 */ u8 mUnk_0431;
            /* 0432 */ u16 mUnk_0432;
            /* 0434 */ u16 mUnk_0434;
            /* 0436 */ u16 mUnk_0436;
            /* 0438 */ u8 mUnk_0438;
            /* 0439 */ u8 mUnk_0439;
            /* 043a */ u8 mUnk_043a;
            /* 043b */ s8 mUnk_043b;
            /* 043c */ u8 mUnk_043c;
            /* 043d */ u8 mUnk_043d;
            /* 043e */ u8 mUnk_043e[0x2];
            /* 0440 */ s32 (*mUnk_0440)();
            /* 0444 */ s32 (*mUnk_0444)();
            /* 0448 */ s32 (*mUnk_0448)();
            /* 044c */ s32 (*mUnk_044c)();
            /* 0450 */ s32 (*mUnk_0450)();
            /* 0454 */ u16 mUnk_0454;
            /* 0456 */ union {
                u8 mUnk_0456;
                struct {
                    u8 mUnk_0456_0 : 1;
                };
            };
            /* 0457 */ u8 mUnk_0457;
            /* 0458 */ u8 mUnk_0458;
            /* 0459 */ u8 mUnk_0459[3];
        };
        Unk0217aa00_ac mUnk_00ac_view;
    };
    /* 045c */ Unk0217aa00_45c mUnk_045c[8];
    /* 15bc */ union {
        struct {
            /* 15bc */ Unk021450ec *mUnk_15bc;
            /* 15c0 */ Unk0214461c *mUnk_15c0;
            /* 15c4 */ Unk0217aa00_15c4 *mUnk_15c4;
            /* 15c8 */ Unk0217aa00_15c8 *mUnk_15c8;
            /* 15cc */ s32 mUnk_15cc;
            /* 15d0 */ u8 mUnk_15d0[0x1c];
            /* 15ec */ u8 mUnk_15ec;
            /* 15ed */ u8 mUnk_15ed[0x3];
            /* 15f0 */ s32 mUnk_15f0;
            /* 15f4 */ u16 mUnk_15f4;
            /* 15f6 */ u8 mUnk_15f6;
            /* 15f7 */ u8 mUnk_15f7;
            /* 15f8 */ u16 mUnk_15f8[7];
            /* 1606 */ u8 mUnk_1606;
            /* 1607 */ u8 mUnk_1607[0x1];
        };
        Unk0217aa00_15bc mUnk_15bc_view;
    };
    /* 1608 */ Unk0217aa00_1608 mUnk_1608;
    /* 1624 */ void *mUnk_1624;
    /* 1628 */ u8 mUnk_1628;
    /* 1629 */ u8 mUnk_1629;
    /* 162a */ u8 mUnk_162a;
    /* 162b */ u8 mUnk_162b[0x1];
    /* 162c */ u8 *mUnk_162c[8];
    /* 164c */ u8 mUnk_164c;
    /* 164d */ u8 mUnk_164d;
    /* 164e */ u8 mUnk_164e;
    /* 164f */ u8 mUnk_164f;
    /* 1650 */ void *mUnk_1650;
    /* 1654 */ void *mUnk_1654;
    /* 1658 */ union {
        struct {
            /* 1658 */ void *mUnk_1658;
            /* 165c */ void *mUnk_165c;
            /* 1660 */ s32 mUnk_1660;
            /* 1664 */ void *mUnk_1664;
            /* 1668 */ void *mUnk_1668;
            /* 166c */ s32 mUnk_166c;
            /* 1670 */ u8 mUnk_1670[0x1c];
            /* 168c */ u32 mUnk_168c;
            /* 1690 */ u16 mUnk_1690;
            /* 1692 */ u16 mUnk_1692;
            /* 1694 */ u8 mUnk_1694;
            /* 1695 */ u8 mUnk_1695;
            /* 1696 */ u8 mUnk_1696;
            /* 1697 */ u8 mUnk_1697;
            /* 1698 */ u8 mUnk_1698;
            /* 1699 */ u8 mUnk_1699;
            /* 169a */ s8 mUnk_169a;
            /* 169b */ u8 mUnk_169b[0x1];
            /* 169c */ s32 mUnk_169c;
        };
        Unk0217aa00_1658 mUnk_1658_view;
    };
    /* 16a0 */ union {
        struct {
            /* 16a0 */ Unk0217aa00_16a0 mUnk_16a0[12];
            /* 1d00 */ s32 mUnk_1d00;
            /* 1d04 */ void *mUnk_1d04;
            /* 1d08 */ u16 mUnk_1d08;
            /* 1d0a */ u16 mUnk_1d0a;
            /* 1d0c */ Unk02003024 mUnk_1d0c;
            /* 1d54 */ u8 mUnk_1d54;
            /* 1d55 */ u8 mUnk_1d55[0x3];
            /* 1d58 */ void *mUnk_1d58;
            /* 1d5c */ s16 mUnk_1d5c;
            /* 1d5e */ u16 mUnk_1d5e;
            /* 1d60 */ u32 *mUnk_1d60;
            /* 1d64 */ u8 mUnk_1d64[0x3c];
            /* 1da0 */ Unk0217aa00_1da0 *mUnk_1da0[16];
            /* 1de0 */ void *mUnk_1de0[16];
            /* 1e20 */ void *mUnk_1e20;
            /* 1e24 */ void *mUnk_1e24;
            /* 1e28 */ s32 mUnk_1e28;
            /* 1e2c */ s32 mUnk_1e2c;
            /* 1e30 */ s32 mUnk_1e30;
            /* 1e34 */ s32 mUnk_1e34;
            /* 1e38 */ s32 mUnk_1e38;
            /* 1e3c */ s32 mUnk_1e3c;
            /* 1e40 */ u16 mUnk_1e40;
            /* 1e42 */ u16 mUnk_1e42;
            /* 1e44 */ u8 mUnk_1e44;
            /* 1e45 */ s8 mUnk_1e45;
            /* 1e46 */ u8 mUnk_1e46;
            /* 1e47 */ u8 mUnk_1e47[0x1];
            /* 1e48 */ Unk0217aa00_1e48 *mUnk_1e48;
            /* 1e4c */ union {
                struct {
                    /* 1e4c */ u16 mUnk_1e4c;
                    /* 1e4e */ u8 mUnk_1e4e[0x4];
                    /* 1e52 */ Unk0217aa00_1e52 mUnk_1e52[7];
                    /* 1e8a */ u16 mUnk_1e8a;
                    /* 1e8c */ u16 mUnk_1e8c[8];
                    /* 1e9c */ u16 mUnk_1e9c[8];
                    /* 1eac */ u8 mUnk_1eac[4];
                    /* 1eb0 */ s32 mUnk_1eb0;
                    /* 1eb4 */ u8 mUnk_1eb4[4];
                    /* 1eb8 */ Unk0217aa00_1eb8 mUnk_1eb8;
                };
                Unk0217aa00_1e4c mUnk_1e4c_view;
            };
            /* 1ed0 */ s32 mUnk_1ed0;
            /* 1ed4 */ u16 mUnk_1ed4;
            /* 1ed6 */ u16 mUnk_1ed6;
            /* 1ed8 */ s32 mUnk_1ed8;
            /* 1edc */ u16 mUnk_1edc;
            /* 1ede */ u16 mUnk_1ede;
            /* 1ee0 */ u8 mUnk_1ee0[2];
            /* 1ee2 */ u8 mUnk_1ee2[6];
        };
        Unk0217aa00_16a0_view mUnk_16a0_view;
    };
    /* 1ee8 */ Unk020f41c4_B mUnk_1ee8;
} Unk0217aa00;

extern Unk0217aa00 *data_0217aa00;
extern Unk0217aa08 *data_0217aa08;
// Object behind data_0217aa0c; the Unk0200db5c at 0x2c is passed to func_0200e28c and func_0200df68.
typedef struct Unk0217aa0c {
    /* 00 */ void (*mUnk_00[10])(void);
    /* 28 */ u8 mUnk_28;
    /* 29 */ u8 mUnk_29[3];
    /* 2c */ Unk0200db5c mUnk_2c;
    /* e4 */ u8 mUnk_e4[0x10];
    /* f4 */ void *mUnk_f4;
    /* f8 */ s32 mUnk_f8;
} Unk0217aa0c;

extern Unk0217aa0c *data_0217aa0c;
// 0xc-byte entries from 0x08 of Unk0217aa10.
typedef struct Unk0217aa10_08 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
} Unk0217aa10_08;

struct Unk02017584;

// Object behind data_0217aa10; func_0212034c reads the word at 0. The objects at 0x2c and 0x58 are passed to
// FS_StartOverlay and FS_InitFile, the pointer at 0xa4 to func_0201797c.
typedef struct Unk0217aa10 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ Unk0217aa10_08 mUnk_08[3];
    /* 2c */ Unk020055f0 mUnk_2c;
    /* 58 */ Unk02003024 mUnk_58;
    /* a0 */ void *mUnk_a0;
    /* a4 */ void *mUnk_a4;
    /* a8 */ u32 mUnk_a8;
    /* ac */ u32 mUnk_ac;
} Unk0217aa10;

extern Unk0217aa10 *data_0217aa10;
// 0x38-byte entries from 0x14 of Unk0217aa14.
typedef struct Unk0217aa14_014 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ s32 mUnk_30;
    /* 34 */ u8 mUnk_34;
    /* 35 */ u8 mUnk_35;
    /* 36 */ u8 mUnk_36;
    /* 37 */ u8 mUnk_37;
} Unk0217aa14_014;

// Halfwords from 0x20 of Unk0217aa14_104: bits 7 to 11 and 12 to 13.
typedef struct Unk0217aa14_104_20 {
    /* 00 */ union {
        u16 mUnk_00;
        struct {
            u16 : 7;
            u16 mUnk_00_7 : 5;
            u16 mUnk_00_12 : 2;
        };
    };
} Unk0217aa14_104_20;

// The 0x20 bytes from 0x68 of Unk0217aa14_104.
typedef struct Unk0217aa14_104_68 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ u8 mUnk_10[0x10];
} Unk0217aa14_104_68;

// 0x88-byte entries from 0x104 of Unk0217aa14.
typedef struct Unk0217aa14_104 {
    /* 00 */ union {
        s32 mUnk_00;
        struct {
            u32 mUnk_00_0 : 24;
        };
    };
    /* 04 */ s32 mUnk_04;
    /* 08 */ u8 mUnk_08[0x18];
    /* 20 */ Unk0217aa14_104_20 mUnk_20[4];
    /* 28 */ u8 mUnk_28[0x40];
    /* 68 */ union {
        struct {
            /* 68 */ s32 mUnk_68;
            /* 6c */ s32 mUnk_6c;
            /* 70 */ s32 mUnk_70;
            /* 74 */ u16 mUnk_74;
            /* 76 */ u16 mUnk_76;
            /* 78 */ s32 mUnk_78;
            /* 7c */ u16 mUnk_7c;
            /* 7e */ u8 mUnk_7e[2];
            /* 80 */ s32 mUnk_80;
            /* 84 */ u16 mUnk_84;
            /* 86 */ union {
                u8 mUnk_86;
                struct {
                    u8 mUnk_86_0 : 1;
                    u8 mUnk_86_1 : 7;
                };
            };
            /* 87 */ u8 mUnk_87;
        };
        Unk0217aa14_104_68 mUnk_68_view;
    };
} Unk0217aa14_104;

// 0xc-byte entries from 0x324 of Unk0217aa14.
typedef struct Unk0217aa14_324 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ void *mUnk_04;
    /* 08 */ u8 mUnk_08;
    /* 09 */ u8 mUnk_09;
    /* 0a */ u8 mUnk_0a;
    /* 0b */ u8 mUnk_0b;
} Unk0217aa14_324;

// Halfword of the table at 0x20 of Unk0217aa14_754_04: bits 0 to 6, 7 to 11 and 12 to 13.
typedef struct Unk0217aa14_754_04_20 {
    /* 00 */ union {
        u16 mUnk_00;
        struct {
            u16 mUnk_00_0 : 7;
            u16 mUnk_00_7 : 5;
            u16 mUnk_00_12 : 2;
        };
    };
} Unk0217aa14_754_04_20;

// 0x68 bytes from 0x04 of what member 0x754 of Unk0217aa14 points to.
typedef struct Unk0217aa14_754_04 {
    /* 00 */ union {
        u32 mUnk_00;
        u16 mUnk_00_h;
        u8 mUnk_00_b[4];
        struct {
            u32 mUnk_00_0 : 24;
        };
    };
    /* 04 */ union {
        u32 mUnk_04;
        u8 mUnk_04_b[4];
    };
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c[5];
    /* 20 */ Unk0217aa14_754_04_20 mUnk_20[4];
    /* 28 */ u8 mUnk_28[0x10];
    /* 38 */ u8 mUnk_38[0x30];
} Unk0217aa14_754_04;

// What member 0x754 of Unk0217aa14 points to.
typedef struct Unk0217aa14_754 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ Unk0217aa14_754_04 mUnk_04;
} Unk0217aa14_754;

// Object behind data_0217aa14.
typedef struct Unk0217aa14 {
    /* 000 */ void *mUnk_000;
    /* 004 */ s32 mUnk_004;
    /* 008 */ void *mUnk_008;
    /* 00c */ u16 mUnk_00c;
    /* 00e */ u16 mUnk_00e;
    /* 010 */ u16 mUnk_010;
    /* 012 */ u16 mUnk_012;
    /* 014 */ Unk0217aa14_014 mUnk_014[4];
    /* 0f4 */ s32 mUnk_0f4;
    /* 0f8 */ u16 mUnk_0f8;
    /* 0fa */ u8 mUnk_0fa;
    /* 0fb */ u8 mUnk_0fb;
    /* 0fc */ u8 mUnk_0fc;
    /* 0fd */ u8 mUnk_0fd;
    /* 0fe */ u8 mUnk_0fe[6];
    /* 104 */ Unk0217aa14_104 mUnk_104[4];
    /* 324 */ Unk0217aa14_324 mUnk_324[16];
    /* 3e4 */ Unk0217aa14_324 mUnk_3e4[16][4];
    /* 6e4 */ u8 mUnk_6e4[0x40];
    /* 724 */ u16 mUnk_724;
    /* 726 */ u8 mUnk_726[0x2];
    /* 728 */ s32 mUnk_728;
    /* 72c */ s32 mUnk_72c;
    /* 730 */ u8 mUnk_730[0x4];
    /* 734 */ u16 mUnk_734;
    /* 736 */ s16 mUnk_736;
    /* 738 */ u16 mUnk_738;
    /* 73a */ u8 mUnk_73a;
    /* 73b */ u8 mUnk_73b;
    /* 73c */ u8 mUnk_73c[0x1];
    /* 73d */ u8 mUnk_73d;
    /* 73e */ u8 mUnk_73e;
    /* 73f */ u8 mUnk_73f;
    /* 740 */ u16 mUnk_740[4];
    /* 748 */ u8 mUnk_748;
    /* 749 */ u8 mUnk_749;
    /* 74a */ u8 mUnk_74a[4];
    /* 74e */ u8 mUnk_74e[4];
    /* 752 */ u8 mUnk_752[2];
    /* 754 */ Unk0217aa14_754 *mUnk_754;
    /* 758 */ s32 mUnk_758;
    /* 75c */ u16 mUnk_75c;
} Unk0217aa14;

extern Unk0217aa14 *data_0217aa14;
typedef struct Unk0217aa54 {
    /* 00 */ s16 mUnk_00;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ s32 mUnk_30;
    /* 34 */ s32 mUnk_34;
    /* 38 */ s32 mUnk_38;
    /* 3c */ s32 mUnk_3c;
    /* 40 */ s16 mUnk_40;
    /* 42 */ s16 mUnk_42;
    /* 44 */ s16 mUnk_44;
} Unk0217aa54;

extern Unk0217aa54 *data_0217aa54;
extern s32 data_0217aa64;
struct Unk02077750;

// Object behind data_0217aa6c, returned by func_02061808.
typedef struct Unk02061808 {
    /* 000 */ Vec3 mUnk_000;
    /* 00c */ Vec3 mUnk_00c;
    /* 018 */ Vec3 mUnk_018;
    /* 024 */ Vec3 mUnk_024;
    /* 030 */ Unk02012f58 mUnk_030;
    /* 060 */ s32 mUnk_060;
    /* 064 */ s32 mUnk_064;
    /* 068 */ s16 mUnk_068;
    /* 06a */ s16 mUnk_06a;
    /* 06c */ s32 mUnk_06c;
    /* 070 */ s32 mUnk_070;
    /* 074 */ s32 mUnk_074;
    /* 078 */ s32 mUnk_078;
    /* 07c */ s32 mUnk_07c;
    /* 080 */ s32 mUnk_080;
    /* 084 */ s32 mUnk_084;
    /* 088 */ s32 mUnk_088;
    /* 08c */ s32 mUnk_08c;
    /* 090 */ Vec3 mUnk_090;
    /* 09c */ Vec3 mUnk_09c;
    /* 0a8 */ Vec3 mUnk_0a8;
    /* 0b4 */ Vec3 mUnk_0b4;
    /* 0c0 */ Vec3 mUnk_0c0;
    /* 0cc */ s32 mUnk_0cc;
    /* 0d0 */ s32 mUnk_0d0;
    /* 0d4 */ s32 mUnk_0d4;
    /* 0d8 */ s32 mUnk_0d8;
    /* 0dc */ s32 mUnk_0dc;
    /* 0e0 */ s32 mUnk_0e0;
    /* 0e4 */ s32 mUnk_0e4;
    /* 0e8 */ s32 mUnk_0e8;
    /* 0ec */ s32 mUnk_0ec;
    /* 0f0 */ s32 mUnk_0f0;
    /* 0f4 */ Vec3 mUnk_0f4;
    /* 100 */ Vec3 mUnk_100;
    /* 10c */ Vec3 mUnk_10c;
    /* 118 */ Vec3 mUnk_118;
    /* 124 */ Vec3 mUnk_124;
    /* 130 */ u8 mUnk_130;
    /* 131 */ u8 mUnk_131[0x3];
    /* 134 */ Vec3 mUnk_134;
    /* 140 */ s32 mUnk_140;
    /* 144 */ s32 mUnk_144;
    /* 148 */ s32 mUnk_148;
    /* 14c */ s32 mUnk_14c;
    /* 150 */ s16 mUnk_150;
    /* 152 */ u8 mUnk_152[0x2];
    /* 154 */ s32 mUnk_154;
    /* 158 */ s32 mUnk_158;
    /* 15c */ Vec3 mUnk_15c;
    /* 168 */ s32 mUnk_168;
    /* 16c */ s32 mUnk_16c;
    /* 170 */ s32 mUnk_170;
    /* 174 */ s32 mUnk_174;
    /* 178 */ s32 mUnk_178;
    /* 17c */ Vec3 mUnk_17c;
    /* 188 */ Vec3 mUnk_188;
    /* 194 */ Unk0207b960 mUnk_194;
    /* 1d0 */ Unk0207b960 mUnk_1d0;
    /* 20c */ u16 mUnk_20c;
    /* 20e */ u16 mUnk_20e;
    /* 210 */ u16 mUnk_210;
    /* 212 */ u8 mUnk_212[0x2];
    /* 214 */ s32 mUnk_214;
    /* 218 */ struct Unk020748b8_218 *mUnk_218;
    /* 21c */ struct Unk02077750 *mUnk_21c;
    /* 220 */ struct Unk02077750 *mUnk_220;
    /* 224 */ u16 mUnk_224;
    /* 226 */ u8 mUnk_226[0x2];
    /* 228 */ s32 mUnk_228;
    /* 22c */ u16 mUnk_22c;
    /* 22e */ u8 mUnk_22e[0x2];
    /* 230 */ s32 mUnk_230;
    /* 234 */ s32 mUnk_234;
    /* 238 */ s32 mUnk_238;
    /* 23c */ u16 mUnk_23c;
    /* 23e */ u8 mUnk_23e[0x2];
    /* 240 */ s32 mUnk_240;
    /* 244 */ s32 mUnk_244;
    /* 248 */ s32 mUnk_248;
    /* 24c */ s32 mUnk_24c;
    /* 250 */ s32 mUnk_250;
    /* 254 */ s32 mUnk_254;
    /* 258 */ s32 mUnk_258;
    /* 25c */ s32 mUnk_25c;
    /* 260 */ Vec3 mUnk_260;
    /* 26c */ u16 mUnk_26c;
    /* 26e */ u8 mUnk_26e[0x2];
} Unk02061808;

extern Unk02061808 *data_0217aa6c;
extern u16 data_0217aa28;
extern u16 data_0217aa30;
extern s16 data_0217aa34;
extern u16 data_0217aa38;
extern s16 data_0217aa3c;
extern s16 data_0217aa40;
extern s32 data_0217aa44;
extern s32 data_0217aa48;
extern s32 data_0217aa4c;
extern s32 data_0217aa50;
extern s32 data_0217aa58;
extern Unk02061808 *data_0217aa5c;
extern s32 data_0217aa60;
extern s32 data_0217aa68;
extern s32 data_0217aa70;
extern void *data_0217aa74;
extern s32 data_0217aa78;
extern s32 data_0217aa80;
extern s32 data_0217aa84;
extern Unk02061808 *data_0217aa88;
extern u32 data_0217aa8c[4];
extern u32 data_0217aa9c[8];
extern u32 data_0217aabc[8];
extern u16 data_0217aadc[32];
extern Unk02012f58 *data_0217aa7c;
extern u32 data_0217ac10;
extern void *data_0217ac14;
extern void *data_0217ac18[15];
extern void *data_0217ac54[15];
extern struct Unk02061808 *data_0217ac94;
extern s32 data_0217aca8;
extern Unk02061808 *data_0217acb4;
extern Unk02061808 *data_0217acbc;
extern u8 data_0217acc0[];
// 0x20-byte entries behind member 0x014 of Unk0217ad00.
typedef struct Unk0217ad00_014 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[0x1a];
} Unk0217ad00_014;

// Object behind data_0217ad00 (0x144 bytes); the addresses of 0x2c, 0x98 and 0x10c are passed on as objects.
struct Unk0206bcb0_590;

typedef struct Unk0217ad00 {
    /* 000 */ struct Unk0206bcb0_590 *mUnk_000;
    /* 004 */ u8 *mUnk_004;
    /* 008 */ u16 mUnk_008;
    /* 00a */ u8 mUnk_00a[2];
    /* 00c */ s32 mUnk_00c;
    /* 010 */ u16 *mUnk_010;
    /* 014 */ Unk0217ad00_014 *mUnk_014;
    /* 018 */ s16 mUnk_018[8];
    /* 028 */ void *mUnk_028;
    /* 02c */ Unk02084b2c mUnk_02c;
    /* 098 */ Unk0207adf8 mUnk_098;
    /* 10c */ Unk02087d0c mUnk_10c;
} Unk0217ad00;

extern Unk0217ad00 *data_0217ad00;

// Object behind member 0x08 of an Unk0217ad08_058 (0x38 bytes); only the words below are read.
typedef struct Unk0217ad08_058_08 {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ s32 mUnk_0c;
    /* 10 */ u8 mUnk_10[0xa];
    /* 1a */ u16 mUnk_1a;
    /* 1c */ s32 **mUnk_1c;
} Unk0217ad08_058_08;

// Object behind member 0x20 of an Unk0217ad08_058: a word at 0x10 and rows of three words from 0x14 and from 0x44.
typedef struct Unk0217ad08_058_20 {
    /* 00 */ u8 mUnk_00[0x10];
    /* 10 */ s32 mUnk_10;
    /* 14 */ Vec3 mUnk_14[4];
    /* 44 */ Vec3 mUnk_44[1];
    /* 50 */ u8 mUnk_50[0x90];
} Unk0217ad08_058_20;

// 0xb8-byte entries from 0x58 of Unk0217ad08.
typedef struct Unk0217ad08_058 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ Unk0217ad08_058_08 *mUnk_08;
    /* 0c */ u8 mUnk_0c[4];
    /* 10 */ struct Unk02084b2c *mUnk_10;
    /* 14 */ struct Unk02084b2c *mUnk_14;
    /* 18 */ struct Unk02084b2c *mUnk_18;
    /* 1c */ struct Unk0207adf8 *mUnk_1c;
    /* 20 */ Unk0217ad08_058_20 *mUnk_20;
    /* 24 */ u8 mUnk_24[0x8c];
    /* b0 */ s32 mUnk_b0;
    /* b4 */ void *mUnk_b4;
} Unk0217ad08_058;

struct Unk020136f0;

// 0x34-byte entries from 0x1f4 of Unk0217ad08; the pointers at 0x08 to 0x28 are passed to func_02012b30.
typedef struct Unk0217ad08_1f4 {
    /* 00 */ void *mUnk_00;
    /* 04 */ struct Unk020176c0 *mUnk_04;
    /* 08 */ struct Unk020136f0 *mUnk_08;
    /* 0c */ struct Unk020136f0 *mUnk_0c;
    /* 10 */ struct Unk020136f0 *mUnk_10;
    /* 14 */ void *mUnk_14;
    /* 18 */ struct Unk020136f0 *mUnk_18;
    /* 1c */ struct Unk020136f0 *mUnk_1c;
    /* 20 */ struct Unk020136f0 *mUnk_20;
    /* 24 */ struct Unk020136f0 *mUnk_24;
    /* 28 */ struct Unk020136f0 *mUnk_28;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ u16 mUnk_30;
    /* 32 */ u8 mUnk_32[2];
} Unk0217ad08_1f4;

// Six halfwords; the 0xc-byte entries behind member 0x1c of Unk0217ad08.
typedef struct Unk0217ad08_01c {
    /* 00 */ u16 mUnk_00[6];
} Unk0217ad08_01c;

// Embedded in Unk0217ad08 at 0x24 (0x34 bytes).
typedef struct Unk0217ad08_024 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ u16 mUnk_14;
    /* 16 */ u16 mUnk_16;
    /* 18 */ s16 mUnk_18;
    /* 1a */ u16 mUnk_1a;
    /* 1c */ u8 mUnk_1c[0x10];
    /* 2c */ s32 mUnk_2c;
    /* 30 */ s32 mUnk_30;
} Unk0217ad08_024;

// Object behind data_0217ad08.
typedef struct Unk0217ad08 {
    /* 000 */ s32 mUnk_000;
    /* 004 */ s32 mUnk_004;
    /* 008 */ s32 mUnk_008;
    /* 00c */ s16 mUnk_00c[6];
    /* 018 */ s16 *mUnk_018;
    /* 01c */ Unk0217ad08_01c *mUnk_01c;
    /* 020 */ Unk0217ad08_058 *mUnk_020;
    /* 024 */ Unk0217ad08_024 mUnk_024;
    /* 058 */ Unk0217ad08_058 mUnk_058[2];
    /* 1c8 */ Unk0217ad08_058_20 *mUnk_1c8;
    /* 1cc */ struct Unk02084b2c *mUnk_1cc;
    /* 1d0 */ void *mUnk_1d0;
    /* 1d4 */ void *mUnk_1d4;
    /* 1d8 */ void *mUnk_1d8;
    /* 1dc */ s32 mUnk_1dc;
    /* 1e0 */ s32 mUnk_1e0;
    /* 1e4 */ s32 mUnk_1e4;
    /* 1e8 */ void *mUnk_1e8;
    /* 1ec */ void *mUnk_1ec;
    /* 1f0 */ s16 mUnk_1f0;
    /* 1f2 */ u8 mUnk_1f2[2];
    /* 1f4 */ Unk0217ad08_1f4 mUnk_1f4[2];
    /* 25c */ s32 mUnk_25c;
    /* 260 */ s32 mUnk_260;
    /* 264 */ s16 mUnk_264;
    /* 266 */ s16 mUnk_266;
    /* 268 */ void *mUnk_268;
} Unk0217ad08;

extern Unk0217ad08 *data_0217ad08;
extern u16 data_0217ad10;
extern char data_usa_0217ad14[];
extern s32 data_0217ad24;
extern u32 data_0217ad28;
extern s32 data_0217ad2c;
extern s32 data_0217ad30;
struct Unk0201ca6c;

// Two objects returned by func_0208b7bc.
typedef struct Unk0217ae84_10 {
    union {
        struct {
            /* 00 */ struct Unk0201ca6c *mUnk_00;
            /* 04 */ struct Unk0201ca6c *mUnk_04;
        };
        struct Unk0201ca6c *mUnk_00_a[2];
    };
} Unk0217ae84_10;

// 0x58-byte entries of the table behind data_0217ae84; the pointers at 0x0c and
// 0x20 to 0x30 hold objects returned by func_0208b7bc.
typedef struct Unk0217ae84 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04[2];
    /* 0c */ struct Unk0201ca6c *mUnk_0c;
    /* 10 */ Unk0217ae84_10 mUnk_10[2];
    union {
        struct {
            /* 20 */ struct Unk0201ca6c *mUnk_20;
            /* 24 */ struct Unk0201ca6c *mUnk_24;
        };
        struct Unk0201ca6c *mUnk_20_a[2];
    };
    /* 28 */ struct Unk0201ca6c *mUnk_28;
    /* 2c */ struct Unk0201ca6c *mUnk_2c;
    /* 30 */ struct Unk0201ca6c *mUnk_30;
    /* 34 */ Vec3 mUnk_34[2];
    /* 4c */ Unk02148038 mUnk_4c[2];
} Unk0217ae84;

extern Unk0217ae84 *data_0217ae84;
extern struct Unk0208fd8c_08 *data_0217ae34;
extern struct Unk0208fd8c_08 *data_0217ae38;
struct Unk02080b1c;
struct Unk020888b4;
struct Unk0208001c;
struct Unk0206bcb0;
extern const s32 *data_usa_0217ae38;
extern void (*data_usa_0217ae3c)(struct Unk02080b1c *p);
extern const s32 *data_usa_0217ae40;
extern void (*data_usa_0217ae44)(struct Unk020888b4 *p, struct Unk0208001c *q, struct Unk0206bcb0 *r);
extern const s32 *data_usa_0217ae48;
extern const s32 *data_usa_0217ae2c;
extern const s32 *data_usa_0217ae30;
extern const s32 *data_usa_0217ae34;
extern u16 data_0217ae6c;
extern u16 data_0217ae70;
extern struct Unk0201ca6c **data_0217ae74;
// Three objects per entry, 0xc bytes each.
typedef struct Unk0217ae7c {
    /* 00 */ struct Unk0201ca6c *mUnk_00[3];
} Unk0217ae7c;

extern Unk0217ae7c *data_0217ae7c;
extern u16 *data_0217ae8c;
extern s32 data_0217ae90;
extern struct Unk0201ca6c **data_0217ae94;
extern s32 data_0217ae98;

// Three doublewords, read by func_0208537c's callers: the first is replaced by the first times the second plus the
// third.
typedef Unk020f41c4_B Unk0217aebc_128;

// Entry of the eight 0xc-byte entries at 0xb0 of Unk0217aebc: a word, then the links of a list.
typedef struct Unk0217aebc_0b0 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u8 mUnk_04[8];
} Unk0217aebc_0b0;

// Entry of the 0xc-byte entries func_02085fd8 selects; data_0217aec0 points to one.
typedef struct Unk0217aec0 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
} Unk0217aec0;

// Object behind data_0217aebc, 0x144 bytes: word tables of eight entries, the eight
// 0xc-byte entries at 0xb0 passed to func_020174a4, and the list at 0x12c.
typedef struct Unk0217aebc {
    /* 000 */ s32 mUnk_000[8];
    /* 020 */ s32 mUnk_020[8];
    /* 040 */ s32 mUnk_040[8];
    /* 060 */ s32 mUnk_060[8];
    /* 080 */ s32 mUnk_080;
    /* 084 */ s32 mUnk_084;
    /* 088 */ s32 mUnk_088;
    /* 08c */ s32 mUnk_08c;
    /* 090 */ s32 mUnk_090[8];
    /* 0b0 */ Unk0217aebc_0b0 mUnk_0b0[8];
    /* 110 */ s32 mUnk_110;
    /* 114 */ s32 mUnk_114[2];
    /* 11c */ s32 mUnk_11c;
    /* 120 */ s32 mUnk_120;
    /* 124 */ s16 mUnk_124;
    /* 126 */ u8 mUnk_126[2];
    /* 128 */ Unk0217aebc_128 *mUnk_128;
    /* 12c */ Unk02017328 mUnk_12c;
    /* 138 */ s32 mUnk_138;
    /* 13c */ s16 mUnk_13c;
    /* 13e */ s16 mUnk_13e[3];
} Unk0217aebc;

extern Unk0217aebc *data_0217aebc;
extern Unk0217aec0 *data_0217aec0;
extern u8 *data_0217aec4;
extern u16 *data_0217aec8;
extern u8 *data_0217aecc;
extern Vec3 *data_0217aed8;
extern u16 *data_0217aed4;
extern s32 data_0217aedc;
extern Unk0214ad4c data_0217aee0;

struct Unk02086250;

// Object behind data_0217aed0, 0x194 bytes: tables of eight entries.
typedef struct Unk0217aed0 {
    /* 000 */ struct Unk02086250 *mUnk_000[8];
    /* 020 */ s32 mUnk_020;
    /* 024 */ s16 mUnk_024[8];
    /* 034 */ s16 mUnk_034[8];
    /* 044 */ u16 mUnk_044[8];
    /* 054 */ s32 mUnk_054[8];
    /* 074 */ u16 mUnk_074[8];
    /* 084 */ s16 mUnk_084[8];
    /* 094 */ u16 mUnk_094[8];
    /* 0a4 */ u32 mUnk_0a4[8];
    /* 0c4 */ struct Unk02086250 *mUnk_0c4[8];
    /* 0e4 */ s32 mUnk_0e4[8];
    /* 104 */ s32 mUnk_104[8];
    /* 124 */ u32 mUnk_124[8];
    /* 144 */ void *mUnk_144[8];
    /* 164 */ void *mUnk_164[8];
    /* 184 */ s32 mUnk_184;
    /* 188 */ void *mUnk_188;
    /* 18c */ u8 mUnk_18c[8];
} Unk0217aed0;

extern Unk0217aed0 *data_0217aed0;
extern const char *data_0217af24;
extern char data_0217af28[];

// Entries of the 0x400-byte buffer behind member 0x04 of Unk0217aa04.
typedef struct Unk0217aa04_04 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ union {
        u32 mUnk_04;
        u16 mUnk_04_h;
    };
} Unk0217aa04_04;

// Object behind data_0217aa04.
typedef struct Unk0217aa04 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ Unk0217aa04_04 *mUnk_04;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u8 mUnk_0a;
    /* 0b */ u8 mUnk_0b[0x1];
    /* 0c */ s32 mUnk_0c;
} Unk0217aa04;

extern Unk0217aa04 *data_0217aa04;
// Object behind data_0217aa20, 0x10 bytes.
typedef struct Unk0217aa20 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s16 mUnk_08;
    /* 0a */ u8 mUnk_0a[2];
    /* 0c */ void *mUnk_0c;
} Unk0217aa20;

// 0xc-byte entries of the array behind member 0x00 of Unk0217aa24.
typedef struct Unk0217aa24_00 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02[2];
    /* 04 */ s32 mUnk_04;
    /* 08 */ u8 mUnk_08;
    /* 09 */ u8 mUnk_09;
    /* 0a */ u8 mUnk_0a[2];
} Unk0217aa24_00;

// Object behind data_0217aa24, 8 bytes.
typedef struct Unk0217aa24 {
    /* 00 */ Unk0217aa24_00 *mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[2];
} Unk0217aa24;

extern Unk0217aa20 *data_0217aa20;
extern Unk0217aa24 *data_0217aa24;
extern u16 data_0217aa2c;
extern s32 data_0217acac;

// Ten bytes: bytes 6 to 9 are signed values read in rows of four.
typedef struct Unk0217aa18 {
    /* 00 */ s8 mUnk_00[4];
    /* 04 */ u8 mUnk_04;
    /* 05 */ u8 mUnk_05;
    /* 06 */ s8 mUnk_06[4];
} Unk0217aa18;

extern Unk0217aa18 *data_0217aa18;
// 0xa-byte elements of the rows (eight each) of the table at member 0 of Unk0217aa1c.
typedef struct Unk0217aa1c_00 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
    /* 04 */ u8 mUnk_04;
    /* 05 */ u8 mUnk_05;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u8 mUnk_08;
    /* 09 */ u8 mUnk_09;
} Unk0217aa1c_00;

// 4-byte object, two of which make an element of the table at member 0x144 of Unk0217aa1c.
typedef struct Unk0217aa1c_144_00 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02;
    /* 03 */ union {
        u8 mUnk_03;
        struct {
            u8 mUnk_03_0 : 1;
        };
    };
} Unk0217aa1c_144_00;

// 8-byte elements of the table at member 0x144 of Unk0217aa1c.
typedef struct Unk0217aa1c_144 {
    /* 00 */ Unk0217aa1c_144_00 mUnk_00[2];
} Unk0217aa1c_144;

// Object behind data_0217aa1c.
typedef struct Unk0217aa1c {
    /* 000 */ Unk0217aa1c_00 mUnk_000[4][8];
    /* 140 */ s32 mUnk_140;
    /* 144 */ Unk0217aa1c_144 mUnk_144[4];
    /* 164 */ union {
        u32 mUnk_164;
        struct {
            u32 mUnk_164_0 : 1;
        };
    };
} Unk0217aa1c;

extern Unk0217aa1c *data_0217aa1c;
extern struct Unk0206bcb0 *data_0217ad18;
extern Unk02017328 data_0217aeb0;
struct Unk0206cdd4_B;
extern struct Unk0206cdd4_B *data_usa_0217acfc;

extern Unk02061808 *data_usa_0217ac84;
extern Unk02061808 *data_usa_0217ac98;
extern void *data_usa_0217aa68;
extern s32 data_usa_0217ac7c;
extern s32 data_usa_0217ac90;
extern s32 data_usa_0217ac78;
extern s32 data_usa_0217ac90;
extern u16 data_usa_0217ac70;
