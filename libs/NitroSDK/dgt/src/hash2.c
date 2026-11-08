#include "hash2.h"

#include "code_0214d018.h"
#include "Main/Unknown/code_02150000.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_02150e1c.h"

u32 data_02180490;

// Selects the block routine DGT_Hash2SetSource and DGT_Hash2GetDigest call: the overlay-table one when flag is
// nonzero. Returns the previous flag.
u32 DGT_SetOverlayTableMode(u32 flag) {
    u32 prev;

    prev = data_02180490;
    data_02180490 = flag;
    if (flag != 0) {
        data_0216f26c = DGTi_Hash2ProcessMessageBlock;
    } else {
        data_0216f26c = func_02150e1c;
    }
    return prev;
}

// Starts a SHA-1 computation.
void DGT_Hash2Reset(Hash20State *ctx) {
    ctx->mWords[0] = 0x67452301u;
    ctx->mWords[1] = 0xefcdab89u;
    ctx->mWords[2] = 0x98badcfeu;
    ctx->mWords[3] = 0x10325476u;
    ctx->mWords[4] = 0xc3d2e1f0u;
    ctx->mBitCountLow = 0x0u;
    ctx->mBitCountHigh = 0x0u;
    ctx->mBufferLen = 0x0u;
}

// Adds length bytes of input to the SHA-1 computation, hashing each full 64-byte block as it fills.
void DGT_Hash2SetSource(Hash20State *ctx, const u8 *input, u32 length) {
    u8 *buffer;
    u32 newLow;
    u32 num;
    u32 chunk;

    buffer = ctx->mBlock;
    if (length == 0) {
        return;
    }
    newLow = ctx->mBitCountLow + (length << 3);
    if (newLow < ctx->mBitCountLow) {
        ctx->mBitCountHigh++;
    }
    ctx->mBitCountHigh += length >> 29;
    ctx->mBitCountLow = newLow;
    num = ctx->mBufferLen;
    if (num != 0) {
        if (num + length >= 0x40) {
            chunk = 0x40 - num;
            MI_CpuCopy8(input, buffer + num, chunk);
            length -= chunk;
            input += chunk;
            data_0216f26c(ctx, buffer, 0x40);
            ctx->mBufferLen = 0;
        } else {
            MI_CpuCopy8(input, buffer + num, length);
            ctx->mBufferLen += length;
            return;
        }
    }
    if (length >= 0x40) {
        chunk = length & ~0x3f;
        length -= chunk;
        if (((u32) input & 3) == 0) {
            data_0216f26c(ctx, (u8 *) input, chunk);
            input += chunk;
        } else {
            do {
                MI_CpuCopy8(input, buffer, 0x40);
                input += 0x40;
                data_0216f26c(ctx, buffer, 0x40);
                chunk -= 0x40;
            } while ((int) chunk > 0);
        }
    }
    ctx->mBufferLen = length;
    if (length == 0) {
        return;
    }
    MI_CpuCopy8(input, buffer, length);
}

