#include "Main/Unknown/code_0202993c.h"
#include "Main/Unknown/code_02029a24.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/unk_02174000.h"

#pragma optimize_for_size on
#pragma thumb on
void func_0202993c(void) {
    s32 i;
    func_02029a38(data_02174e1c, 0x110);
    for (i = 0; i < 8; i++) {
        data_02174e1c->mUnk_00[i].mCharacterIndex = -1;
        data_02174e1c->mUnk_00[i].mKartIndex = -1;
        data_02174e1c->mUnk_00[i].mUnk_08 = 4;
        data_02174e1c->mUnk_00[i].mTeamIndex = -1;
        data_02174e1c->mUnk_00[i].mUnk_10 = 3;
    }
    data_02174e1c->mMissionTableRow = 1;
    data_02174e1c->mMissionTableColumn = 1;
    if (func_02029a24() == 0) {
        if (func_020299e4() == 0) {
            data_02174e1c->mMissionFile = FindSceneFile(data_usa_0216212c);
        } else {
            data_02174e1c->mMissionFile = NULL;
        }
        if (data_02174e1c->mMissionFile != NULL) {
            data_02174e1c->mMissionFileRows = (Unk02029930_f8 *) (data_02174e1c->mMissionFile + 8);
        } else {
            data_02174e1c->mMissionFileRows = NULL;
        }
    }
}
#pragma thumb off

u32 func_020299e4(void) {
    return func_020299f0();
}

u32 func_020299f0(void) {
    if (*func_02029a18() == 2) {
        return 1;
    }
    return 0;
}

u16 *func_02029a18(void) {
    return (u16 *) 0x27ffc40;
}
