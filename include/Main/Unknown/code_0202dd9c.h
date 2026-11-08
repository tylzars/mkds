#pragma once

#include "types.h"
#include "Main/Unknown/unk_021759c0.h" // MinuteSecondMillisecondTime

typedef struct SelectCharacter SelectCharacter;

unsigned int GetSlotGhostCount(void);
unsigned int GetCourseGhostCount(void);
unsigned int GetGhostCount(void);
unsigned int GetSlotGhostBuffer(void);
void *GetCourseGhostBuffer(void);
void PrintGhostRecordInfo(SelectCharacter *fileSets, s16 (*labelRows)[4], void *name, s32 characterIndex, s32 kartIndex,
                          s32 courseId, MinuteSecondMillisecondTime *time);
void func_0202dec8(void);
void ReleaseGhostScene(void);
void AdvanceGhostScene(s32 sceneNumbers);
void InitGhostScene(void *heap);
