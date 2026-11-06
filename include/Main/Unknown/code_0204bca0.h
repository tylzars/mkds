#pragma once

#include "types.h"
#include "Main/Unknown/code_02006954.h"
#include "Main/Unknown/unk_02175000.h"

typedef struct FSFile FSFile;

// Entry of 0x28 bytes; the table of pointers at the start of the object at 0x440 of data_02175ec0 points to them.
typedef struct Unk0204bfac_28 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ s32 mUnk_04;
    /* 08 */ u8 mUnk_08[0x20];
} Unk0204bfac_28;

// The object at 0x440 of data_02175ec0 as func_0204bfac and func_0204c320 use it: three tables of 16 words, then the
// entries.
typedef struct Unk0204bfac {
    /* 000 */ Unk0204bfac_28 *mUnk_000[16];
    /* 040 */ u32 mUnk_040[16];
    /* 080 */ void *mUnk_080[16];
    /* 0c0 */ Unk0204bfac_28 mUnk_0c0[16];
    /* 340 */ u8 mUnk_340[0x7bc];
    /* afc */ void *mUnk_afc;
    /* b00 */ u32 mUnk_b00;
    /* b04 */ u32 mUnk_b04;
    /* b08 */ s32 mUnk_b08;
} Unk0204bfac;

// Node of 0x8c0 bytes; func_0204c090 chains eight of them from 0xc0 of the object at 0x440 of data_02175ec0.
typedef struct Unk0204c090 {
    /* 000 */ struct Unk0204c090 *mUnk_000;
    /* 004 */ Unk02007014 mUnk_004;
    /* 038 */ FSFile mUnk_038;
    /* 080 */ s32 mUnk_080;
    /* 084 */ s32 mUnk_084;
    /* 088 */ u32 mUnk_088;
    /* 08c */ s32 mUnk_08c;
    /* 090 */ s32 mUnk_090;
    /* 094 */ u32 mUnk_094;
    /* 098 */ s32 mUnk_098;
    /* 09c */ s32 mUnk_09c;
    /* 0a0 */ s32 mUnk_0a0;
    /* 0a4 */ s32 mUnk_0a4[2];
    /* 0ac */ u8 mUnk_0ac[0x14];
    /* 0c0 */ u8 mUnk_0c0[2][0x400];
} Unk0204c090;

// Words at 0x14 of the object that func_0204c320 and func_0204c7e4 receive.
typedef union Unk0204c320_14 {
    u32 mUnk_w;
    struct {
        u16 mUnk_14;
        s16 mUnk_16;
        s16 mUnk_18;
    } h;
    Unk02175ec0_440 mUnk_0e;
    Unk02175ec0_msg mUnk_m;
} Unk0204c320_14;

// Object that func_0204c320 and func_0204c7e4 receive.
typedef struct Unk0204c320 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ u16 mUnk_08;
    /* 0a */ u16 mUnk_0a;
    /* 0c */ u8 mUnk_0c[8];
    /* 14 */ Unk0204c320_14 mUnk_14;
    /* 20 */ s16 mUnk_20;
} Unk0204c320;

// Object that func_0204cc94 receives.
typedef struct Unk0204cc94 {
    /* 00 */ u8 mUnk_00[4];
    /* 04 */ u16 mUnk_04;
    /* 06 */ u8 mUnk_06[6];
    /* 0c */ const u8 *mUnk_0c;
    /* 10 */ u16 mUnk_10;
    /* 12 */ u16 mUnk_12;
} Unk0204cc94;

typedef struct FSFile FSFile;

// Entries of 0x20 bytes after a count word; func_0204d28c reads and rewrites the word at 0x18.
typedef struct Unk0204d28c_20 {
    /* 00 */ u8 mUnk_00[0x18];
    /* 18 */ u32 mUnk_18;
    /* 1c */ u8 mUnk_1c[4];
} Unk0204d28c_20;

void func_0204bca0(void);
u32 func_0204bcb4(u32 arg0);
u32 func_0204bcdc(void);
void func_0204bcec(void);
void func_0204be0c(void);
void func_0204bf48(int a, u32 b, u32 c, void (*d)(s32 a), void *(*e)(s32 a, u32 b, void *c), u32 f);
void func_0204bfac(u32 a, void (*b)(s32 a), void *(*c)(s32 a, u32 b, void *c), u32 d);
void func_0204c090(u32 a, void (*b)(s32 a), void *(*c)(s32 a, u32 b, void *c), u32 d, u32 e, FSFile *f, s32 g);
void func_0204c28c(u32 a, void (*b)(s32 a), void *(*c)(s32 a, u32 b, void *c), u32 d);
void func_0204c320(Unk0204c320 *a);
void func_0204c7e4(Unk0204c320 *a);
void func_0204cc94(Unk0204cc94 *a);
void func_0204ce60(void);
void func_0204cf5c(FSFile *a);
void func_0204d0bc(Unk02175ec0_440s *a, Unk0204c090 *b);
void func_0204d110(Unk0204c090 **a, Unk0204c090 **b, Unk0204c090 *c);
void func_0204d18c(Unk02175ec0_440s *a, Unk0204c090 *b, s32 c);
void func_0204d28c(void);
void func_0204d5bc(void);
u32 func_0204d610(u32 *a);
void func_0204d6f4(FSFile *a, s32 b);
s32 func_0204dab8(FSFile *a, u32 b);
