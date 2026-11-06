#pragma once

#include "types.h"

typedef struct CARDiCommon CARDiCommon;

// The enable flag: CARD_Enable stores it, CARD_IsEnabled returns it.
extern u8 gAccessEnabled[];
// The 0x620-byte card state.
extern CARDiCommon gAccessState;
