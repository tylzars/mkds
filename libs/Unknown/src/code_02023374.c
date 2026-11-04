#include "code_02023374.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02153000.h"

void func_020244f4(Unk02180728 *a, s32 b, s32 c, u32 d, u16 *e, u16 **f) {
    s32 n;
    Unk02022aa8 *s;
    u16 *p;
    Unk02022aa8_f *g;
    u16 ch;

    n = a->mUnk_08;
    s = a->mUnk_04;
    p = e;
    g = s->mUnk_04;
    ch = g(&p);
    if (ch != 0) {
        do {
            if (ch == 10) {
                break;
            }
            b += func_02023450((Unk02023374 *) a->mUnk_00, s, b, c, d, ch);
            b += n;
            ch = g(&p);
        } while (ch != 0);
    }
    if (f != 0) {
        *f = ch == 10 ? p : 0;
    }
}

void func_020243f0(Unk02180728 *a, s32 b, s32 c, s32 d, u32 e, u32 f, u16 *g) {
    s32 h;
    s32 n;
    s32 x;
    u32 m1;
    u32 m2;
    s32 t;
    u16 *v;

    h = a->mUnk_0c + ((Unk02022aa8 *) a->mUnk_04)->mUnk_00->mUnk_01;
    v = g;
    if (v == 0) {
        return;
    }
    m1 = f & 0x800;
    m2 = f & 0x400;
    t = (d + 1) / 2;
    do {
        x = b;
        if (m1 != 0) {
            n = func_02022bbc(a->mUnk_04, a->mUnk_08, (u8 *) v, 0);
            x = b + (d - n);
        } else if (m2 != 0) {
            n = func_02022bbc(a->mUnk_04, a->mUnk_08, (u8 *) v, 0);
            x = b + (t - (n + 1) / 2);
        }
        func_020244f4(a, x, c, e, v, &v);
        c += h;
    } while (v != 0);
}

u32 func_02024340(Unk02180728 *a, s32 b, s32 c, u32 d, u32 e, void *f) {
    Unk02022b10 z;

    func_02022aa8(&z, a->mUnk_04, a->mUnk_08, a->mUnk_0c, f);
    if (e & 0x10) {
        b -= (z.mUnk_00 + 1) / 2;
    } else if (e & 0x20) {
        b -= z.mUnk_00;
    }
    if (e & 2) {
        c -= (z.mUnk_04 + 1) / 2;
    } else if (e & 4) {
        c -= z.mUnk_04;
    }
    func_020243f0(a, b, c, z.mUnk_00, d, e, f);
}

void func_0202428c(Unk02180728 *a, s32 b, s32 c, s32 d, s32 e, s32 f, u32 g, u16 *h) {
    s32 n;

    if (g & 0x100) {
        n = func_02022b44(a->mUnk_04, a->mUnk_0c, (u8 *) h);
        c += e - n;
    } else if (g & 0x80) {
        n = func_02022b44(a->mUnk_04, a->mUnk_0c, (u8 *) h);
        c += (e + 1) / 2 - (n + 1) / 2;
    }
    func_020243f0(a, b, c, d, f, g, h);
}

