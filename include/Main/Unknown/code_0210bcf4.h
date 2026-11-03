#pragma once

#include "types.h"
#include "code_0212bcac.h"
#include "code_0212d254.h" // Unk0212d580
#include "code_0212da38.h" // Unk02017328

// data_0217d048 is addressed in rows of twelve bytes; func_0210bfbc and func_0210c0bc address the
// container of one of those rows. Unk0206bcb0 and the data_027e00cc elements (Unk020f41c4_A) start with it:
// func_02109078 and func_021090c4 pass either one to func_0210c610 and func_0210c86c. func_02109110 writes the
// byte at 0x3c and the word at 0x40.
typedef struct Unk0210bfbc {
    /* 00 */ u8 mUnk_00[2];
    /* 02 */ u16 mUnk_02;
    /* 04 */ u8 mUnk_04[8];
    /* 0c */ Unk02017328 mUnk_0c;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u8 mUnk_1c[0xc];
    /* 28 */ u32 mUnk_28;
    /* 2c */ void (*mUnk_2c)(void *a, void *b, u32 c);
    /* 30 */ void (*mUnk_30)(void *a, void *b, void *c);
    /* 34 */ u16 mUnk_34;
    /* 36 */ u8 mUnk_36[2];
    /* 38 */ u32 mUnk_38;
    /* 3c */ u8 mUnk_3c;
    /* 3d */ u8 mUnk_3d[3];
    /* 40 */ u32 mUnk_40;
} Unk0210bfbc;

// Returned by func_0210e128 and passed to func_0210bcf4; func_0210c084 writes its byte at 0x19.
// func_0210bf24 subtracts one Unk02017328 from mUnk_10 to reach the Unk0210bfbc holding it.
typedef struct Unk0210bf24 {
    /* 00 */ Unk0212c400 *mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ Unk02017328 *mUnk_10;
    /* 14 */ s16 mUnk_14;
    /* 16 */ u16 mUnk_16;
    /* 18 */ u8 mUnk_18;
    /* 19 */ u8 mUnk_19;
    /* 1a */ u8 mUnk_1a;
} Unk0210bf24;

// Object at 0x20 of Unk0210bcf4: words at 0x08 and 0x0c.
typedef struct Unk0210bcf4_20 {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
} Unk0210bcf4_20;

// Held on the stack by func_0210bcf4 and func_0210ca4c and passed to the three functions
// data_0217d018, data_0217d014 and data_0217d01c point at.
typedef struct Unk0210bcf4 {
    /* 00 */ Unk0210bfbc *mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ s32 mUnk_08;
    /* 0c */ s32 mUnk_0c;
    /* 10 */ s32 mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
    /* 20 */ Unk0210bcf4_20 *mUnk_20;
} Unk0210bcf4;

void func_0210c0bc(Unk0210bfbc *p);
void func_0210c084(Unk0210bf24 *p, u32 b);
void func_0210bfbc(Unk0210bfbc *p);
void func_0210bf24(u32 a, u32 b, u32 c, u32 d);
u32 func_0210bee8(u32 a, u32 b, u32 c, u32 d, u32 e);
u32 func_0210bcf4(u32 a, u32 b, u32 c, u32 d, u32 e);
