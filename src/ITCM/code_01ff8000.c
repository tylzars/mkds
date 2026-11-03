#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/unk_02152000.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/unk_02170000.h"
#include "Main/Unknown/unk_02173000.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0200c914.h"
#include "code_0214c778.h"
#include "code_02146bb8.h"

// clang-format off
// Interrupt dispatch: reads the interrupt flag and enable registers (0x04000210), takes the highest set bit with clz,
// acknowledges it, and runs the function in data_027e0008 for that bit with lr set to func_01ff8058.
// Not compiled code: it jumps with a set return address instead of a call (ldr lr, bx).
asm void func_01ff8000(void) {
    stmdb sp!, {lr}
    mov ip, #0x4000000
    add ip, ip, #0x210
    ldr r1, [ip, #-0x8]
    cmp r1, #0x0
    ldmeqia sp!, {pc}
    ldmia ip, {r1, r2}
    ands r1, r1, r2
    ldmeqia sp!, {pc}
    mov r3, #0x80000000
L_loop:
    clz r0, r1
    bics r1, r1, r3, lsr r0
    bne L_loop
    mov r1, r3, lsr r0
    str r1, [ip, #0x4]
    rsbs r0, r0, #0x1f
    ldr r1, =data_027e0008
    ldr r0, [r1, r0, lsl #0x2]
    ldr lr, =func_01ff8058
    bx r0
}

// Thread switch after an interrupt: clears the pending flags of the thread list at data_027e0000, then saves the
// registers of the running thread in its context and loads those of the first runnable thread.
// Not compiled code: it switches processor modes and moves the whole register set with the user-bank forms of stm and
// ldm (msr, mrs, ^).
asm void func_01ff8058(void) {
    mov r2, #0x1
    mov r3, #0x0
    ldr ip, =data_027e0000
    ldr ip, [ip, #0x0]
    cmp ip, #0x0
    beq L_01ff80a8
L_01ff8070:
    str r2, [ip, #0x64]
    str r3, [ip, #0x78]
    str r3, [ip, #0x7c]
    ldr r0, [ip, #0x80]
    str r3, [ip, #0x80]
    mov ip, r0
    cmp ip, #0x0
    bne L_01ff8070
    ldr ip, =data_027e0000
    str r3, [ip, #0x0]
    str r3, [ip, #0x4]
    ldr ip, =data_0216ff5c
    mov r1, #0x1
    strh r1, [ip, #0x0]
L_01ff80a8:
    ldr ip, =data_0216ff5c
    ldrh r1, [ip, #0x0]
    cmp r1, #0x0
    ldreq pc, [sp], #0x4
    mov r1, #0x0
    strh r1, [ip, #0x0]
    mov r3, #0xd2
    msr cpsr_c, r3
    add r2, ip, #0x8
    ldr r1, [r2, #0x0]
L_01ff80d0:
    cmp r1, #0x0
    ldrneh r0, [r1, #0x64]
    cmpne r0, #0x1
    ldrne r1, [r1, #0x68]
    bne L_01ff80d0
    cmp r1, #0x0
    bne L_01ff80f8
L_01ff80ec:
    mov r3, #0x92
    msr cpsr_c, r3
    ldr pc, [sp], #0x4
L_01ff80f8:
    ldr r0, [ip, #0x4]
    cmp r1, r0
    beq L_01ff80ec
    ldr r3, [ip, #0xc]
    cmp r3, #0x0
    beq L_01ff8120
    stmdb sp!, {r0, r1, ip}
    mov lr, pc
    bx r3
    ldmia sp!, {r0, r1, ip}
L_01ff8120:
    str r1, [ip, #0x4]
    mrs r2, spsr
    str r2, [r0, #0x0]!
    stmdb sp!, {r0, r1}
    add r0, r0, #0x0
    add r0, r0, #0x48
    ldr r1, =func_02146c24
    blx r1
    ldmia sp!, {r0, r1}
    ldmib sp!, {r2, r3}
    stmib r0!, {r2, r3}
    ldmib sp!, {r2, r3, ip, lr}
    stmib r0!, {r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, ip, sp, lr}^
    stmib r0!, {lr}
    mov r3, #0xd3
    msr cpsr_c, r3
    stmib r0!, {sp}
    stmdb sp!, {r1}
    add r0, r1, #0x0
    add r0, r0, #0x48
    ldr r1, =func_02146bb8
    blx r1
    ldmia sp!, {r1}
    ldr sp, [r1, #0x44]
    mov r3, #0xd2
    msr cpsr_c, r3
    ldr r2, [r1, #0x0]!
    msr spsr_fc, r2
    ldr lr, [r1, #0x40]
    ldmib r1!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, ip, sp, lr}^
    mov r0, r0
    stmda sp!, {r0, r1, r2, r3, ip, lr}
    ldmia sp!, {pc}
}
// clang-format on

void func_01ff81b4(Unk02170500 *s, u32 a) {
    s32 v[3];
    s32 x;

    if (!(s->mUnk_08 & 0x100) && !(s->mUnk_08 & 0x200)) {
        if (a == 0) {
            x = s->mUnk_e0;
            v[2] = x;
            v[1] = x;
            v[0] = x;
        } else {
            x = s->mUnk_e4;
            v[2] = x;
            v[1] = x;
            v[0] = x;
        }
        func_01ff9048(0x1b, v, 3);
    }
    s->mUnk_00 += 1;
}

// non-matching: same size; the original keeps the halfword at +2 of the pair in the stack word at sp+0 and the one at
// +0 in r11 (swapped here, so the stack word is at sp+4); the mla is `mla r0, r1, r4, r0` there, `mla r0, r4, r0, r1`
// here; the first table value is stored after the second table address is loaded (constant-word load order)
void func_01ff8220(Unk02170500 *s, u32 a) {
    u32 w;
    s32 b1;
    u32 t;
    u32 q;
    u32 t2;
    u32 n;
    Unk02014c5c_out *o;
    u16 *r;
    s32 k;
    u32 v1;
    u32 f;
    u32 c;
    s32 v2;
    s32 b0;
    s32 m;
    u16 *p;
    u8 *h;
    u8 *e;
    Unk02170500_04 *i;

    v1 = s->mUnk_00[1];
    n = 4;
    s->mUnk_ae = v1;
    s->mUnk_08 |= 0x10;
    f = s->mUnk_08;
    if (f & 0x400) {
        if (a == 0x40 || a == 0x60) {
            n += 1;
        }
        if (a == 0x20 || a == 0x60) {
            n += 1;
            if (!(f & 0x100)) {
                t = s->mUnk_00[4];
                func_01ff9048(0x14, &t, 1);
            }
        }
        s->mUnk_00 += n;
        return;
    }
    if (a == 0x40 || a == 0x60) {
        n += 1;
        if (a == 0x40) {
            q = s->mUnk_00[4];
        } else {
            q = s->mUnk_00[5];
        }
        if (!(s->mUnk_08 & 0x100)) {
            func_01ff9048(0x14, &q, 1);
        }
    }
    s->mUnk_b4 = &s->mUnk_12c;
    if (s->mUnk_0c[6] != 0) {
        w = s->mUnk_8c[6];
    } else {
        w = 0;
    }
    if (s->mUnk_04->mUnk_34 != 0) {
        o = s->mUnk_04->mUnk_34 + v1;
        c = (s->mUnk_08 & 0x80) == 0;
    } else {
        o = &s->mUnk_12c;
        c = 0;
    }
    if (c == 0) {
        o->mUnk_00 = 0;
        i = s->mUnk_04;
        if (i->mUnk_10 != 0) {
            if (i->mUnk_14(o, i->mUnk_10, v1) != 0) {
                goto done;
            }
        }
        h = (u8 *) s->mUnk_d4;
        e = h + *(u32 *) (h + *(u16 *) (h + 6) + *(u16 *) (h + *(u16 *) (h + 6)) * v1 + 4);
        p = (u16 *) e;
        r = (u16 *) (e + 4);
        if (!(*p & 1)) {
            o->mUnk_4c[0] = ((s32 *) r)[0];
            o->mUnk_4c[1] = ((s32 *) r)[1];
            o->mUnk_4c[2] = ((s32 *) r)[2];
            r += 6;
        } else {
            o->mUnk_00 |= 4;
        }
        v2 = *p;
        if (v2 & 2) {
            o->mUnk_00 |= 2;
        } else if (v2 & 8) {
            k = (v2 & 0xf0) >> 4;
            b1 = ((s16 *) r)[1];
            b0 = ((s16 *) r)[0];
            func_0214d32c(o->mUnk_28);
            r += 2;
            m = (*p & 0x100) ? -0x1000 : 0x1000;
            o->mUnk_28[k] = m;
            o->mUnk_28[data_usa_02152c0c[k][0]] = b0;
            o->mUnk_28[data_usa_02152c0d[k][0]] = b1;
            if (*p & 0x200) {
                b1 = -b1;
            }
            o->mUnk_28[data_usa_02152c0e[k][0]] = b1;
            if (*p & 0x400) {
                b0 = -b0;
            }
            o->mUnk_28[data_usa_02152c0f[k][0]] = b0;
        } else {
            o->mUnk_28[0] = ((s16 *) p)[1];
            o->mUnk_28[1] = ((s16 *) r)[0];
            o->mUnk_28[2] = ((s16 *) r)[1];
            o->mUnk_28[3] = ((s16 *) r)[2];
            o->mUnk_28[4] = ((s16 *) r)[3];
            o->mUnk_28[5] = ((s16 *) r)[4];
            o->mUnk_28[6] = ((s16 *) r)[5];
            o->mUnk_28[7] = ((s16 *) r)[6];
            o->mUnk_28[8] = ((s16 *) r)[7];
            r += 8;
        }
        s->mUnk_e8(o, r, s->mUnk_00, *p);
    }
done:
    s->mUnk_b4 = o;
    if (!(s->mUnk_08 & 0x100)) {
        s->mUnk_ec(s->mUnk_b4);
    }
    c = 0;
    s->mUnk_b4 = 0;
    if (w == 3) {
        s->mUnk_08 &= ~0x40;
        s->mUnk_0c[6](s);
        c = s->mUnk_08 & 0x40;
    }
    if (a == 0x20 || a == 0x60) {
        n += 1;
        if (c == 0 && !(s->mUnk_08 & 0x100)) {
            t2 = s->mUnk_00[4];
            func_01ff9048(0x13, &t2, 1);
        }
    }
    s->mUnk_00 += n;
}

void func_01ff85d0(Unk02170500 *s, u32 a) {
    u32 f;
    Unk02170500_d4 *b;
    u8 *e;
    u8 *t;
    u32 v1;

    f = s->mUnk_08;
    if (!(f & 0x200) && (f & 1) && !(f & 2)) {
        b = (Unk02170500_d4 *) s->mUnk_dc;
        v1 = s->mUnk_00[1];
        t = (u8 *) b + b->mUnk_06;
        e = (u8 *) b + *(u32 *) (t + *(u16 *) t * v1 + 4);
        data_usa_0216188c[*(u16 *) e](s, a, e, v1);
    }
    s->mUnk_00 += 2;
}

void func_01ff8648(Unk02170500 *s, u32 a, Unk0201290c_0c *c) {
    u32 w;

    if (s->mUnk_0c[5] != 0) {
        w = s->mUnk_8c[5];
    } else {
        w = 0;
    }
    if (!(s->mUnk_08 & 0x100)) {
        func_01ff9144((u8 *) c + c->mUnk_08, c->mUnk_0c);
    }
    if (w == 3) {
        s->mUnk_08 &= ~0x40;
        s->mUnk_0c[5](s);
    }
}

void func_01ff86b4(Unk02170500 *s, u32 a) {
    u32 f;
    u8 *h;
    u8 *e;
    u32 v1;
    u8 *t;
    s32 b;

    f = s->mUnk_08;
    if (!(f & 0x200)) {
        v1 = s->mUnk_00[1];
        if ((f & 1) || !(f & 8) || v1 != s->mUnk_ad) {
            h = s->mUnk_d8;
            t = h + 4;
            b = *(u16 *) (t + *(u16 *) (h + 0xa));
            e = h + *(u32 *) (t + *(u16 *) (h + 0xa) + b * v1 + 4);
            data_usa_0216187c[*(u16 *) e](s, a, e, v1);
        }
    }
    s->mUnk_00 += 2;
}

void func_01ff8738(Unk02170500 *s, u32 a, const u8 *e, u32 b) {
    u32 w;
    u32 m;
    u32 *d;
    Unk0201290c_1c *o;
    Unk0201290c_1c *v1;
    u8 *h;
    u8 *t;
    s32 k;
    u32 x;
    u32 y;
    u32 v2[8];
    s32 c;

    s->mUnk_ad = b;
    s->mUnk_08 |= 8;
    s->mUnk_b0 = &s->mUnk_f4;
    if (s->mUnk_0c[4] != 0) {
        w = s->mUnk_8c[4];
    } else {
        w = 0;
    }
    v1 = s->mUnk_04->mUnk_38;
    if (v1 != 0 && !(s->mUnk_08 & 0x80)) {
        o = v1 + b;
        goto done;
    }
    if (a == 0x20 || a == 0x40) {
        m = 1 << (b & 0x1f);
        if (s->mUnk_bc[b >> 5] & m) {
            if (v1 != 0) {
                o = v1 + b;
            } else {
                o = data_usa_021704e4 + b;
            }
            goto done;
        }
    }
    if (v1 != 0) {
        s->mUnk_bc[b >> 5] |= 1 << (b & 0x1f);
        o = s->mUnk_04->mUnk_38 + b;
    } else if (a == 0x40) {
        s->mUnk_bc[b >> 5] |= 1 << (b & 0x1f);
        o = data_usa_021704e4 + b;
    } else {
        o = &s->mUnk_f4;
    }
    o->mUnk_00 = 0;
    h = s->mUnk_d8;
    t = h + 4;
    c = *(u16 *) (t + *(u16 *) (h + 0xa));
    if (*(u16 *) (h + *(u32 *) (t + *(u16 *) (h + 0xa) + c * b + 4) + 0x1e) & 0x20) {
        o->mUnk_00 |= 0x20;
    }
    k = *(u16 *) (e + 0x1e);
    x = ((u32 *) data_usa_02152bec)[(k >> 6) & 7];
    o->mUnk_04 = (data_0217029c.mUnk_94 & ~x) | (*(u32 *) (e + 4) & x);
    y = ((u32 *) data_usa_02152bec)[(*(u16 *) (e + 0x1e) >> 9) & 7];
    o->mUnk_08 = (data_0217029c.mUnk_98 & ~y) | (*(u32 *) (e + 8) & y);
    x = *(u32 *) (e + 0x10);
    o->mUnk_0c = (data_0217029c.mUnk_9c & ~x) | (*(u32 *) (e + 0xc) & x);
    o->mUnk_10 = *(u32 *) (e + 0x14);
    o->mUnk_14 = *(u16 *) (e + 0x1c);
    k = *(u16 *) (e + 0x1e);
    if (k & 1) {
        d = (u32 *) (e + 0x2c);
        if (!(k & 2)) {
            o->mUnk_18[0] = d[0];
            o->mUnk_18[1] = d[1];
            d += 2;
        } else {
            o->mUnk_00 |= 1;
        }
        if (!(*(u16 *) (e + 0x1e) & 4)) {
            o->mUnk_20[0] = ((s16 *) d)[0];
            o->mUnk_20[1] = ((s16 *) d)[1];
            d = (u32 *) ((s16 *) d + 2);
        } else {
            o->mUnk_00 |= 2;
        }
        if (!(*(u16 *) (e + 0x1e) & 8)) {
            o->mUnk_24[0] = d[0];
            o->mUnk_24[1] = d[1];
        } else {
            o->mUnk_00 |= 4;
        }
        o->mUnk_00 |= 8;
    }
    if (s->mUnk_04->mUnk_08 != 0 && (s->mUnk_04->mUnk_3c[b >> 5] & (1 << (b & 0x1f)))) {
        s->mUnk_04->mUnk_0c(o, s->mUnk_04->mUnk_08, b);
    }
    if (o->mUnk_00 & 0x18) {
        o->mUnk_2c = *(u16 *) (e + 0x20);
        o->mUnk_2e = *(u16 *) (e + 0x22);
        o->mUnk_30 = *(u32 *) (e + 0x24);
        o->mUnk_34 = *(u32 *) (e + 0x28);
    }
done:
    s->mUnk_b0 = o;
    v1 = s->mUnk_b0;
    if (v1->mUnk_0c & 0x1f0000) {
        if (v1->mUnk_00 & 0x20) {
            v1->mUnk_0c &= ~0x1f0000;
        }
        s->mUnk_08 &= ~2;
        if (!(s->mUnk_08 & 0x100)) {
            v2[0] = 0x293130;
            v2[1] = v1->mUnk_04;
            v2[2] = v1->mUnk_08;
            v2[3] = v1->mUnk_0c;
            v2[4] = 0x2b2a;
            v2[5] = v1->mUnk_10;
            v2[6] = v1->mUnk_14;
            func_01ff9048(v2[0], &v2[1], 6);
            if (v1->mUnk_00 & 0x18) {
                s->mUnk_f0(v1);
            }
        }
    } else {
        s->mUnk_08 |= 2;
    }
    if (w == 3) {
        s->mUnk_08 &= ~0x40;
        s->mUnk_0c[4](s);
    }
}

void func_01ff8b08(Unk02170500 *s, u32 a) {
    u32 w;
    u32 v;

    if (!(s->mUnk_08 & 0x200) && (s->mUnk_08 & 1)) {
        if (s->mUnk_0c[3] != 0) {
            w = s->mUnk_8c[3];
        } else {
            w = 0;
        }
        v = s->mUnk_00[1];
        if (!(s->mUnk_08 & 0x100)) {
            func_01ff9048(0x14, &v, 1);
        }
        if (w == 3) {
            s->mUnk_08 &= ~0x40;
            s->mUnk_0c[3](s);
        }
    }
    s->mUnk_00 += 2;
}

void func_01ff8b98(Unk02170500 *s, u32 a) {
    u32 w;
    u32 v1;
    Unk02170500_04 *i;

    if (!(s->mUnk_08 & 0x200)) {
        s->mUnk_ac = s->mUnk_00[1];
        v1 = s->mUnk_ac;
        s->mUnk_08 |= 4;
        s->mUnk_b8 = &s->mUnk_184;
        if (s->mUnk_0c[2] != 0) {
            w = s->mUnk_8c[2];
        } else {
            w = 0;
        }
        i = s->mUnk_04;
        if (i->mUnk_18 == 0 || !(i->mUnk_4c[v1 >> 5] & (1 << (v1 & 0x1f))) ||
            i->mUnk_1c(s->mUnk_b8, i->mUnk_18, v1) == 0) {
            *s->mUnk_b8 = s->mUnk_00[2] & 1;
        }
        if (*s->mUnk_b8 != 0) {
            s->mUnk_08 |= 1;
        } else {
            s->mUnk_08 &= ~1;
        }
        if (w == 3) {
            s->mUnk_08 &= ~0x40;
            s->mUnk_0c[2](s);
        }
    }
    s->mUnk_00 += 3;
}

void func_01ff8c98(Unk02170500 *s, u32 a) {
    if (s->mUnk_0c[1] != 0) {
        s->mUnk_0c[1](s);
    }
    s->mUnk_08 |= 0x20;
}

void func_01ff8cc4(Unk02170500 *s, u32 a) {
    if (s->mUnk_0c[0] != 0) {
        s->mUnk_0c[0](s);
    }
    s->mUnk_00 += 1;
}

void func_01ff8cf0(void *a) {
    Unk02170500_04 *i;
    Unk02170500 v1;

    i = a;
    if ((i->mUnk_00 & 0x10) == 0x10) {
        func_01ff8cf0_inline(i->mUnk_3c);
        func_01ff8cf0_inline(i->mUnk_44);
        func_01ff8cf0_inline(i->mUnk_4c);
        if (i->mUnk_08 != 0) {
            func_01ff8dec(i->mUnk_3c, i->mUnk_08);
        }
        if (i->mUnk_10 != 0) {
            func_01ff8dec(i->mUnk_44, i->mUnk_10);
        }
        if (i->mUnk_18 != 0) {
            func_01ff8dec(i->mUnk_4c, i->mUnk_18);
        }
        i->mUnk_00 &= ~0x10;
    }
    if (data_02170500 != 0) {
        func_01ff8e64(data_02170500, i);
        return;
    }
    data_02170500 = &v1;
    func_01ff8e64(&v1, i);
    data_02170500 = 0;
}

void func_01ff8dec(u32 *a, Unk020152bc *b) {
    s32 i;

    if (b == 0) {
        return;
    }
    do {
        for (i = 0; i < b->mUnk_19; i++) {
            if (b->mUnk_1a[i] & 0x100) {
                a[i >> 5] |= 1 << (i & 0x1f);
            }
        }
        b = b->mUnk_10;
    } while (b != 0);
}

void func_01ff8e64(Unk02170500 *s, Unk02170500_04 *i) {
    func_0214d05c_inline(s, 0x188);
    s->mUnk_c4[0] = 1;
    s->mUnk_08 = 1;
    if (i->mUnk_30 != 0) {
        s->mUnk_00 = i->mUnk_30;
    } else {
        s->mUnk_00 = (u8 *) i->mUnk_04 + i->mUnk_04->mUnk_04;
    }
    s->mUnk_04 = i;
    s->mUnk_d4 = (Unk02170500_d4 *) ((u8 *) i->mUnk_04 + 0x40);
    s->mUnk_d8 = (u8 *) i->mUnk_04 + i->mUnk_04->mUnk_08;
    s->mUnk_dc = (u8 *) i->mUnk_04 + i->mUnk_04->mUnk_0c;
    s->mUnk_e8 = (UnkFunc *) data_usa_02161850[i->mUnk_04->mUnk_15];
    s->mUnk_ec = data_usa_02161844[i->mUnk_04->mUnk_15];
    s->mUnk_f0 = data_0216185c[i->mUnk_04->mUnk_16];
    s->mUnk_e0 = i->mUnk_04->mUnk_1c;
    s->mUnk_e4 = i->mUnk_04->mUnk_20;
    if (i->mUnk_20 != 0 && i->mUnk_24 < 0x20) {
        s->mUnk_0c[i->mUnk_24] = i->mUnk_20;
        s->mUnk_8c[i->mUnk_24] = i->mUnk_25;
    }
    if (i->mUnk_00 & 1) {
        s->mUnk_08 |= 0x80;
    }
    if (i->mUnk_00 & 2) {
        s->mUnk_08 |= 0x100;
    }
    if (i->mUnk_00 & 4) {
        s->mUnk_08 |= 0x200;
    }
    if (i->mUnk_00 & 8) {
        s->mUnk_08 |= 0x400;
    }
    if (i->mUnk_28 != 0) {
        i->mUnk_28(s);
    }
    func_01ff8ff8(s);
    i->mUnk_00 &= ~1;
}

void func_01ff8ff8(Unk02170500 *s) {
    u32 v1;

    do {
        s->mUnk_08 &= ~0x40;
        v1 = s->mUnk_00[0];
        data_usa_0216196c[v1 & 0x1f](s, v1 & 0xe0);
    } while (!(s->mUnk_08 & 0x20));
}

void func_01ff9048(u32 a, const void *b, u32 n) {
    u32 c;

    if (data_usa_021731e4 != 0) {
        if (data_usa_021731e8 != 0) {
            c = data_usa_021731e4->mUnk_00;
            if (c + 1 + n <= 0xc0) {
                data_usa_021731e4->mUnk_00 = c + 1;
                data_usa_021731e4->mUnk_04[c] = a;
                if (n == 0) {
                    return;
                }
                func_0214d0a8(b, &data_usa_021731e4->mUnk_04[data_usa_021731e4->mUnk_00], n * 4);
                data_usa_021731e4->mUnk_00 += n;
                return;
            }
        }
        if (data_usa_021731e4->mUnk_00 != 0) {
            func_01ff9234();
        } else if (data_usa_021731e8 != 0) {
            func_01ff921c();
        }
    } else if (data_usa_021731e8 != 0) {
        func_01ff921c();
    }
    *(vu32 *) 0x4000400 = a;
    func_0214d044(b, (vu32 *) 0x4000400, n * 4);
}

void func_01ff9144(const void *a, u32 b) {
    if (b < 0x100 || data_0216f074[0] == 0xffffffff) {
        func_01ff9048(*(u32 *) a, a + 4, (b >> 2) - 1);
        return;
    }
    func_01ff9234();
    data_usa_021731e8 = 1;
    if (*(u32 *) data_0217320c != 0) {
        func_0214ccd4(data_0216f074[0], a, b, (UnkFunc *) func_01ff9210, (u32) &data_usa_021731e8);
    } else {
        func_0214ced0(data_0216f074[0], a, b, (UnkFunc *) func_01ff9210, (u32) &data_usa_021731e8);
    }
}

void func_01ff9210(u32 *a) {
    *a = 0;
}

void func_01ff921c(void) {
    while (data_usa_021731e8 != 0) {
    }
}

void func_01ff9234(void) {
    if (data_usa_021731e8 != 0) {
        func_01ff921c();
    }
    if (data_usa_021731e4 == 0) {
        return;
    }
    if (data_usa_021731e4->mUnk_00 == 0) {
        return;
    }
    func_0214d044(data_usa_021731e4->mUnk_04, (vu32 *) 0x4000400, data_usa_021731e4->mUnk_00 * 4);
    data_usa_021731e4->mUnk_00 = 0;
}

Unk01ff9048 *func_01ff92b4(void) {
    Unk01ff9048 *p;

    func_01ff9234();
    p = data_usa_021731e4;
    data_usa_021731e4 = 0;
    return p;
}

void func_01ff92e0(Unk01ff9048 *a) {
    if (data_usa_021731e4 == 0) {
        a->mUnk_00 = 0;
        data_usa_021731e4 = a;
    }
}
