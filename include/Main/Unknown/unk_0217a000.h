#pragma once

#include "types.h"
#include "Main/Unknown/code_020d22c0.h" // Unk020f41c4_B
#include "code_02004dc0.h" // Unk020055f0, FSFile
#include "code_0212d214.h"
#include "code_0200db4c.h"
#include "code_02142eac.h" // Unk021438f0, Unk02143a78, Unk02143c30
#include "code_021445e0.h" // Unk021450ec, Unk0214461c
#include "code_02147cd8.h" // Vec3s16
#include "code_0214a748.h" // Unk0214ad4c
#include "code_02012b30.h" // MtxFx43
#include "Main/Unknown/code_02006954.h"
#include "Main/Unknown/code_0207b960.h" // PosCurve
#include "Main/Unknown/code_0207adf8.h" // Unk0207adf8
#include "Main/Unknown/code_020846c0.h" // Nsbmd
#include "Main/Unknown/code_02087d0c.h" // Unk02087d0c
#include "code_02003024.h"

// Values of Unk0217aa08_00.mSoundMode.
typedef enum { SOUND_MODE_SURROUND, SOUND_MODE_STEREO, SOUND_MODE_HEADPHONES } SoundMode;

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
            u8 mSoundMode : 2;
            u8 mUnk_31_3 : 1;
            u8 mLocateFriendOff : 1;
            u8 mUnk_31_5 : 3;
        };
    };
    /* 32 */ u8 mUnk_32[0x2];
    /* 34 */ u32 mUnk_34[6];
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

// One buddy: counts per kind of match, the date of the last result, the name and four flags; 60 entries from 0x04 of
// BuddyRecordBlock.
typedef struct BuddyRecord {
// Two counters for each of three kinds of match (VS, Battle and a third kind), each raised by one at the end of a
// race.
    /* 00 */ u16 mResultCounts[3][2];
    /* 0c */ union {
        u16 mDate;
        struct {
            u16 mYear : 7;
            u16 mMonth : 4;
            u16 mDay : 5;
        };
    };
    /* 0e */ u8 mName[0x14];
    /* 22 */ union {
        u8 mUnk_22;
        struct {
            u8 mFilled : 1;
// Set when the buddy was added by friend key; cleared once the library reports a buddy.
            u8 mNotYetBuddy : 1;
            u8 mUnk_22_2 : 1;
            u8 mFlagged : 1;
        };
    };
    /* 23 */ u8 mUnk_23;
} BuddyRecord;

