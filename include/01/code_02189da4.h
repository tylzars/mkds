#pragma once

#include "types.h"
#include "01/code_02188950.h"

typedef struct Unk02188950 Unk02188950;
typedef struct Unk0218d87c Unk0218d87c;
typedef struct Unk0201ca6c Unk0201ca6c;
typedef struct ItemObject ItemObject;

void *CreateBombKingUpdateList(void);
void *CreateBombKingDrawList(void);
void func_ov001_02189dd8(void);
void func_ov001_02189e0c(void *mapObjectList, Unk02188950 *mapObject);
void InitBombKing(Unk0218d87c *list);
void BombKingItemHitCallback(Unk02188950 *mapObject, ItemObject *itemObject);
void func_ov001_02189fe0(Unk02188950 *mapObject, ItemObject *itemObject);
void func_ov001_0218a028(Unk0201ca6c *emitter);
void func_ov001_0218a034(Unk02188950 *mapObject);
void UpdateBombKing(u32 a, Unk02188950 *mapObject);
void InitBombKingObjects(Unk0218d87c *list);
void func_ov001_0218a19c(Unk02188950 *mapObject);
void func_ov001_0218a1d0(Unk02188950 *mapObject);
void func_ov001_0218a20c(Unk02188950 *mapObject);
void func_ov001_0218a250(Unk02188950 *mapObject);
void StartBombKingWaitForRaceStart(Unk02188950 *mapObject);
s32 func_ov001_0218a2b8(Unk02188950 *mapObject);
void func_ov001_0218a2d4(void);
void func_ov001_0218a2dc(Unk02188950 *mapObject);
void func_ov001_0218a30c(Unk02188950 *mapObject);
