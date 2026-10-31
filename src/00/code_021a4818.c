#include "00/code_021a4818.h"
#include "00/code_0218e8c4.h"

void func_ov000_021a4818(void *param_1) {
    int iVar1;
    if (param_1 == 0) {
        param_1 = data_ov000_021b426c;
    }
    if (*(int *) ((u8 *) param_1 + 0xbc) != 0) {
        iVar1 = func_ov000_0218e8c4();
        if ((u32) (iVar1 - *(int *) ((u8 *) param_1 + 0xac)) < ((u32) 0x00002710u)) {
            *(u32 *) ((u8 *) param_1 + 0xb4) = 1;
            return;
        }
        func_ov000_021a3a18((Unk021a3a18 *) param_1, 1);
        *(u32 *) ((u8 *) param_1 + 0xb4) = 0;
    }
    return;
}
