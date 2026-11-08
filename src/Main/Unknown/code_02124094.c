#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02036820.h"
#include "code_0200eddc.h"
#include "g2d_NOB_load.h"
#include "Main/Unknown/code_02022000.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_02124f4c.h"
#include "Main/Unknown/code_02125000.h"
#include "code_02016468.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_020b4000.h"
#include "g2d_CharCanvas.h"
#include "code_02146cb0.h"
#include "Main/Unknown/unk_0215d000.h"
#include "code_02147cd8.h"
#include "gx.h"

#pragma thumb on

void SetLayoutEntryAngleAndScale(LayoutTableEntry *entry, s32 angle, s32 scale) {
    s32 pairIndex;
    s32 *dividedValues;
    s32 *matrix;
    s64 inverseScale;
    s32 cosine;
    s32 sine;
    pairIndex = (angle >> 4) * 2;
    dividedValues = entry->mUnk_14;
    matrix = entry->mMatrix;
    inverseScale = FX_Div(0x1000, scale);
    cosine = gPairsByAngle[pairIndex + 1];
    entry->mUnk_14[0] = ((s64) cosine * inverseScale) >> 12;
    sine = gPairsByAngle[pairIndex];
    dividedValues[1] = ((s64) sine * inverseScale) >> 12;
    dividedValues[2] = -dividedValues[1];
    dividedValues[3] = entry->mUnk_14[0];
    MTX_Rot22_(matrix, sine, cosine);
    entry->mMatrix[0] = FX_MulFunc(entry->mMatrix[0], scale);
    matrix[1] = FX_MulFunc(matrix[1], scale);
    matrix[2] = FX_MulFunc(matrix[2], scale);
    matrix[3] = FX_MulFunc(matrix[3], scale);
}

BOOL func_02124ae4(s32 index, Unk02021dc8 *cells, Unk0201ea30 *cellLayout) {
    Unk020224e0_c *cellData;
    CellLayoutEntry *cellEntry;
    cellEntry = (CellLayoutEntry *) (cellLayout + 1);
    cellEntry += index;
    cellData = NNS_G2dGetCellDataByIdx(cells, (u16) cellEntry->mCellIndex);
    if ((cellData->mUnk_04->mUnk_00 & 0xc00) >> 10 == 1) {
        return TRUE;
    }
    return FALSE;
}

void func_02124a98(u32 index, s32 value, Unk02021dc8 *cells, Unk0201ea30 *cellLayout) {
    Unk020224e0_c *cellData;
    CellLayoutEntry *cellEntry;
    s32 i;
    Unk020224e0_s *oamEntry;
    cellEntry = (CellLayoutEntry *) (cellLayout + 1);
    cellEntry += index;
    cellData = NNS_G2dGetCellDataByIdx(cells, (u16) cellEntry->mCellIndex);
    oamEntry = cellData->mUnk_04;
    for (i = 0; i < cellData->mUnk_00; i++) {
        oamEntry->mUnk_00 &= ~0xc00;
        if (value != 0) {
            oamEntry->mUnk_00 |= 0x400;
        }
        oamEntry++;
    }
}

u8 GetCellPaletteIndex(u32 index, Unk02021dc8 *cells, Unk0201ea30 *cellLayout) {
    Unk020224e0_c *cellData;
    CellLayoutEntry *cellEntry;
    cellEntry = (CellLayoutEntry *) (cellLayout + 1);
    cellEntry += index;
    cellData = NNS_G2dGetCellDataByIdx(cells, (u16) cellEntry->mCellIndex);
    return (cellData->mUnk_04->mUnk_04 & 0xf000) >> 12;
}

