#include "Main/Unknown/code_020b2c80.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020b24e4.h"
#include "Main/Unknown/code_020b252c.h"
#include "Main/Unknown/code_020b2a4c.h"
#include "Main/Unknown/code_020b2d90.h"
#include "Main/Unknown/code_020b32ec.h"
#include "Main/Unknown/code_020b41e8.h"
#include "Main/Unknown/code_020c3000.h"
#include "Main/Unknown/code_020c3db4.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020b1de4.h"
#include "Main/Unknown/code_0203c5f8.h"

s32 GetEntryEndKind(void) {
    if (IsKartEnded((u16) GetEntryIndex()) != 0) {
        return gRaceProgress->mEntryEndKind;
    }
    return 6;
}

#pragma thumb on
#pragma optimize_for_size on
u32 GetChoisesSListIndex(void) {
    if (func_020b24e4() == 2 && GetRaceDone() == 0) {
        return 3;
    }
    if (GetRaceDone() != 0) {
        if (func_020b252c() == MODE_MISSION_RUN) {
            if (GetEntryEndKind() == 0) {
                return 2;
            }
            return 1;
        }
        if (func_020c3db4() != 0) {
            return 2;
        }
        return 1;
    }
    return 0;
}

void func_020b2c80(s32 selectedIndex) {
    s32 valueCount;
    s32 row;
    u16 *screenMap;

    valueCount = gChoisesS->mLists[GetChoisesSListIndex()].mValueCount;
    screenMap = func_020b32f8();
    if (screenMap != NULL) {
        if (gChoisesS->mUnk_010 == FALSE || gChoisesS->mPickFrames >= 5) {
            row = 0xd - valueCount * 2 + selectedIndex * 4;
            if (gChoisesS->mCycleFrames < 0x1e) {
                func_020b4428(screenMap, 2, row, 1, 1, 0x21);
                func_020b4428(screenMap, 2, row + 1, 1, 1, 0x41);
            }
            func_020b44a4(screenMap, 0, row - 1, 0x20, 4, 0xe);
        }
    }
}
#pragma thumb off
