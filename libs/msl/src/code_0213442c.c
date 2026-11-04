#include "code_0213442c.h"

#pragma avoid_byte all

#include "code_02134b18.h"
#include "code_02139f70.h"

int mbtowc(u16 *dst, const char *src, u32 n) {
    return data_0216eccc.mUnk_08->mUnk_00(dst, src, n);
}

int MbtowcSingleByte(u16 *dst, const char *src, u32 n) {
    if (src == 0) {
        return 0;
    }
    if (n == 0) {
        return -1;
    }
    if (dst != 0) {
        *dst = *src;
    }
    if (*src == 0) {
        return 0;
    }
    return 1;
}

int WctombSingleByte(char *dst, u16 c) {
    if (dst == 0) {
        return 0;
    }
    *dst = c;
    return 1;
}

int wctomb(char *dst, u16 c) {
    return data_0216eccc.mUnk_08->mUnk_04(dst, c);
}

int mbstowcs(u16 *dst, const char *src, u32 n) {
    u32 i;
    int len;
    int r;

    len = strlen(src);
    if (dst != 0) {
        for (i = 0; i < n; i++) {
            if (*src != 0) {
                r = mbtowc(dst, src, len);
                dst++;
                if (r > 0) {
                    src += r;
                    len -= r;
                } else {
                    return -1;
                }
            } else {
                *dst = 0;
                break;
            }
        }
    } else {
        i = 0;
    }
    return i;
}

int wcstombs(char *dst, const u16 *src, u32 n) {
    u32 len;
    u32 i = 0;
    char buf[4];
    char *p;

    if (dst == 0 || src == 0) {
        return 0;
    }
    p = buf;
    while (1) {
        if (*src == 0) {
            dst[i] = 0;
            break;
        }
        len = wctomb(p, *src++);
        if (i + len > n) {
            break;
        }
        strncpy(dst + i, p, len);
        i += len;
        if (i > n) {
            break;
        }
    }
    return i;
}

#pragma avoid_byte all

#include "code_02134890.h"
#include "code_02134398.h"
#include "code_0213ee6c.h"
#include "Main/Unknown/unk_0216e000.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/unk_0217e000.h"

double LdexpViaFrexp(double a, int n) {
    int e;

    a = frexp(a, &e);
    e += n;
    return ldexp(a, e);
}

int fflush(FILE *a) {
    if (a == 0) {
        return FflushAll();
    }
    if (a->mFailed != 0 || a->mUnk_04_7 == 0) {
        return -1;
    }
    if (a->mUnk_04_2 == 1) {
        return 0;
    }
    if (a->mUnk_08_0 >= 3) {
        a->mUnk_08_0 = 2;
    }
    if (a->mUnk_08_0 == 2) {
        a->mBufferRemaining = 0;
    }
    if (a->mUnk_08_0 != 1) {
        a->mUnk_08_0 = 0;
        return 0;
    }
    if (FileFlushBuffer(a, 0) != 0) {
        a->mFailed = 1;
        a->mBufferRemaining = 0;
        return -1;
    }
    a->mUnk_08_0 = 0;
    a->mUnk_18 = 0;
    a->mBufferRemaining = 0;
    return 0;
}

u32 fwrite(const char *a, u32 b, u32 c, FILE *d) {
    int i;
    u8 *p;
    u32 r;

    if (d == &data_0216eb7c[1]) {
        i = 3;
    } else if (d == &data_0216eb7c[2]) {
        i = 4;
    } else {
        i = 5;
    }
    p = data_0217eadc[i];
    if (func_0200ec08(p) == 0) {
        data_0217ea94[i] = data_0216ff5c.mUnk_08->mUnk_6c;
        data_0217eab8[i] = 1;
    } else {
        u32 v;

        v = data_0217ea94[i];
        if (v == data_0216ff5c.mUnk_08->mUnk_6c) {
            data_0217eab8[i]++;
        } else {
            func_0200ed34(p);
            data_0217ea94[i] = data_0216ff5c.mUnk_08->mUnk_6c;
            data_0217eab8[i] = 1;
        }
    }
    r = FwriteBody(a, b, c, d);
    if (--data_0217eab8[i] == 0) {
        func_0200ecc4(p);
    }
    return r;
}

#pragma avoid_byte all

