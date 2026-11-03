#include "Main/Unknown/code_02073eb8.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d50c4.h"
#include "Main/Unknown/unk_02154000.h"
#include "code_02147cd8.h"

void func_02073eb8(Unk02061808 *p) {
    s32 t;
    BOOL u;

    if (p->mUnk_140 == 0) {
        return;
    }
    p->mUnk_144 = p->mUnk_144 + p->mUnk_14c * p->mUnk_150;
    t = p->mUnk_144;
    if (t > 0x1000) {
        p->mUnk_150 *= -1;
        p->mUnk_144 = 0x2000 - p->mUnk_144;
    } else if (t < -0x1000) {
        p->mUnk_150 *= -1;
        p->mUnk_144 = -0x2000 - p->mUnk_144;
    }
    p->mUnk_148 = (s32) (((s64) p->mUnk_148 * p->mUnk_154) >> 12);
    p->mUnk_148 = p->mUnk_148 - 0x14;
    p->mUnk_158 = (s32) (((s64) p->mUnk_144 * p->mUnk_148) >> 12);
    if (p->mUnk_148 <= 0) {
        u = FALSE;
        p->mUnk_158 = u;
        p->mUnk_140 = u;
    }
}

void func_02073f90(void) {
    func_02073fc8(data_usa_021656b4, 0, 0x1000);
}

void func_02073fb0(u32 a, s32 b) {
    func_02073fc8(0x2800, a, b);
}

void func_02073fc8(s32 a, u32 b, s32 c) {
    Unk02061808 *p;
    s32 d;
    s32 t;

    d = 0x1000;
    p = data_0217ac94;
    if (b > 1000000) {
        return;
    }
    if (b > 0x57e40) {
        d = 0x4cd;
    } else if (b > 0x15f90) {
        d = 0x99a;
    }
    t = (s32) (((s64) a * (s32) (((s64) c * d) >> 12)) >> 12);
    if (p->mUnk_140 != 0 && p->mUnk_148 > t) {
        return;
    }
    p->mUnk_148 = t;
    p->mUnk_140 = 1;
    p->mUnk_144 = 0;
    p->mUnk_14c = 0x800;
    p->mUnk_150 = 1;
    p->mUnk_154 = 0xe66;
    p->mUnk_158 = 0;
}

void func_0207409c(const Vec3 *a, void *b) {
    Unk02061808 *p;
    Vec3 m[3];
    Vec3 v;
    s32 t;

    p = data_0217ac94;
    func_01ffccd0(m, b);
    t = (s32) (((s64) -data_usa_0217ac90 * p->mUnk_0f0 + 0x800) >> 12);
    v.x = (s32) (((s64) m[2].x * t) >> 12);
    v.y = (s32) (((s64) m[2].y * t) >> 12);
    v.z = (s32) (((s64) m[2].z * t) >> 12);
    func_02148504(a, &v, &p->mUnk_024);
    p->mUnk_024.y = p->mUnk_024.y + data_usa_0217ac7c;
    p->mUnk_0c0 = data_usa_02154fc4;
    p->mUnk_134 = p->mUnk_024;
    p->mUnk_088 = 0x1000;
    data_0217ac94->mUnk_248 = 0;
    func_020d4f94((Unk020d4f94 *) &p->mUnk_030);
    func_020d50c4();
}

