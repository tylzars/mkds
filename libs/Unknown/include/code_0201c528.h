#pragma once

#include "types.h"
#include "code_02012b30.h" // Unk02012f58
#include "code_02147cd8.h"

// Linked through mUnk_00/mUnk_04; on the lists at Unk0201ca6c 0x08 and 0x14 and Unk020184e4 0x1c.
typedef struct Unk0201e3c8 {
    /* 00 */ struct Unk0201e3c8 *mUnk_00;
    /* 04 */ struct Unk0201e3c8 *mUnk_04;
    /* 08 */ Vec3 mUnk_08;
    /* 14 */ Vec3 mUnk_14;
    /* 20 */ u16 mUnk_20;
    /* 22 */ s16 mUnk_22;
    /* 24 */ u16 mUnk_24;
    /* 26 */ u16 mUnk_26;
    /* 28 */ u16 mUnk_28;
    /* 2a */ u16 mUnk_2a;
    /* 2c */ u8 mUnk_2c;
    /* 2d */ u8 mUnk_2d;
    /* 2e */ u16 mUnk_2e_0 : 5;
    /* 2e */ u16 mUnk_2e_5 : 5;
    /* 2e */ u16 mUnk_2e_10 : 6;
    /* 30 */ s32 mUnk_30;
    /* 34 */ s16 mUnk_34;
    /* 36 */ u16 mUnk_36;
    /* 38 */ Vec3 mUnk_38;
} Unk0201e3c8;

// Used by func_0201e494, func_0201e3c8 and func_0201e448.
typedef struct Unk0201e494 {
    /* 00 */ Unk0201e3c8 *mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ Unk0201e3c8 *mUnk_08;
} Unk0201e494;

typedef struct Unk0201ca6c_20_00_00 {
    /* 00 */ u32 mUnk_00_0 : 4;
    /* 00 */ u32 mUnk_00_4 : 2;
    /* 00 */ u32 mUnk_00_6 : 2;
    /* 00 */ u32 mUnk_00_8 : 1;
    /* 00 */ u32 mUnk_00_9 : 1;
    /* 00 */ u32 mUnk_00_10 : 1;
    /* 00 */ u32 mUnk_00_11 : 1;
    /* 00 */ u32 mUnk_00_12 : 1;
    /* 00 */ u32 mUnk_00_13 : 1;
    /* 00 */ u32 mUnk_00_14 : 1;
    /* 00 */ u32 mUnk_00_15 : 1;
    /* 00 */ u32 mUnk_00_16 : 1;
    /* 00 */ u32 mUnk_00_17 : 2;
    /* 00 */ u32 mUnk_00_19 : 1;
    /* 00 */ u32 mUnk_00_20 : 1;
    /* 00 */ u32 mUnk_00_21 : 1;
    /* 00 */ u32 mUnk_00_22 : 1;
    /* 00 */ u32 mUnk_00_23 : 1;
    /* 00 */ u32 mUnk_00_24 : 1;
    /* 00 */ u32 mUnk_00_25 : 1;
    /* 00 */ u32 mUnk_00_26 : 1;
    /* 00 */ u32 mUnk_00_27 : 1;
    /* 00 */ u32 mUnk_00_28 : 1;
    /* 00 */ u32 mUnk_00_29 : 1;
    /* 00 */ u32 mUnk_00_30 : 1;
    /* 00 */ u32 mUnk_00_31 : 1;
} Unk0201ca6c_20_00_00;

typedef struct Unk0201ca6c_20_00_48 {
    /* 00 */ u32 mUnk_00_0 : 8;
    /* 00 */ u32 mUnk_00_8 : 16;
    /* 00 */ u32 mUnk_00_24 : 2;
    /* 00 */ u32 mUnk_00_26 : 2;
    /* 00 */ u32 mUnk_00_28 : 3;
    /* 00 */ u32 mUnk_00_31 : 1;
} Unk0201ca6c_20_00_48;

