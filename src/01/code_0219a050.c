#include "01/code_0219a050.h"

#include "01/unk_021a6000.h"
#include "Main/Unknown/unk_02175628.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_02128210.h"
#include "01/code_0219c000.h"
#include "code_0201ea58.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_02111450.h"
#include "Main/Unknown/code_02114000.h"
#include "00/code_02182fdc.h"
#include "Main/Unknown/code_02111488.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_02124000.h"
#include "01/code_0219a000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02125f88.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_021262f0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "01/code_0219b540.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_0212b000.h"
#include "Main/Unknown/code_020472a8.h"

void func_ov001_0219b000(void) {
    Unk020b4934 *a;
    Unk020b4a44 *b;
    Unk020b4934 *c;
    Unk020b4a44 *d;
    Unk020b4934 *e;
    Unk020b4a44 *f;
    Unk020b47d8 *g;
    u16 *q;

    a = 0;
    b = 0;
    c = 0;
    d = 0;
    e = 0;
    f = 0;
    g = 0;
    func_020b4934(&e, func_0204799c(data_0216cd24));
    func_020b4a44(&f, func_0204799c(data_0216cce8));
    func_020b47d8(&g, func_0204799c(data_0216cd10));
    data_ov001_021a9bf0->mUnk_28 = func_02036bec(data_ov001_021a9bf0->mUnk_2c, 0x800);
    data_ov001_021a9bf0->mUnk_04 = func_0204799c(data_0216ccdc);
    data_ov001_021a9bf0->mUnk_08 = func_0204799c(data_0216cd08);
    func_020b49bc(&a, func_0204799c(data_0216cce0));
    func_020b48b4(&data_ov001_021a9bf0->mUnk_00, func_0204799c(data_0216cd30));
    func_020b4a44(&b, func_0204799c(data_0216ccf4));
    data_ov001_021a9bf0->mUnk_10 = func_0204799c(data_0216cc88);
    data_ov001_021a9bf0->mUnk_14 = func_0204799c(data_0216cca0);
    func_020b49bc(&c, func_0204799c(data_0216ccb4));
    func_020b48b4(&data_ov001_021a9bf0->mUnk_0c, func_0204799c(data_0216ccac));
    func_020b4a44(&d, func_0204799c(data_0216ccf0));
    q = b->mUnk_0c;
    func_02016468(4, 0, e->mUnk_14, e->mUnk_10);
    func_02016468(15, 0, f->mUnk_0c, 0x60);
    func_02016468(8, 0, g->mUnk_0c, g->mUnk_08);
    func_02016468(8, 0x800, data_ov001_021a9bf0->mUnk_28, 0x800);
    func_02016468(0x13, 0, a->mUnk_14, a->mUnk_10);
    func_02016468(14, 0, b->mUnk_0c, 0x1a0);
    func_02016468(14, 0x1c0, q + 0xe0, 0x40);
    func_02016468(0x23, 0, c->mUnk_14, c->mUnk_10);
    func_02016468(0x1e, 0, d->mUnk_0c, d->mUnk_08);
}

void func_ov001_0219afc8(s32 a) {
    data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6a9c[a]].mUnk_00 = 1;
    func_02124a20(data_ov001_021a6aa4[a], 14, data_ov001_021a9bf0->mUnk_0c, data_ov001_021a9bf0->mUnk_10);
}

void func_ov001_0219af90(s32 a) {
    data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6a9c[a]].mUnk_00 = 0;
    func_02124a20(data_ov001_021a6aa4[a], 15, data_ov001_021a9bf0->mUnk_0c, data_ov001_021a9bf0->mUnk_10);
}

void func_ov001_0219ae88(void) {
    s32 i;
    s32 j;
    u16 *p;
    s32 n;

    data_ov001_021a9bf0->mUnk_34 = 0;
    data_ov001_021a9bf0->mUnk_38 = 0;
    data_ov001_021a9bf0->mUnk_3c = ~0xbf;
    n = data_ov001_021a9bf0->mUnk_04->mUnk_06;
    data_ov001_021a9bf0->mUnk_18[0].mUnk_06 = ~0xbf;
    data_ov001_021a9bf0->mUnk_18[1].mUnk_06 = ~0xbf;
    data_ov001_021a9bf0->mUnk_18[n].mUnk_06 = ~0xbf;
    for (i = 0; i < 3; i++) {
        data_ov001_021a9bf0->mUnk_18[data_ov001_021a6aac[i]].mUnk_06 = ~0xbf;
    }
    for (i = 0; i < 3; i++) {
        for (j = 0, p = data_ov001_021a6ae4[i]; j < 3; j++) {
            data_ov001_021a9bf0->mUnk_18[n + *p].mUnk_06 = ~0xbf;
            p++;
        }
    }
    for (i = 0; i < 3; i++) {
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6ab4[i]].mUnk_04 = 0xe0;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6ac4[i]].mUnk_04 = 0xe0;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6a9c[i]].mUnk_04 = 0xe0;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6aa4[i]].mUnk_04 = 0xe0;
        func_ov001_0219af90(i);
    }
}

