#include "03/code_021ca56c.h"
#include "03/code_021cef6c.h"
#include "03/code_021d2168.h"
#include "03/code_021d254c.h"

void func_ov003_021ca6d4(void) {
    int v1;
    v1 = func_ov003_021d2b04((u32) 2);
    if (v1 != 0) {
        func_ov003_021cdbd0();
        func_ov003_021bf31c((u8) 0);
    }
}

void func_ov003_021ca6d0(void) {
    return;
}

void func_ov003_021ca6a8(void) {
    int v1;
    v1 = func_ov003_021bf334();
    if (v1 == 0) {
        func_ov003_021cdbd0();
        func_ov003_021cdc10((u32) 7);
        func_ov003_021c212c(func_ov003_021ca688);
    }
}

void func_ov003_021ca688(void) {
    func_ov003_021bf2d0();
    func_ov003_021d1dd0((u16) 8);
    func_ov003_021c212c(func_ov003_021ca64c);
}

void func_ov003_021ca64c(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if (v1 == 0) {
        func_ov003_021bf344();
        func_ov003_021d1ee0(3, 1, (u32) 1, (u16) 8);
        func_ov003_021d1ee0(3, 0, (u32) 0x15, (u16) 8);
        func_ov003_021c212c(func_ov003_021ca5b0);
    }
}

void func_ov003_021ca5b0(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if (((v1 == 0) && (v1 = func_ov003_021d1f70(0), v1 == 0)) && (v1 = func_ov003_021bf2f0(), v1 != 0)) {
        do {
            v1 = func_ov003_021cd118();
        } while (v1 == 0);
        func_ov003_021beecc();
        func_ov003_021d2168(0);
        func_ov003_021bf410();
        func_ov003_021d272c(1, (u32) 1);
        func_ov003_021d272c(0, (u32) 0x15);
        if ((*(u8 *) &data_ov003_021da228) != 1) {
            func_ov003_021cd27c();
            v1 = func_ov003_021cdb6c();
            func_ov003_021cd790((int) (*(u8 *) (v1 + 0xf4)));
            func_ov003_021c2120((u32) 2, (u32) 1);
            func_ov003_021c212c(func_ov003_021cb7fc);
            return;
        }
        func_ov003_021c2120((u32) 0, (u32) 1);
        func_ov003_021c20f8((u32) 0, (u32) 0);
        func_ov003_021c212c(func_ov003_021c6668);
    }
}

void func_ov003_021ca588(void) {
    int v1;
    v1 = func_ov003_021cef80();
    if (v1 == 0) {
        func_ov003_021cdc10((u32) 6);
        func_ov003_021cef90();
        func_ov003_021c212c(func_ov003_021ca56c);
    }
}

void func_ov003_021ca56c(void) {
    int v1;
    v1 = func_ov003_021cef6c();
    if (v1 == 0) {
        func_ov003_021c212c(func_ov003_021ca688);
    }
}
