#include "Main/Unknown/code_020ce974.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020ce744.h"
#include "Main/Unknown/code_02119e14.h"
#include "gx.h"

#pragma thumb on

void WriteVsSelectRaceRuleRegisters(void) {
    int screenChanged;
    screenChanged = func_020cccc0();
    if (screenChanged != 0) {
        GxsDispCntBits8To12Write(0x1f);
        GXS_SetGraphicsMode(0);
    }
    WriteSelectRaceRuleRegisters();
}

#pragma thumb off
