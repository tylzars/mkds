#include "00/code_021a1ae0.h"
#include "00/code_021a10b0.h"
#include "code_02139f70.h"
#include "00/code_0219e4e8.h"

void func_ov000_021a1ae0(u32 param_1, u32 param_2, u8 *param_3) {
    u32 v1[33];
    u8 v2[16];
    const u8 **e;
    s32 i;
    u32 *q;
    e = 0;
    i = 0;
    q = v1;
    do {
        if (func_ov000_021a0958(v2, param_3 + 1, i) == -1) {
            break;
        }
        *q = func_0213c074(v2, e, 10);
        q++;
        i++;
    } while (i < 0x80);
    func_ov000_021a01dc(param_3[0], param_2, 0, 0, v1, i);
}

void func_ov000_021a1b2c(Unk0219887c *param_1, s32 param_2) {
    Unk021b566c *p;
    s32 i;
    void **q;
    Unk021b5550 *e;
    char v1[12];
    p = data_ov000_021b566c;
    if (p == 0) {
        return;
    }
    if (p->mUnk_198 != 7 && p->mUnk_198 != 12) {
        return;
    }
    if (param_2 != 0) {
        if (param_2 == 5) {
            return;
        }
        if (param_2 == 6) {
            p->mUnk_0c++;
            p = data_ov000_021b566c;
            if (p->mUnk_0c > 5) {
                p->mUnk_0c = 0;
                func_ov000_0219f9bc(data_ov000_021b566c->mUnk_f4[data_ov000_021b566c->mUnk_0d + 1]);
                return;
            }
            func_0200d9e0(v1, 12, data_ov000_021b40b8, p->mUnk_1e8);
            p = data_ov000_021b566c;
            if (func_ov000_0219e3e4(func_ov000_02198968(
                    *data_ov000_021b566c->mUnk_04, 0,
                    func_ov000_0219a760(p->mUnk_1f8[p->mUnk_14],
                                        ((const Unk021b566c *) p)->mUnk_278[((const Unk021b566c *) p)->mUnk_14], 0),
                    v1, -1, 5000, p->mUnk_08, 0)) == 0) {
                return;
            }
            return;
        }
        if (param_2 == 2) {
            if (func_ov000_0219f9bc(data_ov000_021b566c->mUnk_f4[data_ov000_021b566c->mUnk_0d + 1]) == 0) {
                return;
            }
            return;
        }
        func_ov000_0219e3e4(param_2);
        return;
    }
    i = func_ov000_0219b998();
    if (i == -1) {
        func_ov000_021a1a38(6, -87100);
    }
    q = func_ov000_0219b958(i);
    e = func_ov000_0219b8f0(i);
    *q = param_1;
    data_ov000_021b566c->mUnk_0d++;
    e->mUnk_00 = i;
    e->mUnk_02 = 0;
    e->mUnk_04 = 0;
    e->mUnk_01 = data_ov000_021b566c->mUnk_2b8[data_ov000_021b566c->mUnk_0d];
    func_ov000_021988a4(param_1, e);
    if (data_ov000_021b566c->mUnk_198 == 12) {
        func_ov000_0219f544(0);
        return;
    }
    func_ov000_0219f544(1);
}

// non-matching: original keeps param_3 in r7 and spills param_4 ([sp, #0]) and a data pointer loaded before the strtol
// call ([sp, #4], used for the f4 compare); ours holds p in r7 and spills param_3/param_4 (0x194 bytes against 0x198)
void func_ov000_021a1ca8(u32 param_1, Unk0219887c *param_2, u32 param_3, u32 param_4, s32 param_5, u8 *param_6) {
    Unk021b566c *p;
    Unk021b5550 *e;
    void **q;
    s32 i;
    s32 j;
    s32 t;
    p = data_ov000_021b566c;
    if (p == 0 || p->mUnk_198 != 7 || p->mUnk_1a1 != 0) {
        func_ov000_02198a74((Unk02197fe8 *) param_2, data_ov000_021b41b0, -1);
        return;
    }
    i = func_ov000_0219b998();
    if (i == -1) {
        func_ov000_02198a74((Unk02197fe8 *) param_2, data_ov000_021b41bc, -1);
        func_ov000_021a1a38(6, -87100);
        return;
    }
    p = data_ov000_021b566c;
    j = p->mUnk_0d;
    if (param_3 != p->mUnk_1f8[j] || param_4 != p->mUnk_278[j]) {
        if (*param_6 != 0 && p->mUnk_f4[j] == func_0213c074(param_6, 0, 10)) {
            data_ov000_021b566c->mUnk_1f8[j] = param_3;
            data_ov000_021b566c->mUnk_278[data_ov000_021b566c->mUnk_0d] = param_4;
        } else {
            func_ov000_02198a74((Unk02197fe8 *) param_2, data_ov000_021b41c8, -1);
            return;
        }
    }
    data_ov000_021b566c->mUnk_184 = 0;
    if (func_ov000_02198a7c((Unk02197fe8 *) param_2, (Unk02198778 *) data_ov000_021b566c->mUnk_08) == 0) {
        func_ov000_021a1a38(6, -80410);
        return;
    }
    func_ov000_021a1ac0();
    p = data_ov000_021b566c;
    if (p->mUnk_0d == 0) {
        t = param_5 >> 1;
        if (t >= 0xffff) {
            t = 0xffff;
        }
        p->mUnk_1a6 = t;
    }
    q = func_ov000_0219b958(i);
    e = func_ov000_0219b8f0(i);
    *q = param_2;
    data_ov000_021b566c->mUnk_0d++;
    e->mUnk_00 = i;
    e->mUnk_01 = data_ov000_021b566c->mUnk_2b8[data_ov000_021b566c->mUnk_0d - 1];
    e->mUnk_02 = 0;
    e->mUnk_04 = 0;
    func_ov000_021988a4(param_2, e);
    func_ov000_0219f544(2);
}

