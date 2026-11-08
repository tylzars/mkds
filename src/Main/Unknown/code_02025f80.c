#include "Main/Unknown/code_02025f80.h"
#include "registers.h"

#include "Main/Unknown/code_02025edc.h"
#include "Main/Unknown/code_0202b000.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_0211f498.h"
#include "Main/Unknown/unk_02174000.h"
#include "code_0214a390.h"
#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_02025eb0.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025ebc.h"
#include "Main/Unknown/code_02027000.h"
#include "Main/Unknown/code_0202bb80.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_0202b604.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02077000.h"
#include "Main/Unknown/code_02148000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02077bc0.h"
#include "Main/Unknown/code_02078000.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ae5d4.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_021105a0.h"
#include "Main/Unknown/code_021106a8.h"
#include "Main/Unknown/code_02116ec0.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_0211f378.h"
#include "Main/Unknown/code_0211f394.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_02121e84.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_02175628.h"
#include "code_0201ea58.h"
#include "Main/Unknown/code_02025b84.h"
#include "Main/Unknown/code_02025bb4.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_0202c000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_0211f4b0.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/code_02025f54.h"
#include "Main/Unknown/code_0202719c.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_02025e28.h"

#pragma thumb on

void func_02027188(void) {
    func_0202719c();
    func_020271e8();
}

#pragma thumb off

#pragma thumb on

void func_020270fc(s32 previousTableIndex) {
    gSelectCharacter->mUnk_064 = previousTableIndex;
    switch (gSelectCharacter->mUnk_07c) {
        case 8:
            func_02027be0();
            break;
        case 9:
            func_02027a58();
            break;
        case 10:
            func_02027850();
            break;
        case 11:
            func_02027648();
            break;
        case 12:
            func_02027448();
            break;
    }
    func_02027188();
    func_0202721c();
    SetInterpolationState(&gSelectCharacter->mInterpolations[0], 0);
    gSelectCharacter->mCharacterIndex = gSelectCharacter->mUnk_090[gSelectCharacter->mUnk_060].mCharacterIndex;
    gSelectCharacter->mKartIndex = func_02025e60(gSelectCharacter->mCharacterIndex);
}

#pragma thumb off

#pragma thumb on

u32 func_020270d0(void) {
    int result;
    if ((gSelectCharacter->mUnk_080 != 0) && (result = IsPlayerEntryListTimerZero(), result != 0)) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

void func_02027084(void) {
    CellFileSet *sParts = &gSelectCharacter->mUnk_01c;
    s32 i;
    s32 elementCount;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        elementCount = sParts->mCellLayout->mUnk_06;
        for (i = 0; i < elementCount; i++) {
            func_02124b1c(&sParts->mCellTable[i], gSelectCharacter->mUnk_074, gSelectCharacter->mUnk_070);
        }
    }
}

#pragma thumb off

#pragma thumb on

