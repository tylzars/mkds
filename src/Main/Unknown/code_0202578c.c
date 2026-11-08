#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/unk_02174000.h"
#include "code_02016468.h"

#pragma thumb on

void LocateCellFileSet(void *fileSetPointer, const char *charsName, const char *cellsName, const char *paletteName,
                       const char *cellLayoutName, const char *labelLayoutName, const char *rectsName,
                       void *(*findFile)(const char *) ) {
    CellFileSet *fileSet = fileSetPointer;
    if (charsName) {
        LocateNcgr2((Ncgr **) &fileSet->mChars, findFile(charsName));
    }
    if (cellsName) {
        LocateNcer((Unk02021dc8 **) &fileSet->mCells, findFile(cellsName));
    }
    if (paletteName) {
        LocateNclr((Nclr **) &fileSet->mPalette, findFile(paletteName));
    }
    if (cellLayoutName) {
        fileSet->mCellLayout = findFile(cellLayoutName);
    }
    if (labelLayoutName) {
        fileSet->mLabelLayout = findFile(labelLayoutName);
    }
    if (rectsName) {
        fileSet->mRects = findFile(rectsName);
    }
}

void LoadCellFileSet(void *fileSetPointer, const char *charsName, const char *cellsName, const char *paletteName,
                     const char *cellLayoutName, const char *labelLayoutName, const char *rectsName,
                     void *(*findFile)(const char *) ) {
    CellFileSet *fileSet = fileSetPointer;
    if (charsName) {
        LoadNcgrData2((Ncgr **) &fileSet->mChars, findFile(charsName));
    }
    if (cellsName) {
        LoadNcerData((Unk02021dc8 **) &fileSet->mCells, findFile(cellsName));
    }
    if (paletteName) {
        LoadNclrData((Nclr **) &fileSet->mPalette, findFile(paletteName));
    }
    if (cellLayoutName) {
        fileSet->mCellLayout = findFile(cellLayoutName);
    }
    if (labelLayoutName) {
        fileSet->mLabelLayout = findFile(labelLayoutName);
    }
    if (rectsName) {
        fileSet->mRects = findFile(rectsName);
    }
}

void func_02025a50(u32 a, void *heap, void *fileSetPointer) {
    CellFileSet *fileSet = fileSetPointer;
    u32 r;
    InitLayoutTable(heap, fileSet->mCellLayout, fileSet->mLabelLayout, &fileSet->mCellTable);
    if (a == 0) {
        r = 0x13;
        CallQueueAppend(0xe, 0, ((Nclr *) fileSet->mPalette)->mData, 0x1a0);
        CallQueueAppend(0xe, 0x1c0, (u8 *) ((Nclr *) fileSet->mPalette)->mData + 0x1c0, 0x40);
    } else {
        r = 0x23;
        CallQueueAppend(0x1e, 0, ((Nclr *) fileSet->mPalette)->mData, ((Nclr *) fileSet->mPalette)->mDataSize);
    }
    CallQueueAppend(r, 0, ((Ncgr *) fileSet->mChars)->mData, ((Ncgr *) fileSet->mChars)->mDataSize);
}

s32 func_02025a00(u32 a, void *heap, void *fileSetPointer, void *entryPointer, s32 e) {
    Unk02153918 *entry = entryPointer;
    CellFileSet *fileSet = fileSetPointer;
    s32 result;
    result = InitLabelCanvas(heap, entry->mUnk_00, fileSet->mLabelLayout, entry->mUnk_02, entry->mUnk_04,
                             entry->mUnk_06, fileSet->mCells, fileSet->mCellLayout, fileSet->mCellTable, e);
    ClearAndQueueLabelLayoutText(a, entry->mUnk_00, fileSet->mLabelLayout, fileSet->mCellLayout, fileSet->mCellTable);
    return result;
}

