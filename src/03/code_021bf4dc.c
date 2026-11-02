#include "03/code_021bf4dc.h"
#include "03/code_021d1fd0.h"
#include "03/unk_021da000.h"
#include "03/code_021bf410.h"
#include "03/code_021bf000.h"
#include "03/code_021c2000.h"
#include "03/code_021ce000.h"
#include "03/code_021d1440.h"

#include "03/code_021c2530.h"
#include "03/unk_021d5000.h"
#include "03/code_021d1000.h"
#include "03/code_021c209c.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_02139f70.h"

u8 *func_ov003_021bf650(const u8 *param_0) {
    u32 a;

    func_0213a228(data_ov003_021da110, param_0, 0x3f);
    if (param_0[5] == 0x78) {
        return data_ov003_021da110;
    }
    a = func_ov003_021c20d0();
    if (param_0[5] == 0x79 && a != 0) {
        return data_ov003_021da110;
    }
    data_ov003_021da110[5] = data_ov003_021d5f04[a];
    return data_ov003_021da110;
}

u32 func_ov003_021bf620(void *param_0, void *param_1) {
    u32 a;
    void *b;

    b = func_ov003_021d14b8(func_ov003_021bf650((const u8 *) param_0), &a, 4);
    func_0200ee74(b, a);
    ((void (*)(void *, u32, u32)) param_1)(b, 0, a);
    func_ov003_021d1490(b);
}

void func_ov003_021bf5ec(u32 param_1) {
    int v1[2];
    func_ov003_021c2104(v1, 0);
    if (v1[0] == 1) {
        func_ov003_021ce408(param_1);
        return;
    }
    if (v1[0] == 2) {
        func_ov003_021ce024(param_1);
    }
    return;
}

void func_ov003_021bf5c8(u32 param_1) {
    int v1[2];
    func_ov003_021c2104(0, v1);
    if (v1[0] == 1) {
        func_ov003_021bf364(param_1);
    }
    return;
}

void func_ov003_021bf578(u32 param_0) {
    void *a;
    void *b;

    a = func_ov003_021d2288(0, 0);
    b = (void *) func_ov003_021c2530((int *) data_ov003_021da19c, param_0);
    func_ov003_021d2070(a, data_ov003_021d5f0c[0], data_ov003_021d5f0c[1], data_ov003_021d5f0c[2],
                        data_ov003_021d5f0c[3], 2, func_ov003_021bf4dc(), b);
    func_ov003_021d1fd0(a);
}

void func_ov003_021bf4f4(u32 param_0, u32 param_1) {
    void *a;
    void *b;

    a = func_ov003_021d2288(0, 0);
    b = (void *) func_ov003_021c2530((int *) data_ov003_021da19c, param_1);
    func_ov003_021d2070(a, data_ov003_021d5f14[0], data_ov003_021d5f14[1], data_ov003_021d5f14[2],
                        data_ov003_021d5f14[3], 2, func_ov003_021bf4dc(), b);
    func_ov003_021d214c((u32) a, data_ov003_021d5f34[func_ov003_021c20d0() * 2],
                        data_ov003_021d5f36[func_ov003_021c20d0() * 2], 2, 0x209, param_0);
    func_ov003_021d1fd0(a);
}

u32 func_ov003_021bf4dc(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) func_ov003_021c20d0();
    value1 = (value0 << 2);
    value0 = (u32) &data_ov003_021d5f1c;
    value0 = (u32) * (const u32 *) ((value0) + (value1));
    return value0;
}
