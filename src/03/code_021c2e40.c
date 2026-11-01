#include "03/code_021c2e40.h"
#include "03/code_021bf31c.h"
#include "03/code_021bf698.h"
#include "03/code_021c2b28.h"
#include "03/code_021d2a34.h"
#include "03/code_021d2acc.h"

void func_ov003_021c2e40(void) {
    u32 i;
    for (i = 0; i < 2; i++) {
        if (func_ov003_021d2a34(&data_ov003_021d6318[i]) != 0) {
            func_ov003_021bf31c(1);
            data_ov003_021da1a0 = i;
            func_ov003_021bf6c8(
                data_ov003_021d6328[data_ov003_021da1a0 * 4], data_ov003_021d632c[data_ov003_021da1a0 * 4],
                data_ov003_021d632a[data_ov003_021da1a0 * 4], data_ov003_021d632e[data_ov003_021da1a0 * 4]);
            return;
        }
    }
    if (func_ov003_021d2b04(1) != 0) {
        func_ov003_021bf31c(1);
    } else if (func_ov003_021d2b04(2) != 0) {
        func_ov003_021bf31c(0);
    } else if (func_ov003_021d2ae8(0x40) != 0) {
        func_ov003_021c2cc8(1);
    } else if (func_ov003_021d2ae8(0x80) != 0) {
        func_ov003_021c2cc8(3);
    } else if (func_ov003_021d2ae8(0x20) != 0) {
        func_ov003_021c2cc8(0);
    } else if (func_ov003_021d2ae8(0x10) != 0) {
        func_ov003_021c2cc8(2);
    }
}
