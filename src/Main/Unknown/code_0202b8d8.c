#include "Main/Unknown/code_0202b8d8.h"
#include "Main/Unknown/code_0204799c.h"
#include "Main/Unknown/code_020b47d8.h"
#include "code_02148950.h"
#include "Main/Unknown/code_02025ebc.h"

#pragma thumb on

void func_0202ba14(void) {
    u32 a = 0x19;
    s32 b;
    s16 x;

    x = func_02025ebc(&data_02174e3c->mUnk_210[2]);
    if (data_02174e3c->mUnk_254 == 2) {
        b = 0;
        a |= 2;
        *(vu32 *) 0x4000010 = x & 0x1ff;
        *(vu32 *) 0x4000014 = -x & 0x1ff;
        *(vu16 *) 0x4000008 = (*(vu16 *) 0x4000008 & ~3) | 3;
        *(vu16 *) 0x400000a = (*(vu16 *) 0x400000a & ~3) | 3;
    } else {
        b = 1;
    }
    if (data_02174e3c->mUnk_250 == 2) {
        a |= 2;
    }
    *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffffe0ff) | (a << 8);
    func_02148950(1, 0, b);
    if (data_02174e3c->mUnk_254 == 2) {
        *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffff1fff) | 0x6000;
        *(vu16 *) 0x4000048 = (u32) ((*(vu16 *) 0x4000048 & ~0x3f) | 0x1d) | 0x20;
        *(vu16 *) 0x4000048 = (u32) ((*(vu16 *) 0x4000048 & 0xffffc0ff) | 0x1e00) | 0x2000;
        *(vu16 *) 0x400004a = (u32) ((*(vu16 *) 0x400004a & ~0x3f) | 0x1c) | 0x20;
        *(vu16 *) 0x4000040 = 0x80;
        *(vu16 *) 0x4000044 = 0xc0;
        *(vu16 *) 0x4000042 = 0x8000;
        *(vu16 *) 0x4000046 = 0xc0;
    } else {
        *(vu32 *) 0x4000000 = *(vu32 *) 0x4000000 & 0xffff1fff;
    }
}

void func_0202b8d8(void) {
    Unk020b4934 *a;
    Unk020b4a44 *b;
    Unk02021dc8 *c;
    Unk020b47d8 *d;

    if (*(vu16 *) 0x27ffc40 == 2) {
        func_020b496c(&a, func_0204799c(data_usa_021626d0));
        func_020b49f4(&a, func_0204799c(data_usa_021626f8));
        func_020b48ec(&c, func_0204799c(data_usa_02162720));
        func_020b4a7c(&b, func_0204799c(data_usa_02162748));
        func_020b4a7c(&b, func_0204799c(data_usa_02162770));
        func_020b4810(&d, func_0204799c(data_usa_02162798));
        func_020b4810(&d, func_0204799c(data_usa_021627c4));
    } else {
        func_020b496c(&a, func_02047a28(data_usa_021627f0));
        func_020b49f4(&a, func_02047a28(data_usa_0216280c));
        func_020b49f4(&a, func_02047a28(data_usa_02162828));
        func_020b48ec(&c, func_02047a28(data_usa_0216284c));
        func_020b48ec(&c, func_02047a28(data_usa_02162868));
        func_020b4a7c(&b, func_02047a28(data_usa_0216288c));
        func_020b4a7c(&b, func_02047a28(data_usa_021628a8));
        func_020b4810(&d, func_02047a28(data_usa_021628c4));
        func_020b4810(&d, func_02047a28(data_usa_021628e4));
    }
}

#pragma thumb off
