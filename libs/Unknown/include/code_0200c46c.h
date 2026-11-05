#pragma once

#include "types.h"

// Calls PxiSendFifoWord(13, a, 0) and, while it returns nonzero, WaitByLoop(1) and the call again.
void SendTag13WordUntilAccepted(u32 a);
