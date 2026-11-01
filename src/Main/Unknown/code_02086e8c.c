#include "Main/Unknown/code_02086e8c.h"
#include "code_02013740.h"
#include "code_02012b30.h"
#include "code_0214c1bc.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_020478bc.h"
#include "Main/Unknown/code_02079bcc.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_02088338.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_021759c0.h"

#pragma thumb on

void func_020870ec(void *a, u16 b) {
    u8 *p;
    s32 c;
    u32 i;
    Unk02086098 *q;
    u8 v;
    u32 w;
    u8 x;
    u8 y;
    q = a;
    if (data_021759c0->mUnk_68[b].mUnk_08.mUnk_26 != 0) {
        p = data_0217aecc;
        c = 7;
        switch (data_021759c0->mUnk_68[b].mUnk_08.mUnk_26) {
            case 2:
                c = 4;
                break;
            case 3:
                c = -1;
                break;
        }
        func_0214d1fc(q->mUnk_0c, p, q->mUnk_04);
        if (c > 0) {
            for (i = 0; i < q->mUnk_04; i++) {
                v = p[i];
                w = v & 0xf0;
                x = w >> 4;
                y = v & 0xf;
                if (y < c) {
                    v = w;
                }
                if (x < c) {
                    v = v & 0xf;
                }
                p[i] = v;
            }
        }
        func_0200ee74(p, q->mUnk_04);
        q->mUnk_0c = p;
    } else {
        q->mUnk_0c = 0;
    }
}

void func_02087000(void) {
    u16 i;
    Unk020b4a44 *o;
    u8 *p;
    char *s;
    u8 *q;
    u8 *r;
    for (i = 0; (u32) i < data_021759c0->mUnk_3d0; i++) {
        data_0217aed0->mUnk_144[i] = 0;
        data_0217aed0->mUnk_164[i] = 0;
        if (data_021759c0->mUnk_68[i].mUnk_08.mUnk_24 == 0 || data_021759c0->mUnk_58 != 0) {
            if (data_021759c0->mUnk_58 != 0) {
                s = func_02088338(data_021759c0->mUnk_68[i].mUnk_08.mUnk_04 == 1 ? 1 : 0);
            } else {
                s = func_02088390((u16) data_021759c0->mUnk_68[i].mUnk_00);
            }
            p = func_020136f0(func_02047950(s));
            q = p + *(u32 *) (p + 0x38);
            r = p + *(u32 *) (p + 0x14);
            data_0217aed0->mUnk_144[i] = r;
            data_0217aed0->mUnk_164[i] = q;
        } else {
            r = (void *) data_021759c0->mUnk_68[i].mUnk_08.mUnk_1c;
            func_020b4a7c(&o, func_02047950(data_02165a7c));
            q = (u8 *) o->mUnk_0c;
            data_0217aed0->mUnk_144[i] = r;
            data_0217aed0->mUnk_164[i] = q;
        }
    }
}

void func_02086fac(void) {
    u16 i;
    for (i = 0; (u32) i < data_021759c0->mUnk_3d0; i++) {
        func_02086f24(i, data_0217aed0->mUnk_144[i], data_0217aed0->mUnk_164[i]);
    }
}

void func_02086f24(u32 a, void *b, void *c) {
    u8 *p;
    u8 *q;
    u8 *r;
    u8 *e;
    s32 n;
    s32 h;
    u32 d;
    u32 f;
    p = func_02079bcc((u16) a);
    n = func_02013754(p + *(u32 *) (p + 8) + 4, &data_02155a54);
    q = p + *(u32 *) (p + 8);
    r = q + 4;
    h = *(u16 *) (r + *(u16 *) (q + 0xa));
    e = q + *(u32 *) (r + *(u16 *) (q + 0xa) + h * n + 4);
    d = (*(u32 *) (e + 0x14) & 0xffff) << 3;
    f = *(u16 *) (e + 0x1c) << 4;
    func_0200ee74(b, 0x200);
    func_0200ee74(c, 0x20);
    func_0214c6a8();
    func_0214c544(b, d, 0x200);
    func_0214c4d4();
    func_0214c48c();
    func_0214c418(c, f, 0x20);
    func_0214c3c0();
}

void func_02086e8c(Unk02086098 *a) {
    u16 v;
    u32 d;
    v = a->mUnk_00 >> 26 & 7;
    d = (data_021619ec(a->mUnk_04, 0, 0) & 0xffff) << 3;
    a->mUnk_00 = a->mUnk_00 & 0xffff0000;
    func_0214c6a8();
    func_0214c544(a->mUnk_0c, d, a->mUnk_04);
    func_0214c4d4();
    a->mUnk_00 = a->mUnk_00 | (d >> 3 & 0xffff);
    if (a->mUnk_08 != 0) {
        a->mUnk_18 = (data_021619f4(a->mUnk_08, v == 2, 0) & 0xffff) << 3;
        func_0214c48c();
        func_0214c418(a->mUnk_10, a->mUnk_18, a->mUnk_08);
        func_0214c3c0();
    }
    func_02087458(a);
}

#pragma thumb off
