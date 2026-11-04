#include "code_0214d018.h"
#include "code_02150228.h"
#include "Main/Unknown/code_0214d000.h"

u8 data_0216f0a8 = 0x80;
u32 data_0216f0ac[48] = {
    1,  6, 11, 0, 5, 10, 15, 4, 9, 14, 3,  8, 13, 2, 7,  12, 5, 8,  11, 14, 1, 4,  7, 10,
    13, 0, 3,  6, 9, 12, 15, 2, 0, 7,  14, 5, 12, 3, 10, 1,  8, 15, 6,  13, 4, 11, 2, 9,
};
u32 data_0216f16c[64] = {
    0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee, 0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
    0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be, 0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
    0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa, 0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
    0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed, 0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
    0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c, 0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
    0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05, 0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
    0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039, 0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
    0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1, 0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391,
};

void Hash16Update(Hash16State *ctx, const u8 *src, u32 n) {
    u32 off;
    u32 room;
    int blocks;
    const u8 *p;

    off = (u32) ctx->mByteCount & 0x3f;
    ctx->mByteCount += n;
    room = 0x40 - off;
    if (room > n) {
        if (n == 0) {
            return;
        }
        MemCopy(src, ctx->mBlock + off, n);
        return;
    }
    MemCopy(src, ctx->mBlock + off, room);
    Hash16Block(ctx);
    n -= room;
    blocks = n >> 6;
    p = src + room;
    for (; blocks > 0; blocks--) {
        MemCopy(p, ctx->mBlock, 0x40);
        p += 0x40;
        Hash16Block(ctx);
    }
    if ((n & 0x3f) == 0) {
        return;
    }
    MemCopy(p, ctx->mBlock, n & 0x3f);
}

void Hash16Final(u8 *out, Hash16State *ctx) {
    u32 lo;
    u32 hi;
    u32 n;
    u32 m;
    u64 bits;

    bits = ctx->mByteCount << 3;
    lo = (u32) bits;
    hi = (u32) (bits >> 32);
    Hash16Update(ctx, &data_0216f0a8, 1);
    n = (u32) (ctx->mByteCount & 0x3f);
    m = 0x40 - n;
    if (m < 8) {
        MemFill(ctx->mBlock + n, 0, m);
        Hash16Block(ctx);
        n = 0;
        m = 0x40;
    }
    if (m > 8) {
        MemFill(ctx->mBlock + n, 0, m - 8);
    }
    ctx->mBitCountLow = lo;
    ctx->mBitCountHigh = hi;
    Hash16Block(ctx);
    MemCopy(ctx, out, 0x10);
    MemFill(ctx, 0, 0x58);
}

void Hash16Block(Hash16State *q) {
    const u32 *w;
    const u32 *p;
    s32 i;
    u32 a;
    u32 b;
    u32 c;
    u32 d;
    u32 t;
    u32 *x;
    const u32 *k;

    x = (u32 *) q->mBlock;
    a = q->mWords[0];
    b = q->mWords[1];
    c = q->mWords[2];
    d = q->mWords[3];
    k = data_0216f16c;
    for (i = 0, w = x; i < 4; i++) {
        t = *k++;
        t += *w++ + (a + ((b & c) | (~b & d)));
        a = b + ((t << 7) | (t >> 25));
        t = *k++;
        t += *w++ + (d + ((a & b) | (~a & c)));
        d = a + ((t << 12) | (t >> 20));
        t = *k++;
        t += *w++ + (c + ((d & a) | (~d & b)));
        c = d + ((t << 17) | (t >> 15));
        t = *k++;
        t += *w++ + (b + ((c & d) | (~c & a)));
        b = c + ((t << 22) | (t >> 10));
    }
    for (i = 0, p = data_0216f0ac; i < 4; i++) {
        t = *k++;
        t += x[*p++] + (a + ((b & d) | (c & ~d)));
        a = b + ((t << 5) | (t >> 27));
        t = *k++;
        t += x[*p++] + (d + ((a & c) | (b & ~c)));
        d = a + ((t << 9) | (t >> 23));
        t = *k++;
        t += x[*p++] + (c + ((d & b) | (a & ~b)));
        c = d + ((t << 14) | (t >> 18));
        t = *k++;
        t += x[*p++] + (b + ((c & a) | (d & ~a)));
        b = c + ((t << 20) | (t >> 12));
    }
    for (i = 0; i < 4; i++) {
        t = *k++;
        t += x[*p++] + (a + (b ^ c ^ d));
        a = b + ((t << 4) | (t >> 28));
        t = *k++;
        t += x[*p++] + (d + (a ^ b ^ c));
        d = a + ((t << 11) | (t >> 21));
        t = *k++;
        t += x[*p++] + (c + (d ^ a ^ b));
        c = d + ((t << 16) | (t >> 16));
        t = *k++;
        t += x[*p++] + (b + (c ^ d ^ a));
        b = c + ((t << 23) | (t >> 9));
    }
    for (i = 0; i < 4; i++) {
        t = *k++;
        t += x[*p++] + (a + (c ^ (b | ~d)));
        a = b + ((t << 6) | (t >> 26));
        t = *k++;
        t += x[*p++] + (d + (b ^ (a | ~c)));
        d = a + ((t << 10) | (t >> 22));
        t = *k++;
        t += x[*p++] + (c + (a ^ (d | ~b)));
        c = d + ((t << 15) | (t >> 17));
        t = *k++;
        t += x[*p++] + (b + (d ^ (c | ~a)));
        b = c + ((t << 21) | (t >> 11));
    }
    q->mWords[0] += a;
    q->mWords[1] += b;
    q->mWords[2] += c;
    q->mWords[3] += d;
}
