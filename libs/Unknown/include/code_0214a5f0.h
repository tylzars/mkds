#pragma once

#include "types.h"

s32 GxStatTryReadBit13(u32 *a);
s32 GxStatTryReadBits8To12(u32 *a);
// Zeroes 16 bytes at 0x4000330 and 96 bytes at 0x4000360, with the DMA channel in the first word of data_0216f074
// (MI_DmaFill32Async, then MI_DmaFill32) when that word is not -1 and with MemFillWords otherwise, then writes 0 to
// 0x40004d0 thirty-two times.
void G3X_InitTable(void);
void ClearColorDepthWrite(u32 a, u32 b, u16 c, u32 d, s32 e);
