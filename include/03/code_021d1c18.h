#pragma once

#include "types.h"

void *CreateOamEntryFromNceImage(u32 screen, u32 imageIndex);
void CopyNceImageToOamEntries(u32 slot, u32 imageIndex, u8 *destination);
void FreeNceFile(u32 slot);
void LoadNceFile(u32 slot, const u8 *path);
