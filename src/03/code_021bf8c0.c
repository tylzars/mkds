#include "03/code_021bf4dc.h"
#include "03/code_021bf8c0.h"
#include "03/code_021bf000.h"
#include "03/code_021bf810.h"
#include "03/code_021c0000.h"
#include "03/code_021c209c.h"
#include "03/code_021c04ec.h"
#include "03/code_021c0680.h"
#include "code_0212df7c.h"
#include "03/code_021cdbd0.h"
#include "03/code_021d1790.h"
#include "03/code_021d197c.h"
#include "03/unk_021da000.h"
#include "03/code_021d2940.h"
#include "code_02147cd8.h"
#include "03/code_021d1000.h"
#include "03/code_021d1970.h"
#include "03/code_021d1c18.h"
#include "03/code_021d2ecc.h"
#include "03/code_021d3000.h"
#include "03/code_021d1fd0.h"
#include "03/code_021d27d8.h"
#include "03/code_021d3488.h"
#include "03/code_021d1770.h"
#include "03/unk_021d5f00.h"
#include "code_02142eac.h"
#include "code_0214b824.h"

void func_ov003_021bf8c0(void) {
    data_ov003_021da154 = func_ov003_021d285c(0xc0, 4);
    func_ov003_021bf620(data_ov003_021d6bb0, func_0214ba2c);
    switch (func_ov003_021c20c0()) {
        case 0:
            func_ov003_021bf620(data_ov003_021d6b60[0], func_0214bd6c);
            break;
        case 1:
            func_ov003_021bf620(data_ov003_021d6b60[1], func_0214bd6c);
            break;
    }
}

void func_ov003_021bf920(void) {
    u32 i;
    u16 a;
    i = 0;
    a = *(vu16 *) 0x4000208;
    *(vu16 *) 0x4000208 = 0;
    if (func_02143280() != 0x8000) {
        i = func_021431d8();
    }
    *(vu16 *) 0x4000208;
    *(vu16 *) 0x4000208 = a;
    func_ov003_021d1c3c(0, data_ov003_021d5f58[data_ov003_021da158->mUnk_08][i], (u8 *) data_ov003_021da158->mUnk_00);
    data_ov003_021da158->mUnk_00->mUnk_00 =
        ((data_ov003_021d5f54[0] & 0x1ff) << 16) |
        ((data_ov003_021da158->mUnk_00->mUnk_00 & 0xfe00ff00) | (data_ov003_021d5f54[1] & 0xff));
    data_ov003_021da158->mUnk_00->mUnk_04 = (data_ov003_021da158->mUnk_00->mUnk_04 & 0xfffff3ff) | 0x800;
}

void func_ov003_021bf9b8(void) {
    if (data_ov003_021da158 != NULL) {
        func_ov003_021d34c0(0, data_ov003_021da158->mUnk_04);
        func_ov003_021d2f00((u32 *) data_ov003_021da158->mUnk_00);
        func_ov003_021d2808(&data_ov003_021da158);
    }
}

void func_ov003_021bf9e8(int param_1) {
    if (data_ov003_021da158 == NULL) {
        data_ov003_021da158 = func_ov003_021d285c(0xc, 4);
        data_ov003_021da158->mUnk_08 = param_1;
        data_ov003_021da158->mUnk_00 = func_ov003_021d1c18(0, data_ov003_021d5f58[param_1][0]);
        data_ov003_021da158->mUnk_00->mUnk_00 =
            ((data_ov003_021d5f54[0] & 0x1ff) << 16) |
            ((data_ov003_021da158->mUnk_00->mUnk_00 & 0xfe00ff00) | (data_ov003_021d5f54[1] & 0xff));
        data_ov003_021da158->mUnk_00->mUnk_04 = (data_ov003_021da158->mUnk_00->mUnk_04 & 0xfffff3ff) | 0x800;
        data_ov003_021da158->mUnk_04 = func_ov003_021d3544(0, func_ov003_021bf920, NULL, 0x78);
    }
}

