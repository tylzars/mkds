#pragma avoid_byte all

#include "code_02139f70.h"
#include "code_0213a460.h"

double func_0213a450(const u8 *s) {
    return func_0213a460(s, 0);
}

u32 strlen(const u8 *s) {
    u32 n = -1;
    u32 c;

    do {
        c = *s++;
        n++;
    } while (c != 0);
    return n;
}

char *strcpy(char *dst, const u8 *src) {
    u8 *p;
    u32 a;
    u32 b;
    u32 w;
    u32 k;
    u32 m;
    u32 t;
    u32 n;

    p = (u8 *) dst;
    a = (u32) src & 3;
    b = (u32) dst & 3;
    if (b == a) {
        if (a != 0) {
            *dst = *src;
            if (*(u8 *) dst == 0) {
                return dst;
            }
            n = 3 - a;
            if (n != 0) {
                do {
                    *++p = *++src;
                    if (*p == 0) {
                        return dst;
                    }
                } while (--n != 0);
            }
            p++;
            src++;
        }
        w = *(u32 *) src;
        k = 0xfefefeff;
        m = 0x80808080;
        t = w + k;
        if ((t & m) == 0) {
            p -= 4;
            do {
                p += 4;
                *(u32 *) p = w;
                src += 4;
                w = *(u32 *) src;
                t = w + k;
            } while ((t & m) == 0);
            p += 4;
        }
    }
    *p = *src;
    if (*p == 0) {
        return dst;
    }
    do {
        *++p = *++src;
    } while (*p != 0);
    return dst;
}

u8 *strncpy(u8 *dst, const u8 *src, u32 n) {
    u8 *p;

    p = dst;
    for (; n != 0; n--) {
        if ((*p++ = *src++) == 0) {
            while (--n != 0) {
                *p++ = 0;
            }
            break;
        }
    }
    return dst;
}

char *strcat(char *dst, const u8 *src) {
    u8 *p;
    u8 *q;

    p = (u8 *) dst;
    while (*p++ != 0) {
    }
    p--;
    do {
        q = p;
        *p++ = *src++;
    } while (*q != 0);
    return dst;
}

int strcmp(const u8 *a, const u8 *b) {
    u32 c;
    u32 d;
    u32 x;
    u32 y;
    u32 f;
    u32 k;
    u32 m;
    u32 ra;
    u32 rb;

    c = *a;
    d = c - *b;
    if (d != 0) {
        return d;
    }
    ra = (u32) a & 3;
    rb = (u32) b & 3;
    if (rb == ra) {
        if (ra != 0) {
            if (c == 0) {
                return 0;
            }
            ra = 3 - ra;
            if (ra != 0) {
                do {
                    x = *++a;
                    y = x - *++b;
                    if (y != 0) {
                        return y;
                    }
                    if (x == 0) {
                        return 0;
                    }
                } while (--ra != 0);
            }
            a++;
            b++;
        }
        c = *(u32 *) a;
        k = 0xfefefeff;
        m = 0x80808080;
        f = *(u32 *) b;
        if (((c + k) & m) == 0) {
            if (c == f) {
                do {
                    c = *(u32 *) (a += 4);
                    f = *(u32 *) (b += 4);
                    if (((c + k) & m) != 0) {
                        goto tail;
                    }
                } while (c == f);
            }
            a--;
            b--;
            goto slow;
        }
    tail:
        c = *a;
        d = c - *b;
        if (d != 0) {
            return d;
        }
    }
slow:
    if (c == 0) {
        return 0;
    }
    do {
        x = *++a;
        y = x - *++b;
        if (y != 0) {
            return y;
        }
    } while (x != 0);
    return 0;
}

int strncmp(const u8 *a, const u8 *b, u32 n) {
    u32 c;
    u32 d;

    if (n != 0) {
        do {
            d = *b++;
            c = *a++;
            if (c != d) {
                return c - d;
            }
            if (c == 0) {
                break;
            }
        } while (--n != 0);
    }
    return 0;
}

const u8 *strchr(const u8 *s, int c) {
    u32 d;
    const u8 *p;

    c = (u8) c;
    p = s + 1;
    d = *s;
    if (d != 0) {
        do {
            if (d == c) {
                return p - 1;
            }
            d = *p++;
        } while (d != 0);
    }
    if (c != 0) {
        return 0;
    }
    return p - 1;
}

u8 *strstr(const u8 *a, const u8 *b) {
    u32 d;
    const u8 *p;
    u32 c;
    u32 e;
    const u8 *q;
    const u8 *r;
    u32 f;

    if (b == 0) {
        return (u8 *) a;
    }
    c = *b;
    if (c == 0) {
        return (u8 *) a;
    }
    p = a + 1;
    d = *a;
    for (; d != 0; d = *p++) {
        if (d == c) {
            q = p;
            r = b + 1;
            do {
                e = *r++;
                f = *q++;
            } while (f == e && f != 0);
            if (e == 0) {
                return (u8 *) (p - 1);
            }
        }
    }
    return 0;
}
