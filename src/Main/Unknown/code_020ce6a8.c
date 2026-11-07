#include "Main/Unknown/code_020ce6a8.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_0211e4e8.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma optimize_for_size on
#pragma thumb on
void func_020ce6c0(void) {
    switch (AdvanceSelectCupM()) {
        case 1:
            func_020ccc74(0xd, 0x1f);
            break;
        case 2:
            func_020ccc74(0xb, 0x1f);
            break;
    }
}
#pragma thumb off

s32 CreateRaceHudSubScreenRainStarCells(void) {
    return CreateRaceHudSubScreenCells(&gRaceHudSubScreenRainStarCells, 0x154);
}
