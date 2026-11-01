#include "Main/Unknown/code_0205821c.h"
#include "Main/Unknown/code_02050000.h"
#include "Main/Unknown/code_02051000.h"
#include "Main/Unknown/code_02052000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_02142eac.h"

#pragma thumb on

static inline u32 func_0205821c_inline(void) {
    if (data_0217aa00 == 0) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

static inline void func_0205821c_inline2(u16 v) {
    Unk0217aa00_1608 *p = &data_0217aa00->mUnk_1608;
    p->mUnk_10 = v;
    p->mUnk_12 = 1;
}

s32 func_020586ac(u8 a, u8 *b, u16 c, u8 d, u8 e) {
    u8 *q;

    if ((data_0217aa00->mUnk_1608.mUnk_1a & 1) == 0) {
        return 0;
    }
    q = data_0217aa00->mUnk_1624;
    q[1] = a;
    *(u16 *) (q + 2) = c;
    q[0] = d;
    if (b != 0) {
        func_0214d1fc(b, q + 4, c);
    } else {
        c = 0;
    }
    func_0200ee58(q, c + 4);
    data_0217aa00->mUnk_1608.mUnk_1a &= ~1;
    if (func_02050650(data_0217aa00->mUnk_1624, c + 4, e, 0, &data_021652a0) == 0) {
        data_0217aa00->mUnk_1608.mUnk_1a |= 1;
        return 0;
    }
    return 1;
}

s32 func_0205867c(u8 *a, s32 b, s32 c, u8 **d, u16 *e) {
    s32 n;

    b = b * c;
    n = 0x22c - b;
    if (n <= 0) {
        return 0;
    }
    if (n > c) {
        n = c;
    }
    *e = n;
    *d = a + b;
    return 1;
}

void func_02058528(void) {
    Unk0217aa00 *p;
    u32 a;
    u8 b;
    u8 c;
    u8 *d;
    u16 v1;
    u16 v;

    if (func_0205821c_inline() == 1) {
        p = data_0217aa00;
        a = p->mUnk_0044.mUnk_42;
        b = p->mUnk_162a;
        if (a == (a & b)) {
            if (func_020586ac(0xfe, 0, (u8) (b | 1), 0, b) != 0) {
                func_0205821c_inline2(9);
            }
        } else {
            if ((data_0217aa00->mUnk_0454 & 0x40) != 0) {
                v = 0x708;
            } else {
                v = 0x258;
            }
            data_0217aa00->mUnk_1608.mUnk_16++;
            if (data_0217aa00->mUnk_1608.mUnk_16 > v) {
                data_0217aa00->mUnk_0044.mUnk_42 = data_0217aa00->mUnk_0044.mUnk_43;
            }
        }
    } else {
        if ((data_0217aa00->mUnk_1608.mUnk_1a & 1) != 0) {
            c = data_0217aa00->mUnk_1628;
            v = data_0217aa00->mUnk_0000 == 2 ? data_0217aa00->mUnk_0432 : 0;
            if (func_0205867c((u8 *) &data_0217aa00->mUnk_045c[v], c, 0x20, &d, &v1) != 0) {
                v = data_0217aa00->mUnk_0000 == 2 ? data_0217aa00->mUnk_0432 : 0;
                func_020586ac(c, d, v1, v, 1);
                data_0217aa00->mUnk_1628 = c + 1;
            } else {
                data_0217aa00->mUnk_1628 = 0;
            }
        }
    }
}

void func_020584f0(void) {
    data_0217aa00->mUnk_0004 = 10;
    data_0217aa00->mUnk_1608.mUnk_16 = 0;
    data_0217aa00->mUnk_162a = 0;
    data_0217aa00->mUnk_1628 = 0;
    data_0217aa00->mUnk_1629 = 0;
}

void func_020583c4(void) {
    u32 f;
    u8 a;
    u8 b;
    u8 *d;
    u16 v1;
    u16 v;

    if (func_0205821c_inline() == 1) {
        if ((data_0217aa00->mUnk_1608.mUnk_1a & 1) != 0) {
            f = 1;
            b = data_0217aa00->mUnk_1629;
            if (((u8) (data_0217aa00->mUnk_0044.mUnk_43 | 1) & (1 << b)) != 0) {
                a = data_0217aa00->mUnk_1628;
                if (func_0205867c((u8 *) &data_0217aa00->mUnk_045c[b], a, 0x168, &d, &v1) != 0) {
                    func_020586ac(a, d, v1, b, data_0217aa00->mUnk_0044.mUnk_43);
                    data_0217aa00->mUnk_1628 = a + 1;
                    f = 0;
                }
            }
            if (f != 0) {
                data_0217aa00->mUnk_1629++;
                data_0217aa00->mUnk_1628 = 0;
                if (data_0217aa00->mUnk_1629 >= 8) {
                    data_0217aa00->mUnk_1629 = 0;
                }
            }
        }
        if ((data_0217aa00->mUnk_0454 & 0x40) != 0) {
            v = 0x708;
        } else {
            v = 0x258;
        }
        data_0217aa00->mUnk_1608.mUnk_16++;
        if (data_0217aa00->mUnk_1608.mUnk_16 > v) {
            data_0217aa00->mUnk_162a = data_0217aa00->mUnk_0044.mUnk_43;
            func_0205821c_inline2(10);
        }
    }
}

void func_02058338(void) {
    u8 i;

    func_0214358c(14, 0, 0);
    data_0217aa00->mUnk_043c = data_0217aa00->mUnk_045c[0].mUnk_228_4;
    if (*(u16 *) 0x027ffc40 == 2) {
        data_021759d0->mUnk_04 = data_0217aa00->mUnk_043c;
    }
    for (i = 1; i < 8; i++) {
        if ((data_0217aa00->mUnk_162a & (1 << i)) == 0) {
            func_0214d168(&data_0217aa00->mUnk_045c[i], 0, 0x22c);
        }
    }
}

void func_020582f4(void) {
    if (data_0217aa00->mUnk_0010 == 0) {
        switch (data_0217aa00->mUnk_000c) {
            case 0xb:
                func_02052da4();
                break;
            case 0x25:
                func_0205821c_inline2(6);
                break;
        }
    }
}

void func_020582d4(void) {
    data_0217aa00->mUnk_164e = 0;
    data_0217aa00->mUnk_164c = 0;
}

void func_0205821c(void) {
    u8 a;
    u8 b;
    u32 c;

    switch (func_0205821c_inline()) {
        case 1:
            a = data_0217aa00->mUnk_164e;
            b = data_0217aa00->mUnk_162a;
            c = b & (1 << a);
            if (c != 0) {
                if (func_020504a4(a, b) != 0) {
                    data_0217aa00->mUnk_164e++;
                }
            } else {
                data_0217aa00->mUnk_164e++;
            }
            if (data_0217aa00->mUnk_164e >= 8) {
                func_0205821c_inline2(6);
            }
            break;
        case 2:
            a = data_0217aa00->mUnk_162a;
            b = data_0217aa00->mUnk_164c;
            if (a == (a & b)) {
                func_0205821c_inline2(6);
            }
            break;
    }
}

#pragma thumb off
