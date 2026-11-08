#pragma once

#include "types.h"

typedef struct GhostRecord GhostRecord;

void ReadBackupSlotGhost(u32 index, GhostRecord *ghostRecord);
void WriteBackupSlotGhost(s32 index, const void *record);
void ReadBackupCourseGhost(u8 index, GhostRecord *ghostRecord);
void WriteBackupCourseGhost(u32 index, const void *record);
