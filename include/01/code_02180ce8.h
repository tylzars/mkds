#pragma once

#include "types.h"

// Two-byte element; FillEmblemGridRegion copies it whole.
typedef struct EmblemGridPoint {
    /* 00 */ u8 mX;
    /* 01 */ u8 mY;
} EmblemGridPoint;

#include "01/code_02181000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_02133000.h"

s32 FillEmblemGridRegion(s32 startX, s32 startY, s32 newValue);
s32 SetEmblemGridLine(s32 x, s32 y, s32 endX, s32 endY, s32 value);
u8 GetEmblemGridCellValue(s32 x, s32 y);
u32 SetEmblemGridCellValue(u32 x, u32 y, u32 value);
void ResetEmblemGridChanges(void);
unsigned int IsEmblemGridChanged(void);
void ClearEmblemGridCopied(void);
unsigned int IsEmblemGridSwapped(void);
void SwapEmblemGridCells(void);
s32 SetEmblemGridCellsFromTable(u8 *indices, u16 *table);
u32 SetEmblemGridCells(u8 *src);
unsigned int GetEmblemGridCells(void);
unsigned int GetEmblemGridCharSize(void);
unsigned int func_ov001_02181194(void);
int GetEmblemGridScrSize(void);
unsigned int func_ov001_021811b8(void);
unsigned int GetEmblemGridScr(void);
void CopyEmblemGridCellsOnFirstChange(void);
u8 *GetEmblemGridCellPtr(s32 x, s32 y);
unsigned int GetEmblemGridSide(void);
void CreateEmblemGrid(s32 side, s32 scrSide, s32 tableCount);
