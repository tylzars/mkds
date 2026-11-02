#include "Main/Unknown/code_0200589c.h"
#include "Main/Unknown/code_02006380.h"
#include "Main/Unknown/code_0200635c.h"
#include "Main/Unknown/code_02006954.h"
#include "Main/Unknown/code_020070f0.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_02133000.h"

#pragma thumb on

s32 func_0200589c(Unk0216f3dc *a, s32 b, s32 c) {
    s32 v1;
    u32 v2;
    s32 i;
    Unk0216f3dc_9c *v3;
    Unk0200628c *v4;
    Unk0200628c *v5;
    v1 = 0;
    v3 = &a->mUnk_09c;
    if (a->mUnk_000.mUnk_00 != 0) {
        return 0;
    }
    if (v3->mUnk_00 == 0) {
        return 0;
    }
    func_020070fc();
    v2 = func_02007114();
    switch (v3->mUnk_00) {
        case 2:
            func_0214d02c(v3, a, 0x9c);
            a->mUnk_000.mUnk_0c = v2;
            v2 = func_020070d8();
            v1 = func_02006858(b, a->mUnk_000.mUnk_08, a->mUnk_000.mUnk_0c, v2, func_020070e4());
            break;
        case 6:
            func_0214d02c(v3, a, 0x9c);
            a->mUnk_000.mUnk_0c = v2;
            for (i = 0, v4 = &a->mUnk_1d4[0].mUnk_24; i < 16; i++) {
                if (((a->mUnk_000.mUnk_08 >> i) & 1) != 0) {
                    func_0200639c(v4, a->mUnk_000.mUnk_18, v4->mUnk_1c, a->mUnk_000.mUnk_1c[i]);
                }
                v4 = (Unk0200628c *) ((u8 *) v4 + 0x68);
            }
            if (v3->mUnk_00 == 4) {
                v1 = func_02006794(b, a->mUnk_000.mUnk_08, a->mUnk_000.mUnk_0c, a->mUnk_000.mUnk_14, 0);
            } else {
                v1 = func_020066c0(b, a->mUnk_000.mUnk_08, a->mUnk_000.mUnk_0c, a->mUnk_000.mUnk_14, 0);
            }
            break;
        case 4:
            func_0214d02c(v3, a, 0x9c);
            a->mUnk_000.mUnk_0c = v2;
            for (i = 0, v5 = &a->mUnk_1d4[0].mUnk_24; i < 16; i++) {
                if (((a->mUnk_000.mUnk_08 >> i) & 1) != 0) {
                    func_0200639c(v5, a->mUnk_000.mUnk_18, a->mUnk_000.mUnk_5c[i], a->mUnk_000.mUnk_1c[i]);
                }
                v5 = (Unk0200628c *) ((u8 *) v5 + 0x68);
            }
            if (v3->mUnk_00 == 4) {
                v1 = func_02006794(b, a->mUnk_000.mUnk_08, a->mUnk_000.mUnk_0c, a->mUnk_000.mUnk_14, 0);
            } else {
                v1 = func_020066c0(b, a->mUnk_000.mUnk_08, a->mUnk_000.mUnk_0c, a->mUnk_000.mUnk_14, 0);
            }
            break;
        case 10:
            func_0214d02c(v3, a, 0x9c);
            a->mUnk_000.mUnk_0c = v2;
            v1 = func_0200654c(b, a->mUnk_000.mUnk_08, a->mUnk_000.mUnk_0c, &a->mUnk_000.mUnk_14,
                               *((u8 *) &a->mUnk_000.mUnk_1c[0] + 1));
            break;
    }
    v3->mUnk_00 = 0;
    return v1;
}

