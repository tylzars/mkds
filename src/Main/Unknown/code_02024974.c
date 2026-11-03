#include "Main/Unknown/code_02024974.h"
#include "Main/Unknown/code_02024fc0.h"
#include "Main/Unknown/code_02061f7c.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02086058.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0210c1b0.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_021759c0.h"

s32 func_02024eec(Unk02024eec *a, s32 b, s32 c) {
    s32 d;
    s32 e;
    s32 f;
    s32 g;
    s32 h;

    d = a->mUnk_08;
    e = a->mUnk_0c;
    f = a->mUnk_10;
    if (d == -1) {
        b = 0;
        f = b;
        a->mUnk_0c = b;
    } else {
        g = b & 0x7fff0000;
        if ((d & 0x7fff0000) == g) {
            a->mUnk_0c = b;
            f = 0;
        } else if ((e & 0x7fff0000) != g) {
            a->mUnk_0c = b;
            if (b < d) {
                h = *(s32 *) data_02174e0c;
            } else if (c != 0) {
                h = *(s32 *) data_02174e08;
            } else {
                h = *(s32 *) data_02174e10;
            }
            f = ((s64) h * (b - d) + 0x800) >> 12;
            b = f + d;
        } else if (f != 0) {
            b = f + d;
        }
    }
    if (b > 0x880000) {
        b = 0x880000;
    }
    if (b < 0) {
        b = 0;
    }
    a->mUnk_10 = f;
    return b;
}

