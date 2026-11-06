#include "code_02010c84.h"

#include "code_02147288.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/unk_02170000.h"
#include "00/code_02188720.h"
#include "code_02012b30.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"
#include "code_021479b4.h"
#include "code_0214a4dc.h"
#include "code_0214a748.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_02171000.h"
#include "registers.h"
#include "code_021471bc.h"
#include "code_02147954.h"

void func_0201290c(Unk0201290c *a, u32 b, u32 c, s32 d) {
    u32 s[7];
    Unk0201290c_1c t;
    s32 v[3];
    s32 w[3];
    u8 *p;
    u8 *q;
    Unk0201290c_08 *e;
    Unk0201290c_0c *f;
    u16 *h;
    s32 k;
    void (*fn)(Unk0201290c_1c *);
    u32 x;

    k = a->mUnk_1c;
    if (k != 0x1000) {
        v[0] = k;
        v[1] = k;
        v[2] = k;
        func_01ff9048(0x1b, v, 3);
    }
    if (d != 0) {
        q = (u8 *) a + a->mEntriesOffset;
        h = (u16 *) (q + 4 + *(u16 *) (q + 0xa));
        e = (Unk0201290c_08 *) (q + *(u32 *) ((u8 *) h + *h * b + 4));
        if (!(e->mUnk_0c & 0x1f0000)) {
            return;
        }
        s[0] = 0x293130;
        s[1] = e->mUnk_04;
        s[2] = e->mUnk_08;
        x = e->mUnk_0c;
        s[3] = x;
        if (e->mUnk_1e & 0x20) {
            s[3] = x & ~0x1f0000;
        }
        s[4] = 0x2b2a;
        s[5] = e->mUnk_14;
        s[6] = e->mUnk_1c;
        func_01ff9048(s[0], &s[1], 6);
        if (e->mUnk_1e & 1) {
            fn = data_0216185c[a->mUnk_16];
            t.mUnk_00 = 8;
            t.mUnk_2c = e->mUnk_20;
            t.mUnk_2e = e->mUnk_22;
            t.mUnk_30 = e->mUnk_24;
            t.mUnk_34 = e->mUnk_28;
            p = e->mUnk_2c;
            if (!(e->mUnk_1e & 2)) {
                t.mUnk_18[0] = ((u32 *) p)[0];
                t.mUnk_18[1] = ((u32 *) p)[1];
                p += 8;
            } else {
                t.mUnk_00 |= 1;
            }
            if (!(e->mUnk_1e & 4)) {
                t.mUnk_20[0] = ((s16 *) p)[0];
                t.mUnk_20[1] = ((s16 *) p)[1];
                p += 4;
            } else {
                t.mUnk_00 |= 2;
            }
            if (!(e->mUnk_1e & 8)) {
                t.mUnk_24[0] = ((u32 *) p)[0];
                t.mUnk_24[1] = ((u32 *) p)[1];
            } else {
                t.mUnk_00 |= 4;
            }
            fn(&t);
        }
    }
    q = (u8 *) a + a->mUnk_0c;
    h = (u16 *) (q + *(u16 *) (q + 6));
    f = (Unk0201290c_0c *) (q + *(u32 *) ((u8 *) h + *h * c + 4));
    func_01ff9144((u8 *) f + f->mUnk_08, f->mUnk_0c);
    k = a->mUnk_20;
    if (k != 0x1000) {
        w[0] = k;
        w[1] = k;
        w[2] = k;
        func_01ff9048(0x1b, w, 3);
    }
}

