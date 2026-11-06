#include "Main/Unknown/code_020ceb20.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020ceb54.h"
#include "01/code_0219c784.h"
#include "code_02148950.h"
#include "code_021488e8.h"

#pragma optimize_for_size on
#pragma thumb on
void func_020ceb20(void) {
    if (func_020cccc0() != 0) {
        GxDispCntBits8To12Write2(0x1e);
        GX_SetGraphicsMode(1, 0, 0);
        GxsDispCntBits8To12Write2(0x1f);
        GXS_SetGraphicsMode(0);
    }
    func_ov001_0219c784();
}
#pragma thumb off