void func_ov003_021bfa80(u32 param_1) {
    s32 i;
    s32 j;
    func_ov003_021d34c8(0, param_1);
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            func_ov003_021d2388(data_ov003_021da15c->mUnk_000[i][j]);
            if (i == 0) {
                func_ov003_021d197c(data_ov003_021da15c->mUnk_104[j]);
            }
        }
    }
    for (i = 0; i < 2; i++) {
        func_ov003_021d197c(data_ov003_021da15c->mUnk_0fc[i]);
    }
    for (i = 0; i < 4; i++) {
        func_ov003_021d2f00((u32 *) data_ov003_021da15c->mUnk_0ec[i]);
    }
    for (i = 0; i < 0x2f; i++) {
        func_ov003_021d2f00((u32 *) data_ov003_021da15c->mUnk_030[i]);
    }
    func_ov003_021d2808(&data_ov003_021da15c);
}

static inline void func_ov003_021bfbd0_inline(Unk021bf920 *p, u32 *x, u32 *y) {
    *x = (p->mUnk_00 & 0x1ff0000) >> 16;
    *y = p->mUnk_00 & 0xff;
}

void func_ov003_021bfb28(u32 param_1) {
    s32 a;
    s32 y;
    func_ov003_021bfbd0_inline(data_ov003_021da15c->mUnk_030[0], (u32 *) &a, (u32 *) &y);
    y += 12;
    func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 0, y);
    if (y >= 0xc0) {
        func_ov003_021d34e0((Unk021d34e0 *) param_1, func_ov003_021bfa80);
    }
}

void func_ov003_021bfb7c(u32 param_1) {
    s32 x;
    s32 y;
    func_ov003_021bfbd0_inline(data_ov003_021da15c->mUnk_030[12], (u32 *) &x, (u32 *) &y);
    y += 12;
    func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 1, y);
    if (y >= 0xc0) {
        func_ov003_021d34e0((Unk021d34e0 *) param_1, func_ov003_021bfb28);
    }
}

void func_ov003_021bfbd0(u32 param_1) {
    s32 a;
    s32 b;
    func_ov003_021bfbd0_inline(data_ov003_021da15c->mUnk_030[24], (u32 *) &a, (u32 *) &b);
    b += 12;
    func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 2, b);
    if (b >= 0xc0) {
        func_ov003_021d34e0((Unk021d34e0 *) param_1, func_ov003_021bfb7c);
    }
}

void func_ov003_021bfc28(u32 param_1) {
    s32 a;
    s32 y;
    func_ov003_021bfbd0_inline(data_ov003_021da15c->mUnk_030[36], (u32 *) &a, (u32 *) &y);
    y += 12;
    func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 3, y);
    if (y >= 0xc0) {
        func_ov003_021d34e0((Unk021d34e0 *) param_1, func_ov003_021bfbd0);
    }
}

void func_ov003_021bfc80(u32 param_1) {
    s32 a;
    s32 b;
    func_ov003_021bfbd0_inline(func_ov003_021d1974((s32) data_ov003_021da15c->mUnk_0fc[0], 0), (u32 *) &a, (u32 *) &b);
    b += 12;
    func_ov003_021c0154(data_ov003_021da15c->mUnk_11d, 4, b);
    if (b >= 0xc0) {
        func_ov003_021d34e0((Unk021d34e0 *) param_1, func_ov003_021bfc28);
    }
}

