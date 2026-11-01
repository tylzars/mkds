#include "03/code_021c7844.h"
#include "03/code_021d2168.h"
#include "03/code_021d254c.h"

void func_ov003_021c795c(void) {
    int v1;
    v1 = func_ov003_021d2b04(1);
    if (v1 != 0) {
        func_ov003_021bf31c((u8) (0));
    }
    return;
}

void func_ov003_021c7958(void) {
    return;
}

void func_ov003_021c7934(void) {
    int v1;
    v1 = func_ov003_021bf334();
    if (v1 == 0) {
        func_ov003_021cdc10(6);
        func_ov003_021c212c(func_ov003_021c7914);
    }
    return;
}

void func_ov003_021c7914(void) {
    func_ov003_021bf2d0();
    func_ov003_021d1dd0((u16) (8));
    func_ov003_021c212c(func_ov003_021c78d8);
    return;
}

void func_ov003_021c78d8(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if (v1 == 0) {
        func_ov003_021bf344();
        func_ov003_021d1ee0(3, 1, 1, (u16) (8));
        func_ov003_021d1ee0(3, 0, 0x15, (u16) (8));
        func_ov003_021c212c(func_ov003_021c7850);
    }
    return;
}

void func_ov003_021c7850(void) {
    int v1;
    int v2[1];
    v1 = func_ov003_021d1f70(1);
    if (((v1 == 0) && (v1 = func_ov003_021d1f70(0), v1 == 0)) && (v1 = func_ov003_021bf2f0(), v1 != 0)) {
        func_ov003_021d2168(0);
        func_ov003_021bf410();
        func_ov003_021d272c(1, 1);
        func_ov003_021d272c(0, 0x15);
        func_ov003_021c20dc(0, v2);
        if (v2[0] != 0) {
            func_ov003_021c2120(2, 1);
            func_ov003_021c212c(func_ov003_021cb294);
            return;
        }
        func_ov003_021c2120(2, 0);
        func_ov003_021c20f8(0, 0);
        func_ov003_021c7d30((u8) (0));
        func_ov003_021c212c(func_ov003_021c965c);
    }
    return;
}

void func_ov003_021c7844(u32 param_1) {
    *(u32 *) &data_ov003_021da200 = param_1;
    return;
}
