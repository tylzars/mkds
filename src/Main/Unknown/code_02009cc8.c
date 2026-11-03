#include "Main/Unknown/code_020091fc.h"
#include "Main/Unknown/code_02009c34.h"
#include "Main/Unknown/code_02009cc8.h"
#include "code_0200eddc.h"
#include "code_0214d5b8.h"

#pragma thumb on

s32 func_02009cc8(u16 a) {
    data_0216fdac->mUnk_1320 = 1;
    return func_02009ce4(a);
}

s32 func_02009ce4(u16 a) {
    u32 v1;
    vu16 v2[2];
    s32 v4;
    s32 i;
    Unk0216fdac *v5;
    Unk0216fda8 *v6;
    v1 = func_0200fca0();
    data_0216fda8->mUnk_032 = a;
    v5 = data_0216fdac;
    data_usa_0216fd84 = (void *) (((u32) v5 + 0x7d1f) & ~0x1f);
    v4 = (s32) v5->mUnk_14e4;
    v2[0] = 0;
    func_0214cfe4(v2[0], v5->mUnk_1340, 0x69c0);
    func_02007ea0((UnkFunc *) v4);
    data_0216fdac->mUnk_1318 = data_0216fda8->mUnk_500 - 6;
    func_0200c448(data_0216fda8->mUnk_502);
    func_0200c430((u32) data_0216fdac->mUnk_1538);
    for (i = 0; i < 15; i++) {
        data_0216fdac->mUnk_14e8[i] = 0;
        data_0216fdac->mUnk_1526[i] = -1;
    }
    data_0216fdac->mUnk_1524 = 0;
    v2[1] = 0;
    func_0214cfe4(v2[1], data_0216fdac->mUnk_1788, 0x5d40);
    func_0214d168(data_0216fdac->mUnk_1754, 0, 0x1e);
    data_0216fda8->mUnk_524 = 1;
    data_0216fda8->mUnk_51c = func_020079c4;
    data_0216fda8->mUnk_508 = func_0200a7b0;
    data_0216fda8->mUnk_034 = data_0216fda8->mUnk_500;
    v6 = data_0216fda8;
    v6->mUnk_518 = (v6->mUnk_034 + 0x23) & ~0x1f;
    data_0216fda8->mUnk_036 = data_0216fda8->mUnk_502;
    v6 = data_0216fda8;
    v6->mUnk_51a = (((v6->mUnk_036 + 0xe) * 0xf + 0x29) & ~0x1f) << 1;
    func_020096d4();
    v4 = func_02009e70();
    func_0200fcb4(v1);
    data_0216fdac->mUnk_74c8 = func_0214d79c(0xf, 1);
    return v4;
}

s32 func_02009e70(void) {
    data_0216fda8->mUnk_528 = 0;
    data_0216fda8->mUnk_52a = 0;
    data_0216fda8->mUnk_526 = 0;
    data_0216fda8->mUnk_538[8] = 0;
    func_02009adc(10);
    if (data_0216fdac->mUnk_1320 == 0) {
        s32 v;
        do {
            v = func_02143e10(data_usa_0216fd84, data_0216fda8->mUnk_508, data_usa_0216fd80);
        } while (v == 4);
        if (v != 2) {
            return 8;
        }
        func_021435e8(data_0216fda8->mUnk_508);
        data_0216fda8->mUnk_50d = 1;
        return 0;
    }
    func_021435e8(data_0216fda8->mUnk_508);
    data_0216fda8->mUnk_50d = 1;
    func_0200ad00();
    return 0;
}

u32 func_02009f38(u32 a, u32 b) {
    u32 v;
    v = func_0200fca0();
    if (data_0216fda8->mUnk_50d != 0) {
        func_0200fcb4(v);
        return 0;
    }
    if (func_02009fac(a, 8, b) == 0) {
        func_0200fcb4(v);
        return 0;
    }
    data_0216fda8->mUnk_010 = b;
    data_0216fda8->mUnk_500 = a;
    data_0216fda8->mUnk_502 = 8;
    func_0200fcb4(v);
    return 1;
}

u32 func_02009fac(u32 a, u32 b, u32 c) {
    s32 v;
    if (a > 0x1fe || a < 0xe4) {
        return 0;
    }
    if (b > 0x10 || b < 8) {
        return 0;
    }
    v = (a + 0x26) * 4 + 0x14a + c * ((b + 0x20) * 4 + 0x70);
    if (v < 0x15e0) {
        return 1;
    }
    return 0;
}

