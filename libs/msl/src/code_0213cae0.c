#pragma avoid_byte all

#include "code_0213cae0.h"
#include "code_02134b18.h"
#include "code_02134d30.h"
#include "code_02139f70.h"
#include "code_0213c94c.h"
#include "code_0213ecf8.h"
#include "code_0213ee6c.h"

const u16 *func_0213e468(const u16 *a, char **b, Unk0213d398 *c) {
    Unk0213d398 s;
    const u16 *p;
    u16 ch;
    int k;

    s.mUnk_00 = 1;
    s.mUnk_01 = 0;
    s.mUnk_02 = 0;
    s.mUnk_03 = 0;
    s.mUnk_04 = 0;
    s.mUnk_08 = 0;
    s.mUnk_0c = 0;
    p = a + 1;
    ch = *p;
    if (ch == '%') {
        s.mUnk_06 = ch;
        *c = s;
        return p + 1;
    }
    for (;;) {
        k = 1;
        switch (ch) {
            case '-':
                s.mUnk_00 = 0;
                break;
            case '+':
                s.mUnk_01 = 1;
                break;
            case ' ':
                if (s.mUnk_01 != 1) {
                    s.mUnk_01 = 2;
                }
                break;
            case '#':
                s.mUnk_03 = 1;
                break;
            case '0':
                if (s.mUnk_00 != 0) {
                    s.mUnk_00 = 2;
                }
                break;
            default:
                k = 0;
                break;
        }
        if (!k) {
            break;
        }
        ch = *++p;
    }
    if (ch == '*') {
        *b += 4;
        s.mUnk_08 = *(int *) (*b - 4);
        if (s.mUnk_08 < 0) {
            s.mUnk_00 = 0;
            s.mUnk_08 = -s.mUnk_08;
        }
        ch = *++p;
    } else {
        while ((ch >= 0x80 ? 0 : data_0215d384[ch] & 8) != 0) {
            s.mUnk_08 = s.mUnk_08 * 10 + (ch - '0');
            ch = *++p;
        }
    }
    if (s.mUnk_08 > 0x1fd) {
        s.mUnk_06 = 0xffff;
        *c = s;
        return p + 1;
    }
    if (ch == '.') {
        s.mUnk_02 = 1;
        ch = *++p;
        if (ch == '*') {
            *b += 4;
            s.mUnk_0c = *(int *) (*b - 4);
            if (s.mUnk_0c < 0) {
                s.mUnk_02 = 0;
            }
            ch = *++p;
        } else {
            while ((ch >= 0x80 ? 0 : data_0215d384[ch] & 8) != 0) {
                s.mUnk_0c = s.mUnk_0c * 10 + (ch - '0');
                ch = *++p;
            }
        }
    }
    k = 1;
    switch (ch) {
        case 'h':
            s.mUnk_04 = 2;
            if (p[1] == 'h') {
                s.mUnk_04 = 1;
                ch = *++p;
            }
            break;
        case 'l':
            s.mUnk_04 = 3;
            if (p[1] == 'l') {
                s.mUnk_04 = 4;
                ch = *++p;
            }
            break;
        case 'L':
            s.mUnk_04 = 5;
            break;
        default:
            k = 0;
            break;
    }
    if (k) {
        ch = *++p;
    }
    s.mUnk_06 = ch;
    switch (ch) {
        case 'd':
        case 'i':
        case 'o':
        case 'u':
        case 'x':
        case 'X':
            if (s.mUnk_04 == 5) {
                s.mUnk_04 = 4;
            }
            if (s.mUnk_02 == 0) {
                s.mUnk_0c = 1;
            } else if (s.mUnk_00 == 2) {
                s.mUnk_00 = 1;
            }
            break;
        case 'f':
        case 'F':
            if (s.mUnk_04 == 2 || s.mUnk_04 == 4) {
                s.mUnk_06 = 0xffff;
            } else if (s.mUnk_02 == 0) {
                s.mUnk_0c = 6;
            }
            break;
        case 'g':
        case 'G':
            if (s.mUnk_0c == 0) {
                s.mUnk_0c = 1;
            }
        case 'e':
        case 'E':
            if (s.mUnk_04 == 2 || s.mUnk_04 == 4 || s.mUnk_04 == 1) {
                s.mUnk_06 = 0xffff;
            } else if (s.mUnk_02 == 0) {
                s.mUnk_0c = 6;
            }
            break;
        case 'p':
            s.mUnk_04 = 3;
            s.mUnk_03 = 1;
            s.mUnk_06 = 'x';
            s.mUnk_0c = 8;
            break;
        case 'c':
            if (s.mUnk_04 == 3) {
                s.mUnk_04 = 6;
            } else if (s.mUnk_02 != 0 || s.mUnk_04 != 0) {
                s.mUnk_06 = 0xffff;
            }
            break;
        case 's':
            if (s.mUnk_04 == 3) {
                s.mUnk_04 = 6;
            } else if (s.mUnk_04 != 0) {
                s.mUnk_06 = 0xffff;
            }
            break;
        case 'n':
            if (s.mUnk_04 == 5) {
                s.mUnk_04 = 4;
            }
            break;
        default:
            s.mUnk_06 = 0xffff;
            break;
    }
    *c = s;
    return p + 1;
}

