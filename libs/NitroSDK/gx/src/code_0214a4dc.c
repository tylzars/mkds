#include "code_0214a4dc.h"
#include "registers.h"
#include "code_0214c728.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0214c000.h"
#include "Main/Unknown/code_0214d000.h"

// Sends the load 4x4 matrix command and the 16 words of mtx to the geometry FIFO.
void G3_LoadMtx44(const void *mtx) {
    reg_G3X_GXFIFO = 0x16;
    GX_SendFifo64B(mtx, (void *) &reg_G3X_GXFIFO);
}

// Sends the load 4x3 matrix command and the 12 words of mtx to the geometry FIFO.
void G3_LoadMtx43(const void *mtx) {
    reg_G3X_GXFIFO = 0x17;
    GX_SendFifo48B(mtx, (void *) &reg_G3X_GXFIFO);
}

// Sends the multiply by 4x3 matrix command and the 12 words of mtx to the geometry FIFO.
void G3_MultMtx43(const void *mtx) {
    reg_G3X_GXFIFO = 0x19;
    GX_SendFifo48B(mtx, (void *) &reg_G3X_GXFIFO);
}

// Sends the multiply by 3x3 matrix command and the 9 words of mtx to the geometry FIFO.
void G3_MultMtx33(const void *mtx) {
    reg_G3X_GXFIFO = 0x1a;
    MI_Copy36B(mtx, (void *) &reg_G3X_GXFIFO);
}
