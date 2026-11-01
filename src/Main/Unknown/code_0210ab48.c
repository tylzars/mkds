#include "Main/Unknown/code_0210ab48.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0203c5ac.h"
#include "Main/Unknown/code_021053e4.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_0210a67c.h"
#include "Main/Unknown/code_0210bafc.h"
#include "Main/Unknown/code_0210c1b0.h"
#include "Main/Unknown/code_0211057c.h"
#include "Main/Unknown/code_02110590.h"
#include "Main/Unknown/code_0212c6a0.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_020172d0.h"
#include "code_0212c688.h"
#include "code_0212c6ac.h"
#include "code_0212df7c.h"

void func_0210b4e0(Unk0206bcb0 *a, s32 b, s32 c, s32 d) {
    u32 e;

    switch (a->mUnk_490) {
        case 0:
            e = 0xb2;
            break;
        case 1:
            e = 0xb9;
            break;
        case 2:
            e = 0xc0;
            break;
    }
    if (b != 0) {
        func_02109078(&a->mUnk_00, func_0210bb74(1, c, d), 0x5f, -0x345);
    }
    func_02109078(&a->mUnk_00, e, 0x7f, 0);
}

void func_0210b2a8(Unk0206bcb0 *a, s32 b, s32 c, s32 d, u32 e) {
    Unk0206bcb0_A *p;
    s16 f;
    s32 g;
    s32 h;
    s16 w;
    u32 i;
    s32 j;
    s32 k;
    u32 m;
    u32 n;

    if (!(a->mUnk_00.mUnk_34 & 1)) {
        return;
    }
    if (a->mUnk_4c & 0x10000000) {
        return;
    }
    p = &a->mUnk_450;
    f = p->mUnk_08 >> 12;
    if (f > 0x1fc) {
        g = 0x7f;
    } else {
        g = f >> 2;
    }
    if (b == 1) {
        if (e != 0) {
            f = f + 0x1c0;
        } else {
            f = (s16) (f - 0x7d0) >> 2;
        }
    }
    if (e != 0) {
        w = 0;
        h = a->mUnk_74 == data_021759c0->mUnk_62;
        if (e > 0x11170) {
            w = 0x384;
            if (h != 0) {
                w += data_0217ccb4;
            }
        } else if (e > 0x61a8 && e <= 0x11170) {
            w = ((s32) ((((s64) data_0217ccb0 * (s32) ((e - 0x61a8) << 12)) + 0x800) >> 12)) >> 12;
            if (h != 0) {
                w += data_0217ccb4 >> 1;
            }
        }
        func_02109078(&a->mUnk_00, 0x74, g & 0xff, (s16) (f - w));
    } else {
        i = func_0210bb74(b, c, d);
        if (i == 0xffff) {
            return;
        }
        switch (i) {
            case 0xffd0:
            case 0xffd1:
                m = i & 1;
                j = func_0203c5ac(a->mUnk_74);
                k = j - p->mUnk_28;
                if (k < 0) {
                    k = -k;
                }
                if (k > func_02110590(m)) {
                    n = func_0211057c(m);
                    p->mUnk_2c++;
                    func_021090c4(&a->mUnk_00, (u16) ((p->mUnk_2c & 1) + n), 0x7f, 0);
                    p->mUnk_28 = j;
                }
                break;
            default:
                func_02109078(&a->mUnk_00, i, g & 0xff, f);
                break;
        }
    }
}

void func_0210b234(Unk0206bcb0 *a, s32 b, s32 c, s32 d, s32 param_5) {
    u32 e;

    if (!(a->mUnk_00.mUnk_34 & 1)) {
        return;
    }
    e = func_0210bafc(b, c, d);
    if (e == 0xffff) {
        return;
    }
    if (data_021759c0->mUnk_00 == 0x1d) {
        e = 0x1b6;
    }
    func_021090c4(&a->mUnk_00, e, 0x7f, 0);
}

void func_0210b198(s32 a, s32 b, u32 c, s32 d, s32 e) {
    Unk0212c400 *h;
    u16 f;

    if (func_02105504() == 0) {
        return;
    }
    func_0212c6a0(&h);
    f = a * 0xe + b;
    if (h != 0) {
        func_0212c6f0(&h, 0);
    }
    func_0212ec04(&h, d, -1, e, 2, f);
    func_02105b28(&h, c);
    func_0212c688(&h);
}

void func_0210b12c(Unk0206bcb0 *a, s32 b, s16 d) {
    Unk0210bf24 *p;
    s32 c;

    c = b + 0xc1;
    if (data_0217c814.mUnk_00 < 0x78) {
        return;
    }
    p = func_0210c86c(&a->mUnk_00, 0, c, 0x7f, 0);
    if (p == 0) {
        return;
    }
    p->mUnk_19 |= 0x20;
    p->mUnk_19 |= 0x40;
}

