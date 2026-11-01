#include "Main/Unknown/code_02110100.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_02108eb4.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_0212c668.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "01/code_02181274.h"
#include "code_0212c478.h"
#include "code_02147cd8.h"

void func_021103c0(void) {
    data_0217d1fc = func_02147f34(0x7f000, 0x1e000);
    data_0217d224[0] = func_02147f34(0x7f000, 0x1e000);
    data_0217d224[1] = func_02147f34(0x7f000, 0x5a000);
    data_0217d210 = func_02147f34(data_0216cb28 << 12, 0x23000);
    data_0217d214 = func_02147f34(0x7f000, 0x19000);
    data_0217d234.mUnk_00 = data_0217d1fc;
    data_0217d234.mUnk_04 = 0x7f000;
    data_0217d218 = data_0216cb28;
}

void func_02110350(Unk020e71a0_94 *a) {
    s32 v;
    v = (s32) (((s64) data_0217d214 * (0x1f000 - func_ov001_02181528()) + 0x800) >> 12) >> 12;
    if (v < 0) {
        v = 0;
    } else if (v > 0x7f) {
        v = 0x7f;
    }
    func_02109078(&a->mUnk_00, 0x231, (0x7f - v) & 0xff, 0);
}

u32 func_02110324(void) {
    u32 a;
    u32 b;
    a = 0;
    b = data_0217d20c;
    if (b <= 5) {
        if ((1 << b) & 0x25) {
            a = 1;
        }
    }
    return a;
}

// Moves the object at data_0217d234 towards t.
static inline void func_02110114_inline(Unk0212c400 **p, s32 v, s32 k, s32 t) {
    s32 m;
    s32 c;
    s32 r;
    s32 x;
    func_02108eb4(1, v);
    func_0212c524(p, 0xffff, k);
    c = data_0217d234.mUnk_04 >> 12;
    if (t == c) {
        r = -1;
    } else {
        if (c <= t) {
            x = data_0217d234.mUnk_04 + data_0217d234.mUnk_00;
            if ((x >> 12) > t) {
                x = t << 12;
            }
        } else {
            x = data_0217d234.mUnk_04 - data_0217d234.mUnk_00;
            if ((x >> 12) < t) {
                x = t << 12;
            }
        }
        c = x >> 12;
        r = c;
        data_0217d234.mUnk_04 = x;
    }
    data_0217d218 = c;
    m = data_0216cb28;
    if (c <= m) {
        if (c < 0) {
            c = 0;
        }
        m = c;
    }
    data_0217d218 = m;
    if (r != -1) {
        func_0212c678(p, r);
    }
}

void func_02110114(Unk0212c400 **a) {
    s32 b;
    s32 c;
    c = data_0217d20c;
    b = data_0216cb28;
    switch (c) {
        case 0:
            c = (s32) (((s64) data_0217d210 * (0x29000 - func_ov001_02181528()) + 0x800) >> 12) >> 12;
            b = 0;
            if (c >= 0) {
                b = data_0216cb28;
                if (c <= b) {
                    b = c;
                }
            }
            break;
        case 1:
            b = 0;
            break;
        case 2:
            b = 0;
            break;
        case 5:
            if (data_0217d21c == 2) {
                if (data_0217d1e8 < 0x14) {
                    b = 0;
                }
            }
            break;
        case 7:
            break;
    }
    if (data_0217d1f8 != data_0217d20c) {
        data_0217d1e8 = 0;
    } else {
        data_0217d1e8++;
    }
    if (b != data_0216cb28) {
        data_0217d234.mUnk_00 = data_0217d224[0];
    } else {
        data_0217d234.mUnk_00 = data_0217d224[1];
    }
    func_02110114_inline(a, 0x7f, 0, b);
}

u32 func_02110100(Unk0212c400 **a) {
    if (*a != 0) {
        return 1;
    }
    return 0;
}