// non-matching: original keeps the tail `cmp r5, #254; bne; movs r0, #0` and a second `movs r0, #0` return (0xb4 bytes)
// and holds the first byte in r5; ours folds the identical returns into one (0xa4 bytes) and uses r1
u32 func_ov000_021a1e40(u32 param_1, u32 param_2, u16 param_3, u8 *param_4, u32 param_5) {
    Unk021a1e40 a;
    volatile u32 v; // placeholder: value passed through a stack offset
    u32 c;
    if (param_5 == 0 || param_4 == 0) {
        return 0;
    }
    v = 0;
    func_0214d018(v, &a, 8);
    a.mUnk_01 = 2;
    a.mUnk_04 = param_2;
    a.mUnk_02 = ((param_3 >> 8) & 0xff) | ((param_3 << 8) & 0xff00);
    c = param_4[0];
    if ((c == 0xfe && param_4[1] == 0xfd) || c == 0x5c) {
        if (data_ov000_021b566c->mUnk_10 != 0) {
            func_ov000_021a3c14((Unk021a3a18 *) data_ov000_021b566c->mUnk_10, (s8 *) param_4, param_5, &a);
        }
    } else if (func_02134d30(param_4, data_ov000_021b400c, 6) == 0) {
        func_ov000_0219a7e4(param_4, param_5, &a);
    } else {
        if (c == 0xfe) {
            return 0;
        }
        return 0;
    }
    return 1;
}

