#include "03/code_021c5cdc.h"
#include "03/code_021bf2d0.h"
#include "03/code_021bf344.h"
#include "03/code_021bf410.h"
#include "03/code_021bf698.h"
#include "03/code_021c20f8.h"
#include "03/code_021c2120.h"
#include "03/code_021c5c68.h"
#include "03/code_021cb000.h"
#include "03/code_021cca10.h"
#include "03/code_021cd000.h"
#include "03/code_021cd27c.h"
#include "03/code_021cdb14.h"
#include "03/code_021d1000.h"
#include "03/code_021d1f70.h"
#include "03/code_021d254c.h"
#include "03/code_021d2f00.h"
#include "03/code_021d2188.h"
#include "03/code_021d27d8.h"
#include "03/code_021d34c0.h"
#include "03/unk_021da000.h"
#include "03/code_021c5724.h"

void func_ov003_021c5cdc(void) {
    int i;
    Unk021c5c68State *s;
    if (func_ov003_021d1f70(1) != 0) {
        return;
    }
    if (func_ov003_021d1f70(0) != 0) {
        return;
    }
    if (func_ov003_021bf2f0() == 0) {
        return;
    }
    func_ov003_021d34c0(1, data_ov003_021da1f4->mUnk_3c);
    for (i = 0; i < 5; i++) {
        if (data_ov003_021da1f4->mUnk_10[i] != 0) {
            func_ov003_021d2f00((u32 *) data_ov003_021da1f4->mUnk_10[i]);
        }
        if (data_ov003_021da1f4->mUnk_24[i] != 0) {
            func_ov003_021d2f00((u32 *) data_ov003_021da1f4->mUnk_24[i]);
        }
    }
    func_ov003_021d2188(data_ov003_021da1f4->mUnk_0c);
    func_ov003_021cce78();
    func_ov003_021bf698();
    func_ov003_021bf410();
    func_ov003_021cca10();
    func_ov003_021d1490(data_ov003_021da1f4->mUnk_04);
    func_ov003_021d1490(data_ov003_021da1f4->mUnk_08);
    func_ov003_021d272c(1, 1);
    func_ov003_021d272c(0, 0x1d);
    *(vu32 *) 0x4000010 = 0;
    *(vu32 *) 0x4000018 = 0;
    s = data_ov003_021da1f4;
    if (s->mUnk_54 == 0) {
        func_ov003_021cd27c();
        func_ov003_021cd790(*(u8 *) (func_ov003_021cdb6c() + 0xf4));
        func_ov003_021c2120(2, 0);
        func_ov003_021c212c(func_ov003_021cb7fc);
    } else if (data_ov003_021da1ec == 4) {
        func_ov003_021cd27c();
        func_ov003_021c2120(0, 1);
        func_ov003_021c212c(func_ov003_021ca8e8);
    } else {
        func_ov003_021cdb14(s->mUnk_00 + s->mUnk_52 * 0x2a);
        func_ov003_021c2120(0, 0);
        if ((data_ov003_021da1f4->mUnk_00 + data_ov003_021da1f4->mUnk_52 * 0x2a)[0x28] != 0) {
            func_ov003_021c2120(0, 1);
            func_ov003_021c20f8(1, 1);
            func_ov003_021c212c(func_ov003_021c6e38);
        } else {
            func_ov003_021c2120(0, 1);
            func_ov003_021c20f8(0, 1);
            func_ov003_021c212c(func_ov003_021cbf60);
        }
    }
    func_ov003_021d2808(&data_ov003_021da1f4);
}

void func_ov003_021c5e54(void) {
    if (func_ov003_021d1f70(1) == 0) {
        if (data_ov003_021da1f4->mUnk_54 != 0) {
            func_ov003_021bf344();
        } else {
            func_ov003_021bf2d0();
        }
        func_ov003_021d1ee0(3, 1, 1, 8);
        func_ov003_021d1ee0(3, 0, 0x1d, 8);
        func_ov003_021c212c(func_ov003_021c5cdc);
    }
}
