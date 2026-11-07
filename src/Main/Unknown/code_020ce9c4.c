#include "Main/Unknown/code_020ce9c4.h"
#include "Main/Unknown/code_02027e78.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020ce744.h"
#include "code_02148950.h"

#pragma thumb on

void func_020ce9c4(void) {
    int v1;
    v1 = func_020cccc0();
    if (v1 != 0) {
        GxDispCntBits8To12Write(0xb);
        GX_SetGraphicsMode(1, 0, 1);
    }
    GxsDispCntBits8To12Write(0x12);
    WriteSelectKartRegisters();
}

#pragma thumb off