// 60 BuddyRecord entries from 0x04, then the 60 buddy friend data of 0xc bytes each from 0x874.
typedef struct BuddyRecordBlock {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ BuddyRecord mRecords[1];
} BuddyRecordBlock;

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
    /* 14 */ Unk0217aa08_14 *mUnk_14[3];
    /* 20 */ BuddyRecordBlock *mBuddyRecordBlock;
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
    /* 798 */ BOOL mUnk_798;
    /* 79c */ BOOL mUnk_79c;
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
    /* 0034 */ void *mUnk_0034;
    /* 0038 */ s32 mUnk_0038;
    /* 003c */ void *mUnk_003c;
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
            /* 1d04 */ void *mHeap;
            /* 1d08 */ u16 mUnk_1d08;
            /* 1d0a */ u16 mUnk_1d0a;
            /* 1d0c */ FSFile mUnk_1d0c;
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
            /* 1e30 */ u8 *mUnk_1e30;
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
// Object behind data_0217aa0c; the OSThread at 0x2c is passed to OS_CreateThread and OS_WakeupThreadDirect.
typedef struct Unk0217aa0c {
    /* 00 */ void (*mUnk_00[10])(void);
    /* 28 */ u8 mUnk_28;
    /* 29 */ u8 mUnk_29[3];
    /* 2c */ OSThread mUnk_2c;
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

struct NNSiFndHeapHead;

// Object behind data_0217aa10; UpdateWiFiSession reads the word at 0. The objects at 0x2c and 0x58 are passed to
// FS_StartOverlay and FS_InitFile, the pointer at 0xa4 to NNS_FndDestroyExpHeap.
typedef struct Unk0217aa10 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ Unk0217aa10_08 mUnk_08[3];
    /* 2c */ Unk020055f0 mUnk_2c;
    /* 58 */ FSFile mUnk_58;
    /* a0 */ struct NNSiFndHeapHead *mUnk_a0;
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
    /* 30 */ BOOL mUnk_30;
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
    /* 10 */ s32 mUnk_10;
    /* 14 */ u16 mUnk_14;
    /* 16 */ u8 mUnk_16[0xa];
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
    /* 6e4 */ u8 mUnk_6e4[16][4];
    /* 724 */ u16 mUnk_724;
    /* 726 */ u8 mUnk_726[0x2];
    /* 728 */ s32 mUnk_728;
    /* 72c */ BOOL mUnk_72c;
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
// Per-run state of the race scene, one record behind gRace (0x48 bytes, allocated by InitRace on the scene heap and
// never cleared at the end of the scene): frame counters (mUpdateFrames and three phases derived from it), toon-table
// cycle, fog/fade switch, kind flags derived from gRaceSetup->mUnk_00c (also live in the demo and credits kinds 3 to
// 6), a light vector. Not the race setup (gRaceSetup), not the karts.
typedef struct Race {
    // 1 once the race has started, else 0: StartRace sets it when UpdateRaceStartSequence reaches its frame 180, and
    // InitRace sets it at once for the kinds 5 and 6 of RaceSetup.mUnk_00c, which have no countdown; IsRaceStarted
    // returns it.
    /* 00 */ s16 mStarted;
    /* 02 */ u8 mUnk_02[2];
    // Counts calls of UpdateRace; in mode 5 held at 128 until mUpdateFramesUnlimited is set (func_020617f0).
    /* 04 */ s32 mUpdateFrames;
    // Counts calls of DrawRace; never read (2 writes, 0 reads).
    /* 08 */ s32 mDrawFrames;
    // Value of mUpdateFrames modulo 8 (its low three bits) as of the end of the latest UpdateRace, 0 at set-up; kart
    // and map object code compare it with an index or a limit to act on one frame out of eight.
    /* 0c */ s32 mUpdateFramesMod8;
    // Value of mUpdateFrames modulo 2 as of the end of the latest UpdateRace, 0 at set-up; compared with 0 or with a
    // bit of the object's own flags to act on every second frame.
    /* 10 */ s32 mUpdateFramesMod2;
    // Value of mUpdateFrames modulo RaceSetup.mKartCount as of the end of the latest UpdateRace, 0 at set-up; its one
    // reader uses it as a kart index.
    /* 14 */ s32 mUpdateFramesModKartCount;
    // Start index (0 to 7) of the 32 entries of data_0217aadc that UpdateRace gives to G3X_SetToonTable on each call;
    // it advances by 1 each time mToonTableFrames passes data_021653ec and wraps back to 0 after 7.
    /* 18 */ s32 mToonTableOffset;
    // Counts calls of UpdateRace since mToonTableOffset last changed; when it exceeds data_021653ec (2) it restarts at
    // 0 and mToonTableOffset advances (every third call).
    /* 1c */ s32 mToonTableFrames;
    // 1 from the start of a fog fade (func_02061874) until UpdateRace ends it, else 0: while it is 1 DrawRace writes
    // the fade fog into the fog registers instead of the course fog. UpdateRace holds it for 72 calls, then steps
    // data_021653e8 from 72 down to 0 in steps of 4 and clears it. DrawRace compares it with mDrawnFadeFog.
    /* 20 */ s32 mFadeFog;
    // The value of mFadeFog that DrawRace last handled; DrawRace writes the fog registers when it differs from
    // mFadeFog, then copies mFadeFog here. func_02061874 sets it to 0 when it is 1 so that the next DrawRace writes the
    // registers again.
    /* 24 */ s32 mDrawnFadeFog;
    // 1 when RaceSetup.mUnk_00c is 3, 4 or 5, else 0. While it is 1, InitRace creates the chain cameras, UpdateRace
    // updates them and takes their view, and DrawRace skips the draw call of func_02086250. The other readers go
    // through GetRaceUseChainCameras and use it to tell these kinds apart (map objects, balloons, effects, kart
    // set-up).
    /* 28 */ s32 mUseChainCameras;
    // 1 when RaceSetup.mUnk_00c is 4: only the first chain camera is created and updated instead of the pair (read
    // only while mUseChainCameras is non-zero).
    /* 2c */ s32 mUseFirstChainCamera;
    // Mode 5 only: set by UpdateRace when mUpdateFrames reaches 128 while mUpdateFramesUnlimited is FALSE; from then on
    // mUpdateFrames stays put until mUpdateFramesUnlimited is set. Never cleared again.
    /* 30 */ BOOL mUpdateFramesLimitReached;
    // Mode 5 only: FALSE at set-up, set by func_020617f0 (called by UpdateRaceStartSequence when it begins counting);
    // once set, UpdateRace counts mUpdateFrames on every call with no stop at 128.
    /* 34 */ BOOL mUpdateFramesUnlimited;
    /* 38 */ s32 mUnk_38;
    // Value of mUpdateFrames when the end handler of the kart of the selected entry (RaceSetup.mEntryIndex) first
    // ran, stored by SetRaceUpdateFramesAtEntryEnd (in mission run mode that is after the end wait); 0 until then.
    /* 3c */ s32 mUpdateFramesAtEntryEnd;
    // x component of the direction of light 0, the vector func_02062078 gives to NNS_G3dGlbLightVector; set at InitRace
    // from data_021653f0 and by SetRaceLightVector.
    /* 40 */ s16 mLightVectorX;
    // y component of the direction of light 0, the vector func_02062078 gives to NNS_G3dGlbLightVector; set at InitRace
    // from data_021653f0 and by SetRaceLightVector.
    /* 42 */ s16 mLightVectorY;
    // z component of the direction of light 0, the vector func_02062078 gives to NNS_G3dGlbLightVector; set at InitRace
    // from data_021653f0 and by SetRaceLightVector.
    /* 44 */ s16 mLightVectorZ;
} Race;

extern Race *gRace;
extern s32 data_0217aa64;
struct Unk02077750;

// The viewer of a race: position, look-at point, three axes, view matrix and frustum. One class, several instances:
// gChaseCamera follows the selected kart, gEntryCamera and gFirstChainCamera / gSecondChainCamera step through
// CourseMapCamera entries; data_0217aa6c points at the one used this frame.
typedef struct Camera {
    /* 000 */ Vec3 mUp;
    // baseUp x forward, perpendicular to mUp and mForward. Sign not fixed (left or right is not shown); not updated
    // by UpdateCameraViewWithWorldUp.
    /* 00c */ Vec3 mSide;
    /* 018 */ Vec3 mLookAt;
    /* 024 */ Vec3 mPos;
    /* 030 */ MtxFx43 mViewMatrix;
    // Half of the vertical field of view, 0x10000 per turn (top = near * tan). The chase camera eases it toward
    // mHalfFovAngleGoal; entry cameras set the pair mHalfFovPairFirst / mHalfFovPairSecond (sin and cos of the angle)
    // directly.
    /* 060 */ s32 mHalfFovAngle;
    // Default data_0216569c (0x157c, about 30 degrees).
    /* 064 */ s32 mHalfFovAngleGoal;
    // First and second element of the pair gPairsByAngle holds for mHalfFovAngle; mFrustumTop = mNear * first / second.
    /* 068 */ s16 mHalfFovPairFirst;
    /* 06a */ s16 mHalfFovPairSecond;
    /* 06c */ s32 mAspectRatio;
    /* 070 */ s32 mNear;
    // Far plane of the main projection (course settings value, default 0x640000); mUnk_08c is a second far value.
    /* 074 */ s32 mFar;
    // The four extents handed to G3i_FrustumW_ (top, bottom, left, right), 20.12; shifted by mFrustumShift
    // and a kind-6 entry offset, left and right swapped in mirror mode.
    /* 078 */ s32 mFrustumTop;
    /* 07c */ s32 mFrustumBottom;
    /* 080 */ s32 mFrustumLeft;
    /* 084 */ s32 mFrustumRight;
    // Fraction of the Kart's last-frame movement (mPos - mPrevPos) added to the camera position while Kart bit 0x1000
    // of mUnk_48 is set; 0x1000 when the camera is placed, times 0xe66/0x1000 per use.
    /* 088 */ s32 mKartMoveScale;
    /* 08c */ s32 mUnk_08c;
    /* 090 */ Vec3 mViewLookAt;
    /* 09c */ Vec3 mViewPos;
    /* 0a8 */ Vec3 mUnk_0a8;
    /* 0b4 */ Vec3 mUnk_0b4;
    // The up vector mUp is built from: eased toward world up (or a kart vector); mUp is made perpendicular to
    // mForward from it.
    /* 0c0 */ Vec3 mBaseUp;
    /* 0cc */ s32 mHeldHeight;
    // Set once the kart is above mHeldHeight; then mHeldHeight eases toward the free y.
    /* 0d0 */ BOOL mHeldHeightEasing;
    /* 0d4 */ s32 mLookAtHeight;
    /* 0d8 */ s32 mUnk_0d8;
    /* 0dc */ s32 mFollowDistance;
    /* 0e0 */ s32 mUnk_0e0;
    // Amount the look-at is lowered: +0x1000 per call up to 0xa000 while the Kart has bit 0x10000 of mUnk_48, else
    // decays; subtracted from the look-at goal y (UpdateChaseCameraLookAt).
    /* 0e4 */ s32 mLookAtLowering;
    /* 0e8 */ s32 mFollowDistanceScale;
    /* 0ec */ s32 mUnk_0ec;
    // 0x1000, or -0x1000 in mode 4 with flag 0x20 of gRaceSetup->mUnk_044.
    /* 0f0 */ s32 mFollowDirectionSign;
    /* 0f4 */ Vec3 mShakeLookAtOffsetGoal;
    /* 100 */ Vec3 mShakePosOffsetGoal;
    /* 10c */ Vec3 mShakeLookAtOffset;
    /* 118 */ Vec3 mShakePosOffset;
    // Third look-at shake term: adds -mShakeLookAtOffset times a per-kind factor (1.25 / 2 / 2.75), halved each call;
    // added to the look-at in UpdateCameraView.
    /* 124 */ Vec3 mShakeLookAtCounterOffset;
    /* 130 */ u8 mShakeKind;
    /* 131 */ u8 mUnk_131[0x3];
    // mPos of the previous frame; the chase step keeps it while a collision push is active.
    /* 134 */ Vec3 mPrevPos;
    // Set by StartCameraWobble, cleared by UpdateCameraWobble when the amplitude is used up.
    /* 140 */ BOOL mWobbling;
    /* 144 */ s32 mUnk_144;
    /* 148 */ s32 mWobbleAmplitude;
    // Added to mUnk_144 each frame, times mWobbleDirection.
    /* 14c */ s32 mWobblePerFrame;
    /* 150 */ s16 mWobbleDirection;
    /* 152 */ u8 mUnk_152[0x2];
    /* 154 */ s32 mWobbleDecay;
    /* 158 */ s32 mWobbleOffset;
    /* 15c */ Vec3 mForward;
    // Added to the y of the position goal; eased toward a value taken from the Kart's heading y while Kart bit 0x10 of
    // mUnk_44 or 0x10000 of mUnk_48 is set.
    /* 168 */ s32 mPosGoalYOffset;
    // Eased toward 0, or toward +-0x19000 (sign of Kart.mTurnDirection) while Kart bit 8 of mUnk_44 is set.
    /* 16c */ s32 mPosGoalKartOffsetScale;
    // Length of the push-out vector while the push is in state 1 of mUnk_254, else 0; mCollisionOffsetLength eases
    // toward it.
    /* 170 */ s32 mCollisionOffsetLengthGoal;
    // Eased mCollisionOffsetLengthGoal; times 3 it shortens the follow distance and raises the position goal
    // (UpdateChaseCameraPos).
    /* 174 */ s32 mCollisionOffsetLength;
    // Added to the eye height of the view only, not to the look-at.
    /* 178 */ s32 mViewPosYOffset;
    // The push-out vector of the collision test (func_01ffdee4) scaled by 3 to 8, kept and eased; added to the position
    // goal.
    /* 17c */ Vec3 mPosGoalCollisionOffset;
    // Kart.mUnk_120 (a row of the Kart's matrix) times mPosGoalKartOffsetScale; added to the position goal.
    /* 188 */ Vec3 mPosGoalKartOffset;
    /* 194 */ PosCurve mPosCurve;
    /* 1d0 */ PosCurve mUnk_1d0;
    /* 20c */ u16 mUnk_20c;
    /* 20e */ u16 mUnk_20e;
    // Index into gKarts the look-at is taken from (entry cameras; the chase camera is handed its Kart).
    /* 210 */ u16 mFollowedKartIndex;
    /* 212 */ u8 mUnk_212[0x2];
    // Index GetCourseMapCameraIndexAtPos last returned for the followed kart; mCourseMapCamera is the entry actually in
    // use.
    /* 214 */ s32 mLastCourseMapCameraIndex;
    /* 218 */ struct CourseMapCamera *mCourseMapCamera;
    /* 21c */ struct Unk02077750 *mUnk_21c;
    /* 220 */ struct Unk02077750 *mUnk_220;
    /* 224 */ u16 mUnk_224;
    /* 226 */ u8 mUnk_226[0x2];
    // TRUE from StartEntryCameraKind6Entry until mKind6EntryFrames reaches 300 (outside mode 2) or func_02075d08
    // replaces the entry. While TRUE the entry is not replaced by the one picked from the Kart's position; in mode 2
    // TryUpdateEntryCamera steps the entry by its kind on every call and only func_02075d08 clears it.
    /* 228 */ BOOL mKind6EntryRunning;
    // Counts the calls of TryUpdateEntryCamera outside mode 2 while mKind6EntryRunning is TRUE; at 300 it clears
    // mKind6EntryRunning. Only SetupCamera zeroes it, so it carries over a restart.
    /* 22c */ u16 mKind6EntryFrames;
    /* 22e */ u8 mUnk_22e[0x2];
    // Set to 1 by func_02075d08(1), which only does so while the current entry is of kind 5 or 6, and to 0 by
    // func_02075d08(0) and SetupCamera. While non-zero TryUpdateEntryCamera returns FALSE at once, so the chase camera
    // is shown.
    /* 230 */ s32 mEntryUpdateHold;
    // Set to 1 once by DisableEntryCameraUpdate and never cleared (SetupCamera zeroes it). While set
    // TryUpdateEntryCamera returns FALSE at once, so the chase camera is shown.
    /* 234 */ BOOL mEntryUpdateDisabled;
    // Set to TRUE by StartEntryCameraKind8Entry and never cleared (SetupCamera zeroes it). While set, and after the
    // mEntryUpdateHold and mEntryUpdateDisabled tests, TryUpdateEntryCamera runs UpdateCameraAngleEntry on the current
    // entry and returns TRUE.
    /* 238 */ BOOL mKind8EntryRunning;
    /* 23c */ u16 mCourseMapCameraFrames;
    /* 23e */ u8 mUnk_23e[0x2];
    /* 240 */ s32 mFovBlend;
    /* 244 */ s32 mLookAtBlend;
    // Non-zero while the position y is held at mHeldHeight (set by SetCameraHeightHold for kart state 6).
    /* 248 */ s32 mHeightHold;
    // 0 none; 1 and 2 (gFirstChainCamera / gSecondChainCamera while the entry is kind 4) shift the window of
    // mFrustumTop and mFrustumBottom up or down by 1.3 of its half height (RefreshCameraProjection).
    /* 24c */ s32 mFrustumShift;
    // Which camera this instance is: 0 chase, 1 entry camera, 2 chain camera, 3 entry camera in mode 2 with a kind 7
    // entry; tested by outside code (func_02061818).
    /* 250 */ s32 mKind;
    /* 254 */ s32 mUnk_254;
    /* 258 */ BOOL mUnk_258;
    /* 25c */ BOOL mUnk_25c;
    // GetKartForward (row 2 of the Kart's matrix, taken as its heading) of the selected Kart at creation; used instead
    // of the live vector for a Kart with bit 0x20000000 of mUnk_4c. SetupCamera zeroes it.
    /* 260 */ Vec3 mSavedKartForward;
    /* 26c */ s16 mSideDistanceSign;
    /* 26e */ u8 mUnk_26e[0x2];
} Camera;

extern Camera *data_0217aa6c;
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
extern Camera *data_0217aa5c;
extern s32 data_0217aa60;
extern s32 data_0217aa68;
extern s32 data_0217aa70;
extern void *data_0217aa74;
extern s32 data_0217aa78;
extern s32 data_0217aa80;
extern s32 data_0217aa84;
extern Camera *data_0217aa88;
extern u32 data_0217aa8c[4];
extern u32 data_0217aa9c[8];
extern u32 data_0217aabc[8];
extern u16 data_0217aadc[32];
extern MtxFx43 *data_0217aa7c;
extern u32 data_0217ac10;
extern void *data_0217ac14;
extern void *data_0217ac18[15];
extern void *data_0217ac54[15];
extern struct Camera *gChaseCamera;
// Set to 1 at race set-up and when a camera entry is started or advanced; cleared once per UpdateRace call by
// ClearCameraEntryFlags. UpdateRace calls func_020d50c4 when it is set.
extern s32 gCameraEntryChanged;
// The chain camera whose view matrix the last chain step returned; UpdateRace stores it as the camera in use. Not
// written in races without chain cameras.
extern Camera *gCurrentChainCamera;
// The Camera that picks its CourseMapCamera entry from the position of the followed Kart (GetCourseMapCameraIndexAtPos)
// and is stepped by TryUpdateEntryCamera. mKind is 1, or 3 in mode 2 when CourseMap.mFirstKind7EntryInMode2 is set. The
// Kart code starts its kind 6 and kind 8 entries (StartEntryCameraKind6Entry, StartEntryCameraKind8Entry). The chain
// cameras also run entries but never pick by position.
extern Camera *gEntryCamera;
extern u8 data_0217acc0[];
// 0x20-byte entries behind member 0x014 of KartModels.
typedef struct Unk0217ad00_014 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[0x1a];
} Unk0217ad00_014;

