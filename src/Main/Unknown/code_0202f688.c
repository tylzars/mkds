#include "Main/Unknown/code_0202f688.h"
#include "Main/Unknown/code_020302a0.h"

#include "Main/Unknown/unk_02174000.h"
#include "registers.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_0202f14c.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02030000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0204f000.h"
#include "Main/Unknown/code_0204f814.h"
#include "Main/Unknown/code_02054000.h"
#include "Main/Unknown/code_02054f58.h"
#include "Main/Unknown/code_02055000.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ade08.h"
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
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_0212658c.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128274.h"
#include "code_02148950.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_02163000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212d214.h"
#include "code_0212df7c.h"
#include "code_0213ecf8.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0203033c.h"

#pragma thumb on

s32 IsRectInMemberRow(s32 rectIndex, s32 memberRow) {
    s32 i;
    BOOL found;

    found = FALSE;
    for (i = 0; i < 3; i++) {
        if (rectIndex == gMemberRowRectIndices[memberRow][i]) {
            found = TRUE;
            break;
        }
    }
    return found;
}

s32 func_0203023c(void) {
    BOOL result;
    s32 selectedIndex;
    BOOL memberChecksPass;

    result = TRUE;
    selectedIndex = gMultiSelectMemberGroup->mSelectedIndex;
    if (selectedIndex != 4) {
        memberChecksPass = FALSE;
        if (gMultiSelectMemberGroup->mUnk_58[selectedIndex].mUnk_00 != 0 &&
            gMultiSelectMemberGroup->mUnk_58[selectedIndex].mUnk_08 < 7) {
            memberChecksPass = TRUE;
        }
        if (memberChecksPass == FALSE) {
            result = FALSE;
        }
    }
    return result;
}

void SetMemberGroupCellTableOffsetY(void) {
    s32 i;
    s32 entryCount;
    Unk02174e50_24 *cellFileSet;

    cellFileSet = &gMultiSelectMemberGroup->mGroupSParts;
    entryCount = *OFFSET_PTR(u16, cellFileSet->mUnk_0c, 6) + *OFFSET_PTR(u16, cellFileSet->mUnk_14, 6);
    for (i = 0; i < entryCount; i++) {
        cellFileSet->mUnk_18[i].mOffsetY = gMultiSelectMemberGroup->mBg3Offset;
    }
}

