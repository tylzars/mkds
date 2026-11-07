#include "Main/Unknown/code_020acbe8.h"
#include "Main/Unknown/code_0203b6ac.h"
#include "Main/Unknown/code_020aca24.h"

#include "Main/Unknown/code_020acbf0.h"
#include "Main/Unknown/code_020acbf8.h"
#include "Main/Unknown/code_020acdc4.h"
#include "Main/Unknown/code_020acdec.h"
#include "Main/Unknown/code_020ace14.h"
#include "Main/Unknown/code_020acec4.h"
#include "Main/Unknown/code_020acef4.h"
#include "Main/Unknown/code_020acf04.h"
#include "Main/Unknown/code_020acff4.h"
#include "Main/Unknown/code_020ad230.h"
#include "Main/Unknown/code_020adad0.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020291c4.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Unknown/code_0210f72c.h"
#include "Main/Unknown/code_0210f744.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020acde4.h"
#include "Main/Unknown/code_020ace0c.h"

u32 func_020ace0c(u32 p0) {
    return (*OFFSET_PTR(const u16, p0, 0));
}

u32 func_020acdec(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value12;
    value2 = (u32) &data_02175628;
    value1 = 0x5cu;
    value1 = (value0) * (value1) + (value2);
    value12 = (u32) &func_020ace0c;
    value0 = (value1) + (0x48u);
    value0 = func_020ace0c(value0);
    return value0;
}

u32 func_020acde4(u32 p0) {
    return (*OFFSET_PTR(const u16, p0, 2));
}

u32 func_020acdc4(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value12;
    value2 = (u32) &data_02175628;
    value1 = 0x5cu;
    value1 = (value0) * (value1) + (value2);
    value12 = (u32) &func_020acde4;
    value0 = (value1) + (0x48u);
    value0 = func_020acde4(value0);
    return value0;
}

#pragma thumb on

void UpdateTitleState2(Unk020aca24 *a) {
    u32 i;
    s32 j;
    s32 n;

    if (a != NULL) {
        i = func_020acef4();
        if (func_020acec4(i, PAD_KEY_A) != 0) {
            SetTitleState(4, 8);
            func_020acf04();
            gTitleScene->mSelectedPressed = TRUE;
        } else if (GetNewOrRepeatBits(i, (PAD_KEY_LEFT | PAD_KEY_RIGHT)) != 0) {
            switch (gTitleScene->mSelectedIndex) {
                case 3:
                    gTitleScene->mSelectedIndex = 4;
                    gTitleScene->mPreferEntry4 = TRUE;
                    StartSoundOncePerFrame(0);
                    break;
                case 4:
                    gTitleScene->mSelectedIndex = 3;
                    gTitleScene->mPreferEntry4 = FALSE;
                    StartSoundOncePerFrame(0);
                    break;
            }
            gTitleScene->mNoInputFrames = 0;
        } else if (GetNewOrRepeatBits(i, PAD_KEY_UP) != 0) {
            switch (gTitleScene->mSelectedIndex) {
                case 0:
                    if (gTitleScene->mPreferEntry4 != FALSE) {
                        gTitleScene->mSelectedIndex = 4;
                    } else {
                        gTitleScene->mSelectedIndex = 3;
                    }
                    break;
                case 1:
                    gTitleScene->mSelectedIndex = 0;
                    break;
                case 2:
                    gTitleScene->mSelectedIndex = 1;
                    break;
                case 3:
                case 4:
                    gTitleScene->mSelectedIndex = 2;
                    break;
            }
            StartSoundOncePerFrame(0);
            gTitleScene->mNoInputFrames = 0;
        } else if (GetNewOrRepeatBits(i, PAD_KEY_DOWN) != 0) {
            switch (gTitleScene->mSelectedIndex) {
                case 0:
                    gTitleScene->mSelectedIndex = 1;
                    break;
                case 1:
                    gTitleScene->mSelectedIndex = 2;
                    break;
                case 2:
                    if (gTitleScene->mPreferEntry4 != FALSE) {
                        gTitleScene->mSelectedIndex = 4;
                    } else {
                        gTitleScene->mSelectedIndex = 3;
                    }
                    break;
                case 3:
                case 4:
                    gTitleScene->mSelectedIndex = 0;
                    break;
            }
            StartSoundOncePerFrame(0);
            gTitleScene->mNoInputFrames = 0;
        } else if (func_020ace14(i) != 0) {
            u32 x = func_020acdec(i);
            u32 y = func_020acdc4(i);
            j = gTitleScene->mSelectedIndex;
            n = FindRectContainingPoint(x, y, gTitleScene->mTitleSBnbl);
            if (n != -1) {
                if (j == n) {
                    gTitleScene->mSelectedPressed = TRUE;
                }
                gTitleScene->mSelectedIndex = n;
                SetTitleState(4, 8);
                func_020acf04();
            }
        } else {
            s32 m = GetTitleNoInputFrameLimit();
            gTitleScene->mNoInputFrames++;
            if (gTitleScene->mNoInputFrames > m) {
                if (IsSeqVariableChanged(0) != 0) {
                    a->mNextScene = 2;
                    SetNextDemoRace(gTitleScene->mUnk_8b8);
                }
            }
        }
    }
    SetupAndDrawTitleTable();
}

#pragma thumb off

#pragma thumb on
u32 func_020acbf0(u32 arg0) {
    u32 value0 = arg0;
    u32 value3;
    value3 = (u32) &func_020ad230;
    value0 = func_020ad230(value0);
    return value0;
}
#pragma thumb off

u32 func_020acbe8(Unk0201ea30 *p0) {
    return (*OFFSET_PTR(const u16, p0, 6));
}
