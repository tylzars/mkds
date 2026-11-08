#pragma once

#include "types.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02056b30.h"

// 0x03-byte argument of IsDateEarlier.
typedef struct Unk0203b0a0 {
    /* 00 */ u8 mUnk_00;
    /* 01 */ u8 mUnk_01;
    /* 02 */ u8 mUnk_02;
} Unk0203b0a0;

BOOL IsDateEarlier(const Unk0203b0a0 *firstDate, const Unk0203b0a0 *secondDate);
void func_0203b0f8(void *heap);
void func_0203b194(void *heap);
void func_0203b1c8(void *heap);
void func_0203b1fc(void *heap);
u32 TrySetMissionRecord(void);
BOOL TrySetGrandPrixRecord(void);
BOOL ShouldSetGrandPrixRecord(TimeRecord *storedRecord, TimeRecord *newRecord);
void FillGrandPrixRecord(TimeRecord *record);
void SumTimes(TimeRecord *firstTime, Unk0217aa1c_144_00 *secondTime, TimeRecord *sum);

#include "00/code_021832d8.h"
