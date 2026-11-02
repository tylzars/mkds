#pragma avoid_byte all
#pragma dont_reuse_strings off

#include "code_0214177c.h"

// Compares the byte strings a and b, mapping each byte below 0x80 through data_0215d184 first: -1 or 1 at the first
// difference, 0 when both end together.
int func_02142374(const u8 *a, const u8 *b) {
    int x;
    u8 c1;
    u8 c2;

    for (;;) {
        x = *a++;
        c1 = (x < 0 || x >= 0x80) ? x : data_0215d184[x];
        x = *b++;
        c2 = (x < 0 || x >= 0x80) ? x : data_0215d184[x];
        if (c1 < c2) {
            return -1;
        }
        if (c1 > c2) {
            return 1;
        }
        if (c1 == 0) {
            return 0;
        }
    }
}

int func_02142368(const u8 *a, const u8 *b) {
    return func_02142374(a, b);
}

// Number of 0 bits below the lowest 1 bit of a, its bytes read from the lowest address up; 32 when a is 0.
int func_021422a0(u32 a) {
    u8 *p;
    int n;

    if (a != 0) {
        p = (u8 *) &a;
        n = 0;
        while (*p == 0) {
            p++;
            n += 8;
        }
        *p = ~*p;
        while (*p & 1) {
            *p >>= 1;
            n++;
        }
        return n;
    }
    return 32;
}

// Compares the digits from index n on with 5 followed by 0s: 1 when above, -1 when below; when equal, 1 if the digit
// before index n is odd, else -1.
int func_02142224(const Unk02136638 *a, int n) {
    const u8 *p;
    const u8 *end;
    u8 c;

    p = a->mUnk_05 + n;
    c = a->mUnk_05[n];
    if (c > 5) {
        return 1;
    }
    if (c < 5) {
        return -1;
    }
    end = a->mUnk_05 + a->mUnk_04;
    for (p++; p < end; p++) {
        if (*p != 0) {
            return 1;
        }
    }
    if (a->mUnk_05[n - 1] & 1) {
        return 1;
    }
    return -1;
}

// Adds 1 to the digit at index n - 1, carrying into the digits before it; a carry out of the first digit sets it to 1
// and adds 1 to mUnk_02.
void func_0214214c(Unk02136638 *a, int n) {
    u8 *base;
    u8 *p;

    base = a->mUnk_05;
    p = base + n - 1;
    for (;;) {
        if (*p < 9) {
            (*p)++;
            return;
        }
        if (p == base) {
            *p = 1;
            a->mUnk_02++;
            return;
        }
        *p-- = 0;
    }
}

// For 0 < n < mUnk_04: keeps the first n digits and adds 1 to the last one (func_0214214c) when func_02142224 is not
// negative.
void func_021420c0(Unk02136638 *a, int n) {
    int r;

    if (n <= 0) {
        return;
    }
    if (n >= a->mUnk_04) {
        return;
    }
    r = func_02142224(a, n);
    a->mUnk_04 = n;
    if (r < 0) {
        return;
    }
    func_0214214c(a, n);
}

// Writes the decimal digits of v, most significant first, with mUnk_02 = digit count - 1.
void func_02141f14(Unk02136638 *out, u64 v) {
    u8 *p;
    u8 *q;
    u8 t;

    out->mUnk_00 = 0;
    out->mUnk_04 = 0;
    while (v != 0) {
        out->mUnk_05[out->mUnk_04++] = v % 10;
        v /= 10;
    }
    for (p = out->mUnk_05, q = p + out->mUnk_04 - 1; p < q; p++, q--) {
        t = *p;
        *p = *q;
        *q = t;
    }
    out->mUnk_02 = out->mUnk_04 - 1;
}

// Multiplies the digits of a and b (mUnk_02 = the sum of theirs), keeps the first 32 and adds 1 to the last kept one
// (func_0214214c) when the digits after them are above 5 followed by 0s, or equal to it and the last kept digit is odd.
void func_02141c98(Unk02136638 *out, const Unk02136638 *a, const Unk02136638 *b) {
    u8 buf[64];
    int k;
    u32 carry;
    int i;
    u8 *p;
    u8 *end;
    int j;
    int n;
    const u8 *pa;
    const u8 *pb;

    carry = 0;
    i = a->mUnk_04 + b->mUnk_04 - 1;
    p = buf + i + 1;
    end = p;
    out->mUnk_00 = 0;
    while (i > 0) {
        j = b->mUnk_04 - 1;
        k = i - j - 1;
        if (k < 0) {
            k = 0;
            j = i - 1;
        }
        pa = a->mUnk_05 + k;
        pb = b->mUnk_05 + j;
        n = j + 1;
        if (n > a->mUnk_04 - k) {
            n = a->mUnk_04 - k;
        }
        for (; n > 0; n--, pa++, pb--) {
            carry += *pa * *pb;
        }
        *--p = carry % 10;
        carry /= 10;
        i--;
    }
    out->mUnk_02 = a->mUnk_02 + b->mUnk_02;
    if (carry != 0) {
        *--p = carry;
        out->mUnk_02++;
    }
    for (i = 0; i < 32 && p < end; i++, p++) {
        out->mUnk_05[i] = *p;
    }
    out->mUnk_04 = i;
    if (p >= end) {
        return;
    }
    if (*p < 5) {
        return;
    }
    if (*p == 5) {
        for (pa = p + 1; pa < end; pa++) {
            if (*pa != 0) {
                goto round;
            }
        }
        if (!(p[-1] & 1)) {
            return;
        }
    }
round:
    func_0214214c(out, out->mUnk_04);
}

