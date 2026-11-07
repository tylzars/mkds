#include "Main/Unknown/code_020ce8d0.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020ce744.h"
#include "Main/Unknown/code_020ce778.h"
#include "Main/Unknown/code_021173e4.h"
#include "gx.h"
#include "code_02148950.h"

#pragma thumb on

void WriteVsSelectCupGridRegisters(void) {
    int flag;
    flag = func_020cccc0();
    if (flag != 0) {
        flag = func_020ce778();
        if (flag == 0) {
            GxDispCntBits8To12Write(0x19);
            GX_SetGraphicsMode(1, 0, 0);
            GxsDispCntBits8To12Write(0x16);
            GXS_SetGraphicsMode(0);
        } else {
            GxDispCntBits8To12Write(0x18);
            GX_SetGraphicsMode(1, 0, 0);
            GxsDispCntBits8To12Write(0x12);
            GXS_SetGraphicsMode(0);
        }
    }
    WriteSelectCupGridRegisters();
}

#pragma thumb off
