#include "01/code_02185438.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_02117000.h"
#include "Main/Unknown/code_020cc000.h"
#include "01/code_0218547c.h"
#include "code_02012b30.h"
#include "Main/Unknown/code_02021000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_02117418.h"

#pragma optimize_for_size on

void func_ov001_02185438(void) {
    switch (AdvanceSelectCupGrid()) {
        case 1:
            SwitchMenuScreen(0x1d, 0x1f);
            break;
        case 2:
            SwitchMenuScreen(6, 0x1f);
            break;
        case 3:
            SwitchMenuScreen(0, 0x1f);
            func_ov001_02185490(0);
            func_ov001_0218547c(1);
            break;
    }
}
