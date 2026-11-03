#pragma once

#include "types.h"

s32 IsSelectReturnState0NoState1Request(void);
s32 IsSelectReturnState2NoState3Or4Request(void);
void func_021282c8(void);
void func_02128310(s32 a);
void func_02128374(void);
void WriteSelectReturnRegisters(void);
void AdvanceSelectReturn(void);
void AdvanceSelectReturnState4(void);
void AdvanceSelectReturnState3(void);