void RefreshMultiSelectMemberGroup(s32 showSelected) {
    Unk02174e50_24 *cellFileSet;
    Unk021634a8 valueTable;
    s32 i;
    s32 j;
    s32 entryOffset;
    s32 rowSelected;
    s32 rowNotSelected;
    s32 x;
    BOOL y;
    BOOL z;
    MemberRowCellIndices *rowCellIndices;

    cellFileSet = &gMultiSelectMemberGroup->mGroupSParts;
    valueTable = data_021634a8;
    i = 0;
    entryOffset = 0;
    rowCellIndices = gMemberRowCellIndices;
    do {
        rowSelected = 0;
        if (gMultiSelectMemberGroup->mSelectedIndex == i && showSelected != 0) {
            rowSelected = 1;
        }
        x = *(s32 *) ((u8 *) gMultiSelectMemberGroup + entryOffset + 0x58);
        cellFileSet->mUnk_18[rowCellIndices->mCellIndices[0]].mVisible = rowSelected;
        if (rowSelected == 0) {
            rowNotSelected = 1;
        } else {
            rowNotSelected = 0;
        }
        cellFileSet->mUnk_18[rowCellIndices->mCellIndices[0x18 / 2]].mVisible = rowNotSelected;
        for (j = 1; j < 12; j++) {
            cellFileSet->mUnk_18[rowCellIndices->mCellIndices[j]].mVisible = rowSelected & x;
            cellFileSet->mUnk_18[(rowCellIndices->mCellIndices + 12)[j]].mVisible = rowNotSelected & x;
        }
        cellFileSet->mUnk_18[rowCellIndices->mCellIndices[1]].mVisible &=
            *(s32 *) ((u8 *) gMultiSelectMemberGroup + entryOffset + 0x5c);
        cellFileSet->mUnk_18[rowCellIndices->mCellIndices[13]].mVisible &=
            *(s32 *) ((u8 *) gMultiSelectMemberGroup + entryOffset + 0x5c);
        if (*(s32 *) ((u8 *) gMultiSelectMemberGroup + entryOffset + 0x5c) == 0) {
            y = TRUE;
        } else {
            y = FALSE;
        }
        cellFileSet->mUnk_18[rowCellIndices->mCellIndices[2]].mVisible &= y;
        if (*(s32 *) ((u8 *) gMultiSelectMemberGroup + entryOffset + 0x5c) == 0) {
            y = TRUE;
        } else {
            y = FALSE;
        }
        cellFileSet->mUnk_18[rowCellIndices->mCellIndices[14]].mVisible &= y;
        for (j = 0; j < 8; j++) {
            if (j == *(s32 *) (entryOffset + (s32) gMultiSelectMemberGroup + 0x60)) {
                z = TRUE;
            } else {
                z = FALSE;
            }
            cellFileSet->mUnk_18[(rowCellIndices->mCellIndices + 4)[j]].mVisible &= z;
            cellFileSet->mUnk_18[(rowCellIndices->mCellIndices + 16)[j]].mVisible &= z;
        }
        SetLabelPaletteIndex(rowCellIndices->mLabelIndex, valueTable.mUnk_00[rowSelected], cellFileSet->mUnk_14,
                             cellFileSet->mUnk_18, cellFileSet->mUnk_0c);
        entryOffset += 0xc;
        rowCellIndices = OFFSET_PTR(MemberRowCellIndices, rowCellIndices, 0x32);
        i++;
    } while (i < 4);
    if (gMultiSelectMemberGroup->mSelectedIndex == i && showSelected != 0) {
        rowSelected = 1;
    } else {
        rowSelected = 0;
    }
    cellFileSet->mUnk_18[89].mVisible = rowSelected;
    if (rowSelected == 0) {
        rowNotSelected = 1;
    } else {
        rowNotSelected = 0;
    }
    cellFileSet->mUnk_18[88].mVisible = rowNotSelected;
    SetLabelPaletteIndex(4, valueTable.mUnk_00[rowSelected], cellFileSet->mUnk_14, cellFileSet->mUnk_18,
                         cellFileSet->mUnk_0c);
}

#pragma thumb off

#pragma thumb on

// Fills with 0 through a halfword stack offset of its own.
static inline void func_0202f764_inline(void *p, s32 v1) {
    volatile u16 zero = 0;
    MIi_CpuClear16(zero, p, v1);
}

