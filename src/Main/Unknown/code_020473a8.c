#include "Main/Unknown/code_020473a8.h"
#include "code_02017f24.h"

#pragma thumb on

void func_02047468(const void *param_1, u32 param_2) {
    u32 v1;
    u8 v2[128];
    v1 = func_02048440();
    func_0200d9e0((char *) v2, 0x80, (const char *) data_02164ffc, param_1, v1);
    func_02047498(v2, param_2);
}

void func_020473e4(void) {
    func_0204f5e4();
    func_0201804c((void *) data_021759c8->mUnk_a80, (u32) 3);
    func_02047498(data_02164f48, 0xb);
    func_02047498(data_02164f64, 0xc);
    func_02047498(data_02164f80, 0);
    func_02047468(data_02164f98, (u32) 1);
    func_02047498(data_02164fac, 8);
    func_02047498(data_02164fc0, 9);
    func_02047468(data_02164fd4, (u32) 10);
    func_02047498(data_02164fe4, 0xd);
}

void func_020473a8(void) {
    func_0204f5e4();
    func_0201804c((void *) data_021759c8->mUnk_a80, (u32) 3);
    func_02047498(data_02164f1c, 0);
    func_02047468(data_02164f34, (u32) 1);
}

#pragma thumb off
