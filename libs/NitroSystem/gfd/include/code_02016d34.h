#pragma once

#include "types.h"
#include "code_020170e4.h"

void NNS_GfdResetLnkTexVramState(void);
s32 NNS_GfdFreeLnkTexVram(u32 texKey);
u32 NNS_GfdAllocLnkTexVram(u32 szByte, s32 is4x4comp, u32 opt);
void NNS_GfdInitLnkTexVramManager(u32 szByte, u32 szByteFor4x4, void *pManagementWork, u32 szByteManagementWork,
                                  int useAsDefault);
int NNS_GfdGetLnkTexVramManagerWorkSize(int numMemBlk);
