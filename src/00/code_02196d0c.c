#include "00/code_02196d0c.h"

const s8 *func_ov000_02196df0(const s8 *a, s32 b) {
    const s8 *c = a;
    s32 d = b - 6;
    if (d > 0) {
        do {
            if (c[0] == '\\' && c[1] == 'f' && c[2] == 'i' && c[3] == 'n' && c[4] == 'a' && c[5] == 'l' &&
                c[6] == '\\') {
                return c;
            }
            c++;
        } while (c - a < d);
    }
    return 0;
}

s32 func_ov000_02196d84(s32 a, s32 b, s32 c) {
    s32 d;
    Unk02196d84 *e;
    if (data_ov000_021b4e5c == 0) {
        return -1;
    }
    d = 0;
    if ((s32) func_ov000_0218dc44((u32 *) data_ov000_021b4e5c) > 0) {
        do {
            e = (Unk02196d84 *) func_ov000_0218dbf8(data_ov000_021b4e5c, d);
            if (e->mUnk_00 == a && e->mUnk_04 == b && e->mUnk_08 == c) {
                return d;
            }
            d++;
        } while (d < (s32) func_ov000_0218dc44((u32 *) data_ov000_021b4e5c));
    }
    return -1;
}

void func_ov000_02196d0c(u8 *param_1, s32 param_2) {
    s32 a = func_0213bf90((const u8 *) func_ov000_021970e4((const s8 *) param_1, data_ov000_021b3df0));
    s32 b = func_0213bf90((const u8 *) func_ov000_021970e4((const s8 *) param_1, data_ov000_021b3dc4));
    const s8 *c = func_ov000_021970e4((const s8 *) param_1, data_ov000_021b3df8);
    s32 d = func_ov000_02196d84(0, b, 0);
    if (d != -1) {
        Unk02196d84 *e = (Unk02196d84 *) func_ov000_0218dbf8(data_ov000_021b4e5c, d);
        e->mUnk_08 = a;
        func_ov000_021969d8(d, a > 0 ? 1 : 0, 0, (const u8 *) c, 0);
    }
}
