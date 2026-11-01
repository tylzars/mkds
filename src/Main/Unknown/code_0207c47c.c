#include "Main/Unknown/code_0207c47c.h"
#include "Main/Unknown/code_0207cb74.h"
#include "Main/Unknown/code_02043000.h"
#include "Main/Unknown/code_0208537c.h"
#include "Main/Unknown/code_020888b4.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"

void func_0207cb0c(Unk0208fd8c *a, struct Unk020888b4 *b) {
    if ((data_027e00c8)[b->mUnk_04].mUnk_058.mUnk_008 == 4) {
        data_0217ae48(a, b);
    } else {
        data_0217ae44(a, b);
    }
}

void func_0207caa8(Unk0208fd8c *a, struct Unk020888b4 *b) {
    if ((data_027e00c8)[b->mUnk_04].mUnk_058.mUnk_008 == 3) {
        data_0217ae3c(a, b);
    } else {
        data_0217ae40(a, b);
    }
}

void func_0207ca60(Unk0208fd8c *a, struct Unk020888b4 *b) {
    s32 r;

    r = 0;
    a->mUnk_02--;
    if (a->mUnk_02 <= 0) {
        a->mUnk_02 = 0;
        r = 1;
    }
    if (r == 0) {
        return;
    }
    func_0207d194(a, b);
}

void func_0207ca18(Unk0208fd8c *a, struct Unk020888b4 *b) {
    s32 r;

    r = 0;
    a->mUnk_02--;
    if (a->mUnk_02 <= 0) {
        a->mUnk_02 = 0;
        r = 1;
    }
    if (r == 0) {
        return;
    }
    func_0207cd74(a, b);
}

void func_0207c978(Unk0208fd8c *a, struct Unk020888b4 *b) {
    Unk020ee684 *e;
    s32 t;
    s32 r;

    e = &(data_027e00c8)[b->mUnk_04];
    t = e->mUnk_030.mUnk_00;
    if (a->mUnk_10 != 0) {
        if (t != 0x13) {
            a->mUnk_0c = 1;
        }
        if (a->mUnk_0c == 0) {
            return;
        }
        r = 0;
        a->mUnk_02--;
        if (a->mUnk_02 <= 0) {
            a->mUnk_02 = 0;
            r = 1;
        }
        if (r == 0) {
            return;
        }
        func_0207d194(a, b);
    } else {
        func_0207d194(a, b);
    }
}

void func_0207c8d8(Unk0208fd8c *a, struct Unk020888b4 *b) {
    Unk020ee684 *e;
    s32 t;
    s32 r;

    e = &(data_027e00c8)[b->mUnk_04];
    t = e->mUnk_030.mUnk_00;
    if (a->mUnk_10 != 0) {
        if (t != 0x13) {
            a->mUnk_0c = 1;
        }
        if (a->mUnk_0c == 0) {
            return;
        }
        r = 0;
        a->mUnk_02--;
        if (a->mUnk_02 <= 0) {
            a->mUnk_02 = 0;
            r = 1;
        }
        if (r == 0) {
            return;
        }
        func_0207cd74(a, b);
    } else {
        func_0207cd74(a, b);
    }
}

void func_0207c78c(void) {
    switch (data_021759c0->mUnk_014) {
        case 1:
            data_0217ae38 = data_usa_021554a4;
            data_0217ae34 = data_usa_0215524c;
            data_0217ae48 = func_0207ca18;
            data_0217ae44 = func_0207c8d8;
            data_0217ae3c = func_0207ca18;
            data_0217ae40 = func_0207c8d8;
            break;
        case 2:
            data_0217ae38 = data_usa_021552f4;
            data_0217ae34 = data_usa_0215524c;
            data_0217ae48 = func_0207ca18;
            data_0217ae44 = func_0207c8d8;
            data_0217ae3c = func_0207ca18;
            data_0217ae40 = func_0207c8d8;
            break;
        case 3:
        default:
            data_0217ae38 = data_usa_021553cc;
            data_0217ae34 = data_usa_0215524c;
            data_0217ae48 = func_0207ca60;
            data_0217ae44 = func_0207c978;
            data_0217ae3c = func_0207ca60;
            data_0217ae40 = func_0207c978;
            break;
    }
}

void func_0207c6d0(Unk0208fd8c *a, struct Unk020888b4 *b) {
    Unk0217aebc_128 *r;
    u16 n;
    u32 v;

    func_0204360c(b->mUnk_00->mUnk_78, 0x600);
    a->mUnk_10 = 0;
    if (a->mUnk_04 == 0) {
        return;
    }
    n = a->mUnk_04->mUnk_0a;
    r = func_0208537c();
    if (n == 0) {
        v = 0;
    } else {
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        v = (n == 0) ? (u32) (r->mUnk_00 >> 32) : (u32) (((r->mUnk_00 >> 32) * (u32) n) >> 32);
    }
    a->mUnk_00 = a->mUnk_04->mUnk_08 + (u16) v;
}

void func_0207c614(Unk0208fd8c *a, struct Unk020888b4 *b) {
    Unk0217aebc_128 *r;
    u16 n;
    u32 v;

    func_0204360c(b->mUnk_00->mUnk_78, 0x600);
    a->mUnk_10 = 0;
    if (a->mUnk_08 == 0) {
        return;
    }
    n = a->mUnk_08->mUnk_0a;
    r = func_0208537c();
    if (n == 0) {
        v = 0;
    } else {
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        v = (n == 0) ? (u32) (r->mUnk_00 >> 32) : (u32) (((r->mUnk_00 >> 32) * (u32) n) >> 32);
    }
    a->mUnk_02 = a->mUnk_08->mUnk_08 + (u16) v;
}

void func_0207c548(Unk0208fd8c *a, struct Unk020888b4 *b) {
    Unk0217aebc_128 *r;
    u16 n;
    u32 v;

    func_0204360c(b->mUnk_00->mUnk_78, 0x600);
    a->mUnk_14 = 1;
    a->mUnk_1c = 2;
    a->mUnk_10 = 0;
    if (a->mUnk_08 == 0) {
        return;
    }
    n = a->mUnk_08->mUnk_0a;
    r = func_0208537c();
    if (n == 0) {
        v = 0;
    } else {
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        v = (n == 0) ? (u32) (r->mUnk_00 >> 32) : (u32) (((r->mUnk_00 >> 32) * (u32) n) >> 32);
    }
    a->mUnk_02 = a->mUnk_08->mUnk_08 + (u16) v;
}

void func_0207c47c(Unk0208fd8c *a, struct Unk020888b4 *b) {
    Unk0217aebc_128 *r;
    u16 n;
    u32 v;

    func_0204360c(b->mUnk_00->mUnk_78, 0x600);
    a->mUnk_18 = 1;
    a->mUnk_1e = 2;
    a->mUnk_10 = 0;
    if (a->mUnk_08 == 0) {
        return;
    }
    n = a->mUnk_08->mUnk_0a;
    r = func_0208537c();
    if (n == 0) {
        v = 0;
    } else {
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        v = (n == 0) ? (u32) (r->mUnk_00 >> 32) : (u32) (((r->mUnk_00 >> 32) * (u32) n) >> 32);
    }
    a->mUnk_02 = a->mUnk_08->mUnk_08 + (u16) v;
}