// Object behind gKartModels (0x144 bytes); the addresses of 0x2c, 0x98 and 0x10c are passed on as objects.
struct KartModelsEntry;

typedef struct KartModels {
    // Array of the per-kart model entries (0xb4 bytes each), allocated by InitKartModels with mKartCount elements;
    // Kart.mKartModelsEntry points into it.
    /* 000 */ struct KartModelsEntry *mKartModelsEntries;
    /* 004 */ u16 *mUnk_004;
    // Number of elements of mKartModelsEntries, copied from gRaceSetup->mKartCount; the loop bound over the
    // entries.
    /* 008 */ u16 mKartCount;
    /* 00a */ u8 mUnk_00a[2];
    /* 00c */ s32 mKartTireMaterialIndex;
    /* 010 */ u16 *mUnk_010;
    /* 014 */ Unk0217ad00_014 *mUnk_014;
    /* 018 */ s16 mUnk_018[8];
    /* 028 */ void *mUnk_028;
    /* 02c */ Nsbmd mUnk_02c;
    /* 098 */ Unk0207adf8 mUnk_098;
    /* 10c */ Unk02087d0c mUnk_10c;
} KartModels;

extern KartModels *gKartModels;

// Object behind member 0x08 of an KartModelMenuSlot (0x38 bytes); only the words below are read.
typedef struct Unk0217ad08_058_08 {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ s32 mUnk_0c;
    /* 10 */ u8 mUnk_10[0xa];
    /* 1a */ u16 mUnk_1a;
    /* 1c */ s32 **mUnk_1c;
} Unk0217ad08_058_08;

