#include "code_0214a2a0.h"

// Returns the address in the sub engine BG VRAM of the screen base block set in the BG1 control register.
// Returns the sub engine BG VRAM address of the screen base block set in BG1CNT.
u32 G2S_GetBG1ScrPtr(void) {
    u32 control;

    control = *(vu16 *) 0x400100a;
    control &= 0x1f00;
    control = (s32) control >> 8;
    return (control << 11) + 0x6200000;
}
