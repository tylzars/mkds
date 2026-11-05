#include "code_021384cc.h"

#include "Main/Unknown/unk_0216e000.h"

#pragma avoid_byte all

#include "code_02134b18.h"
#include "code_0213a460.h"

u32 gRandValue = 1;

const char *ScanParseSpec(const char *a, ScanSpec *b) {
    ScanSpec s = {0, 0, 0, 0, 0x7fffffff};
    const char *p = a + 1;
    int c = *p;
    int g;
    int h;
    int d;
    int i;
    unsigned char *q;
    unsigned char m;

    if (c == '%') {
        s.mSpecChar = c;
        *b = s;
        return p + 1;
    }
    if (c == '*') {
        s.mStar = 1;
        c = *++p;
    }
    if ((c < 0 || c >= 0x80) ? 0 : (data_0215d284[c] & 8)) {
        s.mMaxLength = 0;
        do {
            s.mMaxLength = s.mMaxLength * 10 + (c - '0');
            c = *++p;
        } while ((c < 0 || c >= 0x80) ? 0 : (data_0215d284[c] & 8));
        if (s.mMaxLength == 0) {
            s.mSpecChar = 0xff;
            *b = s;
            return p + 1;
        }
        s.mHasMaxLength = 1;
    }
    g = 1;
    switch (c) {
        case 'h':
            s.mArgKind = 2;
            if (p[1] == 'h') {
                s.mArgKind = 1;
                c = *++p;
            }
            break;
        case 'l':
            s.mArgKind = 3;
            if (p[1] == 'l') {
                s.mArgKind = 7;
                c = *++p;
            }
            break;
        case 'L':
            s.mArgKind = 9;
            break;
        case 'j':
            s.mArgKind = 4;
            break;
        case 'z':
            s.mArgKind = 5;
            break;
        case 't':
            s.mArgKind = 6;
            break;
        default:
            g = 0;
            break;
    }
    if (g) {
        c = *++p;
    }
    s.mSpecChar = c;
    switch (c) {
        case 'd':
        case 'i':
        case 'o':
        case 'u':
        case 'x':
        case 'X':
            if (s.mArgKind == 9) {
                s.mSpecChar = 0xff;
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
            m = s.mArgKind;
            if (m == 1 || m == 2 || (unsigned char) (m + 0xfc) <= 3) {
                s.mSpecChar = 0xff;
            } else if (m == 3) {
                s.mArgKind = 8;
            }
            break;
        case 'p':
            s.mArgKind = 3;
            s.mSpecChar = 'x';
            break;
        case 'c':
            if (s.mArgKind == 3) {
                s.mArgKind = 10;
            } else if (s.mArgKind != 0) {
                s.mSpecChar = 0xff;
            }
            break;
        case 's':
            if (s.mArgKind == 3) {
                s.mArgKind = 10;
            } else if (s.mArgKind != 0) {
                s.mSpecChar = 0xff;
            }
            for (i = 32, q = s.mCharSet; i > 0; i--) {
                *q++ = 0xff;
            }
            s.mCharSet[1] = 0xc1;
            s.mCharSet[4] = 0xfe;
            break;
        case '[':
            if (s.mArgKind == 3) {
                s.mArgKind = 10;
            } else if (s.mArgKind != 0) {
                s.mSpecChar = 0xff;
            }
            c = *++p;
            h = 0;
            if (c == '^') {
                c = *++p;
                h = 1;
            }
            if (c == ']') {
                s.mCharSet[']' >> 3] |= 1 << (']' & 7);
                c = *++p;
            }
            while (c != 0 && c != ']') {
                s.mCharSet[(unsigned char) c >> 3] |= 1 << (c & 7);
                if (p[1] == '-' && (d = p[2]) != 0 && d != ']') {
                    for (c++; c <= d; c++) {
                        s.mCharSet[(unsigned char) c >> 3] |= 1 << (c & 7);
                    }
                    c = *(p += 3);
                } else {
                    c = *++p;
                }
            }
            if (c == 0) {
                s.mSpecChar = 0xff;
            } else if (h) {
                for (i = 32, q = s.mCharSet; i > 0; i--, q++) {
                    *q = ~*q;
                }
            }
            break;
        case 'n':
            break;
        default:
            s.mSpecChar = 0xff;
            break;
    }
    *b = s;
    return p + 1;
}

static inline int func_02138618_inline(int c) {
    return (c < 0 || c >= 0x80) ? 0 : (data_0215d284[c] & 0x100);
}

int ScanWithSourceFunc(Unk02138618Func fn, ScanStringSource *a, const char *s, char *v) {
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
    ScanSpec t;

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
        s = ScanParseSpec(s, &t);
        if (t.mStar == 0 && t.mSpecChar != '%') {
            v += 4;
            p = ((char **) v)[-1];
        } else {
            p = 0;
        }
        if (t.mSpecChar != 'n') {
            if (fn(a, 0, 2) != 0) {
                goto exit;
            }
        }
        switch (t.mSpecChar) {
            case 'd':
                base = 10;
                goto signed_int;
            case 'i':
                base = 0;
            signed_int:
                if (t.mArgKind == 7) {
                    u64 = ScanInt64(base, t.mMaxLength, fn, a, &n, &g, &e);
                } else {
                    u32 = ScanInt32(base, t.mMaxLength, fn, a, &n, &g, &e);
                }
                if (n == 0) {
                    goto exit;
                }
                k += n;
                if (t.mArgKind == 7) {
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
                    switch (t.mArgKind) {
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
                if (t.mArgKind == 7) {
                    u64 = ScanInt64(base, t.mMaxLength, fn, a, &n, &g, &e);
                } else {
                    u32 = ScanInt32(base, t.mMaxLength, fn, a, &n, &g, &e);
                }
                if (n == 0) {
                    goto exit;
                }
                k += n;
                if (g != 0) {
                    if (t.mArgKind == 7) {
                        u64 = -u64;
                    } else {
                        u32 = -u32;
                    }
                }
                if (p != 0) {
                    switch (t.mArgKind) {
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
                d = ScanDouble(t.mMaxLength, fn, a, &n, &e);
                if (n == 0) {
                    goto exit;
                }
                k += n;
                if (p != 0) {
                    switch (t.mArgKind) {
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
                if (t.mHasMaxLength == 0) {
                    t.mMaxLength = 1;
                }
                if (p != 0) {
                    n = 0;
                    while (t.mMaxLength-- != 0 && (ch = fn(a, 0, 0)) != -1) {
                        chb = ch;
                        if (t.mArgKind == 10) {
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
                    while (t.mMaxLength-- != 0 && (ch = fn(a, 0, 0)) != -1) {
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
                    while (t.mMaxLength-- != 0 && (ch = fn(a, 0, 0)) != -1) {
                        chb = ch;
                        if (!(t.mCharSet[chb >> 3] & (1 << (chb & 7)))) {
                            break;
                        }
                        if (t.mArgKind == 10) {
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
                    if (t.mArgKind == 10) {
                        *(short *) p = 0;
                    } else {
                        *p = 0;
                    }
                    r++;
                } else {
                    n = 0;
                    while (t.mMaxLength-- != 0 && (ch = fn(a, 0, 0)) != -1) {
                        chb = ch;
                        if (!(t.mCharSet[chb >> 3] & (1 << (chb & 7)))) {
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
                if (t.mMaxLength >= 0) {
                    fn(a, chb, 1);
                }
                m++;
                break;
            case 'n':
                if (p != 0) {
                    switch (t.mArgKind) {
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

int ScanStringSourceOp(void *a, int b, int c) {
    ScanStringSource *p;
    const char *s;
    u32 ch;

    p = a;
    switch (c) {
        case 0:
            s = p->mNextChar;
            ch = *s;
            if (ch == 0) {
                p->mAtEnd = 1;
                return -1;
            }
            p->mNextChar = s + 1;
            return ch;
        case 1:
            if (p->mAtEnd == 0) {
                p->mNextChar--;
            } else {
                p->mAtEnd = 0;
            }
            return b;
        case 2:
            return p->mAtEnd;
        default:
            return 0;
    }
}

int vsscanf(const char *a, const char *b, char *c) {
    ScanStringSource loc;

    loc.mNextChar = a;
    if (a == 0 || *a == 0) {
        return -1;
    }
    loc.mAtEnd = 0;
    return ScanWithSourceFunc(ScanStringSourceOp, &loc, b, c);
}

int sscanf(const char *a, const char *b, ...) {
    char *ap;

    ap = (char *) (((u32) &b & ~3) + 4);
    return vsscanf(a, b, ap);
}

u32 rand(void) {
    gRandValue = gRandValue * 0x41c64e6d + 0x3039;
    return (gRandValue >> 16) & 0x7fff;
}

void srand(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    value1 = (u32) &gRandValue;
    *(u32 *) ((value1) + (0)) = value0;
}
