#include "03/code_021c9058.h"

void func_ov003_021c9058(u32 param_1) {
    int v1;
    v1 = func_ov003_021cdb6c();
    if (*(u8 *) (v1 + 0xf6) != param_1) {
        *(s8 *) ((int) data_ov003_021da214 + 0x43) = (s8) param_1;
        func_ov003_021cdb44(param_1);
        func_ov003_021c8b94();
    }
    return;
}
