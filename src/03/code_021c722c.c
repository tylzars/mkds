#include "03/code_021bf4dc.h"
#include "03/code_021c722c.h"
#include "03/code_021bf000.h"
#include "03/code_021bf410.h"
#include "03/code_021c2000.h"
#include "03/code_021c209c.h"
#include "03/code_021c9000.h"
#include "03/code_021c9500.h"
#include "03/code_021cdbd0.h"
#include "03/code_021cef90.h"
#include "03/code_021d1dd0.h"
#include "03/unk_021d7000.h"
#include "03/unk_021da000.h"
#include "code_0214b824.h"
#include "03/code_021c1c5c.h"
#include "03/code_021c6f08.h"
#include "03/code_021ce000.h"
#include "03/code_021c7000.h"
#include "03/code_021cd000.h"
#include "03/code_021d1000.h"
#include "03/code_021d1f70.h"

#include "03/code_021c70a4.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d254c.h"
#include "03/code_021d27d8.h"
#include "03/code_021d2ecc.h"

void func_ov003_021c7358(void) {
    return;
}

void func_ov003_021c733c(void) {
    func_ov003_021d1dd0((u16) (8));
    func_ov003_021c212c(func_ov003_021c7314);
    return;
}

void func_ov003_021c7314(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if (v1 == 0) {
        func_ov003_021c1cb0();
        func_ov003_021cdc10(0x15);
        func_ov003_021c212c(func_ov003_021c72a4);
    }
    return;
}

void func_ov003_021c72a4(void) {
    u8 a;
    if (func_ov003_021c1c5c() == 0) {
        a = data_ov003_021da1fc->mUnk_15;
        if (a == 0) {
            func_ov003_021c212c(func_ov003_021c722c);
            return;
        }
        if (a == 2) {
            func_ov003_021cefc0(0x2f, 3, 1, -1, 0);
            func_ov003_021c212c(func_ov003_021c6f3c);
            return;
        }
        func_ov003_021cefc0(0x9b, 2, 1, -1, 0);
        func_ov003_021c212c(func_ov003_021c7118);
    }
}

void func_ov003_021c722c(void) {
    int v1[1];
    func_ov003_021bf410();
    func_ov003_021d2f00((u32 *) (u32) (data_ov003_021da1fc->mUnk_04));
    func_ov003_021d2168(0);
    func_ov003_021bf620(&data_ov003_021d7338, &func_0214c090);
    func_ov003_021d272c(1, (u32) 1);
    func_ov003_021d272c(0, (u32) 0x15);
    func_ov003_021c20dc(v1, NULL);
    if (3 <= v1[0]) {
        v1[0] = v1[0] + 1;
    }
    func_ov003_021c2120((u32) 2, (u32) 1);
    func_ov003_021c20f8((u32) 0, (u32) (v1[0] + 3));
    func_ov003_021c212c(func_ov003_021c965c);
    func_ov003_021d2808(&data_ov003_021da1fc);
}