void func_02025954(u32 a, void *fileSetPointer, u32 index) {
    ScreenMapFileSet *fileSet = fileSetPointer;
    u32 charsCode;
    u32 screenMapCode;
    u32 paletteCode;
    if (a == 0) {
        paletteCode = 0xf;
        switch (index) {
            case 0:
                charsCode = 4;
                screenMapCode = 8;
                break;
            case 1:
                charsCode = 5;
                screenMapCode = 9;
                break;
            case 2:
                charsCode = 6;
                screenMapCode = 10;
                break;
            case 3:
                charsCode = 7;
                screenMapCode = 11;
                break;
        }
    } else {
        paletteCode = 0x1f;
        switch (index) {
            case 0:
                charsCode = 0x14;
                screenMapCode = 0x18;
                break;
            case 1:
                charsCode = 0x15;
                screenMapCode = 0x19;
                break;
            case 2:
                charsCode = 0x16;
                screenMapCode = 0x1a;
                break;
            case 3:
                charsCode = 0x17;
                screenMapCode = 0x1b;
                break;
        }
    }
    CallQueueAppend(charsCode, 0, fileSet->mChars[index]->mData, fileSet->mChars[index]->mDataSize);
    CallQueueAppend(paletteCode, 0, fileSet->mPalette->mData, 0x140);
    CallQueueAppend(screenMapCode, 0, &fileSet->mScreenMaps[index]->mData, fileSet->mScreenMaps[index]->mDataSize);
}

void LocateScreenMapFileSet(void *fileSetPointer, const char *charsName, const char *paletteName,
                            const char *screenMapName, s32 index, void *(*findFile)(const char *) ) {
    ScreenMapFileSet *fileSet = fileSetPointer;
    if (charsName) {
        LocateNcgr(&fileSet->mChars[index], findFile(charsName));
    }
    if (paletteName) {
        LocateNclr(&fileSet->mPalette, findFile(paletteName));
    }
    if (screenMapName) {
        LocateNscr(&fileSet->mScreenMaps[index], findFile(screenMapName));
    }
}

void func_020258d4(u32 a, void *fileSetPointer, const char *charsName, const char *paletteName,
                   const char *screenMapName, s32 index, void *(*findFile)(const char *) ) {
    LocateScreenMapFileSet(fileSetPointer, charsName, paletteName, screenMapName, index, findFile);
    func_02025954(a, fileSetPointer, index);
}

void LoadScreenMapFileSet(void *fileSetPointer, const char *charsName, const char *paletteName,
                          const char *screenMapName, s32 index, void *(*findFile)(const char *) ) {
    ScreenMapFileSet *fileSet = fileSetPointer;
    if (charsName) {
        LoadNcgrData(&fileSet->mChars[index], findFile(charsName));
    }
    if (paletteName) {
        LoadNclrData(&fileSet->mPalette, findFile(paletteName));
    }
    if (screenMapName) {
        LoadNscrData(&fileSet->mScreenMaps[index], findFile(screenMapName));
    }
}

void func_02025854(u32 a, void *fileSetPointer, const char *charsName, const char *paletteName,
                   const char *screenMapName, s32 index, void *(*findFile)(const char *) ) {
    LoadScreenMapFileSet(fileSetPointer, charsName, paletteName, screenMapName, index, findFile);
    func_02025954(a, fileSetPointer, index);
}

#pragma thumb off

u32 func_0202578c(u32 a) {
    u32 result = 3;
    switch (a) {
        case 0:
        case 3:
        case 6:
        case 9:
        case 12:
        case 15:
        case 18:
        case 21:
        case 24:
        case 27:
        case 30:
        case 33:
        case 36:
            result = 0;
            break;
        case 2:
        case 8:
        case 13:
        case 14:
        case 20:
        case 23:
        case 25:
        case 28:
        case 31:
            result = 0;
            break;
        case 1:
        case 7:
        case 19:
        case 22:
        case 26:
        case 29:
        case 32:
        case 34:
        case 35:
            result = 1;
            break;
        case 4:
        case 5:
        case 10:
        case 11:
        case 16:
        case 17:
            result = 2;
            break;
    }
    return result;
}
