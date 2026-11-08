#pragma once

#include "types.h"

void WriteSelectKartRegisters(void);
void WriteSubWin0HV(u32 startX, u32 startY, u32 endX, u32 endY);
u32 WriteSubWinOutBits(u32 lowBits, u32 extraBitFlag);
u32 WriteSubWinInBits(u32 lowBits, u32 extraBitFlag);
u32 func_02027fb8(u32 bits);
void WriteSubBlendAlpha(u32 firstPlane, u32 secondPlane, u32 firstCoefficient, u32 secondCoefficient);
void WriteSubBg3CntBits(u32 bits);
void func_0202802c(u32 offsetX, u32 offsetY);
u32 func_02028058(u32 bits);
u32 func_02028074(u32 bits);
void ReleaseSelectKart(void);
u32 func_020280dc(void);
u32 func_020280e8(void);
u16 *func_02028110(void);
unsigned int func_0202811c(void);
