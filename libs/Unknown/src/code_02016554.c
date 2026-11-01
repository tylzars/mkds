#include "code_02016554.h"

void func_02016554(void *arg0, u32 arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = arg1;
    u32 value2;
    u32 value12;
    value2 = (u32) &data_02173220;
    value12 = (u32) &func_0201661c;
    *(u32 *) ((value2) + (0)) = value0;
    value0 = value2;
    *(u32 *) ((value2) + (4)) = value1;
    func_0201661c(value0);
}