s32 func_02005a30(Unk0216f3dc *a, s32 b, s32 c) {
    s32 v1;
    s32 i;
    u32 v2;
    Unk0200628c *v3;
    s32 v4;
    u16 v5;
    v1 = 0;
    switch (a->mUnk_000.mUnk_00) {
        case 2:
            v2 = func_020070d8();
            return func_02006858(b, a->mUnk_000.mUnk_08, a->mUnk_000.mUnk_0c, v2, func_020070e4());
        case 4:
        case 6:
            for (i = 0, v3 = &a->mUnk_1d4[0].mUnk_24; i < 16; i++) {
                v2 = 1;
                v2 = v2 << i;
                if ((a->mUnk_000.mUnk_08 & (u16) v2) != 0) {
                    v4 = func_020062f4(v3);
                    if (v4 == -1) {
                        v1 = func_020065f8(b, (u16) v2, a->mUnk_000.mUnk_0c, a->mUnk_000.mUnk_14);
                    } else {
                        v5 = a->mUnk_000.mUnk_08;
                        if (a->mUnk_000.mUnk_00 == 4) {
                            v1 = func_02006794(b, v5, a->mUnk_000.mUnk_0c, a->mUnk_000.mUnk_14, v4);
                        } else {
                            v1 = func_020066c0(b, v5, a->mUnk_000.mUnk_0c, a->mUnk_000.mUnk_14, v4);
                        }
                    }
                    if (v1 != 0) {
                        return v1;
                    }
                }
                v3 = (Unk0200628c *) ((u8 *) v3 + 0x68);
            }
            return v1;
        case 10:
            v1 = func_0200654c(b, a->mUnk_000.mUnk_08, a->mUnk_000.mUnk_0c, &a->mUnk_000.mUnk_14,
                               *((u8 *) &a->mUnk_000.mUnk_1c[0] + 1));
            break;
    }
    return v1;
}

s32 func_02005b18(Unk0216f3dc *a, s32 b, s32 c, s32 d) {
    s32 v1;
    u32 v2;
    u32 v3;
    Unk0216f3dc_68 *v4;
    v1 = 0;
    v4 = &a->mUnk_1d4[b];
    if (v4->mUnk_00 == 2) {
        if (func_02006ffc() == 0) {
            v2 = 0xffff;
        } else {
            v2 = 1;
        }
        if (v4->mUnk_01 == 6) {
            v3 = func_020063f4(v4->mUnk_10, v4->mUnk_14);
            v1 = func_02006648(c, v2, v4->mUnk_02, v4->mUnk_10, v4->mUnk_14, v3, func_020070d8());
            v4->mUnk_00 = 1;
        }
    }
    return v1;
}

s32 func_02005b80(Unk0216f3dc *a, s32 b, s32 c, s32 d) {
    s32 v1;
    u32 v2;
    u32 v3;
    Unk0216f3dc_68 *v4;
    v1 = 0;
    v4 = &a->mUnk_1d4[b];
    if (v4->mUnk_00 == 2) {
        if (func_02006ffc() == 0) {
            v2 = 0xffff;
        } else {
            v2 = 1;
        }
        if (v4->mUnk_01 == 6) {
            v3 = func_020063f4(v4->mUnk_10, v4->mUnk_14);
            if (v3 != 0) {
                v1 = func_02006648(c, v2, v4->mUnk_02, v4->mUnk_10, v4->mUnk_14, v3, func_020070d8());
                v4->mUnk_00 = 1;
            }
        }
    }
    return v1;
}

s32 func_02005bec(Unk0216f3dc *a, s32 b, s32 c, s32 d) {
    s32 v1;
    u32 v2;
    s32 v3;
    u32 v4;
    Unk02007014 *v5;
    Unk0216f3dc_9c *v6;
    Unk0216f3dc_68 *v7;
    v1 = 0;
    v6 = &a->mUnk_138;
    v7 = &a->mUnk_1d4[b];
    if (v7->mUnk_00 == 2) {
        if (func_02006ffc() == 0) {
            v2 = 0xfffe;
        } else {
            v2 = 1;
        }
        if (v7->mUnk_01 == 4) {
            v5 = func_02007014(v7->mUnk_10);
            if (v5 != NULL) {
                v3 = func_02006458(v7->mUnk_10, v7->mUnk_14);
                if (v3 != -1) {
                    if (v5->mUnk_32 == 0) {
                        v4 = func_020063f4(v7->mUnk_10, v3);
                        v1 = func_0200671c(c, v2, v7->mUnk_02, v7->mUnk_10, v3, v4, func_020070d8());
                    } else if (v5->mUnk_32 == 1) {
                        v6->mUnk_14 = v7->mUnk_10;
                        v6->mUnk_18 = v3;
                        *(s16 *) &v6->mUnk_1c[1] = func_020070d8();
                        v6->mUnk_1c[0] = 0;
                        func_020061d8(a, 13, b, 0);
                        if (v6->mUnk_1c[0] != 0) {
                            v1 = func_0200671c(c, v2, v7->mUnk_02, v6->mUnk_14, v6->mUnk_18, v6->mUnk_1c[0],
                                               *(s16 *) &v6->mUnk_1c[1]);
                        }
                    }
                }
            }
            v7->mUnk_00 = 1;
        }
    }
    return v1;
}