// Object behind member 0x20 of an KartModelMenuSlot: a word at 0x10 and rows of three words from 0x14 and from 0x44.
typedef struct Unk0217ad08_058_20 {
    /* 00 */ u8 mUnk_00[0x10];
    /* 10 */ s32 mUnk_10;
    /* 14 */ Vec3 mUnk_14[4];
    /* 44 */ Vec3 mUnk_44[1];
    /* 50 */ u8 mUnk_50[0x90];
} Unk0217ad08_058_20;

// 0xb8-byte entries from 0x58 of KartModelMenuData.
typedef struct KartModelMenuSlot {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ Unk0217ad08_058_08 *mCharacterAnimation;
    /* 0c */ u8 mUnk_0c[4];
    /* 10 */ struct Nsbmd *mUnk_10;
    /* 14 */ struct Nsbmd *mUnk_14;
    /* 18 */ struct Nsbmd *mUnk_18;
    /* 1c */ struct Unk0207adf8 *mUnk_1c;
    /* 20 */ Unk0217ad08_058_20 *mUnk_20;
    /* 24 */ u8 mUnk_24[0x8c];
    /* b0 */ s32 mUnk_b0;
    /* b4 */ struct NNSG3dResTex *mEmblemTex;
} KartModelMenuSlot;

struct NNSG3dResFileHeader;

