#include "00/code_021ab6d4.h"

#include "00/code_021abc04.h"
#include "00/unk_021b4000.h"
#include "code_0214d018.h"

u8 data_ov000_021b4aa4[64] = {
    0x80,
};

u8 data_ov000_021b4a64[64] = {
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,
    0x01, 0x06, 0x0b, 0x00, 0x05, 0x0a, 0x0f, 0x04, 0x09, 0x0e, 0x03, 0x08, 0x0d, 0x02, 0x07, 0x0c,
    0x05, 0x08, 0x0b, 0x0e, 0x01, 0x04, 0x07, 0x0a, 0x0d, 0x00, 0x03, 0x06, 0x09, 0x0c, 0x0f, 0x02,
    0x00, 0x07, 0x0e, 0x05, 0x0c, 0x03, 0x0a, 0x01, 0x08, 0x0f, 0x06, 0x0d, 0x04, 0x0b, 0x02, 0x09,
};

u32 data_ov000_021b4ae4[64] = {
    0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee, 0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
    0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be, 0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
    0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa, 0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
    0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed, 0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
    0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c, 0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
    0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05, 0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
    0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039, 0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
    0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1, 0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391,
};

void func_ov000_021ab7e8(Unk021ab728 *a, const u8 *b) {
    u32 w[16];
    u32 p;
    u32 q;
    u32 r;
    u32 s;
    u32 i;
    s32 j;
    p = a->mUnk_00;
    q = a->mUnk_04;
    r = a->mUnk_08;
    s = a->mUnk_0c;
    func_ov000_021abc04(w, b, 0x40);
    i = 0;
    for (j = 0; j < 4; j++) {
        p += (s ^ (q & (r ^ s))) + w[data_ov000_021b4a64[i]] + data_ov000_021b4ae4[i];
        p = q + ((p << 7) | (p >> 25));
        s += (r ^ (p & (q ^ r))) + w[data_ov000_021b4a64[i + 1]] + data_ov000_021b4ae4[i + 1];
        s = p + ((s << 12) | (s >> 20));
        r += (q ^ (s & (p ^ q))) + w[data_ov000_021b4a64[i + 2]] + data_ov000_021b4ae4[i + 2];
        r = s + ((r << 17) | (r >> 15));
        q += (p ^ (r & (s ^ p))) + w[data_ov000_021b4a64[i + 3]] + data_ov000_021b4ae4[i + 3];
        q = r + ((q << 22) | (q >> 10));
        i += 4;
    }
    for (j = 0; j < 4; j++) {
        p += ((q & s) | (r & ~s)) + w[data_ov000_021b4a64[i]] + data_ov000_021b4ae4[i];
        p = q + ((p << 5) | (p >> 27));
        s += ((p & r) | (q & ~r)) + w[data_ov000_021b4a64[i + 1]] + data_ov000_021b4ae4[i + 1];
        s = p + ((s << 9) | (s >> 23));
        r += ((s & q) | (p & ~q)) + w[data_ov000_021b4a64[i + 2]] + data_ov000_021b4ae4[i + 2];
        r = s + ((r << 14) | (r >> 18));
        q += ((r & p) | (s & ~p)) + w[data_ov000_021b4a64[i + 3]] + data_ov000_021b4ae4[i + 3];
        q = r + ((q << 20) | (q >> 12));
        i += 4;
    }
    for (j = 0; j < 4; j++) {
        p += (s ^ (q ^ r)) + w[data_ov000_021b4a64[i]] + data_ov000_021b4ae4[i];
        p = q + ((p << 4) | (p >> 28));
        s += (r ^ (p ^ q)) + w[data_ov000_021b4a64[i + 1]] + data_ov000_021b4ae4[i + 1];
        s = p + ((s << 11) | (s >> 21));
        r += (q ^ (s ^ p)) + w[data_ov000_021b4a64[i + 2]] + data_ov000_021b4ae4[i + 2];
        r = s + ((r << 16) | (r >> 16));
        q += (p ^ (r ^ s)) + w[data_ov000_021b4a64[i + 3]] + data_ov000_021b4ae4[i + 3];
        q = r + ((q << 23) | (q >> 9));
        i += 4;
    }
    for (j = 0; j < 4; j++) {
        p += (r ^ (q | ~s)) + w[data_ov000_021b4a64[i]] + data_ov000_021b4ae4[i];
        p = q + ((p << 6) | (p >> 26));
        s += (q ^ (p | ~r)) + w[data_ov000_021b4a64[i + 1]] + data_ov000_021b4ae4[i + 1];
        s = p + ((s << 10) | (s >> 22));
        r += (p ^ (s | ~q)) + w[data_ov000_021b4a64[i + 2]] + data_ov000_021b4ae4[i + 2];
        r = s + ((r << 15) | (r >> 17));
        q += (s ^ (r | ~p)) + w[data_ov000_021b4a64[i + 3]] + data_ov000_021b4ae4[i + 3];
        q = r + ((q << 21) | (q >> 11));
        i += 4;
    }
    a->mUnk_00 += p;
    a->mUnk_04 += q;
    a->mUnk_08 += r;
    a->mUnk_0c += s;
}

void func_ov000_021ab7b4(Unk021ab728 *a) {
    MI_CpuFill8(a, 0, 0x58);
    a->mUnk_00 = (0x67452301u);
    a->mUnk_04 = (0xefcdab89u);
    a->mUnk_08 = (0x98badcfeu);
    a->mUnk_0c = (0x10325476u);
}

void func_ov000_021ab728(void *f, const u8 *b, u32 c) {
    Unk021ab728 *a = f;
    u32 d;
    u32 e;
    d = (a->mUnk_10 >> 3) & 0x3f;
    a->mUnk_10 += c << 3;
    if (a->mUnk_10 < (c << 3)) {
        a->mUnk_14++;
    }
    a->mUnk_14 += c >> 29;
    e = 64 - d;
    if (c >= e) {
        MI_CpuCopy8(b, &a->mUnk_18[d], e);
        d = 0;
        func_ov000_021ab7e8(a, a->mUnk_18);
        for (; e + 63 < c; e += 64) {
            func_ov000_021ab7e8(a, b + e);
        }
    } else {
        e = 0;
    }
    MI_CpuCopy8(b + e, &a->mUnk_18[d], c - e);
}

void func_ov000_021ab6d4(Unk021ab728 *a, u8 *b) {
    int v1;
    int v2;
    func_ov000_021abc14((u32) b, (u32) &a->mUnk_10, 8);
    v1 = a->mUnk_10 >> 3 & 0x3f;
    if (v1 < 0x38) {
        v2 = 0x38 - v1;
    } else {
        v2 = 0x78 - v1;
    }
    func_ov000_021ab728(a, data_ov000_021b4aa4, v2);
    func_ov000_021ab728(a, b, 8);
    func_ov000_021abc14((u32) b, (u32) a, 0x10);
}
