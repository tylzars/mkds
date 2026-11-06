#pragma once

#include "types.h"
#include "code_02021db0.h" // Unk02021dc8, Unk02021e40

void NNS_G2dUnpackNCE(Unk02021dc8 *bank);
Unk02021e40 *NNS_G2dGetCellDataByIdx(Unk02021dc8 *bank, u32 idx);
Unk02021e40 *GetPtrOamArrayHead_(Unk02021dc8 *bank);