void InitSelectCharacter(void *parentHeap, s32 mode, void *mainOam, void *subOam) {
    void *heap;
    Unk02174e14 *selectCharacter;
    CellFileSet *sParts;
    Unk021534bc *positions;
    s32 i;
    s32 tableIndex;
    s32 modeValue;
    BOOL f;
    CellFileSet titleParts;
    CellFileSet w;

    heap = CreateFrmHeapFromMaxFree(parentHeap);
    gSelectCharacter = HeapAlloc(heap, 0x12c);
    MemFillWordsByBlock_inline(gSelectCharacter, 0x12c);
    gSelectCharacter->mHeap = heap;
    gSelectCharacter->mUnk_080 = mode;
    switch (GetRaceSetupCopy()->mUnk_108) {
        case 0:
            SetupInterpolation(&gSelectCharacter->mInterpolations[0], 0, 10, -0x80, 0);
            SetupInterpolation(&gSelectCharacter->mInterpolations[2], 0, 10, 0x60, 0);
            if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
                StartKartModelMenuBg0Increase();
            }
            break;
        case 2:
            SetupInterpolation(&gSelectCharacter->mInterpolations[0], 1, 10, -0x80, 0);
            SetupInterpolation(&gSelectCharacter->mInterpolations[2], 1, 10, 0x60, 0);
            switch (gSelectCharacter->mUnk_080) {
                case 1:
                    if (data_0217aa00->mUnk_0004 == 8) {
                        data_0217aa00->mUnk_15f7 = 0xff;
                    }
                    break;
                case 2:
                    SetWiFiSessionOwnCharacterIndexNone();
                    break;
            }
            break;
    }
    SetupInterpolation(&gSelectCharacter->mInterpolations[1], 0, 10, -0x40, 0);
    gSelectCharacter->mMainOam = mainOam;
    gSelectCharacter->mUnk_058 = subOam;
    if (gSelectCharacter->mUnk_080 != 0 || GetRaceSetupCopy()->mMode == 3 || GetRaceSetupCopy()->mMode == 2) {
        f = TRUE;
    } else {
        f = FALSE;
    }
    gSelectCharacter->mUnk_128 = f;
    if (gSelectCharacter->mUnk_128 != FALSE) {
        switch (gSelectCharacter->mUnk_080) {
            case 0:
                modeValue = 0;
                break;
            case 1:
                modeValue = 1;
                break;
            case 2:
                modeValue = 2;
                break;
        }
        SetupPlayerEntryList(modeValue, PLAYER_ENTRY_LIST_CHARACTER);
    }
    selectCharacter = gSelectCharacter;
    switch (selectCharacter->mUnk_080) {
        case 0:
            selectCharacter->mEntryIndex = 0;
            break;
        case 1:
            selectCharacter->mEntryIndex =
                data_0217aa00->mUnk_1e52[(u16) (data_0217aa00->mUnk_0000 == 2 ? data_0217aa00->mOwnIndex : 0)]
                    .mEntryIndex;
            break;
        case 2:
            gSelectCharacter->mEntryIndex = GetRaceSetupCopyEntryIndex();
            break;
    }
    selectCharacter = gSelectCharacter;
    if (selectCharacter->mUnk_128 == FALSE) {
        LocateCellFileSet(&selectCharacter->mUnk_000, gSelectCharacterGpMNcgrName, gSelectCharacterGpMNcerName,
                          gSelectCharacterGpMONclrName, gSelectCharacterGpMBnclName, NULL, NULL,
                          FindFileInLoadedArchives);
        func_02025a50(0, gSelectCharacter->mHeap, &selectCharacter->mUnk_000);
        LocateCellFileSet(&titleParts, gSelectCharacterGpTitleMNcgrName, gSelectCharacterGpTitleMNcerName, NULL,
                          gSelectCharacterGpTitleMBnclName, NULL, NULL, FindFileInLoadedArchives);
        func_02124748(0, titleParts.mCells, titleParts.mChars, titleParts.mCellLayout, 0, 0,
                      selectCharacter->mUnk_000.mCells, selectCharacter->mUnk_000.mCellLayout);
        LocateCellFileSet(&gSelectCharacter->mUnk_038, gSelectCharacterGpNameMNcgrName, gSelectCharacterGpNameMNcerName,
                          NULL, gSelectCharacterGpNameMBnclName, NULL, NULL, FindFileInLoadedArchives);
        selectCharacter->mUnk_000.mCellTable[9].mVisible = 0;
        selectCharacter->mUnk_000.mCellTable[8].mVisible = selectCharacter->mUnk_000.mCellTable[9].mVisible;
        selectCharacter->mUnk_000.mCellTable[7].mVisible = selectCharacter->mUnk_000.mCellTable[8].mVisible;
        selectCharacter->mUnk_000.mCellTable[6].mVisible = selectCharacter->mUnk_000.mCellTable[7].mVisible;
        selectCharacter->mUnk_000.mCellTable[5].mVisible = selectCharacter->mUnk_000.mCellTable[6].mVisible;
        selectCharacter->mUnk_000.mCellTable[4].mVisible = selectCharacter->mUnk_000.mCellTable[5].mVisible;
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        sParts = &gSelectCharacter->mUnk_01c;
        LocateCellFileSet(sParts, gSelectCharacterSNcgrName, gSelectCharacterSNcerName, gSelectCharacterSONclrName,
                          gSelectCharacterSBnclName, NULL, gSelectCharacterSBnblName, FindFileInLoadedArchives);
        func_02025a50(1, gSelectCharacter->mHeap, sParts);
        sParts->mCellTable[24].mVisible = 0;
        for (i = 0; i < 12; i++) {
            sParts->mCellTable[data_usa_02153554[i].mUnk_04].mUnk_10 = 1;
            sParts->mCellTable[data_usa_02153554[i].mUnk_02].mUnk_10 =
                sParts->mCellTable[data_usa_02153554[i].mUnk_04].mUnk_10;
            sParts->mCellTable[data_usa_02153554[i].mUnk_00].mUnk_10 =
                sParts->mCellTable[data_usa_02153554[i].mUnk_02].mUnk_10;
            sParts->mCellTable[data_usa_02153554[i].mUnk_04].mUnk_34 = 0;
            sParts->mCellTable[data_usa_02153554[i].mUnk_02].mUnk_34 =
                sParts->mCellTable[data_usa_02153554[i].mUnk_04].mUnk_34;
            sParts->mCellTable[data_usa_02153554[i].mUnk_00].mUnk_34 =
                sParts->mCellTable[data_usa_02153554[i].mUnk_02].mUnk_34;
        }
        sParts->mCellTable[25].mUnk_10 = 1;
        sParts->mCellTable[24].mUnk_10 = sParts->mCellTable[25].mUnk_10;
        sParts->mCellTable[25].mUnk_34 = 0;
        sParts->mCellTable[24].mUnk_34 = sParts->mCellTable[25].mUnk_34;
    } else if (GetRaceSetupCopy()->mMode == 2) {
        InitSelectRaceRuleWait(gSelectCharacter->mHeap, gSelectCharacter->mUnk_058);
        func_0211f394();
    }
    gSelectCharacter->mUnk_07c = 8;
    for (i = 0; i < 8; i++) {
        gSelectCharacter->mUnk_090[i] = data_021535b4[i];
    }
    if (func_02056dec(0x15) != 0) {
        gSelectCharacter->mUnk_090[i] = data_021535b4[8];
        i++;
        gSelectCharacter->mUnk_07c++;
    }
    if (func_02056dec(0x14) != 0) {
        gSelectCharacter->mUnk_090[i] = data_021535b4[9];
        i++;
        gSelectCharacter->mUnk_07c++;
    }
    if (func_02056dec(0x16) != 0) {
        gSelectCharacter->mUnk_090[i] = data_021535b4[10];
        i++;
        gSelectCharacter->mUnk_07c++;
    }
    if (func_02056dec(0x17) != 0) {
        gSelectCharacter->mUnk_090[i] = data_021535b4[11];
        i++;
        gSelectCharacter->mUnk_07c++;
    }
    for (; i < 12; i++) {
        gSelectCharacter->mUnk_090[i].mCharacterIndex = -1;
    }
    for (tableIndex = 0; tableIndex < gSelectCharacter->mUnk_07c; tableIndex++) {
        if (gSelectCharacter->mUnk_090[tableIndex].mCharacterIndex ==
            GetRaceSetupCopy()->mEntries[gSelectCharacter->mEntryIndex].mCharacterIndex) {
            gSelectCharacter->mUnk_060 = tableIndex;
        }
    }
    gSelectCharacter->mUnk_064 = gSelectCharacter->mUnk_060;
    selectCharacter = gSelectCharacter;
    selectCharacter->mCharacterIndex = GetRaceSetupCopy()->mEntries[selectCharacter->mEntryIndex].mCharacterIndex;
    if (gSelectCharacter->mCharacterIndex == -1) {
        gSelectCharacter->mCharacterIndex = 0;
    }
    gSelectCharacter->mKartIndex = func_02025e60(gSelectCharacter->mCharacterIndex);
    GetRaceSetupCopy()->mEntries[gSelectCharacter->mEntryIndex].mCharacterIndex = -1;
    GetRaceSetupCopy()->mEntries[gSelectCharacter->mEntryIndex].mKartIndex = -1;
    GetRaceSetupCopy()->mEntries[gSelectCharacter->mEntryIndex].mUnk_14 = 0;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        sParts = &gSelectCharacter->mUnk_01c;
        func_02025b84(0, &w);
        for (i = 0; i < gSelectCharacter->mUnk_07c; i++) {
            func_0212481c(gSelectCharacter->mUnk_090[i].mCharacterIndex, w.mCells, w.mChars, w.mPalette, w.mCellLayout,
                          1, data_usa_02153554[i].mUnk_02, sParts->mCells, sParts->mCellLayout);
        }
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        positions = NULL;
        sParts = &gSelectCharacter->mUnk_01c;
        switch (gSelectCharacter->mUnk_07c) {
            case 8:
                positions = data_021534bc;
                func_02027be0();
                break;
            case 9:
                positions = data_021534dc;
                func_02027a58();
                break;
            case 10:
                positions = data_02153500;
                func_02027850();
                break;
            case 11:
                positions = data_02153528;
                func_02027648();
                break;
            case 12:
                func_02027448();
                break;
        }
        if (positions != NULL) {
            for (i = 0; i < gSelectCharacter->mUnk_07c; i++) {
                func_02025c94(data_usa_02153554[i].mUnk_00, positions[i].mUnk_00, positions[i].mUnk_02,
                              sParts->mCellLayout);
                func_02025c94(data_usa_02153554[i].mUnk_02, positions[i].mUnk_00, positions[i].mUnk_02,
                              sParts->mCellLayout);
                RectTableSetEntryXY(data_usa_02153554[i].mRectEntryId, positions[i].mUnk_00, positions[i].mUnk_02,
                                    sParts->mRects);
                func_02025c94(data_usa_02153554[i].mUnk_04, (s16) (positions[i].mUnk_00 + 3),
                              (s16) (positions[i].mUnk_02 + 3), sParts->mCellLayout);
            }
            for (; i < 12; i++) {
                sParts->mCellTable[data_usa_02153554[i].mUnk_00].mVisible = 0;
                sParts->mCellTable[data_usa_02153554[i].mUnk_02].mVisible = 0;
                sParts->mCellTable[data_usa_02153554[i].mUnk_04].mVisible = 0;
                RectTableSetEntryXY(data_usa_02153554[i].mRectEntryId, 0x400, 0x400, sParts->mRects);
            }
        }
        func_020271e8();
        func_0202721c();
    }
    if (gSelectCharacter->mUnk_080 == 0) {
        func_021170f8();
        SetSelectReturnSoundId(0xe);
        RequestSelectReturnState1();
    }
    if (AreBrightnessFadesClear() != 0) {
        gSelectCharacter->mUnk_06c = 1;
    } else {
        StartFadeToClear(10);
        func_0202734c(0);
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        func_02077f48(0);
    }
    FrmHeapShrinkInParent(gSelectCharacter->mHeap);
}

