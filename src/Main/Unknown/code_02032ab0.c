#include "Main/Unknown/code_02032ab0.h"
#include "Main/Unknown/code_0202578c.h"

#include "00/code_021832d8.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_020336ec.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_02033d9c.h"
#include "Main/Unknown/code_02033dd0.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_02054f58.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_0210f714.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bc8.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02125da0.h"
#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_021277ac.h"
#include "Main/Unknown/code_020a23a0.h"
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
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "00/code_0219b580.h"
#include "Main/Unknown/code_02025b84.h"
#include "Main/Unknown/code_02033000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_02062000.h"
#include "Main/Unknown/code_020ad000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020cbad0.h"
#include "Main/Unknown/code_02122734.h"
#include "Main/Unknown/code_02122b14.h"
#include "Main/Unknown/code_02125960.h"
#include "Main/Unknown/code_02125de0.h"
#include "code_02148950.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02164000.h"
#include "01/code_021804e0.h"
#include "code_0201ea30.h"
#include "code_0214b824.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"

#pragma thumb on

// Fills with 0 through a halfword stack offset of its own.
static inline void func_02032f94_inline(void *buffer, s32 byteCount) {
    volatile u16 fillValue = 0;
    MIi_CpuClear16(fillValue, buffer, byteCount);
}

static inline Unk0217aa1c_144_00 *func_02032f94_inline_2(s32 index) {
    return &gCupRecords->mUnk_144[GetCourseIndexInCup()].mUnk_00[index];
}

static inline Unk0217aa1c_144 *func_02032f94_inline_3(void) {
    return &gCupRecords->mUnk_144[GetCourseIndexInCup()];
}

