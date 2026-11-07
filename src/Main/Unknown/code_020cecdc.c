#include "Main/Unknown/code_020cecdc.h"
#include "Main/Unknown/code_0203206c.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020ceb54.h"
#include "gx.h"
#include "code_02148950.h"

#pragma thumb on

void WriteSelectGameRegisters(void) {
    int screenChanged;
    screenChanged = func_020cccc0();
    if (screenChanged != 0) {
        GxDispCntBits8To12Write2(0x18);
        GX_SetGraphicsMode(1, 0, 0);
        GxsDispCntBits8To12Write2(0x12);
        GXS_SetGraphicsMode(0);
    }
    func_02032138();
}

#pragma thumb off
