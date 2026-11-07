#include "code_021488e8.h"
#include "registers.h"

// Sets the background mode of the sub screen (DISPCNT bits 0-2).
void GXS_SetGraphicsMode(u32 bgMode) {
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x7) | bgMode;
}

// Writes the master brightness register: 0 for no change, 0x4000 | brightness to brighten, 0x8000 | -brightness to
// darken.
void GXx_SetMasterBrightness_(vu16 *reg, s32 brightness) {
    if (brightness == 0) {
        *reg = 0;
        return;
    }
    if (brightness > 0) {
        *reg = brightness | 0x4000;
    } else {
        *reg = -brightness | 0x8000;
    }
}

// Does nothing.
void func_02148904(void) {}

// Multiplies two 20.12 fixed-point values, rounding to nearest.
s32 FX_MulFunc(s32 v1, s32 v2) {
    return ((s64) v1 * v2 + 0x800) >> 12;
}
