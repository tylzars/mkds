#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_020ed5c0.h" // KartModelsEntry

void *GetKartModelResMdl(u32 kartIndex);

KartModelsEntry *GetKartModelsEntry(u32 kartIndex);