void SetCellPaletteIndex(s32 index, s32 paletteIndex, Unk02021dc8 *cells, Unk0201ea30 *cellLayout) {
    Unk020224e0_c *cellData;
    CellLayoutEntry *cellEntry;
    s32 i;
    Unk020224e0_s *oamEntry;
    cellEntry = (CellLayoutEntry *) (cellLayout + 1);
    cellEntry += index;
    cellData = NNS_G2dGetCellDataByIdx(cells, (u16) cellEntry->mCellIndex);
    oamEntry = cellData->mUnk_04;
    for (i = 0; i < cellData->mUnk_00; i++) {
        oamEntry->mUnk_04 &= ~0xf000;
        oamEntry->mUnk_04 |= paletteIndex << 12;
        oamEntry++;
    }
}

u8 func_021249f0(s32 index, Unk02021dc8 *cells, Unk0201ea30 *cellLayout) {
    Unk020224e0_c *cellData;
    CellLayoutEntry *cellEntry;
    cellEntry = (CellLayoutEntry *) (cellLayout + 1);
    cellEntry += index;
    cellData = NNS_G2dGetCellDataByIdx(cells, (u16) cellEntry->mCellIndex);
    return (cellData->mUnk_04->mUnk_04 & 0xc00) >> 10;
}

void func_021249a8(u32 index, u32 value, Unk02021dc8 *cells, Unk0201ea30 *cellLayout) {
    Unk020224e0_c *cellData;
    CellLayoutEntry *cellEntry;
    s32 i;
    Unk020224e0_s *oamEntry;
    cellEntry = (CellLayoutEntry *) (cellLayout + 1);
    cellEntry += index;
    cellData = NNS_G2dGetCellDataByIdx(cells, (u16) cellEntry->mCellIndex);
    oamEntry = cellData->mUnk_04;
    for (i = 0; i < cellData->mUnk_00; i++) {
        oamEntry->mUnk_04 &= ~0xc00;
        oamEntry->mUnk_04 |= value << 10;
        oamEntry++;
    }
}

u16 GetCellCharIndex(u32 index, Unk02021dc8 *cells, Unk0201ea30 *cellLayout) {
    Unk020224e0_c *cellData;
    CellLayoutEntry *cellEntry;
    cellEntry = (CellLayoutEntry *) (cellLayout + 1);
    cellEntry += index;
    cellData = NNS_G2dGetCellDataByIdx(cells, (u16) cellEntry->mCellIndex);
    return cellData->mUnk_04->mUnk_04 & 0x3ff;
}

void func_0212481c(u32 index, Unk02021dc8 *cells, Unk0212463c_c *chars, Unk0212463c_d *palette, Unk0201ea30 *cellLayout,
                   s32 queueSelector, u32 destIndex, Unk02021dc8 *destCells, Unk0201ea30 *destCellLayout) {
    u8 usedPalettes[16];
    s32 oamCount;
    s32 destCharOffset;
    u8 *charsSource;
    Unk020224e0_c *cellData;
    s32 j;
    Unk020224e0_c *destCellData;
    Unk020224e0_s *oamEntry;
    CellLayoutEntry *cellEntry;
    CellLayoutEntry *destCellEntry;
    s32 charBytes;
    u32 x;
    u32 y;
    u32 paletteIndex;
    u32 w;
    s32 k;
    s32 runStart;
    s32 runLength;
    u8 *paletteSource;
    s32 runBytes;
    cellEntry = (CellLayoutEntry *) (cellLayout + 1);
    cellEntry += index;
    cellData = NNS_G2dGetCellDataByIdx(cells, (u16) cellEntry->mCellIndex);
    destCellEntry = (CellLayoutEntry *) (destCellLayout + 1);
    destCellEntry += destIndex;
    destCellData = NNS_G2dGetCellDataByIdx(destCells, (u16) destCellEntry->mCellIndex);
    oamCount = cellData->mUnk_00;
    for (k = 0; k < 16; k++) {
        usedPalettes[k] = 0;
    }
    for (j = 0; j < oamCount; j++) {
        w = cellData->mUnk_04[j].mUnk_04;
        destCharOffset = (destCellData->mUnk_04[j].mUnk_04 & 0x3ff) << 5;
        oamEntry = &cellData->mUnk_04[j];
        y = (((u32) oamEntry->mUnk_02 << 16) & 0xc0000000) >> 30;
        x = ((u32) cellData->mUnk_04[j].mUnk_00 & 0xc000) >> 14;
        charBytes = (&data_0215d024[y])[x * 4] << 5;
        charsSource = chars->mUnk_14 + ((w & 0x3ff) << 5);
        DC_FlushRange(charsSource, charBytes);
        if (queueSelector == 0) {
            CallQueueAppend(0x13, destCharOffset, charsSource, charBytes);
        } else {
            CallQueueAppend(0x23, destCharOffset, charsSource, charBytes);
        }
        paletteIndex = (w & 0xf000) >> 12;
        usedPalettes[paletteIndex] = 1;
        destCellData->mUnk_04[j].mUnk_04 &= ~0xf000;
        destCellData->mUnk_04[j].mUnk_04 |= paletteIndex << 12;
    }
    runStart = 0;
    runLength = 0;
    for (k = 0; k < 16; k++) {
        if (usedPalettes[k] != 0 && runStart + runLength < 15) {
            runLength++;
        } else if (runLength > 0) {
            runStart <<= 5;
            paletteSource = palette->mUnk_0c + runStart;
            runBytes = runLength << 5;
            if (queueSelector == 0) {
                CallQueueAppend(0xe, runStart, paletteSource, runBytes);
            } else {
                CallQueueAppend(0x1e, runStart, paletteSource, runBytes);
            }
            runStart = k + 1;
            runLength = 0;
        } else {
            runStart = k + 1;
        }
    }
}

