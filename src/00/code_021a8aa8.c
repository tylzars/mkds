#include "00/code_021a8aa8.h"
#include "00/unk_021b6000.h"
#include "00/code_021a8878.h"
#include "00/code_021a4654.h"

#include "00/types_021a8ab8.h"
#include "00/code_021a88a8.h"
#include "code_0200dc3c.h"
#include "code_0200d118.h"
#include "code_0214d018.h"
#include "00/code_021a87bc.h"
#include "00/code_021a6d6c.h"
#include "00/code_021a75f8.h"
#include "00/code_021a6fa8.h"
#include "00/code_021a86bc.h"
#include "00/unk_021b5000.h"
#include "code_0200c858.h"
#include "00/code_021a8604.h"
#include "00/code_021a836c.h"
#include "00/code_021a7bfc.h"
#include "00/code_021a7000.h"
#include "00/code_021a740c.h"
#include "00/code_021a73d8.h"

s32 func_ov000_021a918c(s32 v1, s32 v2, s32 v3) {
    if (v2 == 1) {
        return func_ov000_021a73d8(&data_ov000_021b49b8);
    }
    return func_ov000_021a73d8(&data_0216e204);
}

s32 func_ov000_021a916c(s32 v1, const void *v2) {
    const Unk021a8e18 *a = v2;
    u16 b = ((a->mUnk_02 >> 8) & 0xff) | ((a->mUnk_02 << 8) & 0xff00);
    return func_ov000_021a7824((Unk021a6fa8 *) v1, b);
}

s32 func_ov000_021a911c(Unk021a6fa8 *a, Unk021a8e18 *b) {
    u32 c = b->mUnk_04;
    u16 d = ((b->mUnk_02 >> 8) & 0xff) | ((b->mUnk_02 << 8) & 0xff00);
    u32 e = ((c << 24) & 0xff000000) | (((c << 8) & 0xff0000) | (((c >> 24) & 0xff) | ((c >> 8) & 0xff00)));
    return func_ov000_021a7748(a, d, (u16 *) e);
}

s32 func_ov000_021a9104(s32 p0, void *p1, s32 p2, s32 p3) {
    u32 v5 = ((0x0u) + (0x0u));
    u32 v6 = func_ov000_021a7de0((u32) p0, (u32) p1, (u32) p2, v5, (u32) 0x0u, (u32) p3);
    return v6;
}

s32 func_ov000_021a90a0(s32 v1, void *v2, s32 v3, s32 v4, void *v5) {
    Unk021a8e18 *a;
    u16 b;
    u32 c;
    s32 d = func_ov000_021a7de0(v1, (u32) v2, v3, (u32) &b, (u32) &c, v4);
    if (d >= 0 && v5 != NULL) {
        a = v5;
        a->mUnk_02 = ((b >> 8) & 0xff) | ((b << 8) & 0xff00);
        a->mUnk_04 = ((c << 24) & 0xff000000) | (((c << 8) & 0xff0000) | (((c >> 24) & 0xff) | ((c >> 8) & 0xff00)));
    }
    return d;
}

s32 func_ov000_021a9088(s32 p0, void *p1, s32 p2, s32 p3) {
    u32 v5 = ((0x0u) + (0x0u));
    u32 v6 = func_ov000_021a8268((u32) p0, (u32) p1, (u32) p2, v5, (u32) 0x0u, (u32) p3);
    return v6;
}

s32 func_ov000_021a9018(s32 v1, void *v2, s32 v3, s32 v4, void *v5) {
    Unk021a8e18 *a = v5;
    u16 b;
    u32 c;
    if (a != NULL) {
        b = ((a->mUnk_02 >> 8) & 0xff) | ((a->mUnk_02 << 8) & 0xff00);
        c = ((a->mUnk_04 << 24) & 0xff000000) |
            (((a->mUnk_04 << 8) & 0xff0000) | (((a->mUnk_04 >> 24) & 0xff) | ((a->mUnk_04 >> 8) & 0xff00)));
    } else {
        b = 0;
        c = 0;
    }
    return func_ov000_021a8268(v1, (u32) v2, v3, b, c, v4);
}

s32 func_ov000_021a9010(s32 descriptor) {
    return func_ov000_021a836c(descriptor);
}

