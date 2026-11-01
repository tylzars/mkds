#include "code_021453ec.h"
#include "code_021445e0.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_0214259c.h"
#include "code_02142ab8.h"
#include "code_02142aa8.h"
#include "code_02142c0c.h"
#include "code_0214cfe4.h"

u8 data_0217f960[0x80];

int func_02145708(u32 a, u32 b, void *c) {
    int r;

    r = func_02142a30();
    if (r != 0) {
        return r;
    }
    if (b > 3) {
        return 6;
    }
    if (b != 0) {
        if (c == 0) {
            return 6;
        }
        func_0200ee58(c, 0x50);
    }
    func_02142c0c(0x14, a);
    r = func_02142ab8(0x14, 2, b, c);
    if (r == 0) {
        r = 2;
    }
    return r;
}

int func_02145668(u32 a, u32 b, u32 c, void *d) {
    int r;

    r = func_02142a30();
    if (r != 0) {
        return r;
    }
    if (b > 3) {
        return 6;
    }
    if (b != 0) {
        if (d == 0) {
            return 6;
        }
        func_0200ee58(d, 0x50);
    }
    func_02142c0c(0x27, a);
    r = func_02142ab8(0x27, 3, b, d, c);
    if (r == 0) {
        r = 2;
    }
    return r;
}

int func_021455a0(Unk021425e8Func a, const void *b, u32 c, u32 d, u16 e, u8 f) {
    int r;

    r = func_02142988(2, 7, 9);
    if (r != 0) {
        return r;
    }
    if (b == 0) {
        return 6;
    }
    if (c > 0x70) {
        return 6;
    }
    func_0214cffc(b, data_0217f960, c);
    func_0200ee58(data_0217f960, c);
    func_02142c0c(0x18, (u32) a);
    r = func_02142ab8(0x18, 5, data_0217f960, c, d, e, f);
    if (r == 0) {
        r = 2;
    }
    return r;
}

int func_02145530(Unk021425e8Func a, u32 b) {
    int r;

    r = func_02142a30();
    if (r != 0) {
        return r;
    }
    if (b != 0 && b != 1) {
        return 6;
    }
    func_02142c0c(0x19, (u32) a);
    r = func_02142ab8(0x19, 1, b);
    if (r == 0) {
        r = 2;
    }
    return r;
}

int func_021454c4(Unk021425e8Func a, u32 b, u32 c, u32 d, u16 e) {
    int r;

    r = func_02142a30();
    if (r != 0) {
        return r;
    }
    func_02142c0c(0x1d, (u32) a);
    r = func_02142ab8(0x1d, 4, b, c, d, e);
    if (r == 0) {
        r = 2;
    }
    return r;
}

// Stores five u16 values at mUnk_00c of the Unk02142aa8 and passes code 0x1e to func_02142ab8.
int func_0214544c(Unk021425e8Func a, u16 b, u16 c, u16 d, u16 e) {
    Unk02142aa8 *p;
    u16 *q;
    int r;

    p = func_02142aa8();
    r = func_02142988(1, 2);
    if (r != 0) {
        return r;
    }
    func_02142c0c(0x1e, (u32) a);
    q = p->mUnk_00c;
    q[0] = 0x1e;
    q[1] = b;
    q[2] = c;
    q[3] = d;
    q[4] = e;
    r = func_02142ab8(0x1e, 0);
    if (r == 0) {
        r = 2;
    }
    return r;
}

int func_021453ec(Unk021425e8Func a, u32 b) {
    int r;

    r = func_02142988(2, 7, 9);
    if (r != 0) {
        return r;
    }
    func_02142c0c(0x21, (u32) a);
    r = func_02142ab8(0x21, 1, b);
    if (r == 0) {
        r = 2;
    }
    return r;
}
