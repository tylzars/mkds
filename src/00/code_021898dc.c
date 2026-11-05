#include "00/code_021898dc.h"
#include "00/code_02188720.h"
#include "00/unk_021b4000.h"
#include "00/code_021884d8.h"
#include "00/code_02188ee0.h"
#include "00/code_0218973c.h"
#include "00/code_02189888.h"
#include "00/code_0218a018.h"
#include "00/code_021a8878.h"
#include "00/code_021a8aa8.h"
#include "00/unk_021b0000.h"
#include "code_0200f5ac.h"

u32 func_ov000_02189fd0(s32 a) {
    s32 i;
    u32 m;

    a = 0x20 - a;
    i = 0;
    m = ~i;
    for (; i < a; i++) {
        m <<= 1;
    }
    return ((m << 24) & 0xff000000) | (((m << 8) & 0xff0000) | (((m >> 24) & 0xff) | ((m >> 8) & 0xff00)));
}

void func_ov000_02189f64(Unk02188ec0 *v1) {
    Unk02188db0 *e;
    s32 v2;
    u32 a;
    u32 b;

    if (v1->mUnk_d0d < 6) {
        e = &v1->mUnk_000[func_ov000_021884d8(v1->mUnk_d0d)];
        v2 = e->mUnk_c8[3] + (e->mUnk_c8[2] + (e->mUnk_c8[0] + e->mUnk_c8[1]));
        if (e->mUnk_c0[0] == 0 && v2 != 0) {
            a = func_ov000_0218a018(e->mUnk_c8);
            b = func_ov000_0218a018(e->mUnk_cc);
            func_ov000_021a8e78(&a, &b);
        }
    }
}

u8 func_ov000_02189f00(void) {
    u32 t;
    Unk02188ec0 *v1;
    Unk02189f00 s;
    s32 r;

    t = func_ov000_021a5bfc();
    v1 = (Unk02188ec0 *) func_ov000_02188584(0x10);
    if (t == 1) {
        s.mUnk_00 = v1->mUnk_d0a;
        s.mUnk_04 = 0;
        s.mUnk_08 = 0;
        s.mUnk_0c = 0;
        func_ov000_0218973c(0);
        r = func_ov000_021a629c((Unk021a5a78 *) &s, (void (*)(Unk021a586c *)) func_ov000_02188d78);
        if (r == 1 || r >= 4) {
            func_ov000_02188508(1);
            return 0x11;
        }
    } else {
        return 1;
    }
    return 2;
}

u32 func_ov000_02189e80(void) {
    Unk02188ec0 *v1;
    u32 s;
    u32 t;

    v1 = (Unk02188ec0 *) func_ov000_02188584(0x10);
    s = func_ov000_02188528();
    t = func_ov000_021a5bfc();
    if (s == 2 && t == 3) {
        s = func_ov000_02189cdc(v1);
    } else if (s == 6) {
        s = func_ov000_021898dc(v1, s);
    } else if (t == 3 || t == 6) {
        s = func_ov000_021898dc(v1, s);
        if (s != 7) {
            if (s == 3) {
                s = func_ov000_02189c50(v1);
            } else if (s == 4) {
                s = func_ov000_02189b28(v1);
            } else if (s == 5) {
                s = func_ov000_02189a28(v1);
            }
        }
    }
    return s;
}

void func_ov000_02189e54(u32 a) {
    Unk02188ec0 *v1;

    v1 = (Unk02188ec0 *) func_ov000_02188584(0x10);
    if (a > 0xd) {
        a = 0xd;
    }
    v1->mUnk_d16 |= 1 << (a - 1);
}

s8 func_ov000_02189df8(s32 a) {
    Unk02188ec0 *v1;
    u16 m;
    u8 i;
    u8 n;

    v1 = (Unk02188ec0 *) func_ov000_02188584(0x10);
    m = v1->mUnk_d16;
    if (m == 0) {
        return -1;
    }
    n = i = 0;
    for (; i < 0xd; i++) {
        if ((m & (1 << i)) != 0) {
            if (n == a) {
                return i;
            }
            n++;
        }
    }
    return -1;
}

void func_ov000_02189d2c(u32 a) {
    Unk02188ec0 *v1;

    v1 = (Unk02188ec0 *) func_ov000_02188584(0x10);
    switch (a) {
        case 3:
            v1->mUnk_cb0 = OS_GetTick();
            func_ov000_02189868(data_ov000_021b07bc, data_ov000_021b07c4, v1->mUnk_d11, 0x200000);
            break;
        case 4:
            v1->mUnk_cb0 = OS_GetTick();
            func_ov000_02189868(data_ov000_021b07bc, v1->mUnk_300[v1->mUnk_d0f].mUnk_04,
                                v1->mUnk_300[v1->mUnk_d0f].mUnk_02, 0x300000);
            break;
        case 5:
            v1->mUnk_cb0 = OS_GetTick();
            func_ov000_02189868(data_ov000_021b07bc, v1->mUnk_300[v1->mUnk_d0f].mUnk_04, v1->mUnk_d11, 0x300000);
            break;
    }
}

