#pragma once

#include "types.h"

typedef struct NNSiFndHeapHead NNSiFndHeapHead;

extern NNSiFndHeapHead *gExpHeap;

void FreeExpHeapBlock(void *block);
void FreeExpHeapBlockAndClearPointer(void *storage);
void *AllocZeroedExpHeapBlock(u32 size, s32 alignment);
void *AllocExpHeapBlock(u32 size, s32 alignment);
void ReleaseExpHeap(void);
void CreateExpHeapOverBuffer(void *buffer);
