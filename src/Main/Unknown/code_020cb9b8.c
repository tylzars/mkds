#include "Main/Unknown/code_020cb9b8.h"
#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/code_020cb618.h"
#include "Main/Unknown/code_020cba30.h"
#include "Main/Unknown/code_020cbad0.h"
#include "Main/Unknown/code_020d0f78.h"
#include "Main/Unknown/code_0211e0c4.h"
#include "Main/Unknown/code_02125da0.h"
#include "Main/Unknown/code_0212abd0.h"
#include "Main/Unknown/code_02116ec0.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on
#pragma optimize_for_size on
void ReleaseMenu(void) {
    if (data_0217b43c->mScreenInitPending == FALSE) {
        data_0217b43c->mPreviousScreenNumber = data_0217b43c->mScreenNumber;
        data_0217b43c->mScreenNumber = 0x1f;
        ReleasePreviousMenuScreen();
    }
    if (func_020cbad0() == 0) {
        ClearCupPicturePointer();
        ClearGhostRecordSetPointer();
    }
    func_02125da0();
    func_0212abd0();
    ClearPicksHolderPointer();
    ReleaseAllResFiles();
    func_020cbabc(0);
    func_020cbaa8(0);
    func_020cba6c(0, 0x3f, 6, 10);
    func_020cba30(0, 0x3f, 6, 10);
    data_0217b43c = NULL;
}