void func_ov001_0219ae74(void) {
    data_ov001_021a9bf0->mUnk_34 = 1;
    data_ov001_021a9bf0->mUnk_38 = 0;
}

void func_ov001_0219ae60(void) {
    data_ov001_021a9bf0->mUnk_34 = 2;
    data_ov001_021a9bf0->mUnk_38 = 0;
}

void func_ov001_0219ae44(void) {
    data_ov001_021a9bf0->mUnk_34 = 3;
    data_ov001_021a9bf0->mUnk_38 = 0;
    func_02128374();
}

void func_ov001_0219ae30(void) {
    data_ov001_021a9bf0->mUnk_34 = 4;
    data_ov001_021a9bf0->mUnk_38 = 0;
}

void func_ov001_0219ae10(void) {
    data_ov001_021a9bf0->mUnk_34 = 5;
    data_ov001_021a9bf0->mUnk_38 = 0;
    func_0212ecc0(&data_0217d068, 0, 5);
}

void func_ov001_0219adfc(void) {
    data_ov001_021a9bf0->mUnk_34 = 6;
    data_ov001_021a9bf0->mUnk_38 = 0;
}

void func_ov001_0219ade8(void) {
    data_ov001_021a9bf0->mUnk_34 = 7;
    data_ov001_021a9bf0->mUnk_38 = 0;
}

void func_ov001_0219adbc(void) {
    data_ov001_021a9bf0->mUnk_34 = 8;
    data_ov001_021a9bf0->mUnk_38 = 0;
    func_021262f0(func_020b3f7c(data_ov001_021a9bf0->mUnk_20, 0x76));
}

void func_ov001_0219ad98(void) {
    data_ov001_021a9bf0->mUnk_34 = 9;
    data_ov001_021a9bf0->mUnk_38 = 0;
    func_0212ecc0(&data_0217d068, 0, 0x15);
}

void func_ov001_0219ad7c(void) {
    data_ov001_021a9bf0->mUnk_34 = 10;
    data_ov001_021a9bf0->mUnk_38 = 0;
    func_02125fc0();
}

void func_ov001_0219ad68(void) {
    data_ov001_021a9bf0->mUnk_34 = 11;
    data_ov001_021a9bf0->mUnk_38 = 0;
}

void func_ov001_0219ad3c(void) {
    data_ov001_021a9bf0->mUnk_40++;
    if (data_ov001_021a9bf0->mUnk_40 >= 3) {
        data_ov001_021a9bf0->mUnk_40 = 0;
    }
    func_0212ecc0(&data_0217d068, 0, 0);
}

void func_ov001_0219ad10(void) {
    data_ov001_021a9bf0->mUnk_40--;
    if (data_ov001_021a9bf0->mUnk_40 < 0) {
        data_ov001_021a9bf0->mUnk_40 = 2;
    }
    func_0212ecc0(&data_0217d068, 0, 0);
}

void func_ov001_0219ac98(void) {
    s32 best = 7;
    s32 i;
    s32 j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
            if (func_02060440(i, j)) {
                s32 v = func_02060364(i, j);
                if (best > v) {
                    best = v;
                }
            } else {
                best = 0;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        data_ov001_021a9bf0->mUnk_18[data_ov001_021a6aac[i]].mUnk_00 = 0;
    }
    if (best > 4) {
        data_ov001_021a9bf0->mUnk_18[data_ov001_021a6aac[best - 5]].mUnk_00 = 1;
    }
}

