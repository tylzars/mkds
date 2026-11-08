#include "01/code_021a59cc.h"
#include "01/code_02184f7c.h"

#include "types.h"
#include "01/code_021a5140.h"
#include "01/code_02184000.h"
#include "01/code_02185000.h"
#include "01/code_02180ce8.h"
#include "01/code_02180cb4.h"
#include "01/unk_021ca000.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "01/unk_021a7000.h"
#include "code_0212df7c.h"

Unk021ca420 *data_ov001_021ca420;

void func_ov001_021a63d8(void) {
    s32 lo = 0;
    s32 hi = data_ov001_021ca420->mSide - 1;

    switch (data_ov001_021ca420->mSizeIndex) {
        case 1:
            hi -= 1;
            break;
        case 2:
            lo += 1;
            hi -= 1;
            break;
    }
    data_ov001_021ca420->mCellX = (data_ov001_021ca420->mCellX > lo) ? data_ov001_021ca420->mCellX : lo;
    data_ov001_021ca420->mCellX = (data_ov001_021ca420->mCellX < hi) ? data_ov001_021ca420->mCellX : hi;
    data_ov001_021ca420->mCellY = (data_ov001_021ca420->mCellY > lo) ? data_ov001_021ca420->mCellY : lo;
    data_ov001_021ca420->mCellY = (data_ov001_021ca420->mCellY < hi) ? data_ov001_021ca420->mCellY : hi;
}

void func_ov001_021a63cc(s32 shift) {
    data_ov001_021ca420->mCellShift = shift;
}

void func_ov001_021a63c0(u8 cellValue) {
    data_ov001_021ca420->mCellValue = cellValue;
}

u8 func_ov001_021a63b4(void) {
    return data_ov001_021ca420->mCellValue;
}

void func_ov001_021a63a8(s32 mode) {
    data_ov001_021ca420->mMode = mode;
}

s32 func_ov001_021a639c(void) {
    return data_ov001_021ca420->mMode;
}

void func_ov001_021a6388(s32 sizeIndex) {
    data_ov001_021ca420->mSizeIndex = sizeIndex;
    func_ov001_021a63d8();
}

s32 func_ov001_021a637c(void) {
    return data_ov001_021ca420->mSizeIndex;
}

void func_ov001_021a6350(s32 x, s32 y) {
    data_ov001_021ca420->mCellX = (x - data_ov001_021ca420->mOriginX) >> data_ov001_021ca420->mCellShift;
    data_ov001_021ca420->mCellY = (y - data_ov001_021ca420->mOriginY) >> data_ov001_021ca420->mCellShift;
    func_ov001_021a63d8();
}

s32 func_ov001_021a633c(void) {
    return data_ov001_021ca420->mOriginX + (data_ov001_021ca420->mCellX << data_ov001_021ca420->mCellShift);
}

s32 func_ov001_021a6328(void) {
    return data_ov001_021ca420->mOriginY + (data_ov001_021ca420->mCellY << data_ov001_021ca420->mCellShift);
}

s32 func_ov001_021a6314(void) {
    return data_ov001_021ca420->mOriginX + (data_ov001_021ca420->mPrevCellX << data_ov001_021ca420->mCellShift);
}

s32 func_ov001_021a6300(void) {
    return data_ov001_021ca420->mOriginY + (data_ov001_021ca420->mPrevCellY << data_ov001_021ca420->mCellShift);
}

BOOL IsEmblemPointInGrid(s32 x, s32 y) {
    s32 px = (x - data_ov001_021ca420->mOriginX) >> data_ov001_021ca420->mCellShift;
    s32 py = (y - data_ov001_021ca420->mOriginY) >> data_ov001_021ca420->mCellShift;

    if (px >= 0 && px < data_ov001_021ca420->mSide && py >= 0 && py < data_ov001_021ca420->mSide) {
        return TRUE;
    }
    return FALSE;
}

s32 func_ov001_021a62ac(void) {
    return FillEmblemGridRegion(data_ov001_021ca420->mCellX, data_ov001_021ca420->mCellY,
                                data_ov001_021ca420->mCellValue);
}

BOOL func_ov001_021a6278(void) {
    u8 v = GetEmblemGridCellValue(data_ov001_021ca420->mCellX, data_ov001_021ca420->mCellY);

    if (v != 0 && v != data_ov001_021ca420->mCellValue) {
        data_ov001_021ca420->mCellValue = v;
        return TRUE;
    }
    return FALSE;
}

