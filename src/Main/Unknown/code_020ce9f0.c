#include "Main/Unknown/code_020ce9f0.h"
#include "Main/Unknown/code_02025f80.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_02026000.h"

#pragma optimize_for_size on
#pragma thumb on
void UpdateVsSelectCharacter(void) {
    switch (AdvanceSelectCharacter()) {
        case 1:
            SwitchMenuScreen(9, 0x1f);
            break;
        case 2:
            SwitchMenuScreen(0, 0x1f);
            break;
        case 3:
            SwitchMenuScreen(0xa, 0x1f);
            break;
    }
}
#pragma thumb off
