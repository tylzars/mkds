#include "00/code_02188720.h"
#include "00/code_02188ee0.h"
#include "00/code_02188de4.h"
#include "00/code_02188ea0.h"
#include "00/unk_021b4000.h"
#include "00/code_021884d8.h"
#include "00/code_021894e4.h"
#include "00/code_021a8aa8.h"
#include "code_0200f5ac.h"
#include "code_02139f70.h"
#include "code_0214d018.h"

s32 func_ov000_02189280(void) {
    switch (func_ov000_021a5bfc()) {
        case 0:
            return 1;
        case 1:
            func_ov000_021a6428();
            break;
        case 3:
            func_ov000_021a61e4();
            break;
        case 6:
            func_ov000_021a6024();
            break;
        case 9:
            func_ov000_021a5db0();
            break;
        case 12:
            func_ov000_021a5c24();
            break;
        case 11:
            func_ov000_02188508(0);
            return -1;
    }
    return 0;
}

u32 func_ov000_0218925c(void) {
    s32 s;

    s = func_ov000_021a8c8c();
    if (s == 0 || s == -0x27) {
        return 1;
    }
    return 0;
}

u32 func_ov000_0218922c(void) {
    u32 s;
    Unk02188ec0 *v1;

    s = func_ov000_02188528();
    v1 = (Unk02188ec0 *) func_ov000_02188584(0x10);
    switch (s) {
        case 7:
            s = func_ov000_02189134(v1);
            break;
        case 8:
            s = func_ov000_02189030(v1);
            break;
    }
    return s;
}

u32 func_ov000_02189134(Unk02188ec0 *v1) {
    Unk02188ee0 *b;

    b = &v1->mUnk_470[v1->mUnk_d13];
    v1->mUnk_d0d = func_ov000_02188ee0(v1);
    MemFill(&v1->mUnk_cb8, 0, 0x52);
    if (func_ov000_02188de4(v1, v1->mUnk_d0d, &v1->mUnk_cb8) != 0) {
        v1->mUnk_d0b_2 = 1;
        if (((b->mUnk_2c >> 4) & 1) == 0) {
            v1->mUnk_444[v1->mUnk_d13].mUnk_00 = 3;
            return 9;
        }
        if (v1->mUnk_d0d == 6 && b->mUnk_15 == 0) {
            v1->mUnk_444[v1->mUnk_d13].mUnk_00 = 3;
            return 9;
        }
    } else {
        v1->mUnk_d0b_2 = 0;
        if (((b->mUnk_2c >> 4) & 1) == 1) {
            v1->mUnk_444[v1->mUnk_d13].mUnk_00 = 3;
            return 9;
        }
    }
    v1->mUnk_d15 = 0;
    v1->mUnk_d14 = 0;
    return 8;
}

u32 func_ov000_02189030(Unk02188ec0 *v1) {
    Unk02188ee0 *b;
    u32 r;
    u32 s;

    s = func_ov000_021a5bfc();
    b = &v1->mUnk_470[v1->mUnk_d13];
    if (s == 3) {
        r = func_ov000_02188ec0(v1);
        v1->mUnk_d15++;
        if (v1->mUnk_d15 > 3) {
            v1->mUnk_d15 = 0;
            v1->mUnk_444[v1->mUnk_d13].mUnk_00 = 1;
            return 9;
        }
        if (v1->mUnk_d15 != 1) {
            if (v1->mUnk_d14 == 1) {
                v1->mUnk_d0b_2 = 0;
            } else if (v1->mUnk_d14 == 2) {
                v1->mUnk_d15 = 0;
                v1->mUnk_444[v1->mUnk_d13].mUnk_00 = 3;
                return 9;
            } else if (v1->mUnk_d14 == 3) {
                v1->mUnk_d15 = 0;
                v1->mUnk_444[v1->mUnk_d13].mUnk_00 = 4;
                return 9;
            }
        }
        func_ov000_021a5e84((Unk021a5e84 *) b, &v1->mUnk_cb8, r | func_ov000_02188ea0(v1));
    } else if (s == 9) {
        v1->mUnk_d15 = 0;
        v1->mUnk_cb0 = func_0200f5ac();
        return 10;
    }
    return 8;
}

u8 func_ov000_02188ee0(Unk02188ec0 *v1) {
    Unk02188ee0 *b;
    s32 r;
    s32 i;
    s32 n;

    b = &v1->mUnk_470[v1->mUnk_d13];
    r = 0;
    if (v1->mUnk_d0c_6 == 0) {
        n = r;
        if (b->mUnk_0a == 0x20) {
            r = func_ov000_02188c1c((Unk02188408Entry0xc0 *) b);
            if (r > 0) {
                n++;
            } else {
                r = 0;
            }
        } else if (b->mUnk_0a == 8) {
            r = func_ov000_02189714(b);
            if (r != 0) {
                n++;
            } else {
                r = 0;
            }
        }
        for (i = 0; i < v1->mUnk_d10; i++) {
            if (b->mUnk_0a == v1->mUnk_300[i].mUnk_03 &&
                strncmp((const char *) b->mUnk_0c, (const char *) v1->mUnk_300[i].mUnk_04, b->mUnk_0a) == 0) {
                if (n == 0) {
                    r = v1->mUnk_300[i].mUnk_01;
                } else {
                    v1->mUnk_300[i].mUnk_00_hi = 1;
                    v1->mUnk_d0c_6 = 1;
                }
                n++;
            }
        }
    } else {
        i = r;
        n = r;
        for (; i < v1->mUnk_d10; i++) {
            if (v1->mUnk_300[i].mUnk_00_hi == 1) {
                if (n == 0) {
                    v1->mUnk_300[i].mUnk_00_hi = 0;
                    r = v1->mUnk_300[i].mUnk_01;
                }
                n++;
            }
        }
        if (n == 1) {
            v1->mUnk_d0c_6 = 0;
        }
    }
    return r;
}
