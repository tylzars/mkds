#include "00/code_0219eaf4.h"
#include "00/code_021988e8.h"
#include "00/code_0219a000.h"
#include "00/code_0219b000.h"
#include "00/code_0219d000.h"
#include "00/code_0219e000.h"
#include "00/code_0219f000.h"
#include "00/code_0219f9bc.h"
#include "00/code_021a0000.h"
#include "00/unk_021b5000.h"
#include "00/code_0219f4c4.h"
#include "00/code_021a1000.h"
#include "00/code_021a3000.h"
#include "00/unk_021b4000.h"
#include "code_0200d118.h"
#include "00/code_021a10b0.h"
#include "00/code_021a3264.h"
#include "00/code_0219b8bc.h"

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

// non-matching: the original keeps the object pointer on the stack and steps a pointer into the bytes at offset 0x2b8
// (0xe8 bytes against 0xe0); ours indexes
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
    p = data_ov000_021b566c;
    for (n = 1; n <= p->mUnk_0d; n++) {
        b = 1 << p->mUnk_2b8[n];
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

void func_ov000_0219f0f4(void) {
    data_ov000_021b566c->mUnk_1a0 = 2;
    func_ov000_021988e8(*data_ov000_021b566c->mUnk_04);
    data_ov000_021b566c->mUnk_1a0 = 0;
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

void func_ov000_0219f214(void) {
    Unk021b566c *p;
    p = data_ov000_021b566c;
    if (p->mUnk_15 != 2 && p->mUnk_15 != 3) {
        func_ov000_0219f0f4();
        func_ov000_0219f23c(1);
    }
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

// non-matching: the value read from the object at offset 0x1f4 and the byte at offset 0x15 swap registers (r0 and r1)
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
        data_ov000_021b566c->mUnk_44c(0, 1, b, a, func_ov000_0219d5e4(p->mUnk_1f4), p->mUnk_450);
        data_ov000_021b566c->mUnk_1a1 = 0;
    }
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
