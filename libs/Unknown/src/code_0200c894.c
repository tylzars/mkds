#include "code_0200c894.h"
#include "code_0200c914.h"
#include "code_0200db4c.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/code_02000000.h"
#include "Main/Unknown/code_0200c000.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_0214d000.h"

// Optionally clears the bits irqFlags of the IRQ check flag, then sleeps the thread until one of them is set.
void OS_WaitIrq(u32 clear, u32 irqFlags) {
    u32 enabled;
    Unk027e0000 *p;
    u32 *q;

    enabled = OS_DisableInterrupts();
    p = (Unk027e0000 *) 0x027e0000;
    if (clear != 0) {
        p->mUnk_3ff8 &= ~irqFlags;
    }
    OS_RestoreInterrupts(enabled);
    p = (Unk027e0000 *) 0x027e0000;
    if ((irqFlags & p->mUnk_3ff8) != 0) {
        return;
    }
    q = &p->mUnk_3ff8;
    do {
        OS_SleepThread(&data_027e0000.mUnk_0000);
    } while ((irqFlags & *q) == 0);
}
