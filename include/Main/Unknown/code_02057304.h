#pragma once

#include "types.h"

void ResetBackupFirstBlock(s32 copyOwnerName);
BOOL IsSlotGhostBitSet(u32 bitIndex);
void ClearCourseGhostBit(s32 bitIndex);
BOOL IsCourseGhostBitSet(u8 bitIndex);
void ClearBitArrayBit(s32 bitIndex, u8 *bytes, s32 c);
BOOL IsBitArrayBitSet(s32 bitIndex, u8 *bytes, s32 c);
void SetBitArrayBit(s32 bitIndex, u8 *bytes, s32 c);