void QueueCellChars(u32 index, Unk02021dc8 *cells, void *chars, Unk0201ea30 *cellLayout, s32 queueSelector,
                    u32 destIndex, Unk02021dc8 *destCells, Unk0201ea30 *destCellLayout) {
    s32 i;
    Unk020224e0_c *cellData;
    Unk020224e0_c *destCellData;
    Unk020224e0_s *oamEntry;
    CellLayoutEntry *cellEntry;
    CellLayoutEntry *destCellEntry;
    s32 oamCount;
    u8 *charsSource;
    s32 destCharOffset;
    s32 charBytes;
    u32 t;
    u32 x;
    cellEntry = (CellLayoutEntry *) (cellLayout + 1);
    cellEntry += index;
    cellData = NNS_G2dGetCellDataByIdx(cells, (u16) cellEntry->mCellIndex);
    destCellEntry = (CellLayoutEntry *) (destCellLayout + 1);
    destCellEntry += destIndex;
    destCellData = NNS_G2dGetCellDataByIdx(destCells, (u16) destCellEntry->mCellIndex);
    i = 0;
    oamCount = cellData->mUnk_00;
    for (; i < oamCount; i++) {
        destCharOffset = (destCellData->mUnk_04[i].mUnk_04 & 0x3ff) << 5;
        oamEntry = &cellData->mUnk_04[i];
        t = (((u32) oamEntry->mUnk_02 << 16) & 0xc0000000) >> 30;
        x = ((u32) cellData->mUnk_04[i].mUnk_00 & 0xc000) >> 14;
        charBytes = (&data_0215d024[t])[x * 4] << 5;
        charsSource = ((Unk0212463c_c *) chars)->mUnk_14 + ((oamEntry->mUnk_04 & 0x3ff) << 5);
        DC_FlushRange(charsSource, charBytes);
        if (queueSelector == 0) {
            CallQueueAppend(0x13, destCharOffset, charsSource, charBytes);
        } else {
            CallQueueAppend(0x23, destCharOffset, charsSource, charBytes);
        }
    }
}

