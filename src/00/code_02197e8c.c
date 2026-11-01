#include "00/code_02197e8c.h"

s32 func_ov000_02198148(Unk02197fe8 *a, s32 b) {
    if (a == 0) {
        func_0213442c(data_ov000_021b3f68, data_ov000_021b3f58, 0, 0xd9);
    }
    if (a == 0) {
        return 1;
    }
    if (a->mUnk_28.mUnk_0c == 0) {
        return 1;
    }
    a->mUnk_24++;
    a->mUnk_08->mUnk_1c++;
    a->mUnk_28.mUnk_0c(a, b);
    a->mUnk_24--;
    a->mUnk_08->mUnk_1c--;
    if (a->mUnk_08->mUnk_14 != 0 && a->mUnk_08->mUnk_1c == 0) {
        func_ov000_0219a3f8((u32 *) a->mUnk_08);
        return 0;
    }
    return 1;
}

s32 func_ov000_02198098(Unk02197fe8 *a, s32 b, s32 c, void *d, s32 e) {
    Unk02197fe8Entry *f;
    if (a == 0) {
        func_0213442c(data_ov000_021b3f68, data_ov000_021b3f58, 0, 0x101);
    }
    if (a == 0) {
        return 1;
    }
    f = (Unk02197fe8Entry *) func_ov000_0218dbf8(a->mUnk_98, b);
    if (f == 0) {
        return 1;
    }
    if (d == 0 || c == 0) {
        c = 0;
        d = 0;
    }
    a->mUnk_24++;
    a->mUnk_08->mUnk_1c++;
    f->mUnk_00(a, b, c, d, e);
    a->mUnk_24--;
    a->mUnk_08->mUnk_1c--;
    if (a->mUnk_08->mUnk_14 != 0 && a->mUnk_08->mUnk_1c == 0) {
        func_ov000_0219a3f8((u32 *) a->mUnk_08);
        return 0;
    }
    return 1;
}

s32 func_ov000_02197fe8(Unk02197fe8 *a, s32 b, void *c, s32 d, s32 e) {
    Unk02197fe8Entry *f;
    if (a == 0) {
        func_0213442c(data_ov000_021b3f68, data_ov000_021b3f58, 0, 0x12d);
    }
    if (a == 0) {
        return 1;
    }
    f = (Unk02197fe8Entry *) func_ov000_0218dbf8(a->mUnk_9c, b);
    if (f == 0) {
        return 1;
    }
    if (d == 0 || c == 0) {
        c = 0;
        d = 0;
    }
    a->mUnk_24++;
    a->mUnk_08->mUnk_1c++;
    f->mUnk_00(a, b, c, d, e);
    a->mUnk_24--;
    a->mUnk_08->mUnk_1c--;
    if (a->mUnk_08->mUnk_14 != 0 && a->mUnk_08->mUnk_1c == 0) {
        func_ov000_0219a3f8((u32 *) a->mUnk_08);
        return 0;
    }
    return 1;
}

u32 func_ov000_02197f28(int param_1, int param_2, u32 param_3, u32 param_4, u32 param_5, int param_6, int param_7,
                        int param_8) {
    Unk02197e8c *a = (Unk02197e8c *) param_1;
    Unk02197fe8 *b = (Unk02197fe8 *) param_2;
    UnkWordFunc *c;
    if (a == 0) {
        func_0213442c(data_ov000_021b3f50, data_ov000_021b3f58, 0, 0x160);
    }
    if (a == 0) {
        return 1;
    }
    if (param_8 != 0) {
        c = a->mUnk_28;
    } else {
        c = a->mUnk_2c;
    }
    if (c == 0) {
        return 1;
    }
    if (param_7 == 0 || param_6 == 0) {
        param_6 = 0;
        param_7 = 0;
    }
    a->mUnk_1c++;
    if (b != 0) {
        b->mUnk_24++;
    }
    c(a, b, param_3, param_4, param_5, param_6, param_7);
    a->mUnk_1c--;
    if (b != 0) {
        b->mUnk_24--;
    }
    if (a->mUnk_14 != 0 && a->mUnk_1c == 0) {
        func_ov000_0219a3f8((u32 *) a);
        return 0;
    }
    return 1;
}

s32 func_ov000_02197e8c(Unk02197e8c *a, s32 b, s32 c, void *d, s32 e, s32 *f) {
    *f = 0;
    if (a == 0) {
        func_0213442c(data_ov000_021b3f50, data_ov000_021b3f58, 0, 0x197);
    }
    if (a == 0) {
        return 1;
    }
    if (a->mUnk_30 == 0) {
        return 1;
    }
    if (e == 0 || d == 0) {
        d = 0;
        e = 0;
    }
    a->mUnk_1c++;
    *f = a->mUnk_30(a, b, c, d, e);
    a->mUnk_1c--;
    if (a->mUnk_14 != 0 && a->mUnk_1c == 0) {
        func_ov000_0219a3f8((u32 *) a);
        return 0;
    }
    return 1;
}