void InitResultsBattle(void *heap, s32 b, s32 c) {
    Unk02180774 *displaySettings;
    CellFileSet *mainCellFileSet;
    CellFileSet *subCellFileSet;
    ResultsBattle *results;
    ScreenMapFileSet *screenMapFileSet;
    Unk0201ea30 *cellLayout;
    u32 remainingObjSize;
    s32 j;
    s32 k;
    s32 orderIndex;
    u16 i;
    u16 entryIndex;
    u16 entryName[11];
    Unk02125de0Arg v;
    s32 orderUsed[8];

    gResultsBattle = HeapAlloc(heap, 0x154);
    MemFillWordsByBlock_inline(gResultsBattle, 0x154);
    gResultsBattle->mUnk_0b8[0] = b;
    gResultsBattle->mUnk_0b8[1] = c;
    gResultsBattle->mMode = data_021759d0->mUnk_20;
    if (gResultsBattle->mMode == 3) {
        SetupWiFiSession(3);
    }
    Init3dEngine();
    displaySettings = CreateDisplaySettings(heap, data_021547f0);
    SetBg0Record(displaySettings->mMainBgRecords, 3, 0, 0, 0, 0xd, 2, 0);
    SetBg1Record(displaySettings->mMainBgRecords, 0, 0, 0, 0, 0xc, 0, 0);
    SetBg2RecordParams(displaySettings->mMainBgRecords, 2, 0, 0, 0, 0x1e, 6);
    SetBg3RecordParams(displaySettings->mMainBgRecords, 3, 0, 0, 0, 0x1d, 6);
    SetBg3RecordParams(displaySettings->mSubBgRecords, 3, 0, 0, 0, 1, 6);
    InitDisplayFromSettings(displaySettings);
    v.mUnk_00 = 0;
    v.mUnk_04 = NULL;
    v.mUnk_08 = 0;
    v.mUnk_0c = 0;
    v.mUnk_10 = 0;
    v.mUnk_14 = 1;
    v.mUnk_18 = func_020b403c(2);
    v.mUnk_1c = 0;
    v.mUnk_20 = 0;
    v.mUnk_24 = 0;
    LoadTxtSystemAndSelectChoisesAndSelectReturnData();
    func_02125de0(heap, &v);
    func_020629a4();
    gResultsBattle->mCommonMessages = FindFileInLoadedArchives(data_0216416c);
    switch (gResultsBattle->mMode) {
        case 0:
            gResultsBattle->mOwnEntryIndex = 0;
            gResultsBattle->mKartCount = gRaceSetup->mKartCount;
            gResultsBattle->mState = 2;
            break;
        case 1:
        case 2:
            SetSelectChoisesSoundId(1, 0xf);
            gResultsBattle->mOwnEntryIndex =
                data_0217aa00->mUnk_1e52[(u16) (data_0217aa00->mUnk_0000 == 2 ? data_0217aa00->mOwnIndex : 0)]
                    .mEntryIndex;
            gResultsBattle->mKartCount = gRaceSetup->mKartCount;
            gResultsBattle->mState = 0;
            break;
        case 3:
            gResultsBattle->mOwnEntryIndex = GetPackedIndex(func_ov000_0219bb50());
            gResultsBattle->mKartCount = gWiFiSession->mKartCount;
            gResultsBattle->mUseTimer = TRUE;
            gResultsBattle->mTimer = 0x384;
            gResultsBattle->mState = 2;
            break;
    }
    FillResultsBattleEntries();
    if (gRaceSetup->mUseTeams != 0) {
        j = 0;
        k = 0;
        switch (gRaceSetup->mRuleKind) {
            case 1:
                j = func_02032f94_inline_2(0)->mUnk_02;
                k = func_02032f94_inline_2(1)->mUnk_02;
                break;
            case 2:
                j = func_02032f94_inline_3()->mUnk_00[0].mUnk_00;
                k = func_02032f94_inline_3()->mUnk_00[1].mUnk_00;
                break;
        }
        if (j == k) {
            gResultsBattle->mUnk_0d4 = gResultsBattle->mKartCount;
            gResultsBattle->mFileSetKind = 2;
        } else if (j > k) {
            gResultsBattle->mUnk_0d4 = gRaceSetup->mTeamKartCounts[0];
            gResultsBattle->mFileSetKind = 3;
        } else if (k > j) {
            gResultsBattle->mUnk_0d4 = gRaceSetup->mTeamKartCounts[1];
            gResultsBattle->mFileSetKind = 4;
        }
    } else if (AreResultsBattleRanksAllZero() != 0) {
        gResultsBattle->mUnk_0d4 = gResultsBattle->mKartCount;
        gResultsBattle->mFileSetKind = 2;
    } else if (gResultsBattle->mEntries[gResultsBattle->mOwnEntryIndex].mRank == 0) {
        gResultsBattle->mFileSetKind = 0;
    } else {
        gResultsBattle->mFileSetKind = 1;
    }
    func_02025b84(1, &gResultsBattle->mCellFileSets[2]);
    func_02025b84(0, &gResultsBattle->mCellFileSets[3]);
    gResultsBattle->mUnk_0c0 = func_020b4024(1);
    gResultsBattle->mUnk_0c4 = func_020b4024(0);
    screenMapFileSet = &gResultsBattle->mScreenMapFileSets[0];
    LoadScreenMapFileSet(screenMapFileSet, data_02153f80[gResultsBattle->mFileSetKind][0],
                         data_02153f84[gResultsBattle->mFileSetKind][0], data_02153f8c[gResultsBattle->mFileSetKind][0],
                         3, FindSceneFile);
    LoadNscrData(&screenMapFileSet->mScreenMaps[2], FindSceneFile(data_02153f88[gResultsBattle->mFileSetKind][0]));
    GX_LoadBG3Char(screenMapFileSet->mChars[3]->mData, 0, screenMapFileSet->mChars[3]->mDataSize);
    GX_LoadBGPltt(screenMapFileSet->mPalette->mData, 0, 0x140);
    GX_LoadBG2Scr(screenMapFileSet->mScreenMaps[2]->mData, 0, screenMapFileSet->mScreenMaps[2]->mDataSize);
    GX_LoadBG3Scr(screenMapFileSet->mScreenMaps[3]->mData, 0, screenMapFileSet->mScreenMaps[3]->mDataSize);
    mainCellFileSet = &gResultsBattle->mCellFileSets[0];
    LoadCellFileSet(mainCellFileSet, data_02153f90[gResultsBattle->mFileSetKind][0],
                    data_02153f94[gResultsBattle->mFileSetKind][0], data_02153f98[gResultsBattle->mFileSetKind][0],
                    data_02153f9c[gResultsBattle->mFileSetKind][0], data_02153fa0[gResultsBattle->mFileSetKind][0],
                    NULL, FindSceneFile);
    func_02025a50(0, heap, mainCellFileSet);
    switch (gResultsBattle->mFileSetKind) {
        case 0:
            func_02033a0c(heap);
            break;
        case 1:
            func_020338f8(heap);
            break;
        case 2:
            func_02033840(heap);
            break;
        case 3:
        case 4:
            func_020336ec(heap);
            break;
    }
    cellLayout = mainCellFileSet->mCellLayout;
    for (i = 0; i < cellLayout->mUnk_06; i++) {
        func_0201ea30(mainCellFileSet->mCellLayout, i);
    }
    screenMapFileSet = &gResultsBattle->mScreenMapFileSets[1];
    LoadScreenMapFileSet(screenMapFileSet, gResultsBattleSBNcgrName, gResultsBattleSBNclrName,
                         gResultsBattleSBgNscrName, 3, FindSceneFile);
    GXS_LoadBG3Char(screenMapFileSet->mChars[3]->mData, 0, screenMapFileSet->mChars[3]->mDataSize);
    GXS_LoadBGPltt(screenMapFileSet->mPalette->mData, 0, 0x140);
    GXS_LoadBG3Scr(screenMapFileSet->mScreenMaps[3]->mData, 0, screenMapFileSet->mScreenMaps[3]->mDataSize);
    remainingObjSize = GX_GetSizeOfSubOBJ();
    results = gResultsBattle;
    subCellFileSet = &results->mCellFileSets[1];
    LoadCellFileSet(subCellFileSet, gResultsBattleSNcgrName, gResultsBattleSNcerName, gResultsBattleSONclrName,
                    gResultsBattleSBnclName, gResultsBattleSBnllName, NULL, FindSceneFile);
    InitLayoutTable(heap, subCellFileSet->mCellLayout, subCellFileSet->mLabelLayout, &subCellFileSet->mCellTable);
    GXS_LoadOBJ(((Ncgr *) results->mCellFileSets[1].mChars)->mData, 0,
                ((Ncgr *) results->mCellFileSets[1].mChars)->mDataSize);
    GXS_LoadOBJPltt(((Nclr *) subCellFileSet->mPalette)->mData, 0, ((Nclr *) subCellFileSet->mPalette)->mDataSize);
    for (i = 0; i < subCellFileSet->mLabelLayout->mUnk_06; i++) {
        remainingObjSize -= func_02025a00(1, heap, subCellFileSet, data_02153f00[i], remainingObjSize);
    }
    for (i = 0; i < subCellFileSet->mCellLayout->mUnk_06; i++) {
        func_021249a8(i, 2, subCellFileSet->mCells, subCellFileSet->mCellLayout);
    }
    for (i = 0; i < 8; i++) {
        orderUsed[i] = 0;
    }
    for (entryIndex = 0; entryIndex < 8; entryIndex++) {
        orderIndex = gResultsBattle->mEntries[entryIndex].mOrderIndex;
        k = gRaceSetup->mCurrentEntries[entryIndex].mPlayer.mKind;
        if ((k == PLAYER_KIND_HUMAN || k == PLAYER_KIND_CPU || k == PLAYER_KIND_PEER) &&
            (gResultsBattle->mMode != 3 || gResultsBattle->mEntries[entryIndex].mScore != 0)) {
            func_02033ab8(1, entryIndex, orderIndex + 0x30, 1);
            func_02032f94_inline(entryName, 0x16);
            CopyKartEntryName(entryIndex, entryName, 0);
            func_0212426c(1, orderIndex, subCellFileSet->mLabelLayout, entryName, subCellFileSet->mCellLayout,
                          subCellFileSet->mCellTable);
            func_02033b80(entryIndex);
            func_02033c80(entryIndex);
            orderUsed[orderIndex] = 1;
        }
    }
    for (i = 0; i < 8; i++) {
        if (orderUsed[i] == 0) {
            subCellFileSet->mCellTable[i + 0x48].mVisible = 0;
            subCellFileSet->mCellTable[i + 0x30].mVisible = subCellFileSet->mCellTable[i + 0x48].mVisible;
            subCellFileSet->mCellTable[i + 0x38].mVisible = subCellFileSet->mCellTable[i + 0x30].mVisible;
            subCellFileSet->mCellTable[i + 0x28].mVisible = subCellFileSet->mCellTable[i + 0x38].mVisible;
            subCellFileSet->mCellTable[i + 0x20].mVisible = subCellFileSet->mCellTable[i + 0x28].mVisible;
            subCellFileSet->mCellTable[i + 0x18].mVisible = subCellFileSet->mCellTable[i + 0x20].mVisible;
            subCellFileSet->mCellTable[i + 0x10].mVisible = subCellFileSet->mCellTable[i + 0x18].mVisible;
            subCellFileSet->mCellTable[i + 0x08].mVisible = subCellFileSet->mCellTable[i + 0x10].mVisible;
            subCellFileSet->mCellTable[i].mVisible = subCellFileSet->mCellTable[i + 0x08].mVisible;
        }
    }
    switch (gResultsBattle->mFileSetKind) {
        case 3:
            if (gRaceSetup->mCurrentEntries[(u16) gResultsBattle->mOwnEntryIndex].mPlayer.mTeamIndex == 0) {
                k = 0;
            } else {
                k = 7;
            }
            break;
        case 4:
            if (gRaceSetup->mCurrentEntries[(u16) gResultsBattle->mOwnEntryIndex].mPlayer.mTeamIndex == 1) {
                k = 0;
            } else {
                k = 7;
            }
            break;
        case 0:
            k = 0;
            break;
        default:
            k = 7;
            break;
    }
    func_020a269c(8, (u16) k);
}

