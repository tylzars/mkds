#include "code_02150228.h"
#include "code_0214d018.h"
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

// Adds length bytes of input to the hash, running ProcessBlock on each full 64-byte block.
void DGT_Hash1SetSource(DGTHash1Context *ctx, const void *input, u32 length) {
    u32 used;
    u32 room;
    int blocks;
    const u8 *src;

    used = (u32) ctx->mLength & 0x3f;
    ctx->mLength += length;
    room = 0x40 - used;
    if (room > length) {
        if (length == 0) {
            return;
        }
        MI_CpuCopy8(input, ctx->mBuffer8 + used, length);
        return;
    }
    MI_CpuCopy8(input, ctx->mBuffer8 + used, room);
    ProcessBlock(ctx);
    length -= room;
    blocks = length >> 6;
    src = (const u8 *) input + room;
    for (; blocks > 0; blocks--) {
        MI_CpuCopy8(src, ctx->mBuffer8, 0x40);
        src += 0x40;
        ProcessBlock(ctx);
    }
    if ((length & 0x3f) == 0) {
        return;
    }
    MI_CpuCopy8(src, ctx->mBuffer8, length & 0x3f);
}

// Appends the 0x80 pad, zeros and the bit count, runs the last block, copies the 16 state bytes to digest and clears
// ctx.
void DGT_Hash1GetDigest_R(void *digest, DGTHash1Context *ctx) {
    u32 bitsLow;
    u32 bitsHigh;
    u32 used;
    u32 room;
    u64 bits;

    bits = ctx->mLength << 3;
    bitsLow = bits;
    bitsHigh = bits >> 32;
    DGT_Hash1SetSource(ctx, &data_0216f0a8, 1);
    used = ctx->mLength & 0x3f;
    room = 0x40 - used;
    if (room < 8) {
        MI_CpuFill8(ctx->mBuffer8 + used, 0, room);
        ProcessBlock(ctx);
        used = 0;
        room = 0x40;
    }
    if (room > 8) {
        MI_CpuFill8(ctx->mBuffer8 + used, 0, room - 8);
    }
    ctx->mBitCountLow = bitsLow;
    ctx->mBitCountHigh = bitsHigh;
    ProcessBlock(ctx);
    MI_CpuCopy8(ctx, digest, 0x10);
    MI_CpuFill8(ctx, 0, 0x58);
}

// One MD5 block: four rounds of 16 steps over the 16 words of ctx.mBuffer8, added into ctx.mState.
void ProcessBlock(DGTHash1Context *ctx) {
    const u32 *word;
    const u32 *order;
    s32 i;
    u32 a;
    u32 b;
    u32 c;
    u32 d;
    u32 sum;
    u32 *block;
    const u32 *constant;

    block = (u32 *) ctx->mBuffer8;
    a = ctx->mState[0];
    b = ctx->mState[1];
    c = ctx->mState[2];
    d = ctx->mState[3];
    constant = data_0216f16c;
    for (i = 0, word = block; i < 4; i++) {
        sum = *constant++;
        sum += *word++ + (a + ((b & c) | (~b & d)));
        a = b + ((sum << 7) | (sum >> 25));
        sum = *constant++;
        sum += *word++ + (d + ((a & b) | (~a & c)));
        d = a + ((sum << 12) | (sum >> 20));
        sum = *constant++;
        sum += *word++ + (c + ((d & a) | (~d & b)));
        c = d + ((sum << 17) | (sum >> 15));
        sum = *constant++;
        sum += *word++ + (b + ((c & d) | (~c & a)));
        b = c + ((sum << 22) | (sum >> 10));
    }
    for (i = 0, order = data_0216f0ac; i < 4; i++) {
        sum = *constant++;
        sum += block[*order++] + (a + ((b & d) | (c & ~d)));
        a = b + ((sum << 5) | (sum >> 27));
        sum = *constant++;
        sum += block[*order++] + (d + ((a & c) | (b & ~c)));
        d = a + ((sum << 9) | (sum >> 23));
        sum = *constant++;
        sum += block[*order++] + (c + ((d & b) | (a & ~b)));
        c = d + ((sum << 14) | (sum >> 18));
        sum = *constant++;
        sum += block[*order++] + (b + ((c & a) | (d & ~a)));
        b = c + ((sum << 20) | (sum >> 12));
    }
    for (i = 0; i < 4; i++) {
        sum = *constant++;
        sum += block[*order++] + (a + (b ^ c ^ d));
        a = b + ((sum << 4) | (sum >> 28));
        sum = *constant++;
        sum += block[*order++] + (d + (a ^ b ^ c));
        d = a + ((sum << 11) | (sum >> 21));
        sum = *constant++;
        sum += block[*order++] + (c + (d ^ a ^ b));
        c = d + ((sum << 16) | (sum >> 16));
        sum = *constant++;
        sum += block[*order++] + (b + (c ^ d ^ a));
        b = c + ((sum << 23) | (sum >> 9));
    }
    for (i = 0; i < 4; i++) {
        sum = *constant++;
        sum += block[*order++] + (a + (c ^ (b | ~d)));
        a = b + ((sum << 6) | (sum >> 26));
        sum = *constant++;
        sum += block[*order++] + (d + (b ^ (a | ~c)));
        d = a + ((sum << 10) | (sum >> 22));
        sum = *constant++;
        sum += block[*order++] + (c + (a ^ (d | ~b)));
        c = d + ((sum << 15) | (sum >> 17));
        sum = *constant++;
        sum += block[*order++] + (b + (d ^ (c | ~a)));
        b = c + ((sum << 21) | (sum >> 11));
    }
    ctx->mState[0] += a;
    ctx->mState[1] += b;
    ctx->mState[2] += c;
    ctx->mState[3] += d;
}
