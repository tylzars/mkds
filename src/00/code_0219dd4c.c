#include "00/code_0219dd4c.h"

#include "00/code_021a0958.h"
#include "00/unk_021b4000.h"
#include "00/unk_021b5000.h"
#include "00/code_0219e4e8.h"
#include "00/code_0219e134.h"
#include "00/code_021a01dc.h"
#include "code_02139f70.h"
#include "code_0214d018.h"
#include "00/code_0219de4c.h"
#include "00/code_0219de5c.h"
#include "00/code_0219eac8.h"
#include "00/code_0218e2dc.h"
#include "00/code_021a3a18.h"
#include "00/code_0218aea4.h"
#include "00/code_0219dee0.h"
#include "00/code_0218b000.h"
#include "00/code_0218d000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b2000.h"
#include "code_02134398.h"
#include "00/code_0218d818.h"
#include "00/code_021a3264.h"
#include "00/code_021a2950.h"
#include "00/code_0219fb48.h"
#include "00/code_0219f000.h"
#include "00/code_021a0000.h"
#include "00/code_0219f4c4.h"
#include "code_0200f5ac.h"
#include "00/code_0219c954.h"
#include "00/code_0219eaf4.h"
#include "00/code_0219b580.h"
#include "00/code_0219c000.h"
#include "00/code_0219c384.h"
#include "00/code_021a17bc.h"
#include "03/code_021b94b8.h"
#include "00/code_021a369c.h"
#include "00/code_0219d000.h"
#include "00/code_0219e000.h"
#include "00/code_0219a654.h"
#include "00/code_0219d128.h"
#include "00/code_021988e8.h"
#include "00/code_0219a000.h"
#include "00/code_0219b000.h"
#include "00/code_0219f9bc.h"
#include "00/code_021a1000.h"
#include "code_0200d118.h"
#include "00/code_021a10b0.h"
#include "00/code_0218f960.h"
#include "00/code_02194000.h"
#include "00/code_0218e8d4.h"
#include "00/code_0218a000.h"
#include "00/code_0218c000.h"
#include "Main/Unknown/code_02152698.h"
#include "code_0213a460.h"
#include "code_02152500.h"
#include "00/code_0219dabc.h"
#include "00/code_0219887c.h"
#include "00/code_0219dd48.h"
#include "00/code_021a8878.h"
#include "00/code_021a8aa8.h"
#include "00/code_021a4000.h"
#include "00/code_021a4b84.h"
#include "00/code_02188720.h"
#include "code_0214cfe4.h"
#include "00/code_021a1ac0.h"
#include "00/code_02198a8c.h"
#include "00/code_021a1ae0.h"

void func_ov000_021a2870(Unk021b566c *param_1, GpConnection *param_2, void **param_3, void *param_4, void *param_5,
                         void *param_6, void *param_7, u32 param_8) {
    data_ov000_021b566c = param_1;
    param_1->mUnk_00 = param_2;
    data_ov000_021b566c->mUnk_04 = param_3;
    data_ov000_021b566c->mUnk_08 = (u32) param_4;
    data_ov000_021b566c->mUnk_10 = NULL;
    data_ov000_021b566c->mUnk_1c = NULL;
    data_ov000_021b566c->mUnk_1a = 0;
    data_ov000_021b566c->mUnk_e4 = NULL;
    data_ov000_021b566c->mUnk_198 = 0;
    data_ov000_021b566c->mUnk_0f = 0;
    data_ov000_021b566c->mUnk_19 = 0;
    data_ov000_021b566c->mUnk_1a5 = 0;
    data_ov000_021b566c->mUnk_1e8 = 0;
    data_ov000_021b566c->mUnk_2dc = (u32) param_5;
    data_ov000_021b566c->mUnk_2e0 = (u32) param_6;
    data_ov000_021b566c->mUnk_2e4 = (u32) param_7;
    data_ov000_021b566c->mUnk_2e8 = param_8;
    MemFill(data_ov000_021b566c->mUnk_2ec, 0, 0x40);
    data_ov000_021b566c->mUnk_32c = 0;
    data_ov000_021b566c->mUnk_44c = NULL;
    data_ov000_021b566c->mUnk_450 = 0;
    data_ov000_021b566c->mUnk_45c = 0;
    data_ov000_021b566c->mUnk_460 = 0;
    func_ov000_0219ea88();
    data_ov000_021b5668.mUnk_00 = 0;
    data_ov000_021b5668.mUnk_01 = 0;
    data_ov000_021b5668.mUnk_02 = 0;
    func_ov000_021a1140(0);
}

u32 func_ov000_021a2768(u32 param_1) {
    Unk021b566c *p;
    s32 i;
    u32 r;
    p = data_ov000_021b566c;
    if (p->mUnk_10 != NULL) {
        return 0;
    }
    p->mUnk_1e8 = param_1;
    i = 0;
    do {
        p = data_ov000_021b566c;
        r = func_ov000_021a4a08(&data_ov000_021b566c->mUnk_10, GetSocketDescriptor(*p->mUnk_04),
                                GetSocketPort(*p->mUnk_04), (const char *) p->mUnk_2dc, (const char *) p->mUnk_2e0, 1,
                                1, (Unk021a4a08Func88) func_ov000_0219dee0, (Unk021a4a08Func8c) func_ov000_0219dedc,
                                (Unk021a4a08Func8c) func_ov000_0219ded8, (Unk021a4a08Func94) func_ov000_0219de68,
                                (Unk021a4a08Func98) func_ov000_0219de64, (Unk021a4a08Func9c) func_ov000_0219de5c, NULL);
        if (r == 0) {
            break;
        }
        if (r != 3 || i == 4) {
            func_ov000_0219e4e8(r);
            return r;
        }
        i++;
    } while (i < 5);
    data_ov000_021b566c->mUnk_1c = NULL;
    data_ov000_021b566c->mUnk_1a = 0;
    func_ov000_021a49cc(data_ov000_021b566c->mUnk_10, func_ov000_0219de4c);
    func_ov000_021a49f4(data_ov000_021b566c->mUnk_10, func_ov000_0219ddbc);
    func_ov000_021a49e0(data_ov000_021b566c->mUnk_10, func_ov000_0219dd4c);
    func_ov000_021a4818(data_ov000_021b566c->mUnk_10);
    return r;
}

void func_ov000_021a260c(u32 param_1, const void *param_2, u32 param_3, u32 param_4, u32 param_5, u32 param_6) {
    char v1[0x100];
    s32 n;
    if (data_ov000_021b5674 != NULL) {
        func_ov000_021a3704(4, (u32) data_ov000_021b5674, 0);
        data_ov000_021b5674 = NULL;
    }
    if (param_2 != NULL) {
        n = func_ov000_021a0ed8(v1, -1, 0x20, 3);
        n = 0x100 - n - strlen(data_ov000_021b41e8);
        data_ov000_021b5674 = func_ov000_021a372c(4, n);
        if (data_ov000_021b5674 == NULL) {
            func_ov000_021a1a38(11, -80001);
            return;
        }
        MemCopy(param_2, data_ov000_021b5674, n);
        *((u8 *) data_ov000_021b5674 + n - 1) = 0;
    }
    ((void (*)(u32, u32, u32, u32)) func_ov000_021a10b0)(0, param_1, param_3, param_4);
    data_ov000_021b566c->mUnk_45c = param_5;
    data_ov000_021b566c->mUnk_460 = param_6;
    data_ov000_021b566c->mUnk_198 = 2;
    if (data_ov000_021b566c->mUnk_e4 == NULL) {
        data_ov000_021b566c->mUnk_e4 =
            func_ov000_0218b668(data_ov000_021b566c->mUnk_2dc, data_ov000_021b566c->mUnk_2dc,
                                data_ov000_021b566c->mUnk_2e0, 0, 20, 1, 0, func_ov000_0219e138, 0);
    }
    if (data_ov000_021b566c->mUnk_e4 == NULL && func_ov000_0219e594(5) != 0) {
        return;
    }
    func_ov000_0219d558(3, data_ov000_021b4114, NULL);
    if (func_ov000_0219e594(func_ov000_021a0f20(data_ov000_021b566c->mUnk_1e8)) != 0) {
        return;
    }
    if (data_ov000_021b566c->mUnk_10 == NULL) {
        func_ov000_021a2768(data_ov000_021b566c->mUnk_1e8);
    }
    func_ov000_0219e8b8(0);
}

void func_ov000_021a2468(const void *param_1, s32 param_2, s32 param_3, s32 param_4, void *param_5, u32 param_6,
                         u32 param_7, u32 param_8) {
    char v1[12];
    u8 v2[0x24];
    ((void (*)(u32, u32, u32, u32)) func_ov000_021a10b0)(1, param_3, (u32) param_5, param_6);
    data_ov000_021b566c->mUnk_19e = param_4 != 0 ? 1 : 0;
    data_ov000_021b566c->mUnk_45c = param_7;
    data_ov000_021b566c->mUnk_460 = param_8;
    MemCopy(param_1, data_ov000_021b566c->mUnk_2ec, param_2);
    data_ov000_021b566c->mUnk_32c = param_2;
    if (param_2 == 0 || (param_2 < param_3 && param_4 == 0 &&
                         (data_ov000_021b5670 == NULL || data_ov000_021b5670->mUnk_00 == 0 ||
                          param_2 < data_ov000_021b5670->mUnk_01 - 1))) {
        func_ov000_021a1a38(7, 0);
        return;
    }
    data_ov000_021b566c->mUnk_198 = 4;
    if (data_ov000_021b566c->mUnk_e4 == NULL) {
        data_ov000_021b566c->mUnk_e4 =
            func_ov000_0218b668(data_ov000_021b566c->mUnk_2dc, data_ov000_021b566c->mUnk_2dc,
                                data_ov000_021b566c->mUnk_2e0, 0, 20, 1, 0, func_ov000_0219e138, 0);
    }
    if (data_ov000_021b566c->mUnk_e4 == NULL && func_ov000_0219e594(5) != 0) {
        return;
    }
    StringFormatBounded(v1, 12, data_ov000_021b40b8, param_3);
    func_ov000_021a363c(data_ov000_021b411c, v1, v2, 0x2f);
    func_ov000_021a360c(data_ov000_021b4120, param_4 != 0 ? data_ov000_021b41e0 : data_ov000_021b41e4, v2, 0x2f);
    StringFormatBounded(v1, 12, data_ov000_021b40b8, 3);
    func_ov000_021a360c(data_ov000_021b4118, v1, v2, 0x2f);
    if (func_ov000_0219e608(func_ov000_0219d558(4, v2, NULL)) != 0) {
        return;
    }
    if (func_ov000_0219fee4(func_ov000_0219fbec(0, 1)) != 0) {
        return;
    }
    if (data_ov000_021b566c->mUnk_10 == NULL) {
        func_ov000_021a2768(data_ov000_021b566c->mUnk_1e8);
    }
    func_ov000_0219e8b8(0);
}