// Reads up to 32 digit characters of s into out with mUnk_02 = n. Then adds 1 to the last digit (func_0214214c) when
// the next byte is above 5, or is 5 with only '0' bytes after it and the last digit odd.
void func_02141b5c(Unk02136638 *out, const u8 *s, int n) {
    int i;
    const u8 *p;

    out->mUnk_02 = n;
    out->mUnk_00 = 0;
    for (i = 0; i < 32 && *s != 0; i++) {
        out->mUnk_05[i] = *s++ - '0';
    }
    out->mUnk_04 = i;
    if (*s == 0) {
        return;
    }
    if (*s < 5) {
        return;
    }
    if (*s <= 5) {
        for (p = s + 1; *p != 0; p++) {
            if (*p != '0') {
                goto round;
            }
        }
        if (!(out->mUnk_05[i - 1] & 1)) {
            return;
        }
    }
round:
    func_0214214c(out, out->mUnk_04);
}

// For n of -64, -53, -32, -16 and -8 to 8, passes a digit string and a count to func_02141b5c. Otherwise calls itself
// for n / 2 (the sign bit added by hand) and combines the result with itself through func_02141c98, then with a
// one-digit string when n is odd.
void func_0214177c(Unk02136638 *out, int n) {
    Unk02136638 a;
    Unk02136638 b;

    switch (n) {
        case -64:
            func_02141b5c(out, (const u8 *) "542101086242752217003726400434970855712890625", -20);
            return;
        case -53:
            func_02141b5c(out, (const u8 *) "11102230246251565404236316680908203125", -16);
            return;
        case -32:
            func_02141b5c(out, (const u8 *) "23283064365386962890625", -10);
            return;
        case -16:
            func_02141b5c(out, (const u8 *) "152587890625", -5);
            return;
        case -8:
            func_02141b5c(out, (const u8 *) "390625", -3);
            return;
        case -7:
            func_02141b5c(out, (const u8 *) "78125", -3);
            return;
        case -6:
            func_02141b5c(out, (const u8 *) "15625", -2);
            return;
        case -5:
            func_02141b5c(out, (const u8 *) "3125", -2);
            return;
        case -4:
            func_02141b5c(out, (const u8 *) "625", -2);
            return;
        case -3:
            func_02141b5c(out, (const u8 *) "125", -1);
            return;
        case -2:
            func_02141b5c(out, (const u8 *) "25", -1);
            return;
        case -1:
            func_02141b5c(out, (const u8 *) "5", -1);
            return;
        case 0:
            func_02141b5c(out, (const u8 *) "1", 0);
            return;
        case 1:
            func_02141b5c(out, (const u8 *) "2", 0);
            return;
        case 2:
            func_02141b5c(out, (const u8 *) "4", 0);
            return;
        case 3:
            func_02141b5c(out, (const u8 *) "8", 0);
            return;
        case 4:
            func_02141b5c(out, (const u8 *) "16", 1);
            return;
        case 5:
            func_02141b5c(out, (const u8 *) "32", 1);
            return;
        case 6:
            func_02141b5c(out, (const u8 *) "64", 1);
            return;
        case 7:
            func_02141b5c(out, (const u8 *) "128", 2);
            return;
        case 8:
            func_02141b5c(out, (const u8 *) "256", 2);
            return;
    }
    func_0214177c(&a, (n + (int) ((u32) (n & 0x80000000) >> 31)) >> 1);
    func_02141c98(out, &a, &a);
    if (n & 1) {
        b = *out;
        if (n > 0) {
            func_02141b5c(&a, (const u8 *) "2", 0);
        } else {
            func_02141b5c(&a, (const u8 *) "5", -1);
        }
        func_02141c98(out, &b, &a);
    }
}
