#pragma avoid_byte all

#include "code_0213c94c.h"

u16 *wmemchr(const u16 *s, int c, u32 n) {
    while (n != 0) {
        if (*s == c) {
            return (u16 *) s;
        }
        s++;
        n--;
    }
    return 0;
}

int fwide(Unk0213c94c *a, int b) {
    if (a == 0 || a->mUnk_04_7 == 0) {
        return 0;
    }
    switch (a->mUnk_04_10) {
        case 0:
            if (b > 0) {
                a->mUnk_04_10 = 2;
            } else if (b < 0) {
                a->mUnk_04_10 = 1;
            }
            break;
        case 1:
            b = -1;
            break;
        case 2:
            b = 1;
            break;
    }
    return b;
}
