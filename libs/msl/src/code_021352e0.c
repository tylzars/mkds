#pragma avoid_byte all

#include "code_021352e0.h"
#include "code_02134b18.h"
#include "code_02134d30.h"
#include "code_02139f70.h"
#include "code_0213a460.h"
#include "code_0213ee6c.h"

const char *FormatParseSpec(const char *p, char **b, FormatSpec *buf) {
    const char *s;
    FormatSpec v;
    int c;
    int n;
    int w;

    v.mPadKind = 1;
    v.mSignKind = 0;
    v.mHasDot = 0;
    v.mHash = 0;
    v.mArgKind = 0;
    v.mMinLength = 0;
    v.mUnk_0c = 0;
    s = p + 1;
    c = *s;
    if (c == '%') {
        v.mSpecChar = c;
        *buf = v;
        return s + 1;
    }
    for (;;) {
        n = 1;
        switch (c) {
            case '-':
                v.mPadKind = 0;
                break;
            case '+':
                v.mSignKind = 1;
                break;
            case ' ':
                if (v.mSignKind != 1) {
                    v.mSignKind = 2;
                }
                break;
            case '#':
                v.mHash = 1;
                break;
            case '0':
                if (v.mPadKind != 0) {
                    v.mPadKind = 2;
                }
                break;
            default:
                n = 0;
                break;
        }
        if (!n) {
            break;
        }
        c = *++s;
    }
    if (c == '*') {
        *b += 4;
        w = ((int *) *b)[-1];
        v.mMinLength = w;
        if (w < 0) {
            v.mPadKind = 0;
            v.mMinLength = -w;
        }
        c = *++s;
    } else {
        while ((c < 0 || c >= 0x80) ? 0 : (data_0215d284[c] & 8)) {
            v.mMinLength = v.mMinLength * 10 + (c - '0');
            c = *++s;
        }
    }
    if (v.mMinLength > 0x1fd) {
        v.mSpecChar = 0xff;
        *buf = v;
        return s + 1;
    }
    if (c == '.') {
        v.mHasDot = 1;
        c = *++s;
        if (c == '*') {
            *b += 4;
            v.mUnk_0c = ((int *) *b)[-1];
            if (v.mUnk_0c < 0) {
                v.mHasDot = 0;
            }
            c = *++s;
        } else {
            while ((c < 0 || c >= 0x80) ? 0 : (data_0215d284[c] & 8)) {
                v.mUnk_0c = v.mUnk_0c * 10 + (c - '0');
                c = *++s;
            }
        }
    }
    n = 1;
    switch (c) {
        case 'h':
            v.mArgKind = 2;
            if (s[1] == 'h') {
                v.mArgKind = 1;
                c = *++s;
            }
            break;
        case 'l':
            v.mArgKind = 3;
            if (s[1] == 'l') {
                v.mArgKind = 7;
                c = *++s;
            }
            break;
        case 'L':
            v.mArgKind = 8;
            break;
        case 'j':
            v.mArgKind = 4;
            break;
        case 'z':
            v.mArgKind = 5;
            break;
        case 't':
            v.mArgKind = 6;
            break;
        default:
            n = 0;
            break;
    }
    if (n) {
        c = *++s;
    }
    v.mSpecChar = c;
    switch (c) {
        case 'd':
        case 'i':
        case 'o':
        case 'u':
        case 'x':
        case 'X':
            if (v.mArgKind == 8) {
                v.mSpecChar = 0xff;
            } else if (v.mHasDot == 0) {
                v.mUnk_0c = 1;
            } else if (v.mPadKind == 2) {
                v.mPadKind = 1;
            }
            break;
        case 'f':
        case 'F':
            if (v.mArgKind == 2 || v.mArgKind == 4 || v.mArgKind == 5 || v.mArgKind == 6 || v.mArgKind == 7) {
                v.mSpecChar = 0xff;
            } else if (v.mHasDot == 0) {
                v.mUnk_0c = 6;
            }
            break;
        case 'a':
        case 'A':
            if (v.mHasDot == 0) {
                v.mUnk_0c = 0xd;
            }
            if (v.mArgKind == 2 || v.mArgKind == 4 || v.mArgKind == 5 || v.mArgKind == 6 || v.mArgKind == 7 ||
                v.mArgKind == 1) {
                v.mSpecChar = 0xff;
            }
            break;
        case 'g':
        case 'G':
            if (v.mUnk_0c == 0) {
                v.mUnk_0c = 1;
            }
        case 'e':
        case 'E':
            if (v.mArgKind == 2 || v.mArgKind == 4 || v.mArgKind == 5 || v.mArgKind == 6 || v.mArgKind == 7 ||
                v.mArgKind == 1) {
                v.mSpecChar = 0xff;
            } else if (v.mHasDot == 0) {
                v.mUnk_0c = 6;
            }
            break;
        case 'p':
            v.mSpecChar = 'x';
            v.mHash = 1;
            v.mArgKind = 3;
            v.mUnk_0c = 8;
            break;
        case 'c':
            if (v.mArgKind == 3) {
                v.mArgKind = 9;
            } else if (v.mHasDot != 0 || v.mArgKind != 0) {
                v.mSpecChar = 0xff;
            }
            break;
        case 's':
            if (v.mArgKind == 3) {
                v.mArgKind = 9;
            } else if (v.mArgKind != 0) {
                v.mSpecChar = 0xff;
            }
            break;
        case 'n':
            if (v.mArgKind == 8) {
                v.mSpecChar = 0xff;
            }
            break;
        default:
            v.mSpecChar = 0xff;
            break;
    }
    *buf = v;
    return s + 1;
}