s32 func_02009ff4(void *a, Unk02009ff4 *b, u32 c, u32 d, u32 e) {
    Unk0216fda8 *v1;
    Unk0216fdac *v2;
    u32 v3;
    vu16 v4;
    vu32 v5;
    s32 i;
    u16 *w;
    if (data_0216fdac != NULL && data_0216fdac->mUnk_1316 != 0) {
        return 2;
    }
    v1 = (Unk0216fda8 *) (((u32) a + 0x1f) & ~0x1f);
    v2 = (Unk0216fdac *) (((u32) v1 + 0x1e1f) & ~0x1f);
    if (d == 0x10000) {
        d = func_02142eac();
    }
    v3 = func_0200fca0();
    data_usa_0216fd80 = e;
    data_0216fda8 = v1;
    data_0216fdac = v2;
    v5 = 0;
    func_0214d018(v5, v1, 0x1e00);
    v4 = 0;
    func_0214cfe4(v4, v2, 0x1340);
    w = v1->mUnk_530;
    for (i = 0; i < b->mUnk_01; i++) {
        *w = b->mUnk_02[i];
        w++;
    }
    w = v1->mUnk_538;
    for (i = 0; i < 16; i++) {
        if (*data_usa_021617a0 == 0) {
            break;
        }
        *w = *data_usa_021617a0++;
        w++;
    }
    func_0214d1fc(b, &v2->mUnk_1300, 0x16);
    if (b->mUnk_01 < 10) {
        v2->mUnk_1300.mUnk_02[b->mUnk_01] = 0;
    }
    v1->mUnk_500 = 0x100;
    v1->mUnk_502 = 8;
    v1->mUnk_518 = 0;
    v1->mUnk_51a = 0;
    v1->mUnk_52c = 1;
    v1->mUnk_504 = (u32) v2->mUnk_0000 + 0x400;
    v1->mUnk_00e = 1;
    v1->mUnk_012 = 0;
    v1->mUnk_016 = 1;
    v1->mUnk_014 = 0;
    v1->mUnk_008 = c;
    v1->mUnk_00c = d;
    v1->mUnk_018 = func_0200a184() + 0xc8;
    v1->mUnk_010 = 0xf;
    v1->mUnk_50c = 0;
    v1->mUnk_50d = 0;
    v2->mUnk_1316 = 1;
    v2->mUnk_131c = 0;
    func_0200fcb4(v3);
    return 0;
}

u32 func_0200a184(void) {
    u8 v1[6];
    u32 v2;
    s32 i;
    func_0200fe58(v1);
    i = 0;
    v2 = 0;
    for (; i < 6; i++) {
        v2 += v1[i];
    }
    return (v2 + *(vu32 *) 0x27ffc3c) * 7 % 0x14;
}

