#include "03/code_021bf4dc.h"
#include "03/code_021bf8c0.h"
#include "03/code_021c3fa0.h"
#include "03/code_021c3fc8.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d1f70.h"
#include "03/code_021d254c.h"
#include "03/code_021d2940.h"
#include "03/unk_021d7000.h"
#include "code_0200fc8c.h"
#include "code_0214b824.h"
#include "code_0214f4a4.h"

void func_ov003_021c4130(void) {
    int v1;
    v1 = func_ov003_021d2b04((u32) 1);
    if (v1 != 0) {
        func_ov003_021bf31c((u8) 0);
    }
}

void func_ov003_021c412c(void) {
    return;
}

void func_ov003_021c4108(void) {
    int v1;
    v1 = func_ov003_021bf334();
    if (v1 == 0) {
        func_ov003_021cdc10((u32) 6);
        func_ov003_021c212c(func_ov003_021c40e8);
    }
}

void func_ov003_021c40e8(void) {
    func_ov003_021bf2d0();
    func_ov003_021d1dd0((u16) 8);
    func_ov003_021c212c(func_ov003_021c40b0);
}

void func_ov003_021c40b0(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if (v1 == 0) {
        func_ov003_021d1ee0(3, 1, (u32) 0x3f, (u16) 0x40);
        func_ov003_021d1ee0(3, 0, (u32) 0x3f, (u16) 0x40);
        func_ov003_021c212c(func_ov003_021c4084);
    }
}

void func_ov003_021c4084(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if ((v1 == 0) && (v1 = func_ov003_021d1f70(0), v1 == 0)) {
        func_0200fd10((u32) (((u32) 0x01000000u)));
        func_0214fb54();
    }
}

void func_ov003_021c4054(void) {
    func_ov003_021c3ff0();
    func_ov003_021bf578((u32) 0x60);
    func_ov003_021beef8(0);
    func_ov003_021bf9e8(1);
    func_ov003_021cdc10((u32) 0xb);
    func_ov003_021c212c(func_ov003_021c3fc8);
}

void func_ov003_021c3ff0(void) {
    void *v2 = &data_ov003_021d7158;
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
    u32 v26;
    u32 v27;
    u32 v28;
    u32 v29;
    *(u16 *) ((v5) + (0)) = (u16) v9;
    v11 = 0x400100au;
    v12 = ((u32) * (u16 *) ((v11) + (0)));
    v13 = ((v12) & ~(0x3u));
    v14 = ((v13) | (0x3u));
    *(u16 *) ((v11) + (0)) = (u16) v14;
    v16 = 0x4000008u;
    v17 = ((u32) * (u16 *) ((v16) + (0)));
    v18 = ((v17) & ~(0x3u));
    v19 = ((v18) | (0x3u));
    *(u16 *) ((v16) + (0)) = (u16) v19;
    v21 = 0x400000au;
    v22 = ((u32) * (u16 *) ((v21) + (0)));
    v23 = ((v22) & ~(0x3u));
    v24 = ((v23) | (0x3u));
    *(u16 *) ((v21) + (0)) = (u16) v24;
    v26 = 0x400000cu;
    v27 = ((u32) * (u16 *) ((v26) + (0)));
    v28 = ((v27) & ~(0x3u));
    v29 = ((v28) | (0x3u));
    *(u16 *) ((v26) + (0)) = (u16) v29;
}

void func_ov003_021c3fc8(void) {
    func_ov003_021d1ee0(2, 0, (u32) 0x15, (u16) 8);
    func_ov003_021d2784(0, (u32) 0x15);
    func_ov003_021c212c(func_ov003_021c3fa0);
}
