#include "code_0200d118.h"

void StringFormatPutChar(Unk0200d118 *s, char c) {
    if (s->mUnk_00 != 0) {
        s->mUnk_04[0] = c;
        s->mUnk_00 = s->mUnk_00 - 1;
    }
    s->mUnk_04 = s->mUnk_04 + 1;
}

void StringFormatPutRepeat(Unk0200d118 *s, char c, int n) {
    u32 k;
    u32 m;

    if (n <= 0) {
        return;
    }
    m = s->mUnk_00;
    if (m > n) {
        m = n;
    }
    for (k = 0; k < m; k++) {
        s->mUnk_04[k] = c;
    }
    s->mUnk_00 = s->mUnk_00 - m;
    s->mUnk_04 = s->mUnk_04 + n;
}

void StringFormatPutBytes(Unk0200d118 *s, const char *p, int n) {
    u32 k;
    u32 m;

    if (n <= 0) {
        return;
    }
    m = s->mUnk_00;
    if (m > n) {
        m = n;
    }
    for (k = 0; k < m; k++) {
        s->mUnk_04[k] = p[k];
    }
    s->mUnk_00 = s->mUnk_00 - m;
    s->mUnk_04 = s->mUnk_04 + n;
}

int StringFormat(char *buf, const char *p, ...) {
    char *q;

    q = (char *) (((u32) &p & ~3) + 4);
    return StringFormatArgs(buf, p, q);
}

int StringFormatArgs(char *buf, const char *p, char *q) {
    return StringFormatArgsBounded(buf, 0x7fffffff, p, q);
}

int StringFormatBounded(char *buf, u32 n, const char *p, ...) {
    char *q;

    q = (char *) (((u32) &p & ~3) + 4);
    return StringFormatArgsBounded(buf, n, p, q);
}

