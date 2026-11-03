#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02077f5c.h"
#include "Main/Unknown/code_02087228.h"
#include "code_0200eddc.h"
#include "code_0214a748.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061f7c.h"
#include "Main/Unknown/code_02077000.h"
#include "Main/Unknown/code_02079bcc.h"
#include "Main/Unknown/code_02086e8c.h"
#include "Main/Unknown/code_020871a4.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_021759c0.h"

void func_0208784c(s32 a, s32 b) {
    u16 x;
    u16 y;
    u16 c;
    x = (b << 8) >> 16;
    y = (a << 8) >> 16;
    *(u32 *) 0x4000488 = 0x60006;
    c = data_021659d4[2];
    *(u32 *) 0x400048c = data_021659d4[0] | data_021659d4[1] << 16;
    *(u32 *) 0x400048c = c;
    *(u32 *) 0x4000488 = x << 16 | 6;
    c = data_021659d4[5];
    *(u32 *) 0x400048c = data_021659d4[3] | data_021659d4[4] << 16;
    *(u32 *) 0x400048c = c;
    *(u32 *) 0x4000488 = y | x << 16;
    c = data_021659d4[8];
    *(u32 *) 0x400048c = data_021659d4[6] | data_021659d4[7] << 16;
    *(u32 *) 0x400048c = c;
    *(u32 *) 0x4000488 = y | 0x60000;
    c = data_021659d4[11];
    *(u32 *) 0x400048c = data_021659d4[9] | data_021659d4[10] << 16;
    *(u32 *) 0x400048c = c;
}

#pragma thumb on

void func_020875b4(void) {
    void *v1;
    BOOL f;
    u16 i;
    s32 j;
    BOOL t;
    BOOL u;
    u32 v;
    Unk02086250 *q;
    s32 w;
    BOOL k;
    v1 = func_020364e0(func_020364e8());
    if (data_021759c0->mUnk_08 == 0) {
        f = TRUE;
    } else {
        f = FALSE;
    }
    data_0217aed0 = func_02036bec(v1, 0x194);
    data_0217aed0->mUnk_184 = 0;
    data_0217aed0->mUnk_188 = NULL;
    if (func_02062eb0() != 0) {
        data_0217aed0->mUnk_020 = 0;
    } else if (f == FALSE) {
        data_0217aed0->mUnk_020 = data_021759c0->mUnk_3d0 - 1;
        for (i = 0; (u32) i < data_021759c0->mUnk_3d0; i++) {
            if (data_021759c0->mUnk_68[i].mUnk_08.mUnk_00 == 2 && data_021759c0->mUnk_68[i].mUnk_08.mUnk_10 == 0) {
                data_0217aed0->mUnk_020 = data_0217aed0->mUnk_020 - 1;
            }
        }
    } else {
        data_0217aed0->mUnk_020 = data_021759c0->mUnk_3d1;
        w = data_021759c0->mUnk_62;
        u = FALSE;
        if (w != -1) {
            v = data_021759c0->mUnk_68[(u16) w].mUnk_08.mUnk_00;
            if (v <= 3 && ((1 << v) & 0xd) != 0) {
                u = TRUE;
            }
            if (u != FALSE) {
                data_0217aed0->mUnk_020 = data_0217aed0->mUnk_020 - 1;
            }
        }
    }
    data_0217aed8 = &data_02155a48;
    func_02087000();
    for (i = 0; (u32) i < data_021759c0->mUnk_3d0; i++) {
        data_0217aed0->mUnk_024[i] = i;
        data_0217aed0->mUnk_044[i] = i;
        data_0217aed0->mUnk_094[i] = i;
        data_0217aed0->mUnk_034[i] = 0;
        data_0217aed0->mUnk_084[i] = 0;
        data_0217aed0->mUnk_054[i] = 0;
        data_0217aed0->mUnk_0a4[i] = 0;
        data_0217aed0->mUnk_074[i] = i;
        data_0217aed0->mUnk_094[i] = i;
        data_0217aed0->mUnk_104[i] = 0;
        data_0217aed0->mUnk_000[i] = NULL;
        data_0217aed0->mUnk_0e4[i] = 0;
    }
    if (data_0217aed0->mUnk_020 > 0) {
        j = 0;
        for (i = 0; (u32) i < data_021759c0->mUnk_3d0; i++) {
            t = FALSE;
            if (f == FALSE) {
                if (i != data_021759c0->mUnk_62) {
                    if (data_021759c0->mUnk_68[i].mUnk_08.mUnk_00 != 2 ||
                        data_021759c0->mUnk_68[i].mUnk_08.mUnk_10 != 0) {
                        t = TRUE;
                    }
                }
            } else {
                k = FALSE;
                v = data_021759c0->mUnk_68[i].mUnk_08.mUnk_00;
                if (v <= 3 && ((1 << v) & 0xd) != 0) {
                    k = TRUE;
                }
                if (k != FALSE && i != data_021759c0->mUnk_62) {
                    t = TRUE;
                }
            }
            if (t != FALSE) {
                data_0217aed0->mUnk_000[i] = func_02036bec(v1, 0x28);
                q = data_0217aed0->mUnk_000[i];
                func_02087508(q, i, v1);
                data_0217aed0->mUnk_0c4[j] = q;
                j++;
            } else {
                data_0217aed0->mUnk_000[i] = NULL;
            }
        }
    }
    *(u32 *) 0x4000440 = 0;
    func_0214ad4c(0x60000, 0xfffa0000, 0xfff80000, 0x80000, 0, 0x1000, 0x200, 1, &data_0217aee0);
}

