#include "Main/Unknown/code_0204b714.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_02133458.h"

#pragma thumb on

u32 func_0204b714(u32 a, u32 *b, u32 n, void (*c)(u32 *, u32), s32 d, u32 e, s32 f) {
    if (data_021759d4->mUnk_0c == 0 || func_02145d2c() == 0) {
        return 0;
    }
    if (func_0204b3a4() == 0) {
        return 0;
    }
    data_021759d4->mUnk_04 = 0;
    data_021759d4->mUnk_10 = 1;
    data_021759d4->mUnk_00 = 3;
    data_021759d4->mUnk_2c = a;
    data_021759d4->mUnk_28 = b;
    data_021759d4->mUnk_30 = n;
    data_021759d4->mUnk_34 = e;
    data_021759d4->mUnk_38 = f;
    data_021759d4->mUnk_14 = d;
    func_0200ee3c(b, n);
    func_02145e8c(a, (u32) b, n, (UnkFunc *) func_0204b7b8, c, 1, 6, 1, 0);
    return 1;
}

void func_0204b7b8(void (*a)(u32 *, u32)) {
    u32 *p;
    u32 n;
    s32 e;
    s32 f;
    u32 s;
    u16 v;
    u16 t;
    e = 0;
    f = 1;
    s = func_021457ec();
    func_0204b3dc();
    data_021759d4->mUnk_10 = 0;
    switch (s) {
        case 0:
            func_0200ee58(data_021759d4->mUnk_28, data_021759d4->mUnk_30);
            if (data_021759d4->mUnk_38 != 0) {
                p = (u32 *) ((u8 *) data_021759d4->mUnk_28 + 8);
                n = data_021759d4->mUnk_30 - 8;
                if (func_0204b960((u8 *) data_021759d4->mUnk_28) == 0) {
                    e = 4;
                }
            } else {
                p = data_021759d4->mUnk_28;
                n = data_021759d4->mUnk_30;
            }
            if (e == 0) {
                if (func_0204b084(p, n, data_021759d4->mUnk_34) == 0) {
                    e = 3;
                } else if (func_0204b258((u8 *) data_021759d4->mUnk_28, data_021759d4->mUnk_30, 0) == 0) {
                    e = 3;
                } else if (data_021759d4->mUnk_34 != 0 && *p != data_021759d4->mUnk_34) {
                    e = 3;
                }
            }
            break;
        case 1:
        case 4:
        case 6:
            e = 2;
            break;
        case 2:
        case 3:
        case 5:
        case 7:
        default:
            e = 1;
            break;
    }
    p = data_021759d4->mUnk_28;
    v = *(u16 *) ((u8 *) p + data_021759d4->mUnk_30 - 4);
    switch (data_021759d4->mUnk_14) {
        case 0:
            break;
        case 1:
            if (e != 2) {
                data_021759d4->mUnk_1c = e;
                data_021759d4->mUnk_20 = data_021759d4->mUnk_28;
                data_021759d4->mUnk_24 = v;
                p = (u32 *) ((u8 *) data_021759d4->mUnk_28 + data_021759d4->mUnk_30);
                func_0204b714(data_021759d4->mUnk_18, p, data_021759d4->mUnk_30, a, 2, data_021759d4->mUnk_34,
                              data_021759d4->mUnk_38);
                f = 0;
            } else {
                f = 1;
            }
            break;
        case 2:
            if (e == 0) {
                if (data_021759d4->mUnk_1c == 0) {
                    t = data_021759d4->mUnk_24;
                    if ((t == 0 && v == 0xffff) || t >= v) {
                        p = data_021759d4->mUnk_20;
                    }
                }
            } else {
                if (data_021759d4->mUnk_1c == 0) {
                    e = 0;
                    p = data_021759d4->mUnk_20;
                } else if (e == 2 || data_021759d4->mUnk_1c == 2) {
                    e = 2;
                } else if (e != 1 && data_021759d4->mUnk_1c != 1) {
                    if (e == 4 && data_021759d4->mUnk_1c == 4) {
                        e = 4;
                    } else {
                        e = 3;
                    }
                } else {
                    e = 1;
                }
            }
            break;
    }
    if (f != 0) {
        if (e == 0) {
            if (a != 0) {
                a(p, data_021759d4->mUnk_30);
            }
            func_0204ba7c();
            return;
        }
        if (e == 2) {
            data_021759d4->mUnk_0c = 0;
        }
        func_0204b344(e);
    }
}