typedef struct Unk0201ca6c_20_00 {
    /* 00 */ Unk0201ca6c_20_00_00 mUnk_00;
    /* 04 */ Vec3 mUnk_04;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ Vec3s16 mUnk_1c;
    /* 22 */ u16 mUnk_22;
    /* 24 */ s32 mUnk_24;
    /* 28 */ s32 mUnk_28;
    /* 2c */ s32 mUnk_2c;
    /* 30 */ s16 mUnk_30;
    /* 32 */ u16 mUnk_32;
    /* 34 */ s16 mUnk_34;
    /* 36 */ s16 mUnk_36;
    /* 38 */ u16 mUnk_38;
    /* 3a */ u8 mUnk_3a[2];
    /* 3c */ u16 mUnk_3c;
    /* 3e */ u16 mUnk_3e;
    /* 40 */ u8 mUnk_40;
    /* 41 */ u8 mUnk_41;
    /* 42 */ u8 mUnk_42;
    /* 43 */ u8 mUnk_43;
    /* 44 */ u8 mUnk_44;
    /* 45 */ u8 mUnk_45;
    /* 46 */ u8 mUnk_46;
    /* 47 */ u8 mUnk_47;
    /* 48 */ Unk0201ca6c_20_00_48 mUnk_48;
    /* 4c */ u32 mUnk_4c_0 : 1;
    /* 4c */ u32 mUnk_4c_1 : 1;
    /* 4c */ u32 mUnk_4c_2 : 30;
    /* 50 */ s16 mUnk_50;
    /* 52 */ s16 mUnk_52;
    /* 54 */ u8 mUnk_54;
} Unk0201ca6c_20_00;

typedef struct Unk0201ca6c_20_04 {
    /* 00 */ s16 mUnk_00;
    /* 02 */ s16 mUnk_02;
    /* 04 */ s16 mUnk_04;
    /* 06 */ u8 mUnk_06;
    /* 07 */ u8 mUnk_07;
    /* 08 */ u16 mUnk_08_0 : 1;
    /* 08 */ u16 mUnk_08_1 : 15;
} Unk0201ca6c_20_04;

typedef struct Unk0201ca6c_20_08 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04;
    /* 05 */ u8 mUnk_05;
    /* 06 */ u8 mUnk_06;
    /* 07 */ u8 mUnk_07;
    /* 08 */ u16 mUnk_08_0 : 1;
    /* 08 */ u16 mUnk_08_1 : 1;
    /* 08 */ u16 mUnk_08_2 : 1;
    /* 08 */ u16 mUnk_08_3 : 13;
} Unk0201ca6c_20_08;

typedef struct Unk0201ca6c_20_0c {
    /* 00 */ u16 mUnk_00_0 : 5;
    /* 00 */ u16 mUnk_00_5 : 5;
    /* 00 */ u16 mUnk_00_10 : 5;
    /* 00 */ u16 mUnk_00_15 : 1;
    /* 02 */ u16 mUnk_02_0 : 8;
    /* 02 */ u16 mUnk_02_8 : 1;
    /* 02 */ u16 mUnk_02_9 : 7;
    /* 04 */ u8 mUnk_04;
    /* 05 */ u8 mUnk_05;
    /* 06 */ u8 mUnk_06[2];
} Unk0201ca6c_20_0c;

typedef struct Unk0201ca6c_20_10 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ u32 mUnk_08_0 : 8;
    /* 08 */ u32 mUnk_08_8 : 8;
    /* 08 */ u32 mUnk_08_16 : 1;
    /* 08 */ u32 mUnk_08_17 : 1;
    /* 08 */ u32 mUnk_08_18 : 14;
} Unk0201ca6c_20_10;

typedef struct Unk0201ca6c_20_14_10 {
    /* 00 */ u32 mUnk_00_0 : 2;
    /* 00 */ u32 mUnk_00_2 : 2;
    /* 00 */ u32 mUnk_00_4 : 1;
    /* 00 */ u32 mUnk_00_5 : 1;
    /* 00 */ u32 mUnk_00_6 : 1;
    /* 00 */ u32 mUnk_00_7 : 25;
} Unk0201ca6c_20_14_10;