void func_0201261c(Unk02011624 *a, u32 b) {
    u32 c;
    u32 c2;
    s32 mm[16];
    s32 m2[16];
    s32 m3[16];
    u32 v;
    u32 n = 2;
    Vec3 *p0c = &data_0216190c;
    Vec3 *p18 = &data_02161918;

    if (a->mUnk_08 & 0x200) {
        if (b == 0x40 || b == 0x60) {
            n++;
        }
        if (b == 0x20 || b == 0x60) {
            n++;
        }
        a->mUnk_00 += n;
        return;
    }
    if (b == 0x40 || b == 0x60) {
        n++;
        if (!(a->mUnk_08 & 0x100)) {
            if (b == 0x40) {
                c = a->mUnk_00[2];
            } else {
                c = a->mUnk_00[3];
            }
            func_01ff9048(0x14, &c, 1);
        }
    }
    if (a->mUnk_28 != 0) {
        v = a->mUnk_93;
    } else {
        v = 0;
    }
    if (!(a->mUnk_08 & 0x100)) {
        func_01ff9234();
        reg_G3X_GXFIFO = 0x151110;
        reg_G3X_GXFIFO = 0;
        reg_G3X_GXFIFO = 0;
        while (G3X_GetClipMtx(mm) != 0) {
        }
        if (data_0217029c.mUnk_fc & 1) {
            MTX_Copy43To44_(func_02010e2c(), m2);
            MTX_Concat44(mm, m2, mm);
        } else if (data_0217029c.mUnk_fc & 2) {
            MTX_Copy43To44_(&data_0217029c.mUnk_4c, m3);
            MTX_Concat44(mm, m3, mm);
        }
        p0c->x = mm[12];
        p0c->y = mm[13];
        p0c->z = mm[14];
        p18->x = VEC_Mag((Vec3 *) &mm[0]);
        p18->y = VEC_Mag((Vec3 *) &mm[4]);
        p18->z = VEC_Mag((Vec3 *) &mm[8]);
        if (data_0217029c.mUnk_fc & 1) {
            reg_G3X_GXFIFO = 0x171012;
            MIi_CpuSend32(data_021618e0, &reg_G3X_GXFIFO, 8);
            MIi_CpuSend32(func_02010de8(), &reg_G3X_GXFIFO, 0x30);
            reg_G3X_GXFIFO = 0x1b19;
            MIi_CpuSend32(data_021618e8, &reg_G3X_GXFIFO, 0x3c);
        } else if (data_0217029c.mUnk_fc & 2) {
            reg_G3X_GXFIFO = 0x171012;
            MIi_CpuSend32(data_021618e0, &reg_G3X_GXFIFO, 8);
            MIi_CpuSend32(func_02010ed4(), &reg_G3X_GXFIFO, 0x30);
            reg_G3X_GXFIFO = 0x1b19;
            MIi_CpuSend32(data_021618e8, &reg_G3X_GXFIFO, 0x3c);
        } else {
            MIi_CpuSend32(data_021618dc, &reg_G3X_GXFIFO, 0x48);
        }
    }
    if (v == 3) {
        a->mUnk_08 &= ~0x40;
        a->mUnk_28(a);
        v = a->mUnk_08 & 0x40;
    } else {
        v = 0;
    }
    if (b == 0x20 || b == 0x60) {
        n++;
        if (v == 0 && !(a->mUnk_08 & 0x100)) {
            c2 = a->mUnk_00[2];
            func_01ff9048(0x13, &c2, 1);
        }
    }
    a->mUnk_00 += n;
}

