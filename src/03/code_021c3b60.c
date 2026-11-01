#include "03/code_021c3b60.h"
#include "03/code_021bf31c.h"
#include "03/code_021bf698.h"
#include "03/code_021c391c.h"
#include "03/code_021d2a34.h"
#include "03/code_021d2acc.h"

void func_ov003_021c3b60(void) {
    u32 i;
    for (i = 0; i < 3; i++) {
        if (func_ov003_021d2a34(&data_ov003_021d6350[i]) != 0) {
            func_ov003_021bf31c(1);
            data_ov003_021da1ac = i;
            func_ov003_021bf6c8(
                data_ov003_021d6368[data_ov003_021da1ac * 4], data_ov003_021d636c[data_ov003_021da1ac * 4],
                data_ov003_021d636a[data_ov003_021da1ac * 4], data_ov003_021d636e[data_ov003_021da1ac * 4]);
            return;
        }
    }
    if (func_ov003_021d2b04(1) != 0) {
        func_ov003_021bf31c(1);
    } else if (func_ov003_021d2b04(2) != 0) {
        func_ov003_021bf31c(0);
    } else if (func_ov003_021d2ae8(0x40) != 0) {
        func_ov003_021c3940(1);
    } else if (func_ov003_021d2ae8(0x80) != 0) {
        func_ov003_021c3940(3);
    }
}