#pragma thumb off

#pragma thumb on

static inline s32 func_02026120_inline(u16 inputSlot) {
    BOOL result = FALSE;
    if (data_02175674[inputSlot].mUnk_00 == 0 && data_02175680[inputSlot].mUnk_00 < 5) {
        result = TRUE;
    }
    return result;
}

static inline s32 func_02026120_inline_2(u16 inputSlot) {
    BOOL result = FALSE;
    if (func_02026120_inline(inputSlot) == 0 && data_0217567c[inputSlot].mUnk_00 == 0 &&
        data_02175674[inputSlot].mUnk_00 != 0) {
        result = TRUE;
    }
    return result;
}

int AdvanceSelectCharacter(void) {
    int result;
    Unk02174e14 *selectCharacter;
    CellFileSet *sParts;
    s32 previousTableIndex;
    Unk02174e14 *selectCharacterReload;
    u16 inputSlot;
    s32 nextState;
    s32 tableIndex;
    s32 rectEntryId;
    s32 pointX;
    s32 pointY;
    u16 keyBits;
    u8 flaggedCharacterIndex;
    s16 targetTableIndex;
    s16 interpolatedValue;

    result = 0;
    inputSlot = func_020435bc();
    selectCharacter = gSelectCharacter;
    sParts = &selectCharacter->mUnk_01c;
    switch (selectCharacter->mUnk_06c) {
        case 0:
            if (AreBrightnessFadesClear() != 0) {
                gSelectCharacter->mUnk_06c = 1;
            }
            break;
        case 1:
            if (selectCharacter->mUnk_068 == 0) {
                func_0202734c(1);
            }
            gSelectCharacter->mUnk_068++;
            selectCharacterReload = gSelectCharacter;
            if (selectCharacterReload->mUnk_068 < 10) {
                selectCharacterReload->mUnk_070 = (selectCharacterReload->mUnk_068 << 12) / 10;
            } else {
                selectCharacterReload->mUnk_070 = 0x1000;
                gSelectCharacter->mUnk_068 = 0;
                if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
                    nextState = 2;
                } else {
                    nextState = 3;
                }
                gSelectCharacter->mUnk_06c = nextState;
            }
            func_02027084();
            break;
        case 2:
            selectCharacter->mCharacterIndex = 0xc;
            gSelectCharacter->mKartIndex = 0x24;
            gSelectCharacter->mUnk_068 = 0;
            gSelectCharacter->mUnk_08c = 1;
            if (GetRaceSetupCopy()->mMode == 3) {
                flaggedCharacterIndex = gSelectCharacter->mCharacterIndex | 0x40;
                if (data_0217aa00->mUnk_0004 == 8) {
                    data_0217aa00->mUnk_15f7 = flaggedCharacterIndex;
                }
                func_02027424(1);
                gSelectCharacter->mUnk_06c = 8;
            } else if (GetRaceSetupCopy()->mMode == 2) {
                flaggedCharacterIndex = gSelectCharacter->mCharacterIndex | 0xc0;
                if (data_0217aa00->mUnk_0004 == 8) {
                    data_0217aa00->mUnk_15f7 = flaggedCharacterIndex;
                }
                gSelectCharacter->mUnk_06c = 6;
            }
            break;
        case 3:
            previousTableIndex = selectCharacter->mUnk_060;
            if (func_02026120_inline_2(inputSlot) != 0) {
                pointX = data_02175670[inputSlot].mUnk_00;
                pointY = data_02175672[inputSlot].mUnk_00;
                rectEntryId = RectTableFindContaining(sParts->mRects, pointX, pointY);
                if (rectEntryId >= 0) {
                    for (tableIndex = 0; tableIndex < gSelectCharacter->mUnk_07c; tableIndex++) {
                        if (rectEntryId == data_usa_02153554[tableIndex].mRectEntryId) {
                            gSelectCharacter->mUnk_060 = tableIndex;
                            break;
                        }
                    }
                    func_020270fc(previousTableIndex);
                    func_021106a8(func_02025eb0(gSelectCharacter->mCharacterIndex), 0);
                    gSelectCharacter->mUnk_068 = 0;
                    gSelectCharacter->mUnk_06c = 5;
                } else if (gSelectCharacter->mUnk_080 == 0 &&
                           IsSelectReturnState2NoState3Or4RequestAndInRect(pointX, pointY) != FALSE) {
                    StartSelectCharacterReturn();
                }
            } else if (func_020270d0() != 0) {
                gSelectCharacter->mUnk_068 = 0;
                gSelectCharacter->mUnk_08c = 3;
                gSelectCharacter->mUnk_06c = 6;
                func_021106a8(func_02025eb0(gSelectCharacter->mCharacterIndex), 0);
                func_02077f48(1);
                selectCharacterReload = gSelectCharacter;
                switch (selectCharacterReload->mUnk_080) {
                    case 2:
                        SetWiFiSessionOwnCharacterIndex(selectCharacterReload->mCharacterIndex);
                        SetWiFiSessionOwnKartIndex(gSelectCharacter->mKartIndex);
                        break;
                    case 1:
                        flaggedCharacterIndex = selectCharacterReload->mCharacterIndex | 0xc0;
                        if (data_0217aa00->mUnk_0004 == 8) {
                            data_0217aa00->mUnk_15f7 = flaggedCharacterIndex;
                        }
                        break;
                }
            } else {
                keyBits = data_02175628[inputSlot].mUnk_00;
                if ((u16) (keyBits & PAD_KEY_A) != 0) {
                    gSelectCharacter->mUnk_068 = 0;
                    gSelectCharacter->mUnk_06c = 5;
                    func_02027188();
                    func_021106a8(func_02025eb0(gSelectCharacter->mCharacterIndex), 0);
                } else if (gSelectCharacter->mUnk_080 == 0 && (u16) (keyBits & PAD_KEY_B) != 0) {
                    StartSelectCharacterReturn();
                } else {
                    if (GetNewOrRepeatBits(inputSlot, PAD_KEY_UP) != 0) {
                        selectCharacterReload = gSelectCharacter;
                        targetTableIndex = selectCharacterReload->mTableIndexByKey[0];
                        if (targetTableIndex != -1) {
                            selectCharacterReload->mUnk_060 = targetTableIndex;
                        }
                    } else if (GetNewOrRepeatBits(inputSlot, PAD_KEY_DOWN) != 0) {
                        selectCharacterReload = gSelectCharacter;
                        targetTableIndex = selectCharacterReload->mTableIndexByKey[1];
                        if (targetTableIndex != -1) {
                            selectCharacterReload->mUnk_060 = targetTableIndex;
                        }
                    } else if (GetNewOrRepeatBits(inputSlot, PAD_KEY_RIGHT) != 0) {
                        selectCharacterReload = gSelectCharacter;
                        targetTableIndex = selectCharacterReload->mTableIndexByKey[2];
                        if (targetTableIndex != -1) {
                            selectCharacterReload->mUnk_060 = targetTableIndex;
                        }
                    } else if (GetNewOrRepeatBits(inputSlot, PAD_KEY_LEFT) != 0) {
                        selectCharacterReload = gSelectCharacter;
                        targetTableIndex = selectCharacterReload->mTableIndexByKey[3];
                        if (targetTableIndex != -1) {
                            selectCharacterReload->mUnk_060 = targetTableIndex;
                        }
                    }
                    if (gSelectCharacter->mUnk_060 != previousTableIndex) {
                        func_02110698();
                        func_020270fc(previousTableIndex);
                        gSelectCharacter->mUnk_06c = 4;
                    }
                }
            }
            break;
        case 4:
            selectCharacter->mUnk_068++;
            if (gSelectCharacter->mUnk_068 > 5) {
                func_020272ec();
                gSelectCharacter->mUnk_068 = 0;
                gSelectCharacter->mUnk_06c = 3;
            }
            break;
        case 5:
            selectCharacter->mUnk_068++;
            selectCharacterReload = gSelectCharacter;
            if (selectCharacterReload->mUnk_068 > 5) {
                selectCharacterReload->mUnk_068 = 0;
                gSelectCharacter->mUnk_08c = 1;
                func_020272ec();
                selectCharacterReload = gSelectCharacter;
                switch (selectCharacterReload->mUnk_080) {
                    case 0:
                        GetRaceSetupCopy()->mEntries[gSelectCharacter->mEntryIndex].mCharacterIndex =
                            selectCharacterReload->mCharacterIndex;
                        GetRaceSetupCopy()->mEntries[gSelectCharacter->mEntryIndex].mKartIndex =
                            gSelectCharacter->mKartIndex;
                        FillRandomCharacterIndices();
                        if (GetRaceSetupCopy()->mMode == 2) {
                            GetRaceSetupCopy()->mEntries[gSelectCharacter->mEntryIndex].mUnk_14 = 1;
                            func_02077f48(1);
                            gSelectCharacter->mUnk_06c = 7;
                            func_02117060();
                            SetKartIndicesFromCharacters();
                        } else {
                            func_02027424(1);
                            func_02077f5c();
                            gSelectCharacter->mUnk_06c = 8;
                            func_02025f14(&gSelectCharacter->mInterpolations[1], 2);
                        }
                        break;
                    case 1:
                        if (GetRaceSetupCopy()->mMode == 3) {
                            flaggedCharacterIndex = gSelectCharacter->mCharacterIndex | 0x40;
                            if (data_0217aa00->mUnk_0004 == 8) {
                                data_0217aa00->mUnk_15f7 = flaggedCharacterIndex;
                            }
                            func_02025f14(&gSelectCharacter->mInterpolations[1], 2);
                            func_02027424(1);
                            gSelectCharacter->mUnk_06c = 8;
                            func_02077f5c();
                        } else if (GetRaceSetupCopy()->mMode == 2) {
                            flaggedCharacterIndex = gSelectCharacter->mCharacterIndex | 0xc0;
                            if (data_0217aa00->mUnk_0004 == 8) {
                                data_0217aa00->mUnk_15f7 = flaggedCharacterIndex;
                            }
                            func_02077f48(1);
                            gSelectCharacter->mUnk_06c = 6;
                        }
                        break;
                    case 2:
                        SetWiFiSessionOwnCharacterIndex(selectCharacterReload->mCharacterIndex);
                        func_02025f14(&gSelectCharacter->mInterpolations[1], 2);
                        func_02027424(1);
                        gSelectCharacter->mUnk_06c = 8;
                        func_02077f5c();
                        break;
                }
            }
            break;
        case 6:
            if ((selectCharacter->mUnk_080 == 1 && IsEveryPlayerKartStored() != 0) ||
                (gSelectCharacter->mUnk_080 == 2 && func_02121d0c() != 0)) {
                if (gSelectCharacter->mUnk_080 == 2) {
                    func_021219cc();
                }
                if (GetRaceSetupCopy()->mMode == 2 || func_020270d0() != 0) {
                    gSelectCharacter->mUnk_06c = 7;
                } else {
                    func_02027424(1);
                    func_02025f14(&gSelectCharacter->mInterpolations[1], 2);
                    gSelectCharacter->mUnk_06c = 8;
                }
            }
            break;
        case 7:
            selectCharacter->mUnk_068++;
            selectCharacterReload = gSelectCharacter;
            if (selectCharacterReload->mUnk_068 > 60) {
                if (selectCharacterReload->mUnk_080 == 2) {
                    func_02027424(3);
                } else {
                    func_02027424(2);
                }
                func_02025f14(&gSelectCharacter->mInterpolations[1], 2);
                if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
                    StartKartModelMenuBg0Decrease();
                } else if (GetRaceSetupCopy()->mMode == 2) {
                    func_0211f378();
                }
                gSelectCharacter->mUnk_068 = 0;
                gSelectCharacter->mUnk_06c = 8;
            }
            break;
        case 8:
            selectCharacter->mUnk_068++;
            selectCharacterReload = gSelectCharacter;
            if (selectCharacterReload->mUnk_068 < 10) {
                selectCharacterReload->mUnk_070 = ((10 - selectCharacterReload->mUnk_068) << 12) / 10;
            } else {
                GetRaceSetupCopy()->mEntries[gSelectCharacter->mEntryIndex].mCharacterIndex =
                    selectCharacterReload->mCharacterIndex;
                GetRaceSetupCopy()->mEntries[gSelectCharacter->mEntryIndex].mKartIndex = gSelectCharacter->mKartIndex;
                gSelectCharacter->mUnk_06c = 9;
            }
            gSelectCharacter->mUnk_074 += 0x1000;
            func_02027084();
            break;
        case 9:
            result = selectCharacter->mUnk_08c;
            break;
    }

    AdvanceInterpolation(&gSelectCharacter->mInterpolations[0]);
    AdvanceInterpolation(&gSelectCharacter->mInterpolations[1]);
    AdvanceInterpolation(&gSelectCharacter->mInterpolations[2]);
    func_0202728c(GetInterpolatedValue(&gSelectCharacter->mInterpolations[0]));
    interpolatedValue = GetInterpolatedValue(&gSelectCharacter->mInterpolations[1]);
    func_020272c0(interpolatedValue, GetInterpolatedValue(&gSelectCharacter->mInterpolations[2]));
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        selectCharacterReload = gSelectCharacter;
        if (selectCharacterReload->mUnk_08c != 2) {
            RequestKartModelMenuCharacter(selectCharacterReload->mCharacterIndex);
            RequestKartModelMenuKart(gSelectCharacter->mKartIndex);
        }
        AdvanceKartModelMenu(GetRaceSetupCopy()->mMirrorMode);
    }
    if (gSelectCharacter->mUnk_128 != FALSE) {
        AdvancePlayerEntryList();
    } else {
        DrawLayoutTable(selectCharacter->mUnk_000.mCellLayout, selectCharacter->mUnk_000.mCells, NULL,
                        gSelectCharacter->mMainOam, selectCharacter->mUnk_000.mCellTable);
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        func_02124bf0(sParts->mCellLayout, sParts->mCells, NULL, gSelectCharacter->mUnk_058, sParts->mCellTable);
        func_020ae5d4(gSelectCharacter->mUnk_058);
    } else if (GetRaceSetupCopy()->mMode == 2) {
        AdvanceSelectRaceRuleWait();
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        DrawKartModelMenu();
    }
    switch (result) {
        case 1:
            if (GetRaceSetupCopy()->mMode == 2) {
                GetRaceSetupCopy()->mUnk_108 = 0;
            } else {
                GetRaceSetupCopy()->mUnk_108 = 1;
            }
            break;
        case 2:
            if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
                RequestKartModelMenuCharacter(-1);
                RequestKartModelMenuKart(-1);
            }
            GetRaceSetupCopy()->mUnk_108 = 0;
            break;
    }
    return result;
}

