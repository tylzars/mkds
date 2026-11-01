#include "Main/Unknown/code_0203b0a0.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0202db04.h"
#include "Main/Unknown/code_02045000.h"
#include "Main/Unknown/code_020445f8.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/code_0204799c.h"
#include "Main/Unknown/code_0204e000.h"
#include "Main/Unknown/code_020563d8.h"
#include "Main/Unknown/code_02056408.h"
#include "Main/Unknown/code_02056700.h"
#include "Main/Unknown/code_02056a7c.h"
#include "Main/Unknown/code_02056b08.h"
#include "Main/Unknown/code_020593dc.h"
#include "Main/Unknown/code_0205982c.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_021759c0.h"

s32 func_0203b0a0(const u8 *a, const u8 *b) {
    if (a[0] < b[0]) {
        return 1;
    }
    if (a[0] > b[0]) {
        return 0;
    }
    if (a[1] < b[1]) {
        return 1;
    }
    if (a[1] > b[1]) {
        return 0;
    }
    return a[2] < b[2];
}

void func_0203b0f8(void *a) {
    void *r = 0;
    s32 t;
    u32 f;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        func_0204f240(a, 1);
    } else {
        r = func_0204799c(data_usa_0216478c);
    }
    t = data_021759d0->mUnk_20;
    f = 1;
    if (t != 1 && t != 2) {
        f = 0;
    }
    if (f != 0) {
        func_0204e928(a, t == 1, (u32) r);
        func_0205982c(a);
    }
    func_02045590();
}

void func_0203b194(void *a) {
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        func_0204f240(a, 1);
    }
    func_0205949c();
}

void func_0203b1c8(void *a) {
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        func_0204f240(a, 1);
    }
    func_020594d4();
}

void func_0203b1fc(void *a) {
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        func_0204f240(a, 1);
    }
    func_020445f8();
}

u32 func_0203b230(void) {
    Unk02056a2c c;
    Unk02056a2c d;
    u32 r = 0;
    s32 a;
    s32 b;
    s32 t;
    s32 v1;
    a = (data_021759c0->mUnk_08 == 4) ? data_021759c0->mUnk_54 : -1;
    b = (data_021759c0->mUnk_08 == 4) ? data_021759c0->mUnk_55 : -1;
    t = func_0203c880((u16) data_021759c0->mUnk_62);
    t = (t != 0) ? data_0217561c->mUnk_4e0 : 6;
    if (t != 0) {
        return 0;
    }
    func_020569dc((u16) a, (u16) b, &c);
    d.mUnk_00 = 1;
    d.mUnk_01 = func_0205d140();
    if (c.mUnk_00 == 0) {
        v1 = 1;
    } else {
        v1 = c.mUnk_01 < d.mUnk_01;
    }
    if (v1 != 0) {
        func_02056a04((u16) a, (u16) b, &d);
        func_020563d8();
        r = 1;
    }
    return r;
}

s32 func_0203b324(void) {
    Unk02056bc0 a;
    Unk02056bc0 b;
    s32 r = 0;
    s32 v;
    Unk0217b488 *p = data_0217b488;
    switch (p->mUnk_88) {
        case 0:
            v = r;
            break;
        case 1:
            v = 1;
            break;
        case 2:
            v = (p->mUnk_8c != 0) ? 3 : 2;
            break;
    }
    func_02056a7c(p->mUnk_84, v, &a);
    func_0203b4c8(&b);
    if (func_0203b3d8(&a, &b) != 0) {
        func_02056b08(data_0217b488->mUnk_84, v, &b);
        func_0205641c();
        r = 1;
    }
    return r;
}

s32 func_0203b3d8(Unk02056bc0 *a, Unk02056bc0 *b) {
    s32 x;
    s32 y;
    if (b->mUnk_1c == 3) {
        return 0;
    }
    if (a->mUnk_18 == 0) {
        return 1;
    }
    if (a->mUnk_1c > b->mUnk_1c) {
        return 1;
    }
    if (a->mUnk_1c < b->mUnk_1c) {
        return 0;
    }
    if (a->mUnk_1e < b->mUnk_1e) {
        return 1;
    }
    if (a->mUnk_1e > b->mUnk_1e) {
        return 0;
    }
    if (a->mUnk_1d < b->mUnk_1d) {
        return 1;
    }
    if (a->mUnk_1d > b->mUnk_1d) {
        return 0;
    }
    x = a->mUnk_03 * 1000 + a->mUnk_02 * 60000 + a->mUnk_00;
    y = b->mUnk_03 * 1000 + b->mUnk_02 * 60000 + b->mUnk_00;
    return x > y;
}

void func_0203b4c8(Unk02056bc0 *a) {
    u8 i;
    a->mUnk_02 = 0;
    a->mUnk_03 = 0;
    a->mUnk_00 = 0;
    func_0214d1fc(data_0217aa08->mUnk_00->mUnk_0c, a->mUnk_04, 0x14);
    for (i = 0; i < 4; i++) {
        func_0203b598(a, &data_0217b488->mUnk_98[i], a);
    }
    a->mUnk_19 = data_0217b488->mUnk_90;
    a->mUnk_1a = data_0217b488->mUnk_94;
    a->mUnk_1b = 0;
    a->mUnk_1c = data_usa_02154064[data_0217b488->mUnk_7c];
    a->mUnk_1d = data_0217b488->mUnk_a8;
    a->mUnk_1e = data_0217b488->mUnk_80;
    a->mUnk_18 = 1;
}

void func_0203b598(Unk02056bc0 *a, Unk0217aa1c_144_00 *b, Unk02056bc0 *c) {
    u16 v1 = a->mUnk_00 + b->mUnk_00;
    u16 v2 = a->mUnk_02 + b->mUnk_02;
    u16 v3 = a->mUnk_03 + b->mUnk_03;
    u16 d = v1 / 1000;
    if (d != 0) {
        v3 += d;
        v1 -= d * 1000;
    }
    d = v3 / 60;
    if (d != 0) {
        v2 += d;
        v3 -= d * 60;
    }
    if (v2 > 99) {
        v2 = 99;
    }
    c->mUnk_02 = v2;
    c->mUnk_03 = v3;
    c->mUnk_00 = v1;
}