void func_0200a1bc(Unk021425e8 *a) {
    Unk0216fda8_600 *e;
    u8 c;
    Unk0216fda8 *v1;
    s32 i;
    s32 n;
    u32 v2;
    u8 *v3;
    v1 = data_0216fda8;
    switch (a->mUnk_00) {
        case 0:
            if (a->mUnk_02 != 0) {
                v1->mUnk_51c(0x100, a);
                return;
            }
            v1->mUnk_51c(0x15, a);
            func_02009928(0x1d, func_021454c4(func_0200a1bc, *(u16 *) &data_0216179c, *(u16 *) &data_02161794,
                                              *(u16 *) &data_02161790, *(u16 *) &data_02161798));
            return;
        case 0x1d:
            if (a->mUnk_02 != 0) {
                v1->mUnk_51c(0x100, a);
                return;
            }
            data_0216fdc0.mUnk_00 = v1->mUnk_440;
            if (data_0216fdc0.mUnk_04 == 0) {
                data_0216fdc0.mUnk_04 = 1;
            }
            if (data_0216fdc0.mUnk_06 == 0) {
                data_0216fdc0.mUnk_06 = 0xc8;
            }
            data_0216fdc0.mUnk_08[0] = 0xff;
            data_0216fdc0.mUnk_08[1] = 0xff;
            data_0216fdc0.mUnk_08[2] = 0xff;
            data_0216fdc0.mUnk_08[3] = 0xff;
            data_0216fdc0.mUnk_08[4] = 0xff;
            data_0216fdc0.mUnk_08[5] = 0xff;
            v1->mUnk_5e4 = 1;
            v1->mUnk_5e8 = 1;
            func_02009928(0xa, func_02143a78(func_0200a1bc, &data_0216fdc0));
            return;
        case 10:
            if (a->mUnk_02 != 0) {
                v1->mUnk_51c(0x100, a);
                return;
            }
            switch (a->mUnk_08_0) {
                case 3:
                    return;
                case 5:
                    v3 = (u8 *) v1->mUnk_600;
                    i = 0;
                    n = v1->mUnk_5e0;
                    if (n > 0) {
                        e = (Unk0216fda8_600 *) v3;
                        c = a->mUnk_0a[0];
                        do {
                            if (c == e->mUnk_0c0.mUnk_0a[0] && a->mUnk_0a[1] == e->mUnk_0c0.mUnk_0a[1] &&
                                a->mUnk_0a[2] == e->mUnk_0c0.mUnk_0a[2] && a->mUnk_0a[3] == e->mUnk_0c0.mUnk_0a[3] &&
                                a->mUnk_0a[4] == e->mUnk_0c0.mUnk_0a[4] && a->mUnk_0a[5] == e->mUnk_0c0.mUnk_0a[5]) {
                                v2 = i * 0x180;
                                ((Unk0216fda8_600 *) (v3 + v2))->mUnk_0c0.mUnk_36 = a->mUnk_36;
                                ((Unk0216fda8_600 *) (v3 + (s32) v2))->mUnk_0c0.mUnk_38 = a->mUnk_38;
                                func_0200ee3c((Unk0216fda8_600 *) ((u8 *) v1->mUnk_600 + v2), 0xc0);
                                func_0214cb10(data_usa_0216fd80, v1->mUnk_440,
                                              (Unk0216fda8_600 *) ((u8 *) v1->mUnk_600 + v2), 0xc0);
                                v1->mUnk_5ec = i;
                                goto done;
                            }
                            e++;
                            i++;
                        } while (i < n);
                    }
                    if (i < 16) {
                        v1->mUnk_5e0 = i + 1;
                        v2 = i * 0x180;
                        func_0214cffc(a, v3 + v2 + 0xc0, 0xb8);
                        e = (Unk0216fda8_600 *) ((u8 *) v1->mUnk_600 + v2);
                        func_0200ee3c(e, 0xc0);
                        func_0214cb10(data_usa_0216fd80, v1->mUnk_440, e, 0xc0);
                        v1->mUnk_5ec = i;
                    }
                done:
                    v1->mUnk_51c(4, a);
                    if (v1->mUnk_5e4 == 0) {
                        return;
                    }
                    if (v1->mUnk_5e8 != 0) {
                        if (func_0200ada4(&data_0216fdc0) == 0) {
                            func_02009c34();
                        }
                    }
                    func_02009928(0xa, func_02143a78(func_0200a1bc, &data_0216fdc0));
                    return;
                case 4:
                    v1->mUnk_51c(5, a);
                    if (v1->mUnk_5e4 == 0) {
                        return;
                    }
                    if (v1->mUnk_5e8 != 0) {
                        if (func_0200ada4(&data_0216fdc0) == 0) {
                            func_02009c34();
                        }
                    }
                    func_02009928(0xa, func_02143a78(func_0200a1bc, &data_0216fdc0));
                    return;
                default:
                    v1->mUnk_51c(0x100, a);
                    return;
            }
        case 11:
            if (a->mUnk_02 != 0) {
                v1->mUnk_51c(0x100, a);
                return;
            }
            func_02009928(0xc, func_021437d8(func_0200a1bc, v1->mUnk_520, NULL, 1, 0));
            return;
        case 12:
            if (a->mUnk_02 != 0) {
                v1->mUnk_5e0 = 0;
                v1->mUnk_51c(0xb, a);
                return;
            }
            switch (a->mUnk_08_0) {
                case 6:
                    v1->mUnk_52a = 0;
                    v1->mUnk_528 = 1;
                    return;
                case 7:
                    v1->mUnk_5e2 = a->mUnk_08_2;
                    v1->mUnk_51c(6, a);
                    v1->mUnk_52a = 1;
                    if (func_0214358c(1, (UnkFunc *) func_0200a77c, NULL) != 0) {
                        return;
                    }
                    func_02009928(0xe, func_02144230(func_0200a1bc, v1->mUnk_504, v1->mUnk_51a, (u32) v1->mUnk_040,
                                                     v1->mUnk_518, v1->mUnk_52c == 0 ? 1 : 0, 0, 0, 0, 1, 1));
                    return;
                case 9:
                    v1->mUnk_51c(10, a);
                    v1->mUnk_52a = 0;
                    v1->mUnk_528 = 0;
                    return;
                default:
                    v1->mUnk_51c(0x100, a);
                    return;
            }
        case 14:
            switch (a->mUnk_04) {
                case 10:
                    v1->mUnk_528 = 1;
                    if (func_0200ad4c() == 0) {
                        return;
                    }
                    v1->mUnk_51c(0x19, NULL);
                    return;
                case 12:
                case 13:
                    return;
                default:
                    v1->mUnk_51c(0x100, a);
                    return;
            }
        case 15:
            v1->mUnk_50c = 0;
            if (a->mUnk_02 == 0) {
                v1->mUnk_51c(8, a);
            } else if (a->mUnk_02 == 9) {
                v1->mUnk_51c(0x29, a);
            } else {
                v1->mUnk_51c(0x12, a);
            }
            v1->mUnk_51c(0x19, NULL);
            return;
        case 1:
            if (a->mUnk_02 != 0) {
                v1->mUnk_526 = 0;
                v1->mUnk_51c(0x100, a);
                return;
            }
            v1->mUnk_52a = 0;
            data_0216fda8->mUnk_528 = 0;
            func_02009928(2, func_02143d88(func_0200a1bc));
            return;
        case 2:
            if (a->mUnk_02 != 0) {
                v1->mUnk_526 = 0;
                v1->mUnk_51c(0x100, a);
                return;
            }
            v1->mUnk_50d = 0;
            data_0216fdac->mUnk_1316 = 0;
            v1->mUnk_51c(0x11, a);
            return;
        case 21:
            if (func_0200ad4c() == 0) {
                return;
            }
            v1->mUnk_51c(0x19, NULL);
            return;
        case 0x80:
            switch (a->mUnk_04) {
                case 0x16:
                    func_0200fd1c();
                    break;
                case 0x17:
                    break;
            }
            return;
        default:
            v1->mUnk_51c(0x100, a);
            return;
    }
}