// Writes the digits of v backwards from end (after a 0 terminator) and returns the address of the first one, or 0
// when more than 0x1fd characters would result. The character s.mUnk_06 picks base 10 ('d', 'i', 'u'), 8 ('o') or
// 16 ('x', 'X'; digits above 9 start at 'a' for 'x', else at 'A'). Nothing is written but the terminator when v
// and s.mUnk_0c are 0, unless mUnk_03 is set and the character is 'o'. 'd' and 'i' negate a negative v and put '-'
// in front; mUnk_00 == 2 pads with '0' to mUnk_08 (less 1 for a sign, less 2 for a 0x prefix); mUnk_01 1 and 2 put
// '+' and ' ' in front; mUnk_03 puts a '0' in front for base 8 and '0' plus the character for base 16.
u16 *func_0213e1f0(unsigned long v, u16 *end, Unk0213d398 s) {
    unsigned long b;
    u16 *p;
    int n;
    int a;
    int m;
    int k;
    u8 t;
    int f;
    int d;
    u16 c;

    m = s.mUnk_0c;
    t = s.mUnk_03;
    c = s.mUnk_06;
    k = s.mUnk_08;
    f = s.mUnk_01;
    a = 0;
    n = 0;
    p = end;
    *--p = 0;
    if (v == 0 && m == 0) {
        if (t == 0 || c != 'o') {
            return p;
        }
    }
    switch (c) {
        case 'd':
        case 'i':
            b = 10;
            if ((int) v < 0) {
                v = -v;
                a = 1;
            }
            break;
        case 'o':
            b = 8;
            f = 0;
            break;
        case 'u':
            b = 10;
            f = 0;
            break;
        case 'x':
        case 'X':
            b = 16;
            f = 0;
            break;
    }
    do {
        d = v % b;
        v = v / b;
        if (d < 10) {
            d += '0';
        } else if (c == 'x') {
            d += 0x57;
        } else {
            d += 0x37;
        }
        *--p = d;
        n++;
    } while (v != 0);
    if (b == 8 && t != 0) {
        if (*p != '0') {
            *--p = '0';
            n++;
        }
    }
    if (s.mUnk_00 == 2) {
        m = k;
        if (a != 0 || f != 0) {
            m--;
        }
        if (b == 16 && t != 0) {
            m -= 2;
        }
    }
    if (m + (end - p) > 0x1fd) {
        return 0;
    }
    while (n < m) {
        n++;
        *--p = '0';
    }
    if (b == 16 && t != 0) {
        *--p = c;
        *--p = '0';
    }
    if (a != 0) {
        *--p = '-';
    } else if (f == 1) {
        *--p = '+';
    } else if (f == 2) {
        *--p = ' ';
    }
    return p;
}