void func_02024a88(Unk0206bcb0 *a) {
    Unk02024eec *q;
    s32 f;
    s32 g;
    s32 h;
    s32 i;
    s32 j;
    s32 k;
    s32 l;
    s32 m;

    q = (Unk02024eec *) &a->mUnk_450;
    m = a->mUnk_48;
    f = (m & 2) != 0 ? 1 : 0;
    g = (m & 4) != 0 ? 1 : 0;
    if ((a->mUnk_4c & 0x10000000) != 0) {
        q->mUnk_08 = 0x6c0000;
        q->mUnk_0c = 0x6c0000;
        q->mUnk_10 = 0;
        if (f != 0) {
            q->mUnk_00 = q->mUnk_60;
        } else {
            q->mUnk_00 = q->mUnk_50;
        }
        q->mUnk_14 = f;
        q->mUnk_04 = 0x46;
        func_02109078(&a->mUnk_00, 0xfc, 0x7f, 0);
        return;
    }
    if ((s32) func_02061fb8() < 5) {
        return;
    }
    if (data_0217c814.mUnk_0c == 0) {
        h = a->mUnk_4d4;
        if (h > 0xcd && data_021759c0->mUnk_68[a->mIndex].mUnk_08.mUnk_00 != 1) {
            if (f != 0) {
                if ((a->mUnk_4c & 0x20000000) != 0) {
                    i = 0;
                } else {
                    i = ((s64) h * 0x580000 + 0x800) >> 12;
                }
                g = func_02024eec((Unk02024eec *) &a->mUnk_450, i, 0);
                q->mUnk_04 = 0x7f;
                q->mUnk_00 = q->mUnk_44;
                func_0210ddf4(&data_0217d274, func_02086080(a->mIndex), (void (*)(void *, int)) func_02024fc0, a,
                              (s32) q);
            } else {
                i = ((s64) h * 0x480000 + 0x800) >> 12;
                g = func_02024eec((Unk02024eec *) &a->mUnk_450, i, 0);
                q->mUnk_04 = 0x46;
                q->mUnk_00 = q->mUnk_44;
                func_0210ddf4(&data_0217d274, func_02086080(a->mIndex), (void (*)(void *, int)) func_02024fc0, a,
                              (s32) q);
            }
        } else {
            q->mUnk_0c = 0;
            q->mUnk_10 = 0;
            q->mUnk_04 = 0x3c;
            func_0210ddf4(&data_0217d274, func_02086080(a->mIndex), (void (*)(void *, int)) func_02025030, a, (s32) q);
            g = -1;
        }
        q->mUnk_08 = g;
        q->mUnk_14 = f;
        return;
    }
    j = a->mUnk_2cc->mUnk_10;
    k = a->mUnk_2a4;
    h = k - j;
    l = h > 0 ? 1 : 0;
    if (g != 0 && a->mUnk_2a8 > 0 && (a->mUnk_44 & 0x10) != 0) {
        g = ((s64) q->mUnk_24 * k + 0x800) >> 12;
        if (g > 0x280000) {
            g = 0x280000;
        }
        q->mUnk_04 = data_02153158[(a->mUnk_2a0 >> 8) & 0xff];
        func_0210ddf4(&data_0217d274, func_02086080(a->mIndex), (void (*)(void *, int)) func_02024fe8, a, (s32) q);
    } else if (f != 0 || (g != 0 && a->mUnk_2a8 < 0)) {
        if (l != 0) {
            i = (s32) (((s64) h * q->mUnk_18 + 0x800) >> 12) + 0x580000;
        } else {
            i = ((s64) q->mUnk_1c * k + 0x800) >> 12;
        }
        g = func_02024eec((Unk02024eec *) &a->mUnk_450, i, l);
        q->mUnk_04 = 0x7f;
        if (q->mUnk_14 == 0) {
            q->mUnk_00 = a->mUnk_2a0 < 0x333 ? q->mUnk_64 : q->mUnk_60;
        }
        func_0210ddf4(&data_0217d274, func_02086080(a->mIndex), (void (*)(void *, int)) func_0202506c, a, (s32) q);
    } else {
        if (l != 0) {
            i = (s32) (((s64) h * q->mUnk_18 + 0x800) >> 12) + 0x480000;
        } else {
            i = ((s64) q->mUnk_20 * k + 0x800) >> 12;
        }
        g = func_02024eec((Unk02024eec *) &a->mUnk_450, i, l);
        q->mUnk_04 = 0x32;
        if (a->mUnk_2a0 < 0x19a) {
            q->mUnk_00 = q->mUnk_58;
        } else if (a->mUnk_2a0 < 0x4cd) {
            q->mUnk_00 = q->mUnk_54;
        } else {
            q->mUnk_00 = q->mUnk_50;
        }
        func_0210ddf4(&data_0217d274, func_02086080(a->mIndex), (void (*)(void *, int)) func_0202506c, a, (s32) q);
    }
    q->mUnk_08 = g;
    q->mUnk_14 = f;
}

void func_02024a28(Unk0210bfbc *p, u16 a, s32 b, s32 c) {
    u8 t;
    u8 v;

    if (c == 2) {
        t = (b << 7) >> 12;
        v = t + 0x14;
        if (v > 0x7f) {
            v = 0x7f;
        } else if (v < 0x32) {
            v = 0x32;
        }
    } else {
        v = 0x7f;
    }
    func_0210c86c(p, 0, a, v, 0);
}

void func_020249b8(Unk0206bcb0 *a, s32 b, s32 c) {
    s32 d;
    u8 e;

    if (b <= 0) {
        return;
    }
    if (b >= 0x1000) {
        return;
    }
    d = (b << 14) >> 16;
    e = (b << 7) >> 12;
    if (d > 0x400) {
        d = 0x400;
    }
    if (e > 0x7f) {
        e = 0x7f;
    }
    func_02109078(&a->mUnk_00, c > 0 ? 0x150 : 0x151, e, d);
}

s32 func_02024974(s32 a, s32 b, u32 c, u32 d) {
    s32 r;
    s32 t;

    r = b != 0 ? 4 : 0;
    if (a == 0) {
        if (c == d) {
            t = 0;
        } else if (c == d + 1) {
            t = 1;
        } else {
            t = 2;
        }
        r += t;
    } else {
        r += 3;
    }
    return r + 0x130;
}
