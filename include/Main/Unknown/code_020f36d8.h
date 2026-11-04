#pragma once

#include "types.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "code_02146d78.h"
#include "code_0212d214.h"
#include "Main/Unknown/code_0210bcf4.h"
#include "Main/Unknown/code_020d849c.h"
#include "Main/Unknown/code_020d22c0.h" // Unk020f41c4_B
#include "Main/Unknown/unk_0217a000.h" // Unk0217aa1c_144_00

// Object whose first word is compared with a stored value.
typedef struct {
    /* 00 */ s32 mUnk_00;
} Unk020f36d8;

// Node with two lists of node pointers and a position pointer.
typedef struct Unk020f371c {
    /* 00 */ struct Unk020f371c *mUnk_00[3];
    /* 0c */ struct Unk020f371c *mUnk_0c[3];
    /* 18 */ Vec3 *mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ u8 mUnk_20;
    /* 21 */ u8 mUnk_21;
    /* 22 */ u8 mUnk_22;
    /* 23 */ u8 mUnk_23;
    /* 24 */ u16 mUnk_24;
    /* 26 */ u16 mUnk_26;
} Unk020f371c;

// A node and which of its two lists is used.
typedef struct {
    /* 00 */ Unk020f371c *mUnk_00;
    /* 04 */ s32 mUnk_04;
} Unk020f371c_Ref;

// Nine halfwords moved together.
typedef struct {
    /* 00 */ u16 mUnk_00[9];
} Unk020f41c4_C;

// Four positions and pointers to them.
typedef struct {
    /* 00 */ Unk020d849c mUnk_00;
    /* 60 */ s32 mUnk_60;
    /* 64 */ Vec3 *mUnk_64[4];
    /* 74 */ Vec3 mUnk_74[4];
} Unk020f3fa8;

extern Unk020f3fa8 data_0217bb88;

// Element returned through data_027e00cc: the first 0x12c bytes, which the elements of every entry share (the
// element sizes in the data_0217bc34 entries start at 0x12c).
typedef struct Unk020f41c4_A {
    /* 00 */ Unk0210bfbc mUnk_00;
    /* 44 */ s32 mUnk_44;
    /* 48 */ s32 mUnk_48;
    /* 4c */ s16 mUnk_4c;
    /* 4e */ s16 mUnk_4e;
    /* 050 */ Vec3 mUnk_50;
    /* 5c */ Vec3 mUnk_5c;
    /* 68 */ Vec3 mUnk_68;
    /* 74 */ u32 mUnk_74;
    /* 78 */ u16 mUnk_78;
    /* 7a */ u16 mUnk_7a;
    /* 7c */ Unk020f41c4_C mUnk_7c;
    /* 08e */ u8 mUnk_08e[2];
    /* 090 */ u16 *mUnk_90;
    /* 094 */ Unk02012f58 mUnk_94;
    /* 0c4 */ Vec3 mUnk_0c4;
    /* d0 */ Vec3 *mUnk_d0;
    /* 0d4 */ s32 mUnk_d4;
    /* 0d8 */ s16 mUnk_d8;
    /* 0da */ s16 mUnk_da;
    /* 0dc */ s32 mUnk_dc;
    /* e0 */ s32 mUnk_e0;
    /* 0e4 */ Vec3 mUnk_0e4;
    /* 0f0 */ Vec3 mUnk_f0;
    /* fc */ u32 mUnk_fc;
    /* 100 */ s32 mUnk_100;
    /* 104 */ struct Unk020e04b0 *mUnk_104;
    /* 108 */ Vec3 mUnk_108;
    /* 114 */ s16 mUnk_114;
    /* 116 */ s16 mUnk_116;
    /* 118 */ s16 mUnk_118;
    /* 11a */ s16 mUnk_11a;
    /* 11c */ s32 mUnk_11c;
    /* 120 */ void (*mUnk_120)(struct Unk020f41c4_A *);
    /* 124 */ void (*mUnk_124)(struct Unk020f41c4_A *, Vec3 *, Vec3 *);
    /* 128 */ u8 mUnk_128;
    /* 129 */ u8 mUnk_129[3];
} Unk020f41c4_A;

