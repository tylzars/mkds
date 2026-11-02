#include "00/code_02197e8c.h"

BOOL func_ov000_02198148(Unk02197fe8 *a, s32 b) {
    if (a == NULL) {
        func_0213442c(data_ov000_021b3f68, data_ov000_021b3f58, NULL, 0xd9);
    }
    if (a == NULL) {
        return TRUE;
    }
    if (a->mUnk_28.mUnk_0c == NULL) {
        return TRUE;
    }
    a->mUnk_24++;
    a->mUnk_08->mUnk_1c++;
    a->mUnk_28.mUnk_0c(a, b);
    a->mUnk_24--;
    a->mUnk_08->mUnk_1c--;
    if (a->mUnk_08->mUnk_14 != 0 && a->mUnk_08->mUnk_1c == 0) {
        func_ov000_0219a3f8((u32 *) a->mUnk_08);
        return FALSE;
    }
    return TRUE;
}

BOOL func_ov000_02198098(Unk02197fe8 *a, s32 b, s32 c, void *d, s32 e) {
    Unk02197fe8Entry *f;
    if (a == NULL) {
        func_0213442c(data_ov000_021b3f68, data_ov000_021b3f58, NULL, 0x101);
    }
    if (a == NULL) {
        return TRUE;
    }
    f = func_ov000_0218dbf8(a->mUnk_98, b);
    if (f == NULL) {
        return TRUE;
    }
    if (d == NULL || c == 0) {
        c = 0;
        d = NULL;
    }
    a->mUnk_24++;
    a->mUnk_08->mUnk_1c++;
    f->mUnk_00(a, b, c, d, e);
    a->mUnk_24--;
    a->mUnk_08->mUnk_1c--;
    if (a->mUnk_08->mUnk_14 != 0 && a->mUnk_08->mUnk_1c == 0) {
        func_ov000_0219a3f8((u32 *) a->mUnk_08);
        return FALSE;
    }
    return TRUE;
}

BOOL func_ov000_02197fe8(Unk02197fe8 *a, s32 b, void *c, s32 d, s32 e) {
    Unk02197fe8Entry *f;
    if (a == NULL) {
        func_0213442c(data_ov000_021b3f68, data_ov000_021b3f58, NULL, 0x12d);
    }
    if (a == NULL) {
        return TRUE;
    }
    f = func_ov000_0218dbf8(a->mUnk_9c, b);
    if (f == NULL) {
        return TRUE;
    }
    if (d == 0 || c == NULL) {
        c = NULL;
        d = 0;
    }
    a->mUnk_24++;
    a->mUnk_08->mUnk_1c++;
    f->mUnk_00(a, b, c, d, e);
    a->mUnk_24--;
    a->mUnk_08->mUnk_1c--;
    if (a->mUnk_08->mUnk_14 != 0 && a->mUnk_08->mUnk_1c == 0) {
        func_ov000_0219a3f8((u32 *) a->mUnk_08);
        return FALSE;
    }
    return TRUE;
}

u32 func_ov000_02197f28(int d, int e, u32 f, u32 g, u32 h, int l, int m, int n) {
    Unk02197e8c *a = (Unk02197e8c *) d;
    Unk02197fe8 *b = (Unk02197fe8 *) e;
    UnkWordFunc *c;
    if (a == NULL) {
        func_0213442c(data_ov000_021b3f50, data_ov000_021b3f58, NULL, 0x160);
    }
    if (a == NULL) {
        return 1;
    }
    if (n != 0) {
        c = a->mUnk_28;
    } else {
        c = a->mUnk_2c;
    }
    if (c == NULL) {
        return 1;
    }
    if (m == 0 || l == 0) {
        l = 0;
        m = 0;
    }
    a->mUnk_1c++;
    if (b != NULL) {
        b->mUnk_24++;
    }
    c(a, b, f, g, h, l, m);
    a->mUnk_1c--;
    if (b != NULL) {
        b->mUnk_24--;
    }
    if (a->mUnk_14 != 0 && a->mUnk_1c == 0) {
        func_ov000_0219a3f8((u32 *) a);
        return 0;
    }
    return 1;
}

BOOL func_ov000_02197e8c(Unk02197e8c *a, s32 b, s32 c, void *d, s32 e, s32 *f) {
    *f = 0;
    if (a == NULL) {
        func_0213442c(data_ov000_021b3f50, data_ov000_021b3f58, NULL, 0x197);
    }
    if (a == NULL) {
        return TRUE;
    }
    if (a->mUnk_30 == NULL) {
        return TRUE;
    }
    if (e == 0 || d == NULL) {
        d = NULL;
        e = 0;
    }
    a->mUnk_1c++;
    *f = a->mUnk_30(a, b, c, d, e);
    a->mUnk_1c--;
    if (a->mUnk_14 != 0 && a->mUnk_1c == 0) {
        func_ov000_0219a3f8((u32 *) a);
        return FALSE;
    }
    return TRUE;
}
