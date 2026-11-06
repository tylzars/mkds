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

    heap = GetHeap(func_020364e8());
    gEmblemGrid = HeapAllocAligned(heap, 0x30, 0x20);
    gEmblemGrid->mSide = side;
    gEmblemGrid->mScrSide = scrSide;
    gEmblemGrid->mTableCount = tableCount;
    heap = GetHeap(func_020364e8());
    gEmblemGrid->mUnk_18 = HeapAllocAligned(heap, gEmblemGrid->mTableCount * 2, 0x20);
    heap = GetHeap(func_020364e8());
    gEmblemGrid->mBuffers[0] = HeapAllocAligned(heap, gEmblemGrid->mScrSide / 8 * (gEmblemGrid->mScrSide / 8), 0x20);
    MI_CpuFill8(gEmblemGrid->mBuffers[0], gEmblemGrid->mSide / 8 * gEmblemGrid->mSide / 8,
                gEmblemGrid->mScrSide / 8 * (gEmblemGrid->mScrSide / 8));
    for (i = 0; i < gEmblemGrid->mSide / 8; i++) {
        for (j = 0; j < gEmblemGrid->mSide / 8; j++) {
            gEmblemGrid->mBuffers[0][i * gEmblemGrid->mScrSide / 8 + j] = j + i * gEmblemGrid->mSide / 8;
        }
    }
    heap = GetHeap(func_020364e8());
    gEmblemGrid->mBuffers[1] = HeapAllocAligned(heap, gEmblemGrid->mSide * gEmblemGrid->mSide + 0x40, 0x20);
    heap = GetHeap(func_020364e8());
    gEmblemGrid->mBuffers[2] = HeapAllocAligned(heap, gEmblemGrid->mSide * gEmblemGrid->mSide + 0x40, 0x20);
    heap = GetHeap(func_020364e8());
    gEmblemGrid->mBuffers[3] = HeapAllocAligned(heap, gEmblemGrid->mSide * gEmblemGrid->mSide, 0x20);
    heap = GetHeap(func_020364e8());
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
    int v1;
    v1 = _s32_div_f(gEmblemGrid->mScrSide, 8);
    return v1 * v1;
}

u32 func_ov001_02181194(void) {
    return 0x0u;
}

u32 GetEmblemGridCharSize(void) {
    return gEmblemGrid->mSide * gEmblemGrid->mSide + 0x40;
}

u32 GetEmblemGridCells(void) {
    return ((u32) gEmblemGrid->mBuffers[1]);
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
    u8 *v1;
    u32 v2;
    v2 = 0;
    v1 = GetEmblemGridCellPtr(x, y);
    if ((v1 != NULL) && (*v1 != value)) {
        v2 = 1;
        CopyEmblemGridCellsOnFirstChange();
        *v1 = value;
    }
    return v2;
}

u8 GetEmblemGridCellValue(s32 x, s32 y) {
    u8 *v1;
    v1 = GetEmblemGridCellPtr(x, y);
    if (v1 != NULL) {
        return *v1;
    }
    return 0;
}

s32 SetEmblemGridLine(s32 x, s32 y, s32 endX, s32 endY, s32 value) {
    s32 dy;
    s32 dx;
    s32 stepY;
    s32 stepX;
    BOOL changed;
    s32 n;
    s32 i;
    u8 *ptr;

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
        n = dx >> 12;
    } else {
        n = dy >> 12;
    }
    for (i = 0; i <= n; i++, x += stepX, y += stepY) {
        ptr = GetEmblemGridCellPtr(x >> 12, y >> 12);
        if (ptr != NULL && *ptr != value) {
            changed = TRUE;
            CopyEmblemGridCellsOnFirstChange();
            *ptr = value;
        }
    }
    ptr = GetEmblemGridCellPtr(endX >> 12, endY >> 12);
    if (ptr != NULL && *ptr != value) {
        changed = TRUE;
        CopyEmblemGridCellsOnFirstChange();
        *ptr = value;
    }
    return changed;
}

s32 FillEmblemGridRegion(s32 startX, s32 startY, s32 newValue) {
    BOOL result;
    s32 top;
    s32 k;
    s32 *sm;
    u8 hi;
    s32 *sk;
    s32 py;
    s32 m;
    u8 *ptr;
    u8 *q;
    u8 val;
    u8 *b;
    EmblemGridPoint s0;
    u8 buf[2];
    EmblemGridPoint s1;

    result = FALSE;
    s0.mX = startX;
    s0.mY = startY;
    ptr = GetEmblemGridCellPtr(s0.mX, s0.mY);
    if (ptr != NULL) {
        val = *ptr;
        if (val != newValue) {
            top = 1;
            ((EmblemGridPoint *) gEmblemGrid->mBuffers[4])[0] = s0;
            MemFillWordsByBlock_inline(gEmblemGrid->mBuffers[3], gEmblemGrid->mSide * gEmblemGrid->mSide);
            do {
                s32 steps[2] = {-1, 1};

                top--;
                s0 = ((EmblemGridPoint *) gEmblemGrid->mBuffers[4])[top];
                for (k = 0, b = buf, sk = steps, py = s0.mY; k < 2; k++) {
                    *b = s0.mX;
                    for (;;) {
                        ptr = GetEmblemGridCellPtr(*b, py);
                        q = &gEmblemGrid->mBuffers[3][*b + py * gEmblemGrid->mSide];
                        if (ptr == NULL || *ptr != val) {
                            break;
                        }
                        *b += *sk;
                        *q = 1;
                    }
                    *b -= *sk;
                    b++;
                    sk++;
                }
                for (m = 0, sm = steps, hi = buf[1]; m < 2; m++) {
                    s1.mY = py + *sm;
                    for (s1.mX = buf[0]; s1.mX <= hi; s1.mX++) {
                        ptr = GetEmblemGridCellPtr(s1.mX, s1.mY);
                        q = &gEmblemGrid->mBuffers[3][s1.mX + s1.mY * gEmblemGrid->mSide];
                        if (ptr != NULL && *ptr == val && *q == 0) {
                            do {
                                s1.mX++;
                                ptr = GetEmblemGridCellPtr(s1.mX, s1.mY);
                                q = &gEmblemGrid->mBuffers[3][s1.mX + s1.mY * gEmblemGrid->mSide];
                            } while (ptr != NULL && *ptr == val && *q == 0);
                            s1.mX--;
                            ((EmblemGridPoint *) gEmblemGrid->mBuffers[4])[top++] = s1;
                        }
                    }
                    sm++;
                }
            } while (top > 0);
            result = TRUE;
            CopyEmblemGridCellsOnFirstChange();
            for (s0.mY = 0; s0.mY < gEmblemGrid->mSide; s0.mY++) {
                for (s0.mX = 0; s0.mX < gEmblemGrid->mSide; s0.mX++) {
                    if (gEmblemGrid->mBuffers[3][s0.mX + s0.mY * gEmblemGrid->mSide] != 0) {
                        *GetEmblemGridCellPtr(s0.mX, s0.mY) = newValue;
                    }
                }
            }
        }
    }
    return result;
}