s32 func_0204b960(u8 *p) {
    s32 r;
    u8 i;
    r = 1;
    i = 0;
    while (r == 1 && i < 8) {
        if (*p != (u8) (func_02133458(0x3031565353444b4dull, i * 8) & 0xff)) {
            r = 0;
        }
        i++;
        p++;
    }
    return r;
}

void func_0204b9ac(void) {
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2 || func_0200e8fc() != 0) {
        data_021759d4->mUnk_0c = 0;
        return;
    }
    data_021759d4->mUnk_0c = 1;
    func_0204b3a4();
    func_02145d44(0x1202);
    func_0204b3dc();
    data_021759d4->mUnk_00 = 0;
    data_021759d4->mUnk_04 = 0;
    data_021759d4->mUnk_08 = -3;
    data_021759d4->mUnk_10 = 0;
    data_021759d4->mUnk_14 = 0;
    data_021759d4->mUnk_28 = 0;
    data_021759d4->mUnk_30 = 0;
    data_021759d4->mUnk_40 = 0;
    data_021759d4->mUnk_48 = 0;
    data_021759d4->mUnk_58 = -1;
    data_021759d4->mUnk_5c = -1;
}

void func_0204ba2c(void *a) {
    data_021759d4 = func_02036bec(a, 0x70);
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        data_021759d4->mUnk_60 = func_02036b74(a, 0x2c00, 0x20);
        data_021759d4->mUnk_64 = func_02036b74(a, 1, 0x20);
    }
    data_021759d4->mUnk_0c = 0;
}

void func_0204ba7c(void) {
    data_021759d4->mUnk_00 = 0;
}

#pragma thumb off

void func_0204ba8c(void) {
    Unk021759b8 *t;
    t = (Unk021759b8 *) &data_usa_021759b8;
    if (func_0200e070(&t->mUnk_400) != 0) {
        return;
    }
    do {
        func_0200df68(&t->mUnk_400);
        func_0200e084(&t->mUnk_400);
    } while (func_0200e070(&t->mUnk_400) == 0);
}

void func_0204bad8(void) {
    Unk021759b8 *t;
    t = (Unk021759b8 *) &data_usa_021759b8;
    t->mUnk_4c4 = 0;
    t->mUnk_4c0 = t->mUnk_4c4;
    func_0200e28c(&t->mUnk_400, (void (*)(void *)) func_0204bb34, t, (u8 *) &t->mUnk_400, 0x400, 15);
    func_0200df68(&t->mUnk_400);
}

void func_0204bb34(void *a) {
    Unk02003a6c *o;
    Unk02175ec0 *g;
    Unk021762e0 *b;
    s32 i;
    Unk021762e0_46c8 *r;
    u32 s;
    u32 s2;
    s32 v1;
    u8 *q;
    o = func_020041e8(data_usa_021651d0, 3);
    g = (Unk02175ec0 *) &data_02175ec0;
    while (1) {
        s = func_0200fca0();
        b = (Unk021762e0 *) &data_usa_021762e0;
        r = b->mUnk_46c8;
        if (r == 0) {
            do {
                if (g->mUnk_000c == 0) {
                    func_0200fcb4(s);
                    return;
                }
                func_0200e01c(0);
                r = b->mUnk_46c8;
            } while (r == 0);
        }
        func_0200fcb4(s);
        if (r->mUnk_80 == 1) {
            func_02004afc(&r->mUnk_38, o, r->mUnk_90, r->mUnk_90 + r->mUnk_94, r->mUnk_8c);
            i = 0;
            v1 = 0;
            q = r->mUnk_c0[0];
            for (; i < 2; i++) {
                r->mUnk_a4[i] = v1;
                func_020048ac(&r->mUnk_38, q, 0x400);
                v1 += 0x400;
                q += 0x400;
            }
            r->mUnk_98 = 0;
            r->mUnk_a0 = 1;
            r->mUnk_9c = 2;
            s2 = func_0200fca0();
            func_0204d18c(&data_usa_021762e0, (Unk0204c090 *) r, 1);
            func_0200fcb4(s2);
        } else {
            func_020049e8(&r->mUnk_38);
            s2 = func_0200fca0();
            func_0204d0bc(&data_usa_021762e0, (Unk0204c090 *) r);
            func_0200fcb4(s2);
        }
    }
}
