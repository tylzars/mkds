#include "code_0214a054.h"
#include "registers.h"

// Returns the main engine BG VRAM address of the screen base block set in BG2CNT.
u32 G2_GetBG2ScrPtr(void) {
    u32 mode;
    u32 control;
    u32 offset;
    u32 block;

    mode = reg_GX_DISPCNT & 0x7;
    control = reg_G2_BG2CNT;
    offset = ((reg_GX_DISPCNT & 0x38000000) >> 27) << 16;
    block = (control & 0x1f00) >> 8;
    switch (mode) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            return offset + 0x6000000 + (block << 11);
        case 5:
            if (control & 0x80) {
                return (block << 14) + 0x6000000;
            }
            return offset + 0x6000000 + (block << 11);
        case 6:
            return 0x6000000;
    }
    return 0;
}

// Returns the sub engine BG VRAM address of the screen base block set in BG2CNT.
u32 G2S_GetBG2ScrPtr(void) {
    u32 mode;
    u32 control;
    u32 block;

    mode = reg_GXS_DB_DISPCNT & 0x7;
    control = reg_G2S_DB_BG2CNT;
    block = (control & 0x1f00) >> 8;
    switch (mode) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
            return (block << 11) + 0x6200000;
        case 5:
            if (control & 0x80) {
                return (block << 14) + 0x6200000;
            }
            return (block << 11) + 0x6200000;
        case 6:
            return 0;
    }
    return 0;
}

// Returns the main engine BG VRAM address of the screen base block set in BG3CNT.
u32 G2_GetBG3ScrPtr(void) {
    u32 mode;
    u32 control;
    u32 offset;
    u32 block;

    mode = reg_GX_DISPCNT & 0x7;
    control = reg_G2_BG3CNT;
    offset = ((reg_GX_DISPCNT & 0x38000000) >> 27) << 16;
    block = (control & 0x1f00) >> 8;
    switch (mode) {
        case 0:
        case 1:
        case 2:
            return offset + 0x6000000 + (block << 11);
        case 3:
        case 4:
        case 5:
            if (control & 0x80) {
                return (block << 14) + 0x6000000;
            }
            return offset + 0x6000000 + (block << 11);
        case 6:
            return 0;
    }
    return 0;
}

// Returns the sub engine BG VRAM address of the screen base block set in BG3CNT.
u32 G2S_GetBG3ScrPtr(void) {
    u32 mode;
    u32 control;
    u32 block;

    mode = reg_GXS_DB_DISPCNT & 0x7;
    control = reg_G2S_DB_BG3CNT;
    block = (control & 0x1f00) >> 8;
    switch (mode) {
        case 0:
        case 1:
        case 2:
            return (block << 11) + 0x6200000;
        case 3:
        case 4:
        case 5:
            if (control & 0x80) {
                return (block << 14) + 0x6200000;
            }
            return (block << 11) + 0x6200000;
        case 6:
            return 0;
    }
    return 0;
}

// Returns the main engine BG VRAM address of the character base block set in BG0CNT.
u32 G2_GetBG0CharPtr(void) {
    u32 control;
    u32 offset;

    control = reg_G2_BG0CNT;
    offset = (reg_GX_DISPCNT & 0x7000000) >> 24;
    control &= 0x3c;
    offset <<= 16;
    control = (s32) control >> 2;
    return offset + 0x6000000 + (control << 14);
}
