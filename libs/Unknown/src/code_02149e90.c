#include "code_02149e90.h"

// Returns the main engine BG VRAM address of the character base block set in BG2CNT,
// or 0 in mode 5 or 6 with the 256 color bit set.
u32 G2_GetBG2CharPtr(void) {
    s32 mode;
    u32 control;

    mode = *(vu32 *) 0x4000000 & 0x7;
    control = *(vu16 *) 0x400000c;
    if (mode < 5 || !(control & 0x80)) {
        return (((*(vu32 *) 0x4000000 & 0x7000000) >> 24) << 16) + 0x6000000 + (((control & 0x3c) >> 2) << 14);
    }
    return 0;
}

// Returns the sub engine BG VRAM address of the character base block set in BG2CNT,
// or 0 in mode 5 or 6 with the 256 color bit set.
u32 G2S_GetBG2CharPtr(void) {
    s32 mode;
    u32 control;

    mode = *(vu32 *) 0x4001000 & 0x7;
    control = *(vu16 *) 0x400100c;
    if (mode < 5 || !(control & 0x80)) {
        return (((control & 0x3c) >> 2) << 14) + 0x6200000;
    }
    return 0;
}

// Returns the main engine BG VRAM address of the character base block set in BG3CNT,
// or 0 when the mode is 6 or higher or in mode 3 to 5 with the 256 color bit set.
u32 G2_GetBG3CharPtr(void) {
    s32 mode;
    u32 control;

    mode = *(vu32 *) 0x4000000 & 0x7;
    control = *(vu16 *) 0x400000e;
    if (mode < 3 || (mode < 6 && !(control & 0x80))) {
        return (((*(vu32 *) 0x4000000 & 0x7000000) >> 24) << 16) + 0x6000000 + (((control & 0x3c) >> 2) << 14);
    }
    return 0;
}

// Returns the sub engine BG VRAM address of the character base block set in BG3CNT,
// or 0 when the mode is 6 or higher or in mode 3 to 5 with the 256 color bit set.
u32 G2S_GetBG3CharPtr(void) {
    s32 mode;
    u32 control;

    mode = *(vu32 *) 0x4001000 & 0x7;
    control = *(vu16 *) 0x400100e;
    if (mode < 3 || (mode < 6 && !(control & 0x80))) {
        return (((control & 0x3c) >> 2) << 14) + 0x6200000;
    }
    return 0;
}
