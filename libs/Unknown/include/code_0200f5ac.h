#pragma once

#include "types.h"

// Returns the 64-bit tick: gTickOverflowCount shifted left by 16 plus the timer 0 count (0x04000100); with interrupts
// off it adds one to the count part when IF bit 3 is set and the count's top bit is clear.
u64 OS_GetTick(void);
// Timer 0 interrupt handler: adds 1 to gTickOverflowCount; when the word at 0x02170230 is nonzero (nothing sets it in
// this build) restarts timer 0 and clears the word; registers itself again for timer slot 0.
void TickOverflowCallback(void);
// Returns gTickInitialized.
u32 OS_IsTickAvailable(void);
// Runs once: marks timer slot 0 (func_0200f580), clears gTickOverflowCount, stops timer 0, zeroes its count, starts
// it with control 0xc1, installs TickOverflowCallback for IRQ bit 3 and enables it, clears the word at 0x02170230.
void OS_InitTick(void);
