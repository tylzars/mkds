#pragma once

#include "types.h"

struct Unk02197e8c;
struct Unk02197fe8;

typedef struct Unk02198778 {
    /* 00 */ void (*mUnk_00)(struct Unk02197fe8 *a, int b, void *c, int d);
    /* 04 */ void (*mUnk_04)(struct Unk02197fe8 *a, void *b, int c, int d);
    /* 08 */ void (*mUnk_08)(struct Unk02197fe8 *a, void *b);
    /* 0c */ UnkWordFunc *mUnk_0c;
} Unk02198778;

// Object with the callbacks that the functions of this file call.
typedef struct Unk02197e8c {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u8 mUnk_0a[2];
    /* 0c */ void *mUnk_0c;
    /* 10 */ void *mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ void (*mUnk_20)(struct Unk02197e8c *a, struct Unk02197fe8 *b, int c, int d, int e, int f, int g);
    /* 24 */ void (*mUnk_24)(struct Unk02197e8c *a);
    /* 28 */ UnkWordFunc *mUnk_28;
    /* 2c */ UnkWordFunc *mUnk_2c;
    /* 30 */ UnkWordFunc *mUnk_30;
    /* 34 */ UnkWordFunc *mUnk_34;
    /* 38 */ u32 mUnk_38;
    /* 3c */ u32 mUnk_3c;
    /* 40 */ u8 mUnk_40[4];
} Unk02197e8c;

typedef struct Unk02197fe8Entry {
    /* 00 */ UnkWordFunc *mUnk_00;
} Unk02197fe8Entry;

typedef struct Unk02197fe8Buf {
    /* 0 */ u8 *mUnk_00;
    /* 4 */ u32 mUnk_04;
    /* 8 */ u32 mUnk_08;
} Unk02197fe8Buf;

typedef struct Unk02197fe8 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[2];
    /* 08 */ Unk02197e8c *mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ u32 mUnk_20;
    /* 24 */ s32 mUnk_24;
    /* 28 */ Unk02198778 mUnk_28;
    /* 38 */ Unk02197fe8Buf mUnk_38;
    /* 44 */ Unk02197fe8Buf mUnk_44;
    /* 50 */ Unk02197fe8Buf mUnk_50;
    /* 5c */ void *mUnk_5c;
    /* 60 */ void *mUnk_60;
    /* 64 */ u16 mUnk_64;
    /* 66 */ u16 mUnk_66;
    /* 68 */ u8 mUnk_68[0x20];
    /* 88 */ u32 mUnk_88;
    /* 8c */ u32 mUnk_8c;
    /* 90 */ u32 mUnk_90;
    /* 94 */ u32 mUnk_94;
    /* 98 */ void *mUnk_98;
    /* 9c */ void *mUnk_9c;
} Unk02197fe8;

extern const u8 data_ov000_021b3f50[];
extern const u8 data_ov000_021b3f58[];
extern const u8 data_ov000_021b3f68[];

BOOL func_ov000_02197e8c(Unk02197e8c *a, s32 b, s32 c, void *d, s32 e, s32 *f);
u32 func_ov000_02197f28(int d, int e, u32 f, u32 g, u32 h, int l, int m, int n);
BOOL func_ov000_02197fe8(Unk02197fe8 *a, s32 b, void *c, s32 d, s32 e);
BOOL func_ov000_02198098(Unk02197fe8 *a, s32 b, s32 c, void *d, s32 e);
BOOL func_ov000_02198148(Unk02197fe8 *a, s32 b);
