#include "00/code_0219fb48.h"
#include "00/code_0218b000.h"
#include "00/code_0218b220.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "00/code_0218dc44.h"
#include "00/code_0218cdc4.h"
#include "00/code_0218b434.h"
#include "00/code_0218eb9c.h"
#include "00/unk_021b5000.h"
#include "00/code_0219c954.h"
#include "00/code_0219e000.h"
#include "00/code_021a0000.h"
#include "00/code_0219f4c4.h"
#include "00/code_021a0958.h"
#include "00/code_021a17bc.h"
#include "00/code_021a3264.h"
#include "00/unk_021b4000.h"
#include "00/code_021a4784.h"
#include "Main/Unknown/code_02152698.h"
#include "code_0200f5ac.h"
#include "code_0213a460.h"
#include "code_0214d018.h"
#include "code_02152500.h"

s32 func_ov000_021a0064(s32 a, u32 b, s32 c) {
    s32 r;

    switch (data_ov000_021b566c->mUnk_15) {
        case 1:
            if (func_ov000_0218eb9c(data_ov000_021b566c->mUnk_00, a) == 0) {
                r = 0xff;
                break;
            }
        case 0:
            if (b != data_ov000_021b566c->mUnk_15 || data_ov000_021b566c->mUnk_1a1 != 0 ||
                data_ov000_021b566c->mUnk_14 == data_ov000_021b566c->mUnk_16 ||
                (data_ov000_021b566c->mUnk_17 != 0 && data_ov000_021b566c->mUnk_20 == data_ov000_021b566c->mUnk_1e8)) {
                r = 3;
                if (data_ov000_021b566c->mUnk_15 == 0 && *(u32 *) ((u8 *) data_ov000_021b566c->mUnk_10 + 0xb4) == 0 &&
                    data_ov000_021b566c->mUnk_17 != 0 &&
                    data_ov000_021b566c->mUnk_20 == data_ov000_021b566c->mUnk_1e8) {
                    func_ov000_021a4818(data_ov000_021b566c->mUnk_10);
                }
            } else if ((data_ov000_021b566c->mUnk_198 != 3 && data_ov000_021b566c->mUnk_198 != 4) ||
                       (data_ov000_021b566c->mUnk_1c == 0 && data_ov000_021b566c->mUnk_1a == 0)) {
                r = 4;
            } else if (data_ov000_021b566c->mUnk_1ec != 0) {
                if (data_ov000_021b566c->mUnk_1ec == a) {
                    if (c != 0 || ((s32) data_ov000_021b566c->mUnk_1e8 < a && a != data_ov000_021b566c->mUnk_1f0)) {
                        r = 2;
                    } else {
                        r = 0xff;
                    }
                } else if (c != 0 || ((s32) data_ov000_021b566c->mUnk_1e8 < a && data_ov000_021b566c->mUnk_1f0 == 0)) {
                    if (func_ov000_0219fee4(func_ov000_0219fb14(data_ov000_021b566c->mUnk_1ec)) != 0) {
                        return 0xff;
                    }
                    r = 2;
                } else {
                    r = 3;
                }
            } else {
                r = 2;
            }
            break;
        case 2:
            if (func_ov000_0218eb9c(data_ov000_021b566c->mUnk_00, a) == 0) {
                r = 0xff;
            } else if (b != 3 || data_ov000_021b566c->mUnk_14 == data_ov000_021b566c->mUnk_16) {
                r = 3;
            } else if (data_ov000_021b5668.mUnk_00 == 1 && data_ov000_021b5668.mUnk_01 == 1) {
                r = 0x13;
            } else if (data_ov000_021b566c->mUnk_198 != 10 ||
                       (data_ov000_021b566c->mUnk_1c == 0 && data_ov000_021b566c->mUnk_1a == 0)) {
                r = 4;
            } else {
                r = 2;
            }
            break;
    }
    return r;
}

