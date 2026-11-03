#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_02087d0c.h"
#include "Main/Unknown/code_020846c0.h"
#include "Main/Unknown/code_020d22e0.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/code_020ea588.h"
#include "Main/Unknown/code_020ea618.h"
#include "Main/Unknown/code_020ea670.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_020109c4.h"
#include "code_02012b30.h"

void *func_0209bbfc(void *b) {
    Unk020e6fd4 *a = b;
    MapObject *e;
    s32 i;

    if (a != NULL) {
        for (i = 0; i < a->mUnk_04 && (e = a->mUnk_00[i]) != NULL; i++) {
            if ((e->mFlags & 0x100) != 0) {
                func_020d233c(e);
                return e;
            }
        }
    }
    return NULL;
}

void func_0209bbd0(void *a, void *b) {
    Unk0209bc74 *o = b;

    if (o->mUnk_0c == NULL) {
        return;
    }
    func_020e6a18(o->mUnk_0c);
}

void func_0209bb2c(void *a, void *b, void *d) {
    Unk0209bc74 *o = b;
    MapObject *c = d;

    func_01ff9048(0x1b, o, 3);
    if (o->mUnk_0c != NULL) {
        func_020ea5b0(o->mUnk_0c, c->mUnk_66, NULL);
    }
    if (o->mUnk_10 == NULL && o->mUnk_14 == NULL) {
        return;
    }
    if (o->mUnk_10 != NULL) {
        if (o->mUnk_1c[2] != NULL) {
            func_020ea670(o->mUnk_10, c->mUnk_66);
        } else {
            func_020ea7cc(o->mUnk_10, c->mUnk_66);
        }
    }
    if (o->mUnk_14 == NULL) {
        return;
    }
    func_020ea618(o->mUnk_14, c->mUnk_66);
}

void func_0209ba88(u32 a, Unk0209bc74 *b, int d) {
    Unk0209bc74 *o = b;
    MapObject *c = (MapObject *) d;

    func_01ff9048(0x1b, o, 3);
    if (o->mUnk_0c != NULL) {
        func_020ea5b0(o->mUnk_0c, c->mUnk_66, &c->mPos);
    }
    if (o->mUnk_10 == NULL && o->mUnk_14 == NULL) {
        return;
    }
    if (o->mUnk_10 != NULL) {
        if (o->mUnk_1c[2] != NULL) {
            func_020ea670(o->mUnk_10, c->mUnk_66);
        } else {
            func_020ea7cc(o->mUnk_10, c->mUnk_66);
        }
    }
    if (o->mUnk_14 == NULL) {
        return;
    }
    func_020ea618(o->mUnk_14, c->mUnk_66);
}

void func_0209ba58(void *a, void *b, void *c) {
    Unk0209bc74 *o = b;

    if (o->mUnk_10 == NULL) {
        return;
    }
    func_020ea740(o->mUnk_10, ((MapObject *) c)->mUnk_66);
}

void func_0209ba08(void *a, u32 b) {
    Unk0209bc74 *o = a;
    Unk020e6488 *m = o->mUnk_0c;

    if (m != NULL) {
        m->mUnk_14 &= ~0xf;
        m->mUnk_14 |= b;
    }
    if (o->mUnk_10 == NULL) {
        return;
    }
    func_020849b0(o->mUnk_10, b);
}

void func_0209b9a4(void *a, u16 b) {
    Unk0209bc74 *o = a;
    Unk020e6488 *m = o->mUnk_0c;

    if (m != NULL) {
        m->mUnk_14 &= ~0x1f0000;
        m->mUnk_14 |= b << 16;
    }
    if (o->mUnk_10 != NULL) {
        func_0201308c(o->mUnk_10->mUnk_004, b);
    }
    if (o->mUnk_14 != NULL) {
        o->mUnk_14->mUnk_6e = b;
    }
}

void func_0209b940(void *a, u32 b) {
    Unk0209bc74 *o = a;
    Unk020e6488 *m = o->mUnk_0c;

    if (m != NULL) {
        m->mUnk_14 &= ~0x3f000000;
        m->mUnk_14 |= b << 24;
    }
    if (o->mUnk_10 != NULL) {
        func_020130d4(o->mUnk_10->mUnk_004, b);
    }
    if (o->mUnk_14 != NULL) {
        o->mUnk_14->mUnk_6c = b;
    }
}

