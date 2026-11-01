#include "Main/Unknown/code_020c13e8.h"
#include "Main/Unknown/code_020c0dd8.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020c13d0.h"
#include "Main/Unknown/code_0205dc7c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020b1000.h"

void func_020c1ef8(void) {
    s32 a[8];
    u32 w;
    s32 neg;
    s32 x0;
    s32 x1;
    s32 v;
    s32 c;
    u16 i;

    if (data_0217561c->mUnk_4cc == 0) {
        return;
    }
    data_0217b3e0->mUnk_00a4 = 1;
    if (data_021759c0->mUnk_08 == 2 && data_021759c0->mUnk_58 != 0) {
        data_0217b3e0->mUnk_00ac = func_020c0f48;
        data_0217b3e0->mUnk_00b0 = 0;
        func_020b1d90();
    } else {
        data_0217b3e0->mUnk_00ac = func_020c1e70;
        data_0217b3e0->mUnk_00b0 = 0;
    }
    neg = -1;
    x0 = 0;
    x1 = 0;
    for (i = 0; (u32) i < (u32) data_021759c0->mUnk_3d0; i++) {
        data_0217b3e0->mUnk_0040[i] = i;
        if (data_021759c0->mUnk_1c == 1 || data_021759c0->mUnk_08 == 2) {
            v = x0;
            if ((u32) data_021759c0->mUnk_68[i].mUnk_08.mUnk_00 <= 3 &&
                ((1 << data_021759c0->mUnk_68[i].mUnk_08.mUnk_00) & 0xd)) {
                v = 1;
            }
            c = v != 0 ? 1 : x1;
            a[i] = c * 8 + 8 - func_0203c8dc(i);
            if (func_0203c8dc(i) == 1) {
                a[i] += 0x20;
            }
            a[i] = a[i] * neg;
        } else {
            a[i] = func_0203c8dc(i);
        }
    }
    func_020ae770(data_0217b3e0->mUnk_0040, a, data_021759c0->mUnk_3d0);
    if (data_021759c0->mUnk_08 == 3 || data_021759c0->mUnk_08 == 5) {
        if (func_020617a8(&w) != 0) {
            if (w >= 0xb4) {
                func_0212ecc0(&data_0217d068, 0, 0x46);
            }
        }
    }
}

void func_020c1e70(void) {
    s32 n;

    n = data_0217b3e0->mUnk_00b0++;
    if (n < 0x14) {
        data_0217b3e0->mUnk_00a0 = func_020ae4c0(1, -0x100, 0, n, 0x14);
    } else {
        data_0217b3e0->mUnk_00a0 = 0;
        data_0217b3e0->mUnk_00ac = func_020c1de4;
        data_0217b3e0->mUnk_00b0 = 0;
    }
}

void func_020c1de4(void) {
    s32 n;
    u16 f;
    Unk02175628Index i;

    n = data_0217b3e0->mUnk_00b0++;
    if (n >= 0x5a) {
        data_0217b3e0->mUnk_00ac = func_020c1bc0;
        data_0217b3e0->mUnk_00b0 = 0;
    }
    i = UNK_02175628_INDEX_8;
    f = data_02175628[i].mUnk_00 & 1;
    if (f != 0 && n >= 0x2d) {
        data_0217b3e0->mUnk_00ac = func_020c1bc0;
        data_0217b3e0->mUnk_00b0 = 0;
    }
}

