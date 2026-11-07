#pragma once

#include "types.h"

void CreateSeqRowHeap(void *heapMemory, u32 heapSize);
u32 LoadSeqRowIfChanged(s32 index);
