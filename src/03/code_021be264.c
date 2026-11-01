#include "03/code_021be264.h"
#include "03/code_021be4e0.h"
#include "03/code_021be4ec.h"
#include "03/code_021be610.h"
#include "00/code_021a8c94.h"
#include "code_0200dc3c.h"
#include "code_0200f7a0.h"

s32 func_ov003_021be264(void) {
    Unk0200fb08 v1;
    Unk021d8c2c *p0;
    s32 a = 1;
    s32 b = -2;
    s32 c;
    s32 d;

    p0 = data_ov003_021d8c2c + data_ov003_021d8be8;
    if (p0 == 0) {
        return 0;
    }
    if (func_ov003_021be708(p0, 0, 0x30000) == 0) {
        return -2;
    }
    func_0200fb08(&v1);
    func_0200f950(&v1, 0x3fec42, (void (*)(void *)) func_ov003_021be4e0, (void *) 0x12);
    c = 0;
    do {
        if (func_ov003_021bb354() >= data_ov003_021d68b8) {
            b = -3;
            break;
        }
        if (data_ov003_021d8be0 != 0) {
            b = -8;
            break;
        }
        func_0200dc3c(10);
        while ((d = func_ov003_021be528()) != 0) {
            switch (d) {
                case 12:
                    a = c;
                    b = 1;
                    break;
                case 13:
                    if (data_ov003_021d8be0 != 0) {
                        a = c;
                        b = -8;
                    } else if (func_ov003_021be708(p0, 0, 0x30000) == 0) {
                        return b;
                    }
                    break;
                case 4:
                case 5:
                case 18:
                case 19:
                    break;
                default:
                    a = c;
                    break;
            }
        }
    } while (a != 0);
    func_0200f8b8(&v1);
    while (func_ov003_021be528() != 0) {
    }
    if (b > 0) {
        data_ov003_021d8bf0 = 1;
        if ((s32) func_ov000_021a8c94(data_ov003_021d691c) < 0) {
            b = -2;
        } else {
            data_ov003_021d8bf4 = 1;
        }
    }
    return b;
}

u32 func_ov003_021be3b8(void) {
    u32 a = 1;
    u32 b;

    if (func_ov003_021be7b8() != 0) {
        do {
            func_0200dc3c(10);
            while ((b = func_ov003_021be528()) != 0) {
                switch (b) {
                    case 4:
                    case 5:
                        break;
                    case 20:
                        a = 0;
                        break;
                    default:
                        a = 0;
                        break;
                }
            }
        } while (a != 0);
    }
    if (data_ov003_021d8c24 != 0) {
        data_ov003_021d8bdc(data_ov003_021d8c24);
        data_ov003_021d8c24 = 0;
    }
    return 1;
}

// non-matching: the original keeps 0x1f in r3 for both alignments (movs r3,#31; adds r1,r0,r3; bics r1,r3), ours adds
// the immediate; 0xcc bytes against 0xc8
s32 func_ov003_021be418(u32 param_0) {
    u32 a = 1;
    s32 b;
    u32 c;
    u32 d;
    u32 e;
    u32 f;

    data_ov003_021d8c40 = param_0;
    func_ov003_021be568();
    e = param_0 * 0xd0;
    data_ov003_021d8c24 = (void *) data_ov003_021d8bd4(e + 0x24d0 + param_0 * 0xc0);
    if (data_ov003_021d8c24 == 0) {
        return -1;
    }
    d = ((u32) data_ov003_021d8c24 + 0x1f) & ~0x1f;
    data_ov003_021d8c10 = (void *) d;
    f = e + 0x2490;
    data_ov003_021d8c2c = (Unk021d8c2c *) ((d + f + 0x1f) & ~0x1f);
    if (func_ov003_021be610(func_ov003_021be4ec, (void *) d, f) == 0) {
        return -2;
    }
    do {
        func_0200dc3c(10);
        while ((c = func_ov003_021be528()) != 0) {
            if (c == 4 || c == 5) {
            } else if (c == 6) {
                a = 0;
                b = 1;
            } else {
                a = 0;
                b = -2;
            }
        }
    } while (a != 0);
    return b;
}