void func_020c1bc0(void) {
    s32 n;
    u16 f;
    u16 i;
    s32 t;
    s32 v;
    u32 p;
    u32 r;
    Unk0217aa1c_00 *s;
    Unk02175628Index x;

    n = data_0217b3e0->mUnk_00b0++;
    if (n % 5 == 0) {
        t = 1;
        for (i = 0; (u32) i < (u32) data_021759c0->mUnk_3d0; i++) {
            if (data_021759c0->mUnk_1c == 1 || data_021759c0->mUnk_08 == 2) {
                p = func_0205dc7c(i);
                r = func_0205db28();
                v = data_0217aa1c->mUnk_000[r][func_0205dc7c(p)].mUnk_05;
            } else {
                p = func_0205dc7c(i);
                r = func_0205db28();
                s = &data_0217aa1c->mUnk_000[r][func_0205dc7c(p)];
                v = s->mUnk_00;
            }
            if (data_0217b3e0->mUnk_0020[i] < v) {
                if (data_0217b3e0->mUnk_0020[i] < 0x3e8) {
                    data_0217b3e0->mUnk_0020[i]++;
                    t = 0;
                }
            }
        }
        if (t != 0) {
            data_0217b3e0->mUnk_00ac = func_020c195c;
            data_0217b3e0->mUnk_00b0 = 0;
            data_0217b3e0->mUnk_00b0 = 0;
            if (data_021759c0->mUnk_1c == 1 || data_021759c0->mUnk_08 == 2) {
                func_0212ecc0(&data_0217d068, 0, 0x29);
            }
        } else {
            func_0212ecc0(&data_0217d068, 0, 0x29);
        }
    }
    x = UNK_02175628_INDEX_8;
    f = data_02175628[x].mUnk_00 & 1;
    if (f != 0 && n >= 0x2d) {
        data_0217b3e0->mUnk_00ac = func_020c195c;
        data_0217b3e0->mUnk_00b0 = 0;
    }
}

void func_020c195c(void) {
    s32 n;
    u16 f;
    u16 i;
    u32 p;
    u32 r;
    Unk0217aa1c_00 *s;
    Unk02175628Index x;

    n = data_0217b3e0->mUnk_00b0++;
    if (n < 0x5a) {
        for (i = 0; (u32) i < (u32) data_021759c0->mUnk_3d0; i++) {
            if (data_021759c0->mUnk_1c == 1 || data_021759c0->mUnk_08 == 2) {
                p = func_0205dc7c(i);
                r = func_0205db28();
                data_0217b3e0->mUnk_0020[i] = data_0217aa1c->mUnk_000[r][func_0205dc7c(p)].mUnk_05;
            } else {
                p = func_0205dc7c(i);
                r = func_0205db28();
                s = &data_0217aa1c->mUnk_000[r][func_0205dc7c(p)];
                data_0217b3e0->mUnk_0020[i] = s->mUnk_00;
            }
        }
    } else {
        if (data_021759c0->mUnk_58 != 0) {
            data_0217b3e0->mUnk_00ac = func_020c0fd0;
            data_0217b3e0->mUnk_00b0 = 0;
        } else if (data_021759c0->mUnk_60 == 1) {
            data_0217b3e0->mUnk_00ac = func_020c13e8;
            data_0217b3e0->mUnk_00b0 = 0;
        } else {
            data_0217b3e0->mUnk_00ac = func_020c1728;
            data_0217b3e0->mUnk_00b0 = 0;
        }
    }
    x = UNK_02175628_INDEX_8;
    f = data_02175628[x].mUnk_00 & 1;
    if (f != 0 && n >= 0x2d) {
        if (data_021759c0->mUnk_58 != 0) {
            data_0217b3e0->mUnk_00ac = func_020c0fd0;
            data_0217b3e0->mUnk_00b0 = 0;
        } else if (data_021759c0->mUnk_60 == 1) {
            data_0217b3e0->mUnk_00ac = func_020c13e8;
            data_0217b3e0->mUnk_00b0 = 0;
        } else {
            data_0217b3e0->mUnk_00ac = func_020c1728;
            data_0217b3e0->mUnk_00b0 = 0;
        }
    }
}

