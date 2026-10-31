#include "03/code_021cb0b0.h"
#include "03/code_021cb084.h"
#include "03/code_021d254c.h"

void func_ov003_021cb0e0(void) {
    func_ov003_021d1ee0(2, 1, 1, (u16) (8));
    func_ov003_021d1ee0(2, 0, 0x14, (u16) (8));
    func_ov003_021d2784(1, 1);
    func_ov003_021d2784(0, 0x14);
    func_ov003_021c212c(func_ov003_021cb0b0);
    return;
}

void func_ov003_021cb0b0(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if ((v1 == 0) && (v1 = func_ov003_021d1f70(0), v1 == 0)) {
        func_ov003_021bf5c8(0);
        func_ov003_021c212c(func_ov003_021cb084);
    }
    return;
}
