#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h" // Kart

typedef struct SoundSetPlayer SoundSetPlayer;

void func_0210f9f0(void *kartAddress, int b);
void func_0210f9ac(Kart *kart);
void func_0210f8b0(SoundSetPlayer *player, s32 seqId, s32 firstBankId);
void SetSeqVariableEnabled(u32 slot, u32 enabled);
