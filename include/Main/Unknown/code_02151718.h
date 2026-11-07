#pragma once

#include "types.h"

u32 WriteNvramEntriesWithCrc16(int a);
u32 WriteFlaggedNvramEntries(int a, int *b, void *c);
u32 func_02151804(void *a);
u32 func_02151830(u16 *a);
