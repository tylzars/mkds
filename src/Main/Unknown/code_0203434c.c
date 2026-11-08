#include "Main/Unknown/code_0203434c.h"
#include "Main/Unknown/code_0202d990.h"
#include "Main/Unknown/code_02034bf4.h"
#include "Main/Unknown/code_020351c8.h"
#include "Main/Unknown/code_02036000.h"

#include "00/code_02181f98.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025d5c.h"
#include "Main/Unknown/code_0202d000.h"
#include "Main/Unknown/code_0202dd9c.h"
#include "Main/Unknown/code_02034000.h"
#include "Main/Unknown/code_02035000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_0204e000.h"
#include "Main/Unknown/code_0204ece0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_0204ed04.h"
#include "Main/Unknown/code_0204f5e4.h"
#include "Main/Unknown/code_0204f7f4.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_02054f58.h"
#include "Main/Unknown/code_020566a8.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020b3f7c.h"
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
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02124f4c.h"
#include "Main/Unknown/code_02125ed0.h"
#include "Main/Unknown/code_02125f2c.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02126230.h"
#include "Main/Unknown/code_021262f0.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0201ea58.h"
#include "code_0212d214.h"
#include "code_0212df7c.h"
#include "code_0214d018.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_02025edc.h"

#pragma thumb on

static inline s32 func_02034370_inline(void) {
    Unk021759d4 *p = data_021759d4;
    if (p->mBackupEnabled != 0) {
        return p->mCommandRunning;
    }
    return 0;
}

static inline s32 func_02034370_inline_2(void) {
    if (data_0217aa08->mUnk_28 == 0) {
        return func_02034370_inline();
    }
    return 1;
}

