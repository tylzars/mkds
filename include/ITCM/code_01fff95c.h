#pragma once

#include "types.h"
#include "Main/Unknown/code_020f36d8.h"

BOOL UpdateItemObject(ItemPool *a, ItemObject *p, s32 f);
// As StartDmaTransferAndChannel0Dummy but the interrupt state is not touched (the caller has interrupts disabled),
// and 0x40000b0 is read twice more at the end.
void StartDmaTransferAndChannel0DummyWithoutIrqDisable(u32 a, const void *b, void *c, u32 d);
// Writes the source, the destination and the control word to the three registers of the channel (0x40000b0 +
// channel * 12); the interrupt state is not touched (the callers have interrupts disabled).
void StartDmaTransferWithoutIrqDisable(u32 a, const void *b, void *c, u32 d);
// As StartDmaTransfer, then reads 0x40000b0 twice and, for channel 0, stores 0, 0 and 0x81400001 in the channel 0
// registers (the dummy transfer).
void StartDmaTransferAndChannel0Dummy(u32 a, const void *b, void *c, u32 d);
// Disables interrupts, writes the source, the destination and the control word to the three registers of the
// channel (0x40000b0 + channel * 12) and restores the interrupt state.
void StartDmaTransfer(u32 a, const void *b, void *c, u32 d);
