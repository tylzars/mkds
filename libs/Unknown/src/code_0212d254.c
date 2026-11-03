#include "code_0212d254.h"

#include "code_02003be0.h"
#include "code_0212f788.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_0212da38.h"
#include "code_02004d80.h"
#include "code_0212d214.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0212d968.h"
#include "code_02020eb0.h"
#include "code_0201750c.h"
#include "Main/Unknown/code_02017000.h"
#include "code_020172d0.h"
#include "Main/Unknown/code_02018000.h"
#include "Main/Unknown/code_02021000.h"
#include "code_0212da1c.h"
#include "code_02017f24.h"
#include "code_0214d018.h"

u32 func_0212d9dc(Unk0212d9dc *a, void *p) {
    func_02017538(&a->mUnk_04, 12);
    a->mUnk_00 = p;
    return func_0212d98c(a) != 0;
}

u32 func_0212d98c(Unk0212d9dc *a) {
    void *p;

    p = FrmHeapAlloc(a->mUnk_00, 0x14, 4);
    if (p == 0) {
        return 0;
    }
    func_0212da1c(p);
    func_020174a4(&a->mUnk_04, p);
    return 1;
}

void func_0212d968(void) {
    u32 v;

    v = func_02021114();
    func_020211e4(1);
    func_02021154(v);
}

void func_0212d8e0(Unk0212d5f8 *a, const u8 *path, void *p, u32 flag) {
    a->mUnk_8c = 0;
    a->mUnk_84 = 0;
    a->mUnk_88 = 0;
    if (FS_ConvertPathToFileID(&a->mUnk_7c, path) == 0) {
        return;
    }
    FS_InitFile(&a->mUnk_34);
    if (FS_OpenFileFast(&a->mUnk_34, a->mUnk_7c) == 0) {
        return;
    }
    a->mUnk_30 = 1;
    if (func_0212d6c4(a, p, flag) != 0) {
        data_0217dec4 = a;
    }
}

u32 func_0212d6c4(Unk0212d5f8 *a, void *p, u32 flag) {
    s32 n;

    if (FS_SeekFile(&a->mUnk_34, 0, 0) == 0) {
        return 0;
    }
    if (FS_ReadFile(&a->mUnk_34, a, 0x30) != 0x30) {
        return 0;
    }
    if (p != 0) {
        a->mUnk_8c = func_0212db7c(p, a->mUnk_1c, func_0212d22c, a, 0);
        if (a->mUnk_8c == 0) {
            return 0;
        }
        if (FS_SeekFile(&a->mUnk_34, a->mUnk_18, 0) == 0) {
            return 0;
        }
        n = FS_ReadFile(&a->mUnk_34, a->mUnk_8c, a->mUnk_1c);
        if (n != a->mUnk_1c) {
            return 0;
        }
        a->mUnk_84 = func_0212db7c(p, a->mUnk_24, func_0212d220, a, 0);
        if (a->mUnk_84 == 0) {
            return 0;
        }
        if (FS_SeekFile(&a->mUnk_34, a->mUnk_20, 0) == 0) {
            return 0;
        }
        n = FS_ReadFile(&a->mUnk_34, a->mUnk_84, a->mUnk_24);
        if (n != a->mUnk_24) {
            return 0;
        }
        if (flag != 0 && a->mUnk_14 != 0) {
            a->mUnk_88 = func_0212db7c(p, a->mUnk_14, func_0212d214, a, 0);
            if (a->mUnk_88 == 0) {
                return 0;
            }
            if (FS_SeekFile(&a->mUnk_34, a->mUnk_10, 0) == 0) {
                return 0;
            }
            n = FS_ReadFile(&a->mUnk_34, a->mUnk_88, a->mUnk_14);
            if (n != a->mUnk_14) {
                return 0;
            }
        }
    }
    return 1;
}

void func_0212d5f8(Unk0212d5f8 *a, void *buf) {
    u32 i;

    func_0214d02c(buf, a, 0x30);
    a->mUnk_8c = a->mUnk_18 == 0 ? 0 : (Unk0212d38c *) ((u8 *) buf + a->mUnk_18);
    a->mUnk_84 = a->mUnk_20 == 0 ? 0 : (Unk0212d254 *) ((u8 *) buf + a->mUnk_20);
    a->mUnk_88 = a->mUnk_10 == 0 ? 0 : (u8 *) buf + a->mUnk_10;
    for (i = 0; i < a->mUnk_84->mUnk_08; i++) {
        Unk0212d27c *e = &a->mUnk_84->mUnk_0c[i];

        e->mUnk_08 = e->mUnk_00 == 0 ? 0 : (Unk0212f788 *) ((u8 *) buf + e->mUnk_00);
    }
    a->mUnk_30 = 0;
    data_0217dec4 = a;
}

Unk0212d5f8 *func_0212d5e0(Unk0212d5f8 *a) {
    Unk0212d5f8 *old = data_0217dec4;

    data_0217dec4 = a;
    return old;
}

struct Unk0212d5f8 *func_0212d5d0(void) {
    u32 value0;
    value0 = (u32) &data_0217dec4;
    value0 = (u32) * (const u32 *) ((value0) + (0));
    return (struct Unk0212d5f8 *) value0;
}

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

    off = d->mUnk_8c->mUnk_08[0];
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

    off = d->mUnk_8c->mUnk_08[1];
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

    off = d->mUnk_8c->mUnk_08[2];
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

    off = d->mUnk_8c->mUnk_08[3];
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

    off = d->mUnk_8c->mUnk_08[4];
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

    off = d->mUnk_8c->mUnk_08[5];
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
