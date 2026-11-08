#include "Main/Unknown/code_020ca520.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/unk_0217b000.h"

void ClearRaceHudSubScreenCrabCells(void) {
    u32 address;
    u32 unusedValue;
    address = (u32) &gRaceHudSubScreenCrabCells;
    ClearRaceHudSubScreenCells((RaceHudSubScreenCells **) address);
}
