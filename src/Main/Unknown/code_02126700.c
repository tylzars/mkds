#include "Main/Unknown/code_02126700.h"
#include "Main/Unknown/code_02126ea8.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02126f78.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_02016468.h"
#include "code_0214a390.h"
#include "code_0212df7c.h"

#pragma thumb on

void func_02126d28(void) {
    u32 a[9];
    s32 i;
    s32 n;
    s32 m;

    if (data_0217d3f0->mUnk_34 != 0) {
        for (i = 0; i < 9; i++) {
            if (i <= 6) {
                if (data_0217d3f0->mUnk_2204[i] != 0) {
                    a[i] = 1;
                } else {
                    a[i] = 0;
                }
            } else {
                if ((&data_0217d3f0->mUnk_04)[i] != 0) {
                    (&data_0217d3f0->mUnk_04)[i] = 0;
                    *(&data_0217d3f0->mUnk_00 + i - 1) = 1;
                    a[i] = 1;
                } else {
                    a[i] = 0;
                }
            }
        }
        func_02126f78(a);
        func_02016468(10, 0, data_0217d3f0->mUnk_54, 0x1000);
        func_02016468(0x18, 0, &data_0217d3f0->mUnk_1054, 0x1000);
        data_0217d3f0->mUnk_04 = 1;
        data_0217d3f0->mUnk_0c = 0;
        for (i = 0; i < 2; i++) {
            data_0217d3f0->mUnk_205c[i] = data_0217d3f0->mUnk_2064[i];
        }
        for (i = 0; i < 2; i++) {
            data_0217d3f0->mUnk_206c[i] = data_0217d3f0->mUnk_2074[i];
        }
        for (i = 0; i < 7; i++) {
            if (data_0217d3f0->mUnk_2204[i] != 0) {
                n = (data_0215d044[i][0] * data_0215d044[i][1]) << 5;
                m = 0x14;
                if ((u32) i <= 1) {
                    m = 6;
                }
                func_02016468(m, (data_0217d3f0->mUnk_2220[i] + data_0215d054[i]) << 5, data_0217d3f0->mUnk_21e8[i], n);
            }
        }
        if (data_0217d3f0->mUnk_28 > 0) {
            func_02126ef8();
        }
        if (data_0217d3f0->mUnk_18[0] == 0 && data_0217d3f0->mUnk_18[1] == 0) {
            if (data_0217d3f0->mUnk_2258 != -1) {
                func_0212ecc0(&data_0217d068, 0, (u16) data_0217d3f0->mUnk_2258);
            }
        }
    }
}

void func_02126c90(void) {
    Unk0217d3f0 *p;
    s32 i;

    data_0217d3f0->mUnk_0c++;
    for (i = 0; i < 2; i++) {
        data_0217d3f0->mUnk_2054[i] = func_020ae4c0(1, data_0215d040[data_0217d3f0->mUnk_3c],
                                                    (s16) -data_0217d3f0->mUnk_205c[i], data_0217d3f0->mUnk_0c, 0xf);
    }
    p = data_0217d3f0;
    p->mUnk_207c = (p->mUnk_0c * -10) / 15;
    if (data_0217d3f0->mUnk_0c >= 15) {
        if (data_0217d3f0->mUnk_38 == 0) {
            data_0217d3f0->mUnk_34 = 0;
        }
        data_0217d3f0->mUnk_04 = 2;
        data_0217d3f0->mUnk_0c = 0;
    }
}

static inline s32 func_02126a00_inline(u16 a, u16 b, u8 c, u8 d, u8 e, u8 f) {
    if (a >= c && a <= d && b >= e && b <= f) {
        return 1;
    }
    return 0;
}

static inline s32 func_02126a00_inline2(u32 v) {
    s32 r = 0;
    s32 s = 0;
    u16 c = data_02175674[v].mUnk_00;

    if (c == 0 && data_02175680[v].mUnk_00 < 5) {
        s = 1;
    }
    if (s == 0 && data_0217567c[v].mUnk_00 == 0 && c != 0) {
        r = 1;
    }
    return r;
}

