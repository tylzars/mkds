#pragma avoid_byte all

#include "code_0213a460.h"
#include "code_02134398.h"
#include "code_021384cc.h"
#include "code_0213cae0.h"
#include "code_0213ee6c.h"

// Reads values through f(p, 0, 0), at most b of them, in base a. st is the state: 1, 2, 4, 8 and 0x10 while
// reading, 0x20 or 0x40 once it stops. *q gets the count used, *r 1 after a '-', *s 1 when the value does not fit.
u32 ScanInt32(int a, int b, Unk02138618Func f, ScanStringSource *p, int *q, int *r, int *s) {
    int st;
    int n;
    int k;
    int c;
    u32 acc;
    u32 lim;

    k = 0;
    *r = *s = 0;
    st = 1;
    n = k;
    acc = k;
    lim = k;
    if (a < 0 || a == 1 || a > 36 || b < 1) {
        st = 0x40;
    } else {
        n++;
        c = f(p, 0, 0);
    }
    if (a != 0) {
        lim = 0xffffffffU / a;
    }
    while (n <= b && c != -1 && !(st & 0x60)) {
        switch (st) {
            case 1:
                if ((c < 0 || c >= 0x80) ? 0 : data_0215d284[c] & 0x100) {
                    c = f(p, 0, 0);
                    k++;
                } else {
                    if (c == '+') {
                        n++;
                        c = f(p, 0, 0);
                    } else if (c == '-') {
                        n++;
                        c = f(p, 0, 0);
                        *r = 1;
                    }
                    st = 2;
                }
                break;
            case 2:
                if ((a == 0 || a == 16) && c == '0') {
                    st = 4;
                    n++;
                    c = f(p, 0, 0);
                } else {
                    st = 8;
                }
                break;
            case 4:
                if (c == 'X' || c == 'x') {
                    a = 16;
                    st = 8;
                    n++;
                    c = f(p, 0, 0);
                } else {
                    if (a == 0) {
                        a = 8;
                    }
                    st = 0x10;
                }
                break;
            case 8:
            case 0x10:
                if (a == 0) {
                    a = 10;
                }
                if (lim == 0) {
                    lim = 0xffffffffU / a;
                }
                if ((c < 0 || c >= 0x80) ? 0 : data_0215d284[c] & 0x8) {
                    c -= '0';
                    if (c >= a) {
                        st = st == 0x10 ? 0x20 : 0x40;
                        c += '0';
                        break;
                    }
                } else {
                    if (!(((c < 0 || c >= 0x80) ? 0 : data_0215d284[c] & 0x1) &&
                          ((c < 0 || c >= 0x80) ? c : data_0215d204[c]) - 0x37 < a)) {
                        st = st == 0x10 ? 0x20 : 0x40;
                        break;
                    }
                    c = (c < 0 || c >= 0x80) ? c : data_0215d204[c];
                    c -= 0x37;
                }
                if (acc > lim) {
                    *s = 1;
                }
                acc *= a;
                if (c > 0xffffffffU - acc) {
                    *s = 1;
                }
                acc += c;
                st = 0x10;
                n++;
                c = f(p, 0, 0);
                break;
        }
    }
    if (!(st & 0x34)) {
        *q = acc = 0;
    } else {
        *q = n - 1 + k;
    }
    f(p, c, 1);
    return acc;
}