// 0x34-byte entries from 0x1f4 of KartModelMenuData; the pointers at 0x08 to 0x28 are passed to
// NNS_G3dResDefaultRelease.
typedef struct KartModelMenuFiles {
    /* 00 */ void *mHeapMemory;
    /* 04 */ struct NNSiFndHeapHead *mHeap;
    /* 08 */ struct NNSG3dResFileHeader *mUnk_08;
    /* 0c */ struct NNSG3dResFileHeader *mUnk_0c;
    /* 10 */ struct NNSG3dResFileHeader *mUnk_10;
    /* 14 */ void *mUnk_14;
    /* 18 */ struct NNSG3dResFileHeader *mUnk_18;
    /* 1c */ struct NNSG3dResFileHeader *mUnk_1c;
    /* 20 */ struct NNSG3dResFileHeader *mUnk_20;
    /* 24 */ struct NNSG3dResFileHeader *mUnk_24;
    /* 28 */ struct NNSG3dResFileHeader *mUnk_28;
    /* 2c */ BOOL mLoadRequested;
    /* 30 */ u16 mLoadStep;
    /* 32 */ u8 mUnk_32[2];
} KartModelMenuFiles;

// Six halfwords; the 0xc-byte entries behind member 0x1c of KartModelMenuData.
typedef struct Unk0217ad08_01c {
    /* 00 */ u16 mUnk_00[6];
} Unk0217ad08_01c;

