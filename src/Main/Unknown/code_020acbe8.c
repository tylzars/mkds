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

u32 func_020ace0c(u32 pair) {
    return (*OFFSET_PTR(const u16, pair, 0));
}

u32 func_020acdec(u32 slotIndex) {
    u32 value0 = slotIndex;
    u32 value1;
    u32 slotsAddress;
    u32 functionAddress;
    slotsAddress = (u32) &data_02175628;
    value1 = 0x5cu;
    value1 = (value0) * (value1) + (slotsAddress);
    functionAddress = (u32) &func_020ace0c;
    value0 = (value1) + (0x48u);
    value0 = func_020ace0c(value0);
    return value0;
}

u32 func_020acde4(u32 pair) {
    return (*OFFSET_PTR(const u16, pair, 2));
}

u32 func_020acdc4(u32 slotIndex) {
    u32 value0 = slotIndex;
    u32 value1;
    u32 slotsAddress;
    u32 functionAddress;
    slotsAddress = (u32) &data_02175628;
    value1 = 0x5cu;
    value1 = (value0) * (value1) + (slotsAddress);
    functionAddress = (u32) &func_020acde4;
    value0 = (value1) + (0x48u);
    value0 = func_020acde4(value0);
    return value0;
}

#pragma thumb on

void UpdateTitleState2(Unk020aca24 *a) {
    u32 slotIndex;
    s32 previousIndex;
    s32 rectIndex;

    if (a != NULL) {
        slotIndex = func_020acef4();
        if (func_020acec4(slotIndex, PAD_KEY_A) != 0) {
            SetTitleState(4, 8);
            func_020acf04();
            gTitleScene->mSelectedPressed = TRUE;
        } else if (GetNewOrRepeatBits(slotIndex, (PAD_KEY_LEFT | PAD_KEY_RIGHT)) != 0) {
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
        } else if (GetNewOrRepeatBits(slotIndex, PAD_KEY_UP) != 0) {
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
        } else if (GetNewOrRepeatBits(slotIndex, PAD_KEY_DOWN) != 0) {
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
        } else if (func_020ace14(slotIndex) != 0) {
            u32 pointX = func_020acdec(slotIndex);
            u32 pointY = func_020acdc4(slotIndex);
            previousIndex = gTitleScene->mSelectedIndex;
            rectIndex = FindRectContainingPoint(pointX, pointY, gTitleScene->mTitleSBnbl);
            if (rectIndex != -1) {
                if (previousIndex == rectIndex) {
                    gTitleScene->mSelectedPressed = TRUE;
                }
                gTitleScene->mSelectedIndex = rectIndex;
                SetTitleState(4, 8);
                func_020acf04();
            }
        } else {
            s32 noInputFrameLimit = GetTitleNoInputFrameLimit();
            gTitleScene->mNoInputFrames++;
            if (gTitleScene->mNoInputFrames > noInputFrameLimit) {
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
u32 func_020acbf0(u32 value) {
    u32 value0 = value;
    u32 functionAddress;
    functionAddress = (u32) &func_020ad230;
    value0 = func_020ad230(value0);
    return value0;
}
#pragma thumb off

u32 func_020acbe8(Unk0201ea30 *p0) {
    return (*OFFSET_PTR(const u16, p0, 6));
}
