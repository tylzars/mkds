#include "Main/Unknown/code_020acaa4.h"

#include "Main/Unknown/code_020acacc.h"
#include "Main/Unknown/code_020acff4.h"
#include "Main/Unknown/code_020ad230.h"
#include "Main/Unknown/code_020adad0.h"
#include "Main/Unknown/code_020adaf8.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020acb00.h"
#include "00/code_02181f98.h"

#pragma thumb on
u32 func_020acb00(u32 arg0) {
    u32 value0 = arg0;
    u32 value3;
    value3 = (u32) &func_020ad230;
    value0 = func_020ad230(value0);
    return value0;
}
#pragma thumb off

#pragma thumb on

void UpdateTitleState4(void) {
    s32 titleStateFrames;

    titleStateFrames = GetTitleStateFrames();
    gTitleScene->mSelectedOffset = func_020ae488(titleStateFrames);
    if (titleStateFrames >= 10) {
        SetTitleState(3, 5);
    }
    SetupAndDrawTitleTable();
}

void func_020acacc(void) {}

#pragma thumb off

void func_020acab8(u32 p0) {
    data_021759d0->mUnk_20 = p0;
}

void func_020acaa4(u32 p0) {
    data_0217b488->mUnk_74 = p0;
}
