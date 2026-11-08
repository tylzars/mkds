#pragma once

#include "types.h"

void *GetChoisesSValueMessage(s32 listIndex, s32 value);
void ClearChoisesSListValueCounts(void);
void AppendChoisesSListValue(s32 listIndex, s32 value);
s32 MoveChoisesSSelectedValue(s32 step);
u32 func_020b302c(void);
void ResetChoisesSSelection(void);
void func_020b2f88(s32 openFlag);
u32 func_020b2f58(void);
s8 GetMissionRunTableRow(void);
s8 GetMissionRunTableColumn(void);
u32 func_020b2ecc(void);