#pragma thumb off

#pragma thumb on

void ReleaseSelectCharacter(void) {
    if (*(vu16 *) 0x27ffc40 == 2) {
        if (GetRaceSetupCopy()->mMode == 2) {
            func_0211f498();
        }
    }
    HeapDestroy(gSelectCharacter->mHeap);
    gSelectCharacter = NULL;
}

void WriteSelectCharacterRegisters(void) {
    u32 displayBits = 0x18;

    G2x_SetBlendAlpha_(&reg_G2S_DB_BLDCNT, 0, 0x3f, 6, 10);
    if (!(gSelectCharacter->mUnk_06c == 9 && gSelectCharacter->mUnk_08c == 2)) {
        displayBits |= 1;
    }
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | (displayBits << 8);
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | 0x1600;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 1;
    if (gSelectCharacter->mUnk_128 != FALSE) {
        WritePlayerEntryListRegisters();
    }
}

void func_02025f90(void) {
    Ncgr *chars = NULL;
    Nclr *palette = NULL;
    Unk02021dc8 *cells = NULL;

    LoadNcgrData2(&chars, FindFileInLoadedArchives(data_usa_02161b3c));
    LoadNcerData(&cells, FindFileInLoadedArchives(data_usa_02161b5c));
    LoadNclrData(&palette, FindFileInLoadedArchives(data_usa_02161b7c));
    LoadNcgrData2(&chars, FindFileInLoadedArchives(data_usa_02161b9c));
    LoadNcerData(&cells, FindFileInLoadedArchives(data_usa_02161bb8));
    LoadNclrData(&palette, FindFileInLoadedArchives(data_usa_02161bd4));
    LoadNcgrData2(&chars, FindFileInLoadedArchives(data_usa_02161bf0));
    LoadNcerData(&cells, FindFileInLoadedArchives(data_usa_02161c14));
    LoadNcgrData2(&chars, FindFileInLoadedArchives(data_usa_02161c38));
    LoadNcerData(&cells, FindFileInLoadedArchives(data_usa_02161c60));
}

void SetupInterpolation(Interpolation *interpolation, s32 state, s32 counterLimit, s16 startValue, s32 endValue) {
    interpolation->mCounterLimit = counterLimit;
    interpolation->mStartValue = startValue;
    interpolation->mEndValue = endValue;
    func_02025f14(interpolation, state);
}

#pragma thumb off