// Embedded in KartModelMenuData at 0x24 (0x34 bytes).
typedef struct KartModelMenuView {
    /* 00 */ s32 mCharacterIndex;
    /* 04 */ s32 mKartIndex;
    /* 08 */ s32 mScale;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ u16 mSpinAngle;
    /* 16 */ u16 mYawAngle;
    /* 18 */ s16 mUnk_18;
    /* 1a */ u16 mUnk_1a;
    /* 1c */ u8 mUnk_1c[0x10];
    /* 2c */ s32 mBg0Offset;
    /* 30 */ s32 mBg0Direction;
} KartModelMenuView;

// Object behind gKartModelMenu.
typedef struct KartModelMenuData {
    /* 000 */ s32 mKartIndex;
    /* 004 */ s32 mKartListPos;
    /* 008 */ s32 mKartListCount;
    /* 00c */ s16 mMenuParams[6];
    /* 018 */ s16 *mCharMenuParams;
    /* 01c */ Unk0217ad08_01c *mKartMenuParams;
    /* 020 */ KartModelMenuSlot *mLoadSlot;
    /* 024 */ KartModelMenuView mView;
    /* 058 */ KartModelMenuSlot mSlots[2];
    /* 1c8 */ Unk0217ad08_058_20 *mUnk_1c8;
    /* 1cc */ struct Nsbmd *mSelectModel;
    /* 1d0 */ void *mUnk_1d0;
    /* 1d4 */ void *mEmblemTex;
    /* 1d8 */ s32 mUnk_1d8;
    /* 1dc */ BOOL mUnk_1dc;
    /* 1e0 */ BOOL mUseEmblemTex;
    /* 1e4 */ s32 mMirrorMode;
    /* 1e8 */ void *mEmblemData;
    /* 1ec */ void *mEmblemPalette;
    /* 1f0 */ s16 mUnk_1f0;
    /* 1f2 */ u8 mUnk_1f2[2];
    /* 1f4 */ KartModelMenuFiles mFiles[2];
    /* 25c */ s32 mCharacterRequested;
    /* 260 */ s32 mKartRequested;
    /* 264 */ s16 mShownSlotIndex;
    /* 266 */ s16 mLoadSlotIndex;
    /* 268 */ struct Unk0205fd2c *mUnk_268;
} KartModelMenuData;

