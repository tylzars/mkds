#include "Main/Unknown/code_021189f4.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_0205ee14.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020d0e3c.h"
#include "Main/Unknown/code_02119e14.h"
#include "Main/Unknown/code_0211f394.h"
#include "Main/Unknown/code_021277ac.h"
#include "Main/Unknown/unk_0216d000.h"
#include "Main/Unknown/code_02119a90.h"

#include "00/code_02181f98.h"
#include "Main/Unknown/code_02047104.h"
#include "code_02016468.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_0205f000.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020d0000.h"
#include "Main/Unknown/code_02119544.h"
#include "Main/Unknown/code_021196f4.h"
#include "Main/Unknown/code_0211952c.h"
#include "Main/Unknown/code_021196dc.h"
#include "Main/Unknown/code_02119ac4.h"
#include "Main/Unknown/code_0211de00.h"
#include "Main/Unknown/code_0211df44.h"
#include "Main/Unknown/code_0211e0c4.h"
#include "Main/Unknown/code_0211f000.h"
#include "Main/Unknown/code_0211f2b8.h"
#include "Main/Unknown/code_0211f378.h"
#include "Main/Unknown/code_02119dfc.h"
#include "Main/Unknown/code_02127000.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0201ea58.h"
#include "code_0212df7c.h"
#include "registers.h"

#pragma thumb on
static inline s32 func_02119340_inline(InputSlotIndex inputIndex) {
    BOOL g;
    BOOL f;
    u16 v;

    g = FALSE;
    f = FALSE;
    v = data_02175674[inputIndex].mUnk_00;
    if (v == 0 && data_02175680[inputIndex].mUnk_00 < 5) {
        f = TRUE;
    }
    if (f == FALSE && data_0217567c[inputIndex].mUnk_00 == 0 && v != 0) {
        g = TRUE;
    }
    return g;
}

void AdvanceSelectCupCourseState3(void) {
    s32 touchedRectIndex;
    InputSlotIndex inputIndex;
    s16 courseIndex;

    touchedRectIndex = -1;
    inputIndex = UNK_02175628_INDEX_8;
    AdvanceSelectCupCourseIndexChange();
    if (func_02119340_inline(inputIndex) != 0) {
        touchedRectIndex = RectTableFindContaining(gSelectCupCourse->mSelectCupMBnbl, data_02175670[inputIndex].mUnk_00,
                                                   data_02175672[inputIndex].mUnk_00 + 0x20);
    }
    if ((u16) (data_02175628[inputIndex].mUnk_00 & PAD_KEY_B) != 0 ||
        (func_02119340_inline(inputIndex) != 0 &&
         IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175670[inputIndex].mUnk_00,
                                                         data_02175672[inputIndex].mUnk_00) != FALSE)) {
        if (IsSelectCupCourseIndexChangeRunning() == 0) {
            if (*(vu16 *) 0x027ffc40 == 2) {
                SetSelectReturnSoundId(-1);
            } else {
                SetSelectReturnSoundId(0xe);
            }
            RequestSelectCupCourseState8();
            gSelectCupCourse->mResult = 2;
            RequestSelectReturnState3WithSound(0);
        }
        return;
    }
    if ((u32) touchedRectIndex <= 3) {
        courseIndex = data_0215caac[touchedRectIndex];
        if (gSelectCupCourse->mIndex == courseIndex) {
            gSelectCupCourse->mUnk_54 = FALSE;
        }
        gSelectCupCourse->mIndex = courseIndex;
        RequestSelectCupCourseState4();
        return;
    }
    if (touchedRectIndex == 4) {
        RequestSelectCupCourseState4();
        return;
    }
    if ((u16) (data_02175628[inputIndex].mUnk_00 & PAD_KEY_A) != 0) {
        RequestSelectCupCourseState4();
        gSelectCupCourse->mUnk_54 = FALSE;
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_UP) != 0) {
        gSelectCupCourse->mIndex = gSelectCupCourse->mIndex - 1;
        if (gSelectCupCourse->mIndex < 0) {
            gSelectCupCourse->mIndex = 3;
        }
        if (*(vu16 *) 0x027ffc40 != 2) {
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
        }
        return;
    }
    if (GetNewOrRepeatBits(8, PAD_KEY_DOWN) != 0) {
        gSelectCupCourse->mIndex = gSelectCupCourse->mIndex + 1;
        if (gSelectCupCourse->mIndex >= 4) {
            gSelectCupCourse->mIndex = 0;
        }
        if (*(vu16 *) 0x027ffc40 != 2) {
            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
        }
    }
}

