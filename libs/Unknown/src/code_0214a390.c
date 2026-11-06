#include "code_0214a390.h"

// Writes a 2x2 BG affine matrix (fixed point 12, stored as 8.8) and the transformed start position of the BG to the
// four words at reg.
void G2x_SetBGyAffine_(u32 *reg, const s32 *mtx, s32 centerX, s32 centerY, s32 x1, s32 y1) {
    s32 affineX;
    s32 y2;

    reg[0] = (u16) (s16) (mtx[0] >> 4) | ((u16) (s16) (mtx[1] >> 4) << 16);
    reg[1] = (u16) (s16) (mtx[2] >> 4) | ((u16) (s16) (mtx[3] >> 4) << 16);
    affineX = mtx[0] * (x1 - centerX) + mtx[1] * (y1 - centerY) + (centerX << 12);
    y2 = mtx[2] * (x1 - centerX) + mtx[3] * (y1 - centerY) + (centerY << 12);
    reg[2] = affineX >> 4;
    reg[3] = y2 >> 4;
}

// Writes the alpha blend control word: the first and second target planes, then the two blend coefficients.
void G2x_SetBlendAlpha_(u32 *reg, u32 plane1, int plane2, u32 ev1, int ev2) {
    *reg = (plane1 | 0x40 | (plane2 << 8)) | ((ev1 | (ev2 << 8)) << 16);
}

// Writes the brightness effect for the target planes in plane: increase for a positive brightness, decrease for a
// negative one, with the amount as its absolute value.
void G2x_SetBlendBrightness_(u16 *reg, u32 plane, s32 brightness) {
    if (brightness < 0) {
        reg[0] = plane | 0xc0;
        reg[2] = -brightness;
    } else {
        reg[0] = plane | 0x80;
        reg[2] = brightness;
    }
}

// As G2x_SetBlendBrightness_, with a second target plane and the two blend coefficients written as well.
void G2x_SetBlendBrightnessExt_(u16 *reg, u32 plane1, u32 plane2, u32 ev1, u32 ev2, s32 brightness) {
    reg[1] = ev1 | (ev2 << 8);
    if (brightness < 0) {
        reg[0] = plane1 | 0xc0 | (plane2 << 8);
        reg[2] = -brightness;
    } else {
        reg[0] = plane1 | 0x80 | (plane2 << 8);
        reg[2] = brightness;
    }
}
