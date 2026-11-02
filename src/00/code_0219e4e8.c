#include "00/code_0219e4e8.h"
#include "00/code_0218b000.h"
#include "00/unk_021b5000.h"
#include "00/code_0219b8bc.h"
#include "00/code_0219c000.h"
#include "00/code_0219c384.h"
#include "00/code_0219f000.h"
#include "00/code_021a0000.h"
#include "00/code_021a17bc.h"
#include "03/code_021b94b8.h"
#include "00/code_021a369c.h"
#include "00/code_0219d000.h"
#include "00/code_0219e000.h"
#include "00/code_0219eac8.h"
#include "00/code_021a3264.h"
#include "code_0200f5ac.h"
#include "code_0214d018.h"
#include "00/code_0219f4c4.h"
#include "00/code_0219fb48.h"

u32 func_ov000_0219e4e8(u32 a) {
    s32 c;
    s32 b;
    if (a == 0) {
        return 0;
    }
    switch (a) {
        case 1:
            b = 6;
            c = -50;
            break;
        case 2:
            b = 6;
            c = -60;
            break;
        case 3:
            b = 6;
            c = -30;
            break;
        case 4:
            b = 6;
            c = -80;
            break;
        case 5:
            b = 6;
            c = -20;
            break;
    }
    switch (func_ov000_0219bab4()) {
        case 2:
            func_ov000_0219c990(b, c - 0xfa00);
            break;
        case 4:
            func_ov000_0219d734(b, c - 0x12110);
            break;
        case 5:
            func_ov000_021a1a38(b, c - 0x14820);
            break;
        default:
            func_ov000_0219c384(b, c - 0x16f30);
            break;
    }
    return a;
}

u32 func_ov000_0219e594(u32 a) {
    s32 b;
    s32 c;
    if (a == 0) {
        return 0;
    }
    switch (a) {
        case 1:
            b = 6;
            c = -50;
            break;
        case 2:
            b = 6;
            c = -30;
            break;
        case 3:
            b = 6;
            c = -20;
            break;
        case 4:
            b = 6;
            c = -40;
            break;
        case 5:
            b = 11;
            c = -1;
            break;
        case 6:
            b = 11;
            c = -2;
            break;
    }
    func_ov000_021a1a38(b, c - 0x14c08);
    return a;
}

u32 func_ov000_0219e608(u32 a) {
    s32 b;
    s32 c;
    if (a == 0) {
        return 0;
    }
    switch (a) {
        case 1:
            b = 11;
            c = -1;
            break;
        case 2:
            b = 11;
            c = -2;
            break;
        case 3:
            b = 6;
            c = -10;
            break;
        case 4:
            b = 6;
            c = -20;
            break;
    }
    func_ov000_021a1a38(b, c - 0x13c68);
    return a;
}

void func_ov000_0219e668(void) {
    Unk021b5670 *q;
    Unk021b566c *p;
    u32 a;
    u8 b;
    s32 n;
    q = data_ov000_021b5670;
    if (q == NULL) {
        return;
    }
    if (q->mUnk_00 == 0) {
        return;
    }
    p = data_ov000_021b566c;
    if (p->mUnk_15 == 2) {
        return;
    }
    if (p->mUnk_15 == 3) {
        return;
    }
    if (p->mUnk_198 == 0x13) {
        a = func_ov000_0219e8fc(0);
        q = data_ov000_021b5670;
        if (q->mUnk_08 == a) {
            if (q->mUnk_0c == a) {
                data_ov000_021b566c->mUnk_16 = data_ov000_021b566c->mUnk_0d;
                data_ov000_021b566c->mUnk_19c = data_ov000_021b566c->mUnk_0d - 1;
                func_ov000_0219f544(0);
                return;
            }
            q->mUnk_18 = func_ov000_021a350c();
            q->mUnk_08 = 0;
            p = data_ov000_021b566c;
            if (p->mUnk_15 == 0) {
                p->mUnk_198 = 3;
                data_ov000_021b566c->mUnk_e8 = 2;
                data_ov000_021b566c->mUnk_ec = func_0200f5ac();
                return;
            }
            p->mUnk_198 = 4;
            func_ov000_0219fbec(1, 0);
            return;
        }
        b = q->mUnk_02;
        if (func_ov000_021a350c() - q->mUnk_18 < b * 0x1770) {
            return;
        }
        if (b > 5) {
            func_ov000_0219e8b8(1);
            func_ov000_0219f0f4();
            func_ov000_0219f23c(1);
            return;
        }
        for (n = 1; n <= (p = data_ov000_021b566c)->mUnk_0d; n++) {
            if ((data_ov000_021b5670->mUnk_08 & (1 << p->mUnk_2b8[n])) == 0) {
                p = data_ov000_021b566c;
                if (func_ov000_0219fee4(func_ov000_021a0ae8(0x11, p->mUnk_f4[n], p->mUnk_24[n], p->mUnk_a4[n], NULL, 0)) !=
                    0) {
                    return;
                }
            }
        }
        data_ov000_021b5670->mUnk_02++;
    } else if (p->mUnk_198 == 3 || p->mUnk_198 == 4) {
        if (p->mUnk_0d < q->mUnk_01 - 1) {
            return;
        }
        if (q->mUnk_02 != 0 || func_ov000_021a350c() - q->mUnk_10 < q->mUnk_04) {
            if (q->mUnk_02 == 0) {
                return;
            }
            q = data_ov000_021b5670;
            if (func_ov000_021a350c() - q->mUnk_18 < (q->mUnk_04 >> 2)) {
                return;
            }
        }
        p = data_ov000_021b566c;
        if (p->mUnk_1ec != 0) {
            if (func_ov000_0219fee4(func_ov000_0219fb14(p->mUnk_1ec)) != 0) {
                return;
            }
        }
        p = data_ov000_021b566c;
        p->mUnk_198 = 0x13;
        for (n = 1; n <= data_ov000_021b566c->mUnk_0d; n++) {
            p = data_ov000_021b566c;
            if (func_ov000_0219fee4(func_ov000_021a0ae8(0x11, p->mUnk_f4[n], p->mUnk_24[n], p->mUnk_a4[n], NULL, 0)) !=
                0) {
                return;
            }
        }
        q = data_ov000_021b5670;
        q->mUnk_18 = func_ov000_021a350c();
        q->mUnk_02 = 1;
    }
}