void AdvanceSelectCupCourseState4(void) {
    AdvanceSelectCupCourseIndexChange();
    if (gSelectCupCourse->mStateFrames == 5) {
        gSelectCupCourse->mUnk_54 = TRUE;
    }
    gSelectCupCourse->mStateFrames++;
    if (gSelectCupCourse->mStateFrames >= 10) {
        if (IsSelectCupCourseIndexChangeRunning() == 0) {
            if (gSelectCupCourse->mMode == 0) {
                func_02119e14();
                if (func_0211e130() != FALSE) {
                    func_0211e0c4(0);
                    RequestSelectCupCourseState5();
                    return;
                }
                SetCourseIdFromSelectCupCourse();
                gSelectCupCourse->mResult = 1;
                RequestSelectCupCourseState8();
                return;
            }
            RequestSelectCupCourseState5();
        }
    }
}

void AdvanceSelectCupCourseState5(void) {
    switch (gSelectCupCourse->mMode) {
        case 0:
        case 1:
        case 3:
            if (IsSelectChoisesState1NoState0Request() != 0) {
                RequestSelectCupCourseState6();
            }
            break;
        case 2:
            gSelectCupCourse->mStateFrames++;
            if (gSelectCupCourse->mStateFrames >= 0xf) {
                if (IsSelectChoisesState1NoState0Request() != 0 || GetSelectChoisesDone() != 0) {
                    RequestSelectCupCourseState6();
                }
            }
            break;
    }
}

void AdvanceSelectCupCourseState6(void) {
    s32 choiceIndex;

    if (GetSelectChoisesDone() != 0) {
        RequestSelectCupCourseState7();
        if (*(vu16 *) 0x027ffc40 == 2) {
            choiceIndex = GetSelectChoisesIndex();
            switch (choiceIndex) {
                case 0:
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 7);
                    break;
                case -1:
                case 1:
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x10);
                    break;
            }
        }
    }
}

void AdvanceSelectCupCourseState7(void) {
    s32 choiceIndex;

    switch (gSelectCupCourse->mMode) {
        case 0:
        case 1:
        case 3:
            if (IsSelectChoisesState0NoState1Request() != 0) {
                choiceIndex = GetSelectChoisesIndex();
                switch (choiceIndex) {
                    case 0:
                        SetCourseIdFromSelectCupCourse();
                        gSelectCupCourse->mResult = 1;
                        RequestSelectCupCourseState8();
                        break;
                    case -1:
                    case 1:
                        RequestSelectCupCourseState3();
                        break;
                }
            }
            break;
        case 2:
            gSelectCupCourse->mStateFrames++;
            if (gSelectCupCourse->mStateFrames >= 0xf) {
                if (IsSelectChoisesState0NoState1Request() != 0) {
                    choiceIndex = GetSelectChoisesIndex();
                    switch (choiceIndex) {
                        case 0:
                            SetCourseIdFromSelectCupCourse();
                            gSelectCupCourse->mResult = 1;
                            RequestSelectCupCourseState8();
                            if (*(vu16 *) 0x027ffc40 == 2) {
                                func_0211f378();
                            }
                            break;
                        case -1:
                        case 1:
                            RequestSelectCupCourseState3();
                            break;
                    }
                }
            }
            break;
    }
}

