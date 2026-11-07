#include "code_0214a034.h"
#include "registers.h"

// Returns the address in the sub engine BG VRAM of the character base block set in the BG0 control register.
// Returns the sub engine BG VRAM address of the character base block set in BG0CNT.
u32 G2S_GetBG0CharPtr(void) {
    u32 control;

    control = reg_G2S_DB_BG0CNT;
    control &= 0x3c;
    control = (s32) control >> 2;
    return (control << 14) + 0x6200000;
}
