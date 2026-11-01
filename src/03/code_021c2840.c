#include "03/code_021c2840.h"
#include "03/code_021d11d4.h"
#include "03/code_021c20d0.h"
#include "03/code_021c2530.h"
#include "03/code_021d27d8.h"
#include "03/code_021d3544.h"
#include "03/code_021bf43c.h"
#include "code_0200fd1c.h"

void func_ov003_021c2840(u32 a) {
    Unk021d6e24 b;
    data_ov003_021da194 = func_ov003_021d285c(0x1e2a4, 0x20);
    data_ov003_021da194->mUnk_1e298 = (void (*)(s32)) a;
    data_ov003_021da194->mUnk_1e2a0 = 0;
    data_ov003_021da194->mUnk_1e2a1 = 0;
    b = data_ov003_021d6e24;
    b.mUnk_04 = func_ov003_021c2530((int *) data_ov003_021da19c, 0xf);
    b.mUnk_08 = func_ov003_021c2530((int *) data_ov003_021da19c, 0x10);
    b.mUnk_18 = func_ov003_021c20d0() + 0x31;
    func_ov003_021d1358((Unk021da2ac *) data_ov003_021da194, (Unk021d1358 *) &b);
    if (func_ov003_021d11d4() == 0) {
        func_0200fd1c();
    }
    data_ov003_021da194->mUnk_1e29c = func_ov003_021d3544(0, func_ov003_021c25e0, 0, 0x78);
}
