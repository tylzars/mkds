#pragma once

#include "types.h"
#include "code_02021db0.h" // Unk02021dc8, Unk02021e40
#include "code_02022030.h" // Unk020224e0_c

void NNS_G2dUnpackNCE(Unk02021dc8 *bank);
Unk020224e0_c *NNS_G2dGetCellDataByIdx(Unk02021dc8 *bank, u32 idx);
Unk02021e40 *GetPtrOamArrayHead_(Unk02021dc8 *bank);
