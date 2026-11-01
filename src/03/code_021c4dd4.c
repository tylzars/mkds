#include "03/code_021c4dd4.h"
#include "03/code_021d2168.h"
#include "03/code_021d254c.h"

void func_ov003_021c4f80(void) {
    int v1;
    v1 = func_ov003_021d2b04(2);
    if (v1 != 0) {
        func_ov003_021bf31c(0);
        return;
    }
    v1 = func_ov003_021c50d8();
    if (v1 != 0) {
        func_ov003_021bf31c(0);
    }
    return;
}

void func_ov003_021c4f7c(void) {
    return;
}

void func_ov003_021c4f54(void) {
    int v1;
    v1 = func_ov003_021bf334();
    if (v1 == 0) {
        func_ov003_021cdbd0();
        func_ov003_021cdc10(7);
        func_ov003_021c212c(func_ov003_021c4f24);
    }
    return;
}

void func_ov003_021c4f24(void) {
    if (data_ov003_021da1d8 == 0) {
        func_ov003_021c2824();
    }
    func_ov003_021bf2d0();
    func_ov003_021d1dd0(8);
    func_ov003_021c212c(func_ov003_021c4ecc);
    return;
}

void func_ov003_021c4ecc(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if ((v1 == 0) && ((data_ov003_021da1d8 != 0 || (v1 = func_ov003_021c27e4(), v1 != 0)))) {
        func_ov003_021bf344();
        if (data_ov003_021da1d8 == 0) {
            func_ov003_021d1ee0(3, 1, 1, 8);
        }
        func_ov003_021d1ee0(3, 0, 0x15, 8);
        func_ov003_021c212c(func_ov003_021c4e14);
    }
    return;
}

void func_ov003_021c4e14(void) {
    int v1;
    v1 = func_ov003_021d1f70(0);
    if (((v1 == 0) && (((data_ov003_021da1d8 != 0 || (v1 = func_ov003_021d1f70(1), v1 == 0)) &&
                        (v1 = func_ov003_021bf2f0(), v1 != 0)))) &&
        ((data_ov003_021da1d8 != 0 || (v1 = func_ov003_021c27e4(), v1 != 0)))) {
        func_ov003_021beecc();
        func_ov003_021d2168(0);
        if (data_ov003_021da1d8 == 0) {
            func_ov003_021bf410();
            func_ov003_021d272c(1, 1);
        }
        func_ov003_021d272c(0, 0x15);
        if (data_ov003_021da1d8 == 0) {
            func_ov003_021c2120(0, 1);
            func_ov003_021c212c(func_ov003_021c3dd4);
            return;
        }
        if (data_ov003_021da1d8 == 2) {
            func_ov003_021c2120(0, 1);
            func_ov003_021c212c(func_ov003_021c4aa4);
            return;
        }
        func_ov003_021c2120(0, 1);
        func_ov003_021c212c(func_ov003_021c4d3c);
    }
    return;
}

void func_ov003_021c4dd4(int param_1) {
    func_ov003_021cdbd0();
    if (param_1 == 0) {
        data_ov003_021da1d8 = 1;
        func_ov003_021cdc10(0x10);
    } else {
        data_ov003_021da1d8 = 2;
        func_ov003_021cdc10(0x12);
    }
    func_ov003_021c27d0(0);
    func_ov003_021c212c(func_ov003_021c4f24);
    return;
}