s32 func_02005cc8(Unk0216f3dc *a, s32 b, s32 c, s32 d) {
    s32 v1;
    u16 v2;
    Unk0216f3dc_68 *v3;
    v1 = 0;
    v3 = &a->mUnk_1d4[b];
    v2 = 1 << b;
    if (v3->mUnk_00 == 2) {
        if (v3->mUnk_01 == 10) {
            v1 = func_02006508(c, v2, v3->mUnk_02);
            v3->mUnk_00 = 1;
        }
    }
    return v1;
}

s32 func_02005d08(Unk0216f3dc *a, s32 b, s32 c, s32 d) {
    s32 v1;
    u16 v2;
    Unk0216f3dc_68 *v3;
    v1 = 0;
    v3 = &a->mUnk_1d4[b];
    v2 = 1 << b;
    if (v3->mUnk_00 == 2) {
        if (v3->mUnk_01 == 8) {
            v1 = func_020065a8(c, v2, v3->mUnk_02, v3->mUnk_10);
            v3->mUnk_00 = 1;
        }
    }
    return v1;
}

s32 func_02005d4c(Unk0216f3dc *a, s32 b, s32 c, s32 d) {
    s32 v1;
    s32 v3;
    u32 v4;
    Unk0216f3dc_68 *v5;
    u16 v2;
    v1 = 0;
    v5 = &a->mUnk_1d4[b];
    v2 = 1 << b;
    if (v5->mUnk_00 == 2) {
        if (v5->mUnk_01 == 2) {
            v3 = func_02006ef8();
            v4 = func_020070d8();
            v1 = func_020067f0(c, v2, v5->mUnk_02, v3, v4, func_020070e4());
            v5->mUnk_00 = 1;
        }
    }
    return v1;
}