s32 func_ov000_021a9008(s32 descriptor) {
    return func_ov000_021a8604(descriptor);
}

Unk021a8f84 *func_ov000_021a8f84(const u8 *a) {
    u32 b = func_ov000_021a88e4(a);
    if (b == 0) {
        return NULL;
    }
    func_0200c858(data_ov000_021b6078, (const s8 *) a, 0x101);
    data_ov000_021b6020.mUnk_00 = (u8 *) data_ov000_021b6078;
    data_ov000_021b6020.mUnk_04 = NULL;
    data_ov000_021b6020.mUnk_08 = 2;
    data_ov000_021b6020.mUnk_0a = 4;
    data_ov000_021b6020.mUnk_0c = data_ov000_021b6018;
    data_ov000_021b6018[0] = &data_ov000_021b600c;
    data_ov000_021b6018[1] = NULL;
    data_ov000_021b600c =
        ((b << 24) & 0xff000000) | (((b << 8) & 0xff0000) | (((b >> 24) & 0xff) | ((b >> 8) & 0xff00)));
    return &data_ov000_021b6020;
}

u32 func_ov000_021a8f0c(u32 f, u32 g) {
    Unk021a6fa8 *a = (Unk021a6fa8 *) f;
    Unk021a8e18 *b = (Unk021a8e18 *) g;
    u32 c;
    u32 d;
    u16 e;
    if (a == NULL) {
        return -0x27;
    }
    c = func_ov000_021a8830();
    if (a != NULL) {
        d = a->mUnk_74;
    } else {
        d = 0;
    }
    if (c == 0) {
        d = 0;
    }
    b->mUnk_00 = 8;
    b->mUnk_01 = 2;
    e = d;
    b->mUnk_02 = ((e >> 8) & 0xff) | ((e << 8) & 0xff00);
    b->mUnk_04 = ((c << 24) & 0xff000000) | (((c << 8) & 0xff0000) | (((c >> 24) & 0xff) | ((c >> 8) & 0xff00)));
    return 0;
}

u32 func_ov000_021a8ed4(void) {
    u32 v1 = ((u32) func_ov000_021a8830());
    u32 v2 = ((v1) << 24);
    u32 v3 = 0xff000000u;
    u32 v4 = ((v2) & (v3));
    u32 v5 = ((v1) << 8);
    u32 v6 = 0xff0000u;
    u32 v7 = ((v5) & (v6));
    u32 v8 = ((v1) >> 24);
    u32 v10 = ((v8) & (0xffu));
    u32 v11 = ((v1) >> 8);
    u32 v12 = 0xff00u;
    u32 v13 = ((v11) & (v12));
    u32 v14 = ((v10) | (v13));
    u32 v15 = ((v7) | (v14));
    u32 v16 = ((v4) | (v15));
    u32 v17 = ((v16) + (0x0u));
    return v17;
}

void func_ov000_021a8e78(u32 *p0, u32 *p1) {
    u32 v2 = ((u32) * (u32 *) ((p1) + (0)));
    u32 v3 = ((u32) * (u32 *) ((p0) + (0)));
    u32 v4 = ((v3) << 24);
    u32 v5 = 0xff000000u;
    u32 v6 = ((v4) & (v5));
    u32 v7 = ((v3) << 8);
    u32 v8 = 0xff0000u;
    u32 v9 = ((v7) & (v8));
    u32 v10 = ((v3) >> 24);
    u32 v12 = ((v10) & (0xffu));
    u32 v13 = ((v3) >> 8);
    u32 v14 = 0xff00u;
    u32 v15 = ((v13) & (v14));
    u32 v16 = ((v12) | (v15));
    u32 v17 = ((v9) | (v16));
    u32 v18 = ((v6) | (v17));
    u32 v19 = ((v18) + (0x0u));
    u32 v20 = ((v2) << 24);
    u32 v21 = 0xff000000u;
    u32 v22 = ((v20) & (v21));
    u32 v23 = ((v2) << 8);
    u32 v24 = ((v23) & (v8));
    u32 v25 = ((v2) >> 24);
    u32 v26 = ((v25) & (0xffu));
    u32 v27 = ((v2) >> 8);
    u32 v28 = ((v27) & (v14));
    u32 v29 = ((v26) | (v28));
    u32 v30 = ((v24) | (v29));
    u32 v31 = ((v22) | (v30));
    u32 v32 = ((v31) + (0x0u));
    u32 v33 = ((u32) func_ov000_021a8878(v19, v32));
}

