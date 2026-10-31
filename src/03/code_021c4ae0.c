#include "03/code_021c4ae0.h"
#include "03/code_021d2168.h"
#include "03/code_021d254c.h"

void func_ov003_021c4ae0(void) {
    int v1;
    if (((data_ov003_021da1d0 == 0) && (data_ov003_021da1d4 != 0)) || (v1 = func_ov003_021c27e4(), v1 != 0)) {
        func_ov003_021d2168(0);
        func_ov003_021d272c(0, 0x15);
        if (data_ov003_021da1d4 == 0) {
            func_ov003_021bf410();
            func_ov003_021d272c(1, 1);
        }
        func_ov003_021c2120(0, 1);
        if (data_ov003_021da1d0 != 0) {
            func_ov003_021c212c(func_ov003_021c4aa4);
            return;
        }
        if (data_ov003_021da1d4 == 0) {
            func_ov003_021d272c(1, 1);
            func_ov003_021c212c(func_ov003_021c3dd4);
            return;
        }
        func_ov003_021c212c(func_ov003_021c4054);
    }
    return;
}