u32 func_ov000_0219ff54(u32 a, u32 b, u16 c) {
    u32 s[2];
    s32 i;
    u32 r;

    if (data_ov000_021b566c->mUnk_17 != 0 && data_ov000_021b566c->mUnk_20 == a) {
        return 0;
    }
    data_ov000_021b566c->mUnk_17 = 1;
    data_ov000_021b566c->mUnk_20 = a;
    data_ov000_021b566c->mUnk_1b0 = 0;
    data_ov000_021b566c->mUnk_1bc = 0;
    func_ov000_021a4818(data_ov000_021b566c->mUnk_10);
    data_ov000_021b566c->mUnk_1ec = 0;
    data_ov000_021b566c->mUnk_f4[data_ov000_021b566c->mUnk_14 + 1] = a;
    data_ov000_021b566c->mUnk_24[data_ov000_021b566c->mUnk_14 + 1] = b;
    data_ov000_021b566c->mUnk_a4[data_ov000_021b566c->mUnk_14 + 1] = c;
    data_ov000_021b566c->mUnk_1ac = b;
    data_ov000_021b566c->mUnk_1aa = c;
    data_ov000_021b566c->mUnk_2b8[data_ov000_021b566c->mUnk_14 + 1] = func_ov000_0219ea48();
    s[0] = a;
    s[1] = data_ov000_021b566c->mUnk_2b8[data_ov000_021b566c->mUnk_14 + 1];
    for (i = 1; i <= data_ov000_021b566c->mUnk_14; i++) {
        r = func_ov000_021a0ae8(7, data_ov000_021b566c->mUnk_f4[i], data_ov000_021b566c->mUnk_24[i],
                                data_ov000_021b566c->mUnk_a4[i], s, 2);
        if (r != 0) {
            return r;
        }
    }
    func_ov000_0219e8b8(1);
    return 0;
}

void func_ov000_0219ff0c(u32 a, u32 *b) {
    u32 n;

    n = b[0] + 2;
    if (n > 2) {
        func_0214d02c(b + 1, &data_ov000_021b566c->mUnk_330[2], (n - 2) * 4);
    }
    data_ov000_021b566c->mUnk_330[0] = n - 1;
    data_ov000_021b566c->mUnk_330[1] = a;
}

u32 func_ov000_0219fee4(u32 a) {
    if (data_ov000_021b566c->mUnk_15 == 0) {
        return func_ov000_0219e594(a);
    }
    return func_ov000_0219e608(a);
}

u32 func_ov000_0219fdc8(u32 a, s32 b) {
    u32 s[3];
    u32 t;
    u32 m;
    u32 v;

    if (b != 0) {
        data_ov000_021b566c->mUnk_1b0 = 1;
        data_ov000_021b566c->mUnk_1b4 = func_0200f5ac();
        data_ov000_021b566c->mUnk_f4[0] = a;
        return 0;
    }
    if (data_ov000_021b566c->mUnk_15 == 0) {
        t = func_ov000_0218b480((u32) data_ov000_021b566c->mUnk_e4, 0);
        data_ov000_021b566c->mUnk_f4[0] = func_ov000_0218b2a8((Unk0218af28 *) t, data_ov000_021b40c4, 0);
        data_ov000_021b566c->mUnk_24[0] = func_ov000_0218b27c((u32 *) t);
        data_ov000_021b566c->mUnk_a4[0] = func_ov000_0218b260(t);
        data_ov000_021b566c->mUnk_1ec = data_ov000_021b566c->mUnk_f4[0];
        m = 1;
    } else {
        if (data_ov000_021b566c->mUnk_15 == 1) {
            data_ov000_021b566c->mUnk_f4[0] = a;
        }
        data_ov000_021b566c->mUnk_1ec = a;
        s[1] = (u32) data_ov000_021b566c->mUnk_1c;
        s[2] = data_ov000_021b566c->mUnk_1a;
        m = 3;
    }
    data_ov000_021b566c->mUnk_1bc = 6000;
    data_ov000_021b566c->mUnk_1c0 = func_0200f5ac();
    data_ov000_021b566c->mUnk_1b0 = 0;
    v = data_ov000_021b566c->mUnk_1f0 != 0 ? 11 : 1;
    s[0] = data_ov000_021b566c->mUnk_15;
    return func_ov000_021a0ae8(v, a, data_ov000_021b566c->mUnk_24[0], data_ov000_021b566c->mUnk_a4[0], s, m);
}

