#pragma once

#include "types.h"

// Returns gRemovalSeen.
u32 CARD_IsPulledOut(void);
// Stores the hook that ReceiveRemovalMessage calls.
void CARD_SetPulledOutCallback(void *arg0);
// Tag 14 callback. When the low 6 bits of the second argument are 17, sets gRemovalSeen to 1, calls the hook in
// gRemovalCallback when set, and calls CARD_TerminateForPulledOut when there is no hook or the hook returns non-zero.
// For any other value calls OS_Terminate.
void ReceiveRemovalMessage(u32 a, u32 b);
// Calls PxiInit, installs ReceiveRemovalMessage as the tag 14 callback and clears gRemovalCallback.
void CARD_InitPulledOutCallback(void);
