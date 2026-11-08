#include "01/code_02180ce8.h"

#include "01/unk_021a9000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_02133048.h"
#include "code_02147cd8.h"
#include "code_0214d018.h"
#include "01/code_0218155c.h"
#include "01/code_02188950.h"
#include "01/code_02188e88.h"
#include "01/code_02181000.h"
#include "03/code_021b94b8.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020c0d9c.h"

EmblemGrid *gEmblemGrid;

void CreateEmblemGrid(s32 side, s32 scrSide, s32 tableCount) {
    s32 j;
    s32 i;
    void *heap;

    heap = GetHeap(GetCurrentHeapCall());
    gEmblemGrid = HeapAllocAligned(heap, 0x30, 0x20);
    gEmblemGrid->mSide = side;
    gEmblemGrid->mScrSide = scrSide;
    gEmblemGrid->mTableCount = tableCount;
    heap = GetHeap(GetCurrentHeapCall());
    gEmblemGrid->mUnk_18 = HeapAllocAligned(heap, gEmblemGrid->mTableCount * 2, 0x20);
    heap = GetHeap(GetCurrentHeapCall());
    gEmblemGrid->mBuffers[0] = HeapAllocAligned(heap, gEmblemGrid->mScrSide / 8 * (gEmblemGrid->mScrSide / 8), 0x20);
    MI_CpuFill8(gEmblemGrid->mBuffers[0], gEmblemGrid->mSide / 8 * gEmblemGrid->mSide / 8,
                gEmblemGrid->mScrSide / 8 * (gEmblemGrid->mScrSide / 8));
    for (i = 0; i < gEmblemGrid->mSide / 8; i++) {
        for (j = 0; j < gEmblemGrid->mSide / 8; j++) {
            gEmblemGrid->mBuffers[0][i * gEmblemGrid->mScrSide / 8 + j] = j + i * gEmblemGrid->mSide / 8;
        }
    }
    heap = GetHeap(GetCurrentHeapCall());
    gEmblemGrid->mBuffers[1] = HeapAllocAligned(heap, gEmblemGrid->mSide * gEmblemGrid->mSide + 0x40, 0x20);
    heap = GetHeap(GetCurrentHeapCall());
    gEmblemGrid->mBuffers[2] = HeapAllocAligned(heap, gEmblemGrid->mSide * gEmblemGrid->mSide + 0x40, 0x20);
    heap = GetHeap(GetCurrentHeapCall());
    gEmblemGrid->mBuffers[3] = HeapAllocAligned(heap, gEmblemGrid->mSide * gEmblemGrid->mSide, 0x20);
    heap = GetHeap(GetCurrentHeapCall());
    gEmblemGrid->mBuffers[4] = HeapAllocAligned(heap, gEmblemGrid->mSide * gEmblemGrid->mSide * 2, 0x20);
}

u32 GetEmblemGridSide(void) {
    return (gEmblemGrid->mSide);
}

u8 *GetEmblemGridCellPtr(s32 x, s32 y) {
    if (x >= 0 && x < gEmblemGrid->mSide && y >= 0 && y < gEmblemGrid->mSide) {
        return gEmblemGrid->mBuffers[1] +
               ((y & 7) * 8 + ((x & 7) + x / 8 * 64) + gEmblemGrid->mSide / 8 * (y / 8 * 64));
    }
    return NULL;
}

void CopyEmblemGridCellsOnFirstChange(void) {
    if (gEmblemGrid->mCopied == FALSE) {
        gEmblemGrid->mChanged = 1;
        gEmblemGrid->mCopied = TRUE;
        gEmblemGrid->mSwapped = 0;
        MIi_CpuCopyFast(gEmblemGrid->mBuffers[1], gEmblemGrid->mBuffers[2], gEmblemGrid->mSide * gEmblemGrid->mSide);
    }
}

u32 GetEmblemGridScr(void) {
    return ((u32) gEmblemGrid->mBuffers[0]);
}

u32 func_ov001_021811b8(void) {
    return 0x0u;
}

int GetEmblemGridScrSize(void) {
    int charsPerSide;
    charsPerSide = _s32_div_f(gEmblemGrid->mScrSide, 8);
    return charsPerSide * charsPerSide;
}

u32 func_ov001_02181194(void) {
    return 0x0u;
}

