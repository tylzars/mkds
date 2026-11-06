#include "code_0214a2c0.h"

// Returns the main engine BG VRAM address of the screen base block set in BG1CNT.
u32 G2_GetBG1ScrPtr(void) {
    u32 control;
    u32 offset;

    control = *(vu16 *) 0x400000a;
    offset = (*(vu32 *) 0x4000000 & 0x38000000) >> 27;
    control &= 0x1f00;
    offset <<= 16;
    control = (s32) control >> 8;
    return offset + 0x6000000 + (control << 11);
}