u32 func_02005dac(Unk0216f3dc *a, s32 b, const u8 *c, s32 d) {
    s32 v1;
    u32 v2;
    u32 v3;
    BOOL v4;
    Unk0216f3dc_68 *v5;
    Unk0200628c *v6;
    v1 = 0;
    v2 = 1;
    v5 = &a->mUnk_1d4[b];
    v6 = &a->mUnk_1d4[b].mUnk_24;
    v5->mUnk_00 = 1;
    if (d == 0) {
        return 0;
    }
    if (d > 0) {
        do {
            switch (v2) {
                case 1:
                    func_0214d1fc(c, &v5->mUnk_01, 1);
                    c = c + 1;
                    v1 = v1 + 1;
                    v2 = 2;
                    continue;
                case 2:
                    func_0214d1fc(c, &v5->mUnk_08, 2);
                    c = c + 2;
                    v1 = v1 + 2;
                    v2 = v5->mUnk_08;
                    if (func_02006ffc() == -1) {
                        v4 = FALSE;
                    } else {
                        v2 = v2 & (1 << func_02006ffc());
                        if (v2 != 0) {
                            v4 = TRUE;
                        } else {
                            v4 = FALSE;
                        }
                    }
                    if (v4 == FALSE) {
                        return v1;
                    }
                    v2 = 3;
                    continue;
                case 3:
                    func_0214d1fc(c, &v5->mUnk_02, 1);
                    c = c + 1;
                    v1 = v1 + 1;
                    switch (v5->mUnk_01) {
                        case 1:
                            return v1;
                        case 2:
                            v2 = 5;
                            continue;
                        case 3:
                            v2 = 4;
                            continue;
                        case 11:
                            if (a->mUnk_000.mUnk_00 == 10) {
                                func_02006144(a, v5->mUnk_01, b);
                            }
                            return v1;
                        case 10:
                            v2 = 10;
                            continue;
                        default:
                            v2 = 7;
                            continue;
                    }
                case 10:
                    func_0214d1fc(c, &v5->mUnk_0d, 1);
                    c = c + 1;
                    v1 = v1 + 1;
                    v2 = 9;
                    continue;
                case 9:
                    v5->mUnk_20 = (u8 *) c;
                    func_020061d8(a, v5->mUnk_01, b, 0);
                    v5->mUnk_00 = 2;
                    v1 = v1 + 9;
                    return v1;
                case 4:
                    func_0214d1fc(c, &v5->mUnk_0a, 2);
                    c = c + 2;
                    v1 = v1 + 2;
                    if (v5->mUnk_01 == 3) {
                        v2 = 5;
                    }
                    continue;
                case 5:
                    func_0214d1fc(c, &v5->mUnk_06, 2);
                    func_0214d1fc(c + 2, &v5->mUnk_04, 2);
                    if (func_02006ffc() != 0) {
                        func_020070c0(v5->mUnk_04);
                        func_020070cc(v5->mUnk_06);
                    }
                    v3 = v5->mUnk_01;
                    switch (v3) {
                        case 2:
                            func_020061d8(a, v3, b, 0);
                            v5->mUnk_00 = 2;
                            return v1 + 4;
                        case 3:
                            if (a->mUnk_000.mUnk_00 == 2) {
                                func_02006144(a, v3, b);
                            }
                            return v1 + 4;
                        default:
                            func_020061d8(a, 15, b, 3);
                            return v1 + 4;
                    }
                case 7:
                    func_0214d1fc(c, &v5->mUnk_10, 4);
                    c = c + 4;
                    v1 = v1 + 4;
                    v3 = v5->mUnk_01;
                    switch (v3) {
                        case 8:
                            func_020061d8(a, v3, b, 0);
                            v5->mUnk_00 = 2;
                            return v1;
                        case 9:
                            if (a->mUnk_000.mUnk_00 == 4) {
                                if (a->mUnk_000.mUnk_14 == v5->mUnk_10) {
                                    func_02006144(a, 5, b);
                                }
                            } else if (a->mUnk_000.mUnk_00 == 6) {
                                if (a->mUnk_000.mUnk_14 == v5->mUnk_10) {
                                    func_02006144(a, 7, b);
                                }
                            }
                            return v1;
                        case 4:
                        case 5:
                        case 6:
                        case 7:
                            v2 = 8;
                            continue;
                        default:
                            func_020061d8(a, 15, b, 3);
                            continue;
                    }
                case 8:
                    func_0214d1fc(c, &v5->mUnk_14, 4);
                    c = c + 4;
                    v1 = v1 + 4;
                    v3 = v5->mUnk_01;
                    switch (v3) {
                        case 4:
                        case 6:
                            v5->mUnk_00 = 2;
                            return v1;
                        case 5:
                        case 7:
                            v5->mUnk_20 = (u8 *) c;
                            if (a->mUnk_000.mUnk_00 == 4 || a->mUnk_000.mUnk_00 == 6) {
                                if (v5->mUnk_10 == a->mUnk_000.mUnk_14) {
                                    if ((a->mUnk_000.mUnk_08 & (u16) (1 << b)) != 0) {
                                        if (func_02006380(v6, v5->mUnk_14) == 0) {
                                            if (func_0200628c(v6, v5->mUnk_14, v5->mUnk_20) == 1) {
                                                func_0200635c(v6, v5->mUnk_14);
                                            } else {
                                                func_020061d8(a, 15, b, 6);
                                            }
                                        }
                                    }
                                }
                            }
                            return v1;
                        default:
                            func_020061d8(a, 15, b, 3);
                            continue;
                    }
                default:
                    func_020061d8(a, 15, b, 4);
                    continue;
            }
        } while (v1 < d);
    }
    func_020061d8(a, 15, b, 5);
    return v1;
}

