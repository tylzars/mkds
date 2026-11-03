#pragma avoid_byte all

#include "code_021384dc.h"
#include "code_02134b18.h"
#include "code_0213a460.h"
#include "Main/Unknown/unk_0216e000.h"

const char *func_02139400(const char *a, Unk02139400 *b) {
    Unk02139400 s = {0, 0, 0, 0, 0x7fffffff};
    const char *p = a + 1;
    int c = *p;
    int g;
    int h;
    int d;
    int i;
    unsigned char *q;
    unsigned char m;

    if (c == '%') {
        s.mUnk_03 = c;
        *b = s;
        return p + 1;
    }
    if (c == '*') {
        s.mUnk_00 = 1;
        c = *++p;
    }
    if ((c < 0 || c >= 0x80) ? 0 : (data_0215d284[c] & 8)) {
        s.mUnk_04 = 0;
        do {
            s.mUnk_04 = s.mUnk_04 * 10 + (c - '0');
            c = *++p;
        } while ((c < 0 || c >= 0x80) ? 0 : (data_0215d284[c] & 8));
        if (s.mUnk_04 == 0) {
            s.mUnk_03 = 0xff;
            *b = s;
            return p + 1;
        }
        s.mUnk_01 = 1;
    }
    g = 1;
    switch (c) {
        case 'h':
            s.mUnk_02 = 2;
            if (p[1] == 'h') {
                s.mUnk_02 = 1;
                c = *++p;
            }
            break;
        case 'l':
            s.mUnk_02 = 3;
            if (p[1] == 'l') {
                s.mUnk_02 = 7;
                c = *++p;
            }
            break;
        case 'L':
            s.mUnk_02 = 9;
            break;
        case 'j':
            s.mUnk_02 = 4;
            break;
        case 'z':
            s.mUnk_02 = 5;
            break;
        case 't':
            s.mUnk_02 = 6;
            break;
        default:
            g = 0;
            break;
    }
    if (g) {
        c = *++p;
    }
    s.mUnk_03 = c;
    switch (c) {
        case 'd':
        case 'i':
        case 'o':
        case 'u':
        case 'x':
        case 'X':
            if (s.mUnk_02 == 9) {
                s.mUnk_03 = 0xff;
            }
            break;
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'f':
        case 'F':
        case 'g':
        case 'G':
            m = s.mUnk_02;
            if (m == 1 || m == 2 || (unsigned char) (m + 0xfc) <= 3) {
                s.mUnk_03 = 0xff;
            } else if (m == 3) {
                s.mUnk_02 = 8;
            }
            break;
        case 'p':
            s.mUnk_02 = 3;
            s.mUnk_03 = 'x';
            break;
        case 'c':
            if (s.mUnk_02 == 3) {
                s.mUnk_02 = 10;
            } else if (s.mUnk_02 != 0) {
                s.mUnk_03 = 0xff;
            }
            break;
        case 's':
            if (s.mUnk_02 == 3) {
                s.mUnk_02 = 10;
            } else if (s.mUnk_02 != 0) {
                s.mUnk_03 = 0xff;
            }
            for (i = 32, q = s.mUnk_08; i > 0; i--) {
                *q++ = 0xff;
            }
            s.mUnk_08[1] = 0xc1;
            s.mUnk_08[4] = 0xfe;
            break;
        case '[':
            if (s.mUnk_02 == 3) {
                s.mUnk_02 = 10;
            } else if (s.mUnk_02 != 0) {
                s.mUnk_03 = 0xff;
            }
            c = *++p;
            h = 0;
            if (c == '^') {
                c = *++p;
                h = 1;
            }
            if (c == ']') {
                s.mUnk_08[']' >> 3] |= 1 << (']' & 7);
                c = *++p;
            }
            while (c != 0 && c != ']') {
                s.mUnk_08[(unsigned char) c >> 3] |= 1 << (c & 7);
                if (p[1] == '-' && (d = p[2]) != 0 && d != ']') {
                    for (c++; c <= d; c++) {
                        s.mUnk_08[(unsigned char) c >> 3] |= 1 << (c & 7);
                    }
                    c = *(p += 3);
                } else {
                    c = *++p;
                }
            }
            if (c == 0) {
                s.mUnk_03 = 0xff;
            } else if (h) {
                for (i = 32, q = s.mUnk_08; i > 0; i--, q++) {
                    *q = ~*q;
                }
            }
            break;
        case 'n':
            break;
        default:
            s.mUnk_03 = 0xff;
            break;
    }
    *b = s;
    return p + 1;
}