void func_ov000_0219e8b8(s32 a) {
    Unk021b5670 *q;
    q = data_ov000_021b5670;
    if (q != NULL && q->mUnk_00 != 0) {
        q->mUnk_08 = 0;
        data_ov000_021b5670->mUnk_0c = 0;
        data_ov000_021b5670->mUnk_02 = 0;
        data_ov000_021b5670->mUnk_18 = func_ov000_021a350c();
        if (a == 0) {
            data_ov000_021b5670->mUnk_10 = func_ov000_021a350c();
        }
    }
}

u32 func_ov000_0219e8fc(s32 a) {
    s32 i;
    u32 r = 0;

    if (a != 0) {
        return data_ov000_021b566c->mUnk_2d8 & ~1;
    }
    for (i = 1; i <= data_ov000_021b566c->mUnk_0d; i++) {
        r |= 1 << data_ov000_021b566c->mUnk_2b8[i];
    }
    return r;
}

s32 func_ov000_0219e948(u32 a, s32 b) {
    if (b == 0) {
        b = 1;
    } else {
        b = 0;
    }
    for (; b <= data_ov000_021b566c->mUnk_0d; b++) {
        if (a == data_ov000_021b566c->mUnk_f4[b]) {
            return data_ov000_021b566c->mUnk_2b8[b];
        }
    }
    return 0xff;
}

s32 func_ov000_0219e994(u32 a) {
    if (func_ov000_0218b2a8((Unk0218af28 *) a, data_ov000_021b40d8, -1) == -1) {
        return 0;
    }
    if (func_ov000_0218b2a8((Unk0218af28 *) a, data_ov000_021b40e4, -1) == -1) {
        return 0;
    }
    if (func_ov000_0218b2a8((Unk0218af28 *) a, data_ov000_021b40f0, -1) == -1) {
        return 0;
    }
    if (func_ov000_0218b2a8((Unk0218af28 *) a, data_ov000_021b40fc, -1) == -1 &&
        func_ov000_0218b2a8((Unk0218af28 *) a, data_ov000_021b40fc, 0) == 0) {
        return 0;
    }
    if (func_ov000_0218b2a8((Unk0218af28 *) a, data_ov000_021b4108, -1) == -1) {
        return 0;
    }
    return func_ov000_0218b2a8((Unk0218af28 *) a, data_ov000_021b40c4, 0);
}

u8 func_ov000_0219ea48(void) {
    u8 i;
    s32 j;
    volatile Unk021b566c *p; // fields are read again on each use
    i = 0;
    p = data_ov000_021b566c;
    for (; i < 0x20; i++) {
        for (j = 0; j <= p->mUnk_14; j++) {
            if (i == p->mUnk_2b8[j]) {
                break;
            }
        }
        if (j > p->mUnk_14) {
            break;
        }
    }
    return i;
}

void func_ov000_0219ea88(void) {
    s32 i;
    volatile u32 v; // read back from its stack offset
    u8(*e)[12];
    i = 0;
    e = data_ov000_021b5698;
    for (; i < 0x9a; i++) {
        if (*(u32 *) &e[0][4] != 0) {
            func_ov000_021a3704(4, *(u32 *) &e[0][4], 0);
        }
        e++;
    }
    v = 0;
    func_0214d018(v, data_ov000_021b5698, 0x738);
}
