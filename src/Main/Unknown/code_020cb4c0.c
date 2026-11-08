#include "Main/Unknown/code_020cb4c0.h"
#include "Main/Unknown/code_0204984c.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/code_020cae54.h"
#include "Main/Unknown/code_020cb600.h"
#include "Main/Unknown/code_020cb618.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_0212a000.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02049000.h"
#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/code_02054000.h"
#include "Main/Unknown/code_0212a920.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on
#pragma optimize_for_size on
void UpdateMenuScreen(u32 a) {
    MenuScene *menu;
    enum { K0 } screenNumber;

    if (func_02049b6c() == 0) {
        if (func_020cae54() == 1 || func_020cae54() == 2) {
            if (data_0217b43c->mUnk_958 == FALSE) {
                if (StartDataSharingSync() != 1) {
                    return;
                }
                data_0217b43c->mUnk_958 = TRUE;
            }
            if (data_0217b43c->mUnk_95c == FALSE) {
                if (FinishDataSharingSync() != 1) {
                    return;
                }
                data_0217b43c->mUnk_95c = TRUE;
            }
        }
        func_020ae6ac(data_0217b43c->mMainOam, data_0217b43c->mSubOam);
        if (data_0217b43c->mScreenInitPending != FALSE) {
            data_0217b43c->mScreenInitPending = FALSE;
            InitCurrentMenuScreen();
            menu = data_0217b43c;
            screenNumber = menu->mScreenNumber;
            menu->mScreenCallbacks[screenNumber].mUpdate(a);
        } else {
            menu = data_0217b43c;
            screenNumber = menu->mScreenNumber;
            menu->mScreenCallbacks[screenNumber].mUpdate(a);
            if (data_0217b43c->mUnk_004 != 0) {
                ReleasePreviousMenuScreen();
                InitCurrentMenuScreen();
            }
        }
        func_02125928();
        AdvanceLinkLevelIcons();
        if (AreBrightnessFadesClear() != 0) {
            func_020cb600(&data_0217b43c->mFramesSinceScreenSwitch);
        }
    }
}

void func_020cb4c0(void) {
    if (func_02049b6c() == 0) {
        if (func_020cae54() == 1 || func_020cae54() == 2) {
            if (data_0217b43c->mUnk_958 == FALSE || data_0217b43c->mUnk_95c == FALSE) {
                return;
            }
        }
        func_020ae630(data_0217b43c->mMainOam, data_0217b43c->mSubOam);
    }
}
