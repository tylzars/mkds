#include "code_02130a70.h"
#pragma avoid_byte all

#include "code_0213ee6c.h"
#include "code_02134890.h"
#include "code_0213a460.h"
#include "code_0214177c.h"
#include "Main/Unknown/code_02130000.h"

// 1 when a and b have the same mUnk_02 and the same digits (missing digits count as 0), or both have mUnk_05[0] == 0.
int func_0214166c(const Unk02136638 *a, const Unk02136638 *b) {
    int i;
    int m;
    int la;
    int lb;

    if (a->mUnk_05[0] == 0) {
        return b->mUnk_05[0] == 0;
    }
    if (b->mUnk_05[0] == 0) {
        return a->mUnk_05[0] == 0;
    }
    if (a->mUnk_02 == b->mUnk_02) {
        la = a->mUnk_04;
        m = la;
        lb = b->mUnk_04;
        i = 0;
        if (la > lb) {
            m = lb;
        }
        for (; i < m; i++) {
            if (a->mUnk_05[i] != b->mUnk_05[i]) {
                return 0;
            }
        }
        if (m == la) {
            a = b;
        }
        for (; i < a->mUnk_04; i++) {
            if (a->mUnk_05[i] != 0) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

// 1 when a is less than b: compares mUnk_05[0] == 0 first, then mUnk_02, then the digits from mUnk_05[0] on.
int func_02141538(const Unk02136638 *a, const Unk02136638 *b) {
    int i;
    int m;
    int la;
    int lb;
    u32 x;
    u32 y;

    if (a->mUnk_05[0] == 0) {
        return b->mUnk_05[0] != 0;
    }
    if (b->mUnk_05[0] == 0) {
        return 0;
    }
    if (a->mUnk_02 == b->mUnk_02) {
        la = a->mUnk_04;
        m = la;
        lb = b->mUnk_04;
        i = 0;
        if (la > lb) {
            m = lb;
        }
        for (; i < m; i++) {
            x = b->mUnk_05[i];
            y = a->mUnk_05[i];
            if (y < x) {
                return 1;
            }
            if (x < y) {
                return 0;
            }
        }
        if (m == la) {
            for (; i < b->mUnk_04; i++) {
                if (b->mUnk_05[i] != 0) {
                    return 1;
                }
            }
        }
        return 0;
    }
    return a->mUnk_02 < b->mUnk_02;
}

// Copies b to a; if c->mUnk_05[0] is not 0, subtracts c's digits from a's, shifted by mUnk_02, and then drops leading
// and trailing zero digits.
void func_021410bc(Unk02136638 *a, const Unk02136638 *b, const Unk02136638 *c) {
    int n;
    int m;
    int d;
    char *p;
    char *e;
    const char *cb;
    const char *s;
    const char *t;
    int k;
    char *q;
    const char *r;
    int f;

    *a = *b;
    if (c->mUnk_05[0] == 0) {
        return;
    }
    n = a->mUnk_04;
    m = n;
    if (n < c->mUnk_04) {
        m = c->mUnk_04;
    }
    d = a->mUnk_02 - c->mUnk_02;
    m += d;
    if (m > 32) {
        m = 32;
    }
    if (n < m) {
        do {
            a->mUnk_04++;
            a->mUnk_05[n] = 0;
            n = a->mUnk_04;
        } while (n < m);
    }
    p = a->mUnk_05;
    e = p + m;
    if (c->mUnk_04 + d < m) {
        e = p + (c->mUnk_04 + d);
    }
    cb = c->mUnk_05;
    s = cb + (e - p - d);
    t = s;
    while (e > p && s > cb) {
        e--;
        s--;
        if (*e < *s) {
            q = e - 1;
            while (*q == 0) {
                q--;
            }
            while (q != e) {
                (*q)--;
                q++;
                *q += 10;
            }
        }
        *e -= *s;
    }
    k = t - cb;
    if (k < c->mUnk_04) {
        f = 0;
        if (*t < 5) {
            f = 1;
        } else if (*t == 5) {
            r = c->mUnk_05 + c->mUnk_04;
            t++;
            while (t < r) {
                if (*t != 0) {
                    goto done;
                }
                t++;
            }
            e = p + k + d - 1;
            if (*e & 1) {
                f = 1;
            }
        }
        if (f != 0) {
            if (*e < 1) {
                q = e - 1;
                while (*q == 0) {
                    q--;
                }
                while (q != e) {
                    (*q)--;
                    q++;
                    *q += 10;
                }
            }
            (*e)--;
        }
    }
done:
    t = p;
    while (*t == 0) {
        t++;
    }
    if (t > p) {
        char *x;
        u8 cnt;

        cnt = t - p;
        a->mUnk_02 -= cnt;
        x = p + a->mUnk_04;
        while (t < x) {
            *p = *t;
            t++;
            p++;
        }
        a->mUnk_04 -= cnt;
    }
    p = a->mUnk_05;
    t = p + a->mUnk_04;
    while (t > p) {
        t--;
        if (*t != 0) {
            break;
        }
    }
    a->mUnk_04 = t - p + 1;
}

// Fills out from the double v: mUnk_00 is the sign bit. A zero v gives one digit 0; an all-ones exponent gives one
// digit, 0x4e when the mantissa bits are not all 0, else 0x49. Otherwise the digits come from func_02141f14 and
// func_0214177c, combined by func_02141c98.
void func_02140d74(Unk02136638 *out, double v) {
    int e;
    double y1;
    double y2;
    double y3;
    double m;
    Unk02136638 big_a;
    Unk02136638 big_b;
    u32 *w;
    u32 hi;
    u8 sign;
    int k;
    int n;
    int s;

    hi = ((u32 *) &v)[1];
    sign = (hi & 0x80000000) != 0;
    if (v == 0.0) {
        out->mUnk_00 = sign;
        out->mUnk_02 = 0;
        out->mUnk_04 = 1;
        out->mUnk_05[0] = 0;
        return;
    }
    y1 = v;
    switch (((u32 *) &y1)[1] & 0x7ff00000) {
        case 0x7ff00000:
            if ((((u32 *) &y1)[1] & 0xfffff) || ((u32 *) &y1)[0]) {
                k = 1;
            } else {
                k = 2;
            }
            break;
        case 0:
            if ((((u32 *) &y1)[1] & 0xfffff) || ((u32 *) &y1)[0]) {
                k = 5;
            } else {
                k = 3;
            }
            break;
        default:
            k = 4;
            break;
    }
    if (k <= 2) {
        out->mUnk_00 = sign;
        out->mUnk_02 = 0;
        out->mUnk_04 = 1;
        y2 = v;
        switch (((u32 *) &y2)[1] & 0x7ff00000) {
            case 0x7ff00000:
                if ((((u32 *) &y2)[1] & 0xfffff) || ((u32 *) &y2)[0]) {
                    k = 1;
                } else {
                    k = 2;
                }
                break;
            case 0:
                if ((((u32 *) &y2)[1] & 0xfffff) || ((u32 *) &y2)[0]) {
                    k = 5;
                } else {
                    k = 3;
                }
                break;
            default:
                k = 4;
                break;
        }
        out->mUnk_05[0] = k == 1 ? 0x4e : 0x49;
        return;
    }
    if (sign) {
        v = 0.0 - v;
    }
    m = frexp(v, &e);
    y3 = m;
    w = (u32 *) &y3;
    if (w[0]) {
        n = func_021422a0(w[0]);
    } else {
        n = func_021422a0(w[1] | 0x100000) + 0x20;
    }
    s = 0x35 - n;
    func_0214177c(&big_b, e - s);
    func_02141f14(&big_a, (u64) ldexp(m, s));
    func_02141c98(out, &big_a, &big_b);
    out->mUnk_00 = sign;
}

// Calls func_02140d74 on b, then raises mUnk_04 to n (a->mUnk_02, at most 32) by appending 0 entries to mUnk_05,
// lowers b->mUnk_02 by mUnk_04 - 1 and adds 0x30 to every entry. Does nothing more when mUnk_05[0] is above 9.
void func_02140c28(Unk02140c28 *a, double v, Unk02136638 *b) {
    int n;
    int i;

    n = a->mUnk_02;
    func_02140d74(b, v);
    if (b->mUnk_05[0] > 9) {
        return;
    }
    if (n > 32) {
        n = 32;
    }
    func_021420c0(b, n);
    while (b->mUnk_04 < n) {
        b->mUnk_05[b->mUnk_04++] = 0;
    }
    b->mUnk_02 = b->mUnk_02 - (b->mUnk_04 - 1);
    for (i = 0; i < b->mUnk_04; i++) {
        b->mUnk_05[i] += 0x30;
    }
}

double func_0214049c(const Unk02136638 *d) {
    char *p;
    char *end;
    int m;
    u32 v;
    int i;
    u64 *py;
    int j;
    int k;
    double r;
    u64 *pr;
    double x;
    double y;
    double t;
    double s;
    union {
        double d;
        u32 w[2];
    } u1, u2;
    Unk02136638 e;
    Unk02136638 g;
    Unk02136638 a;
    Unk02136638 b;
    Unk02136638 c;
    Unk02136638 f;

    if (d->mUnk_04 == 0) {
        return copysign(0.0, d->mUnk_00 == 0 ? 1.0 : -1.0);
    }
    switch (d->mUnk_05[0]) {
        case '0':
            return copysign(0.0, d->mUnk_00 == 0 ? 1.0 : -1.0);
        case 'I':
            return copysign(data_0216ec98, d->mUnk_00 == 0 ? 1.0 : -1.0);
        case 'N':
            pr = (u64 *) &r;
            *pr = 0x7ff0000000000000ULL;
            if (d->mUnk_00) {
                *pr |= 0x8000000000000000ULL;
            }
            *pr |= 0x0008000000000000ULL;
            return r;
    }
    e = *d;
    for (p = e.mUnk_05, end = p + e.mUnk_04; p < end; p++) {
        *p -= '0';
    }
    e.mUnk_02 += e.mUnk_04 - 1;
    m = e.mUnk_02;
    func_02141b5c(&g, data_0216ef70, 0x134);
    if (func_02141538(&g, &e)) {
        return copysign(data_0216ec98, d->mUnk_00 == 0 ? 1.0 : -1.0);
    }
    p = e.mUnk_05;
    x = *p++;
    while (p < end) {
        int n;

        v = 0;
        n = (end - p) % 8;
        if (n == 0) {
            n = 8;
        }
        for (i = 0; i < n; i++) {
            v = 10 * v + *p;
            p++;
        }
        t = x * data_0216ef30[n - 1];
        s = t + v;
        if (v != 0 && t == s) {
            break;
        }
        x = s;
        m -= n;
    }
    if (m < 0) {
        x = x / pow(5.0, -m);
    } else {
        x = x * pow(5.0, m);
    }
    x = ldexp(x, m);
    u1.d = x;
    switch (u1.w[1] & 0x7ff00000) {
        case 0x7ff00000:
            if ((u1.w[1] & 0xfffff) || u1.w[0]) {
                k = 1;
            } else {
                k = 2;
            }
            break;
        case 0:
            if ((u1.w[1] & 0xfffff) || u1.w[0]) {
                k = 5;
            } else {
                k = 3;
            }
            break;
        default:
            k = 4;
            break;
    }
    if (k == 2) {
        x = 1.7976931348623157e+308;
    }
    py = (u64 *) &y;
    j = 0;
    func_02140d74(&a, x);
    if (!func_0214166c(&a, &e)) {
        if (func_02141538(&a, &e)) {
            j = 1;
        }
        y = x;
        for (;;) {
            if (j) {
                (*py)++;
                u2.d = y;
                switch (u2.w[1] & 0x7ff00000) {
                    case 0x7ff00000:
                        if ((u2.w[1] & 0xfffff) || u2.w[0]) {
                            k = 1;
                        } else {
                            k = 2;
                        }
                        break;
                    case 0:
                        if ((u2.w[1] & 0xfffff) || u2.w[0]) {
                            k = 5;
                        } else {
                            k = 3;
                        }
                        break;
                    default:
                        k = 4;
                        break;
                }
                if (k == 2) {
                    goto done;
                }
            } else {
                (*py)--;
            }
            func_02140d74(&b, y);
            if (j && !func_02141538(&b, &e)) {
                break;
            }
            if (!j && !func_02141538(&e, &b)) {
                c = a;
                a = b;
                b = c;
                t = x;
                x = y;
                y = t;
                break;
            }
            a = b;
            x = y;
        }
        func_021410bc(&c, &e, &a);
        func_021410bc(&f, &b, &e);
        if (func_0214166c(&c, &f)) {
            if (*(u64 *) &x & 1) {
                x = y;
            }
        } else if (!func_02141538(&c, &f)) {
            x = y;
        }
    }
done:
    if (e.mUnk_00) {
        x = -x;
    }
    return x;
}

double pow(double a, double b) {
    return func_0213ee6c(a, b);
}

// Classifies the exponent field of d: 1 and 2 when it is all ones (1 with mantissa bits set, 2 without), 3 and 5
// when it is zero (3 with a zero mantissa, 5 otherwise), 4 otherwise.
static inline int func_021401ac_inline(double d) {
    int m = *((int *) &d + 1) & 0x7ff00000;

    switch (m) {
        case 0x7ff00000:
            if ((*((int *) &d + 1) & 0xfffff) != 0 || *(int *) &d != 0) {
                return 1;
            }
            return 2;
        case 0:
            if ((*((int *) &d + 1) & 0xfffff) != 0 || *(int *) &d != 0) {
                return 5;
            }
            return 3;
    }
    return 4;
}

// Adds n to the exponent field of x, scaling with multiplications by constants when it leaves the normal range.
double ldexp(double x, int n) {
    int h;
    int l;
    int k;

    if (func_021401ac_inline(x) <= 2 || 0.0 == x) {
        return x;
    }
    h = *((int *) &x + 1);
    l = *(int *) &x;
    k = (h & 0x7ff00000) >> 20;
    if (k == 0) {
        if ((l | (h & 0x7fffffff)) == 0) {
            return x;
        }
        x *= 18014398509481984.0;
        h = *((int *) &x + 1);
        k = ((h & 0x7ff00000) >> 20) - 54;
        if (n < -50000) {
            return 1e-300 * x;
        }
    }
    if (k == 0x7ff) {
        return x + x;
    }
    k += n;
    if (k > 0x7fe) {
        return 1e300 * copysign(1e300, x);
    }
    if (k > 0) {
        *((int *) &x + 1) = (h & 0x800fffff) | (k << 20);
        return x;
    }
    if (k <= -54) {
        if (n > 50000) {
            return 1e300 * copysign(1e300, x);
        }
        return 1e-300 * copysign(1e-300, x);
    }
    k += 54;
    *((int *) &x + 1) = (h & 0x800fffff) | (k << 20);
    return x * 5.551115123125783e-17;
}

// Splits a into a fraction with an exponent field of 0x3fe and the exponent count stored to *e (0 and a unchanged
// when a is zero or has an all-ones exponent field).
double frexp(double a, int *e) {
    int m;
    int h;
    int l;

    h = *((int *) &a + 1);
    l = *(int *) &a;
    m = h & 0x7fffffff;
    *e = 0;
    if (m >= 0x7ff00000 || (m | l) == 0) {
        return a;
    }
    if (m < 0x100000) {
        a *= 18014398509481984.0;
        h = *((int *) &a + 1);
        m = h & 0x7fffffff;
        *e = -54;
    }
    *e += (m >> 20) - 1022;
    *((int *) &a + 1) = (h & 0x800fffff) | 0x3fe00000;
    return a;
}

// Clears the sign bit of a.
double fabs(double a) {
    *((u32 *) &a + 1) &= 0x7fffffff;
    return a;
}

// a with the sign bit of b.
double copysign(double a, double b) {
    *((u32 *) &a + 1) = (*((u32 *) &a + 1) & 0x7fffffff) | (*((u32 *) &b + 1) & 0x80000000);
    return a;
}

double func_0213ee6c(double a, double b) {
    static const double k0 = -1.904654299957768e-09;
    int q;
    double z, c, p1, b1, t1, t, s1, t3;
    double d, u, v, w, r, s, s0, s2, s3, t2, t4, z1, z2, p2;
    int i, j, k, m, n, e;
    int ha, hb, ia, ib;
    u32 la, lb;

    hb = *(1 + (int *) &b);
    lb = *(u32 *) &b;
    ha = *(1 + (int *) &a);
    la = *(u32 *) &a;
    ib = hb & 0x7fffffff;
    ia = ha & 0x7fffffff;

    if ((ib | lb) == 0) {
        return 1.0;
    }
    if (ia > 0x7ff00000 || (ia == 0x7ff00000 && la != 0) || ib > 0x7ff00000 || (ib == 0x7ff00000 && lb != 0)) {
        return a + b;
    }

    m = 0;
    if (ha < 0) {
        if (ib >= 0x43400000) {
            m = 2;
        } else if (ib >= 0x3ff00000) {
            k = (ib >> 20) - 0x3ff;
            if (k > 20) {
                j = lb >> (52 - k);
                if ((j << (52 - k)) == lb) {
                    m = 2 - (j & 1);
                }
            } else if (lb == 0) {
                j = ib >> (20 - k);
                if ((j << (20 - k)) == ib) {
                    m = 2 - (j & 1);
                }
            }
        }
    }

    if (lb == 0) {
        if (ib == 0x7ff00000) {
            if (((ia - 0x3ff00000) | la) == 0) {
                return b - b;
            } else if (ia >= 0x3ff00000) {
                return hb >= 0 ? b : 0.0;
            } else {
                return hb < 0 ? -b : 0.0;
            }
        }
        if (ib == 0x3ff00000) {
            if (hb < 0) {
                return 1.0 / a;
            } else {
                return a;
            }
        }
        if (hb == 0x40000000) {
            return a * a;
        }
        if (hb == 0x3fe00000) {
            if (ha >= 0) {
                return func_02130a70(a);
            }
        }
    }

    d = a;
    c = fabs(d);
    if (la == 0) {
        if (ia == 0x7ff00000 || ia == 0 || ia == 0x3ff00000) {
            z = c;
            if (hb < 0) {
                z = 1.0 / z;
            }
            if (ha < 0) {
                if (((ia - 0x3ff00000) | m) == 0) {
                    z = (z - z) / (z - z);
                } else if (m == 1) {
                    z = -z;
                }
            }
            return z;
        }
    }

    n = (ha >> 31) + 1;
    if ((n | m) == 0) {
        data_0217ee90 = 33;
        return data_0216ec9c;
    }

    if (ib > 0x41e00000) {
        if (ib > 0x43f00000) {
            if (ia <= 0x3fefffff) {
                return hb < 0 ? 1e300 * 1e300 : 0.0;
            }
            if (ia >= 0x3ff00000) {
                return hb > 0 ? 1e300 * 1e300 : 0.0;
            }
        }
        if (ia < 0x3fefffff) {
            return hb < 0 ? 1e300 * 1e300 : 0.0;
        }
        if (ia > 0x3ff00000) {
            return hb > 0 ? 1e300 * 1e300 : 0.0;
        }
        t = d - 1.0;
        w = (t * t) * (0.5 - t * (0.3333333333333333 - t * 0.25));
        u = 1.4426950216293335 * t;
        v = t * 1.9259629911266175e-08 - w * 1.4426950408889634;
        t1 = u + v;
        *(int *) &t1 = 0;
        t2 = v - (t1 - u);
    } else {
        e = 0;
        if (ia < 0x00100000) {
            c *= 9007199254740992.0;
            e -= 53;
            ia = *(1 + (int *) &c);
        }
        e += (ia >> 20) - 0x3ff;
        j = ia & 0x000fffff;
        ia = j | 0x3ff00000;
        if (j <= 0x3988e) {
            k = 0;
        } else if (j < 0xbb67a) {
            k = 1;
        } else {
            k = 0;
            e += 1;
            ia -= 0x00100000;
        }
        *(1 + (int *) &c) = ia;

        u = c - data_0215d494[k];
        v = 1.0 / (c + data_0215d494[k]);
        s0 = u * v;
        s1 = s0;
        *(int *) &s1 = 0;
        t3 = 0.0;
        *(1 + (int *) &t3) = ((ia >> 1) | 0x20000000) + 0x00080000 + (k << 18);
        t4 = c - (t3 - data_0215d494[k]);
        s3 = v * ((u - s1 * t3) - s1 * t4);
        s2 = s0 * s0;
        r = s2 * s2 *
            (0.5999999999999946 +
             s2 * (0.4285714285785502 +
                   s2 * (0.33333332981837743 +
                         s2 * (0.272728123808534 + s2 * (0.23066074577556175 + s2 * 0.20697501780033842)))));
        r += s3 * (s1 + s0);
        s2 = s1 * s1;
        t3 = 3.0 + s2 + r;
        *(int *) &t3 = 0;
        t4 = r - ((t3 - 3.0) - s2);
        u = s1 * t3;
        v = s3 * t3 + t4 * s0;
        p1 = u + v;
        *(int *) &p1 = 0;
        p2 = v - (p1 - u);
        z1 = 0.9617967009544373 * p1;
        z2 = data_0215d4a4[k] + (-7.028461650952758e-09 * p1 + p2 * 0.9617966939259756);
        t = e;
        t1 = ((z1 + z2) + data_0215d484[k]) + t;
        *(int *) &t1 = 0;
        t2 = z2 - (((t1 - t) - data_0215d484[k]) - z1);
    }

    s = 1.0;
    if ((n | (m - 1)) == 0) {
        s = -1.0;
    }
    b1 = b;
    *(int *) &b1 = 0;
    p2 = (b - b1) * t1 + b * t2;
    p1 = b1 * t1;
    z = p2 + p1;
    j = *(1 + (int *) &z);
    i = *(int *) &z;
    if (j >= 0x40900000) {
        if (((j - 0x40900000) | i) != 0) {
            return s * 1e300 * 1e300;
        } else if (p2 + 8.008566259537294e-17 > z - p1) {
            return s * 1e300 * 1e300;
        }
    } else if ((j & 0x7fffffff) >= 0x4090cc00) {
        if (((j - 0xc090cc00) | i) != 0) {
            return s * 1e-300 * 1e-300;
        } else if (p2 <= z - p1) {
            return s * 1e-300 * 1e-300;
        }
    }

    i = j & 0x7fffffff;
    k = (i >> 20) - 0x3ff;
    q = 0;
    if (i > 0x3fe00000) {
        i = j + (0x00100000 >> (k + 1));
        k = ((i & 0x7fffffff) >> 20) - 0x3ff;
        t = 0.0;
        *(1 + (int *) &t) = i & ~(0x000fffff >> k);
        q = ((i & 0x000fffff) | 0x00100000) >> (20 - k);
        if (j < 0) {
            q = -q;
        }
        p1 -= t;
    }
    t = p2 + p1;
    *(int *) &t = 0;
    u = t * 0.6931471824645996;
    v = (p2 - (t - p1)) * 0.6931471805599453 + t * k0;
    z = u + v;
    w = v - (z - u);
    t = z * z;
    t1 = z - t * (0.16666666666666602 +
                  t * (-0.0027777777777015593 +
                       t * (6.613756321437934e-05 + t * (-1.6533902205465252e-06 + t * 4.1381367970572385e-08))));
    r = (z * t1) / (t1 - 2.0) - (w + z * w);
    z = 1.0 - (r - z);
    j = *(1 + (int *) &z);
    j += q << 20;
    if ((j >> 20) <= 0) {
        z = func_02134ae8(z, q);
    } else {
        *(1 + (int *) &z) += q << 20;
    }
    return s * z;
}
