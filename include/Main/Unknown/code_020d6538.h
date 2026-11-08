#pragma once

#include "types.h"

// Object func_020d6538 fills from 0x5c on; only the words it writes are seen.
typedef struct Unk020d6538_a {
    /* 00 */ u8 pad_00[0x5c];
    /* 5c */ u32 mUnk_5c;
    /* 60 */ u8 pad_60[4];
    /* 64 */ u32 mUnk_64;
    /* 68 */ u32 mUnk_68;
    /* 6c */ u32 mUnk_6c;
} Unk020d6538_a;

#include "Main/Unknown/code_020f36d8.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020e6fd4.h"

// Second half of the 0x5c-byte object behind data_0217b650: the words from 0x2c, then three more.
typedef struct RockShadowMatrix {
    /* 00 */ s32 mUnk_00[9];
    /* 24 */ Vec3 mUnk_24;
} RockShadowMatrix;

// 0x5c-byte object that CreateRock2DrawList and CreateRockDrawList allocate and fill from a table; func_020d49d8 stores
// the address of its pointer at 0x28.
typedef struct RockDrawList {
    /* 00 */ u8 mUnk_00[0x28];
    /* 28 */ struct RockDrawList **mUnk_28;
    /* 2c */ RockShadowMatrix mUnk_2c;
} RockDrawList;

// 0x28-byte object that CreateRockUpdateList allocates and fills from a table; SetUpdateListSlot stores the address of
// its pointer at 0x24.
typedef struct RockUpdateList {
    /* 00 */ u8 mUnk_00[0x24];
    /* 24 */ struct RockUpdateList **mUnk_24;
} RockUpdateList;

#include "Main/Unknown/code_020d50ec.h" // EmitterParams, RockObject

void func_020d6538(Unk020d6538_a *emitter, EmitterParams *params);
void func_020d655c(void *a, RockObject *rock, void *c, s32 alpha);
void SetupDrawRock(void);
RockUpdateList *CreateRockUpdateList(void);
RockDrawList *CreateRock2DrawList(void);
RockDrawList *CreateRockDrawList(void);
MapObjectKindData *CreateRockKindData(void);
s32 func_020d6910(s32 itemKind, MapObject *mapObject);
// 1 when the ItemObject kind a has a response to the map object b, else 0.
s32 DoesItemObjectRespondToMapObject(s32 itemKind, MapObject *mapObject);
// 1 when the Kart item effect a has a response to the map object b, else 0.
s32 DoesKartRespondToMapObject(s32 itemEffect, MapObject *mapObject);
// Response code for the ItemObject a and the map object b; the kind's own callback may change it; the second value goes
// to *c.
s32 func_020d6a54(ItemObject *itemObject, MapObject *mapObject, s32 *firstResponseOut);
// Index into gCollideKartWithMapObjectResponses of the Kart a response to the map object b; the kind's own callback may
// change it.
s32 func_020d6be0(Kart *kart, MapObject *mapObject);
u32 GetItemObjectResponseByKind(s32 flagBit, s32 itemKind, s32 kindHundreds, s32 kindRemainder, s32 kindDataValue);
u32 func_020d6d8c(u32 zeroResultFlag, u32 itemKind, u32 kindHundreds, u32 kindRemainder);
