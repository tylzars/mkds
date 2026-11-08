#include "Main/Unknown/code_020ced10.h"
#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020c0b84.h"

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
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/code_020cedf8.h"

void func_020cedf8(void) {
    u32 address;
    u32 value12;
    address = (u32) &data_0217b484;
    ClearRaceHudSubScreenCells((RaceHudSubScreenCells **) address);
}

void func_020ced2c(void) {
    s32 i;
    s32 cellCount;
    s32 v;
    Unk0217b498_00 *object;

    cellCount = 0;
    v = GetRaceHudSubScreenScale();
    for (i = 0; i < data_0217b484->mObjectCount; i++) {
        object = data_0217b484->mObjects[i];
        if ((object->mFlags & 1) == 0) {
            if (ComputeRaceHudSubScreenPosition(&object->mPos, &data_0217b484->mCells[cellCount].mDrawPos, v, 1, 1) !=
                FALSE) {
                data_0217b484->mCells[cellCount].mCell = GetRaceSNcerEntry(0xa4);
                data_0217b484->mCells[cellCount].mUnk_0c = 2;
                cellCount++;
            }
        }
    }
    data_0217b484->mCellCount = cellCount;
}

void func_020ced10(Unk020c06c4 *oamBuffer) {
    DrawRaceHudSubScreenCells(oamBuffer, data_0217b484, 0);
}
