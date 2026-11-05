#include "Main/Unknown/code_02027e78.h"

#include "Main/Unknown/code_0202b000.h"
#include "Main/Unknown/unk_02174000.h"
#include "registers.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_021281fc.h"
#include "Main/Unknown/code_0212b1a8.h"
#include "Main/Unknown/code_0214a000.h"
#include "Main/Unknown/code_02028000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_0211f498.h"
#include "Main/Unknown/code_02128000.h"
#include "Main/Unknown/code_0212b000.h"
#include "code_0214a390.h"
#include "Main/Unknown/code_0202b604.h"

u32 func_0202811c(void) {
    return ((u32) data_021759d0->mUnk_20);
}

u16 *func_02028110(void) {
    return (u16 *) 0x27ffc40;
}

u32 func_020280e8(void) {
    if (*func_02028110() == 2) {
        return 1;
    }
    return 0;
}

u32 func_020280dc(void) {
    return func_020280e8();
}

#pragma thumb on

void ReleaseSelectKart(void) {
    int v1;
    if ((gSelectKart->mResult == 1) && (v1 = ((u32) func_0202811c()), v1 == 2)) {
        ClearSelectReturnDisplayBitOn();
    }
    v1 = func_020280dc();
    if (v1 == 0) {
        func_0212b91c();
    } else {
        func_0211f498();
    }
    HeapDestroy((void *) gSelectKart->mHeap);
    *&gSelectKart = NULL;
}

#pragma thumb off

u32 func_02028074(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = 0x4000000u;
    value1 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value1) & ~(0x1f00u);
    value0 = (value1) | ((value0 << 8));
    *(u32 *) ((value2) + (0)) = value0;
    return value0;
}

u32 func_02028058(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = 0x4001000u;
    value1 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value1) & ~(0x1f00u);
    value0 = (value1) | ((value0 << 8));
    *(u32 *) ((value2) + (0)) = value0;
    return value0;
}

void func_0202802c(u32 a, u32 b) {
    reg_G2S_DB_BG3OFS = (a & 0x1ff) | ((b << 16) & 0x1ff0000);
}

void func_02028010(u32 a) {
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | a;
}

void func_02027fd4(u32 a, u32 b, u32 c, u32 d) {
    func_0214a40c(((u32 *) 0x04001050u), a, b, c, d);
}

u32 func_02027fb8(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    value2 = 0x4001000u;
    value1 = (u32) * (const u32 *) ((value2) + (0));
    value1 = (value1) & ~(0xe000u);
    value0 = (value1) | ((value0 << 13));
    *(u32 *) ((value2) + (0)) = value0;
    return value0;
}

u32 func_02027f90(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    u32 compareLeft0;
    u32 compareRight0;
    value2 = 0x4001048u;
    compareLeft0 = value1;
    compareRight0 = 0u;
    value1 = (u32) * (const u16 *) ((value2) + (0));
    value1 = (value1) & ~(0x3fu);
    value1 = (value1) | (value0);
    value0 = 0x4001048u;
    if (compareLeft0 != compareRight0) {
        value1 = (value1) | (0x20u);
    }
    *(u16 *) ((value0) + (0)) = (u16) value1;
    return value0;
}

u32 func_02027f68(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    u32 compareLeft0;
    u32 compareRight0;
    value2 = 0x400104au;
    compareLeft0 = value1;
    compareRight0 = 0u;
    value1 = (u32) * (const u16 *) ((value2) + (0));
    value1 = (value1) & ~(0x3fu);
    value1 = (value1) | (value0);
    value0 = 0x400104au;
    if (compareLeft0 != compareRight0) {
        value1 = (value1) | (0x20u);
    }
    *(u16 *) ((value0) + (0)) = (u16) value1;
    return value0;
}

void func_02027f1c(u32 a, u32 b, u32 c, u32 d) {
    reg_G2S_DB_WIN0H = ((a << 8) & 0xff00) | (c & 0xff);
    reg_G2S_DB_WIN0V = ((b << 8) & 0xff00) | (d & 0xff);
}

#pragma thumb on

void func_02027e78(void) {
    u32 a = 0x16;
    s32 b = func_02025ebc(&gSelectKart->mUnk_0ac[4]);
    if (gSelectKart->mState != 8) {
        a |= 8;
    }
    func_02028074(0x19);
    func_02028058(a);
    func_0202802c(0, -b);
    func_02028010(2);
    func_02027fd4(0, 0x3f, 6, 10);
    if (b != 0 && gSelectKart->mState != 8) {
        func_02027fb8(1);
        func_02027f90(0x1f, 1);
        func_02027f68(7, 1);
        func_02027f1c(0, 0, 0xff, b + 0xc0);
    } else {
        func_02027fb8(0);
    }
    if (gSelectKart->mUnk_104 != FALSE) {
        func_0202ba14();
    }
}
