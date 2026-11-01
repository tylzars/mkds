#include "03/code_021d0850.h"
#include "03/code_021cf260.h"
#include "03/code_021cef90.h"
#include "03/code_021cfb98.h"
#include "03/code_021d010c.h"
#include "03/unk_021da000.h"
#include "code_0214d018.h"

void func_ov003_021d0850(void) {
    s32 i;
    Unk021da2ac *p;
    Unk021da2ac_100 *e;

    for (i = 0; i < 16; i++) {
        p = data_ov003_021da2ac;
        if (p->mUnk_208[i] != 0) {
            e = &p->mUnk_100[(u32) i];
            if (i == 1) {
                if (p->mUnk_a93 == 1) {
                    if (e->mUnk_00 != 0x10) {
                        return;
                    }
                    p->mUnk_a94 = p->mUnk_a94 + 1;
                    if ((data_ov003_021da2ac->mUnk_a94 & 1) == 0) {
                        data_ov003_021da2ac->mUnk_200 = data_ov003_021da2ac->mUnk_200 + 1;
                        if (data_ov003_021da2ac->mUnk_200 >= 0x24) {
                            data_ov003_021da2ac->mUnk_200 = 0;
                        }
                    }
                } else {
                    p->mUnk_202 = 0xbc;
                    if (e->mUnk_00 == 0xbd) {
                        data_ov003_021da2ac->mUnk_a93 = 1;
                        data_ov003_021da2ac->mUnk_200 = 0;
                        data_ov003_021da2ac->mUnk_a94 = 0;
                    }
                }
            }
        }
    }
}

void func_ov003_021d0900(u16 param_1, u16 param_2, u8 *param_3) {
    u16 i;

    if (data_ov003_021da2ac->mUnk_a93 == 1) {
        data_ov003_021da2ac->mUnk_ab0->mUnk_00 = param_1;
        data_ov003_021da2ac->mUnk_ab0->mUnk_02 = param_2;
        func_0214d1fc(param_3, data_ov003_021da2ac->mUnk_ab0->mUnk_04, 0x40);
    } else {
        data_ov003_021da2ac->mUnk_204 = data_ov003_021da2ac->mUnk_204 + 1;
        data_ov003_021da2ac->mUnk_ab0->mUnk_00 = 0xbc;
        data_ov003_021da2ac->mUnk_ab0->mUnk_04[0] = data_ov003_021da2ac->mUnk_a92;
    }
    if (func_ov003_021d010c() == 5) {
        if (func_ov003_021cfb98(data_ov003_021da2ac) == 0) {
            data_ov003_021da2ac->mUnk_204 = data_ov003_021da2ac->mUnk_204 + 4;
            return;
        }
        if (data_ov003_021da2ac->mUnk_a93 == 0) {
            data_ov003_021da2ac->mUnk_204 = data_ov003_021da2ac->mUnk_204 + 1;
        } else {
            data_ov003_021da2ac->mUnk_204 = 0;
            if (func_ov003_021d0118() != 3) {
                data_ov003_021da2ac->mUnk_a90 = 0x1b;
                return;
            }
        }
        for (i = 0; i < 2; i++) {
            u8 *p = func_ov003_021cfc1c(i);
            if (p != 0) {
                func_0214d1fc(p, &data_ov003_021da2ac->mUnk_100[i], 0x44);
                data_ov003_021da2ac->mUnk_208[i] = 1;
            } else {
                data_ov003_021da2ac->mUnk_208[i] = 0;
            }
        }
    }
}

void func_ov003_021d0a18(void) {
    func_0214d168(data_ov003_021da2ac->mUnk_100, 0, 0x100);
    func_0214d168(data_ov003_021da2ac, 0, 0x100);
    data_ov003_021da2ac->mUnk_ab0 = (Unk021da2ac_100 *) data_ov003_021da2ac;
}

u32 func_ov003_021d0a50(Unk021425e8 *v1) {
    u16 r = func_ov003_021cf1e8(v1->mUnk_0a);
    if (r == 0) {
        return 0;
    }
    data_ov003_021da2ac->mUnk_aa0[r - 1] = func_ov003_021cf260(r);
    return 1;
}