s32 func_ov000_021a8e70(s32 descriptor) {
    return func_ov000_021a75f8(descriptor);
}

s32 func_ov000_021a8e18(Unk021a6fa8 *a, Unk021a8e18 *b, s32 f) {
    u16 c;
    u32 d;
    s32 e = func_ov000_021a7534(a, &c, &d);
    if (e >= 0) {
        b->mUnk_02 = ((c >> 8) & 0xff) | ((c << 8) & 0xff00);
        b->mUnk_04 = ((d << 24) & 0xff000000) | (((d << 8) & 0xff0000) | (((d >> 24) & 0xff) | ((d >> 8) & 0xff00)));
    }
    return e;
}

s32 func_ov000_021a8dd8(Unk021a6fa8 *a, s32 b, u32 c) {
    if (a == NULL) {
        return -1;
    }
    switch (b) {
        case 3:
            if (a->mUnk_72 == 1) {
                return 0;
            }
            return 4;
        case 4:
            if (c & 4) {
                a->mUnk_72 = 0;
            } else {
                a->mUnk_72 = 1;
            }
            break;
    }
    return 0;
}

void *func_ov000_021a8db8(u32 a) {
    u32 b = a + 4;
    u32 *c = data_ov000_021b6014(0, b);
    if (c != NULL) {
        *c = b;
        c++;
    }
    return c;
}

void func_ov000_021a8d98(int a) {
    if (a != 0) {
        (*(UnkFunc *) (*(u32 *) &data_ov000_021b6010))(0, (u32 *) (a + -4), *(u32 *) (a + -4));
    }
    return;
}

s32 func_ov000_021a8c94(void *b) {
    Unk021a8c94 *a = b;
    data_ov000_021b6040.mUnk_00 = a->mUnk_0c == 1 ? 1 : 0;
    data_ov000_021b6040.mUnk_04 =
        ((a->mUnk_10[0] << 24) & 0xff000000) |
        (((a->mUnk_10[0] << 8) & 0xff0000) | (((a->mUnk_10[0] >> 24) & 0xff) | ((a->mUnk_10[0] >> 8) & 0xff00)));
    data_ov000_021b6040.mUnk_08 =
        ((a->mUnk_10[1] << 24) & 0xff000000) |
        (((a->mUnk_10[1] << 8) & 0xff0000) | (((a->mUnk_10[1] >> 24) & 0xff) | ((a->mUnk_10[1] >> 8) & 0xff00)));
    data_ov000_021b6040.mUnk_0c =
        ((a->mUnk_10[2] << 24) & 0xff000000) |
        (((a->mUnk_10[2] << 8) & 0xff0000) | (((a->mUnk_10[2] >> 24) & 0xff) | ((a->mUnk_10[2] >> 8) & 0xff00)));
    data_ov000_021b6040.mUnk_10 =
        ((a->mUnk_10[3] << 24) & 0xff000000) |
        (((a->mUnk_10[3] << 8) & 0xff0000) | (((a->mUnk_10[3] >> 24) & 0xff) | ((a->mUnk_10[3] >> 8) & 0xff00)));
    data_ov000_021b6040.mUnk_14 =
        ((a->mUnk_10[4] << 24) & 0xff000000) |
        (((a->mUnk_10[4] << 8) & 0xff0000) | (((a->mUnk_10[4] >> 24) & 0xff) | ((a->mUnk_10[4] >> 8) & 0xff00)));
    data_ov000_021b6040.mUnk_18 = func_ov000_021a8db8;
    data_ov000_021b6040.mUnk_1c = (void (*)(void *)) func_ov000_021a8d98;
    data_ov000_021b6014 = a->mUnk_04;
    *(void **) data_ov000_021b6010 = a->mUnk_08;
    data_ov000_021b6040.mUnk_20 = 0x40;
    data_ov000_021b6040.mUnk_30 = a->mUnk_2c;
    data_ov000_021b6040.mUnk_34 = a->mUnk_30;
    return func_ov000_021a6ee4(&data_ov000_021b6040);
}

