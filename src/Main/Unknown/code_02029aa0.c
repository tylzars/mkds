#include "Main/Unknown/code_02029aa0.h"
#include "01/code_021804e0.h"
#include "Main/Unknown/code_02025b84.h"
#include "Main/Unknown/code_02025d5c.h"
#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_0202a340.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02062000.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_020a23a0.h"
#include "Main/Unknown/code_0210f71c.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02125960.h"
#include "Main/Unknown/code_02125de0.h"
#include "Main/Unknown/code_02125ebc.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_021258f0.h"
#include "code_02148950.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217d068.h"
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
#include "00/code_02181f98.h"
#include "01/code_021956dc.h"
#include "code_02016468.h"
#include "code_0212df7c.h"
#include "code_0214a390.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"
#include "code_021458c4.h"
#include "Main/Unknown/code_02045874.h"
#include "Main/Unknown/code_02090354.h"

#pragma thumb on

// Sets up the Grand Prix results screen: loads its files and lays out the cup, course and time texts.
void InitResultsGp(void *heap, void *firstOamList, void *secondOamList) {
    s16 timeText[10];
    Unk02125de0Arg config;
    ScreenMapFileSet mainScreenMapFileSet;
    u16 playerName[11];
    CellFileSet cellFileSet;
    ScreenMapFileSet subScreenMapFileSet;
    CellFileSet cupNameFileSet;
    CellFileSet *mainFileSet;
    CellFileSet *subFileSet;
    Unk02180774 *displaySettings;
    u32 mainObjSize;
    u32 subObjSizeLeft;
    u32 characterIndex;
    u32 labelTableIndex;
    u32 cellFlag;
    s32 i;
    void *message;
    s32 courseIndex;
    s32 j;
    Unk02153918 *tableEntry;

    labelTableIndex = 0;
    gResultsGp = HeapAlloc(heap, 0x60);
    MemFillWordsByBlock_inline(gResultsGp, 0x60);
    gResultsGp->mOamLists[0] = firstOamList;
    gResultsGp->mOamLists[1] = secondOamList;
    gResultsGp->mCommonMessages = FindFileInLoadedArchives(data_usa_02162138);
    gResultsGp->mSecretMessages = FindSceneFile(gSecretBmgName);
    gResultsGp->mCupIndex = data_0217b488->mCupIndex;
    gResultsGp->mCupRankIndex = data_0217b488->mCupRankIndex;
    if (gResultsGp->mCupRankIndex < 0) {
        gResultsGp->mCupRankIndex = 0;
    }
    gResultsGp->mUnk_44 = data_0217b488->mUnk_80;
    Init3dEngine();
    displaySettings = CreateDisplaySettings(heap, data_021547f0);
    SetBg1Record(&displaySettings->mMainBgRecords, 2, 0, 0, 0, 0x10, 6, 0);
    SetBg3RecordParams(&displaySettings->mMainBgRecords, 3, 0, 0, 0, 2, 6);
    SetBg3RecordParams(&displaySettings->mSubBgRecords, 3, 0, 0, 0, 1, 6);
    InitDisplayFromSettings(displaySettings);
    config.mUnk_00 = 1;
    config.mUnk_04 = func_020b403c(1);
    config.mUnk_08 = 0;
    config.mUnk_0c = 1;
    config.mUnk_10 = 0;
    config.mUnk_14 = 0;
    config.mUnk_18 = NULL;
    config.mUnk_1c = 0;
    config.mUnk_20 = 0;
    config.mUnk_24 = 0;
    LoadTxtSystemAndSelectChoisesAndSelectReturnData();
    func_02125de0(heap, &config);
    func_02025854(0, &mainScreenMapFileSet, gResultsGpMBNcgrName, gResultsGpMBNclrName, gResultsGpM1NscrName, 1,
                  FindSceneFile);
    LoadNscrData(&mainScreenMapFileSet.mScreenMaps[3], FindSceneFile(gResultsGpM2NscrName));
    CallQueueAppend(0xb, 0, &mainScreenMapFileSet.mScreenMaps[3]->mData,
                    mainScreenMapFileSet.mScreenMaps[3]->mDataSize);
    mainObjSize = GX_GetSizeOfOBJ();
    mainFileSet = &gResultsGp->mCellFileSets[0];
    LoadCellFileSet(mainFileSet, gResultsGpMNcgrName, gResultsGpMNcerName, gResultsGpMONclrName, gResultsGpMBnclName,
                    gResultsGpMBnllName, NULL, FindSceneFile);
    func_02025a50(0, heap, mainFileSet);
    MIi_CpuCopy16(&data_0217aa08->mUnk_00->mUnk_0c, playerName, 0x14);
    playerName[10] = 0;
    func_021243ac(heap, 0, mainFileSet->mLabelLayout, 0x82, 0xd, 0x14, mainFileSet->mCells, mainFileSet->mCellLayout,
                  mainFileSet->mCellTable, mainObjSize);
    func_0212426c(0, 0, mainFileSet->mLabelLayout, playerName, mainFileSet->mCellLayout, mainFileSet->mCellTable);
    func_02124094(0, 1, mainFileSet->mLabelLayout, mainFileSet->mCellTable, mainFileSet->mCellLayout);
    for (i = 0; i < 8; i++) {
        if (i == gResultsGp->mCupRankIndex) {
            cellFlag = 1;
        } else {
            cellFlag = 0;
        }
        mainFileSet->mCellTable[gCupRankCellIndexTable[i]].mVisible = cellFlag;
    }
    for (i = 0; i < 8; i++) {
        if (i == gResultsGp->mUnk_44) {
            cellFlag = 1;
        } else {
            cellFlag = 0;
        }
        mainFileSet->mCellTable[data_usa_02153888[i]].mVisible = cellFlag;
    }
    if (gResultsGp->mCupRankIndex >= 3) {
        cellFlag = 1;
    } else {
        cellFlag = 0;
    }
    mainFileSet->mCellTable[3].mVisible = cellFlag;
    mainFileSet->mCellTable[2].mVisible = mainFileSet->mCellTable[3].mVisible;
    mainFileSet->mCellTable[1].mVisible = (mainFileSet->mCellTable[2].mVisible == 0) ? 1 : 0;
    mainFileSet->mCellTable[0].mVisible = mainFileSet->mCellTable[1].mVisible;
    characterIndex = data_0217b488->mCharacterIndex;
    mainFileSet = &gResultsGp->mCellFileSets[0];
    func_02025b84(1, &cellFileSet);
    func_0212463c(characterIndex, cellFileSet.mCells, cellFileSet.mChars, cellFileSet.mPalette, cellFileSet.mCellLayout,
                  0, 0x14, mainFileSet->mCells, mainFileSet->mCellLayout);
    func_02025854(1, &subScreenMapFileSet, gResultsGpSBNcgrName, gResultsGpSBNclrName, gResultsGpSNscrName, 3,
                  FindSceneFile);
    subObjSizeLeft = GX_GetSizeOfSubOBJ();
    subFileSet = &gResultsGp->mCellFileSets[1];
    LoadCellFileSet(subFileSet, gResultsGpSNcgrName, gResultsGpSNcerName, gResultsGpSONclrName, gResultsGpSBnclName,
                    gResultsGpSBnllName, NULL, FindSceneFile);
    func_02025a50(1, heap, subFileSet);
    j = 0;
    tableEntry = data_usa_02153918;
    for (; j < 16; j++) {
        subObjSizeLeft -= func_02025a00(1, heap, subFileSet, tableEntry, subObjSizeLeft);
        tableEntry++;
    }
    message = GetBmgEntry(gResultsGp->mCommonMessages, gEngineMessageIndexTable[data_0217b488->mEngineIndex]);
    for (j = 0; j < 2; j++) {
        func_0212426c(1, data_usa_02153918[labelTableIndex].mUnk_00, subFileSet->mLabelLayout, message,
                      subFileSet->mCellLayout, subFileSet->mCellTable);
        labelTableIndex++;
    }
    if (data_0217b488->mMirrorMode != 0) {
        message = GetBmgEntry(gResultsGp->mCommonMessages, 0x71);
        for (j = 0; j < 2; j++) {
            func_0212426c(1, data_usa_02153918[labelTableIndex].mUnk_00, subFileSet->mLabelLayout, message,
                          subFileSet->mCellLayout, subFileSet->mCellTable);
            labelTableIndex++;
        }
    } else {
        labelTableIndex += 2;
    }
    for (courseIndex = 0; courseIndex < 4; courseIndex++) {
        message = GetBmgEntry(gResultsGp->mCommonMessages,
                              GetCourseMessageIndex(data_usa_02153898[gResultsGp->mCupIndex][courseIndex]));
        func_0212426c(1, data_usa_02153918[labelTableIndex].mUnk_00, subFileSet->mLabelLayout, message,
                      subFileSet->mCellLayout, subFileSet->mCellTable);
        labelTableIndex++;
    }
    for (j = 0; j < 4; j++) {
        func_0202a340(timeText, j);
        func_02124224(1, data_usa_02153918[labelTableIndex].mUnk_00, subFileSet->mLabelLayout, timeText,
                      subFileSet->mCellLayout, subFileSet->mCellTable, 7);
        func_02124224(1, data_usa_02153918[labelTableIndex + 4].mUnk_00, subFileSet->mLabelLayout, timeText,
                      subFileSet->mCellLayout, subFileSet->mCellTable, 7);
        labelTableIndex++;
    }
    subFileSet = &gResultsGp->mCellFileSets[1];
    LoadCellFileSet(&cupNameFileSet, gCupNameLeftNcgrName, gCupNameLeftNcerName, NULL, gCupNameLeftBnclName, NULL, NULL,
                    FindSceneFile);
    func_02124748(data_usa_02153868[gResultsGp->mCupIndex], cupNameFileSet.mCells, cupNameFileSet.mChars,
                  cupNameFileSet.mCellLayout, 1, 0, subFileSet->mCells, subFileSet->mCellLayout);
    func_020629a4();
    func_020a269c(gResultsGp->mCupIndex, (u16) gResultsGp->mCupRankIndex);
    i = -1;
    switch (gResultsGp->mUnk_44) {
        case 5:
            i = 0x1e;
            break;
        case 6:
            i = 0x1f;
            break;
        case 7:
            i = 0x20;
            break;
    }
    if (i >= 0) {
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, (u16) i);
    }
    if (TrySetGrandPrixRecord()) {
        func_02057d9c();
        if (data_021759d4->mBackupEnabled != 0) {
            CARD_WaitBackupAsync();
        }
        gResultsGp->mSecretMessageMask = func_020911a8();
    }
}

