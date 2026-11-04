#pragma avoid_byte all
#pragma dont_reuse_strings off

#include "code_0214177c.h"

// Compares the byte strings a and b, mapping each byte below 0x80 through data_0215d184 first: -1 or 1 at the first
// difference, 0 when both end together.
int StrcmpMapped(const char *a, const char *b) {
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

int func_02142368(const char *a, const char *b) {
    return StrcmpMapped(a, b);
}

// Number of 0 bits below the lowest 1 bit of a, its bytes read from the lowest address up; 32 when a is 0.
int CountLowZeroBits(u32 a) {
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
int DigitsRoundCompare(const DigitRecord *a, int n) {
    const char *p;
    const char *end;
    u8 c;

    p = a->mDigits + n;
    c = a->mDigits[n];
    if (c > 5) {
        return 1;
    }
    if (c < 5) {
        return -1;
    }
    end = a->mDigits + a->mDigitCount;
    for (p++; p < end; p++) {
        if (*p != 0) {
            return 1;
        }
    }
    if (a->mDigits[n - 1] & 1) {
        return 1;
    }
    return -1;
}

// Adds 1 to the digit at index n - 1, carrying into the digits before it; a carry out of the first digit sets it to 1
// and adds 1 to mUnk_02.
void DigitsIncrement(DigitRecord *a, int n) {
    char *base;
    char *p;

    base = a->mDigits;
    p = base + n - 1;
    for (;;) {
        if (*p < 9) {
            (*p)++;
            return;
        }
        if (p == base) {
            *p = 1;
            a->mExponent++;
            return;
        }
        *p-- = 0;
    }
}

// For 0 < n < mUnk_04: keeps the first n digits and adds 1 to the last one (DigitsIncrement) when DigitsRoundCompare is
// not negative.
void DigitsRoundTo(DigitRecord *a, int n) {
    int r;

    if (n <= 0) {
        return;
    }
    if (n >= a->mDigitCount) {
        return;
    }
    r = DigitsRoundCompare(a, n);
    a->mDigitCount = n;
    if (r < 0) {
        return;
    }
    DigitsIncrement(a, n);
}

// Writes the decimal digits of v, most significant first, with mUnk_02 = digit count - 1.
void DigitsFromU64(DigitRecord *out, u64 v) {
    char *p;
    char *q;
    u8 t;

    out->mNegative = 0;
    out->mDigitCount = 0;
    while (v != 0) {
        out->mDigits[out->mDigitCount++] = v % 10;
        v /= 10;
    }
    for (p = out->mDigits, q = p + out->mDigitCount - 1; p < q; p++, q--) {
        t = *p;
        *p = *q;
        *q = t;
    }
    out->mExponent = out->mDigitCount - 1;
}

// Multiplies the digits of a and b (mUnk_02 = the sum of theirs), keeps the first 32 and adds 1 to the last kept one
// (DigitsIncrement) when the digits after them are above 5 followed by 0s, or equal to it and the last kept digit is
// odd.
void DigitsMultiply(DigitRecord *out, const DigitRecord *a, const DigitRecord *b) {
    char buf[64];
    int k;
    u32 carry;
    int i;
    char *p;
    char *end;
    int j;
    int n;
    const char *pa;
    const char *pb;

    carry = 0;
    i = a->mDigitCount + b->mDigitCount - 1;
    p = buf + i + 1;
    end = p;
    out->mNegative = 0;
    while (i > 0) {
        j = b->mDigitCount - 1;
        k = i - j - 1;
        if (k < 0) {
            k = 0;
            j = i - 1;
        }
        pa = a->mDigits + k;
        pb = b->mDigits + j;
        n = j + 1;
        if (n > a->mDigitCount - k) {
            n = a->mDigitCount - k;
        }
        for (; n > 0; n--, pa++, pb--) {
            carry += *pa * *pb;
        }
        *--p = carry % 10;
        carry /= 10;
        i--;
    }
    out->mExponent = a->mExponent + b->mExponent;
    if (carry != 0) {
        *--p = carry;
        out->mExponent++;
    }
    for (i = 0; i < 32 && p < end; i++, p++) {
        out->mDigits[i] = *p;
    }
    out->mDigitCount = i;
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
    DigitsIncrement(out, out->mDigitCount);
}

// Reads up to 32 digit characters of s into out with mUnk_02 = n. Then adds 1 to the last digit (DigitsIncrement) when
// the next byte is above 5, or is 5 with only '0' bytes after it and the last digit odd.
void DigitsFromString(DigitRecord *out, const char *s, int n) {
    int i;
    const char *p;

    out->mExponent = n;
    out->mNegative = 0;
    for (i = 0; i < 32 && *s != 0; i++) {
        out->mDigits[i] = *s++ - '0';
    }
    out->mDigitCount = i;
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
        if (!(out->mDigits[i - 1] & 1)) {
            return;
        }
    }
round:
    DigitsIncrement(out, out->mDigitCount);
}

// For n of -64, -53, -32, -16 and -8 to 8, passes a digit string and a count to DigitsFromString. Otherwise calls
// itself for n / 2 (the sign bit added by hand) and combines the result with itself through DigitsMultiply, then with a
// one-digit string when n is odd.
void DigitsPowerOfTwo(DigitRecord *out, int n) {
    DigitRecord a;
    DigitRecord b;

    switch (n) {
        case -64:
            DigitsFromString(out, "542101086242752217003726400434970855712890625", -20);
            return;
        case -53:
            DigitsFromString(out, "11102230246251565404236316680908203125", -16);
            return;
        case -32:
            DigitsFromString(out, "23283064365386962890625", -10);
            return;
        case -16:
            DigitsFromString(out, "152587890625", -5);
            return;
        case -8:
            DigitsFromString(out, "390625", -3);
            return;
        case -7:
            DigitsFromString(out, "78125", -3);
            return;
        case -6:
            DigitsFromString(out, "15625", -2);
            return;
        case -5:
            DigitsFromString(out, "3125", -2);
            return;
        case -4:
            DigitsFromString(out, "625", -2);
            return;
        case -3:
            DigitsFromString(out, "125", -1);
            return;
        case -2:
            DigitsFromString(out, "25", -1);
            return;
        case -1:
            DigitsFromString(out, "5", -1);
            return;
        case 0:
            DigitsFromString(out, "1", 0);
            return;
        case 1:
            DigitsFromString(out, "2", 0);
            return;
        case 2:
            DigitsFromString(out, "4", 0);
            return;
        case 3:
            DigitsFromString(out, "8", 0);
            return;
        case 4:
            DigitsFromString(out, "16", 1);
            return;
        case 5:
            DigitsFromString(out, "32", 1);
            return;
        case 6:
            DigitsFromString(out, "64", 1);
            return;
        case 7:
            DigitsFromString(out, "128", 2);
            return;
        case 8:
            DigitsFromString(out, "256", 2);
            return;
    }
    DigitsPowerOfTwo(&a, (n + (int) ((u32) (n & 0x80000000) >> 31)) >> 1);
    DigitsMultiply(out, &a, &a);
    if (n & 1) {
        b = *out;
        if (n > 0) {
            DigitsFromString(&a, "2", 0);
        } else {
            DigitsFromString(&a, "5", -1);
        }
        DigitsMultiply(out, &b, &a);
    }
}