u32 GetEmblemGridCharSize(void) {
    return gEmblemGrid->mSide * gEmblemGrid->mSide + 0x40;
}

u8 *GetEmblemGridCells(void) {
    return gEmblemGrid->mBuffers[1];
}

u32 SetEmblemGridCells(u8 *src) {
    int i;
    u32 ret;

    ret = 0;
    for (i = 0; i < gEmblemGrid->mSide * gEmblemGrid->mSide; i++) {
        if (gEmblemGrid->mBuffers[1][i] != src[i]) {
            ret = 1;
            CopyEmblemGridCellsOnFirstChange();
            gEmblemGrid->mBuffers[1][i] = src[i];
        }
    }
    return ret;
}

s32 SetEmblemGridCellsFromTable(u8 *indices, u16 *table) {
    s32 i;
    BOOL changed;

    changed = FALSE;
    for (i = 0; i < gEmblemGrid->mSide * gEmblemGrid->mSide; i++) {
        if (indices[i] < gEmblemGrid->mTableCount && gEmblemGrid->mBuffers[1][i] != (u8) table[indices[i]]) {
            changed = TRUE;
            CopyEmblemGridCellsOnFirstChange();
            gEmblemGrid->mBuffers[1][i] = table[indices[i]];
        }
    }
    return changed;
}

void SwapEmblemGridCells(void) {
    u8 *tmp;

    tmp = gEmblemGrid->mBuffers[1];
    gEmblemGrid->mBuffers[1] = gEmblemGrid->mBuffers[2];
    gEmblemGrid->mBuffers[2] = tmp;
    gEmblemGrid->mSwapped = gEmblemGrid->mSwapped == 0 ? 1 : 0;
}

u32 IsEmblemGridSwapped(void) {
    return (gEmblemGrid->mSwapped);
}

void ClearEmblemGridCopied(void) {
    gEmblemGrid->mCopied = FALSE;
}

u32 IsEmblemGridChanged(void) {
    return (gEmblemGrid->mChanged);
}

void ResetEmblemGridChanges(void) {
    gEmblemGrid->mChanged = 0;
    gEmblemGrid->mCopied = FALSE;
    gEmblemGrid->mSwapped = 0;
    MIi_CpuCopyFast(gEmblemGrid->mBuffers[1], gEmblemGrid->mBuffers[2], gEmblemGrid->mSide * gEmblemGrid->mSide);
}

u32 SetEmblemGridCellValue(u32 x, u32 y, u32 value) {
    u8 *cellPtr;
    u32 changed;
    changed = 0;
    cellPtr = GetEmblemGridCellPtr(x, y);
    if ((cellPtr != NULL) && (*cellPtr != value)) {
        changed = 1;
        CopyEmblemGridCellsOnFirstChange();
        *cellPtr = value;
    }
    return changed;
}

u8 GetEmblemGridCellValue(s32 x, s32 y) {
    u8 *cellPtr;
    cellPtr = GetEmblemGridCellPtr(x, y);
    if (cellPtr != NULL) {
        return *cellPtr;
    }
    return 0;
}

s32 SetEmblemGridLine(s32 x, s32 y, s32 endX, s32 endY, s32 value) {
    s32 dy;
    s32 dx;
    s32 stepY;
    s32 stepX;
    BOOL changed;
    s32 stepCount;
    s32 i;
    u8 *cellPtr;

    changed = FALSE;
    if ((endX >> 12) > (x >> 12)) {
        dx = endX - x;
    } else if ((x >> 12) > (endX >> 12)) {
        dx = x - endX;
    } else {
        dx = 0;
    }
    if ((endY >> 12) > (y >> 12)) {
        dy = endY - y;
    } else if ((y >> 12) > (endY >> 12)) {
        dy = y - endY;
    } else {
        dy = 0;
    }
    if (dx == 0) {
        stepX = 0;
    } else if (dx < dy) {
        stepX = FX_Div(endX - x, dy);
    } else if (endX > x) {
        stepX = 0x1000;
    } else {
        stepX = -0x1000;
    }
    if (dy == 0) {
        stepY = 0;
    } else if (dy < dx) {
        stepY = FX_Div(endY - y, dx);
    } else if (endY > y) {
        stepY = 0x1000;
    } else {
        stepY = -0x1000;
    }
    if (dx > dy) {
        stepCount = dx >> 12;
    } else {
        stepCount = dy >> 12;
    }
    for (i = 0; i <= stepCount; i++, x += stepX, y += stepY) {
        cellPtr = GetEmblemGridCellPtr(x >> 12, y >> 12);
        if (cellPtr != NULL && *cellPtr != value) {
            changed = TRUE;
            CopyEmblemGridCellsOnFirstChange();
            *cellPtr = value;
        }
    }
    cellPtr = GetEmblemGridCellPtr(endX >> 12, endY >> 12);
    if (cellPtr != NULL && *cellPtr != value) {
        changed = TRUE;
        CopyEmblemGridCellsOnFirstChange();
        *cellPtr = value;
    }
    return changed;
}