void func_020741a0(Vec3 *a, Vec3 *b, Unk02061808 *c, Unk0206bcb0 *d, Vec3 *e, const Vec3 *f, s32 g) {
    Vec3 v4;
    Vec3 v10;
    Vec3 v1;
    Vec3 v28;
    Vec3 v34;
    Vec3 v40;
    Vec3 v2;
    Vec3 v58;
    Vec3 v64;
    Vec3 v70;
    Vec3 v3;
    Vec3 v88;
    Vec3 v94;
    s32 h;
    s32 i;
    s32 j;
    s32 k;

    v1 = *f;
    h = c->mUnk_0dc - g;
    func_02063b30(d, &v10);
    if (h < 500) {
        h = 500;
    }
    func_021484d0(&d->mUnk_80, &d->mUnk_8c, &v4);
    if (d->mUnk_48 & 0x1000) {
        if (d->mUnk_4c & 0x4000000) {
            return;
        }
        c->mUnk_088 = (s32) (((s64) c->mUnk_088 * 0xe66) >> 12);
        func_02147fd8(c->mUnk_088, &v4, a, a);
        return;
    }
    v4.y = 0;
    func_02148504(a, &v4, a);
    i = -h;
    v2.x = (s32) (((s64) v1.x * i) >> 12);
    v2.y = (s32) (((s64) v1.y * i) >> 12);
    v2.z = (s32) (((s64) v1.z * i) >> 12);
    func_02148504(&v2, &c->mUnk_188, &v2);
    func_02148504(&v2, &c->mUnk_17c, &v2);
    func_02147fd8(data_usa_0217ac7c, &v10, &v2, &v3);
    func_02148504(e, &v3, &v70);
    v2.y = data_usa_0217ac7c;
    func_02148504(e, &v2, &v64);
    v40 = v64;
    v40.y = v40.y + c->mUnk_168;
    if (!(d->mUnk_48 & 0x40000000)) {
        v88 = data_usa_02154fdc;
    } else {
        func_021484d0(&v70, &v40, &v88);
        func_02147fd8(-0x1e000, &v10, &v88, &v88);
    }
    func_021484d0(&v88, b, &v94);
    v94.x = (s32) (((s64) v94.x * 0x19a) >> 12);
    v94.y = (s32) (((s64) v94.y * 0x19a) >> 12);
    v94.z = (s32) (((s64) v94.z * 0x19a) >> 12);
    func_02148504(b, &v94, b);
    func_02148504(&v40, b, &v40);
    func_021484d0(&v40, a, &v58);
    j = v58.y;
    k = 0;
    v58.y = 0;
    if ((s64) v58.x * v58.x + (s64) v58.y * v58.y + (s64) v58.z * v58.z >= 16) {
        k = func_02039860(&v58, &v58);
    }
    func_02147fd8((s32) (((s64) k * 0x11f) >> 12), &v58, a, a);
    a->y = a->y + ((s32) (((s64) j * 0x11f) >> 9) + g * 2);
    if (c->mUnk_248 != 0) {
        if (c->mUnk_0d0 != 0) {
            s32 l;
            l = a->y - c->mUnk_0cc;
            c->mUnk_0cc = c->mUnk_0cc + (s32) (((s64) l * 0x29 + 0x800) >> 12);
        }
        a->y = c->mUnk_0cc;
    }
    func_021484d0(a, e, &v28);
    v34 = v28;
    k = 0;
    if ((s64) v34.x * v34.x + (s64) v34.y * v34.y + (s64) v34.z * v34.z >= 16) {
        k = func_02039860(&v34, &v34);
    }
    if (k == 0) {
        return;
    }
    func_02147fd8((s32) (((s64) c->mUnk_0dc * c->mUnk_0e8) >> 12), &v34, e, a);
}

void func_020745d4(Vec3 *a, Vec3 *b, s32 *c, Unk0206bcb0 *d, s32 e, s32 f) {
    Vec3 v4;
    Vec3 v10;
    Vec3 v1;
    Vec3 v28;
    s32 t;

    v4 = d->mUnk_80;
    v10 = d->mUnk_80;
    v10.y = v10.y - e;
    func_02147fd8(f, &d->mUnk_12c, &v10, &v10);
    v4.y = v4.y + (f - e);
    if (!(d->mUnk_48 & 0x40000000)) {
        v1 = data_usa_02154fdc;
    } else {
        func_021484d0(&v10, &v4, &v1);
        func_02147fd8(0xa000, &d->mUnk_12c, &v1, &v1);
    }
    func_021484d0(&v1, b, &v28);
    v28.x = (s32) (((s64) v28.x * 0x266) >> 12);
    v28.y = (s32) (((s64) v28.y * 0x266) >> 12);
    v28.z = (s32) (((s64) v28.z * 0x266) >> 12);
    func_02148504(b, &v28, b);
    func_02148504(&v4, b, &v4);
    a->x = v4.x;
    a->z = v4.z;
    if (d->mUnk_48 & 0x10000) {
        *c = *c + 0x1000;
        if (*c > 0xa000) {
            *c = 0xa000;
        }
    } else {
        t = *c;
        *c = t + (s32) (((s64) -t * 0x29 + 0x800) >> 12);
    }
    v4.y = v4.y - *c;
    t = a->y;
    a->y = t + (s32) (((s64) (v4.y - t) * 0xccd + 0x800) >> 12);
}

void func_020747f4(s32 a) {
    data_0217ac94->mUnk_248 = a;
    if (a == 0) {
        return;
    }
    data_0217ac94->mUnk_0cc = data_0217ac94->mUnk_024.y;
    data_0217ac94->mUnk_0d0 = 0;
}

void func_02074828(void) {
    s32 t;

    t = data_0216569c;
    data_0217ac94->mUnk_064 = t;
    data_0217ac94->mUnk_060 = t + 5;
}