void func_0202fd2c(void) {
    s32 changed;
    Unk02174e50_24 *cellFileSet;
    s32 oldWord0;
    s32 oldWord8;
    s32 oldWord4;
    BOOL isNewEntry;
    s32 i;
    s32 j;
    Unk02174e4c_818_04 entry;

    cellFileSet = &gMultiSelectMemberGroup->mGroupSParts;
    changed = 0;
    switch (gMultiSelectMemberGroup->mUnk_50) {
        case 0:
            if (func_0205579c(0, 0) == 1) {
                gMultiSelectMemberGroup->mUnk_50 = 1;
            }
            return;
        case 1:
            if (gMultiSelectMemberGroup->mUnk_88 != FALSE) {
                if (gMultiSelectMemberGroup->mSelectedIndex < 4) {
                    for (i = 0; i < 4; i++) {
                        if (func_0204ff14(i, &func_0202f14c()->mUnk_04[i]) != 0) {
                            func_0202f14c()->mUnk_04[i].mUnk_14 = 0;
                        } else {
                            func_0202f764_inline(&func_0202f14c()->mUnk_04[i], 0x16);
                        }
                    }
                    if (func_0204ff14(gMultiSelectMemberGroup->mSelectedIndex, NULL) != 0) {
                        func_0202f14c()->mUnk_00 = gMultiSelectMemberGroup->mSelectedIndex;
                        gMultiSelectMemberGroup->mNextCallbacksIndex = 3;
                        gMultiSelectMemberGroup->mUnk_50 = 0xb;
                        return;
                    }
                    gMultiSelectMemberGroup->mUnk_58[gMultiSelectMemberGroup->mSelectedIndex].mUnk_00 = 0;
                    return;
                }
                gMultiSelectMemberGroup->mNextCallbacksIndex = 1;
                gMultiSelectMemberGroup->mUnk_50 = 5;
                return;
            }
            if (gMultiSelectMemberGroup->mState != 1) {
                return;
            }
            for (i = 0; i < 4; i++) {
                oldWord0 = gMultiSelectMemberGroup->mUnk_58[i].mUnk_00;
                oldWord8 = gMultiSelectMemberGroup->mUnk_58[i].mUnk_08;
                oldWord4 = gMultiSelectMemberGroup->mUnk_58[i].mUnk_04;
                func_0202f764_inline(&entry, 0x16);
                gMultiSelectMemberGroup->mUnk_58[i].mUnk_00 = func_0204ff14(i, &entry);
                if (gMultiSelectMemberGroup->mUnk_58[i].mUnk_00 != 0) {
                    entry.mUnk_14 = 0;
                    func_0212426c(1, gMemberRowCellIndices[i].mLabelIndex, cellFileSet->mUnk_14, &entry,
                                  cellFileSet->mUnk_0c, cellFileSet->mUnk_18);
                    gMultiSelectMemberGroup->mUnk_58[i].mUnk_08 = func_0204fe1c(i);
                    gMultiSelectMemberGroup->mUnk_58[i].mUnk_04 = func_0204fe90(i);
                } else {
                    func_0212426c(1, gMemberRowCellIndices[i].mLabelIndex, cellFileSet->mUnk_14,
                                  GetBmgEntry(gMultiSelectMemberGroup->mBannerMessages, 8), cellFileSet->mUnk_0c,
                                  cellFileSet->mUnk_18);
                    gMultiSelectMemberGroup->mUnk_58[i].mUnk_08 = 0;
                    gMultiSelectMemberGroup->mUnk_58[i].mUnk_04 = 0;
                }
                if (oldWord0 == 0 && gMultiSelectMemberGroup->mUnk_58[i].mUnk_00 != 0) {
                    isNewEntry = TRUE;
                    for (j = 0; j < 4; j++) {
                        if (wcsncmp(entry.mUnk_00, func_0202f14c()->mUnk_04[j].mUnk_00, 0xb) == 0) {
                            isNewEntry = FALSE;
                        }
                    }
                    if (isNewEntry != FALSE) {
                        NNS_SndArcSetCurrent(&data_0217c868);
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 4);
                        NNS_SndArcSetCurrent(&data_0217d0a0);
                    }
                } else if (oldWord0 != 0 && gMultiSelectMemberGroup->mUnk_58[i].mUnk_00 == 0) {
                    NNS_SndArcSetCurrent(&data_0217c868);
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 5);
                    NNS_SndArcSetCurrent(&data_0217d0a0);
                }
                changed |= oldWord0 != gMultiSelectMemberGroup->mUnk_58[i].mUnk_00 ? 1 : 0;
                changed |= oldWord8 != gMultiSelectMemberGroup->mUnk_58[i].mUnk_08 ? 1 : 0;
                changed |= oldWord4 != gMultiSelectMemberGroup->mUnk_58[i].mUnk_04 ? 1 : 0;
            }
            if (changed != 0) {
                RefreshMultiSelectMemberGroup(1);
            }
            return;
        case 5:
        case 8:
            if (func_02054f58() == 1) {
                gMultiSelectMemberGroup->mUnk_50 = 0xb;
            }
            return;
    }
}

