#pragma once

#include "types.h"

typedef struct Unk02180728 Unk02180728;

typedef void PixelSetFunc(u16 *a, s32 b, s32 c, s32 d);

typedef struct Unk02175628_48 Unk02175628_48;

// The bounds of a rectangle, passed by value to IsNewPairInRect.
typedef struct PairRect {
    /* 00 */ u16 mMinX;
    /* 02 */ u16 mMinY;
    /* 04 */ u16 mMaxX;
    /* 06 */ u16 mMaxY;
} PairRect;

typedef struct Unk02175628_48 Unk02175628_48;

void FindMissionTableCell(u32 value, u8 *outRow, u8 *outColumn);

typedef struct InputSlot InputSlot;

extern u32 gCupCourseIds[];

void PlotNibblePixels(const u16 *a, u16 *b, s32 c, s32 d, PixelSetFunc *e);
void SetPixel2Bit(u16 *a, s32 b, s32 c, s32 d);
void RenderKartEntryName(u32 a);
void DrawTextOnCanvas(Unk02180728 *a, s32 b, s32 c, u32 d, u32 e, void *f);
void InitTextCanvas(Unk02180728 *a, void *b, void *c, s32 d, s32 e);
void CopyKartEntryName(u32 a, u16 *b, u32 c);
int GetKartEntryNumber(int arg0);
u32 func_020ae114(u32 a);
u32 func_020ae15c(u32 arg0);
u32 IsNewPairInRect(u32 a, PairRect b);
u32 IsSlotPairNew(u32 a);
u32 func_020ae2b0(Unk02175628_48 *a);
u32 IsPairNew(Unk02175628_48 *a);
u32 func_020ae308(Unk02175628_48 *a);
unsigned int func_020ae338(Unk02175628_48 *p0);
u32 GetCupCourseId(s32 a, s32 b);
u32 func_020ae3b4(u32 a);
u16 GetRepeatBits(u32 a, u32 b);
u16 func_020ae444(InputSlot *a, u32 b);
u16 GetNewBits(u32 a, u32 b);
u16 func_020ae474(InputSlot *a, u32 b);
s16 func_020ae488(s32 a);
s16 InterpolateS16(s32 a, s16 b, s16 c, s32 d, s32 e);
s32 func_020ae54c(s32 a);
s32 func_020ae554(s32 a, s32 b);
s16 func_020ae564(s32 a);
s32 func_020ae584(s32 a);
u16 func_020ae5c4(void *a);
