#include "Main/Unknown/code_020cecdc.h"
#include "Main/Unknown/code_0203206c.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020ceb54.h"
#include "code_021488e8.h"
#include "code_02148950.h"

#pragma thumb on

void func_020cecdc(void) {
    int v1;
    v1 = func_020cccc0();
    if (v1 != 0) {
        GxDispCntBits8To12Write2(0x18);
        GX_SetGraphicsMode((u16) 1, (u32) 0, 0);
        GxsDispCntBits8To12Write2(0x12);
        GxsDispCntBits0To2Write((u32) 0);
    }
    func_02032138();
}

#pragma thumb off
