#include "03/code_021c4788.h"
#include "03/code_021c4760.h"
#include "03/code_021d2168.h"
#include "03/code_021d254c.h"

void func_ov003_021c48f4(void) {
    func_ov003_021bf2d0();
    func_ov003_021d1dd0(8);
    func_ov003_021c212c(func_ov003_021c48ac);
}

void func_ov003_021c48ac(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if (v1 == 0) {
        func_ov003_021bf344();
        if (data_ov003_021da1cc == 0) {
            func_ov003_021d1ee0(3, 1, 1, 8);
        }
        func_ov003_021d1ee0(3, 0, 0x15, 8);
        func_ov003_021c212c(func_ov003_021c482c);
    }
}

void func_ov003_021c482c(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if (((v1 == 0) && (v1 = func_ov003_021d1f70(0), v1 == 0)) && (v1 = func_ov003_021bf2f0(), v1 != 0)) {
        func_ov003_021d2168(0);
        if (data_ov003_021da1cc == 0) {
            func_ov003_021bf410();
            func_ov003_021d272c(1, 1);
        }
        func_ov003_021d272c(0, 0x15);
        if (data_ov003_021da1cc == 0) {
            func_ov003_021c2120(0, 1);
            func_ov003_021c212c(func_ov003_021c3dd4);
            return;
        }
        func_ov003_021c2120(0, 1);
        func_ov003_021c212c(func_ov003_021c5098);
    }
}

void func_ov003_021c4804(void) {
    data_ov003_021da1c4 = 0;
    func_ov003_021c47b0();
    func_ov003_021bf578(99);
    func_ov003_021c212c(func_ov003_021c4788);
}

void func_ov003_021c47b0(void) {
    void *v2 = &data_ov003_021d7180;
    void *v3 = &func_0214bc9c;
    u32 v4 = func_ov003_021bf620(v2, v3);
    u32 v5 = 0x4001008u;
    u32 v6 = ((u32) * (u16 *) ((v5) + (0)));
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
    v12 = ((u32) * (u16 *) ((v11) + (0)));
    v13 = ((v12) & ~(0x3u));
    v14 = ((v13) | (0x3u));
    *(u16 *) ((v11) + (0)) = (u16) v14;
    v16 = 0x400000au;
    v17 = ((u32) * (u16 *) ((v16) + (0)));
    v18 = ((v17) & ~(0x3u));
    v19 = ((v18) | (0x3u));
    *(u16 *) ((v16) + (0)) = (u16) v19;
    v21 = 0x400000cu;
    v22 = ((u32) * (u16 *) ((v21) + (0)));
    v23 = ((v22) & ~(0x3u));
    v24 = ((v23) | (0x3u));
    *(u16 *) ((v21) + (0)) = (u16) v24;
}

void func_ov003_021c4788(void) {
    func_ov003_021d1ee0(2, 0, 0x15, 8);
    func_ov003_021d2784(0, 0x15);
    func_ov003_021c212c(func_ov003_021c4760);
}