void func_020122cc(Unk02011624 *a, u32 b) {
    u32 c;
    u32 c2;
    s32 mm[16];
    s32 m2[16];
    s32 m3[16];
    u32 v;
    u32 n = 2;
    Vec3 *p54 = &data_02161954;
    Vec3 *p60 = &data_02161960;
    Vec3 *p30 = data_02161930;

    if (a->mUnk_08 & 0x200) {
        if (b == 0x40 || b == 0x60) {
            n++;
        }
        if (b == 0x20 || b == 0x60) {
            n++;
        }
        a->mUnk_00 += n;
        return;
    }
    if (b == 0x40 || b == 0x60) {
        n++;
        if (!(a->mUnk_08 & 0x100)) {
            if (b == 0x40) {
                c = a->mUnk_00[2];
            } else {
                c = a->mUnk_00[3];
            }
            func_01ff9048(0x14, &c, 1);
        }
    }
    if (a->mUnk_2c != 0) {
        v = a->mUnk_94;
    } else {
        v = 0;
    }
    if (!(a->mUnk_08 & 0x100)) {
        func_01ff9234();
        reg_G3X_GXFIFO = 0x151110;
        reg_G3X_GXFIFO = 0;
        reg_G3X_GXFIFO = 0;
        while (G3X_GetClipMtx(mm) != 0) {
        }
        if (data_0217029c.mUnk_fc & 1) {
            MTX_Copy43To44_(func_02010e2c(), m2);
            MTX_Concat44(mm, m2, mm);
        } else if (data_0217029c.mUnk_fc & 2) {
            MTX_Copy43To44_(&data_0217029c.mUnk_4c, m3);
            MTX_Concat44(mm, m3, mm);
        }
        p54->x = mm[12];
        p54->y = mm[13];
        p54->z = mm[14];
        p60->x = VEC_Mag((Vec3 *) &mm[0]);
        p60->y = VEC_Mag((Vec3 *) &mm[4]);
        p60->z = VEC_Mag((Vec3 *) &mm[8]);
        if (mm[5] != 0 || mm[6] != 0) {
            VEC_Normalize((Vec3 *) &mm[4], &p30[1]);
            p30[2].y = -p30[1].z;
            p30[2].z = p30[1].y;
        } else {
            VEC_Normalize((Vec3 *) &mm[8], &p30[2]);
            p30[1].z = -p30[2].y;
            p30[1].y = p30[2].z;
        }
        if (data_0217029c.mUnk_fc & 1) {
            reg_G3X_GXFIFO = 0x171012;
            MIi_CpuSend32(data_02161928, &reg_G3X_GXFIFO, 8);
            MIi_CpuSend32(func_02010de8(), &reg_G3X_GXFIFO, 0x30);
            reg_G3X_GXFIFO = 0x1b19;
            MIi_CpuSend32(data_02161930, &reg_G3X_GXFIFO, 0x3c);
        } else if (data_0217029c.mUnk_fc & 2) {
            reg_G3X_GXFIFO = 0x171012;
            MIi_CpuSend32(data_02161928, &reg_G3X_GXFIFO, 8);
            MIi_CpuSend32(func_02010ed4(), &reg_G3X_GXFIFO, 0x30);
            reg_G3X_GXFIFO = 0x1b19;
            MIi_CpuSend32(data_02161930, &reg_G3X_GXFIFO, 0x3c);
        } else {
            MIi_CpuSend32(data_02161924, &reg_G3X_GXFIFO, 0x48);
        }
    }
    if (v == 3) {
        a->mUnk_08 &= ~0x40;
        a->mUnk_2c(a);
        v = a->mUnk_08 & 0x40;
    } else {
        v = 0;
    }
    if (b == 0x20 || b == 0x60) {
        n++;
        if (v == 0 && !(a->mUnk_08 & 0x100)) {
            c2 = a->mUnk_00[2];
            func_01ff9048(0x13, &c2, 1);
        }
    }
    a->mUnk_00 += n;
}

