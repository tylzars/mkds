#pragma once

#include "types.h"

void WriteWinInOutBits(int screen, int selector, u32 bits, int extraBitFlag);
void WriteWinRect(int screen, int window, u16 *rect);
void ClearDispcntBits(int screen, u32 bits);
void CombineDispcntBits(int screen, u32 bits);