void AdvanceSelectCupCourseState8(void) {
    BOOL a;
    s16 offsetY;
    s32 w;
    s32 i;

    gSelectCupCourse->mStateFrames++;
    if (*(vu16 *) 0x027ffc40 == 2) {
        return;
    }
    if (gSelectCupCourse->mMode == 0) {
        if (gSelectCupCourse->mResult == 1) {
            if (func_0211e130() != FALSE) {
                a = TRUE;
            } else {
                a = FALSE;
            }
        } else {
            a = TRUE;
        }
    } else {
        a = TRUE;
    }
    InterpolateS16(1, 0, 0x100, gSelectCupCourse->mStateFrames, 10);
    offsetY = InterpolateS16(1, 0, -0xc0, gSelectCupCourse->mStateFrames, 10);
    if (a != FALSE) {
        w = gSelectCupCourse->mSelectCupCourseTaOrVsMBncl->mUnk_06;
        gSelectCupCourse->mBg0Offset = offsetY;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[0].mOffsetY = offsetY;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[2].mOffsetY = offsetY;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[1].mOffsetY = offsetY;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[4].mOffsetY = offsetY;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[3].mOffsetY = offsetY;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[5].mOffsetY = offsetY;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[w].mOffsetY = offsetY;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[w + 1].mOffsetY = offsetY;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[w + 2].mOffsetY = offsetY;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[w + 3].mOffsetY = offsetY;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[w + 4].mOffsetY = offsetY;
        gSelectCupCourse->mSelectCupCourseTaOrVsMTable[w + 5].mOffsetY = offsetY;
    }
    if (gSelectCupCourse->mResult != 2) {
        w = gSelectCupCourse->mSelectCupMBncl->mUnk_06;
        gSelectCupCourse->mBg3Offset = offsetY - 0x20;
        gSelectCupCourse->mSelectCupMTable[0x14].mOffsetY = offsetY - 0x20;
        gSelectCupCourse->mSelectCupMTable[0x13].mOffsetY = offsetY - 0x20;
        gSelectCupCourse->mSelectCupMTable[2].mOffsetY = offsetY - 0x20;
        gSelectCupCourse->mSelectCupMTable[1].mOffsetY = offsetY - 0x20;
        gSelectCupCourse->mSelectCupMTable[0].mOffsetY = offsetY - 0x20;
        for (i = 0; i < 8; i++) {
            gSelectCupCourse->mSelectCupMTable[data_0215cacc[i]].mOffsetY = offsetY - 0x20;
        }
        offsetY -= 0x20;
        for (i = 0; i < 4; i++) {
            gSelectCupCourse->mSelectCupMTable[data_0215caa4[i]].mOffsetY = offsetY;
            gSelectCupCourse->mSelectCupMTable[w + data_0215cab4[i]].mOffsetY = offsetY;
        }
    }
}

s32 AdvanceSelectCupCourse(void) {
    s32 i;
    u16 *screenMap;

    gSelectCupCourse->mState = gSelectCupCourse->mNextState;
    switch (gSelectCupCourse->mState) {
        case 0:
            AdvanceSelectCupCourseState0();
            break;
        case 1:
            AdvanceSelectCupCourseState1();
            break;
        case 2:
            AdvanceSelectCupCourseState2();
            break;
        case 3:
            AdvanceSelectCupCourseState3();
            break;
        case 4:
            AdvanceSelectCupCourseState4();
            break;
        case 5:
            AdvanceSelectCupCourseState5();
            break;
        case 6:
            AdvanceSelectCupCourseState6();
            break;
        case 7:
            AdvanceSelectCupCourseState7();
            break;
        case 8:
            AdvanceSelectCupCourseState8();
            break;
    }
    AdvanceSelectCupCourseHighlight();
    if (*(vu16 *) 0x027ffc40 != 2) {
        if (gSelectCupCourse->mCupPicturePending != FALSE && func_020d0ec4() != FALSE) {
            screenMap = GetCupPictureNscrData();
            CallQueueAppend(0x1f, 0, GetCupPictureNclrData(), 0xe0);
            CallQueueAppend(0x17, 0x20, GetCupPictureNcgrData(), 0xdc0);
            for (i = 0; i < 11; i++) {
                CallQueueAppend(0x1b, ((i + 8) * 0x20 + 0x16) * 2, screenMap + ((i + 8) * 0x20 + 0x16), 0x14);
            }
            gSelectCupCourse->mCupPicturePending = FALSE;
        }
        DrawLayoutTable(gSelectCupCourse->mSelectCupCourseTaOrVsMBncl, gSelectCupCourse->mSelectCupCourseMNcer,
                        gSelectCupCourse->mSelectCupCourseTaOrVsMBnll, gSelectCupCourse->mMainOam,
                        gSelectCupCourse->mSelectCupCourseTaOrVsMTable);
        DrawLayoutTable(gSelectCupCourse->mSelectCupMBncl, gSelectCupCourse->mSelectCupMNcer,
                        gSelectCupCourse->mSelectCupMBnll, gSelectCupCourse->mSubOam,
                        gSelectCupCourse->mSelectCupMTable);
    } else {
        AdvanceSelectRaceRuleWait();
    }
    if (gSelectCupCourse->mState == 8 && gSelectCupCourse->mStateFrames >= 10) {
        return gSelectCupCourse->mResult;
    }
    return 0;
}

