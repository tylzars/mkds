#include "Main/Unknown/code_02025f80.h"
#include "Main/Unknown/code_02025edc.h"
#include "Main/Unknown/code_0202b000.h"
#include "Main/Unknown/code_02029930.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_0204799c.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_0211f498.h"
#include "Main/Unknown/unk_02174000.h"
#include "code_0214a390.h"

#pragma thumb on

void func_020260e4(void) {
    if (*(vu16 *) 0x27ffc40 == 2) {
        if (func_02029930()->mUnk_c8 == 2) {
            func_0211f498();
        }
    }
    func_02036ab0(data_02174e14->mUnk_05c);
    data_02174e14 = 0;
}

void func_02026058(void) {
    u32 a = 0x18;

    func_0214a40c((u32 *) 0x4001050, 0, 0x3f, 6, 10);
    if (!(data_02174e14->mUnk_06c == 9 && data_02174e14->mUnk_08c == 2)) {
        a |= 1;
    }
    *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffffe0ff) | (a << 8);
    *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | 0x1600;
    *(vu16 *) 0x4000008 = (*(vu16 *) 0x4000008 & ~3) | 1;
    if (data_02174e14->mUnk_128 != 0) {
        func_0202ba14();
    }
}

void func_02025f90(void) {
    Unk020b4934 *a = 0;
    Unk020b4a44 *b = 0;
    Unk02021dc8 *c = 0;

    func_020b49f4(&a, func_02047a28(data_usa_02161b3c));
    func_020b48ec(&c, func_02047a28(data_usa_02161b5c));
    func_020b4a7c(&b, func_02047a28(data_usa_02161b7c));
    func_020b49f4(&a, func_02047a28(data_usa_02161b9c));
    func_020b48ec(&c, func_02047a28(data_usa_02161bb8));
    func_020b4a7c(&b, func_02047a28(data_usa_02161bd4));
    func_020b49f4(&a, func_02047a28(data_usa_02161bf0));
    func_020b48ec(&c, func_02047a28(data_usa_02161c14));
    func_020b49f4(&a, func_02047a28(data_usa_02161c38));
    func_020b48ec(&c, func_02047a28(data_usa_02161c60));
}

void func_02025f80(Unk02025ebc *a, s32 b, s32 c, s16 d, s32 e) {
    a->mUnk_08 = c;
    a->mUnk_0c = d;
    a->mUnk_0e = e;
    func_02025f14(a, b);
}

#pragma thumb off