void QueueCellCharsAndFirstPalette(u32 index, Unk02021dc8 *cells, Unk0212463c_c *chars, Unk0212463c_d *palette,
                                   Unk0201ea30 *cellLayout, s32 queueSelector, u32 destIndex, Unk02021dc8 *destCells,
                                   Unk0201ea30 *destCellLayout) {
    s32 j;
    Unk020224e0_c *cellData;
    Unk020224e0_c *destCellData;
    Unk020224e0_s *oamEntry;
    CellLayoutEntry *cellEntry;
    CellLayoutEntry *destCellEntry;
    s32 oamCount;
    u8 *charsSource;
    s32 destCharOffset;
    s32 charBytes;
    u32 x;
    u32 y;
    u32 queueCommand;
    u32 destPaletteOffset;
    u8 *paletteSource;
    cellEntry = (CellLayoutEntry *) (cellLayout + 1);
    cellEntry += index;
    cellData = NNS_G2dGetCellDataByIdx(cells, (u16) cellEntry->mCellIndex);
    destCellEntry = (CellLayoutEntry *) (destCellLayout + 1);
    destCellEntry += destIndex;
    destCellData = NNS_G2dGetCellDataByIdx(destCells, (u16) destCellEntry->mCellIndex);
    j = 0;
    oamCount = cellData->mUnk_00;
    for (; j < oamCount; j++) {
        destCharOffset = (destCellData->mUnk_04[j].mUnk_04 & 0x3ff) << 5;
        oamEntry = &cellData->mUnk_04[j];
        y = (((u32) oamEntry->mUnk_02 << 16) & 0xc0000000) >> 30;
        x = ((u32) cellData->mUnk_04[j].mUnk_00 & 0xc000) >> 14;
        charBytes = (&data_0215d024[y])[x * 4] << 5;
        charsSource = chars->mUnk_14 + ((oamEntry->mUnk_04 & 0x3ff) << 5);
        DC_FlushRange(charsSource, charBytes);
        if (queueSelector == 0) {
            CallQueueAppend(0x13, destCharOffset, charsSource, charBytes);
        } else {
            CallQueueAppend(0x23, destCharOffset, charsSource, charBytes);
        }
    }
    destPaletteOffset = (((u32) destCellData->mUnk_04->mUnk_04 & 0xf000) >> 12) << 5;
    paletteSource = palette->mUnk_0c + ((((u32) cellData->mUnk_04->mUnk_04 & 0xf000) >> 12) << 5);
    if (queueSelector == 0) {
        queueCommand = 0xe;
    } else {
        queueCommand = 0x1e;
    }
    CallQueueAppend(queueCommand, destPaletteOffset, paletteSource, 0x20);
}

