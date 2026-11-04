#pragma once

#include "types.h"

typedef struct Unk021d8dc8 Unk021d8dc8;

typedef struct Unk021bbd70 Unk021bbd70;

typedef struct Unk021bbd70 {
    /* 00 */ u32 mUnk_00[4];
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ u8 mUnk_18[0x40];
} Unk021bbd70;

// Five, thirteen and sixteen bytes moved as one value.
typedef struct Unk021bd338_5 {
    /* 0 */ u8 mUnk_00[5];
} Unk021bd338_5;

typedef struct Unk021bd338_13 {
    /* 0 */ u8 mUnk_00[13];
} Unk021bd338_13;

typedef struct Unk021bd338_16 {
    /* 0 */ u8 mUnk_00[16];
} Unk021bd338_16;

#include "03/unk_021d8000.h"

// Eight bytes passed by address.
typedef struct Unk021bdcd8 {
    /* 0 */ u8 mUnk_00;
    /* 1 */ u8 mUnk_01;
    /* 2 */ u16 mUnk_02;
    /* 4 */ u32 mUnk_04;
} Unk021bdcd8;

// Table of 0x30-byte records, mUnk_00 counts them.
typedef struct Unk021bdd3c_Entry {
    /* 00 */ u32 mUnk_00;
    /* 04 */ char mUnk_04[0x20];
    /* 24 */ u8 mUnk_24[4];
    /* 28 */ Unk021d8c54 mUnk_28;
    /* 2e */ u16 mUnk_2e;
} Unk021bdd3c_Entry;

typedef struct Unk021bdd3c {
    /* 0 */ u32 mUnk_00;
    /* 4 */ Unk021bdd3c_Entry mUnk_04[1];
} Unk021bdd3c;

extern u8 data_ov003_021d68dc[];

void func_ov003_021bb03c(void);
u32 func_ov003_021bb058(Unk021d8dc8 *a);
u32 func_ov003_021bb070(u32 *a);
s32 func_ov003_021bb0b0(void);
s32 func_ov003_021bb168(u32 a, s32 b, UnkFunc *c, UnkWordFunc *d, UnkFunc *e, u32 f);
s32 func_ov003_021bb29c(u8 *a, const s8 *b);
s32 func_ov003_021bb2d8(u8 *a, s8 b);
void func_ov003_021bb314(void *p0);
void *func_ov003_021bb328(s32 a, s32 b);
u32 func_ov003_021bb354(void);
void func_ov003_021bb378(u8 *a, const u8 *b, u32 c);
void func_ov003_021bb3a4(void *buffer, s32 value, u32 count);
void func_ov003_021bb3bc(void *a, const void *b, u32 c);
void func_ov003_021bb3d8(u32 *output, const u8 *input, u32 size);
void func_ov003_021bb408(u8 *output, const u32 *input, u32 size);
void func_ov003_021bb438(Unk021bbd70 *a, const u8 *b);
void func_ov003_021bbc94(u8 *a, Unk021bbd70 *b);
void func_ov003_021bbcf0(Unk021bbd70 *a, const u8 *b, u32 c);
void func_ov003_021bbd70(Unk021bbd70 *a);
void func_ov003_021bbd9c(u32 *a, int b, u8 *c, u8 *d);
void func_ov003_021bc1c4(u32 *a, int b, u8 *c, u8 *d);
int func_ov003_021bc5e4(u32 *a, u8 *b, int c);
int func_ov003_021bc7a8(u32 *a, u8 *b, int c);
void func_ov003_021bca90(u8 *a, u8 *b, u8 *c);
int func_ov003_021bcadc(u8 *param_1, u8 *param_2, u32 param_3, u8 *param_4, int param_5);
BOOL func_ov003_021bccd0(u8 *param_1, u8 *param_2, u32 param_3, u8 *param_4, int param_5);
void func_ov003_021bcedc(void);
int func_ov003_021bcf1c(void);
s32 func_ov003_021bd338(void);
BOOL func_ov003_021bd4cc(u8 *a, const s8 *b, s32 c);
s32 func_ov003_021bd59c(u8 *p);
s32 func_ov003_021bd768(u8 *a, void *b);
unsigned int func_ov003_021bd884(void *p);
s32 func_ov003_021bd894(u8 *p);
s32 func_ov003_021bd938(const u8 *p, u32 a, u8 *b, const void *c);
BOOL func_ov003_021bd998(const u8 *p, s32 *a);
s32 func_ov003_021bda78(u8 *p, u32 a, const void *b, u32 c);
u8 *func_ov003_021bdaa4(u8 *p, u32 a, const void *b, u32 c);
s32 func_ov003_021bdb0c(u8 *p, u32 a, u8 *b, u32 c, const void *d);
u8 *func_ov003_021bdbd0(const u8 *p, u32 *a, s32 *b);
u8 *func_ov003_021bdc08(u8 **p, u8 *a, u32 *b, s32 *c);
u8 *func_ov003_021bdc5c(const u8 *p, u32 *a, s32 *b);
s32 func_ov003_021bdccc(s32 descriptor, const void *unused, const void *data, u32 size);
s32 func_ov003_021bdcd8(s32 descriptor, const void *data, u32 size);
s32 func_ov003_021bdd1c(s32 descriptor, const Unk021bdcd8 *address, const u8 *param_2, const void *data, u32 size);
s32 func_ov003_021bdd3c(void);
s32 func_ov003_021be028(Unk021bdd3c *a, Unk021bdd3c *b, u32 *c);
void func_ov003_021be1fc(void);
s32 func_ov003_021be264(void);
u32 func_ov003_021be3b8(void);
s32 func_ov003_021be418(u32 param_0);
void func_ov003_021be4e0(u32 value);
void func_ov003_021be4ec(u32 value, u32 unused);
u32 func_ov003_021be528(void);
void func_ov003_021be568(void);
void func_ov003_021be59c(u32 a, s32 b, s32 c);
u32 func_ov003_021be5cc(u32 a, s32 b);
u32 func_ov003_021be604(void);
