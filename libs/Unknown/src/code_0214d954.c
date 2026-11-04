#include "code_0214d954.h"

#include "code_0200fc8c.h"
#include "code_0214d5b8.h"
#include "code_0214d93c.h"
#include "Main/Unknown/code_0200f000.h"

u16 data_021803ac;

// Calls func_0214e17c with 0x11.
s32 func_0214e1d0(void) {
    return func_0214e17c(0x11);
}

// Calls func_0214e17c with 0x12.
s32 func_0214e1c0(void) {
    return func_0214e17c(0x12);
}

// Calls func_0214e17c with 0x27.
s32 func_0214e1b0(void) {
    return func_0214e17c(0x27);
}

// Returns whether PxiSendFifoWord(5, a << 8 & 0x7f00, 0) is not negative.
s32 func_0214e17c(u32 a) {
    return PxiSendFifoWord(5, (a << 8) & 0x7f00, 0) >= 0;
}

// Runs once: clears the first word, mUnk_04, mUnk_1c, mUnk_08 and mUnk_0c, waits until func_0214d79c(5, 1) is
// nonzero and passes 5 and func_0214d9e8 to func_0214d7c4.
void func_0214e0f4(void) {
    if (data_021803ac != 0) {
        return;
    }
    data_021803ac = 1;
    data_021803b0.mUnk_00 = 0;
    data_021803b0.mUnk_04 = 0;
    data_021803b0.mUnk_1c = 0;
    data_021803b0.mUnk_08 = 0;
    data_021803b0.mUnk_0c = 0;
    func_0214d5b8();
    while (func_0214d79c(5, 1) == 0) {
    }
    func_0214d7c4(5, func_0214d9e8);
}

// Returns 1 while mUnk_00 is set; otherwise records a, b and c, clears mUnk_14 and mUnk_18 and returns 0 when
// func_0214e1d0 returns nonzero, 3 when it returns 0.
u32 func_0214e07c(u32 *a, UnkFunc *b, u32 c) {
    u32 s;

    s = IrqDisable();
    if (data_021803b0.mUnk_00 != 0) {
        IrqRestore(s);
        return 1;
    }
    data_021803b0.mUnk_00 = 1;
    IrqRestore(s);
    data_021803b0.mUnk_14 = 0;
    data_021803b0.mUnk_18 = 0;
    data_021803b0.mUnk_08 = a;
    data_021803b0.mUnk_04 = b;
    data_021803b0.mUnk_10 = c;
    return func_0214e1d0() != 0 ? 0 : 3;
}

// Runs func_0214e07c with func_0214d954, stores the result in mUnk_20 and waits when it is 0.
u32 func_0214e038(u32 *a) {
    data_021803b0.mUnk_20 = func_0214e07c(a, func_0214d954, 0);
    if (data_021803b0.mUnk_20 == 0) {
        func_0214d93c();
    }
    return data_021803b0.mUnk_20;
}

// Like func_0214e07c, but sets mUnk_14 to 1 and calls func_0214e1c0.
u32 func_0214dfbc(u32 *a, UnkFunc *b, u32 c) {
    u32 s;

    s = IrqDisable();
    if (data_021803b0.mUnk_00 != 0) {
        IrqRestore(s);
        return 1;
    }
    data_021803b0.mUnk_00 = 1;
    IrqRestore(s);
    data_021803b0.mUnk_14 = 1;
    data_021803b0.mUnk_18 = 0;
    data_021803b0.mUnk_08 = a;
    data_021803b0.mUnk_04 = b;
    data_021803b0.mUnk_10 = c;
    return func_0214e1c0() != 0 ? 0 : 3;
}

// Runs func_0214dfbc with func_0214d954, stores the result in mUnk_20 and waits when it is 0.
u32 func_0214df78(u32 *a) {
    data_021803b0.mUnk_20 = func_0214dfbc(a, func_0214d954, 0);
    if (data_021803b0.mUnk_20 == 0) {
        func_0214d93c();
    }
    return data_021803b0.mUnk_20;
}