void func_ov001_021a6238(s32 originX, s32 originY, s32 side, s32 scrSide, s32 tableCount) {
    data_ov001_021ca420 = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x44);
    data_ov001_021ca420->mOriginX = originX;
    data_ov001_021ca420->mOriginY = originY;
    data_ov001_021ca420->mSide = side;
    CreateEmblemGrid(side, scrSide, tableCount);
}

s32 func_ov001_021a5f70(s32 down, s32 x, s32 y, s32 d, s32 dx, s32 dy) {
    s32 result;
    s32 i;
    s32 j;
    u8 col;
    s32 saveX;
    s32 saveY;
    s32 ax;
    s32 ay;
    s32 bx;
    s32 by;
    s32 cx;
    s32 cy;
    s32 ex;
    s32 ey;
    s32 ox;
    s32 oy;
    s32 sh;
    BOOL in1;
    BOOL in2;

    saveX = data_ov001_021ca420->mCellX;
    saveY = data_ov001_021ca420->mCellY;
    ox = data_ov001_021ca420->mOriginX;
    sh = data_ov001_021ca420->mCellShift;
    ax = (data_ov001_021ca420->mPrevX - ox) << 12;
    ax >>= sh;
    oy = data_ov001_021ca420->mOriginY;
    ay = (data_ov001_021ca420->mPrevY - oy) << 12;
    ay >>= sh;
    bx = (x - ox) << 12;
    bx >>= sh;
    by = (y - oy) << 12;
    by >>= sh;
    cx = ax >> 12;
    cy = ay >> 12;
    ex = bx >> 12;
    ey = by >> 12;
    in1 = FALSE;
    if (cx >= 0 && cx < data_ov001_021ca420->mSide && cy >= 0 && cy < data_ov001_021ca420->mSide) {
        in1 = TRUE;
    }
    in2 = FALSE;
    if (ex >= 0 && ex < data_ov001_021ca420->mSide && ey >= 0 && ey < data_ov001_021ca420->mSide) {
        in2 = TRUE;
    }
    result = 0;
    data_ov001_021ca420->mCellX += dx;
    data_ov001_021ca420->mCellY += dy;
    if ((data_ov001_021ca420->mPrevDown != 0 && in1 != FALSE) || (down != 0 && in2 != FALSE)) {
        if (data_ov001_021ca420->mMode == 1) {
            col = 0;
        } else {
            col = data_ov001_021ca420->mCellValue;
        }
        data_ov001_021ca420->mCellX = ex;
        data_ov001_021ca420->mCellY = ey;
        switch (data_ov001_021ca420->mMode) {
            case 0:
            case 1:
                if (data_ov001_021ca420->mPrevDown != 0) {
                    switch (data_ov001_021ca420->mSizeIndex) {
                        case 0:
                            if (SetEmblemGridLine(ax, ay, bx, by, col) != 0) {
                                result = 1;
                            } else {
                                result = 0;
                            }
                            break;
                        case 1:
                            for (i = 0; i < 0x2000; i += 0x1000) {
                                for (j = 0; j < 0x2000; j += 0x1000) {
                                    if (SetEmblemGridLine(ax + i, ay + j, bx + i, by + j, col) != 0) {
                                        result = 1;
                                    }
                                }
                            }
                            break;
                        case 2:
                            for (i = -0x1000; i < 0x2000; i += 0x1000) {
                                for (j = -0x1000; j < 0x2000; j += 0x1000) {
                                    if (SetEmblemGridLine(ax + i, ay + j, bx + i, by + j, col) != 0) {
                                        result = 1;
                                    }
                                }
                            }
                            break;
                    }
                }
                d = result;
                break;
            case 2:
            case 3:
                d = 1;
                break;
        }
    }
    func_ov001_021a63d8();
    if (d != 0) {
        if (data_ov001_021ca420->mMode == 1) {
            col = 0;
        } else {
            col = data_ov001_021ca420->mCellValue;
        }
        switch (data_ov001_021ca420->mMode) {
            case 0:
            case 1:
                switch (data_ov001_021ca420->mSizeIndex) {
                    case 0:
                        if (SetEmblemGridCellValue(data_ov001_021ca420->mCellX, data_ov001_021ca420->mCellY, col) !=
                            0) {
                            result = 1;
                        }
                        break;
                    case 1:
                        for (i = 0; i < 2; i++) {
                            for (j = 0; j < 2; j++) {
                                if (SetEmblemGridCellValue(data_ov001_021ca420->mCellX + i,
                                                           data_ov001_021ca420->mCellY + j, col) != 0) {
                                    result = 1;
                                }
                            }
                        }
                        break;
                    case 2:
                        for (i = -1; i < 2; i++) {
                            for (j = -1; j < 2; j++) {
                                if (SetEmblemGridCellValue(data_ov001_021ca420->mCellX + i,
                                                           data_ov001_021ca420->mCellY + j, col) != 0) {
                                    result = 1;
                                }
                            }
                        }
                        break;
                }
                break;
            case 2:
                result = func_ov001_021a62ac();
                break;
            case 3:
                result = func_ov001_021a6278();
                break;
        }
    }
    data_ov001_021ca420->mPrevDown = down;
    data_ov001_021ca420->mPrevX = x;
    data_ov001_021ca420->mPrevY = y;
    data_ov001_021ca420->mPrevCellX = saveX;
    data_ov001_021ca420->mPrevCellY = saveY;
    if (down == 0 && d == 0) {
        ClearEmblemGridCopied();
    }
    return result;
}

