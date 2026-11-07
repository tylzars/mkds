#pragma once

#include "types.h"
#include "Main/Unknown/code_020f2dac.h"

// Kinoko: the mushroom. Object of item kind 3, element of gItemPools[3].
typedef struct ItemKinoko {
    /* 000 */ BouncingItemObject mUnk_000;
    /* 130 */ s32 mTimer;
    /* 134 */ BOOL mVisible;
} ItemKinoko;

typedef struct ItemKinoko ItemKinoko;

#include "Main/Unknown/code_020ec8bc.h"

// Koura: a shell. Object of the red shell (item kind 1), element of gItemPools[1].
typedef struct ItemKouraR {
    /* 000 */ Unk020ec8bc mUnk_000;
    /* 228 */ struct KartItems *mKartItems;
    /* 22c */ Vec3 mUnk_22c;
    /* 238 */ s32 mUnk_238;
    /* 23c */ Unk020e005c_080 mStateMachine;
    /* 250 */ s32 mUnk_250;
    /* 254 */ s32 mThrowForward;
    /* 258 */ Unk0210b7ec mUnk_258;
    /* 268 */ u8 mUnk_268[0xc];
} ItemKouraR;

// Object of item kind 2, element of gItemPools[2].
typedef struct ItemBanana {
    /* 000 */ BouncingItemObject mUnk_000;
    /* 130 */ s32 mThrowForward;
} ItemBanana;

// Object of the green shell (item kind 0), element of gItemPools[0].
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

void StartNextHeldItemObject(HeldItem *a);
void InitHeldItem(HeldItem *a, KartItems *b);
void CreateItemInfos(void);
void StartBouncingItemKinoko(void **a, Vec3 *b, s32 c);
void func_020f4e78(ItemKinoko *a, Vec3 *b, Vec3 *c);
ItemKinoko *StartItemKinokoOrZero(void);
void AdvanceBouncingItemKinoko(ItemKinoko *a);
void AdvanceRestingItemKinoko(ItemKinoko *a);
void DrawItemKinoko(ItemKinoko *a, void *b, void *c);
void ResetItemKinoko(ItemKinoko *p0);
void StartItemKinokoBoost(ItemInUse *a, HeldItem *b);
void InitItemBananaFromData(ItemBanana *a);
void *func_020f5108(void *a, ItemBanana *b, void *c);
void AdvanceItemBanana(ItemBanana *a);
s32 InitItemBanana(ItemInUse *a, ItemBanana *b);
BOOL func_020f5324(void *a0, s32 b);
void InitItemKouraRFromData(ItemKouraR *a);
void *func_020f5550(void *a, ItemKouraR *b, void *c);
void func_020f5614(void *a0, s32 b, ItemObject *c0);
void UpdateItemKouraRState6(ItemKouraR *a);
void UpdateItemKouraRState5(ItemKouraR *a);
void UpdateItemKouraRState4(ItemKouraR *a);
void EnterItemKouraRState4(ItemKouraR *p0);
s32 InitItemKouraR(ItemInUse *a, ItemKouraR *b);
void func_020f5f7c(ItemKouraR *a, Vec3 *b, Vec3 *c);
void StartItemKouraRSound(void *a0, s32 b);
void InitItemKouraGFromData(ItemKouraG *a);
void *func_020f6038(void *a, ItemKouraG *b, void *c);
void AdvanceItemKouraG(ItemKouraG *a);
BOOL InitItemKouraG(ItemInUse *a, ItemKouraG *b);
void StartItemKouraGSound(void *a0, s32 b);
void StartItemStar(ItemInUse *a, HeldItem *b);
void StartItemThunder(ItemInUse *a, HeldItem *b);
void func_020f6388(ItemObject *a, Vec3 *b, Vec3 *c);
void AdvanceFallingItemObject(ItemObject *a);
void StartFallingItemObject(ItemObject *a);
void func_020f6630(ItemObject *a0, s32 b, Vec3 *c, Vec3 *d, Vec3 *e);
void func_020f6830(ItemObject *a, Vec3 *b, Vec3 *c);
void AdvanceRestingItemObject(ItemObject *a);
void StartRestingItemObject(ItemObject *a, void *b);
