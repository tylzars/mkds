#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_02087d0c.h"
#include "Main/Unknown/code_020846c0.h"
#include "Main/Unknown/code_020d22e0.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020ea588.h"
#include "Main/Unknown/code_020ea618.h"
#include "Main/Unknown/code_020ea670.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02012b30.h"

u16 func_0209b634(void *param_1) {
    Unk0209bc74 *o = param_1;

    if (o->mUnk_0c != 0) {
        return o->mUnk_0c->mUnk_1a;
    }
    if (o->mUnk_10 == 0) {
        return 0;
    }
    return (u16) ((u32) func_02087d0c(o->mUnk_20) >> 12);
}

void func_0209b688(void *param_1, u16 param_2) {
    Unk0209bc74 *o = param_1;
    Unk02087d0c *p;

    if (o->mUnk_0c != 0) {
        o->mUnk_0c->mUnk_18 = param_2;
        return;
    }
    if (o->mUnk_10 == 0) {
        return;
    }
    p = o->mUnk_20;
    p->mUnk_0c = param_2 << 12;
    p->mUnk_1c[p->mUnk_1a]->mUnk_00 = p->mUnk_0c;
}

void func_0209b6c8(void *a, s32 b) {
    Unk0209bc74 *o = a;
    Unk02087d0c *p = o->mUnk_28;

    p->mUnk_0c = b << 12;
    p->mUnk_1c[p->mUnk_1a]->mUnk_00 = p->mUnk_0c;
}

u16 func_0209b6ec(void *a) {
    Unk0209bc74 *o = a;

    return (u16) ((u32) func_02087d0c(o->mUnk_28) >> 12);
}

s32 func_0209b710(void *param_1) {
    Unk0209bc74 *o = param_1;

    return (u16) ((u32) func_02087d0c(o->mUnk_24) >> 12);
}

void func_0209b734(void *param_1, u32 param_2) {
    Unk0209bc74 *o = param_1;
    Unk02087d0c *p = o->mUnk_24;

    p->mUnk_0c = param_2 << 12;
    p->mUnk_1c[p->mUnk_1a]->mUnk_00 = p->mUnk_0c;
}

u16 func_0209b758(void *a) {
    Unk0209bc74 *o = a;

    return (u16) ((u32) func_02087d0c(o->mUnk_1c) >> 12);
}

void func_0209b77c(void *a, u16 b) {
    Unk0209bc74 *o = a;
    Unk02087d0c *p = o->mUnk_1c;

    p->mUnk_0c = b << 12;
    p->mUnk_1c[p->mUnk_1a]->mUnk_00 = p->mUnk_0c;
}

void func_0209b7a0(void *param_1, s32 param_2, s32 param_3) {
    Unk0209bc74 *o = param_1;
    Unk020e6488 *m;
    s32 k;

    if (o->mUnk_0c != 0) {
        m = o->mUnk_0c;
        k = param_2 != 0 || param_3 != 0 ? 1 : 0;
        if (k ^ data_021759c0->mUnk_57) {
            m->mUnk_14 &= ~0x80;
            o->mUnk_0c->mUnk_14 |= 0x40;
        } else {
            m->mUnk_14 |= 0x80;
            o->mUnk_0c->mUnk_14 &= ~0x40;
        }
    }
    if (o->mUnk_10 != 0) {
        k = param_2 != 0 || param_3 != 0 ? 1 : 0;
        if (k ^ data_021759c0->mUnk_57) {
            func_02084958(o->mUnk_10, 1);
        } else {
            func_02084958(o->mUnk_10, 2);
        }
    }
    o->mUnk_00.mUnk_00 = param_2 != 0 ? -0x1000 : 0x1000;
    o->mUnk_00.mUnk_04 = param_3 != 0 ? -0x1000 : 0x1000;
}

void func_0209b8ac(void *param_1, u32 param_2) {
    Unk0209bc74 *o = param_1;
    Unk020e6488 *m = o->mUnk_0c;

    if (m != 0) {
        if (param_2 != 0) {
            m->mUnk_14 |= 0x8000;
        } else {
            m->mUnk_14 &= ~0x8000;
        }
    }
    if (o->mUnk_10 == 0) {
        return;
    }
    func_02013044(o->mUnk_10->mUnk_004, param_2);
}