void WriteSelectCupCourseBgOffsets(void) {
    reg_G2_BG0OFS = (-gSelectCupCourse->mBg0Offset << 16) & 0x1ff0000;
    reg_G2S_DB_BG3OFS = (-gSelectCupCourse->mBg3Offset << 16) & 0x1ff0000;
}

void LoadSelectCupGridData(void) {
    Ncgr *selectCupMChars = NULL;
    Unk02021dc8 *selectCupMCells = NULL;
    Nclr *selectCupMOPalette = NULL;
    Ncgr *selectCupSChars = NULL;
    Unk02021dc8 *selectCupSCells = NULL;
    Nclr *selectCupSOPalette = NULL;
    Ncgr *selectCupMBChars = NULL;
    Nscr *selectCupMScreenMap = NULL;
    Nclr *selectCupMBPalette = NULL;

    if (*(vu16 *) 0x027ffc40 != 2) {
        LoadNcgrData(&selectCupMBChars, FindSceneFile(data_0216d690));
        LoadNclrData(&selectCupMBPalette, FindSceneFile(data_0216d6b8));
        LoadNscrData(&selectCupMScreenMap, FindSceneFile(data_0216d6bc));
        LoadNcgrData2(&selectCupMChars, FindSceneFile(data_0216d6ac));
        LoadNcerData(&selectCupMCells, FindSceneFile(data_0216d694));
        LoadNclrData(&selectCupMOPalette, FindSceneFile(data_0216d6a0));
        LoadNcgrData2(&selectCupSChars, FindSceneFile(data_0216d69c));
        LoadNcerData(&selectCupSCells, FindSceneFile(data_0216d6b4));
        LoadNclrData(&selectCupSOPalette, FindSceneFile(data_0216d68c));
        LoadSelectCupNameMData();
        LoadCommonCupMarkData();
        LoadTrophyIconData();
    }
}

