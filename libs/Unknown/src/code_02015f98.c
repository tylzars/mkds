#include "code_02015f98.h"
#include "Main/Unknown/unk_02161000.h"

void func_0201625c(u32 a, u32 b, u32 c, u32 d, u32 e) {
    data_02161a04[0] = &data_02161a18[a];
    data_02161a04[1] = &data_02161a18[b];
    data_02161a04[2] = &data_02161a18[c];
    data_02161a04[3] = &data_02161a18[d];
    data_02161a04[4] = &data_02161a18[e];
}

void func_020161b4(u32 a, u32 b) {
    if (a <= 2) {
        func_0201625c(4, 3, 2, 0, 1);
    } else {
        func_0201625c(4, 3, 0, 2, 1);
    }
    data_02173210 = a;
    func_02016134();
    if (b != 0) {
        data_021619ec = (u32(*)(s32, s32, s32)) func_02015fa0;
        data_021619f0 = (void (*)(void *)) func_02015f98;
    }
}

void func_02016134(void) {
    u32 n;
    s32 i;
    Unk02015fa0 *p;

    n = data_02173210;
    p = data_02161a18;
    if (n > 1) {
        n++;
    }
    for (i = 0; i < 5; i++) {
        if (i < (s32) n) {
            p->mUnk_08 = 1;
        } else {
            p->mUnk_08 = 0;
        }
        if (p->mUnk_0c != 0) {
            p->mUnk_00 = 0;
            p->mUnk_04 = 0x10000;
        } else {
            p->mUnk_00 = 0;
            p->mUnk_04 = 0x20000;
        }
        p++;
    }
}

// non-matching: 0x190 bytes against 0x194. Same branches and literal pools; the original keeps the size in r7, the
// halved size in lr and the address base in r8 with the table pointers and null hoisted into r0, r2, r3 and ip, and
// uses no fp; here the size lands in r9 and the temporaries use fp.
u32 func_02015fa0(u32 a, u32 b) {
    u32 s;
    u32 h;
    u32 base;
    u32 ok;
    s32 i;
    Unk02015fa0 *e;
    Unk02015fa0 *t;

    if (a == 0) {
        s = 0x10;
    } else {
        s = (a + 0xf) & ~0xf;
    }
    if (s >= 0x7fff0) {
        return 0;
    }
    if (b != 0) {
        h = s >> 1;
        for (i = 0; i < 2; i++) {
            e = data_021619fc[i];
            if (e->mUnk_08 != 0 && e->mUnk_04 - e->mUnk_00 >= s) {
                switch (e->mUnk_10) {
                    case 0:
                        t = &data_02161a18[1];
                        break;
                    case 3:
                        t = &data_02161a18[2];
                        break;
                    default:
                        t = 0;
                        break;
                }
                if (t->mUnk_08 != 0 && t->mUnk_04 - t->mUnk_00 >= h) {
                    ok = 1;
                    base = e->mUnk_00;
                    e->mUnk_00 = base + s;
                    t->mUnk_00 += h;
                    base += e->mUnk_14;
                    goto done;
                }
            }
        }
        ok = 0;
    } else {
        s32 j;
        Unk02015fa0 *q;

        for (j = 0; j < 5; j++) {
            q = data_02161a04[j];
            if (q->mUnk_08 != 0 && q->mUnk_04 - q->mUnk_00 >= s) {
                q->mUnk_04 -= s;
                ok = 1;
                base = q->mUnk_04 + q->mUnk_14;
                goto done;
            }
        }
        ok = 0;
    }
done:
    if (ok == 0) {
        return 0;
    }
    return ((base >> 3) & 0xffff) | ((s >> 4) << 16) | (b << 31);
}

s32 func_02015f98(void) {
    return 0;
}
