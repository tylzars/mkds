#include "code_0200c894.h"
#include "code_0200c914.h"
#include "code_0200db4c.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/code_02000000.h"
#include "Main/Unknown/code_0200c000.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_0214d000.h"

void InterruptClearAndWait(u32 a, u32 b) {
    u32 s;
    Unk027e0000 *p;
    u32 *q;

    s = OS_DisableInterrupts();
    p = (Unk027e0000 *) 0x027e0000;
    if (a != 0) {
        p->mUnk_3ff8 &= ~b;
    }
    OS_RestoreInterrupts(s);
    p = (Unk027e0000 *) 0x027e0000;
    if ((b & p->mUnk_3ff8) != 0) {
        return;
    }
    q = &p->mUnk_3ff8;
    do {
        OS_SleepThread(&data_027e0000.mUnk_0000);
    } while ((b & *q) == 0);
}
