#include "00/code_0219dd4c.h"
#include "00/code_021a0958.h"
#include "00/unk_021b4000.h"
#include "00/unk_021b5000.h"
#include "00/code_0219e4e8.h"
#include "00/code_0219e134.h"
#include "00/code_021a01dc.h"
#include "code_02139f70.h"
#include "code_0214d018.h"

void func_ov000_0219ddbc(u32 a) {
    if (data_ov000_021b566c->mUnk_198 == 1) {
        data_ov000_021b566c->mUnk_198 = 6;
    } else if (data_ov000_021b566c->mUnk_198 != 6 && data_ov000_021b566c->mUnk_198 != 0xb) {
        return;
    }
    if (data_ov000_021b566c->mUnk_178 == a) {
        data_ov000_021b566c->mUnk_174[0]++;
    } else {
        data_ov000_021b566c->mUnk_174[0] = 0;
        data_ov000_021b566c->mUnk_178 = a;
    }
    data_ov000_021b566c->mUnk_17c = 0;
    if (func_ov000_0219e4a0(func_ov000_021a0cac(1, a, 0)) == 0) {
        data_ov000_021b566c->mUnk_3b4 = 0xff;
    }
}

void func_ov000_0219dd4c(const void *a, u32 b) {
    Unk0219dd4c c;
    u8 d[0x80];
    u32 e;
    e = 0;
    if (b >= 0x14) {
        do {
            func_0214d1fc(a, &c, 0x14);
            if (strncmp(c.mUnk_00, data_ov000_021b40bc, 4) != 0) {
                break;
            }
            if (c.mUnk_04 != 3) {
                break;
            }
            func_0214d1fc(a + 0x14, d, c.mUnk_09);
            if (func_ov000_021a01dc(c.mUnk_08, c.mUnk_10, c.mUnk_0c, c.mUnk_0a, (u32 *) d, c.mUnk_09 >> 2) == 0) {
                break;
            }
            e += c.mUnk_09 + 0x14;
        } while (e + 0x14 <= b);
    }
}
