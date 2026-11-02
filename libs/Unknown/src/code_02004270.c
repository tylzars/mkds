#include "code_02004270.h"
#include "code_02003024.h"
#include "code_02003be0.h"
#include "code_02004d80.h"
#include "code_0200dc3c.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_0214d000.h"

u32 func_02004c20(Unk02003024 *p, const u8 *path, void *out, void *flag) {
    Unk02003024U loc;
    s32 i;
    Unk02003a6c *q;
    s32 t;

    if (path[0] == '/' || path[0] == '\\') {
        loc.h.mUnk_00 = data_0216f344.h.mUnk_00;
        loc.h.mUnk_04 = 0;
        loc.h.mUnk_08 = 0;
        loc.h.mUnk_06 = 0;
        path++;
    } else {
        loc = data_0216f344;
        for (i = 0; i <= 3; i++) {
            if (path[i] == 0 || path[i] == '/' || path[i] == '\\') {
                break;
            }
            if (path[i] == ':') {
                q = func_020041e8(path, i);
                if (q == 0) {
                    return 0;
                }
                if (q->mUnk_1c & 2) {
                    t = 1;
                } else {
                    t = 0;
                }
                if (t == 0) {
                    return 0;
                }
                loc.h.mUnk_00 = q;
                loc.h.mUnk_08 = 0;
                loc.h.mUnk_06 = 0;
                loc.h.mUnk_04 = 0;
                path += i + 1;
                if (*path == '/' || *path == '\\') {
                    path++;
                }
                break;
            }
        }
    }
    p->mUnk_08 = loc.h.mUnk_00;
    p->mUnk_3c = path;
    p->mUnk_30 = loc;
    if (flag != 0) {
        p->mUnk_40 = 1;
        p->mUnk_44 = flag;
    } else {
        p->mUnk_40 = 0;
        p->mUnk_44 = out;
    }
    return func_02004270(p, 4);
}

s32 func_02004b98(Unk02003024 *p, void *buf, s32 n, u32 flag) {
    s32 pos;
    s32 m;

    pos = p->mUnk_2c;
    m = n;
    if (n > p->mUnk_20.p.mUnk_08 - pos) {
        n = p->mUnk_20.p.mUnk_08 - pos;
    }
    if (n < 0) {
        n = 0;
    }
    p->mUnk_30.p.mUnk_00 = buf;
    p->mUnk_30.p.mUnk_04 = m;
    p->mUnk_30.p.mUnk_08 = n;
    if (flag == 0) {
        p->mUnk_0c |= 4;
    }
    func_02004270(p, 0);
    if (flag == 0) {
        if (func_02004918(p) != 0) {
            n = p->mUnk_2c - pos;
        } else {
            n = -1;
        }
    }
    return n;
}

u32 func_02004b54(Unk02005814 *out, const u8 *path) {
    Unk02003024 o;

    func_02004d80(&o);
    return func_02004c20(&o, path, out, 0) != 0;
}

u32 func_02004afc(Unk02003024 *p, Unk02003a6c *owner, u32 a, u32 b, u32 c) {
    p->mUnk_08 = owner;
    p->mUnk_30.w.mUnk_08 = c;
    p->mUnk_30.w.mUnk_00 = a;
    p->mUnk_30.w.mUnk_04 = b;
    if (func_02004270(p, 7) == 0) {
        return 0;
    }
    p->mUnk_0c |= 0x10;
    p->mUnk_0c &= ~0x20;
    return 1;
}

u32 func_02004a80(Unk02003024 *p, Unk02005814 s) {
    if (s.mUnk_00 == 0) {
        return 0;
    }
    p->mUnk_08 = s.mUnk_00;
    p->mUnk_30.d.mUnk_00 = s;
    if (func_02004270(p, 6) == 0) {
        return 0;
    }
    p->mUnk_0c |= 0x10;
    p->mUnk_0c &= ~0x20;
    return 1;
}

u32 func_02004a30(Unk02003024 *p, const u8 *path) {
    Unk02005814 s;

    if (func_02004b54(&s, path) != 0) {
        if (func_02004a80(p, s) != 0) {
            return 1;
        }
    }
    return 0;
}

u32 func_020049e8(Unk02003024 *p) {
    if (func_02004270(p, 8) == 0) {
        return 0;
    }
    p->mUnk_08 = 0;
    p->mUnk_10 = 0xe;
    p->mUnk_0c &= ~0x30;
    return 1;
}

