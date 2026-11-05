#pragma once

#include "types.h"

typedef struct Unk021458c4 Unk021458c4;

// The enable flag: CARD_Enable stores it, CARD_IsEnabled returns it.
extern u8 gAccessEnabled[];
// The 0x620-byte state: the block pointer at +0, lock owner, count and target at +8, +0xc, +0x18, wait queues at
// +0x10 and +0x10c, the request words at +0x1c to +0x3c, the task at +0x40, the worker thread at +0x44, the flag word
// at +0x114, the transfer buffer at +0x120 and the worker stack at +0x220.
extern Unk021458c4 gAccessState;