// Same as ScanInt32 with a 64-bit result.
u64 ScanInt64(int a, int b, Unk02138618Func f, void *p, int *q, int *r, int *s) {
    int st;
    int n;
    int k;
    int c;
    u64 acc;
    u64 lim;

    k = 0;
    *r = *s = 0;
    st = 1;
    n = k;
    acc = k;
    lim = k;
    if (a < 0 || a == 1 || a > 36 || b < 1) {
        st = 0x40;
    } else {
        n++;
        c = f(p, 0, 0);
    }
    if (a != 0) {
        lim = 0xffffffffffffffffULL / a;
    }
    while (n <= b && c != -1 && !(st & 0x60)) {
        switch (st) {
            case 1:
                if ((c < 0 || c >= 0x80) ? 0 : data_0215d284[c] & 0x100) {
                    c = f(p, 0, 0);
                    k++;
                } else {
                    if (c == '+') {
                        n++;
                        c = f(p, 0, 0);
                    } else if (c == '-') {
                        n++;
                        c = f(p, 0, 0);
                        *r = 1;
                    }
                    st = 2;
                }
                break;
            case 2:
                if ((a == 0 || a == 16) && c == '0') {
                    st = 4;
                    n++;
                    c = f(p, 0, 0);
                } else {
                    st = 8;
                }
                break;
            case 4:
                if (c == 'X' || c == 'x') {
                    a = 16;
                    st = 8;
                    n++;
                    c = f(p, 0, 0);
                } else {
                    if (a == 0) {
                        a = 8;
                    }
                    st = 0x10;
                }
                break;
            case 8:
            case 0x10:
                if (a == 0) {
                    a = 10;
                }
                if (lim == 0) {
                    lim = 0xffffffffffffffffULL / a;
                }
                if ((c < 0 || c >= 0x80) ? 0 : data_0215d284[c] & 0x8) {
                    c -= '0';
                    if (c >= a) {
                        st = st == 0x10 ? 0x20 : 0x40;
                        c += '0';
                        break;
                    }
                } else {
                    if (!(((c < 0 || c >= 0x80) ? 0 : data_0215d284[c] & 0x1) &&
                          ((c < 0 || c >= 0x80) ? c : data_0215d204[c]) - 0x37 < a)) {
                        st = st == 0x10 ? 0x20 : 0x40;
                        break;
                    }
                    c = (c < 0 || c >= 0x80) ? c : data_0215d204[c];
                    c -= 0x37;
                }
                if (acc > lim) {
                    *s = 1;
                }
                acc *= a;
                if (c > 0xffffffffffffffffULL - acc) {
                    *s = 1;
                }
                acc += c;
                st = 0x10;
                n++;
                c = f(p, 0, 0);
                break;
        }
    }
    if (!(st & 0x34)) {
        *q = acc = 0;
    } else {
        *q = n - 1 + k;
    }
    f(p, c, 1);
    return acc;
}

u32 strtoul(const char *s, const char **end, int base) {
    int n;
    int neg;
    int ovf;
    ScanStringSource st;
    u32 v;

    st.mNextChar = s;
    st.mAtEnd = 0;
    v = ScanInt32(base, 0x7fffffff, ScanStringSourceOp, &st, &n, &neg, &ovf);
    if (end != 0) {
        *end = s + n;
    }
    if (ovf != 0) {
        gLibErrorCode = 0x22;
        return -1;
    }
    if (neg != 0) {
        v = -v;
    }
    return v;
}

long strtol(const char *s, const char **end, int base) {
    int n;
    int neg;
    int ovf;
    ScanStringSource st;
    u32 v;

    st.mNextChar = s;
    st.mAtEnd = 0;
    v = ScanInt32(base, 0x7fffffff, ScanStringSourceOp, &st, &n, &neg, &ovf);
    if (end != 0) {
        *end = s + n;
    }
    if (ovf != 0 || (neg == 0 && v > 0x7fffffff) || (neg != 0 && v > 0x80000000)) {
        v = neg != 0 ? 0x80000000 : 0x7fffffff;
        gLibErrorCode = 0x22;
        return v;
    }
    if (neg != 0) {
        v = -v;
    }
    return v;
}

long StrtolBase10(const char *s) {
    return strtol(s, 0, 10);
}