u32 func_02004918(Unk02003024 *p0) {
    u32 r;
    u32 state;

    r = 0;
    state = func_0200fca0();
    if (((p0->mUnk_0c & 1) ? 1 : 0) != 0) {
        r = (p0->mUnk_0c & 0x44) == 0;
        if (r) {
            p0->mUnk_0c |= 4;
            do {
                func_0200e01c(&p0->mUnk_18);
            } while ((p0->mUnk_0c & 0x40) == 0);
        } else {
            do {
                func_0200e01c(&p0->mUnk_18);
            } while (((p0->mUnk_0c & 1) ? 1 : 0) != 0);
        }
    }
    func_0200fcb4(state);
    if (r) {
        return func_0200442c(p0);
    }
    return p0->mUnk_14 == 0;
}

void func_020048cc(Unk02003024 *p0) {
    u32 state;

    state = func_0200fca0();
    if (((p0->mUnk_0c & 1) ? 1 : 0) != 0) {
        p0->mUnk_0c |= 2;
        p0->mUnk_08->mUnk_1c |= 0x20;
    }
    func_0200fcb4(state);
}

s32 func_020048bc(Unk02003024 *p0, void *p1, s32 p2) {
    return func_02004b98(p0, p1, p2, 1);
}

s32 func_020048ac(Unk02003024 *p0, void *p1, s32 p2) {
    return func_02004b98(p0, p1, p2, 0);
}

u32 func_02004840(Unk02003024 *p0, s32 p1, u32 p2) {
    switch (p2) {
        case 0:
            p1 += p0->mUnk_20.p.mUnk_04;
            break;
        case 1:
            p1 += p0->mUnk_2c;
            break;
        case 2:
            p1 += p0->mUnk_20.p.mUnk_08;
            break;
        default:
            return 0;
    }
    if (p1 < p0->mUnk_20.p.mUnk_04) {
        p1 = p0->mUnk_20.p.mUnk_04;
    }
    if (p1 > p0->mUnk_20.p.mUnk_08) {
        p1 = p0->mUnk_20.p.mUnk_08;
    }
    p0->mUnk_2c = p1;
    return 1;
}

u32 func_020047ec(const u8 *p0) {
    Unk02003024U pos;
    Unk02003024 b;

    func_02004d80(&b);
    if (func_02004c20(&b, p0, 0, &pos) == 0) {
        return 0;
    }
    data_0216f344 = pos;
    return 1;
}

u32 func_02004788(const u8 *p0, s32 p1) {
    u32 v;
    u32 x;
    int i;

    v = 0;
    if (p1 <= 3) {
        for (i = 0; i < p1; i++) {
            if (p0[i] == 0) {
                break;
            }
            x = p0[i] - 0x41;
            v |= ((x <= 0x19) ? x + 0x61 : x + 0x41) << (i * 8);
        }
    }
    return v;
}

s32 func_02004760(Unk02003a6c *p0, void *p1, u32 p2, u32 p3) {
    func_0214d1fc(p0->mUnk_28 + p2, p1, p3);
    return 0;
}

s32 func_02004734(Unk02003a6c *p0, void *p1, u32 p2, u32 p3) {
    func_0214d1fc(p1, p0->mUnk_28 + p2, p3);
    return 0;
}

s32 func_02004710(Unk02003a6c *p0, void *p1, u32 p2, u32 p3) {
    func_0214d1fc((const void *) p2, p1, p3);
    return 0;
}