void func_ov000_021a1ef4(s32 param_1) {
    Unk021b566c *p;
    u32 n;
    Unk021a4a08 *q;
    if (data_ov000_021b566c == NULL) {
        return;
    }
    if (func_ov000_0219c39c() != 0) {
        return;
    }
    if (param_1 == 0) {
        if (data_ov000_021b566c->mUnk_10 != NULL) {
            func_ov000_021a49a0(data_ov000_021b566c->mUnk_10);
        }
        if (data_ov000_021b566c->mUnk_04 != NULL) {
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
                    param_1 = p->mUnk_15;
                    if (param_1 == 3) {
                        p->mUnk_1a2++;
                        p = data_ov000_021b566c;
                        if (p->mUnk_1a2 > 5) {
                            func_ov000_021a1a38(6, -80430);
                            return;
                        }
                        if (func_ov000_0219fee4(func_ov000_0219fdc8(p->mUnk_f4[0], 0)) != 0) {
                            return;
                        }
                    } else if (func_ov000_0219fb48(param_1) == 0) {
                        return;
                    }
                }
            }
            p = data_ov000_021b566c;
            if (p->mUnk_1b0 != 0) {
                n = (u32) (p->mUnk_0d * 3000) + 3000;
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
            if ((s32) p->mUnk_e8 > 0) {
                if (p->mUnk_198 == 3) {
                    n = (u32) (p->mUnk_0d * 3000) + 3000;
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
                            if (func_ov000_0219f9bc(p->mUnk_f4[p->mUnk_0d]) == 0) {
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
    if (data_ov000_021b566c->mUnk_e4 != NULL) {
        func_ov000_0218b4bc(data_ov000_021b566c->mUnk_e4);
    }
    if (data_ov000_021b566c->mUnk_10 != NULL) {
        func_ov000_021a49a0(data_ov000_021b566c->mUnk_10);
        p = data_ov000_021b566c;
        q = p->mUnk_10;
        if ((q->mUnk_0b4 == 0 && (p->mUnk_15 == 0 || p->mUnk_15 == 1) &&
             (p->mUnk_198 == 1 || p->mUnk_198 == 2 || p->mUnk_198 == 3 || p->mUnk_198 == 4 || p->mUnk_198 == 6 ||
              p->mUnk_198 == 11)) ||
            (p->mUnk_15 == 2 && p->mUnk_198 == 11)) {
            func_ov000_021a4818(q);
        }
    }
    func_ov000_0219aaec();
    if (data_ov000_021b566c->mUnk_04 != NULL) {
        func_ov000_02198a8c(*data_ov000_021b566c->mUnk_04);
    }
    if (data_ov000_021b566c->mUnk_198 == 18) {
        if (func_ov000_021a350c() - data_ov000_021b566c->mUnk_1e0 > 3000) {
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

u32 func_ov000_021a1e40(u32 param_1, u32 param_2, u16 param_3, u8 *param_4, u32 param_5) {
    Unk021a1e40 a;
    volatile u32 v; // placeholder: value passed through a stack offset
    u32 c;
    if (param_5 == 0 || param_4 == NULL) {
        return 0;
    }
    v = 0;
    MemFillWords(v, &a, 8);
    a.mUnk_01 = 2;
    a.mUnk_04 = param_2;
    a.mUnk_02 = ((param_3 >> 8) & 0xff) | ((param_3 << 8) & 0xff00);
    c = param_4[0];
    if ((c == 0xfe && param_4[1] == 0xfd) || c == 0x5c) {
        if (data_ov000_021b566c->mUnk_10 != NULL) {
            func_ov000_021a3c14((Unk021a3a18 *) data_ov000_021b566c->mUnk_10, (s8 *) param_4, param_5, &a);
        }
    } else if (memcmp(param_4, data_ov000_021b400c, 6) == 0) {
        func_ov000_0219a7e4(param_4, param_5, &a);
    } else {
        switch (c) {
            case 0xfe:
                return 0;
            default:
                return 0;
        }
    }
    return 1;
}

void func_ov000_021a1ca8(u32 param_1, Unk0219887c *param_2, u32 param_3, u32 param_4, s32 param_5, char *param_6) {
    Unk021b566c *p;
    Unk021b5550 *e;
    void **q;
    s32 i;
    s32 j;
    s32 t;
    p = data_ov000_021b566c;
    if (p == NULL || p->mUnk_198 != 7 || p->mUnk_1a1 != 0) {
        func_ov000_02198a74((Gt2Connection *) param_2, data_ov000_021b41b0, -1);
        return;
    }
    i = func_ov000_0219b998();
    if (i == -1) {
        func_ov000_02198a74((Gt2Connection *) param_2, data_ov000_021b41bc, -1);
        func_ov000_021a1a38(6, -87100);
        return;
    }
    if (param_3 != data_ov000_021b566c->mUnk_1f8[data_ov000_021b566c->mUnk_0d] ||
        param_4 != data_ov000_021b566c->mUnk_278[data_ov000_021b566c->mUnk_0d]) {
        j = data_ov000_021b566c->mUnk_0d;
        if (*param_6 != 0 &&
            (p = *(Unk021b566c **) &data_ov000_021b566c, p->mUnk_f4[j] == strtoul(param_6, NULL, 10))) {
            data_ov000_021b566c->mUnk_1f8[j] = param_3;
            data_ov000_021b566c->mUnk_278[data_ov000_021b566c->mUnk_0d] = param_4;
        } else {
            func_ov000_02198a74((Gt2Connection *) param_2, data_ov000_021b41c8, -1);
            return;
        }
    }
    data_ov000_021b566c->mUnk_184 = 0;
    if (func_ov000_02198a7c((Gt2Connection *) param_2, (Gt2ConnectionCallbacks *) data_ov000_021b566c->mUnk_08) == 0) {
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

void func_ov000_021a1b2c(Unk0219887c *param_1, s32 param_2) {
    Unk021b566c *p;
    s32 i;
    void **q;
    Unk021b5550 *e;
    char v1[12];
    p = data_ov000_021b566c;
    if (p == NULL) {
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
            StringFormatBounded(v1, 12, data_ov000_021b40b8, p->mUnk_1e8);
            p = data_ov000_021b566c;
            if (func_ov000_0219e3e4(func_ov000_02198968(
                    *data_ov000_021b566c->mUnk_04, NULL,
                    Gt2FormatAddress(p->mUnk_1f8[p->mUnk_14],
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

void func_ov000_021a1ae0(u32 param_1, u32 param_2, const char *param_3) {
    u32 v1[33];
    char v2[16];
    const char **e;
    s32 i;
    u32 *q;
    e = NULL;
    i = 0;
    q = v1;
    do {
        if (func_ov000_021a0958(v2, param_3 + 1, i) == -1) {
            break;
        }
        *q = strtoul(v2, e, 10);
        q++;
        i++;
    } while (i < 0x80);
    func_ov000_021a01dc(param_3[0], param_2, 0, 0, v1, i);
}

void func_ov000_021a1ac0(void) {
    data_ov000_021b566c->mUnk_3b4 = 0xff;
    data_ov000_021b566c->mUnk_3b5 = 0;
}

void func_ov000_021a1a38(s32 d, s32 e) {
    Unk021b566c *p;
    u32 a;
    u32 b;
    u32 c;
    if (data_ov000_021b566c != NULL && d != 0) {
        func_ov000_0219f0f4();
        func_ov000_0219c384(d, e);
        func_ov000_0219d558(0, data_ov000_021b4114, NULL);
        p = data_ov000_021b566c;
        a = p->mUnk_15 == 2 ? 1 : 0;
        c = data_ov000_021b566c->mUnk_1f4;
        b = c == 0 ? 1 : 0;
        data_ov000_021b566c->mUnk_44c(d, 0, b, a, func_ov000_0219d5e4(c), p->mUnk_450);
        func_ov000_021a104c();
    }
}

void func_ov000_021a1a10(void) {
    Unk021b566c *p;
    p = data_ov000_021b566c;
    if (p->mUnk_15 != 2) {
        p->mUnk_14 = 0;
        data_ov000_021b566c->mUnk_16 = 0;
        func_ov000_021a4818(data_ov000_021b566c->mUnk_10);
    }
}

void func_ov000_021a18e0(s32 a, s32 b, u8 *c) {
    Unk021b566c *p;
    s32 i;
    u32 *q;
    s32 v;
    switch (b) {
        case 2:
            p = data_ov000_021b566c;
            if (p->mUnk_198 == 1) {
                if (c[0] == 1) {
                    p->mUnk_1f4 = 0;
                }
                i = c[1];
                data_ov000_021b566c->mUnk_2b8[i] = c[2];
                data_ov000_021b566c->mUnk_f4[i] = data_ov000_021b566c->mUnk_1e8;
                p = data_ov000_021b566c;
                if (p->mUnk_15 == 0 || p->mUnk_15 == 1) {
                    p = data_ov000_021b566c;
                    p->mUnk_16 = p->mUnk_0d;
                }
                data_ov000_021b566c->mUnk_198 = 9;
            }
            func_ov000_0219ef68(a, 3);
            break;
        case 3:
            p = data_ov000_021b566c;
            if (p->mUnk_198 == 16) {
                q = &p->mUnk_1c8;
                *q = *q | (1 << a);
                v = c[0] | (c[1] << 8);
                if (v > data_ov000_021b566c->mUnk_1a6) {
                    data_ov000_021b566c->mUnk_1a6 = v;
                }
                v = func_ov000_0219e8fc(0);
                if (data_ov000_021b566c->mUnk_1c8 == v) {
                    for (i = 1; i <= data_ov000_021b566c->mUnk_0d; i++) {
                        func_ov000_0219ef68(data_ov000_021b566c->mUnk_2b8[i], 4);
                    }
                    data_ov000_021b566c->mUnk_198 = 17;
                }
            } else {
                func_ov000_0219ef68(a, 4);
            }
            break;
        case 4:
            if (data_ov000_021b566c->mUnk_198 == 9) {
                func_ov000_0219f544(4);
            }
            break;
    }
}

u32 func_ov000_021a17bc(s32 a, s32 b, s32 c) {
    Unk021b566c *p;
    if (func_ov000_0219bab4() != 5) {
        return 0;
    }
    p = data_ov000_021b566c;
    if (p->mUnk_15 == 2) {
        return 1;
    }
    if (a != 0) {
        func_ov000_021a1a38(a, b - 80000);
        return 1;
    }
    p->mUnk_2b8[0] = 0;
    p = data_ov000_021b566c;
    if (p->mUnk_1a1 == 1 || p->mUnk_1a0 == 1 || p->mUnk_1a0 == 2) {
        return 1;
    }
    if (p->mUnk_194 != 0) {
        func_ov000_0219ac50(p->mUnk_194);
        data_ov000_021b566c->mUnk_194 = 0;
    }
    p = data_ov000_021b566c;
    if (p->mUnk_0d != 0) {
        if (p->mUnk_1a0 == 0) {
            p->mUnk_1a0 = 3;
            func_ov000_021988e8(*data_ov000_021b566c->mUnk_04);
        }
    } else if (p->mUnk_15 == 3) {
        func_ov000_021a1a38(6, -80430);
    } else if (p->mUnk_1f0 != 0) {
        func_ov000_0219f184();
    } else if (p->mUnk_198 == 1) {
        p->mUnk_198 = 18;
        data_ov000_021b566c->mUnk_1e0 = func_ov000_021a350c();
    } else {
        func_ov000_0219f23c(1);
    }
    return 1;
}

void func_ov000_021a1798(u32 value) {
    if (data_ov000_021b566c->mUnk_1a0 != 2) {
        func_ov000_0219f9bc(value);
    }
}

u32 func_ov000_021a1754(int a, int b) {
    int v1;
    int v2;
    v2 = *(s32 *) &data_ov000_021b566c;
    if (0 == v2) {
        return 0;
    }
    v1 = 0;
    if (0 < b) {
        do {
            if (a == *(s32 *) (v2 + 0xf4)) {
                func_ov000_021a1620(v1, b);
                return 1;
            }
            v2 = v2 + 4;
            v1 = v1 + 1;
        } while (v1 < b);
    }
    return 0;
}

u32 func_ov000_021a1620(s32 b, s32 c) {
    Unk021b566c *p;
    u32 v1;
    u32 *m;
    s32 i;
    s32 n;
    s32 k;
    p = data_ov000_021b566c;
    if (p == NULL) {
        return 0;
    }
    v1 = p->mUnk_f4[b];
    m = &p->mUnk_2d8;
    *m = *m & ~(1 << p->mUnk_2b8[b]);
    func_ov000_021a15b0();
    if (b < c - 1) {
        i = 0;
        n = c - b;
        if (n > 0) {
            do {
                s32 a = b + i;
                data_ov000_021b566c->mUnk_24[a] = data_ov000_021b566c->mUnk_24[a + 1];
                data_ov000_021b566c->mUnk_a4[a] = data_ov000_021b566c->mUnk_a4[a + 1];
                data_ov000_021b566c->mUnk_f4[a] = data_ov000_021b566c->mUnk_f4[a + 1];
                data_ov000_021b566c->mUnk_1f8[a] = data_ov000_021b566c->mUnk_1f8[a + 1];
                data_ov000_021b566c->mUnk_278[a] = data_ov000_021b566c->mUnk_278[a + 1];
                data_ov000_021b566c->mUnk_2b8[a] = data_ov000_021b566c->mUnk_2b8[a + 1];
                i++;
            } while (i < n);
        }
    }
    if (c > 0) {
        k = c - 1;
        data_ov000_021b566c->mUnk_24[k] = 0;
        data_ov000_021b566c->mUnk_a4[k] = 0;
        data_ov000_021b566c->mUnk_f4[k] = 0;
        data_ov000_021b566c->mUnk_1f8[k] = 0;
        data_ov000_021b566c->mUnk_278[k] = 0;
        data_ov000_021b566c->mUnk_2b8[k] = 0;
    }
    return v1;
}

u8 func_ov000_021a160c(void) {
    if (data_ov000_021b566c != NULL) {
        return data_ov000_021b566c->mUnk_0d;
    }
    return 0;
}

u8 func_ov000_021a15f8(void) {
    if (data_ov000_021b566c != NULL) {
        return data_ov000_021b566c->mUnk_0e;
    }
    return 0;
}

void func_ov000_021a15b0(void) {
    Unk021b566c *p;
    s32 n;
    s32 i;
    u32 m;
    i = 0;
    n = -1;
    p = data_ov000_021b566c;
    m = p->mUnk_2d8;
    for (; i < 32; i++) {
        if ((m & (1 << i)) != 0) {
            n++;
        }
    }
    if (n == -1) {
        p->mUnk_0e = 0;
    } else {
        p->mUnk_0e = n;
    }
}

u32 func_ov000_021a158c(void **output) {
    if (data_ov000_021b566c == NULL) {
        return 0;
    }
    *output = data_ov000_021b566c->mUnk_2b8;
    return data_ov000_021b566c->mUnk_0d + 1;
}

u32 func_ov000_021a1514(void **a) {
    s32 i;
    u8 *c;
    u8 *q;
    Unk021b566c *p;
    u8 b;
    if (data_ov000_021b566c == NULL) {
        return 0;
    }
    MemFill(data_ov000_021b5678, 0, 0x20);
    i = 0;
    c = (u8 *) data_ov000_021b566c;
    if (i <= ((Unk021b566c *) c)->mUnk_0e) {
        q = data_ov000_021b5678;
        p = (Unk021b566c *) c;
        do {
            b = c[0x2b8];
            if ((p->mUnk_2d8 & (1 << b)) == 0) {
                break;
            }
            *q = b;
            c++;
            q++;
            i++;
        } while (i <= p->mUnk_0e);
    }
    *a = data_ov000_021b5678;
    return data_ov000_021b566c->mUnk_0e + 1;
}

u32 func_ov000_021a1488(void) {
    char name[12];
    u8 buffer[32];
    if (data_ov000_021b566c->mUnk_15 != 2) {
        return 0;
    }
    StringFormatBounded(name, 0xc, data_ov000_021b40b8, data_ov000_021b566c->mUnk_16 + 1);
    func_ov000_021a363c(data_ov000_021b41a8, name, buffer, 0x2f);
    StringFormatBounded(name, 0xc, data_ov000_021b40b8, data_ov000_021b566c->mUnk_0d + 1);
    func_ov000_021a360c(data_ov000_021b41ac, name, buffer, 0x2f);
    StringFormatBounded(name, 0xc, data_ov000_021b40b8, 3);
    func_ov000_021a360c(data_ov000_021b4118, name, buffer, 0x2f);
    return func_ov000_0219d558(6, buffer, NULL);
}

void func_ov000_021a1430(void) {
    data_ov000_021b566c = NULL;
    if (data_ov000_021b5674 != NULL) {
        func_ov000_021a3704(4, (u32) data_ov000_021b5674, 0);
        data_ov000_021b5674 = NULL;
    }
    func_ov000_0219ea88();
    if (data_ov000_021b5670 != NULL) {
        func_ov000_021a3704(4, (u32) data_ov000_021b5670, 0);
        data_ov000_021b5670 = NULL;
    }
    data_ov000_021b5668.mUnk_00 = 0;
    data_ov000_021b5668.mUnk_01 = 0;
}

u32 func_ov000_021a141c(void) {
    if (data_ov000_021b566c == NULL) {
        return 1;
    }
    return 0;
}

void func_ov000_021a1140(s32 a) {
    vu16 h;
    vu16 g;

    data_ov000_021b566c->mUnk_0c = 0;
    data_ov000_021b566c->mUnk_174[0] = 0;
    data_ov000_021b566c->mUnk_176 = func_ov000_021a3448(0x10000);
    data_ov000_021b566c->mUnk_178 = 0;
    data_ov000_021b566c->mUnk_17c = 0;
    data_ov000_021b566c->mUnk_184 = 0;
    data_ov000_021b566c->mUnk_19c = 0;
    data_ov000_021b566c->mUnk_1a1 = 0;
    data_ov000_021b566c->mUnk_1a2 = 0;
    data_ov000_021b566c->mUnk_1a3[0] = 0;
    data_ov000_021b566c->mUnk_1a3[1] = 0;
    data_ov000_021b566c->mUnk_19f = 0;
    data_ov000_021b566c->mUnk_1a0 = 0;
    data_ov000_021b566c->mUnk_1a8 = 0;
    data_ov000_021b566c->mUnk_1aa = 0;
    data_ov000_021b566c->mUnk_1ac = 0;
    data_ov000_021b566c->mUnk_1d0 = 0;
    data_ov000_021b566c->mUnk_1e0 = 0;
    func_0214d018_inline(&data_ov000_021b566c->mUnk_3b4, 0x98);
    if (a == 2) {
        data_ov000_021b566c->mUnk_14 = data_ov000_021b566c->mUnk_0d;
        if (data_ov000_021b566c->mUnk_15 == 3) {
            data_ov000_021b566c->mUnk_198 = 1;
            return;
        }
        if (data_ov000_021b566c->mUnk_15 == 2) {
            data_ov000_021b566c->mUnk_198 = 10;
            return;
        }
    } else {
        data_ov000_021b566c->mUnk_0d = 0;
        data_ov000_021b566c->mUnk_0e = 0;
        data_ov000_021b566c->mUnk_14 = 0;
        data_ov000_021b566c->mUnk_17 = 0;
        data_ov000_021b566c->mUnk_20 = 0;
        data_ov000_021b566c->mUnk_e8 = 0;
        data_ov000_021b566c->mUnk_19d = 0;
        data_ov000_021b566c->mUnk_1a6 = 0;
        data_ov000_021b566c->mUnk_1b0 = 0;
        data_ov000_021b566c->mUnk_1b4 = 0;
        data_ov000_021b566c->mUnk_1bc = 0;
        data_ov000_021b566c->mUnk_1c0 = 0;
        data_ov000_021b566c->mUnk_1c8 = 0;
        data_ov000_021b566c->mUnk_1ec = 0;
        data_ov000_021b566c->mUnk_1f0 = 0;
        data_ov000_021b566c->mUnk_2d8 = 0;
        func_0214d018_inline(data_ov000_021b566c->mUnk_24, 0x80);
        h = 0;
        MemFillHalfwords(h, data_ov000_021b566c->mUnk_a4, 0x40);
        func_0214d018_inline(data_ov000_021b566c->mUnk_f4, 0x80);
        func_0214d018_inline(data_ov000_021b566c->mUnk_18c, 0xc);
        func_0214d018_inline(data_ov000_021b566c->mUnk_1f8, 0x80);
        g = 0;
        MemFillHalfwords(g, data_ov000_021b566c->mUnk_278, 0x40);
        MemFill(data_ov000_021b566c->mUnk_2b8, 0, 0x20);
        func_0214d018_inline(data_ov000_021b566c->mUnk_330, 0x84);
        if (a == 1) {
            if (data_ov000_021b566c->mUnk_15 == 0) {
                data_ov000_021b566c->mUnk_198 = 3;
                return;
            }
            if (data_ov000_021b566c->mUnk_15 == 1) {
                data_ov000_021b566c->mUnk_198 = 4;
                return;
            }
        } else {
            data_ov000_021b566c->mUnk_15 = 0;
            data_ov000_021b566c->mUnk_16 = 0;
            data_ov000_021b566c->mUnk_18 = 0;
            data_ov000_021b566c->mUnk_1f4 = 0;
            data_ov000_021b566c->mUnk_19e = 0;
            data_ov000_021b566c->mUnk_454 = NULL;
            data_ov000_021b566c->mUnk_458 = 0;
        }
    }
}

void func_ov000_021a10b0(u8 a, u8 b, u32 c, u32 d) {
    Unk021b566c **v1;
    func_ov000_021a1140(0);
    v1 = &data_ov000_021b566c;
    data_ov000_021b566c->mUnk_15 = a;
    (*v1)->mUnk_16 = b;
    (*v1)->mUnk_44c = (UnkFunc *) c;
    (*v1)->mUnk_450 = d;
    (*v1)->mUnk_174[1] = 0;
    (*v1)->mUnk_2b8[0] = 0;
    func_ov000_021a4b84(0x32, data_ov000_021b40c4);
    func_ov000_021a4b84(0x33, data_ov000_021b40f0);
    func_ov000_021a4b84(0x34, data_ov000_021b40fc);
    func_ov000_021a4b84(0x35, data_ov000_021b4108);
    func_ov000_021a4b84(0x36, data_ov000_021b40cc);
}

void func_ov000_021a104c(void) {
    if (data_ov000_021b566c != NULL) {
        if (data_ov000_021b566c->mUnk_e4 != NULL) {
            func_ov000_0218b64c(data_ov000_021b566c->mUnk_e4);
            data_ov000_021b566c->mUnk_e4 = NULL;
        }
        func_ov000_0219b110();
        data_ov000_021b566c->mUnk_198 = 0;
        if (data_ov000_021b5674 != NULL) {
            func_ov000_021a3704(4, (u32) data_ov000_021b5674, 0);
            data_ov000_021b5674 = NULL;
        }
        func_ov000_0219ea88();
        data_ov000_021b566c->mUnk_18 = 1;
    }
}

u32 func_ov000_021a0f20(u32 a) {
    char v1[0x100];
    u8 v2[0xa8];
    s32 i;
    u8 *e;
    u8 *w;
    u32 n;
    u32 r;

    n = 7;
    v2[0] = 8;
    v2[1] = 0xa;
    v2[2] = 0x32;
    v2[3] = 0x33;
    v2[4] = 0x34;
    v2[5] = 0x35;
    v2[6] = 0x36;
    if (data_ov000_021b566c->mUnk_15 == 0 || data_ov000_021b566c->mUnk_15 == 1) {
        i = 0;
        e = data_ov000_021b5698[0];
        w = v2 + 7;
        for (; i < 0x9a; i++) {
            if (e[0] != 0) {
                *w = e[0];
                w++;
                n++;
            }
            e += 12;
        }
    }
    switch (data_ov000_021b566c->mUnk_198) {
        case 3:
            a = data_ov000_021b566c->mUnk_1f0;
            if (a == 0) {
                func_ov000_021a0ed8(v1, data_ov000_021b566c->mUnk_1e8, data_ov000_021b566c->mUnk_16,
                                    data_ov000_021b566c->mUnk_15);
                if (data_ov000_021b5674 != NULL) {
                    StringFormatBounded(v1, 0x100, data_ov000_021b4194, v1, data_ov000_021b5674);
                }
                break;
            }
        case 2:
        case 4:
        case 5:
            StringFormatBounded(v1, 0x100, data_ov000_021b41a0, data_ov000_021b40c4, a);
            data_ov000_021b566c->mUnk_1ec = a;
            break;
    }
    func_ov000_0218b48c(data_ov000_021b566c->mUnk_e4);
    for (i = 0; i < 5; i++) {
        r = func_ov000_0218b570((u32) data_ov000_021b566c->mUnk_e4, 1, 0, (u32) v2, n, (u32) v1, 0x10);
        if (r == 0 || r != 2) {
            break;
        }
    }
    return r;
}

s32 func_ov000_021a0ed8(char *a, s32 b, s32 c, s32 d) {
    return StringFormatBounded(a, 0x100, data_ov000_021b413c, data_ov000_021b4108, 3, data_ov000_021b40c4, b, c, c,
                               data_ov000_021b40f0, d, data_ov000_021b40fc, data_ov000_021b40c4);
}

u32 func_ov000_021a0cac(s32 a, s32 b, u32 c) {
    u32 t[2];
    u16 v1;
    u32 k;
    BOOL x;
    u32 v2;
    u32 r;

    k = data_ov000_021b566c->mUnk_14;
    v2 = 0;
    if (a == 0) {
        b = (data_ov000_021b566c->mUnk_1e8 & 0xffff) | (data_ov000_021b566c->mUnk_176 << 16);
        if (func_ov000_0218b248(c) != 0) {
            if (func_ov000_0218b27c((u32 *) c) == func_ov000_0218b458(data_ov000_021b566c->mUnk_e4)) {
                data_ov000_021b566c->mUnk_1f8[k] = func_ov000_0218b244(c);
                data_ov000_021b566c->mUnk_278[k] = func_ov000_0218b228(c);
                x = FALSE;
            } else {
                x = TRUE;
            }
        } else {
            v1 = func_ov000_021a8ed4();
            if ((v1 & 0xffff) == 0xa8c0 ||
                ((v1 & 0xff) == 0xac && (v1 & 0xff00u) >= 0x1000 && (v1 & 0xff00u) <= 0x1f00) || (v1 & 0xff) == 0x10) {
                x = TRUE;
            } else {
                data_ov000_021b566c->mUnk_1f8[k] = func_ov000_0218b27c((u32 *) c);
                data_ov000_021b566c->mUnk_278[k] = func_ov000_0218b260(c);
                x = FALSE;
            }
        }
        if (x != FALSE) {
            data_ov000_021b566c->mUnk_176 = func_ov000_021a3448(0x10000);
            data_ov000_021b566c->mUnk_194 = b;
        } else {
            t[0] = func_ov000_021a8ed4();
            t[1] = GetSocketPort(*data_ov000_021b566c->mUnk_04);
            r = func_ov000_021a0ae8(6, data_ov000_021b566c->mUnk_f4[k], func_ov000_0218b27c((u32 *) c),
                                    func_ov000_0218b260(c), t, 2);
            data_ov000_021b566c->mUnk_3b5 = 0;
            if (r != 0) {
                return 2;
            }
            data_ov000_021b566c->mUnk_194 = 0;
        }
        data_ov000_021b566c->mUnk_18c[0] = 0;
        data_ov000_021b566c->mUnk_18c[1] = 0;
        *(u16 *) &data_ov000_021b566c->mUnk_18c[2] = func_ov000_0218b260(c);
        *(u32 *) &data_ov000_021b566c->mUnk_18c[4] = func_ov000_0218b27c((u32 *) c);
    } else {
        x = TRUE;
        data_ov000_021b566c->mUnk_18c[0] = 1;
        data_ov000_021b566c->mUnk_18c[1] = v2;
        *(u16 *) &data_ov000_021b566c->mUnk_18c[2] = v2;
        *(u32 *) &data_ov000_021b566c->mUnk_18c[4] = v2;
        data_ov000_021b566c->mUnk_194 = b;
    }
    if (x != FALSE) {
        v2 = func_ov000_021a0c30((Unk021a0c30 *) data_ov000_021b566c->mUnk_18c);
    } else {
        func_ov000_0219db18(0, GetSocketDescriptor(*data_ov000_021b566c->mUnk_04), 0, data_ov000_021b566c->mUnk_18c);
        data_ov000_021b566c->mUnk_184 = 0;
    }
    return v2;
}

u32 func_ov000_021a0c30(Unk021a0c30 *a) {
    u32 r;
    s32 i;

    if (a->mUnk_00 == 0) {
        if (func_ov000_0219e594(func_ov000_0218b4f8(data_ov000_021b566c->mUnk_e4, Gt2FormatAddress(a->mUnk_04, 0, 0),
                                                    a->mUnk_02, a->mUnk_08)) != 0) {
            return 2;
        }
    }
    for (i = 0; i < 5; i++) {
        r = func_ov000_0219ac7c(GetSocketDescriptor(*data_ov000_021b566c->mUnk_04), a->mUnk_08, a->mUnk_00,
                                (void (*)(s32, void *)) func_ov000_0219dd48,
                                (void (*)(s32, s32, void *, void *)) func_ov000_0219db18, a);
        if (r == 0 || r != 3) {
            break;
        }
    }
    return r;
}

u32 func_ov000_021a0ae8(u32 a, u32 b, u32 c, u32 d, void *e, s32 f) {
    char v1[0x10];
    char v2[0x200];
    u32 *w;
    s32 n;
    s32 k;
    s32 j;

    n = 0;
    if (data_ov000_021b566c->mUnk_15 == 0 ||
        ((data_ov000_021b566c->mUnk_15 == 3 || data_ov000_021b566c->mUnk_19e != 0) && a == 6)) {
        n = func_ov000_021a0a40(a, c, d, e, f);
    } else {
        if (e != NULL && f != 0) {
            w = e;
            n = StringFormatBounded(v2, 0x200, data_ov000_021b40b8, w[0]);
            for (k = 1; k < f; k++) {
                j = StringFormatBounded(v1, 0x10, data_ov000_021b4138, w[k]);
                MemCopy(v1, v2 + n, j);
                n += j;
            }
        }
        v2[n] = 0;
        n = func_ov000_021a09d0(data_ov000_021b566c->mUnk_00, a, b, v2);
    }
    if (a == 2 || a == 6 || (u8) (a + 0xf8) <= 1) {
        data_ov000_021b566c->mUnk_3b4 = a;
        data_ov000_021b566c->mUnk_3b6 = d;
        data_ov000_021b566c->mUnk_3b8 = c;
        data_ov000_021b566c->mUnk_43c = b;
        data_ov000_021b566c->mUnk_440 = f;
        data_ov000_021b566c->mUnk_444 = func_ov000_021a350c();
        if (e != NULL && f != 0) {
            MemCopyWords(e, data_ov000_021b566c->mUnk_3bc, f * 4);
        }
    }
    return n;
}

u32 func_ov000_021a0a40(u32 a, u32 b, u32 c, u32 *d, u32 e) {
    u32 v1[0x21];
    Unk021a0a40 s;
    u32 r;
    s32 i;

    if (d != NULL && e != 0) {
        MemCopyWords(d, v1, e * 4);
    } else {
        e = 0;
    }
    *(Unk021b40bc *) &s = *(Unk021b40bc *) data_ov000_021b40bc;
    s.mUnk_04 = 3;
    s.mUnk_08 = a;
    s.mUnk_09 = e * 4;
    s.mUnk_0a = data_ov000_021b566c->mUnk_1a;
    s.mUnk_0c = (u32) data_ov000_021b566c->mUnk_1c;
    s.mUnk_10 = data_ov000_021b566c->mUnk_1e8;
    for (i = 0; i < 5; i++) {
        r = func_ov000_0218b530(data_ov000_021b566c->mUnk_e4, Gt2FormatAddress(b, 0, 0), c, (u8 *) &s,
                                s.mUnk_09 + 0x14);
        if (r == 0 || r != 2) {
            break;
        }
    }
    return r;
}

s32 func_ov000_021a09d0(struct GpConnection *a, u32 b, u32 c, const char *d) {
    char v1[0x200];
    char *e;
    char *g;
    s32 n;
    s32 i;

    i = StringFormatBounded(v1, 0x200, data_ov000_021b4124, data_ov000_021b412c, 3, data_ov000_021b4134);
    v1[i] = b;
    g = v1 + 1;
    e = g + i;
    g[i] = 0;
    if (d != NULL) {
        n = strlen(d);
        MemCopy(d, e, n);
        e[n] = 0;
    }
    return GpSendMessage(a, c, v1);
}

s32 func_ov000_021a0958(char *a, const char *b, s32 c) {
    const char *e;
    const char *p;
    s32 i;
    s32 n;

    e = strchr(b, 0);
    for (i = 0; i < c; i++) {
        p = strchr(b, 0x2f);
        if (p == NULL) {
            return -1;
        }
        b = p + 1;
    }
    p = strchr(b, 0x2f);
    if (p == NULL) {
        p = e;
    }
    if (b == p) {
        return -1;
    }
    n = p - b;
    MemCopy(b, a, n);
    a[n] = 0;
    return n;
}

s32 func_ov000_021a01dc(s32 a, u32 b, u32 c, u16 d, u32 *e, s32 f) {
    u32 *w;
    u32 z;
    Unk021a01dc s;
    u32 g[0x41];
    s32 i;
    s32 t;
    u16 y;
    s32 x;
    u32 u;
    u8 v;
    Unk021b566c *o;
    Unk021b566c *p;
    Unk021b5670 *q;
    u32 *n;

    i = 0;
    o = data_ov000_021b566c;
    if (o == NULL || o->mUnk_198 == 0) {
        return 1;
    }
    switch (a) {
        case 1:
        case 11:
            t = func_ov000_021a0064(b, e[0], a == 11 ? 1 : 0);
            if (t == 2) {
                if (data_ov000_021b566c->mUnk_15 != 0) {
                    c = e[1];
                    d = (u16) e[2];
                }
                if (func_ov000_0219fee4(func_ov000_0219ff54(b, c, d)) != 0) {
                    return 0;
                }
                p = data_ov000_021b566c;
                if (p->mUnk_15 == 2 && p->mUnk_454 != NULL) {
                    data_ov000_021b566c->mUnk_454(func_ov000_0219d5e4(b), p->mUnk_458);
                }
                g[0] = data_ov000_021b566c->mUnk_14;
                for (i = 1; i <= data_ov000_021b566c->mUnk_14; i++) {
                    g[i] = data_ov000_021b566c->mUnk_f4[i];
                }
                p = data_ov000_021b566c;
                g[i++] = (u32) p->mUnk_1c;
                g[i++] = p->mUnk_1a;
                p->mUnk_198 = 11;
            }
            if (t == 0xff) {
                break;
            }
            if (func_ov000_0219fee4(func_ov000_021a0ae8(t, b, c, d, (void *) g, i)) == 0) {
                break;
            }
            return 0;
        case 2:
            if (o->mUnk_198 != 4) {
                break;
            }
            if (b != o->mUnk_1ec) {
                break;
            }
            o->mUnk_1f0 = 0;
            data_ov000_021b566c->mUnk_19f = 0;
            data_ov000_021b566c->mUnk_1bc = 0;
            data_ov000_021b566c->mUnk_1b0 = 0;
            data_ov000_021b566c->mUnk_24[0] = (e + e[0])[1];
            data_ov000_021b566c->mUnk_a4[0] = (e + e[0])[2];
            data_ov000_021b566c->mUnk_1ac = (e + e[0])[1];
            data_ov000_021b566c->mUnk_1aa = (e + e[0])[2];
            if (data_ov000_021b566c->mUnk_15 == 1) {
                if (func_ov000_0219f4c4(e + 1, e[0]) != 0) {
                    if (data_ov000_021b566c->mUnk_0d != 0) {
                        func_ov000_0219ff0c(b, e);
                    }
                } else {
                    if (func_ov000_0219fee4(func_ov000_0219fb14(b)) != 0) {
                        return 0;
                    }
                    if (func_ov000_0219fee4(func_ov000_0219fbec(0, 0)) == 0) {
                        break;
                    }
                    return 0;
                }
            }
            if (data_ov000_021b566c->mUnk_15 == 0) {
                if (data_ov000_021b566c->mUnk_0d != 0) {
                    func_ov000_0219ff0c(b, e);
                    if (func_ov000_0219fee4(func_ov000_0219f8b0()) != 0) {
                        return 0;
                    }
                }
                data_ov000_021b566c->mUnk_198 = 6;
                if (func_ov000_0219e4a0(
                        func_ov000_021a0cac(0, 0, func_ov000_0218b480((u32) data_ov000_021b566c->mUnk_e4, 0))) == 0) {
                    break;
                }
                return 0;
            } else {
                data_ov000_021b566c->mUnk_198 = 5;
                if (func_ov000_0219e594(func_ov000_021a0f20(b)) == 0) {
                    break;
                }
                return 0;
            }
        case 3:
            if (o->mUnk_198 != 4) {
                break;
            }
            if (b != o->mUnk_1ec) {
                break;
            }
            return func_ov000_0219fb48();
        case 4:
            if (o->mUnk_198 != 4) {
                break;
            }
            if (b != o->mUnk_1ec) {
                break;
            }
            o->mUnk_1c0 = func_0200f5ac();
            if ((o->mUnk_1f0 != 0 && o->mUnk_19f < 0x10) || o->mUnk_15 == 3) {
                o->mUnk_1b0 = 1;
                p = data_ov000_021b566c;
                p->mUnk_1b4 = func_0200f5ac();
                if (p->mUnk_15 == 3) {
                    break;
                }
                p->mUnk_19f++;
                break;
            }
            o->mUnk_1f0 = 0;
            data_ov000_021b566c->mUnk_19f = 0;
            p = data_ov000_021b566c;
            if (p->mUnk_15 == 0) {
                p->mUnk_198 = 3;
                data_ov000_021b566c->mUnk_e8 = 1;
                data_ov000_021b566c->mUnk_ec = func_0200f5ac();
            } else if (p->mUnk_15 == 1) {
                func_ov000_0219fbec(1, 0);
            }
            break;
        case 5:
            if (o->mUnk_17 == 0) {
                break;
            }
            if (b != o->mUnk_20) {
                break;
            }
            if (o->mUnk_15 == 2 && o->mUnk_0d == 1 && o->mUnk_f4[1] == b) {
                func_ov000_021988e8(*o->mUnk_04);
            }
            if (func_ov000_0219f9bc(b) == 0) {
                return 0;
            }
            break;
        case 6:
            x = e[0];
            y = e[1];
            if (o->mUnk_198 == 1) {
                o->mUnk_198 = 6;
            } else {
                if (o->mUnk_198 != 6 && o->mUnk_198 != 11) {
                    break;
                }
                if (b != o->mUnk_20) {
                    break;
                }
            }
            data_ov000_021b566c->mUnk_3b4 = 0xff;
            p = data_ov000_021b566c;
            n = &p->mUnk_f4[p->mUnk_0d + 1];
            if (b != *n) {
                *n = b;
            }
            s.mUnk_04 = x;
            s.mUnk_02 = ((y >> 8) & 0xff) | ((y << 8) & 0xff00);
            data_ov000_021b566c->mUnk_18c[0] = 1;
            p = data_ov000_021b566c;
            func_ov000_0219db18(0, GetSocketDescriptor(*p->mUnk_04), (s32) &s, p->mUnk_18c);
            data_ov000_021b566c->mUnk_184 = 0;
            break;
        case 7:
            z = e[0];
            u = e[1];
            o->mUnk_f4[o->mUnk_14 + 1] = z;
            data_ov000_021b566c->mUnk_2b8[data_ov000_021b566c->mUnk_14 + 1] = u;
            func_ov000_021a4818(data_ov000_021b566c->mUnk_10);
            p = data_ov000_021b566c;
            if (p->mUnk_454 == NULL) {
                break;
            }
            data_ov000_021b566c->mUnk_454(func_ov000_0219d5e4(z), p->mUnk_458);
            break;
        case 8:
            x = e[0];
            z = x;
            if (x == 0) {
                u = e[1];
                o->mUnk_2b8[u] = e[2];
                data_ov000_021b566c->mUnk_f4[u] = data_ov000_021b566c->mUnk_1e8;
                func_ov000_0219f544(3);
                break;
            }
            u = e[1];
            v = e[2];
            w = &o->mUnk_f4[u];
            if (x == *w && u == o->mUnk_0d - 1) {
                if (func_ov000_0219fee4(func_ov000_021a0ae8(9, b, o->mUnk_24[0], o->mUnk_a4[0], &z, 1)) == 0) {
                    break;
                }
                return 0;
            }
            *w = x;
            data_ov000_021b566c->mUnk_2b8[u] = v;
            data_ov000_021b566c->mUnk_24[u] = e[3];
            data_ov000_021b566c->mUnk_a4[u] = e[4];
            data_ov000_021b566c->mUnk_1ac = e[3];
            data_ov000_021b566c->mUnk_1aa = e[4];
            data_ov000_021b566c->mUnk_198 = 5;
            if (func_ov000_0219e594(func_ov000_021a0f20(z)) != 0) {
                return 0;
            }
            data_ov000_021b566c->mUnk_1bc = 0;
            data_ov000_021b566c->mUnk_1b0 = 0;
            break;
        case 9:
            if (o->mUnk_198 != 13) {
                break;
            }
            if (e[0] != o->mUnk_f4[o->mUnk_19c + 1]) {
                break;
            }
            o->mUnk_19c++;
            func_ov000_0219f544(0);
            break;
        case 10:
            if (o->mUnk_15 == 0 || func_ov000_0219f4c4(e + 1, e[0]) != 0) {
                data_ov000_021b566c->mUnk_1f0 = e[1];
                data_ov000_021b566c->mUnk_19f = 0;
            } else {
                data_ov000_021b566c->mUnk_1f0 = 0;
            }
            p = data_ov000_021b566c;
            if (p->mUnk_0d != 0) {
                func_ov000_021988e8(*p->mUnk_04);
                break;
            }
            if (func_ov000_0219f184() == 0) {
                break;
            }
            return 0;
        case 12:
            if (o->mUnk_15 == 0 || o->mUnk_15 == 1) {
                if (func_ov000_0219f938(b) != 0) {
                    break;
                }
                return 0;
            }
            if (o->mUnk_15 == 3) {
                if (e[0] == 0) {
                    o->mUnk_1f4 = b;
                    func_ov000_0219f0f4();
                    func_ov000_0219f23c(0);
                } else {
                    func_ov000_0219f124(e[0]);
                }
            }
            break;
        case 13:
        case 14:
        case 15:
            if (func_ov000_0219ec44(b, a, e[0]) != 0) {
                break;
            }
            return 0;
        case 16:
            if (b != o->mUnk_f4[0]) {
                return 1;
            }
            for (i = 0; i < f; i++) {
                t = func_ov000_0219e948(e[i], 0);
                if (t != 0xff) {
                    func_ov000_0219bbac(t);
                }
            }
            break;
        case 17:
            q = data_ov000_021b5670;
            if (q != NULL && q->mUnk_00 != 0 && func_ov000_021a350c() - q->mUnk_10 >= q->mUnk_04) {
                g[0] = 1;
            } else {
                g[0] = 0;
            }
            if (func_ov000_0219fee4(func_ov000_021a0ae8(0x12, b, c, d, (void *) g, 1)) == 0) {
                break;
            }
            return 0;
        case 18:
            if (o->mUnk_198 != 0x13) {
                break;
            }
            t = func_ov000_0219e948(b, 0);
            if (t == 0xff) {
                break;
            }
            data_ov000_021b5670->mUnk_08 |= 1 << t;
            if (e[0] != 0) {
                data_ov000_021b5670->mUnk_0c |= 1 << t;
            }
            break;
        case 19:
            func_ov000_021a1a38(10, -80000);
            return 0;
    }
    return 1;
}

s32 func_ov000_021a0064(s32 a, u32 b, s32 c) {
    s32 r;

    switch (data_ov000_021b566c->mUnk_15) {
        case 1:
            if (GpIsBuddy(data_ov000_021b566c->mUnk_00, a) == 0) {
                r = 0xff;
                break;
            }
        case 0:
            if (b != data_ov000_021b566c->mUnk_15 || data_ov000_021b566c->mUnk_1a1 != 0 ||
                data_ov000_021b566c->mUnk_14 == data_ov000_021b566c->mUnk_16 ||
                (data_ov000_021b566c->mUnk_17 != 0 && data_ov000_021b566c->mUnk_20 == data_ov000_021b566c->mUnk_1e8)) {
                r = 3;
                if (data_ov000_021b566c->mUnk_15 == 0 && data_ov000_021b566c->mUnk_10->mUnk_0b4 == 0 &&
                    data_ov000_021b566c->mUnk_17 != 0 &&
                    data_ov000_021b566c->mUnk_20 == data_ov000_021b566c->mUnk_1e8) {
                    func_ov000_021a4818(data_ov000_021b566c->mUnk_10);
                }
            } else if ((data_ov000_021b566c->mUnk_198 != 3 && data_ov000_021b566c->mUnk_198 != 4) ||
                       (data_ov000_021b566c->mUnk_1c == NULL && data_ov000_021b566c->mUnk_1a == 0)) {
                r = 4;
            } else if (data_ov000_021b566c->mUnk_1ec != 0) {
                if (data_ov000_021b566c->mUnk_1ec == a) {
                    if (c != 0 || ((s32) data_ov000_021b566c->mUnk_1e8 < a && a != data_ov000_021b566c->mUnk_1f0)) {
                        r = 2;
                    } else {
                        r = 0xff;
                    }
                } else if (c != 0 || ((s32) data_ov000_021b566c->mUnk_1e8 < a && data_ov000_021b566c->mUnk_1f0 == 0)) {
                    if (func_ov000_0219fee4(func_ov000_0219fb14(data_ov000_021b566c->mUnk_1ec)) != 0) {
                        return 0xff;
                    }
                    r = 2;
                } else {
                    r = 3;
                }
            } else {
                r = 2;
            }
            break;
        case 2:
            if (GpIsBuddy(data_ov000_021b566c->mUnk_00, a) == 0) {
                r = 0xff;
            } else if (b != 3 || data_ov000_021b566c->mUnk_14 == data_ov000_021b566c->mUnk_16) {
                r = 3;
            } else if (data_ov000_021b5668.mUnk_00 == 1 && data_ov000_021b5668.mUnk_01 == 1) {
                r = 0x13;
            } else if (data_ov000_021b566c->mUnk_198 != 10 ||
                       (data_ov000_021b566c->mUnk_1c == NULL && data_ov000_021b566c->mUnk_1a == 0)) {
                r = 4;
            } else {
                r = 2;
            }
            break;
    }
    return r;
}

u32 func_ov000_0219ff54(u32 a, u32 b, u16 c) {
    u32 s[2];
    s32 i;
    u32 r;

    if (data_ov000_021b566c->mUnk_17 != 0 && data_ov000_021b566c->mUnk_20 == a) {
        return 0;
    }
    data_ov000_021b566c->mUnk_17 = 1;
    data_ov000_021b566c->mUnk_20 = a;
    data_ov000_021b566c->mUnk_1b0 = 0;
    data_ov000_021b566c->mUnk_1bc = 0;
    func_ov000_021a4818(data_ov000_021b566c->mUnk_10);
    data_ov000_021b566c->mUnk_1ec = 0;
    data_ov000_021b566c->mUnk_f4[data_ov000_021b566c->mUnk_14 + 1] = a;
    data_ov000_021b566c->mUnk_24[data_ov000_021b566c->mUnk_14 + 1] = b;
    data_ov000_021b566c->mUnk_a4[data_ov000_021b566c->mUnk_14 + 1] = c;
    data_ov000_021b566c->mUnk_1ac = b;
    data_ov000_021b566c->mUnk_1aa = c;
    data_ov000_021b566c->mUnk_2b8[data_ov000_021b566c->mUnk_14 + 1] = func_ov000_0219ea48();
    s[0] = a;
    s[1] = data_ov000_021b566c->mUnk_2b8[data_ov000_021b566c->mUnk_14 + 1];
    for (i = 1; i <= data_ov000_021b566c->mUnk_14; i++) {
        r = func_ov000_021a0ae8(7, data_ov000_021b566c->mUnk_f4[i], data_ov000_021b566c->mUnk_24[i],
                                data_ov000_021b566c->mUnk_a4[i], s, 2);
        if (r != 0) {
            return r;
        }
    }
    func_ov000_0219e8b8(1);
    return 0;
}

void func_ov000_0219ff0c(u32 a, u32 *b) {
    u32 n;

    n = b[0] + 2;
    if (n > 2) {
        MemCopyWords(b + 1, &data_ov000_021b566c->mUnk_330[2], (n - 2) * 4);
    }
    data_ov000_021b566c->mUnk_330[0] = n - 1;
    data_ov000_021b566c->mUnk_330[1] = a;
}

u32 func_ov000_0219fee4(u32 a) {
    if (data_ov000_021b566c->mUnk_15 == 0) {
        return func_ov000_0219e594(a);
    }
    return func_ov000_0219e608(a);
}

u32 func_ov000_0219fdc8(u32 a, s32 b) {
    u32 s[3];
    u32 t;
    u32 m;
    u32 v;

    if (b != 0) {
        data_ov000_021b566c->mUnk_1b0 = 1;
        data_ov000_021b566c->mUnk_1b4 = func_0200f5ac();
        data_ov000_021b566c->mUnk_f4[0] = a;
        return 0;
    }
    if (data_ov000_021b566c->mUnk_15 == 0) {
        t = func_ov000_0218b480((u32) data_ov000_021b566c->mUnk_e4, 0);
        data_ov000_021b566c->mUnk_f4[0] = SbServerGetInt((SbServer *) t, data_ov000_021b40c4, 0);
        data_ov000_021b566c->mUnk_24[0] = func_ov000_0218b27c((u32 *) t);
        data_ov000_021b566c->mUnk_a4[0] = func_ov000_0218b260(t);
        data_ov000_021b566c->mUnk_1ec = data_ov000_021b566c->mUnk_f4[0];
        m = 1;
    } else {
        if (data_ov000_021b566c->mUnk_15 == 1) {
            data_ov000_021b566c->mUnk_f4[0] = a;
        }
        data_ov000_021b566c->mUnk_1ec = a;
        s[1] = (u32) data_ov000_021b566c->mUnk_1c;
        s[2] = data_ov000_021b566c->mUnk_1a;
        m = 3;
    }
    data_ov000_021b566c->mUnk_1bc = 6000;
    data_ov000_021b566c->mUnk_1c0 = func_0200f5ac();
    data_ov000_021b566c->mUnk_1b0 = 0;
    v = data_ov000_021b566c->mUnk_1f0 != 0 ? 11 : 1;
    s[0] = data_ov000_021b566c->mUnk_15;
    return func_ov000_021a0ae8(v, a, data_ov000_021b566c->mUnk_24[0], data_ov000_021b566c->mUnk_a4[0], s, m);
}

u32 func_ov000_0219fbec(s32 a, s32 b) {
    BOOL d;
    s32 i;
    BOOL c;
    s32 e;
    char g[8];
    s32 q;
    char x[12];
    Unk0218ec44 h;
    Unk021b566c *p;
    s32 n;
    u32 r;
    s32 k;
    s32 t;
    s32 z;

    if (b != 0) {
        i = data_ov000_021b566c->mUnk_19d;
    } else if (data_ov000_021b566c->mUnk_19d < data_ov000_021b566c->mUnk_32c - 1) {
        i = data_ov000_021b566c->mUnk_19d + 1;
    } else {
        i = 0;
    }
    c = FALSE;
    d = b == 0;
    while (1) {
        if (d != FALSE || c != FALSE) {
            data_ov000_021b566c->mUnk_19d++;
            if (data_ov000_021b566c->mUnk_19d >= data_ov000_021b566c->mUnk_32c) {
                data_ov000_021b566c->mUnk_19d = 0;
            }
        }
        if (c != FALSE && data_ov000_021b566c->mUnk_19d == i) {
            data_ov000_021b566c->mUnk_1bc = 3000;
            data_ov000_021b566c->mUnk_1c0 = func_0200f5ac();
            data_ov000_021b566c->mUnk_1b0 = 0;
            return 0;
        }
        c = TRUE;
        p = data_ov000_021b566c;
        n = func_02152520((void *) func_ov000_0219c9c4(), (u8 *) p->mUnk_2e4 + p->mUnk_2ec[p->mUnk_19d] * 12);
        if (n == 0) {
            continue;
        }
        if (n == -1) {
            continue;
        }
        if (func_02152698((u8 *) data_ov000_021b566c->mUnk_2e4 +
                          data_ov000_021b566c->mUnk_2ec[data_ov000_021b566c->mUnk_19d] * 12) == 0) {
            continue;
        }
        for (k = 1; k <= data_ov000_021b566c->mUnk_0d; k++) {
            if (n == data_ov000_021b566c->mUnk_f4[k]) {
                break;
            }
        }
        if (k <= data_ov000_021b566c->mUnk_0d) {
            continue;
        }
        r = GpGetBuddyIndex(data_ov000_021b566c->mUnk_00, n, &q);
        r |= GpGetBuddyStatus(data_ov000_021b566c->mUnk_00, q, &h);
        if (r != 0) {
            continue;
        }
        if (h.mUnk_004 != 4) {
            continue;
        }
        t = func_ov000_021a3530(data_ov000_021b4118, x, h.mUnk_008, 0x2f);
        e = func_ov000_021a3530(data_ov000_021b411c, g + 2, h.mUnk_008, 0x2f);
        z = func_ov000_021a3530(data_ov000_021b4120, g, h.mUnk_008, 0x2f);
        if (t > 0 && e > 0 && z > 0) {
            if (strtoul(x, NULL, 10) == 3) {
                if (data_ov000_021b566c->mUnk_16 == strtoul(g + 2, NULL, 10)) {
                    return func_ov000_0219fdc8(n, a);
                }
            }
        }
    }
}

u32 func_ov000_0219fb48(void) {
    Unk021b566c *p;

    data_ov000_021b566c->mUnk_1f0 = 0;
    data_ov000_021b566c->mUnk_1ec = 0;
    data_ov000_021b566c->mUnk_19f = 0;
    p = data_ov000_021b566c;
    p->mUnk_1c0 = func_0200f5ac();
    if (p->mUnk_15 == 0) {
        p->mUnk_198 = 3;
        if (func_ov000_0219e594(func_ov000_021a0f20(0)) != 0) {
            return 0;
        }
    } else if (p->mUnk_15 == 1) {
        if (func_ov000_0219fee4(func_ov000_0219fbec(0, 0)) != 0) {
            return 0;
        }
    } else if (p->mUnk_15 == 3) {
        func_ov000_021a1a38(6, -80410);
        return 0;
    }
    return 1;
}

u32 func_ov000_0219fb14(u32 a) {
    u32 result;
    result = func_ov000_021a0ae8(5, a, data_ov000_021b566c->mUnk_24[0], data_ov000_021b566c->mUnk_a4[0], NULL, 0);
    data_ov000_021b566c->mUnk_1ec = 0;
    return result;
}

u32 func_ov000_0219f9bc(u32 a) {
    s32 i;
    u32 b;

    if (data_ov000_021b566c->mUnk_17 != 0 && data_ov000_021b566c->mUnk_20 == data_ov000_021b566c->mUnk_1e8) {
        b = 0;
    } else {
        b = 1;
    }
    if (b != 0) {
        data_ov000_021b566c->mUnk_17 = 0;
        data_ov000_021b566c->mUnk_20 = 0;
        func_ov000_021a4818(data_ov000_021b566c->mUnk_10);
    }
    if (data_ov000_021b566c->mUnk_0d < 0x1f) {
        data_ov000_021b566c->mUnk_f4[data_ov000_021b566c->mUnk_0d + 1] = 0;
    }
    data_ov000_021b566c->mUnk_3b4 = 0xff;
    if (data_ov000_021b566c->mUnk_194 != 0) {
        func_ov000_0219ac50(data_ov000_021b566c->mUnk_194);
        data_ov000_021b566c->mUnk_194 = 0;
    }
    data_ov000_021b566c->mUnk_14 = data_ov000_021b566c->mUnk_0d;
    data_ov000_021b566c->mUnk_1ec = 0;
    if (b == 0) {
        if (data_ov000_021b566c->mUnk_15 != 3) {
            func_ov000_0219f214();
        }
    } else if (data_ov000_021b566c->mUnk_15 == 0) {
        data_ov000_021b566c->mUnk_198 = 3;
        data_ov000_021b566c->mUnk_e8 = 2;
        data_ov000_021b566c->mUnk_ec = func_0200f5ac();
    } else if (data_ov000_021b566c->mUnk_15 == 1) {
        data_ov000_021b566c->mUnk_198 = 4;
        func_ov000_0219fbec(1, 0);
    } else if (data_ov000_021b566c->mUnk_15 == 2) {
        data_ov000_021b566c->mUnk_198 = 14;
        data_ov000_021b566c->mUnk_1cc = 0;
        data_ov000_021b566c->mUnk_1a8 = 0;
        func_ov000_0219f124(a);
        for (i = 1; i <= data_ov000_021b566c->mUnk_0d; i++) {
            if (func_ov000_0219edb0(data_ov000_021b566c->mUnk_f4[i], 0xd) == 0) {
                return 0;
            }
        }
        if (data_ov000_021b566c->mUnk_0d == 0) {
            func_ov000_0219f23c(2);
        }
    }
    return 1;
}

u32 func_ov000_0219f938(u32 a) {
    u32 b;

    b = 1;
    if (data_ov000_021b566c->mUnk_15 == 3) {
        if (data_ov000_021b566c->mUnk_0d != 0) {
            func_ov000_0219f0f4();
        }
        func_ov000_021a1a38(6, -80430);
        return 0;
    }
    data_ov000_021b566c->mUnk_14 = data_ov000_021b566c->mUnk_0d;
    data_ov000_021b566c->mUnk_1f0 = 0;
    if (data_ov000_021b566c->mUnk_194 != 0) {
        func_ov000_0219ac50(data_ov000_021b566c->mUnk_194);
        data_ov000_021b566c->mUnk_194 = 0;
    }
    if (data_ov000_021b566c->mUnk_0d != 0) {
        func_ov000_0219f214();
    } else {
        data_ov000_021b566c->mUnk_198 = 4;
        b = func_ov000_0219fb48();
    }
    return b;
}

u32 func_ov000_0219f8b0(void) {
    s32 i;
    u32 r;

    for (i = 1; i <= data_ov000_021b566c->mUnk_0d; i++) {
        r = func_ov000_021a0ae8(10, data_ov000_021b566c->mUnk_f4[i], data_ov000_021b566c->mUnk_24[i],
                                data_ov000_021b566c->mUnk_a4[i], data_ov000_021b566c->mUnk_330,
                                data_ov000_021b566c->mUnk_330[0] + 1);
        if (r != 0) {
            return r;
        }
    }
    data_ov000_021b566c->mUnk_17 = 0;
    data_ov000_021b566c->mUnk_20 = 0;
    data_ov000_021b566c->mUnk_1a0 = 1;
    func_ov000_021988e8(*data_ov000_021b566c->mUnk_04);
    data_ov000_021b566c->mUnk_1a0 = 0;
    return 0;
}

void func_ov000_0219f544(s32 a) {
    Unk021b566c *p;
    u32 v[4]; // the original also writes v[4], one word past the end
    s32 w;
    s32 f;
    s32 n;
    BOOL c;
    w = 3;
    f = 0;
    switch (a) {
        case 0:
            p = data_ov000_021b566c;
            if (p->mUnk_19c < p->mUnk_0d - 1) {
                p->mUnk_198 = 13;
                p = data_ov000_021b566c;
                v[0] = p->mUnk_f4[p->mUnk_19c + 1];
                v[1] = p->mUnk_19c + 1;
                v[2] = p->mUnk_2b8[p->mUnk_19c + 1];
                v[3] = p->mUnk_24[p->mUnk_19c + 1];
                v[4] = p->mUnk_a4[p->mUnk_19c + 1];
                w = 5;
            } else {
                p->mUnk_17 = 0;
                data_ov000_021b566c->mUnk_20 = 0;
                func_ov000_021a4818(data_ov000_021b566c->mUnk_10);
                p = data_ov000_021b566c;
                if (p->mUnk_15 == 0) {
                    p->mUnk_198 = 3;
                } else if (p->mUnk_15 == 1) {
                    p->mUnk_198 = 4;
                } else {
                    p->mUnk_198 = 10;
                }
                data_ov000_021b566c->mUnk_19c = 0;
                p = data_ov000_021b566c;
                if (p->mUnk_15 == 2 || p->mUnk_0d == p->mUnk_16) {
                    if (p->mUnk_15 == 2) {
                        p = data_ov000_021b566c;
                        p->mUnk_1f4 = p->mUnk_f4[p->mUnk_0d];
                    } else {
                        p->mUnk_1f4 = 0;
                        p = data_ov000_021b566c;
                        p->mUnk_f4[0] = p->mUnk_1e8;
                    }
                    data_ov000_021b566c->mUnk_198 = 16;
                    data_ov000_021b566c->mUnk_1c8 = 0;
                    for (n = 1; n <= data_ov000_021b566c->mUnk_0d; n++) {
                        func_ov000_0219ef68(data_ov000_021b566c->mUnk_2b8[n], 2);
                    }
                } else {
                    v[0] = 0;
                    v[1] = p->mUnk_0d;
                    v[2] = p->mUnk_2b8[p->mUnk_0d];
                    if (p->mUnk_15 == 0) {
                        p->mUnk_e8 = 2;
                        data_ov000_021b566c->mUnk_ec = func_0200f5ac();
                    } else if (p->mUnk_15 == 1) {
                        func_ov000_0219fbec(1, 0);
                    }
                }
                if (data_ov000_021b566c->mUnk_15 != 2) {
                    f = 1;
                }
            }
            if (data_ov000_021b566c->mUnk_198 == 16) {
                break;
            }
            p = data_ov000_021b566c;
            n = p->mUnk_0d;
            if (func_ov000_0219fee4(func_ov000_021a0ae8(8, p->mUnk_f4[n], p->mUnk_24[n], p->mUnk_a4[n], v, w)) != 0) {
                return;
            }
            data_ov000_021b566c->mUnk_3b5 = 0;
            break;
        case 1:
            data_ov000_021b566c->mUnk_198 = 1;
            p = data_ov000_021b566c;
            if (p->mUnk_15 == 3) {
                p->mUnk_1f4 = p->mUnk_f4[p->mUnk_0d];
            }
            f = 1;
            break;
        case 2:
            data_ov000_021b566c->mUnk_198 = 1;
            p = data_ov000_021b566c;
            if (p->mUnk_15 == 0 || p->mUnk_15 == 1) {
                p->mUnk_17 = 1;
                data_ov000_021b566c->mUnk_20 = data_ov000_021b566c->mUnk_1e8;
            }
            p = data_ov000_021b566c;
            if (p->mUnk_0d > 1) {
                if (func_ov000_0219fee4(func_ov000_021a0ae8(9, p->mUnk_f4[0], p->mUnk_24[0], p->mUnk_a4[0],
                                                            &p->mUnk_f4[p->mUnk_0d - 1], 1)) != 0) {
                    return;
                }
            }
            break;
        case 3:
            data_ov000_021b566c->mUnk_198 = 1;
            data_ov000_021b566c->mUnk_1f4 = f;
            f = 1;
            break;
        case 4:
            if (data_ov000_021b566c->mUnk_15 != 2) {
                func_ov000_0219d558(2, data_ov000_021b4114, (void *) f);
            }
            p = data_ov000_021b566c;
            if (p->mUnk_1f4 == 0) {
                c = TRUE;
            } else {
                c = FALSE;
            }
            data_ov000_021b566c->mUnk_44c(0, 0, c, 0, func_ov000_0219d5e4(data_ov000_021b566c->mUnk_1f4), p->mUnk_450);
            p = data_ov000_021b566c;
            if (p->mUnk_15 == 0 || p->mUnk_15 == 1) {
                func_ov000_021a104c();
            } else {
                if (p->mUnk_e4 != NULL) {
                    func_ov000_0218b64c(p->mUnk_e4);
                    data_ov000_021b566c->mUnk_e4 = NULL;
                }
                func_ov000_0219b110();
                p = data_ov000_021b566c;
                if (p->mUnk_15 == 2) {
                    if (func_ov000_0219e608(func_ov000_021a1488()) != 0) {
                        return;
                    }
                    if (data_ov000_021b5668.mUnk_00 == 1) {
                        data_ov000_021b5668.mUnk_01 = 1;
                    }
                    data_ov000_021b566c->mUnk_198 = 10;
                } else {
                    p->mUnk_198 = 1;
                }
                data_ov000_021b566c->mUnk_1f4 = 0;
            }
            data_ov000_021b566c->mUnk_1a1 = 0;
            break;
    }
    if (f != 0) {
        p = data_ov000_021b566c;
        if (p->mUnk_15 != 3) {
            func_ov000_0218b48c(p->mUnk_e4);
        }
    }
}

u32 func_ov000_0219f4c4(u32 *a, u32 b) {
    Unk021b566c *p;
    u32 i;
    p = data_ov000_021b566c;
    if (p->mUnk_19e != 0 && p->mUnk_198 == 4) {
        return 1;
    }
    for (i = 0; i < b; i++) {
        if (GpIsBuddy(p->mUnk_00, *a) == 0) {
            return 0;
        }
        p = data_ov000_021b566c;
        if (p->mUnk_19e != 0 && p->mUnk_198 == 1) {
            return 1;
        }
        a++;
    }
    return 1;
}

void func_ov000_0219f3cc(void) {
    Unk021b566c *p;
    u32 s;
    data_ov000_021b566c->mUnk_1f4 = 0;
    p = data_ov000_021b566c;
    if (p->mUnk_198 == 2) {
        func_ov000_0219f344();
        return;
    }
    p->mUnk_1a1 = 1;
    p = data_ov000_021b566c;
    s = p->mUnk_15;
    if (s == 3) {
        p->mUnk_1a1 = 1;
        p = data_ov000_021b566c;
        if (p->mUnk_0d != 0) {
            func_ov000_021988e8(*p->mUnk_04);
        } else {
            if (func_ov000_0219fee4(func_ov000_0219fb14(p->mUnk_f4[0])) != 0) {
                return;
            }
        }
        func_ov000_0219f344();
        return;
    }
    if (p->mUnk_198 == 4 || p->mUnk_198 == 5 || p->mUnk_198 == 6 || p->mUnk_198 == 7 || p->mUnk_198 == 11 ||
        p->mUnk_198 == 12) {
        if (p->mUnk_1ec != 0) {
            if (func_ov000_0219fee4(func_ov000_0219fb14(p->mUnk_f4[0])) != 0) {
                return;
            }
        }
        if (func_ov000_0219fee4(func_ov000_0219f2e4()) != 0) {
            return;
        }
    }
    p = data_ov000_021b566c;
    if (p->mUnk_194 != 0) {
        func_ov000_0219ac50(p->mUnk_194);
        data_ov000_021b566c->mUnk_194 = 0;
    }
    p = data_ov000_021b566c;
    if (p->mUnk_0d != 0) {
        p->mUnk_1a1 = 1;
        func_ov000_021988e8(*data_ov000_021b566c->mUnk_04);
    }
    func_ov000_0219f344();
}

void func_ov000_0219f344(void) {
    Unk021b566c *p;
    BOOL a;
    BOOL b;
    u32 c;
    if (func_ov000_0219e608(func_ov000_0219d558(1, data_ov000_021b4114, NULL)) == 0) {
        func_ov000_021a104c();
        p = data_ov000_021b566c;
        c = p->mUnk_1f4;
        if (c != 0) {
            a = TRUE;
        } else if (p->mUnk_15 == 2) {
            a = TRUE;
        } else {
            a = FALSE;
        }
        if (c == 0) {
            b = TRUE;
        } else {
            b = FALSE;
        }
        data_ov000_021b566c->mUnk_44c(0, 1, b, a, func_ov000_0219d5e4(c), p->mUnk_450);
        data_ov000_021b566c->mUnk_1a1 = 0;
    }
}

u32 func_ov000_0219f2e4(void) {
    u32 r;
    u32 v;
    s32 n;
    volatile Unk021b566c *p; // fields are read again on each use
    r = 0;
    v = 0;
    p = data_ov000_021b566c;
    if (p->mUnk_17 != 0 && p->mUnk_20 != 0 && p->mUnk_20 != p->mUnk_1e8) {
        n = p->mUnk_0d + 1;
        r = func_ov000_021a0ae8(12, p->mUnk_20, p->mUnk_24[n], p->mUnk_a4[n], &v, 1);
        data_ov000_021b566c->mUnk_17 = 0;
        data_ov000_021b566c->mUnk_20 = 0;
    }
    return r;
}

void func_ov000_0219f23c(s32 a) {
    Unk021b566c *p;
    s32 b;
    BOOL c;
    if (a == 0) {
        func_ov000_0219f344();
        return;
    }
    func_ov000_021a1140(a);
    p = data_ov000_021b566c;
    if (p->mUnk_15 == 2 || p->mUnk_15 == 3) {
        if (p->mUnk_1f4 == 0) {
            c = TRUE;
        } else {
            c = FALSE;
        }
        data_ov000_021b566c->mUnk_44c(0, 1, c, 0, func_ov000_0219d5e4(p->mUnk_1f4), p->mUnk_450);
    } else if (p->mUnk_15 == 0) {
        if (a == 1) {
            if (func_ov000_0219e594(func_ov000_021a0f20(0)) != 0) {
                return;
            }
        }
    } else if (p->mUnk_15 == 1) {
        if (a == 1) {
            func_ov000_0219fbec(0, 0);
        }
    }
}

void func_ov000_0219f214(void) {
    Unk021b566c *p;
    p = data_ov000_021b566c;
    if (p->mUnk_15 != 2 && p->mUnk_15 != 3) {
        func_ov000_0219f0f4();
        func_ov000_0219f23c(1);
    }
}

u32 func_ov000_0219f184(void) {
    u32 r;
    Unk021b566c *p;
    data_ov000_021b566c->mUnk_17 = 0;
    data_ov000_021b566c->mUnk_20 = 0;
    data_ov000_021b566c->mUnk_1a0 = 0;
    p = data_ov000_021b566c;
    if (p->mUnk_1f0 != 0) {
        if (p->mUnk_15 == 0) {
            p->mUnk_198 = 3;
            r = func_ov000_021a0f20(0);
            if (func_ov000_0219e594(r) != 0) {
                return r;
            }
        } else if (p->mUnk_15 == 1) {
            p->mUnk_198 = 4;
            r = func_ov000_0219fdc8(data_ov000_021b566c->mUnk_1f0, 0);
            if (func_ov000_0219fee4(r) != 0) {
                return r;
            }
        }
    } else {
        func_ov000_0219f23c(1);
    }
    return 0;
}

u32 func_ov000_0219f124(u32 a) {
    void **r;
    data_ov000_021b566c->mUnk_1f4 = a;
    r = func_ov000_0219b8fc(a, data_ov000_021b566c->mUnk_0d + 1);
    if (r != NULL) {
        data_ov000_021b566c->mUnk_1a0 = 2;
        func_ov000_02198908(*r);
        data_ov000_021b566c->mUnk_1a0 = 0;
        return 1;
    }
    func_ov000_021a1754(a, data_ov000_021b566c->mUnk_0d + 1);
    return 0;
}

void func_ov000_0219f0f4(void) {
    data_ov000_021b566c->mUnk_1a0 = 2;
    func_ov000_021988e8(*data_ov000_021b566c->mUnk_04);
    data_ov000_021b566c->mUnk_1a0 = 0;
}

u32 func_ov000_0219f00c(u32 a) {
    u32 d[32];
    u32 e[32];
    s32 k;
    s32 m;
    s32 n;
    s32 i;
    u32 b;
    Unk021b566c *p;
    m = 0;
    k = 0;
    n = 1;
    p = data_ov000_021b566c;
    for (; n <= p->mUnk_0d; n++) {
        b = 1 << data_ov000_021b566c->mUnk_2b8[n];
        if ((a & b) != 0) {
            e[k] = p->mUnk_f4[n];
            k++;
        } else {
            d[m] = p->mUnk_f4[n];
            m++;
        }
    }
    for (i = 0; i < k; i++) {
        if (func_ov000_0219fee4(func_ov000_021a0ae8(0x10, e[i], 0, 0, d, m)) != 0) {
            return 0;
        }
    }
    data_ov000_021b566c->mUnk_1a0 = 2;
    for (i = 0; i < m; i++) {
        s32 t;
        t = func_ov000_0219e948(d[i], 0);
        if (t != 0xff) {
            func_ov000_0219bbac(t);
        }
    }
    data_ov000_021b566c->mUnk_1a0 = 0;
    return 1;
}

void func_ov000_0219ef68(s32 a, u16 b) {
    u8 n;
    u8 v1[3];
    volatile Unk021b566c *p; // fields are read again on each use
    switch (b) {
        case 2:
            p = data_ov000_021b566c;
            if (a == p->mUnk_2b8[p->mUnk_0d]) {
                v1[0] = 1;
            } else {
                v1[0] = 0;
            }
            for (n = 1; n <= p->mUnk_0d; n++) {
                if (a == p->mUnk_2b8[n]) {
                    v1[1] = n;
                    v1[2] = a;
                    break;
                }
            }
            break;
        case 3:
            p = data_ov000_021b566c;
            v1[0] = p->mUnk_1a6;
            v1[1] = p->mUnk_1a6 >> 8;
            break;
    }
    func_ov000_021a3310(b, a, v1, 4);
    data_ov000_021b566c->mUnk_1d0 = func_ov000_021a350c();
}

u32 func_ov000_0219ee14(void) {
    Unk021b566c *p;
    u64 t;
    s32 n;
    u8 b;
    p = data_ov000_021b566c;
    if (p->mUnk_198 == 9 || p->mUnk_198 == 16 || p->mUnk_198 == 17) {
        t = func_ov000_021a350c() - p->mUnk_1d0;
    } else {
        return 1;
    }
    switch (p->mUnk_198) {
        case 9:
            if (t > 6000) {
                func_ov000_0219ef68(p->mUnk_2b8[0], 3);
            }
            break;
        case 16:
            if (t > 6000) {
                p->mUnk_1a3[0]++;
                p = data_ov000_021b566c;
                if (p->mUnk_1a3[0] > 5) {
                    if (p->mUnk_15 == 0 || p->mUnk_15 == 1) {
                        func_ov000_0219f0f4();
                        func_ov000_0219f23c(1);
                        break;
                    }
                    if (func_ov000_0219f00c(p->mUnk_1c8) == 0) {
                        return 0;
                    }
                    p = data_ov000_021b566c;
                    if (p->mUnk_0d != 0) {
                        p->mUnk_1a3[0] = 0;
                        data_ov000_021b566c->mUnk_1d0 = func_ov000_021a350c();
                    } else {
                        if (func_ov000_0219f9bc(p->mUnk_1f4) == 0) {
                            return 0;
                        }
                    }
                } else {
                    for (n = 1; n <= p->mUnk_0d; n++, p = data_ov000_021b566c) {
                        p = data_ov000_021b566c;
                        b = p->mUnk_2b8[n];
                        if ((p->mUnk_1c8 & (1 << b)) == 0) {
                            func_ov000_0219ef68(b, 2);
                        }
                    }
                }
            }
            break;
        case 17:
            if (p->mUnk_1a6 < t) {
                func_ov000_0219f544(4);
            }
            break;
    }
    return 1;
}

u32 func_ov000_0219edb0(u32 a, u32 b) {
    u32 v;
    u32 c;
    if (b == 13) {
        v = data_ov000_021b566c->mUnk_1f4;
        c = 1;
    } else {
        c = 0;
    }
    if (func_ov000_0219fee4(func_ov000_021a0ae8(b, a, 0, 0, &v, c)) != 0) {
        return 0;
    }
    data_ov000_021b566c->mUnk_1d8 = func_ov000_021a350c();
    return 1;
}

BOOL func_ov000_0219ec44(u32 a, s32 b, u32 c) {
    Unk021b566c *p;
    u64 t;
    u64 x;
    u64 d;
    u32 m;
    s32 n;
    u32 r;
    if (func_ov000_0219bab4() != 6) {
        return TRUE;
    }
    switch (b) {
        case 13:
            if (data_ov000_021b566c->mUnk_198 != 8) {
                data_ov000_021b566c->mUnk_198 = 8;
                func_ov000_0219f124(c);
            }
            if (func_ov000_0219edb0(a, 14) == 0) {
                return FALSE;
            }
            break;
        case 14:
            if (data_ov000_021b566c->mUnk_198 == 14) {
                t = func_ov000_021a350c();
                p = data_ov000_021b566c;
                x = p->mUnk_1d8;
                if (x + 600 < t) {
                    d = ((t - x) >> 1) - 300;
                    if (p->mUnk_1a8 < d) {
                        p->mUnk_1a8 = d;
                    }
                }
                r = func_ov000_0219e948(a, 0);
                if (r != 0xff) {
                    data_ov000_021b566c->mUnk_1cc |= 1 << r;
                }
                m = func_ov000_0219e8fc(1);
                p = data_ov000_021b566c;
                if (p->mUnk_1cc == m) {
                    for (n = 1; n <= p->mUnk_0d; n++, p = data_ov000_021b566c) {
                        if (func_ov000_0219edb0(p->mUnk_f4[n], 15) == 0) {
                            return FALSE;
                        }
                    }
                    p->mUnk_198 = 15;
                }
            } else {
                if (func_ov000_0219edb0(a, 15) == 0) {
                    return FALSE;
                }
            }
            break;
        case 15:
            if (data_ov000_021b566c->mUnk_198 == 8) {
                func_ov000_0219f23c(2);
            }
            break;
    }
    return TRUE;
}

u32 func_ov000_0219eaf4(void) {
    Unk021b566c *p;
    u64 t;
    s32 n;
    p = data_ov000_021b566c;
    if (p->mUnk_198 == 8 || p->mUnk_198 == 14 || p->mUnk_198 == 15) {
        t = func_ov000_021a350c() - p->mUnk_1d8;
    } else {
        return 1;
    }
    switch (p->mUnk_198) {
        case 8:
            if (t > 6000) {
                if (func_ov000_0219edb0(p->mUnk_f4[0], 14) == 0) {
                    return 0;
                }
            }
            break;
        case 14:
            if (t > 6000) {
                p->mUnk_1a3[1]++;
                p = data_ov000_021b566c;
                if (p->mUnk_1a3[1] > 5) {
                    if (func_ov000_0219f00c(p->mUnk_1cc) == 0) {
                        return 0;
                    }
                    p = data_ov000_021b566c;
                    if (p->mUnk_0d != 0) {
                        p->mUnk_1a3[1] = 0;
                        data_ov000_021b566c->mUnk_1d8 = func_ov000_021a350c();
                    } else {
                        func_ov000_0219f23c(2);
                    }
                } else {
                    for (n = 1; n <= p->mUnk_0d; n++, p = data_ov000_021b566c) {
                        if ((data_ov000_021b566c->mUnk_1cc & (1 << data_ov000_021b566c->mUnk_2b8[n])) == 0) {
                            if (func_ov000_0219edb0(p->mUnk_f4[n], 13) == 0) {
                                return 0;
                            }
                        }
                    }
                }
            }
            break;
        case 15:
            if (p->mUnk_1a8 < t) {
                func_ov000_0219f23c(2);
            }
            break;
    }
    return 1;
}

u8 func_ov000_0219eac8(void) {
    u8 i = 0;
    do {
        if (data_ov000_021b5698[i][0] == 0) {
            return i + 100;
        }
        i++;
    } while (i < 154);
    return 0;
}

void func_ov000_0219ea88(void) {
    s32 i;
    volatile u32 v; // read back from its stack offset
    u8(*e)[12];
    i = 0;
    e = data_ov000_021b5698;
    for (; i < 0x9a; i++) {
        if (*(u32 *) &e[0][4] != 0) {
            func_ov000_021a3704(4, *(u32 *) &e[0][4], 0);
        }
        e++;
    }
    v = 0;
    MemFillWords(v, data_ov000_021b5698, 0x738);
}

u8 func_ov000_0219ea48(void) {
    u8 i;
    s32 j;
    volatile Unk021b566c *p; // fields are read again on each use
    i = 0;
    p = data_ov000_021b566c;
    for (; i < 0x20; i++) {
        for (j = 0; j <= p->mUnk_14; j++) {
            if (i == p->mUnk_2b8[j]) {
                break;
            }
        }
        if (j > p->mUnk_14) {
            break;
        }
    }
    return i;
}

s32 func_ov000_0219e994(u32 a) {
    if (SbServerGetInt((SbServer *) a, data_ov000_021b40d8, -1) == -1) {
        return 0;
    }
    if (SbServerGetInt((SbServer *) a, data_ov000_021b40e4, -1) == -1) {
        return 0;
    }
    if (SbServerGetInt((SbServer *) a, data_ov000_021b40f0, -1) == -1) {
        return 0;
    }
    if (SbServerGetInt((SbServer *) a, data_ov000_021b40fc, -1) == -1 &&
        SbServerGetInt((SbServer *) a, data_ov000_021b40fc, 0) == 0) {
        return 0;
    }
    if (SbServerGetInt((SbServer *) a, data_ov000_021b4108, -1) == -1) {
        return 0;
    }
    return SbServerGetInt((SbServer *) a, data_ov000_021b40c4, 0);
}

s32 func_ov000_0219e948(u32 a, s32 b) {
    if (b == 0) {
        b = 1;
    } else {
        b = 0;
    }
    for (; b <= data_ov000_021b566c->mUnk_0d; b++) {
        if (a == data_ov000_021b566c->mUnk_f4[b]) {
            return data_ov000_021b566c->mUnk_2b8[b];
        }
    }
    return 0xff;
}

u32 func_ov000_0219e8fc(s32 a) {
    s32 i;
    u32 r = 0;

    if (a != 0) {
        return data_ov000_021b566c->mUnk_2d8 & ~1;
    }
    for (i = 1; i <= data_ov000_021b566c->mUnk_0d; i++) {
        r |= 1 << data_ov000_021b566c->mUnk_2b8[i];
    }
    return r;
}

void func_ov000_0219e8b8(s32 a) {
    Unk021b5670 *q;
    q = data_ov000_021b5670;
    if (q != NULL && q->mUnk_00 != 0) {
        q->mUnk_08 = 0;
        data_ov000_021b5670->mUnk_0c = 0;
        data_ov000_021b5670->mUnk_02 = 0;
        data_ov000_021b5670->mUnk_18 = func_ov000_021a350c();
        if (a == 0) {
            data_ov000_021b5670->mUnk_10 = func_ov000_021a350c();
        }
    }
}

void func_ov000_0219e668(void) {
    Unk021b5670 *q;
    Unk021b566c *p;
    u32 a;
    u8 b;
    s32 n;
    q = data_ov000_021b5670;
    if (q == NULL) {
        return;
    }
    if (q->mUnk_00 == 0) {
        return;
    }
    p = data_ov000_021b566c;
    if (p->mUnk_15 == 2) {
        return;
    }
    if (p->mUnk_15 == 3) {
        return;
    }
    if (p->mUnk_198 == 0x13) {
        a = func_ov000_0219e8fc(0);
        q = data_ov000_021b5670;
        if (q->mUnk_08 == a) {
            if (q->mUnk_0c == a) {
                data_ov000_021b566c->mUnk_16 = data_ov000_021b566c->mUnk_0d;
                data_ov000_021b566c->mUnk_19c = data_ov000_021b566c->mUnk_0d - 1;
                func_ov000_0219f544(0);
                return;
            }
            q->mUnk_18 = func_ov000_021a350c();
            q->mUnk_08 = 0;
            p = data_ov000_021b566c;
            if (p->mUnk_15 == 0) {
                p->mUnk_198 = 3;
                data_ov000_021b566c->mUnk_e8 = 2;
                data_ov000_021b566c->mUnk_ec = func_0200f5ac();
                return;
            }
            p->mUnk_198 = 4;
            func_ov000_0219fbec(1, 0);
            return;
        }
        b = q->mUnk_02;
        if (func_ov000_021a350c() - q->mUnk_18 < b * 0x1770) {
            return;
        }
        if (b > 5) {
            func_ov000_0219e8b8(1);
            func_ov000_0219f0f4();
            func_ov000_0219f23c(1);
            return;
        }
        for (n = 1; n <= (p = data_ov000_021b566c)->mUnk_0d; n++) {
            if ((data_ov000_021b5670->mUnk_08 & (1 << p->mUnk_2b8[n])) == 0) {
                p = data_ov000_021b566c;
                if (func_ov000_0219fee4(
                        func_ov000_021a0ae8(0x11, p->mUnk_f4[n], p->mUnk_24[n], p->mUnk_a4[n], NULL, 0)) != 0) {
                    return;
                }
            }
        }
        data_ov000_021b5670->mUnk_02++;
    } else if (p->mUnk_198 == 3 || p->mUnk_198 == 4) {
        if (p->mUnk_0d < q->mUnk_01 - 1) {
            return;
        }
        if (q->mUnk_02 != 0 || func_ov000_021a350c() - q->mUnk_10 < q->mUnk_04) {
            if (q->mUnk_02 == 0) {
                return;
            }
            q = data_ov000_021b5670;
            if (func_ov000_021a350c() - q->mUnk_18 < (q->mUnk_04 >> 2)) {
                return;
            }
        }
        p = data_ov000_021b566c;
        if (p->mUnk_1ec != 0) {
            if (func_ov000_0219fee4(func_ov000_0219fb14(p->mUnk_1ec)) != 0) {
                return;
            }
        }
        p = data_ov000_021b566c;
        p->mUnk_198 = 0x13;
        for (n = 1; n <= data_ov000_021b566c->mUnk_0d; n++) {
            p = data_ov000_021b566c;
            if (func_ov000_0219fee4(func_ov000_021a0ae8(0x11, p->mUnk_f4[n], p->mUnk_24[n], p->mUnk_a4[n], NULL, 0)) !=
                0) {
                return;
            }
        }
        q = data_ov000_021b5670;
        q->mUnk_18 = func_ov000_021a350c();
        q->mUnk_02 = 1;
    }
}

u32 func_ov000_0219e608(u32 a) {
    s32 b;
    s32 c;
    if (a == 0) {
        return 0;
    }
    switch (a) {
        case 1:
            b = 11;
            c = -1;
            break;
        case 2:
            b = 11;
            c = -2;
            break;
        case 3:
            b = 6;
            c = -10;
            break;
        case 4:
            b = 6;
            c = -20;
            break;
    }
    func_ov000_021a1a38(b, c - 0x13c68);
    return a;
}

u32 func_ov000_0219e594(u32 a) {
    s32 b;
    s32 c;
    if (a == 0) {
        return 0;
    }
    switch (a) {
        case 1:
            b = 6;
            c = -50;
            break;
        case 2:
            b = 6;
            c = -30;
            break;
        case 3:
            b = 6;
            c = -20;
            break;
        case 4:
            b = 6;
            c = -40;
            break;
        case 5:
            b = 11;
            c = -1;
            break;
        case 6:
            b = 11;
            c = -2;
            break;
    }
    func_ov000_021a1a38(b, c - 0x14c08);
    return a;
}

u32 func_ov000_0219e4e8(u32 a) {
    s32 c;
    s32 b;
    if (a == 0) {
        return 0;
    }
    switch (a) {
        case 1:
            b = 6;
            c = -50;
            break;
        case 2:
            b = 6;
            c = -60;
            break;
        case 3:
            b = 6;
            c = -30;
            break;
        case 4:
            b = 6;
            c = -80;
            break;
        case 5:
            b = 6;
            c = -20;
            break;
    }
    switch (func_ov000_0219bab4()) {
        case 2:
            func_ov000_0219c990(b, c - 0xfa00);
            break;
        case 4:
            func_ov000_0219d734(b, c - 0x12110);
            break;
        case 5:
            func_ov000_021a1a38(b, c - 0x14820);
            break;
        default:
            func_ov000_0219c384(b, c - 0x16f30);
            break;
    }
    return a;
}

s32 func_ov000_0219e4a0(s32 a) {
    s32 b;
    s32 c;
    if (a == 0) {
        return 0;
    }
    switch (a) {
        case 1:
            b = 11;
            c = -1;
            break;
        case 2:
            b = 6;
            c = -50;
            break;
        case 3:
            b = 6;
            c = -30;
            break;
    }
    func_ov000_021a1a38(b, c - 0x14ff0);
    return a;
}

s32 func_ov000_0219e45c(s32 a) {
    enum { K6 = 6 } b;
    s32 c;
    if (a == 0) {
        return 0;
    }
    switch (a) {
        case 1:
            return 1;
        case 2:
            return 2;
        default:
            b = K6;
            c = -9;
            break;
    }
    if (b != 0) {
        func_ov000_021a1a38(b, c - 0x14ff0);
    }
    return a;
}

u32 func_ov000_0219e3e4(u32 a) {
    s32 b;
    s32 c;
    if (a == 0) {
        return 0;
    }
    switch (a) {
        case 1:
            b = 11;
            c = -1;
            break;
        case 2:
        case 5:
            b = 0;
            c = 0;
            a = 0;
            break;
        case 3:
            b = 6;
            c = -10;
            break;
        case 4:
            b = 6;
            c = -30;
            break;
        case 6:
            b = 6;
            c = -70;
            break;
        case 7:
            b = 6;
            c = -80;
            break;
    }
    if (b != 0) {
        func_ov000_021a1a38(b, c - 0x153d8);
    }
    return a;
}

void func_ov000_0219e138(u32 a, s32 b, s32 c) {
    s32 d;
    u32 e;
    Unk021b566c *f;
    switch (b) {
        case 0:
            func_ov000_0219e134(c);
            return;
        case 4:
            d = 0;
            if ((s32) func_ov000_0218b474(a) > 0) {
                do {
                    e = func_ov000_0218b480(a, d);
                    if (func_ov000_0219e994(e) == 0) {
                        func_ov000_0218b4d4((struct Unk0218b668 *) a, e);
                        d--;
                    }
                    d++;
                } while (d < (s32) func_ov000_0218b474(a));
            }
            switch (data_ov000_021b566c->mUnk_198) {
                case 2:
                    d = 0;
                    if ((s32) func_ov000_0218b474(a) > 0) {
                        do {
                            e = func_ov000_0218b480(a, d);
                            f = data_ov000_021b566c;
                            if (f->mUnk_1c != NULL && f->mUnk_1c == (void *) func_ov000_0218b27c((u32 *) e) &&
                                f->mUnk_1a != 0 && data_ov000_021b566c->mUnk_1a == func_ov000_0218b260(e)) {
                                break;
                            }
                            d++;
                        } while (d < (s32) func_ov000_0218b474(a));
                    }
                    if (d < (s32) func_ov000_0218b474(a)) {
                        data_ov000_021b566c->mUnk_198 = 3;
                        data_ov000_021b566c->mUnk_1ec = 0;
                        if (func_ov000_0219e594(func_ov000_021a0f20(data_ov000_021b566c->mUnk_1ec)) != 0) {
                            return;
                        }
                        return;
                    }
                    data_ov000_021b566c->mUnk_e8 = 2;
                    data_ov000_021b566c->mUnk_ec = func_0200f5ac();
                    return;
                case 3:
                    func_ov000_0219dfe4(1);
                    if (func_ov000_0218b474(a) != 0) {
                        if (func_ov000_0219fee4(func_ov000_0219fdc8(0, 0)) != 0) {
                            return;
                        }
                        data_ov000_021b566c->mUnk_198 = 4;
                        data_ov000_021b566c->mUnk_e8 = 0;
                        return;
                    }
                    data_ov000_021b566c->mUnk_e8 = 2;
                    data_ov000_021b566c->mUnk_ec = func_0200f5ac();
                    return;
                case 5:
                    if (func_ov000_0218b474(a) != 0) {
                        do {
                            e = func_ov000_0218b480(a, 0);
                            if (data_ov000_021b566c->mUnk_1ac == func_ov000_0218b27c((u32 *) e) &&
                                data_ov000_021b566c->mUnk_1aa == func_ov000_0218b260(e)) {
                                break;
                            }
                            func_ov000_0218b4d4((struct Unk0218b668 *) a, e);
                        } while (func_ov000_0218b474(a) != 0);
                    }
                    if (func_ov000_0218b474(a) != 0) {
                        e = SbServerGetInt((SbServer *) func_ov000_0218b480(a, 0), data_ov000_021b40c4, 0);
                        f = data_ov000_021b566c;
                        if (f->mUnk_15 == 1 && e == f->mUnk_f4[0]) {
                            if (func_ov000_0219dfe4(0) != 0) {
                                if (data_ov000_021b566c->mUnk_0d != 0) {
                                    if (func_ov000_0219fee4(func_ov000_0219f8b0()) != 0) {
                                        return;
                                    }
                                }
                            } else {
                                if (func_ov000_0219fee4(func_ov000_0219fb14(data_ov000_021b566c->mUnk_f4[0])) != 0) {
                                    return;
                                }
                                data_ov000_021b566c->mUnk_198 = 4;
                                if (func_ov000_0219fee4(func_ov000_0219fbec(0, 0)) != 0) {
                                    return;
                                }
                                return;
                            }
                        }
                        data_ov000_021b566c->mUnk_198 = 6;
                        if (func_ov000_0219e4a0(func_ov000_021a0cac(0, 0, func_ov000_0218b480(a, 0))) != 0) {
                            return;
                        }
                        return;
                    }
                    data_ov000_021b566c->mUnk_e8 = 2;
                    data_ov000_021b566c->mUnk_ec = func_0200f5ac();
                    return;
            }
            return;
        case 5:
            break;
    }
}

void func_ov000_0219e134(s32 a) {
    return;
}

BOOL func_ov000_0219dfe4(s32 a) {
    BOOL c;
    BOOL d;
    s32 e;
    u32 f;
    u32 g;
    s32 h;
    c = FALSE;
    e = 0;
    for (; e < (s32) func_ov000_0218b474((u32) data_ov000_021b566c->mUnk_e4); e++) {
        f = func_ov000_0218b480((u32) data_ov000_021b566c->mUnk_e4, e);
        if (data_ov000_021b566c->mUnk_15 == 0) {
            g = SbServerGetInt((SbServer *) f, data_ov000_021b40c4, 0);
            d = FALSE;
            for (h = 1; h <= data_ov000_021b566c->mUnk_0d; h++) {
                if (g == data_ov000_021b566c->mUnk_f4[h]) {
                    func_ov000_0218b4d4((struct Unk0218b668 *) data_ov000_021b566c->mUnk_e4, f);
                    e--;
                    d = TRUE;
                    break;
                }
            }
            if (d != FALSE) {
                continue;
            }
        }
        if (data_ov000_021b566c->mUnk_45c != 0) {
            g = ((s32(*)(s32, u32)) data_ov000_021b566c->mUnk_45c)(e, data_ov000_021b566c->mUnk_460);
            if ((s32) g > 0) {
                if ((s32) g > 0x7fffff) {
                    g = 0x7fffff;
                }
                SbServerSetInt((SbServer *) f, data_ov000_021b40cc, (g << 8) | func_ov000_021a3448(0x100));
            } else {
                func_ov000_0218b4d4((struct Unk0218b668 *) data_ov000_021b566c->mUnk_e4, f);
                e--;
                c = TRUE;
            }
        } else {
            SbServerSetInt((SbServer *) f, data_ov000_021b40cc, func_ov000_021a3448(0x80));
        }
    }
    if (a != 0 && func_ov000_0218b474((u32) data_ov000_021b566c->mUnk_e4) != 0) {
        func_ov000_0218b464(data_ov000_021b566c->mUnk_e4, 0, data_ov000_021b40cc, 0);
    }
    if (c != FALSE && func_ov000_0218b474((u32) data_ov000_021b566c->mUnk_e4) == 0) {
        return FALSE;
    }
    return TRUE;
}

void func_ov000_0219dee0(s32 a, Unk021a471c *b, void *c) {
    s32 d;
    switch (a) {
        case 8:
            func_ov000_021a4760(b, data_ov000_021b566c->mUnk_14);
            return;
        case 0xa:
            func_ov000_021a4760(b, data_ov000_021b566c->mUnk_16);
            return;
        case 0x32:
            func_ov000_021a4760(b, data_ov000_021b566c->mUnk_1e8);
            return;
        case 0x33:
            func_ov000_021a4760(b, data_ov000_021b566c->mUnk_15);
            return;
        case 0x34:
            func_ov000_021a4760(b, data_ov000_021b566c->mUnk_20);
            return;
        case 0x35:
            func_ov000_021a4760(b, 3);
            return;
        case 0x36:
            func_ov000_021a4760(b, 1);
            return;
    }
    d = a - 100;
    if (data_ov000_021b5698[d][0] != 0) {
        if (data_ov000_021b5699[d * 12] != 0) {
            func_ov000_021a471c(b, *(const char **) &data_ov000_021b56a0[d * 12]);
        } else {
            func_ov000_021a4760(b, **(s32 **) &data_ov000_021b56a0[d * 12]);
        }
    }
}

void func_ov000_0219dedc(void) {}

void func_ov000_0219ded8(void) {}

void func_ov000_0219de68(s32 a, Unk021a3fc8 *b, void *c) {
    s32 i;
    u8 *d;
    switch (a) {
        case 0:
            func_ov000_021a4784((u32) b, 8);
            func_ov000_021a4784((u32) b, 0xa);
            func_ov000_021a4784((u32) b, 0x32);
            func_ov000_021a4784((u32) b, 0x33);
            func_ov000_021a4784((u32) b, 0x34);
            func_ov000_021a4784((u32) b, 0x35);
            func_ov000_021a4784((u32) b, 0x36);
            i = 0;
            d = data_ov000_021b5698[0];
            for (; i < 0x9a; i++) {
                if (d[0] != 0) {
                    func_ov000_021a4784((u32) b, d[0]);
                }
                d += 12;
            }
            break;
        case 1:
            break;
        case 2:
            break;
    }
}

s32 func_ov000_0219de64(void) {
    return 0;
}

u32 func_ov000_0219de5c(u32 kind) {
    return func_ov000_0219e4e8(kind);
}

void func_ov000_0219de4c(void *value, u16 index) {
    data_ov000_021b566c->mUnk_1c = value;
    data_ov000_021b566c->mUnk_1a = index;
}

void func_ov000_0219ddbc(u32 a) {
    if (data_ov000_021b566c->mUnk_198 == 1) {
        data_ov000_021b566c->mUnk_198 = 6;
    } else if (data_ov000_021b566c->mUnk_198 != 6 && data_ov000_021b566c->mUnk_198 != 0xb) {
        return;
    }
    if (data_ov000_021b566c->mUnk_178 == a) {
        data_ov000_021b566c->mUnk_174[0]++;
    } else {
        data_ov000_021b566c->mUnk_174[0] = 0;
        data_ov000_021b566c->mUnk_178 = a;
    }
    data_ov000_021b566c->mUnk_17c = 0;
    if (func_ov000_0219e4a0(func_ov000_021a0cac(1, a, 0)) == 0) {
        data_ov000_021b566c->mUnk_3b4 = 0xff;
    }
}

void func_ov000_0219dd4c(const void *a, u32 b) {
    Unk0219dd4c c;
    u8 d[0x80];
    u32 e;
    e = 0;
    if (b >= 0x14) {
        do {
            MemCopy(a, &c, 0x14);
            if (strncmp(c.mUnk_00, data_ov000_021b40bc, 4) != 0) {
                break;
            }
            if (c.mUnk_04 != 3) {
                break;
            }
            MemCopy(a + 0x14, d, c.mUnk_09);
            if (func_ov000_021a01dc(c.mUnk_08, c.mUnk_10, c.mUnk_0c, c.mUnk_0a, (u32 *) d, c.mUnk_09 >> 2) == 0) {
                break;
            }
            e += c.mUnk_09 + 0x14;
        } while (e + 0x14 <= b);
    }
}
