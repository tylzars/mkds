#include "code_020184e4.h"
#include "code_02146d78.h"
#include "code_02147288.h"
#include "code_02147cd8.h"
#include "code_0214a4dc.h"
#include "code_0214c1bc.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02173000.h"
#include "code_0214d018.h"
#include "registers.h"

void func_0201c09c(Unk020184e4 *p, Unk0201e3c8 *n) {
    Vec3 t;
    Unk02012f58 m;
    s32 k;
    s32 f0;
    s32 f1;
    s32 t0;
    s32 t1;
    u16 c0;
    u16 c1;
    s32 x;
    s32 y;
    s32 z;
    s32 s;
    Unk02012f58 *q;
    u8 w;
    s32 h;

    s = p->mUnk_40->mUnk_20->mUnk_00->mUnk_30;
    q = p->mUnk_44;
    w = p->mUnk_40->mUnk_20->mUnk_00->mUnk_48.mUnk_00_28;
    h = n->mUnk_34;
    c0 = n->mUnk_36;
    c1 = p->mUnk_40->mUnk_72;
    k = (n->mUnk_2e_0 * (n->mUnk_2e_5 + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (n->mUnk_2e_10 << 24) | (p->mUnk_3c | 0xc0) | (k << 16);
    reg_G3_POLYGON_ATTR; // read back after the write
    if (k == 0) {
        return;
    }
    f1 = n->mUnk_30;
    f0 = ((s64) f1 * s + 0x800) >> 12;
    if (w == 0) {
        f0 = ((s64) f0 * h + 0x800) >> 12;
        f1 = ((s64) f1 * h + 0x800) >> 12;
    } else if (w == 1) {
        f0 = ((s64) f0 * h + 0x800) >> 12;
    } else {
        f1 = ((s64) f1 * h + 0x800) >> 12;
    }
    if (p->mUnk_40->mUnk_20->mUnk_00->mUnk_00.mUnk_00_23 == 0) {
        t.x = n->mUnk_08.x + n->mUnk_38.x;
        t.y = n->mUnk_08.y + n->mUnk_38.y;
        t.z = n->mUnk_08.z + n->mUnk_38.z;
        Vec3MultiplyMatrix4x3(&t, q, &t);
        t0 = data_0215d4b4[(n->mUnk_20 >> 4) * 2];
        t1 = data_0215d4b4[(n->mUnk_20 >> 4) * 2 + 1];
        m.mUnk_00[0].x = ((s64) t1 * f0 + 0x800) >> 12;
        m.mUnk_00[0].y = ((s64) t0 * f0 + 0x800) >> 12;
        m.mUnk_00[0].z = 0;
        m.mUnk_00[1].x = ((s64) -t0 * f1 + 0x800) >> 12;
        m.mUnk_00[1].y = ((s64) t1 * f1 + 0x800) >> 12;
        m.mUnk_00[1].z = 0;
        m.mUnk_00[2].x = 0;
        m.mUnk_00[2].y = 0;
        m.mUnk_00[2].z = 0x1000;
        m.mUnk_00[3].x = t.x;
        m.mUnk_00[3].y = t.y;
        m.mUnk_00[3].z = t.z;
        reg_G3_MTX_IDENTITY = 0;
        GxFifoWrite0x19Then12Words(&m);
    } else {
        t.x = n->mUnk_08.x + n->mUnk_38.x - p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.x;
        t.y = n->mUnk_08.y + n->mUnk_38.y - p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.y;
        t.z = n->mUnk_08.z + n->mUnk_38.z - p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.z;
        Vec3MultiplyMatrix4x3(&t, q, &t);
        t0 = data_0215d4b4[(n->mUnk_20 >> 4) * 2];
        t1 = data_0215d4b4[(n->mUnk_20 >> 4) * 2 + 1];
        m.mUnk_00[0].x = ((s64) t1 * f0 + 0x800) >> 12;
        m.mUnk_00[0].y = ((s64) t0 * f0 + 0x800) >> 12;
        m.mUnk_00[0].z = 0;
        m.mUnk_00[1].x = ((s64) -t0 * f1 + 0x800) >> 12;
        m.mUnk_00[1].y = ((s64) t1 * f1 + 0x800) >> 12;
        m.mUnk_00[1].z = 0;
        m.mUnk_00[2].x = 0;
        m.mUnk_00[2].y = 0;
        m.mUnk_00[2].z = 0x1000;
        m.mUnk_00[3].x = t.x;
        m.mUnk_00[3].y = t.y;
        m.mUnk_00[3].z = t.z;
        reg_G3_MTX_IDENTITY = 0;
        z = p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.z;
        y = p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.y;
        x = p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.x;
        reg_G3_MTX_TRANS = x;
        reg_G3_MTX_TRANS = y;
        reg_G3_MTX_TRANS = z;
        GxFifoWrite0x19Then12Words(&m);
    }
    reg_G3_COLOR = (u16) ((((c0 & 0x1f) * (c1 & 0x1f)) >> 5) | ((((c0 & 0x3e0) * (c1 & 0x3e0)) >> 15) << 5) |
                          ((((c0 & 0x7c00) * (c1 & 0x7c00)) >> 25) << 10));
    func_0201c690(p->mUnk_40->mUnk_78, p->mUnk_40->mUnk_7a, p->mUnk_40->mUnk_20->mUnk_00->mUnk_50,
                  p->mUnk_40->mUnk_20->mUnk_00->mUnk_52);
}

void func_0201bc48(Unk020184e4 *p, Unk0201e3c8 *n) {
    Vec3 t;
    Unk02012f58 m;
    s32 k;
    s32 f0;
    s32 f1;
    s32 t0;
    s32 t1;
    u16 c0;
    u16 c1;
    s32 x;
    s32 y;
    s32 z;
    s32 s;
    Unk02012f58 *q;

    s = p->mUnk_40->mUnk_20->mUnk_00->mUnk_30;
    q = p->mUnk_44;
    k = (n->mUnk_2e_0 * (n->mUnk_2e_5 + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (n->mUnk_2e_10 << 24) | (p->mUnk_3c | 0xc0) | (k << 16);
    reg_G3_POLYGON_ATTR; // read back after the write
    if (k == 0) {
        return;
    }
    f1 = n->mUnk_30;
    f0 = ((s64) f1 * s + 0x800) >> 12;
    switch (p->mUnk_40->mUnk_20->mUnk_00->mUnk_48.mUnk_00_28) {
        case 0:
            f0 = ((s64) f0 * n->mUnk_34 + 0x800) >> 12;
            f1 = ((s64) f1 * n->mUnk_34 + 0x800) >> 12;
            break;
        case 1:
            f0 = ((s64) f0 * n->mUnk_34 + 0x800) >> 12;
            break;
        case 2:
            f1 = ((s64) f1 * n->mUnk_34 + 0x800) >> 12;
            break;
    }
    if (p->mUnk_40->mUnk_20->mUnk_00->mUnk_00.mUnk_00_23 == 0) {
        t.x = n->mUnk_08.x + n->mUnk_38.x;
        t.y = n->mUnk_08.y + n->mUnk_38.y;
        t.z = n->mUnk_08.z + n->mUnk_38.z;
        Vec3MultiplyMatrix4x3(&t, q, &t);
        t0 = data_0215d4b4[(n->mUnk_20 >> 4) * 2];
        t1 = data_0215d4b4[(n->mUnk_20 >> 4) * 2 + 1];
        m.mUnk_00[0].x = ((s64) t1 * f0 + 0x800) >> 12;
        m.mUnk_00[0].y = ((s64) t0 * f0 + 0x800) >> 12;
        m.mUnk_00[0].z = 0;
        m.mUnk_00[1].x = ((s64) -t0 * f1 + 0x800) >> 12;
        m.mUnk_00[1].y = ((s64) t1 * f1 + 0x800) >> 12;
        m.mUnk_00[1].z = 0;
        m.mUnk_00[2].x = 0;
        m.mUnk_00[2].y = 0;
        m.mUnk_00[2].z = 0x1000;
        m.mUnk_00[3].x = t.x;
        m.mUnk_00[3].y = t.y;
        m.mUnk_00[3].z = t.z;
        reg_G3_MTX_IDENTITY = 0;
        GxFifoWrite0x19Then12Words(&m);
    } else {
        t.x = n->mUnk_08.x + n->mUnk_38.x - p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.x;
        t.y = n->mUnk_08.y + n->mUnk_38.y - p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.y;
        t.z = n->mUnk_08.z + n->mUnk_38.z - p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.z;
        Vec3MultiplyMatrix4x3(&t, q, &t);
        t0 = data_0215d4b4[(n->mUnk_20 >> 4) * 2];
        t1 = data_0215d4b4[(n->mUnk_20 >> 4) * 2 + 1];
        m.mUnk_00[0].x = ((s64) t1 * f0 + 0x800) >> 12;
        m.mUnk_00[0].y = ((s64) t0 * f0 + 0x800) >> 12;
        m.mUnk_00[0].z = 0;
        m.mUnk_00[1].x = ((s64) -t0 * f1 + 0x800) >> 12;
        m.mUnk_00[1].y = ((s64) t1 * f1 + 0x800) >> 12;
        m.mUnk_00[1].z = 0;
        m.mUnk_00[2].x = 0;
        m.mUnk_00[2].y = 0;
        m.mUnk_00[2].z = 0x1000;
        m.mUnk_00[3].x = t.x;
        m.mUnk_00[3].y = t.y;
        m.mUnk_00[3].z = t.z;
        reg_G3_MTX_IDENTITY = 0;
        z = p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.z;
        y = p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.y;
        x = p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.x;
        reg_G3_MTX_TRANS = x;
        reg_G3_MTX_TRANS = y;
        reg_G3_MTX_TRANS = z;
        GxFifoWrite0x19Then12Words(&m);
    }
    c0 = n->mUnk_36;
    c1 = p->mUnk_40->mUnk_72;
    reg_G3_COLOR = (u16) ((((c0 & 0x1f) * (c1 & 0x1f)) >> 5) | ((((c0 & 0x3e0) * (c1 & 0x3e0)) >> 15) << 5) |
                          ((((c0 & 0x7c00) * (c1 & 0x7c00)) >> 25) << 10));
    func_0201c690(p->mUnk_40->mUnk_7c, p->mUnk_40->mUnk_7e, 0, 0);
}

void func_0201b560(Unk020184e4 *p, Unk0201e3c8 *e) {
    Vec3 c;
    Vec3 pos;
    Vec3 v;
    Vec3 col;
    s32 m33[9];
    s32 buf[12];
    Unk02012f58 *m;
    s32 a;
    s32 h;
    s32 w;
    s32 t;
    s32 u;
    s32 x;
    u16 k;
    u16 q;
    s16 s;
    s32 i;
    s32 j;
    s32 n;

    m = p->mUnk_44;
    s = p->mUnk_40->mUnk_20->mUnk_00->mUnk_30;
    a = (e->mUnk_2e_0 * (e->mUnk_2e_5 + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (e->mUnk_2e_10 << 24) | (p->mUnk_3c | 0xc0) | (a << 16);
    reg_G3_POLYGON_ATTR; // read back after the write
    if (a == 0) {
        return;
    }
    w = e->mUnk_30;
    h = ((s64) w * s + 0x800) >> 12;
    switch (p->mUnk_40->mUnk_20->mUnk_00->mUnk_48.mUnk_00_28) {
        case 0:
            h = ((s64) h * e->mUnk_34 + 0x800) >> 12;
            w = ((s64) w * e->mUnk_34 + 0x800) >> 12;
            break;
        case 1:
            h = ((s64) h * e->mUnk_34 + 0x800) >> 12;
            break;
        case 2:
            w = ((s64) w * e->mUnk_34 + 0x800) >> 12;
            break;
    }
    if (!p->mUnk_40->mUnk_20->mUnk_00->mUnk_00.mUnk_00_23) {
        pos.x = e->mUnk_08.x + e->mUnk_38.x;
        pos.y = e->mUnk_08.y + e->mUnk_38.y;
        pos.z = e->mUnk_08.z + e->mUnk_38.z;
        v = e->mUnk_14;
        col.x = m->mUnk_00[0].z;
        col.y = m->mUnk_00[1].z;
        col.z = m->mUnk_00[2].z;
        Vec3Cross(&v, &col, &v);
        if (v.x == 0 && v.y == 0 && v.z == 0) {
            return;
        }
        Vec3Normalize(&v, &v);
        MemCopy9Words(m, m33);
        Vec3MultiplyMatrix3x3(&v, m33, &v);
        Vec3MultiplyMatrix4x3(&pos, m, &pos);
        c = e->mUnk_14;
        Vec3Normalize(&c, &c);
        t = (s32) (((s64) c.x * -m->mUnk_00[0].z + 0x800) >> 12) +
            (s32) (((s64) c.y * -m->mUnk_00[1].z + 0x800) >> 12) + (s32) (((s64) c.z * -m->mUnk_00[2].z + 0x800) >> 12);
        if (t < 0) {
            t = -t;
        }
        u = ((s64) (0x1000 - t) * (s32) p->mUnk_40->mUnk_20->mUnk_00->mUnk_48.mUnk_00_8 + 0x800) >> 12;
        x = ((s64) w * (u + 0x1000) + 0x800) >> 12;
        buf[0] = ((s64) v.x * h + 0x800) >> 12;
        buf[3] = ((s64) -v.y * x + 0x800) >> 12;
        buf[6] = 0;
        buf[9] = pos.x;
        buf[1] = ((s64) v.y * h + 0x800) >> 12;
        buf[4] = ((s64) v.x * x + 0x800) >> 12;
        buf[7] = 0;
        buf[10] = pos.y;
        buf[2] = 0;
        buf[5] = 0;
        buf[8] = 0x1000;
        buf[11] = pos.z;
        reg_G3_MTX_IDENTITY = 0;
        GxFifoWrite0x19Then12Words(buf);
    } else {
        pos.x = e->mUnk_08.x + e->mUnk_38.x - p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.x;
        pos.y = e->mUnk_08.y + e->mUnk_38.y - p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.y;
        pos.z = e->mUnk_08.z + e->mUnk_38.z - p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.z;
        v = e->mUnk_14;
        col.x = m->mUnk_00[0].z;
        col.y = m->mUnk_00[1].z;
        col.z = m->mUnk_00[2].z;
        Vec3Cross(&v, &col, &v);
        if (v.x == 0 && v.y == 0 && v.z == 0) {
            return;
        }
        Vec3Normalize(&v, &v);
        MemCopy9Words(m, m33);
        Vec3MultiplyMatrix3x3(&v, m33, &v);
        Vec3MultiplyMatrix4x3(&pos, m, &pos);
        c = e->mUnk_14;
        Vec3Normalize(&c, &c);
        t = (s32) (((s64) c.x * -m->mUnk_00[0].z + 0x800) >> 12) +
            (s32) (((s64) c.y * -m->mUnk_00[1].z + 0x800) >> 12) + (s32) (((s64) c.z * -m->mUnk_00[2].z + 0x800) >> 12);
        if (t < 0) {
            t = -t;
        }
        u = ((s64) (0x1000 - t) * (s32) p->mUnk_40->mUnk_20->mUnk_00->mUnk_48.mUnk_00_8 + 0x800) >> 12;
        x = ((s64) w * (u + 0x1000) + 0x800) >> 12;
        buf[0] = ((s64) v.x * h + 0x800) >> 12;
        buf[3] = ((s64) -v.y * x + 0x800) >> 12;
        buf[6] = 0;
        buf[9] = pos.x;
        buf[1] = ((s64) v.y * h + 0x800) >> 12;
        buf[4] = ((s64) v.x * x + 0x800) >> 12;
        buf[7] = 0;
        buf[10] = pos.y;
        buf[2] = 0;
        buf[5] = 0;
        buf[8] = 0x1000;
        buf[11] = pos.z;
        reg_G3_MTX_IDENTITY = 0;
        n = p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.z;
        j = p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.y;
        i = p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.x;
        reg_G3_MTX_TRANS = i;
        reg_G3_MTX_TRANS = j;
        reg_G3_MTX_TRANS = n;
        GxFifoWrite0x19Then12Words(buf);
    }
    q = e->mUnk_36;
    k = p->mUnk_40->mUnk_72;
    reg_G3_COLOR = (u16) ((((q & 0x1f) * (k & 0x1f)) >> 5) | ((((q & 0x3e0) * (k & 0x3e0)) >> 15) << 5) |
                          ((((q & 0x7c00) * (k & 0x7c00)) >> 25) << 10));
    func_0201c690(p->mUnk_40->mUnk_78, p->mUnk_40->mUnk_7a, p->mUnk_40->mUnk_20->mUnk_00->mUnk_50,
                  p->mUnk_40->mUnk_20->mUnk_00->mUnk_52);
}

void func_0201ae80(Unk020184e4 *p, Unk0201e3c8 *e) {
    Vec3 c;
    Vec3 pos;
    Vec3 v;
    Vec3 col;
    s32 m33[9];
    s32 buf[12];
    Unk02012f58 *m;
    s32 a;
    s32 h;
    s32 w;
    s32 t;
    s32 u;
    s32 x;
    u16 k;
    u16 q;
    s16 s;
    s32 i;
    s32 j;
    s32 n;

    m = p->mUnk_44;
    s = p->mUnk_40->mUnk_20->mUnk_00->mUnk_30;
    a = (e->mUnk_2e_0 * (e->mUnk_2e_5 + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (e->mUnk_2e_10 << 24) | (p->mUnk_3c | 0xc0) | (a << 16);
    reg_G3_POLYGON_ATTR; // read back after the write
    if (a == 0) {
        return;
    }
    w = e->mUnk_30;
    h = ((s64) w * s + 0x800) >> 12;
    switch (p->mUnk_40->mUnk_20->mUnk_00->mUnk_48.mUnk_00_28) {
        case 0:
            h = ((s64) h * e->mUnk_34 + 0x800) >> 12;
            w = ((s64) w * e->mUnk_34 + 0x800) >> 12;
            break;
        case 1:
            h = ((s64) h * e->mUnk_34 + 0x800) >> 12;
            break;
        case 2:
            w = ((s64) w * e->mUnk_34 + 0x800) >> 12;
            break;
    }
    if (!p->mUnk_40->mUnk_20->mUnk_00->mUnk_00.mUnk_00_23) {
        pos.x = e->mUnk_08.x + e->mUnk_38.x;
        pos.y = e->mUnk_08.y + e->mUnk_38.y;
        pos.z = e->mUnk_08.z + e->mUnk_38.z;
        v = e->mUnk_14;
        col.x = m->mUnk_00[0].z;
        col.y = m->mUnk_00[1].z;
        col.z = m->mUnk_00[2].z;
        Vec3Cross(&v, &col, &v);
        if (v.x == 0 && v.y == 0 && v.z == 0) {
            return;
        }
        Vec3Normalize(&v, &v);
        MemCopy9Words(m, m33);
        Vec3MultiplyMatrix3x3(&v, m33, &v);
        Vec3MultiplyMatrix4x3(&pos, m, &pos);
        c = e->mUnk_14;
        Vec3Normalize(&c, &c);
        t = (s32) (((s64) c.x * -m->mUnk_00[0].z + 0x800) >> 12) +
            (s32) (((s64) c.y * -m->mUnk_00[1].z + 0x800) >> 12) + (s32) (((s64) c.z * -m->mUnk_00[2].z + 0x800) >> 12);
        if (t < 0) {
            t = -t;
        }
        u = ((s64) (0x1000 - t) * (s32) p->mUnk_40->mUnk_20->mUnk_00->mUnk_48.mUnk_00_8 + 0x800) >> 12;
        x = ((s64) w * (u + 0x1000) + 0x800) >> 12;
        buf[0] = ((s64) v.x * h + 0x800) >> 12;
        buf[3] = ((s64) -v.y * x + 0x800) >> 12;
        buf[6] = 0;
        buf[9] = pos.x;
        buf[1] = ((s64) v.y * h + 0x800) >> 12;
        buf[4] = ((s64) v.x * x + 0x800) >> 12;
        buf[7] = 0;
        buf[10] = pos.y;
        buf[2] = 0;
        buf[5] = 0;
        buf[8] = 0x1000;
        buf[11] = pos.z;
        reg_G3_MTX_IDENTITY = 0;
        GxFifoWrite0x19Then12Words(buf);
    } else {
        pos.x = e->mUnk_08.x + e->mUnk_38.x - p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.x;
        pos.y = e->mUnk_08.y + e->mUnk_38.y - p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.y;
        pos.z = e->mUnk_08.z + e->mUnk_38.z - p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.z;
        v = e->mUnk_14;
        col.x = m->mUnk_00[0].z;
        col.y = m->mUnk_00[1].z;
        col.z = m->mUnk_00[2].z;
        Vec3Cross(&v, &col, &v);
        if (v.x == 0 && v.y == 0 && v.z == 0) {
            return;
        }
        Vec3Normalize(&v, &v);
        MemCopy9Words(m, m33);
        Vec3MultiplyMatrix3x3(&v, m33, &v);
        Vec3MultiplyMatrix4x3(&pos, m, &pos);
        c = e->mUnk_14;
        Vec3Normalize(&c, &c);
        t = (s32) (((s64) c.x * -m->mUnk_00[0].z + 0x800) >> 12) +
            (s32) (((s64) c.y * -m->mUnk_00[1].z + 0x800) >> 12) + (s32) (((s64) c.z * -m->mUnk_00[2].z + 0x800) >> 12);
        if (t < 0) {
            t = -t;
        }
        u = ((s64) (0x1000 - t) * (s32) p->mUnk_40->mUnk_20->mUnk_00->mUnk_48.mUnk_00_8 + 0x800) >> 12;
        x = ((s64) w * (u + 0x1000) + 0x800) >> 12;
        buf[0] = ((s64) v.x * h + 0x800) >> 12;
        buf[3] = ((s64) -v.y * x + 0x800) >> 12;
        buf[6] = 0;
        buf[9] = pos.x;
        buf[1] = ((s64) v.y * h + 0x800) >> 12;
        buf[4] = ((s64) v.x * x + 0x800) >> 12;
        buf[7] = 0;
        buf[10] = pos.y;
        buf[2] = 0;
        buf[5] = 0;
        buf[8] = 0x1000;
        buf[11] = pos.z;
        reg_G3_MTX_IDENTITY = 0;
        n = p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.z;
        j = p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.y;
        i = p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.x;
        reg_G3_MTX_TRANS = i;
        reg_G3_MTX_TRANS = j;
        reg_G3_MTX_TRANS = n;
        GxFifoWrite0x19Then12Words(buf);
    }
    q = e->mUnk_36;
    k = p->mUnk_40->mUnk_72;
    reg_G3_COLOR = (u16) ((((q & 0x1f) * (k & 0x1f)) >> 5) | ((((q & 0x3e0) * (k & 0x3e0)) >> 15) << 5) |
                          ((((q & 0x7c00) * (k & 0x7c00)) >> 25) << 10));
    func_0201c690(p->mUnk_40->mUnk_7c, p->mUnk_40->mUnk_7e, 0, 0);
}

void func_0201ab30(Unk020184e4 *p, Unk0201e3c8 *n) {
    Unk02012f58 a;
    Unk02012f58 b;
    Unk02012f58 c;
    s32 k;
    s32 f0;
    s32 f1;
    u16 c0;
    u16 c1;
    s32 x;
    s32 y;
    s32 z;

    k = (n->mUnk_2e_0 * (n->mUnk_2e_5 + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (n->mUnk_2e_10 << 24) | (p->mUnk_3c | 0xc0) | (k << 16);
    reg_G3_POLYGON_ATTR; // read back after the write
    if (k == 0) {
        return;
    }
    data_02161ac8[p->mUnk_40->mUnk_20->mUnk_00->mUnk_00.mUnk_00_17](data_0215d4b4[(n->mUnk_20 >> 4) * 2],
                                                                    data_0215d4b4[(n->mUnk_20 >> 4) * 2 + 1], &b);
    f1 = n->mUnk_30;
    f0 = ((s64) f1 * p->mUnk_40->mUnk_20->mUnk_00->mUnk_30 + 0x800) >> 12;
    switch (p->mUnk_40->mUnk_20->mUnk_00->mUnk_48.mUnk_00_28) {
        case 0:
            f0 = ((s64) f0 * n->mUnk_34 + 0x800) >> 12;
            f1 = ((s64) f1 * n->mUnk_34 + 0x800) >> 12;
            break;
        case 1:
            f0 = ((s64) f0 * n->mUnk_34 + 0x800) >> 12;
            break;
        case 2:
            f1 = ((s64) f1 * n->mUnk_34 + 0x800) >> 12;
            break;
    }
    Matrix4x3FromDiagonal(&c, f0, f1, f1);
    Matrix4x3Multiply(&c, &b, &a);
    if (p->mUnk_40->mUnk_20->mUnk_00->mUnk_00.mUnk_00_23 == 0) {
        a.mUnk_00[3].x = n->mUnk_08.x + n->mUnk_38.x;
        a.mUnk_00[3].y = n->mUnk_08.y + n->mUnk_38.y;
        a.mUnk_00[3].z = n->mUnk_08.z + n->mUnk_38.z;
        GxFifoWrite0x17Then12Words(p->mUnk_44);
        GxFifoWrite0x19Then12Words(&a);
    } else {
        a.mUnk_00[3].x = n->mUnk_08.x + n->mUnk_38.x - p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.x;
        a.mUnk_00[3].y = n->mUnk_08.y + n->mUnk_38.y - p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.y;
        a.mUnk_00[3].z = n->mUnk_08.z + n->mUnk_38.z - p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.z;
        reg_G3_MTX_IDENTITY = 0;
        z = p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.z;
        y = p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.y;
        x = p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.x;
        reg_G3_MTX_TRANS = x;
        reg_G3_MTX_TRANS = y;
        reg_G3_MTX_TRANS = z;
        GxFifoWrite0x19Then12Words(p->mUnk_44);
        GxFifoWrite0x19Then12Words(&a);
    }
    c0 = n->mUnk_36;
    c1 = p->mUnk_40->mUnk_72;
    reg_G3_COLOR = (u16) ((((c0 & 0x1f) * (c1 & 0x1f)) >> 5) | ((((c0 & 0x3e0) * (c1 & 0x3e0)) >> 15) << 5) |
                          ((((c0 & 0x7c00) * (c1 & 0x7c00)) >> 25) << 10));
    data_02161ac0[p->mUnk_40->mUnk_20->mUnk_00->mUnk_00.mUnk_00_19](p->mUnk_40->mUnk_78, p->mUnk_40->mUnk_7a,
                                                                    p->mUnk_40->mUnk_20->mUnk_00->mUnk_50,
                                                                    p->mUnk_40->mUnk_20->mUnk_00->mUnk_52);
}

void func_0201a7e0(Unk020184e4 *p, Unk0201e3c8 *n) {
    Unk02012f58 a;
    Unk02012f58 b;
    Unk02012f58 c;
    s32 k;
    s32 f0;
    s32 f1;
    u16 c0;
    u16 c1;
    s32 x;
    s32 y;
    s32 z;

    k = (n->mUnk_2e_0 * (n->mUnk_2e_5 + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (n->mUnk_2e_10 << 24) | (p->mUnk_3c | 0xc0) | (k << 16);
    reg_G3_POLYGON_ATTR; // read back after the write
    if (k == 0) {
        return;
    }
    data_02161ac8[p->mUnk_40->mUnk_20->mUnk_14->mUnk_00_9](data_0215d4b4[(n->mUnk_20 >> 4) * 2],
                                                           data_0215d4b4[(n->mUnk_20 >> 4) * 2 + 1], &b);
    f1 = n->mUnk_30;
    f0 = ((s64) f1 * p->mUnk_40->mUnk_20->mUnk_00->mUnk_30 + 0x800) >> 12;
    switch (p->mUnk_40->mUnk_20->mUnk_00->mUnk_48.mUnk_00_28) {
        case 0:
            f0 = ((s64) f0 * n->mUnk_34 + 0x800) >> 12;
            f1 = ((s64) f1 * n->mUnk_34 + 0x800) >> 12;
            break;
        case 1:
            f0 = ((s64) f0 * n->mUnk_34 + 0x800) >> 12;
            break;
        case 2:
            f1 = ((s64) f1 * n->mUnk_34 + 0x800) >> 12;
            break;
    }
    Matrix4x3FromDiagonal(&c, f0, f1, f1);
    Matrix4x3Multiply(&b, &c, &a);
    if (p->mUnk_40->mUnk_20->mUnk_00->mUnk_00.mUnk_00_23 == 0) {
        a.mUnk_00[3].x = n->mUnk_08.x + n->mUnk_38.x;
        a.mUnk_00[3].y = n->mUnk_08.y + n->mUnk_38.y;
        a.mUnk_00[3].z = n->mUnk_08.z + n->mUnk_38.z;
        GxFifoWrite0x17Then12Words(p->mUnk_44);
        GxFifoWrite0x19Then12Words(&a);
    } else {
        a.mUnk_00[3].x = n->mUnk_08.x + n->mUnk_38.x - p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.x;
        a.mUnk_00[3].y = n->mUnk_08.y + n->mUnk_38.y - p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.y;
        a.mUnk_00[3].z = n->mUnk_08.z + n->mUnk_38.z - p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.z;
        reg_G3_MTX_IDENTITY = 0;
        z = p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.z;
        y = p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.y;
        x = p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.x;
        reg_G3_MTX_TRANS = x;
        reg_G3_MTX_TRANS = y;
        reg_G3_MTX_TRANS = z;
        GxFifoWrite0x19Then12Words(p->mUnk_44);
        GxFifoWrite0x19Then12Words(&a);
    }
    c0 = n->mUnk_36;
    c1 = p->mUnk_40->mUnk_72;
    reg_G3_COLOR = (u16) ((((c0 & 0x1f) * (c1 & 0x1f)) >> 5) | ((((c0 & 0x3e0) * (c1 & 0x3e0)) >> 15) << 5) |
                          ((((c0 & 0x7c00) * (c1 & 0x7c00)) >> 25) << 10));
    data_02161ac0[p->mUnk_40->mUnk_20->mUnk_14->mUnk_00_11](p->mUnk_40->mUnk_7c, p->mUnk_40->mUnk_7e, 0, 0);
}

void func_0201a364(Unk020184e4 *p, Unk0201e3c8 *n) {
    Unk02012f58 a;
    Unk02012f58 b;
    Unk02012f58 c;
    Vec3 v;
    Vec3 u;
    Vec3 w;
    Vec3 e;
    Unk02012f58 d;
    s32 k;
    s32 f0;
    s32 f1;
    s32 s;
    u16 c0;
    u16 c1;
    s32 x;
    s32 y;
    s32 z;

    k = (n->mUnk_2e_0 * (n->mUnk_2e_5 + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (n->mUnk_2e_10 << 24) | (p->mUnk_3c | 0xc0) | (k << 16);
    reg_G3_POLYGON_ATTR; // read back after the write
    if (k == 0) {
        return;
    }
    data_02161ac8[p->mUnk_40->mUnk_20->mUnk_00->mUnk_00.mUnk_00_17](data_0215d4b4[(n->mUnk_20 >> 4) * 2],
                                                                    data_0215d4b4[(n->mUnk_20 >> 4) * 2 + 1], &b);
    Matrix4x3Identity(&d);
    if (p->mUnk_40->mUnk_20->mUnk_00->mUnk_48.mUnk_00_31 == 0) {
        Vec3Normalize(&n->mUnk_14, &v);
    } else {
        Vec3Normalize(&n->mUnk_08, &v);
        v.x = -v.x;
        v.y = -v.y;
        v.z = -v.z;
    }
    e.x = 0;
    e.y = 0x1000;
    e.z = 0;
    s = Vec3Dot(&v, &e);
    if (s > 0xccd || s < -0xccd) {
        e.x = 0x1000;
        e.y = 0;
        e.z = 0;
    }
    Vec3Cross(&v, &e, &u);
    Vec3Cross(&v, &u, &w);
    d.mUnk_00[0].x = u.x;
    d.mUnk_00[0].y = u.y;
    d.mUnk_00[0].z = u.z;
    d.mUnk_00[1].x = v.x;
    d.mUnk_00[1].y = v.y;
    d.mUnk_00[1].z = v.z;
    d.mUnk_00[2].x = w.x;
    d.mUnk_00[2].y = w.y;
    d.mUnk_00[2].z = w.z;
    Matrix4x3Multiply(&b, &d, &b);
    f1 = n->mUnk_30;
    f0 = ((s64) f1 * p->mUnk_40->mUnk_20->mUnk_00->mUnk_30 + 0x800) >> 12;
    switch (p->mUnk_40->mUnk_20->mUnk_00->mUnk_48.mUnk_00_28) {
        case 0:
            f0 = ((s64) f0 * n->mUnk_34 + 0x800) >> 12;
            f1 = ((s64) f1 * n->mUnk_34 + 0x800) >> 12;
            break;
        case 1:
            f0 = ((s64) f0 * n->mUnk_34 + 0x800) >> 12;
            break;
        case 2:
            f1 = ((s64) f1 * n->mUnk_34 + 0x800) >> 12;
            break;
    }
    Matrix4x3FromDiagonal(&c, f0, f1, f1);
    Matrix4x3Multiply(&c, &b, &a);
    if (p->mUnk_40->mUnk_20->mUnk_00->mUnk_00.mUnk_00_23 == 0) {
        a.mUnk_00[3].x = n->mUnk_08.x + n->mUnk_38.x;
        a.mUnk_00[3].y = n->mUnk_08.y + n->mUnk_38.y;
        a.mUnk_00[3].z = n->mUnk_08.z + n->mUnk_38.z;
        GxFifoWrite0x17Then12Words(p->mUnk_44);
        GxFifoWrite0x19Then12Words(&a);
    } else {
        a.mUnk_00[3].x = n->mUnk_08.x + n->mUnk_38.x - p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.x;
        a.mUnk_00[3].y = n->mUnk_08.y + n->mUnk_38.y - p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.y;
        a.mUnk_00[3].z = n->mUnk_08.z + n->mUnk_38.z - p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.z;
        reg_G3_MTX_IDENTITY = 0;
        z = p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.z;
        y = p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.y;
        x = p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.x;
        reg_G3_MTX_TRANS = x;
        reg_G3_MTX_TRANS = y;
        reg_G3_MTX_TRANS = z;
        GxFifoWrite0x19Then12Words(p->mUnk_44);
        GxFifoWrite0x19Then12Words(&a);
    }
    c0 = n->mUnk_36;
    c1 = p->mUnk_40->mUnk_72;
    reg_G3_COLOR = (u16) ((((c0 & 0x1f) * (c1 & 0x1f)) >> 5) | ((((c0 & 0x3e0) * (c1 & 0x3e0)) >> 15) << 5) |
                          ((((c0 & 0x7c00) * (c1 & 0x7c00)) >> 25) << 10));
    data_02161ac0[p->mUnk_40->mUnk_20->mUnk_00->mUnk_00.mUnk_00_19](p->mUnk_40->mUnk_78, p->mUnk_40->mUnk_7a,
                                                                    p->mUnk_40->mUnk_20->mUnk_00->mUnk_50,
                                                                    p->mUnk_40->mUnk_20->mUnk_00->mUnk_52);
}

void func_02019ee4(Unk020184e4 *p, Unk0201e3c8 *n) {
    Unk02012f58 a;
    Unk02012f58 b;
    Unk02012f58 c;
    Vec3 v;
    Vec3 u;
    Vec3 w;
    Vec3 e;
    Unk02012f58 d;
    s32 k;
    s32 f0;
    s32 f1;
    s32 s;
    u16 c0;
    u16 c1;
    s32 x;
    s32 y;
    s32 z;

    k = (n->mUnk_2e_0 * (n->mUnk_2e_5 + 1)) >> 5;
    reg_G3_POLYGON_ATTR = (n->mUnk_2e_10 << 24) | (p->mUnk_3c | 0xc0) | (k << 16);
    reg_G3_POLYGON_ATTR; // read back after the write
    if (k == 0) {
        return;
    }
    data_02161ac8[p->mUnk_40->mUnk_20->mUnk_14->mUnk_00_9](data_0215d4b4[(n->mUnk_20 >> 4) * 2],
                                                           data_0215d4b4[(n->mUnk_20 >> 4) * 2 + 1], &b);
    Matrix4x3Identity(&d);
    if (p->mUnk_40->mUnk_20->mUnk_14->mUnk_10.mUnk_00_6 == 0) {
        Vec3Normalize(&n->mUnk_14, &v);
    } else {
        Vec3Normalize(&n->mUnk_08, &v);
        v.x = -v.x;
        v.y = -v.y;
        v.z = -v.z;
    }
    e.x = 0;
    e.y = 0x1000;
    e.z = 0;
    s = Vec3Dot(&v, &e);
    if (s > 0xccd || s < -0xccd) {
        e.x = 0x1000;
        e.y = 0;
        e.z = 0;
    }
    Vec3Cross(&v, &e, &u);
    Vec3Cross(&v, &u, &w);
    d.mUnk_00[0].x = u.x;
    d.mUnk_00[0].y = u.y;
    d.mUnk_00[0].z = u.z;
    d.mUnk_00[1].x = v.x;
    d.mUnk_00[1].y = v.y;
    d.mUnk_00[1].z = v.z;
    d.mUnk_00[2].x = w.x;
    d.mUnk_00[2].y = w.y;
    d.mUnk_00[2].z = w.z;
    Matrix4x3Multiply(&b, &d, &b);
    f1 = n->mUnk_30;
    f0 = ((s64) f1 * p->mUnk_40->mUnk_20->mUnk_00->mUnk_30 + 0x800) >> 12;
    switch (p->mUnk_40->mUnk_20->mUnk_00->mUnk_48.mUnk_00_28) {
        case 0:
            f0 = ((s64) f0 * n->mUnk_34 + 0x800) >> 12;
            f1 = ((s64) f1 * n->mUnk_34 + 0x800) >> 12;
            break;
        case 1:
            f0 = ((s64) f0 * n->mUnk_34 + 0x800) >> 12;
            break;
        case 2:
            f1 = ((s64) f1 * n->mUnk_34 + 0x800) >> 12;
            break;
    }
    Matrix4x3FromDiagonal(&c, f0, f1, f1);
    Matrix4x3Multiply(&b, &c, &a);
    if (p->mUnk_40->mUnk_20->mUnk_00->mUnk_00.mUnk_00_23 == 0) {
        a.mUnk_00[3].x = n->mUnk_08.x + n->mUnk_38.x;
        a.mUnk_00[3].y = n->mUnk_08.y + n->mUnk_38.y;
        a.mUnk_00[3].z = n->mUnk_08.z + n->mUnk_38.z;
        GxFifoWrite0x17Then12Words(p->mUnk_44);
        GxFifoWrite0x19Then12Words(&a);
    } else {
        a.mUnk_00[3].x = n->mUnk_08.x + n->mUnk_38.x - p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.x;
        a.mUnk_00[3].y = n->mUnk_08.y + n->mUnk_38.y - p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.y;
        a.mUnk_00[3].z = n->mUnk_08.z + n->mUnk_38.z - p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.z;
        reg_G3_MTX_IDENTITY = 0;
        z = p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.z;
        y = p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.y;
        x = p->mUnk_40->mUnk_20->mUnk_00->mUnk_04.x;
        reg_G3_MTX_TRANS = x;
        reg_G3_MTX_TRANS = y;
        reg_G3_MTX_TRANS = z;
        GxFifoWrite0x19Then12Words(p->mUnk_44);
        GxFifoWrite0x19Then12Words(&a);
    }
    c0 = n->mUnk_36;
    c1 = p->mUnk_40->mUnk_72;
    reg_G3_COLOR = (u16) ((((c0 & 0x1f) * (c1 & 0x1f)) >> 5) | ((((c0 & 0x3e0) * (c1 & 0x3e0)) >> 15) << 5) |
                          ((((c0 & 0x7c00) * (c1 & 0x7c00)) >> 25) << 10));
    data_02161ac0[p->mUnk_40->mUnk_20->mUnk_14->mUnk_00_11](p->mUnk_40->mUnk_7c, p->mUnk_40->mUnk_7e, 0, 0);
}

typedef enum { UNK_02019DF8_KIND_0 } Unk02019df8_Kind;

static inline void func_02019df8_inline(u32 addr, Unk02019df8_Kind b0, Unk02019df8_Kind b4, Unk02019df8_Kind b8,
                                        Unk02019df8_Kind b12, Unk02019df8_Kind b14, Unk02019df8_Kind b16) {
    reg_G3_TEXIMAGE_PARAM =
        (addr >> 3) | (b0 << 26) | 0x40000000 | (b4 << 20) | (b8 << 23) | (b12 << 16) | (b14 << 18) | (b16 << 29);
}

void func_02019df8(Unk020184e4_2c *a) {
    Unk020184e4_2c_0c w;
    u32 sx;
    u32 sy;

    w = a->mUnk_0c;
    func_02019df8_inline(a->mUnk_04, w.mUnk_00_0, w.mUnk_00_4, w.mUnk_00_8, w.mUnk_00_12, w.mUnk_00_14, w.mUnk_00_16);
    reg_G3_PLTT_BASE = a->mUnk_08 >> (4 - (w.mUnk_00_0 == 2 ? 1 : 0));
    reg_G3_MTX_MODE = 3;
    reg_G3_MTX_IDENTITY = 0;
    sx = a->mUnk_10 << 12;
    sy = a->mUnk_12 << 12;
    reg_G3_MTX_SCALE = sx;
    reg_G3_MTX_SCALE = sy;
    reg_G3_MTX_SCALE = 0;
    reg_G3_MTX_MODE = 1;
}

void func_02019df4(Unk020184e4_2c *a) {}

void func_02019b28(Unk0201ca6c *p, Unk0201ca6c_20 *c, Vec3 *pos) {
    Unk0201ca6c_20_00 *d;

    p->mUnk_20 = c;
    *(u32 *) &p->mUnk_24 = 0;
    p->mUnk_28.x = pos->x + p->mUnk_20->mUnk_00->mUnk_04.x;
    p->mUnk_28.y = pos->y + p->mUnk_20->mUnk_00->mUnk_04.y;
    p->mUnk_28.z = pos->z + p->mUnk_20->mUnk_00->mUnk_04.z;
    p->mUnk_40.x = 0;
    p->mUnk_40.y = 0;
    p->mUnk_40.z = 0;
    p->mUnk_34.x = p->mUnk_34.y = p->mUnk_34.z = 0;
    p->mUnk_4c = 0;
    p->mUnk_4e = 0;
    d = p->mUnk_20->mUnk_00;
    p->mUnk_50 = d->mUnk_1c;
    p->mUnk_56 = p->mUnk_20->mUnk_00->mUnk_38;
    p->mUnk_58 = p->mUnk_20->mUnk_00->mUnk_10;
    p->mUnk_5c = p->mUnk_20->mUnk_00->mUnk_14;
    p->mUnk_60 = p->mUnk_20->mUnk_00->mUnk_18;
    p->mUnk_64 = p->mUnk_20->mUnk_00->mUnk_24;
    p->mUnk_68 = p->mUnk_20->mUnk_00->mUnk_28;
    p->mUnk_6c = p->mUnk_20->mUnk_00->mUnk_2c;
    p->mUnk_70 = p->mUnk_20->mUnk_00->mUnk_3e;
    p->mUnk_72 = 0x7fff;
    p->mUnk_80_0 = p->mUnk_20->mUnk_00->mUnk_44;
    p->mUnk_80_8 = p->mUnk_20->mUnk_00->mUnk_45;
    p->mUnk_80_16 = 0;
    p->mUnk_80_19 = 0;
    p->mUnk_74 = 0x80000000;
    p->mUnk_78 = 0x1000 << p->mUnk_20->mUnk_00->mUnk_48.mUnk_00_24;
    p->mUnk_7a = 0x1000 << p->mUnk_20->mUnk_00->mUnk_48.mUnk_00_26;
    if (p->mUnk_20->mUnk_00->mUnk_4c_0) {
        p->mUnk_78 *= -1;
    }
    if (p->mUnk_20->mUnk_00->mUnk_4c_1) {
        p->mUnk_7a *= -1;
    }
    if (p->mUnk_20->mUnk_00->mUnk_00.mUnk_00_16) {
        p->mUnk_7c = 0x1000 << p->mUnk_20->mUnk_14->mUnk_10.mUnk_00_0;
        p->mUnk_7e = 0x1000 << p->mUnk_20->mUnk_14->mUnk_10.mUnk_00_2;
        if (p->mUnk_20->mUnk_14->mUnk_10.mUnk_00_4) {
            p->mUnk_7c *= -1;
        }
        if (p->mUnk_20->mUnk_14->mUnk_10.mUnk_00_5) {
            p->mUnk_7e *= -1;
        }
    }
    p->mUnk_00 = p->mUnk_04 = 0;
    p->mUnk_08.mUnk_00 = p->mUnk_14.mUnk_00 = 0;
    p->mUnk_08.mUnk_04 = p->mUnk_14.mUnk_04 = 0;
    p->mUnk_90 = 0;
    p->mUnk_94 = 0;
    p->mUnk_98 = 0;
}

void func_020192e0(Unk020184e4 *a, Unk0201ca6c *p) {
    Unk0201ca6c_20 *c;
    s32 cnt;
    Unk0201e3c8 *n0;
    s32 i;
    s32 n;
    Unk0201e3c8 *next;
    Unk0201ca6c_20_14 *e;
    Unk0201ca6c_20_00 *d;
    Unk0201ca6c_20_00_00 flags;
    s32 k0;
    s32 t;
    u8 b[2];
    Unk020192e0_28 tbl[4];
    Unk020192e0_28 tbl2[4];
    Vec3 v;

    c = p->mUnk_20;
    e = c->mUnk_14;
    d = c->mUnk_00;
    flags = d->mUnk_00;
    n = 0;
    k0 = d->mUnk_46 + 0x180;
    cnt = c->mUnk_1c;

    if (p->mUnk_90) {
        p->mUnk_90(p, 0);
    }

    if (d->mUnk_3c == 0 || p->mUnk_4c < d->mUnk_3c) {
        if (p->mUnk_4c % p->mUnk_80_0 == 0 && !p->mUnk_24.mUnk_00_0 && !p->mUnk_24.mUnk_00_1 && p->mUnk_24.mUnk_00_4) {
            func_0201ca6c(p, &a->mUnk_04[2]);
        }
    }

    if (flags.mUnk_00_8) {
        tbl[n].mUnk_00 = func_0201df30;
        tbl[n++].mUnk_04 = c->mUnk_04->mUnk_08_0;
    }
    if (flags.mUnk_00_9 && !c->mUnk_08->mUnk_08_0) {
        tbl[n].mUnk_00 = func_0201dd64;
        tbl[n++].mUnk_04 = c->mUnk_08->mUnk_08_1;
    }
    if (flags.mUnk_00_10) {
        tbl[n].mUnk_00 = func_0201dc88;
        tbl[n++].mUnk_04 = c->mUnk_0c->mUnk_02_8;
    }
    if (flags.mUnk_00_11 && !c->mUnk_10->mUnk_08_16) {
        tbl[n].mUnk_00 = func_0201dc24;
        tbl[n++].mUnk_04 = c->mUnk_10->mUnk_08_17;
    }

    for (n0 = p->mUnk_08.mUnk_00; n0; n0 = next) {
        next = n0->mUnk_00;
        b[0] = (n0->mUnk_2a * n0->mUnk_26) >> 8;
        b[1] = n0->mUnk_2d + ((n0->mUnk_28 * n0->mUnk_26) >> 8);
        for (i = 0; i < n; i++) {
            tbl[i].mUnk_00(n0, c, b[tbl[i].mUnk_04]);
        }
        v.x = v.y = v.z = 0;
        if (flags.mUnk_00_15) {
            n0->mUnk_38 = p->mUnk_28;
        }
        for (i = 0; i < cnt; i++) {
            c->mUnk_18[i].mUnk_00(c->mUnk_18[i].mUnk_04, n0, &v, p);
        }
        n0->mUnk_20 += n0->mUnk_22;
        n0->mUnk_14.x = (n0->mUnk_14.x * k0) >> 9;
        n0->mUnk_14.y = (n0->mUnk_14.y * k0) >> 9;
        n0->mUnk_14.z = (n0->mUnk_14.z * k0) >> 9;
        n0->mUnk_14.x += v.x;
        n0->mUnk_14.y += v.y;
        n0->mUnk_14.z += v.z;
        n0->mUnk_08.x += n0->mUnk_14.x + p->mUnk_34.x;
        n0->mUnk_08.y += n0->mUnk_14.y + p->mUnk_34.y;
        n0->mUnk_08.z += n0->mUnk_14.z + p->mUnk_34.z;
        if (flags.mUnk_00_16) {
            t = (n0->mUnk_26 << 12) - ((s32) (((s64) (n0->mUnk_24 << 12) * (e->mUnk_0d << 12) + 0x800) >> 12) >> 8);
            if (t >= 0 && (t >> 12) % e->mUnk_0e == 0) {
                func_0201c74c(n0, p, &a->mUnk_04[2]);
            }
        }
        if (p->mUnk_20->mUnk_00->mUnk_00.mUnk_00_30) {
            n0->mUnk_2e_10 = (u16) a->mUnk_38_18;
        } else {
            n0->mUnk_2e_10 = (u16) a->mUnk_38_12;
            a->mUnk_38_12++;
            if (a->mUnk_38_12 > a->mUnk_38_6) {
                a->mUnk_38_12 = a->mUnk_38_0;
            }
        }
        n0->mUnk_26++;
        if (n0->mUnk_26 > n0->mUnk_24) {
            func_0201e494(&a->mUnk_04[2], func_0201e3c8(&p->mUnk_08, n0));
        }
    }

    if (flags.mUnk_00_16) {
        n = 0;
        if (e->mUnk_00_1) {
            tbl2[n].mUnk_00 = func_0201dbd8;
            tbl2[n++].mUnk_04 = 0;
        }
        if (e->mUnk_00_2) {
            tbl2[n].mUnk_00 = func_0201db80;
            tbl2[n++].mUnk_04 = 0;
        }
        if (!e->mUnk_00_0) {
            cnt = 0;
        }
        for (n0 = p->mUnk_14.mUnk_00; n0; n0 = next) {
            next = n0->mUnk_00;
            b[0] = (n0->mUnk_26 << 8) / n0->mUnk_24;
            for (i = 0; i < n; i++) {
                tbl2[i].mUnk_00(n0, c, b[0]);
            }
            v.x = v.y = v.z = 0;
            if (e->mUnk_00_5) {
                n0->mUnk_38 = p->mUnk_28;
            }
            for (i = 0; i < cnt; i++) {
                c->mUnk_18[i].mUnk_00(c->mUnk_18[i].mUnk_04, n0, &v, p);
            }
            n0->mUnk_20 += n0->mUnk_22;
            n0->mUnk_14.x = (n0->mUnk_14.x * k0) >> 9;
            n0->mUnk_14.y = (n0->mUnk_14.y * k0) >> 9;
            n0->mUnk_14.z = (n0->mUnk_14.z * k0) >> 9;
            n0->mUnk_14.x += v.x;
            n0->mUnk_14.y += v.y;
            n0->mUnk_14.z += v.z;
            n0->mUnk_08.x += n0->mUnk_14.x + p->mUnk_34.x;
            n0->mUnk_08.y += n0->mUnk_14.y + p->mUnk_34.y;
            n0->mUnk_08.z += n0->mUnk_14.z + p->mUnk_34.z;
            if (p->mUnk_20->mUnk_00->mUnk_00.mUnk_00_31) {
                n0->mUnk_2e_10 = (u16) a->mUnk_38_18;
            } else {
                n0->mUnk_2e_10 = (u16) a->mUnk_38_12;
                a->mUnk_38_12++;
                if (a->mUnk_38_12 > a->mUnk_38_6) {
                    a->mUnk_38_12 = a->mUnk_38_0;
                }
            }
            n0->mUnk_26++;
            if (n0->mUnk_26 > n0->mUnk_24) {
                func_0201e494(&a->mUnk_04[2], func_0201e3c8(&p->mUnk_14, n0));
            }
        }
    }

    p->mUnk_4c++;
    if (p->mUnk_90) {
        p->mUnk_90(p, 1);
    }
}

void func_020191f4(Unk020184e4 *a) {
    Unk0201ca6c *n;
    Unk0201ca6c_20_00 *d;
    void (*f)(Unk020184e4 *a, Unk0201e3c8 *b);
    void (*g)(Unk020184e4_2c *a);
    Unk0201e3c8 *e;

    n = a->mUnk_40;
    d = n->mUnk_20->mUnk_00;
    f = 0;
    func_02019df8(a->mUnk_2c + d->mUnk_47);
    switch (d->mUnk_00.mUnk_00_4) {
        case 0:
            f = func_0201c09c;
            break;
        case 1:
            f = func_0201b560;
            break;
        case 2:
            f = func_0201ab30;
            break;
        case 3:
            f = func_0201a364;
            break;
        case 4:
            f = func_0201a364;
            break;
    }
    if (d->mUnk_00.mUnk_00_11) {
        g = func_02019df8;
    } else {
        g = func_02019df4;
    }
    for (e = n->mUnk_08.mUnk_00; e != 0; e = e->mUnk_00) {
        g(a->mUnk_2c + e->mUnk_2c);
        f(a, e);
    }
}

void func_0201910c(Unk020184e4 *a) {
    Unk0201ca6c *n;
    Unk0201ca6c_20 *c;
    void (*f)(Unk020184e4 *a, Unk0201e3c8 *b);
    Unk0201e3c8 *e;

    n = a->mUnk_40;
    f = 0;
    c = n->mUnk_20;
    if (c->mUnk_00->mUnk_00.mUnk_00_16 == 0) {
        return;
    }
    func_02019df8(a->mUnk_2c + c->mUnk_14->mUnk_0f);
    switch (c->mUnk_14->mUnk_00_7) {
        case 0:
            f = func_0201bc48;
            break;
        case 1:
            f = func_0201ae80;
            break;
        case 2:
            f = func_0201a7e0;
            break;
        case 3:
            f = func_02019ee4;
            break;
        case 4:
            f = func_02019ee4;
            break;
    }
    for (e = n->mUnk_14.mUnk_00; e != 0; e = e->mUnk_00) {
        f(a, e);
    }
}

void func_02019090(Unk020184e4 *a) {
    Unk0201ca6c_20_00 *d;

    d = a->mUnk_40->mUnk_20->mUnk_00;
    if (d->mUnk_00.mUnk_00_21) {
        func_0201910c(a);
        if (d->mUnk_00.mUnk_00_22) {
            return;
        }
        func_020191f4(a);
    } else {
        if (d->mUnk_00.mUnk_00_22 == 0) {
            func_020191f4(a);
        }
        func_0201910c(a);
    }
}

void func_02018f94(Unk0201ca6c *a, Vec3 *b, Vec3 *c) {
    Vec3 v;

    if (a->mUnk_20->mUnk_00->mUnk_00.mUnk_00_0 - 6 > 1) {
        return;
    }
    a->mUnk_28.x = (c->x + b->x) / 2;
    a->mUnk_28.y = (c->y + b->y) / 2;
    a->mUnk_28.z = (c->z + b->z) / 2;
    a->mUnk_60 = Vec3Distance(b, c) / 2;
    v.x = c->x - b->x;
    v.y = c->y - b->y;
    v.z = c->z - b->z;
    Vec3Normalize(&v, &v);
    a->mUnk_50.x = v.x;
    a->mUnk_50.y = v.y;
    a->mUnk_50.z = v.z;
}

u32 func_02018f5c(s32 a, s32 b) {
    return (data_021619ec(a, b, 0) & 0xffff) << 3;
}

u32 func_02018f24(s32 a, s32 b) {
    return (data_021619f4(a, b, 0) & 0xffff) << 3;
}

Unk020184e4 *func_02018d94(void *(*a)(u32 a), u16 b, u16 c, s32 d, u16 e, u16 f) {
    Unk020184e4 *p;
    s32 i;
    u8 *q;

    p = a(0x4c);
    MemFill(p, 0, 0x4c);
    p->mUnk_34 = b;
    p->mUnk_36 = c;
    p->mUnk_38_0 = e;
    p->mUnk_38_6 = f;
    p->mUnk_38_12 = p->mUnk_38_0;
    p->mUnk_38_18 = d;
    p->mUnk_38_24 = 0;
    p->mUnk_38_25 = 0;
    p->mUnk_00 = a;
    p->mUnk_04[0].mUnk_04 = 0;
    p->mUnk_04[1].mUnk_04 = 0;
    p->mUnk_04[2].mUnk_04 = 0;
    p->mUnk_04[0].mUnk_00 = 0;
    p->mUnk_04[1].mUnk_00 = 0;
    p->mUnk_04[2].mUnk_00 = 0;
    p->mUnk_3c = 0;
    p->mUnk_48 = 0;
    q = a(b * 0x9c);
    MemFill(q, 0, b * 0x9c);
    for (i = 0; i < b; i++) {
        func_0201e494(&p->mUnk_04[1], (Unk0201e3c8 *) q);
        q += 0x9c;
    }
    q = a(c * 0x44);
    MemFill(q, 0, c * 0x44);
    for (i = 0; i < c; i++) {
        func_0201e494(&p->mUnk_04[2], (Unk0201e3c8 *) q);
        q += 0x44;
    }
    p->mUnk_28 = 0;
    p->mUnk_2c = 0;
    p->mUnk_32 = 0;
    p->mUnk_30 = p->mUnk_32;
    return p;
}

void func_02018a1c(Unk020184e4 *a, Unk02018a1c *b) {
    s32 i;
    s32 off;
    Unk0201ca6c_20 *e;
    Unk0201ca6c_20_00_00 flags;
    Unk0201ca6c_20_18 *g;
    Unk020184e4_2c *h;
    Unk020184e4_2c_00 *d;

    off = 0x20;
    a->mUnk_30 = b->mUnk_08;
    a->mUnk_32 = b->mUnk_0a;
    a->mUnk_28 = a->mUnk_00(a->mUnk_30 << 5);
    MemFill(a->mUnk_28, 0, a->mUnk_30 << 5);
    for (i = 0; i < a->mUnk_30; i++) {
        e = a->mUnk_28 + i;
        e->mUnk_00 = (Unk0201ca6c_20_00 *) ((u8 *) b + off);
        off += 0x58;
        flags = e->mUnk_00->mUnk_00;
        if (flags.mUnk_00_8) {
            e->mUnk_04 = (Unk0201ca6c_20_04 *) ((u8 *) b + off);
            off += 0xc;
        } else {
            e->mUnk_04 = 0;
        }
        if (flags.mUnk_00_9) {
            e->mUnk_08 = (Unk0201ca6c_20_08 *) ((u8 *) b + off);
            off += 0xc;
        } else {
            e->mUnk_08 = 0;
        }
        if (flags.mUnk_00_10) {
            e->mUnk_0c = (Unk0201ca6c_20_0c *) ((u8 *) b + off);
            off += 8;
        } else {
            e->mUnk_0c = 0;
        }
        if (flags.mUnk_00_11) {
            e->mUnk_10 = (Unk0201ca6c_20_10 *) ((u8 *) b + off);
            off += 0xc;
        } else {
            e->mUnk_10 = 0;
        }
        if (flags.mUnk_00_16) {
            e->mUnk_14 = (Unk0201ca6c_20_14 *) ((u8 *) b + off);
            off += 0x14;
        } else {
            e->mUnk_14 = 0;
        }
        e->mUnk_1c = flags.mUnk_00_24 + flags.mUnk_00_25 + flags.mUnk_00_26 + flags.mUnk_00_27 + flags.mUnk_00_28 +
                     flags.mUnk_00_29;
        if (e->mUnk_1c != 0) {
            e->mUnk_18 = a->mUnk_00(e->mUnk_1c << 3);
            g = e->mUnk_18;
            if (flags.mUnk_00_24) {
                g->mUnk_04 = (u8 *) b + off;
                g->mUnk_00 = func_0201e394;
                off += 8;
                g++;
            }
            if (flags.mUnk_00_25) {
                g->mUnk_04 = (u8 *) b + off;
                g->mUnk_00 = func_0201e2cc;
                off += 8;
                g++;
            }
            if (flags.mUnk_00_26) {
                g->mUnk_04 = (u8 *) b + off;
                g->mUnk_00 = func_0201e248;
                off += 0x10;
                g++;
            }
            if (flags.mUnk_00_27) {
                g->mUnk_04 = (u8 *) b + off;
                g->mUnk_00 = func_0201e170;
                off += 4;
                g++;
            }
            if (flags.mUnk_00_28) {
                g->mUnk_04 = (u8 *) b + off;
                g->mUnk_00 = func_0201e054;
                off += 8;
                g++;
            }
            if (flags.mUnk_00_29) {
                g->mUnk_04 = (u8 *) b + off;
                g->mUnk_00 = func_0201dfc0;
                off += 0x10;
            }
        } else {
            e->mUnk_18 = 0;
        }
    }
    a->mUnk_2c = a->mUnk_00(a->mUnk_32 * 0x14);
    MemFill(a->mUnk_2c, 0, a->mUnk_32 * 0x14);
    for (i = 0; i < a->mUnk_32; i++) {
        h = a->mUnk_2c + i;
        d = (Unk020184e4_2c_00 *) ((u8 *) b + off);
        h->mUnk_00 = d;
        h->mUnk_10 = 1 << (d->mUnk_04.mUnk_00_4 + 3);
        h->mUnk_12 = 1 << (d->mUnk_04.mUnk_00_8 + 3);
        h->mUnk_0c = d->mUnk_04;
        off += d->mUnk_1c;
    }
}

s32 func_02018950(Unk020184e4 *a, u32 (*b)(s32 a, s32 b)) {
    s32 i;
    Unk020184e4_2c *e;
    Unk020184e4_2c_00 *d;
    u32 t;

    func_0214c6a8();
    for (i = 0; i < a->mUnk_32; i++) {
        e = a->mUnk_2c + i;
        d = e->mUnk_00;
        if (d->mUnk_04.mUnk_00_17) {
            e->mUnk_04 = a->mUnk_2c[d->mUnk_04.mUnk_00_18].mUnk_04;
        } else {
            t = b(d->mUnk_08, d->mUnk_04.mUnk_00_0 == 5 ? 1 : 0);
            func_0214c544((u8 *) e->mUnk_00 + 0x20, t, d->mUnk_08);
            e->mUnk_04 = t;
        }
    }
    func_0214c4d4();
    return 1;
}

s32 func_0201889c(Unk020184e4 *a, u32 (*b)(s32 a, s32 b)) {
    s32 i;
    Unk020184e4_2c *e;
    Unk020184e4_2c_00 *d;
    u32 t;

    func_0214c48c();
    for (i = 0; i < a->mUnk_32; i++) {
        e = a->mUnk_2c + i;
        d = e->mUnk_00;
        t = 0;
        if (d->mUnk_10 != 0) {
            t = b(d->mUnk_10, d->mUnk_04.mUnk_00_0 == 2 ? 1 : 0);
            func_0214c418((u8 *) e->mUnk_00 + d->mUnk_0c, t, d->mUnk_10);
        }
        e->mUnk_08 = t;
    }
    func_0214c3c0();
    return 1;
}

s32 func_02018888(Unk020184e4 *a) {
    return func_02018950(a, func_02018f5c);
}

s32 func_02018874(Unk020184e4 *a) {
    return func_0201889c(a, func_02018f24);
}

void func_0201873c(Unk020184e4 *a) {
    Unk0201ca6c *n;
    Unk0201ca6c *next;
    Unk0201ca6c_20_00 *d;

    for (n = (Unk0201ca6c *) a->mUnk_04[0].mUnk_00; n != 0; n = next) {
        d = n->mUnk_20->mUnk_00;
        next = n->mUnk_00;
        if (n->mUnk_24.mUnk_00_4 == 0) {
            if (n->mUnk_4c >= d->mUnk_32) {
                n->mUnk_24.mUnk_00_4 = 1;
                n->mUnk_4c = 0;
            }
        }
        if (n->mUnk_24.mUnk_00_2 == 0) {
            if (n->mUnk_80_16 == 0 || a->mUnk_48 == n->mUnk_80_16 - 1) {
                func_020192e0(a, n);
            }
        }
        if ((d->mUnk_00.mUnk_00_14 && d->mUnk_3c != 0 && n->mUnk_24.mUnk_00_4 != 0 && n->mUnk_4c > d->mUnk_3c) ||
            n->mUnk_24.mUnk_00_0 != 0) {
            if (n->mUnk_08.mUnk_04 == 0 && n->mUnk_14.mUnk_04 == 0) {
                func_0201e494(&a->mUnk_04[1], func_0201e3c8(&a->mUnk_04[0], (Unk0201e3c8 *) n));
            }
        }
    }
    a->mUnk_48++;
    if (a->mUnk_48 > 1) {
        a->mUnk_48 = 0;
    }
}

void func_02018674(Unk020184e4 *a, Unk02012f58 *b) {
    Unk0201ca6c *n;

    reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~0x3000) | 8;
    a->mUnk_44 = b;
    if (a->mUnk_38_24 == 0) {
        for (n = (Unk0201ca6c *) a->mUnk_04[0].mUnk_00; n != 0; n = n->mUnk_00) {
            a->mUnk_40 = n;
            if (n->mUnk_24.mUnk_00_3 == 0) {
                func_02019090(a);
            }
        }
    } else {
        for (n = (Unk0201ca6c *) a->mUnk_04[0].mUnk_08; n != 0; n = n->mUnk_04) {
            a->mUnk_40 = n;
            if (n->mUnk_24.mUnk_00_3 == 0) {
                func_02019090(a);
            }
        }
    }
}

Unk0201ca6c *func_02018600(Unk020184e4 *a, s32 b, Vec3 *c) {
    Unk0201ca6c *n;

    n = 0;
    if (a->mUnk_04[1].mUnk_00 != 0) {
        n = (Unk0201ca6c *) func_0201e448(&a->mUnk_04[1]);
        func_02019b28(n, a->mUnk_28 + b, c);
        func_0201e494(&a->mUnk_04[0], (Unk0201e3c8 *) n);
        if (n->mUnk_20->mUnk_00->mUnk_00.mUnk_00_14) {
            n = 0;
        }
    }
    return n;
}

Unk0201ca6c *func_02018578(Unk020184e4 *a, s32 b, Vec3 *c, s32 d, void (*e)(Unk0201ca6c *p, s32 a)) {
    Unk0201ca6c *n;

    n = 0;
    if (a->mUnk_04[1].mUnk_00 != 0) {
        n = (Unk0201ca6c *) func_0201e448(&a->mUnk_04[1]);
        func_02019b28(n, a->mUnk_28 + b, c);
        if (e != 0) {
            e(n, d);
        }
        func_0201e494(&a->mUnk_04[0], (Unk0201e3c8 *) n);
        if (n->mUnk_20->mUnk_00->mUnk_00.mUnk_00_14) {
            n = 0;
        }
    }
    return n;
}

void func_020184e4(Unk020184e4 *a, Unk0201ca6c *b) {
    Unk0201e3c8 *n;

    while ((n = func_0201e448(&b->mUnk_08)) != 0) {
        func_0201e494(&a->mUnk_04[2], n);
    }
    while ((n = func_0201e448(&b->mUnk_14)) != 0) {
        func_0201e494(&a->mUnk_04[2], n);
    }
    func_0201e3c8(&a->mUnk_04[0], (Unk0201e3c8 *) b);
    func_0201e494(&a->mUnk_04[1], (Unk0201e3c8 *) b);
}