static inline int func_02138618_inline(int c) {
    return (c < 0 || c >= 0x80) ? 0 : (data_0215d284[c] & 0x100);
}

int func_02138618(Unk02138618Func fn, void *a, const char *s, char *v) {
    int k;
    int s32;
    long long s64;
    int r;
    int m;
    unsigned int u32;
    unsigned long long u64;
    int ch;
    unsigned char c;
    char *p;
    int base;
    char chb;
    int n;
    int g;
    int e;
    double d;
    Unk02139400 t;

    k = 0;
    r = 0;
    m = 0;
    while ((c = *s) != 0) {
        if (func_02138618_inline(c)) {
            do {
                s++;
                c = *s;
            } while (func_02138618_inline(c));
            while (chb = fn(a, 0, 0), func_02138618_inline(chb)) {
                k++;
            }
            fn(a, chb, 1);
            continue;
        }
        if (c != '%') {
            chb = fn(a, 0, 0);
            if (c != chb) {
                fn(a, chb, 1);
                goto exit;
            }
            s++;
            k++;
            continue;
        }
        s = func_02139400(s, &t);
        if (t.mUnk_00 == 0 && t.mUnk_03 != '%') {
            v += 4;
            p = ((char **) v)[-1];
        } else {
            p = 0;
        }
        if (t.mUnk_03 != 'n') {
            if (fn(a, 0, 2) != 0) {
                goto exit;
            }
        }
        switch (t.mUnk_03) {
            case 'd':
                base = 10;
                goto signed_int;
            case 'i':
                base = 0;
            signed_int:
                if (t.mUnk_02 == 7) {
                    u64 = func_0213c110(base, t.mUnk_04, fn, a, &n, &g, &e);
                } else {
                    u32 = func_0213c560(base, t.mUnk_04, fn, a, &n, &g, &e);
                }
                if (n == 0) {
                    goto exit;
                }
                k += n;
                if (t.mUnk_02 == 7) {
                    if (g == 0) {
                        s64 = u64;
                    } else {
                        s64 = -u64;
                    }
                } else {
                    if (g != 0) {
                        s32 = -u32;
                    } else {
                        s32 = u32;
                    }
                }
                if (p != 0) {
                    switch (t.mUnk_02) {
                        case 0:
                            *(int *) p = s32;
                            break;
                        case 1:
                            *p = s32;
                            break;
                        case 2:
                            *(short *) p = s32;
                            break;
                        case 3:
                            *(int *) p = s32;
                            break;
                        case 4:
                            *(long long *) p = s32;
                            break;
                        case 5:
                            *(int *) p = s32;
                            break;
                        case 6:
                            *(int *) p = s32;
                            break;
                        case 7:
                            *(long long *) p = s64;
                            break;
                    }
                    r++;
                }
                m++;
                break;
            case 'o':
                base = 8;
                goto unsigned_int;
            case 'u':
                base = 10;
                goto unsigned_int;
            case 'X':
            case 'x':
                base = 16;
            unsigned_int:
                if (t.mUnk_02 == 7) {
                    u64 = func_0213c110(base, t.mUnk_04, fn, a, &n, &g, &e);
                } else {
                    u32 = func_0213c560(base, t.mUnk_04, fn, a, &n, &g, &e);
                }
                if (n == 0) {
                    goto exit;
                }
                k += n;
                if (g != 0) {
                    if (t.mUnk_02 == 7) {
                        u64 = -u64;
                    } else {
                        u32 = -u32;
                    }
                }
                if (p != 0) {
                    switch (t.mUnk_02) {
                        case 0:
                            *(unsigned int *) p = u32;
                            break;
                        case 1:
                            *(unsigned char *) p = u32;
                            break;
                        case 2:
                            *(unsigned short *) p = u32;
                            break;
                        case 3:
                            *(unsigned int *) p = u32;
                            break;
                        case 4:
                            *(unsigned long long *) p = u32;
                            break;
                        case 5:
                            *(unsigned int *) p = u32;
                            break;
                        case 6:
                            *(unsigned int *) p = u32;
                            break;
                        case 7:
                            *(unsigned long long *) p = u64;
                            break;
                    }
                    r++;
                }
                m++;
                break;
            case 'A':
            case 'E':
            case 'F':
            case 'G':
            case 'a':
            case 'e':
            case 'f':
            case 'g':
                d = func_0213a550(t.mUnk_04, fn, a, &n, &e);
                if (n == 0) {
                    goto exit;
                }
                k += n;
                if (p != 0) {
                    switch (t.mUnk_02) {
                        case 0:
                            *(float *) p = d;
                            break;
                        case 8:
                            *(double *) p = d;
                            break;
                        case 9:
                            *(double *) p = d;
                            break;
                    }
                    r++;
                }
                m++;
                break;
            case 'c':
                if (t.mUnk_01 == 0) {
                    t.mUnk_04 = 1;
                }
                if (p != 0) {
                    n = 0;
                    while (t.mUnk_04-- != 0 && (ch = fn(a, 0, 0)) != -1) {
                        chb = ch;
                        if (t.mUnk_02 == 10) {
                            mbtowc((u16 *) p, &chb, 1);
                            p += 1;
                        } else {
                            *p++ = chb;
                        }
                        n++;
                    }
                    chb = ch;
                    if (n == 0) {
                        goto exit;
                    }
                    k += n;
                    r++;
                } else {
                    n = 0;
                    while (t.mUnk_04-- != 0 && (ch = fn(a, 0, 0)) != -1) {
                        chb = ch;
                        n++;
                    }
                    chb = ch;
                    if (n == 0) {
                        goto exit;
                    }
                }
                m++;
                break;
            case '%':
                while (chb = fn(a, 0, 0), func_02138618_inline(chb)) {
                    k++;
                }
                if (chb != '%') {
                    fn(a, chb, 1);
                    goto exit;
                }
                k++;
                break;
            case 's':
                chb = fn(a, 0, 0);
                while (func_02138618_inline(chb)) {
                    k++;
                    chb = fn(a, 0, 0);
                }
                fn(a, chb, 1);
            case '[':
                if (p != 0) {
                    n = 0;
                    while (t.mUnk_04-- != 0 && (ch = fn(a, 0, 0)) != -1) {
                        chb = ch;
                        if (!(t.mUnk_08[chb >> 3] & (1 << (chb & 7)))) {
                            break;
                        }
                        if (t.mUnk_02 == 10) {
                            mbtowc((u16 *) p, &chb, 1);
                            p += 2;
                        } else {
                            *p++ = chb;
                        }
                        n++;
                    }
                    chb = ch;
                    if (n == 0) {
                        fn(a, chb, 1);
                        goto exit;
                    }
                    k += n;
                    if (t.mUnk_02 == 10) {
                        *(short *) p = 0;
                    } else {
                        *p = 0;
                    }
                    r++;
                } else {
                    n = 0;
                    while (t.mUnk_04-- != 0 && (ch = fn(a, 0, 0)) != -1) {
                        chb = ch;
                        if (!(t.mUnk_08[chb >> 3] & (1 << (chb & 7)))) {
                            break;
                        }
                        n++;
                    }
                    chb = ch;
                    if (n == 0) {
                        fn(a, chb, 1);
                        break;
                    }
                    k += n;
                }
                if (t.mUnk_04 >= 0) {
                    fn(a, chb, 1);
                }
                m++;
                break;
            case 'n':
                if (p != 0) {
                    switch (t.mUnk_02) {
                        case 0:
                            *(int *) p = k;
                            break;
                        case 2:
                            *(short *) p = k;
                            break;
                        case 3:
                            *(int *) p = k;
                            break;
                        case 1:
                            *p = k;
                            break;
                        case 7:
                            *(long long *) p = k;
                            break;
                    }
                }
                break;
            case 0xff:
            default:
                goto exit;
        }
    }
exit:
    if (fn(a, 0, 2) != 0 && m == 0) {
        return -1;
    }
    return r;
}

int func_021385a0(void *a, int b, int c) {
    Unk0213a460 *p;
    const char *s;
    u32 ch;

    p = a;
    switch (c) {
        case 0:
            s = p->mUnk_00;
            ch = *s;
            if (ch == 0) {
                p->mUnk_04 = 1;
                return -1;
            }
            p->mUnk_00 = s + 1;
            return ch;
        case 1:
            if (p->mUnk_04 == 0) {
                p->mUnk_00--;
            } else {
                p->mUnk_04 = 0;
            }
            return b;
        case 2:
            return p->mUnk_04;
        default:
            return 0;
    }
}

int vsscanf(const char *a, const char *b, char *c) {
    Unk0213a460 loc;

    loc.mUnk_00 = a;
    if (a == 0 || *a == 0) {
        return -1;
    }
    loc.mUnk_04 = 0;
    return func_02138618(func_021385a0, &loc, b, c);
}

int sscanf(const char *a, const char *b, ...) {
    char *ap;

    ap = (char *) (((u32) &b & ~3) + 4);
    return vsscanf(a, b, ap);
}

u32 rand(void) {
    data_0216eeb8 = data_0216eeb8 * 0x41c64e6d + 0x3039;
    return (data_0216eeb8 >> 16) & 0x7fff;
}
