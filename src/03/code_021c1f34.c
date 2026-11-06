#include "03/code_021c1f34.h"
#include "03/code_021cd000.h"

#include "03/code_021b94b8.h"
#include "03/code_021cd2e0.h"
#include "03/unk_021da000.h"
#include "03/code_021d27d8.h"
#include "03/code_021c1f20.h"
#include "03/code_021c1f28.h"
#include "03/unk_021d6000.h"
#include "code_0200fc8c.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"

void func_ov003_021c1fc8(void) {
    Unk021c1fc8 a;
    Unk021b94c4 *p;
    data_ov003_021da168 = func_ov003_021d283c(0x26c, 4);
    data_ov003_021da164[0] = 0;
    a.mUnk_00 = 0;
    MIi_CpuClear16(a.mUnk_00, &a.mUnk_02, 0x104);
    a.mUnk_02 = 0x50;
    a.mUnk_04 = 0xc;
    MI_CpuCopy8(data_ov003_021d630c, a.mUnk_06, 0xc);
    data_ov003_021da168->mUnk_000 = 3;
    p = data_ov003_021da168;
    *(Unk021c1fc8_02 *) &p->mUnk_002 = *(Unk021c1fc8_02 *) &a.mUnk_02;
    p->mUnk_106 = 1;
    data_ov003_021da168->mUnk_108 = -1;
    data_ov003_021da168->mUnk_10a = 1;
    data_ov003_021da168->mUnk_10c = -1;
    data_ov003_021da168->mUnk_10e = -1;
    OS_GetMacAddress(data_ov003_021da168->mUnk_110);
    if (func_ov003_021ba61c((void *(*) (u32)) func_ov003_021c1f28, func_ov003_021c1f20) != 0) {
        OS_Terminate();
    }
}

void func_ov003_021c1f84(int a) {
    func_ov003_021ba560();
    if (((a != 0) && (data_ov003_021da168->mUnk_116 == 0)) && ((*(u8 *) &data_ov003_021da164) == 1)) {
        func_ov003_021cd4e8((s32) &data_ov003_021da168->mUnk_117);
    }
    func_ov003_021d2808(&data_ov003_021da168);
}

u32 func_ov003_021c1f34(void) {
    u8 a;
    if (func_ov003_021ba05c(data_ov003_021da168) == 0) {
        data_ov003_021da164[0] = 1;
        return 1;
    }
    a = data_ov003_021da168->mUnk_116;
    if (a == 1 || (u8) (a + 253) <= 2) {
        return 0;
    }
    return 2;
}
