#pragma once

#include "types.h"

s32 IsSelectReturnState0NoState1Request(void);
s32 IsSelectReturnState2NoState3Or4Request(void);
void RequestSelectReturnState4(void);
void RequestSelectReturnState3WithSound(s32 requestState4);
void RequestSelectReturnState1(void);
void WriteSelectReturnRegisters(void);
void AdvanceSelectReturn(void);
void AdvanceSelectReturnState4(void);
void AdvanceSelectReturnState3(void);
