#include "00/code_02190988.h"

u32 func_ov000_02190b58(void *a, void *b, u32 c) {
    u8 d[0x14];

    func_02135014(d, data_ov000_021b29a0, c);
    return func_ov000_02190b80(a, b, d);
}

u32 func_ov000_02190aa8(Unk0218f960 *a, s32 b, const void *c, s32 d, s32 *e, s32 *f, const s8 *g) {
    s32 h;
    u32 i;

    h = func_ov000_0218e420(b, c, d, 0);
    if (h == -1) {
        i = func_ov000_0218e368(b);
        if (i != -6 && i != -0x1a && i != -0x4c) {
            if (g[0] == 0x50 && g[1] == 0x52) {
                return 3;
            }
            func_ov000_021965a0(a, 5, data_ov000_021b29cc);
            func_ov000_02190f4c(a, 3, 0);
            return 3;
        }
        *f = 0;
        *e = 0;
    } else if (h == 0) {
        func_ov000_0219690c(a, (const u8 *) data_ov000_021b29f4, g);
        *f = 0;
        *e = 1;
    } else {
        *f = h;
        *e = 0;
    }
    return 0;
}

u32 func_ov000_02190a24(Unk0218f960 *a, Unk02190988 *b, s8 c) {
    s32 d;
    s32 e;
    u32 f;

    if (b->mUnk_28.mUnk_00 == 0) {
        func_0213442c(data_ov000_021b29a4, data_ov000_021b28a8, 0, 0xde);
    }
    if (b->mUnk_28.mUnk_08 - b->mUnk_28.mUnk_0c == 0 && func_ov000_0218dc44(b->mUnk_38) == 0) {
        f = func_ov000_02190aa8(a, b->mUnk_08, &c, 1, &d, &e, data_ov000_021b29c8);
        if (f != 0) {
            return f;
        }
        if (e != 0) {
            return 0;
        }
    }
    return func_ov000_02190c64(a, &b->mUnk_28, c);
}

u32 func_ov000_02190988(Unk0218f960 *a, Unk02190988 *b, const u8 *c, s32 d) {
    s32 e;
    s32 f;
    s32 g;
    u32 h;

    if (b->mUnk_28.mUnk_00 == 0) {
        func_0213442c(data_ov000_021b29a4, data_ov000_021b28a8, 0, 0xfb);
    }
    e = 0;
    if (d == 0) {
        return e;
    }
    if (b->mUnk_28.mUnk_08 - b->mUnk_28.mUnk_0c == 0 && func_ov000_0218dc44(b->mUnk_38) == 0) {
        do {
            h = func_ov000_02190aa8(a, b->mUnk_08, c + e, d, &f, &g, data_ov000_021b29c8);
            if (h != 0) {
                return h;
            }
            if (g != 0) {
                e += g;
                d -= g;
            }
        } while (g != 0 && d != 0);
    }
    if (d != 0) {
        h = func_ov000_02190ba0(a, &b->mUnk_28, c + e, d);
        if (h != 0) {
            return h;
        }
    }
    return 0;
}
