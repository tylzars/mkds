#include "code_0212d254.h"
#include "code_02004270.h"
#include "code_0212f788.h"
#include "Main/Unknown/unk_0217d000.h"

Unk0212d580 *func_0212d580(s32 a, s32 b) {
    u32 *p;
    Unk0212f788 *q;
    u32 *r;

    p = func_0212d4b8(a);
    if (p == 0) {
        return 0;
    }
    q = func_0212d254(*p);
    if (q == 0) {
        return 0;
    }
    r = func_0212f788(q, b);
    if (r == 0) {
        return 0;
    }
    return (Unk0212d580 *) (r + 1);
}

void *func_0212d51c(s32 a) {
    Unk0212d5f8 *d = data_0217dec4;
    Unk0212d328 *t;
    u32 off;
    u8 *base;

    off = d->mUnk_8c->mUnk_08;
    t = off == 0 ? 0 : (Unk0212d328 *) ((u8 *) d->mUnk_8c + off);
    if (t == 0) {
        return 0;
    }
    if (a < 0) {
        return 0;
    }
    if (a >= t->mUnk_00) {
        return 0;
    }
    off = t->mUnk_04[a];
    base = (u8 *) d->mUnk_8c;
    return off == 0 ? 0 : base + off;
}

u32 *func_0212d4b8(s32 a) {
    Unk0212d5f8 *d = data_0217dec4;
    Unk0212d328 *t;
    u32 off;
    u8 *base;

    off = d->mUnk_8c->mUnk_0c;
    t = off == 0 ? 0 : (Unk0212d328 *) ((u8 *) d->mUnk_8c + off);
    if (t == 0) {
        return 0;
    }
    if (a < 0) {
        return 0;
    }
    if (a >= t->mUnk_00) {
        return 0;
    }
    off = t->mUnk_04[a];
    base = (u8 *) d->mUnk_8c;
    return off == 0 ? 0 : (u32 *) (base + off);
}

void *func_0212d454(s32 a) {
    Unk0212d5f8 *d = data_0217dec4;
    Unk0212d328 *t;
    u32 off;
    u8 *base;

    off = d->mUnk_8c->mUnk_10;
    t = off == 0 ? 0 : (Unk0212d328 *) ((u8 *) d->mUnk_8c + off);
    if (t == 0) {
        return 0;
    }
    if (a < 0) {
        return 0;
    }
    if (a >= t->mUnk_00) {
        return 0;
    }
    off = t->mUnk_04[a];
    base = (u8 *) d->mUnk_8c;
    return off == 0 ? 0 : base + off;
}

void *func_0212d3f0(s32 a) {
    Unk0212d5f8 *d = data_0217dec4;
    Unk0212d328 *t;
    u32 off;
    u8 *base;

    off = d->mUnk_8c->mUnk_14;
    t = off == 0 ? 0 : (Unk0212d328 *) ((u8 *) d->mUnk_8c + off);
    if (t == 0) {
        return 0;
    }
    if (a < 0) {
        return 0;
    }
    if (a >= t->mUnk_00) {
        return 0;
    }
    off = t->mUnk_04[a];
    base = (u8 *) d->mUnk_8c;
    return off == 0 ? 0 : base + off;
}

void *func_0212d38c(s32 a) {
    Unk0212d5f8 *d = data_0217dec4;
    Unk0212d328 *t;
    u32 off;
    u8 *base;

    off = d->mUnk_8c->mUnk_18;
    t = off == 0 ? 0 : (Unk0212d328 *) ((u8 *) d->mUnk_8c + off);
    if (t == 0) {
        return 0;
    }
    if (a < 0) {
        return 0;
    }
    if (a >= t->mUnk_00) {
        return 0;
    }
    off = t->mUnk_04[a];
    base = (u8 *) d->mUnk_8c;
    return off == 0 ? 0 : base + off;
}

void *func_0212d328(s32 a) {
    Unk0212d5f8 *d = data_0217dec4;
    Unk0212d328 *t;
    u32 off;
    u8 *base;

    off = d->mUnk_8c->mUnk_1c;
    t = off == 0 ? 0 : (Unk0212d328 *) ((u8 *) d->mUnk_8c + off);
    if (t == 0) {
        return 0;
    }
    if (a < 0) {
        return 0;
    }
    if (a >= t->mUnk_00) {
        return 0;
    }
    off = t->mUnk_04[a];
    base = (u8 *) d->mUnk_8c;
    return off == 0 ? 0 : base + off;
}

u32 func_0212d300(u32 a) {
    Unk0212d254 *t = data_0217dec4->mUnk_84;

    if (a >= t->mUnk_08) {
        return 0;
    }
    return t->mUnk_0c[a].mUnk_04;
}

s32 func_0212d27c(u32 a, void *dst, u32 n, u32 off) {
    Unk0212d5f8 *d = data_0217dec4;
    Unk0212d254 *t;
    Unk0212d27c *e;
    u32 left;

    t = d->mUnk_84;
    if (a >= t->mUnk_08) {
        return -1;
    }
    e = &t->mUnk_0c[a];
    left = e->mUnk_04 - off;
    if (n > left) {
        n = left;
    }
    if (FS_SeekFile(&d->mUnk_34, e->mUnk_00 + off, 0) == 0) {
        return -1;
    }
    return FS_ReadFile(&d->mUnk_34, dst, n);
}

void *func_0212d254(u32 a) {
    Unk0212d254 *t = data_0217dec4->mUnk_84;

    if (a >= t->mUnk_08) {
        return 0;
    }
    return t->mUnk_0c[a].mUnk_08;
}
