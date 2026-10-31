#include "03/code_021c7cb0.h"
#include "03/code_021cef6c.h"

void func_ov003_021c7d58(void) {
    int v1;
    v1 = func_ov003_021cef80();
    if (v1 == 0) {
        func_ov003_021cdc10((u32) 6);
        func_ov003_021cef90();
        func_ov003_021cc900((u32) ((u32) data_ov003_021da214->mUnk_0c[0]));
        func_ov003_021c212c(func_ov003_021c7d3c);
    }
}

void func_ov003_021c7d3c(void) {
    int v1;
    v1 = func_ov003_021cef6c();
    if (v1 == 0) {
        func_ov003_021c212c(func_ov003_021c9450);
    }
}

void func_ov003_021c7d30(u8 param_1) {
    *(u8 *) &data_ov003_021da208 = param_1;
}

void func_ov003_021c7d14(void) {
    func_ov003_021c7cb0();
    func_ov003_021c7a0c();
    func_ov003_021c212c(func_ov003_021c79e4);
}

void func_ov003_021c7cb0(void) {
    u32 v2 = ((u32) (&data_ov003_021d73b8));
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
    u32 v26;
    u32 v27;
    u32 v28;
    u32 v29;
    *(u16 *) ((v5) + (0)) = (u16) v9;
    v11 = 0x400100au;
    v12 = ((u32) *(u16 *) ((v11) + (0)));
    v13 = ((v12) & ~(0x3u));
    v14 = ((v13) | (0x3u));
    *(u16 *) ((v11) + (0)) = (u16) v14;
    v16 = 0x4000008u;
    v17 = ((u32) *(u16 *) ((v16) + (0)));
    v18 = ((v17) & ~(0x3u));
    v19 = ((v18) | (0x3u));
    *(u16 *) ((v16) + (0)) = (u16) v19;
    v21 = 0x400000au;
    v22 = ((u32) *(u16 *) ((v21) + (0)));
    v23 = ((v22) & ~(0x3u));
    v24 = ((v23) | (0x3u));
    *(u16 *) ((v21) + (0)) = (u16) v24;
    v26 = 0x400000cu;
    v27 = ((u32) *(u16 *) ((v26) + (0)));
    v28 = ((v27) & ~(0x3u));
    v29 = ((v28) | (0x3u));
    *(u16 *) ((v26) + (0)) = (u16) v29;
}