void func_0200a77c(Unk021425e8 *a) {
    if (a->mUnk_02 == 0) {
        if (a->mUnk_04 == 7) {
        } else if (a->mUnk_04 == 9) {
        } else if (a->mUnk_04 == 0x15) {
            data_0216fda8->mUnk_51c(9, a);
        }
    }
}

void func_0200a7b0(Unk021425e8 *a) {
    u32 n;
    u32 i;
    Unk0216fdac *p;
    u32 x;
    switch (a->mUnk_00) {
        case 0:
            if (a->mUnk_02 != 0) {
                data_0216fda8->mUnk_51c(0x100, a);
                return;
            }
            func_0200ad00();
            return;
        case 0x1d:
            if (a->mUnk_02 != 0) {
                data_0216fda8->mUnk_51c(0x100, a);
                return;
            }
            func_02009928(7, func_02143c80(func_0200a7b0, (Unk02143c30 *) data_0216fda8));
            return;
        case 7:
            data_0216fda8->mUnk_51c(0x15, a);
            func_02009928(0x19, func_02145530(func_0200a7b0, 1));
            return;
        case 0x19:
            if (a->mUnk_02 != 0) {
                data_0216fda8->mUnk_51c(0x100, a);
                return;
            }
            func_02009928(8, func_02143bd4(func_0200a7b0, data_usa_021617a4));
            return;
        case 8:
            if (a->mUnk_02 != 0) {
                data_0216fda8->mUnk_51c(0x100, a);
                return;
            }
            switch (a->mUnk_08_0) {
                case 0:
                    data_0216fda8->mUnk_52a = 0;
                    data_0216fda8->mUnk_528 = 0;
                    return;
                case 7:
                    if (data_0216fda8->mUnk_526 == 1) {
                        return;
                    }
                    data_0216fda8->mUnk_52a |= 1 << a->mUnk_10;
                    data_0216fda8->mUnk_51c(0, a);
                    if (data_0216fda8->mUnk_528 == 0 && data_0216fdac->mUnk_131c == 0) {
                        data_0216fdac->mUnk_131c = 1;
                        x = 1;
                        if (data_0216fda8->mUnk_52c != 0) {
                            x = 0;
                        }
                        func_02009928(0xe, func_02144230(func_0200a7b0, data_0216fda8->mUnk_504,
                                                         data_0216fda8->mUnk_51a, (u32) data_0216fda8->mUnk_040,
                                                         data_0216fda8->mUnk_518, x, 0, 0, 0, 1, 1));
                        return;
                    }
                    if (func_0200ad4c() == 0) {
                        return;
                    }
                    data_0216fda8->mUnk_51c(0x19, NULL);
                    return;
                case 9:
                    data_0216fda8->mUnk_52a &= ~(1 << a->mUnk_10);
                    data_0216fda8->mUnk_51c(1, a);
                    return;
                case 2:
                    if (data_0216fda8->mUnk_526 == 1) {
                        return;
                    }
                    data_0216fda8->mUnk_51c(0x1c, a);
                    return;
                default:
                    data_0216fda8->mUnk_51c(0x100, a);
                    return;
            }
        case 14:
            data_0216fdac->mUnk_131c = 0;
            switch (a->mUnk_04) {
                case 10:
                    data_0216fda8->mUnk_528 = 1;
                    data_0216fda8->mUnk_51c(0x19, NULL);
                    return;
                case 11:
                    data_0216fda8->mUnk_51c(3, a->mUnk_08);
                    return;
                default:
                    data_0216fda8->mUnk_51c(0x100, a);
                    return;
            }
        case 15:
            p = data_0216fdac;
            if (p->mUnk_74c8 != 0) {
                n = 0;
                for (i = 0; i < 15; i++) {
                    if (p->mUnk_14e8[i] != 0) {
                        n++;
                        if (n >= 2) {
                            break;
                        }
                    }
                }
                if (n == 1) {
                    func_0200fd10(0x32c8);
                }
            }
            data_0216fda8->mUnk_50c = 0;
            if (a->mUnk_02 == 0) {
                data_0216fda8->mUnk_51c(2, a);
                data_0216fda8->mUnk_51c(0x19, NULL);
                return;
            }
            if (a->mUnk_02 == 10) {
                data_0216fda8->mUnk_51c(0x2a, a);
                return;
            }
            data_0216fda8->mUnk_51c(0x13, a);
            data_0216fda8->mUnk_51c(0x19, NULL);
            return;
        case 1:
            if (data_0216fdac->mUnk_1320 == 0) {
                if (a->mUnk_02 != 0) {
                    data_0216fda8->mUnk_526 = 0;
                    data_0216fda8->mUnk_51c(0x100, a);
                    return;
                }
                data_0216fda8->mUnk_52a = 0;
                data_0216fda8->mUnk_528 = 0;
                func_02009928(2, func_02143d88(func_0200a7b0));
                return;
            }
            func_0214358c(1, NULL, NULL);
            func_021435e8(NULL);
        case 2:
            if (a->mUnk_02 != 0) {
                data_0216fda8->mUnk_526 = 0;
                data_0216fda8->mUnk_51c(0x100, a);
                return;
            }
            data_0216fda8->mUnk_50d = 0;
            data_0216fdac->mUnk_1316 = 0;
            data_0216fda8->mUnk_51c(0x11, a);
            return;
        case 13:
            if (a->mUnk_02 == 0) {
                data_0216fda8->mUnk_52a &= ~a->mUnk_08_2;
            }
            return;
        case 0x80:
            switch (a->mUnk_04) {
                case 0x10:
                    data_0216fda8->mUnk_51c(0x1d, a);
                    return;
                case 0x11:
                    data_0216fda8->mUnk_51c(0x1f, a);
                    return;
                case 0x12:
                    data_0216fda8->mUnk_51c(0x20, a);
                    return;
                case 0x13:
                    data_0216fda8->mUnk_51c(0x21, a);
                    return;
                case 0x16:
                    func_0200fd1c();
                    break;
                case 0x17:
                    break;
            }
            break;
        default:
            data_0216fda8->mUnk_51c(0x100, a);
            return;
    }
}

#pragma thumb off