s32 func_ov000_021a8c8c(void) {
    return func_ov000_021a87bc();
}

u8 *func_ov000_021a8c6c(Unk021b5dfc a) {
    func_ov000_021a8bc0(2, &a, (char *) data_ov000_021b6030, 0x10);
    return data_ov000_021b6030;
}

u32 func_ov000_021a8c1c(u32 b, u32 *c) {
    u32 a = func_ov000_021a88a8(b);
    if (a == 0) {
        return 0;
    }
    *c = ((a << 24) & 0xff000000) | (((a << 8) & 0xff0000) | (((a >> 24) & 0xff) | ((a >> 8) & 0xff00)));
    return 1;
}

char *func_ov000_021a8bc0(s32 a, const void *b, char *c, u32 d) {
    u8 e[8];
    if (a != 2) {
        return NULL;
    }
    if (d < 0x10) {
        return NULL;
    }
    func_0214d1fc(b, e, 4);
    func_ov000_021a8bb0(*(u32 *) e, &e[4]);
    func_0200d9e0(c, 0x10, data_ov000_021b49e8, e[7], e[6], e[5], e[4]);
    return c;
}

void func_ov000_021a8bb0(u32 a, u8 *b) {
    *b = (s8) (a >> 0x18);
    b[1] = (s8) (a >> 0x10);
    b[2] = (s8) (a >> 8);
    b[3] = (s8) a;
    return;
}

s32 func_ov000_021a8b20(void *a, s32 b, s64 c) {
    Unk021a8b20 *d;
    s32 e;
    u32 f;
    u32 g;
    BOOL h;
    h = c != -1;
    for (;;) {
        d = a;
        e = 0;
        for (f = 0; f < b; f++) {
            g = d->mUnk_04 | 0xe0;
            g &= func_ov000_021a8994(d->mUnk_00);
            if (g != 0) {
                e++;
            }
            d->mUnk_06 = g;
            d++;
        }
        if (e > 0) {
            break;
        }
        if (h != FALSE && c <= 0) {
            break;
        }
        func_0200dc3c(1);
        c -= 0x20b;
    }
    return e;
}

void func_ov000_021a8b10(void *arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    u32 value3;
    value1 = (value0) + (0u);
    value0 = (u32) &data_ov000_021b6004;
    value3 = (u32) &func_ov000_021a8b08;
    func_ov000_021a8b08(value0, value1);
    return;
}

void func_ov000_021a8b08(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    value2 = (u32) * (const u32 *) ((value0) + 0u);
    *(u32 *) ((value1) + 124u) = value2;
    *(u32 *) ((value0) + 0u) = value1;
    return;
}

void func_ov000_021a8af8(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value3;
    value1 = (value0) + (0u);
    value0 = (u32) &data_ov000_021b6008;
    value3 = (u32) &func_ov000_021a8b08;
    func_ov000_021a8b08(value0, value1);
    return;
}

void func_ov000_021a8ae8(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value3;
    value1 = (value0) + (0u);
    value0 = (u32) &data_ov000_021b6004;
    value3 = (u32) &func_ov000_021a8ad0;
    func_ov000_021a8ad0((Unk021a8ab8 **) value0, (Unk021a8ab8 *) value1);
    return;
}

void func_ov000_021a8ad0(Unk021a8ab8 **head, Unk021a8ab8 *node) {
    Unk021a8ab8 **link = func_ov000_021a8ab8(head, node);
    if (link != NULL) {
        *link = node->mUnk_7c;
    }
    return;
}

Unk021a8ab8 **func_ov000_021a8ab8(Unk021a8ab8 **head, Unk021a8ab8 *node) {
    Unk021a8ab8 *entry = *head;
    while (entry != NULL) {
        if (entry == node) {
            return head;
        }
        head = &entry->mUnk_7c;
        entry = entry->mUnk_7c;
    }
    return NULL;
}

void func_ov000_021a8aa8(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value3;
    value1 = (value0) + (0u);
    value0 = (u32) &data_ov000_021b6008;
    value3 = (u32) &func_ov000_021a8ad0;
    func_ov000_021a8ad0((Unk021a8ab8 **) value0, (Unk021a8ab8 *) value1);
    return;
}
