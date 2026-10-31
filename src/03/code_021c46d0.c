#include "03/code_021c46d0.h"
#include "03/code_021c46a8.h"
#include "03/code_021d2168.h"
#include "03/code_021d254c.h"

void func_ov003_021c474c(void) {
    func_ov003_021c46a8();
    func_ov003_021c4748();
    return;
}

void func_ov003_021c4748(void) {
    return;
}

void func_ov003_021c471c(void) {
    func_ov003_021d1ee0(3, 1, 1, (u16) (8));
    func_ov003_021d1ee0(3, 0, 0x15, (u16) (8));
    func_ov003_021c212c(func_ov003_021c46d0);
    return;
}

void func_ov003_021c46d0(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if ((v1 == 0) && (v1 = func_ov003_021d1f70(0), v1 == 0)) {
        func_ov003_021d2168(0);
        func_ov003_021bf410();
        func_ov003_021d272c(1, 1);
        func_ov003_021d272c(0, 0x15);
        func_ov003_021c2120(0, 1);
        func_ov003_021c212c(func_ov003_021c3dd4);
    }
    return;
}
