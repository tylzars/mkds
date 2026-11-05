#include "code_0214a5f0.h"
#include "code_0214c778.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0216f000.h"
#include "00/code_02188720.h"

void ClearColorDepthWrite(u32 a, u32 b, u16 c, u32 d, s32 e) {
    u32 v;

    v = a | (b << 16) | (d << 24);
    if (e != 0) {
        v |= 0x8000;
    }
    *(vu32 *) 0x4000350 = v;
    *(vu16 *) 0x4000354 = c;
}

void G3X_InitTable(void) {
    volatile u32 a;
    volatile u32 b;
    s32 i;

    if (data_0216f074[0] != -1) {
        MI_DmaFill32Async(data_0216f074[0], (void *) 0x4000330, 0, 0x10, 0, 0);
        MI_DmaFill32(data_0216f074[0], (void *) 0x4000360, 0, 0x60);
    } else {
        a = 0;
        MemFillWords(a, (void *) 0x4000330, 0x10);
        b = 0;
        MemFillWords(b, (void *) 0x4000360, 0x60);
    }
    for (i = 0; i < 32; i++) {
        *(vu32 *) 0x40004d0 = 0;
    }
}

s32 GxStatTryReadBits8To12(u32 *a) {
    if (*(vu32 *) 0x4000600 & 0x4000) {
        return -1;
    }
    *a = (*(vu32 *) 0x4000600 & 0x1f00) >> 8;
    return 0;
}

s32 GxStatTryReadBit13(u32 *a) {
    if (*(vu32 *) 0x4000600 & 0x4000) {
        return -1;
    }
    *a = (*(vu32 *) 0x4000600 & 0x2000) >> 13;
    return 0;
}