s32 InitLabelCanvas(void *heap, s32 labelIndex, Unk0201ea30 *labelLayout, s32 width, s32 height, s32 entryIndex,
                    Unk02021dc8 *cells, Unk0201ea30 *cellLayout, LayoutTableEntry *table, s32 j) {
    Unk02022eb0 oamBuffer[128];
    LabelLayoutEntry *labelEntry;
    LabelCanvas *canvas;
    Unk020224e0_c *cellData;
    s32 widthBlocks;
    s32 heightBlocks;
    s32 blockCount;
    s32 oamCount;
    s32 k;
    s32 m;
    s32 n;
    s32 u;
    s32 v;
    s32 sa;
    s32 sb;
    s32 cellEntryCount;
    void *font;
    cellEntryCount = cellLayout->mUnk_06;
    table[entryIndex].mLabelIndex = labelIndex;
    canvas = HeapAlloc(heap, 0x48);
    table[cellEntryCount + labelIndex].mLabelCanvas = canvas;
    labelEntry = func_0201ea58(labelLayout, labelIndex);
    widthBlocks = ((width - 1) >> 3) + 1;
    heightBlocks = ((height - 1) >> 3) + 1;
    blockCount = widthBlocks * heightBlocks;
    canvas->mUnk_20.mUnk_14 = blockCount << 5;
    canvas->mUnk_20.mUnk_18 = ((j - 0x100) >> 5) - blockCount;
    canvas->mUnk_20.mUnk_10 = HeapAlloc(heap, canvas->mUnk_20.mUnk_14);
    NNS_G2dCharCanvasInitForOBJ1D(canvas, canvas->mUnk_20.mUnk_10, widthBlocks, heightBlocks, 4);
    canvas->mUnk_18(canvas, 0);
    sb = labelEntry->mUnk_05;
    sa = labelEntry->mUnk_04;
    font = GetFontByIndex(labelEntry->mUnk_06_12);
    canvas->mUnk_20.mCharCanvas = canvas;
    canvas->mUnk_20.mFont = font;
    canvas->mUnk_20.mCharSpacing = sa;
    canvas->mUnk_20.mLineSpacing = sb;
    canvas->mUnk_20.mUnk_1c = width;
    canvas->mUnk_20.mUnk_20 = height;
    m = 0;
    n = 0;
    if (entryIndex < cellEntryCount) {
        u = func_021249f0(entryIndex, cells, cellLayout);
        v = func_02124ae4(entryIndex, cells, cellLayout);
    } else {
        entryIndex -= cellEntryCount;
        u = func_021240d4(entryIndex, labelLayout, table, cellLayout);
        v = func_0212418c(entryIndex, labelLayout, table, cellLayout);
    }
    switch (labelEntry->mUnk_00.mUnk_00_12) {
        case 1:
            m = -(widthBlocks << 2);
            break;
        case 2:
            m = -(widthBlocks << 3);
            break;
    }
    switch (labelEntry->mUnk_02.mUnk_00_12) {
        case 1:
            n = -(heightBlocks << 2);
            break;
        case 2:
            n = -(heightBlocks << 3);
            break;
    }
    oamCount = NNS_G2dArrangeOBJ1D(oamBuffer, widthBlocks, heightBlocks, m, n, 0, canvas->mUnk_20.mUnk_18, 0);
    cellData = HeapAlloc(heap, oamCount * 6 + 0x10);
    cellData->mUnk_00 = oamCount;
    cellData->mUnk_02 = 0;
    cellData->mUnk_04 = (Unk020224e0_s *) (cellData + 1);
    cellData->mUnk_08 = widthBlocks << 2;
    cellData->mUnk_0a = heightBlocks << 2;
    cellData->mUnk_0c = -widthBlocks << 2;
    cellData->mUnk_0e = -heightBlocks << 2;
    for (k = 0; k < oamCount; k++) {
        oamBuffer[k].mUnk_04 = (oamBuffer[k].mUnk_04 & ~0xc00) | (u * 0x400);
        if (v != 0) {
            m = labelEntry->mUnk_06_8;
            oamBuffer[k].mUnk_00 = (oamBuffer[k].mUnk_00 & ~0xc00) | 0x400;
            oamBuffer[k].mUnk_04 = (oamBuffer[k].mUnk_04 & ~0xf000) | (m * 0x1000);
        } else {
            m = labelEntry->mUnk_06_8;
            oamBuffer[k].mUnk_00 &= ~0xc00;
            oamBuffer[k].mUnk_04 = (oamBuffer[k].mUnk_04 & ~0xf000) | (m * 0x1000);
        }
        oamBuffer[k].mUnk_00 &= ~0x1000;
        oamBuffer[k].mUnk_00 &= 0xc1fffcff;
        cellData->mUnk_04[k].mUnk_00 = oamBuffer[k].mUnk_00_0;
        cellData->mUnk_04[k].mUnk_02 = oamBuffer[k].mUnk_00_2;
        cellData->mUnk_04[k].mUnk_04 = oamBuffer[k].mUnk_04;
    }
    canvas->mUnk_44 = cellData;
    return canvas->mUnk_20.mUnk_14;
}