void func_ov001_0219a9a0(void *heap) {
    u32 scores[3][3] = {0};
    u16 buf[16];
    s32 rem;
    u16 x;
    u16 base;
    s32 i;
    s32 j;
    Unk0217aa08_00 **pp;

    *(vu16 *) 0x4000008 = (*(vu16 *) 0x4000008 & ~3) | 1;
    *(vu16 *) 0x4000008 = (*(vu16 *) 0x4000008 & 0x43) | 0x8800;
    *(vu16 *) 0x400100a = (*(vu16 *) 0x400100a & 0x43) | 0x1018;
    data_ov001_021a9bf0 = func_02036bec(heap, 0x48);
    data_ov001_021a9bf0->mUnk_2c = heap;
    data_ov001_021a9bf0->mUnk_30 = 0;
    switch (func_0211147c()) {
        case 1:
        case 5:
            data_ov001_021a9bf0->mUnk_40 = 0;
            break;
        case 2:
            data_ov001_021a9bf0->mUnk_40 = 1;
            break;
        case 3:
            if (func_021143b4()) {
                data_ov001_021a9bf0->mUnk_40 = 2;
            } else {
                data_ov001_021a9bf0->mUnk_40 = 0;
            }
            break;
    }
    func_ov001_0219b000();
    for (i = 0; i < 3; i++) {
        func_02124a98(data_ov001_021a6ac4[i], 1, data_ov001_021a9bf0->mUnk_0c, data_ov001_021a9bf0->mUnk_10);
    }
    func_020ae6d4(func_02111318(), func_0211130c());
    func_02124ed0(heap, data_ov001_021a9bf0->mUnk_04, data_ov001_021a9bf0->mUnk_08, &data_ov001_021a9bf0->mUnk_18);
    func_02124ed0(heap, data_ov001_021a9bf0->mUnk_10, 0, &data_ov001_021a9bf0->mUnk_1c);
    data_ov001_021a9bf0->mUnk_20 = func_02047a28("common.bmg");
    data_ov001_021a9bf0->mUnk_24 = func_0204799c("record.bmg");
    rem = 0x8000;
    rem -= func_021243ac(heap, 0, data_ov001_021a9bf0->mUnk_08, 0xaa, 0xe, 0, data_ov001_021a9bf0->mUnk_00,
                         data_ov001_021a9bf0->mUnk_04, data_ov001_021a9bf0->mUnk_18, rem);
    func_0212426c(0, 0, data_ov001_021a9bf0->mUnk_08, func_020b3f7c(data_ov001_021a9bf0->mUnk_24, 9),
                  data_ov001_021a9bf0->mUnk_04, data_ov001_021a9bf0->mUnk_18);
    x = 1;
    base = data_ov001_021a9bf0->mUnk_04->mUnk_06;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            rem -= func_021243ac(heap, data_ov001_021a6ae4[i][j], data_ov001_021a9bf0->mUnk_08,
                                 data_ov001_021a6af8[i][j], data_ov001_021a6b0c[i][j], x, data_ov001_021a9bf0->mUnk_00,
                                 data_ov001_021a9bf0->mUnk_04, data_ov001_021a9bf0->mUnk_18, rem);
            x = base + data_ov001_021a6ae4[i][j];
        }
    }
    for (i = 0; i < 3; i++) {
        func_0212426c(0, data_ov001_021a6ae4[0][i], data_ov001_021a9bf0->mUnk_08,
                      func_020b3f7c(data_ov001_021a9bf0->mUnk_24, data_ov001_021a6abc[i]), data_ov001_021a9bf0->mUnk_04,
                      data_ov001_021a9bf0->mUnk_18);
    }
    pp = &data_0217aa08->mUnk_00;
    scores[1][0] = (*pp)->mUnk_34;
    scores[2][0] = (*pp)->mUnk_38;
    scores[1][1] = (*pp)->mUnk_3c;
    scores[2][1] = (*pp)->mUnk_40;
    scores[1][2] = (*pp)->mUnk_44;
    scores[2][2] = (*pp)->mUnk_48;
    for (i = 1; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (scores[i][j] > 9999) {
                scores[i][j] = 9999;
            }
            func_02124fac(scores[i][j], buf);
            func_02124248(0, data_ov001_021a6ae4[i][j], data_ov001_021a9bf0->mUnk_08, buf, data_ov001_021a9bf0->mUnk_04,
                          data_ov001_021a9bf0->mUnk_18, 6);
        }
    }
    func_ov001_0219ac98();
    func_ov001_0219ae88();
    func_ov001_0219afc8(data_ov001_021a9bf0->mUnk_40);
}

void func_ov001_0219a950(void) {
    u32 a;
    u32 b;

    data_ov001_021a9bf0 = 0;
    a = (*(vu32 *) 0x4000000 & 0x1f00) >> 8;
    a &= ~0x11;
    *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffffe0ff) | (a << 8);
    b = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
    b &= ~0x1;
    *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | (b << 8);
}

