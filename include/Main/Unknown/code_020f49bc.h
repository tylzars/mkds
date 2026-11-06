#pragma once

#include "types.h"
#include "Main/Unknown/code_020f2dac.h"

// Element of gItemPools[3]: 0x138 bytes (the size in gItemKinds[3]), handled by func_020f4dfc to
// func_020f5040: the Unk020f2df0 part and words at 0x130 and 0x134.
typedef struct Unk020f5008 {
    /* 000 */ Unk020f2df0 mUnk_000;
    /* 130 */ s32 mUnk_130;
    /* 134 */ BOOL mUnk_134;
} Unk020f5008;

typedef struct Unk020f5008 Unk020f5008;

#include "Main/Unknown/code_020ec8bc.h"

// Object of item kind 1, element of gItemPools[1].
typedef struct ItemKouraR {
    /* 000 */ Unk020ec8bc mUnk_000;
    /* 228 */ struct KartItems *mKartItems;
    /* 22c */ Vec3 mUnk_22c;
    /* 238 */ s32 mUnk_238;
    /* 23c */ Unk020e005c_080 mStateMachine;
    /* 250 */ s32 mUnk_250;
    /* 254 */ s32 mUnk_254;
    /* 258 */ Unk0210b7ec mUnk_258;
    /* 268 */ u8 mUnk_268[0xc];
} ItemKouraR;

// Element of gItemPools[2]: 0x134 bytes (the size in gItemKinds[2]), handled by func_020f50b4 to
// func_020f5240: the Unk020f2df0 part and a word at 0x130.
typedef struct Unk020f5240 {
    /* 000 */ Unk020f2df0 mUnk_000;
    /* 130 */ s32 mUnk_130;
} Unk020f5240;

// Element of gItemPools[0]: 0x188 bytes (the size in gItemKinds[0]), handled by func_020f5ffc to
// func_020f6220: the Unk020f1d70 part, a word at 0x168 and a Unk0210b7ec at 0x16c.
typedef struct Unk020f6150 {
    /* 000 */ Unk020f1d70 mUnk_000;
    /* 168 */ s32 mUnk_168;
    /* 16c */ Unk0210b7ec mUnk_16c;
    /* 17c */ u8 mUnk_17c[0xc];
} Unk020f6150;

#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f1d70.h"
#include "Main/Unknown/code_020e005c.h"
#include "Main/Unknown/code_0210b000.h" // Unk0210b7ec

void func_020f49bc(Unk020f40dc *a);
void func_020f4b20(Unk020f40dc *a, KartItems *b);
void CreateItemInfos(void);
void func_020f4dfc(void **a, Vec3 *b, s32 c);
void func_020f4e78(Unk020f5008 *a, Vec3 *b, Vec3 *c);
Unk020f5008 *func_020f4ee8(void);
void func_020f4f44(Unk020f5008 *a);
void func_020f4fd0(Unk020f5008 *a);
void func_020f5008(Unk020f5008 *a, void *b, void *c);
void func_020f5040(Unk020f5008 *p0);
void func_020f504c(Unk020eda5c *a, Unk020f40dc *b);
void func_020f50b4(Unk020f5240 *a);
void *func_020f5108(void *a, Unk020f5240 *b, void *c);
void func_020f518c(Unk020f5240 *a);
s32 func_020f5240(Unk020eda5c *a, Unk020f5240 *b);
BOOL func_020f5324(void *a0, s32 b);
void func_020f53d0(ItemKouraR *a);
void *func_020f5550(void *a, ItemKouraR *b, void *c);
void func_020f5614(void *a0, s32 b, ItemObject *c0);
void UpdateItemKouraRState6(ItemKouraR *a);
void UpdateItemKouraRState5(ItemKouraR *a);
void UpdateItemKouraRState4(ItemKouraR *a);
void EnterItemKouraRState4(ItemKouraR *p0);
s32 func_020f5d6c(Unk020eda5c *a, ItemKouraR *b);
void func_020f5f7c(ItemKouraR *a, Vec3 *b, Vec3 *c);
void func_020f5fb8(void *a0, s32 b);
void func_020f5ffc(Unk020f6150 *a);
void *func_020f6038(void *a, Unk020f6150 *b, void *c);
void func_020f60d0(Unk020f6150 *a);
BOOL func_020f6150(Unk020eda5c *a, Unk020f6150 *b);
void func_020f6220(void *a0, s32 b);
void func_020f6264(Unk020eda5c *a, Unk020f40dc *b);
void func_020f62b0(Unk020eda5c *a, Unk020f40dc *b);
void func_020f6388(ItemObject *a, Vec3 *b, Vec3 *c);
void func_020f63cc(ItemObject *a);
void func_020f65c4(ItemObject *a);
void func_020f6630(ItemObject *a0, s32 b, Vec3 *c, Vec3 *d, Vec3 *e);
void func_020f6830(ItemObject *a, Vec3 *b, Vec3 *c);
void func_020f68b0(ItemObject *a);
void func_020f6a6c(ItemObject *a, void *b);
