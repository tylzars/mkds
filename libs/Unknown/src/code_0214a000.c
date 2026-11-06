#include "code_0214a000.h"
#include "registers.h"

// Returns the main engine BG VRAM address of the character base block set in BG1CNT.
u32 G2_GetBG1CharPtr(void) {
    u32 control;
    u32 offset;

    control = reg_G2_BG1CNT;
    offset = (reg_GX_DISPCNT & 0x7000000) >> 24;
    control &= 0x3c;
    offset <<= 16;
    control = (s32) control >> 2;
    return offset + 0x6000000 + (control << 14);
}