void func_ov001_0219a938(void) {
    int v1;
    v1 = func_02036c5c();
    if (v1 != 0) {
        func_ov001_0219ae74();
    }
    return;
}

void func_ov001_0219a80c(void) {
    s16 a;
    s32 i;
    s32 j;
    s16 b;
    u16 *p;
    s32 idx;

    data_ov001_021a9bf0->mUnk_38++;
    a = func_020ae4c0(1, 0xe0, 0, data_ov001_021a9bf0->mUnk_38, 10);
    b = func_020ae4c0(1, -0xc0, 0, data_ov001_021a9bf0->mUnk_38, 10);
    data_ov001_021a9bf0->mUnk_3c = b;
    idx = data_ov001_021a9bf0->mUnk_04->mUnk_06;
    data_ov001_021a9bf0->mUnk_18[0].mUnk_06 = b;
    data_ov001_021a9bf0->mUnk_18[1].mUnk_06 = b;
    data_ov001_021a9bf0->mUnk_18[idx].mUnk_06 = b;
    for (i = 0; i < 3; i++) {
        data_ov001_021a9bf0->mUnk_18[data_ov001_021a6aac[i]].mUnk_06 = b;
    }
    for (i = 0; i < 3; i++) {
        for (j = 0, p = data_ov001_021a6ae4[i]; j < 3; j++) {
            data_ov001_021a9bf0->mUnk_18[idx + *p].mUnk_06 = b;
            p++;
        }
    }
    for (i = 0; i < 3; i++) {
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6ab4[i]].mUnk_04 = a;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6ac4[i]].mUnk_04 = a;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6a9c[i]].mUnk_04 = a;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6aa4[i]].mUnk_04 = a;
    }
    if (data_ov001_021a9bf0->mUnk_38 >= 10) {
        func_ov001_0219ae60();
    }
}

void func_ov001_0219a77c(void) {
    s16 v;
    s32 i;

    data_ov001_021a9bf0->mUnk_38++;
    v = func_020ae488(data_ov001_021a9bf0->mUnk_38);
    for (i = 0; i < 3; i++) {
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6ab4[i]].mUnk_04 = v;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6ac4[i]].mUnk_04 = v;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6a9c[i]].mUnk_04 = v;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6aa4[i]].mUnk_04 = v;
    }
    if (data_ov001_021a9bf0->mUnk_38 >= 10) {
        func_ov001_0219ae44();
    }
}

void func_ov001_0219a764(void) {
    int v1;
    v1 = func_02128294();
    if (v1 != 0) {
        func_ov001_0219ae30();
    }
    return;
}

void func_ov001_0219a5bc(void) {
    Unk02175628Index i;
    u16 flags;
    s32 b;
    s32 sel;
    s32 a;
    s32 b2;
    s32 a2;
    s32 t;

    b = 0;
    sel = -1;
    i = UNK_02175628_INDEX_8;
    a = 0;
    if (data_02175628[i].mUnk_4c == 0 && data_02175628[i].mUnk_58 < 5) {
        a = 1;
    }
    if (a == 0 && data_02175628[i].mUnk_54 == 0 && data_02175628[i].mUnk_4c != 0) {
        b = 1;
    }
    if (b != 0) {
        sel = func_0201ea84(data_ov001_021a9bf0->mUnk_14, data_02175628[i].mUnk_48, data_02175628[i].mUnk_4a);
    }
    flags = data_02175628[i].mUnk_00 & 2;
    if (flags == 0) {
        b2 = 0;
        a2 = 0;
        if (data_02175628[i].mUnk_4c == 0 && data_02175628[i].mUnk_58 < 5) {
            a2 = 1;
        }
        if (a2 == 0 && data_02175628[i].mUnk_54 == 0 && data_02175628[i].mUnk_4c != 0) {
            b2 = 1;
        }
        if (b2 == 0 || func_02128210(data_02175628[i].mUnk_48, data_02175628[i].mUnk_4a) == 0) {
            goto skip;
        }
    }
    func_021281c8(15);
    func_ov001_0219adfc();
    data_ov001_021a9bf0->mUnk_44 = 5;
    func_02128310(1);
    return;
skip:
    if ((u32) sel <= 2) {
        t = data_ov001_021a6acc[sel];
        if (data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6aa4[t]].mUnk_00 != 0) {
            if (data_ov001_021a9bf0->mUnk_40 == t) {
                func_ov001_0219af90(data_ov001_021a9bf0->mUnk_40);
                data_ov001_021a9bf0->mUnk_40 = t;
            } else {
                func_ov001_0219af90(data_ov001_021a9bf0->mUnk_40);
                data_ov001_021a9bf0->mUnk_40 = t;
                func_ov001_0219afc8(data_ov001_021a9bf0->mUnk_40);
            }
            func_ov001_0219ae10();
        }
    } else {
        flags = data_02175628[i].mUnk_00 & 1;
        if (flags != 0) {
            func_ov001_0219af90(data_ov001_021a9bf0->mUnk_40);
            func_ov001_0219ae10();
        } else if (func_020ae408(8, 0x40) != 0) {
            func_ov001_0219af90(data_ov001_021a9bf0->mUnk_40);
            func_ov001_0219ad10();
            func_ov001_0219afc8(data_ov001_021a9bf0->mUnk_40);
        } else if (func_020ae408(8, 0x80) != 0) {
            func_ov001_0219af90(data_ov001_021a9bf0->mUnk_40);
            func_ov001_0219ad3c();
            func_ov001_0219afc8(data_ov001_021a9bf0->mUnk_40);
        }
    }
}

