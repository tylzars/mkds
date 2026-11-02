#include "03/code_021bdaa4.h"
#include "03/code_021b7bb4.h"
#include "03/code_021bd000.h"
#include "code_02134d30.h"

u8 *func_ov003_021bdaa4(u8 *p, u32 a, const void *b, u32 c) {
    u32 d;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    *(u16 *) p = func_ov003_021b7c44_inline(a);
    d = ((c + 0xb) & ~7) - 4;
    *(u16 *) (p + 2) = func_ov003_021b7c44_inline(c);
    p = (u8 *) p + 4;
    memset(p, 0, d);
    memcpy(p, b, c);
    return p + d;
}

s32 func_ov003_021bdb0c(u8 *p, u32 a, u8 *b, u32 c, const void *d) {
    u8 *e;
    u8 *f;
    u32 g;
    e = p;
    g = 0;
    b[0] = 0;
    b[1] = 0;
    b[2] = 0;
    b[3] = 0;
    b[4] = 0;
    b[5] = 0;
    b[6] = 0;
    b[7] = 0;
    *(u16 *) b = func_ov003_021b7c44_inline(c - 8);
    if (d != NULL) {
        func_ov003_021bccd0(p + 6, b, c, d, 0x10);
        c += 8;
    } else {
        memcpy(p + 6, b, c);
    }
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    *(u16 *) p = func_ov003_021b7c44_inline(a);
    *(u16 *) (p + 2) = func_ov003_021b7c44_inline(c);
    e += 6;
    e += c;
    for (f = p; f < e; f++) {
        g += *f;
    }
    *(u16 *) e = func_ov003_021b7c44_inline(g);
    return e + 2 - p;
}

u8 *func_ov003_021bdbd0(const u8 *p, u32 *a, s32 *b) {
    u8 *c;
    c = (u8 *) p + 8;
    return func_ov003_021bdc08(&c, c + func_ov003_021b7c44_inline(*(u16 *) p), a, b);
}

u8 *func_ov003_021bdc08(u8 **p, u8 *a, u32 *b, s32 *c) {
    u8 *d;
    d = *p;
    if (d >= a) {
        return NULL;
    }
    *b = func_ov003_021b7c44_inline(*(u16 *) d);
    *c = func_ov003_021b7c44_inline(*(u16 *) (d + 2));
    d += 4;
    *p = d + (((*c + 0xb) & ~7) - 4);
    return d;
}

u8 *func_ov003_021bdc5c(const u8 *p, u32 *a, s32 *b) {
    u32 c;
    const u8 *d;
    const u8 *e;
    c = 0;
    *a = func_ov003_021b7c44_inline(*(u16 *) p);
    *b = func_ov003_021b7c44_inline(*(u16 *) (p + 2));
    d = p + 6 + *b;
    for (e = p; e < d; e++) {
        c += *e;
    }
    if ((u16) c != func_ov003_021b7c44_inline(*(u16 *) d)) {
        return NULL;
    }
    return (u8 *) p + 6;
}
