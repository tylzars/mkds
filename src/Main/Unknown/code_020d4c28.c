#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_0207a780.h"
#include "Main/Unknown/code_0210bcf4.h"
#include "Main/Unknown/code_0210cf9c.h"
#include "Main/Unknown/code_02146000.h"
#include "code_02146d78.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/code_020d7000.h"

void func_020d4f94(Unk020d4f94 *p) {
    s32 buf[10];

    func_02146d0c(p, buf);
    func_02146d78(&p->mUnk_24, buf, &data_0217b4f8.mUnk_08);
    data_0217b4f8.mUnk_08.x = -data_0217b4f8.mUnk_08.x;
    data_0217b4f8.mUnk_08.y = -data_0217b4f8.mUnk_08.y;
    data_0217b4f8.mUnk_08.z = -data_0217b4f8.mUnk_08.z;
    data_0217b4f8.mUnk_08.x = data_0217b4f8.mUnk_08.x << 4;
    data_0217b4f8.mUnk_08.y = data_0217b4f8.mUnk_08.y << 4;
    data_0217b4f8.mUnk_08.z = data_0217b4f8.mUnk_08.z << 4;
    data_0217b4f8.mUnk_14.x = -buf[6];
    data_0217b4f8.mUnk_14.y = -buf[7];
    data_0217b4f8.mUnk_14.z = -buf[8];
    func_02146d78(&data_0217b550.mUnk_20, buf, &data_0217b4f8.mUnk_20);
    func_02146d78(&data_0217b550.mUnk_2c, buf, &data_0217b4f8.mUnk_2c);
    func_02146d78(&data_0217b550.mUnk_38, buf, &data_0217b4f8.mUnk_38);
    func_02146d78(&data_0217b550.mUnk_44, buf, &data_0217b4f8.mUnk_44);
    if (data_0217b4f8.mUnk_50 != 0) {
        data_0217b4f8.mUnk_50 = 0;
        data_0217b4f8.mUnk_54 = 1;
    } else {
        data_0217b4f8.mUnk_54 = 0;
    }
}

u32 func_020d4f34(Vec3 *a, s32 b, s32 c, s32 d) {
    s32 x;
    s32 z;
    s32 v;
    u32 r;

    x = (a->x - data_0217b4f8.mUnk_08.x) >> 12;
    z = (a->z - data_0217b4f8.mUnk_08.z) >> 12;
    v = x * x + z * z;
    r = v & ~0xc000001f;
    if (v > d) {
        r |= data_021568f4;
    }
    return r | 3;
}

s32 func_020d4ef4(Vec3 *p) {
    s32 x;
    s32 z;

    if (p == 0) {
        return 0;
    }
    x = (p->x - data_0217b4f8.mUnk_08.x) >> 12;
    z = (p->z - data_0217b4f8.mUnk_08.z) >> 12;
    return x * x + z * z;
}

void func_020d4e28(Unk020f41c4_A *p, Vec3 *v, u32 a) {
    s32 d;

    if (a & 4) {
        if (p->mUnk_00.mUnk_34 & 1) {
            func_0210cfbc(&p->mUnk_00, 2, 1);
        }
        return;
    }
    d = data_0217b4f8.mUnk_08.y - v->y;
    if (d > -0x12c000 && d < data_0217b4f4) {
        if (!(p->mUnk_00.mUnk_34 & 1)) {
            func_0210cfbc(&p->mUnk_00, 2, 1);
        }
    } else {
        if (p->mUnk_00.mUnk_34 & 1) {
            func_0210cfbc(&p->mUnk_00, 2, 1);
        }
    }
}

s32 func_020d4ddc(Unk020e71a0 *p) {
    s32 d;

    if (p->mUnk_78 & 4) {
        return 1;
    }
    d = data_0217b4f8.mUnk_08.y - p->mUnk_04.y;
    if (p->mUnk_98->mUnk_3c < d && d < p->mUnk_98->mUnk_38) {
        return 0;
    }
    return 1;
}

s32 func_020d4d60(Unk020e71a0 *p, s32 a) {
    s32 h;
    Vec3 *v;
    Unk020e71a0_98 *q;

    v = &p->mUnk_04;
    if (a > p->mUnk_70) {
        return 1;
    }
    q = p->mUnk_98;
    h = (v->y - data_0217b4f8.mUnk_08.y) >> 12;
    if (h < q->mUnk_3c || q->mUnk_38 < h) {
        return 1;
    }
    return (func_0207a780() & p->mUnk_74) != 0;
}

void func_020d4d44(Unk02012f58 *p) {
    func_020e6df0(p);
    func_020d7bec(p);
}

void func_020d4c28(Unk020e6fd4 *p, void *a) {
    s32 i;
    Unk020e71a0 *e;
    UnkFunc *f;
    s32 n;
    void **t;
    Unk020e71a0 *b;
    s32 m;

    f = p->mUnk_10;
    n = p->mUnk_04;
    t = p->mUnk_24;
    if (f == 0) {
        return;
    }
    if (p->mUnk_1c != 0) {
        b = 0;
        for (i = 0; i < n; i++) {
            e = t[i];
            if (!(e->mUnk_02 & 0x12) && e->mUnk_66 != 0) {
                f(p, e, a, e->mUnk_66);
                if (b != 0 && (s32) (e->mUnk_78 & ~0xc000001f) > (s32) (b->mUnk_78 & ~0xc000001f)) {
                    t[m] = e;
                    t[i] = b;
                } else {
                    b = e;
                }
                m = i;
            }
        }
    } else {
        for (i = 0; i < n; i++) {
            e = t[i];
            if (!(e->mUnk_02 & 0x12) && e->mUnk_66 != 0) {
                f(p, e, a, e->mUnk_66);
            }
        }
    }
}
