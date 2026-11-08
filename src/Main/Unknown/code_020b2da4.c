#include "Main/Unknown/code_020b2da4.h"
#include "Main/Unknown/code_020b2c80.h"
#include "Main/Unknown/code_020b32ec.h"
#include "Main/Unknown/code_020b41e8.h"
#include "Main/Unknown/code_020b1de4.h"

#pragma thumb on
#pragma optimize_for_size on
void func_020b2e00(u16 *screenMap, s32 column, s32 row) {
    SetScreenMapBlockLowBits(screenMap, column, row, 1, 1, 4);
    SetScreenMapBlockLowBits(screenMap, column, row + 1, 1, 1, 0x24);
}

void func_020b2da4(void) {
    s32 valueCount;
    s32 valueIndex;
    s32 firstRow;
    u16 *screenMap;

    valueCount = gChoisesS->mLists[GetChoisesSListIndex()].mValueCount;
    screenMap = GetChoisesSListScreenMapData();
    if (screenMap != NULL) {
        for (valueIndex = 0, firstRow = 0xd - valueCount * 2; valueIndex < valueCount; valueIndex++) {
            func_020b2e00(screenMap, 2, firstRow + valueIndex * 4);
        }
        SetScreenMapBlockTopBits(screenMap, 0, 0, 0x20, 0x18, 0xf);
    }
}
#pragma thumb off
