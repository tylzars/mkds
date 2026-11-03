#pragma once

#include "types.h"
#include "code_0200e0ec.h"

typedef struct Unk0200df9c Unk0200df9c;
typedef struct Unk0200edc0 Unk0200edc0;
typedef struct Unk0200eb90 Unk0200eb90;

struct Unk021a6fa8;
struct Unk021a78a4;

// Four bytes read by func_ov000_021a72a4: a size, a count and a byte.
typedef struct Unk021a72a4 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
} Unk021a72a4;

// Start address and size of a part of an Unk021a6fa8 or of its blocks, set by func_ov000_021a71a4.
typedef struct Unk021a71a4 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u8 *mUnk_04;
} Unk021a71a4;

// Shared start of the two blocks func_ov000_021a71c0 sets up behind an Unk021a6fa8.
typedef struct Unk021a7154 {
    /* 00 */ Unk0200eb90 mUnk_00;
    /* 20 */ Unk0200db5c mUnk_20;
    /* d8 */ u8 mUnk_d8[8];
    /* e0 */ Unk0200edc0 mUnk_e0;
} Unk021a7154;

typedef struct Unk021a71c0 {
    /* 000 */ Unk021a7154 mUnk_00;
    /* 0f8 */ s32 mUnk_f8;
    /* 0fc */ u16 mUnk_fc;
    /* 0fe */ s8 mUnk_fe;
    /* 100 */ struct Unk021a78a4 *mUnk_100;
    /* 104 */ struct Unk021a78a4 *mUnk_104;
    /* 108 */ u16 mUnk_108;
    /* 10a */ u16 mUnk_10a;
    /* 10c */ Unk0200df9c mUnk_10c;
    /* 114 */ u8 mUnk_114[4];
} Unk021a71c0;

typedef struct Unk021a722a {
    /* 000 */ Unk021a7154 mUnk_00;
    /* 0f8 */ Unk021a71a4 mUnk_f8;
    /* 100 */ u16 mUnk_100;
    /* 102 */ u16 mUnk_102;
    /* 104 */ s32 mUnk_104;
    /* 108 */ s32 mUnk_108;
    /* 10c */ struct Unk021a6fa8 *mUnk_10c;
    /* 110 */ u8 mUnk_110[4];
} Unk021a722a;

typedef struct Unk021a6fa8 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ u8 mUnk_08;
    /* 09 */ u8 mUnk_09;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u8 mUnk_0c[0xc];
    /* 18 */ u16 mUnk_18;
    /* 1a */ u16 mUnk_1a;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ u8 mUnk_24[0x18];
    /* 3c */ Unk021a71a4 mUnk_3c;
    /* 44 */ s32 mUnk_44;
    /* 48 */ Unk021a71a4 mUnk_48;
    /* 50 */ Unk021a71a4 mUnk_50;
    /* 58 */ Unk021a71a4 mUnk_58;
    /* 60 */ u8 mUnk_60[4];
    /* 64 */ void *mUnk_64;
    /* 68 */ void *mUnk_68;
    /* 6c */ s32 mUnk_6c;
    /* 70 */ s16 mUnk_70;
    /* 72 */ s8 mUnk_72;
    /* 73 */ s8 mUnk_73;
    /* 74 */ u16 mUnk_74;
    /* 76 */ u16 mUnk_76;
    /* 78 */ u16 *mUnk_78;
    /* 7c */ struct Unk021a6fa8 *mUnk_7c;
    /* 80 */ Unk021a71c0 mUnk_80;
} Unk021a6fa8;

s32 func_ov000_021a6fa8(Unk021a6fa8 *object, void *request);
