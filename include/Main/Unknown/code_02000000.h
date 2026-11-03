#pragma once

#include "types.h"

void CpuSet(const void *src, void *dst, u32 ctrl);
void WaitByLoop(s32 n);
void VBlankIntrWait(void);
