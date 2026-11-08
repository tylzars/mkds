#pragma once

#include "types.h"

typedef struct OamEntry OamEntry;

void *CreateOamEntryFromNceImage(u32 screen, u32 imageIndex);
void CopyNceImageToOamEntries(u32 slot, u32 imageIndex, OamEntry *destination);
void FreeNceFile(u32 slot);
void LoadNceFile(u32 slot, const u8 *path);
