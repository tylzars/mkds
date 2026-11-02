#include "00/code_0219a3f4.h"
#include "00/code_0218e49c.h"

void func_ov000_0219a3f8(u32 *param_1) {
    if (param_1[7] != 0) {
        param_1[5] = 1;
        return;
    }
    func_ov000_0218e53c(*param_1);
    func_ov000_0218dfb4((int *) ((int *) (u32) (param_1[3])));
    func_ov000_0218dc48((int *) ((int *) (u32) (param_1[4])));
    func_ov000_021a3668((void *) ((u32) (param_1)));
    func_ov000_0218e8b4();
    return;
}

void func_ov000_0219a3f4(int param_1, u32 param_2) {
    *(u32 *) (param_1 + 0x20) = param_2;
    return;
}