extern KartModelMenuData *gKartModelMenu;
extern u16 gKillerItemKartIndex;
extern char gCharacterNsbcaPathBuffer[];
// 1 when this is a mission run and the course has a shape of kind 2, else 0; set by InitKarts.
extern s32 gMissionRunKind2ShapesPresent;
extern u32 gKartKind3ShapeMask;
extern s32 gKartSpeedLimitReciprocal;
extern s32 gKartForwardSpeedRatio;
struct Unk0201ca6c;

// Two objects returned by StartEffect.
typedef struct KartEffectPair {
    union {
        struct {
            /* 00 */ struct Unk0201ca6c *mEffect0;
            /* 04 */ struct Unk0201ca6c *mEffect1;
        };
        struct Unk0201ca6c *mUnk_00_a[2];
    };
} KartEffectPair;

// Effect objects of one Kart: the current effect with its id, and further effect objects with the points they are
// placed at. One record per Kart in gKartEffects, indexed by Kart.mIndex. 0x58-byte entries of the table behind
// gKartEffects; the pointers at 0x0c and 0x20 to 0x30 hold objects returned by StartEffect.
typedef struct KartEffects {
    // Id of the effect in mCurrentEffect, -1 when there is none.
    /* 00 */ s32 mCurrentEffectId;
    // Id of the effect running in entry i of mEffectPairs, -1 when there is none; compared with the wanted id to decide
    // whether to start again.
    /* 04 */ s32 mEffectIds[2];
    // The effect object of this Kart started by StartKartCurrentEffect, whose id is mCurrentEffectId (NULL when none).
    /* 0c */ struct Unk0201ca6c *mCurrentEffect;
    // The effect objects started for mEffectIds: entry i holds the object of side 0 and the object of side 1 (the byte
    // set in each object is the side number); ids in mEffectIds.
    /* 10 */ KartEffectPair mEffectPairs[2];
    union {
        struct {
            /* 20 */ struct Unk0201ca6c *mWaterEffect0;
            /* 24 */ struct Unk0201ca6c *mWaterEffect1;
        };
        struct Unk0201ca6c *mUnk_20_a[2];
    };
    /* 28 */ struct Unk0201ca6c *mUnk_28;
    /* 2c */ struct Unk0201ca6c *mKillerEffect;
    /* 30 */ struct Unk0201ca6c *mUnk_30;
    // Position in effect units (position / 16) of each side of the Kart: model point 2 or 3 moved by the x offset
    // 0x1800 or -0x1800 of gKartSideOffsetsX, scaled by the Kart scale and transformed by the Kart matrix; written only
    // by ComputeKartSidePoints.
    /* 34 */ Vec3 mSidePositions[2];
    // Direction vector (halfwords) of the effect on each side of the Kart: the vector of gKartSideDirectionVectors for
    // that side rotated by the Kart matrix; written only by ComputeKartSidePoints and read as the direction of the
    // effect object.
    /* 4c */ Vec3s16 mSideDirections[2];
} KartEffects;

