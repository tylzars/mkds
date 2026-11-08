#include "Main/Unknown/code_020acb08.h"
#include "Main/Unknown/code_020acbe8.h"
#include "Main/Unknown/code_020acff4.h"
#include "Main/Unknown/code_020adad0.h"
#include "Main/Unknown/code_020adaf8.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/unk_0217b000.h"

u32 func_020acbc0(void) {
    return data_0217aa08->mFirstBlock->mUnk_31_0 != 0;
}

#pragma optimize_for_size on
#pragma thumb on

void UpdateTitleState3(void) {
    u32 w;
    s32 i;
    LayoutTableEntry *titleTable;

    titleTable = gTitleScene->mTitleTable;
    w = func_020acbe8(gTitleScene->mTitleSBncl);
    if (GetTitleStateFrames() < 10) {
        for (i = 0; i <= 14; i++) {
            titleTable[i].mOffsetX = InterpolateS16(1, 0, 0xf8, GetTitleStateFrames(), 10);
        }
        for (i = 0; i <= 1; i++) {
            titleTable[i + w].mOffsetX = InterpolateS16(1, 0, 0xf8, GetTitleStateFrames(), 10);
        }
    } else {
        for (i = 0; i <= 14; i++) {
            titleTable[i].mOffsetX = 0xf8;
        }
        for (i = 0; i <= 1; i++) {
            titleTable[i + w].mOffsetX = 0xf8;
        }
        if (func_020acbc0() != 0) {
            SetTitleState(gTitleScene->mNextState, 8);
        } else {
            SetTitleState(6, 8);
        }
    }
    SetupAndDrawTitleTable();
}

#pragma thumb off
