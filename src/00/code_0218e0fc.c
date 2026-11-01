#include "00/code_0218e0fc.h"
#include "00/code_0218e2c0.h"
#include "00/code_021acee0.h"
#include "00/code_021acee8.h"
#include "00/code_021acef0.h"
#include "00/unk_021b0000.h"
#include "00/unk_021b2000.h"
#include "code_02135014.h"

s32 func_ov000_0218e284(s32 param_1, s32 param_2) {
    s32 a = param_2 - param_1;
    s32 r;
    if (a == 0) {
        return param_1;
    }
    r = func_ov000_0218e2c0() % a;
    return r + param_1;
}

void func_ov000_0218e220(const s8 *param_1, u8 *param_2, s32 param_3) {
    u8 a[3];
    s32 b = 0;
    for (; b < param_3; b++) {
        a[b] = param_1[b];
    }
    for (; b < 3; b++) {
        a[b] = 0;
    }
    param_2[0] = a[0] >> 2;
    param_2[1] = ((a[0] & 3) << 4) | (a[1] >> 4);
    param_2[2] = ((a[1] & 0xf) << 2) | (a[2] >> 6);
    param_2[3] = a[2] & 0x3f;
}

void func_ov000_0218e15c(const void *param_1, void *param_2, s32 param_3, s32 param_4) {
    const s8 *a = param_1;
    s8 *b = param_2;
    s8 *g = b;
    const s8 *c;
    s32 d = param_3;
    s8 *e;
    s8 f;
    switch (param_4) {
        case 1:
            c = (const s8 *) data_ov000_021b07b0;
            break;
        case 2:
            c = (const s8 *) data_ov000_021b07b4;
            break;
        default:
            c = (const s8 *) data_ov000_021b07b8;
            break;
    }
    while (d > 0) {
        func_ov000_0218e220(a, (u8 *) b, param_3 >= 3 ? 3 : param_3);
        b += 4;
        a += 3;
        d -= 3;
    }
    e = b;
    if (param_3 % 3 == 1) {
        e = b - 2;
    } else if (param_3 % 3 == 2) {
        e = b - 1;
    }
    *b = 0;
    while (b > g) {
        b--;
        if (b >= e) {
            *b = c[2];
        } else {
            f = *b;
            if (f <= 25) {
                *b = f + 65;
            } else if (f <= 51) {
                *b = f + 71;
            } else if (f <= 61) {
                *b = f - 4;
            } else if (f == 62) {
                *b = c[0];
            } else if (f == 63) {
                *b = c[1];
            }
        }
    }
}

void func_ov000_0218e130(const u8 *param_1, u8 *param_2) {
    u32 a;
    s32 b;
    a = 0;
    b = 0;
    for (; a < 16; a++) {
        func_02135014(param_2 + b, data_ov000_021b23a4, param_1[a]);
        b += 2;
    }
}

void func_ov000_0218e0fc(const u8 *param_1, s32 param_2, u8 *param_3) {
    u8 a[16];
    Unk02150610 b;
    func_ov000_021acef0(&b);
    func_ov000_021acee8(&b, param_1, param_2);
    func_ov000_021acee0(a, &b);
    func_ov000_0218e130(a, param_3);
}
