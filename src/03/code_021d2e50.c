#include "03/code_021d2e50.h"
#include "03/code_021d2e68.h"

void func_ov003_021d2e5c(void *arg0, void *arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value3;
    value0 = (value0) + 8u;
    func_ov003_021d2e68(value0, value1);
}

void func_ov003_021d2e50(void *arg0, void *arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = (u32) arg1;
    u32 value3;
    value0 = *(const u32 *) ((value0) + 4u);
    func_ov003_021d2e68(value0, value1);
}