// non-matching: original computes `muls r1, r0 (3000); adds r5, r1, r0` for the two timeouts, ours folds to `adds r5,
// r0, #1; muls r5, r0` (0x56c bytes against 0x574, branch targets and jump table words shift)
void func_ov000_021a1ef4(s32 param_1) {
    Unk021b566c *p;
    u32 n;
    if (data_ov000_021b566c == 0) {
        return;
    }
    if (func_ov000_0219c39c() != 0) {
        return;
    }
    if (param_1 == 0) {
        if (data_ov000_021b566c->mUnk_10 != 0) {
            func_ov000_021a49a0(data_ov000_021b566c->mUnk_10);
        }
        if (data_ov000_021b566c->mUnk_04 != 0) {
            func_ov000_02198a8c(*data_ov000_021b566c->mUnk_04);
        }
        return;
    }
    p = data_ov000_021b566c;
    if (p->mUnk_198 == 0) {
        return;
    }
    switch (p->mUnk_198) {
        case 4:
            if (p->mUnk_1bc != 0) {
                if ((func_0200f5ac() - p->mUnk_1c0) * 64 / 0x82ea > p->mUnk_1bc) {
                    p->mUnk_1bc = 0;
                    p = data_ov000_021b566c;
                    if (p->mUnk_15 == 3) {
                        p->mUnk_1a2++;
                        p = data_ov000_021b566c;
                        if (p->mUnk_1a2 > 5) {
                            func_ov000_021a1a38(6, -80430);
                            return;
                        }
                        if (func_ov000_0219fee4(func_ov000_0219fdc8(p->mUnk_f4[0], 0)) != 0) {
                            return;
                        }
                    } else if (func_ov000_0219fb48(p->mUnk_15) == 0) {
                        return;
                    }
                }
            }
            p = data_ov000_021b566c;
            if (p->mUnk_1b0 != 0) {
                n = p->mUnk_0d * 3000 + 3000;
                if ((func_0200f5ac() - p->mUnk_1b4) * 64 / 0x82ea >= n) {
                    if (func_ov000_0219fee4(func_ov000_0219fdc8(p->mUnk_f4[0], 0)) != 0) {
                        return;
                    }
                }
            }
            break;
        case 2:
        case 3:
        case 5:
            if (p->mUnk_e8 > 0) {
                if (p->mUnk_198 == 3) {
                    n = p->mUnk_0d * 3000 + 3000;
                } else if (p->mUnk_e8 == 1) {
                    n = 1000;
                } else {
                    n = 3000;
                }
                if ((func_0200f5ac() - p->mUnk_ec) * 64 / 0x82ea > n) {
                    if (func_ov000_0219e594(func_ov000_021a0f20(p->mUnk_1ec)) != 0) {
                        return;
                    }
                    data_ov000_021b566c->mUnk_e8 = 0;
                }
            }
            break;
        case 7:
            if (p->mUnk_184 != 0) {
                if (func_ov000_021a350c() - p->mUnk_184 > 25000) {
                    data_ov000_021b566c->mUnk_184 = 0;
                    if (func_ov000_0219f938(data_ov000_021b566c->mUnk_f4[0]) == 0) {
                        return;
                    }
                }
            } else if (p->mUnk_3b4 == 6) {
                if (func_ov000_021a350c() - p->mUnk_444 > 6000) {
                    p->mUnk_3b5++;
                    p = data_ov000_021b566c;
                    if (p->mUnk_3b5 > 5) {
                        func_ov000_021a1ac0();
                        if (func_ov000_0219f938(data_ov000_021b566c->mUnk_f4[0]) == 0) {
                            return;
                        }
                    } else if (func_ov000_0219fee4(func_ov000_021a0ae8(6, p->mUnk_43c, p->mUnk_3b8, p->mUnk_3b6,
                                                                       p->mUnk_3bc, p->mUnk_440)) != 0) {
                        return;
                    }
                }
            }
            break;
        case 11:
            if (p->mUnk_3b4 == 2) {
                if ((p->mUnk_15 == 0 && func_ov000_021a350c() - data_ov000_021b566c->mUnk_444 > 6000) ||
                    func_ov000_021a350c() - data_ov000_021b566c->mUnk_444 > 19000) {
                    func_ov000_021a1ac0();
                    if (func_ov000_0219f9bc(data_ov000_021b566c->mUnk_f4[data_ov000_021b566c->mUnk_0d + 1]) == 0) {
                        return;
                    }
                }
            }
            break;
        case 13:
            if (p->mUnk_3b4 == 8) {
                if (func_ov000_021a350c() - p->mUnk_444 > 30000) {
                    p->mUnk_3b5++;
                    p = data_ov000_021b566c;
                    if (p->mUnk_3b5 != 0) {
                        func_ov000_021a1ac0();
                        p = data_ov000_021b566c;
                        if (p->mUnk_15 == 2) {
                            if (func_ov000_0219f9bc(p->mUnk_f4[p->mUnk_0d + 1]) == 0) {
                                return;
                            }
                        } else {
                            func_ov000_0219f214();
                        }
                    } else if (func_ov000_0219fee4(func_ov000_021a0ae8(8, p->mUnk_43c, p->mUnk_3b8, p->mUnk_3b6,
                                                                       p->mUnk_3bc, p->mUnk_440)) != 0) {
                        return;
                    }
                }
            }
            break;
    }
    p = data_ov000_021b566c;
    if (p->mUnk_198 == 11 || p->mUnk_198 == 6) {
        if (p->mUnk_17c != 0) {
            if (func_ov000_021a350c() - p->mUnk_17c > 10000) {
                func_ov000_0219db18(1, 0, 0, p->mUnk_18c);
            }
        }
    }
    if (data_ov000_021b566c->mUnk_e4 != 0) {
        func_ov000_0218b4bc(data_ov000_021b566c->mUnk_e4);
    }
    if (data_ov000_021b566c->mUnk_10 != 0) {
        func_ov000_021a49a0(data_ov000_021b566c->mUnk_10);
        p = data_ov000_021b566c;
        if ((*(s32 *) ((u8 *) p->mUnk_10 + 0xb4) == 0 && (p->mUnk_15 == 0 || p->mUnk_15 == 1) &&
             (p->mUnk_198 == 1 || p->mUnk_198 == 2 || p->mUnk_198 == 3 || p->mUnk_198 == 4 || p->mUnk_198 == 6 ||
              p->mUnk_198 == 11)) ||
            (p->mUnk_15 == 2 && p->mUnk_198 == 11)) {
            func_ov000_021a4818(p->mUnk_10);
        }
    }
    func_ov000_0219aaec();
    if (data_ov000_021b566c->mUnk_04 != 0) {
        func_ov000_02198a8c(*data_ov000_021b566c->mUnk_04);
    }
    p = data_ov000_021b566c;
    if (p->mUnk_198 == 18) {
        if (func_ov000_021a350c() - p->mUnk_1e0 > 3000) {
            if (func_ov000_0219f184() != 0) {
                return;
            }
        }
    }
    if (func_ov000_0219ee14() != 0) {
        if (func_ov000_0219eaf4() != 0) {
            func_ov000_0219e668();
        }
    }
}