BOOL func_ov001_021a5ef4(LldEntry *entry) {
    if (entry->mUnk_10 <= 0) {
        SetLldEntryScale(entry, 0x1000);
    }
    entry->mUnk_10++;
    if (entry->mUnk_10 <= 5) {
        func_ov001_02185018(entry, 0);
        SetLldEntryScale(entry, GetLldEntryScale(entry) - 0x19a);
        if (GetLldEntryScale(entry) <= 0) {
            SetLldEntryScale(entry, 0);
            return TRUE;
        }
        return FALSE;
    }
    if (entry->mUnk_10 <= 10) {
        SetLldEntryScale(entry, 0);
        return FALSE;
    }
    return TRUE;
}

BOOL func_ov001_021a5e60(LldEntry *entry) {
    if (entry->mUnk_10 <= 0) {
        SetLldEntryScale(entry, 0);
    }
    entry->mUnk_10++;
    if (entry->mUnk_10 <= 5) {
        return FALSE;
    }
    if (entry->mUnk_10 <= 10) {
        func_ov001_02185018(entry, 0);
        SetLldEntryScale(entry, GetLldEntryScale(entry) + 0x19a);
        if (GetLldEntryScale(entry) >= 0x1000) {
            SetLldEntryScale(entry, 0x1000);
        }
        return FALSE;
    }
    SetLldEntryScale(entry, 0x1000);
    if (gEmblem->mUnk_108c != NULL) {
        gEmblem->mUnk_108c();
        gEmblem->mUnk_108c = NULL;
    }
    return TRUE;
}

void func_ov001_021a5df0(void *obj, s32 index) {
    void *a = GetLldEntry(obj, index);
    void *b = GetLldEntry(obj, 9);
    void *c = GetLldEntry(obj, 10);

    SetLldEntryPos(b, GetLldEntryX(a), GetLldEntryY(a));
    SetLldEntryPos(c, GetLldEntryX(a), GetLldEntryY(a));
    func_ov001_021850a4(b, (s32(*)(LldEntry *)) func_ov001_021a5ef4);
    func_ov001_021850a4(c, (s32(*)(LldEntry *)) func_ov001_021a5e60);
}

BOOL func_ov001_021a5d18(LldEntry *entry) {
    if (entry->mUnk_10 <= 0) {
        SetLldEntryScale(entry, 0x1000);
    }
    entry->mUnk_10++;
    if (entry->mUnk_10 <= 5) {
        func_ov001_02185018(entry, 1);
        SetLldEntryScale(entry, GetLldEntryScale(entry) - 0x19a);
        if (GetLldEntryScale(entry) <= 0) {
            SetLldEntryScale(entry, 0);
        }
        return FALSE;
    }
    if (entry->mUnk_10 <= 10) {
        func_ov001_02185018(entry, 1);
        SetLldEntryScale(entry, GetLldEntryScale(entry) + 0x19a);
        if (GetLldEntryScale(entry) >= 0x1000) {
            SetLldEntryScale(entry, 0x1000);
        }
        return FALSE;
    }
    if (entry->mUnk_10 == 11) {
        if (gEmblem->mUnk_108c != NULL) {
            gEmblem->mUnk_108c();
            gEmblem->mUnk_108c = NULL;
        }
        return FALSE;
    }
    if (entry->mUnk_10 <= 20) {
        return FALSE;
    }
    func_ov001_02185018(entry, 0);
    return TRUE;
}

void func_ov001_021a5d00(void *obj, s32 index) {
    func_ov001_021850a4(GetLldEntry(obj, index), (s32(*)(LldEntry *)) func_ov001_021a5d18);
}