void func_ov003_021bfce0(int param_1) {
    s8 a;
    a = data_ov003_021da15c->mUnk_121;
    data_ov003_021da15c->mUnk_121 = data_ov003_021d6140[a][param_1];
    if (data_ov003_021da15c->mUnk_121 == 0x2e && param_1 == 3) {
        data_ov003_021da15c->mUnk_120 = a;
    } else if (data_ov003_021da15c->mUnk_121 == 0x33 && (param_1 == 1 || param_1 == 3)) {
        data_ov003_021da15c->mUnk_120 = a;
    } else if (data_ov003_021da15c->mUnk_121 == 0x34 && (param_1 == 1 || param_1 == 3)) {
        if (a != 0x2e) {
            data_ov003_021da15c->mUnk_120 = a;
        }
    } else if (data_ov003_021da15c->mUnk_121 == -1) {
        if (data_ov003_021da15c->mUnk_120 == 0x23 || data_ov003_021da15c->mUnk_120 == 0x32) {
            data_ov003_021da15c->mUnk_121 = 0x23;
        } else {
            data_ov003_021da15c->mUnk_121 = 0x22;
        }
    } else if (data_ov003_021da15c->mUnk_121 == -2) {
        switch (data_ov003_021da15c->mUnk_120) {
            case 0:
            case 0x31:
                data_ov003_021da15c->mUnk_121 = 0x31;
                break;
            case 1:
            case 0x24:
                data_ov003_021da15c->mUnk_121 = 0x24;
                break;
            case 3:
            case 0x26:
                data_ov003_021da15c->mUnk_121 = 0x26;
                break;
            case 4:
            case 0x27:
                data_ov003_021da15c->mUnk_121 = 0x27;
                break;
            case 5:
            case 0x28:
                data_ov003_021da15c->mUnk_121 = 0x28;
                break;
            default:
                data_ov003_021da15c->mUnk_121 = 0x25;
                break;
        }
    } else if (data_ov003_021da15c->mUnk_121 == -3) {
        switch (data_ov003_021da15c->mUnk_120) {
            case 6:
            case 0x29:
                data_ov003_021da15c->mUnk_121 = 0x29;
                break;
            case 7:
            case 0x2a:
                data_ov003_021da15c->mUnk_121 = 0x2a;
                break;
            case 9:
            case 0x2c:
                data_ov003_021da15c->mUnk_121 = 0x2c;
                break;
            case 10:
            case 0x2d:
                data_ov003_021da15c->mUnk_121 = 0x2d;
                break;
            case 11:
            case 0x22:
            case 0x23:
            case 0x32:
                data_ov003_021da15c->mUnk_121 = 0x2e;
                break;
            default:
                data_ov003_021da15c->mUnk_121 = 0x2b;
                break;
        }
    } else if (data_ov003_021da15c->mUnk_121 == -4) {
        switch (data_ov003_021da15c->mUnk_120) {
            case 0:
            case 0x31:
                data_ov003_021da15c->mUnk_121 = 0;
                break;
            case 1:
            case 0x24:
                data_ov003_021da15c->mUnk_121 = 1;
                break;
            case 3:
            case 0x26:
                data_ov003_021da15c->mUnk_121 = 3;
                break;
            case 4:
            case 0x27:
                data_ov003_021da15c->mUnk_121 = 4;
                break;
            case 5:
            case 0x28:
                data_ov003_021da15c->mUnk_121 = 5;
                break;
            default:
                data_ov003_021da15c->mUnk_121 = 2;
                break;
        }
    } else if (data_ov003_021da15c->mUnk_121 == -5) {
        switch (data_ov003_021da15c->mUnk_120) {
            case 6:
            case 0x29:
                data_ov003_021da15c->mUnk_121 = 6;
                break;
            case 7:
            case 0x2a:
                data_ov003_021da15c->mUnk_121 = 7;
                break;
            case 9:
            case 0x2c:
                data_ov003_021da15c->mUnk_121 = 9;
                break;
            case 10:
            case 0x2d:
                data_ov003_021da15c->mUnk_121 = 10;
                break;
            case 11:
            case 0x22:
                data_ov003_021da15c->mUnk_121 = 11;
                break;
            case 0x23:
            case 0x32:
                data_ov003_021da15c->mUnk_121 = 0x32;
                break;
            default:
                data_ov003_021da15c->mUnk_121 = 8;
                break;
        }
    }
    func_ov003_021bffb0();
    func_ov003_021cdc10(8);
}

