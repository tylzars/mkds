#include "code_0214a314.h"

// Returns the main engine BG VRAM address of the screen base block set in BG0CNT.
u32 G2_GetBG0ScrPtr(void) {
    u32 control;
    u32 offset;

    control = *(vu16 *) 0x4000008;
    offset = (*(vu32 *) 0x4000000 & 0x38000000) >> 27;
    control &= 0x1f00;
    offset <<= 16;
    control = (s32) control >> 8;
    return offset + 0x6000000 + (control << 11);
}