BOOL func_ov001_021a5c40(LldEntry *entry) {
    if (entry->mUnk_10 <= 0) {
        SetLldEntryScale(entry, 0x1000);
    }
    entry->mUnk_10++;
    if (entry->mUnk_10 <= 5) {
        func_ov001_02185018(entry, 1);
        SetLldEntryScale(entry, GetLldEntryScale(entry) - 0x19a);
        if (GetLldEntryScale(entry) <= 0) {
            SetLldEntryScale(entry, 0);
        }
        return FALSE;
    }
    if (entry->mUnk_10 <= 10) {
        func_ov001_02185018(entry, 1);
        SetLldEntryScale(entry, GetLldEntryScale(entry) + 0x19a);
        if (GetLldEntryScale(entry) >= 0x1000) {
            SetLldEntryScale(entry, 0x1000);
        }
        return FALSE;
    }
    if (gEmblem->mUnk_108c != NULL) {
        gEmblem->mUnk_108c();
        gEmblem->mUnk_108c = NULL;
    }
    func_ov001_02185018(entry, 0);
    return TRUE;
}

void func_ov001_021a5c28(void *obj, s32 index) {
    func_ov001_021850a4(GetLldEntry(obj, index), (s32(*)(LldEntry *)) func_ov001_021a5c40);
}

BOOL func_ov001_021a5b70(LldEntry *entry) {
    if (entry->mUnk_10 <= 0) {
        SetLldEntryScale(entry, 0x1000);
    }
    entry->mUnk_10++;
    if (entry->mUnk_10 <= 5) {
        func_ov001_02185018(entry, 0);
        SetLldEntryScale(entry, GetLldEntryScale(entry) - 0x19a);
        if (GetLldEntryScale(entry) <= 0) {
            SetLldEntryScale(entry, 0);
        }
        return FALSE;
    }
    if (entry->mUnk_10 <= 10) {
        func_ov001_02185018(entry, 1);
        SetLldEntryScale(entry, GetLldEntryScale(entry) + 0x19a);
        if (GetLldEntryScale(entry) >= 0x1000) {
            SetLldEntryScale(entry, 0x1000);
        }
        return FALSE;
    }
    if (gEmblem->mUnk_108c != NULL) {
        gEmblem->mUnk_108c();
        gEmblem->mUnk_108c = NULL;
    }
    return TRUE;
}

void func_ov001_021a5b4c(void *obj, s32 index) {
    LldEntry *entry = GetLldEntry(obj, index);

    func_ov001_021850a4(entry, NULL);
    func_ov001_02185018(entry, 0);
    entry->mScale = 0x1000;
}

void func_ov001_021a5ab0(void *obj, s32 index) {
    func_ov001_021a5b4c(gEmblem->mEmblemSLld, 14);
    func_ov001_021a5b4c(gEmblem->mEmblemSLld, 15);
    func_ov001_021a5b4c(gEmblem->mEmblemSLld, 16);
    func_ov001_021a5b4c(gEmblem->mEmblemSLld, 17);
    func_ov001_021a5b4c(gEmblem->mEmblemSLld, 18);
    func_ov001_021a5b4c(gEmblem->mEmblemSLld, 19);
    func_ov001_021a5b4c(gEmblem->mEmblemSLld, 20);
    func_ov001_021a5b4c(gEmblem->mEmblemSLld, 21);
    func_ov001_021850a4(GetLldEntry(obj, index), (s32(*)(LldEntry *)) func_ov001_021a5b70);
}

BOOL func_ov001_021a5a58(LldEntry *entry) {
    if (entry->mUnk_10 <= 0) {
        SetLldEntryScale(entry, 0x1000);
    }
    entry->mUnk_10++;
    if (entry->mUnk_10 <= 10) {
        func_ov001_02185018(entry, 1);
        return FALSE;
    }
    if (gEmblem->mUnk_108c != NULL) {
        gEmblem->mUnk_108c();
        gEmblem->mUnk_108c = NULL;
    }
    return TRUE;
}

void func_ov001_021a5a40(void *obj, s32 index) {
    func_ov001_021850a4(GetLldEntry(obj, index), (s32(*)(LldEntry *)) func_ov001_021a5a58);
}

void func_ov001_021a59cc(void *obj, s32 index) {
    void *a = GetLldEntry(obj, index);
    void *b = GetLldEntry(obj, 24);

    if (GetLldEntryFrameIndex(b) >= 0) {
        func_ov001_021850a4(a, (s32(*)(LldEntry *)) func_ov001_021a5d18);
        func_ov001_02185018(b, -5);
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 505);
    } else {
        func_ov001_021850a4(a, (s32(*)(LldEntry *)) func_ov001_021a5d18);
        func_ov001_02185018(b, 0);
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 506);
    }
}
