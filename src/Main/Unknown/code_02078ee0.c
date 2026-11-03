#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02078ee0.h"
#include "Main/Unknown/code_02079a3c.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"

#pragma thumb on

void func_02078f78(Unk020136f0 *a) {
    data_0217ad08->mUnk_1d4 = func_020136f0(a);
    func_02012cbc(a);
}

void func_02078f18(void *a, int b) {
    u32 v1;
    func_02079a3c((u32 *) ((u32 *) (u32) b));
    *(u32 *) (b + 0xb0) = (u32) data_021759d0->mUnk_00;
    *(u32 *) (b + 0xb4) = 0;
    v1 = ((u32) func_02036bec(a, (u32) 0x6c));
    *(u32 *) (b + 0x10) = v1;
    v1 = ((u32) func_02036bec(a, (u32) 0x6c));
    *(u32 *) (b + 0x14) = v1;
    v1 = ((u32) func_02036bec(a, (u32) 0x6c));
    *(u32 *) (b + 0x18) = v1;
    v1 = ((u32) func_02036bec(a, (u32) 0x74));
    *(u32 *) (b + 0x1c) = v1;
    v1 = ((u32) func_02036bec(a, (u32) 0x38));
    *(u32 *) (b + 8) = v1;
}

void func_02078ee0(u32 *a, int b) {
    u32 v1;
    v1 = 0;
    *a = 0xffffffff;
    a[1] = 0xffffffff;
    a[2] = ((u32) 0x00001000u);
    *(u16 *) ((s32) a + 0x16) = (0x0000eaabu);
    *(u16 *) (a + 5) = *(u16 *) ((s32) a + 0x16);
    *(u16 *) (a + 6) = 0;
    a[3] = 0;
    a[4] = 0xffffff88;
    if (b != 0) {
        v1 = 0xffffff06;
    }
    a[0xb] = v1;
    a[0xc] = 0;
}

#pragma thumb off
