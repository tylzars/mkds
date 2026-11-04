#pragma once

#include "types.h"

typedef struct Unk021a8f84 Unk021a8f84;

// Entry of the list behind data_ov000_021b4e5c; the function at 0x18 takes the arguments of the entry's type.
typedef union Unk021969d8Func {
    void (*mUnk_00)(u32 a, u32 b, s32 c, const u8 *d, u32 e);
    void (*mUnk_01)(u32 a, u32 b, u32 c, u32 d, s32 e, s32 f, const u8 *g, s32 h, u32 i);
    void (*mUnk_02)(u32 a, u32 b, u32 c, u32 d, s32 e, s32 f, u32 g);
    void (*mUnk_03)(u32 a, u32 b, s32 c, u32 d);
} Unk021969d8Func;

typedef struct Unk021969d8Entry {
    /* 00 */ s32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ Unk021969d8Func mUnk_18;
} Unk021969d8Entry;

typedef struct Unk02196960Key {
    /* 00 */ u8 mUnk_00[0x10];
} Unk02196960Key;

// Entry of the list at data_ov000_021b4e5c; only the words read here.
typedef struct Unk02196d84 {
    /* 00 */ s32 mUnk_00;
    /* 04 */ s32 mUnk_04;
    /* 08 */ s32 mUnk_08;
} Unk02196d84;

// Record appended to the list at data_ov000_021b4e5c by func_ov000_02197020.
typedef struct Unk02197020 {
    /* 00 */ u32 mUnk_00;
    /* 04 */ u32 mUnk_04;
    /* 08 */ u32 mUnk_08;
    /* 0c */ u32 mUnk_0c;
    /* 10 */ u32 mUnk_10;
    /* 14 */ u32 mUnk_14;
    /* 18 */ UnkFunc *mUnk_18;
} Unk02197020;

typedef struct Unk021b3c08 {
    /* 00 */ s8 mUnk_00[0x3f];
} Unk021b3c08;

typedef struct Unk021b3b68 {
    /* 00 */ s8 mUnk_00[0x10];
} Unk021b3b68;

typedef struct Unk021b3c88 {
    /* 00 */ s8 mUnk_00[0x100];
} Unk021b3c88;

void GstatsClose(void);

typedef struct Unk021b3bdc {
    /* 00 */ s8 mUnk_00[0x2c];
} Unk021b3bdc;

extern s32 data_ov000_021b3b2c;
extern u8 *data_ov000_021b3b30;
extern u32 data_ov000_021b3b34;
extern char data_ov000_021b3b38[];
extern char data_ov000_021b3b40[];
extern const Unk021b3b68 data_ov000_021b3b68;
extern Unk02196960Key data_ov000_021b3b78;
extern u8 data_ov000_021b3b88[];
extern u8 data_ov000_021b3b98[];
extern const Unk021b3bdc data_ov000_021b3bdc;
extern const Unk021b3c08 data_ov000_021b3c08;
extern const Unk021b3c88 data_ov000_021b3c88;
extern char data_ov000_021b3db8[];
extern char data_ov000_021b3dc0[];
extern const char data_ov000_021b3dc4[];
extern char data_ov000_021b3dc8[];
extern char data_ov000_021b3dcc[];
extern char data_ov000_021b3dd4[];
extern char data_ov000_021b3ddc[];
extern const s8 data_ov000_021b3de4[];
extern char data_ov000_021b3de8[];
extern const char data_ov000_021b3df0[];
extern const char data_ov000_021b3df8[];
extern const char data_ov000_021b3e00[];
extern const char data_ov000_021b3e04[];
extern const char data_ov000_021b3e0c[];
extern u32 data_ov000_021b4e4c;
extern void *data_ov000_021b4e5c;
extern s32 data_ov000_021b4e70;
extern char data_ov000_021b4e84[];
extern char data_ov000_021b4f84[];
extern s8 data_ov000_021b5084[];

void func_ov000_02196960(void);
void func_ov000_021969d8(s32 a, s32 b, s32 c, const u8 *d, s32 e);
s32 func_ov000_02196a84(u8 *a, s32 b);
void func_ov000_02196ae0(u8 *a, s32 b);
void func_ov000_02196b90(u8 *e, s32 f);
void func_ov000_02196c00(u8 *f, s32 g);
void func_ov000_02196ca4(u8 *c, s32 d);
void func_ov000_02196d0c(u8 *f, s32 g);
s32 func_ov000_02196d84(s32 a, s32 b, s32 c);
const s8 *func_ov000_02196df0(const s8 *a, s32 b);
u32 func_ov000_02196e48(u32 arg0);
void func_ov000_02196e50(s32 a, s32 b, s32 c, s32 d, const u8 *e, s32 f, UnkFunc *g, s32 h, s32 i);
void func_ov000_02196f8c(s8 *a, s32 b, s32 c, UnkFunc *d, s32 e);
void func_ov000_02197020(s32 a, s32 b, s32 c, s32 d, s32 e, UnkFunc *f, s32 g);
BOOL func_ov000_02197064(const s8 *a, u32 b, u8 *c, Unk021a8f84 **d);
const s8 *func_ov000_021970e4(const s8 *text, const char *key);
const s8 *func_ov000_021970fc(const s8 *text, const char *key);
void func_ov000_02197190(u32 a, s8 *b);
int func_ov000_021971c8(const s8 *a, int b);
void func_ov000_021971ec(s8 *a, s32 b);
s32 func_ov000_02197220(s8 *a, s32 b);
s32 func_ov000_021972b4(void);
s32 func_ov000_0219735c(const s8 *a, u32 b);
