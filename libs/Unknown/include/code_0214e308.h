#pragma once

#include "types.h"

// Four halfwords; func_0214e89c copies them from Unk0214e308 and func_0214e334 reads them. Also the 8-byte entries of
// the array at mUnk_10 of Unk0214e308: func_0214e788 clears mUnk_04 of each, func_0214ec18 fills one.
typedef struct Unk0214e334_b {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u16 mUnk_02;
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
} Unk0214e334_b;

// Four halfwords; func_0214e334 and func_0214e464 fill them, func_0214e994 reads them and func_0214eadc clears them.
typedef struct Unk0214e334 {
    /* 00 */ s16 mUnk_00;
    /* 02 */ s16 mUnk_02;
    /* 04 */ s16 mUnk_04;
    /* 06 */ s16 mUnk_06;
} Unk0214e334;

// Six words; func_0214e994 stores them and func_0214e334 reads mUnk_00, mUnk_08, mUnk_0c and mUnk_14.
typedef struct Unk0214e334_c {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
} Unk0214e334_c;

// Two fixed-address halfwords func_0214ec18 reads, split into bit fields.
typedef union Unk0214ec18 {
    u16 h[2];
    struct {
        /* 00 */ u32 mUnk_00_0 : 12;
        /* 00 */ u32 mUnk_00_12 : 12;
        /* 00 */ u32 mUnk_00_24 : 1;
        /* 00 */ u32 mUnk_00_25 : 2;
        /* 00 */ u32 : 5;
    } f;
} Unk0214ec18;

// Fixed-address object read by func_0214eadc.
typedef struct Unk0214eadc {
    /* 00 */ u8 mUnk_00[0x58];
    /* 58 */ u16 mUnk_58;
    /* 5a */ u16 mUnk_5a;
    /* 5c */ u8 mUnk_5c;
    /* 5d */ u8 mUnk_5d;
    /* 5e */ u16 mUnk_5e;
    /* 60 */ u16 mUnk_60;
    /* 62 */ u8 mUnk_62;
    /* 63 */ u8 mUnk_63;
} Unk0214eadc;

// 0x38 bytes (bss). func_0214e6e4, func_0214e788, func_0214e8f4 and func_0214ec18 call mUnk_00 with three
// arguments. mUnk_32, mUnk_34 and mUnk_36 are volatile: func_0214e31c waits on mUnk_36, and func_0214eb88,
// func_0214e6e4 and func_0214e8f4 store them in source order.
typedef struct Unk0214e308 {
    /* 00 */ void (*mUnk_00)(u32, u8, u8);
    /* 04 */ Unk0214e334_b mUnk_04;
    /* 0c */ u16 mUnk_0c;
    /* 0e */ u16 mUnk_0e;
    /* 10 */ Unk0214e334_b *mUnk_10;
    /* 14 */ u16 mUnk_14;
    /* 16 */ u8 mUnk_16[2];
    /* 18 */ Unk0214e334_c mUnk_18;
    /* 30 */ u16 mUnk_30;
    /* 32 */ vu16 mUnk_32;
    /* 34 */ vu16 mUnk_34;
    /* 36 */ vu16 mUnk_36;
} Unk0214e308;

extern u16 data_021803d4;
extern Unk0214e308 data_021803d8;

u32 func_0214e308(u32 a);
void func_0214e31c(u32 a);
void func_0214e334(Unk0214e334 *out, const Unk0214e334_b *in);
u32 func_0214e464(Unk0214e334 *out, u16 a, u16 b, u16 c, u16 d, u16 e, u16 f, u16 g, u16 h);
u32 func_0214e6d4(void);
void func_0214e6e4(void);
void func_0214e788(u32 a, u32 b, Unk0214e334_b *p, u32 n);
u32 func_0214e89c(Unk0214e334_b *out);
void func_0214e8f4(void);
void func_0214e994(Unk0214e334 *p);
u32 func_0214eadc(Unk0214e334 *p);
void func_0214eb88(void);
void func_0214ec18(u32 a, u32 b, u32 c);
