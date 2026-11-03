#include "code_0200c894.h"
#include "code_0200c914.h"
#include "code_0200db4c.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/code_02000000.h"
#include "Main/Unknown/code_0200c000.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_0214d000.h"

void func_0200c894(u32 a, u32 b) {
    u32 s;
    Unk027e0000 *p;
    u32 *q;

    s = func_0200fca0();
    p = (Unk027e0000 *) 0x027e0000;
    if (a != 0) {
        p->mUnk_3ff8 &= ~b;
    }
    func_0200fcb4(s);
    p = (Unk027e0000 *) 0x027e0000;
    if ((b & p->mUnk_3ff8) != 0) {
        return;
    }
    q = &p->mUnk_3ff8;
    do {
        func_0200e01c(&data_027e0000.mUnk_0000);
    } while ((b & *q) == 0);
}
