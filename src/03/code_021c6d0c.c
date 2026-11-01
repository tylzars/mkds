#include "03/code_021c6d0c.h"
#include "03/code_021c6cf0.h"
#include "03/code_021c0d2c.h"
#include "03/code_021d254c.h"

void func_ov003_021c6da4(void) {
    u32 v2 = ((u32) (&data_ov003_021d72a4));
    u32 v3 = ((u32) (&func_0214c090));
    u32 v4 = func_ov003_021bf620(v2, v3);
    u32 v5 = ((u32) (&data_ov003_021d72b8));
    u32 v6 = ((u32) (&func_0214b95c));
    u32 v7 = func_ov003_021bf620(v5, v6);
    u32 v8 = ((u32) (&data_ov003_021d72d0));
    u32 v9 = ((u32) (&func_0214c160));
    u32 v10 = func_ov003_021bf620(v8, v9);
    u32 v11 = ((u32) (&data_ov003_021d72e8));
    u32 v12 = ((u32) (&func_0214bc9c));
    u32 v13 = func_ov003_021bf620(v11, v12);
    u32 v14 = 0x4001008u;
    u32 v15 = ((u32) * (u16 *) ((v14) + (0)));
    u32 v17 = ((v15) & ~(0x3u));
    u32 v18 = ((v17) | (0x3u));
    u32 v20;
    u32 v21;
    u32 v22;
    u32 v23;
    u32 v25;
    u32 v26;
    u32 v27;
    u32 v29;
    u32 v31;
    u32 v32;
    u32 v33;
    u32 v34;
    u32 v36;
    u32 v37;
    u32 v38;
    u32 v39;
    *(u16 *) ((v14) + (0)) = (u16) v18;
    v20 = 0x400100au;
    v21 = ((u32) * (u16 *) ((v20) + (0)));
    v22 = ((v21) & ~(0x3u));
    v23 = ((v22) | (0x3u));
    *(u16 *) ((v20) + (0)) = (u16) v23;
    v25 = 0x4000008u;
    v26 = ((u32) * (u16 *) ((v25) + (0)));
    v27 = ((v26) & ~(0x3u));
    v29 = ((v27) | (0x2u));
    *(u16 *) ((v25) + (0)) = (u16) v29;
    v31 = 0x400000au;
    v32 = ((u32) * (u16 *) ((v31) + (0)));
    v33 = ((v32) & ~(0x3u));
    v34 = ((v33) | (0x3u));
    *(u16 *) ((v31) + (0)) = (u16) v34;
    v36 = 0x400000cu;
    v37 = ((u32) * (u16 *) ((v36) + (0)));
    v38 = ((v37) & ~(0x3u));
    v39 = ((v38) | (0x3u));
    *(u16 *) ((v36) + (0)) = (u16) v39;
}

void func_ov003_021c6d68(void) {
    func_ov003_021d1ee0(2, 1, (u32) 1, (u16) 8);
    func_ov003_021d1ee0(2, 0, (u32) 0x15, (u16) 8);
    func_ov003_021d2784(1, (u32) 1);
    func_ov003_021d2784(0, (u32) 0x15);
    func_ov003_021c212c(func_ov003_021c6d0c);
}

void func_ov003_021c6d0c(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if ((v1 == 0) && (v1 = func_ov003_021d1f70(0), v1 == 0)) {
        func_ov003_021c0d2c();
        func_ov003_021cdc10((u32) 0x14);
        if (*(u8 *) ((int) data_ov003_021da1f8 + 0x29) == 0) {
            func_ov003_021c0cd0((u8) 0);
        }
        if (*(u8 *) ((int) data_ov003_021da1f8 + 0x29) == ' ') {
            func_ov003_021c0cbc((u8) 0);
        }
        func_ov003_021c212c(func_ov003_021c6cf0);
    }
}
