#pragma once

#include "types.h"

u32 SetScanBssidCallbacks(UnkFunc *setCallback, UnkFunc *clearCallback);
void SetEntryTable(void *entryTable);
