#pragma once

#include "types.h"
#include "code_0212d214.h"
#include "Main/Unknown/code_0210e33c.h" // Unk0217d178

typedef struct NNSSndHeap NNSSndHeap;

u32 SetupSndArcFromFile(NNSSndArc *arc, const u8 *filePath, NNSSndHeap *heap, u32 symbolLoadFlag);
void ClearSndFileIdList(Unk0217d178 *fileIdList);
void ClearSndFileAddresses(Unk0217d178 *fileIdList);