/* f is called as f(p, 0, 0) for each next value and as f(p, c, 1) with a value already read. */
double ScanDouble(int a, Unk02138618Func f, void *p, int *q, int *r) {
    int s = 1;
    int h = 0;
    int n = 0;
    int c;
    int w = 0;
    int m;
    int em;
    int e;
    int ea;
    int sg;
    char *hp;
    char *hz;
    u32 lim;
    int he;
    int hk;
    int hm;
    u32 hd;
    double x;
    DigitRecord rec = {0};
    char hb[8];

    m = 0;
    *r = 0;
    em = 0;
    e = 0;
    ea = 0;
    sg = 0;
    he = 0;
    hm = 0;
    hd = 0;
    hz = hb;
    n++;
    c = f(p, 0, 0);

    while (n <= a && c != -1 && !(s & 0x1800)) {
        switch (s) {
            case 1:
                if ((c < 0 || c >= 0x80) ? 0 : data_0215d284[c] & 0x100) {
                    c = f(p, 0, 0);
                    w++;
                } else {
                    switch ((c < 0 || c >= 0x80) ? c : data_0215d204[c]) {
                        case '-':
                            m = 1;
                    /* fall through */
                        case '+':
                            n++;
                            c = f(p, 0, 0);
                            sg = 1;
                            break;
                        case 'I':
                            n++;
                            c = f(p, 0, 0);
                            s = 0x4000;
                            break;
                        case 'N':
                            n++;
                            c = f(p, 0, 0);
                            s = 0x2000;
                            break;
                        default:
                            s = 2;
                            break;
                    }
                }
                break;
            case 0x4000: {
                int i = 1;
                char t[9] = "INFINITY";
                char *tp;

                tp = t + 1;
                while (i < 8 && *tp == ((c < 0 || c >= 0x80) ? c : data_0215d204[c])) {
                    tp++;
                    i++;
                    n++;
                    c = f(p, 0, 0);
                }
                if (i == 3 || i == 8) {
                    if (m) {
                        x = -data_0216ec98;
                    } else {
                        x = data_0216ec98;
                    }
                    *q = w + i + sg;
                    return x;
                }
                s = 0x1000;
                break;
            }
            case 0x2000: {
                int i = 1;
                int j = 0;
                char t[5] = "NAN(";
                char buf[32] = {0};
                char *tp;

                tp = t + 1;
                while (i < 4 && *tp == ((c < 0 || c >= 0x80) ? c : data_0215d204[c])) {
                    tp++;
                    i++;
                    n++;
                    c = f(p, 0, 0);
                }
                if (i == 3 || i == 4) {
                    if (i == 4) {
                        while (j < 32 && (((c < 0 || c >= 0x80) ? 0 : data_0215d284[c] & 0x8) ||
                                          ((c < 0 || c >= 0x80) ? 0 : data_0215d284[c] & 0x1) || c == '.')) {
                            buf[j++] = c;
                            n++;
                            c = f(p, 0, 0);
                        }
                        if (c != ')') {
                            s = 0x1000;
                            break;
                        }
                        j++;
                    }
                    buf[j] = 0;
                    if (m) {
                        x = -nan(buf);
                    } else {
                        x = nan(buf);
                    }
                    *q = w + i + j + sg;
                    return x;
                }
                s = 0x1000;
                break;
            }
            case 2:
                if (c == '.') {
                    s = 0x10;
                    n++;
                    c = f(p, 0, 0);
                } else if (!((c < 0 || c >= 0x80) ? 0 : data_0215d284[c] & 0x8)) {
                    s = 0x1000;
                } else if (c == '0') {
                    int t;

                    n++;
                    c = t = f(p, 0, 0);
                    if (((t < 0 || t >= 0x80) ? t : data_0215d204[t]) == 'X') {
                        s = 0x8000;
                        h = 1;
                    } else {
                        s = 4;
                    }
                } else {
                    s = 8;
                }
                break;
            case 4:
                if (c == '0') {
                    n++;
                    c = f(p, 0, 0);
                } else {
                    s = 8;
                }
                break;
            case 8:
                if (!((c < 0 || c >= 0x80) ? 0 : data_0215d284[c] & 0x8)) {
                    if (c == '.') {
                        s = 0x20;
                        n++;
                        c = f(p, 0, 0);
                    } else {
                        s = 0x40;
                    }
                } else {
                    if (rec.mDigitCount < 20) {
                        rec.mDigits[rec.mDigitCount++] = c;
                    } else {
                        ea++;
                    }
                    n++;
                    c = f(p, 0, 0);
                }
                break;
            case 0x10:
                if (!((c < 0 || c >= 0x80) ? 0 : data_0215d284[c] & 0x8)) {
                    s = 0x1000;
                } else {
                    s = 0x20;
                }
                break;
            case 0x20:
                if (!((c < 0 || c >= 0x80) ? 0 : data_0215d284[c] & 0x8)) {
                    s = 0x40;
                } else {
                    if (rec.mDigitCount < 20) {
                        if (c != '0' || rec.mDigitCount != 0) {
                            rec.mDigits[rec.mDigitCount++] = c;
                        }
                        ea--;
                    }
                    n++;
                    c = f(p, 0, 0);
                }
                break;
            case 0x40:
                if (((c < 0 || c >= 0x80) ? c : data_0215d204[c]) == 'E') {
                    s = 0x80;
                    n++;
                    c = f(p, 0, 0);
                } else {
                    s = 0x800;
                }
                break;
            case 0x80:
                if (c == '+') {
                    n++;
                    c = f(p, 0, 0);
                } else if (c == '-') {
                    n++;
                    c = f(p, 0, 0);
                    em = 1;
                }
                s = 0x100;
                break;
            case 0x100:
                if (!((c < 0 || c >= 0x80) ? 0 : data_0215d284[c] & 0x8)) {
                    s = 0x1000;
                } else if (c == '0') {
                    s = 0x200;
                    n++;
                    c = f(p, 0, 0);
                } else {
                    s = 0x400;
                }
                break;
            case 0x200:
                if (c == '0') {
                    n++;
                    c = f(p, 0, 0);
                } else {
                    s = 0x400;
                }
                break;
            case 0x400:
                if (!((c < 0 || c >= 0x80) ? 0 : data_0215d284[c] & 0x8)) {
                    s = 0x800;
                } else {
                    e = e * 10 + (c - '0');
                    if (e > 0x7fff) {
                        *r = 1;
                    }
                    n++;
                    c = f(p, 0, 0);
                }
                break;
            case 0x8000:
                switch (h) {
                    case 1:
                        hz[0] = 0;
                        hz[1] = 0;
                        hz[2] = 0;
                        hz[3] = 0;
                        hz[4] = 0;
                        hz[5] = 0;
                        hz[6] = 0;
                        hz[7] = 0;
                        hp = hz;
                        lim = 14;
                        hd = 0;
                        hk = 0;
                        h = 2;
                        n++;
                        c = f(p, 0, 0);
                        break;
                    case 2:
                        if (c == '0') {
                            n++;
                            c = f(p, 0, 0);
                        } else {
                            h = 4;
                        }
                        break;
                    case 4:
                        if (!((c < 0 || c >= 0x80) ? 0 : data_0215d284[c] & 0x400)) {
                            if (c == '.') {
                                h = 8;
                                n++;
                                c = f(p, 0, 0);
                            } else {
                                h = 0x10;
                            }
                        } else if (hd < lim) {
                            u8 v;
                            u8 d;
                            int t;

                            hd++;
                            v = hp[hk / 2];
                            t = (c < 0 || c >= 0x80) ? c : data_0215d204[c];
                            d = t >= 'A' ? t - 0x37 : t - '0';
                            if (hk % 2) {
                                v |= d;
                            } else {
                                v |= (u8) (d << 4);
                            }
                            hp[hk++ / 2] = v;
                            n++;
                            c = f(p, 0, 0);
                        } else {
                            n++;
                            c = f(p, 0, 0);
                        }
                        break;
                    case 8:
                        if (!((c < 0 || c >= 0x80) ? 0 : data_0215d284[c] & 0x400)) {
                            h = 0x10;
                        } else if (hd < lim) {
                            u8 v;
                            u8 d;
                            int t;

                            v = hp[hk / 2];
                            t = (c < 0 || c >= 0x80) ? c : data_0215d204[c];
                            d = t >= 'A' ? t - 0x37 : t - '0';
                            if (hk % 2) {
                                v |= d;
                            } else {
                                v |= (u8) (d << 4);
                            }
                            hp[hk++ / 2] = v;
                            n++;
                            c = f(p, 0, 0);
                        } else {
                            n++;
                            c = f(p, 0, 0);
                        }
                        break;
                    case 0x10:
                        if (((c < 0 || c >= 0x80) ? c : data_0215d204[c]) == 'P') {
                            h = 0x20;
                            n++;
                            c = f(p, 0, 0);
                        } else {
                            s = 0x800;
                        }
                        break;
                    case 0x20:
                        if (c == '-') {
                            hm = 1;
                        } else if (c != '+') {
                            f(p, c, 1);
                            n--;
                        }
                        h = 0x40;
                        n++;
                        c = f(p, 0, 0);
                        break;
                    case 0x40:
                        if (!((c < 0 || c >= 0x80) ? 0 : data_0215d284[c] & 0x8)) {
                            s = 0x1000;
                        } else if (c == '0') {
                            h = 0x80;
                            n++;
                            c = f(p, 0, 0);
                        } else {
                            h = 0x100;
                        }
                        break;
                    case 0x80:
                        if (c == '0') {
                            n++;
                            c = f(p, 0, 0);
                        } else {
                            h = 0x100;
                        }
                        break;
                    case 0x100:
                        if (!((c < 0 || c >= 0x80) ? 0 : data_0215d284[c] & 0x8)) {
                            s = 0x800;
                        } else {
                            he = he * 10 + (c - '0');
                            if (e > 0x7fff) {
                                *r = 1;
                            }
                            n++;
                            c = f(p, 0, 0);
                        }
                        break;
                }
                break;
        }
    }

    if (s != 0x8000 ? !(s & 0xe2c) : (n - 1 <= 2 || !(h & 0x18e))) {
        *q = 0;
    } else {
        *q = n - 1 + w;
    }
    f(p, c, 1);

    if (h == 0) {
        int k;
        char *dp;

        if (em) {
            e = -e;
        }
        k = rec.mDigitCount;
        dp = &rec.mDigits[k];
        while (k-- != 0 && *--dp == '0') {
            ea++;
        }
        rec.mDigitCount = k + 1;
        if (rec.mDigitCount == 0) {
            rec.mDigits[rec.mDigitCount++] = '0';
        }
        e += ea;
        if (e < -0x8000 || e > 0x7fff) {
            *r = 1;
        }
        if (*r) {
            if (em) {
                return 0.0;
            }
            if (!m) {
                return data_0216eca0;
            }
            return -data_0216eca0;
        }
        rec.mExponent = e;
        x = DigitCharsToDouble(&rec);
        if (x != 0.0 && x < 2.2250738585072014e-308) {
            *r = 1;
        } else if (x > 1.7976931348623157e+308) {
            *r = 1;
            x = data_0216eca0;
        }
        if (m && (s & 0xe2c)) {
            x = -x;
        }
        return x;
    } else {
        u32 i;
        u32 b;
        u32 bp;
        u8 *ob;
        u8 v;
        int j;
        u8 cy;
        u32 sh;
        u32 t;
        double u;

        ob = (u8 *) &u;
        if (hm) {
            he = -he;
        }
        he += hd * 4;
        for (i = 0; i < 4 && !(hb[0] & (0x80 >> i)); i++) {
            he--;
        }
        i++;
        if (i != 0) {
            cy = 0;
            for (hp = hb + 7; hp >= hb; hp--) {
                v = *hp;
                *hp = cy | (v << i);
                cy = v >> (8 - i);
            }
        }
        ob[0] = 0;
        ob[1] = 0;
        ob[2] = 0;
        ob[3] = 0;
        ob[4] = 0;
        ob[5] = 0;
        ob[6] = 0;
        ob[7] = 0;
        for (b = 0, bp = 12; b < 52; b += 8) {
            v = hb[b / 8];
            if (b + 8 > 52) {
                v &= 0xff << (52 - b);
            }
            sh = bp % 8;
            ob[bp / 8] |= (u8) (v >> sh);
            bp += 8;
            ob[bp / 8] |= (u8) (v << (8 - sh));
        }
        t = he + 0x3fe;
        if (t & -0x800) {
            *r = 1;
            return 0.0;
        }
        ob[0] |= (t << 21) >> 25;
        ob[1] |= (t << 21) >> 17;
        if (m) {
            ob[0] |= 0x80;
        }
        for (j = 0; j < 4; j++) {
            v = ob[j];
            ob[j] = ob[7 - j];
            ob[7 - j] = v;
        }
        return *(double *) ob;
    }
}

double strtod(const char *s, const char **end) {
    int n;
    int ovf;
    ScanStringSource st;
    double v;
    double a;

    st.mNextChar = s;
    st.mAtEnd = 0;
    v = ScanDouble(0x7fffffff, ScanStringSourceOp, &st, &n, &ovf);
    if (end != 0) {
        *end = s + n;
    }
    a = fabs(v);
    if (ovf != 0 || (v != 0.0 && (a < 2.2250738585072014e-308 || a > 1.7976931348623157e308))) {
        gLibErrorCode = 0x22;
    }
    return v;
}
