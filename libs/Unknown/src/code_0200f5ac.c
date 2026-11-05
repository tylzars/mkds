#include "code_0200f5ac.h"

#include "code_0200c914.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/unk_02170000.h"
#include "code_0200f580.h"

u16 gTickInitialized;
u32 data_02170250;
volatile u64 gTickOverflowCount;

void OS_InitTick(void) {
    if (gTickInitialized != 0) {
        return;
    }
    gTickInitialized = 1;
    func_0200f580(0);
    gTickOverflowCount = 0;
    *(vu16 *) 0x4000102 = 0;
    *(vu16 *) 0x4000100 = 0;
    *(vu16 *) 0x4000102 = 0xc1;
    InterruptHandlerSet(8, TickOverflowCallback);
    InterruptEnableSetBits(8);
    data_02170250 = 0;
}

u32 OS_IsTickAvailable(void) {
    u32 value0;
    value0 = (u32) &gTickInitialized;
    value0 = (u32) * (const u16 *) ((value0) + (0));
    return value0;
}

void TickOverflowCallback(void) {
    gTickOverflowCount++;
    if (data_02170250 != 0) {
        *(vu16 *) 0x4000102 = 0;
        *(vu16 *) 0x4000100 = 0;
        *(vu16 *) 0x4000102 = 0xc1;
        data_02170250 = 0;
    }
    SetTimerOverflowCallback(0, TickOverflowCallback, 0);
}

u64 OS_GetTick(void) {
    u32 s;
    volatile u16 t;
    volatile u64 v;

    s = IrqDisable();
    t = *(vu16 *) 0x4000100;
    v = gTickOverflowCount & 0xffffffffffffULL;
    if ((*(vu32 *) 0x4000214 & 8) && !(t & 0x8000)) {
        v++;
    }
    IrqRestore(s);
    return (v << 16) | t;
}
