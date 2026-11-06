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
    u32 value0;
    u32 value12;
    value0 = (u32) &data_0217b484;
    ClearRaceHudSubScreenCells((RaceHudSubScreenCells **) value0);
}

void func_020ced2c(void) {
    s32 i;
    s32 n;
    s32 v;
    Unk0217b498_00 *e;

    n = 0;
    v = func_020c0db0();
    for (i = 0; i < data_0217b484->mObjectCount; i++) {
        e = data_0217b484->mObjects[i];
        if ((e->mFlags & 1) == 0) {
            if (ComputeRaceHudSubScreenPosition(&e->mPos, &data_0217b484->mCells[n].mUnk_00, v, 1, 1) != FALSE) {
                data_0217b484->mCells[n].mUnk_08 = GetRaceSNcerEntry(0xa4);
                data_0217b484->mCells[n].mUnk_0c = 2;
                n++;
            }
        }
    }
    data_0217b484->mCellCount = n;
}

void func_020ced10(Unk020c06c4 *a) {
    DrawRaceHudSubScreenCells(a, data_0217b484, 0);
}
