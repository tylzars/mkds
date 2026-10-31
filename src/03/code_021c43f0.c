#include "03/code_021c43f0.h"
#include "03/code_021d2168.h"
#include "03/code_021d254c.h"

void func_ov003_021c44e0(void) {
    func_ov003_021bf2d0();
    func_ov003_021d1dd0(8);
    func_ov003_021c212c(func_ov003_021c4498);
    return;
}

void func_ov003_021c4498(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if (v1 == 0) {
        func_ov003_021bf344();
        if (data_ov003_021da1c0 == 0) {
            func_ov003_021d1ee0(3, 1, 1, 8);
        }
        func_ov003_021d1ee0(3, 0, 0x15, 8);
        func_ov003_021c212c(func_ov003_021c4410);
    }
    return;
}

void func_ov003_021c4410(void) {
    int v1;
    v1 = func_ov003_021d1f70(0);
    if ((v1 == 0) && (((data_ov003_021da1c0 != 0 || (v1 = func_ov003_021d1f70(1), v1 == 0)) &&
                          (v1 = func_ov003_021bf2f0(), v1 != 0)))) {
        func_ov003_021d2168(0);
        if (data_ov003_021da1c0 == 0) {
            func_ov003_021bf410();
            func_ov003_021d272c(1, 1);
        }
        func_ov003_021d272c(0, 0x15);
        if (data_ov003_021da1c0 == 0) {
            func_ov003_021c2120(0, 1);
            func_ov003_021c212c(func_ov003_021c3dd4);
            return;
        }
        func_ov003_021c2120(0, 1);
        func_ov003_021c212c(func_ov003_021c43f0);
    }
    return;
}

void func_ov003_021c43f0(void) {
    func_ov003_021c43a4();
    func_ov003_021bf578(0x5c);
    func_ov003_021c212c(func_ov003_021c437c);
    return;
}
