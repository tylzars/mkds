#include "03/code_021c8e48.h"
#include "03/code_021c209c.h"
#include "03/code_021c8000.h"
#include "03/code_021d1dd0.h"
#include "03/unk_021da000.h"
#include "03/code_021ccd18.h"
#include "03/code_021d1000.h"
#include "03/code_021d1f70.h"
#include "03/code_021b94b8.h"
#include "03/code_021cd4ac.h"

#include "03/code_021bf698.h"
#include "03/code_021c85a0.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d3000.h"
#include "03/code_021d3488.h"
#include "code_02133048.h"
#include "code_02147cd8.h"

void func_ov003_021c9058(u32 a) {
    int v1;
    v1 = func_ov003_021cdb6c();
    if (*(u8 *) (v1 + 0xf6) != a) {
        data_ov003_021da214->mUnk_43 = (s8) a;
        func_ov003_021cdb44(a);
        func_ov003_021c8b94();
    }
    return;
}

void func_ov003_021c8ea0(void) {
    int a;
    Unk021da214 *s;
    s = data_ov003_021da214;
    if (s->mUnk_38 == 0) {
        if (s->mUnk_41 != 0) {
            s->mUnk_41--;
        }
        switch (func_ov003_021cce60()) {
            case 1:
                data_ov003_021da214->mUnk_45 = 1;
                break;
            case 2:
                if (data_ov003_021da214->mUnk_41 != 0) {
                    return;
                }
                func_ov003_021bf698();
                *(u16 *) &data_ov003_021da210 = _s32_div_f(func_ov003_021cce6c() * 0x91, 0x37);
                func_ov003_021c8b94();
                data_ov003_021da214->mUnk_41 = 4;
                break;
            case 3:
                data_ov003_021da214->mUnk_45 = 0;
                *(u16 *) &data_ov003_021da210 = _s32_div_f(func_ov003_021cce6c() * 0x91, 0x37);
                func_ov003_021cdc10(0x13);
                func_ov003_021c8b94();
                a = func_02147cd8(*(u16 *) &data_ov003_021da210, 0x1d);
                if (a == 0) {
                    func_ov003_021c812c();
                    return;
                }
                if (a < 0x10) {
                    data_ov003_021da214->mUnk_38 = func_ov003_021d3544(0, func_ov003_021c8320, NULL, 0x78);
                } else {
                    data_ov003_021da214->mUnk_38 = func_ov003_021d3544(0, func_ov003_021c82b4, NULL, 0x78);
                }
                break;
            case 4:
                if (*(u16 *) &data_ov003_021da210 == 0) {
                    if (data_ov003_021da214->mUnk_46 != 0) {
                        return;
                    }
                    func_ov003_021cdc10(9);
                    data_ov003_021da214->mUnk_46 = 1;
                } else {
                    func_ov003_021cdc10(0x13);
                    data_ov003_021da214->mUnk_38 = func_ov003_021d3544(0, func_ov003_021c8320, NULL, 0x78);
                }
                break;
            case 6:
                if (*(u16 *) &data_ov003_021da210 == 0x91) {
                    if (data_ov003_021da214->mUnk_46 != 0) {
                        return;
                    }
                    func_ov003_021cdc10(9);
                    data_ov003_021da214->mUnk_46 = 1;
                } else {
                    func_ov003_021cdc10(0x13);
                    data_ov003_021da214->mUnk_38 = func_ov003_021d3544(0, func_ov003_021c82b4, NULL, 0x78);
                }
                break;
            case 5:
            case 7:
                data_ov003_021da214->mUnk_46 = 0;
                break;
        }
    }
}

void func_ov003_021c8e80(void) {
    func_ov003_021cce38();
    func_ov003_021d1dd0((u16) (8));
    func_ov003_021c212c(func_ov003_021c8e48);
    return;
}

void func_ov003_021c8e48(void) {
    int v1;
    v1 = func_ov003_021d1f70(1);
    if (v1 == 0) {
        func_ov003_021d1ee0(3, 1, 1, (u16) (8));
        func_ov003_021d1ee0(3, 0, 0x1d, (u16) (8));
        func_ov003_021c212c(func_ov003_021c8c14);
    }
    return;
}
