#include "00/code_0219c824.h"
#include "00/code_0218ee1c.h"
#include "00/code_0219b000.h"
#include "00/code_0219c000.h"
#include "00/code_0219d000.h"
#include "00/code_021a1ae0.h"
#include "00/unk_021b4000.h"

s32 func_ov000_0219c8dc(s32 a) {
    s32 x;
    s32 y;
    if (a == 0) {
        return 0;
    }
    switch (a) {
        case 1:
            x = 0xb;
            y = -1;
            break;
        case 2:
            x = 0xb;
            y = -2;
            break;
        case 3:
            x = 6;
            y = -10;
            break;
        case 4:
            x = 6;
            y = -20;
            break;
    }
    func_ov000_0219c990(x, y - 0xee48);
    return a;
}

void func_ov000_0219c824(Unk0218f960 *a, Unk0219c400 *b, u32 c) {
    data_ov000_021b565c->mUnk_34 = 0;
    if (b->mUnk_00 == 0) {
        if (data_ov000_021b565c->mUnk_04 == 2) {
            if (func_ov000_0219c8dc(func_ov000_0219d558(1, data_ov000_021b4064, 0)) == 0) {
                if (data_ov000_021b565c->mUnk_20->mUnk_1c == b->mUnk_04) {
                    if (func_ov000_0219ba20() == 0 && func_ov000_021a2768(b->mUnk_04) == 0) {
                        data_ov000_021b565c->mUnk_04 = 5;
                        data_ov000_021b565c->mUnk_18(0, b->mUnk_04, data_ov000_021b565c->mUnk_1c);
                    }
                } else {
                    func_ov000_0219c990(6, -60000);
                }
            }
        } else if (data_ov000_021b565c->mUnk_04 == 3) {
            if (func_ov000_0219c8dc(func_ov000_0218eff8(a, b->mUnk_04, 0, 0, func_ov000_0219c400, 0)) != 0) {
                return;
            }
        }
    } else {
        func_ov000_0219c8dc(b->mUnk_00);
    }
}
