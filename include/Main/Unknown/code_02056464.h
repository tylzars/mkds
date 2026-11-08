#pragma once

#include "types.h"
#include "Main/Unknown/unk_021759c0.h" // MinuteSecondMillisecondTime

typedef struct GhostRecord GhostRecord;
typedef struct Unk0217aa00_45c Unk0217aa00_45c;

void FillPlayerRecord(Unk0217aa00_45c *a);
s32 GetGhostFinishTimeByIndex(s32 ghostRecordIndex, MinuteSecondMillisecondTime *finishTime);
s32 GetGhostLapTimeByIndex(s32 ghostRecordIndex, s32 lapNumber, MinuteSecondMillisecondTime *lapTime);
BOOL GetGhostFinishTime(GhostRecord *ghostRecord, MinuteSecondMillisecondTime *finishTime);
s32 GetGhostLapTime(GhostRecord *ghostRecord, s32 lapNumber, MinuteSecondMillisecondTime *lapTime);
void ReadSlotGhostRecord(u32 slotIndex);
