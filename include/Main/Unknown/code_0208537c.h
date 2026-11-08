#pragma once

#include "types.h"
#include "Main/Unknown/unk_0217a000.h"

RandomState64 *GetKartAiRandom(void);
BOOL func_02085390(void);
s32 GetKartRaceProgressScaled(u32 kartIndex);
unsigned int func_020853dc(void);
unsigned int GetKartAiTableIndex(unsigned int kartIndex);
s32 GetKartIndexAtRank(unsigned int rank);
KartAiParamRow *GetKartAiParamRow(void);
s32 func_02085434(void);
s32 func_02085458(s32 a);
s32 GetFirstKind1KartByRank(void);
s32 func_0208548c(void);
s32 func_020854a0(unsigned int p0, unsigned int p1);
s32 GetKartRankAmongKind1(u16 kartIndex);
void UpdateKartAiRankLists(void);
void UpdateKartAiShared(void);
s16 func_02085824(u32 kartIndex);
void DecrementKartAiNonCpuCount(u32 kartIndex);
s32 PickKartAiTableIndex(u16 kartIndex, u32 *nextNonCpuTableIndexPointer);
void InitKartAiTableIndices(void);
void func_02085bec(void);
void InitKartAiNonCpuCounts(void);
void InitKartAiShared(void);
void SetKartAiParamRow(void);
