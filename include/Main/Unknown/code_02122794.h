#pragma once

#include "types.h"

u32 GetKartMaskBitOfPackedIndex(u8 packedIndex);
u32 GetKartMaskBit(u32 index);
void UpdateWiFiSessionKartTimeouts(void);
void RemoveWiFiSessionKarts(void);
void func_02122ab0(void);