u32 func_ov000_0219fbec(s32 a, s32 b) {
    s32 d;
    s32 i;
    s32 c;
    s32 e;
    u8 g[8];
    s32 q;
    u8 x[12];
    Unk0218ec44 h;
    Unk021b566c *p;
    s32 n;
    u32 r;
    s32 k;
    s32 t;
    s32 z;

    if (b != 0) {
        i = data_ov000_021b566c->mUnk_19d;
    } else if (data_ov000_021b566c->mUnk_19d < data_ov000_021b566c->mUnk_32c - 1) {
        i = data_ov000_021b566c->mUnk_19d + 1;
    } else {
        i = 0;
    }
    c = 0;
    d = b == 0;
    while (1) {
        if (d != 0 || c != 0) {
            data_ov000_021b566c->mUnk_19d++;
            if (data_ov000_021b566c->mUnk_19d >= data_ov000_021b566c->mUnk_32c) {
                data_ov000_021b566c->mUnk_19d = 0;
            }
        }
        if (c != 0 && data_ov000_021b566c->mUnk_19d == i) {
            data_ov000_021b566c->mUnk_1bc = 3000;
            data_ov000_021b566c->mUnk_1c0 = func_0200f5ac();
            data_ov000_021b566c->mUnk_1b0 = 0;
            return 0;
        }
        c = 1;
        p = data_ov000_021b566c;
        n = func_02152520((void *) func_ov000_0219c9c4(), (u8 *) p->mUnk_2e4 + p->mUnk_2ec[p->mUnk_19d] * 12);
        if (n == 0) {
            continue;
        }
        if (n == -1) {
            continue;
        }
        if (func_02152698((u8 *) data_ov000_021b566c->mUnk_2e4 +
                          data_ov000_021b566c->mUnk_2ec[data_ov000_021b566c->mUnk_19d] * 12) == 0) {
            continue;
        }
        for (k = 1; k <= data_ov000_021b566c->mUnk_0d; k++) {
            if (n == data_ov000_021b566c->mUnk_f4[k]) {
                break;
            }
        }
        if (k <= data_ov000_021b566c->mUnk_0d) {
            continue;
        }
        r = func_ov000_0218ebe8(data_ov000_021b566c->mUnk_00, n, &q);
        r |= func_ov000_0218ec44(data_ov000_021b566c->mUnk_00, q, &h);
        if (r != 0) {
            continue;
        }
        if (h.mUnk_004 != 4) {
            continue;
        }
        t = func_ov000_021a3530(data_ov000_021b4118, x, h.mUnk_008, 0x2f);
        e = func_ov000_021a3530(data_ov000_021b411c, g + 2, h.mUnk_008, 0x2f);
        z = func_ov000_021a3530(data_ov000_021b4120, g, h.mUnk_008, 0x2f);
        if (t > 0 && e > 0 && z > 0) {
            if (func_0213c074(x, 0, 10) == 3) {
                if (data_ov000_021b566c->mUnk_16 == func_0213c074(g + 2, 0, 10)) {
                    return func_ov000_0219fdc8(n, a);
                }
            }
        }
    }
}

u32 func_ov000_0219fb48(void) {
    Unk021b566c *p;

    data_ov000_021b566c->mUnk_1f0 = 0;
    data_ov000_021b566c->mUnk_1ec = 0;
    data_ov000_021b566c->mUnk_19f = 0;
    p = data_ov000_021b566c;
    p->mUnk_1c0 = func_0200f5ac();
    if (p->mUnk_15 == 0) {
        p->mUnk_198 = 3;
        if (func_ov000_0219e594(func_ov000_021a0f20(0)) != 0) {
            return 0;
        }
    } else if (p->mUnk_15 == 1) {
        if (func_ov000_0219fee4(func_ov000_0219fbec(0, 0)) != 0) {
            return 0;
        }
    } else if (p->mUnk_15 == 3) {
        func_ov000_021a1a38(6, -80410);
        return 0;
    }
    return 1;
}
