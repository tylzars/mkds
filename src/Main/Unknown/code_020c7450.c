#include "Main/Unknown/code_020c7450.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/unk_0217b000.h"

void ClearRaceHudSubScreenItemBoxCells(void) {
    u32 value0;
    u32 value12;
    value0 = (u32) &gRaceHudSubScreenItemBoxCells;
    ClearRaceHudSubScreenCells((RaceHudSubScreenCells **) value0);
}