void func_02087508(Unk02086250 *a, u16 b, void *c) {
    a->mUnk_1c = func_02036bec(c, 0x90);
    a->mUnk_00 = data_02155ccc;
    a->mUnk_0c = b;
    a->mUnk_1c->mUnk_00[0] = data_021659ec;
    a->mUnk_1c->mUnk_00[1] = data_02165a34;
    a->mUnk_1c->mUnk_00[2] = data_02165a10;
    a->mUnk_1c->mUnk_00[3] = data_02165a58;
    a->mUnk_10 = 1;
    a->mUnk_14 = 0;
    a->mUnk_18 = 1;
    a->mUnk_24 = 0;
    a->mUnk_26 = 0x7fff;
    a->mUnk_22 = 0;
    a->mUnk_20 = 0;
}

void func_02087458(Unk02086098 *a) {
    u16 v;
    u16 w;
    s32 x;
    s32 y;
    v = a->mUnk_00 >> 23 & 7;
    w = a->mUnk_00 >> 20 & 7;
    switch (w) {
        case 0:
            x = 8;
            break;
        case 1:
            x = 0x11;
            break;
        case 2:
            x = 0x21;
            break;
        case 3:
            x = 0x41;
            break;
        case 4:
            x = 0x80;
            break;
        case 5:
            x = 0x100;
            break;
        case 6:
            x = 0x200;
            break;
        case 7:
            x = 0x400;
            break;
    }
    switch (v) {
        case 0:
            y = 8;
            break;
        case 1:
            y = 0x11;
            break;
        case 2:
            y = 0x21;
            break;
        case 3:
            y = 0x41;
            break;
        case 4:
            y = 0x80;
            break;
        case 5:
            y = 0x100;
            break;
        case 6:
            y = 0x200;
            break;
        case 7:
            y = 0x400;
            break;
    }
    a->mUnk_1c = x << 12;
    a->mUnk_20 = y << 12;
}

u16 func_020873e4(int a) {
    if (data_021759c0->mUnk_08 == 5) {
        return data_02155a2c[data_021759c0->mUnk_68[a].mUnk_08.mUnk_25];
    }
    if (data_021759c0->mUnk_58 != 0) {
        return data_02155a28[data_021759c0->mUnk_68[a].mUnk_08.mUnk_04];
    }
    if (func_02079bf0(a)->mUnk_000 == 0xc) {
        return func_02077f7c(a)->mUnk_04;
    }
    return data_02155a64[a];
}

void func_020872a4(void) {
    u16 i;
    void *v1;
    Unk02086250 *p;
    Unk02086250_1c *q;
    Unk02086098 *e1;
    Unk02086098 *e3;
    v1 = func_020364e0(func_020364e8());
    func_02086fac();
    data_0217aedc = 0;
    data_0217aed4 = func_02036b74(v1, 0x20, -4);
    data_0217aec4 = func_02036b74(v1, 0x100, -4);
    data_0217aec8 = func_02036b74(v1, 8, -4);
    data_0217aecc = func_02036b74(v1, 0x200, -4);
    for (i = 0; i < data_0217aed0->mUnk_020; i++) {
        p = data_0217aed0->mUnk_0c4[i];
        q = p->mUnk_1c;
        e1 = &q->mUnk_00[1];
        e3 = &q->mUnk_00[3];
        q->mUnk_00[0].mUnk_04 = 0x200;
        q->mUnk_00[0].mUnk_08 = 0x20;
        q->mUnk_00[0].mUnk_10 = data_0217aed0->mUnk_188;
        p->mUnk_26 = func_020873e4(p->mUnk_0c);
        func_02087228(&q->mUnk_00[0], p->mUnk_0c);
        func_020871c0(e1, p->mUnk_0c);
        func_020871a4(&q->mUnk_00[2], p->mUnk_0c);
        func_020870ec(e3, p->mUnk_0c);
        func_02086e8c(&q->mUnk_00[0]);
        func_02086e8c(e1);
        func_02086e8c(&p->mUnk_1c->mUnk_00[2]);
        if (e3->mUnk_0c != NULL) {
            func_02086e8c(e3);
        }
    }
    func_02036b30(v1, data_0217aecc);
    func_02036b30(v1, data_0217aec8);
    func_02036b30(v1, data_0217aec4);
    func_02036b30(v1, data_0217aed4);
}

void func_02087228(Unk02086098 *a, u16 b) {
    u16 *p;
    void *q;
    u16 v;
    p = data_0217aed4;
    q = data_0217aed0->mUnk_144[b];
    func_0214d1fc(data_0217aed0->mUnk_164[b], p, a->mUnk_08);
    v = 0x7fff;
    if (data_021759c0->mUnk_58 != 0) {
        v = data_02155a28[data_021759c0->mUnk_68[b].mUnk_08.mUnk_04];
    }
    *p = v;
    func_0200ee74(p, a->mUnk_08);
    func_0200ee74(q, a->mUnk_04);
    a->mUnk_10 = p;
    a->mUnk_0c = q;
}

#pragma thumb off
