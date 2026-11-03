#pragma once

#include "types.h"

typedef struct Unk02150a10 Unk02150a10;

// Function pointer that func_02150dc8 switches between func_02150994 and func_02150e1c.
extern void (*data_0216f26c)(Unk02150a10 *ctx, u8 *data, int n);

u32 func_02150dc8(u32 v);
