#include "03/code_021d0acc.h"
#include "03/code_021cfc4c.h"
#include "03/code_021d010c.h"
#include "03/code_021d083c.h"
#include "03/code_021d0850.h"
#include "03/unk_021da000.h"

void func_ov003_021d0acc(void) {
    u16 a;
    s32 b;

    switch (func_ov003_021d010c()) {
        case 1:
            func_ov003_021cfc4c(4, data_ov003_021da2ac->mUnk_648 + 1, data_ov003_021da2ac->mUnk_64a);
            break;
        case 4:
        case 5:
        case 6:
            a = data_ov003_021da2ac->mUnk_200;
            b = a % 16;
            func_ov003_021d0900(0, a, data_ov003_021da2ac->mUnk_aa0[1] + (b << 6));
            func_ov003_021d0850();
            if (data_ov003_021da2ac->mUnk_a90 != 0x1b) {
                if (data_ov003_021da2ac->mUnk_204 > 0x1e0) {
                    data_ov003_021da2ac->mUnk_a90 = 0x1b;
                    return;
                }
                if (func_ov003_021d083c() == 0x10 || func_ov003_021d083c() == 0x20) {
                    func_ov003_021d083c();
                    data_ov003_021da2ac->mUnk_a90 = 0xa;
                } else if (func_ov003_021d083c() == 0x40) {
                    data_ov003_021da2ac->mUnk_a90 = 0xb;
                } else if (func_ov003_021d083c() == 0xff) {
                    data_ov003_021da2ac->mUnk_a90 = 0x1b;
                } else if (func_ov003_021d083c() == 0x50) {
                    data_ov003_021da2ac->mUnk_a90 = 0x15;
                } else if (func_ov003_021d083c() == 0x60) {
                    data_ov003_021da2ac->mUnk_a90 = 0x18;
                } else if (func_ov003_021d083c() == 0x70) {
                    data_ov003_021da2ac->mUnk_a90 = 0x1b;
                } else if (func_ov003_021d083c() == 0) {
                    data_ov003_021da2ac->mUnk_a90 = 8;
                } else if (func_ov003_021d083c() == 0xbd) {
                    data_ov003_021da2ac->mUnk_a90 = 9;
                } else {
                    data_ov003_021da2ac->mUnk_a90 = 0x1f;
                }
            }
            break;
    }
}
