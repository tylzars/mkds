#pragma once

#include "types.h"

typedef struct InputSlot InputSlot;

u32 func_0203033c(u32 lowBits, u32 extraBitFlag);
u32 func_02030364(u32 lowBits, u32 extraBitFlag);
u32 func_0203038c(u32 bits);
u32 func_020303a8(u32 bits);
void ReleaseMultiSelectNS(void);
s32 AdvanceMultiSelectNS(void);
void func_0203062c(u32 index);
void func_0203063c(u32 index, u32 seqArcNo);
void func_02030654(u32 index);
u32 func_02030688(u32 slotIndex, u32 mask);
u16 func_020306a4(InputSlot *slot, u32 mask);
u32 func_020306b8(u32 slotIndex);
unsigned int func_020306d8(unsigned int p0);
u32 func_020306e0(u32 slotIndex);
unsigned int func_02030700(unsigned int p0);