void InitMultiSelectMemberGroup(void *parentHeap, void *scene, void *oamList) {
    void *heap;
    u32 subObjSizeLeft;
    Unk02174e50_24 *cellFileSet;
    s32 i;
    LabelMessageRow *labelMessageRow;
    void *text;

    heap = CreateFrmHeapFromMaxFree(parentHeap);
    gMultiSelectMemberGroup = HeapAlloc(heap, 0xa8);
    MemFillWordsByBlock_inline(gMultiSelectMemberGroup, 0xa8);
    gMultiSelectMemberGroup->mHeap = heap;
    gMultiSelectMemberGroup->mUnk_40 = scene;
    gMultiSelectMemberGroup->mOamList = oamList;
    gMultiSelectMemberGroup->mBannerMessages = FindSceneFile(gBannerBmgName);
    gMultiSelectMemberGroup->mState = 0;
    gMultiSelectMemberGroup->mBg3Offset = -0xc0;
    func_020258d4(1, gMultiSelectMemberGroup, gMultiSelectMemberSBNcgrName2, gMultiSelectMemberSBNclrName2,
                  gMultiSelectMemberSGroupNscrName2, 3, FindSceneFile);
    subObjSizeLeft = GX_GetSizeOfSubOBJ();
    cellFileSet = &gMultiSelectMemberGroup->mGroupSParts;
    LocateCellFileSet(cellFileSet, gMultiSelectMemberGroupSNcgrName2, gMultiSelectMemberGroupSNcerName2,
                      gMultiSelectMemberGroupSONclrName2, gMultiSelectMemberSGroupBnclName,
                      gMultiSelectMemberSGroupBnllName, gMultiSelectMemberSGroupBnblName, FindSceneFile);
    func_02025a50(1, gMultiSelectMemberGroup->mHeap, cellFileSet);
    for (i = 0, labelMessageRow = gMemberGroupLabelMessageRows; i < 5; labelMessageRow++, i++) {
        subObjSizeLeft -=
            func_02025a00(1, gMultiSelectMemberGroup->mHeap, cellFileSet, labelMessageRow, subObjSizeLeft);
        if (gMemberGroupLabelMessageRows[i].mMessageIndex < 0) {
            text = data_02163610;
        } else {
            text = GetBmgEntry(gMultiSelectMemberGroup->mBannerMessages, gMemberGroupLabelMessageRows[i].mMessageIndex);
        }
        func_0212426c(1, gMemberGroupLabelMessageRows[i].mLabelIndex, cellFileSet->mUnk_14, text, cellFileSet->mUnk_0c,
                      cellFileSet->mUnk_18);
    }
    RefreshMultiSelectMemberGroup(1);
    SetSelectReturnSoundId(0xf);
    data_021759d0->mUnk_20 = 2;
    FrmHeapShrinkInParent(gMultiSelectMemberGroup->mHeap);
}