Unk02003024 *func_02004518(Unk02003a6c *p0) {
    Unk02003024 b;
    Unk02003024 *p;
    Unk02003024 *n;
    u32 state;
    u32 r;

    state = func_0200fca0();
    if (p0->mUnk_1c & 0x20) {
        p0->mUnk_1c &= ~0x20;
        p = p0->mUnk_24;
        if (p != 0) {
            do {
                n = p->mUnk_04;
                if (((p->mUnk_0c & 2) ? 1 : 0) != 0) {
                    if (p0->mUnk_24 == p) {
                        p0->mUnk_24 = n;
                    }
                    FileFinishCommand(p, 3);
                    if (n == 0) {
                        n = p0->mUnk_24;
                    }
                }
                p = n;
            } while (n != 0);
        }
    }
    if (!(p0->mUnk_1c & 0x40) && ((p0->mUnk_1c & 8) ? 1 : 0) == 0 && (p = p0->mUnk_24) != 0) {
        r = ((p0->mUnk_1c & 0x10) ? 1 : 0) == 0;
        if (r != 0) {
            p0->mUnk_1c |= 0x10;
        }
        func_0200fcb4(state);
        if (r != 0 && (p0->mUnk_58 & 0x200)) {
            p0->mUnk_54(p, 9);
        }
        state = func_0200fca0();
        p->mUnk_0c |= 0x40;
        if (((p->mUnk_0c & 4) ? 1 : 0) != 0) {
            func_0200df9c(&p->mUnk_18);
            func_0200fcb4(state);
            return 0;
        }
        func_0200fcb4(state);
        return p;
    }
    if (p0->mUnk_1c & 0x10) {
        p0->mUnk_1c &= ~0x10;
        if (p0->mUnk_58 & 0x400) {
            func_02004d80(&b);
            b.mUnk_08 = p0;
            p0->mUnk_54(&b, 10);
        }
    }
    if (p0->mUnk_1c & 0x40) {
        p0->mUnk_1c &= ~0x40;
        p0->mUnk_1c |= 8;
        func_0200df9c(&p0->mUnk_14);
    }
    func_0200fcb4(state);
    return 0;
}

void func_02004474(Unk02003024 *p0) {
    Unk02003a6c *a;
    u32 state;

    a = p0->mUnk_08;
    if (p0 == 0) {
        return;
    }
    do {
        state = func_0200fca0();
        p0->mUnk_0c |= 0x40;
        if (((p0->mUnk_0c & 4) ? 1 : 0) != 0) {
            func_0200df9c(&p0->mUnk_18);
            func_0200fcb4(state);
            return;
        }
        p0->mUnk_0c |= 8;
        func_0200fcb4(state);
        if (FileDispatchCommand(p0, p0->mUnk_10) == 6) {
            return;
        }
        p0 = func_02004518(a);
    } while (p0 != 0);
}

u32 func_0200442c(Unk02003024 *p0) {
    Unk02003024 *p;

    FileFinishCommand(p0, FileDispatchCommand(p0, p0->mUnk_10));
    p = func_02004518(p0->mUnk_08);
    if (p != 0) {
        func_02004474(p);
    }
    return p0->mUnk_14 == 0;
}

u32 func_02004270(Unk02003024 *p0, u32 p1) {
    Unk02003a6c *a;
    Unk02003024 *s;
    Unk02003024 *q;
    u32 m;
    Unk02003024 *r;
    u32 state;

    a = p0->mUnk_08;
    p0->mUnk_10 = p1;
    m = 1 << p1;
    p0->mUnk_14 = 2;
    p0->mUnk_0c |= 1;
    state = func_0200fca0();
    if (a->mUnk_1c & 0x80) {
        FileFinishCommand(p0, 3);
        func_0200fcb4(state);
        return 0;
    }
    if (m & 0x1fc) {
        p0->mUnk_0c |= 4;
    }
    q = p0->mUnk_00;
    s = (Unk02003024 *) &a->mUnk_20;
    r = p0->mUnk_04;
    if (q != 0) {
        q->mUnk_04 = r;
    }
    if (r != 0) {
        r->mUnk_00 = q;
    }
    while (s->mUnk_04 != 0) {
        s = s->mUnk_04;
    }
    s->mUnk_04 = p0;
    p0->mUnk_00 = s;
    p0->mUnk_04 = 0;
    if (((a->mUnk_1c & 8) ? 1 : 0) == 0 && (a->mUnk_1c & 0x10) == 0) {
        a->mUnk_1c |= 0x10;
        func_0200fcb4(state);
        if (a->mUnk_58 & 0x200) {
            a->mUnk_54(p0, 9);
        }
        state = func_0200fca0();
        p0->mUnk_0c |= 0x40;
        if (((p0->mUnk_0c & 4) ? 1 : 0) == 0) {
            func_0200fcb4(state);
            func_02004474(p0);
            return 1;
        }
        func_0200fcb4(state);
    } else {
        if (((p0->mUnk_0c & 4) ? 1 : 0) == 0) {
            func_0200fcb4(state);
            return 1;
        }
        do {
            func_0200e01c(&p0->mUnk_18);
        } while ((p0->mUnk_0c & 0x40) == 0);
        func_0200fcb4(state);
    }
    return func_0200442c(p0);
}
