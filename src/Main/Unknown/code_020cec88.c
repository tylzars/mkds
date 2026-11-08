#include "Main/Unknown/code_020cec88.h"
#include "Main/Unknown/code_0203206c.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_02032000.h"

#pragma optimize_for_size on
#pragma thumb on
void UpdateSelectGame(void) {
    switch (AdvanceSelectGame()) {
        case 1:
            switch (GetRaceSetupCopy()->mMode) {
                case 3:
                    SwitchMenuScreen(8, 0x1f);
                    break;
                case 2:
                    SwitchMenuScreen(0xf, 0x1f);
                    break;
            }
            break;
        case 2:
            SwitchMenuScreen(0, 0x1f);
            break;
        case 3:
            SwitchMenuScreen(0x1b, 0x1f);
            break;
    }
}
#pragma thumb off
