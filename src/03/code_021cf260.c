#include "03/code_021cf260.h"

#include "03/unk_021da000.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"
#include "03/code_021cf5ac.h"
#include "Main/Unknown/code_02007624.h"
#include "code_0200fd1c.h"
#include "03/code_021b94b8.h"
#include "Main/Unknown/code_02009000.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/code_02009adc.h"

void func_ov003_021cf598(void) {
    func_ov003_021cf36c((u16) (6));
    func_02009c04();
    return;
}

void func_ov003_021cf378(u32 a, u32 b, Unk021425e8 *c) {
    Unk021cf260 *s;
    u32 t;
    u16 m;
    u8 *p;

    switch (b) {
        case 2:
            if (func_ov003_021cf360() == 2) {
                s = data_ov003_021da288;
                t = func_0200fca0();
                s->mMask |= 1 << a;
                func_0200fcb4(t);
                p = data_ov003_021da288->mRecords[a - 1].mUnk_16;
                p[0] = c->mUnk_0a[0];
                p[1] = c->mUnk_0a[1];
                p[2] = c->mUnk_0a[2];
                p[3] = c->mUnk_0a[3];
                p[4] = c->mUnk_0a[4];
                p[5] = c->mUnk_0a[5];
                data_ov003_021da288->mRecords[a - 1].mUnk_1c = a;
            }
            break;
        case 3:
            if (func_ov003_021cf284(a) != 6) {
                m = ~(1 << a);
                t = func_0200fca0();
                data_ov003_021da288->mMask &= m;
                data_ov003_021da288->mUnk_04 &= m;
                data_ov003_021da288->mUnk_06 &= m;
                data_ov003_021da288->mUnk_08 &= m;
                data_ov003_021da288->mUnk_0a &= m;
                data_ov003_021da288->mUnk_0c &= m;
                func_0200fcb4(t);
            }
            break;
        case 10:
            if (func_ov003_021cf360() != 2) {
                func_ov003_021cf7b8(a);
                break;
            }
            data_ov003_021da288->mUnk_04 |= 1 << a;
            func_ov003_021cf844(a);
            t = (u32) func_02007e38(a);
            if (t != 0) {
                func_0214d1fc((void *) t, &data_ov003_021da288->mRecords[a - 1], 0x16);
            }
            break;
        case 14:
            data_ov003_021da288->mUnk_04 &= ~(1 << a);
            data_ov003_021da288->mUnk_06 |= 1 << a;
            if (func_ov003_021cf360() == 3) {
                func_ov003_021cf72c(a);
            }
            break;
        case 7:
            data_ov003_021da288->mUnk_08 &= ~(1 << a);
            data_ov003_021da288->mUnk_0a |= 1 << a;
            break;
        case 9:
            data_ov003_021da288->mUnk_0a &= ~(1 << a);
            data_ov003_021da288->mUnk_0c |= 1 << a;
            if (data_ov003_021da288->mMask == data_ov003_021da288->mUnk_0c) {
                func_02009c04();
            }
            break;
        case 12:
            if (func_ov003_021cf360() == 4) {
                func_ov003_021cf36c(5);
            } else {
                func_ov003_021cf36c(0);
            }
            if (data_ov003_021da288->mUnk_1b144 != 0) {
                data_ov003_021da288->mUnk_1b144 = 0;
            }
            if (data_ov003_021da288->mUnk_1b140 != 0) {
                data_ov003_021da288->mUnk_1b140 = 0;
            }
            break;
        case 13:
            switch (c->mUnk_00) {
                case 1:
                case 2:
                case 9:
                    func_ov003_021cf36c(7);
                    break;
                case 8:
                    break;
            }
            break;
        case 1:
        case 4:
        case 5:
        case 6:
        case 8:
        case 11:
            break;
        default:
            func_0200fd1c();
            break;
    }
}

void func_ov003_021cf36c(u16 a) {
    *(u16 *) (*(u32 *) &data_ov003_021da288) = a;
    return;
}

u16 func_ov003_021cf360(void) {
    return *(u16 *) (u32) data_ov003_021da288;
}

u16 func_ov003_021cf32c(u32 a) {
    Unk021cf260 *s;

    s = data_ov003_021da288;
    data_ov003_021da28c[0] = &s->mMask;
    data_ov003_021da28c[1] = &s->mUnk_04;
    data_ov003_021da28c[2] = &s->mUnk_06;
    data_ov003_021da28c[3] = &s->mUnk_08;
    data_ov003_021da28c[4] = &s->mUnk_0a;
    data_ov003_021da28c[5] = &s->mUnk_0c;
    return *data_ov003_021da28c[a];
}

u32 func_ov003_021cf284(u32 a) {
    u32 t;
    u16 b;
    u16 s[7];

    t = func_0200fca0();
    b = 1 << a;
    if ((data_ov003_021da288->mMask & b) == 0) {
        func_0200fcb4(t);
        return 0;
    }
    func_0214d1fc(data_ov003_021da288, s, 0xe);
    func_0200fcb4(t);
    if ((s[2] & b) != 0) {
        return 2;
    }
    if ((s[3] & b) != 0) {
        return 3;
    }
    if ((s[4] & b) != 0) {
        return 4;
    }
    if ((s[5] & b) != 0) {
        return 5;
    }
    if ((s[6] & b) != 0) {
        return 6;
    }
    return 1;
}

void *func_ov003_021cf260(u32 index) {
    Unk021cf260 *state = data_ov003_021da288;
    if ((state->mMask & (1 << index)) != 0) {
        return &state->mRecords[index - 1];
    }
    return 0;
}
