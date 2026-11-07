#pragma once

#include "types.h"

void CopyBytesIntoTiles(void *bytes, u8 *tiles, s32 side);
void JoinNibbleTilesIntoBytes(void *tiles, u8 *bytes, s32 side);
void SplitBytesIntoNibbleTiles(void *bytes, u8 *tiles, s32 side);
