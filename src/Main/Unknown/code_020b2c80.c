#include "Main/Unknown/code_020b2c80.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020b24e4.h"
#include "Main/Unknown/code_020b252c.h"
#include "Main/Unknown/code_020b2a4c.h"
#include "Main/Unknown/code_020b2d90.h"
#include "Main/Unknown/code_020b32ec.h"
#include "Main/Unknown/code_020b41e8.h"
#include "Main/Unknown/code_020c3000.h"
#include "Main/Unknown/code_020c3db4.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020b1de4.h"
#include "Main/Unknown/code_0203c5f8.h"

s32 func_020b2d54(void) {
    if (IsKartEnded((u16) GetEntryIndex()) != 0) {
        return gRaceProgress->mEntryEndKind;
    }
    return 6;
}

#pragma thumb on
#pragma optimize_for_size on
u32 func_020b2d04(void) {
    if (func_020b24e4() == 2 && GetRaceDone() == 0) {
        return 3;
    }
    if (GetRaceDone() != 0) {
        if (func_020b252c() == MODE_MISSION_RUN) {
            if (func_020b2d54() == 0) {
                return 2;
            }
            return 1;
        }
        if (func_020c3db4() != 0) {
            return 2;
        }
        return 1;
    }
    return 0;
}

void func_020b2c80(s32 a) {
    s32 n;
    s32 b;
    u16 *p;

    n = gChoisesS->mLists[func_020b2d04()].mValueCount;
    p = (u16 *) func_020b32f8();
    if (p != NULL) {
        if (gChoisesS->mUnk_010 == FALSE || gChoisesS->mUnk_014 >= 5) {
            b = 0xd - n * 2 + a * 4;
            if (gChoisesS->mUnk_034 < 0x1e) {
                func_020b4428(p, 2, b, 1, 1, 0x21);
                func_020b4428(p, 2, b + 1, 1, 1, 0x41);
            }
            func_020b44a4(p, 0, b - 1, 0x20, 4, 0xe);
        }
    }
}
#pragma thumb off
