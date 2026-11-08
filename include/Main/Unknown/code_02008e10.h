#pragma once

#include "types.h"
#include "Main/Unknown/code_02008934.h"
#include "Main/Unknown/code_02008dbc.h"
#include "Main/Unknown/code_020091e0.h"

void UpdateEntryFromScan(u8 *scanBlock, u32 entryIndex, u32 c);
void UpdateEntryTimers(EntryCallbackFunc callback, u32 b);
void func_02008ff0(u32 entryIndex, EntryCallbackFunc callback);
s32 FindOrAddEntry(const u8 *scanBlock, EntryCallbackFunc callback);

// Declared here until the code that defines it is decompiled.
