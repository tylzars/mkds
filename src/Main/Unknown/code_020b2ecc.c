#include "Main/Unknown/code_020b2ecc.h"
#include "Main/Unknown/code_0205ee14.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_0205f000.h"
#include "Main/Unknown/code_020b24e4.h"
#include "Main/Unknown/code_020b29c4.h"
#include "Main/Unknown/code_020b2b54.h"
#include "Main/Unknown/code_020b2b70.h"
#include "Main/Unknown/code_020b2c80.h"
#include "Main/Unknown/code_020b2e98.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b3278.h"
#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_02133000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b1de4.h"

#pragma thumb on
#pragma optimize_for_size on
void *GetChoisesSValueMessage(s32 listIndex, s32 value) {
    s32 entryNumbers[11] = {0x5d, 0x67, 0x62, 0x64, 0x65, 0x66, 0x69, 0x62, 0x61, 0x5f, 0x75};

    if (func_020b24e4() == 2) {
        entryNumbers[0] = 0x6a;
        entryNumbers[8] = 0x63;
    }
    if (listIndex != 0) {
        entryNumbers[2] = 0x60;
    }
    return GetBmgEntry(FindFileInLoadedArchivesWrapper("common.bmg"), entryNumbers[value]);
}

void ClearChoisesSListValueCounts(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        gChoisesS->mLists[i].mValueCount = 0;
    }
}

void AppendChoisesSListValue(s32 listIndex, s32 value) {
    s32 valueCount;

    valueCount = gChoisesS->mLists[listIndex].mValueCount;
    gChoisesS->mLists[listIndex].mValueCount = valueCount + 1;
    gChoisesS->mLists[listIndex].mValues[valueCount] = value;
}

s32 MoveChoisesSSelectedValue(s32 step) {
    s32 selectedIndex = 0;
    s32 valueCount;
    s32 listIndex;
    ChoisesS *choisesS;

    if (func_020b2e98() != 0) {
        listIndex = GetChoisesSListIndex();
        valueCount = gChoisesS->mLists[listIndex].mValueCount;
        for (; selectedIndex < valueCount; selectedIndex++) {
            if (gChoisesS->mSelectedValue == gChoisesS->mLists[listIndex].mValues[selectedIndex]) {
                break;
            }
        }
        if (valueCount == 1) {
            step = 0;
        } else if (valueCount == 2) {
            if (step != 0 && selectedIndex + step >= 0 && selectedIndex + step < valueCount) {
                gChoisesS->mCycleFrames = 0;
                StartSoundOncePerFrame(0);
            } else {
                step = 0;
            }
        } else if (step != 0) {
            gChoisesS->mCycleFrames = 0;
            StartSoundOncePerFrame(0);
        }
        choisesS = gChoisesS;
        choisesS->mSelectedValue =
            choisesS->mLists[listIndex].mValues[(valueCount + (selectedIndex + step)) % valueCount];
    }
    return selectedIndex;
}

static inline ChoisesS *func_020b302c_inline(void) {
    return gChoisesS;
}

u32 func_020b302c(void) {
    u32 touched = 0;
    s32 valueCount;
    s32 listIndex;
    s32 valueIndex;
    PairRect valueRects[6];
    s32 firstRectRow;
    s32 top;

    if (func_020b2e98() != 0) {
        MoveChoisesSSelectedValue(0);
        listIndex = GetChoisesSListIndex();
        valueCount = gChoisesS->mLists[listIndex].mValueCount;
        for (valueIndex = 0, firstRectRow = 0xc - valueCount * 2; valueIndex < valueCount; valueIndex++) {
            top = (firstRectRow + valueIndex * 4) * 8 + 6;
            valueRects[valueIndex].mMinX = 8;
            valueRects[valueIndex].mMaxX = 0xf8;
            valueRects[valueIndex].mMinY = top;
            valueRects[valueIndex].mMaxY = top + 0x16;
        }
        for (valueIndex = 0; valueIndex < valueCount; valueIndex++) {
            if (IsNewPairInRect(func_020b2b54(), valueRects[valueIndex]) != 0) {
                if (gChoisesS->mSelectedValue != func_020b302c_inline()->mLists[listIndex].mValues[valueIndex]) {
                    gChoisesS->mSelectedValue = gChoisesS->mLists[listIndex].mValues[valueIndex];
                    MoveChoisesSSelectedValue(0);
                } else {
                    gChoisesS->mUnk_010 = TRUE;
                }
                touched = 1;
            }
        }
        if (touched != 0) {
            if (gChoisesS->mSelectedValue == 0) {
                func_02105c4c();
            } else {
                StartChoisesSSelectedValueSeq();
            }
        }
    }
    return touched;
}

void ResetChoisesSSelection(void) {
    ChoisesS *choisesS;

    gChoisesS->mPickedValue = 0;
    choisesS = gChoisesS;
    choisesS->mSelectedValue = choisesS->mLists[GetChoisesSListIndex()].mValues[0];
}

void func_020b2f88(s32 openFlag) {
    if (gChoisesS->mPickLocked != 0) {
        return;
    }
    if (openFlag != 0 && func_020b2e98() == 0) {
        if (func_020b29c4() != 0) {
            gChoisesS->mOpenDuringRace = openFlag;
        } else if (func_020b2b70() != 0) {
            gChoisesS->mUnk_008 = openFlag;
        } else {
            return;
        }
        ResetChoisesSSelection();
    } else if (openFlag == 0 && func_020b2e98() != 0) {
        if (func_020b29c4() != 0) {
            gChoisesS->mOpenDuringRace = openFlag;
        } else if (func_020b2b70() != 0) {
            gChoisesS->mUnk_008 = openFlag;
        } else {
            return;
        }
    }
    if (gChoisesS->mPickedValue != 0) {
        gChoisesS->mPickLocked = 1;
    }
}

u32 func_020b2f58(void) {
    if ((GetMissionRunTableRow() == 6 && GetMissionRunTableColumn() == 9) ||
        (GetMissionRunTableRow() == 7 && GetMissionRunTableColumn() == 9)) {
        return 1;
    }
    return 0;
}
#pragma thumb off

s8 GetMissionRunTableRow(void) {
    RaceSetup *raceSetup = gRaceSetup;

    if (raceSetup->mMode == MODE_MISSION_RUN) {
        return raceSetup->mMissionTableRow;
    }
    return -1;
}

s8 GetMissionRunTableColumn(void) {
    RaceSetup *raceSetup = gRaceSetup;

    if (raceSetup->mMode == MODE_MISSION_RUN) {
        return raceSetup->mMissionTableColumn;
    }
    return -1;
}

#pragma thumb on
u32 func_020b2ecc(void) {
    s32 recordValue;
    s32 isFilled;

    isFilled = GetMissionRecordValue(GetMissionRunTableRow(), GetMissionRunTableColumn(), &recordValue);
    if (GetEntryEndKind() == 0 && gChoisesS->mUnk_020 != FALSE && isFilled != 0 && (u32) (recordValue - 5) <= 2) {
        return 1;
    }
    return 0;
}
#pragma thumb off