int StringFormatArgsBounded(char *buf, u32 n, const char *p, char *q) {
    int w;
    int g;
    int i;
    int f;
    int m;
    int z;
    char c;
    int k;
    int h;
    const char *t;
    char e;
    int j;
    int x;
    u64 v;
    int y;
    const char *u;
    char a[2];
    char b[24];
    Unk0200d118 s;

    s.mUnk_00 = n;
    s.mUnk_08 = buf;
    s.mUnk_04 = buf;
    while (*p != 0) {
        c = *(const s8 *) p;
        if ((u32) (((u8) c ^ 0x20) - 0xa1) < 0x3c) {
            StringFormatPutChar(&s, c);
            c = *++p;
            if (c != 0) {
                p++;
                StringFormatPutChar(&s, c);
            }
            continue;
        }
        if (c != '%') {
            p++;
            StringFormatPutChar(&s, c);
            continue;
        }
        f = 0;
        m = -1;
        w = 0;
        k = 10;
        h = 0x57;
        t = p;
        for (;;) {
            e = *++p;
            switch (e) {
                case '+':
                    if (p[-1] == ' ') {
                        f |= 2;
                        continue;
                    }
                    break;
                case ' ':
                    f |= 1;
                    continue;
                case '-':
                    f |= 8;
                    continue;
                case '0':
                    f |= 0x10;
                    continue;
            }
            break;
        }
        if (e == '*') {
            q += 4;
            w = *(int *) (q - 4);
            p++;
            if (w < 0) {
                w = -w;
                f |= 8;
            }
        } else {
            while (*p >= '0' && *p <= '9') {
                w = w * 10 + *p++ - '0';
            }
        }
        if (*p == '.') {
            m = 0;
            if (*++p == '*') {
                q += 4;
                m = *(int *) (q - 4);
                p++;
                if (m < 0) {
                    m = -1;
                }
            } else {
                while (*p >= '0' && *p <= '9') {
                    m = m * 10 + *p++ - '0';
                }
            }
        }
        switch (*p) {
            case 'h':
                if (*++p != 'h') {
                    f |= 0x40;
                } else {
                    p++;
                    f |= 0x100;
                }
                break;
            case 'l':
                if (*++p != 'l') {
                    f |= 0x20;
                } else {
                    p++;
                    f |= 0x80;
                }
                break;
        }
        switch (*p) {
            case 'd':
            case 'i':
                goto label_int;
            case 'o':
                k = 8;
                f |= 0x1000;
                goto label_int;
            case 'u':
                f |= 0x1000;
                goto label_int;
            case 'X':
                h = 0x37;
                goto label_16;
            case 'p':
                f |= 4;
                m = 8;
                goto label_16;
            case 'x':
                goto label_16;
            case 'c':
                if (m >= 0) {
                    goto label_copy;
                }
                q += 4;
                y = *(int *) (q - 4);
                if (f & 8) {
                    StringFormatPutChar(&s, y);
                    StringFormatPutRepeat(&s, ' ', w - 1);
                } else {
                    StringFormatPutRepeat(&s, (f & 0x10) ? '0' : ' ', w - 1);
                    StringFormatPutChar(&s, y);
                }
                p++;
                continue;
            case 's':
                q += 4;
                j = 0;
                u = *(const char **) (q - 4);
                if (m < 0) {
                    while (u[j] != 0) {
                        j++;
                    }
                } else {
                    while (j < m && u[j] != 0) {
                        j++;
                    }
                }
                w -= j;
                if (f & 8) {
                    StringFormatPutBytes(&s, u, j);
                    StringFormatPutRepeat(&s, ' ', w);
                } else {
                    StringFormatPutRepeat(&s, (f & 0x10) ? '0' : ' ', w);
                    StringFormatPutBytes(&s, u, j);
                }
                p++;
                continue;
            case 'n':
                x = s.mUnk_04 - s.mUnk_08;
                if (!(f & 0x100)) {
                    if (f & 0x40) {
                        q += 4;
                        **(s16 **) (q - 4) = x;
                    } else if (f & 0x80) {
                        q += 4;
                        **(s64 **) (q - 4) = x;
                    } else {
                        q += 4;
                        **(int **) (q - 4) = x;
                    }
                }
                p++;
                continue;
            case '%':
                if (t + 1 == p) {
                    StringFormatPutChar(&s, *p++);
                    continue;
                }
            default:
            label_copy:
                StringFormatPutBytes(&s, t, p - t);
                continue;
        }
    label_16:
        k = 16;
        f |= 0x1000;
    label_int:
        i = 0;
        if (f & 8) {
            f &= ~0x10;
        }
        if (m >= 0) {
            f &= ~0x10;
        } else {
            m = 1;
        }
        if (f & 0x1000) {
            if (f & 0x100) {
                q += 4;
                v = *(u8 *) (q - 4);
            } else if (f & 0x40) {
                q += 4;
                v = *(u16 *) (q - 4);
            } else if (f & 0x80) {
                q += 8;
                v = *(u64 *) (q - 8);
            } else {
                q += 4;
                v = *(u32 *) (q - 4);
            }
            f &= ~3;
            if (f & 4) {
                if (k == 16) {
                    if (v != 0) {
                        a[1] = '0';
                        a[0] = h + 0x21;
                        i = 2;
                    }
                } else if (k == 8) {
                    a[0] = '0';
                    i = 1;
                }
            }
        } else {
            if (f & 0x100) {
                q += 4;
                v = *(s8 *) (q - 4);
            } else if (f & 0x40) {
                q += 4;
                v = *(s16 *) (q - 4);
            } else if (f & 0x80) {
                q += 8;
                v = *(s64 *) (q - 8);
            } else {
                q += 4;
                v = *(int *) (q - 4);
            }
            if ((v >> 32) & 0x80000000) {
                a[0] = '-';
                v = ~v + 1;
                i = 1;
            } else if (v != 0 || m != 0) {
                if (f & 2) {
                    a[0] = '+';
                    i = 1;
                } else if (f & 1) {
                    a[0] = ' ';
                    i = 1;
                }
            }
        }
        g = 0;
        switch (k) {
            case 8:
                while (v != 0) {
                    int d = (int) (v & 7);
                    v >>= 3;
                    b[g++] = d + '0';
                }
                break;
            case 10:
                if ((v >> 32) == 0) {
                    u32 o = v;
                    while (o != 0) {
                        u32 r = o / 10;
                        int d = o - r * 10;
                        o = r;
                        b[g++] = d + '0';
                    }
                } else {
                    while (v != 0) {
                        u64 r = v / 10;
                        b[g++] = (int) (v - r * 10) + '0';
                        v = r;
                    }
                }
                break;
            case 16:
                while (v != 0) {
                    int d = (int) (v & 0xf);
                    v >>= 4;
                    if (d < 10) {
                        d += '0';
                    } else {
                        d += h;
                    }
                    b[g++] = d;
                }
                break;
        }
        if (i > 0 && a[0] == '0') {
            b[g++] = '0';
            i = 0;
        }
        z = m - g;
        if (f & 0x10) {
            if (z < w - g - i) {
                z = w - g - i;
            }
        }
        if (z > 0) {
            w -= z;
        }
        w -= i + g;
        if (!(f & 8)) {
            StringFormatPutRepeat(&s, ' ', w);
        }
        while (i > 0) {
            StringFormatPutChar(&s, a[--i]);
        }
        StringFormatPutRepeat(&s, '0', z);
        while (g > 0) {
            StringFormatPutChar(&s, b[--g]);
        }
        if (f & 8) {
            StringFormatPutRepeat(&s, ' ', w);
        }
        p++;
    }
    if (s.mUnk_00 != 0) {
        *s.mUnk_04 = 0;
    } else if (n != 0) {
        *(s.mUnk_08 + n - 1) = 0;
    }
    return s.mUnk_04 - s.mUnk_08;
}
