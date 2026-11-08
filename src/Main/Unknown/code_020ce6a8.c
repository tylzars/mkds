#include "Main/Unknown/code_020ce6a8.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_0211e4e8.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma optimize_for_size on
#pragma thumb on
void UpdateVsSelectCupM(void) {
    switch (AdvanceSelectCupM()) {
        case 1:
            SwitchMenuScreen(0xd, 0x1f);
            break;
        case 2:
            SwitchMenuScreen(0xb, 0x1f);
            break;
    }
}
#pragma thumb off

s32 CreateRaceHudSubScreenRainStarCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenRainStarCells, 0x154);
}
