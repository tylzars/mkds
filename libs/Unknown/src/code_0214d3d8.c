#include "code_0214d3d8.h"
#include "code_0214c778.h"
#include "ITCM/code_01fff000.h"
#include "ITCM/code_01fff95c.h"

void StartCardDmaCopy(u32 a, const void *b, void *c, u32 d) {
    MIi_CheckAnotherAutoDMA(a, -1);
    MIi_CheckDma0SourceAddress(a, b, d, 0x1000000);
    if (d == 0) {
        return;
    }
    while (*(vu32 *) (0x40000b0 + (a * 3 + 2) * 4) & 0x80000000) {
    }
    StartDmaTransfer(a, b, c, 0xaf000001);
}
