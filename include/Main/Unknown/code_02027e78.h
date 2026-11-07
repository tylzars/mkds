#pragma once

#include "types.h"

void WriteSelectKartRegisters(void);
void WriteSubWin0HV(u32 a, u32 b, u32 c, u32 d);
u32 WriteSubWinOutBits(u32 arg0, u32 arg1);
u32 WriteSubWinInBits(u32 arg0, u32 arg1);
u32 func_02027fb8(u32 arg0);
void WriteSubBlendAlpha(u32 a, u32 b, u32 c, u32 d);
void WriteSubBg3CntBits(u32 a);
void func_0202802c(u32 a, u32 b);
u32 func_02028058(u32 arg0);
u32 func_02028074(u32 arg0);
void ReleaseSelectKart(void);
u32 func_020280dc(void);
u32 func_020280e8(void);
u16 *func_02028110(void);
unsigned int func_0202811c(void);