void func_0210af40(Unk0206bcb0 *a, s32 b, s32 c) {
    Unk0212c400 *h;
    Unk0206bcb0_A *p;
    u32 d;
    s32 e;
    s32 f;
    u16 g;
    s32 x;
    s32 y;

    d = data_0217c814.mUnk_00;
    if (!(a->mUnk_00.mUnk_34 & 1)) {
        return;
    }
    p = &a->mUnk_450;
    if (a->mUnk_4c & 0x10000000) {
        return;
    }
    if (a->mUnk_7c & 4) {
        return;
    }
    if (data_0217c814.mUnk_0c != 1) {
        if (data_0217c814.mUnk_0c != 0) {
            return;
        }
        e = 0x7f;
        f = a->mUnk_74 == data_021759c0->mUnk_62;
        if (c == 5) {
            e = 0x7f;
        } else if (c == 3) {
            e = 0x7f;
        }
        if (f != 0) {
            if (func_02105504() == 0) {
                return;
            }
            func_0212c6a0(&h);
            g = b * 0xe + c;
            if (h != 0) {
                func_0212c6f0(&h, 0);
            }
            func_0212ec04(&h, 1, -1, 0x7f, 2, g);
            func_02105b28(&h, e);
            func_0212c688(&h);
        } else {
            if (c != 3 && c != 5) {
                return;
            }
            func_0210c86c(&a->mUnk_00, 2, b * 0xe + (c + 1), 0x73, 0);
        }
    } else {
        x = 0xf0;
        y = 0x1e;
        if (c == 1 || c == 2) {
            x = 0x3c;
            y = 0;
        }
        if (d < x) {
            return;
        }
        if (d - p->mUnk_30 < y) {
            return;
        }
        func_0210c86c(&a->mUnk_00, 2, b * 0xe + c, 0x7f, 0);
        p->mUnk_30 = d;
    }
}

void func_0210aefc(void) {
    s32 i;
    Unk0217ccc0 *q = &data_0217ccc0;

    q->mUnk_60 = 0;
    q->mUnk_64 = 0;
    for (i = 0; i < 8; i++) {
        q->mUnk_00[i] = 0;
        q->mUnk_40[i] = 0;
    }
    q->mUnk_68 = 0x5f;
    q->mUnk_6c = -1;
}

void func_0210add4(void) {
    Unk0217ccc0 *q = &data_0217ccc0;
    s32 i;

    if (q->mUnk_64 != 0) {
        return;
    }
    if (q->mUnk_6c != -1) {
        q->mUnk_6c++;
        if (q->mUnk_6c >= 0x19) {
            q->mUnk_6c = -1;
        }
        return;
    }
    for (i = 0; i < 8; i++) {
        if (q->mUnk_00[i] == 0) {
            continue;
        }
        if (q->mUnk_40[i] == 0) {
            if (i != 0 && q->mUnk_40[i - 1] < 0x14) {
                continue;
            }
            if (i != 0 && q->mUnk_40[i - 1] == 0x14) {
                q->mUnk_68 -= 0xf;
            } else {
                q->mUnk_68 = 0x5f;
            }
            if (q->mUnk_68 < 0x1e) {
                q->mUnk_68 = 0x1e;
            }
            func_0210abf4(q->mUnk_00[i], q->mUnk_20[i], 0, q->mUnk_68);
            q->mUnk_40[i]++;
        } else {
            q->mUnk_40[i]++;
        }
    }
}

void func_0210ad58(Unk0206bcb0 *a, s32 b) {
    Unk0217ccc0 *q = &data_0217ccc0;

    if (q->mUnk_64 != 0) {
        return;
    }
    if (a->mUnk_74 == data_021759c0->mUnk_62) {
        func_0210abf4(a, b, 1, 0x6e);
        q->mUnk_6c = 0;
        return;
    }
    q->mUnk_00[q->mUnk_60] = a;
    q->mUnk_20[q->mUnk_60] = b;
    q->mUnk_60++;
}

void func_0210abf4(Unk0206bcb0 *a, s32 b, s32 c, s32 d) {
    Unk0212c400 *h;
    Unk0210bf24 *p;
    Unk0210bf24 *q;
    s32 e;
    u16 f;
    enum { K0 } k;

    p = a->mUnk_00.mUnk_0c.mUnk_00;
    if (p != 0) {
        do {
            if (p->mUnk_18 == 2) {
                q = p;
                p = func_0201733c(&a->mUnk_00.mUnk_0c, p);
                func_0210c450(&a->mUnk_00, q, 0);
            } else {
                p = func_0201733c(&a->mUnk_00.mUnk_0c, p);
            }
        } while (p != 0);
    }
    e = 1;
    if (data_0217d084.mUnk_04 != 2 && data_0217d084.mUnk_04 != 3) {
        e = 0;
    }
    if (e == 0) {
        return;
    }
    k = 0xd;
    if (c != 0) {
        func_0210c86c(&a->mUnk_00, 2, b * 0xe + k, 0x7f, 0);
        return;
    }
    if (func_02105504() == 0) {
        return;
    }
    func_0212c6a0(&h);
    f = b * 0xe + k;
    if (h != 0) {
        func_0212c6f0(&h, 0);
    }
    func_0212ec04(&h, -1, -1, 0x6e, 2, f);
    func_02105b28(&h, d);
    func_0212c688(&h);
}

void func_0210ab48(s32 a, s32 b) {
    Unk0212c400 *h;
    s32 c;
    u16 d;

    c = b != 0 ? 0xc : 0xd;
    data_0217ccc0.mUnk_64 = 1;
    if (func_02105504() == 0) {
        return;
    }
    func_0212c6a0(&h);
    d = a * 0xe + c;
    if (h != 0) {
        func_0212c6f0(&h, 0);
    }
    func_0212ec04(&h, 7, -1, -1, 2, d);
    func_02105b28(&h, 0x6e);
    func_0212c688(&h);
}
