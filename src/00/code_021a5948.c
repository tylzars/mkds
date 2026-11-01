#include "00/code_021a5948.h"
#include "00/code_021a58dc.h"
#include "00/code_021a5b3c.h"
#include "code_02142eac.h"
#include "code_0214d018.h"

void func_ov000_021a5a78(Unk021a5a78 *a, void (*b)(Unk021a586c *)) {
    u8 *p;

    if (a == 0) {
        data_ov000_021b5f50->mUnk_226c = 3;
        data_ov000_021b5f50->mUnk_2270 = 0;
        data_ov000_021b5f50->mUnk_2274 = 0;
        data_ov000_021b5f50->mUnk_2278 = 0;
    } else {
        data_ov000_021b5f50->mUnk_226c = a->mUnk_00 & 3;
        p = a->mUnk_04;
        if ((((4 - ((u32) p & 3)) & 3) + 0xc) > a->mUnk_08) {
            data_ov000_021b5f50->mUnk_2270 = 0;
            data_ov000_021b5f50->mUnk_2274 = 0;
        } else {
            data_ov000_021b5f50->mUnk_2270 = (Unk021b5f50_2270 *) (((u32) p + 3) & ~3);
            data_ov000_021b5f50->mUnk_2274 = a->mUnk_08 - ((4 - ((u32) a->mUnk_04 & 3)) & 3);
            func_0214d168(data_ov000_021b5f50->mUnk_2270, 0, data_ov000_021b5f50->mUnk_2274);
        }
        data_ov000_021b5f50->mUnk_2278 = a->mUnk_0c;
    }
    data_ov000_021b5f50->mUnk_227c = b;
}

void func_ov000_021a5948(const void *a, const u8 *b, u32 c) {
    u16 v;
    s32 i;

    func_ov000_021a5b3c(c);
    data_ov000_021b5f50->mUnk_2288.mUnk_00 = data_ov000_021b5f50->mUnk_1500;
    data_ov000_021b5f50->mUnk_2288.mUnk_04 = 0x400;
    data_ov000_021b5f50->mUnk_2288.mUnk_06 = (1 << func_ov000_021a58dc(0)) >> 1;
    v = data_ov000_021b5f50->mUnk_2268;
    if (v == 0) {
        v = func_02143090();
    }
    data_ov000_021b5f50->mUnk_2288.mUnk_08 = v;
    data_ov000_021b5f50->mUnk_2288.mUnk_10 = (data_ov000_021b5f50->mUnk_2264 & 0x300000) != 0x300000;
    if (a == 0) {
        func_0214d1fc(data_ov000_021b07bc, data_ov000_021b5f50->mUnk_2288.mUnk_0a, 6);
    } else {
        func_0214d1fc(a, data_ov000_021b5f50->mUnk_2288.mUnk_0a, 6);
    }
    if (b == 0 || b == data_ov000_021b07c4) {
        func_0214d1fc(data_ov000_021b07c4, data_ov000_021b5f50->mUnk_2288.mUnk_14, 0x20);
        data_ov000_021b5f50->mUnk_2288.mUnk_12 = 0;
    } else {
        func_0214d1fc(b, data_ov000_021b5f50->mUnk_2288.mUnk_14, 0x20);
        for (i = 0; i < 0x20; i++) {
            if (*b == 0) {
                break;
            }
            b++;
        }
        data_ov000_021b5f50->mUnk_2288.mUnk_12 = i;
    }
    data_ov000_021b5f50->mUnk_2284 = 0;
}