u32 func_ov000_02189cdc(Unk02188ec0 *v1) {
    v1->mUnk_cb0 = OS_GetTick();
    v1->mUnk_d11 = 0;
    v1->mUnk_cb0 = OS_GetTick();
    func_ov000_02189868(data_ov000_021b07bc, data_ov000_021b07c4, v1->mUnk_d11, 0x200000);
    return 3;
}

u32 func_ov000_02189c50(Unk02188ec0 *v1) {
    if ((OS_GetTick() - v1->mUnk_cb0) * 64 / 0x82ea >= 0x12c) {
        v1->mUnk_d11 += 2;
        if (v1->mUnk_d11 >= 0xd) {
            return func_ov000_02189998(v1, 3);
        }
        v1->mUnk_cb0 = OS_GetTick();
        func_ov000_02189868(data_ov000_021b07bc, data_ov000_021b07c4, v1->mUnk_d11, 0x200000);
    }
    return 3;
}

u32 func_ov000_02189c04(Unk02188ec0 *v1) {
    v1->mUnk_d15 = 0;
    v1->mUnk_d0b_4 = v1->mUnk_d0b_4 + 1;
    func_ov000_0218973c(0);
    v1->mUnk_d11 = 1;
    return 3;
}

u32 func_ov000_02189b28(Unk02188ec0 *v1) {
    if ((OS_GetTick() - v1->mUnk_cb0) * 64 / 0x82ea >= 0x96 || v1->mUnk_300[v1->mUnk_d0f].mUnk_00_lo == 1) {
        v1->mUnk_300[v1->mUnk_d0f].mUnk_00_lo = 0;
        v1->mUnk_d0f++;
        if (v1->mUnk_d10 <= v1->mUnk_d0f) {
            v1->mUnk_d0f = 0;
            return func_ov000_02189998(v1, 4);
        }
        v1->mUnk_cb0 = OS_GetTick();
        func_ov000_02189868(data_ov000_021b07bc, v1->mUnk_300[v1->mUnk_d0f].mUnk_04, v1->mUnk_300[v1->mUnk_d0f].mUnk_02,
                            0x300000);
    }
    return 4;
}

u32 func_ov000_02189a28(Unk02188ec0 *v1) {
    if ((OS_GetTick() - v1->mUnk_cb0) * 64 / 0x82ea >= 0x96 || v1->mUnk_300[v1->mUnk_d0f].mUnk_00_lo == 1) {
        v1->mUnk_300[v1->mUnk_d0f].mUnk_00_lo = 0;
        v1->mUnk_d0f++;
        if (v1->mUnk_d10 == v1->mUnk_d0f) {
            v1->mUnk_d15++;
            v1->mUnk_d0f = 0;
            v1->mUnk_d11 = func_ov000_02189df8(v1->mUnk_d15);
        }
        if (v1->mUnk_d11 < 0) {
            v1->mUnk_d15 = 0;
            return func_ov000_02189998(v1, 5);
        }
        v1->mUnk_cb0 = OS_GetTick();
        func_ov000_02189868(data_ov000_021b07bc, v1->mUnk_300[v1->mUnk_d0f].mUnk_04, v1->mUnk_d11, 0x300000);
    }
    return 5;
}

u32 func_ov000_02189998(Unk02188ec0 *v1, u32 a) {
    switch (a) {
        case 3:
            if (v1->mUnk_d12 != 0 || v1->mUnk_d16 != 0) {
                if (func_ov000_0218973c(1) != 0) {
                    a = 4;
                } else {
                    a = func_ov000_02189888(v1);
                }
            } else if (v1->mUnk_d0b_4 < 1) {
                a = func_ov000_02189c04(v1);
            } else {
                a = 6;
            }
            break;
        case 4:
            a = func_ov000_02189888(v1);
            break;
        case 5:
            if (v1->mUnk_d0b_4 < 1) {
                a = func_ov000_02189c04(v1);
            } else {
                a = 6;
            }
            break;
    }
    func_ov000_02189d2c(a);
    return a;
}

u32 func_ov000_021898dc(Unk02188ec0 *v1, u32 a) {
    u8 i;
    u8 n;

    if (a == 0x11) {
        return a;
    }
    i = 0;
    n = v1->mUnk_d12;
    for (; i < n; i++) {
        if (v1->mUnk_444[i].mUnk_00 == 0) {
            break;
        }
    }
    if (a == 6) {
        if (n == i) {
            if (i == 0) {
                func_ov000_02188508(5);
            } else {
                func_ov000_02188508(6);
            }
            return 0x11;
        }
    } else {
        if (n == 0) {
            return a;
        }
        if (n == i) {
            return a;
        }
        if (v1->mUnk_444[i].mUnk_02 < 0x14) {
            return a;
        }
    }
    v1->mUnk_d13 = i;
    if (func_ov000_021a6024() != 1) {
        v1->mUnk_d0e = a;
        a = 7;
    }
    return a;
}
