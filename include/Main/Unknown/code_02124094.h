#pragma once

#include "types.h"
#include "g2d_NAN_load.h" // Unk02021dc8
#include "code_02022030.h" // Unk020224e0_c, Unk020224e0_s
#include "code_0201ea58.h" // Unk0201ea30

// 8-byte elements from offset 8 of an Unk0201ea30 (func_0201ea30 indexes them).
typedef struct CellLayoutEntry {
    /* 00 */ union {
        u32 mUnk_00;
        struct {
            Unk0201ea84 mUnk_00_0;
            Unk0201ea84 mUnk_00_2;
        };
    };
    /* 04 */ u32 mCellIndex;
} CellLayoutEntry;

// 0x24 bytes at member 0x20 of LabelCanvas (func_02125808 takes its address).
typedef struct LabelTextCanvas {
    /* 00 */ struct LabelCanvas *mCharCanvas;
    /* 04 */ struct Unk02022aa8 *mFont;
    /* 08 */ s32 mCharSpacing;
    /* 0c */ s32 mLineSpacing;
    /* 10 */ void *mUnk_10;
    /* 14 */ s32 mUnk_14;
    /* 18 */ s32 mUnk_18;
    /* 1c */ s32 mUnk_1c;
    /* 20 */ s32 mUnk_20;
} LabelTextCanvas;

// Object of 0x48 bytes allocated by InitLabelCanvas.
typedef struct LabelCanvas {
    /* 00 */ u8 mUnk_00[0x18];
    /* 18 */ void (*mUnk_18)(struct LabelCanvas *a, s32 b);
    /* 1c */ u8 mUnk_1c[0x4];
    /* 20 */ LabelTextCanvas mUnk_20;
    /* 44 */ Unk020224e0_c *mUnk_44;
} LabelCanvas;

// 0x40-byte element of the tables InitLayoutTable allocates and InitLayoutTableEntries sets up: behind
// WiFiVSMatching.mUnk_10d4, members 0x14, 0x24 and 0x3c of RecordVSErase, and the tables of the objects behind
// gRecordVS to gSelectRaceRuleWait and of several overlay globals.
typedef struct LayoutTableEntry {
    /* 00 */ s32 mVisible;
    /* 04 */ s16 mOffsetX;
    /* 06 */ s16 mOffsetY;
    /* 08 */ BOOL mUnk_08;
    /* 0c */ s16 mPositionX;
    /* 0e */ s16 mPositionY;
    /* 10 */ s32 mUseMatrix;
    /* 14 */ s32 mUnk_14[4];
    /* 24 */ s32 mMatrix[4];
    /* 34 */ s32 mUnk_34;
    /* 38 */ s32 mLabelIndex;
    /* 3c */ LabelCanvas *mLabelCanvas;
} LayoutTableEntry;

// 8-byte elements InitLabelCanvas fills and copies into Unk020224e0_s elements.
typedef struct Unk02022eb0 {
    /* 00 */ union {
        u32 mUnk_00;
        struct {
            u16 mUnk_00_0;
            u16 mUnk_00_2;
        };
    };
    /* 04 */ u16 mUnk_04;
    /* 06 */ u16 mUnk_06;
} Unk02022eb0;

// 12-byte elements of the array func_0201ea58 indexes.
typedef struct LabelLayoutEntry {
    /* 00 */ Unk0201ea84 mUnk_00;
    /* 02 */ Unk0201ea84 mUnk_02;
    /* 04 */ s8 mUnk_04;
    /* 05 */ s8 mUnk_05;
    /* 06 */ u16 mUnk_06_0 : 8;
    /* 06 */ u16 mUnk_06_8 : 4;
    /* 06 */ u16 mUnk_06_12 : 4;
    /* 08 */ u8 mUnk_08[4];
} LabelLayoutEntry;

// Object whose mUnk_14 is the base address QueueCellCharsAndFirstPalette, QueueCellChars and func_0212481c add offsets
// to.
typedef struct Unk0212463c_c {
    /* 00 */ u8 mUnk_00[0x14];
    /* 14 */ u8 *mUnk_14;
} Unk0212463c_c;

