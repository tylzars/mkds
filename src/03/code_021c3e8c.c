#include "03/code_021c3e8c.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d254c.h"

void func_ov003_021c3f8c(void) {
    func_ov003_021c3f88();
    func_ov003_021c3f84();
}

void func_ov003_021c3f88(void) {
    return;
}

void func_ov003_021c3f84(void) {
    return;
}

void func_ov003_021c3f64(void) {
    func_ov003_021d1ee0(3, 0, (u32) 0x15, (u16) 8);
    func_ov003_021c212c(func_ov003_021c3ef0);
}

void func_ov003_021c3ef0(void) {
    int v1;
    v1 = func_ov003_021d1f70(0);
    if ((v1 == 0) && (v1 = func_ov003_021c27e4(), v1 != 0)) {
        func_ov003_021bf9b8();
        func_ov003_021beecc();
        func_ov003_021d2168(0);
        func_ov003_021d272c(0, (u32) 0x15);
        func_ov003_021c2120((u32) 0, (u32) 1);
        if ((*(u8 *) &data_ov003_021da1bc) == 0) {
            func_ov003_021c212c(func_ov003_021c4aa4);
            return;
        }
        if ((*(u8 *) &data_ov003_021da1bc) == 2) {
            func_ov003_021c212c(func_ov003_021c4804);
            return;
        }
        func_ov003_021c212c(func_ov003_021c4220);
    }
}

void func_ov003_021c3e8c(int a) {
    if (a == 2) {
        func_ov003_021cd42c();
        *(u8 *) &data_ov003_021da1bc = 1;
        func_ov003_021cdbd0();
        func_ov003_021cdc10((u32) 0x10);
    } else if (a == 3) {
        *(u8 *) &data_ov003_021da1bc = 2;
        func_ov003_021cdbd0();
        func_ov003_021cdc10((u32) 0x12);
    } else {
        *(u8 *) &data_ov003_021da1bc = 0;
        func_ov003_021cdbd0();
        func_ov003_021cdc10((u32) 0x12);
    }
    func_ov003_021c27d0(NULL);
    func_ov003_021c2824();
    func_ov003_021c212c(func_ov003_021c3f64);
}