typedef struct Unk0201ca6c_20_14 {
    /* 00 */ u16 mUnk_00_0 : 1;
    /* 00 */ u16 mUnk_00_1 : 1;
    /* 00 */ u16 mUnk_00_2 : 1;
    /* 00 */ u16 mUnk_00_3 : 2;
    /* 00 */ u16 mUnk_00_5 : 1;
    /* 00 */ u16 mUnk_00_6 : 1;
    /* 00 */ u16 mUnk_00_7 : 2;
    /* 00 */ u16 mUnk_00_9 : 2;
    /* 00 */ u16 mUnk_00_11 : 1;
    /* 00 */ u16 mUnk_00_12 : 4;
    /* 02 */ s16 mUnk_02;
    /* 04 */ s16 mUnk_04;
    /* 06 */ u16 mUnk_06;
    /* 08 */ u8 mUnk_08;
    /* 09 */ u8 mUnk_09;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u8 mUnk_0c;
    /* 0d */ u8 mUnk_0d;
    /* 0e */ u8 mUnk_0e;
    /* 0f */ u8 mUnk_0f;
    /* 10 */ Unk0201ca6c_20_14_10 mUnk_10;
} Unk0201ca6c_20_14;

typedef struct Unk0201ca6c_24 {
    /* 00 */ u32 mUnk_00_0 : 1;
    /* 00 */ u32 mUnk_00_1 : 1;
    /* 00 */ u32 mUnk_00_2 : 1;
    /* 00 */ u32 mUnk_00_3 : 1;
    /* 00 */ u32 mUnk_00_4 : 1;
    /* 00 */ u32 mUnk_00_5 : 27;
} Unk0201ca6c_24;

typedef struct Unk0201ca6c Unk0201ca6c;
typedef struct Unk0201ca6c_20 Unk0201ca6c_20;

// Entries of the table at Unk0201ca6c_20 0x18 (count at 0x1c).
typedef struct Unk0201ca6c_20_18 {
    /* 00 */ void (*mUnk_00)(); // called with four arguments; the type of the first differs per entry
    /* 04 */ void *mUnk_04;
} Unk0201ca6c_20_18;

struct Unk0201ca6c_20 {
    /* 00 */ Unk0201ca6c_20_00 *mUnk_00;
    /* 04 */ Unk0201ca6c_20_04 *mUnk_04;
    /* 08 */ Unk0201ca6c_20_08 *mUnk_08;
    /* 0c */ Unk0201ca6c_20_0c *mUnk_0c;
    /* 10 */ Unk0201ca6c_20_10 *mUnk_10;
    /* 14 */ Unk0201ca6c_20_14 *mUnk_14;
    /* 18 */ Unk0201ca6c_20_18 *mUnk_18;
    /* 1c */ u16 mUnk_1c;
};

// The four bytes at Unk0201ca6c 0x98.
typedef struct Unk0201ca6c_98 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02;
    /* 03 */ u8 mUnk_03;
} Unk0201ca6c_98;

struct Unk0201ca6c {
    /* 00 */ struct Unk0201ca6c *mUnk_00;
    /* 04 */ struct Unk0201ca6c *mUnk_04;
    /* 08 */ Unk0201e494 mUnk_08;
    /* 14 */ Unk0201e494 mUnk_14;
    /* 20 */ Unk0201ca6c_20 *mUnk_20;
    /* 24 */ Unk0201ca6c_24 mUnk_24;
    /* 28 */ Vec3 mUnk_28;
    /* 34 */ Vec3 mUnk_34;
    /* 40 */ Vec3 mUnk_40;
    /* 4c */ u16 mUnk_4c;
    /* 4e */ s16 mUnk_4e;
    /* 50 */ Vec3s16 mUnk_50;
    /* 56 */ u16 mUnk_56;
    /* 58 */ s32 mUnk_58;
    /* 5c */ s32 mUnk_5c;
    /* 60 */ s32 mUnk_60;
    /* 64 */ s32 mUnk_64;
    /* 68 */ s32 mUnk_68;
    /* 6c */ s32 mUnk_6c;
    /* 70 */ u16 mUnk_70;
    /* 72 */ u16 mUnk_72;
    /* 74 */ s32 mUnk_74;
    /* 78 */ s16 mUnk_78;
    /* 7a */ s16 mUnk_7a;
    /* 7c */ s16 mUnk_7c;
    /* 7e */ s16 mUnk_7e;
    /* 80 */ u32 mUnk_80_0 : 8;
    /* 80 */ u32 mUnk_80_8 : 8;
    /* 80 */ u32 mUnk_80_16 : 3;
    /* 80 */ u32 mUnk_80_19 : 13;
    /* 84 */ Vec3s16 mUnk_84;
    /* 8a */ Vec3s16 mUnk_8a;
    /* 90 */ void (*mUnk_90)(Unk0201ca6c *p, s32 a);
    /* 94 */ union {
        void *mUnk_94;
        u32 mUnk_94_u;
    };
    /* 98 */ union {
        u32 mUnk_98;
        Unk0201ca6c_98 mUnk_98_b;
        struct {
            u8 mUnk_98_0;
            u8 mUnk_98_8;
            u8 mUnk_98_16;
            u8 mUnk_98_24;
        };
    };
};

