#include "code_0214a314.h"
#include "registers.h"

// Returns the main engine BG VRAM address of the screen base block set in BG0CNT.
u32 G2_GetBG0ScrPtr(void) {
    u32 control;
    u32 offset;

    control = reg_G2_BG0CNT;
    offset = (reg_GX_DISPCNT & 0x38000000) >> 27;
    control &= 0x1f00;
    offset <<= 16;
    control = (s32) control >> 8;
    return offset + 0x6000000 + (control << 11);
}