void func_ov001_0219a4fc(void) {
    s16 v;

    data_ov001_021a9bf0->mUnk_38++;
    v = func_020ae488(data_ov001_021a9bf0->mUnk_38);
    data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6ab4[data_ov001_021a9bf0->mUnk_40]].mUnk_04 = v;
    data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6ac4[data_ov001_021a9bf0->mUnk_40]].mUnk_04 = v;
    data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6a9c[data_ov001_021a9bf0->mUnk_40]].mUnk_04 = v;
    data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6aa4[data_ov001_021a9bf0->mUnk_40]].mUnk_04 = v;
    if (data_ov001_021a9bf0->mUnk_38 == 5) {
        func_ov001_0219afc8(data_ov001_021a9bf0->mUnk_40);
    }
    if (data_ov001_021a9bf0->mUnk_38 >= 10) {
        if (data_ov001_021a9bf0->mUnk_40 == 2 && func_021143b4() == 0) {
            func_ov001_0219ade8();
            return;
        }
        data_ov001_021a9bf0->mUnk_44 = data_ov001_021a6ad8[data_ov001_021a9bf0->mUnk_40];
        func_ov001_0219adfc();
    }
}

void func_ov001_0219a3a0(void) {
    s16 a;
    s32 i;
    s32 j;
    s16 b;
    u16 *p;
    s32 idx;

    if (func_0211145c() == -1 && data_ov001_021a9bf0->mUnk_44 == 5) {
        func_02111450(0);
    }
    data_ov001_021a9bf0->mUnk_38++;
    a = func_020ae4c0(1, 0, 0xe0, data_ov001_021a9bf0->mUnk_38, 10);
    b = func_020ae4c0(1, 0, -0xc0, data_ov001_021a9bf0->mUnk_38, 10);
    data_ov001_021a9bf0->mUnk_3c = b;
    idx = data_ov001_021a9bf0->mUnk_04->mUnk_06;
    data_ov001_021a9bf0->mUnk_18[0].mUnk_06 = b;
    data_ov001_021a9bf0->mUnk_18[1].mUnk_06 = b;
    data_ov001_021a9bf0->mUnk_18[idx].mUnk_06 = b;
    for (i = 0; i < 3; i++) {
        data_ov001_021a9bf0->mUnk_18[data_ov001_021a6aac[i]].mUnk_06 = b;
    }
    for (i = 0; i < 3; i++) {
        for (j = 0, p = data_ov001_021a6ae4[i]; j < 3; j++) {
            data_ov001_021a9bf0->mUnk_18[idx + *p].mUnk_06 = b;
            p++;
        }
    }
    for (i = 0; i < 3; i++) {
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6ab4[i]].mUnk_04 = a;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6ac4[i]].mUnk_04 = a;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6a9c[i]].mUnk_04 = a;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6aa4[i]].mUnk_04 = a;
    }
    if (data_ov001_021a9bf0->mUnk_38 >= 10 && func_0211145c() == -1) {
        func_02111488(data_ov001_021a9bf0->mUnk_44);
    }
}

