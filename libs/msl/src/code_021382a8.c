#pragma avoid_byte all

#include "code_021382a8.h"

// Swaps size bytes between a and b.
static inline void func_021382a8_inline(u8 *a, u8 *b, u32 size) {
    u8 *p;
    u8 *q;
    u8 t;
    u32 i;

    i = size;
    p = a;
    q = b;
    for (; i != 0; i--) {
        t = *q;
        *q++ = *p;
        *p++ = t;
    }
}

void qsort(u8 *base, u32 n, u32 size, int (*cmp)(void *, void *)) {
    u32 l;
    u8 *lo;
    u8 *hi;
    u32 j;
    u8 *c;
    u8 *b;
    u8 *a;

    if (n < 2) {
        return;
    }
    l = (n >> 1) + 1;
    lo = base + size * (l - 1);
    hi = base + size * (n - 1);
    for (;;) {
        if (l > 1) {
            l--;
            lo -= size;
        } else {
            func_021382a8_inline(hi, lo, size);
            n--;
            if (n == 1) {
                return;
            }
            hi -= size;
        }
        j = l;
        b = base + size * (j - 1);
        while (j * 2 <= n) {
            j = j * 2;
            c = b;
            b = base + size * (j - 1);
            if (j < n) {
                a = b + size;
                if (cmp(b, a) < 0) {
                    b = a;
                    j++;
                }
            }
            if (cmp(c, b) >= 0) {
                break;
            }
            func_021382a8_inline(b, c, size);
        }
    }
}