// clang-format off
// Walks two block sizes (c by d, with the limits a by b) down through the table data_usa_021530f8, which gives the shifts
// e and f for the base-2 logarithms of the remaining sizes (each capped at 3 once it is 8 or more), and returns the sum
// of the areas it peels off. It stops when a whole block no longer fits and adds the remainder of the position.
// Not compiled code: it takes the logarithms with clz, which 1.2 never builds (docs/compiler.md).
asm u32 func_02024184(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f) {
    stmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    sub sp, sp, #0x4
    ldr r11, =data_usa_021530f8
    mov r9, #0x0
    mov r10, #0x3
    mvn r7, #0x0
loop_top:
    ldr r4, [sp, #0x2c]
    ldr r6, [sp, #0x28]
    and ip, r3, r7, lsl r4
    cmp ip, r1
    mov r8, r7, lsl r6
    mov r5, r7, lsl r4
    and lr, r2, r7, lsl r6
    bhi d_masked_above
    mla r9, r2, ip, r9
    cmp lr, r0
    movhi r2, lr
    subhi r1, r1, ip
    subhi r3, r3, ip
    bhi next_sizes
    sub r3, r3, ip
    mla r9, lr, r3, r9
    sub r0, r0, lr
    sub r1, r1, ip
    sub r2, r2, lr
    b next_sizes
d_masked_above:
    cmp lr, r0
    mlals r9, lr, ip, r9
    mvn r3, r5
    movls r3, ip
    subls r0, r0, lr
    subls r2, r2, lr
    bls next_sizes
    and r2, r1, r5
    mla r5, lr, r2, r9
    and r2, r0, r8
    and r1, r1, r3
    add r2, r5, r2, lsl r4
    mvn r3, r8
    add r1, r2, r1, lsl r6
    and r0, r0, r3
    add sp, sp, #0x4
    add r0, r1, r0
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    bx lr
next_sizes:
    cmp r2, #0x8
    movlt r4, r2
    movge r5, r10
    clzlt r4, r4
    rsblt r5, r4, #0x1f
    cmp r3, #0x8
    movge r4, r10
    movlt r4, r3
    clzlt r4, r4
    rsblt r4, r4, #0x1f
    add r4, r11, r4, lsl #0x3
    add r6, r4, r5, lsl #0x1
    ldrb r5, [r4, r5, lsl #0x1]
    ldrb r4, [r6, #0x1]
    str r5, [sp, #0x28]
    str r4, [sp, #0x2c]
    b loop_top
    add sp, sp, #0x4
    ldmfd sp!, {r4, r5, r6, r7, r8, r9, r10, r11, lr}
    bx lr
}// clang-format on

u32 func_02024168(const u8 *a) {
    return data_02153118[a[1]][a[0]];
}

// non-matching: 57.6%, the 4-byte format matches in shape but the 8-byte format builds its 64-bit mask with other
// shifts and registers
void func_02024000(u8 *a, s32 b, s32 c, s32 d, s32 e, u32 f, s32 g) {
    u32 *p;
    u32 *q;
    u32 m;
    u32 n;
    u32 lo;
    u32 hi;
    u64 k;
    volatile u32 v;

    if (d == 8 && e == 8) {
        v = f;
        MemFillWordsByBlock(v, a, g << 3);
        return;
    }
    if (g == 4) {
        n = 32 - (b * 4 + d * 4);
        m = (0xffffffffu >> (b * 4)) << (n + b * 4);
        p = (u32 *) a + c;
        q = p + e;
        f &= m >> n;
        for (; p < q; p++) {
            *p = f | (*p & ~(m >> n));
        }
    } else {
        n = 64 - (b * 8 + d * 8);
        k = (((u64) 0xffffffffffffffff >> (b * 8)) << (n + b * 8)) >> n;
        lo = (u32) k;
        hi = (u32) (k >> 32);
        p = (u32 *) a + c * 2;
        q = p + e * 2;
        for (; p < q; p += 2) {
            p[0] = (f & lo) | (p[0] & ~lo);
            p[1] = (f & hi) | (p[1] & ~hi);
        }
    }
}

// non-matching: 92.1%, same frame, one instruction short: the original loads fmt first, computes xe * fmt into r7 and
// copies it to sl for e (`mov sl, r7`); x, y, fmt and g sit in other registers, and so does s in the 4-bit loop
void func_02023d84(Unk02023d84 *a) {
    u8 *src;
    s32 x;
    u32 e;
    s32 v;
    s32 y;
    u32 base;
    s32 y0;
    s32 ye;
    u32 w;
    s32 n;
    s32 xe;
    s32 fmt;
    u32 *p;
    s32 r0;
    s32 o;
    s32 g;
    u32 *q;
    s32 s;
    Unk020247fc b;
    u32 t;
    u32 w2;
    Unk020247fc z;
    u32 c;

    x = a->mUnk_08;
    y = a->mUnk_0c;
    v = x >= 0 ? x : 0;
    xe = x + a->mUnk_10;
    if (y >= 0) {
        y0 = y;
    } else {
        y0 = 0;
    }
    ye = y + a->mUnk_14;
    if (xe >= 8) {
        xe = 8;
    }
    if (ye >= 8) {
        ye = 8;
    }
    if (y > 0) {
        y = 0;
    }
    if (x > 0) {
        x = 0;
    }
    fmt = a->mUnk_20;
    r0 = xe * fmt;
    g = a->mUnk_1c;
    e = r0;
    n = a->mUnk_18;
    v = v * fmt;
    o = -y * n + g * -x;
    src = a->mUnk_04;
    if (fmt == 4) {
        w = a->mUnk_24;
        p = a->mUnk_00 + y0;
        q = a->mUnk_00 + ye;
        if (p < q) {
            do {
                c = *p;
                b.mUnk_00 = src + ((u32) o >> 3);
                b.mUnk_04 = 0;
                b.mUnk_05 = 0;
                BitStreamReadBits(&b, o % 8);
                for (s = v; s < e; s += 4) {
                    t = BitStreamReadBits(&b, g);
                    if (t != 0) {
                        c = (c & ~(0xf << s)) | ((w + t) << s);
                    }
                }
                *p = c;
                o += n;
                p++;
            } while (p < q);
        }
        return;
    }
    base = a->mUnk_24;
    p = a->mUnk_00 + y0 * 2;
    q = a->mUnk_00 + ye * 2;
    for (; p < q; p += 2) {
        w = p[0];
        w2 = p[1];
        z.mUnk_00 = src + ((u32) o >> 3);
        z.mUnk_04 = 0;
        z.mUnk_05 = 0;
        BitStreamReadBits(&z, o % 8);
        for (s = v; s < e; s += 8) {
            t = BitStreamReadBits(&z, g);
            if (t != 0) {
                if ((u32) s < 0x20) {
                    w = (w & ~(0xff << s)) | ((base + t) << s);
                } else {
                    w2 = (w2 & ~(0xff << (s - 0x20))) | ((base + t) << (s - 0x20));
                }
            }
        }
        p[0] = w;
        p[1] = w2;
        o += n;
    }
}

// non-matching: 98.9%, registers match; only the x1 clamp's movcs and the y1 shift are swapped (+0xa4)
void func_02023bcc(Unk02023374 *a, Unk02022aa8 *b, s32 c, s32 d, u32 e, Unk02023374_24 *f) {
    Unk02023d84 s;
    s32 cw;
    s32 skip;
    u32 w;
    s32 xx;
    u32 h;
    u32 y0;
    u32 x1;
    s32 ch;
    u32 y1;
    s32 nx;
    u32 x0;
    s32 ny;
    s32 xe;
    s32 ye;
    s32 yy;
    u32 tw;
    u8 *p;
    s32 bpt;
    u8 *base;

    bpt = (a->mUnk_0c * 0x40) / 8;
    cw = f->mUnk_00->mUnk_01;
    ch = b->mUnk_00->mUnk_08->mUnk_01;
    w = a->mUnk_04;
    h = a->mUnk_08;
    base = a->mUnk_00;
    if (cw == 0) {
        return;
    }
    if (c + cw < 0) {
        return;
    }
    if (d + ch < 0) {
        return;
    }
    if (c <= 0) {
        x0 = 0;
    } else {
        x0 = (u32) c >> 3;
    }
    x1 = (u32) (c + cw + 7) >> 3;
    if (d <= 0) {
        y0 = 0;
    } else {
        y0 = (u32) d >> 3;
    }
    y1 = (u32) (d + ch + 7) >> 3;
    if (x1 >= w) {
        x1 = w;
    }
    if (y1 >= h) {
        y1 = h;
    }
    nx = x1 - x0;
    ny = y1 - y0;
    if (nx < 0) {
        return;
    }
    if (ny < 0) {
        return;
    }
    tw = a->mUnk_10;
    p = base + bpt * (tw * y0 + x0);
    skip = bpt * (tw - nx);
    if (c >= 0) {
        c &= 7;
    }
    if (d >= 0) {
        d &= 7;
    }
    s.mUnk_04 = f->mUnk_04;
    ye = d - ny * 8;
    s.mUnk_10 = cw;
    s.mUnk_24 = e - 1;
    s.mUnk_14 = ch;
    xe = c - nx * 8;
    s.mUnk_1c = b->mUnk_00->mUnk_08->mUnk_04[2];
    s.mUnk_20 = a->mUnk_0c;
    s.mUnk_18 = s.mUnk_1c * b->mUnk_00->mUnk_08->mUnk_00;
    for (yy = d; yy > ye; yy -= 8) {
        s.mUnk_0c = yy;
        for (xx = c; xx > xe; xx -= 8) {
            s.mUnk_00 = (u32 *) p;
            s.mUnk_08 = xx;
            func_02023d84(&s);
            p += bpt;
        }
        p += skip;
    }
}

// non-matching: 68.9%, same shape as func_02023bcc; registers of the early locals and spill order differ
void func_020239a8(Unk02023374 *a, Unk02022aa8 *b, s32 c, s32 d, u32 e, Unk02023374_24 *f) {
    Unk02023d84 s;
    s32 bpt;
    s32 cw;
    s32 ch;
    u32 w;
    u32 h;
    u32 x0;
    u32 y0;
    u32 x1;
    u32 y1;
    s32 nx;
    s32 ny;
    s32 xe;
    s32 ye;
    s32 xx;
    s32 yy;
    u32 tx;
    u32 ty;
    u32 v;
    u32 v0;
    u32 v1;
    u8 *p;

    bpt = (a->mUnk_0c * 0x40) / 8;
    cw = f->mUnk_00->mUnk_01;
    ch = b->mUnk_00->mUnk_08->mUnk_01;
    w = a->mUnk_04;
    h = a->mUnk_08;
    if (cw == 0) {
        return;
    }
    if (c + cw < 0) {
        return;
    }
    if (d + ch < 0) {
        return;
    }
    if (c > 0) {
        x0 = (u32) c >> 3;
    } else {
        x0 = 0;
    }
    x1 = (u32) (c + cw + 7) >> 3;
    if (d > 0) {
        y0 = (u32) d >> 3;
    } else {
        y0 = 0;
    }
    y1 = (u32) (d + ch + 7) >> 3;
    if (x1 >= w) {
        x1 = w;
    }
    if (y1 >= h) {
        y1 = h;
    }
    nx = x1 - x0;
    ny = y1 - y0;
    if (nx < 0) {
        return;
    }
    if (ny < 0) {
        return;
    }
    p = a->mUnk_00;
    if (c >= 0) {
        c &= 7;
    }
    if (d >= 0) {
        d &= 7;
    }
    xe = c - nx * 8;
    ye = d - ny * 8;
    s.mUnk_04 = f->mUnk_04;
    s.mUnk_24 = e - 1;
    s.mUnk_14 = ch;
    s.mUnk_10 = cw;
    s.mUnk_1c = b->mUnk_00->mUnk_08->mUnk_04[2];
    s.mUnk_20 = a->mUnk_0c;
    s.mUnk_18 = s.mUnk_1c * b->mUnk_00->mUnk_08->mUnk_00;
    v = a->mUnk_10;
    v0 = ((u8 *) &v)[0];
    v1 = ((u8 *) &v)[1];
    ty = y0;
    for (yy = d; yy > ye; yy -= 8) {
        s.mUnk_0c = yy;
        tx = x0;
        for (xx = c; xx > xe; xx -= 8) {
            s.mUnk_00 = (u32 *) (p + func_02024184(tx, ty, w, h, v0, v1) * bpt);
            s.mUnk_08 = xx;
            func_02023d84(&s);
            tx++;
        }
        ty++;
    }
}

void func_02023944(Unk02023374 *a, u32 b) {
    volatile u32 v;
    s32 n;

    if (a->mUnk_0c == 4) {
        b = b | (b << 4);
        b = b | (b << 8);
        b = b | (b << 16);
    } else {
        b = b | (b << 8);
        b = b | (b << 16);
    }
    v = b;
    n = a->mUnk_04 * a->mUnk_08;
    n *= (a->mUnk_0c * 0x40) / 8;
    MemFillWordsByBlock(v, a->mUnk_00, n);
}

void func_02023764(Unk02023374 *a, u32 b, s32 c, s32 d, s32 e, s32 f) {
    s32 yy;
    s32 xe;
    s32 ye;
    s32 yend;
    u8 *p;
    s32 x0;
    s32 fmt;
    s32 bpt;
    s32 rowstep;
    s32 yh;
    s32 y1;
    s32 xx;
    s32 xend;
    u8 *q;
    s32 x1;
    s32 xw;

    fmt = a->mUnk_0c;
    xe = c + e;
    ye = d + f;
    if (fmt == 4) {
        b = b | (b << 4);
        b = b | (b << 8);
        b = b | (b << 16);
    } else {
        b = b | (b << 8);
        b = b | (b << 16);
    }
    yy = d & ~7;
    x0 = c & ~7;
    bpt = (fmt * 0x40) / 8;
    xend = (xe + 7) & ~7;
    yend = (ye + 7) & ~7;
    p = a->mUnk_00 + bpt * ((yy / 8) * a->mUnk_10 + x0 / 8);
    rowstep = a->mUnk_10 * bpt;
    for (; yy < yend; yy += 8) {
        if (yy < d) {
            y1 = d - yy;
        } else {
            y1 = 0;
        }
        yh = ye - yy;
        if (yh > 8) {
            yh = 8;
        }
        yh -= y1;
        q = p;
        for (xx = x0; xx < xend; xx += 8) {
            if (xx < c) {
                x1 = c - xx;
            } else {
                x1 = 0;
            }
            xw = xe - xx;
            if (xw > 8) {
                xw = 8;
            }
            xw -= x1;
            func_02024000(q, x1, y1, xw, (s64) yh, b, fmt);
            q += bpt;
        }
        p += rowstep;
    }
}

// non-matching: 73.1%, same shape as func_02023764, 8 bytes more stack; spill order and registers of the loop locals
// differ
void func_02023548(Unk02023374 *a, u32 b, s32 c, s32 d, s32 e, s32 f) {
    s32 yy;
    s32 yh;
    s32 xe;
    s32 ye;
    s32 yend;
    u8 *p;
    s32 tx0;
    s32 x0;
    u32 v1;
    u32 v0;
    u32 h;
    u32 w;
    s32 fmt;
    s32 bpt;
    u32 v;
    s32 y1;
    s32 xx;
    s32 tx;
    s32 ty;
    s32 xend;
    s32 x1;
    s32 xw;

    fmt = a->mUnk_0c;
    xe = c + e;
    ye = d + f;
    if (fmt == 4) {
        b = b | (b << 4);
        b = b | (b << 8);
        b = b | (b << 16);
    } else {
        b = b | (b << 8);
        b = b | (b << 16);
    }
    x0 = c & ~7;
    yy = d & ~7;
    v = a->mUnk_10;
    bpt = (fmt * 0x40) / 8;
    xend = (xe + 7) & ~7;
    yend = (ye + 7) & ~7;
    tx0 = x0 / 8;
    ty = yy / 8;
    w = a->mUnk_04;
    h = a->mUnk_08;
    p = a->mUnk_00;
    v0 = ((u8 *) &v)[0];
    v1 = ((u8 *) &v)[1];
    for (; yy < yend; yy += 8) {
        tx = tx0;
        if (yy < d) {
            y1 = d - yy;
        } else {
            y1 = 0;
        }
        yh = ye - yy;
        if (yh > 8) {
            yh = 8;
        }
        yh -= y1;
        for (xx = x0; xx < xend; xx += 8) {
            if (xx < c) {
                x1 = c - xx;
            } else {
                x1 = 0;
            }
            xw = xe - xx;
            if (xw > 8) {
                xw = 8;
            }
            xw -= x1;
            func_02024000(p + func_02024184(tx, ty, w, h, v0, v1) * bpt, x1, y1, xw, yh, b, fmt);
            tx++;
        }
        ty++;
    }
}

void func_02023510(Unk02023374 *a, void *b, s32 c, s32 d, u32 e,
                   void (*f)(Unk02023374 *, Unk02022aa8 *, s32, s32, u32, Unk02023374_24 *),
                   void (*g)(Unk02023374 *, u32), void (*h)(Unk02023374 *, u32, s32, s32, s32, s32), u32 i) {
    a->mUnk_04 = c;
    a->mUnk_08 = d;
    a->mUnk_0c = e;
    a->mUnk_00 = b;
    a->mUnk_14 = f;
    a->mUnk_18 = g;
    a->mUnk_1c = h;
    a->mUnk_10 = i;
}

s32 func_02023450(Unk02023374 *a, Unk02022aa8 *b, s32 c, s32 d, u32 e, u16 f) {
    Unk02023374_24 v;
    u32 i;
    Unk02022ce4_08 *o;

    i = func_02022ce4(b, f);
    if (i == 0xffff) {
        i = b->mUnk_00->mUnk_02;
    }
    v.mUnk_00 = func_02022c80(b, i);
    o = b->mUnk_00->mUnk_08;
    v.mUnk_04 = &o->mUnk_08[i * o->mUnk_02];
    a->mUnk_14(a, b, c + v.mUnk_00->mUnk_00, d, e, &v);
    if (b->mUnk_08 != 0) {
        return v.mUnk_00->mUnk_00 + v.mUnk_00->mUnk_01;
    }
    return v.mUnk_00->mUnk_02;
}

void func_02023408(void *p0, void *p1, u32 p2, u32 p3, u32 p4) {
    func_02023510((Unk02023374 *) p0, p1, p2, p3, p4, func_02023bcc, func_02023944, func_02023764, p2);
}

// clang-format off
// Looks up the pair of bytes in data_usa_021530f8 for the base-2 logarithms of c and d (each capped at 3 once it is 8
// or more) and passes the pair, as a word, with the other arguments and three callbacks to func_02023510.
// Not compiled code: it takes the logarithms with clz, which 1.2 never builds (docs/compiler.md).
asm void func_02023374(void *a, void *b, s32 c, s32 d, s32 e) {
    stmfd sp!, {r4, r5, r6, lr}
    sub sp, sp, #0x18
    cmp r2, #0x8
    movlt r4, r2
    movge ip, #0x3
    clzlt r4, r4
    rsblt ip, r4, #0x1f
    cmp r3, #0x8
    movlt r4, r3
    movge r6, #0x3
    clzlt r4, r4
    rsblt r6, r4, #0x1f
    ldr r4, =data_usa_021530f8
    ldr r5, [sp, #0x28]
    add r4, r4, r6, lsl #0x3
    ldrb r6, [r4, ip, lsl #0x1]
    add ip, r4, ip, lsl #0x1
    ldr r4, =func_020239a8
    strb r6, [sp, #0x14]
    ldrb r6, [ip, #0x1]
    ldr lr, =func_02023944
    ldr ip, =func_02023548
    strb r6, [sp, #0x15]
    str r5, [sp, #0x0]
    str r4, [sp, #0x4]
    str lr, [sp, #0x8]
    str ip, [sp, #0xc]
    ldr ip, [sp, #0x14]
    str ip, [sp, #0x10]
    bl func_02023510
    add sp, sp, #0x18
    ldmfd sp!, {r4, r5, r6, lr}
    bx lr
}
// clang-format on
