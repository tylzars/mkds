#pragma once

#include "types.h"

typedef struct Unk020e43a8 Unk020e43a8;
typedef struct WanwanChainObject WanwanChainObject;
typedef struct MapObjectList MapObjectList;
typedef struct MapObjectDrawList MapObjectDrawList;
typedef struct MapObjectKindData MapObjectKindData;

void InitEarthenPipe(Unk020e43a8 *pipe);
MapObjectKindData *CreateWanwanChainKindData(void);
MapObjectDrawList *CreateWanwanChainDrawList(void);
MapObjectList *CreateWanwanChainUpdateList(void);
void DrawWanwanChain(void *unused, WanwanChainObject *chainObject, s32 c, u16 d);
void UpdateWanwanChain(void *unused, WanwanChainObject *chainObject);
