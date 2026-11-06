#include "Main/Unknown/code_020acfec.h"

#include "Main/Unknown/code_020acff4.h"
#include "Main/Unknown/code_020ad028.h"
#include "Main/Unknown/code_020ad230.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on

void SetupAndDrawTitleTable(void) {
    TitleScene *v1;
    SetupTitleTable();
    v1 = gTitleScene;
    func_02124c30(v1->mTitleSBncl, v1->mTitleSNceNcer, v1->mTitleSBnll, &v1->mSubOam, v1->mTitleTable);
}

#pragma thumb off

#pragma thumb on
u32 func_020acfec(u32 arg0) {
    u32 value0 = arg0;
    u32 value3;
    value3 = (u32) &func_020ad230;
    value0 = func_020ad230(value0);
    return value0;
}
#pragma thumb off
