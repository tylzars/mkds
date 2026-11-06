#include "code_0214a4dc.h"
#include "code_0214c728.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0214c000.h"
#include "Main/Unknown/code_0214d000.h"

void GxFifoWrite0x16Then16Words(const void *a) {
    *(vu32 *) 0x4000400 = 0x16;
    GX_SendFifo64B(a, (void *) 0x4000400);
}

void GxFifoWrite0x17Then12Words(const void *a) {
    *(vu32 *) 0x4000400 = 0x17;
    GX_SendFifo48B(a, (void *) 0x4000400);
}

void GxFifoWrite0x19Then12Words(const void *a) {
    *(vu32 *) 0x4000400 = 0x19;
    GX_SendFifo48B(a, (void *) 0x4000400);
}

void GxFifoWrite0x1aThenMemCopy9Words(const void *a) {
    *(vu32 *) 0x4000400 = 0x1a;
    MI_Copy36B(a, (void *) 0x4000400);
}