// One 0x8c-byte entry of the array at Unk0217561c::mUnk_14 (the bytes of an entry of mUnk_000 from its member 0x14, and
// the 0x14 bytes after it).
typedef struct Unk0217561c_14 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ Unk0217aa1c_144_00 mUnk_0c[6];
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ u16 mUnk_30;
    /* 32 */ u16 mUnk_32;
    /* 34 */ s16 mUnk_34;
    /* 36 */ s16 mUnk_36;
    /* 38 */ u16 mUnk_38;
    /* 3a */ u16 mUnk_3a;
    /* 3c */ union {
        u16 mUnk_3c;
        struct {
            u16 mUnk_3c_0 : 4;
            u16 mUnk_3c_4 : 4;
            u16 mUnk_3c_8 : 2;
        };
    };
    /* 3e */ s16 mUnk_3e;
    /* 40 */ s32 mUnk_40;
    /* 44 */ s32 mUnk_44;
    /* 48 */ s32 mUnk_48;
    /* 4c */ s32 mUnk_4c[0x10];
} Unk0217561c_14;

// Entry of the array at Unk0217561c::mUnk_000; the word at 0x14 and the halfword at 0x44.
typedef struct {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ union {
        struct {
            /* 08 */ u16 mUnk_08;
            /* 0a */ u8 mUnk_0a;
            /* 0b */ u8 mUnk_0b;
        };
        Unk0217aa1c_144_00 mUnk_08_view;
    };
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u8 mUnk_12[0x2];
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ u16 mUnk_20;
    /* 22 */ u8 mUnk_22;
    /* 23 */ u8 mUnk_23;
    /* 24 */ u8 mUnk_24[0x10];
    /* 34 */ u16 mUnk_34;
    /* 36 */ u8 mUnk_36;
    /* 37 */ u8 mUnk_37;
    /* 38 */ s32 mUnk_38;
    /* 3c */ s32 mUnk_3c;
    /* 40 */ s32 mUnk_40;
    /* 44 */ u16 mUnk_44;
    /* 46 */ u16 mUnk_46;
    /* 48 */ u16 mUnk_48;
    /* 4a */ u16 mUnk_4a;
    /* 4c */ u16 mUnk_4c;
    /* 4e */ u16 mUnk_4e;
    /* 50 */ union {
        u16 mUnk_50;
        struct {
            u16 mUnk_50_0 : 4;
            u16 mUnk_50_4 : 4;
            u16 mUnk_50_8 : 2;
        };
    };
    /* 52 */ s16 mUnk_52;
    /* 54 */ s32 mUnk_54;
    /* 58 */ s32 mUnk_58;
    /* 5c */ s32 mUnk_5c;
    /* 60 */ u8 mUnk_60[0x2c];
} Unk0217561c_000;

// Nine words.
typedef struct Unk0217561c_500 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
} Unk0217561c_500;

// 8-byte entries from 0x1c of the object behind Unk0217561c::mUnk_4c8.
typedef struct Unk0217561c_4c8_1c {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
} Unk0217561c_4c8_1c;

// Object behind Unk0217561c::mUnk_4c8: halfwords.
typedef struct Unk0217561c_4c8 {
    /* 00 */ u8 mUnk_00[0x8];
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
    /* 14 */ u16 mUnk_14;
    /* 16 */ u16 mUnk_16;
    /* 18 */ u16 mUnk_18;
    /* 1a */ u16 mUnk_1a;
    /* 1c */ Unk0217561c_4c8_1c mUnk_1c[1];
} Unk0217561c_4c8;

// Eight bytes: a row of the table behind Unk0217561c::mUnk_4dc.
typedef struct Unk0217561c_4dc {
    /* 00 */ u8 mUnk_00[8];
} Unk0217561c_4dc;