void func_02011c58(Unk02011624 *a) {
    u8 *q;
    u32 n;
    u32 d;
    s64 v;
    u8 *p;
    u32 i;
    Unk02011c58_04_04 *b;
    s32 *m;
    s32 *r;
    u32 k;
    Unk02011c58_38 t;

    b = a->mUnk_04->mUnk_04;
    n = a->mUnk_00[2];
    q = (u8 *) b + b->mUnk_10;
    v = 0;
    p = a->mUnk_00 + 3;
    MemFillWordsByBlock_inline(&t, sizeof(t));
    func_01ff9234();
    reg_G3_MTX_MODE = 0;
    reg_G3_MTX_STORE = 1;
    reg_G3_MTX_IDENTITY = 0;
    reg_G3_MTX_MODE = 2;
    for (i = 0; i < n; i++) {
        k = p[1];
        d = ((s32 *) a->mUnk_cc)[k >> 5] & (1 << (k & 0x1f));
        m = data_02171904[k];
        if (!d) {
            a->mUnk_cc[k >> 5] |= 1 << (k & 0x1f);
            reg_G3_MTX_RESTORE = p[0];
            reg_G3_MTX_MODE = 1;
            GxFifoWrite0x19Then12Words(q + k * 0x54);
        }
        if (i != 0) {
            t.mUnk_30[0] += (v * r[0]) >> 12;
            t.mUnk_30[1] += (v * r[1]) >> 12;
            t.mUnk_30[2] += (v * r[2]) >> 12;
            t.mUnk_30[3] += (v * r[3]) >> 12;
            t.mUnk_30[4] += (v * r[4]) >> 12;
            t.mUnk_30[5] += (v * r[5]) >> 12;
            t.mUnk_30[6] += (v * r[6]) >> 12;
            t.mUnk_30[7] += (v * r[7]) >> 12;
            t.mUnk_30[8] += (v * r[8]) >> 12;
        }
        if (!d) {
            while (G3X_GetClipMtx(m) != 0) {
            }
            reg_G3_MTX_MODE = 2;
            GxFifoWrite0x1aThenMemCopy9Words(q + k * 0x54 + 0x30);
        }
        r = data_02171944[k];
        v = p[2] << 4;
        t.mUnk_00[0] += (v * m[0]) >> 12;
        t.mUnk_00[1] += (v * m[1]) >> 12;
        t.mUnk_00[2] += (v * m[2]) >> 12;
        t.mUnk_00[3] += (v * m[4]) >> 12;
        t.mUnk_00[4] += (v * m[5]) >> 12;
        t.mUnk_00[5] += (v * m[6]) >> 12;
        t.mUnk_00[6] += (v * m[8]) >> 12;
        t.mUnk_00[7] += (v * m[9]) >> 12;
        t.mUnk_00[8] += (v * m[10]) >> 12;
        t.mUnk_00[9] += (v * m[12]) >> 12;
        t.mUnk_00[10] += (v * m[13]) >> 12;
        t.mUnk_00[11] += (v * m[14]) >> 12;
        p += 3;
        if (!d) {
            while (G3X_GetVectorMtx(r) != 0) {
            }
        }
    }
    t.mUnk_30[0] += (v * r[0]) >> 12;
    t.mUnk_30[1] += (v * r[1]) >> 12;
    t.mUnk_30[2] += (v * r[2]) >> 12;
    t.mUnk_30[3] += (v * r[3]) >> 12;
    t.mUnk_30[4] += (v * r[4]) >> 12;
    t.mUnk_30[5] += (v * r[5]) >> 12;
    t.mUnk_30[6] += (v * r[6]) >> 12;
    t.mUnk_30[7] += (v * r[7]) >> 12;
    t.mUnk_30[8] += (v * r[8]) >> 12;
    GxFifoWrite0x17Then12Words(t.mUnk_30);
    reg_G3_MTX_MODE = 1;
    GxFifoWrite0x17Then12Words(t.mUnk_00);
    reg_G3_MTX_MODE = 0;
    reg_G3_MTX_RESTORE = 1;
    reg_G3_MTX_MODE = 2;
    reg_G3_MTX_STORE = a->mUnk_00[1];
    a->mUnk_00 += (a->mUnk_00[2] + 1) * 3;
}

void func_02011bbc(Unk02011624 *a) {
    u8 *p;
    u32 v;

    if (a->mUnk_34 != 0) {
        v = a->mUnk_96;
    } else {
        v = 0;
    }
    if (!(a->mUnk_08 & 0x100)) {
        p = a->mUnk_00;
        func_01ff9144(p + (p[1] | (p[2] << 8) | (p[3] << 16) | (p[4] << 24)),
                      p[5] | (p[6] << 8) | (p[7] << 16) | (p[8] << 24));
    }
    if (v == 3) {
        a->mUnk_08 &= ~0x40;
        a->mUnk_34(a);
    }
    a->mUnk_00 += 9;
}

