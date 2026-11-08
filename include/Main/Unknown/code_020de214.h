#pragma once

#include "types.h"

typedef struct Unk020e43a8 Unk020e43a8;
typedef struct WanwanChainObject WanwanChainObject;
typedef struct Unk020de2d8 Unk020de2d8;
typedef struct MapObjectDrawList MapObjectDrawList;
typedef struct Unk020de390 Unk020de390;

void InitEarthenPipe(Unk020e43a8 *pipe);
Unk020de390 *CreateWanwanChainKindData(void);
MapObjectDrawList *CreateWanwanChainDrawList(void);
Unk020de2d8 *CreateWanwanChainUpdateList(void);
void DrawWanwanChain(void *unused, WanwanChainObject *chainObject, s32 c, u16 d);
void UpdateWanwanChain(void *unused, WanwanChainObject *chainObject);
