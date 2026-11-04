#pragma once

#include "types.h"

s32 CallQueueAppend(u32, u32, void *, u32);
void CallQueueDrain(void);
void CallQueueInit(void *arg0, u32 arg1);