void func_02011928(Unk02011624 *a) {
    u32 c0;
    u32 c1;
    u32 c2;
    u32 c3;
    u32 c4;
    MtxFx43 m;
    u32 v;
    u8 *e;
    u8 *t;
    u16 h2;
    s32 w;
    s32 h;

    if (!(a->mUnk_08 & 0x200) && (a->mUnk_08 & 1)) {
        if ((a->mUnk_b0->mUnk_10 & 0xc0000000) != 0x80000000) {
            a->mUnk_b0->mUnk_10 &= ~0xc0000000;
            a->mUnk_b0->mUnk_10 |= 0x80000000;
            data_02161874[1] = a->mUnk_b0->mUnk_10;
            func_01ff9048(data_02161874[0], &data_02161874[1], 1);
        }
        c0 = 3;
        func_01ff9048(0x10, &c0, 1);
        if (a->mUnk_3c != 0) {
            v = a->mUnk_98;
        } else {
            v = 0;
        }
        w = a->mUnk_b0->mUnk_2c;
        h = a->mUnk_b0->mUnk_2e;
        m.mUnk_00[3].x = w << 15;
        m.mUnk_00[3].y = -h << 15;
        m.mUnk_00[3].z = 0x10000;
        func_01ff9048(0x1b, &m.mUnk_00[3], 3);
        c1 = (u16) (s16) (w << 3) | ((u16) (s16) (h << 3) << 16);
        func_01ff9048(0x22, &c1, 1);
        t = a->mUnk_d8 + 4;
        t = t + *(u16 *) (a->mUnk_d8 + 0xa);
        e = a->mUnk_d8 + *(u32 *) (t + *(u16 *) t * a->mUnk_00[1] + 4);
        h2 = *(u16 *) (e + 0x1e);
        if (h2 & 0x2000) {
            e += 0x2c;
            if (!(h2 & 2)) {
                e += 8;
            }
            if (!(h2 & 4)) {
                e += 4;
            }
            if (!(h2 & 8)) {
                e += 8;
            }
            func_01ff9048(0x18, e, 0x10);
        }
        if (v == 3) {
            a->mUnk_08 &= ~0x40;
            a->mUnk_3c(a);
            v = a->mUnk_08 & 0x40;
        } else {
            v = 0;
        }
        if (v == 0) {
            c2 = 2;
            func_01ff9048(0x10, &c2, 1);
            func_02012f58(0, &m);
            c3 = 3;
            func_01ff9048(0x10, &c3, 1);
            if (data_0217029c.mUnk_fc & 1) {
                func_01ff9048(0x1a, &data_0217029c.mUnk_4c, 9);
                func_01ff9048(0x1a, &data_0217029c.mUnk_bc, 9);
                func_01ff9048(0x1a, &m, 9);
            } else if (data_0217029c.mUnk_fc & 2) {
                func_01ff9048(0x1a, &data_0217029c.mUnk_4c, 9);
                func_01ff9048(0x1a, &m, 9);
            } else {
                func_01ff9048(0x1a, &m, 9);
            }
        }
        c4 = 2;
        func_01ff9048(0x10, &c4, 1);
    }
    a->mUnk_00 += 3;
}

void func_02011624(Unk02011624 *a) {
    u32 c0;
    u32 c1;
    u32 c2;
    u32 c3;
    MtxFx43 m;
    s32 mm[16];
    u32 v;
    u8 *e;
    u8 *t;
    u16 h2;
    s32 w;
    s32 h;
    s32 x;
    s32 y;

    if (!(a->mUnk_08 & 0x200) && (a->mUnk_08 & 1)) {
        func_02012f58(&m, 0);
        c0 = 0x1e;
        func_01ff9048(0x13, &c0, 1);
        if ((a->mUnk_b0->mUnk_10 & 0xc0000000) != 0xc0000000) {
            a->mUnk_b0->mUnk_10 &= ~0xc0000000;
            a->mUnk_b0->mUnk_10 |= 0xc0000000;
            data_0216186c[1] = a->mUnk_b0->mUnk_10;
            func_01ff9048(data_0216186c[0], &data_0216186c[1], 1);
        }
        if (a->mUnk_40 != 0) {
            v = a->mUnk_99;
        } else {
            v = 0;
        }
        h = a->mUnk_b0->mUnk_2e;
        w = a->mUnk_b0->mUnk_2c;
        data_0216189c[0] = w << 15;
        data_0216189c[5] = -h << 15;
        data_0216189c[12] = w << 15;
        data_0216189c[13] = h << 15;
        func_01ff9048(0x16, data_0216189c, 0x10);
        t = a->mUnk_d8 + 4;
        t = t + *(u16 *) (a->mUnk_d8 + 0xa);
        e = a->mUnk_d8 + *(u32 *) (t + *(u16 *) t * a->mUnk_00[1] + 4);
        h2 = *(u16 *) (e + 0x1e);
        if (h2 & 0x2000) {
            e += 0x2c;
            if (!(h2 & 2)) {
                e += 8;
            }
            if (!(h2 & 4)) {
                e += 4;
            }
            if (!(h2 & 8)) {
                e += 8;
            }
            func_01ff9048(0x18, e, 0x10);
        }
        if (v == 3) {
            a->mUnk_08 &= ~0x40;
            a->mUnk_40(a);
            v = a->mUnk_08 & 0x40;
        } else {
            v = 0;
        }
        if (v == 0) {
            if (data_0217029c.mUnk_fc & 1) {
                func_01ff9048(0x1c, &data_0217029c.mUnk_bc.mUnk_00[3], 3);
                func_01ff9048(0x1a, &data_0217029c.mUnk_bc, 9);
                func_01ff9048(0x19, &m, 0xc);
            } else if (data_0217029c.mUnk_fc & 2) {
                func_01ff9048(0x19, &m, 0xc);
            } else {
                func_01ff9048(0x19, func_02010ed4(), 0xc);
                func_01ff9048(0x19, &m, 0xc);
            }
            func_01ff9234();
            reg_G3_MTX_MODE = 0;
            reg_G3_MTX_PUSH = 0;
            reg_G3_MTX_IDENTITY = 0;
            while (G3X_GetClipMtx(mm) != 0) {
            }
            reg_G3_MTX_POP = 1;
            reg_G3_MTX_MODE = 3;
            func_01ff9048(0x16, mm, 0x10);
            x = mm[12] >> 4;
            y = mm[13] >> 4;
            c1 = (u16) (s16) (x >> 8) | ((u16) (s16) (y >> 8) << 16);
            func_01ff9048(0x22, &c1, 1);
        }
        c2 = 2;
        func_01ff9048(0x10, &c2, 1);
        c3 = 0x1e;
        func_01ff9048(0x14, &c3, 1);
    }
    a->mUnk_00 += 3;
}

