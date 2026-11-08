#pragma once

#include "types.h"

typedef struct EmblemBlockData EmblemBlockData;

void ReadBackupEmblemBlock(EmblemBlockData *blockData, s32 blockIndex);
void WriteBackupEmblemBlock(EmblemBlockData *blockData, s32 blockIndex);