// With c set: clears mUnk_18 and mUnk_00 and calls mUnk_04 (cleared first) with 6 and mUnk_10. Otherwise, with bits
// 8-14 of b equal to 0x30, calls mUnk_1c; with the low byte of b zero, fills the words at mUnk_08 (and mUnk_0c) from
// the fixed-address fields of Unk027ffde8 and Unk027ffdec selected by mUnk_14, most through func_0214d964, or
// changes Unk027ffdea and calls func_0214e1b0; then, when mUnk_18 is 0, clears mUnk_00 and calls mUnk_04 the same
// way with a value from 0 to 6.
void func_0214d9e8(u32 a, u32 b, s32 c) {
    u8 k;
    u32 x;
    u32 n;
    u32 *p;
    UnkFunc *f;

    if (c != 0) {
        if (data_021803b0.mUnk_18 != 0) {
            data_021803b0.mUnk_18 = 0;
        }
        if (data_021803b0.mUnk_00 != 0) {
            data_021803b0.mUnk_00 = 0;
        }
        f = data_021803b0.mUnk_04;
        if (f != 0) {
            data_021803b0.mUnk_04 = 0;
            f(6, data_021803b0.mUnk_10);
        }
        return;
    }
    k = (b & 0x7f00) >> 8;
    x = b & 0xff;
    if (k == 0x30) {
        if (data_021803b0.mUnk_1c != 0) {
            data_021803b0.mUnk_1c();
        }
        return;
    }
    if (x == 0) {
        n = 0;
        switch (data_021803b0.mUnk_14) {
            case 0:
                p = data_021803b0.mUnk_08;
                p[0] = func_0214d964(((Unk027ffde8 *) 0x027ffde8)->mUnk_00_0);
                p[1] = func_0214d964(((Unk027ffde8 *) 0x027ffde8)->mUnk_00_8);
                p[2] = func_0214d964(((Unk027ffde8 *) 0x027ffde8)->mUnk_00_16);
                p[3] = ((Unk027ffde8 *) 0x027ffde8)->mUnk_00_24;
                break;
            case 1:
                p = data_021803b0.mUnk_08;
                p[0] = func_0214d964(((Unk027ffdec *) 0x027ffdec)->mUnk_00_0);
                p[1] = func_0214d964(((Unk027ffdec *) 0x027ffdec)->mUnk_00_8);
                p[2] = func_0214d964(((Unk027ffdec *) 0x027ffdec)->mUnk_00_16);
                break;
            case 2:
                p = data_021803b0.mUnk_08;
                p[0] = func_0214d964(*(u32 *) 0x027ffde8 & 0xff);
                p[1] = func_0214d964(((Unk027ffde8 *) 0x027ffde8)->mUnk_00_8);
                p[2] = func_0214d964(((Unk027ffde8 *) 0x027ffde8)->mUnk_00_16);
                p[3] = ((Unk027ffde8 *) 0x027ffde8)->mUnk_00_24;
                p = data_021803b0.mUnk_0c;
                p[0] = func_0214d964(((Unk027ffdec *) 0x027ffdec)->mUnk_00_0);
                p[1] = func_0214d964(((Unk027ffdec *) 0x027ffdec)->mUnk_00_8);
                p[2] = func_0214d964(((Unk027ffdec *) 0x027ffdec)->mUnk_00_16);
                break;
            case 3:
            case 4:
            case 5:
            case 11:
            case 12:
            case 13:
            case 14:
            case 15:
                break;
            case 6:
                p = data_021803b0.mUnk_08;
                switch (((Unk027ffdea *) 0x027ffdea)->mUnk_00_0) {
                    case 4:
                        p[0] = 1;
                        break;
                    default:
                        p[0] = 0;
                        break;
                }
                break;
            case 7:
                p = data_021803b0.mUnk_08;
                if (((Unk027ffdea *) 0x027ffdea)->mUnk_00_6) {
                    p[0] = 1;
                } else {
                    p[0] = 0;
                }
                break;
            case 8:
                p = data_021803b0.mUnk_08;
                p[0] = ((Unk027ffdec_b *) 0x027ffdec)->mUnk_00_0;
                p[1] = func_0214d964(((Unk027ffdec_b *) 0x027ffdec)->mUnk_00_8);
                p[2] = func_0214d964(((Unk027ffdec_b *) 0x027ffdec)->mUnk_00_16);
                p[3] = 0;
                if (((Unk027ffdec_b *) 0x027ffdec)->mUnk_00_7) {
                    p[3] += 1;
                }
                if (((Unk027ffdec_b *) 0x027ffdec)->mUnk_00_15) {
                    p[3] += 2;
                }
                if (((Unk027ffdec_b *) 0x027ffdec)->mUnk_00_23) {
                    p[3] += 4;
                }
                break;
            case 9:
                if (data_021803b0.mUnk_18 == 0) {
                    if (*data_021803b0.mUnk_08 == 1) {
                        if (((Unk027ffdea *) 0x027ffdea)->mUnk_00_0 != 4) {
                            data_021803b0.mUnk_18++;
                            ((Unk027ffdea *) 0x027ffdea)->mUnk_00_0 = 4;
                            if (func_0214e1b0() == 0) {
                                n = 3;
                                data_021803b0.mUnk_18 = 0;
                            }
                        }
                    } else {
                        if (((Unk027ffdea *) 0x027ffdea)->mUnk_00_0 != 0) {
                            data_021803b0.mUnk_18++;
                            ((Unk027ffdea *) 0x027ffdea)->mUnk_00_0 = 0;
                            if (func_0214e1b0() == 0) {
                                n = 3;
                                data_021803b0.mUnk_18 = 0;
                            }
                        }
                    }
                } else {
                    data_021803b0.mUnk_18 = 0;
                }
                break;
            case 10:
                if (data_021803b0.mUnk_18 == 0) {
                    if (*data_021803b0.mUnk_08 == 1) {
                        if (((Unk027ffdea *) 0x027ffdea)->mUnk_00_6 == 0) {
                            data_021803b0.mUnk_18++;
                            ((Unk027ffdea *) 0x027ffdea)->mUnk_00_6 = 1;
                            if (func_0214e1b0() == 0) {
                                n = 3;
                                data_021803b0.mUnk_18 = 0;
                            }
                        }
                    } else {
                        if (((Unk027ffdea *) 0x027ffdea)->mUnk_00_6 != 0) {
                            data_021803b0.mUnk_18++;
                            ((Unk027ffdea *) 0x027ffdea)->mUnk_00_6 = 0;
                            if (func_0214e1b0() == 0) {
                                n = 3;
                                data_021803b0.mUnk_18 = 0;
                            }
                        }
                    }
                } else {
                    data_021803b0.mUnk_18 = 0;
                }
                break;
            default:
                data_021803b0.mUnk_18 = 0;
                n = 4;
                break;
        }
    } else {
        data_021803b0.mUnk_18 = 0;
        switch (x) {
            case 1:
                n = 4;
                break;
            case 2:
                n = 5;
                break;
            case 3:
                n = 1;
                break;
            case 0:
            case 4:
            default:
                n = 6;
                break;
        }
    }
    if (data_021803b0.mUnk_18 != 0) {
        return;
    }
    if (data_021803b0.mUnk_00 != 0) {
        data_021803b0.mUnk_00 = 0;
    }
    f = data_021803b0.mUnk_04;
    if (f != 0) {
        data_021803b0.mUnk_04 = 0;
        f(n, data_021803b0.mUnk_10);
    }
}

// Returns the value of x read as 8 decimal digits (4 bits each, least significant first), or 0 when a digit is above 9.
u32 func_0214d964(u32 x) {
    u32 r;
    u32 m;
    s32 i;

    r = 0;
    for (i = 0; i < 8; i++) {
        if (((x >> (i * 4)) & 0xf) >= 10) {
            return 0;
        }
    }
    m = 1;
    for (i = 0; i < 8; i++) {
        r += m * ((x >> (i * 4)) & 0xf);
        m *= 10;
    }
    return r;
}

void func_0214d954(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    value1 = (u32) &data_021803b0;
    *(u32 *) ((value1) + (32)) = value0;
}