void func_ov003_021bffb0(void) {
    u32 a;
    switch (data_ov003_021da15c->mUnk_121) {
        case 0x2f:
            a = 0x42;
            break;
        case 0x30:
            a = 0x41;
            break;
        case 0x31:
            a = 0x43;
            break;
        case 0x32:
            a = 0x41;
            break;
        case 0x33:
        case 0x34:
            a = 0x45;
            break;
        default:
            a = 0x40;
            break;
    }
    func_ov003_021d1c3c(0, a, func_ov003_021d1974((s32) data_ov003_021da15c->mUnk_114, 0));
    func_ov003_021d1790(data_ov003_021da15c->mUnk_114, -1, 2);
    func_ov003_021d17d4(data_ov003_021da15c->mUnk_114, -1, data_ov003_021d606c[data_ov003_021da15c->mUnk_121][0],
                        data_ov003_021d606e[data_ov003_021da15c->mUnk_121][0]);
}

void func_ov003_021c0050(int param_1, int param_2) {
    Unk021bf920 *p;
    s32 a;
    if (param_1 < 0) {
        return;
    }
    if (param_1 < 0x2f) {
        p = data_ov003_021da15c->mUnk_030[param_1];
        p->mUnk_00 = p->mUnk_00 & 0xfffff3ff;
        p->mUnk_04 = (p->mUnk_04 & 0xffff0fff) | (data_ov003_021d5f60[param_2] << 12);
        return;
    }
    a = param_1 - 0x2f;
    if (a < 4) {
        p = data_ov003_021da15c->mUnk_0ec[a];
        p->mUnk_00 = p->mUnk_00 & 0xfffff3ff;
        p->mUnk_04 = (p->mUnk_04 & 0xffff0fff) | (data_ov003_021d5f60[param_2] << 12);
        return;
    }
    func_ov003_021d1890(data_ov003_021da15c->mUnk_0fc[param_1 - 0x33], -1, 0, data_ov003_021d5f64[param_2]);
}

void func_ov003_021c00ec(int param_1) {
    BOOL a;
    BOOL b;
    s32 i;
    s32 j;
    a = FALSE;
    b = FALSE;
    data_ov003_021da15c->mUnk_11d = param_1;
    i = 0;
    if (i < 4) {
        j = 0;
        do {
            func_ov003_021c0154(param_1, i, data_ov003_021d5fb0[j][1]);
            j = (s32) (j + 12);
            i++;
        } while (i < 4);
    }
    if (param_1 == 2) {
        a = TRUE;
    } else if (param_1 == 1) {
        b = TRUE;
    }
    func_ov003_021c0050(0x2f, a);
    func_ov003_021c0050(0x30, b);
}

