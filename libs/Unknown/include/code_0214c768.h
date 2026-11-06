#pragma once

#include "types.h"

// Stores its argument as one byte at 0x4000247. The video bank functions write the bytes 0x4000240-0x4000246, 0x4000248
// and 0x4000249 and skip this one; the only caller (MI_Init) passes 3.
void MI_SetWramBank(u32 bank);
