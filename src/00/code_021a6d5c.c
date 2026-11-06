#include "00/code_021a6d5c.h"

#include "00/code_021a6d6c.h"
#include "03/code_021b94b8.h"
#include "00/code_021a6fb4.h"
#include "00/code_021a6d1c.h"
#include "00/code_021a669c.h"
#include "00/code_021a6934.h"
#include "00/code_021a73d8.h"
#include "00/code_021a8424.h"
#include "00/code_021a8878.h"
#include "00/code_021ad734.h"
#include "code_0200db4c.h"
#include "code_0214d018.h"
#include "00/unk_021b6000.h"
#include "00/code_021a91b4.h"
#include "Main/Unknown/unk_0216f000.h"
#include "00/unk_021b4000.h"
#include "Main/Unknown/code_02000b44.h"
#include "code_02133048.h"
#include "code_0200fc8c.h"
#include "00/code_021a6fa8.h"
#include "00/code_021a6fc0.h"
#include "00/code_021a88a8.h"
#include "code_0200e77c.h"
#include "00/unk_021b5000.h"
#include "code_0200edc0.h"
#include "00/code_021a72c4.h"
#include "00/code_021a8aa8.h"
#include "00/code_021a78a4.h"
#include "00/code_021a740c.h"
#include "00/code_021a7000.h"
#include "00/code_021ae1e4.h"
#include "00/code_021a7bfc.h"
#include "00/code_021acef8.h"
#include "00/code_02186d04.h"
#include "00/code_021a7bc8.h"
#include "00/code_021ae000.h"
#include "00/code_021a86bc.h"
#include "00/code_021b026c.h"
#include "00/types_021a8ab8.h"
#include "00/code_021a8a80.h"
#include "00/code_0218e2dc.h"
#include "00/code_021a3a18.h"
#include "code_0200d118.h"
#include "00/code_021a87bc.h"
#include "00/code_021a75f8.h"
#include "code_0200c858.h"
#include "00/code_021a8604.h"
#include "00/code_021a836c.h"

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