char *FormatInt32(unsigned long v, char *end, FormatSpec spec) {
    int neg;
    int width;
    u8 alt;
    u8 sign;
    int d;
    int base;
    char *p;
    int cnt;
    int prec;
    u8 conv;

    prec = spec.mUnk_0c;
    alt = spec.mHash;
    conv = spec.mSpecChar;
    width = spec.mMinLength;
    sign = spec.mSignKind;
    p = end;
    neg = 0;
    *--p = 0;
    cnt = neg;
    if (v == 0 && prec == 0 && !(alt != 0 && conv == 'o')) {
        return p;
    }
    switch (conv) {
        case 'i':
        case 'd':
            base = 10;
            if ((long) v < 0) {
                neg = 1;
                v = -v;
            }
            break;
        case 'u':
            base = 10;
            sign = 0;
            break;
        case 'x':
        case 'X':
            base = 16;
            sign = 0;
            break;
        case 'o':
            base = 8;
            sign = 0;
            break;
    }
    do {
        d = v % base;
        v = v / base;
        if (d < 10) {
            d += '0';
        } else if (conv == 'x') {
            d += 'a' - 10;
        } else {
            d += 'A' - 10;
        }
        *--p = d;
        cnt++;
    } while (v != 0);
    if (base == 8 && alt != 0 && *p != '0') {
        *--p = '0';
        cnt++;
    }
    if (spec.mPadKind == 2) {
        prec = width;
        if (neg != 0 || sign != 0) {
            prec--;
        }
        if (base == 16 && alt != 0) {
            prec -= 2;
        }
    }
    if (prec + (end - p) > 0x1fd) {
        return 0;
    }
    while (cnt < prec) {
        *--p = '0';
        cnt++;
    }
    if (base == 16 && alt != 0) {
        *--p = conv;
        *--p = '0';
    }
    if (neg != 0) {
        *--p = '-';
    } else if (sign == 1) {
        *--p = '+';
    } else if (sign == 2) {
        *--p = ' ';
    }
    return p;
}

char *FormatInt64(u64 v, char *end, FormatSpec spec) {
    int neg;
    int w;
    int flag;
    u32 wid;
    int alt;
    u64 base;
    char *p;
    int count;
    int ch;
    int d;

    w = spec.mUnk_0c;
    alt = spec.mHash;
    ch = spec.mSpecChar;
    wid = spec.mMinLength;
    flag = spec.mSignKind;
    p = end;
    neg = 0;
    *--p = 0;
    count = neg;
    if (v == 0 && w == 0 && (alt == 0 || ch != 'o')) {
        return p;
    }
    switch (ch) {
        case 'd':
        case 'i':
            base = 10;
            if ((s64) v < 0) {
                v = -v;
                neg = 1;
            }
            break;
        case 'o':
            base = 8;
            flag = 0;
            break;
        case 'u':
            base = 10;
            flag = 0;
            break;
        case 'x':
        case 'X':
            base = 16;
            flag = 0;
            break;
    }
    do {
        d = (int) (v % base);
        v = v / base;
        if (d < 10) {
            d += '0';
        } else if (ch == 'x') {
            d += 'a' - 10;
        } else {
            d += 'A' - 10;
        }
        *--p = d;
        count++;
    } while (v != 0);
    if (base == 8 && alt != 0 && *p != '0') {
        *--p = '0';
        count++;
    }
    if (spec.mPadKind == 2) {
        w = wid;
        if (neg != 0 || flag != 0) {
            w--;
        }
        if (base == 16 && alt != 0) {
            w -= 2;
        }
    }
    if (w + (end - p) > 0x1fd) {
        return 0;
    }
    while (count < w) {
        *--p = '0';
        count++;
    }
    if (base == 16 && alt != 0) {
        *--p = ch;
        *--p = '0';
    }
    if (neg != 0) {
        *--p = '-';
    } else if (flag == 1) {
        *--p = '+';
    } else if (flag == 2) {
        *--p = ' ';
    }
    return p;
}

