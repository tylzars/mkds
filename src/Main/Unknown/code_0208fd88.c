#include "Main/Unknown/code_0208fd88.h"

#include "Main/Unknown/code_0208fd8c.h"
#include "Main/Unknown/code_020888b4.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_0207c000.h"
#include "Main/Unknown/code_0208537c.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_0208ffd8.h"
#include "Main/Unknown/code_0208ffe4.h"
#include "Main/Unknown/code_02090088.h"
#include "Main/Unknown/code_02090194.h"

void func_02090194(Unk02090194 *p0) {
    p0->mUnk_10 = (u32) 0x1u;
}

void func_02090088(Unk0208fd8c *a, Unk020888b4 *b) {
    Unk0217aebc_128 *r;
    s32 v;

    if (func_0207c078(a) != 0) {
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

void func_0208ffe4(Unk0208fd8c *a, Unk020888b4 *b) {
    Unk0217aebc_128 *r;
    s32 v;

    if (func_0207c078(a) == 0) {
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

void func_0208ffd8(Unk0208ffd8 *p0) {
    p0->mUnk_10 = (u32) 0x1u;
}

void func_0208fefc(Unk0208fd8c *a, struct Unk020888b4 *b) {
    Unk0217aebc_128 *r;
    s32 v;

    if (func_0207c078(a) != 0) {
        r = func_0208537c();
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        v = (s16) (u16) (r->mUnk_00 >> 52);
        if (v > 0xccd) {
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

void func_0208fe58(Unk0208fd8c *a, struct Unk020888b4 *b) {
    Unk0217aebc_128 *r;
    s32 v;

    if (func_0207c078(a) == 0) {
        return;
    }
    r = func_0208537c();
    r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
    v = (s16) (u16) (r->mUnk_00 >> 52);
    if (v > 0xccd) {
        func_0207c47c(a, b);
    } else {
        func_0207c548(a, b);
    }
}

void func_0208fe1c(Unk0208fd8c *a, struct Unk020888b4 *b) {
    if (func_0207c078(a) == 0) {
        return;
    }
    func_0207c614(a, b);
}

void func_0208fdcc(Unk0208fd8c *a, struct Unk020888b4 *b) {
    if (func_0207c078(a) == 0) {
        return;
    }
    if (b->mUnk_70 >= 0xa000) {
        return;
    }
    func_0207c6d0(a, b);
}

void func_0208fd8c(Unk0208fd8c *a, struct Unk020888b4 *b) {
    enum { K0 } k = (data_027e00c8)[b->mIndex].mUnk_058.mUnk_000;
    Unk0208fd8c_08 *t = &data_0217b0a4[k];

    a->mUnk_08 = t;
    func_0207bfd4(a, t);
}

u32 func_0208fd88(u32 p0) {
    return p0;
}
