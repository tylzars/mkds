#pragma once

#include "types.h"

u32 WriteNvramEntriesWithCrc16(int data);
u32 WriteFlaggedNvramEntries(int data, int *flags, void *verifyBuffer);
u32 ReadNvramEntries(void *buffer);
u32 ReadNvramEntriesOffset(u16 *buffer);
