#pragma once

#include "types.h"

void func_0211e0c4(u32 kind);
BOOL func_0211e130(void);
s32 func_0211e160(u32 kind);
s32 GetGhostRecordSetKartIndex(u32 kind);
s32 GetGhostRecordSetCharacterIndex(u32 kind);
void GetGhostRecordSetName(u32 kind, void *name);
void GetGhostRecordSetTime(u32 kind, void *time);
void SetupGhostRecordSetForCourse(u32 courseId);
void ClearGhostRecordSetPointer(void);
void InitGhostRecordSet(void *heap);
