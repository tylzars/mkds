#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx43
#include "code_02010c84.h" // NNSG3dRS
#include "01/code_02188950.h"
#include "01/code_0218d520.h"

extern MtxFx43 data_0217c600;

extern MtxFx43 gJgPreviousInverseMatrix;

extern MtxFx43 gJgInverseMatrix;

extern MtxFx43 gJgMatrix;

void func_ov001_02187d14(NNSG3dRS *renderState);
void *StartItemBombWithParkedKuribo(void);
void *StartItemBombWithParkedItemBox(u16 a);
void IncrementEntryGroupIndex(Unk02188950 *mapObject, s32 groupSpan);
