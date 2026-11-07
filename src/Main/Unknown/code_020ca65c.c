#include "Main/Unknown/code_020ca65c.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/unk_0217b000.h"

void ClearRaceHudSubScreenShine16Cells(void) {
    u32 address;
    u32 value12;
    address = (u32) &gRaceHudSubScreenShine16Cells;
    ClearRaceHudSubScreenCells((RaceHudSubScreenCells **) address);
}