// Callers pass ctx and digest only. The prologue pushes r0-r3 (the form 1.2 gives a variadic function), and the call
// to MIi_CpuClear32 at the end clears the pushed ctx.
void DGT_Hash2GetDigest(Hash20State *ctx, u8 *digest, ...) {
    volatile u32 z;
    u32 *blockWords;
    u8 *blockBytes;
    int len;
    int wordIndex;
    u32 value;

    len = ctx->mBufferLen;
    blockWords = (u32 *) ctx->mBlock;
    wordIndex = len >> 2;
    if ((len & 3) == 0) {
        blockWords[wordIndex] = 0;
    }
    blockBytes = ctx->mBlock;
    blockBytes[len] = 0x80;
    len++;
    while ((len & 3) != 0) {
        blockBytes[len] = 0;
        len++;
    }
    wordIndex++;
    if (ctx->mBufferLen >= 0x38) {
        for (; wordIndex < 16; wordIndex++) {
            blockWords[wordIndex] = 0;
        }
        data_0216f26c(ctx, (u8 *) blockWords, 0x40);
        wordIndex = 0;
    }
    for (; wordIndex < 14; wordIndex++) {
        blockWords[wordIndex] = 0;
    }
    value = ctx->mBitCountLow;
    blockBytes[0x3f] = value;
    blockBytes[0x3e] = value >> 8;
    blockBytes[0x3d] = value >> 16;
    blockBytes[0x3c] = value >> 24;
    value = ctx->mBitCountHigh;
    blockBytes[0x3b] = value;
    blockBytes[0x3a] = value >> 8;
    blockBytes[0x39] = value >> 16;
    blockBytes[0x38] = value >> 24;
    data_0216f26c(ctx, (u8 *) blockWords, 0x40);
    value = ctx->mWords[0];
    digest[0] = value >> 24;
    digest[1] = value >> 16;
    digest[2] = value >> 8;
    digest[3] = value;
    value = ctx->mWords[1];
    digest[4] = value >> 24;
    digest[5] = value >> 16;
    digest[6] = value >> 8;
    digest[7] = value;
    value = ctx->mWords[2];
    digest[8] = value >> 24;
    digest[9] = value >> 16;
    digest[10] = value >> 8;
    digest[11] = value;
    value = ctx->mWords[3];
    digest[12] = value >> 24;
    digest[13] = value >> 16;
    digest[14] = value >> 8;
    digest[15] = value;
    value = ctx->mWords[4];
    digest[16] = value >> 24;
    digest[17] = value >> 16;
    digest[18] = value >> 8;
    digest[19] = value;
    ctx->mBufferLen = 0;
    z = 0;
    MIi_CpuClear32(z, &ctx, 4);
}

// Hashes length bytes of source in 64-byte blocks, clearing the words at offsets 0x18 and 0x38 of each block while it
// is hashed.
void DGTi_Hash2ProcessMessageBlock(Hash20State *ctx, u8 *source, int length) {
    u32 saved18;
    u32 saved38;
    int i;
    int blocks;

    blocks = length / 64;
    for (i = 0; i < blocks; i++) {
        saved18 = *OFFSET_PTR(u32, source, 0x18);
        saved38 = *OFFSET_PTR(u32, source, 0x38);
        *OFFSET_PTR(u32, source, 0x18) = 0;
        *OFFSET_PTR(u32, source, 0x38) = 0;
        func_02150e1c(ctx, source, 0x40);
        *OFFSET_PTR(u32, source, 0x18) = saved18;
        *OFFSET_PTR(u32, source, 0x38) = saved38;
        source += 0x40;
    }
}

// HMAC-SHA-1 of bin with key, written to digest. A key longer than 64 bytes is hashed down first.
void DGT_Hash2CalcHmac(u8 *digest, const u8 *bin, u32 binLen, const u8 *key, s32 keyLen) {
    u8 ipad[0x40];
    u8 opad[0x40];
    u8 inner[0x14];
    Hash20State ctx;
    u8 *innerPtr;
    s32 i;

    innerPtr = inner;
    if (digest == 0 || bin == 0 || binLen == 0 || key == 0 || keyLen == 0) {
        return;
    }
    if (keyLen > 0x40) {
        DGT_Hash2Reset(&ctx);
        DGT_Hash2SetSource(&ctx, key, keyLen);
        DGT_Hash2GetDigest(&ctx, innerPtr);
        key = innerPtr;
        keyLen = 0x14;
    }
    for (i = 0; i < keyLen; i++) {
        ipad[i] = *key ^ 0x36;
        opad[i] = *key++ ^ 0x5c;
    }
    for (; i < 0x40; i++) {
        ipad[i] = 0x36;
        opad[i] = 0x5c;
    }
    DGT_Hash2Reset(&ctx);
    DGT_Hash2SetSource(&ctx, ipad, 0x40);
    DGT_Hash2SetSource(&ctx, bin, binLen);
    DGT_Hash2GetDigest(&ctx, innerPtr);
    DGT_Hash2Reset(&ctx);
    DGT_Hash2SetSource(&ctx, opad, 0x40);
    DGT_Hash2SetSource(&ctx, innerPtr, 0x14);
    DGT_Hash2GetDigest(&ctx, digest);
}
