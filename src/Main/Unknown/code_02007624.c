#include "Main/Unknown/code_02007624.h"
#include "Main/Unknown/code_020091fc.h"
#include "code_0214d018.h"

#pragma thumb on

void *func_02007e38(u32 a) {
    u32 v1;
    v1 = IrqDisable();
    if (*(u32 *) &data_0216fdac != 0 && func_02007138(a) != 0) {
        MemCopy(data_0216fdac->mUnk_1340 + (a - 1) * 0x16, data_0216fdac->mUnk_1772, 0x16);
        IrqRestore(v1);
        return data_0216fdac->mUnk_1772;
    }
    IrqRestore(v1);
    return NULL;
}

u32 func_02007df8(u32 a) {
    if (*(u32 *) &data_0216fdac != 0 && func_02007138(a) != 0 && data_0216fdac->mUnk_14e8[a - 1] == 7) {
        return 1;
    }
    return 0;
}

u32 func_02007d50(u32 a, u32 b) {
    u32 v1;
    u32 v3;
    u32 v2;
    v1 = IrqDisable();
    switch (b) {
        case 0:
            v2 = 0xa;
            v3 = 4;
            break;
        case 1:
            v2 = 0xa;
            v3 = 3;
            break;
        case 2:
            v2 = 0xe;
            v3 = 2;
            break;
        case 3:
            v2 = 7;
            v3 = 5;
            break;
        default:
            IrqRestore(v1);
            return 0;
    }
    if (*(u32 *) &data_0216fdac != 0 && func_02007138(a) != 0 && v2 == data_0216fdac->mUnk_14e8[a - 1]) {
        data_0216fdac->mUnk_1754[a - 1] = v3;
        IrqRestore(v1);
        return 1;
    }
    IrqRestore(v1);
    return 0;
}

void func_02007d18(u32 a, u32 b, void *c) {
    if (func_02007138(a) != 0) {
        data_0216fdac->mUnk_14e8[a - 1] = b;
    }
    func_02007cf8(a, b, c);
}

void func_02007cf8(u32 a, u32 b, void *c) {
    Unk0216fdac *v1;
    v1 = data_0216fdac;
    if (v1->mUnk_14e4 != NULL) {
        v1->mUnk_14e4(a, b, c);
    }
}