char *FormatDoubleHex(double x, char *buf, FormatSpec e) {
    int n;
    u8 c;
    u8 f;
    u8 s;
    Unk02140c28 a;
    FormatSpec b;
    DigitRecord r;
    char *p;
    int i;
    u8 t;
    u8 *q;
    u8 *w;
    u8 d;
    int j;
    int k;

    n = e.mUnk_0c;
    c = e.mSpecChar;
    f = e.mHash;
    s = e.mSignKind;
    if (n > 0x1fd) {
        return 0;
    }
    a.mUnk_00 = 0;
    a.mDigitCount = 0x20;
    DoubleToDigitChars(&a, x, &r);
    if (0.0 == fabs(x)) {
        p = buf - 6;
        strcpy(p, gFormatHexZero);
        return p;
    }
    if (r.mDigits[0] == 'I') {
        if (r.mNegative != 0) {
            p = buf - 5;
            if (c == 'A') {
                strcpy(p, gFormatMinusInfUpper);
            } else {
                strcpy(p, gFormatMinusInfLower);
            }
        } else {
            p = buf - 4;
            if (c == 'A') {
                strcpy(p, gFormatInfUpper);
            } else {
                strcpy(p, gFormatInfLower);
            }
        }
        return p;
    }
    if (r.mDigits[0] == 'N') {
        if (r.mNegative != 0) {
            p = buf - 5;
            if (c == 'A') {
                strcpy(p, gFormatMinusNanUpper);
            } else {
                strcpy(p, gFormatMinusNanLower);
            }
        } else {
            p = buf - 4;
            if (c == 'A') {
                strcpy(p, gFormatNanUpper);
            } else {
                strcpy(p, gFormatNanLower);
            }
        }
        return p;
    }
    b.mPadKind = 1;
    b.mSignKind = 1;
    b.mHasDot = 0;
    b.mHash = 0;
    b.mArgKind = 0;
    b.mUnk_0c = 1;
    b.mMinLength = 0;
    b.mSpecChar = 'd';
    w = (u8 *) &x;
    for (i = 0; i < 4; i++) {
        t = w[i];
        w[i] = w[7 - i];
        w[7 - i] = t;
    }
    k = ((u8 *) &x)[0] << 25;
    k |= ((u8 *) &x)[1] << 17;
    k = ((u32) k >> 21) & 0x7ff;
    j = k - 1023;
    p = FormatInt32(j, buf, b);
    if (c == 'a') {
        *--p = 'p';
    } else {
        *--p = 'P';
    }
    k = n * 4 + 11;
    q = (u8 *) &x;
    for (j = n; j >= 1; j--) {
        if (k < 64) {
            d = q[k >> 3] >> (7 - (k & 7));
            if ((k & ~7) != ((k - 4) & ~7)) {
                d = d | ((q[(k >> 3) - 1] << 8) >> (7 - (k & 7)));
            }
            d &= 15;
            if (d < 10) {
                d += '0';
            } else if (c == 'a') {
                d += 'a' - 10;
            } else {
                d += 'A' - 10;
            }
        } else {
            d = '0';
        }
        *--p = d;
        k -= 4;
    }
    if (n != 0 || f != 0) {
        *--p = '.';
    }
    *--p = '1';
    if (c == 'a') {
        *--p = 'x';
    } else {
        *--p = 'X';
    }
    *--p = '0';
    if (r.mNegative != 0) {
        *--p = '-';
    } else if (s == 1) {
        *--p = '+';
    } else if (s == 2) {
        *--p = ' ';
    }
    return p;
}