void func_ov000_021a2468(const void *param_1, s32 param_2, s32 param_3, s32 param_4, u32 param_5, u32 param_6,
                         u32 param_7, u32 param_8) {
    char v1[12];
    u8 v2[0x24];
    ((void (*)(u32, u32, u32, u32)) func_ov000_021a10b0)(1, param_3, param_5, param_6);
    data_ov000_021b566c->mUnk_19e = param_4 != 0 ? 1 : 0;
    data_ov000_021b566c->mUnk_45c = param_7;
    data_ov000_021b566c->mUnk_460 = param_8;
    func_0214d1fc(param_1, data_ov000_021b566c->mUnk_2ec, param_2);
    data_ov000_021b566c->mUnk_32c = param_2;
    if (param_2 == 0 || (param_2 < param_3 && param_4 == 0 &&
                         (data_ov000_021b5670 == 0 || data_ov000_021b5670->mUnk_00 == 0 ||
                          param_2 < data_ov000_021b5670->mUnk_01 - 1))) {
        func_ov000_021a1a38(7, 0);
        return;
    }
    data_ov000_021b566c->mUnk_198 = 4;
    if (data_ov000_021b566c->mUnk_e4 == 0) {
        data_ov000_021b566c->mUnk_e4 =
            func_ov000_0218b668(data_ov000_021b566c->mUnk_2dc, data_ov000_021b566c->mUnk_2dc,
                                data_ov000_021b566c->mUnk_2e0, 0, 20, 1, 0, func_ov000_0219e138, 0);
    }
    if (data_ov000_021b566c->mUnk_e4 == 0 && func_ov000_0219e594(5) != 0) {
        return;
    }
    func_0200d9e0(v1, 12, data_ov000_021b40b8, param_3);
    func_ov000_021a363c(data_ov000_021b411c, v1, v2, 0x2f);
    func_ov000_021a360c(data_ov000_021b4120, param_4 != 0 ? data_ov000_021b41e0 : data_ov000_021b41e4, v2, 0x2f);
    func_0200d9e0(v1, 12, data_ov000_021b40b8, 3);
    func_ov000_021a360c(data_ov000_021b4118, v1, v2, 0x2f);
    if (func_ov000_0219e608(func_ov000_0219d558(4, v2, 0)) != 0) {
        return;
    }
    if (func_ov000_0219fee4(func_ov000_0219fbec(0, 1)) != 0) {
        return;
    }
    if (data_ov000_021b566c->mUnk_10 == 0) {
        func_ov000_021a2768(data_ov000_021b566c->mUnk_1e8);
    }
    func_ov000_0219e8b8(0);
}

void func_ov000_021a260c(u32 param_1, const void *param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6) {
    u8 v1[0x100];
    s32 n;
    if (data_ov000_021b5674 != 0) {
        func_ov000_021a3704(4, (u32) data_ov000_021b5674, 0);
        data_ov000_021b5674 = 0;
    }
    if (param_2 != 0) {
        n = func_ov000_021a0ed8(v1, -1, 0x20, 3);
        n = 0x100 - n - func_0213a434(data_ov000_021b41e8);
        data_ov000_021b5674 = func_ov000_021a372c(4, n);
        if (data_ov000_021b5674 == 0) {
            func_ov000_021a1a38(11, -80001);
            return;
        }
        func_0214d1fc(param_2, data_ov000_021b5674, n);
        *((u8 *) data_ov000_021b5674 + n - 1) = 0;
    }
    ((void (*)(u32, u32, u32, u32)) func_ov000_021a10b0)(0, param_1, param_3, param_4);
    data_ov000_021b566c->mUnk_45c = param_5;
    data_ov000_021b566c->mUnk_460 = param_6;
    data_ov000_021b566c->mUnk_198 = 2;
    if (data_ov000_021b566c->mUnk_e4 == 0) {
        data_ov000_021b566c->mUnk_e4 =
            func_ov000_0218b668(data_ov000_021b566c->mUnk_2dc, data_ov000_021b566c->mUnk_2dc,
                                data_ov000_021b566c->mUnk_2e0, 0, 20, 1, 0, func_ov000_0219e138, 0);
    }
    if (data_ov000_021b566c->mUnk_e4 == 0 && func_ov000_0219e594(5) != 0) {
        return;
    }
    func_ov000_0219d558(3, data_ov000_021b4114, 0);
    if (func_ov000_0219e594(func_ov000_021a0f20(data_ov000_021b566c->mUnk_1e8)) != 0) {
        return;
    }
    if (data_ov000_021b566c->mUnk_10 == 0) {
        func_ov000_021a2768(data_ov000_021b566c->mUnk_1e8);
    }
    func_ov000_0219e8b8(0);
}

