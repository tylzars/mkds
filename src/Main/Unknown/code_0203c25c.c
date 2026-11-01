#include "Main/Unknown/code_0203c25c.h"
#include "Main/Unknown/code_02044000.h"
#include "Main/Unknown/code_020a12b8.h"
#include "Main/Unknown/code_020b1cdc.h"

s32 func_0203c25c(u16 a) {
    s32 f = 0;
    s32 r;
    switch (data_0217561c->mUnk_000[a].mUnk_14) {
        case 1:
        case 2:
        case 3:
            f = 1;
            break;
    }
    r = f == 0;
    if (r != 0) {
        r = func_02044618() == data_0217561c->mUnk_000[a].mUnk_38;
    }
    return r != 0;
}

// non-matching: same instructions and order; registers differ (a in r5 and the entry pointer in r4 where the original
// has r4 and r5; the stack-free temporaries in r1/r2/r3 are rotated)
void func_0203c2e4(u16 a) {
    Unk0217561c_14 *p = (Unk0217561c_14 *) ((u8 *) &data_0217561c->mUnk_14[0] + a * 0x8c);
    s32 f = 0;
    switch (p->mUnk_00) {
        case 1:
        case 2:
        case 3:
            f = 1;
            break;
    }
    if (f == 0) {
        u16 v;
        u32 o;
        s32 i;
        o = p->mUnk_3c_0;
        v = data_021759c0->mUnk_3d0 - data_0217561c->mUnk_000[0].mUnk_10;
        p->mUnk_3c_0 = v;
        for (i = 0; i < data_021759c0->mUnk_3d0; i++) {
            Unk0217561c_14 *q = (Unk0217561c_14 *) ((u8 *) &data_0217561c->mUnk_14[0] + i * 0x8c);
            if (i != a) {
                u32 m = q->mUnk_3c_0;
                if (m > o && m <= v) {
                    q->mUnk_3c_0--;
                }
            }
        }
        data_0217561c->mUnk_000[0].mUnk_10++;
    }
    if (data_021759c0->mUnk_08 == 2) {
        func_020a16d0(a);
    }
    p->mUnk_00 = 4;
    func_02069044(func_0207a974(a));
    func_020b1cdc(a, 1);
    if (func_0203ef58() != 0) {
        switch (data_021759c0->mUnk_08) {
            case 1:
                break;
            case 2:
                func_020a12b8();
                break;
            case 4:
                func_0203eb38();
                break;
            case 5:
                func_0203ecf0();
                break;
            default:
                func_0203ee28();
                break;
        }
    }
}

// non-matching: same control flow; the data_021759c0 pointer is in ip and the result in r3 where the original has r3
// and ip, and the table address is formed as (r + 1) * 8 plus a - 1 with a register-offset load instead of adding the
// row start and loading at offset 8
u16 func_0203c4d0(u8 a) {
    u16 r = 0;
    Unk0217561c_4dc *t = data_0217561c->mUnk_4dc;
    if (t != 0) {
        switch (data_021759c0->mUnk_08) {
            case 0:
                break;
            case 3:
                r = 1;
                if (data_021759c0->mUnk_58 != 0) {
                    if (data_021759c0->mUnk_3d0 > 3) {
                        if (data_021759c0->mUnk_3d2[0] <= 1 || data_021759c0->mUnk_3d2[1] <= 1) {
                            r = 8;
                        } else {
                            r = 0xf;
                        }
                    } else {
                        r = 8;
                    }
                }
                r = r + 8 - data_021759c0->mUnk_3d0;
                break;
            case 5:
                r = 9 - data_021759c0->mUnk_3d0;
                break;
        }
        r = t[r + 1].mUnk_00[a - 1];
    }
    return r;
}
