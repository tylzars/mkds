#pragma avoid_byte all

#include "code_021352e0.h"
#include "code_02134b18.h"
#include "code_02134d30.h"
#include "code_02139f70.h"
#include "code_0213a460.h"
#include "code_0213ee6c.h"

const u8 *func_0213770c(const u8 *p, char **b, Unk021352e0 *buf) {
    const u8 *s;
    Unk021352e0 v;
    int c;
    int n;
    int w;

    v.mUnk_00 = 1;
    v.mUnk_01 = 0;
    v.mUnk_02 = 0;
    v.mUnk_03 = 0;
    v.mUnk_04 = 0;
    v.mUnk_08 = 0;
    v.mUnk_0c = 0;
    s = p + 1;
    c = *s;
    if (c == '%') {
        v.mUnk_05 = c;
        *buf = v;
        return s + 1;
    }
    for (;;) {
        n = 1;
        switch (c) {
            case '-':
                v.mUnk_00 = 0;
                break;
            case '+':
                v.mUnk_01 = 1;
                break;
            case ' ':
                if (v.mUnk_01 != 1) {
                    v.mUnk_01 = 2;
                }
                break;
            case '#':
                v.mUnk_03 = 1;
                break;
            case '0':
                if (v.mUnk_00 != 0) {
                    v.mUnk_00 = 2;
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
        v.mUnk_08 = w;
        if (w < 0) {
            v.mUnk_00 = 0;
            v.mUnk_08 = -w;
        }
        c = *++s;
    } else {
        while ((c < 0 || c >= 0x80) ? 0 : (data_0215d284[c] & 8)) {
            v.mUnk_08 = v.mUnk_08 * 10 + (c - '0');
            c = *++s;
        }
    }
    if (v.mUnk_08 > 0x1fd) {
        v.mUnk_05 = 0xff;
        *buf = v;
        return s + 1;
    }
    if (c == '.') {
        v.mUnk_02 = 1;
        c = *++s;
        if (c == '*') {
            *b += 4;
            v.mUnk_0c = ((int *) *b)[-1];
            if (v.mUnk_0c < 0) {
                v.mUnk_02 = 0;
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
            v.mUnk_04 = 2;
            if (s[1] == 'h') {
                v.mUnk_04 = 1;
                c = *++s;
            }
            break;
        case 'l':
            v.mUnk_04 = 3;
            if (s[1] == 'l') {
                v.mUnk_04 = 7;
                c = *++s;
            }
            break;
        case 'L':
            v.mUnk_04 = 8;
            break;
        case 'j':
            v.mUnk_04 = 4;
            break;
        case 'z':
            v.mUnk_04 = 5;
            break;
        case 't':
            v.mUnk_04 = 6;
            break;
        default:
            n = 0;
            break;
    }
    if (n) {
        c = *++s;
    }
    v.mUnk_05 = c;
    switch (c) {
        case 'd':
        case 'i':
        case 'o':
        case 'u':
        case 'x':
        case 'X':
            if (v.mUnk_04 == 8) {
                v.mUnk_05 = 0xff;
            } else if (v.mUnk_02 == 0) {
                v.mUnk_0c = 1;
            } else if (v.mUnk_00 == 2) {
                v.mUnk_00 = 1;
            }
            break;
        case 'f':
        case 'F':
            if (v.mUnk_04 == 2 || v.mUnk_04 == 4 || v.mUnk_04 == 5 || v.mUnk_04 == 6 || v.mUnk_04 == 7) {
                v.mUnk_05 = 0xff;
            } else if (v.mUnk_02 == 0) {
                v.mUnk_0c = 6;
            }
            break;
        case 'a':
        case 'A':
            if (v.mUnk_02 == 0) {
                v.mUnk_0c = 0xd;
            }
            if (v.mUnk_04 == 2 || v.mUnk_04 == 4 || v.mUnk_04 == 5 || v.mUnk_04 == 6 || v.mUnk_04 == 7 ||
                v.mUnk_04 == 1) {
                v.mUnk_05 = 0xff;
            }
            break;
        case 'g':
        case 'G':
            if (v.mUnk_0c == 0) {
                v.mUnk_0c = 1;
            }
        case 'e':
        case 'E':
            if (v.mUnk_04 == 2 || v.mUnk_04 == 4 || v.mUnk_04 == 5 || v.mUnk_04 == 6 || v.mUnk_04 == 7 ||
                v.mUnk_04 == 1) {
                v.mUnk_05 = 0xff;
            } else if (v.mUnk_02 == 0) {
                v.mUnk_0c = 6;
            }
            break;
        case 'p':
            v.mUnk_05 = 'x';
            v.mUnk_03 = 1;
            v.mUnk_04 = 3;
            v.mUnk_0c = 8;
            break;
        case 'c':
            if (v.mUnk_04 == 3) {
                v.mUnk_04 = 9;
            } else if (v.mUnk_02 != 0 || v.mUnk_04 != 0) {
                v.mUnk_05 = 0xff;
            }
            break;
        case 's':
            if (v.mUnk_04 == 3) {
                v.mUnk_04 = 9;
            } else if (v.mUnk_04 != 0) {
                v.mUnk_05 = 0xff;
            }
            break;
        case 'n':
            if (v.mUnk_04 == 8) {
                v.mUnk_05 = 0xff;
            }
            break;
        default:
            v.mUnk_05 = 0xff;
            break;
    }
    *buf = v;
    return s + 1;
}

u8 *func_02137358(unsigned long v, u8 *end, Unk021352e0 spec) {
    int neg;
    int width;
    u8 alt;
    u8 sign;
    int d;
    int base;
    u8 *p;
    int cnt;
    int prec;
    u8 conv;

    prec = spec.mUnk_0c;
    alt = spec.mUnk_03;
    conv = spec.mUnk_05;
    width = spec.mUnk_08;
    sign = spec.mUnk_01;
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
    if (spec.mUnk_00 == 2) {
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

// non-matching: base is held as low r11 / high r8 (original low r8, high r11), and the locals at [sp+0x10] and
// [sp+0x14] (mUnk_03 copy, mUnk_08 copy) are in swapped slots; the instruction sequence is otherwise the same
u8 *func_02136f14(u64 v, u8 *end, Unk021352e0 spec) {
    int neg;
    int w;
    int flag;
    int wid;
    int alt;
    u64 base;
    u8 *p;
    int count;
    int ch;
    int d;
    int c;

    p = end;
    w = spec.mUnk_0c;
    alt = spec.mUnk_03;
    ch = spec.mUnk_05;
    flag = spec.mUnk_01;
    wid = spec.mUnk_08;
    neg = 0;
    count = neg;
    *--p = neg;
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
            flag = 0;
            base = 8;
            break;
        case 'u':
            flag = 0;
            base = 10;
            break;
        case 'x':
        case 'X':
            flag = 0;
            base = 16;
            break;
    }
    do {
        d = (int) (v % base);
        v = v / base;
        if (d < 10) {
            c = d + '0';
        } else if (ch == 'x') {
            c = d + 'a' - 10;
        } else {
            c = d + 'A' - 10;
        }
        *--p = c;
        count++;
    } while (v != 0);
    if (base == 8 && alt != 0 && *p != '0') {
        *--p = '0';
        count++;
    }
    if (spec.mUnk_00 == 2) {
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

// non-matching: 23 words. (1) the exponent ((x[0] << 25 | x[1] << 17) >> 21 & 0x7ff) is computed after the copy of b
// into the argument area (original: before it, kept in r7, then add r0, r7, #-1023 at the call); (2) the final digit
// gets r3 instead of the register of the shifted byte (r8) at the four assignments and the store's and.
u8 *func_02136850(double x, u8 *buf, Unk021352e0 e) {
    int n;
    u8 c;
    u8 f;
    u8 s;
    Unk02140c28 a;
    Unk021352e0 b;
    Unk02136638 r;
    char *p;
    int i;
    u8 t;
    u8 *q;
    u8 *w;
    u8 d;
    int j;
    int k;
    u8 v;

    n = e.mUnk_0c;
    c = e.mUnk_05;
    f = e.mUnk_03;
    s = e.mUnk_01;
    if (n > 0x1fd) {
        return 0;
    }
    a.mUnk_00 = 0;
    a.mUnk_02 = 0x20;
    func_02140c28(&a, x, &r);
    if (0.0 == func_021400c8(x)) {
        p = (char *) buf - 6;
        strcpy(p, data_0216eeb0);
        return (u8 *) p;
    }
    if (r.mUnk_05[0] == 'I') {
        if (r.mUnk_00 != 0) {
            p = (char *) buf - 5;
            if (c == 'A') {
                strcpy(p, data_0216ee80);
            } else {
                strcpy(p, data_0216ee88);
            }
        } else {
            p = (char *) buf - 4;
            if (c == 'A') {
                strcpy(p, data_0216ee90);
            } else {
                strcpy(p, data_0216ee94);
            }
        }
        return (u8 *) p;
    }
    if (r.mUnk_05[0] == 'N') {
        if (r.mUnk_00 != 0) {
            p = (char *) buf - 5;
            if (c == 'A') {
                strcpy(p, data_0216ee98);
            } else {
                strcpy(p, data_0216eea0);
            }
        } else {
            p = (char *) buf - 4;
            if (c == 'A') {
                strcpy(p, data_0216eea8);
            } else {
                strcpy(p, data_0216eeac);
            }
        }
        return (u8 *) p;
    }
    b.mUnk_00 = 1;
    b.mUnk_01 = 1;
    b.mUnk_02 = 0;
    b.mUnk_03 = 0;
    b.mUnk_04 = 0;
    b.mUnk_0c = 1;
    b.mUnk_08 = 0;
    b.mUnk_05 = 'd';
    w = (u8 *) &x;
    for (i = 0; i < 4; i++) {
        t = w[i];
        w[i] = w[7 - i];
        w[7 - i] = t;
    }
    p = (char *) func_02137358((((u32) (((u8 *) &x)[0] << 25 | ((u8 *) &x)[1] << 17) >> 21) & 0x7ff) - 1023, buf, b);
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
            v = d & 15;
            if (v < 10) {
                d = v + '0';
            } else if (c == 'a') {
                d = v + 'a' - 10;
            } else {
                d = v + 'A' - 10;
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
    if (r.mUnk_00 != 0) {
        *--p = '-';
    } else if (s == 1) {
        *--p = '+';
    } else if (s == 2) {
        *--p = ' ';
    }
    return (u8 *) p;
}

void func_02136638(Unk02136638 *a, int k) {
    u8 *b;
    u8 *p;
    u8 *q;
    int n;
    u8 v;
    int c;

    if (k < 0) {
    zero:
        a->mUnk_02 = 0;
        a->mUnk_04 = 1;
        a->mUnk_05[0] = '0';
        return;
    }
    n = a->mUnk_04;
    if (k >= n) {
        return;
    }
    b = a->mUnk_05;
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
        a->mUnk_02++;
        a->mUnk_04 = 1;
        a->mUnk_05[0] = '1';
        return;
    }
    if (k == 0) {
        goto zero;
    }
    a->mUnk_04 = k;
}

// non-matching: in the 'f'/'F' case the count i gets r0 and the pointer t r8; the original has them the other
// way round (14 instructions at +0x6d4..+0x8a4, register numbers only)
u8 *func_02135c80(double v, u8 *buf, Unk021352e0 f) {
    Unk02140c28 m;
    Unk02136638 d;
    u8 a;
    int b;
    int g;
    int h;
    u8 *t;
    char *p;
    u8 *q;
    int x;
    int y;
    int n;
    int i;
    int k;
    int c;

    a = f.mUnk_05;
    b = f.mUnk_0c;
    h = f.mUnk_03;
    g = f.mUnk_01;
    m.mUnk_00 = 0;
    m.mUnk_02 = 0x20;
    func_02140c28(&m, v, &d);
    q = d.mUnk_05 + d.mUnk_04;
    while (d.mUnk_04 > 1 && *--q == '0') {
        d.mUnk_04--;
        d.mUnk_02++;
    }
    switch (d.mUnk_05[0]) {
        case '0':
            d.mUnk_02 = 0;
            break;
        case 'I':
            c = a;
            if (v < 0.0) {
                p = (char *) buf - 5;
                if ((c < 0 || c >= 0x80) ? 0 : (data_0215d284[c] & 0x200)) {
                    strcpy(p, data_0216ee80);
                } else {
                    strcpy(p, data_0216ee88);
                }
            } else {
                p = (char *) buf - 4;
                if ((c < 0 || c >= 0x80) ? 0 : (data_0215d284[c] & 0x200)) {
                    strcpy(p, data_0216ee90);
                } else {
                    strcpy(p, data_0216ee94);
                }
            }
            return (u8 *) p;
        case 'N':
            c = a;
            if (d.mUnk_00) {
                p = (char *) buf - 5;
                if ((c < 0 || c >= 0x80) ? 0 : (data_0215d284[c] & 0x200)) {
                    strcpy(p, data_0216ee98);
                } else {
                    strcpy(p, data_0216eea0);
                }
            } else {
                p = (char *) buf - 4;
                if ((c < 0 || c >= 0x80) ? 0 : (data_0215d284[c] & 0x200)) {
                    strcpy(p, data_0216eea8);
                } else {
                    strcpy(p, data_0216eeac);
                }
            }
            return (u8 *) p;
    }
    d.mUnk_02 += d.mUnk_04 - 1;
    p = (char *) buf - 1;
    *p = 0;
    switch (a) {
        case 'g':
        case 'G':
            if (d.mUnk_04 > b) {
                func_02136638(&d, b);
            }
            if (d.mUnk_02 < -4 || d.mUnk_02 >= b) {
                if (h) {
                    b--;
                } else {
                    b = d.mUnk_04 - 1;
                }
                if (a == 'g') {
                    a = 'e';
                } else {
                    a = 'E';
                }
            } else {
                if (h) {
                    b -= d.mUnk_02 + 1;
                } else {
                    b = d.mUnk_04 - (d.mUnk_02 + 1);
                    if (b < 0) {
                        b = 0;
                    }
                }
                goto case_f;
            }
        case 'e':
        case 'E':
            if (d.mUnk_04 > b + 1) {
                func_02136638(&d, b + 1);
            }
            x = d.mUnk_02;
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
            if (b + ((char *) buf - p) > 0x1fd) {
                return 0;
            }
            if (d.mUnk_04 < b + 1) {
                i = b + 2 - d.mUnk_04;
                while (--i) {
                    *--p = '0';
                }
            }
            q = d.mUnk_05 + d.mUnk_04;
            for (i = d.mUnk_04 - 1; i != 0; i--) {
                *--p = *--q;
            }
            if (b != 0 || h) {
                *--p = '.';
            }
            *--p = d.mUnk_05[0];
            if (d.mUnk_00) {
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
            x = d.mUnk_02;
            k = d.mUnk_04 - x - 1;
            if (k < 0) {
                k = 0;
            }
            if (k > b) {
                func_02136638(&d, d.mUnk_04 - (k - b));
                x = d.mUnk_02;
                k = d.mUnk_04 - x - 1;
                if (k < 0) {
                    k = 0;
                }
            }
            i = x + 1;
            if (i < 0) {
                i = 0;
            }
            if (i + k > 0x1fd) {
                return 0;
            }
            t = d.mUnk_05 + d.mUnk_04;
            for (c = 0; c < b - k; c++) {
                *--p = '0';
            }
            for (c = 0; c < k && c < d.mUnk_04; c++) {
                *--p = *--t;
            }
            for (; c < k; c++) {
                *--p = '0';
            }
            if (b != 0 || h) {
                *--p = '.';
            }
            if (i != 0) {
                for (c = 0; c < i - d.mUnk_04; c++) {
                    *--p = '0';
                }
                for (; c < i; c++) {
                    *--p = *--t;
                }
            } else {
                *--p = '0';
            }
            if (d.mUnk_00) {
                *--p = '-';
            } else if (g == 1) {
                *--p = '+';
            } else if (g == 2) {
                *--p = ' ';
            }
            break;
    }
    return (u8 *) p;
}

int func_021352e0(void *(*f)(void *, const u8 *, u32), void *a, const u8 *b, char *c) {
    Unk021352e0 e;
    u8 buf[0x200];
    u8 g;
    u8 h;
    int k;
    unsigned long long x;
    const u8 *s;
    int m;
    int n;
    int w;
    u8 *p;
    unsigned long v;
    double y;
    const u16 *t;
    u8 *q;
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
        b = func_0213770c(s, &c, &e);
        switch (e.mUnk_05) {
            case 'd':
            case 'i':
                if (e.mUnk_04 == 3) {
                    v = *(long *) ((c += 4) - 4);
                } else if (e.mUnk_04 == 7) {
                    x = *(long long *) ((c += 8) - 8);
                } else if (e.mUnk_04 == 4) {
                    v = *(long long *) ((c += 8) - 8);
                } else if (e.mUnk_04 == 5) {
                    v = *(u32 *) ((c += 4) - 4);
                } else if (e.mUnk_04 == 6) {
                    v = *(long *) ((c += 4) - 4);
                } else {
                    v = *(int *) ((c += 4) - 4);
                }
                if (e.mUnk_04 == 2) {
                    v = (short) v;
                }
                if (e.mUnk_04 == 1) {
                    v = (s8) v;
                }
                if (e.mUnk_04 == 7) {
                    p = func_02136f14(x, buf + sizeof(buf), e);
                    if (p == 0) {
                        goto bad;
                    }
                } else {
                    p = func_02137358(v, buf + sizeof(buf), e);
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
                if (e.mUnk_04 == 3) {
                    v = *(unsigned long *) ((c += 4) - 4);
                } else if (e.mUnk_04 == 7) {
                    x = *(unsigned long long *) ((c += 8) - 8);
                } else if (e.mUnk_04 == 4) {
                    v = *(unsigned long long *) ((c += 8) - 8);
                } else if (e.mUnk_04 == 5) {
                    v = *(u32 *) ((c += 4) - 4);
                } else if (e.mUnk_04 == 6) {
                    v = *(unsigned long *) ((c += 4) - 4);
                } else {
                    v = *(u32 *) ((c += 4) - 4);
                }
                if (e.mUnk_04 == 2) {
                    v = (u16) v;
                }
                if (e.mUnk_04 == 1) {
                    v = (u8) v;
                }
                if (e.mUnk_04 == 7) {
                    p = func_02136f14(x, buf + sizeof(buf), e);
                    if (p == 0) {
                        goto bad;
                    }
                } else {
                    p = func_02137358(v, buf + sizeof(buf), e);
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
                if (e.mUnk_04 == 8) {
                    y = *(long double *) ((c += 8) - 8);
                } else {
                    y = *(double *) ((c += 8) - 8);
                }
                p = func_02135c80(y, buf + sizeof(buf), e);
                if (p == 0) {
                    goto bad;
                }
                m = buf + sizeof(buf) - 1 - p;
                break;
            case 'a':
            case 'A':
                if (e.mUnk_04 == 8) {
                    y = *(long double *) ((c += 8) - 8);
                } else {
                    y = *(double *) ((c += 8) - 8);
                }
                p = func_02136850(y, buf + sizeof(buf), e);
                if (p == 0) {
                    goto bad;
                }
                m = buf + sizeof(buf) - 1 - p;
                break;
            case 's':
                if (e.mUnk_04 == 9) {
                    t = *(const u16 **) ((c += 4) - 4);
                    if (t == 0) {
                        t = L"";
                    }
                    if (func_02134b18(buf, t, sizeof(buf)) < 0) {
                        goto bad;
                    }
                    p = buf;
                } else {
                    p = *(u8 **) ((c += 4) - 4);
                }
                if (p == 0) {
                    p = (u8 *) "";
                }
                if (e.mUnk_03 != 0) {
                    m = *(u8 *) p++;
                    if (e.mUnk_02 != 0 && m > e.mUnk_0c) {
                        m = e.mUnk_0c;
                    }
                } else if (e.mUnk_02 != 0) {
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
                switch (e.mUnk_04) {
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
        if (e.mUnk_00 != 0) {
            g = e.mUnk_00 == 2 ? '0' : ' ';
            if ((*p == '+' || *p == '-' || *p == ' ') && g == '0') {
                if (f(a, p, 1) == 0) {
                    return -1;
                }
                p++;
                m--;
            }
            for (; w < e.mUnk_08; w++) {
                if (f(a, &g, 1) == 0) {
                    return -1;
                }
            }
        }
        if (m != 0 && f(a, p, m) == 0) {
            return -1;
        }
        if (e.mUnk_00 == 0) {
            for (; w < e.mUnk_08; w++) {
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