void func_0209b904(void *a, u32 b, u16 c) {
    Unk0209bc74 *o = a;

    if (o->mUnk_10 == NULL) {
        return;
    }
    func_020134b0(o->mUnk_10->mUnk_004, c, b);
}

void func_0209b8ac(void *a, u32 b) {
    Unk0209bc74 *o = a;
    Unk020e6488 *m = o->mUnk_0c;

    if (m != NULL) {
        if (b != 0) {
            m->mUnk_14 |= 0x8000;
        } else {
            m->mUnk_14 &= ~0x8000;
        }
    }
    if (o->mUnk_10 == NULL) {
        return;
    }
    func_02013044(o->mUnk_10->mUnk_004, b);
}

void func_0209b7a0(void *a, s32 b, s32 c) {
    Unk0209bc74 *o = a;
    Unk020e6488 *m;
    s32 k;

    if (o->mUnk_0c != NULL) {
        m = o->mUnk_0c;
        k = b != 0 || c != 0 ? 1 : 0;
        if (k ^ data_021759c0->mUnk_57) {
            m->mUnk_14 &= ~0x80;
            o->mUnk_0c->mUnk_14 |= 0x40;
        } else {
            m->mUnk_14 |= 0x80;
            o->mUnk_0c->mUnk_14 &= ~0x40;
        }
    }
    if (o->mUnk_10 != NULL) {
        k = b != 0 || c != 0 ? 1 : 0;
        if (k ^ data_021759c0->mUnk_57) {
            func_02084958(o->mUnk_10, 1);
        } else {
            func_02084958(o->mUnk_10, 2);
        }
    }
    o->mUnk_00.mUnk_00 = b != 0 ? -0x1000 : 0x1000;
    o->mUnk_00.mUnk_04 = c != 0 ? -0x1000 : 0x1000;
}

void func_0209b77c(void *a, u16 b) {
    Unk0209bc74 *o = a;
    Unk02087d0c *p = o->mUnk_1c[0];

    p->mUnk_0c = b << 12;
    p->mUnk_1c[p->mUnk_1a]->mUnk_00 = p->mUnk_0c;
}

u16 func_0209b758(void *a) {
    Unk0209bc74 *o = a;

    return (u16) ((u32) func_02087d0c(o->mUnk_1c[0]) >> 12);
}

void func_0209b734(void *a, u32 b) {
    Unk0209bc74 *o = a;
    Unk02087d0c *p = o->mUnk_1c[2];

    p->mUnk_0c = b << 12;
    p->mUnk_1c[p->mUnk_1a]->mUnk_00 = p->mUnk_0c;
}

s32 func_0209b710(void *a) {
    Unk0209bc74 *o = a;

    return (u16) ((u32) func_02087d0c(o->mUnk_1c[2]) >> 12);
}

u16 func_0209b6ec(void *a) {
    Unk0209bc74 *o = a;

    return (u16) ((u32) func_02087d0c(o->mUnk_1c[3]) >> 12);
}

void func_0209b6c8(void *a, s32 b) {
    Unk0209bc74 *o = a;
    Unk02087d0c *p = o->mUnk_1c[3];

    p->mUnk_0c = b << 12;
    p->mUnk_1c[p->mUnk_1a]->mUnk_00 = p->mUnk_0c;
}

void func_0209b688(void *a, u16 b) {
    Unk0209bc74 *o = a;
    Unk02087d0c *p;

    if (o->mUnk_0c != NULL) {
        o->mUnk_0c->mUnk_18 = b;
        return;
    }
    if (o->mUnk_10 == NULL) {
        return;
    }
    p = o->mUnk_1c[1];
    p->mUnk_0c = b << 12;
    p->mUnk_1c[p->mUnk_1a]->mUnk_00 = p->mUnk_0c;
}

u16 func_0209b634(void *a) {
    Unk0209bc74 *o = a;

    if (o->mUnk_0c != NULL) {
        return o->mUnk_0c->mUnk_1a;
    }
    if (o->mUnk_10 == NULL) {
        return 0;
    }
    return (u16) ((u32) func_02087d0c(o->mUnk_1c[1]) >> 12);
}