// Object whose mUnk_0c is the base address QueueCellCharsAndFirstPalette and func_0212481c add an offset to.
typedef struct Unk0212463c_d {
    /* 00 */ u8 mUnk_00[0xc];
    /* 0c */ u8 *mUnk_0c;
} Unk0212463c_d;

BOOL func_02124ae4(s32 index, Unk02021dc8 *cells, Unk0201ea30 *cellLayout);
void SetLayoutEntryAngleAndScale(LayoutTableEntry *entry, s32 angle, s32 scale);
void func_02124a98(u32 index, s32 value, Unk02021dc8 *cells, Unk0201ea30 *cellLayout);
u8 GetCellPaletteIndex(u32 index, Unk02021dc8 *cells, Unk0201ea30 *cellLayout);
void SetCellPaletteIndex(s32 index, s32 paletteIndex, Unk02021dc8 *cells, Unk0201ea30 *cellLayout);
u8 func_021249f0(s32 index, Unk02021dc8 *cells, Unk0201ea30 *cellLayout);
void func_021249a8(u32 index, u32 value, Unk02021dc8 *cells, Unk0201ea30 *cellLayout);
u16 GetCellCharIndex(u32 index, Unk02021dc8 *cells, Unk0201ea30 *cellLayout);
void func_0212481c(u32 index, Unk02021dc8 *cells, Unk0212463c_c *chars, Unk0212463c_d *palette, Unk0201ea30 *cellLayout,
                   s32 queueSelector, u32 destIndex, Unk02021dc8 *destCells, Unk0201ea30 *destCellLayout);
void QueueCellChars(u32 index, Unk02021dc8 *cells, void *chars, Unk0201ea30 *cellLayout, s32 queueSelector,
                    u32 destIndex, Unk02021dc8 *destCells, Unk0201ea30 *destCellLayout);
void QueueCellCharsAndFirstPalette(u32 index, Unk02021dc8 *cells, Unk0212463c_c *chars, Unk0212463c_d *palette,
                                   Unk0201ea30 *cellLayout, s32 queueSelector, u32 destIndex, Unk02021dc8 *destCells,
                                   Unk0201ea30 *destCellLayout);
s32 InitLabelCanvas(void *heap, s32 labelIndex, Unk0201ea30 *labelLayout, s32 width, s32 height, s32 entryIndex,
                    Unk02021dc8 *cells, Unk0201ea30 *cellLayout, LayoutTableEntry *table, s32 j);
void PrintLabelLayoutText(s32 queueSelector, s32 labelIndex, Unk0201ea30 *labelLayout, void *text,
                          Unk0201ea30 *cellLayout, LayoutTableEntry *table, s32 g, s8 h);
void func_0212426c(s32 queueSelector, s32 labelIndex, Unk0201ea30 *labelLayout, void *text, Unk0201ea30 *cellLayout,
                   LayoutTableEntry *table);
void func_02124248(s32 queueSelector, s32 labelIndex, Unk0201ea30 *labelLayout, void *text, Unk0201ea30 *cellLayout,
                   LayoutTableEntry *table, s8 g);
void func_02124224(s32 queueSelector, u32 labelIndex, Unk0201ea30 *labelLayout, void *text, Unk0201ea30 *cellLayout,
                   LayoutTableEntry *table, s8 g);
void ClearAndQueueLabelLayoutText(s32 queueSelector, s32 labelIndex, Unk0201ea30 *labelLayout, Unk0201ea30 *cellLayout,
                                  LayoutTableEntry *table);
BOOL func_0212418c(s32 labelIndex, void *b, LayoutTableEntry *table, Unk0201ea30 *cellLayout);
void func_02124140(u32 labelIndex, u32 value, Unk0201ea30 *labelLayout, LayoutTableEntry *table,
                   Unk0201ea30 *cellLayout);
void SetLabelPaletteIndex(s32 labelIndex, u8 paletteIndex, Unk0201ea30 *labelLayout, LayoutTableEntry *table,
                          Unk0201ea30 *cellLayout);
u8 func_021240d4(s32 labelIndex, void *b, LayoutTableEntry *table, Unk0201ea30 *cellLayout);
void func_02124094(u32 labelIndex, u32 value, Unk0201ea30 *labelLayout, LayoutTableEntry *table,
                   Unk0201ea30 *cellLayout);
