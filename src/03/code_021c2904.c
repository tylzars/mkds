#include "03/code_021c2904.h"
#include "03/unk_021d8000.h"

#include "03/unk_021da000.h"
#include "03/code_021d1c18.h"
#include "03/code_021cd4ac.h"
#include "03/code_021bb03c.h"
#include "03/code_021bf698.h"
#include "03/code_021bf810.h"
#include "03/code_021c209c.h"
#include "03/code_021c2530.h"
#include "03/code_021c28f0.h"
#include "03/code_021c28f8.h"
#include "03/code_021bf4dc.h"
#include "03/code_021d1fd0.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf410.h"
#include "03/code_021d1f70.h"
#include "03/code_021d27d8.h"
#include "code_0200db4c.h"
#include "code_0200fc8c.h"

void func_ov003_021c2a28(void) {
    if (func_ov003_021d1f70(1) == 0 && func_ov003_021d1f70(0) == 0) {
        func_ov003_021d1c90(1);
        func_ov003_021d1c90(0);
        func_ov003_021bf8b0();
        func_ov003_021bf7dc();
        func_ov003_021c2544((s32) data_ov003_021da19c);
        func_ov003_021c25a4();
        func_ov003_021cdb80();
        func_ov003_021c209c();
    }
}

void func_ov003_021c29d8(void) {
    data_ov003_021da198 = func_ov003_021d283c(0xc, -4);
    if (func_ov003_021bb168(0xf, 0x40, func_ov003_021c2904, func_ov003_021c28f8, func_ov003_021c28f0, 0x800) != 1) {
        IrqDisableLoopForever();
    }
    func_0200dc3c(0xa);
}

void func_ov003_021c29b8(void) {
    if (func_ov003_021bb0b0() != 1) {
        IrqDisableLoopForever();
    }
    func_ov003_021d2808(&data_ov003_021da198);
}

u32 func_ov003_021c2938(void) {
    Unk021d8dc8 a;
    switch (data_ov003_021da198->mUnk_00) {
        case 0:
        case 1:
        case 3:
        case 5:
            return 0;
        case 2:
            return 1;
        case 4:
            return 2;
        case 6:
            if (func_ov003_021bb058(&a) != 1) {
                IrqDisableLoopForever();
            }
            if (a.mUnk_20 >= 0 && a.mUnk_20 <= 3 && a.mUnk_24 == 1) {
                return 3;
            }
            return 5;
        case 7:
            return 4;
    }
}

void func_ov003_021c2918(void) {
    Unk021d8dc8 a;
    if (func_ov003_021bb058(&a) != 1) {
        IrqDisableLoopForever();
    }
    func_ov003_021cd5e0((const Unk021cd5e0_arg *) &a);
}

void func_ov003_021c2904(const Unk021c2904 *value) {
    *data_ov003_021da198 = *value;
}