// non-matching: register allocation differs (52 words): the original keeps the element offset in r1, t in r3 and y in
// r4 (here r5, r1 and r1)
void func_02126a00(void) {
    s32 m;
    s32 t;
    s32 hit;
    u16 x;
    u16 y;
    Unk0217d3f0 *p;
    u32 v;
    u16 w;

    switch (data_0217d3f0->mUnk_2248) {
        case 0:
            v = 8;
            break;
        case 1:
            v = func_020435bc();
            break;
    }
    x = data_02175670[v].mUnk_00;
    p = data_0217d3f0;
    t = p->mUnk_2054[1] + data_02175672[v].mUnk_00;
    if (t < 0) {
        t = 0xff;
    }
    if (t > 0xff) {
        t = 0xff;
    }
    y = t;
    if (p->mUnk_38 != 0) {
        p->mUnk_04 = 4;
        return;
    }
    m = p->mUnk_28;
    if (m <= 0) {
        return;
    }
    hit = -1;
    if (m == 2) {
        if (func_02126a00_inline2(v) != 0) {
            if (func_02126a00_inline(x, y, data_0215d064[5].mUnk_00, data_0215d064[5].mUnk_01, data_0215d064[5].mUnk_02,
                                     data_0215d064[5].mUnk_03) != 0) {
                hit = 0;
            }
            if (func_02126a00_inline(x, y, data_0215d064[6].mUnk_00, data_0215d064[6].mUnk_01, data_0215d064[6].mUnk_02,
                                     data_0215d064[6].mUnk_03) != 0) {
                hit = 1;
            }
        }
    }
    w = data_02175628[v].mUnk_00;
    if ((u16) (w & 1) == 0) {
        if (func_02126a00_inline2(v) == 0 || m != 1 ||
            func_02126a00_inline(x, y, data_0215d064[4].mUnk_00, data_0215d064[4].mUnk_01, data_0215d064[4].mUnk_02,
                                 data_0215d064[4].mUnk_03) == 0) {
            if (hit == -1) {
                goto L;
            }
        }
    }
    if (m == 1) {
        func_02126ea8();
    } else {
        if (hit == -1 || p->mUnk_2c == hit) {
            func_02126ea8();
        } else {
            p->mUnk_2c = hit;
            func_02126ef8();
        }
    }
    data_0217d3f0->mUnk_04 = 3;
    if (data_0217d3f0->mUnk_28 == 2 && data_0217d3f0->mUnk_2c == 1) {
        if (data_0217d3f0->mUnk_2254 != -1) {
            func_0212ecc0(&data_0217d068, 0, (u16) data_0217d3f0->mUnk_2254);
        }
    } else {
        if (data_0217d3f0->mUnk_2250 != -1) {
            func_0212ecc0(&data_0217d068, 0, (u16) data_0217d3f0->mUnk_2250);
        }
    }
    data_0217d3f0->mUnk_224c = 1;
    return;
L:
    if (m == 2) {
        if ((u16) (w & 0x20) != 0 && p->mUnk_2c == 1) {
            p->mUnk_2c = 0;
            func_02126ef8();
            func_02105ac0(0);
            return;
        }
        if ((u16) (w & 0x10) != 0 && p->mUnk_2c == 0) {
            p->mUnk_2c = 1;
            func_02126ef8();
            func_02105ac0(0);
        }
    }
}

void func_021269b8(void) {
    data_0217d3f0->mUnk_0c++;
    data_0217d3f0->mUnk_224c = 0;
    if (data_0217d3f0->mUnk_0c >= 10) {
        data_0217d3f0->mUnk_30 = 1;
        data_0217d3f0->mUnk_04 = 2;
        data_0217d3f0->mUnk_0c = 0;
    } else if (data_0217d3f0->mUnk_0c >= 5) {
        func_02126ef8();
    }
}