#include "code_0213442c.h"
#include "code_02133e50.h"
#include "code_02134d30.h"
#include "code_02135014.h"
#include "code_0213c94c.h"
#include "code_0200e77c.h"

u32 FwriteBody(const char *a, u32 b, u32 c, FILE *d) {
    u32 n;
    u32 t;
    u32 v;
    u32 l;
    int m;
    char *q;
    u8 *s1;
    u32 s2;

    if (fwide(d, 0) == 0) {
        fwide(d, -1);
    }
    n = b * c;
    if (n == 0 || d->mFailed != 0 || d->mUnk_04_7 == 0) {
        return 0;
    }
    if (d->mUnk_04_7 == 2) {
        func_02135010();
    }
    m = 1;
    if (d->mUnk_04_12 != 0) {
        if (d->mUnk_04_5 != 2 && d->mUnk_04_5 != 1) {
            m = 0;
        }
    }
    if (d->mUnk_08_0 == 0 && (d->mUnk_04_2 & 2) != 0) {
        d->mUnk_08_0 = 1;
        FileResetBuffer(d);
    }
    if (d->mUnk_08_0 != 1) {
        d->mFailed = 1;
        d->mBufferRemaining = 0;
        return 0;
    }
    t = 0;
    if (n != 0 && (d->mBufferNext != d->mBuffer || m != 0)) {
        d->mBufferRemaining = d->mBufferSize - (d->mBufferNext - d->mBuffer);
        v = 10;
        do {
            q = 0;
            l = d->mBufferRemaining;
            if (l > n) {
                l = n;
            }
            if (d->mUnk_04_5 == 1 && l != 0) {
                q = MemChrBackward(a, v, l);
                if (q != 0) {
                    l = q + 1 - a;
                }
            }
            if (l != 0) {
                memcpy(d->mBufferNext, a, l);
                a += l;
                n -= l;
                d->mBufferNext += l;
                d->mBufferRemaining -= l;
            }
            if (d->mBufferRemaining == 0 || q != 0 || d->mUnk_04_5 == 0) {
                if (FileFlushBuffer(d, 0) != 0) {
                    d->mFailed = 1;
                    n = 0;
                    d->mBufferRemaining = n;
                    break;
                }
            }
            t += l;
        } while (n != 0 && m != 0);
    }
    if (n != 0 && m == 0) {
        s1 = d->mBuffer;
        s2 = d->mBufferSize;
        d->mBuffer = (u8 *) a;
        d->mBufferSize = n;
        d->mBufferNext = (u8 *) a + n;
        if (FileFlushBuffer(d, &l) == 0) {
            t += l;
        } else {
            d->mFailed = 1;
            d->mBufferRemaining = 0;
        }
        d->mBuffer = s1;
        d->mBufferSize = s2;
        FileResetBuffer(d);
        d->mBufferRemaining = 0;
    }
    if (d->mUnk_04_5 != 2) {
        d->mBufferRemaining = 0;
    }
    return t / b;
}

void func_0213453c(u8 *a, u32 *b) {}

void FileResetBuffer(FILE *a) {
    a->mBufferNext = a->mBuffer;
    a->mBufferRemaining = a->mBufferSize;
    a->mBufferRemaining = a->mBufferRemaining - (a->mUnk_18 & a->mUnk_2c);
    a->mUnk_34 = a->mUnk_18;
}

int FileFlushBuffer(FILE *a, u32 *b) {
    int n;
    int r;

    n = a->mBufferNext - a->mBuffer;
    if (n != 0) {
        a->mBufferRemaining = n;
        if (a->mUnk_04_12 == 0) {
            func_0213453c(a->mBuffer, &a->mBufferRemaining);
        }
        r = a->mWriteFunc(a->mUnk_00, a->mBuffer, &a->mBufferRemaining, a->mUnk_48);
        if (b != 0) {
            *b = a->mBufferRemaining;
        }
        if (r != 0) {
            return r;
        }
        a->mUnk_18 = a->mUnk_18 + a->mBufferRemaining;
    }
    FileResetBuffer(a);
    return 0;
}

void AssertionFailed(const char *a, const char *b, const char *c, int d) {
    printf("Assertion (%s) failed in \"%s\", function \"%s\", line %d\n", a, b, c, d);
    abort();
}
