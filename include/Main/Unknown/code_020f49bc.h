#pragma once

#include "types.h"
#include "Main/Unknown/code_020f2dac.h"

// Object of item kind 3, element of gItemPools[3].
typedef struct ItemKinoko {
    /* 000 */ Unk020f2df0 mUnk_000;
    /* 130 */ s32 mUnk_130;
    /* 134 */ BOOL mUnk_134;
} ItemKinoko;

typedef struct ItemKinoko ItemKinoko;

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

// Object of item kind 2, element of gItemPools[2].
typedef struct ItemBanana {
    /* 000 */ Unk020f2df0 mUnk_000;
    /* 130 */ s32 mUnk_130;
} ItemBanana;

// Object of item kind 0, element of gItemPools[0].
typedef struct ItemKouraG {
    /* 000 */ Unk020f1d70 mUnk_000;
    /* 168 */ s32 mUnk_168;
    /* 16c */ Unk0210b7ec mUnk_16c;
    /* 17c */ u8 mUnk_17c[0xc];
} ItemKouraG;

#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f1d70.h"
#include "Main/Unknown/code_020e005c.h"
#include "Main/Unknown/code_0210b000.h" // Unk0210b7ec

void func_020f49bc(Unk020f40dc *a);
void InitHeldItem(Unk020f40dc *a, KartItems *b);
void CreateItemInfos(void);
void func_020f4dfc(void **a, Vec3 *b, s32 c);
void func_020f4e78(ItemKinoko *a, Vec3 *b, Vec3 *c);
ItemKinoko *StartItemKinokoOrZero(void);
void func_020f4f44(ItemKinoko *a);
void func_020f4fd0(ItemKinoko *a);
void DrawItemKinoko(ItemKinoko *a, void *b, void *c);
void func_020f5040(ItemKinoko *p0);
void func_020f504c(Unk020eda5c *a, Unk020f40dc *b);
void func_020f50b4(ItemBanana *a);
void *func_020f5108(void *a, ItemBanana *b, void *c);
void AdvanceItemBanana(ItemBanana *a);
s32 InitItemBanana(Unk020eda5c *a, ItemBanana *b);
BOOL func_020f5324(void *a0, s32 b);
void func_020f53d0(ItemKouraR *a);
void *func_020f5550(void *a, ItemKouraR *b, void *c);
void func_020f5614(void *a0, s32 b, ItemObject *c0);
void UpdateItemKouraRState6(ItemKouraR *a);
void UpdateItemKouraRState5(ItemKouraR *a);
void UpdateItemKouraRState4(ItemKouraR *a);
void EnterItemKouraRState4(ItemKouraR *p0);
s32 InitItemKouraR(Unk020eda5c *a, ItemKouraR *b);
void func_020f5f7c(ItemKouraR *a, Vec3 *b, Vec3 *c);
void func_020f5fb8(void *a0, s32 b);
void func_020f5ffc(ItemKouraG *a);
void *func_020f6038(void *a, ItemKouraG *b, void *c);
void AdvanceItemKouraG(ItemKouraG *a);
BOOL InitItemKouraG(Unk020eda5c *a, ItemKouraG *b);
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
