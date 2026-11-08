#pragma once

#include "types.h"
#include "03/code_021d1770.h"

u8 GetOamRangeEntryCount(OamRange *range);
OamEntry *GetOamRangeEntry(OamRange *range, int index);