// Object behind data_0217561c.
typedef struct {
    union {
        struct {
            /* 000 */ Unk0217561c_000 mUnk_000[8];
            /* 460 */ u8 mUnk_460[0x14];
        };
        struct {
            /* 000 */ u8 mUnk_00_header[0x14];
            /* 014 */ Unk0217561c_14 mUnk_14[8];
        };
    };
    /* 474 */ s8 mUnk_474[8];
    /* 47c */ Unk020f41c4_B mUnk_47c;
    /* 494 */ s32 mUnk_494;
    /* 498 */ Unk020f41c4_B mUnk_498;
    /* 4b0 */ Unk020f41c4_B mUnk_4b0;
    /* 4c8 */ Unk0217561c_4c8 *mUnk_4c8;
    /* 4cc */ s32 mUnk_4cc;
    /* 4d0 */ s32 mUnk_4d0;
    /* 4d4 */ s32 *mUnk_4d4;
    /* 4d8 */ u8 mUnk_4d8[0x4];
    /* 4dc */ Unk0217561c_4dc *mUnk_4dc;
    /* 4e0 */ s32 mUnk_4e0;
    /* 4e4 */ s32 mUnk_4e4;
    /* 4e8 */ s32 mUnk_4e8;
    /* 4ec */ s32 mUnk_4ec;
    /* 4f0 */ s32 mUnk_4f0;
    /* 4f4 */ u32 mUnk_4f4;
    /* 4f8 */ u8 mUnk_4f8;
    /* 4f9 */ u8 mUnk_4f9;
    /* 4fa */ u16 mUnk_4fa;
    /* 4fc */ u16 mUnk_4fc;
    /* 4fe */ u16 mUnk_4fe;
    /* 500 */ Unk0217561c_500 mUnk_500;
} Unk0217561c;

// Entry of the table behind data_0217bc34.
typedef struct {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ u8 mUnk_14[4];
    /* 18 */ void (*mUnk_18)(void *);
    /* 1c */ void (*mUnk_1c)(void *);
    /* 20 */ void (*mUnk_20)(void *, void *);
    /* 24 */ s32 (*mUnk_24)(void *, void *);
    /* 28 */ void (*mUnk_28)(struct Unk020f41c4_A *);
    /* 2c */ void (*mUnk_2c)(void *, void *, void *);
    /* 30 */ s32 (*mUnk_30)(void *, s32, s32, s32, s32);
    /* 34 */ UnkWordFunc *mUnk_34;
    /* 38 */ void (*mUnk_38)(void *);
    /* 3c */ void (*mUnk_3c)(void *);
    /* 40 */ s32 mUnk_40;
    /* 44 */ s32 mUnk_44;
    /* 48 */ void *(*mUnk_48)(void *, void *, s32);
    /* 4c */ s32 mUnk_4c;
    /* 50 */ void (*mUnk_50)(void *);
    /* 54 */ s32 mUnk_54;
    /* 58 */ u32 mUnk_58;
    /* 5c */ s32 mUnk_5c;
    /* 60 */ s32 mUnk_60;
    /* 64 */ s32 mUnk_64;
    /* 68 */ s32 mUnk_68;
    /* 6c */ s32 mUnk_6c;
    /* 70 */ s32 mUnk_70;
    /* 74 */ s32 mUnk_74;
    /* 78 */ s32 mUnk_78;
    /* 7c */ s32 mUnk_7c;
    /* 80 */ s32 mUnk_80;
    /* 84 */ s32 mUnk_84;
    /* 88 */ s32 mUnk_88;
    /* 8c */ u8 mUnk_8c[4];
    /* 90 */ s32 mUnk_90;
    /* 94 */ s32 mUnk_94;
    /* 98 */ s32 mUnk_98;
    /* 9c */ s32 mUnk_9c;
    /* a0 */ s32 mUnk_a0;
    /* a4 */ s32 mUnk_a4;
} Unk0217bc34;

extern Unk0217bc34 data_0215a5a4;

extern Unk0217bc34 data_02159dac;

extern Unk0217bc34 data_0215a244;

extern Unk0217bc34 data_0215a308;

extern Unk0217bc34 data_02159e70;

extern Unk0217bc34 data_0215a4dc;

extern Unk0217bc34 data_02159f84;

extern Unk0217bc34 data_02159abc;

extern Unk0217bc34 data_02159cdc;

extern Unk0217bc34 data_021599f8;

extern Unk0217bc34 data_021596bc;

extern Unk0217bc34 data_0215978c;

extern Unk0217bc34 data_02159854;

extern Unk0217bc34 data_02159934;

// Two words of a row of data_0215961c.
typedef struct {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
} Unk020f41c4_Pair;

// Row of data_0215961c.
typedef struct {
    /* 00 */ Unk020f41c4_Pair mUnk_00[3];
} Unk020f41c4_Row;