void func_020c1728(void) {
    s32 n;
    s32 m;
    u16 f;
    u16 j;
    Unk02175628Index i;

    n = data_0217b3e0->mUnk_00b0++;
    if (n < 0x2d) {
        m = data_0217b3e0->mUnk_00a8;
        if (m < data_021759c0->mUnk_3d0) {
            if (n % 5 == 0) {
                switch (m) {
                    case 0:
                        func_0212ecc0(&data_0217d068, 0, 0x32);
                        break;
                    case 1:
                        func_0212ecc0(&data_0217d068, 0, 0x33);
                        break;
                    case 2:
                        func_0212ecc0(&data_0217d068, 0, 0x34);
                        break;
                    case 3:
                        func_0212ecc0(&data_0217d068, 0, 0x35);
                        break;
                    case 4:
                        func_0212ecc0(&data_0217d068, 0, 0x36);
                        break;
                    case 5:
                        func_0212ecc0(&data_0217d068, 0, 0x37);
                        break;
                    case 6:
                        func_0212ecc0(&data_0217d068, 0, 0x38);
                        break;
                    case 7:
                        func_0212ecc0(&data_0217d068, 0, 0x39);
                        break;
                }
                data_0217b3e0->mUnk_0000[data_0217b3e0->mUnk_00a8++] = 0;
            }
        }
    } else {
        func_020c1060();
        data_0217b3e0->mUnk_00ac = func_020c155c;
        data_0217b3e0->mUnk_00b0 = 0;
    }
    i = UNK_02175628_INDEX_8;
    f = data_02175628[i].mUnk_00 & 1;
    if (f != 0 && n >= 0x2d) {
        for (j = 0; (u32) j < (u32) data_021759c0->mUnk_3d0; j++) {
            data_0217b3e0->mUnk_0000[j] = 0;
        }
        data_0217b3e0->mUnk_00a8 = data_021759c0->mUnk_3d0;
        func_020c1060();
        data_0217b3e0->mUnk_00ac = func_020c155c;
        data_0217b3e0->mUnk_00b0 = 0;
    }
}

void func_020c155c(void) {
    s32 n;
    s32 m;
    u16 f;
    Unk02175628Index i;

    n = data_0217b3e0->mUnk_00b0++;
    m = data_0217b3e0->mUnk_00a8;
    if (m > 0) {
        if (n % 5 == 0) {
            data_0217b3e0->mUnk_00a8 = m - 1;
            data_0217b3e0->mUnk_0000[data_0217b3e0->mUnk_00a8] = 1;
            switch (data_0217b3e0->mUnk_00a8) {
                case 0:
                    func_0212ecc0(&data_0217d068, 0, 0x2a);
                    break;
                case 1:
                    func_0212ecc0(&data_0217d068, 0, 0x2b);
                    break;
                case 2:
                    func_0212ecc0(&data_0217d068, 0, 0x2c);
                    break;
                case 3:
                    func_0212ecc0(&data_0217d068, 0, 0x2d);
                    break;
                case 4:
                    func_0212ecc0(&data_0217d068, 0, 0x2e);
                    break;
                case 5:
                    func_0212ecc0(&data_0217d068, 0, 0x2f);
                    break;
                case 6:
                    func_0212ecc0(&data_0217d068, 0, 0x30);
                    break;
                case 7:
                    func_0212ecc0(&data_0217d068, 0, 0x31);
                    break;
            }
        }
    } else {
        data_0217b3e0->mUnk_00ac = func_020c13e8;
        data_0217b3e0->mUnk_00b0 = 0;
    }
    i = UNK_02175628_INDEX_8;
    f = data_02175628[i].mUnk_00 & 1;
    if (f != 0 && n >= 0x2d) {
        data_0217b3e0->mUnk_00ac = func_020c13e8;
        data_0217b3e0->mUnk_00b0 = 0;
    }
}

static inline Unk0217aa1c_144_00 *func_020c13e8_inline(s32 j) {
    return &data_0217aa1c->mUnk_144[func_0205db28()].mUnk_00[j];
}

void func_020c13e8(void) {
    s32 n;
    s32 i;
    s32 a;
    s32 b;

    n = data_0217b3e0->mUnk_00b0++;
    if (n < 0x3c) {
        func_020c1060();
        for (i = 0; i < data_021759c0->mUnk_3d0; i++) {
            data_0217b3e0->mUnk_0000[i] = 1;
        }
    } else {
        if (data_021759c0->mUnk_1c == 1 || data_021759c0->mUnk_08 == 2) {
            if (data_021759c0->mUnk_58 != 0) {
                a = func_020c13e8_inline(0)->mUnk_02;
                b = func_020c13e8_inline(1)->mUnk_02;
                if (a <= b) {
                    a = b;
                }
            } else {
                a = data_0217b3e0->mUnk_0020[data_0217b3e0->mUnk_0040[0]];
            }
            data_0217b3e0->mUnk_00b4 = a >= data_021759c0->mUnk_3d8;
        } else {
            data_0217b3e0->mUnk_00b4 = (u32) data_021759c0->mUnk_60 >= data_021759c0->mUnk_3d8;
        }
        data_0217b3e0->mUnk_00ac = func_020c13d0;
        data_0217b3e0->mUnk_00b0 = 0;
    }
}
