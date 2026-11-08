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
    /* 000 */ LinkFollowingItemObject mUnk_000;
    /* 228 */ struct KartItems *mKartItems;
    /* 22c */ Vec3 mUnk_22c;
    /* 238 */ s32 mUnk_238;
    /* 23c */ Unk020e005c_080 mStateMachine;
    /* 250 */ s32 mUnk_250;
    /* 254 */ s32 mThrowForward;
    /* 258 */ SoundDistanceSquaredChange mUnk_258;
    /* 268 */ u8 mUnk_268[0xc];
} ItemKouraR;

// Object of item kind 2, element of gItemPools[2].
typedef struct ItemBanana {
    /* 000 */ BouncingItemObject mUnk_000;
    /* 130 */ s32 mThrowForward;
} ItemBanana;

// Object of the green shell (item kind 0), element of gItemPools[0].
typedef struct ItemKouraG {
    /* 000 */ DirectedItemObject mUnk_000;
    /* 168 */ s32 mUnk_168;
    /* 16c */ SoundDistanceSquaredChange mUnk_16c;
    /* 17c */ u8 mUnk_17c[0xc];
} ItemKouraG;

#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_020f1d70.h"
#include "Main/Unknown/code_020e005c.h"
#include "Main/Unknown/code_0210b000.h" // SoundDistanceSquaredChange

void StartNextHeldItemObject(HeldItem *heldItem);
void InitHeldItem(HeldItem *heldItem, KartItems *kartItems);
void CreateItemInfos(void);
void StartBouncingItemKinoko(void **kinokoSlot, Vec3 *b, s32 timer);
void func_020f4e78(ItemKinoko *kinoko, Vec3 *normal, Vec3 *pos);
ItemKinoko *StartItemKinokoOrZero(void);
void AdvanceBouncingItemKinoko(ItemKinoko *kinoko);
void AdvanceRestingItemKinoko(ItemKinoko *kinoko);
void DrawItemKinoko(ItemKinoko *kinoko, void *b, void *c);
void ResetItemKinoko(ItemKinoko *kinoko);
void StartItemKinokoBoost(ItemInUse *itemInUse, HeldItem *heldItem);
void InitItemBananaFromData(ItemBanana *banana);
void *func_020f5108(void *buffer, ItemBanana *banana, void *toBuffer);
void AdvanceItemBanana(ItemBanana *banana);
s32 InitItemBanana(ItemInUse *itemInUse, ItemBanana *banana);
BOOL func_020f5324(void *kouraParam, s32 kartIndex);
void InitItemKouraRFromData(ItemKouraR *kouraR);
void *func_020f5550(void *buffer, ItemKouraR *kouraR, void *toBuffer);
void func_020f5614(void *kouraParam, s32 hitType, ItemObject *otherParam);
void UpdateItemKouraRState6(ItemKouraR *kouraR);
void UpdateItemKouraRState5(ItemKouraR *kouraR);
void UpdateItemKouraRState4(ItemKouraR *kouraR);
void EnterItemKouraRState4(ItemKouraR *kouraR);
s32 InitItemKouraR(ItemInUse *itemInUse, ItemKouraR *kouraR);
void func_020f5f7c(ItemKouraR *kouraR, Vec3 *otherVelocity, Vec3 *normal);
void StartItemKouraRSound(void *kouraParam, s32 b);
void InitItemKouraGFromData(ItemKouraG *koura);
void *func_020f6038(void *buffer, ItemKouraG *koura, void *toBuffer);
void AdvanceItemKouraG(ItemKouraG *koura);
BOOL InitItemKouraG(ItemInUse *itemInUse, ItemKouraG *koura);
void StartItemKouraGSound(void *kouraParam, s32 b);
void StartItemStar(ItemInUse *itemInUse, HeldItem *heldItem);
void StartItemThunder(ItemInUse *itemInUse, HeldItem *heldItem);
void func_020f6388(ItemObject *item, Vec3 *otherVelocity, Vec3 *normal);
void AdvanceFallingItemObject(ItemObject *item);
void StartFallingItemObject(ItemObject *item);
void func_020f6630(ItemObject *itemParam, s32 pushStrength, Vec3 *fromPos, Vec3 *fromVelocity, Vec3 *normal);
void func_020f6830(ItemObject *item, Vec3 *otherVelocity, Vec3 *normal);
void AdvanceRestingItemObject(ItemObject *item);
void StartRestingItemObject(ItemObject *item, void *b);
