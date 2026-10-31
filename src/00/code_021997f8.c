#include "00/code_021997f8.h"
#include "00/code_0218e8c4.h"

void func_ov000_021997f8(u32 param_1) {
    u32 v1;
    if (*(int *) (param_1 + 0x90) == 0) {
        *(u32 *) (param_1 + 0x90) = 1;
        v1 = func_ov000_0218e8c4();
        *(u32 *) (param_1 + 0x94) = v1;
    }
    return;
}
