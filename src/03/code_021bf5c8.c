#include "03/code_021bf5c8.h"

void func_ov003_021bf5ec(u32 param_1) {
    int v1[2];
    func_ov003_021c2104(v1, 0);
    if (v1[0] == 1) {
        func_ov003_021ce408(param_1);
        return;
    }
    if (v1[0] == 2) {
        func_ov003_021ce024(param_1);
    }
    return;
}

void func_ov003_021bf5c8(u32 param_1) {
    int v1[2];
    func_ov003_021c2104(0, v1);
    if (v1[0] == 1) {
        func_ov003_021bf364(param_1);
    }
    return;
}
