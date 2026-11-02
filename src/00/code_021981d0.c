#include "00/code_021981d0.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_0213442c.h"
#include "00/code_0218dc44.h"
#include "00/code_02198a8c.h"
#include "00/code_02198d04.h"
#include "00/code_0219a3f4.h"
#include "00/code_021a3668.h"

int func_ov000_021981d0(Unk02197fe8 *a, void *b) {
    if (a == 0) {
        func_0213442c(data_ov000_021b3f68, data_ov000_021b3f58, 0, 0xba);
    }
    if (a == 0) {
        return 1;
    }
    if (a->mUnk_28.mUnk_08 == 0) {
        return 1;
    }
    a->mUnk_24++;
    a->mUnk_08->mUnk_1c++;
    a->mUnk_28.mUnk_08(a, b);
    a->mUnk_24--;
    a->mUnk_08->mUnk_1c--;
    if (a->mUnk_08->mUnk_14 != 0 && a->mUnk_08->mUnk_1c == 0) {
        func_ov000_0219a3f8((u32 *) a->mUnk_08);
        return 0;
    }
    return 1;
}

int func_ov000_02198258(Unk02197fe8 *a, void *b, int c, int d) {
    if (a == 0) {
        func_0213442c(data_ov000_021b3f68, data_ov000_021b3f58, 0, 0x94);
    }
    if (a == 0) {
        return 1;
    }
    if (a->mUnk_28.mUnk_04 == 0) {
        return 1;
    }
    if (c == 0 || b == 0) {
        b = 0;
        c = (int) b;
    }
    a->mUnk_24++;
    a->mUnk_08->mUnk_1c++;
    a->mUnk_28.mUnk_04(a, b, c, d);
    a->mUnk_24--;
    a->mUnk_08->mUnk_1c--;
    if (a->mUnk_08->mUnk_14 != 0 && a->mUnk_08->mUnk_1c == 0) {
        func_ov000_0219a3f8((u32 *) a->mUnk_08);
        return 0;
    }
    return 1;
}

int func_ov000_021982f4(Unk02197fe8 *a, int b, void *c, int d) {
    if (a == 0) {
        func_0213442c(data_ov000_021b3f68, data_ov000_021b3f58, 0, 0x69);
    }
    if (a == 0) {
        return 1;
    }
    a->mUnk_18 = b;
    if (a->mUnk_28.mUnk_00 == 0) {
        return 1;
    }
    if (d == 0 || c == 0) {
        c = 0;
        d = (int) c;
    }
    a->mUnk_24++;
    a->mUnk_08->mUnk_1c++;
    a->mUnk_28.mUnk_00(a, b, c, d);
    a->mUnk_24--;
    a->mUnk_08->mUnk_1c--;
    if (a->mUnk_08->mUnk_14 != 0 && a->mUnk_08->mUnk_1c == 0) {
        func_ov000_0219a3f8((u32 *) a->mUnk_08);
        return 0;
    }
    return 1;
}

int func_ov000_02198394(Unk02197e8c *a, Unk02197fe8 *b, int c, int d, int e, int f, int g) {
    if (a == 0 || b == 0) {
        func_0213442c(data_ov000_021b3f74, data_ov000_021b3f58, 0, 0x3d);
    }
    if (a == 0 || b == 0) {
        return 1;
    }
    if (a->mUnk_20 == 0) {
        return 1;
    }
    if (g == 0 || f == 0) {
        f = 0;
        g = 0;
    }
    a->mUnk_1c++;
    b->mUnk_24++;
    a->mUnk_20(a, b, c, d, e, f, g);
    a->mUnk_1c--;
    b->mUnk_24--;
    if (a->mUnk_14 != 0 && a->mUnk_1c == 0) {
        func_ov000_0219a3f8((u32 *) a);
        return 0;
    }
    return 1;
}

int func_ov000_02198448(Unk02197e8c *a) {
    if (a == 0) {
        func_0213442c(data_ov000_021b3f50, data_ov000_021b3f58, 0, 0x1b);
    }
    if (a == 0) {
        return 1;
    }
    if (a->mUnk_24 == 0) {
        return 1;
    }
    a->mUnk_1c++;
    a->mUnk_24(a);
    a->mUnk_1c--;
    if (a->mUnk_14 != 0 && a->mUnk_1c == 0) {
        func_ov000_0219a3f8((u32 *) a);
        return 0;
    }
    return 1;
}

void func_ov000_021984b4(Unk02197fe8 *a) {
    if (a->mUnk_38.mUnk_00 != 0) {
        func_ov000_021a3668(a->mUnk_38.mUnk_00);
    }
    if (a->mUnk_44.mUnk_00 != 0) {
        func_ov000_021a3668(a->mUnk_44.mUnk_00);
    }
    if (a->mUnk_50.mUnk_00 != 0) {
        func_ov000_021a3668(a->mUnk_50.mUnk_00);
    }
    if (a->mUnk_5c != 0) {
        func_ov000_0218dc48(a->mUnk_5c);
    }
    if (a->mUnk_60 != 0) {
        func_ov000_0218dc48(a->mUnk_60);
    }
    if (a->mUnk_98 != 0) {
        func_ov000_0218dc48(a->mUnk_98);
    }
    if (a->mUnk_9c != 0) {
        func_ov000_0218dc48(a->mUnk_9c);
    }
    func_ov000_021a3668(a);
}

void func_ov000_02198514(Unk02197fe8 *a, ...) {
    if (a->mUnk_0c != 7) {
        a->mUnk_0c = 7;
        func_ov000_0218de8c(a->mUnk_08->mUnk_0c, &a);
        func_ov000_0218dbc0(a->mUnk_08->mUnk_10, &a);
    }
}

void func_ov000_02198548(Unk02197fe8 *a, int b) {
    if (b != 0) {
        if (a->mUnk_0c < 7) {
            func_ov000_02198514(a);
            func_ov000_02198b8c(a);
            func_ov000_021981d0(a, 0);
            func_ov000_0219a220(a);
        }
    } else {
        a->mUnk_0c = 6;
        func_ov000_02198d50((u32) a);
    }
}
