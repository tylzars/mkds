#include "code_0214a5f0.h"
#include "code_0214c778.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0216f000.h"
#include "00/code_02188720.h"
#include "registers.h"

// Sets the clear color register from the color, alpha, polygon ID and fog bit, and the clear depth register.
void G3X_SetClearColor(u32 rgb, u32 alpha, u16 depth, u32 polygonID, s32 fog) {
    u32 value;

    value = rgb | (alpha << 16) | (polygonID << 24);
    if (fog != 0) {
        value |= 0x8000;
    }
    reg_G3X_CLEAR_COLOR = value;
    reg_G3X_CLEAR_DEPTH = depth;
}

// Zeroes the edge color table (16 bytes at 0x4000330) and the fog table (96 bytes at 0x4000360), by DMA when the
// first word of data_0216f074 is not -1 and by CPU otherwise, then writes 0 to the shininess command 32 times.
void G3X_InitTable(void) {
    volatile u32 zero0;
    volatile u32 zero1;
    s32 i;

    if (data_0216f074[0] != -1) {
        MI_DmaFill32Async(data_0216f074[0], (void *) 0x4000330, 0, 0x10, 0, 0);
        MI_DmaFill32(data_0216f074[0], (void *) 0x4000360, 0, 0x60);
    } else {
        zero0 = 0;
        MIi_CpuClear32(zero0, (void *) 0x4000330, 0x10);
        zero1 = 0;
        MIi_CpuClear32(zero1, (void *) 0x4000360, 0x60);
    }
    for (i = 0; i < 32; i++) {
        *(vu32 *) 0x40004d0 = 0;
    }
}

// Reads the position/vector matrix stack level (GXSTAT bits 8-12) into *level. Returns -1 while the stack is busy
// (GXSTAT bit 14 set).
s32 G3X_GetMtxStackLevelPV(s32 *level) {
    if (reg_G3X_GXSTAT & 0x4000) {
        return -1;
    }
    *level = (reg_G3X_GXSTAT & 0x1f00) >> 8;
    return 0;
}

// Reads the projection matrix stack level (GXSTAT bit 13) into *level. Returns -1 while the stack is busy
// (GXSTAT bit 14 set).
s32 G3X_GetMtxStackLevelPJ(s32 *level) {
    if (reg_G3X_GXSTAT & 0x4000) {
        return -1;
    }
    *level = (reg_G3X_GXSTAT & 0x2000) >> 13;
    return 0;
}
