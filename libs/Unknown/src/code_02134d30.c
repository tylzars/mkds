#pragma avoid_byte all

#include "code_02134d30.h"

void func_02135010(void) {}

void func_02134f18(u8 *p, int c, u32 n) {
    u32 *w;
    u32 m;
    u32 k;

    c = (u8) c;
    if (n >= 0x20) {
        m = -(u32) p & 3;
        if (m != 0) {
            n -= m;
            do {
                *p++ = (u8) c;
                m--;
            } while (m != 0);
        }
        w = (u32 *) p;
        if (c != 0) {
            c = (c << 24) | (c << 16) | (c << 8) | c;
        }
        for (k = n >> 5; k != 0; k--) {
            *w++ = c;
            *w++ = c;
            *w++ = c;
            *w++ = c;
            *w++ = c;
            *w++ = c;
            *w++ = c;
            *w++ = c;
        }
        for (k = (n & 0x1f) >> 2; k != 0; k--) {
            *w++ = c;
        }
        n &= 3;
        p = (u8 *) w;
    }
    for (; n != 0; n--) {
        *p++ = (u8) c;
    }
}

void *func_02134eb8(void *dst, const void *src, u32 n) {
    u8 *p = dst;
    const u8 *s = src;

    for (; n != 0; n--) {
        *p++ = *s++;
    }
    return dst;
}

void *func_02134df8(void *a, const void *b, u32 n) {
    if (b >= a) {
        u8 *d;
        const u8 *s;

        for (d = a, s = b; n != 0; n--) {
            *d++ = *s++;
        }
    } else {
        const u8 *s;
        u8 *d;

        for (s = (const u8 *) b + n, d = (u8 *) a + n; n != 0; n--) {
            *--d = *--s;
        }
    }
    return a;
}

void *func_02134de0(void *p, int c, u32 n) {
    func_02134f18(p, c, n);
    return p;
}

void *func_02134db0(const u8 *p, int c, u32 n) {
    u8 ch = c;

    for (; n != 0; n--) {
        if (*p++ == ch) {
            return (void *) (p - 1);
        }
    }
    return 0;
}

void *func_02134d80(const void *a, int v, u32 n) {
    u8 c = v;
    const u8 *p = (const u8 *) a + n;

    for (; n != 0; n--) {
        if (*--p == c) {
            return (void *) p;
        }
    }
    return 0;
}

int func_02134d30(const u8 *a, const u8 *b, u32 n) {
    for (; n != 0; n--) {
        if (*a++ != *b++) {
            return a[-1] < b[-1] ? -1 : 1;
        }
    }
    return 0;
}
