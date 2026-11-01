#include "03/code_021d11d4.h"
#include "03/code_021cd4ac.h"
#include "03/code_021cfa30.h"
#include "03/code_021cfde4.h"
#include "03/code_021d0000.h"
#include "03/code_021d010c.h"
#include "Main/Unknown/code_02009c04.h"
#include "code_0200f5ac.h"
#include "code_02142eac.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_02151718.h"

void func_ov003_021d1358(Unk021da2ac *param_1, Unk021d1358 *param_2) {
    data_ov003_021da2ac = param_1;
    func_ov003_021cfa30(param_1->mUnk_b00);
    data_ov003_021da2ac->mUnk_648 = 0;
    data_ov003_021da2ac->mUnk_64a = 0;
    data_ov003_021da2ac->mUnk_a90 = 1;
    data_ov003_021da2ac->mUnk_a91 = 1;
    data_ov003_021da2ac->mUnk_a9c = 0;
    func_ov003_021d0a18();
    data_ov003_021da2ac->mUnk_ab4 = param_2->mUnk_00;
    data_ov003_021da2ac->mUnk_ab8 = param_2->mUnk_04;
    data_ov003_021da2ac->mUnk_abc = param_2->mUnk_08;
    data_ov003_021da2ac->mUnk_ac0 = param_2->mUnk_0c;
    data_ov003_021da2ac->mUnk_ac4 = param_2->mUnk_10;
    data_ov003_021da2ac->mUnk_ac8 = param_2->mUnk_14;
    data_ov003_021da2ac->mUnk_a92 = param_2->mUnk_18;
    data_ov003_021da2ac->mUnk_acc = 2;
    func_0200f5ac();
    func_02151804((u32) data_ov003_021da2ac->mUnk_64c);
    func_0200f5ac();
    data_ov003_021da2ac->mUnk_aa0[1] = (u8 *) func_ov003_021cd4dc();
}

u32 func_ov003_021d1290(void) {
    Unk021da2ac *a = data_ov003_021da2ac;
    u8 *p = &a->mUnk_a90;
    u8 b = *p;

    if (b == 1 || b == 0x14 || b == 0x17 || b == 0x1a || b == 0x1d) {
        a->mUnk_a90 = 0x22;
        data_ov003_021da2ac->mUnk_aac = 0;
        return 1;
    }
    if (b == 4 || b == 5 || b == 6 || b == 0xd) {
        if (b == 4 && a->mUnk_a98 < 6) {
            return 0;
        }
        func_02009c04();
        data_ov003_021da2ac->mUnk_a90 = 0x10;
        data_ov003_021da2ac->mUnk_aac = 2;
        return 1;
    }
    if (b == 9 || b == 10) {
        *p = 0x20;
        return 1;
    }
    if (b == 0xc) {
        *p = 0x22;
        return 1;
    }
    switch (b) {
        case 2:
            return 0;
        default:
            return 0;
    }
}

void func_ov003_021d1218(void) {
    func_ov003_021d0128(data_ov003_021da2ac->mUnk_ac8);
    data_ov003_021da2ac->mUnk_a90 = 1;
    data_ov003_021da2ac->mUnk_648 = func_02142eac();
    func_0214d1fc(data_ov003_021da2ac->mUnk_aa0[1], data_ov003_021da2ac->mUnk_a50, 0x40);
    data_ov003_021da2ac->mUnk_a93 = 0;
    data_ov003_021da2ac->mUnk_204 = 0;
    data_ov003_021da2ac->mUnk_648++;
}

u32 func_ov003_021d11d4(void) {
    if (data_ov003_021da2ac->mUnk_a90 == 1 || data_ov003_021da2ac->mUnk_a90 == 0x1a ||
        data_ov003_021da2ac->mUnk_a90 == 0x1d) {
        func_ov003_021d1218();
        func_ov003_021cfde4();
        data_ov003_021da2ac->mUnk_a90 = 2;
        return 1;
    }
    return 0;
}
