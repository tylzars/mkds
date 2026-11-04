#include "03/code_021bf4dc.h"
#include "03/code_021bf810.h"
#include "03/code_021cbf60.h"
#include "03/code_021cbfa4.h"
#include "03/code_021bf410.h"
#include "03/code_021c2000.h"
#include "03/code_021cb000.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d1000.h"
#include "03/code_021bf000.h"
#include "03/code_021bf098.h"
#include "03/code_021cc000.h"
#include "03/code_021cd000.h"
#include "03/code_021d1dd0.h"
#include "03/unk_021d7000.h"
#include "code_0214b824.h"

#include "03/code_021c209c.h"
#include "03/unk_021da000.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d254c.h"
#include "03/code_021d1f70.h"

void func_ov003_021cc110(void) {
    data_ov003_021da250 = 0;
    func_ov003_021cc0ac();
    func_ov003_021bf86c(8);
    func_ov003_021bf578(0x6f);
    func_ov003_021cdc10(0x10);
    func_ov003_021c212c(func_ov003_021cc084);
}

void func_ov003_021cc0ac(void) {
    void *v2 = &data_ov003_021d7728;
    void *v3 = &MemCopyHalfwordsToG2Bg2CntBits8To12Address;
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

void func_ov003_021cc084(void) {
    func_ov003_021d1ee0(2, 0, 0x15, 8);
    func_ov003_021d2784(0, 0x15);
    func_ov003_021c212c(func_ov003_021cc064);
}

void func_ov003_021cc064(void) {
    if (func_ov003_021d1f70(0) == 0) {
        func_ov003_021c212c(func_ov003_021cc050);
    }
}

void func_ov003_021cc050(void) {
    func_ov003_021cbfa4();
    func_ov003_021cc04c();
    return;
}

void func_ov003_021cc04c(void) {
    return;
}

void func_ov003_021cc020(void) {
    func_ov003_021d1ee0(3, 1, 1, (u16) (8));
    func_ov003_021d1ee0(3, 0, 0x15, (u16) (8));
    func_ov003_021c212c(func_ov003_021cbfcc);
    return;
}

void func_ov003_021cbfcc(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if ((v1 == 0) && (v1 = func_ov003_021d1f70(0), v1 == 0)) {
        func_ov003_021d2168(0);
        func_ov003_021bf410();
        func_ov003_021d272c(1, 1);
        func_ov003_021d272c(0, 0x15);
        func_ov003_021c2120(0, 0);
        func_ov003_021c20f8(0, 2);
        func_ov003_021c212c(func_ov003_021cbf60);
    }
    return;
}

void func_ov003_021cbfa4(void) {
    data_ov003_021da250++;
    if (data_ov003_021da250 >= 120) {
        func_ov003_021c212c(func_ov003_021cc020);
    }
}