s32 func_020115c8(void *a, Unk020111e0 *b, u32 c) {
    s32 r = 0;

    do {
        u32 h = b->mUnk_1a[c];

        if (h & 0x100) {
            b->mUnk_0c(a, b, h & 0xff);
            r = 1;
        }
        b = b->mUnk_10;
    } while (b != 0);
    return r;
}

void func_02011558(Vec3 *a, const Vec3 *b, s32 c, u32 d) {
    if (d != 0) {
        a->x += c;
        a->y += c;
        a->z += c;
    } else {
        a->x += (c * b->x) >> 12;
        a->y += (c * b->y) >> 12;
        a->z += (c * b->z) >> 12;
    }
}

s32 func_02011254(Unk02011254 *a, Unk020111e0 *b, u32 c) {
    Unk02011254 t;
    Unk020111e0 *p;
    s32 n;
    s32 s;
    Unk020111e0 *q;
    s32 w;
    u32 h;

    if (b->mUnk_10 == 0) {
        h = b->mUnk_1a[c];
        if ((h & 0x300) != 0x100) {
            return 0;
        }
        b->mUnk_0c(a, b, h & 0xff);
        return 1;
    }
    s = 0;
    n = 0;
    p = b;
    do {
        if ((p->mUnk_1a[c] & 0x300) == 0x100) {
            q = p;
            s += p->mUnk_04;
            n++;
        }
        p = p->mUnk_10;
    } while (p != 0);
    if (s == 0) {
        return 0;
    }
    if (n == 1) {
        q->mUnk_0c(a, q, q->mUnk_1a[c] & 0xff);
        return 1;
    }
    MemFillWordsByBlock_inline(a, sizeof(*a));
    a->mUnk_00 = -1;
    do {
        h = b->mUnk_1a[c];
        if ((h & 0x300) == 0x100 && b->mUnk_04 > 0) {
            b->mUnk_0c(&t, b, h & 0xff);
            if (s == 0x1000) {
                w = b->mUnk_04;
            } else {
                w = FX_Div(b->mUnk_04, s);
            }
            func_02011558(&a->mUnk_04[0], &t.mUnk_04[0], w, t.mUnk_00 & 1);
            func_02011558(&a->mUnk_04[1], &t.mUnk_04[1], w, t.mUnk_00 & 8);
            func_02011558(&a->mUnk_04[2], &t.mUnk_04[2], w, t.mUnk_00 & 0x10);
            if (!(t.mUnk_00 & 4)) {
                a->mUnk_28.mUnk_00[3].x += (s32) (((s64) w * t.mUnk_28.mUnk_00[3].x) >> 12);
                a->mUnk_28.mUnk_00[3].y += (s32) (((s64) w * t.mUnk_28.mUnk_00[3].y) >> 12);
                a->mUnk_28.mUnk_00[3].z += (s32) (((s64) w * t.mUnk_28.mUnk_00[3].z) >> 12);
            }
            if (!(t.mUnk_00 & 2)) {
                a->mUnk_28.mUnk_00[0].x += (w * t.mUnk_28.mUnk_00[0].x) >> 12;
                a->mUnk_28.mUnk_00[0].y += (w * t.mUnk_28.mUnk_00[0].y) >> 12;
                a->mUnk_28.mUnk_00[0].z += (w * t.mUnk_28.mUnk_00[0].z) >> 12;
                a->mUnk_28.mUnk_00[1].x += (w * t.mUnk_28.mUnk_00[1].x) >> 12;
                a->mUnk_28.mUnk_00[1].y += (w * t.mUnk_28.mUnk_00[1].y) >> 12;
                a->mUnk_28.mUnk_00[1].z += (w * t.mUnk_28.mUnk_00[1].z) >> 12;
            } else {
                a->mUnk_28.mUnk_00[0].x += w;
                a->mUnk_28.mUnk_00[1].y += w;
            }
            a->mUnk_00 &= t.mUnk_00;
        }
        b = b->mUnk_10;
    } while (b != 0);
    VEC_CrossProduct(&a->mUnk_28.mUnk_00[0], &a->mUnk_28.mUnk_00[1], &a->mUnk_28.mUnk_00[2]);
    VEC_Normalize(&a->mUnk_28.mUnk_00[0], &a->mUnk_28.mUnk_00[0]);
    VEC_Normalize(&a->mUnk_28.mUnk_00[2], &a->mUnk_28.mUnk_00[2]);
    VEC_CrossProduct(&a->mUnk_28.mUnk_00[2], &a->mUnk_28.mUnk_00[0], &a->mUnk_28.mUnk_00[1]);
    return 1;
}

