#include "code_0214a4dc.h"
#include "code_0214c728.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0214c000.h"
#include "Main/Unknown/code_0214d000.h"

void GxFifoWrite0x16Then16Words(const void *a) {
    *(vu32 *) 0x4000400 = 0x16;
    func_0214c74c(a, (void *) 0x4000400);
}

void GxFifoWrite0x17Then12Words(const void *a) {
    *(vu32 *) 0x4000400 = 0x17;
    func_0214c728(a, (void *) 0x4000400);
}

void GxFifoWrite0x19Then12Words(const void *a) {
    *(vu32 *) 0x4000400 = 0x19;
    func_0214c728(a, (void *) 0x4000400);
}

void GxFifoWrite0x1aThenMemCopy9Words(const void *a) {
    *(vu32 *) 0x4000400 = 0x1a;
    MemCopy9Words(a, (void *) 0x4000400);
}