// Per-Kart effect records, allocated for every Kart by InitKartEffects and indexed by Kart.mIndex.
extern KartEffects *gKartEffects;
extern struct Unk0208fd8c_08 *data_0217ae34;
extern struct Unk0208fd8c_08 *data_0217ae38;
struct Unk02080b1c;
struct KartAi;
struct LinkCursor;
struct Kart;
extern const s32 *data_usa_0217ae38;
extern void (*data_usa_0217ae3c)(struct Unk02080b1c *p);
extern const s32 *data_usa_0217ae40;
extern void (*data_usa_0217ae44)(struct KartAi *p, struct LinkCursor *q, struct Kart *r);
extern const s32 *data_usa_0217ae48;
extern const s32 *data_usa_0217ae2c;
extern const s32 *data_usa_0217ae30;
extern const s32 *data_usa_0217ae34;
extern u16 data_0217ae6c;
extern u16 data_0217ae70;
extern struct Unk0201ca6c **data_0217ae74;
// Three objects per entry, 0xc bytes each.
typedef struct KartStarEffects {
    /* 00 */ struct Unk0201ca6c *mEffects[3];
} KartStarEffects;

extern KartStarEffects *gKartStarEffects;
extern u16 *gKartEffectIdSetIndex;
extern s32 gOtherKartOddCount;
extern struct Unk0201ca6c **data_0217ae94;
extern s32 gOtherKartFullPairCount;

// Three doublewords (a random generator): the first is replaced by the first times the second plus the third.
typedef Unk020f41c4_B Unk0217aebc_128;

// Entry of the eight 0xc-byte entries at 0xb0 of KartAiShared: a word, then the links of a list.
typedef struct Unk0217aebc_0b0 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u8 mUnk_04[8];
} Unk0217aebc_0b0;

// One row of 'kartAIparam.bin'.
typedef struct KartAiParamRow {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
} KartAiParamRow;

// State the CPU kart code shares: per-kart tables, the random generator pointer and the team counts.
typedef struct KartAiShared {
    /* 000 */ s32 mUnk_000[8];
    // Kart index at rank n + 1, -1 when no kart has that rank.
    /* 020 */ s32 mKartAtRank[8];
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
    // The race's random generator, or the per-console one in time attack.
    /* 128 */ Unk0217aebc_128 *mRandom;
    /* 12c */ NNSFndList mUnk_12c;
    /* 138 */ s32 mUnk_138;
    /* 13c */ s16 mUnk_13c;
    /* 13e */ s16 mUnk_13e[3];
} KartAiShared;

extern KartAiShared *gKartAiShared;
// The row of 'kartAIparam.bin' for this race; NULL in battle and when mUnk_00c is 5 or 6.
extern KartAiParamRow *gKartAiParamRow;
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
extern const char *gKartModelPathPrefix;
extern char gKartModelPathBuffer[];

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
// Set to 1 when TryUpdateEntryCamera is entered; cleared once per UpdateRace call by ClearCameraEntryFlags.
// RefreshCameraProjection does not skip the chase camera's projection while it is 1.
extern s32 gEntryCameraUpdateRan;

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
extern struct Kart *gKarts;
extern NNSFndList gResFileEntries;
// The event counters of the selected entry's Kart, allocated by InitKarts.
struct EntryKartCounters;
extern struct EntryKartCounters *gEntryKartCounters;

// The Camera (mKind 2) that starts at CourseMap.mSecondChainStartEntry; NULL when only the first chain camera exists.
// While its entry is of kind 4 it is not stepped itself: it copies the field of view, mPos and mLookAt of
// gFirstChainCamera, and its entry advances together with the first one's. Its view is the one used on odd frames.
extern Camera *gSecondChainCamera;
// The Camera (mKind 2) that starts at CourseMap.mFirstChainStartEntry and follows mNextIndex through its entries; the
// only chain camera when gRaceSetup->mUnk_00c is 4. Created by CreateFirstChainCamera or CreateChainCameraPair. With
// two chain cameras its view is the one used on even frames of gRace->mUpdateFrames.
extern Camera *gFirstChainCamera;
extern void *data_usa_0217aa68;
extern s32 data_usa_0217ac7c;
extern s32 data_usa_0217ac90;
extern s32 data_usa_0217ac78;
extern u16 data_usa_0217ac70;
