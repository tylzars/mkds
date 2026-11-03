#include "03/code_021b8b18.h"
#include "03/code_021b9078.h"
#include "03/code_021b7bb4.h"

typedef struct Unk021b9078 {
    /* 00 */ u16 mUnk_00;
    /* 02 */ u8 pad_02[4];
    /* 06 */ u16 mUnk_06;
    /* 08 */ u8 pad_08[7];
    /* 0f */ u8 mUnk_0f;
} Unk021b9078;

s32 func_ov003_021b9078(s32 a, Unk021d7c54 *b, s32 *c, Unk021b916c *d, s32 e) {
    Unk021b9078 *p = (Unk021b9078 *) b->mUnk_0c;
    u32 v;
    if (func_ov003_021b7c44(p->mUnk_00) < 1) {
        *c = *c + 1;
        return a;
    }
    if (p->mUnk_0f != 0x11) {
        *c = *c + 1;
        return a;
    }
    if (func_ov003_021b8c8c((Unk021b8c8c *) b->mUnk_0c) > 0) {
        *c = *c + 1;
        return a;
    }
    v = func_ov003_021b7c44(p->mUnk_06);
    switch (v) {
        case 0x1010:
            a = func_ov003_021b8f68(a, b, c, d);
            break;
        case 0x2010:
            a = func_ov003_021b8e60(a, b, c, d);
            break;
        case 0x3010:
            a = func_ov003_021b8d9c(a, b, c, d);
            break;
    }
    return a;
}

s32 func_ov003_021b9134(s32 a) {
    BOOL r = FALSE;
    if (a == -1) {
        data_ov003_021d680c = a;
        return r;
    }
    if (data_ov003_021d680c != a) {
        data_ov003_021d680c = a;
        return func_ov003_021ba18c(a);
    }
    return r;
}

void func_ov003_021b916c(s32 a, Unk021b916c *b, const u8 *c) {
    s32 i;
    for (i = 0; i < a; i++) {
        func_ov003_021b7d90(b, c, 6);
        b->mUnk_06 = func_ov003_021b7bb4();
        b->mUnk_06 = func_ov003_021b7c94(b->mUnk_06);
        b++;
    }
}

s32 func_ov003_021b91a4(Unk021ba1b0 *a) {
    a->mUnk_00 = func_ov003_021b7c30(data_ov003_021d6870);
    func_ov003_021b7d90(a->mUnk_04, data_ov003_021d6870, a->mUnk_00);
    a->mUnk_24 = 1;
    a->mUnk_28 = func_ov003_021b7c30(data_ov003_021d6868);
    if ((u32) a->mUnk_28 > 0xd) {
        return -1;
    }
    func_ov003_021b7d90(a->mUnk_2c, data_ov003_021d6868, a->mUnk_28);
    return 0;
}

s32 func_ov003_021b91f0(Unk021ba734 *a) {
    s32 m;
    s32 r;
    s32 i;
    s32 n;
    r = 0;
    n = 0;
    m = a->mUnk_00;
    if (m == 0) {
        return 5;
    }
    if ((u32) m > 0x40) {
        m = 0x40;
    }
    for (i = 0; i < m; i++) {
        if (a->mUnk_04[i].mUnk_50 & 1) {
            if (a->mUnk_04[i].mUnk_00 == func_ov003_021b7c30(data_ov003_021d6870)) {
                if (func_ov003_021b7da0(a->mUnk_04[i].mUnk_04, data_ov003_021d6870,
                                        func_ov003_021b7c30(data_ov003_021d6870)) == 0) {
                    n++;
                }
            }
        }
    }
    if (n > 1) {
        r = 4;
    }
    if (n == 0) {
        r = 5;
    }
    return r;
}
