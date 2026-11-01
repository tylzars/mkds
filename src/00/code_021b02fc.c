#include "00/code_021b02fc.h"
#include "00/code_021adbac.h"
#include "00/code_021b04cc.h"
#include "00/code_021b04d0.h"
#include "02/unk_02180500.h"
#include "code_02133048.h"
#include "code_0200f5ac.h"
#include "code_0200fd1c.h"
#include "Main/Unknown/code_02000b44.h"

void func_ov000_021b02fc(Unk021b5fa8 *param_1) {
    func_02000b44(0x2000bfc);
    if (*(u64 *) &param_1->mUnk_14 != 0) {
        data_ov000_021b63e0[0] = *(u64 *) &param_1->mUnk_14;
        data_ov000_021b63e0[1] = 0x5d588b656c078965ULL;
        data_ov000_021b63e0[2] = 0x269ec3;
    } else {
        data_ov000_021b63e0[0] = func_0200f5ac();
        data_ov000_021b63e0[1] = 0x5d588b656c078965ULL;
        data_ov000_021b63e0[2] = 0x269ec3;
    }
    if (param_1->mUnk_04 != 0 && param_1->mUnk_08 != 0) {
        data_ov000_021b63a4 = (u8 * (*) (u32)) param_1->mUnk_04;
        data_ov000_021b63ac = param_1->mUnk_08;
    } else {
        data_ov000_021b63a4 = (u8 * (*) (u32)) func_ov000_021b04d0;
        data_ov000_021b63ac = (void (*)(void *)) func_ov000_021b04d0;
    }
    data_ov000_021b6398 = param_1->mUnk_00;
    if (param_1->mUnk_24 != 0) {
        data_ov000_021b6370 = param_1->mUnk_24;
    } else {
        data_ov000_021b6370 = 0x5b4;
    }
    data_ov000_021b63bc = param_1->mUnk_28;
    data_ov000_021b6390 = param_1->mUnk_2c;
    if (param_1->mUnk_0c != 0) {
        data_ov000_021b6384 = param_1->mUnk_0c;
    } else {
        data_ov000_021b6384 = func_ov000_021b04d0;
    }
    if (param_1->mUnk_10 != 0) {
        data_ov000_021b6388 = param_1->mUnk_10;
    } else {
        data_ov000_021b6388 = (u32(*)(void)) func_ov000_021b04cc;
    }
    data_ov000_021b63c4 = param_1->mUnk_1c;
    data_ov000_021b63c8 = param_1->mUnk_20;
    data_ov000_021b63cc = 0;
    data_ov000_021b6394 = 0;
    data_ov000_021b63e0[0] = _ll_mul(data_ov000_021b63e0[1], data_ov000_021b63e0[0]) + data_ov000_021b63e0[2];
    data_ov000_021b6374 = (_ll_mul(data_ov000_021b63e0[0] >> 32, 0xf88) >> 32) + 0x400;
    func_0200fe58(data_ov000_021b63d0);
    data_ov000_021b6368 = 0;
    func_0200e28c(&data_ov000_021b661c, (void (*)(void *)) func_ov000_021ae3a4, 0, data_ov002_021b7ba0, 0x800,
                  data_ov000_021b4c28);
    func_0200e28c(&data_ov000_021b655c, (void (*)(void *)) func_ov000_021ad898, 0, data_ov000_021b73a0, 0x800,
                  data_ov000_021b4c28);
    func_0200df68(&data_ov000_021b661c);
    func_0200df68(&data_ov000_021b655c);
}
