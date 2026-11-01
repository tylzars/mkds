#include "00/code_02196b90.h"

void func_ov000_02196ca4(u8 *param_1, s32 param_2) {
    s32 a;
    s32 b;
    s32 t;
    Unk021969d8Entry *p;

    a = func_0213bf90((const u8 *) func_ov000_021970e4((const s8 *) param_1, data_ov000_021b3de8));
    b = func_0213bf90((const u8 *) func_ov000_021970e4((const s8 *) param_1, data_ov000_021b3dc4));
    t = func_ov000_02196d84(3, b, 0);
    if (t != -1) {
        p = func_ov000_0218dbf8(data_ov000_021b4e5c, t);
        p->mUnk_08 = a;
        func_ov000_021969d8(t, (a > 0) ? 1 : 0, 0, 0, 0);
    }
}

void func_ov000_02196c00(u8 *param_1, s32 param_2) {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 t;
    s32 e;
    u8 *q;
    const u8 *s;

    a = func_0213bf90((const u8 *) func_ov000_021970e4((const s8 *) param_1, data_ov000_021b3dcc));
    b = func_0213bf90((const u8 *) func_ov000_021970e4((const s8 *) param_1, data_ov000_021b3dc4));
    c = func_0213bf90((const u8 *) func_ov000_021970e4((const s8 *) param_1, data_ov000_021b3dc0));
    d = func_0213bf90((const u8 *) func_ov000_021970e4((const s8 *) param_1, data_ov000_021b3dc8));
    t = func_ov000_02196d84(1, b, c);
    if (t != -1) {
        e = func_0213bf90((const u8 *) func_ov000_021970e4((const s8 *) param_1, data_ov000_021b3dd4));
        q = func_02139f70(param_1, data_ov000_021b3ddc);
        if (q == 0) {
            e = 0;
            s = (const u8 *) data_ov000_021b3de4;
        } else {
            s = q + 6;
        }
        func_ov000_021969d8(t, a, d, s, e);
    }
}

void func_ov000_02196b90(u8 *param_1, s32 param_2) {
    s32 a;
    s32 b;
    s32 c;
    s32 d;
    s32 t;

    a = func_0213bf90((const u8 *) func_ov000_021970e4((const s8 *) param_1, data_ov000_021b3db8));
    b = func_0213bf90((const u8 *) func_ov000_021970e4((const s8 *) param_1, data_ov000_021b3dc0));
    c = func_0213bf90((const u8 *) func_ov000_021970e4((const s8 *) param_1, data_ov000_021b3dc4));
    d = func_0213bf90((const u8 *) func_ov000_021970e4((const s8 *) param_1, data_ov000_021b3dc8));
    t = func_ov000_02196d84(2, c, b);
    if (t != -1) {
        func_ov000_021969d8(t, a, d, 0, 0);
    }
}