// Read by func_0201e248 and func_0201dfc0.
typedef struct Unk0201e248 {
    /* 00 */ Vec3 mUnk_00;
    /* 0c */ s16 mUnk_0c;
} Unk0201e248;

// Read by func_0201e2cc.
typedef struct Unk0201e2cc {
    /* 00 */ s16 mUnk_00;
    /* 02 */ s16 mUnk_02;
    /* 04 */ s16 mUnk_04;
    /* 06 */ u16 mUnk_06;
} Unk0201e2cc;

// Read by func_0201e054.
typedef struct Unk0201e054 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s16 mUnk_04;
    /* 06 */ u16 mUnk_06_0 : 2;
    /* 06 */ u16 mUnk_06_2 : 14;
} Unk0201e054;

// Read by func_0201e170.
typedef struct Unk0201e170 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
} Unk0201e170;

void func_0201c528(s32 a, s32 b, Unk02012f58 *m);
void func_0201c5d4(u32 a, u32 b, s32 c, s32 d);
void func_0201c690(u32 a, u32 b, s32 c, s32 d);
void func_0201c74c(Unk0201e3c8 *p, Unk0201ca6c *q, Unk0201e494 *r);
void func_0201ca6c(Unk0201ca6c *p, Unk0201e494 *r);
void func_0201d798(Vec3 *out, const Vec3 *v, Unk0201ca6c *p);
void func_0201d8f8(Unk0201ca6c *p);
void func_0201db80(Unk0201e3c8 *p, Unk0201ca6c_20 *q, s32 v);
void func_0201dbd8(Unk0201e3c8 *p, Unk0201ca6c_20 *q, s32 v);
void func_0201dc24(Unk0201e3c8 *p, Unk0201ca6c_20 *q, s32 v);
void func_0201dc88(Unk0201e3c8 *p, Unk0201ca6c_20 *q, s32 v);
void func_0201dd64(Unk0201e3c8 *p, Unk0201ca6c_20 *q, s32 v);
void func_0201df30(Unk0201e3c8 *p, Unk0201ca6c_20 *q, s32 v);
void func_0201dfc0(const Unk0201e248 *a, Unk0201e3c8 *p, Vec3 *v, Unk0201ca6c *q);
void func_0201e054(const Unk0201e054 *a, Unk0201e3c8 *p, Vec3 *v, Unk0201ca6c *q);
void func_0201e170(const Unk0201e170 *a, Unk0201e3c8 *p, Vec3 *v, Unk0201ca6c *q);
void func_0201e248(const Unk0201e248 *a, Unk0201e3c8 *p, Vec3 *v, Unk0201ca6c *q);
void func_0201e2cc(const Unk0201e2cc *a, Unk0201e3c8 *p, Vec3 *v, Unk0201ca6c *q);
void func_0201e394(const Vec3s16 *a, Unk0201e3c8 *p, Vec3 *v, Unk0201ca6c *q);
Unk0201e3c8 *func_0201e3c8(Unk0201e494 *l0, Unk0201e3c8 *p);
Unk0201e3c8 *func_0201e448(Unk0201e494 *l0);
void func_0201e494(Unk0201e494 *l0, Unk0201e3c8 *p);
void func_0201e4e4(Vec3 *v);
void func_0201e540(Vec3 *v);
