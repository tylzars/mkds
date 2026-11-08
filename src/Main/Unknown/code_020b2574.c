#include "Main/Unknown/code_020b2574.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020b24e4.h"
#include "Main/Unknown/code_020b252c.h"
#include "Main/Unknown/code_020b29b0.h"
#include "Main/Unknown/code_020b29c4.h"
#include "Main/Unknown/code_020b2a4c.h"
#include "Main/Unknown/code_020b2a74.h"
#include "Main/Unknown/code_020b2b24.h"
#include "Main/Unknown/code_020b2b54.h"
#include "Main/Unknown/code_020b2b70.h"
#include "Main/Unknown/code_020b2c80.h"
#include "Main/Unknown/code_020b2e98.h"
#include "Main/Unknown/code_020b2ec0.h"
#include "Main/Unknown/code_020b2ecc.h"
#include "Main/Unknown/code_020b3278.h"
#include "Main/Unknown/code_020b32ec.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_020b1de4.h"

#pragma thumb on
#pragma optimize_for_size on
void UpdateChoisesS(void) {
    s32 a;

    gChoisesS->mPrevOpenDuringRace = gChoisesS->mOpenDuringRace;
    gChoisesS->mCycleFrames = gChoisesS->mCycleFrames + 1;
    if (gChoisesS->mCycleFrames >= 0x32) {
        gChoisesS->mCycleFrames = 0;
    }
    if (func_020b2bf0() != 0) {
        return;
    }
    if ((func_020b252c() == MODE_GRAND_PRIX || func_020b252c() == MODE_TIME_ATTACK) && func_020b24e4() == 2 &&
        func_0203c0bc() != 0) {
        return;
    }
    if (gChoisesS->mPickFrames == 0 && gChoisesS->mCloseFrames == 0 && IsChoisesSPickLocked() == 0) {
        if (func_020b2bc8() != 0) {
            if (func_020b2b70() != 0) {
                if (func_020b252c() == MODE_MISSION_RUN && func_020b2b5c() != 0 && func_020b2f58() != 0) {
                    if (func_020b2b24(func_020b2b54(), PAD_KEY_A) != 0 || func_020b2a74(func_020b2b54()) != 0) {
                        gChoisesS->mPickedValue = 10;
                        gChoisesS->mSelectedValue = gChoisesS->mPickedValue;
                        gChoisesS->mPickLocked = 1;
                        StartChoisesSSelectedValueSeq();
                    }
                } else if (func_020b252c() == MODE_MISSION_RUN && func_020b2ecc() != 0) {
                    if (func_020b2b24(func_020b2b54(), PAD_KEY_A) != 0 || func_020b2a74(func_020b2b54()) != 0) {
                        gChoisesS->mPickedValue = 6;
                        gChoisesS->mSelectedValue = gChoisesS->mPickedValue;
                        gChoisesS->mPickLocked = 1;
                        StartChoisesSSelectedValueSeq();
                        func_020b2a60(1);
                    }
                } else if (func_020b252c() == MODE_MISSION_RUN && func_020b2b5c() != 0) {
                    if (func_020b2b24(func_020b2b54(), PAD_KEY_A) != 0 || func_020b2a74(func_020b2b54()) != 0) {
                        gChoisesS->mPickedValue = 6;
                        gChoisesS->mSelectedValue = gChoisesS->mPickedValue;
                        gChoisesS->mPickLocked = 1;
                        StartChoisesSSelectedValueSeq();
                    }
                } else if (func_020b2b24(func_020b2b54(), 8) != 0) {
                    if (func_020b2e98() != 0) {
                        func_02105c4c();
                        gChoisesS->mCloseFrames = 1;
                    } else {
                        func_02105d70();
                        func_020b2f88(1);
                    }
                } else if (func_020b302c() != 0) {
                    gChoisesS->mPickFrames = 1;
                } else if (func_020b2b24(func_020b2b54(), PAD_KEY_A) != 0) {
                    if (func_020b2e98() != 0) {
                        if (gChoisesS->mSelectedValue == 0) {
                            func_02105c4c();
                        } else {
                            StartChoisesSSelectedValueSeq();
                        }
                        gChoisesS->mPickFrames = 1;
                        gChoisesS->mUnk_010 = TRUE;
                    } else {
                        func_02105d70();
                        func_020b2f88(1);
                    }
                } else if (func_020b2b24(func_020b2b54(), PAD_KEY_B) != 0) {
                    if (func_020b2e98() != 0) {
                        func_02105c4c();
                        gChoisesS->mCloseFrames = 1;
                    }
                } else if (GetNewOrRepeatBits(func_020b2b54(), PAD_KEY_UP) != 0) {
                    MoveChoisesSSelectedValue(-1);
                } else if (GetNewOrRepeatBits(func_020b2b54(), PAD_KEY_DOWN) != 0) {
                    MoveChoisesSSelectedValue(1);
                }
            }
        } else if (func_020b29c4() != 0) {
            if (func_020b2b24(func_020b2b54(), 8) != 0) {
                if (func_020b2e98() != 0) {
                    func_02105c4c();
                    gChoisesS->mCloseFrames = 1;
                } else {
                    func_02105d70();
                    func_020b2f88(1);
                }
            } else if (func_020b302c() != 0) {
                gChoisesS->mPickFrames = 1;
            } else if (func_020b2b24(func_020b2b54(), PAD_KEY_A) != 0) {
                if (func_020b2e98() != 0) {
                    if (gChoisesS->mSelectedValue == 0) {
                        func_02105c4c();
                    } else {
                        StartChoisesSSelectedValueSeq();
                    }
                    gChoisesS->mPickFrames = 1;
                    gChoisesS->mUnk_010 = TRUE;
                }
            } else if (func_020b2b24(func_020b2b54(), PAD_KEY_B) != 0) {
                if (func_020b2e98() != 0) {
                    func_02105c4c();
                    gChoisesS->mCloseFrames = 1;
                }
            } else if (GetNewOrRepeatBits(func_020b2b54(), PAD_KEY_UP) != 0) {
                MoveChoisesSSelectedValue(-1);
            } else if (GetNewOrRepeatBits(func_020b2b54(), PAD_KEY_DOWN) != 0) {
                MoveChoisesSSelectedValue(1);
            }
        }
    }
    a = gChoisesS->mPickFrames;
    if (a != 0) {
        gChoisesS->mPickFrames = a + 1;
        if (gChoisesS->mPickFrames > 0xf) {
            if (func_020b2bc8() != 0) {
                if (func_020b2e98() != 0) {
                    gChoisesS->mPickedValue = gChoisesS->mSelectedValue;
                    func_020b2f88(0);
                } else {
                    func_020b2f88(1);
                }
            } else if (func_020b2e98() != 0) {
                gChoisesS->mPickedValue = gChoisesS->mSelectedValue;
                func_020b2f88(0);
            }
            gChoisesS->mPickFrames = 0;
            gChoisesS->mUnk_010 = FALSE;
        }
    }
    a = gChoisesS->mCloseFrames;
    if (a != 0) {
        gChoisesS->mCloseFrames = a + 1;
        if (gChoisesS->mCloseFrames > 4) {
            if (func_020b2bc8() != 0) {
                if (func_020b2e98() != 0) {
                    func_020b2f88(0);
                } else {
                    func_020b2f88(1);
                }
            } else if (func_020b2e98() != 0) {
                func_020b2f88(0);
            }
            gChoisesS->mCloseFrames = 0;
        }
    }
    if (func_020b29b0() != 0 && func_020b252c() == 5 && func_020b2bc8() != 0) {
        gChoisesS->mAutoPickFrames = gChoisesS->mAutoPickFrames + 1;
        if (gChoisesS->mAutoPickFrames > 0x384) {
            gChoisesS->mPickedValue = GetCourseNumber() != 4 ? 2 : 7;
        }
    }
    if (GetChoisesSOpenDuringRace() != 0) {
        a = gChoisesS->mUnk_030;
        gChoisesS->mUnk_030 = a + 1;
        if (a >= 1) {
            gChoisesS->mUnk_02c = 2;
            gChoisesS->mUnk_030 = 1;
        }
    } else {
        gChoisesS->mUnk_02c = 0;
        gChoisesS->mUnk_030 = 0;
    }
}
#pragma thumb off
