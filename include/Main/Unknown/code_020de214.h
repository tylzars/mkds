#pragma once

#include "types.h"

typedef struct Unk020e43a8 Unk020e43a8;
typedef struct Unk020de000 Unk020de000;
typedef struct Unk020de2d8 Unk020de2d8;
typedef struct Unk020de334 Unk020de334;
typedef struct Unk020de390 Unk020de390;

void InitEarthenPipe(Unk020e43a8 *pipe);
Unk020de390 *CreateWanwanChainKindData(void);
Unk020de334 *CreateWanwanChainDrawList(void);
Unk020de2d8 *CreateWanwanChainUpdateList(void);
void DrawWanwanChain(void *unused, Unk020de000 *chainObject, s32 c, u16 d);
void UpdateWanwanChain(void *unused, Unk020de000 *chainObject);
