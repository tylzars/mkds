#pragma once

#include "types.h"

// Copies size bytes from src to dest by DMA channel dmaNo, waiting for the channel to be free first. The only caller
// passes the card data register 0x04100010 as src and 0x200 as size and starts the card read command right after.
void MIi_CardDmaCopy32(u32 dmaNo, const void *src, void *dest, u32 size);
