#pragma once

#include "types.h"

void InitBlockEntries(void *heap, s32 mode);
void func_0204f33c(void *heap);
void StartChildSideBlockTransfer(void);
void StartParentSideBlockTransfer(void);
void AddPendingFile(const void *path, void *heap, void **dataOutput, u32 value, s32 uncompress);