s32 FillEmblemGridRegion(s32 startX, s32 startY, s32 newValue) {
    BOOL result;
    s32 stackCount;
    s32 k;
    s32 *rowStep;
    u8 rightEdge;
    s32 *scanStep;
    s32 rowY;
    s32 m;
    u8 *cellPtr;
    u8 *visitedCell;
    u8 oldValue;
    u8 *edgeSlot;
    EmblemGridPoint point;
    u8 edges[2];
    EmblemGridPoint scanPoint;

    result = FALSE;
    point.mX = startX;
    point.mY = startY;
    cellPtr = GetEmblemGridCellPtr(point.mX, point.mY);
    if (cellPtr != NULL) {
        oldValue = *cellPtr;
        if (oldValue != newValue) {
            stackCount = 1;
            ((EmblemGridPoint *) gEmblemGrid->mBuffers[4])[0] = point;
            MemFillWordsByBlock_inline(gEmblemGrid->mBuffers[3], gEmblemGrid->mSide * gEmblemGrid->mSide);
            do {
                s32 steps[2] = {-1, 1};

                stackCount--;
                point = ((EmblemGridPoint *) gEmblemGrid->mBuffers[4])[stackCount];
                for (k = 0, edgeSlot = edges, scanStep = steps, rowY = point.mY; k < 2; k++) {
                    *edgeSlot = point.mX;
                    for (;;) {
                        cellPtr = GetEmblemGridCellPtr(*edgeSlot, rowY);
                        visitedCell = &gEmblemGrid->mBuffers[3][*edgeSlot + rowY * gEmblemGrid->mSide];
                        if (cellPtr == NULL || *cellPtr != oldValue) {
                            break;
                        }
                        *edgeSlot += *scanStep;
                        *visitedCell = 1;
                    }
                    *edgeSlot -= *scanStep;
                    edgeSlot++;
                    scanStep++;
                }
                for (m = 0, rowStep = steps, rightEdge = edges[1]; m < 2; m++) {
                    scanPoint.mY = rowY + *rowStep;
                    for (scanPoint.mX = edges[0]; scanPoint.mX <= rightEdge; scanPoint.mX++) {
                        cellPtr = GetEmblemGridCellPtr(scanPoint.mX, scanPoint.mY);
                        visitedCell = &gEmblemGrid->mBuffers[3][scanPoint.mX + scanPoint.mY * gEmblemGrid->mSide];
                        if (cellPtr != NULL && *cellPtr == oldValue && *visitedCell == 0) {
                            do {
                                scanPoint.mX++;
                                cellPtr = GetEmblemGridCellPtr(scanPoint.mX, scanPoint.mY);
                                visitedCell =
                                    &gEmblemGrid->mBuffers[3][scanPoint.mX + scanPoint.mY * gEmblemGrid->mSide];
                            } while (cellPtr != NULL && *cellPtr == oldValue && *visitedCell == 0);
                            scanPoint.mX--;
                            ((EmblemGridPoint *) gEmblemGrid->mBuffers[4])[stackCount++] = scanPoint;
                        }
                    }
                    rowStep++;
                }
            } while (stackCount > 0);
            result = TRUE;
            CopyEmblemGridCellsOnFirstChange();
            for (point.mY = 0; point.mY < gEmblemGrid->mSide; point.mY++) {
                for (point.mX = 0; point.mX < gEmblemGrid->mSide; point.mX++) {
                    if (gEmblemGrid->mBuffers[3][point.mX + point.mY * gEmblemGrid->mSide] != 0) {
                        *GetEmblemGridCellPtr(point.mX, point.mY) = newValue;
                    }
                }
            }
        }
    }
    return result;
}