s32 func_020111e0(u32 *a, Unk020111e0 *b, u32 c) {
    u32 t;
    s32 r = 0;

    *a = 0;
    do {
        u32 h = b->mUnk_1a[c];

        if (h & 0x100) {
            b->mUnk_0c(&t, b, h & 0xff);
            *a |= t;
            r = 1;
        }
        b = b->mUnk_10;
    } while (b != 0);
    return r;
}

void func_02011074(void) {
    data_0217029c.mUnk_00 = 0x17101610;
    data_0217029c.mUnk_04 = 0;
    data_0217029c.mUnk_48 = 2;
    data_0217029c.mUnk_7c = 0x32323232;
    data_0217029c.mUnk_90 = 0x60293130;
    data_0217029c.mUnk_a4 = 0x33333333;
    data_0217029c.mUnk_b8 = 0x2a1b19;
    MTX_Identity43_(&data_0217029c.mUnk_4c);
    MTX_Identity44_(data_0217029c.mUnk_08);
    data_0217029c.mUnk_80 = 0x2d8b62d8;
    data_0217029c.mUnk_84 = 0x40000200;
    data_0217029c.mUnk_88 = 0x800001ff;
    data_0217029c.mUnk_8c = 0xc0080000;
    data_0217029c.mUnk_94 = 0x4210c210;
    data_0217029c.mUnk_98 = 0x4210c210;
    data_0217029c.mUnk_9c = 0x1f008f;
    data_0217029c.mUnk_a0 = 0xbfff0000;
    data_0217029c.mUnk_a8 = 0x7fff;
    data_0217029c.mUnk_ac = 0x4000001f;
    data_0217029c.mUnk_b0 = 0x800003e0;
    data_0217029c.mUnk_b4 = 0xc0007c00;
    data_0217029c.mUnk_bc.mUnk_00[3].x = 0;
    data_0217029c.mUnk_bc.mUnk_00[3].y = 0;
    data_0217029c.mUnk_bc.mUnk_00[3].z = 0;
    MTX_Identity33_(&data_0217029c.mUnk_bc);
    data_0217029c.mUnk_ec.x = 0x1000;
    data_0217029c.mUnk_ec.y = 0x1000;
    data_0217029c.mUnk_ec.z = 0x1000;
    data_0217029c.mUnk_f8 = 0;
    data_0217029c.mUnk_fc = 0;
    data_0217029c.mUnk_248 = 0;
    data_0217029c.mUnk_244 = 0;
    data_0217029c.mUnk_240 = 0;
    data_0217029c.mUnk_254 = 0;
    data_0217029c.mUnk_24c = 0;
    data_0217029c.mUnk_250 = 0x1000;
    data_0217029c.mUnk_25c = 0;
    data_0217029c.mUnk_258 = 0;
    data_0217029c.mUnk_260 = -0x1000;
}

