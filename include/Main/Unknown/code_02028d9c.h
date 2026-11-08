#pragma once

#include "types.h"

typedef struct CellFileSet CellFileSet;
typedef struct Unk0201ea30 Unk0201ea30;

u32 GetOwnEntryIndex(void);
unsigned int GetParticipantEntryIndex(unsigned int participantIndex);
u16 func_02028dd4(void);
void func_02028e00(void *destination, u32 size);
void func_02028e14(void *destination, u32 value, u32 size);
void RefreshKartMenuParamElements(void);
void SetKartMenuParamElementOffset(s32 elementIndex, s32 endCellIndex, s32 paramValue, CellFileSet *parts);
void *func_02028f08(s32 index, Unk0201ea30 *cellLayout);