void func_020079c4(s32 a, Unk021425e8 *b) {
    u32 v1;
    u8 i;
    Unk0216fdac *p;
    u32 v2;
    u16 v3;
    u8 v4;
    s32 v5;
    void (*v6)(u32, u32, void *);
    v1 = 0;
    switch (a) {
        case 0x15:
            func_02007d18(0, 1, b);
            break;
        case 0:
            v3 = b->mUnk_10;
            if (v3 != 0 && v3 < 16) {
                func_02007d18(v3, 2, b);
            }
            break;
        case 1:
            v3 = b->mUnk_10;
            if (v3 != 0 && v3 < 16) {
                data_0216fdac->mUnk_148a[b->mUnk_10 - 1] = 0;
                MemFill(data_0216fdac->mUnk_14a8 + (b->mUnk_10 - 1), 0, 4);
                MemFill(data_0216fdac->mUnk_1340 + (b->mUnk_10 - 1) * 0x16, 0, 0x16);
                func_0200c3fc(b->mUnk_10);
                v2 = 0;
                data_0216fdac->mUnk_1754[b->mUnk_10 - 1] = v2;
                v3 = b->mUnk_10;
                v5 = data_0216fdac->mUnk_1526[(s32) v3 - 1];
                v2 = ~v2;
                if (v5 != v2) {
                    v1 = 1 << v3;
                    v4 = v5;
                    ((Unk0216fdac *) ((u8 *) data_0216fdac + v4 * 0x5d4))->mUnk_1d4e &= ~v1;
                    ((Unk0216fdac *) ((u8 *) data_0216fdac + v4 * 0x5d4))->mUnk_1d50 |= v1;
                    data_0216fdac->mUnk_1526[v3 - 1] = v2;
                    ((Unk0216fdac *) ((u8 *) data_0216fdac + v4 * 0x5d4))->mUnk_1d4c &= ~v1;
                }
                if ((data_0216fdac->mUnk_1536 & (1 << b->mUnk_10)) != 0) {
                    data_0216fdac->mUnk_1535--;
                    data_0216fdac->mUnk_1536 &= ~(1 << b->mUnk_10);
                }
                v3 = b->mUnk_10;
                if (data_0216fdac->mUnk_14e8[v3 - 1] == 8) {
                    func_02007d18(v3, 9, NULL);
                }
                func_02007d18(b->mUnk_10, 3, b);
                data_0216fdac->mUnk_14e8[b->mUnk_10 - 1] = 0;
            }
            break;
        case 0x11:
            break;
        case 3:
            func_02007624((Unk021432ac *) b);
            break;
        case 0x19:
            func_020071b4();
            break;
        case 0x1c:
            i = 0;
            v1 = 0;
            do {
                p = data_0216fdac;
                v2 = i * 0x5d4;
                if (((Unk0216fdac *) ((u8 *) p + v2))->mUnk_1d52 != 0 &&
                    ((Unk0216fdac *) ((u8 *) p + v2))->mUnk_1d50 != 0) {
                    func_0200973c((Unk0200b610 *) (p->mUnk_1788 + 0xe4 + v2), p->mUnk_1340,
                                  ((Unk0216fdac *) ((u8 *) p + v2))->mUnk_1d4e,
                                  ((Unk0216fdac *) ((u8 *) p + v2))->mUnk_1d50);
                    ((Unk0216fdac *) ((u8 *) data_0216fdac + v2))->mUnk_1d50 = v1;
                }
                i++;
            } while (i < 16);
            {
                u32 v7;
                u16 v8;
                v7 = func_020099cc();
                v8 = func_020099c0();
                func_0200964c(v7, v8, func_02009974());
            }
            break;
        case 0xff:
            switch (b->mUnk_02) {
                case 1:
                case 4:
                case 5:
                case 6:
                case 8:
                case 9:
                    func_02007120(0, 9);
                    break;
                case 15:
                default:
                    func_02007120(0, 8);
                    break;
            }
            break;
        case 0x100:
            switch (b->mUnk_00) {
                case 0:
                case 7:
                case 8:
                case 13:
                case 14:
                case 15:
                case 17:
                case 18:
                case 21:
                case 25:
                case 29:
                    func_02007120(0, 9);
                    break;
                case 22:
                default:
                    func_02007120(0, 8);
                    break;
            }
            break;
    }
    if (a == 0x11) {
        v6 = data_0216fdac->mUnk_14e4;
        MemFillWordsByBlock_inline(data_0216fdac, 0x7d00);
        *(u32 *) &data_0216fdac = 0;
        if (v6 != NULL) {
            v6(0, 0xc, NULL);
        }
    }
}

