#include "Main/Unknown/code_020cec24.h"
#include "Main/Unknown/code_02025f80.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_02026000.h"

#pragma optimize_for_size on
#pragma thumb on
void UpdateBattleSelectCharacter(void) {
    switch (AdvanceSelectCharacter()) {
        case 1:
        case 3:
            SwitchMenuScreen(0x10, 0x1f);
            break;
        case 2:
            SwitchMenuScreen(0xe, 0x1f);
            break;
    }
}
#pragma thumb off