void func_ov001_0219a304(void) {
    s16 v;
    s32 i;

    data_ov001_021a9bf0->mUnk_38++;
    v = func_020ae4c0(1, 0, 0xe0, data_ov001_021a9bf0->mUnk_38, 10);
    for (i = 0; i < 3; i++) {
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6ab4[i]].mUnk_04 = v;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6ac4[i]].mUnk_04 = v;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6a9c[i]].mUnk_04 = v;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6aa4[i]].mUnk_04 = v;
    }
    if (data_ov001_021a9bf0->mUnk_38 >= 10) {
        func_ov001_0219adbc();
    }
}

void func_ov001_0219a2ec(void) {
    int v1;
    v1 = func_02125fa4();
    if (v1 != 0) {
        func_ov001_0219ad98();
    }
    return;
}

void func_ov001_0219a258(void) {
    Unk02175628Index i = UNK_02175628_INDEX_8;
    u16 flags;
    s32 b;
    s32 a;
    u16 v;

    func_0201ea84(data_ov001_021a9bf0->mUnk_14, data_02175628[i].mUnk_48, data_02175628[i].mUnk_4a);
    flags = data_02175628[i].mUnk_00 & 2;
    if (flags == 0) {
        b = 0;
        a = 0;
        v = data_02175628[i].mUnk_4c;
        if (v == 0 && data_02175628[i].mUnk_58 < 5) {
            a = 1;
        }
        if (a == 0 && data_02175628[i].mUnk_54 == 0 && v != 0) {
            b = 1;
        }
        if (b == 0 || func_02128210(data_02175628[i].mUnk_48, data_02175628[i].mUnk_4a) == 0) {
            return;
        }
    }
    func_ov001_0219ad7c();
    func_02128310(0);
}

void func_ov001_0219a240(void) {
    int v1;
    v1 = func_02125f88();
    if (v1 != 0) {
        func_ov001_0219ad68();
    }
    return;
}

void func_ov001_0219a1a4(void) {
    s32 i;
    s16 v;
    data_ov001_021a9bf0->mUnk_38++;
    v = func_020ae4c0(1, 0xe0, 0, data_ov001_021a9bf0->mUnk_38, 10);
    for (i = 0; i < 3; i++) {
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6ab4[i]].mUnk_04 = v;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6ac4[i]].mUnk_04 = v;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6a9c[i]].mUnk_04 = v;
        data_ov001_021a9bf0->mUnk_1c[data_ov001_021a6aa4[i]].mUnk_04 = v;
    }
    if (data_ov001_021a9bf0->mUnk_38 >= 10) {
        func_ov001_0219ae44();
    }
}

void func_ov001_0219a0e8(void) {
    Unk021a9bf0 *p;
    data_ov001_021a9bf0->mUnk_30 = data_ov001_021a9bf0->mUnk_34;
    switch (data_ov001_021a9bf0->mUnk_30) {
        case 0:
            func_ov001_0219a938();
            break;
        case 1:
            func_ov001_0219a80c();
            break;
        case 2:
            func_ov001_0219a77c();
            break;
        case 3:
            func_ov001_0219a764();
            break;
        case 4:
            func_ov001_0219a5bc();
            break;
        case 5:
            func_ov001_0219a4fc();
            break;
        case 6:
            func_ov001_0219a3a0();
            break;
        case 7:
            func_ov001_0219a304();
            break;
        case 8:
            func_ov001_0219a2ec();
            break;
        case 9:
            func_ov001_0219a258();
            break;
        case 10:
            func_ov001_0219a240();
            break;
        case 11:
            func_ov001_0219a1a4();
            break;
    }
    p = data_ov001_021a9bf0;
    func_02124c30(p->mUnk_04, p->mUnk_00, p->mUnk_08, func_02111318(), p->mUnk_18);
    p = data_ov001_021a9bf0;
    func_02124c30(p->mUnk_10, p->mUnk_0c, 0, func_0211130c(), p->mUnk_1c);
}

void func_ov001_0219a0c0(void) {
    *(vu32 *) 0x4000010 = (-data_ov001_021a9bf0->mUnk_3c << 16) & 0x1ff0000;
    func_02111428();
}

void func_ov001_0219a078(void) {
    u32 a;
    u32 b;
    a = (*(vu32 *) 0x4000000 & 0x1f00) >> 8;
    *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffffe0ff) | ((a | 0x11) << 8);
    b = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
    *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | ((b | 0x1) << 8);
}

void func_ov001_0219a050(void) {
    UnkFunc *tbl[5] = {func_ov001_0219a9a0, func_ov001_0219a950, func_ov001_0219a0e8, func_ov001_0219a0c0,
                       func_ov001_0219a078};
    func_02111494(tbl);
}
