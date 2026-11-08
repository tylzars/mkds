#pragma once

#include "types.h"

typedef struct BlockTransferRecord BlockTransferRecord;
typedef struct Unk0217aa00_24_50 Unk0217aa00_24_50;

void func_0204ea94(BlockTransferRecord *record);
void func_0204ead0(u16 a, s32 b);
BOOL func_0204eb08(void *destination);
BOOL TryGetScanGhostInfo(u8 entryIndex, void *destination, u8 *kartIndex, u8 *characterIndex, u8 *courseId, u8 *minute,
                         u8 *second, u16 *millisecond);
void SetScanGhostInfo(u32 entryIndex, Unk0217aa00_24_50 *gameInfo);
void func_0204eca0(void);
