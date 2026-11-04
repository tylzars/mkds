#include "Main/Unknown/code_0207b960.h"

#include "Main/Unknown/code_020435c4.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_02043000.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0208537c.h"
#include "Main/Unknown/code_020888b4.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_0207e64c.h"
#include "Main/Unknown/code_0207e654.h"
#include "Main/Unknown/code_0207fe70.h"

void func_0207d6a4(struct Unk02089a24 *a, struct Unk020888b4 *b) {
    s32 m;
    s32 t;
    s32 v;
    s32 x;

    if (func_02061f90() == b->mIndex) {
        a->mUnk_08 = 0;
        v = b->mKart->mUnk_cc;
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
    if (b->mKart->mState != 0) {
        return;
    }
    if ((b->mKart->mUnk_48 & 0x10000020) != 0) {
        return;
    }
    x = func_0207fe70((Unk02080b1c *) &b->mUnk_08.mUnk_00);
    b->mKart->mUnk_cc = (s32) (((s64) a->mUnk_04 * x + 0x800) >> 12);
}

void func_0207d5b8(Unk0208fd8c *a, struct Unk020888b4 *b) {
    BOOL t;
    Unk0217aebc_128 *r;
    u16 n;
    u32 v;

    t = FALSE;
    a->mUnk_00--;
    if (a->mUnk_00 <= 0) {
        a->mUnk_00 = 0;
        t = TRUE;
    }
    if (t == FALSE) {
        return;
    }
    func_0204360c(b->mKart->mUnk_78, 0x600);
    a->mUnk_10 = 0;
    if (a->mUnk_08 == NULL) {
        return;
    }
    n = a->mUnk_08->mTimerRandomLimit;
    r = func_0208537c();
    if (n == 0) {
        v = 0;
    } else {
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        v = (n == 0) ? (u32) (r->mUnk_00 >> 32) : (u32) (((r->mUnk_00 >> 32) * (u32) n) >> 32);
    }
    a->mUnk_02 = a->mUnk_08->mTimerBase + (u16) v;
}

void func_0207d4cc(Unk0208fd8c *a, struct Unk020888b4 *b) {
    BOOL t;
    Unk0217aebc_128 *r;
    u16 n;
    u32 v;

    t = FALSE;
    a->mUnk_00--;
    if (a->mUnk_00 <= 0) {
        a->mUnk_00 = 0;
        t = TRUE;
    }
    if (t == FALSE) {
        return;
    }
    func_0204360c(b->mKart->mUnk_78, 0x600);
    a->mUnk_10 = 0;
    if (a->mUnk_08 == NULL) {
        return;
    }
    n = a->mUnk_08->mTimerRandomLimit;
    r = func_0208537c();
    if (n == 0) {
        v = 0;
    } else {
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        v = (n == 0) ? (u32) (r->mUnk_00 >> 32) : (u32) (((r->mUnk_00 >> 32) * (u32) n) >> 32);
    }
    a->mUnk_02 = a->mUnk_08->mTimerBase + (u16) v;
}
void func_0207d474(Unk0208fd8c *a, struct Unk020888b4 *b) {
    Unk021759c0 *d;
    u16 n;

    d = data_021759c0;
    n = b->mIndex;
    if ((d->mCurrentEntries[n].mUnk_08.mUnk_14 & 1) != 0) {
        if (a->mUnk_20 <= 0xc00) {
            a->mUnk_10 = 1;
            return;
        }
    }
    func_0207d3a4(a, b);
}
void func_0207d3ec(Unk0208fd8c *a, struct Unk020888b4 *b) {
    Unk021759c0 *d;
    u16 n;

    d = data_021759c0;
    n = b->mIndex;
    if ((d->mCurrentEntries[n].mUnk_08.mUnk_14 & 1) != 0) {
        if (a->mUnk_20 <= 0x400) {
            a->mUnk_10 = 1;
            return;
        }
    }
    {
        BOOL t;

        t = FALSE;
        a->mUnk_00--;
        if (a->mUnk_00 <= 0) {
            a->mUnk_00 = 0;
            t = TRUE;
        }
        if (t == FALSE) {
            return;
        }
    }
    func_0207cd74(a, b);
}

void func_0207d3a4(Unk0208fd8c *a, struct Unk020888b4 *b) {
    BOOL t;

    t = FALSE;
    a->mUnk_00--;
    if (a->mUnk_00 <= 0) {
        a->mUnk_00 = 0;
        t = TRUE;
    }
    if (t == FALSE) {
        return;
    }
    func_0207d194(a, b);
}

void func_0207d35c(Unk0208fd8c *a, struct Unk020888b4 *b) {
    BOOL t;

    t = FALSE;
    a->mUnk_00--;
    if (a->mUnk_00 <= 0) {
        a->mUnk_00 = 0;
        t = TRUE;
    }
    if (t == FALSE) {
        return;
    }
    func_0207cd74(a, b);
}
void func_0207d194(Unk0208fd8c *a, struct Unk020888b4 *b) {
    Unk0217aebc_128 *r;
    u16 n;
    u32 v;

    if (func_0207e654(b) != 0) {
        if (func_0207e64c(b) != 0) {
            func_0204360c(b->mKart->mUnk_78, 0x600);
            a->mUnk_14 = 1;
            a->mUnk_1c = 2;
            a->mUnk_10 = 0;
            if (a->mUnk_08 == NULL) {
                return;
            }
            n = a->mUnk_08->mTimerRandomLimit;
            r = func_0208537c();
            if (n == 0) {
                v = 0;
            } else {
                r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
                v = (n == 0) ? (u32) (r->mUnk_00 >> 32) : (u32) (((r->mUnk_00 >> 32) * (u32) n) >> 32);
            }
            a->mUnk_02 = a->mUnk_08->mTimerBase + (u16) v;
            return;
        } else {
            func_0204360c(b->mKart->mUnk_78, 0x600);
            a->mUnk_18 = 1;
            a->mUnk_1e = 2;
            a->mUnk_10 = 0;
            if (a->mUnk_08 == NULL) {
                return;
            }
            n = a->mUnk_08->mTimerRandomLimit;
            r = func_0208537c();
            if (n == 0) {
                v = 0;
            } else {
                r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
                v = (n == 0) ? (u32) (r->mUnk_00 >> 32) : (u32) (((r->mUnk_00 >> 32) * (u32) n) >> 32);
            }
            a->mUnk_02 = a->mUnk_08->mTimerBase + (u16) v;
            return;
        }
    } else {
        func_0207cd74(a, b);
    }
}
void func_0207cd74(Unk0208fd8c *a, struct Unk020888b4 *b) {
    Unk0217aebc_128 *r;
    s32 k;
    u16 n;
    u32 v;

    k = func_0203c8dc(b->mIndex);
    if (k == 1) {
        func_0204360c(b->mKart->mUnk_78, 0x600);
        a->mUnk_18 = 1;
        a->mUnk_1e = 2;
        a->mUnk_10 = 0;
        if (a->mUnk_08 == NULL) {
            return;
        }
        n = a->mUnk_08->mTimerRandomLimit;
        r = func_0208537c();
        if (n == 0) {
            v = 0;
        } else {
            r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
            v = (n == 0) ? (u32) (r->mUnk_00 >> 32) : (u32) (((r->mUnk_00 >> 32) * (u32) n) >> 32);
        }
        a->mUnk_02 = a->mUnk_08->mTimerBase + (u16) v;
        return;
    } else if ((u32) k >= 2 && k <= data_021759c0->mKartCount - 1) {
        switch (a->mUnk_04->mUnk_04) {
            case 0:
                func_0204360c(b->mKart->mUnk_78, 0x600);
                a->mUnk_10 = 0;
                if (a->mUnk_08 == NULL) {
                    return;
                }
                n = a->mUnk_08->mTimerRandomLimit;
                r = func_0208537c();
                if (n == 0) {
                    v = 0;
                } else {
                    r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
                    v = (n == 0) ? (u32) (r->mUnk_00 >> 32) : (u32) (((r->mUnk_00 >> 32) * (u32) n) >> 32);
                }
                a->mUnk_02 = a->mUnk_08->mTimerBase + (u16) v;
                return;
            case 1:
                func_0204360c(b->mKart->mUnk_78, 0x600);
                a->mUnk_14 = 1;
                a->mUnk_1c = 2;
                a->mUnk_10 = 0;
                if (a->mUnk_08 == NULL) {
                    return;
                }
                n = a->mUnk_08->mTimerRandomLimit;
                r = func_0208537c();
                if (n == 0) {
                    v = 0;
                } else {
                    r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
                    v = (n == 0) ? (u32) (r->mUnk_00 >> 32) : (u32) (((r->mUnk_00 >> 32) * (u32) n) >> 32);
                }
                a->mUnk_02 = a->mUnk_08->mTimerBase + (u16) v;
                return;
            case 2:
                func_0204360c(b->mKart->mUnk_78, 0x600);
                a->mUnk_18 = 1;
                a->mUnk_1e = 2;
                a->mUnk_10 = 0;
                if (a->mUnk_08 == NULL) {
                    return;
                }
                n = a->mUnk_08->mTimerRandomLimit;
                r = func_0208537c();
                if (n == 0) {
                    v = 0;
                } else {
                    r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
                    v = (n == 0) ? (u32) (r->mUnk_00 >> 32) : (u32) (((r->mUnk_00 >> 32) * (u32) n) >> 32);
                }
                a->mUnk_02 = a->mUnk_08->mTimerBase + (u16) v;
                return;
            default:
                return;
        }
    } else {
        func_0204360c(b->mKart->mUnk_78, 0x600);
        a->mUnk_14 = 1;
        a->mUnk_1c = 2;
        a->mUnk_10 = 0;
        if (a->mUnk_08 == NULL) {
            return;
        }
        n = a->mUnk_08->mTimerRandomLimit;
        r = func_0208537c();
        if (n == 0) {
            v = 0;
        } else {
            r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
            v = (n == 0) ? (u32) (r->mUnk_00 >> 32) : (u32) (((r->mUnk_00 >> 32) * (u32) n) >> 32);
        }
        a->mUnk_02 = a->mUnk_08->mTimerBase + (u16) v;
        return;
    }
}

void func_0207cc74(Unk0208fd8c *a, struct Unk020888b4 *b) {
    BOOL t;
    Unk0217aebc_128 *r;
    u16 n;
    u32 v;

    t = FALSE;
    a->mUnk_00--;
    if (a->mUnk_00 <= 0) {
        a->mUnk_00 = 0;
        t = TRUE;
    }
    if (t == FALSE) {
        return;
    }
    if (b->mUnk_70 >= 0x14000) {
        return;
    }
    func_0204360c(b->mKart->mUnk_78, 0x600);
    a->mUnk_10 = 0;
    if (a->mUnk_08 == NULL) {
        return;
    }
    n = a->mUnk_08->mTimerRandomLimit;
    r = func_0208537c();
    if (n == 0) {
        v = 0;
    } else {
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        v = (n == 0) ? (u32) (r->mUnk_00 >> 32) : (u32) (((r->mUnk_00 >> 32) * (u32) n) >> 32);
    }
    a->mUnk_02 = a->mUnk_08->mTimerBase + (u16) v;
}

void func_0207cb74(Unk0208fd8c *a, struct Unk020888b4 *b) {
    BOOL t;
    Unk0217aebc_128 *r;
    u16 n;
    u32 v;

    t = FALSE;
    a->mUnk_00--;
    if (a->mUnk_00 <= 0) {
        a->mUnk_00 = 0;
        t = TRUE;
    }
    if (t == FALSE) {
        return;
    }
    if (b->mUnk_70 >= 0x14000) {
        return;
    }
    func_0204360c(b->mKart->mUnk_78, 0x600);
    a->mUnk_10 = 0;
    if (a->mUnk_04 == NULL) {
        return;
    }
    n = a->mUnk_04->mTimerRandomLimit;
    r = func_0208537c();
    if (n == 0) {
        v = 0;
    } else {
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        v = (n == 0) ? (u32) (r->mUnk_00 >> 32) : (u32) (((r->mUnk_00 >> 32) * (u32) n) >> 32);
    }
    a->mUnk_00 = a->mUnk_04->mTimerBase + (u16) v;
}

u32 func_0207cb70(u32 p0) {
    return p0;
}

void func_0207cb0c(Unk0208fd8c *a, struct Unk020888b4 *b) {
    if ((data_027e00c8)[b->mIndex].mUnk_058.mUnk_008 == 4) {
        data_0217ae48(a, b);
    } else {
        data_0217ae44(a, b);
    }
}

void func_0207caa8(Unk0208fd8c *a, struct Unk020888b4 *b) {
    if ((data_027e00c8)[b->mIndex].mUnk_058.mUnk_008 == 3) {
        data_0217ae3c(a, b);
    } else {
        data_0217ae40(a, b);
    }
}

void func_0207ca60(Unk0208fd8c *a, struct Unk020888b4 *b) {
    BOOL r;

    r = FALSE;
    a->mUnk_02--;
    if (a->mUnk_02 <= 0) {
        a->mUnk_02 = 0;
        r = TRUE;
    }
    if (r == FALSE) {
        return;
    }
    func_0207d194(a, b);
}

void func_0207ca18(Unk0208fd8c *a, struct Unk020888b4 *b) {
    BOOL r;

    r = FALSE;
    a->mUnk_02--;
    if (a->mUnk_02 <= 0) {
        a->mUnk_02 = 0;
        r = TRUE;
    }
    if (r == FALSE) {
        return;
    }
    func_0207cd74(a, b);
}

void func_0207c978(Unk0208fd8c *a, struct Unk020888b4 *b) {
    Unk020ee684 *e;
    s32 t;
    BOOL r;

    e = &(data_027e00c8)[b->mIndex];
    t = e->mUnk_030.mUnk_00;
    if (a->mUnk_10 != 0) {
        if (t != 0x13) {
            a->mUnk_0c = 1;
        }
        if (a->mUnk_0c == 0) {
            return;
        }
        r = FALSE;
        a->mUnk_02--;
        if (a->mUnk_02 <= 0) {
            a->mUnk_02 = 0;
            r = TRUE;
        }
        if (r == FALSE) {
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
    BOOL r;

    e = &(data_027e00c8)[b->mIndex];
    t = e->mUnk_030.mUnk_00;
    if (a->mUnk_10 != 0) {
        if (t != 0x13) {
            a->mUnk_0c = 1;
        }
        if (a->mUnk_0c == 0) {
            return;
        }
        r = FALSE;
        a->mUnk_02--;
        if (a->mUnk_02 <= 0) {
            a->mUnk_02 = 0;
            r = TRUE;
        }
        if (r == FALSE) {
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

    func_0204360c(b->mKart->mUnk_78, 0x600);
    a->mUnk_10 = 0;
    if (a->mUnk_04 == NULL) {
        return;
    }
    n = a->mUnk_04->mTimerRandomLimit;
    r = func_0208537c();
    if (n == 0) {
        v = 0;
    } else {
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        v = (n == 0) ? (u32) (r->mUnk_00 >> 32) : (u32) (((r->mUnk_00 >> 32) * (u32) n) >> 32);
    }
    a->mUnk_00 = a->mUnk_04->mTimerBase + (u16) v;
}

void func_0207c614(Unk0208fd8c *a, struct Unk020888b4 *b) {
    Unk0217aebc_128 *r;
    u16 n;
    u32 v;

    func_0204360c(b->mKart->mUnk_78, 0x600);
    a->mUnk_10 = 0;
    if (a->mUnk_08 == NULL) {
        return;
    }
    n = a->mUnk_08->mTimerRandomLimit;
    r = func_0208537c();
    if (n == 0) {
        v = 0;
    } else {
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        v = (n == 0) ? (u32) (r->mUnk_00 >> 32) : (u32) (((r->mUnk_00 >> 32) * (u32) n) >> 32);
    }
    a->mUnk_02 = a->mUnk_08->mTimerBase + (u16) v;
}

void func_0207c548(Unk0208fd8c *a, struct Unk020888b4 *b) {
    Unk0217aebc_128 *r;
    u16 n;
    u32 v;

    func_0204360c(b->mKart->mUnk_78, 0x600);
    a->mUnk_14 = 1;
    a->mUnk_1c = 2;
    a->mUnk_10 = 0;
    if (a->mUnk_08 == NULL) {
        return;
    }
    n = a->mUnk_08->mTimerRandomLimit;
    r = func_0208537c();
    if (n == 0) {
        v = 0;
    } else {
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        v = (n == 0) ? (u32) (r->mUnk_00 >> 32) : (u32) (((r->mUnk_00 >> 32) * (u32) n) >> 32);
    }
    a->mUnk_02 = a->mUnk_08->mTimerBase + (u16) v;
}

void func_0207c47c(Unk0208fd8c *a, struct Unk020888b4 *b) {
    Unk0217aebc_128 *r;
    u16 n;
    u32 v;

    func_0204360c(b->mKart->mUnk_78, 0x600);
    a->mUnk_18 = 1;
    a->mUnk_1e = 2;
    a->mUnk_10 = 0;
    if (a->mUnk_08 == NULL) {
        return;
    }
    n = a->mUnk_08->mTimerRandomLimit;
    r = func_0208537c();
    if (n == 0) {
        v = 0;
    } else {
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        v = (n == 0) ? (u32) (r->mUnk_00 >> 32) : (u32) (((r->mUnk_00 >> 32) * (u32) n) >> 32);
    }
    a->mUnk_02 = a->mUnk_08->mTimerBase + (u16) v;
}

void func_0207c448(Unk0208fd8c *p0) {
    p0->mUnk_00 = (u16) 0x0u;
    p0->mUnk_02 = (u16) 0x0u;
    *(u32 *) ((u8 *) (u32) p0 + 4) = (u32) 0x0u;
    *(u32 *) ((u8 *) (u32) p0 + 8) = (u32) 0x0u;
    p0->mUnk_0c = (u32) 0x0u;
    p0->mUnk_10 = (u32) 0x0u;
    p0->mUnk_14 = (u32) 0x0u;
    p0->mUnk_18 = (u32) 0x0u;
    p0->mUnk_1c = (u16) 0x0u;
    p0->mUnk_1e = (u16) 0x0u;
    p0->mUnk_20 = (u32) 0x0u;
}

void func_0207c2ec(struct Unk0208fd8c *a, struct Unk020888b4 *b) {
    u16 v1;
    Unk020ee684 *e;

    if (func_01ffc67c(b->mKart) != 0) {
        return;
    }
    v1 = b->mIndex;
    if (v1 == func_02061f90()) {
        e = &(data_027e00c8)[v1];
        if (e->mUnk_058.mUnk_000 != 0xf && a->mUnk_08 != NULL) {
            a->mUnk_08->mUnk_00(a, b);
        } else if ((a->mUnk_04 != 0) & (e->mUnk_030.mUnk_00 != 0x13)) {
            a->mUnk_04->mUnk_00(a, b);
        } else {
            func_0204360c(b->mKart->mUnk_78, 0x600);
        }
    } else if (a->mUnk_14 != 0) {
        func_0204360c(b->mKart->mUnk_78, 0x40);
        a->mUnk_1c--;
        if (a->mUnk_1c <= 0) {
            a->mUnk_14 = 0;
        }
    } else if (a->mUnk_18 != 0) {
        func_0204360c(b->mKart->mUnk_78, 0x80);
        a->mUnk_1e--;
        if (a->mUnk_1e <= 0) {
            a->mUnk_18 = 0;
        }
    }
    if (a->mUnk_10 != 0) {
        func_0204360c(b->mKart->mUnk_78, 0x600);
    }
}

void func_0207c270(struct Unk0208fd8c *a, struct Unk020888b4 *b) {
    if (func_0203c880(b->mIndex) != 0) {
        return;
    }
    if ((data_027e00c8)[b->mIndex].mUnk_030.mUnk_00 == 0xe) {
        if (*(u16 *) &b->mUnk_08.mUnk_00.mUnk_00->mUnk_24 > 1) {
            return;
        }
    }
    func_0207c2ec(a, b);
}

void func_0207c144(struct Unk0208fd8c *a, struct Unk020888b4 *b) {
    Unk0217aebc_128 *r;
    u16 n;
    u32 v;
    enum { K0 } k;

    k = (data_027e00c8)[b->mIndex].mUnk_030.mUnk_00;
    a->mUnk_04 = &data_0217ae38[k];
    r = func_0208537c();
    r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
    a->mUnk_20 = (s16) (u16) (r->mUnk_00 >> 52);
    if (a->mUnk_04 == NULL) {
        return;
    }
    n = a->mUnk_04->mTimerRandomLimit;
    r = func_0208537c();
    if (n == 0) {
        v = 0;
    } else {
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        v = (n == 0) ? (u32) (r->mUnk_00 >> 32) : (u32) (((r->mUnk_00 >> 32) * (u32) n) >> 32);
    }
    a->mUnk_00 = a->mUnk_04->mTimerBase + (u16) v;
}

void func_0207c0a0(struct Unk0208fd8c *a) {
    Unk0217aebc_128 *r;
    u16 n;
    u32 v;

    if (a->mUnk_04 == NULL) {
        return;
    }
    n = a->mUnk_04->mTimerRandomLimit;
    r = func_0208537c();
    if (n == 0) {
        v = 0;
    } else {
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        v = (n == 0) ? (u32) (r->mUnk_00 >> 32) : (u32) (((r->mUnk_00 >> 32) * (u32) n) >> 32);
    }
    a->mUnk_00 = a->mUnk_04->mTimerBase + (u16) v;
}

s32 func_0207c078(struct Unk0208fd8c *a) {
    BOOL r = FALSE;

    a->mUnk_00--;
    if (a->mUnk_00 <= 0) {
        a->mUnk_00 = 0;
        r = TRUE;
    }
    return r;
}

void func_0207bfd4(struct Unk0208fd8c *a, struct Unk0208fd8c_08 *b) {
    Unk0217aebc_128 *r;
    u16 n;
    u32 v;

    if (a->mUnk_08 == NULL) {
        return;
    }
    n = a->mUnk_08->mTimerRandomLimit;
    r = func_0208537c();
    if (n == 0) {
        v = 0;
    } else {
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        v = (n == 0) ? (u32) (r->mUnk_00 >> 32) : (u32) (((r->mUnk_00 >> 32) * (u32) n) >> 32);
    }
    a->mUnk_02 = a->mUnk_08->mTimerBase + (u16) v;
}

s32 func_0207bfac(struct Unk0208fd8c *a) {
    BOOL r = FALSE;

    a->mUnk_02--;
    if (a->mUnk_02 <= 0) {
        a->mUnk_02 = 0;
        r = TRUE;
    }
    return r;
}

void func_0207becc(struct Unk0208fd8c *a, struct Unk020888b4 *b) {
    Unk0217aebc_128 *r;
    u16 n;
    u32 v;
    enum { K0 } k;

    k = (data_027e00c8)[b->mIndex].mUnk_058.mUnk_000;
    a->mUnk_08 = &data_0217ae34[k];
    a->mUnk_0c = 0;
    if (a->mUnk_08 == NULL) {
        return;
    }
    n = a->mUnk_08->mTimerRandomLimit;
    r = func_0208537c();
    if (n == 0) {
        v = 0;
    } else {
        r->mUnk_00 = r->mUnk_08 * r->mUnk_00 + r->mUnk_10;
        v = (n == 0) ? (u32) (r->mUnk_00 >> 32) : (u32) (((r->mUnk_00 >> 32) * (u32) n) >> 32);
    }
    a->mUnk_02 = a->mUnk_08->mTimerBase + (u16) v;
}

void func_0207be40(Unk0207b960 *a, struct Unk020748b8_218 *b) {
    Unk02175620_08 *e = &gCourseMap->mUnk_08[b->mUnk_40];
    u16 i;

    a->mUnk_30 = 0;
    a->mUnk_34 = 0;
    a->mUnk_38 = 0;
    if (e->mUnk_02 < 4) {
        return;
    }
    for (i = 0; i < 4; i++) {
        a->mUnk_00[i] = func_02042044(b->mUnk_40, i)->mUnk_00;
        a->mUnk_34 = i;
    }
}

void func_0207bd6c(Unk0207b960 *a, struct Unk020748b8_218 *b) {
    s16 j;
    s16 i;
    Unk02175620_08 *e = &gCourseMap->mUnk_08[b->mUnk_40];

    a->mUnk_30 = 0;
    a->mUnk_34 = 0;
    a->mUnk_38 = 0;
    if (e->mUnk_02 < 4) {
        return;
    }
    a->mUnk_38 = e->mUnk_02 - 1;
    a->mUnk_34 = 2;
    j = 2;
    for (i = 0; i < 3; i++) {
        a->mUnk_00[(u16) i] = func_02042044(b->mUnk_40, j)->mUnk_00;
        j--;
    }
    a->mUnk_00[3] = func_02042044(b->mUnk_40, e->mUnk_02 - 1)->mUnk_00;
}

void func_0207bc9c(Vec3 *a, Unk0207b960 *b, struct Unk020748b8_218 *c, s32 d) {
    Unk02175620_08 *e;
    Unk02042044 *f;
    u16 i;

    e = &gCourseMap->mUnk_08[c->mUnk_40];
    b->mUnk_30 += d;
    if (b->mUnk_30 > 0x1000) {
        b->mUnk_34++;
        if (b->mUnk_34 >= e->mUnk_02) {
            b->mUnk_34 = e->mUnk_02;
            b->mUnk_30 = 0x1000;
        } else {
            f = func_02042044(c->mUnk_40, b->mUnk_34);
            for (i = 0; i < 3; i++) {
                b->mUnk_00[i] = b->mUnk_00[i + 1];
            }
            b->mUnk_00[3] = f->mUnk_00;
            b->mUnk_30 -= 0x1000;
        }
    }
    func_0207b960(a, b);
}

void func_0207b960(Vec3 *a, Unk0207b960 *b) {
    s32 t;
    s32 t2;
    s32 t3;
    s32 u;
    s32 c0;
    s32 c1;
    s32 c2;
    s32 c3;
    Vec3 *v[4];
    s32 i;

    t = b->mUnk_30;
    u = 0x1000 - t;
    t2 = (s32) (((s64) t * t + 0x800) >> 12);
    t3 = (s32) (((s64) t2 * t + 0x800) >> 12);
    c0 = (s32) (((s64) (s32) (((s64) u * 0x2ab + 0x800) >> 12) * (s32) (((s64) u * u + 0x800) >> 12) + 0x800) >> 12);
    c1 =
        (s32) (((s64) ((s32) (((s64) t3 * 0x3000 + 0x800) >> 12) - (s32) (((s64) 0x6000 * t2 + 0x800) >> 12) + 0x4000) *
                    0x2ab +
                0x800) >>
               12);
    c2 = (s32) (((s64) ((s32) (((s64) (t + (t2 - t3)) * 0x3000 + 0x800) >> 12) + 0x1000) * 0x2ab + 0x800) >> 12);
    c3 = (s32) (((s64) t3 * 0x2ab + 0x800) >> 12);
    for (i = 0; i < 4; i++) {
        v[i] = &b->mUnk_00[i];
    }
    a->x = (s32) (((s64) v[0]->x * c0 + 0x800) >> 12) + (s32) (((s64) v[1]->x * c1 + 0x800) >> 12) +
           (s32) (((s64) v[2]->x * c2 + 0x800) >> 12) + (s32) (((s64) v[3]->x * c3 + 0x800) >> 12);
    a->y = (s32) (((s64) v[0]->y * c0 + 0x800) >> 12) + (s32) (((s64) v[1]->y * c1 + 0x800) >> 12) +
           (s32) (((s64) v[2]->y * c2 + 0x800) >> 12) + (s32) (((s64) v[3]->y * c3 + 0x800) >> 12);
    a->z = (s32) (((s64) v[0]->z * c0 + 0x800) >> 12) + (s32) (((s64) v[1]->z * c1 + 0x800) >> 12) +
           (s32) (((s64) v[2]->z * c2 + 0x800) >> 12) + (s32) (((s64) v[3]->z * c3 + 0x800) >> 12);
}
