#include "03/code_021c6a18.h"
#include "03/code_021c735c.h"
#include "03/code_021c75e4.h"
#include "03/code_021c7000.h"
#include "03/code_021cd000.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d1000.h"
#include "03/code_021d1dd0.h"
#include "03/code_021d1f70.h"
#include "03/code_021c722c.h"
#include "03/code_021bf000.h"
#include "03/code_021c1000.h"
#include "03/unk_021d7000.h"
#include "03/unk_021da000.h"
#include "code_0214b824.h"
#include "03/code_021bf4dc.h"
#include "03/code_021d1fd0.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf410.h"
#include "03/code_021d1440.h"
#include "03/code_021bf810.h"
#include "03/code_021c70a4.h"
#include "03/code_021d1c18.h"
#include "03/code_021d27d8.h"
#include "code_0214d018.h"
#include "code_02134d30.h"

#include "03/code_021c1c5c.h"
#include "03/code_021c209c.h"
#include "03/code_021d254c.h"

void func_ov003_021c7748(void) {
    Unk021d7310 a;
    u8 b[5];
    s32 c;
    Unk021da1fc *d;
    a = data_ov003_021d7310;
    b[0] = data_ov003_021d7300[0];
    b[1] = data_ov003_021d7300[1];
    b[2] = data_ov003_021d7300[2];
    b[3] = data_ov003_021d7300[3];
    b[4] = data_ov003_021d7300[4];
    data_ov003_021da1fc = func_ov003_021d283c(0x18, 4);
    func_ov003_021c20dc(&c, NULL);
    a.mUnk_00[c](data_ov003_021da1fc->mUnk_08);
    d = data_ov003_021da1fc;
    if (memcmp(d->mUnk_08, data_ov003_021d73ac, 3) != 0) {
        d->mUnk_14 = 3;
    } else {
        MemFill(d->mUnk_08, 0, 0xc);
        data_ov003_021da1fc->mUnk_14 = 0;
    }
    func_ov003_021c76b4();
    func_ov003_021bf86c(c + 0xb);
    func_ov003_021bf43c(b[c], -1, 0);
    func_ov003_021bf5ec(2);
    data_ov003_021da1fc->mUnk_00 = func_ov003_021d2288(0, 0);
    data_ov003_021da1fc->mUnk_04 = func_ov003_021d1c18(0, 0x3f);
    data_ov003_021da1fc->mUnk_04->mUnk_04 = (data_ov003_021da1fc->mUnk_04->mUnk_04 & 0xfffff3ff) | 0xc00;
    func_ov003_021c7160();
    func_ov003_021c71a0();
    func_ov003_021c212c(func_ov003_021c7678);
}

void func_ov003_021c76b4(void) {
    void *v2 = &data_ov003_021d7350;
    void *v3 = &func_0214c090;
    u32 v4 = func_ov003_021bf620(v2, v3);
    void *v5 = &data_ov003_021d7364;
    void *v6 = &func_0214b95c;
    u32 v7 = func_ov003_021bf620(v5, v6);
    void *v8 = &data_ov003_021d737c;
    void *v9 = &func_0214c160;
    u32 v10 = func_ov003_021bf620(v8, v9);
    void *v11 = &data_ov003_021d7394;
    void *v12 = &func_0214bc9c;
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

void func_ov003_021c7678(void) {
    func_ov003_021d1ee0(2, 1, (u32) 1, (u16) 8);
    func_ov003_021d1ee0(2, 0, (u32) 0x15, (u16) 8);
    func_ov003_021d2784(1, (u32) 1);
    func_ov003_021d2784(0, (u32) 0x15);
    func_ov003_021c212c(func_ov003_021c7614);
}

void func_ov003_021c7614(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if ((v1 == 0) && (v1 = func_ov003_021d1f70(0), v1 == 0)) {
        func_ov003_021c1cd8();
        func_ov003_021cdc10((u32) 0x14);
        if (data_ov003_021da1fc->mUnk_14 == 0) {
            func_ov003_021c1c90((u8) 0);
            func_ov003_021c1c70((u8) 0);
        } else {
            v1 = func_ov003_021c735c(0x1a);
            if (v1 != 0) {
                func_ov003_021c1c80((u8) 0);
            }
            func_ov003_021c1c70((u8) 0);
        }
        func_ov003_021c212c(func_ov003_021c75f8);
    }
}

void func_ov003_021c75f8(void) {
    if (func_ov003_021c1ca0() != 31) {
        func_ov003_021c212c(func_ov003_021c75e4);
    }
}

void func_ov003_021c75e4(void) {
    func_ov003_021c73cc();
    func_ov003_021c7358();
    return;
}
