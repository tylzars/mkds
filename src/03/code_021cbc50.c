#include "03/code_021cbc50.h"
#include "03/code_021d2168.h"
#include "03/code_021d254c.h"

void func_ov003_021cbd0c(void) {
    func_ov003_021cbc00();
    func_ov003_021cbd08();
    return;
}

void func_ov003_021cbd08(void) {
    return;
}

void func_ov003_021cbcc8(void) {
    int v1[1];
    func_ov003_021c20dc(0, v1);
    if (v1[0] != 0) {
        func_ov003_021ce0c4();
    }
    func_ov003_021d1ee0(3, 1, 1, (u16) (8));
    func_ov003_021d1ee0(3, 0, 0x15, (u16) (8));
    func_ov003_021c212c(func_ov003_021cbc50);
    return;
}

void func_ov003_021cbc50(void) {
    int v1;
    int v2[1];
    v1 = func_ov003_021d1f70(1);
    if (((v1 == 0) && (v1 = func_ov003_021d1f70(0), v1 == 0)) &&
        (v1 = func_ov003_021cdd28(), v1 != 0)) {
        func_ov003_021d2168(0);
        func_ov003_021bf410();
        func_ov003_021d272c(1, 1);
        func_ov003_021d272c(0, 0x15);
        func_ov003_021c2120(2, 1);
        func_ov003_021c20dc(0, v2);
        if (v2[0] == 0) {
            func_ov003_021c20f8(0, 0);
            func_ov003_021c212c(func_ov003_021c965c);
            return;
        }
        func_ov003_021c212c(func_ov003_021c3078);
    }
    return;
}