void FormatRoundDigitChars(DigitRecord *a, int k) {
    char *b;
    char *p;
    char *q;
    int n;
    u8 v;
    int c;

    if (k < 0) {
    zero:
        a->mExponent = 0;
        a->mDigitCount = 1;
        a->mDigits[0] = '0';
        return;
    }
    n = a->mDigitCount;
    if (k >= n) {
        return;
    }
    b = a->mDigits;
    p = b + k + 1;
    v = *--p - '0';
    if (v == 5) {
        q = b + n;
        while (--q > p && *q == '0') {
        }
        if (q == p) {
            c = p[-1] & 1;
        } else {
            c = 1;
        }
    } else {
        c = v > 5;
    }
    while (k != 0) {
        v = *--p - '0' + c;
        c = v > 9;
        if (c != 0 || v == 0) {
            k--;
        } else {
            *p = v + '0';
            break;
        }
    }
    if (c != 0) {
        a->mExponent++;
        a->mDigitCount = 1;
        a->mDigits[0] = '1';
        return;
    }
    if (k == 0) {
        goto zero;
    }
    a->mDigitCount = k;
}

char *FormatDouble(double v, char *buf, FormatSpec f) {
    Unk02140c28 m;
    DigitRecord d;
    u8 a;
    int b;
    int g;
    int h;
    char *t;
    char *p;
    char *q;
    int x;
    int y;
    int n;
    int i;
    int j;
    int k;
    int c;

    a = f.mSpecChar;
    b = f.mUnk_0c;
    h = f.mHash;
    g = f.mSignKind;
    m.mUnk_00 = 0;
    m.mDigitCount = 0x20;
    DoubleToDigitChars(&m, v, &d);
    q = d.mDigits + d.mDigitCount;
    while (d.mDigitCount > 1 && *--q == '0') {
        d.mDigitCount--;
        d.mExponent++;
    }
    switch (d.mDigits[0]) {
        case '0':
            d.mExponent = 0;
            break;
        case 'I':
            c = a;
            if (v < 0.0) {
                p = buf - 5;
                if ((c < 0 || c >= 0x80) ? 0 : (data_0215d284[c] & 0x200)) {
                    strcpy(p, gFormatMinusInfUpper);
                } else {
                    strcpy(p, gFormatMinusInfLower);
                }
            } else {
                p = buf - 4;
                if ((c < 0 || c >= 0x80) ? 0 : (data_0215d284[c] & 0x200)) {
                    strcpy(p, gFormatInfUpper);
                } else {
                    strcpy(p, gFormatInfLower);
                }
            }
            return p;
        case 'N':
            c = a;
            if (d.mNegative) {
                p = buf - 5;
                if ((c < 0 || c >= 0x80) ? 0 : (data_0215d284[c] & 0x200)) {
                    strcpy(p, gFormatMinusNanUpper);
                } else {
                    strcpy(p, gFormatMinusNanLower);
                }
            } else {
                p = buf - 4;
                if ((c < 0 || c >= 0x80) ? 0 : (data_0215d284[c] & 0x200)) {
                    strcpy(p, gFormatNanUpper);
                } else {
                    strcpy(p, gFormatNanLower);
                }
            }
            return p;
    }
    d.mExponent += d.mDigitCount - 1;
    p = buf - 1;
    *p = 0;
    switch (a) {
        case 'g':
        case 'G':
            if (d.mDigitCount > b) {
                FormatRoundDigitChars(&d, b);
            }
            if (d.mExponent < -4 || d.mExponent >= b) {
                if (h) {
                    b--;
                } else {
                    b = d.mDigitCount - 1;
                }
                if (a == 'g') {
                    a = 'e';
                } else {
                    a = 'E';
                }
            } else {
                if (h) {
                    b -= d.mExponent + 1;
                } else {
                    b = d.mDigitCount - (d.mExponent + 1);
                    if (b < 0) {
                        b = 0;
                    }
                }
                goto case_f;
            }
        case 'e':
        case 'E':
            if (d.mDigitCount > b + 1) {
                FormatRoundDigitChars(&d, b + 1);
            }
            x = d.mExponent;
            y = '+';
            if (x < 0) {
                x = -x;
                y = '-';
            }
            for (n = 0; x != 0 || n < 2;) {
                *--p = x % 10 + '0';
                x /= 10;
                n++;
            }
            p[-1] = y;
            p -= 2;
            *p = a;
            if (b + (buf - p) > 0x1fd) {
                return 0;
            }
            if (d.mDigitCount < b + 1) {
                i = b + 2 - d.mDigitCount;
                while (--i) {
                    *--p = '0';
                }
            }
            t = d.mDigits + d.mDigitCount;
            for (i = d.mDigitCount - 1; i != 0; i--) {
                *--p = *--t;
            }
            if (b != 0 || h) {
                *--p = '.';
            }
            *--p = d.mDigits[0];
            if (d.mNegative) {
                *--p = '-';
            } else if (g == 1) {
                *--p = '+';
            } else if (g == 2) {
                *--p = ' ';
            }
            break;
        case 'f':
        case 'F':
        case_f:
            x = d.mExponent;
            k = d.mDigitCount - x - 1;
            if (k < 0) {
                k = 0;
            }
            if (k > b) {
                FormatRoundDigitChars(&d, d.mDigitCount - (k - b));
                x = d.mExponent;
                k = d.mDigitCount - x - 1;
                if (k < 0) {
                    k = 0;
                }
            }
            j = x + 1;
            if (j < 0) {
                j = 0;
            }
            if (j + k > 0x1fd) {
                return 0;
            }
            t = d.mDigits + d.mDigitCount;
            for (c = 0; c < b - k; c++) {
                *--p = '0';
            }
            for (c = 0; c < k && c < d.mDigitCount; c++) {
                *--p = *--t;
            }
            for (; c < k; c++) {
                *--p = '0';
            }
            if (b != 0 || h) {
                *--p = '.';
            }
            if (j != 0) {
                for (c = 0; c < j - d.mDigitCount; c++) {
                    *--p = '0';
                }
                for (; c < j; c++) {
                    *--p = *--t;
                }
            } else {
                *--p = '0';
            }
            if (d.mNegative) {
                *--p = '-';
            } else if (g == 1) {
                *--p = '+';
            } else if (g == 2) {
                *--p = ' ';
            }
            break;
    }
    return p;
}