// Clears the character canvas of entry b, draws the string d into it and queues its upload.
void PrintLabelLayoutText(s32 queueSelector, s32 labelIndex, Unk0201ea30 *labelLayout, void *text,
                          Unk0201ea30 *cellLayout, LayoutTableEntry *table, s32 g, s8 h) {
    s32 canvasWidth;
    s32 offsetX;
    s32 offsetY;
    LabelLayoutEntry *labelEntry;
    LabelCanvas *canvas;
    s32 alignedWidth;
    s32 alignedHeight;
    s32 canvasHeight;
    u32 flags;
    void *chars;
    s32 destOffset;
    s32 charBytes;
    labelEntry = func_0201ea58(labelLayout, labelIndex);
    canvas = (table + cellLayout->mUnk_06 + labelIndex)->mLabelCanvas;
    canvasWidth = canvas->mUnk_20.mUnk_1c;
    canvasHeight = canvas->mUnk_20.mUnk_20;
    alignedWidth = ((canvasWidth - 1) >> 3) + 1 << 3;
    alignedHeight = ((canvasHeight - 1) >> 3) + 1 << 3;
    flags = 0;
    offsetX = 0;
    offsetY = 0;
    if (labelEntry->mUnk_00.mUnk_00_12 == 0) {
        flags |= 0x200;
    } else if (labelEntry->mUnk_00.mUnk_00_12 == 1) {
        flags |= 0x400;
        offsetX = (alignedWidth - canvasWidth) >> 1;
    } else if (labelEntry->mUnk_00.mUnk_00_12 == 2) {
        flags |= 0x800;
        offsetX = alignedWidth - canvasWidth;
    }
    if (labelEntry->mUnk_02.mUnk_00_12 == 0) {
        flags |= 0x40;
    } else if (labelEntry->mUnk_02.mUnk_00_12 == 1) {
        flags |= 0x80;
        offsetY = (alignedHeight - canvasHeight) >> 1;
    } else if (labelEntry->mUnk_02.mUnk_00_12 == 2) {
        flags |= 0x100;
        offsetY = alignedHeight - canvasHeight;
    }
    canvas->mUnk_18(canvas, 0);
    func_02125808(&canvas->mUnk_20, offsetX, offsetY, canvasWidth, canvasHeight, labelEntry->mUnk_06_0, flags,
                  labelEntry->mUnk_00.mUnk_00_14, text, g, h);
    chars = canvas->mUnk_20.mUnk_10;
    destOffset = canvas->mUnk_20.mUnk_18 << 5;
    charBytes = canvas->mUnk_20.mUnk_14;
    DC_FlushRange(chars, charBytes);
    if (queueSelector == 0) {
        CallQueueAppend(0x13, destOffset, chars, charBytes);
    } else {
        CallQueueAppend(0x23, destOffset, chars, charBytes);
    }
}

void func_0212426c(s32 queueSelector, s32 labelIndex, Unk0201ea30 *labelLayout, void *text, Unk0201ea30 *cellLayout,
                   LayoutTableEntry *table) {
    PrintLabelLayoutText(queueSelector, labelIndex, labelLayout, text, cellLayout, table, 0, -1);
}

void func_02124248(s32 queueSelector, s32 labelIndex, Unk0201ea30 *labelLayout, void *text, Unk0201ea30 *cellLayout,
                   LayoutTableEntry *table, s8 g) {
    PrintLabelLayoutText(queueSelector, labelIndex, labelLayout, text, cellLayout, table, 0, g);
}

void func_02124224(s32 queueSelector, u32 labelIndex, Unk0201ea30 *labelLayout, void *text, Unk0201ea30 *cellLayout,
                   LayoutTableEntry *table, s8 g) {
    PrintLabelLayoutText(queueSelector, labelIndex, labelLayout, text, cellLayout, table, 1, g);
}

// Clears the character canvas of entry b and queues its upload.
void ClearAndQueueLabelLayoutText(s32 queueSelector, s32 labelIndex, Unk0201ea30 *labelLayout, Unk0201ea30 *cellLayout,
                                  LayoutTableEntry *table) {
    LabelCanvas *canvas;
    void *chars;
    s32 destOffset;
    s32 charBytes;
    func_0201ea58(labelLayout, labelIndex);
    canvas = (table + cellLayout->mUnk_06 + labelIndex)->mLabelCanvas;
    canvas->mUnk_18(canvas, 0);
    chars = canvas->mUnk_20.mUnk_10;
    destOffset = canvas->mUnk_20.mUnk_18 << 5;
    charBytes = canvas->mUnk_20.mUnk_14;
    DC_FlushRange(chars, charBytes);
    if (queueSelector == 0) {
        CallQueueAppend(0x13, destOffset, chars, charBytes);
    } else {
        CallQueueAppend(0x23, destOffset, chars, charBytes);
    }
}

