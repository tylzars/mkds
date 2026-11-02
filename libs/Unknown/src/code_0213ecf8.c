#pragma avoid_byte all

#include "code_0213ecf8.h"

// Number of u16 elements before the 0 terminator.
int wcslen(const u16 *s) {
    int n = -1;
    u16 c;

    do {
        c = *s++;
        n++;
    } while (c != 0);
    return n;
}

// Copies src up to and including its 0 terminator; returns dst.
u16 *wcscpy(u16 *dst, const u16 *src) {
    u16 *p = dst;

    while ((*p++ = *src++) != 0) {
    }
    return dst;
}

// Copies at most n elements of src to dst, then fills the rest of the n elements with 0; returns dst.
u16 *wcsncpy(u16 *dst, const u16 *src, u32 n) {
    u16 *p = dst;

    if (n != 0) {
        do {
            if ((*p++ = *src++) == 0) {
                if (--n != 0) {
                    do {
                        *p++ = 0;
                    } while (--n != 0);
                }
                return dst;
            }
        } while (--n != 0);
    }
    return dst;
}

// Appends at most n elements of src after the 0 terminator of dst, then writes a 0 terminator; returns dst.
u16 *wcsncat(u16 *dst, const u16 *src, u32 n) {
    u16 *p = dst;

    while (*p++ != 0) {
    }
    p--;
    if (n != 0) {
        do {
            if ((*p++ = *src++) == 0) {
                p--;
                break;
            }
        } while (--n != 0);
    }
    *p = 0;
    return dst;
}

// Compares at most n elements of a and b, stopping after a 0; returns the first difference a - b, or 0.
int wcsncmp(const u16 *a, const u16 *b, u32 n) {
    u16 x;
    u16 y;

    if (n != 0) {
        do {
            x = *b++;
            y = *a++;
            if (y != x) {
                return y - x;
            }
            if (y == 0) {
                break;
            }
        } while (--n != 0);
    }
    return 0;
}

// Pointer to the first element equal to c, or to the 0 terminator when c is 0; 0 when there is none.
u16 *wcschr(const u16 *s, int c) {
    u16 ch;

    while ((ch = *s++) != 0) {
        if (ch == c) {
            return (u16 *) (s - 1);
        }
    }
    return c != 0 ? 0 : (u16 *) (s - 1);
}
