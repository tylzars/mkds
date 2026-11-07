#pragma once

#include "types.h"

typedef struct HeapCall HeapCall;

void *GetHeap(HeapCall *call);
void *GetCurrentHeapCall(void);
u32 RunHeapCall(HeapCall *call, u32 argument);