BOOL func_0212418c(s32 labelIndex, void *b, LayoutTableEntry *table, Unk0201ea30 *cellLayout) {
    LayoutTableEntry *entry;
    LayoutTableEntry *labelTableEntry;
    entry = table + labelIndex;
    labelTableEntry = entry + cellLayout->mUnk_06;
    if ((labelTableEntry->mLabelCanvas->mUnk_44->mUnk_04->mUnk_00 & 0xc00) >> 10 == 1) {
        return TRUE;
    }
    return FALSE;
}

void func_02124140(u32 labelIndex, u32 value, Unk0201ea30 *labelLayout, LayoutTableEntry *table,
                   Unk0201ea30 *cellLayout) {
    LayoutTableEntry *labelTableEntry;
    LayoutTableEntry *entry;
    s32 i;
    Unk020224e0_c *cellData;
    Unk020224e0_s *oamEntry;
    entry = table + labelIndex;
    labelTableEntry = entry + cellLayout->mUnk_06;
    cellData = labelTableEntry->mLabelCanvas->mUnk_44;
    oamEntry = cellData->mUnk_04;
    for (i = 0; i < cellData->mUnk_00; i++) {
        oamEntry->mUnk_00 &= ~0xc00;
        if (value != 0) {
            oamEntry->mUnk_00 |= 0x400;
        }
        oamEntry++;
    }
}

void SetLabelPaletteIndex(s32 labelIndex, u8 paletteIndex, Unk0201ea30 *labelLayout, LayoutTableEntry *table,
                          Unk0201ea30 *cellLayout) {
    LayoutTableEntry *labelTableEntry;
    LayoutTableEntry *entry;
    s32 i;
    Unk020224e0_c *cellData;
    Unk020224e0_s *oamEntry;
    entry = table + labelIndex;
    labelTableEntry = entry + cellLayout->mUnk_06;
    cellData = labelTableEntry->mLabelCanvas->mUnk_44;
    oamEntry = cellData->mUnk_04;
    for (i = 0; i < cellData->mUnk_00; i++) {
        oamEntry->mUnk_04 &= ~0xf000;
        oamEntry->mUnk_04 |= paletteIndex << 12;
        oamEntry++;
    }
}

u8 func_021240d4(s32 labelIndex, void *b, LayoutTableEntry *table, Unk0201ea30 *cellLayout) {
    LayoutTableEntry *entry;
    LayoutTableEntry *labelTableEntry;
    entry = table + labelIndex;
    labelTableEntry = entry + cellLayout->mUnk_06;
    return (labelTableEntry->mLabelCanvas->mUnk_44->mUnk_04->mUnk_04 & 0xc00) >> 10;
}

void func_02124094(u32 labelIndex, u32 value, Unk0201ea30 *labelLayout, LayoutTableEntry *table,
                   Unk0201ea30 *cellLayout) {
    LayoutTableEntry *labelTableEntry;
    LayoutTableEntry *entry;
    s32 i;
    Unk020224e0_c *cellData;
    Unk020224e0_s *oamEntry;
    entry = table + labelIndex;
    labelTableEntry = entry + cellLayout->mUnk_06;
    cellData = labelTableEntry->mLabelCanvas->mUnk_44;
    oamEntry = cellData->mUnk_04;
    for (i = 0; i < cellData->mUnk_00; i++) {
        oamEntry->mUnk_04 &= ~0xc00;
        oamEntry->mUnk_04 |= value << 10;
        oamEntry++;
    }
}

#pragma thumb off