s32 AdvanceMultiSelectMemberGroup(Unk0202f764 *sceneNumbers) {
    Unk02174e50_24 *cellFileSet;
    s32 result;
    u16 slotIndex;
    s32 i;
    s32 touchInReturnRect;
    s32 rectIndex;
    BOOL pairIsNew;
    BOOL pairRecentlyGone;
    u16 v;
    s32 pairX;
    s32 pairY;
    s32 selectionChanged;

    result = -1;
    slotIndex = func_020435bc();
    cellFileSet = &gMultiSelectMemberGroup->mGroupSParts;
    if (gMultiSelectMemberGroup->mEntriesCleared == FALSE) {
        gMultiSelectMemberGroup->mEntriesClearFrames++;
        if (gMultiSelectMemberGroup->mEntriesClearFrames > 0x78) {
            for (i = 0; i < 4; i++) {
                func_0202f764_inline(&func_0202f14c()->mUnk_04[i], 0x16);
            }
            gMultiSelectMemberGroup->mEntriesCleared = TRUE;
        }
    }
    if (gMultiSelectMemberGroup->mState != -1) {
        func_0202fd2c();
    }
    switch (gMultiSelectMemberGroup->mState) {
        case 0:
            if (AreBrightnessFadesClear() == 0) {
                break;
            }
            if (gMultiSelectMemberGroup->mBg3OffsetFrames == 0) {
                RequestSelectReturnState1();
                func_02126638(GetBmgEntry(gMultiSelectMemberGroup->mBannerMessages, 7), 0, 0, 1, 0, 0, 0);
            }
            gMultiSelectMemberGroup->mBg3OffsetFrames++;
            if (gMultiSelectMemberGroup->mBg3OffsetFrames < 10) {
                gMultiSelectMemberGroup->mBg3Offset =
                    InterpolateS16(1, -0xc0, 0, gMultiSelectMemberGroup->mBg3OffsetFrames, 10);
            } else {
                gMultiSelectMemberGroup->mBg3OffsetFrames = 0;
                gMultiSelectMemberGroup->mBg3Offset = 0;
                gMultiSelectMemberGroup->mState = 1;
            }
            SetMemberGroupCellTableOffsetY();
            break;
        case 1:
            touchInReturnRect = 0;
            rectIndex = -1;
            pairIsNew = FALSE;
            pairRecentlyGone = FALSE;
            v = data_02175628[slotIndex].mHasPair;
            if (v == 0 && data_02175628[slotIndex].mNoPairCount < 5) {
                pairRecentlyGone = TRUE;
            }
            if (pairRecentlyGone == FALSE && data_02175628[slotIndex].mPrevHasPair == 0 && v != 0) {
                pairIsNew = TRUE;
            }
            if (pairIsNew != FALSE) {
                pairX = data_02175628[slotIndex].mPairX;
                pairY = data_02175628[slotIndex].mPairY;
                touchInReturnRect = IsSelectReturnState2NoState3Or4RequestAndInRect(pairX, pairY);
                rectIndex = RectTableFindContaining(cellFileSet->mUnk_10, pairX, pairY);
            }
            v = data_02175628[slotIndex].mUnk_00;
            if ((u16) (v & PAD_KEY_A) != 0) {
                if (func_0203023c() != 0) {
                    gMultiSelectMemberGroup->mUnk_88 = TRUE;
                    gMultiSelectMemberGroup->mState = 2;
                    gMultiSelectMemberGroup->mState2Frames = 0;
                    RefreshMultiSelectMemberGroup(0);
                    if (gMultiSelectMemberGroup->mSelectedIndex == 4) {
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x4e);
                    } else {
                        if ((data_0217aa00 == NULL ? 0 : data_0217aa00->mUnk_0000) == 2) {
                            data_0217aa00->mUnk_0436 |= 1;
                        }
                        NNS_SndArcSetCurrent(&data_0217c868);
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 2);
                        NNS_SndArcSetCurrent(&data_0217d0a0);
                    }
                } else {
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x4f);
                }
            } else if ((u16) (v & PAD_KEY_B) != 0 || touchInReturnRect != 0) {
                if (sceneNumbers != NULL) {
                    sceneNumbers->mUnk_04 = 0;
                }
                gMultiSelectMemberGroup->mState = 3;
                RequestSelectReturnState3WithSound(1);
            } else if (GetNewOrRepeatBits(slotIndex, PAD_KEY_UP) != 0) {
                gMultiSelectMemberGroup->mSelectedIndex--;
                if (gMultiSelectMemberGroup->mSelectedIndex < 0) {
                    gMultiSelectMemberGroup->mSelectedIndex = 4;
                }
                RefreshMultiSelectMemberGroup(1);
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
            } else if (GetNewOrRepeatBits(slotIndex, PAD_KEY_DOWN) != 0) {
                gMultiSelectMemberGroup->mSelectedIndex++;
                if (gMultiSelectMemberGroup->mSelectedIndex > 4) {
                    gMultiSelectMemberGroup->mSelectedIndex = 0;
                }
                RefreshMultiSelectMemberGroup(1);
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
            } else if (rectIndex == 0xc) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x4e);
                RefreshMultiSelectMemberGroup(gMultiSelectMemberGroup->mSelectedIndex != 4 ? 1 : 0);
                gMultiSelectMemberGroup->mState2Frames = 0;
                gMultiSelectMemberGroup->mState = 2;
                gMultiSelectMemberGroup->mSelectedIndex = 4;
                gMultiSelectMemberGroup->mUnk_88 = TRUE;
            } else {
                for (i = 0; i < 4; i++) {
                    if (IsRectInMemberRow(rectIndex, i) != 0) {
                        selectionChanged = gMultiSelectMemberGroup->mSelectedIndex != i ? 1 : 0;
                        if (gMultiSelectMemberGroup->mUnk_58[i].mUnk_00 != 0 &&
                            gMultiSelectMemberGroup->mUnk_58[i].mUnk_08 < 7) {
                            NNS_SndArcSetCurrent(&data_0217c868);
                            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 2);
                            NNS_SndArcSetCurrent(&data_0217d0a0);
                            gMultiSelectMemberGroup->mSelectedIndex = i;
                            RefreshMultiSelectMemberGroup(selectionChanged);
                            gMultiSelectMemberGroup->mState2Frames = 0;
                            gMultiSelectMemberGroup->mState = 2;
                            gMultiSelectMemberGroup->mUnk_88 = TRUE;
                        } else {
                            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x4f);
                        }
                    }
                }
            }
            break;
        case 2:
            gMultiSelectMemberGroup->mState2Frames++;
            if (gMultiSelectMemberGroup->mState2Frames >= 5) {
                gMultiSelectMemberGroup->mState2Frames = 0;
                RefreshMultiSelectMemberGroup(1);
                if (gMultiSelectMemberGroup->mSelectedIndex < 4 &&
                    gMultiSelectMemberGroup->mUnk_58[gMultiSelectMemberGroup->mSelectedIndex].mUnk_00 == 0) {
                    gMultiSelectMemberGroup->mState = 1;
                } else {
                    gMultiSelectMemberGroup->mState = 3;
                    RequestTxtSystemClose();
                }
            }
            break;
        case 3:
            gMultiSelectMemberGroup->mBg3OffsetFrames++;
            if (gMultiSelectMemberGroup->mBg3OffsetFrames < 10) {
                gMultiSelectMemberGroup->mBg3Offset =
                    InterpolateS16(1, 0, -0xc0, gMultiSelectMemberGroup->mBg3OffsetFrames, 10);
            } else {
                gMultiSelectMemberGroup->mBg3OffsetFrames = 0;
                gMultiSelectMemberGroup->mBg3Offset = 0;
                gMultiSelectMemberGroup->mState = 4;
            }
            SetMemberGroupCellTableOffsetY();
            break;
        case 4:
            if (gMultiSelectMemberGroup->mUnk_50 == 0xb) {
                result = gMultiSelectMemberGroup->mNextCallbacksIndex;
            }
            break;
    }
    if (gMultiSelectMemberGroup->mState != 4) {
        DrawLayoutTable(cellFileSet->mUnk_0c, cellFileSet->mUnk_08, cellFileSet->mUnk_14,
                        gMultiSelectMemberGroup->mOamList, cellFileSet->mUnk_18);
    }
    return result;
}

