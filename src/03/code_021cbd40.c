#include "03/code_021cbd40.h"
#include "03/code_021cbd20.h"
#include "03/code_021cef6c.h"
#include "03/code_021d254c.h"

void func_ov003_021cbe44(void) {
    int v1;
    func_ov003_021cbe40();
    func_ov003_021cbe3c();
    v1 = func_ov003_021cef80();
    if (v1 == 0) {
        func_ov003_021cdc10((u32) 6);
        func_ov003_021cef90();
        func_ov003_021cdc10((u32) 6);
        func_ov003_021c212c(func_ov003_021cbe14);
    }
}

void func_ov003_021cbe40(void) {
    return;
}

void func_ov003_021cbe3c(void) {
    return;
}

void func_ov003_021cbe14(void) {
    int v1;
    v1 = func_ov003_021cef6c();
    if (v1 == 0) {
        func_ov003_021d1ee0(3, 0, (u32) 0x14, (u16) 8);
        func_ov003_021c212c(func_ov003_021cbde4);
    }
}

void func_ov003_021cbde4(void) {
    int v1;
    v1 = func_ov003_021d1f70(0);
    if (v1 == 0) {
        func_ov003_021d272c(0, (u32) 0x14);
        func_ov003_021c2120((u32) 0, (u32) 1);
        func_ov003_021c212c(func_ov003_021cbb98);
    }
}

void func_ov003_021cbdbc(void) {
    *(u8 *) &data_ov003_021da24c = 0;
    func_ov003_021cbd68();
    func_ov003_021bf578((u32) 0x77);
    func_ov003_021c212c(func_ov003_021cbd40);
}

void func_ov003_021cbd68(void) {
    u32 v2 = ((u32) (&data_ov003_021d76f4));
    u32 v3 = ((u32) (&func_0214bc9c));
    u32 v4 = func_ov003_021bf620(v2, v3);
    u32 v5 = 0x4001008u;
    u32 v6 = ((u32) *(u16 *) ((v5) + (0)));
    u32 v8 = ((v6) & ~(0x3u));
    u32 v9 = ((v8) | (0x3u));
    u32 v11;
    u32 v12;
    u32 v13;
    u32 v14;
    u32 v16;
    u32 v17;
    u32 v18;
    u32 v19;
    u32 v21;
    u32 v22;
    u32 v23;
    u32 v24;
    *(u16 *) ((v5) + (0)) = (u16) v9;
    v11 = 0x400100au;
    v12 = ((u32) *(u16 *) ((v11) + (0)));
    v13 = ((v12) & ~(0x3u));
    v14 = ((v13) | (0x3u));
    *(u16 *) ((v11) + (0)) = (u16) v14;
    v16 = 0x400000au;
    v17 = ((u32) *(u16 *) ((v16) + (0)));
    v18 = ((v17) & ~(0x3u));
    v19 = ((v18) | (0x3u));
    *(u16 *) ((v16) + (0)) = (u16) v19;
    v21 = 0x400000cu;
    v22 = ((u32) *(u16 *) ((v21) + (0)));
    v23 = ((v22) & ~(0x3u));
    v24 = ((v23) | (0x3u));
    *(u16 *) ((v21) + (0)) = (u16) v24;
}

void func_ov003_021cbd40(void) {
    func_ov003_021d1ee0(2, 0, (u32) 0x15, (u16) 8);
    func_ov003_021d2784(0, (u32) 0x15);
    func_ov003_021c212c(func_ov003_021cbd20);
}
