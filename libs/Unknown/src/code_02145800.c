#include "code_0200fc8c.h"
#include "code_02145800.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/unk_0217f000.h"
#include "code_0200db4c.h"
#include "code_021458c4.h"

// Waits until bit 2 of mUnk_114 is clear; returns 1 when the word at mUnk_00 is 0.
int func_0214581c(void) {
    Unk021458c4 *p;
    u32 s;

    p = (Unk021458c4 *) (u32) &data_0217fa40;
    s = func_0200fca0();
    while (p->mUnk_114 & 4) {
        func_0200e01c(&p->mUnk_10c);
    }
    func_0200fcb4(s);
    return p->mUnk_00->mUnk_00 == 0;
}

// Returns 1 when bit 2 of mUnk_114 is clear.
int func_02145800(void) {
    return (data_0217fa40.mUnk_114 & 4) == 0;
}