void func_02006144(Unk0216f3dc *a, s32 b, s32 c) {
    u16 v1;
    u8 v4;
    Unk0216f3dc_68 *v2;
    v2 = &a->mUnk_1d4[c];
    v1 = 1 << c;
    a->mUnk_000.mUnk_0a = v1;
    v4 = v2->mUnk_02;
    if (a->mUnk_000.mUnk_0c == v4) {
        a->mUnk_000.mUnk_0d = v4;
        if ((a->mUnk_000.mUnk_08 & v1) != 0) {
            a->mUnk_000.mUnk_08 &= ~v1;
            switch (b) {
                case 3:
                    *(s16 *) &a->mUnk_000.mUnk_14 = v2->mUnk_0a;
                    *((s16 *) &a->mUnk_000.mUnk_14 + 1) = v2->mUnk_06;
                    *(s16 *) &a->mUnk_000.mUnk_18 = v2->mUnk_04;
                    break;
                case 0:
                case 1:
                case 2:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                    break;
            }
            a->mUnk_000.mUnk_04 = b;
            if (a->mUnk_000.mUnk_10 != NULL) {
                a->mUnk_000.mUnk_10(&a->mUnk_000);
            }
        }
        if (a->mUnk_000.mUnk_08 == 0) {
            a->mUnk_000.mUnk_00 = 0;
        }
    }
}

void func_020061d8(Unk0216f3dc *a, s32 b, s32 c, u32 d) {
    Unk0216f3dc_68 *v2;
    Unk0216f3dc_9c *v1;
    v1 = &a->mUnk_138;
    v2 = &a->mUnk_1d4[c];
    if (b == 13 || v2->mUnk_02 != v2->mUnk_03) {
        v1->mUnk_00 = 12;
        v1->mUnk_0a = 1 << c;
        v2->mUnk_03 = v2->mUnk_02;
        v1->mUnk_0d = v2->mUnk_02;
        v1->mUnk_0e = d;
        switch (b) {
            case 8:
                v1->mUnk_14 = v2->mUnk_10;
                break;
            case 2:
                *(s16 *) &v1->mUnk_14 = v2->mUnk_0a;
                *((s16 *) &v1->mUnk_14 + 1) = v2->mUnk_06;
                *(s16 *) &v1->mUnk_18 = v2->mUnk_04;
                break;
            case 10:
                if (v2->mUnk_0d > 9) {
                    *((u8 *) &v1->mUnk_1c[0] + 1) = 0;
                } else {
                    *((u8 *) &v1->mUnk_1c[0] + 1) = v2->mUnk_0d;
                    func_0214d1fc(v2->mUnk_20, &v1->mUnk_14, *((u8 *) &v1->mUnk_1c[0] + 1));
                }
                break;
            case 12:
            case 14:
                break;
        }
        v1->mUnk_04 = b;
        if (v1->mUnk_10 != NULL) {
            v1->mUnk_10(v1);
        }
    }
}

BOOL func_0200628c(Unk0200628c *a, s32 b, const u8 *c) {
    u32 v1;
    u8 *v2;
    u32 v3;
    v1 = func_020070e4();
    v2 = a->mUnk_18;
    if (b < a->mUnk_04) {
        if (b == a->mUnk_04 - 1) {
            v3 = (u32) (_s32_div_f(a->mUnk_00, v1) >> 32);
            if (v3 != 0) {
                func_0214d1fc(c, v2 + b * v1, v3);
            } else {
                func_0214d1fc(c, v2 + b * v1, v1);
            }
        } else {
            func_0214d1fc(c, v2 + b * v1, v1);
        }
    } else {
        return FALSE;
    }
    return TRUE;
}

s32 func_020062f4(Unk0200628c *a) {
    s32 v1;
    s32 v2;
    s32 v3;
    u32 *v4;
    s32 v6;
    u32 *v5;
    v1 = a->mUnk_0c + 1;
    v6 = a->mUnk_04;
    if (v1 >= v6) {
        v1 = 0;
    }
    v2 = v1;
    v5 = a->mUnk_14;
    v4 = v5 + (v1 >> 5);
    v3 = v1 & 0x1f;
    do {
        if ((*v4 & (1 << v3)) == 0) {
            goto found;
        }
        v1 = v1 + 1;
        if (v1 < v6) {
            v3 = v3 + 1;
            if (v3 > 0x1f) {
                v3 = 0;
                v4 = v4 + 1;
            }
        } else {
            v1 = 0;
            v3 = v1;
            v4 = v5;
        }
    } while (v1 != v2);
    goto fail;
found:
    a->mUnk_08 = v1;
    return v1;
fail:
    return -1;
}

#pragma thumb off
