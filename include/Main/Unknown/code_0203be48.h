#pragma once

#include "types.h"

void GetEntryCharacterAndKart(u8 *picks, u8 entryIndex, u32 *outCharacterIndex, u32 *outKartIndex);
void SetGivenCharacterAndKart(u8 *picks, u32 entryIndex, u32 characterIndex, u32 kartIndex);
