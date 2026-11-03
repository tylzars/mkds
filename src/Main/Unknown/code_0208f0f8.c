#include "Main/Unknown/code_0208f0f8.h"
#include "Main/Unknown/code_020888b4.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_0207c000.h"
#include "Main/Unknown/code_0208537c.h"
#include "Main/Unknown/code_0208ecd8.h"
#include "Main/Unknown/code_0208ee40.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_020472a8.h"
#include "code_0201750c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_02166000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_020172d0.h"

// non-matching: same size; 29 words differ, all in the two blocks of constant stores: the original stores each
// constant right after loading it (8 in r1, 3 then 1 in r7, 0x4d then 0xe in r10) and loads &data_021759c0 after the
// first store, so the constants and pool addresses get other registers here
void func_0208f0f8(void *a) {
    void *s;
    Unk0208ec64 *e;
    Unk0208ec64_08 *f;
    u16 i;
    u16 n;
    u16 m;
    Unk020850c4 *q;
    s32 t;

    s = FindMainRaceOrMainEffectFile(data_021759c0->mUnk_00c == 5 ? data_02166514 : data_02166530);
    data_021663e0 = 8;
    data_021663f0 = 0x4d;
    data_021663dc = 3;
    data_021663e4 = 0xc;
    data_021663d8 = 0xe;
    data_021663e8 = 1;
    n = 1;
    data_021663ec = (s32(*)()) func_0208ee40;
    if (data_021759c0->mUnk_08 == 5) {
        n += 3;
    } else if (data_021759c0->mUnk_00c == 5) {
        data_021663e0 = 0xe;
        data_021663dc = 2;
        data_021663f0 = 0;
        data_021663e4 = 0x1e;
        data_021663ec = (s32(*)()) func_0208ecd8;
        data_021663d8 = 4;
        data_021663e8 = 0;
        n = 6;
    }
    m = data_021663e4 * n;
    if (data_021759c0->mUnk_08 == 4) {
        a = data_0217aa10->mUnk_a4;
    }
    data_0217b08c = func_02036bec(a, 0x38);
    e = func_02036bec(a, n * 0x30);
    f = func_02036bec(a, m * 0x1c);
    func_02017538(&data_0217b08c->mUnk_00[0], 0);
    func_02017538(&data_0217b08c->mUnk_00[1], 0);
    func_02017538(&data_0217b08c->mUnk_00[2], 0);
    for (i = 0; i < n; i++) {
        func_02017538(&e[i].mUnk_08, 0);
        func_020174a4(&data_0217b08c->mUnk_00[1], &e[i]);
    }
    for (i = 0; i < m; i++) {
        func_020174a4(&data_0217b08c->mUnk_00[2], &f[i]);
    }
    func_0208526c(&data_0217b08c->mUnk_24, s, s);
    q = data_0217b08c->mUnk_24.mUnk_0c;
    t = (q->mUnk_08 & 0xffff) << 3;
    data_021663f4.mUnk_00 = data_021663f4.mUnk_00 & 0xffff0000;
    data_021663f4.mUnk_00 = data_021663f4.mUnk_00 | (((u32) t >> 3) & 0xffff);
    data_021663f4.mUnk_18 = (q->mUnk_2c & 0xffff) << 3;
    data_021663f4.mUnk_1c = 0x10000;
    data_021663f4.mUnk_20 = 0x8000;
    data_0217b08c->mUnk_34 = data_021759c0->mUnk_00 == 0x1d ? 0 : 0x8000;
}

void func_0208f3d0(Unk0208fd8c *a, struct Unk020888b4 *b) {
    if (func_0207bfac(a) == 0) {
        if (b->mUnk_b0 == NULL) {
            return;
        }
        if (b->mUnk_b8 >= 0x15f90) {
            return;
        }
    }
    func_0207c47c(a, b);
}

void func_0208f434(Unk0208fd8c *a, struct Unk020888b4 *b) {
    a->mUnk_10 = 1;
    if (func_0207bfac(a) == 0) {
        return;
    }
    if (b->mUnk_b0 == NULL) {
        return;
    }
    if (b->mUnk_b8 >= 0x15f90) {
        return;
    }
    if (b->mUnk_b4 != 0) {
        if (b->mUnk_bc <= 0xb33) {
            return;
        }
        func_0207c47c(a, b);
    } else {
        func_0207c47c(a, b);
    }
}

void func_0208f4e8(Unk0208fd8c *a, struct Unk020888b4 *b) {
    Unk0217aebc_128 *r;
    s32 v;

    if (func_0207bfac(a) != 0) {
        r = func_0208537c();
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        v = (s16) (u16) (r->mUnk_00 >> 52);
        if (v > 0xb33) {
            func_0207c47c(a, b);
        } else {
            func_0207c548(a, b);
        }
    } else {
        if (b->mUnk_b0 == NULL) {
            return;
        }
        if (b->mUnk_b8 >= 0x15f90) {
            return;
        }
        func_0207c47c(a, b);
    }
}

void func_0208f5c4(Unk0208fd8c *a, struct Unk020888b4 *b) {
    if (func_0207bfac(a) == 0) {
        return;
    }
    if (b->mUnk_b0 == NULL) {
        return;
    }
    if (b->mUnk_b8 >= 0x15f90) {
        return;
    }
    if (b->mUnk_b4 != 0) {
        if (b->mUnk_bc <= 0xb33) {
            return;
        }
        func_0207c548(a, b);
    } else {
        func_0207c47c(a, b);
    }
}