void func_02007698(Unk021432ac *a, u32 b) {
    Unk0200c16c v1;
    Unk0200c12c v2;
    u8 *v3;
    u32 v4;
    u32 v5;
    u8 v7;
    u8 v6;
    u8 v11;
    u32 v12;
    if (b == 0 || b > 15) {
        return;
    }
    v3 = func_0200c2e0(a->mUnk_0a, &v1, b);
    v4 = b - 1;
    v5 = data_0216fdac->mUnk_14e8[v4];
    switch (v1.mUnk_00) {
        case 7:
            if (v5 == 2) {
                if (v3 == NULL) {
                    return;
                }
                MemCopy(v3, &v2, 0x1d);
                v12 = b - 1;
                data_0216fdac->mUnk_14a8[v4] = v2.mUnk_00;
                data_0216fdac->mUnk_148a[v12] = v2.mUnk_1a;
                v12 *= 0x16;
                MemCopy(v2.mUnk_04, data_0216fdac->mUnk_1340 + v12, 0x16);
                ((Unk0216fdac_1340 *) &data_0216fdac->mUnk_1340[v12])->mUnk_00_4 = b;
                func_02007d18(b, 0xa, v2.mUnk_04);
            }
            if (v5 == 10) {
                v6 = 0;
                v11 = ((Unk0200c12c *) v3)->mUnk_1c;
                if (v11 >= 16 || ((Unk0216fdac *) ((u8 *) data_0216fdac + v11 * 0x5d4))->mUnk_1d52 == 0 ||
                    data_0216fdac->mUnk_14a8[v4] !=
                        ((Unk0216fdac *) ((u8 *) data_0216fdac + v11 * 0x5d4))->mUnk_1d40->mUnk_14) {
                    data_0216fdac->mUnk_1754[v4] = 4;
                } else {
                    v7 = 0;
                    do {
                        if (((1 << v7) & ((Unk0216fdac *) ((u8 *) data_0216fdac + v11 * 0x5d4))->mUnk_1d4e) != 0) {
                            v6++;
                        }
                        v7++;
                    } while (v7 < 16);
                    if (v6 >= ((Unk0216fdac *) ((u8 *) data_0216fdac + v11 * 0x5d4))->mUnk_1d40->mUnk_18[0]) {
                        data_0216fdac->mUnk_1754[v4] = 0;
                        func_02007d18(b, 0xb, NULL);
                        return;
                    }
                }
                switch (data_0216fdac->mUnk_1754[v4]) {
                    case 3:
                        if ((data_0216fdac->mUnk_1536 & (1U << b)) != 0) {
                            return;
                        }
                        data_0216fdac->mUnk_1535++;
                        data_0216fdac->mUnk_1536 |= 1 << b;
                        data_0216fdac->mUnk_1526[b - 1] = v11;
                        ((Unk0216fdac *) ((u8 *) data_0216fdac + v11 * 0x5d4))->mUnk_1d4e |= 1 << b;
                        ((Unk0216fdac *) ((u8 *) data_0216fdac + v11 * 0x5d4))->mUnk_1d50 |= 1 << b;
                        data_0216fdac->mUnk_1754[v4] = 0;
                        func_02007d18(b, 5, NULL);
                        break;
                    case 4:
                        ((Unk0216fdac *) ((u8 *) data_0216fdac + v4 * 2))->mUnk_1754[0] = 0;
                        func_02007d18(b, 4, NULL);
                        break;
                }
            }
            break;
        case 8:
            if (v5 == 5) {
                func_02007d18(b, 0xe, NULL);
            } else if (v5 == 0xe) {
                if (data_0216fdac->mUnk_1754[v4] == 2) {
                    v11 = data_0216fdac->mUnk_1526[v4];
                    ((Unk0216fdac *) ((u8 *) data_0216fdac + v11 * 0x5d4))->mUnk_1d4c |= 1 << b;
                    ((Unk0216fdac *) ((u8 *) data_0216fdac + v11 * 0x5d4))->mUnk_1d48 = 0;
                    data_0216fdac->mUnk_1754[v4] = 0;
                    func_02007d18(b, 6, NULL);
                }
            }
            break;
        case 9:
            if (v5 == 6) {
                v11 = data_0216fdac->mUnk_1526[v4];
                if (v11 != 0xff) {
                    ((Unk0216fdac *) ((u8 *) data_0216fdac + v11 * 0x5d4))->mUnk_1d4a =
                        func_02007148(((Unk0216fdac *) ((u8 *) data_0216fdac + v11 * 0x5d4))->mUnk_1d4a, v1.mUnk_02);
                }
            }
            break;
        case 10:
            if (v5 == 6) {
                v11 = data_0216fdac->mUnk_1526[v4];
                if (v11 != 0xff) {
                    ((Unk0216fdac *) ((u8 *) data_0216fdac + v11 * 0x5d4))->mUnk_1d4c &= ~(1 << b);
                    func_02007d18(b, 7, NULL);
                }
            } else if (v5 == 7) {
                if (data_0216fdac->mUnk_1754[v4] == 5) {
                    ((Unk0216fdac *) ((u8 *) data_0216fdac + v4 * 2))->mUnk_1754[0] = 0;
                    func_02007d18(b, 8, NULL);
                }
            }
            break;
        case 11:
            break;
    }
}

void func_02007624(Unk021432ac *a) {
    u16 i;
    u16 v1;
    void *v2;
    for (i = 0; i < 16; i++) {
        if (((Unk0216fdac *) ((u8 *) data_0216fdac + i * 0x5d4))->mUnk_1d52 != 0) {
            ((Unk0216fdac *) ((u8 *) data_0216fdac + i * 0x5d4))->mUnk_1d4a = 0;
        }
    }
    for (i = 1; i <= 15; i++) {
        v2 = func_021432ac(a, i);
        if (v2 != NULL) {
            v1 = *(u16 *) v2;
            if (v1 != 0xffff && v1 != 0) {
                func_02007698(v2, i);
            }
        }
    }
}

#pragma thumb off
