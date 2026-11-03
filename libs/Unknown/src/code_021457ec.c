#include "code_021457ec.h"

#include "Main/Unknown/unk_0217f000.h"
#include "code_0200fc8c.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200db4c.h"
#include "code_021458c4.h"
#include "code_0200fd1c.h"
#include "Main/Unknown/code_02145888.h"
#include "Main/Unknown/code_021458b4.h"

u8 data_0217f9e0[0x20];

u32 func_021458b4(void) {
    u32 value0;
    value0 = (u32) &data_0217f9e0;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    return value0;
}

void func_02145888(void) {
    u32 value0;
    u32 compareLeft0;
    u32 compareRight0;
    value0 = (u32) func_021458b4();
    compareLeft0 = value0;
    compareRight0 = 0u;
    if (compareLeft0 != compareRight0) {
    }
    if (compareLeft0 != compareRight0) {
    }
    if (compareLeft0 != compareRight0) {
        return;
    }
    func_0200fd1c();
}

void func_02145878(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    value1 = (u32) &data_0217f9e0;
    *(u32 *) ((value1) + (0)) = value0;
}

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

u32 func_021457ec(void) {
    u32 value0;
    value0 = (u32) &data_0217fa40;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    value0 = (u32) * (const u32 *) ((value0) + (0));
    return value0;
}