Unk021a8f84 *func_ov000_021a8f84(const char *a) {
    u32 b = func_ov000_021a88e4(a);
    if (b == 0) {
        return NULL;
    }
    STD_CopyLStringZeroFill((char *) data_ov000_021b6078, a, 0x101);
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

char *func_ov000_021a8c6c(Unk021b5dfc a) {
    func_ov000_021a8bc0(2, &a, data_ov000_021b6030, 0x10);
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
    MI_CpuCopy8(b, e, 4);
    func_ov000_021a8bb0(*(u32 *) e, &e[4]);
    OS_SNPrintf(c, 0x10, data_ov000_021b49e8, e[7], e[6], e[5], e[4]);
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
        OS_Sleep(1);
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

void func_ov000_021a8af8(Unk021a6fa8 *arg0) {
    u32 value0;
    u32 value1;
    u32 value3;
    value1 = ((u32) arg0) + (0u);
    value0 = (u32) &data_ov000_021b6008;
    value3 = (u32) &func_ov000_021a8b08;
    func_ov000_021a8b08(value0, value1);
    return;
}

void func_ov000_021a8ae8(Unk021a6fa8 *arg0) {
    u32 value0;
    u32 value1;
    u32 value3;
    value1 = ((u32) arg0) + (0u);
    value0 = (u32) &data_ov000_021b6004;
    value3 = (u32) &func_ov000_021a8ad0;
    func_ov000_021a8ad0((Unk021a8ab8 **) value0, (Unk021a8ab8 *) value1);
    return;
}

void func_ov000_021a8ad0(Unk021a8ab8 **head, Unk021a8ab8 *node) {
    Unk021a8ab8 **link = func_ov000_021a8ab8(head, node);
    if (link != NULL) {
        *link = node->mNext;
    }
    return;
}

Unk021a8ab8 **func_ov000_021a8ab8(Unk021a8ab8 **head, Unk021a8ab8 *node) {
    Unk021a8ab8 *entry = *head;
    while (entry != NULL) {
        if (entry == node) {
            return head;
        }
        head = &entry->mNext;
        entry = entry->mNext;
    }
    return NULL;
}

void func_ov000_021a8aa8(Unk021a6fa8 *arg0) {
    u32 value0;
    u32 value1;
    u32 value3;
    value1 = ((u32) arg0) + (0u);
    value0 = (u32) &data_ov000_021b6008;
    value3 = (u32) &func_ov000_021a8ad0;
    func_ov000_021a8ad0((Unk021a8ab8 **) value0, (Unk021a8ab8 *) value1);
    return;
}

u32 func_ov000_021a8a80(Unk021a6fa8 *a) {
    if ((s32) a <= 0 || func_ov000_021a8ab8((Unk021a8ab8 **) &data_ov000_021b6004, (Unk021a8ab8 *) a) == NULL) {
        return 1;
    }
    return 0;
}

BOOL func_ov000_021a8a5c(Unk021a8ab8 *node) {
    if (func_ov000_021a8ab8((Unk021a8ab8 **) &data_ov000_021b6008, node) != NULL) {
        return TRUE;
    }
    return FALSE;
}

u32 func_ov000_021a8a54(int a) {
    return a + 3U & 0xfffffffc;
}

// the original reloads the halfword at 0x70 for every test; a volatile view of the object is the only spelling found
u32 func_ov000_021a8994(Unk021a6fa8 *a) {
    u32 b = 0;
    u32 c;
    BOOL d;
    volatile Unk021a6fa8 *v = a;
    if (func_ov000_021a8a80(a) != 0) {
        b |= 0x80;
    } else {
        if ((v->mUnk_70 & 0x40) != 0) {
            b |= 0x20;
        }
        if (a->mUnk_73 == 1 || (v->mUnk_70 & 4) != 0) {
            c = OS_DisableInterrupts();
            if (func_ov000_021a8960(a) > 0) {
                b |= 1;
            }
            if (func_ov000_021a8118(a) > 0) {
                b |= 8;
            }
            OS_RestoreInterrupts(c);
        }
        d = TRUE;
        if (a->mUnk_73 != 0 && a->mUnk_73 != 4) {
            d = FALSE;
        }
        if (d != FALSE) {
            if ((v->mUnk_70 & 4) != 0 && a->mState != 4 && (b & 1) == 0) {
                v->mUnk_70 &= ~6;
            }
            if ((v->mUnk_70 & 2) == 0 && (v->mUnk_70 & 4) == 0) {
                b |= 0x40;
            }
        }
    }
    return b;
}

s32 func_ov000_021a8960(Unk021a6fa8 *a) {
    u32 v1;
    Unk021a71c0 *v2;
    s8 v3;
    v2 = a->mReceiveBlock;
    v1 = 0;
    if (v2 != NULL) {
        v3 = a->mUnk_73;
        if (v3 == 1) {
            if (v2->mUnk_104 != NULL) {
                v1 = v2->mUnk_104->mUnk_04;
            }
        } else if ((v3 == 0) || (v3 == 4)) {
            v1 = a->mReceiveBufferLength - v2->mUnk_f8;
        }
    }
    return v1;
}

s32 func_ov000_021a88e4(const char *a) {
    Unk021a88e4 b;
    u8 *c;
    s32 d;
    if (a == NULL) {
        return 0;
    }
    c = data_ov000_021b5f94->mUnk_18(0x1154);
    if (c == NULL) {
        return 0;
    }
    MI_CpuFill8(&b, 0, 0x64);
    b.mReceiveBuffer.mStart = c;
    b.mReceiveBuffer.mSize = 0xb68;
    b.mSendBuffer.mStart = c + 0xb68;
    b.mSendBuffer.mSize = 0x5ea;
    func_ov000_021ae304(&b);
    d = func_ov000_021acef8(a);
    func_ov000_021ae2f4();
    data_ov000_021b5f94->mUnk_1c(c);
    return d;
}

s32 func_ov000_021a88a8(u32 a) {
    u32 b = OS_DisableInterrupts();
    u32 c = data_ov000_021b63d8[0];
    u32 d = data_ov000_021b63d8[1];
    s32 e;
    data_ov000_021b63d8[0] = 0;
    data_ov000_021b63d8[1] = 0;
    e = func_ov000_021acef8((const char *) a);
    data_ov000_021b63d8[0] = c;
    data_ov000_021b63d8[1] = d;
    OS_RestoreInterrupts(b);
    return e;
}

u32 func_ov000_021a8878(u32 first, u32 second) {
    if (func_ov000_021a8830() == 0) {
        return 0xffffffd9;
    }
    data_ov000_021b63d8[0] = first;
    data_ov000_021b63d8[1] = second;
    return 0;
}

s32 func_ov000_021a8830(void) {
    if (data_ov000_021b63b4 == 0) {
        if ((data_ov000_021b5fa0 & 3) == 1) {
            if (OS_GetProcMode() != 0x12) {
                OS_Sleep(10);
            }
        }
    } else if (data_ov000_021b5f9c == 0) {
        data_ov000_021b5f9c = data_ov000_021b63b4;
    }
    return data_ov000_021b63b4;
}

s32 func_ov000_021a87bc(void) {
    s32 a;
    s32 b;
    if (data_ov000_021b5f9c == 0) {
        data_ov000_021b5f9c = data_ov000_021b63b4;
    }
    a = func_ov000_021a86e8();
    b = -0x1a;
    if (a == b) {
        do {
            OS_Sleep(100);
        } while (func_ov000_021a86e8() == b);
    }
    a = func_ov000_021a70b0();
    if (a >= 0) {
        func_ov000_021b026c();
        func_ov000_021b02b0(NULL);
        if (data_ov000_021b5f94->mUnk_28 == NULL) {
            data_ov000_021b5f94->mUnk_1c(data_ov000_021b5fa8.mUnk_1c);
        }
        data_ov000_021b5f94 = NULL;
    }
    return a;
}

s32 func_ov000_021a8740(void) {
    Unk021a6fa8 *a;
    Unk021a6fa8 *b;
    u32 c;
    for (;;) {
        c = OS_DisableInterrupts();
        a = data_ov000_021b6004;
        if (a != NULL) {
            b = data_ov000_021b5fa4;
            do {
                if (a != b && (a->mUnk_70 & 0x10) == 0) {
                    break;
                }
                a = a->mNext;
            } while (a != NULL);
        }
        OS_RestoreInterrupts(c);
        if (a == NULL) {
            break;
        }
        func_ov000_021a8604((s32) a);
    }
    if (data_ov000_021b6004 == NULL ||
        (data_ov000_021b6004 == data_ov000_021b5fa4 && data_ov000_021b6004->mNext == NULL)) {
        if (data_ov000_021b6008 == NULL) {
            return 0;
        }
    }
    return -0x1a;
}

s32 func_ov000_021a86e8(void) {
    s32 a;
    func_ov000_021a8740();
    if (data_ov000_021b5fa4 != NULL) {
        a = func_ov000_021a8740();
        if (a == 0) {
            func_ov000_021a8604((s32) data_ov000_021b5fa4);
            if (func_ov000_021a86bc(data_ov000_021b5fa4) != 0) {
                data_ov000_021b5fa4 = NULL;
            }
            a = -0x1a;
        }
        func_ov000_021a8424();
    } else {
        if (func_ov000_021b02bc() != 0) {
            a = 0;
        } else {
            a = -0x1a;
        }
    }
    return a;
}

u32 func_ov000_021a86bc(Unk021a6fa8 *a) {
    int v1;
    if (((0 <= (s32) a) && (v1 = func_ov000_021a8a80(a), v1 != 0)) &&
        (v1 = func_ov000_021a8a5c((Unk021a8ab8 *) a), v1 == 0)) {
        return 1;
    }
    return 0;
}

static inline s32 func_ov000_021a7c4c_inline(Unk021a6fa8 *a) {
    BOOL b = TRUE;
    if (a->mUnk_73 != 0 && a->mUnk_73 != 4) {
        b = FALSE;
    }
    return b;
}

static inline s32 func_ov000_021a7de0_inline(Unk021a6fa8 *a) {
    BOOL b = FALSE;
    if (a != NULL) {
        b = (a->mUnk_70 & 1) != 0;
    }
    return b;
}

s32 func_ov000_021a8604(s32 param_1) {
    volatile Unk021a6fa8 *v;
    Unk021a6fa8 *a = (Unk021a6fa8 *) param_1;
    Unk021a7064 *c;
    v = a;
    if (param_1 <= 0) {
        return -0x1c;
    }
    if (func_ov000_021a8a5c((Unk021a8ab8 *) a) != FALSE) {
        return -0x1a;
    }
    if (func_ov000_021a8a80(a) != 0) {
        return 0;
    }
    if (func_ov000_021a7de0_inline(a) == 0) {
        return -0x27;
    }
    if ((v->mUnk_70 & 0x10) != 0) {
        return -0x1a;
    }
    v->mUnk_70 |= 0x18;
    if (func_ov000_021a7c4c_inline(a) != 0) {
        func_ov000_021a7008(a->mSendBlock, NULL);
    }
    c = func_ov000_021a7064(func_ov000_021a8580, a, 1);
    c->mUnk_0d = 0;
    return func_ov000_021a6f84(a, c);
}

s32 func_ov000_021a8580(Unk021a7064 *a) {
    Unk021a6fa8 *b = a->mUnk_04;
    void *c;
    u32 d;
    if (func_ov000_021a7c4c_inline(b) != 0) {
        OS_JoinThread(&((Unk021a722a *) b->mSendBlock)->mUnk_00.mUnk_20);
        func_ov000_021ae094();
        func_ov000_021ae048();
        func_ov000_021ae258();
    }
    func_ov000_021ae2f4();
    b->mUnk_70 &= ~6;
    if (b->mUnk_73 == 2) {
        c = b->mSendBlock;
    } else {
        c = b->mReceiveBlock;
    }
    func_ov000_021a7008(c, NULL);
    d = OS_DisableInterrupts();
    func_ov000_021a8ae8(b);
    func_ov000_021a8af8(b);
    OS_RestoreInterrupts(d);
    b->mUnk_70 |= 0x20;
    return 0;
}

void func_ov000_021a84c4(Unk021a6fa8 *a) {
    Unk021a78a4 *b;
    Unk021a78a4 *c;
    u32 d;
    if (a != NULL) {
        a->mUnk_70 = 0;
        if (func_ov000_021a7c4c_inline(a) != 0) {
            func_ov000_021a8454(a->mSendBlock);
            func_ov000_021a8454(a->mReceiveBlock);
        } else if (a->mUnk_73 == 1) {
            b = ((Unk021a71c0 *) a->mReceiveBlock)->mUnk_104;
            while (b != NULL) {
                c = b->mUnk_00;
                data_ov000_021b5f94->mUnk_1c(b);
                b = c;
            }
            ((Unk021a71c0 *) a->mReceiveBlock)->mUnk_108 = 0;
            ((Unk021a71c0 *) a->mReceiveBlock)->mUnk_100 = NULL;
            ((Unk021a71c0 *) a->mReceiveBlock)->mUnk_104 = NULL;
            OS_WakeupThread(&((Unk021a71c0 *) a->mReceiveBlock)->mUnk_10c);
            func_ov000_021a8454(a->mReceiveBlock);
        } else if (a->mUnk_73 == 2) {
            func_ov000_021a8454(a->mSendBlock);
        }
        d = OS_DisableInterrupts();
        func_ov000_021a8ae8(a);
        func_ov000_021a8aa8(a);
        data_ov000_021b5f94->mUnk_1c(a);
        OS_RestoreInterrupts(d);
    }
}

void func_ov000_021a8454(Unk021a7154 *a) {
    Unk021a7064 *b;
    u32 c;
    if (a != NULL) {
        OS_JoinThread(&a->mUnk_20);
        c = OS_DisableInterrupts();
        OS_DisableScheduler();
        if (OS_ReceiveMessage(&a->mUnk_00, (void **) &b, 0) != 0) {
            do {
                if (b != NULL) {
                    if (b->mUnk_08 != NULL) {
                        OS_SendMessage(b->mUnk_08, (void *) -11, 0);
                    }
                    func_ov000_021a7048(b);
                }
            } while (OS_ReceiveMessage(&a->mUnk_00, (void **) &b, 0) != 0);
        }
        OS_EnableScheduler();
        OS_RestoreInterrupts(c);
        OSi_RescheduleThread();
    }
}

void func_ov000_021a8424(void) {
    u32 a = OS_DisableInterrupts();
    while (data_ov000_021b6008 != NULL) {
        func_ov000_021a84c4(data_ov000_021b6008);
    }
    OS_RestoreInterrupts(a);
}

s32 func_ov000_021a836c(s32 param_1) {
    volatile Unk021a6fa8 *v;
    Unk021a6fa8 *a = (Unk021a6fa8 *) param_1;
    Unk021a722a *b;
    Unk021a7064 *c;
    v = a;
    if (func_ov000_021a8a80(a) != 0) {
        return -0x1c;
    }
    if (func_ov000_021a7de0_inline(a) == 0) {
        return -0x27;
    }
    if ((v->mUnk_70 & 4) == 0 || (v->mUnk_70 & 8) != 0) {
        return -0x38;
    }
    v->mUnk_70 |= 8;
    b = a->mSendBlock;
    if (b != NULL && b->mUnk_10c != NULL) {
        c = func_ov000_021a7064(func_ov000_021a8344, b->mUnk_10c, a->mUnk_72);
        if (c == NULL) {
            return -0x21;
        }
        return func_ov000_021a6fa8(b->mUnk_10c, c);
    }
    return 0;
}

s32 func_ov000_021a8344(Unk021a7064 *a) {
    if (func_ov000_021a7c4c_inline(a->mUnk_04) != 0) {
        func_ov000_021ae094();
    }
    return 0;
}

u32 func_ov000_021a8268(u32 a, u32 b, u32 c, u16 d, u32 e, u32 f) {
    volatile Unk021a6fa8 *v;
    Unk021a6fa8 *g = (Unk021a6fa8 *) a;
    Unk021a722a *h;
    BOOL i;
    s32 j;
    v = g;
    if (func_ov000_021a8a80(g) != 0) {
        return -0x1c;
    }
    if (func_ov000_021a7de0_inline(g) == 0) {
        return -0x27;
    }
    if (func_ov000_021a7c4c_inline(g) != 0) {
        if ((v->mUnk_70 & 4) == 0 || (v->mUnk_70 & 8) != 0) {
            return -0x38;
        }
    }
    h = g->mSendBlock;
    if ((f & 4) != 0 || g->mUnk_72 == 0) {
        if (OS_TryLockMutex(&h->mUnk_00.mUnk_e0) == 0) {
            return -6;
        }
        i = FALSE;
    } else {
        OS_LockMutex(&h->mUnk_00.mUnk_e0);
        i = TRUE;
    }
    j = func_ov000_021a81a8(g, (u8 *) b, c, d, (u16 *) e, i);
    OS_UnlockMutex(&h->mUnk_00.mUnk_e0);
    return j;
}

s32 func_ov000_021a81a8(Unk021a6fa8 *a, u8 *b, s32 c, u16 d, u16 *e, s32 f) {
    s32 h;
    s32 g;
    s32 i;
    u32 j;
    g = 0;
    h = ((Unk021a722a *) a->mSendBlock)->mUnk_10c->mSendBuffer.mSize;
    if (a->mUnk_73 == 1) {
        h -= 0x2a;
        if (c > h) {
            return -0x23;
        }
        h = c;
    } else {
        h -= 0x36;
        if (c <= h) {
            h = c;
        }
    }
    while (c > 0) {
        i = func_ov000_021a813c(a, c, h, &j, f);
        if (i > 0) {
            if (func_ov000_021a8014(a, b, i, j, d, e, f) <= 0) {
                return -6;
            }
            b += i;
            c -= i;
            g += i;
        }
        if (f == 0) {
            if (i > 0) {
                break;
            }
            return -6;
        }
    }
    return g;
}

s32 func_ov000_021a813c(Unk021a6fa8 *a, s32 b, s32 c, u32 *d, s32 e) {
    Unk021a722a *f = a->mSendBlock;
    s32 g;
    u32 h;
    if (c > b) {
        c = b;
    }
    h = OS_DisableInterrupts();
    for (;;) {
        g = func_ov000_021a8118(a);
        if (g >= c) {
            if (g >= b) {
                g = b;
            }
            *d = f->mUnk_100;
            break;
        }
        if (e == 0) {
            g = 0;
            break;
        }
        OS_SleepThread((OSThreadQueue *) &f->mUnk_104);
    }
    OS_RestoreInterrupts(h);
    return g;
}

s32 func_ov000_021a8118(Unk021a6fa8 *a) {
    Unk021a722a *b = a->mSendBlock;
    s32 c = b->mUnk_f8.mSize;
    s32 d = b->mUnk_100;
    d = b->mUnk_102 - d - 1;
    if (d < 0) {
        d += c;
    }
    return d;
}

s32 func_ov000_021a8014(Unk021a6fa8 *a, u8 *b, s32 c, s32 d, u16 e, u16 *f, s32 g) {
    Unk021a722a *h = a->mSendBlock;
    Unk021a7eec *i;
    s32 j;
    u8 *k;
    s32 l;
    s32 m;
    i = (Unk021a7eec *) func_ov000_021a7064(func_ov000_021a7f48, h->mUnk_10c, g);
    if (i == NULL) {
        return -0x21;
    }
    i->mUnk_0d = 0;
    j = 0;
    k = h->mUnk_f8.mStart;
    l = h->mUnk_f8.mSize;
    m = d + c;
    if (m < l) {
        i->mUnk_10 = k + d;
        i->mUnk_14 = c;
        i->mUnk_18 = (u8 *) j;
        i->mUnk_1c = j;
        d = m;
    } else {
        i->mUnk_10 = k + d;
        i->mUnk_14 = l - d;
        i->mUnk_18 = k;
        i->mUnk_1c = c - i->mUnk_14;
        d = i->mUnk_1c;
        MI_CpuCopy8(b + i->mUnk_14, i->mUnk_18, d);
    }
    MI_CpuCopy8(b, i->mUnk_10, i->mUnk_14);
    i->mUnk_20 = d;
    h->mUnk_100 = i->mUnk_20;
    if (a->mUnk_73 == 1) {
        if (a->mUnk_74 == 0) {
            a->mUnk_74 = func_ov000_021ae340();
            a->mUnk_0a = a->mUnk_74;
        }
        i->mUnk_24 = a->mUnk_74;
        if (a->mUnk_78 == NULL || f != NULL) {
            i->mUnk_28 = f;
            i->mUnk_26 = e;
        } else {
            i->mUnk_28 = a->mUnk_78;
            i->mUnk_26 = a->mUnk_76;
        }
    } else {
        i->mUnk_28 = NULL;
    }
    if (func_ov000_021a6fa8(h->mUnk_10c, i) != 0) {
        c = 0;
    }
    return c;
}

s32 func_ov000_021a7f48(Unk021a7064 *param_1) {
    Unk021a7eec *a = (Unk021a7eec *) param_1;
    Unk021a6fa8 *b = a->mUnk_04;
    Unk021a722a *c = b->mSendBlock;
    s32 e;
    u8 *f;
    s32 d = 0;
    s32 g;
    s32 h;
    if (func_ov000_021a7c4c_inline(b) == 0 || (b->mUnk_70 & 4) != 0) {
        if (a->mUnk_28 != NULL) {
            func_ov000_021ae290(a->mUnk_24, a->mUnk_26, (s32) a->mUnk_28);
        }
        if (func_ov000_021a7c4c_inline(b) != 0) {
            e = 0x36;
        } else {
            e = 0x2a;
        }
        f = b->mSendBuffer.mStart + e;
        g = b->mSendBuffer.mSize - e;
        for (;;) {
            h = func_ov000_021a7eec(f, g, a);
            if (h <= 0) {
                break;
            }
            h = func_ov000_021adbf4(f, h);
            if (h <= 0) {
                if (func_ov000_021a7c4c_inline(b) != 0) {
                    b->mUnk_70 &= ~0xe;
                }
                d = -0x4c;
                break;
            }
            d += h;
        }
    } else {
        d = -0x4c;
    }
    c->mUnk_102 = a->mUnk_20;
    OS_WakeupThread((OSThreadQueue *) &c->mUnk_104);
    return d;
}

s32 func_ov000_021a7eec(const void *a, s32 b, Unk021a7eec *c) {
    s32 d = c->mUnk_14;
    s32 e = c->mUnk_1c;
    if (d > b) {
        d = b;
        e = 0;
    } else if (e > b - d) {
        e = b - d;
    }
    if (d > 0) {
        MI_CpuCopy8(c->mUnk_10, a, d);
        c->mUnk_10 += d;
        c->mUnk_14 -= d;
    }
    if (e > 0) {
        MI_CpuCopy8(c->mUnk_18, (u8 *) a + d, e);
        c->mUnk_18 += e;
        c->mUnk_1c -= e;
    }
    return d + e;
}

u32 func_ov000_021a7de0(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f) {
    volatile Unk021a6fa8 *v;
    Unk021a6fa8 *g = (Unk021a6fa8 *) a;
    Unk021a71c0 *h;
    s32 i;
    v = g;
    if (func_ov000_021a8a80(g) != 0) {
        return -0x1c;
    }
    if ((f & 4) != 0 || g->mUnk_72 == 0) {
        if (g->mUnk_73 == 4) {
            return -0x1c;
        }
        i = 0;
    } else {
        if (OS_GetProcMode() == 0x12) {
            return -0x1c;
        }
        i = 1;
    }
    if (func_ov000_021a7de0_inline(g) == 0) {
        return -0x27;
    }
    if (func_ov000_021a7c4c_inline(g) != 0) {
        if ((v->mUnk_70 & 4) == 0 || (v->mUnk_70 & 8) != 0) {
            return -0x38;
        }
    }
    h = g->mReceiveBlock;
    if (i == 0) {
        if (OS_TryLockMutex(&h->mUnk_00.mUnk_e0) == 0) {
            return -6;
        }
    } else {
        OS_LockMutex(&h->mUnk_00.mUnk_e0);
    }
    i = func_ov000_021a7d68(g, (void *) b, c, (u16 *) d, (u32 *) e, i, f);
    OS_UnlockMutex(&h->mUnk_00.mUnk_e0);
    return i;
}

s32 func_ov000_021a7d68(Unk021a6fa8 *a, void *b, s32 c, u16 *d, u32 *e, s32 f, s32 g) {
    Unk021a71c0 *h = a->mReceiveBlock;
    s32 i;
    s32 j;
    BOOL k;
    if ((g & 2) != 0 && h != NULL) {
        k = TRUE;
    } else {
        k = FALSE;
    }
    if (k != FALSE) {
        i = h->mUnk_fe;
        h->mUnk_fe = 1;
    }
    if (a->mUnk_73 == 1) {
        j = func_ov000_021a797c(a, b, c, d, e, f);
    } else {
        j = func_ov000_021a7d14(a, b, c, d, e, f);
        if (j >= 0) {
            func_ov000_021a7aa8(a);
        }
    }
    if (k != FALSE) {
        h->mUnk_fe = i;
    }
    return j;
}

s32 func_ov000_021a7d14(Unk021a6fa8 *a, void *b, s32 c, u16 *d, u32 *e, s32 f) {
    s32 g;
    if (a->mUnk_73 == 4) {
        return func_ov000_021a7bc8(a, (u32) b, (u32) c, (u32) d, (u32) e);
    }
    g = func_ov000_021a7c4c(a, b, c, d, e);
    if (g == -6 && f == 1) {
        g = func_ov000_021a7bc8(a, (u32) b, (u32) c, (u32) d, (u32) e);
    }
    return g;
}

s32 func_ov000_021a7c4c(Unk021a6fa8 *a, void *b, s32 c, u16 *d, u32 *e) {
    u32 f = OS_DisableInterrupts();
    u16 g[2];
    s32 h;
    u32 i;
    u8 *j;
    s32 k;
    j = func_ov000_021a7bfc(a, &h, &g[0], &g[1], &i);
    if (j != NULL) {
        k = h;
        if (k == 0) {
            k = -6;
        } else {
            if (c > k) {
                c = k;
            }
            if (func_ov000_021a7c4c_inline(a) != 0) {
                k = c;
            }
            MI_CpuCopy8(j, b, c);
            if (((Unk021a71c0 *) a->mReceiveBlock)->mUnk_fe == 0) {
                ((Unk021a71c0 *) a->mReceiveBlock)->mUnk_f8 = ((Unk021a71c0 *) a->mReceiveBlock)->mUnk_f8 + k;
            }
        }
    } else {
        if (h == 0) {
            k = 0;
        } else {
            k = -0x1c;
        }
        a->mUnk_70 &= ~6;
    }
    if (k >= 0) {
        if (d != NULL && e != NULL) {
            *d = g[1];
            *e = i;
        }
        if (a->mUnk_74 == 0) {
            a->mUnk_74 = g[0];
        }
    }
    OS_RestoreInterrupts(f);
    return k;
}

u8 *func_ov000_021a7bfc(Unk021a6fa8 *a, s32 *b, u16 *c, u16 *d, u32 *e) {
    Unk021a71c0 *f = a->mReceiveBlock;
    Unk021a6fa8 *g = *(Unk021a6fa8 **) f->mUnk_00.mUnk_20.mUnk_a4;
    s32 h = f->mUnk_f8;
    s32 i = g->mReceiveBufferLength - h;
    if (i >= 0) {
        *c = g->mUnk_0a;
        *d = g->mUnk_18;
        *e = g->mUnk_1c;
        *b = i;
        if (i == 0 && g->mState != 4) {
            return NULL;
        }
    } else {
        *b = -1;
        return NULL;
    }
    return g->mReceiveBuffer.mStart + h;
}

s32 func_ov000_021a7bc8(Unk021a6fa8 *p0, u32 p1, u32 p2, u32 p3, u32 p4) {
    u32 v3 = ((p1) + (0x0u));
    u32 v4 = ((p2) + (0x0u));
    u32 v5 = ((p3) + (0x0u));
    Unk021a7064Func v6 = (Unk021a7064Func) func_ov000_021a7af0;
    u32 v9 = ((u32) func_ov000_021a7064(v6, p0, (s32) 0x1u));
    u32 v10 = ((v9) + (0x0u));
    u32 v14;
    u32 v17;
    *(u32 *) ((v10) + (16)) = v3;
    *(u32 *) ((v10) + (20)) = v4;
    *(u32 *) ((v10) + (24)) = v5;
    v14 = p4;
    *(u32 *) ((v10) + (28)) = v14;
    v17 = func_ov000_021a6fb4(p0, (Unk021a7064 *) v10);
    return v17;
}

s32 func_ov000_021a7af0(Unk021a7064 *param_1) {
    Unk021a7af0 *a = (Unk021a7af0 *) param_1;
    Unk021a6fa8 *b = a->mUnk_04;
    Unk021a71c0 *c = b->mReceiveBlock;
    u8 *d = a->mUnk_10;
    u32 e = a->mUnk_14;
    u16 *f = a->mUnk_18;
    u32 *g = a->mUnk_1c;
    s32 h = c->mUnk_f8;
    const u8 *i;
    s32 j;
    BOOL k;
    for (;;) {
        i = func_ov000_021adf78((u32 *) &j);
        if (i == NULL) {
            break;
        }
        if (j - h > 0) {
            break;
        }
        k = TRUE;
        if (b->mUnk_73 != 0 && b->mUnk_73 != 4) {
            k = FALSE;
        }
        if (k != FALSE && b->mState != 4) {
            i = NULL;
            break;
        }
        OS_Sleep(10);
    }
    if (b->mUnk_73 == 4) {
        if (i == NULL) {
            return 0;
        }
        if (e > j) {
            e = j;
        }
        MI_CpuCopy8(i, d, e);
        func_ov000_021adf00(e);
        return e;
    }
    if (i != NULL) {
        h = func_ov000_021a7c4c(b, d, e, f, g);
    } else {
        h = 0;
    }
    if (h <= 0) {
        return h;
    }
    if (c->mUnk_f8 >= c->mUnk_fc) {
        func_ov000_021a7a6c(b);
    }
    return h;
}

static inline s32 func_ov000_021a797c_inline(Unk021a6fa8 *a) {
    BOOL b = FALSE;
    if (a != NULL) {
        b = (a->mUnk_70 & 1) != 0;
    }
    return b;
}

s32 func_ov000_021a7aa8(Unk021a6fa8 *a) {
    Unk021a71c0 *b = a->mReceiveBlock;
    Unk021a7064 *c;
    if (b->mUnk_f8 < b->mUnk_fc) {
        return 0;
    }
    c = func_ov000_021a7064(func_ov000_021a7a9c, a, 0);
    if (c == NULL) {
        return -0x21;
    }
    return func_ov000_021a6fb4(a, c);
}

s32 func_ov000_021a7a9c(Unk021a7064 *a) {
    return func_ov000_021a7a6c(a->mUnk_04);
}

s32 func_ov000_021a7a6c(Unk021a6fa8 *a) {
    Unk021a71c0 *b = a->mReceiveBlock;
    u32 c = OS_DisableInterrupts();
    s32 d = b->mUnk_f8;
    if (d != 0) {
        b->mUnk_f8 = 0;
        func_ov000_021adf00(d);
    }
    OS_RestoreInterrupts(c);
    return d;
}

s32 func_ov000_021a797c(Unk021a6fa8 *a, void *b, s32 c, u16 *d, u32 *e, s32 f) {
    Unk021a71c0 *h = a->mReceiveBlock;
    u32 i;
    s32 g;
    Unk021a78a4 *j;
    *(Unk021a78a4 *volatile *) &h->mUnk_104;
    i = OS_DisableInterrupts();
    j = h->mUnk_104;
    while (j == NULL) {
        if (f == 0) {
            g = -6;
            break;
        }
        OS_SleepThread(&h->mUnk_10c);
        if (func_ov000_021a8a80(a) != 0 || func_ov000_021a797c_inline(a) == 0) {
            g = -0x38;
            break;
        }
        j = h->mUnk_104;
    }
    if (j != NULL) {
        if (c > j->mUnk_04) {
            c = j->mUnk_04;
        }
        MI_CpuCopy8(j->mUnk_0c, b, c);
        if (d != NULL) {
            *d = j->mUnk_06;
        }
        if (e != NULL) {
            *e = j->mUnk_08;
        }
        g = j->mUnk_04;
        if (h->mUnk_fe == 0) {
            h->mUnk_104 = j->mUnk_00;
            if (j->mUnk_00 == NULL) {
                h->mUnk_100 = NULL;
            }
            data_ov000_021b5f94->mUnk_1c(j);
            h->mUnk_108 -= g;
        }
    }
    OS_RestoreInterrupts(i);
    return g;
}

s32 func_ov000_021a78a4(void *param_1, u32 param_2, Unk021a6fa8 *param_3) {
    Unk021a71c0 *d = param_3->mReceiveBlock;
    u32 e = OS_DisableInterrupts();
    if (d->mUnk_10a >= d->mUnk_108 + param_2) {
        Unk021a78a4 *f = data_ov000_021b5f94->mUnk_18(param_2 + 0xc);
        if (f != NULL) {
            d->mUnk_108 += param_2;
            f->mUnk_00 = NULL;
            f->mUnk_04 = param_2;
            f->mUnk_06 = param_3->mUnk_18;
            f->mUnk_08 = param_3->mUnk_1c;
            MI_CpuCopy8(param_1, f->mUnk_0c, param_2);
            if (param_3->mUnk_74 == 0) {
                param_3->mUnk_74 = param_3->mUnk_0a;
            }
            param_3->mUnk_18 = param_3->mUnk_1a;
            param_3->mUnk_1c = param_3->mUnk_20;
            if (((const Unk021a71c0 *) d)->mUnk_100 != NULL) {
                d->mUnk_100->mUnk_00 = f;
            }
            d->mUnk_100 = f;
            if (d->mUnk_104 == NULL) {
                d->mUnk_104 = f;
            }
        } else {
            data_ov000_021b5ffc[0]++;
        }
    } else {
        data_ov000_021b5ffc[1]++;
    }
    OS_WakeupThread(&d->mUnk_10c);
    OS_RestoreInterrupts(e);
    return 1;
}

s32 func_ov000_021a7824(Unk021a6fa8 *param_1, u16 param_2) {
    BOOL a;
    if (func_ov000_021a8a80(param_1) != 0) {
        return -28;
    }
    a = FALSE;
    if (param_1 != NULL) {
        a = (param_1->mUnk_70 & 1) != 0;
    }
    if (a == FALSE) {
        return -39;
    }
    if (param_1->mUnk_70 & 2) {
        return -7;
    }
    param_1->mUnk_74 = param_2;
    if (param_1->mUnk_73 == 1) {
        return func_ov000_021a76f4(param_1);
    }
    return 0;
}

s32 func_ov000_021a7748(Unk021a6fa8 *param_1, u16 param_2, u16 *param_3) {
    s32 a;
    BOOL b;
    volatile Unk021a6fa8 *v = param_1;

    if (func_ov000_021a8a80(param_1) != 0 || (v->mUnk_70 & 8)) {
        return -28;
    }
    b = FALSE;
    if (param_1 != NULL) {
        b = (param_1->mUnk_70 & 1) != 0;
    }
    if (b == FALSE) {
        return -39;
    }
    b = TRUE;
    if (param_1->mUnk_73 != 0 && param_1->mUnk_73 != 4) {
        b = FALSE;
    }
    if (b != FALSE) {
        if (v->mUnk_70 & 4) {
            if (param_1->mUnk_72 == 1) {
                return -30;
            }
            return 0;
        }
        if (v->mUnk_70 & 2) {
            if (v->mUnk_70 & 0x40) {
                return param_1->mEntryResult;
            }
            return data_ov000_021b49b4;
        }
        param_1->mUnk_76 = param_2;
        param_1->mUnk_78 = param_3;
        a = func_ov000_021a76f4(param_1);
        if (param_1->mUnk_72 == 1) {
            return a;
        }
        return -26;
    }
    param_1->mUnk_76 = param_2;
    param_1->mUnk_78 = param_3;
    return 0;
}

s32 func_ov000_021a76f4(Unk021a6fa8 *param_1) {
    Unk021a7064 *a;

    a = func_ov000_021a7064(func_ov000_021a7680, param_1, param_1->mUnk_72);
    if (a == NULL) {
        return -33;
    }
    a->mUnk_10 = param_1->mUnk_74;
    a->mUnk_12 = param_1->mUnk_76;
    a->mUnk_14 = param_1->mUnk_78;
    param_1->mUnk_70 |= 2;
    return func_ov000_021a6fb4(param_1, a);
}

s32 func_ov000_021a7680(Unk021a7064 *param_1) {
    Unk021a6fa8 *a;
    Unk021a71c0 *b;
    s32 c;

    a = param_1->mUnk_04;
    c = 0;
    b = a->mReceiveBlock;
    OS_LockMutex(&b->mUnk_00.mUnk_e0);
    func_ov000_021ae290(param_1->mUnk_10, param_1->mUnk_12, (s32) param_1->mUnk_14);
    b->mUnk_f8 = 0;
    if (param_1->mUnk_0c == 0 || param_1->mUnk_0c == 4) {
        c = func_ov000_021ae134();
    }
    OS_UnlockMutex(&b->mUnk_00.mUnk_e0);
    if (c != 0) {
        a->mUnk_70 |= 0x40;
        return -76;
    }
    a->mUnk_70 |= 4;
    return 0;
}

s32 func_ov000_021a75f8(s32 param_1) {
    Unk021a6fa8 *a = (Unk021a6fa8 *) param_1;
    BOOL b;

    if (func_ov000_021a8a80(a) != 0) {
        return -28;
    }
    b = FALSE;
    if (a != NULL) {
        b = (a->mUnk_70 & 1) != 0;
    }
    if (b == FALSE) {
        return -39;
    }
    if (a->mUnk_70 & 2) {
        return -28;
    }
    b = TRUE;
    if (a->mUnk_73 != 0 && a->mUnk_73 != 4) {
        b = FALSE;
    }
    if (b == FALSE) {
        return -28;
    }
    if (a->mUnk_72 == 1) {
        return 0;
    }
    return -6;
}

s32 func_ov000_021a7534(Unk021a6fa8 *param_1, u16 *param_2, u32 *param_3) {
    s32 a;
    BOOL b;
    s32 c;

    if (func_ov000_021a8a80(param_1) != 0) {
        return -28;
    }
    b = FALSE;
    if (param_1 != NULL) {
        b = (param_1->mUnk_70 & 1) != 0;
    }
    if (b == FALSE) {
        return -39;
    }
    if (param_1->mUnk_70 & 2) {
        return -28;
    }
    b = TRUE;
    if (param_1->mUnk_73 != 0 && param_1->mUnk_73 != 4) {
        b = FALSE;
    }
    if (b == FALSE) {
        return -28;
    }
    if (param_1->mUnk_72 != 1) {
        return -6;
    }
    a = func_ov000_021a73d8(&data_ov000_021b49b8);
    if (a < 0) {
        return a;
    }
    c = func_ov000_021a7824((Unk021a6fa8 *) a, param_1->mUnk_74);
    if (c < 0) {
        return c;
    }
    c = func_ov000_021a7468((Unk021a6fa8 *) a, param_2, param_3);
    if (c < 0) {
        return c;
    }
    return a;
}

s32 func_ov000_021a7468(Unk021a6fa8 *param_1, u16 *param_2, u32 *param_3) {
    Unk021a7064 *a;
    BOOL b;
    s32 c;

    if (func_ov000_021a8a80(param_1) != 0) {
        return -28;
    }
    b = FALSE;
    if (param_1 != NULL) {
        b = (param_1->mUnk_70 & 1) != 0;
    }
    if (b == FALSE) {
        return -39;
    }
    if (param_1->mUnk_70 & 2) {
        return -28;
    }
    b = TRUE;
    if (param_1->mUnk_73 != 0 && param_1->mUnk_73 != 4) {
        b = FALSE;
    }
    if (b == FALSE) {
        return -28;
    }
    if (param_1->mUnk_72 != 1) {
        return -6;
    }
    if (param_1->mUnk_74 == 0) {
        return -28;
    }
    a = func_ov000_021a7064(func_ov000_021a740c, param_1, param_1->mUnk_72);
    a->mUnk_10 = param_1->mUnk_74;
    a->mUnk_14 = param_2;
    a->mUnk_18 = param_3;
    param_1->mUnk_70 |= 2;
    return func_ov000_021a6fb4(param_1, a);
}

s32 func_ov000_021a740c(Unk021a7064 *param_1) {
    Unk021a6fa8 *a;
    Unk021a71c0 *b;
    u16 c;
    u32 d;
    u32 e;

    a = param_1->mUnk_04;
    b = a->mReceiveBlock;
    OS_LockMutex(&b->mUnk_00.mUnk_e0);
    func_ov000_021ae290(param_1->mUnk_10, 0, 0);
    func_ov000_021ae1e4();
    b->mUnk_f8 = 0;
    e = func_ov000_021ae100(&c, &d);
    *param_1->mUnk_14 = c;
    *param_1->mUnk_18 = e;
    a->mUnk_70 |= 4;
    OS_UnlockMutex(&b->mUnk_00.mUnk_e0);
    return 0;
}

s32 func_ov000_021a73d8(Unk021b49b8 *a) {
    Unk021a6fa8 *v1;
    Unk021a7064 *v2;
    v1 = func_ov000_021a732c(a);
    if (v1 == NULL) {
        return -0x31;
    }
    v2 = func_ov000_021a7064(func_ov000_021a7378, v1, 1);
    func_ov000_021a6f84(v1, v2);
    return (s32) v1;
}

s32 func_ov000_021a7378(Unk021a7064 *param_1) {
    Unk021a6fa8 *a;
    Unk021a7154 *b;

    a = param_1->mUnk_04;
    func_ov000_021ae304(a);
    b = a->mSendBlock;
    switch (a->mUnk_73) {
        case 0:
        case 4:
            func_ov000_021ae244(&b->mUnk_20);
            func_ov000_021ae270();
            break;
        case 1:
            func_ov000_021ae270();
            func_ov000_021ae2d8();
            func_ov000_021ae214(func_ov000_021a78a4);
            break;
        case 2:
            func_ov000_021ae2d8();
            break;
        case 3:
            break;
    }
    a->mUnk_70 = 1;
    return 0;
}

Unk021a6fa8 *func_ov000_021a732c(Unk021b49b8 *param_1) {
    s32 a;
    u32 b;
    Unk021a6fa8 *c;

    a = func_ov000_021a72c4(param_1);
    b = OS_DisableInterrupts();
    c = data_ov000_021b5f94->mUnk_18(a);
    if (c != NULL) {
        MI_CpuFill8(c, 0, a);
        func_ov000_021a71c0(c, param_1);
        func_ov000_021a8b10(c);
    }
    OS_RestoreInterrupts(b);
    return c;
}

s32 func_ov000_021a72c4(Unk021b49b8 *param_1) {
    s32 a = 0x80;

    if (param_1->mUnk_02 != 0) {
        a += 0x114;
        a += func_ov000_021a8a54(param_1->mUnk_02);
        a += func_ov000_021a8a54(param_1->mUnk_08);
        a += func_ov000_021a72a4(&param_1->mUnk_10);
    }
    if (param_1->mUnk_06 != 0) {
        a += 0x110;
        a += func_ov000_021a8a54(param_1->mUnk_06);
        a += func_ov000_021a8a54(param_1->mUnk_0a);
        a += func_ov000_021a8a54(param_1->mUnk_0c);
        a += func_ov000_021a72a4(&param_1->mUnk_14);
    }
    return a;
}

int func_ov000_021a72a4(Unk021a72a4 *a) {
    int v1;
    int v2;
    v1 = func_ov000_021a8a54(a->mUnk_03 << 2);
    v2 = func_ov000_021a8a54(a->mUnk_00);
    return v1 + v2;
}

u8 *func_ov000_021a71c0(Unk021a6fa8 *d, Unk021b49b8 *e) {
    u8 *a;
    Unk021a71c0 *b;
    Unk021a722a *c;

    d->mUnk_73 = e->mUnk_00;
    d->mUnk_72 = e->mUnk_01;
    a = (u8 *) &d->mUnk_80;
    if (e->mUnk_02 != 0) {
        b = &d->mUnk_80;
        d->mReceiveBlock = a;
        b->mUnk_fc = e->mUnk_04;
        a = func_ov000_021a7154(b->mUnk_114, &b->mUnk_00, &e->mUnk_10);
        a = func_ov000_021a71a4(a, &d->mReceiveBuffer, e->mUnk_02);
        a = func_ov000_021a71a4(a, &d->mUnk_50, e->mUnk_08);
        b->mUnk_10a = e->mUnk_0e;
        b->mUnk_10c.mTail = NULL;
        b->mUnk_10c.mHead = b->mUnk_10c.mTail;
    }
    if (e->mUnk_06 != 0) {
        c = (Unk021a722a *) a;
        d->mSendBlock = a;
        c->mUnk_10c = d;
        a = func_ov000_021a7154(c->mUnk_110, &c->mUnk_00, &e->mUnk_14);
        a = func_ov000_021a71a4(a, &d->mSendBuffer, e->mUnk_06);
        a = func_ov000_021a71a4(a, &d->mUnk_58, e->mUnk_0a);
        a = func_ov000_021a71a4(a, &c->mUnk_f8, e->mUnk_0c);
        c->mUnk_108 = 0;
        c->mUnk_104 = c->mUnk_108;
    } else {
        d->mSendBlock = data_ov000_021b5fa4->mSendBlock;
    }
    return a;
}

u8 *func_ov000_021a71a4(u8 *a, Unk021a71a4 *b, s32 c) {
    u8 *v1;
    v1 = a;
    if (c == 0) {
        v1 = NULL;
    }
    b->mStart = v1;
    b->mSize = c;
    return a + func_ov000_021a8a54(c);
}

u8 *func_ov000_021a7154(u8 *b, Unk021a7154 *c, Unk021a72a4 *d) {
    u8 *a;

    a = b + func_ov000_021a72a4(d);
    OS_InitMessageQueue(&c->mUnk_00, (void **) b, d->mUnk_03);
    OS_InitMutex(&c->mUnk_e0);
    OS_CreateThread(&c->mUnk_20, func_ov000_021a6f18, c, a, d->mUnk_00, d->mUnk_02);
    OS_WakeupThreadDirect(&c->mUnk_20);
    return a;
}

s32 func_ov000_021a70ec(s32 e) {
    s32 a;
    void **b;
    Unk021a7064 *c;
    s32 d;

    a = (e * 4 + 3) & ~3;
    d = (e * 0x2c + 3) & ~3;
    b = data_ov000_021b5f94->mUnk_18(d + a);
    if (b == NULL) {
        return -1;
    }
    OS_InitMessageQueue(&data_ov000_021b5fdc, b, e);
    c = (Unk021a7064 *) ((u8 *) b + a);
    if (e > 0) {
        do {
            func_ov000_021a7048(c);
            c++;
            e--;
        } while (e > 0);
    }
    data_ov000_021b5fd8 = b;
    return 0;
}

s32 func_ov000_021a70b0(void) {
    if (data_ov000_021b5fdc.mCount < data_ov000_021b5fdc.mCapacity) {
        return -1;
    }
    data_ov000_021b5f94->mUnk_1c(data_ov000_021b5fd8);
    data_ov000_021b5fd8 = NULL;
    return 0;
}

Unk021a7064 *func_ov000_021a7088(s32 a) {
    int v1;
    Unk021a7064 *v2[1];
    v1 = OS_ReceiveMessage(&data_ov000_021b5fdc, (void **) (v2), (s32) (a));
    if (v1 != 0) {
        return v2[0];
    }
    return NULL;
}

Unk021a7064 *func_ov000_021a7064(Unk021a7064Func b, Unk021a6fa8 *c, s32 d) {
    Unk021a7064 *a;

    a = func_ov000_021a7088(d);
    if (a != NULL) {
        a->mUnk_00 = b;
        a->mUnk_04 = c;
        a->mUnk_0d = d;
        a->mUnk_0c = c->mUnk_73;
    }
    return a;
}

void func_ov000_021a7048(Unk021a7064 *a) {
    if (a != NULL) {
        OS_SendMessage(&data_ov000_021b5fdc, (a), 0);
    }
    return;
}

s32 func_ov000_021a7008(Unk021a7154 *b, Unk021a7064 *c) {
    s32 a;

    a = OS_SendMessage(&b->mUnk_00, c, c != NULL ? c->mUnk_0d : 1);
    if (a == 0) {
        func_ov000_021a7048(c);
    }
    if (a != 0) {
        return 0;
    }
    return -42;
}

s32 func_ov000_021a6fc0(Unk021a7154 *d, Unk021a7064 *e) {
    s32 a;
    void *b;
    OSMessageQueue c;

    if (e->mUnk_0d == 0) {
        e->mUnk_08 = NULL;
        a = func_ov000_021a7008(d, e);
    } else {
        OS_InitMessageQueue(&c, &b, 1);
        e->mUnk_08 = &c;
        func_ov000_021a7008(d, e);
        OS_ReceiveMessage(&c, (void **) &a, 1);
    }
    return a;
}

s32 func_ov000_021a6fb4(Unk021a6fa8 *a, Unk021a7064 *b) {
    return func_ov000_021a6fc0(a->mReceiveBlock, b);
}

s32 func_ov000_021a6fa8(Unk021a6fa8 *object, void *request) {
    return func_ov000_021a6fc0(object->mSendBlock, request);
}

s32 func_ov000_021a6f84(Unk021a6fa8 *param_1, Unk021a7064 *param_2) {
    if (param_1->mReceiveBlock != NULL) {
        return func_ov000_021a6fc0(param_1->mReceiveBlock, param_2);
    }
    return func_ov000_021a6fc0(param_1->mSendBlock, param_2);
}

void func_ov000_021a6f18(void *param_1) {
    OSMessageQueue *a = param_1;
    Unk021a7064 *b;
    s32 c;
    u32 d;

    while (1) {
        OS_ReadMessage(a, (void **) &b, 1);
        if (b == NULL) {
            return;
        }
        c = b->mUnk_00(b);
        d = OS_DisableInterrupts();
        OS_DisableScheduler();
        OS_ReceiveMessage(a, NULL, 0);
        if (b->mUnk_04 != NULL) {
            b->mUnk_04->mEntryResult = c;
        }
        if (b->mUnk_08 != NULL) {
            OS_SendMessage(b->mUnk_08, (void *) c, 0);
        }
        func_ov000_021a7048(b);
        OS_EnableScheduler();
        OS_RestoreInterrupts(d);
        OSi_RescheduleThread();
    }
}

s32 func_ov000_021a6ee4(Unk021b5f94 *param_1) {
    func_02000b44(0x2000bbc);
    if (data_ov000_021b5f94 != NULL) {
        return 0;
    }
    data_ov000_021b5f94 = param_1;
    func_ov000_021a6db0();
    return func_ov000_021a6eb4();
}

s32 func_ov000_021a6eb4(void) {
    s32 a;

    a = func_ov000_021a70ec(data_ov000_021b5f94->mUnk_20);
    if (a >= 0) {
        data_ov000_021b5fa4 = (Unk021a6fa8 *) func_ov000_021a73d8(&data_ov000_021b49d0);
    }
    return a;
}

void func_ov000_021a6db0(void) {
    Unk021b5fa8 *a = &data_ov000_021b5fa8;
    Unk021b5f94 *b = data_ov000_021b5f94;
    s32 c;
    s32 d;

    MI_CpuFill8(a, 0, 0x30);
    a->mUnk_04 = b->mUnk_18;
    a->mUnk_08 = b->mUnk_1c;
    a->mUnk_10 = func_ov000_021a6d40;
    a->mUnk_14 = 0;
    a->mUnk_18 = 0;
    a->mUnk_2c = *(u32 *) data_ov000_021b5f98;
    if (b->mUnk_24 != 0) {
        a->mUnk_20 = b->mUnk_24;
    } else {
        a->mUnk_20 = 0x4000;
    }
    if (b->mUnk_28 != NULL) {
        a->mUnk_1c = b->mUnk_28;
    } else {
        a->mUnk_1c = data_ov000_021b5f94->mUnk_18(a->mUnk_20);
    }
    c = b->mUnk_30;
    if (c == 0) {
        c = 0x240;
    }
    d = b->mUnk_34;
    if (d == 0) {
        d = 0x10c0;
    }
    a->mUnk_24 = c - 0x28;
    data_ov000_021b49b8.mUnk_02 = d;
    data_ov000_021b49b8.mUnk_04 = d / 2;
    data_ov000_021b63b4 = 0;
    if (b->mUnk_00 != 0) {
        data_ov000_021b5fa0 = 1;
        a->mUnk_00 = 0;
        a->mUnk_0c = func_ov000_021a6d5c;
        a->mUnk_28 = data_ov000_021b5f9c;
    } else {
        data_ov000_021b5fa0 = 0;
        a->mUnk_00 = 1;
        a->mUnk_0c = func_ov000_021a6d6c;
    }
    c = b->mUnk_2c;
    if (c == 0) {
        c = 0xb;
    }
    func_ov000_021b0240(c);
    func_ov000_021a6aa0(func_ov000_021afe5c);
    func_ov000_021b02b0(func_ov000_021a8424);
    func_ov000_021b02fc(a);
}

void func_ov000_021a6d6c(void) {
    Unk021b5f94 *a = data_ov000_021b5f94;

    data_ov000_021b63b4 = a->mUnk_04;
    data_ov000_021b6380 = a->mUnk_08;
    data_ov000_021b639c = a->mUnk_0c;
    data_ov000_021b63d8[0] = a->mUnk_10;
    data_ov000_021b63d8[1] = a->mUnk_14;
    data_ov000_021b5fa0 |= 2;
}

void func_ov000_021a6d5c(void) {
    data_ov000_021b5fa0 |= 2;
}
