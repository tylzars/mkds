#include "Main/Unknown/code_020483e4.h"
#include "Main/Unknown/code_02048000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217a000.h"

#include "code_0200d118.h"
#include "code_02004270.h"
#include "code_02004dc0.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_02004d80.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_020487a0.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_02175000.h"

#pragma thumb on

void func_020486d4(void *a) {
    s32 i;

    data_021759c8 = func_02036bec(a, 0xa84);
    data_021759c8->mUnk_8c8.mUnk_88 = func_02036b74(a, 0x400, 0x20);
    for (i = 0; i < 20; i++) {
        data_021759c8->mUnk_00[i].mUnk_68 = 0;
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        data_021759c8->mUnk_8c0 = func_02004dfc(0, 0);
        data_021759c8->mUnk_8c4 = func_02036bec(a, data_021759c8->mUnk_8c0);
        func_02004dfc((u32) data_021759c8->mUnk_8c4, data_021759c8->mUnk_8c0);
    }
    for (i = 0; i < 16; i++) {
        func_020487a0(i);
    }
    data_021759c8->mUnk_a70 = 0;
    data_021759c8->mUnk_a78 = 0;
    data_021759c8->mUnk_a7c = 0;
    func_02004d80(&data_021759c8->mUnk_968);
}

int func_02048684(const char *param_1, void *param_2, u32 param_3) {
    Unk02003024 f;
    u32 r;
    u32 n;

    func_02004d80(&f);
    r = func_02004a30(&f, (const u8 *) param_1);
    if (r != 0) {
        n = f.mUnk_20.p.mUnk_08 - f.mUnk_20.p.mUnk_04;
        if (param_3 != 0 && n > param_3) {
            r = 0;
        } else {
            if (func_020048ac(&f, param_2, n) < 0) {
                r = 0;
            }
            func_020049e8(&f);
        }
    }
    return r;
}

u32 func_0204863c(void *a, void *b, u32 c) {
    Unk02003024 f;
    u32 r;

    func_02004d80(&f);
    r = func_02004a30(&f, a);
    if (r != 0) {
        if (c <= (u32) (f.mUnk_20.p.mUnk_08 - f.mUnk_20.p.mUnk_04)) {
            if (func_020048ac(&f, b, c) < 0) {
                r = 0;
            }
            func_020049e8(&f);
        }
    }
    return r;
}

u32 func_02048590(char *param_1, u32 param_2, void **param_3) {
    u32 s;
    Unk02003024 *p;
    u32 n;
    void *t;

    p = &data_021759c8->mUnk_968;
    if (((p->mUnk_0c & 1) ? 1 : 0) != 0) {
        return 0;
    }
    if (((p->mUnk_0c & 0x10) ? 1 : 0) != 0) {
        func_020049e8(p);
    }
    s = func_02004a30(p, (const u8 *) param_1);
    if (s != 0) {
        n = p->mUnk_20.p.mUnk_08 - p->mUnk_20.p.mUnk_04;
        t = func_02036bec((void *) param_2, n);
        *param_3 = t;
        if (t == 0) {
            s = 0;
        }
        if (s != 0) {
            if (func_020048ac(p, t, n) < 0) {
                s = 0;
                func_02036b30((void *) param_2, t);
            }
        }
        func_020049e8(p);
    }
    if (s == 0) {
        n = -1;
        *param_3 = 0;
    }
    return n;
}

void *func_02048504(const char *a, s32 b) {
    Unk02003024 f;
    u32 s;
    void *r;
    u32 n;

    r = 0;
    if (func_02004db0() == 0) {
        return 0;
    }
    func_02004d80(&f);
    s = func_02004a30(&f, (const u8 *) a);
    if (s != 0) {
        n = f.mUnk_20.p.mUnk_08 - f.mUnk_20.p.mUnk_04;
        r = func_02036b74(func_020364e0(func_020364e8()), n, b);
        func_0200ee58(r, n);
        if (r == 0) {
            s = 0;
        } else {
            if (func_020048ac(&f, r, n) < 0) {
                func_02036b30(func_020364e0(func_020364e8()), r);
                s = 0;
            }
            func_020049e8(&f);
        }
    }
    if (s == 0) {
        r = 0;
    }
    return r;
}

void func_02048498(char *a, s32 b, s32 c) {
    s32 d;
    const char *e;
    const char *f;

    d = 0;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2 && data_usa_02154228[b].mUnk_04 == 1) {
        d = 1;
    }
    if (c != 0) {
        e = data_usa_02165164;
    } else {
        e = data_usa_02165168;
    }
    if (d != 0) {
        f = data_usa_0216516c;
    } else {
        f = data_usa_02165170;
    }
    func_0200d9e0(a, 0x80, data_usa_02165174, data_usa_02154228[b].mUnk_00, f, e);
}

u32 func_02048474(void) {
    s32 a;

    a = data_021759d0->mUnk_04;
    if (data_021759d0->mUnk_00 == 2 && a == 1) {
        a += 5;
    }
    return ((u32 *) data_02164dc8)[a];
}

#pragma thumb off

#pragma thumb on

u32 func_02048440(void) {
    u32 v1;
    v1 = (int) data_0217aa00->mUnk_043c;
    if ((data_021759d0->mUnk_00 == 2) && (((int *) (u32) data_021759d0)[1] == 1)) {
        v1 = v1 + 5;
    }
    return ((u32 *) &data_02164dc8)[v1];
}

void func_0204840c(u32 param_1, u8 *param_2) {
    u32 v1;
    if (*param_2 != 0) {
        v1 = func_02048474();
        func_0200d9e0((char *) param_1, 0x80, (const char *) data_02165148, param_2, v1, (u32) &data_0216515c);
    }
}

void func_020483e4(u32 param_1, u8 *param_2) {
    if (*param_2 != 0) {
        func_0200d9e0((char *) param_1, 0x80, (const char *) data_0216512c, param_2, (u32) &data_02165140);
    }
}

#pragma thumb off