void func_02011034(void) {
    u32 *p = (u32 *) &data_0217029c;
    u32 c = *p++;

    func_01ff9048(c, p, 0x3e);
    data_0217029c.mUnk_fc &= ~1;
    data_0217029c.mUnk_fc &= ~2;
}

void func_0201100c(const Vec3 *a) {
    data_0217029c.mUnk_bc.mUnk_00[3] = *a;
    data_0217029c.mUnk_fc &= ~0xa4;
}

void func_02010fe4(const Vec3 *a) {
    data_0217029c.mUnk_ec = *a;
    data_0217029c.mUnk_fc &= ~0xa4;
}

void func_02010fac(u32 a, s32 b, s32 c, s32 d) {
    (&data_0217029c.mUnk_80)[a] =
        ((b >> 3) & 0x3ff) | (((c >> 3) & 0x3ff) << 10) | (((d >> 3) & 0x3ff) << 20) | (a << 30);
}

void func_02010f98(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    value2 = (u32) &data_02170344;
    value1 = (value1) | ((value0 << 30));
    *(u32 *) ((value2) + ((value0 << 2))) = value1;
}

void func_02010f74(u32 a, u32 b, u32 c) {
    data_0217029c.mUnk_94 = a | (b << 16) | ((c != 0) << 15);
}

void func_02010f50(u32 a, u32 b, u32 c) {
    data_0217029c.mUnk_98 = a | (b << 16) | ((c != 0) << 15);
}

void func_02010f24(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f) {
    data_0217029c.mUnk_9c = (f | (a | (b << 4) | (c << 6))) | (d << 24) | (e << 16);
}

MtxFx43 *func_02010ed4(void) {
    if (!(data_0217029c.mUnk_fc & 0x8)) {
        MTX_Inverse43(&data_0217029c.mUnk_4c, &data_0217029c.mUnk_100[0]);
        data_0217029c.mUnk_fc |= 0x8;
    }
    return &data_0217029c.mUnk_100[0];
}

void func_02010e70(void) {
    MTX_Concat43(&data_0217029c.mUnk_bc, &data_0217029c.mUnk_4c, &data_0217029c.mUnk_100[1]);
    MTX_ScaleApply43(&data_0217029c.mUnk_100[1], &data_0217029c.mUnk_100[1], data_0217029c.mUnk_ec.x,
                     data_0217029c.mUnk_ec.y, data_0217029c.mUnk_ec.z);
    MTX_Inverse43(&data_0217029c.mUnk_100[1], &data_0217029c.mUnk_100[2]);
}

MtxFx43 *func_02010e2c(void) {
    if (!(data_0217029c.mUnk_fc & 0x80)) {
        func_02010e70();
        data_0217029c.mUnk_fc |= 0x80;
    }
    return &data_0217029c.mUnk_100[1];
}

MtxFx43 *func_02010de8(void) {
    if (!(data_0217029c.mUnk_fc & 0x80)) {
        func_02010e70();
        data_0217029c.mUnk_fc |= 0x80;
    }
    return &data_0217029c.mUnk_100[2];
}

u32 func_02010d98(const u8 *a, const Unk02010d98 *b) {
    switch (*a) {
        case 0x4d:
            return ((b->mUnk_18 << 1) + 0x1c) & ~3;
        case 0x4a:
        case 0x56:
            return ((b->mUnk_17 << 1) + 0x1c) & ~3;
        default:
            return 0;
    }
}

void func_02010cec(Unk02010c84 *a, const Unk02010cec_08 *b, u32 c, u32 d) {
    u32 i;

    a->mUnk_00 = 0;
    a->mUnk_08 = b;
    a->mUnk_10 = 0;
    a->mUnk_18 = 0x7f;
    a->mUnk_04 = 0x1000;
    a->mUnk_14 = d;
    for (i = 0; i < data_021617d0; i++) {
        if (b->mUnk_00 == data_021617f4[i].mUnk_00 && b->mUnk_02 == data_021617f4[i].mUnk_02) {
            data_021617f8[i].mUnk_00(a, b, c);
            return;
        }
    }
}

void func_02010c84(Unk02010c84 *a, u32 b) {
    volatile u32 z = 0;

    MIi_CpuClear32(z, a, 0x54);
    a->mUnk_0c = data_021617f0;
    a->mUnk_14 = data_021617ec;
    a->mUnk_1c = data_021617e8;
    a->mUnk_04 = b;
}