int FormatWithPutFunc(void *(*f)(void *, const char *, u32), void *a, const char *b, char *c) {
    FormatSpec e;
    char buf[0x200];
    char g;
    char h;
    int k;
    unsigned long long x;
    const char *s;
    int m;
    int n;
    int w;
    char *p;
    unsigned long v;
    double y;
    const u16 *t;
    char *q;
    void *u;

    g = ' ';
    k = 0;
    while (*b != 0) {
        s = strchr(b, '%');
        if (s == 0) {
            n = strlen(b);
            k += n;
            if (n != 0 && f(a, b, n) == 0) {
                return -1;
            }
            break;
        }
        n = s - b;
        k += n;
        if (n != 0 && f(a, b, n) == 0) {
            return -1;
        }
        b = FormatParseSpec(s, &c, &e);
        switch (e.mSpecChar) {
            case 'd':
            case 'i':
                if (e.mArgKind == 3) {
                    v = *(long *) ((c += 4) - 4);
                } else if (e.mArgKind == 7) {
                    x = *(long long *) ((c += 8) - 8);
                } else if (e.mArgKind == 4) {
                    v = *(long long *) ((c += 8) - 8);
                } else if (e.mArgKind == 5) {
                    v = *(u32 *) ((c += 4) - 4);
                } else if (e.mArgKind == 6) {
                    v = *(long *) ((c += 4) - 4);
                } else {
                    v = *(int *) ((c += 4) - 4);
                }
                if (e.mArgKind == 2) {
                    v = (short) v;
                }
                if (e.mArgKind == 1) {
                    v = (s8) v;
                }
                if (e.mArgKind == 7) {
                    p = FormatInt64(x, buf + sizeof(buf), e);
                    if (p == 0) {
                        goto bad;
                    }
                } else {
                    p = FormatInt32(v, buf + sizeof(buf), e);
                    if (p == 0) {
                        goto bad;
                    }
                }
                m = buf + sizeof(buf) - 1 - p;
                break;
            case 'o':
            case 'u':
            case 'x':
            case 'X':
                if (e.mArgKind == 3) {
                    v = *(unsigned long *) ((c += 4) - 4);
                } else if (e.mArgKind == 7) {
                    x = *(unsigned long long *) ((c += 8) - 8);
                } else if (e.mArgKind == 4) {
                    v = *(unsigned long long *) ((c += 8) - 8);
                } else if (e.mArgKind == 5) {
                    v = *(u32 *) ((c += 4) - 4);
                } else if (e.mArgKind == 6) {
                    v = *(unsigned long *) ((c += 4) - 4);
                } else {
                    v = *(u32 *) ((c += 4) - 4);
                }
                if (e.mArgKind == 2) {
                    v = (u16) v;
                }
                if (e.mArgKind == 1) {
                    v = (u8) v;
                }
                if (e.mArgKind == 7) {
                    p = FormatInt64(x, buf + sizeof(buf), e);
                    if (p == 0) {
                        goto bad;
                    }
                } else {
                    p = FormatInt32(v, buf + sizeof(buf), e);
                    if (p == 0) {
                        goto bad;
                    }
                }
                m = buf + sizeof(buf) - 1 - p;
                break;
            case 'e':
            case 'E':
            case 'f':
            case 'F':
            case 'g':
            case 'G':
                if (e.mArgKind == 8) {
                    y = *(long double *) ((c += 8) - 8);
                } else {
                    y = *(double *) ((c += 8) - 8);
                }
                p = FormatDouble(y, buf + sizeof(buf), e);
                if (p == 0) {
                    goto bad;
                }
                m = buf + sizeof(buf) - 1 - p;
                break;
            case 'a':
            case 'A':
                if (e.mArgKind == 8) {
                    y = *(long double *) ((c += 8) - 8);
                } else {
                    y = *(double *) ((c += 8) - 8);
                }
                p = FormatDoubleHex(y, buf + sizeof(buf), e);
                if (p == 0) {
                    goto bad;
                }
                m = buf + sizeof(buf) - 1 - p;
                break;
            case 's':
                if (e.mArgKind == 9) {
                    t = *(const u16 **) ((c += 4) - 4);
                    if (t == 0) {
                        t = L"";
                    }
                    if (wcstombs(buf, t, sizeof(buf)) < 0) {
                        goto bad;
                    }
                    p = buf;
                } else {
                    p = *(char **) ((c += 4) - 4);
                }
                if (p == 0) {
                    p = "";
                }
                if (e.mHash != 0) {
                    m = *p++;
                    if (e.mHasDot != 0 && m > e.mUnk_0c) {
                        m = e.mUnk_0c;
                    }
                } else if (e.mHasDot != 0) {
                    m = e.mUnk_0c;
                    q = memchr(p, 0, m);
                    if (q != 0) {
                        m = q - p;
                    }
                } else {
                    m = strlen(p);
                }
                break;
            case 'n':
                u = *(void **) ((c += 4) - 4);
                switch (e.mArgKind) {
                    case 0:
                        *(int *) u = k;
                        break;
                    case 2:
                        *(short *) u = k;
                        break;
                    case 3:
                        *(long *) u = k;
                        break;
                    case 7:
                        *(long long *) u = k;
                        break;
                }
                continue;
            case 'c':
                p = buf;
                *p = *(int *) ((c += 4) - 4);
                m = 1;
                break;
            case '%':
                p = buf;
                *p = '%';
                m = 1;
                break;
            case 0xff:
            default:
            bad:
                n = strlen(s);
                k += n;
                if (n != 0 && f(a, s, n) == 0) {
                    return -1;
                }
                return k;
        }
        w = m;
        if (e.mPadKind != 0) {
            g = e.mPadKind == 2 ? '0' : ' ';
            if ((*p == '+' || *p == '-' || *p == ' ') && g == '0') {
                if (f(a, p, 1) == 0) {
                    return -1;
                }
                p++;
                m--;
            }
            for (; w < e.mMinLength; w++) {
                if (f(a, &g, 1) == 0) {
                    return -1;
                }
            }
        }
        if (m != 0 && f(a, p, m) == 0) {
            return -1;
        }
        if (e.mPadKind == 0) {
            for (; w < e.mMinLength; w++) {
                h = ' ';
                if (f(a, &h, 1) == 0) {
                    return -1;
                }
            }
        }
        k += w;
    }
    return k;
}
