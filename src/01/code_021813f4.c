#include "01/code_021813f4.h"

#include "01/code_0218155c.h"
#include "01/code_02188950.h"
#include "01/code_02188e88.h"
#include "01/unk_021a9000.h"
#include "01/code_02181000.h"
#include "03/code_021b94b8.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_020b4000.h"
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
#include "Main/Unknown/code_020c06c4.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/code_0214d000.h"

RaceHudSubScreenCells *data_ov001_021a9b8c;

s32 func_ov001_02181528(void) {
    Unk02188950 *p;

    if (data_021759c0->mMode == MODE_MISSION_RUN) {
        p = func_ov001_02181b68(data_021759c0->mMode == MODE_MISSION_RUN ? func_ov001_02181b54() : 0);
    } else {
        p = NULL;
    }
    return p->mUnk_168;
}

#pragma thumb off

s32 func_ov001_02181510(void) {
    return CreateRaceHudSubScreenCells(&data_ov001_021a9b8c, 0x68);
}

void func_ov001_021814fc(void) {
    ClearRaceHudSubScreenCells(&data_ov001_021a9b8c);
}

void func_ov001_02181410(void) {
    s32 i;
    s32 count;
    Unk0217b498_00 *e;
    Vec3 *pos;
    u32 v;

    count = 0;
    v = func_020c0db0();
    for (i = 0; i < data_ov001_021a9b8c->mObjectCount; i++) {
        e = data_ov001_021a9b8c->mObjects[i];
        if ((e->mFlags & 1) == 0) {
            pos = &e->mPos;
            if (ComputeRaceHudSubScreenPosition(pos, &data_ov001_021a9b8c->mCells[count].mUnk_00, v, 1, 1)) {
                data_ov001_021a9b8c->mCells[count].mUnk_08 = GetRaceSNcerEntry(0x58);
                data_ov001_021a9b8c->mCells[count].mUnk_0c = func_020b4e70(pos) != 0 ? 2 : 3;
                count++;
            }
        }
    }
    data_ov001_021a9b8c->mCellCount = count;
}

void func_ov001_021813f4(void *p0) {
    DrawRaceHudSubScreenCells(p0, data_ov001_021a9b8c, 0);
}

#pragma thumb on
