#include "Main/Unknown/code_0207cb74.h"
#include "Main/Unknown/code_02043000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0207e64c.h"
#include "Main/Unknown/code_0207e654.h"
#include "Main/Unknown/code_0207fe70.h"
#include "Main/Unknown/code_02061f7c.h"
#include "Main/Unknown/code_0208537c.h"
#include "Main/Unknown/code_020888b4.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"

void func_0207cb74(Unk0208fd8c *a, struct Unk020888b4 *b) {
    s32 t;
    Unk0217aebc_128 *r;
    u16 n;
    u32 v;

    t = 0;
    a->mUnk_00--;
    if (a->mUnk_00 <= 0) {
        a->mUnk_00 = 0;
        t = 1;
    }
    if (t == 0) {
        return;
    }
    if (b->mUnk_70 >= 0x14000) {
        return;
    }
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

void func_0207cc74(Unk0208fd8c *a, struct Unk020888b4 *b) {
    s32 t;
    Unk0217aebc_128 *r;
    u16 n;
    u32 v;

    t = 0;
    a->mUnk_00--;
    if (a->mUnk_00 <= 0) {
        a->mUnk_00 = 0;
        t = 1;
    }
    if (t == 0) {
        return;
    }
    if (b->mUnk_70 >= 0x14000) {
        return;
    }
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

void func_0207cd74(Unk0208fd8c *a, struct Unk020888b4 *b) {
    Unk0217aebc_128 *r;
    s32 k;
    u16 n;
    u32 v;

    k = func_0203c8dc(b->mUnk_04);
    if (k == 1) {
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
        return;
    } else if ((u32) k >= 2 && k <= data_021759c0->mUnk_3d0 - 1) {
        switch (a->mUnk_04->mUnk_04) {
            case 0:
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
                return;
            case 1:
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
                return;
            case 2:
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
                return;
            default:
                return;
        }
    } else {
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
        return;
    }
}
void func_0207d194(Unk0208fd8c *a, struct Unk020888b4 *b) {
    Unk0217aebc_128 *r;
    u16 n;
    u32 v;

    if (func_0207e654(b) != 0) {
        if (func_0207e64c(b) != 0) {
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
            return;
        } else {
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
            return;
        }
    } else {
        func_0207cd74(a, b);
    }
}
void func_0207d35c(Unk0208fd8c *a, struct Unk020888b4 *b) {
    s32 t;

    t = 0;
    a->mUnk_00--;
    if (a->mUnk_00 <= 0) {
        a->mUnk_00 = 0;
        t = 1;
    }
    if (t == 0) {
        return;
    }
    func_0207cd74(a, b);
}

void func_0207d3a4(Unk0208fd8c *a, struct Unk020888b4 *b) {
    s32 t;

    t = 0;
    a->mUnk_00--;
    if (a->mUnk_00 <= 0) {
        a->mUnk_00 = 0;
        t = 1;
    }
    if (t == 0) {
        return;
    }
    func_0207d194(a, b);
}

void func_0207d3ec(Unk0208fd8c *a, struct Unk020888b4 *b) {
    Unk021759c0 *d;
    u16 n;

    d = data_021759c0;
    n = b->mUnk_04;
    if ((d->mUnk_68[n].mUnk_08.mUnk_14 & 1) != 0) {
        if (a->mUnk_20 <= 0x400) {
            a->mUnk_10 = 1;
            return;
        }
    }
    {
        s32 t;

        t = 0;
        a->mUnk_00--;
        if (a->mUnk_00 <= 0) {
            a->mUnk_00 = 0;
            t = 1;
        }
        if (t == 0) {
            return;
        }
    }
    func_0207cd74(a, b);
}
void func_0207d474(Unk0208fd8c *a, struct Unk020888b4 *b) {
    Unk021759c0 *d;
    u16 n;

    d = data_021759c0;
    n = b->mUnk_04;
    if ((d->mUnk_68[n].mUnk_08.mUnk_14 & 1) != 0) {
        if (a->mUnk_20 <= 0xc00) {
            a->mUnk_10 = 1;
            return;
        }
    }
    func_0207d3a4(a, b);
}
void func_0207d4cc(Unk0208fd8c *a, struct Unk020888b4 *b) {
    s32 t;
    Unk0217aebc_128 *r;
    u16 n;
    u32 v;

    t = 0;
    a->mUnk_00--;
    if (a->mUnk_00 <= 0) {
        a->mUnk_00 = 0;
        t = 1;
    }
    if (t == 0) {
        return;
    }
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

void func_0207d5b8(Unk0208fd8c *a, struct Unk020888b4 *b) {
    s32 t;
    Unk0217aebc_128 *r;
    u16 n;
    u32 v;

    t = 0;
    a->mUnk_00--;
    if (a->mUnk_00 <= 0) {
        a->mUnk_00 = 0;
        t = 1;
    }
    if (t == 0) {
        return;
    }
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

void func_0207d6a4(struct Unk02089a24 *a, struct Unk020888b4 *b) {
    s32 m;
    s32 t;
    s32 v;
    s32 x;

    if (func_02061f90() == b->mUnk_04) {
        a->mUnk_08 = 0;
        v = b->mUnk_00->mUnk_cc;
        if (v > 0xa000) {
            v = 0xa000;
        }
        a->mUnk_0c = v;
        t = b->mUnk_70;
        if (t > 0x5000) {
            x = (s32) (((s64) (t - 0x5000) * 0x5b) >> 12);
            if (x > 0x1000) {
                x = 0x1000;
            }
            x = (s32) (((s64) x * 0x668) >> 12);
            a->mUnk_0c = (s32) (((s64) (0x1000 - x) * 0xa000) >> 12);
        }
        m = a->mUnk_0c;
        if (m < v) {
            v = m;
        }
        if (v > 0xa000) {
            v = 0xa000;
        }
        a->mUnk_04 = v;
    }
    if (b->mUnk_00->mUnk_180 != 0) {
        return;
    }
    if ((b->mUnk_00->mUnk_48 & 0x10000020) != 0) {
        return;
    }
    x = func_0207fe70((Unk02080b1c *) &b->mUnk_08.mUnk_00);
    b->mUnk_00->mUnk_cc = (s32) (((s64) a->mUnk_04 * x + 0x800) >> 12);
}