u32 func_ov000_021a2768(u32 param_1) {
    Unk021b566c *p;
    s32 i;
    u32 r;
    p = data_ov000_021b566c;
    if (p->mUnk_10 != 0) {
        return 0;
    }
    p->mUnk_1e8 = param_1;
    i = 0;
    do {
        p = data_ov000_021b566c;
        r = func_ov000_021a4a08((Unk021a4a08 **) &data_ov000_021b566c->mUnk_10, func_ov000_021988d8(*p->mUnk_04),
                                func_ov000_021988e4(*p->mUnk_04), (const u8 *) p->mUnk_2dc, (const u8 *) p->mUnk_2e0, 1,
                                1, (Unk021a4a08Func88) func_ov000_0219dee0, (Unk021a4a08Func8c) func_ov000_0219dedc,
                                (Unk021a4a08Func8c) func_ov000_0219ded8, (Unk021a4a08Func94) func_ov000_0219de68,
                                (Unk021a4a08Func98) func_ov000_0219de64, (Unk021a4a08Func9c) func_ov000_0219de5c, 0);
        if (r == 0) {
            break;
        }
        if (r != 3 || i == 4) {
            func_ov000_0219e4e8(r);
            return r;
        }
        i++;
    } while (i < 5);
    data_ov000_021b566c->mUnk_1c = 0;
    data_ov000_021b566c->mUnk_1a = 0;
    func_ov000_021a49cc(data_ov000_021b566c->mUnk_10, func_ov000_0219de4c);
    func_ov000_021a49f4(data_ov000_021b566c->mUnk_10, func_ov000_0219ddbc);
    func_ov000_021a49e0(data_ov000_021b566c->mUnk_10, func_ov000_0219dd4c);
    func_ov000_021a4818(data_ov000_021b566c->mUnk_10);
    return r;
}

void func_ov000_021a2870(Unk021b566c *param_1, int *param_2, void **param_3, u32 param_4, u32 param_5, u32 param_6,
                         u32 param_7, u32 param_8) {
    data_ov000_021b566c = param_1;
    param_1->mUnk_00 = param_2;
    data_ov000_021b566c->mUnk_04 = param_3;
    data_ov000_021b566c->mUnk_08 = param_4;
    data_ov000_021b566c->mUnk_10 = 0;
    data_ov000_021b566c->mUnk_1c = 0;
    data_ov000_021b566c->mUnk_1a = 0;
    data_ov000_021b566c->mUnk_e4 = 0;
    data_ov000_021b566c->mUnk_198 = 0;
    data_ov000_021b566c->mUnk_0f = 0;
    data_ov000_021b566c->mUnk_19 = 0;
    data_ov000_021b566c->mUnk_1a5 = 0;
    data_ov000_021b566c->mUnk_1e8 = 0;
    data_ov000_021b566c->mUnk_2dc = param_5;
    data_ov000_021b566c->mUnk_2e0 = param_6;
    data_ov000_021b566c->mUnk_2e4 = param_7;
    data_ov000_021b566c->mUnk_2e8 = param_8;
    func_0214d168(data_ov000_021b566c->mUnk_2ec, 0, 0x40);
    data_ov000_021b566c->mUnk_32c = 0;
    data_ov000_021b566c->mUnk_44c = 0;
    data_ov000_021b566c->mUnk_450 = 0;
    data_ov000_021b566c->mUnk_45c = 0;
    data_ov000_021b566c->mUnk_460 = 0;
    func_ov000_0219ea88();
    data_ov000_021b5668.mUnk_00 = 0;
    data_ov000_021b5668.mUnk_01 = 0;
    data_ov000_021b5668.mUnk_02 = 0;
    func_ov000_021a1140(0);
}