void func_0208f670(Unk0208fd8c *a, struct Unk020888b4 *b) {
    if (data_027e00c8[b->mUnk_04].mUnk_058.mUnk_008 == 3) {
        data_0217b0ac(a, b);
    } else {
        data_0217b0a8(a, b);
    }
}

void func_0208f6d4(Unk0208fd8c *a, struct Unk020888b4 *b) {
    if (func_0207bfac(a) == 0) {
        return;
    }
    if (b->mUnk_b0 == NULL) {
        return;
    }
    if (b->mUnk_b8 >= 0x15f90) {
        return;
    }
    if (b->mUnk_b4 == 0) {
        return;
    }
    func_0207c614(a, b);
}

void func_0208f754(Unk0208fd8c *a, struct Unk020888b4 *b) {
    if (func_0207bfac(a) == 0) {
        return;
    }
    if (b->mUnk_b0 == NULL) {
        return;
    }
    if (b->mUnk_b8 >= 0x15f90) {
        return;
    }
    if (b->mUnk_b4 == 0) {
        return;
    }
    func_0207c614(a, b);
}

void func_0208f7d4(Unk0208fd8c *a, struct Unk020888b4 *b) {
    if (func_0207bfac(a) == 0) {
        return;
    }
    func_0207c614(a, b);
}

void func_0208f810(Unk0208fd8c *a, struct Unk020888b4 *b) {
    if (func_0207bfac(a) == 0) {
        return;
    }
    if (b->mUnk_b0 == NULL) {
        return;
    }
    if (b->mUnk_b8 >= 0x15f90) {
        return;
    }
    if (b->mUnk_b4 == 0) {
        return;
    }
    if (b->mUnk_bc <= 0x666) {
        return;
    }
    func_0207c614(a, b);
}

void func_0208f8ac(Unk0208fd8c *a, struct Unk020888b4 *b) {
    if (func_0207bfac(a) == 0) {
        return;
    }
    if (b->mUnk_b0 == NULL) {
        return;
    }
    if (b->mUnk_b8 >= 0x15f90) {
        return;
    }
    if (b->mUnk_b4 == 0) {
        return;
    }
    if (b->mUnk_bc <= 0x666) {
        return;
    }
    func_0207c614(a, b);
}

void func_0208f948(Unk0208fd8c *a, struct Unk020888b4 *b) {
    if (data_027e00c8[b->mUnk_04].mUnk_058.mUnk_008 == 4) {
        data_0217b090(a, b);
    } else {
        data_0217b094(a, b);
    }
}

void func_0208f9ac(Unk0208fd8c *a, struct Unk020888b4 *b) {
    Unk0217aebc_128 *r;
    s32 v;

    if (func_0207bfac(a) == 0) {
        return;
    }
    r = func_0208537c();
    r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
    v = (s16) (u16) (r->mUnk_00 >> 52);
    if (v < 0xb33) {
        func_0207c548(a, b);
    } else {
        func_0207c47c(a, b);
    }
}

void func_0208fa50(Unk0208fd8c *a, struct Unk020888b4 *b) {
    a->mUnk_10 = 1;
    if (func_0207bfac(a) == 0) {
        return;
    }
    if (b->mUnk_b0 == NULL) {
        return;
    }
    if (b->mUnk_b8 >= 0x15f90) {
        return;
    }
    if (b->mUnk_b4 != 0 && b->mUnk_bc > 0xb33) {
        func_0207c548(a, b);
    } else {
        func_0207c47c(a, b);
    }
}

void func_0208fafc(Unk0208fd8c *a, struct Unk020888b4 *b) {
    Unk0217aebc_128 *r;
    s32 v;

    if (func_0207bfac(a) == 0) {
        return;
    }
    r = func_0208537c();
    r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
    v = (s16) (u16) (r->mUnk_00 >> 52);
    if (v < 0xb33) {
        func_0207c548(a, b);
    } else {
        func_0207c47c(a, b);
    }
}

void func_0208fba0(Unk0208fd8c *a, struct Unk020888b4 *b) {
    Unk0217aebc_128 *r;
    s32 v;

    if (func_0207bfac(a) != 0) {
        r = func_0208537c();
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        v = (s16) (u16) (r->mUnk_00 >> 52);
        if (v < 0xb33) {
            func_0207c548(a, b);
        } else {
            func_0207c47c(a, b);
        }
    } else {
        if (b->mUnk_b0 == NULL) {
            return;
        }
        if (b->mUnk_b8 >= 0x15f90) {
            return;
        }
        if (b->mUnk_b4 != 0 && b->mUnk_bc > 0xb33) {
            func_0207c548(a, b);
        } else {
            func_0207c47c(a, b);
        }
    }
}

void func_0208fcac(Unk0208fd8c *a, struct Unk020888b4 *b) {
    if (b->mUnk_b0 == NULL) {
        return;
    }
    if (b->mUnk_b8 >= 0x15f90) {
        return;
    }
    if (b->mUnk_b4 != 0 && b->mUnk_bc > 0xb33) {
        func_0207c548(a, b);
    } else {
        func_0207c47c(a, b);
    }
}

void func_0208fd24(Unk0208fd8c *a, struct Unk020888b4 *b) {
    if (data_027e00c8[b->mUnk_04].mUnk_058.mUnk_008 == 4) {
        data_0217b0a0(a, b);
    } else {
        data_0217b098(a, b);
    }
}
