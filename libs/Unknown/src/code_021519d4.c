#include "code_021510a4.h"
#include "code_021519d4.h"
#include "code_02151868.h"
#include "code_02151fc4.h"
#include "code_020205b0.h"
#include "code_0200f5ac.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"
#include "code_0214d954.h"
#include "string.h"
#include "code_02134398.h"
#include "code_0200fd1c.h"
#include "Main/Unknown/code_02151708.h"
#include "Main/Unknown/code_02151718.h"

#pragma thumb on

u32 func_02151f48(Unk021510a4 *a, u8 *b) {
    Unk021510a4 c;
    func_02151910(&c);
    a->mUnk_00 = a->mUnk_08;
    a->mUnk_08 = c.mUnk_08;
    if (func_02151868(a, b) != 0) {
        return 1;
    }
    return 0;
}

u32 func_02151e20(Unk021510a4 *a) {
    u32 b;
    u32 c;
    u8 d[6] = {0, 0, 0, 0, 0, 0};
    u32 e[4];
    u32 f[3];
    s64 g;
    u32 h;
    func_02151910(a);
    func_0214e0f4();
    if (func_0214e038(e) != 0) {
        return 0;
    }
    if (func_0214df78(f) != 0) {
        return 0;
    }
    g = func_02152244(e, f);
    h = g;
    if (g < 0) {
        return 0;
    }
    if (func_0200f6e4() != 0) {
        h += (u32) func_0200f5ac;
    }
    func_0200fe58(d);
    b = (u8) ((d[0] << 16 | d[1] << 8 | d[2]) != 0x9bf);
    c = d[5];
    c |= (d[3] << 16 | d[4] << 8);
    h = h * 0x5d588b65 + 0x269ec3;
    a->mUnk_10 = ((h >> 16) * 1000) >> 16;
    a->mUnk_08 = 0;
    while (a->mUnk_08 == 0) {
        h = h * 0x5d588b65 + 0x269ec3;
        while (h == 0 || a->mUnk_12 == (u16) h) {
            h = h * 0x5d588b65 + 0x269ec3;
        }
        a->mUnk_12 = h;
        a->mUnk_08 = func_0215211c(a->mUnk_12, c, b, 0);
    }
    return 1;
}

void func_02151ddc(Unk02151ddc *a) {
    Unk021510a4 b;
    func_02151910(&b);
    a->mUnk_00 = b.mUnk_00;
    a->mUnk_08 = b.mUnk_08;
    if (b.mUnk_00 == 0) {
        a->mUnk_10 = 0;
    } else {
        a->mUnk_10 = 1;
    }
}

u32 func_02151da8(void) {
    Unk021510a4 a;
    func_02151910(&a);
    if (a.mUnk_08 == 0 && a.mUnk_00 == 0) {
        return 1;
    }
    return 0;
}

s32 func_02151b38(u8 *a) {
    u32 b[4];
    s32 c;
    u8 *d;
    u8 *e;
    u32 *f;
    u32 g;
    u32 *m;
    s32 h;
    u32 k;
    if (func_02151830((u16 *) a) == 0) {
        return -10001;
    }
    Crc16InitTable((u16 *) (a + 0x500), 0xa001);
    if (func_02151804((u32) a) == 0) {
        return -10001;
    }
    MemFill(b, 0, 0x10);
    c = 0;
    d = a;
    e = a;
    f = b;
    do {
        k = Crc16((u16 *) (a + 0x500), d, 0xfe);
        if (k == *(u16 *) (d + 0xfe)) {
            if (func_02151a64(e) != 0) {
                *f = 1;
            }
        }
        d += 0x100;
        e += 0x100;
        f++;
        c++;
    } while (c < 3);
    k = Crc16((u16 *) (a + 0x500), a + 0x300, 0xfe);
    if (k == *(u16 *) (a + 0x3fe)) {
        b[3] = 1;
    }
    if (b[0] != 0 && b[1] != 0 && b[2] != 0 && b[3] != 0) {
        func_02151708((u32) (a + 0xf0));
        return 0;
    }
    if (b[0] == 0 && b[1] == 0 && b[2] == 0 && b[3] == 0) {
        func_02151a00(a);
        if (func_02151718((int) a) != 0) {
            return 0;
        }
        return -10000;
    }
    if ((b[0] == 0 || b[1] == 0) && (b[2] == 0 || b[3] == 0)) {
        func_02151a00(a);
        if (func_02151718((int) a) != 0) {
            return 0;
        }
        return -10000;
    }
    if (b[0] == 0 && b[1] == 0) {
        func_02151a00(a);
        if (func_02151718((int) a) != 0) {
            return -10003;
        }
        return -10000;
    }
    if (b[0] == 0) {
        func_021519d4(a, 0);
        MemCopy(a + 0x1f0, a + 0xf0, 0xd);
        a[0xef] = a[0x1ef];
    } else if (b[1] == 0) {
        func_021519d4(a, 1);
        MemCopy(a + 0xf0, a + 0x1f0, 0xd);
        a[0x1ef] = a[0xef];
    }
    func_02151708((u32) (a + 0xf0));
    if (b[2] == 0) {
        func_021519d4(a, 2);
    }
    if (b[3] == 0) {
        vu16 z = 0;
        MemFillHalfwords(z, a + 0x300, 0x100);
    }
    g = 0;
    h = 0;
    m = b;
    for (; h < 3; m++, h++) {
        if (*m == 0) {
            k = 1 << h;
            if ((a[0xef] & k) != 0) {
                a[0xef] &= ~k;
                g = 1;
            }
        }
    }
    if (func_02151718((int) a) == 0) {
        return -10000;
    }
    if (g != 0) {
        return -10002;
    }
    return 0;
}

u32 func_02151a64(const u8 *a) {
    u8 b[8];
    u8 c;
    c = a[0xe7];
    if (c == 0xff) {
        return 1;
    }
    if (c > 2) {
        return 0;
    }
    if (Bytes32AnyNonzero(a + 0x40) == 0) {
        return 0;
    }
    if (memcmp(a + 0xc0, data_usa_0216172c, 4) != 0) {
        if (func_02151620(a + 0xc4) == 0) {
            return 0;
        }
        if (a[0xd0] > 0x20) {
            return 0;
        }
        Bytes4StoreTopBitsMask(a[0xd0], b);
        if (func_02151640(a + 0xc0, b) == 0) {
            return 0;
        }
    }
    if (memcmp(a + 0xc8, data_usa_0216172c, 4) != 0) {
        if (func_02151620(a + 0xc8) == 0 && func_02151620(a + 0xcc) == 0) {
            return 0;
        }
    }
    return 1;
}

s32 func_02151a00(u8 *a) {
    vu16 b;
    s32 c;
    u8 *d;
    u8 *e;
    Unk021510a4 f;
    u8 *g;
    b = 0;
    MemFillHalfwords(b, a, 0x400);
    c = 0;
    d = a;
    for (; c < 3; c++) {
        d[0xe7] = 0xff;
        d += 0x100;
    }
    func_02151fc4(&f);
    g = func_021510a4(&f);
    e = a;
    for (c = 0; c < 2; c++) {
        MemCopy(g, e + 0xf0, 0xe);
        e += 0x100;
    }
    return 0;
}

void func_021519d4(u8 *a, u32 b) {
    vu16 c;
    u32 d;
    c = 0;
    d = b << 8;
    MemFillHalfwords(c, a + d, 0x100);
    (a + d)[0xe7] = 0xff;
}

#pragma thumb off
