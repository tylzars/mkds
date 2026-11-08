#include "Main/Unknown/code_020ce7e4.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020ce744.h"
#include "Main/Unknown/code_020ce778.h"
#include "Main/Unknown/code_021189f4.h"
#include "gx.h"
#include "code_02148950.h"

#pragma thumb on

void WriteVsSelectCupCourseRegisters(void) {
    int flag;
    flag = func_020cccc0();
    if (flag != 0) {
        flag = func_020ce778();
        if (flag == 0) {
            GxDispCntBits8To12Write(0x19);
            GX_SetGraphicsMode(1, 0, 0);
            GxsDispCntBits8To12Write(0x1e);
            GXS_SetGraphicsMode(0);
        } else {
            GxDispCntBits8To12Write(0x1c);
            GX_SetGraphicsMode(1, 0, 0);
            GxsDispCntBits8To12Write(0x12);
            GXS_SetGraphicsMode(0);
        }
    }
    WriteSelectCupCourseBgOffsets();
}

#pragma thumb off
