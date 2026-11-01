#include "03/code_021bf4f4.h"
#include "03/code_021c2530.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d211c.h"
#include "03/unk_021d5000.h"

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
