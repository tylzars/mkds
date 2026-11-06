#pragma once

#include "types.h"

// Sends the word on tag 14; while the send is not accepted calls WaitByLoop with the second argument and sends again.
void SendTag14WordUntilAccepted(u32 a, s32 b);
// When bit 15 of the halfword at 0x027fffa8 is set, calls PM_ForceToPowerOff. Then calls SendTag14WordUntilAccepted(1,
// 1) and OS_Terminate.
void CARD_TerminateForPulledOut(void);