// Entry of the table behind data_0217bc48.
typedef struct {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ void (*mUnk_18)(void *, void *);
} Unk0217bc48;

extern Unk0217bc48 data_0215a4c0;

extern Unk0217bc48 data_0215a174;

extern Unk0217bc48 data_0215a2ec;

extern Unk0217bc48 data_0215a588;

extern Unk0217bc48 data_02159d90;

extern Unk0217bc48 data_021599dc;

extern Unk0217bc48 data_021598fc;

extern Unk0217bc48 data_02159680;

extern Unk0217bc48 data_02159f4c;

extern Unk0217bc48 data_02159aa0;

extern Unk0217bc48 data_02159cc0;

extern Unk0217bc48 data_02159e54;

extern Unk0217bc48 data_02159664;

extern Unk0217bc48 data_021596a0;

extern Unk0217bc48 data_02159f68;

extern Unk0217bc48 data_02159770;

extern Unk0217bc48 data_02159838;

extern Unk0217bc48 data_02159918;

// Entry of the table behind data_027e00cc.
typedef struct {
    /* 00 */ s32 mUnk_00;
    /* 04 */ Unk020f41c4_A **mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
    /* 24 */ void (*mUnk_24)(void *, void *, void *);
    /* 28 */ s32 (*mUnk_28)(void *, s32, s32, s32, s32);
    /* 2c */ s32 mUnk_2c;
    /* 30 */ s32 mUnk_30;
    /* 34 */ s32 mUnk_34;
    /* 38 */ s32 mUnk_38;
    /* 3c */ s32 mUnk_3c;
    /* 40 */ s32 mUnk_40;
} Unk027e00cc;

// Value of the first word of Unk020f40dc.
typedef enum { UNK_020F40DC_KIND_0 } Unk020f40dc_Kind;

// Object handled by func_020f40dc and the functions after it.
typedef struct {
    /* 00 */ s32 mUnk_00;
    /* 04 */ struct Unk020ee684 *mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s16 mUnk_10;
    /* 12 */ s16 mUnk_12;
    /* 14 */ Unk020f41c4_A *mUnk_14[3];
    /* 20 */ s32 mUnk_20;
    /* 24 */ s32 mUnk_24;
} Unk020f40dc;

extern Unk0206bcb0 *GetKart(s32 idx);
#include "Main/Unknown/code_020d6dc0.h"

extern s32 data_0217bc38[];
extern Unk0217bc34 *data_0217bc34;
extern Unk0217561c *data_0217561c;
extern Unk020f41c4_Row data_0215961c[];
extern Unk0217bc48 *data_0217bc48;
extern Unk027e00cc *data_027e00cc;

u8 func_020f36d8(Unk020f36d8 *p);
void func_020f371c(Unk020f371c_Ref *in, Unk020f371c_Ref *out, u32 idx, s32 flag);
BOOL func_020f3a58(Unk020f371c_Ref *in, Unk020f371c_Ref *out, Vec3 *pos);
BOOL func_020f3bb4(Unk020f371c_Ref *a, Unk020f371c_Ref *b, Unk020f371c_Ref *out, Vec3 *pos);
BOOL func_020f3c54(Unk020f371c_Ref *in, Unk020f371c_Ref *out, Vec3 *pos);
s32 func_020f3fa8(Unk020f3fa8 *p, Vec3 *v);
void func_020f4020(Unk020f3fa8 *p, Vec3 *points, s32 scale);
s32 func_020f4090(s32 idx);
void func_020f40a0(s32 idx, s32 amount);
void func_020f40dc(Unk020f40dc *rec, s32 kind, s32 count);
void func_020f413c(Unk020f40dc *rec, s32 *kind, s32 *count);
void func_020f4188(Unk020f40dc *rec, s32 v);
BOOL func_020f4198(Unk020f40dc *rec, s32 v);
void func_020f41b0(Unk020f40dc *rec);
void func_020f41c4(Unk020f40dc *rec);
void func_020f45f0(Unk020f40dc *rec, s32 keep);
void func_020f4718(Unk020f40dc *rec);
void func_020f4754(Unk020f40dc *rec, s32 n);
void func_020f47e4(Unk020f40dc *rec, s32 kind);
void func_020f4884(Unk020f40dc *rec);