#pragma thumb off

#pragma thumb on

void ReleaseMultiSelectMemberGroup(void) {
    HeapDestroy(gMultiSelectMemberGroup->mHeap);
    *&gMultiSelectMemberGroup = NULL;
}

#pragma thumb off

#pragma thumb on

void WriteMultiSelectMemberGroupRegisters(void) {
    u32 displayBits = 0x16;
    s32 windowEndY;

    if (gMultiSelectMemberGroup->mState != 4) {
        displayBits |= 8;
    }
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | (displayBits << 8);
    reg_G2S_DB_BG3OFS = (-gMultiSelectMemberGroup->mBg3Offset << 16) & 0x1ff0000;
    if (gMultiSelectMemberGroup->mBg3Offset != 0) {
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffff1fff) | 0x2000;
        reg_G2S_DB_WININ = (u32) ((reg_G2S_DB_WININ & ~0x3f) | 0x1f) | 0x20;
        reg_G2S_DB_WINOUT = (u32) ((reg_G2S_DB_WINOUT & ~0x3f) | 7) | 0x20;
        windowEndY = gMultiSelectMemberGroup->mBg3Offset + 0xc0;
        reg_G2S_DB_WIN0H = 0xff;
        reg_G2S_DB_WIN0V = windowEndY & 0xff;
    } else {
        reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffff1fff;
    }
}

#pragma thumb off
