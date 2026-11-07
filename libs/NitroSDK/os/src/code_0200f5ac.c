#include "code_0200f5ac.h"

#include "code_0200c914.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/unk_02170000.h"
#include "os_timer.h"
#include "registers.h"

u16 gTickInitialized;
u32 data_02170250;
volatile u64 gTickOverflowCount;

// Runs once: reserves timer 0, clears gTickOverflowCount, starts timer 0 and installs OSi_CountUpTick for its
// interrupt.
void OS_InitTick(void) {
    if (gTickInitialized != 0) {
        return;
    }
    gTickInitialized = 1;
    OSi_SetTimerReserved(0);
    gTickOverflowCount = 0;
    *(vu16 *) 0x4000102 = 0;
    *(vu16 *) 0x4000100 = 0;
    *(vu16 *) 0x4000102 = 0xc1;
    OS_SetIrqFunction(8, OSi_CountUpTick);
    OS_EnableIrqMask(8);
    data_02170250 = 0;
}

// Returns gTickInitialized.
u32 OS_IsTickAvailable(void) {
    return gTickInitialized;
}

// Timer 0 overflow handler: adds 1 to gTickOverflowCount and restarts timer 0 when data_02170250 asks for it.
void OSi_CountUpTick(void) {
    gTickOverflowCount++;
    if (data_02170250 != 0) {
        *(vu16 *) 0x4000102 = 0;
        *(vu16 *) 0x4000100 = 0;
        *(vu16 *) 0x4000102 = 0xc1;
        data_02170250 = 0;
    }
    OSi_EnterTimerCallback(0, OSi_CountUpTick, 0);
}

// Returns gTickOverflowCount shifted left by 16 plus the timer 0 count, adding 1 to the overflow count when an overflow
// is pending that the count does not yet include.
u64 OS_GetTick(void) {
    u32 enabled;
    volatile u16 count;
    volatile u64 overflows;

    enabled = OS_DisableInterrupts();
    count = *(vu16 *) 0x4000100;
    overflows = gTickOverflowCount & 0xffffffffffffULL;
    if ((reg_OS_IF & 8) && !(count & 0x8000)) {
        overflows++;
    }
    OS_RestoreInterrupts(enabled);
    return (overflows << 16) | count;
}
