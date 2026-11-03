#include "code_02150808.h"

#include "code_0214d018.h"
#include "Main/Unknown/code_02150000.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_02150e1c.h"

u32 data_02180490;

u32 func_02150dc8(u32 v) {
    u32 old;

    old = data_02180490;
    data_02180490 = v;
    if (v != 0) {
        data_0216f26c = func_02150994;
    } else {
        data_0216f26c = func_02150e1c;
    }
    return old;
}

void func_02150d78(Unk02150a10 *p0) {
    p0->mUnk_00[0] = (u32) 0x67452301u;
    p0->mUnk_00[1] = (u32) 0xefcdab89u;
    p0->mUnk_00[2] = (u32) 0x98badcfeu;
    p0->mUnk_00[3] = (u32) 0x10325476u;
    p0->mUnk_00[4] = (u32) 0xc3d2e1f0u;
    p0->mUnk_14 = (u32) 0x0u;
    p0->mUnk_18 = (u32) 0x0u;
    p0->mUnk_1c = (u32) 0x0u;
}

void func_02150c1c(Unk02150a10 *ctx, u8 *src, u32 n) {
    u8 *buf;
    u32 t;
    u32 f;
    u32 k;

    buf = ctx->mUnk_20;
    if (n == 0) {
        return;
    }
    t = ctx->mUnk_14 + (n << 3);
    if (t < ctx->mUnk_14) {
        ctx->mUnk_18++;
    }
    ctx->mUnk_18 += n >> 29;
    ctx->mUnk_14 = t;
    f = ctx->mUnk_1c;
    if (f != 0) {
        if (f + n >= 0x40) {
            k = 0x40 - f;
            func_0214d1fc(src, buf + f, k);
            n -= k;
            src += k;
            data_0216f26c(ctx, buf, 0x40);
            ctx->mUnk_1c = 0;
        } else {
            func_0214d1fc(src, buf + f, n);
            ctx->mUnk_1c += n;
            return;
        }
    }
    if (n >= 0x40) {
        k = n & ~0x3f;
        n -= k;
        if (((u32) src & 3) == 0) {
            data_0216f26c(ctx, src, k);
            src += k;
        } else {
            do {
                func_0214d1fc(src, buf, 0x40);
                src += 0x40;
                data_0216f26c(ctx, buf, 0x40);
                k -= 0x40;
            } while ((int) k > 0);
        }
    }
    ctx->mUnk_1c = n;
    if (n == 0) {
        return;
    }
    func_0214d1fc(src, buf, n);
}

// Callers pass ctx and out only. The prologue pushes r0-r3 (the form 1.2 gives a variadic function), and the call
// to func_0214d018 at the end clears the pushed ctx.
void func_02150a10(Unk02150a10 *ctx, u8 *out, ...) {
    volatile u32 z;
    u32 *w;
    u8 *b;
    int n;
    int i;
    u32 x;

    n = ctx->mUnk_1c;
    w = (u32 *) ctx->mUnk_20;
    i = n >> 2;
    if ((n & 3) == 0) {
        w[i] = 0;
    }
    b = ctx->mUnk_20;
    b[n] = 0x80;
    n++;
    while ((n & 3) != 0) {
        b[n] = 0;
        n++;
    }
    i++;
    if (ctx->mUnk_1c >= 0x38) {
        for (; i < 16; i++) {
            w[i] = 0;
        }
        data_0216f26c(ctx, (u8 *) w, 0x40);
        i = 0;
    }
    for (; i < 14; i++) {
        w[i] = 0;
    }
    x = ctx->mUnk_14;
    b[0x3f] = x;
    b[0x3e] = x >> 8;
    b[0x3d] = x >> 16;
    b[0x3c] = x >> 24;
    x = ctx->mUnk_18;
    b[0x3b] = x;
    b[0x3a] = x >> 8;
    b[0x39] = x >> 16;
    b[0x38] = x >> 24;
    data_0216f26c(ctx, (u8 *) w, 0x40);
    x = ctx->mUnk_00[0];
    out[0] = x >> 24;
    out[1] = x >> 16;
    out[2] = x >> 8;
    out[3] = x;
    x = ctx->mUnk_00[1];
    out[4] = x >> 24;
    out[5] = x >> 16;
    out[6] = x >> 8;
    out[7] = x;
    x = ctx->mUnk_00[2];
    out[8] = x >> 24;
    out[9] = x >> 16;
    out[10] = x >> 8;
    out[11] = x;
    x = ctx->mUnk_00[3];
    out[12] = x >> 24;
    out[13] = x >> 16;
    out[14] = x >> 8;
    out[15] = x;
    x = ctx->mUnk_00[4];
    out[16] = x >> 24;
    out[17] = x >> 16;
    out[18] = x >> 8;
    out[19] = x;
    ctx->mUnk_1c = 0;
    z = 0;
    func_0214d018(z, &ctx, 4);
}

void func_02150994(Unk02150a10 *ctx, u8 *data, int n) {
    u32 a;
    u32 b;
    int i;
    int blocks;

    blocks = n / 64;
    for (i = 0; i < blocks; i++) {
        a = *(u32 *) (data + 0x18);
        b = *(u32 *) (data + 0x38);
        *(u32 *) (data + 0x18) = 0;
        *(u32 *) (data + 0x38) = 0;
        func_02150e1c(ctx, data, 0x40);
        *(u32 *) (data + 0x18) = a;
        *(u32 *) (data + 0x38) = b;
        data += 0x40;
    }
}

void func_02150808(u8 *a, const u8 *b, u32 n, const u8 *c, s32 m) {
    u8 buf0[0x40];
    u8 buf1[0x40];
    u8 buf2[0x14];
    Unk02150a10 v;
    u8 *p;
    s32 i;

    p = buf2;
    if (a == 0 || b == 0 || n == 0 || c == 0 || m == 0) {
        return;
    }
    if (m > 0x40) {
        func_02150d78(&v);
        func_02150c1c(&v, (u8 *) c, m);
        func_02150a10(&v, p);
        c = p;
        m = 0x14;
    }
    for (i = 0; i < m; i++) {
        buf0[i] = *c ^ 0x36;
        buf1[i] = *c++ ^ 0x5c;
    }
    for (; i < 0x40; i++) {
        buf0[i] = 0x36;
        buf1[i] = 0x5c;
    }
    func_02150d78(&v);
    func_02150c1c(&v, buf0, 0x40);
    func_02150c1c(&v, (u8 *) b, n);
    func_02150a10(&v, p);
    func_02150d78(&v);
    func_02150c1c(&v, buf1, 0x40);
    func_02150c1c(&v, p, 0x14);
    func_02150a10(&v, a);
}