// Draws the Grand Prix results; after a delay and a button press or touch, shows each pending secret message, then
// picks the next scene.
void AdvanceResultsGp(Unk02029aa0 *sceneNumbers) {
    u32 inputSlotIndex;
    void *secretMessage;
    s32 i;
    inputSlotIndex = func_020435bc();
    secretMessage = NULL;
    for (i = 0; i < 2; i++) {
        DrawLayoutTable(gResultsGp->mCellFileSets[i].mCellLayout, gResultsGp->mCellFileSets[i].mCells,
                        gResultsGp->mCellFileSets[i].mLabelLayout, gResultsGp->mOamLists[i],
                        gResultsGp->mCellFileSets[i].mCellTable);
    }
    if (gResultsGp->mCupRankIndex < 3) {
        func_020a2558();
        func_020a23cc();
    }
    switch (gResultsGp->mState) {
        case 0: {
            s32 frameLimit;
            s32 frames;
            frameLimit = func_0210f71c(gResultsGp->mCupRankIndex);
            frames = gResultsGp->mState0Frames;
            gResultsGp->mState0Frames = frames + 1;
            if (frames >= frameLimit) {
                void *commonMessage;
                u32 messageMask;
                if (!(u16) (data_02175628[inputSlotIndex].mUnk_00 & PAD_KEY_A)) {
                    BOOL y;
                    BOOL x;
                    u16 z;
                    y = FALSE;
                    x = FALSE;
                    z = data_02175674[inputSlotIndex].mUnk_00;
                    if (z == 0) {
                        if (data_02175680[inputSlotIndex].mUnk_00 < 5) {
                            x = TRUE;
                        }
                    }
                    if (x == FALSE) {
                        if (data_0217567c[inputSlotIndex].mUnk_00 == 0) {
                            if (z != 0) {
                                y = TRUE;
                            }
                        }
                    }
                    if (y == FALSE) {
                        break;
                    }
                }
                commonMessage = GetBmgEntry(gResultsGp->mCommonMessages, 4);
                messageMask = gResultsGp->mSecretMessageMask;
                if (messageMask != 0) {
                    if (messageMask & 0x1) {
                        secretMessage = GetBmgEntry(gResultsGp->mSecretMessages, 0);
                        gResultsGp->mSecretMessageMask &= ~0x1;
                    } else if (messageMask & 0x2) {
                        secretMessage = GetBmgEntry(gResultsGp->mSecretMessages, 1);
                        gResultsGp->mSecretMessageMask &= ~0x2;
                    } else if (messageMask & 0x4) {
                        secretMessage = GetBmgEntry(gResultsGp->mSecretMessages, 2);
                        gResultsGp->mSecretMessageMask &= ~0x4;
                    } else if (messageMask & 0x8) {
                        secretMessage = GetBmgEntry(gResultsGp->mSecretMessages, 3);
                        gResultsGp->mSecretMessageMask &= ~0x8;
                    } else if (messageMask & 0x10) {
                        secretMessage = GetBmgEntry(gResultsGp->mSecretMessages, 4);
                        gResultsGp->mSecretMessageMask &= ~0x10;
                    } else if (messageMask & 0x20) {
                        secretMessage = GetBmgEntry(gResultsGp->mSecretMessages, 5);
                        gResultsGp->mSecretMessageMask &= ~0x20;
                    } else if (messageMask & 0x40) {
                        secretMessage = GetBmgEntry(gResultsGp->mSecretMessages, 6);
                        gResultsGp->mSecretMessageMask &= ~0x40;
                    } else if (messageMask & 0x80) {
                        secretMessage = GetBmgEntry(gResultsGp->mSecretMessages, 7);
                        gResultsGp->mSecretMessageMask &= ~0x80;
                    } else if (messageMask & 0x100) {
                        secretMessage = GetBmgEntry(gResultsGp->mSecretMessages, 8);
                        gResultsGp->mSecretMessageMask &= ~0x100;
                    } else if (messageMask & 0x200) {
                        secretMessage = GetBmgEntry(gResultsGp->mSecretMessages, 9);
                        gResultsGp->mSecretMessageMask &= ~0x200;
                    } else if (messageMask & 0x400) {
                        secretMessage = GetBmgEntry(gResultsGp->mSecretMessages, 10);
                        gResultsGp->mSecretMessageMask &= ~0x400;
                    } else if (messageMask & 0x800) {
                        secretMessage = GetBmgEntry(gResultsGp->mSecretMessages, 11);
                        gResultsGp->mSecretMessageMask &= ~0x800;
                    }
                    SetTxtSystemOpenSoundId(0x53);
                    SetupTxtSystemSubTextButtonEx(secretMessage, commonMessage, 0, 1, 1, 0);
                    gResultsGp->mState = 1;
                } else {
                    switch (func_020909cc()) {
                        case 0:
                            if (sceneNumbers != NULL) {
                                sceneNumbers->mNextScene = 0;
                            }
                            break;
                        case 1:
                            func_02045a2c(0);
                            if (sceneNumbers != NULL) {
                                sceneNumbers->mNextScene = 2;
                            }
                            break;
                        case 2:
                            func_02045a2c(1);
                            if (sceneNumbers != NULL) {
                                sceneNumbers->mNextScene = 2;
                            }
                            break;
                    }
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 5);
                    gResultsGp->mState = 2;
                }
            }
        } break;
        case 1:
            if (GetTxtSystemDone()) {
                RequestTxtSystemClose();
                gResultsGp->mState = 0;
            }
            break;
    }
    func_02125928();
}

#pragma thumb off
