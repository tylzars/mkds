#include "Main/Unknown/code_020800f4.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0208537c.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_02155000.h"
#include "code_02147cd8.h"

void func_020800f4(Unk0208001c *p, Vec3 *a, Vec3 *b, u16 c, Unk020888b4_d0 *d, s32 e) {
    s32 m2;
    Unk02175620_bc *r;
    s32 m1;
    Unk02175620_bc *v1 = p->mUnk_00;
    u16 n2 = 0;
    Unk02175620_bc *v2[8] = {0, 0, 0, 0, 0, 0, 0, 0};
    u16 n1;
    s32 m0;
    Unk0206bcb0 *o;
    Unk02175620_bc *q;
    s32 u;
    u16 n;
    u16 l;
    u16 h;
    u32 v32;
    BOOL v3;
    Unk02175620_bc *f;
    u16 n0;
    s32 t;
    u16 i;
    u8 j;
    Unk0217aebc_128 *g;
    u16 k;
    Vec3 v;
    Vec3 w;
    Vec3 x;
    Vec3 y;
    Vec3 z[2];
    Vec3 s;

    m2 = -0x1000;
    m1 = 0x1000;
    r = NULL;
    m0 = m2;
    f = NULL;
    if (p->mUnk_00->mUnk_2c == 1) {
        r = p->mUnk_00->mUnk_00[0];
    } else {
        Unk02175620_bc *v4[2] = {0, 0};

        n = 0;
        n1 = 0;
        n1 = (u16) n1;
        n0 = 0;
        if (d != NULL) {
            k = 0;
            func_021484d0(&d->mPos, &func_0207a974(c)->mUnk_80, &v);
            if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z >= 0x10) {
                func_02039860(&v, &v);
            }
            for (i = 0; i < p->mUnk_00->mUnk_2c; i++) {
                if (p->mUnk_04 == ((const Unk0208001c *) p)->mUnk_00->mUnk_00[i]) {
                    continue;
                }
                func_021484d0(p->mUnk_00->mUnk_00[i]->mUnk_20, &func_0207a974(c)->mUnk_80, &w);
                if ((s64) w.x * w.x + (s64) w.y * w.y + (s64) w.z * w.z >= 0x10) {
                    func_02039860(&w, &w);
                }
                t = func_02039828(&w, b);
                if (t >= -0x800) {
                    u = func_0214848c(&v, &w);
                    if (u > m0 || k == 0) {
                        m0 = u;
                        k++;
                        r = p->mUnk_00->mUnk_00[i];
                    }
                } else if (t >= m2 || n2 == 0) {
                    m2 = t;
                    f = p->mUnk_00->mUnk_00[i];
                    n2++;
                }
            }
        } else if (e != -1) {
            n1 = (u16) n1;
            if (func_0207a974(e)->mUnk_4c & 0x40) {
                v3 = TRUE;
            } else {
                v3 = FALSE;
            }
            o = func_0207a974(c);
            func_021484d0(&func_0207a974(e)->mUnk_80, &o->mUnk_80, &x);
            if ((s64) x.x * x.x + (s64) x.y * x.y + (s64) x.z * x.z >= 0x10) {
                func_02039860(&x, &x);
            }
            for (i = 0; i < p->mUnk_00->mUnk_2c; i++) {
                if (p->mUnk_04 == ((const Unk0208001c *) p)->mUnk_00->mUnk_00[i]) {
                    continue;
                }
                func_021484d0(p->mUnk_00->mUnk_00[i]->mUnk_20, &func_0207a974(c)->mUnk_80, &y);
                if ((s64) y.x * y.x + (s64) y.y * y.y + (s64) y.z * y.z >= 0x10) {
                    func_02039860(&y, &y);
                }
                t = func_02039828(&y, b);
                if (t >= -0x800) {
                    if (v3 == FALSE) {
                        u = func_0214848c(&x, &y);
                        if (u > m0 || n0 == 0) {
                            m0 = u;
                            r = p->mUnk_00->mUnk_00[i];
                            n0++;
                        }
                    } else {
                        u = func_0214848c(&x, &y);
                        if (u < m1 || n1 == 0) {
                            m1 = u;
                            r = p->mUnk_00->mUnk_00[i];
                            n1++;
                        }
                    }
                } else if (t >= m2 || n2 == 0) {
                    m2 = t;
                    f = p->mUnk_00->mUnk_00[i];
                    n2++;
                }
            }
        } else {
            for (i = 0; i < p->mUnk_00->mUnk_2c; i++) {
                if (p->mUnk_04 != ((const Unk0208001c *) p)->mUnk_00->mUnk_00[i] &&
                    !(p->mUnk_00->mUnk_2e & (1 << (u8) i))) {
                    v4[n0] = ((const Unk0208001c *) p)->mUnk_00->mUnk_00[i];
                    n0++;
                    n1 = 1;
                }
            }
            if (n1 != 0) {
                l = 0;
                if (n0 > 1) {
                    for (h = 0; h < 2; h++) {
                        func_021484d0(v4[h]->mUnk_20, p->mUnk_00->mUnk_20, &z[h]);
                        if ((s64) z[h].x * z[h].x + (s64) z[h].y * z[h].y + (s64) z[h].z * z[h].z >= 0x10) {
                            func_02039860(&z[h], &z[h]);
                        }
                    }
                    if (func_02039828(&z[0], b) < func_02039828(&z[1], b)) {
                        l = 1;
                    }
                }
                v2[0] = v4[l];
                n = 1;
            } else {
                for (i = 0; i < ((const Unk02175620_bc *) p->mUnk_00)->mUnk_2c; i++) {
                    if (p->mUnk_04 != ((const Unk0208001c *) p)->mUnk_00->mUnk_00[i] &&
                        (p->mUnk_00->mUnk_2e & (1 << (u8) i))) {
                        s = data_021557ec;
                        q = p->mUnk_00->mUnk_00[i];
                        for (j = 0; j < q->mUnk_2c; j++) {
                            if (!(q->mUnk_2e & (1 << j)) && ((const Unk0208001c *) p)->mUnk_00 != q->mUnk_00[j]) {
                                func_021484d0(q->mUnk_00[j]->mUnk_20, q->mUnk_20, &s);
                                if ((s64) s.x * (s64) s.x + (s64) s.y * (s64) s.y + (s64) s.z * (s64) s.z >= 0x10) {
                                    func_02039860(&s, &s);
                                }
                                break;
                            }
                        }
                        t = func_02039828(&s, b);
                        if (t >= -0x800) {
                            v2[n] = p->mUnk_00->mUnk_00[i];
                            n++;
                        } else if (t >= m2 || n2 == 0) {
                            m2 = t;
                            f = p->mUnk_00->mUnk_00[i];
                            n2++;
                        }
                    }
                }
            }
        }
        if (r == NULL) {
            if (n == 0) {
                r = f;
            } else {
                if (n == 1) {
                    k = 0;
                } else {
                    g = func_0208537c();
                    if (n == 0) {
                        v32 = 0;
                    } else {
                        g->mUnk_00 = g->mUnk_08 * g->mUnk_00 + g->mUnk_10;
                        if (n == 0) {
                            v32 = g->mUnk_00 >> 32;
                        } else {
                            v32 = ((g->mUnk_00 >> 32) * (u32) n) >> 32;
                        }
                    }
                    k = v32;
                }
                r = v2[k];
            }
        }
    }
    p->mUnk_00 = r;
    p->mUnk_04 = v1;
    p->mUnk_08 = data_021557ec;
    func_021484d0(p->mUnk_00->mUnk_20, p->mUnk_04->mUnk_20, &p->mUnk_08);
    if ((s64) p->mUnk_08.x * p->mUnk_08.x + (s64) p->mUnk_08.y * p->mUnk_08.y + (s64) p->mUnk_08.z * p->mUnk_08.z >=
        0x10) {
        func_02039860(&p->mUnk_08, &p->mUnk_08);
    }
}