void func_0209b904(void *param_1, u32 param_2, u16 param_3) {
    Unk0209bc74 *o = param_1;

    if (o->mUnk_10 == 0) {
        return;
    }
    func_020134b0(o->mUnk_10->mUnk_004, param_3, param_2);
}

void func_0209b940(void *param_1, u32 param_2) {
    Unk0209bc74 *o = param_1;
    Unk020e6488 *m = o->mUnk_0c;

    if (m != 0) {
        m->mUnk_14 &= ~0x3f000000;
        m->mUnk_14 |= param_2 << 24;
    }
    if (o->mUnk_10 != 0) {
        func_020130d4(o->mUnk_10->mUnk_004, param_2);
    }
    if (o->mUnk_14 != 0) {
        o->mUnk_14->mUnk_6c = param_2;
    }
}

void func_0209b9a4(void *param_1, u16 param_2) {
    Unk0209bc74 *o = param_1;
    Unk020e6488 *m = o->mUnk_0c;

    if (m != 0) {
        m->mUnk_14 &= ~0x1f0000;
        m->mUnk_14 |= param_2 << 16;
    }
    if (o->mUnk_10 != 0) {
        func_0201308c(o->mUnk_10->mUnk_004, param_2);
    }
    if (o->mUnk_14 != 0) {
        o->mUnk_14->mUnk_6e = param_2;
    }
}

void func_0209ba08(void *param_1, u32 param_2) {
    Unk0209bc74 *o = param_1;
    Unk020e6488 *m = o->mUnk_0c;

    if (m != 0) {
        m->mUnk_14 &= ~0xf;
        m->mUnk_14 |= param_2;
    }
    if (o->mUnk_10 == 0) {
        return;
    }
    func_020849b0(o->mUnk_10, param_2);
}

void func_0209ba58(void *a, void *b, void *c) {
    Unk0209bc74 *o = b;

    if (o->mUnk_10 == 0) {
        return;
    }
    func_020ea740(o->mUnk_10, ((Unk020e71a0 *) c)->mUnk_66);
}

void func_0209ba88(u32 param_1, Unk0209bc74 *param_2, int param_3) {
    Unk0209bc74 *o = param_2;
    Unk020e71a0 *c = (Unk020e71a0 *) param_3;

    func_01ff9048(0x1b, o, 3);
    if (o->mUnk_0c != 0) {
        func_020ea5b0(o->mUnk_0c, c->mUnk_66, &c->mUnk_04);
    }
    if (o->mUnk_10 == 0 && o->mUnk_14 == 0) {
        return;
    }
    if (o->mUnk_10 != 0) {
        if (o->mUnk_24 != 0) {
            func_020ea670(o->mUnk_10, c->mUnk_66);
        } else {
            func_020ea7cc(o->mUnk_10, c->mUnk_66);
        }
    }
    if (o->mUnk_14 == 0) {
        return;
    }
    func_020ea618(o->mUnk_14, c->mUnk_66);
}

void func_0209bb2c(void *param_1, void *param_2, void *param_3) {
    Unk0209bc74 *o = param_2;
    Unk020e71a0 *c = param_3;

    func_01ff9048(0x1b, o, 3);
    if (o->mUnk_0c != 0) {
        func_020ea5b0(o->mUnk_0c, c->mUnk_66, 0);
    }
    if (o->mUnk_10 == 0 && o->mUnk_14 == 0) {
        return;
    }
    if (o->mUnk_10 != 0) {
        if (o->mUnk_24 != 0) {
            func_020ea670(o->mUnk_10, c->mUnk_66);
        } else {
            func_020ea7cc(o->mUnk_10, c->mUnk_66);
        }
    }
    if (o->mUnk_14 == 0) {
        return;
    }
    func_020ea618(o->mUnk_14, c->mUnk_66);
}

void func_0209bbd0(void *param_1, void *param_2) {
    Unk0209bc74 *o = param_2;

    if (o->mUnk_0c == 0) {
        return;
    }
    func_020e6a18(o->mUnk_0c);
}

void *func_0209bbfc(void *param_1) {
    Unk020e6fd4 *a = param_1;
    Unk020e71a0 *e;
    s32 i;

    if (a != 0) {
        for (i = 0; i < a->mUnk_04 && (e = a->mUnk_00[i]) != 0; i++) {
            if ((e->mUnk_02 & 0x100) != 0) {
                func_020d233c(e);
                return e;
            }
        }
    }
    return 0;
}
