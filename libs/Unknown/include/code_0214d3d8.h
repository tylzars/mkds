#pragma once

#include "types.h"

// Calls MIi_CheckAnotherAutoDMA(channel, 0xffffffff) and MIi_CheckDma0SourceAddress(channel, source,
// length, 0x1000000), returns when the length is 0, otherwise waits until bit 31 of the control word of the channel is
// clear and starts the transfer with control 0xaf000001 (start-timing bits 5, repeat, 32-bit, fixed source, count 1).
// The only caller passes the card data register 0x04100010 as the source and 0x200 as the length and starts the card
// read command right after.
void StartCardDmaCopy(u32 a, const void *b, void *c, u32 d);
