#include "Main/Unknown/code_020ad028.h"
#include "Main/Unknown/code_020acbe8.h"
#include "Main/Unknown/code_020adaf8.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma optimize_for_size on
#pragma thumb on

void SetupTitleTable(void) {
    Unk02124b1c *p;
    u32 w;
    s32 i;

    p = gTitleScene->mTitleTable;
    w = func_020acbe8(gTitleScene->mTitleSBncl);
    for (i = 0; i <= 9; i++) {
        p[i].mUnk_00 = 1;
    }
    for (i = 10; i <= 14; i++) {
        p[i].mUnk_00 = 0;
    }
    for (i = 0; i <= 1; i++) {
        p[w + i].mUnk_00 = 1;
    }
    func_02124100(0, 15, gTitleScene->mTitleSBnll, p, gTitleScene->mTitleSBncl);
    func_02124100(1, 15, gTitleScene->mTitleSBnll, p, gTitleScene->mTitleSBncl);
    switch (gTitleScene->mSelectedIndex) {
        case 0:
            if (gTitleScene->mState == 4) {
                p[0].mUnk_04 = gTitleScene->mSelectedOffset;
                p[5].mUnk_04 = gTitleScene->mSelectedOffset;
                p[10].mUnk_04 = gTitleScene->mSelectedOffset;
            }
            if (gTitleScene->mState != 4 || gTitleScene->mSelectedPressed == FALSE || GetTitleStateFrames() >= 5) {
                p[5].mUnk_00 = 0;
                p[10].mUnk_00 = 1;
            }
            break;
        case 1:
            if (gTitleScene->mState == 4) {
                p[1].mUnk_04 = gTitleScene->mSelectedOffset;
                p[6].mUnk_04 = gTitleScene->mSelectedOffset;
                p[11].mUnk_04 = gTitleScene->mSelectedOffset;
            }
            if (gTitleScene->mState != 4 || gTitleScene->mSelectedPressed == FALSE || GetTitleStateFrames() >= 5) {
                p[6].mUnk_00 = 0;
                p[11].mUnk_00 = 1;
            }
            break;
        case 2:
            if (gTitleScene->mState == 4) {
                p[2].mUnk_04 = gTitleScene->mSelectedOffset;
                p[7].mUnk_04 = gTitleScene->mSelectedOffset;
                p[12].mUnk_04 = gTitleScene->mSelectedOffset;
            }
            if (gTitleScene->mState != 4 || gTitleScene->mSelectedPressed == FALSE || GetTitleStateFrames() >= 5) {
                p[7].mUnk_00 = 0;
                p[12].mUnk_00 = 1;
            }
            break;
        case 3:
            if (gTitleScene->mState != 4 || gTitleScene->mSelectedPressed == FALSE || GetTitleStateFrames() >= 5) {
                p[8].mUnk_00 = 0;
                p[13].mUnk_00 = 1;
                func_02124100(0, 14, gTitleScene->mTitleSBnll, p, gTitleScene->mTitleSBncl);
            }
            break;
        case 4:
            if (gTitleScene->mState != 4 || gTitleScene->mSelectedPressed == FALSE || GetTitleStateFrames() >= 5) {
                p[9].mUnk_00 = 0;
                p[14].mUnk_00 = 1;
                func_02124100(1, 14, gTitleScene->mTitleSBnll, p, gTitleScene->mTitleSBncl);
            }
            break;
    }
}

#pragma thumb off