#pragma thumb off

#pragma thumb on

void AdvanceResultsBattle(Unk02032ac4 *sceneNumbers) {
    CellFileSet *mainCellFileSet;
    CellFileSet *subCellFileSet;
    InputSlotIndex inputSlotIndex;
    s32 shownTimer;
    s32 cellCount;
    void *tensCellLayout;
    void *tensCells;
    void *unitsCellLayout;
    void *unitsCells;
    s32 i;
    s32 frameLimit;

    subCellFileSet = &gResultsBattle->mCellFileSets[1];
    mainCellFileSet = &gResultsBattle->mCellFileSets[0];
    if (gResultsBattle->mUseTimer != FALSE) {
        if (gResultsBattle->mTimer != 0) {
            gResultsBattle->mTimer = gResultsBattle->mTimer - 1;
            shownTimer = (gResultsBattle->mTimer + 0x3c) / 0x3c;
            mainCellFileSet->mCellTable[gResultsBattle->mTimerTensCell].mVisible = shownTimer >= 10 ? 1 : 0;
            if (gResultsBattle->mTimer == 0) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x51);
            } else if ((gResultsBattle->mTimer + 0x3c) % 0x3c == 0 && shownTimer <= 4) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x50);
            }
        } else {
            shownTimer = 0;
        }
        tensCellLayout = mainCellFileSet->mCellLayout;
        tensCells = mainCellFileSet->mCells;
        QueueCellChars(gResultsBattle->mTimerDigitCellBase + (shownTimer / 10) % 10, tensCells, mainCellFileSet->mChars,
                       tensCellLayout, 0, gResultsBattle->mTimerTensCell, tensCells, tensCellLayout);
        unitsCellLayout = mainCellFileSet->mCellLayout;
        unitsCells = mainCellFileSet->mCells;
        QueueCellChars(gResultsBattle->mTimerDigitCellBase + shownTimer % 10, unitsCells, mainCellFileSet->mChars,
                       unitsCellLayout, 0, gResultsBattle->mTimerTensCell + 1, unitsCells, unitsCellLayout);
    } else {
        mainCellFileSet->mCellTable[gResultsBattle->mTimerTensCell + 1].mVisible = 0;
        mainCellFileSet->mCellTable[gResultsBattle->mTimerTensCell].mVisible =
            mainCellFileSet->mCellTable[gResultsBattle->mTimerTensCell + 1].mVisible;
    }
    switch (gResultsBattle->mState) {
        case 0:
            gResultsBattle->mState0To2Frames = gResultsBattle->mState0To2Frames + 1;
            if (StartDataSharingSync() == 1) {
                gResultsBattle->mState = 1;
            }
            break;
        case 1:
            gResultsBattle->mState0To2Frames = gResultsBattle->mState0To2Frames + 1;
            if (FinishDataSharingSync() == 1) {
                gResultsBattle->mState = 2;
            }
            break;
        case 2:
            frameLimit = func_0210f714();
            gResultsBattle->mState0To2Frames = gResultsBattle->mState0To2Frames + 1;
            if (gResultsBattle->mState0To2Frames > frameLimit) {
                gResultsBattle->mState0To2Frames = 0;
                gResultsBattle->mState = 3;
            }
            break;
        case 3:
            switch (gResultsBattle->mMode) {
                case 0:
                    if ((u16) (data_02175628[func_020435bc()].mUnk_00 & PAD_KEY_A) != 0) {
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 5);
                        if (sceneNumbers != NULL) {
                            sceneNumbers->mUnk_04 = 1;
                        }
                        gResultsBattle->mState = 7;
                    }
                    break;
                case 1:
                case 2:
                    inputSlotIndex = UNK_02175628_INDEX_8;
                    if ((u16) (data_02175628[inputSlotIndex].mUnk_00 & PAD_KEY_A) != 0) {
                        StartResultsBattleChoices();
                        gResultsBattle->mState = 4;
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 5);
                    }
                    break;
                case 3:
                    if (IsResultsBattleTimerRunOut() != 0) {
                        func_02121dec(1);
                        gResultsBattle->mState = 5;
                    } else if ((u16) (data_02175628[func_020435bc()].mUnk_00 & PAD_KEY_A) != 0 ||
                               func_02033dd0() != 0) {
                        StartResultsBattleChoices();
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 5);
                        gResultsBattle->mState = 4;
                    }
                    break;
            }
            break;
        case 4:
            switch (gResultsBattle->mMode) {
                case 1:
                case 2:
                    if (GetSelectChoisesDone() != 0) {
                        switch (GetSelectChoisesIndex()) {
                            case 0:
                                if (data_021759d0->mUnk_1c_2 != 0) {
                                    data_0217b488->mUnk_74 = 3;
                                    data_0217b488->mUnk_08 = 4;
                                    if (sceneNumbers != NULL) {
                                        sceneNumbers->mUnk_04 = 6;
                                    }
                                } else {
                                    data_0217b488->mUnk_08 = 4;
                                    if (sceneNumbers != NULL) {
                                        sceneNumbers->mUnk_04 = 1;
                                    }
                                }
                                gResultsBattle->mState = 7;
                                break;
                            case 1:
                                data_0217aa00->mUnk_0454 = data_0217aa00->mUnk_0454 | 0x80;
                                gResultsBattle->mState = 6;
                                break;
                            case -1:
                                gResultsBattle->mState = 3;
                                break;
                        }
                        RequestSelectChoisesState0();
                    }
                    break;
                case 3:
                    if (GetSelectChoisesDone() != 0 || IsResultsBattleTimerRunOut() != 0) {
                        switch (GetSelectChoisesIndex()) {
                            case 0:
                                gResultsBattle->mState = 5;
                                func_02121dec(1);
                                break;
                            case 1:
                                func_02121dec(0);
                                data_0217b488->mUnk_1c = 1;
                                if (sceneNumbers != NULL) {
                                    sceneNumbers->mUnk_04 = 0xc;
                                }
                                gResultsBattle->mState = 7;
                                break;
                            case -1:
                                gResultsBattle->mState = 3;
                                break;
                        }
                        RequestSelectChoisesState0();
                    }
                    break;
            }
            break;
        case 5:
            if (func_02121c78() != 0) {
                switch (func_02121c78()) {
                    case 1:
                        data_0217b488->mUnk_1c = 2;
                        break;
                    case 2:
                        data_0217b488->mUnk_1c = 1;
                        break;
                }
                if (sceneNumbers != NULL) {
                    sceneNumbers->mUnk_04 = 0xc;
                }
                gResultsBattle->mState = 7;
            }
            break;
        case 6:
            if (func_02054f58() == 1) {
                if (sceneNumbers != NULL) {
                    sceneNumbers->mUnk_04 = 0;
                }
                gResultsBattle->mState = 7;
            }
            break;
    }
    func_020a2558();
    func_020a23cc();
    for (i = 0; i < 2; i++) {
        DrawLayoutTable(gResultsBattle->mCellFileSets[i].mCellLayout, gResultsBattle->mCellFileSets[i].mCells,
                        gResultsBattle->mCellFileSets[i].mLabelLayout, (void *) gResultsBattle->mUnk_0b8[i],
                        gResultsBattle->mCellFileSets[i].mCellTable);
    }
    cellCount = subCellFileSet->mCellLayout->mUnk_06;
    for (i = 0; i < 8; i++) {
        subCellFileSet->mCellTable[i + cellCount].mOffsetY = subCellFileSet->mCellTable[i + cellCount].mOffsetY + 1;
        SetLabelPaletteIndex(i, 0xe, subCellFileSet->mLabelLayout, subCellFileSet->mCellTable,
                             subCellFileSet->mCellLayout);
        DrawLayoutTableEntry(i + cellCount, subCellFileSet->mCellLayout, subCellFileSet->mCells,
                             subCellFileSet->mLabelLayout, (void *) gResultsBattle->mUnk_0b8[1],
                             subCellFileSet->mCellTable);
        SetLabelPaletteIndex(i, 0xf, subCellFileSet->mLabelLayout, subCellFileSet->mCellTable,
                             subCellFileSet->mCellLayout);
        subCellFileSet->mCellTable[i + cellCount].mOffsetY = subCellFileSet->mCellTable[i + cellCount].mOffsetY - 1;
    }
    func_02125928();
}

void func_02032ab0(void) {
    data_0217b488->mUnk_04 = 1;
    func_02125da0();
}

#pragma thumb off