// non-matching: size 0x1b8 against 0x1c4. The original spills the product of the parameter by 12 and the pointer to the
// first row length to stack offsets 20 and 28 and steps pointers through the halfword table; the compiled code keeps
// them in registers.
void func_ov003_021c0154(u32 param_1, s32 param_2, u32 param_3) {
    u8 a[5] = {12, 12, 12, 11, 0};
    u8 c[5] = {1, 1, 1, 1, 0};
    u8 d[5] = {0, 0, 0, 0, 2};
    s32 b;
    s32 i;
    s32 k;
    Unk021bf920 *p;
    b = param_2 * 12;
    if (a[param_2] > 0) {
        for (i = 0; i < a[param_2]; i++) {
            p = data_ov003_021da15c->mUnk_030[b + i];
            p->mUnk_00 = p->mUnk_00 & 0xc1fffcff;
            p = data_ov003_021da15c->mUnk_030[b + i];
            p->mUnk_00 =
                ((data_ov003_021d5fb0[b + i][0] & 0x1ff) << 16) | ((p->mUnk_00 & 0xfe00ff00) | (param_3 & 0xff));
        }
    }
    if (param_2 < 4) {
        func_ov003_021d1ffc(data_ov003_021da15c->mUnk_000[param_1][param_2], data_ov003_021d5fb0[b][0], param_3,
                            data_ov003_021da15c->mUnk_104[param_2], 2);
    }
    k = Div32Remainder(param_2 + 3, 4);
    if (c[param_2] > 0) {
        for (i = 0; i < c[param_2]; i++) {
            p = data_ov003_021da15c->mUnk_0ec[k];
            p->mUnk_00 = p->mUnk_00 & 0xc1fffcff;
            p = data_ov003_021da15c->mUnk_0ec[k];
            p->mUnk_00 = ((data_ov003_021d5f90[k][0] & 0x1ff) << 16) | ((p->mUnk_00 & 0xfe00ff00) | (param_3 & 0xff));
        }
    }
    for (i = 0; i < d[param_2]; i++) {
        func_ov003_021d18f0(data_ov003_021da15c->mUnk_0fc[i], -1, 0, 0);
        func_ov003_021d17d4(data_ov003_021da15c->mUnk_0fc[i], -1, data_ov003_021d5f88[i][0], param_3);
    }
}

void func_ov003_021c0318(void) {
    s32 a;
    if (func_ov003_021d2ae8(0x20) != 0) {
        func_ov003_021bfce0(0);
    }
    if (func_ov003_021d2ae8(0x40) != 0) {
        func_ov003_021bfce0(1);
    }
    if (func_ov003_021d2ae8(0x10) != 0) {
        func_ov003_021bfce0(2);
    }
    if (func_ov003_021d2ae8(0x80) != 0) {
        func_ov003_021bfce0(3);
    }
    if (func_ov003_021d2b04(1) != 0) {
        a = data_ov003_021da15c->mUnk_121;
        if (a < 0x2f) {
            if (data_ov003_021da15c->mUnk_124 == 0) {
                func_ov003_021cdc10(9);
                return;
            }
            data_ov003_021da15c->mUnk_11c = data_ov003_021d6bdc[data_ov003_021da15c->mUnk_11d][a];
            if (data_ov003_021da15c->mUnk_11d == 1) {
                func_ov003_021c00ec(0);
            }
            return;
        }
        if (a - 0x2f < 4) {
            switch (a - 0x2f) {
                case 0:
                    func_ov003_021c06b0();
                    return;
                case 1:
                    func_ov003_021c0680();
                    return;
                case 2:
                    if (data_ov003_021da15c->mUnk_124 == 0) {
                        func_ov003_021cdc10(9);
                        return;
                    }
                    break;
                case 3:
                    if (data_ov003_021da15c->mUnk_123 == 0) {
                        func_ov003_021cdc10(9);
                        return;
                    }
                    break;
            }
            if (data_ov003_021da15c->mUnk_11d == 1) {
                func_ov003_021c00ec(0);
            }
            data_ov003_021da15c->mUnk_11c = data_ov003_021d5f80[a - 0x2f];
            return;
        }
        data_ov003_021da15c->mUnk_11c = data_ov003_021d5f6c[a - 0x33];
    }
    if (func_ov003_021d2ae8(2) != 0) {
        if (data_ov003_021da15c->mUnk_123 == 0) {
            if (data_ov003_021da15c->mUnk_125 != 0) {
                return;
            }
            func_ov003_021cdc10(9);
            data_ov003_021da15c->mUnk_125 = 1;
            return;
        }
        data_ov003_021da15c->mUnk_11c = 0x80;
    } else if (func_ov003_021d2acc(2) != 0) {
        data_ov003_021da15c->mUnk_125 = 0;
    }
    if (func_ov003_021d2b04(0x400) != 0) {
        func_ov003_021c06b0();
    }
    if (func_ov003_021d2b04(0x800) != 0) {
        func_ov003_021c0680();
    }
}
