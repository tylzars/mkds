#include "mi_dma_card.h"
#include "code_0214c778.h"
#include "ITCM/code_01fff000.h"
#include "ITCM/code_01fff95c.h"

// Starts a 32-bit card DMA transfer of size bytes from src to dest on channel dmaNo; the source address stays fixed.
void MIi_CardDmaCopy32(u32 dmaNo, const void *src, void *dest, u32 size) {
    MIi_CheckAnotherAutoDMA(dmaNo, -1);
    MIi_CheckDma0SourceAddress(dmaNo, src, size, 0x1000000);
    if (size == 0) {
        return;
    }
    while (*(vu32 *) (0x40000b0 + (dmaNo * 3 + 2) * 4) & 0x80000000) {
    }
    StartDmaTransfer(dmaNo, src, dest, 0xaf000001);
}
