#include "03/code_021cb4d0.h"

void func_ov003_021cb518(void) {
    func_ov003_021bf2d0();
    func_ov003_021d1dd0((u16) 8);
    func_ov003_021c212c(func_ov003_021cb4d0);
}

void func_ov003_021cb4d0(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if (v1 == 0) {
        if ((*(u8 *) &data_ov003_021da240) != 0) {
            func_ov003_021bf344();
        }
        func_ov003_021d1ee0(3, 1, (u32) 1, (u16) 8);
        func_ov003_021d1ee0(3, 0, (u32) 0x14, (u16) 8);
        func_ov003_021c212c(func_ov003_021cb3d8);
    }
}