void func_02118b48(void) {
    Ncgr *selectCupMChars = NULL;
    Nclr *selectCupMOPalette = NULL;
    Ncgr *selectCupSChars = NULL;
    Nclr *selectCupSOPalette = NULL;
    Ncgr *selectCupMBChars = NULL;
    Nscr *selectCupMScreenMap = NULL;
    Nclr *selectCupMBPalette = NULL;
    u16 *paletteData;

    if (*(vu16 *) 0x027ffc40 == 2) {
        gSelectCupGrid->mSelectCupSBnbl = FindSceneFile(data_0216d6a4);
        return;
    }
    LocateNcgr(&selectCupMBChars, FindSceneFile(data_0216d690));
    LocateNclr(&selectCupMBPalette, FindSceneFile(data_0216d6b8));
    LocateNscr(&selectCupMScreenMap, FindSceneFile(data_0216d6bc));
    gSelectCupGrid->mUnk_20 = HeapAlloc(gSelectCupGrid->mHeap, 0x800);
    gSelectCupGrid->mSelectCupMBncl = FindSceneFile(data_0216d698);
    gSelectCupGrid->mSelectCupMBnll = FindSceneFile(data_0216d6a8);
    LocateNcgr2(&selectCupMChars, FindSceneFile(data_0216d6ac));
    LocateNcer(&gSelectCupGrid->mSelectCupMNcer, FindSceneFile(data_0216d694));
    LocateNclr(&selectCupMOPalette, FindSceneFile(data_0216d6a0));
    gSelectCupGrid->mSelectCupSBncl = FindSceneFile(data_0216d6b0);
    gSelectCupGrid->mSelectCupSBnbl = FindSceneFile(data_0216d6a4);
    LocateNcgr2(&selectCupSChars, FindSceneFile(data_0216d69c));
    LocateNcer(&gSelectCupGrid->mSelectCupSNcer, FindSceneFile(data_0216d6b4));
    LocateNclr(&selectCupSOPalette, FindSceneFile(data_0216d68c));
    paletteData = selectCupMOPalette->mData;
    if (GetPreviousMenuScreenNumber() != 0x18 && GetPreviousMenuScreenNumber() != 0xc) {
        CallQueueAppend(4, 0, selectCupMBChars->mData, selectCupMBChars->mDataSize);
        CallQueueAppend(0xf, 0, selectCupMBPalette->mData, 0x100);
        CallQueueAppend(8, 0, &selectCupMScreenMap->mData, selectCupMScreenMap->mDataSize);
        CallQueueAppend(8, 0x800, gSelectCupGrid->mUnk_20, 0x800);
    }
    CallQueueAppend(0x13, 0, selectCupMChars->mData, selectCupMChars->mDataSize);
    CallQueueAppend(0xe, 0, selectCupMOPalette->mData, 0x1a0);
    CallQueueAppend(0xe, 0x1c0, paletteData + 0xe0, 0x40);
    CallQueueAppend(0x23, 0, selectCupSChars->mData, selectCupSChars->mDataSize);
    CallQueueAppend(0x1e, 0, selectCupSOPalette->mData, selectCupSOPalette->mDataSize);
}

u32 GetSelectCupGridCupEnabled(u32 cupIndex) {
    u32 enabled;
    s32 i;

    enabled = 0;
    switch (gSelectCupGrid->mMode) {
        case 0:
        case 2:
            switch (cupIndex) {
                case 0:
                case 1:
                case 4:
                case 5:
                    enabled = 1;
                    break;
                default:
                    if (GetMirrorMode() != 0) {
                        enabled = IsBackupFlagSet(data_0215c8bc[cupIndex]);
                    } else {
                        enabled = IsBackupFlagSet(data_0215c95c[cupIndex][data_0215c7f0[GetEngineIndex()]]);
                    }
                    break;
            }
            break;
        case 1:
            switch (cupIndex) {
                case 0:
                case 1:
                case 4:
                case 5:
                    enabled = 1;
                    break;
                default:
                    enabled = 0;
                    for (i = 0; i < 4; i++) {
                        if (i == 3) {
                            enabled |= IsBackupFlagSet(data_0215c8bc[cupIndex]);
                        } else {
                            enabled |= IsBackupFlagSet(data_0215c95c[cupIndex][i]);
                        }
                    }
                    break;
            }
            break;
        case 3:
            if (cupIndex == 0 || cupIndex == 4) {
                enabled = 1;
            }
            break;
        case 4:
            switch (cupIndex) {
                case 0:
                case 1:
                case 4:
                case 5:
                    enabled = 1;
                    break;
                default:
                    if (GetMirrorMode() != 0) {
                        enabled = func_0205fbb8(data_0215c8bc[cupIndex]);
                    } else {
                        enabled = func_0205fbb8(data_0215c95c[cupIndex][data_0215c7f0[GetEngineIndex()]]);
                    }
                    break;
            }
            break;
    }
    return enabled;
}
#pragma thumb off
