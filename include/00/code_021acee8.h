#pragma once

#include "types.h"

typedef struct Hash16State Hash16State;

void func_ov000_021acee8(Hash16State *ctx, const u8 *src, u32 count);