void func_021268f8(void) {
    Unk0217d3f0 *p;
    s32 i;

    data_0217d3f0->mUnk_0c++;
    for (i = 0; i < 2; i++) {
        data_0217d3f0->mUnk_2054[i] = func_020ae4c0(1, (s16) -data_0217d3f0->mUnk_205c[i],
                                                    data_0215d040[data_0217d3f0->mUnk_40], data_0217d3f0->mUnk_0c, 0xf);
    }
    p = data_0217d3f0;
    p->mUnk_207c = -10 - (p->mUnk_0c * -10) / 15;
    if (data_0217d3f0->mUnk_0c >= 15) {
        for (i = 0; i < 2; i++) {
            data_0217d3f0->mUnk_2054[i] = -192;
        }
        data_0217d3f0->mUnk_04 = 0;
        func_02126ea8();
        data_0217d3f0->mUnk_0c = 0;
        data_0217d3f0->mUnk_38 = 0;
        data_0217d3f0->mUnk_30 = 0;
        data_0217d3f0->mUnk_18[0] = 0;
        data_0217d3f0->mUnk_18[1] = 0;
    }
}

void func_02126834(void) {
    if (data_0217d3f0->mUnk_50 != 0) {
        data_0217d3f0->mUnk_08 = data_0217d3f0->mUnk_00;
        data_0217d3f0->mUnk_00 = data_0217d3f0->mUnk_04;
        switch (data_0217d3f0->mUnk_00) {
            case 0:
                func_02126d28();
                break;
            case 1:
                func_02126c90();
                break;
            case 2:
                func_02126a00();
                break;
            case 3:
                func_021269b8();
                break;
            case 4:
                func_021268f8();
                break;
        }
        if (data_0217d3f0->mUnk_18[0] != 0 || data_0217d3f0->mUnk_18[1] != 0) {
            data_0217d3f0->mUnk_10++;
            if (data_0217d3f0->mUnk_10 >= 4) {
                data_0217d3f0->mUnk_10 = 0;
                data_0217d3f0->mUnk_14++;
                if (data_0217d3f0->mUnk_14 >= 3) {
                    data_0217d3f0->mUnk_14 = 0;
                }
                func_021270bc();
                func_02016468(10, 0, data_0217d3f0->mUnk_54, 0x1000);
                func_02016468(0x18, 0, &data_0217d3f0->mUnk_1054, 0x1000);
            }
        }
    }
}

void func_02126730(void) {
    if (data_0217d3f0->mUnk_50 != 0) {
        *(vu32 *) 0x4000018 = (data_0217d3f0->mUnk_2054[0] << 16) & 0x1ff0000;
        *(vu32 *) 0x4001010 = (data_0217d3f0->mUnk_2054[1] << 16) & 0x1ff0000;
        if (data_0217d3f0->mUnk_206c[0] != 0) {
            func_0214a390((u16 *) 0x4000050, data_0217d3f0->mUnk_2080[0], 0x1f, data_0217d3f0->mUnk_2088[0],
                          data_0217d3f0->mUnk_2090[0], data_0217d3f0->mUnk_207c);
        } else {
            func_0214a390((u16 *) 0x4000050, 0, 0x1f, data_0217d3f0->mUnk_2088[0], data_0217d3f0->mUnk_2090[0],
                          data_0217d3f0->mUnk_207c);
        }
        if (data_0217d3f0->mUnk_206c[1] != 0) {
            func_0214a390((u16 *) 0x4001050, data_0217d3f0->mUnk_2080[1], 0x1f, data_0217d3f0->mUnk_2088[1],
                          data_0217d3f0->mUnk_2090[1], data_0217d3f0->mUnk_207c);
        } else {
            func_0214a390((u16 *) 0x4001050, 0, 0x1f, data_0217d3f0->mUnk_2088[1], data_0217d3f0->mUnk_2090[1],
                          data_0217d3f0->mUnk_207c);
        }
    }
}

void func_02126700(void) {
    if ((data_0217d3f0->mUnk_00 == 0 && data_0217d3f0->mUnk_34 != 0) || data_0217d3f0->mUnk_00 == 1 ||
        data_0217d3f0->mUnk_00 == 2) {
        data_0217d3f0->mUnk_38 = 1;
    } else {
        data_0217d3f0->mUnk_38 = 0;
    }
    data_0217d3f0->mUnk_34 = 1;
}
#pragma thumb off