s32 func_02034370(Unk02034370 *sceneNumbers) {
    CellFileSet *subCellFileSet;
    CellFileSet *cellFileSet;
    s32 previousSelectedIndex;
    u16 slotIndex;
    s32 result;
    s32 touchInReturnRect;
    s32 rectIndex;
    s32 i;
    s32 j;
    s32 courseMessageIndex;
    BOOL pairIsNew;
    BOOL pairRecentlyGone;
    u16 hasPair;
    s32 pairX;
    s32 pairY;
    void *message;
    void *buttonText;
    void *secondButtonText;
    u8 idBytes[3];
    GhostRecordInfo ghostRecordInfo;
    u16 formattedText[0x100];

    previousSelectedIndex = data_02174e64->mSelectedIndex;
    slotIndex = func_020435bc();
    touchInReturnRect = 0;
    result = -1;
    rectIndex = -1;
    subCellFileSet = &data_02174e64->mCellFileSets[1];
    AdvanceInterpolation(&data_02174e64->mUnk_194);
    switch (data_02174e64->mState) {
        case 0:
            if (AreBrightnessFadesClear() == 0) {
                RequestSelectReturnState1();
                func_02035378();
                func_02025f14(&data_02174e64->mUnk_194, 0);
                data_02174e64->mState = 1;
            }
            break;
        case 1:
            if (data_02174e64->mUnk_194.mState == 1) {
                data_02174e64->mState = 2;
            } else {
                func_02034fec();
            }
            break;
        case 2:
            switch (AdvanceConnectionSetup(0, NULL)) {
                case 1:
                    SetupTxtSystemSubText(GetBmgEntry(data_02174e64->mGhostMessages, 0xf));
                    NNS_SndArcSetCurrent(&data_0217c868);
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 9);
                    NNS_SndArcSetCurrent(&data_0217d0a0);
                    data_02174e64->mState = 5;
                    break;
                case 0:
                    if (data_02174e64->mUnk_18c != FALSE) {
                        break;
                    }
                    if (IsTxtSystemState0NoOpenRequest() != 0) {
                        func_02035378();
                    }
                    data_02174e64->mFilledCount = 0;
                    for (i = 0; i < 4; i++) {
                        j = i + 4;
                        if (func_0204ebb8(i, &ghostRecordInfo, &idBytes[0], &idBytes[1], &idBytes[2],
                                          &ghostRecordInfo.mMinute, &ghostRecordInfo.mSecond,
                                          &ghostRecordInfo.mMillisecond)) {
                            ghostRecordInfo.mUnk_18[1] = idBytes[0];
                            ghostRecordInfo.mUnk_18[0] = idBytes[1];
                            ghostRecordInfo.mUnk_18[2] = idBytes[2];
                            data_02174e64->mFilledCount++;
                            if (data_02174e64->mGhostInfoEntries[i].mFilled == FALSE ||
                                AreGhostRecordInfosDifferent(&data_02174e64->mGhostInfoEntries[i].mInfo,
                                                             &ghostRecordInfo) != FALSE) {
                                courseMessageIndex = func_02025d74(ghostRecordInfo.mUnk_18[2]);
                                ghostRecordInfo.mName[10] = 0;
                                func_0212426c(1, data_02164254[i][0], subCellFileSet->mLabelLayout, &ghostRecordInfo,
                                              subCellFileSet->mCellLayout, subCellFileSet->mCellTable);
                                func_0212426c(1, data_02164254[j][0], subCellFileSet->mLabelLayout,
                                              GetBmgEntry(data_02174e64->mGhostMessages, courseMessageIndex),
                                              subCellFileSet->mCellLayout, subCellFileSet->mCellTable);
                                MIi_CpuCopyFast(&ghostRecordInfo, &data_02174e64->mGhostInfoEntries[i].mInfo, 0x28);
                                data_02174e64->mGhostInfoEntries[i].mFilled = TRUE;
                                func_02025f14(&data_02174e64->mGhostInfoEntries[i].mInterpolation, 0);
                                if (data_02174e64->mSelectedIndex == i) {
                                    func_02034f60();
                                }
                                NNS_SndArcSetCurrent(&data_0217c868);
                                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 7);
                                NNS_SndArcSetCurrent(&data_0217d0a0);
                            }
                        } else {
                            func_02025f14(&data_02174e64->mGhostInfoEntries[i].mInterpolation, 2);
                            data_02174e64->mGhostInfoEntries[i].mFilled = FALSE;
                        }
                    }
                    func_02035114();
                    pairIsNew = FALSE;
                    pairRecentlyGone = FALSE;
                    hasPair = data_02175674[slotIndex].mUnk_00;
                    if (hasPair == 0 && data_02175680[slotIndex].mUnk_00 < 5) {
                        pairRecentlyGone = TRUE;
                    }
                    if (pairRecentlyGone == FALSE && data_0217567c[slotIndex].mUnk_00 == 0 && hasPair != 0) {
                        pairIsNew = TRUE;
                    }
                    if (pairIsNew != FALSE) {
                        pairX = data_02175670[slotIndex].mUnk_00;
                        pairY = data_02175672[slotIndex].mUnk_00;
                        touchInReturnRect = IsSelectReturnState2NoState3Or4RequestAndInRect(pairX, pairY);
                        rectIndex = RectTableFindContaining(subCellFileSet->mRects, pairX, pairY);
                    }
                    if (rectIndex >= 0 && data_02174e64->mGhostInfoEntries[rectIndex].mFilled != FALSE) {
                        SetupGhostSubTextTwoButtons();
                        func_02035228(data_02174e64->mSelectedIndex != rectIndex ? 1 : 0);
                        data_02174e64->mSelectedIndex = rectIndex;
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 5);
                        RequestSelectReturnState4();
                        data_02174e64->mUnk_18c = TRUE;
                        data_02174e64->mStateFrames = 0;
                        data_02174e64->mState = 3;
                    } else if ((u16) (data_02175628[slotIndex].mUnk_00 & PAD_KEY_A) != 0 &&
                               data_02174e64->mSelectedIndex >= 0) {
                        SetupGhostSubTextTwoButtons();
                        func_02035228(0);
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 5);
                        RequestSelectReturnState4();
                        data_02174e64->mUnk_18c = TRUE;
                        data_02174e64->mStateFrames = 0;
                        data_02174e64->mState = 3;
                    } else if ((u16) (data_02175628[slotIndex].mUnk_00 & PAD_KEY_B) != 0 || touchInReturnRect != 0) {
                        data_02174e64->mState = 12;
                        RequestSelectReturnState3WithSound(0);
                    } else if (GetNewOrRepeatBits(slotIndex, PAD_KEY_UP)) {
                        if (data_02174e64->mFilledCount == 2) {
                            MoveSelectedGhostUp(0);
                        } else if (data_02174e64->mFilledCount > 2) {
                            MoveSelectedGhostUp(1);
                        }
                    } else if (GetNewOrRepeatBits(slotIndex, PAD_KEY_DOWN)) {
                        if (data_02174e64->mFilledCount == 2) {
                            MoveSelectedGhostDown(0);
                        } else if (data_02174e64->mFilledCount > 2) {
                            MoveSelectedGhostDown(1);
                        }
                    }
                    break;
                case 2:
                    break;
            }
            if (previousSelectedIndex != data_02174e64->mSelectedIndex) {
                func_02034f60();
                func_02034ef0();
            }
            break;
        case 3:
            data_02174e64->mStateFrames++;
            if (data_02174e64->mStateFrames > 5) {
                func_02035228(1);
                data_02174e64->mStateFrames = 0;
                data_02174e64->mState = 4;
            }
            break;
        case 4:
            if (GetTxtSystemDone() != 0) {
                if (GetTxtSystemSelectedIndex() == 0) {
                    func_0204ece0(data_02174e64->mSelectedIndex);
                } else {
                    RequestSelectReturnState1();
                    data_02174e64->mUnk_18c = FALSE;
                }
                RequestTxtSystemClose();
                data_02174e64->mState = 2;
            }
            break;
        case 5:
            switch (AdvanceBlockCountRequest()) {
                case 1:
                    ResetPendingFiles();
                    func_0204ee4c(0, GetSlotGhostBuffer());
                    data_02174e64->mState = 6;
                    break;
                case 2:
                    func_020353a4();
                    break;
            }
            break;
        case 6:
            switch (AdvanceBlockReceive()) {
                case 1:
                    data_02174e64->mState = 7;
                    break;
                case 2:
                    func_020353a4();
                    break;
            }
            break;
        case 7:
            if (func_02054f58() == 1) {
                func_0204f804();
                data_02174e64->mState = 8;
            }
            break;
        case 12:
            if (func_02054f58() == 1) {
                func_0204f804();
                data_0217b488->mUnk_08 = 5;
                if (sceneNumbers != NULL) {
                    sceneNumbers->mUnk_04 = 1;
                }
                data_02174e64->mState = 16;
            }
            break;
        case 8:
            if (DoesAnySlotGhostMatchCourse(
                    data_02174e64->mGhostInfoEntries[data_02174e64->mSelectedIndex].mInfo.mUnk_18[2]) != 0) {
                courseMessageIndex =
                    func_02025d74(data_02174e64->mGhostInfoEntries[data_02174e64->mSelectedIndex].mInfo.mUnk_18[2]);
                message = GetBmgEntry(data_02174e64->mGhostMessages, 0x55);
                buttonText = GetBmgEntry(data_02174e64->mCommonMessages, 0);
                secondButtonText = GetBmgEntry(data_02174e64->mCommonMessages, 1);
                FormatMessageWithText(GetBmgEntry(data_02174e64->mGhostMessages, courseMessageIndex), message,
                                      formattedText, 0x100);
                SetTxtSystemSoundId(0, -1);
                SetupTxtSystemSubTextTwoButtonsEx(formattedText, buttonText, secondButtonText, 1, 0, 1, 1, 0);
                data_02174e64->mState = 9;
            } else if (GetSlotGhostCount() == 10) {
                RequestTxtSystemClose();
                data_02174e64->mNextCallbacksIndex = 2;
                data_02174e64->mState = 13;
                func_02025f14(&data_02174e64->mUnk_194, 2);
            } else {
                data_02174e64->mGhostSlot = FindUnfilledGhostSlot();
                ((Unk0202ddd8 *) GetSlotGhostBuffer())->mUnk_08_0 = 1;
                func_020566a8((u8) data_02174e64->mGhostSlot, GetSlotGhostBuffer());
                NNS_SndArcSetCurrent(&data_0217c868);
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 10);
                NNS_SndArcSetCurrent(&data_0217d0a0);
                data_02174e64->mState = 11;
            }
            break;
        case 9:
            if (GetTxtSystemInputAccepted() != 0 && GetTxtSystemSelectedIndex() == 0) {
                NNS_SndArcSetCurrent(&data_0217c868);
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 10);
                NNS_SndArcSetCurrent(&data_0217d0a0);
            }
            if (GetTxtSystemDone() != 0) {
                RequestTxtSystemClose();
                if (GetTxtSystemSelectedIndex() == 0) {
                    data_02174e64->mGhostSlot = FindSlotGhostForCourse(
                        data_02174e64->mGhostInfoEntries[data_02174e64->mSelectedIndex].mInfo.mUnk_18[2]);
                    ((Unk0202ddd8 *) GetSlotGhostBuffer())->mUnk_08_0 = 1;
                    func_020566a8((u8) data_02174e64->mGhostSlot, GetSlotGhostBuffer());
                    data_02174e64->mState = 11;
                } else {
                    data_02174e64->mState = 10;
                }
            }
            break;
        case 10:
            if (IsTxtSystemState0NoOpenRequest() != 0) {
                message = GetBmgEntry(data_02174e64->mGhostMessages, 0x54);
                buttonText = GetBmgEntry(data_02174e64->mCommonMessages, 4);
                SetTxtSystemSoundId(0, 5);
                SetupTxtSystemSubTextButton(message, buttonText);
                data_02174e64->mState = 14;
            }
            break;
        case 11:
            if (func_02034370_inline_2() != 0) {
                message = GetBmgEntry(data_02174e64->mGhostMessages, 0x10);
                buttonText = GetBmgEntry(data_02174e64->mCommonMessages, 4);
                SetTxtSystemSoundId(0, 5);
                SetupTxtSystemSubTextButton(message, buttonText);
                data_02174e64->mState = 14;
            }
            break;
        case 15:
            if (IsTxtSystemState2AfterState1() != 0) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x15);
            }
            if (GetTxtSystemDone() != 0) {
                data_02174e64->mStateFrames = 0;
                data_02174e64->mState = 12;
                RequestTxtSystemClose();
            }
            break;
        case 14:
            if (GetTxtSystemDone() != 0) {
                data_0217b488->mUnk_08 = 5;
                if (sceneNumbers != NULL) {
                    sceneNumbers->mUnk_04 = 1;
                }
                data_02174e64->mState = 16;
            }
            break;
        case 13:
            if (data_02174e64->mUnk_194.mState == 3) {
                result = data_02174e64->mNextCallbacksIndex;
                data_02174e64->mState = 16;
            } else {
                func_02034fec();
            }
            break;
    }
    func_02035060();
    func_02054aa0();
    for (i = 0; i < 2; i++) {
        cellFileSet = &data_02174e64->mCellFileSets[i];
        DrawLayoutTable(cellFileSet->mCellLayout, cellFileSet->mCells, cellFileSet->mLabelLayout,
                        data_02174e64->mUnk_024[i], cellFileSet->mCellTable);
    }
    return result;
}

#pragma thumb off

#pragma thumb on

void func_0203434c(void) {
    HeapDestroy((void *) ((u32) data_02174e64->mHeap));
    *&data_02174e64 = NULL;
}

#pragma thumb off
