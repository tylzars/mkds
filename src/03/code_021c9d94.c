#include "03/code_021c9d94.h"
#include "03/code_021d2168.h"
#include "03/code_021d254c.h"

void func_ov003_021c9eb0(void) {
    int v1;
    v1 = func_ov003_021d2b04(2);
    if (v1 != 0) {
        func_ov003_021bf31c(0);
        return;
    }
    v1 = func_ov003_021ca008();
    if (v1 != 0) {
        func_ov003_021bf31c(0);
    }
    return;
}

void func_ov003_021c9eac(void) {
    return;
}

void func_ov003_021c9e84(void) {
    int v1;
    v1 = func_ov003_021bf334();
    if (v1 == 0) {
        func_ov003_021cdbd0();
        func_ov003_021cdc10(7);
        func_ov003_021c212c(func_ov003_021c9e64);
    }
    return;
}

void func_ov003_021c9e64(void) {
    func_ov003_021bf2d0();
    func_ov003_021d1dd0(8);
    func_ov003_021c212c(func_ov003_021c9e1c);
    return;
}

void func_ov003_021c9e1c(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if (v1 == 0) {
        func_ov003_021bf344();
        if (data_ov003_021da21c == 0) {
            func_ov003_021d1ee0(3, 1, 1, 8);
        }
        func_ov003_021d1ee0(3, 0, 0x15, 8);
        func_ov003_021c212c(func_ov003_021c9d94);
    }
    return;
}

void func_ov003_021c9d94(void) {
    int v1;
    v1 = func_ov003_021d1f70(0);
    if ((v1 == 0) && (((data_ov003_021da21c != 0 || (v1 = func_ov003_021d1f70(1), v1 == 0)) &&
                          (v1 = func_ov003_021bf2f0(), v1 != 0)))) {
        func_ov003_021beecc();
        func_ov003_021d2168(0);
        if (data_ov003_021da21c == 0) {
            func_ov003_021bf410();
            func_ov003_021d272c(1, 1);
        }
        func_ov003_021c29b8();
        if (data_ov003_021da21c == 0) {
            func_ov003_021c2120(2, 1);
            func_ov003_021c212c(func_ov003_021cb7fc);
            return;
        }
        func_ov003_021c2120(0, 0);
        func_ov003_021c212c(func_ov003_021ca194);
    }
    return;
}