// Same as func_0213e1f0 with a 64-bit v (one word per half; the digit and the quotient come from 64-bit unsigned
// division and remainder).
u16 *func_0213deec(u64 v, u16 *end, Unk0213d398 s) {
    int a;
    int m;
    int k;
    u8 t;
    int d;
    u64 b;
    u16 *p;
    s32 n;
    u16 c;
    u8 f;
    int e;

    m = s.mUnk_0c;
    t = s.mUnk_03;
    f = s.mUnk_01;
    k = s.mUnk_08;
    a = 0;
    n = 0;
    c = s.mUnk_06;
    p = end;
    *--p = 0;
    if (v == 0 && m == 0) {
        if (t == 0 || c != 'o') {
            return p;
        }
    }
    switch (c) {
        case 'd':
        case 'i':
            b = 10;
            if ((s64) v < 0) {
                v = -v;
                a = 1;
            }
            break;
        case 'o':
            b = 8;
            f = 0;
            break;
        case 'u':
            b = 10;
            f = 0;
            break;
        case 'x':
        case 'X':
            b = 16;
            f = 0;
            break;
    }
    do {
        d = v % b;
        v = v / b;
        if (d < 10) {
            e = d + '0';
        } else if (c == 'x') {
            e = d + 0x57;
        } else {
            e = d + 0x37;
        }
        *--p = e;
        n++;
    } while (v != 0);
    if (b == 8 && t != 0) {
        if (*p != '0') {
            *--p = '0';
            n++;
        }
    }
    if (s.mUnk_00 == 2) {
        m = k;
        if (a != 0 || f != 0) {
            m--;
        }
        if (b == 16 && t != 0) {
            m -= 2;
        }
    }
    if (m + (end - p) > 0x1fd) {
        return 0;
    }
    while (n < m) {
        n++;
        *--p = '0';
    }
    if (b == 16 && t != 0) {
        *--p = c;
        *--p = '0';
    }
    if (a != 0) {
        *--p = '-';
    } else if (f == 1) {
        *--p = '+';
    } else if (f == 2) {
        *--p = ' ';
    }
    return p;
}

