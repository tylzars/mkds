#pragma once

#include "types.h"

typedef struct TextCanvas TextCanvas;

typedef void PixelSetFunc(u16 *a, s32 b, s32 c, s32 d);

typedef struct InputSlotPair InputSlotPair;

// The bounds of a rectangle, passed by value to IsNewPairInRect.
typedef struct PairRect {
    /* 00 */ u16 mMinX;
    /* 02 */ u16 mMinY;
    /* 04 */ u16 mMaxX;
    /* 06 */ u16 mMaxY;
} PairRect;

typedef struct InputSlotPair InputSlotPair;

void FindMissionTableCell(u32 value, u8 *outRow, u8 *outColumn);

typedef struct InputSlot InputSlot;

extern u32 gCupCourseIds[];

void PlotNibblePixels(const u16 *sourcePixels, u16 *dest, s32 colorForValue1, s32 colorForValue2,
                      PixelSetFunc *pixelSetFunc);
void SetPixel2Bit(u16 *pixels, s32 pixelX, s32 pixelY, s32 value);
void RenderKartEntryName(u32 entryIndex);
void DrawTextOnCanvas(TextCanvas *textCanvas, s32 textX, s32 textY, u32 color, u32 flags, void *text);
void InitTextCanvas(TextCanvas *textCanvas, void *charCanvas, void *font, s32 charSpacing, s32 lineSpacing);
void CopyKartEntryName(u32 entryIndex, u16 *nameOut, u32 c);
int GetKartEntryNumber(int entryIndex);
BOOL func_020ae114(u32 entryIndex);
u32 func_020ae15c(u32 entryIndex);
BOOL IsNewPairInRect(u32 slotIndex, PairRect pairRect);
BOOL IsSlotPairNew(u32 slotIndex);
BOOL func_020ae2b0(InputSlotPair *inputSlotPair);
BOOL IsPairNew(InputSlotPair *inputSlotPair);
BOOL func_020ae308(InputSlotPair *inputSlotPair);
unsigned int func_020ae338(InputSlotPair *inputSlotPair);
u32 GetCupCourseId(s32 cupIndex, s32 courseIndex);
u32 func_020ae3b4(u32 limit);
u16 GetRepeatBits(u32 slotIndex, u32 mask);
u16 func_020ae444(InputSlot *inputSlot, u32 mask);
u16 GetNewBits(u32 slotIndex, u32 mask);
u16 func_020ae474(InputSlot *inputSlot, u32 mask);
s16 func_020ae488(s32 frame);
s16 InterpolateS16(s32 mode, s16 start, s16 end, s32 elapsedFrames, s32 durationFrames);
s32 func_020ae54c(s32 value);
s32 func_020ae554(s32 value, s32 factor);
s16 func_020ae564(s32 angle);
s32 func_020ae584(s32 index);
u16 AllocOamMatrixIndex(void *oamList);
