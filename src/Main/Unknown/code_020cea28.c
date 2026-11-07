#include "Main/Unknown/code_020cea28.h"
#include "Main/Unknown/code_02026000.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020ce744.h"
#include "gx.h"
#include "code_02148950.h"
#include "Main/Unknown/code_02025f80.h"

#pragma thumb on

void WriteVsSelectCharacterRegisters(void) {
    int screenChanged;
    screenChanged = func_020cccc0();
    if (screenChanged != 0) {
        GxDispCntBits8To12Write(0xb);
        GX_SetGraphicsMode(1, 0, 1);
        GxsDispCntBits8To12Write(8);
        GXS_SetGraphicsMode(0);
    }
    GxsDispCntBits8To12Write(0x12);
    func_02026058();
}

#pragma thumb off
