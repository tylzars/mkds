#include "00/code_0218e0fc.h"
#include "00/code_0218e2dc.h"
#include "00/code_02196960.h"
#include "00/code_021971ec.h"
#include "00/unk_021b3000.h"
#include "code_02135014.h"
#include "code_02139f70.h"
#include "code_0213a460.h"

s32 func_ov000_0219735c(const s8 *a, u32 b) {
    char f[0x21];
    Unk021b3bdc c = data_ov000_021b3bdc;
    const s8 *d;
    s32 e;
    s8 g[0x80];
    data_ov000_021b3b40[0] = 0x63;
    d = func_ov000_021970fc(a, data_ov000_021b3b40);
    if (d == NULL) {
        func_ov000_0218e53c(data_ov000_021b3b2c);
        return 5;
    }
    e = func_ov000_021971c8(d, strlen((const char *) d));
    e = sprintf((char *) g, data_ov000_021b3e0c, e, data_ov000_021b4f84);
    func_ov000_0218e0fc((const char *) g, e, f);
    data_ov000_021b3b30 = data_ov000_021b3b98;
    func_ov000_021971ec(c.mUnk_00, 0x2b);
    e = sprintf((char *) g, (const char *) c.mUnk_00, data_ov000_021b4e84, f, b);
    if (func_ov000_02197220(g, e) <= 0) {
        func_ov000_0218e53c(data_ov000_021b3b2c);
        return 3;
    }
    return 0;
}

s32 func_ov000_021972b4(void) {
    s8 a[0x80];
    s32 b = func_ov000_0218e460(data_ov000_021b3b2c, a, 0x80, 0);
    const s8 *c;
    s32 d;
    if (b == -1) {
        d = func_ov000_0218e368(data_ov000_021b3b2c);
        if (d != -6 && d != -0x4c && d != -0x1a) {
            func_ov000_0218e53c(data_ov000_021b3b2c);
            return 3;
        }
    }
    a[b] = 0;
    data_ov000_021b3b30 = data_ov000_021b3b88;
    func_ov000_021971ec(a, b);
    data_ov000_021b3b38[0] = 0x73;
    c = func_ov000_021970fc(a, data_ov000_021b3b38);
    if (c == NULL) {
        func_ov000_0218e53c(data_ov000_021b3b2c);
        return 5;
    }
    data_ov000_021b4e4c = func_0213bf90((const char *) c);
    return 0;
}

s32 func_ov000_02197220(s8 *a, s32 b) {
    s32 c = 0;
    s32 d;
    data_ov000_021b3b30 = data_ov000_021b3b88;
    func_ov000_021971ec(a, b);
    strcpy((char *) (a + b), data_ov000_021b3b4c);
    if (b + 7 > 0) {
        do {
            d = func_ov000_0218e420(data_ov000_021b3b2c, a + c, b + 7 - c, 0);
            if (d == -1) {
                d = func_ov000_0218e368(data_ov000_021b3b2c);
                if (d != -6 && d != -0x4c && d != -0x1a) {
                    return d;
                }
            } else if (d == 0) {
                return -1;
            } else {
                c += d;
            }
        } while (c < b + 7);
    }
    return c;
}

void func_ov000_021971ec(s8 *a, s32 b) {
    s32 d;
    s8 *c = (s8 *) data_ov000_021b3b30;
    d = 0;
    if (b > 0) {
        do {
            a[d] ^= *c++;
            if (*c == 0) {
                c = (s8 *) data_ov000_021b3b30;
            }
            d++;
        } while (d < b);
    }
}
