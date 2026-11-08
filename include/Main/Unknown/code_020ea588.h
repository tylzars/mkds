#pragma once

#include "types.h"

typedef struct NsbmdModel NsbmdModel;

void func_020ea5b0(NsbmdModel *model, u32 maxAlpha, Vec3 *position);
void CreateNsbmd(void **slot, void *file, void *unused);