void func_0213dcd4(Unk02136638 *a, int k) {
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

u16 *func_0213d398(double v, u16 *a, Unk0213d398 b) {
    Unk02140c28 g;
    Unk02136638 h;
    u8 buf[0x200];
    int k;
    u16 t;
    u8 x;
    u8 y;
    u8 *p;
    u8 *q;
    u16 *r;
    int e;
    int m;
    int f;
    int n;
    int i;
    u8 c;

    k = b.mUnk_0c;
    t = b.mUnk_06;
    x = b.mUnk_03;
    y = b.mUnk_01;
    if (k > 509) {
        return 0;
    }
    g.mUnk_00 = 0;
    g.mUnk_02 = 0x20;
    func_02140c28(&g, v, &h);
    p = h.mUnk_05 + h.mUnk_04;
    while (h.mUnk_04 > 1 && *--p == '0') {
        h.mUnk_04--;
        h.mUnk_02++;
    }
    switch (h.mUnk_05[0]) {
        case '0':
            h.mUnk_02 = 0;
            break;
        case 'I':
            if (v < 0.0) {
                r = a - 5;
                if ((t >= 0x80 ? 0 : data_0215d384[t] & 0x200) != 0) {
                    wcscpy(r, L"-INF");
                } else {
                    wcscpy(r, L"-inf");
                }
            } else {
                r = a - 4;
                if ((t >= 0x80 ? 0 : data_0215d384[t] & 0x200) != 0) {
                    wcscpy(r, L"INF");
                } else {
                    wcscpy(r, L"inf");
                }
            }
            return r;
        case 'N':
            r = a - 4;
            wcscpy(r, L"NaN");
            return r;
    }
    h.mUnk_02 += h.mUnk_04 - 1;
    p = buf + sizeof(buf);
    *--p = 0;
    switch (t) {
        case 'g':
        case 'G':
            if (h.mUnk_04 > k) {
                func_0213dcd4(&h, k);
            }
            if (h.mUnk_02 < -4 || h.mUnk_02 >= k) {
                if (x != 0) {
                    k--;
                } else {
                    k = h.mUnk_04 - 1;
                }
                if (t == 'g') {
                    t = 'e';
                } else {
                    t = 'E';
                }
                goto exp;
            }
            if (x != 0) {
                k -= h.mUnk_02 + 1;
            } else {
                if ((k = h.mUnk_04 - (h.mUnk_02 + 1)) < 0) {
                    k = 0;
                }
            }
            goto fix;
        case 'e':
        case 'E':
        exp:
            if (h.mUnk_04 > k + 1) {
                func_0213dcd4(&h, k + 1);
            }
            e = h.mUnk_02;
            c = '+';
            if (e < 0) {
                e = -e;
                c = '-';
            }
            for (n = 0; e != 0 || n < 2; n++) {
                *--p = e % 10 + '0';
                e /= 10;
            }
            *--p = c;
            *--p = t;
            if (buf - p + k > 509) {
                return 0;
            }
            if (h.mUnk_04 < k + 1) {
                for (i = k + 2 - h.mUnk_04; --i != 0;) {
                    *--p = '0';
                }
            }
            q = h.mUnk_05 + h.mUnk_04;
            for (i = h.mUnk_04; --i != 0;) {
                *--p = *--q;
            }
            if (k != 0 || x != 0) {
                *--p = '.';
            }
            *--p = h.mUnk_05[0];
            if (h.mUnk_00 != 0) {
                *--p = '-';
            } else if (y == 1) {
                *--p = '+';
            } else if (y == 2) {
                *--p = ' ';
            }
            break;
        case 'f':
        case 'F':
        fix:
            if ((f = h.mUnk_04 - h.mUnk_02 - 1) < 0) {
                f = 0;
            }
            if (f > k) {
                func_0213dcd4(&h, h.mUnk_04 - (f - k));
                if ((f = h.mUnk_04 - h.mUnk_02 - 1) < 0) {
                    f = 0;
                }
            }
            if ((m = h.mUnk_02 + 1) < 0) {
                m = 0;
            }
            if (m + f > 509) {
                return 0;
            }
            q = h.mUnk_05 + h.mUnk_04;
            for (i = 0; i < k - f; i++) {
                *--p = '0';
            }
            for (i = 0; i < f && i < h.mUnk_04; i++) {
                *--p = *--q;
            }
            for (; i < f; i++) {
                *--p = '0';
            }
            if (k != 0 || x != 0) {
                *--p = '.';
            }
            if (m != 0) {
                for (i = 0; i < m - h.mUnk_04; i++) {
                    *--p = '0';
                }
                for (; i < m; i++) {
                    *--p = *--q;
                }
            } else {
                *--p = '0';
            }
            if (h.mUnk_00 != 0) {
                *--p = '-';
            } else if (y == 1) {
                *--p = '+';
            } else if (y == 2) {
                *--p = ' ';
            }
            break;
    }
    r = a - strlen(p) - 1;
    mbstowcs(r, p, strlen(p));
    return r;
}

int func_0213cae0(void *(*a)(void *, const u16 *, u32), void *b, const u16 *c, char *d) {
    u16 e = ' ';
    u16 f;
    u8 g;
    Unk0213d398 s;
    u16 buf[512];
    int t;
    long v;
    u64 vl;
    const u16 *q;
    int w;
    u16 *p;
    int n;
    double x;
    const u8 *bp;
    int m;
    const u16 *r;
    const u8 *bq;
    int k;

    t = 0;
    while (*c != 0) {
        q = wcschr(c, '%');
        if (q == 0) {
            n = wcslen(c);
            t += n;
            if (n != 0 && a(b, c, n) == 0) {
                return -1;
            }
            break;
        }
        n = q - c;
        t += n;
        if (n != 0 && a(b, c, n) == 0) {
            return -1;
        }
        c = func_0213e468(q, &d, &s);
        switch (s.mUnk_06) {
            case 'd':
            case 'i':
                if (s.mUnk_04 == 3) {
                    d += 4;
                    v = *(long *) (d - 4);
                } else if (s.mUnk_04 == 4) {
                    d += 8;
                    vl = *(u64 *) (d - 8);
                } else {
                    d += 4;
                    v = *(int *) (d - 4);
                }
                if (s.mUnk_04 == 2) {
                    v = (short) v;
                }
                if (s.mUnk_04 == 4) {
                    p = func_0213deec(vl, buf + 512, s);
                    if (p == 0) {
                        goto bad;
                    }
                } else {
                    p = func_0213e1f0(v, buf + 512, s);
                    if (p == 0) {
                        goto bad;
                    }
                }
                n = buf + 511 - p;
                break;
            case 'o':
            case 'u':
            case 'x':
            case 'X':
                if (s.mUnk_04 == 3) {
                    d += 4;
                    v = *(long *) (d - 4);
                } else if (s.mUnk_04 == 4) {
                    d += 8;
                    vl = *(u64 *) (d - 8);
                } else {
                    d += 4;
                    v = *(int *) (d - 4);
                }
                if (s.mUnk_04 == 2) {
                    v = (u16) v;
                }
                if (s.mUnk_04 == 4) {
                    p = func_0213deec(vl, buf + 512, s);
                    if (p == 0) {
                        goto bad;
                    }
                } else {
                    p = func_0213e1f0(v, buf + 512, s);
                    if (p == 0) {
                        goto bad;
                    }
                }
                n = buf + 511 - p;
                break;
            case 'e':
            case 'f':
            case 'g':
            case 'E':
            case 'F':
            case 'G':
                if (s.mUnk_04 == 5) {
                    d += 8;
                    x = *(long double *) (d - 8);
                } else {
                    d += 8;
                    x = *(double *) (d - 8);
                }
                p = func_0213d398(x, buf + 512, s);
                if (p == 0) {
                    goto bad;
                }
                n = buf + 511 - p;
                break;
            case 's':
                if (s.mUnk_04 == 6) {
                    d += 4;
                    p = *(u16 **) (d - 4);
                    if (p == 0) {
                        p = L"";
                    }
                    if (s.mUnk_03 != 0) {
                        n = (u8) *p++;
                        if (s.mUnk_02 != 0 && n > s.mUnk_0c) {
                            n = s.mUnk_0c;
                        }
                    } else if (s.mUnk_02 != 0) {
                        n = s.mUnk_0c;
                        r = wmemchr(p, 0, n);
                        if (r != 0) {
                            n = r - p;
                        }
                    } else {
                        n = wcslen(p);
                    }
                } else {
                    d += 4;
                    bp = *(const u8 **) (d - 4);
                    if (bp == 0) {
                        bp = (const u8 *) "";
                    }
                    if (s.mUnk_03 != 0) {
                    // reads p (the u16 pointer of the other branch), not bp
                        m = (u8) *p;
                        if (s.mUnk_02 != 0 && m > s.mUnk_0c) {
                            m = s.mUnk_0c;
                        }
                    } else if (s.mUnk_02 != 0) {
                        m = s.mUnk_0c;
                        bq = memchr(bp, 0, m);
                        if (bq != 0) {
                            m = bq - bp;
                        }
                    } else {
                        m = strlen(bp);
                    }
                    n = mbstowcs(buf, bp, m);
                    if (n < 0) {
                        goto bad;
                    }
                    p = buf;
                }
                break;
            case 'n':
                d += 4;
                p = *(u16 **) (d - 4);
                switch (s.mUnk_04) {
                    case 0:
                        *(int *) p = t;
                        break;
                    case 2:
                        *(short *) p = t;
                        break;
                    case 3:
                        *(long *) p = t;
                        break;
                    case 4:
                        *(long long *) p = t;
                        break;
                }
                continue;
            case 'c':
                p = buf;
                if (s.mUnk_04 == 6) {
                    d += 4;
                    n = 1;
                    *p = *(int *) (d - 4);
                } else {
                    d += 4;
                    g = *(int *) (d - 4);
                    n = mbtowc(p, &g, 1);
                }
                break;
            case '%':
                buf[0] = '%';
                p = buf;
                n = 1;
                break;
            case 0xffff:
            default:
            bad:
                n = wcslen(q);
                t += n;
                if (n != 0 && a(b, q, n) == 0) {
                    return -1;
                }
                return t;
        }
        w = n;
        if (s.mUnk_00 != 0) {
            k = s.mUnk_00 == 2 ? '0' : ' ';
            e = k;
            if ((*p == '+' || *p == '-' || *p == ' ') && k == '0') {
                if (a(b, p, 1) == 0) {
                    return -1;
                }
                p++;
                n--;
            }
            while (w < s.mUnk_08) {
                if (a(b, &e, 1) == 0) {
                    return -1;
                }
                w++;
            }
        }
        if (n != 0 && a(b, p, n) == 0) {
            return -1;
        }
        if (s.mUnk_00 == 0) {
            while (w < s.mUnk_08) {
                f = ' ';
                if (a(b, &f, 1) == 0) {
                    return -1;
                }
                w++;
            }
        }
        t += w;
    }
    return t;
}
