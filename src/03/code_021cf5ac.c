#include "03/code_021cf5ac.h"
#include "03/code_021cf260.h"
#include "code_02004d80.h"
#include "Main/Unknown/code_02007624.h"
#include "Main/Unknown/code_02007ea0.h"
#include "Main/Unknown/code_02008000.h"
#include "Main/Unknown/code_02008880.h"
#include "Main/Unknown/code_02007148.h"
#include "Main/Unknown/code_0200a000.h"
#include "Main/Unknown/code_0200c3fc.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_02142eac.h"
#include "Main/Unknown/code_02009adc.h"
#include "Main/Unknown/code_02009cc8.h"
#include "Main/Unknown/code_02007ec4.h"
#include "code_02004270.h"
#include "code_0200fc8c.h"
#include "code_0200fd1c.h"
#include "code_0214d018.h"

void func_ov003_021cf5ac(void) {
    u16 r;
    u16 i;
    s32 v1;
    u16 m;
    u32 t;

    r = 0;
    i = 1;
    for (; i < 16; i++) {
        v1 = 1 << i;
        if ((data_ov003_021da288->mUnk_0a & v1) != 0) {
            if (func_02007d50(i, 3) == 0) {
                m = ~v1;
                t = func_0200fca0();
                data_ov003_021da288->mMask &= m;
                data_ov003_021da288->mUnk_04 &= m;
                data_ov003_021da288->mUnk_06 &= m;
                data_ov003_021da288->mUnk_08 &= m;
                data_ov003_021da288->mUnk_0a &= m;
                data_ov003_021da288->mUnk_0c &= m;
                func_0200fcb4(t);
                func_02009ae8(i);
            } else {
                r |= v1;
            }
        }
    }
    if (r == 0) {
        func_ov003_021cf36c(7);
    } else {
        func_ov003_021cf36c(4);
    }
}

u32 func_ov003_021cf64c(void) {
    u16 i;

    if (data_ov003_021da288->mMask == 0) {
        return 0;
    }
    for (i = 1; i < 16; i++) {
        if ((data_ov003_021da288->mMask & (1 << i)) != 0) {
            if (func_02007df8(i) == 0) {
                return 0;
            }
        }
    }
    return 1;
}

void func_ov003_021cf69c(void) {
    u16 i;
    s32 v1;
    u16 m;
    u32 t;

    func_ov003_021cf36c(3);
    for (i = 1; i < 16; i++) {
        v1 = 1 << i;
        if ((data_ov003_021da288->mMask & v1) != 0) {
            if ((data_ov003_021da288->mUnk_04 & v1) == 0) {
                if ((data_ov003_021da288->mUnk_06 & v1) == 0) {
                    m = ~v1;
                    t = func_0200fca0();
                    data_ov003_021da288->mMask &= m;
                    data_ov003_021da288->mUnk_04 &= m;
                    data_ov003_021da288->mUnk_06 &= m;
                    data_ov003_021da288->mUnk_08 &= m;
                    data_ov003_021da288->mUnk_0a &= m;
                    data_ov003_021da288->mUnk_0c &= m;
                    func_0200fcb4(t);
                    func_02009ae8(i);
                } else {
                    func_ov003_021cf72c(i);
                }
            }
        }
    }
}

void func_ov003_021cf72c(u32 a) {
    u16 m;
    u32 t;
    s32 v1;

    if (func_02007d50(a, 2) == 0) {
        m = ~(1 << a);
        t = func_0200fca0();
        data_ov003_021da288->mMask &= m;
        data_ov003_021da288->mUnk_04 &= m;
        data_ov003_021da288->mUnk_06 &= m;
        data_ov003_021da288->mUnk_08 &= m;
        data_ov003_021da288->mUnk_0a &= m;
        data_ov003_021da288->mUnk_0c &= m;
        func_0200fcb4(t);
        func_02009ae8(a);
    } else {
        t = func_0200fca0();
        v1 = 1 << a;
        data_ov003_021da288->mUnk_06 &= ~v1;
        data_ov003_021da288->mUnk_08 |= v1;
        func_0200fcb4(t);
    }
}

void func_ov003_021cf7b8(u32 a) {
    u16 m;
    u32 t;
    s32 v1;

    if (func_02007d50(a, 0) == 0) {
        m = ~(1 << a);
        t = func_0200fca0();
        data_ov003_021da288->mMask &= m;
        data_ov003_021da288->mUnk_04 &= m;
        data_ov003_021da288->mUnk_06 &= m;
        data_ov003_021da288->mUnk_08 &= m;
        data_ov003_021da288->mUnk_0a &= m;
        data_ov003_021da288->mUnk_0c &= m;
        func_0200fcb4(t);
        func_02009ae8(a);
    } else {
        t = func_0200fca0();
        v1 = 1 << a;
        data_ov003_021da288->mUnk_04 &= ~v1;
        data_ov003_021da288->mMask &= ~v1;
        func_0200fcb4(t);
    }
}

void func_ov003_021cf844(u32 a) {
    u16 m;
    u32 t;

    if (func_02007d50(a, 1) == 0) {
        m = ~(1 << a);
        t = func_0200fca0();
        data_ov003_021da288->mMask &= m;
        data_ov003_021da288->mUnk_04 &= m;
        data_ov003_021da288->mUnk_06 &= m;
        data_ov003_021da288->mUnk_08 &= m;
        data_ov003_021da288->mUnk_0a &= m;
        data_ov003_021da288->mUnk_0c &= m;
        func_0200fcb4(t);
        func_02009ae8(a);
    }
}

u32 func_ov003_021cf8ac(Unk021cf8ac *a) {
    Unk02003024 *q;
    Unk02003024 s;
    u32 r;

    r = 0;
    if (a->mUnk_00 == NULL) {
        q = NULL;
    } else {
        FS_InitFile(&s);
        if (FS_OpenFile(&s, a->mUnk_00) == 0) {
            return r;
        }
        q = &s;
    }
    if (func_02008880(q) != 0) {
        data_ov003_021da288->mUnk_1b144 = (u8 *) data_ov003_021da288 + 0x2c;
        if (data_ov003_021da288->mUnk_1b144 != NULL) {
            if (func_02008570(q, data_ov003_021da288->mUnk_1b144, 0x10000) != 0) {
                if (func_02008310(a, data_ov003_021da288->mUnk_1b144) != 0) {
                    r = 1;
                }
            }
        }
    }
    if (q == &s) {
        FS_CloseFile(&s);
    }
    return r;
}

void func_ov003_021cf93c(Unk021cf8ac *a, u16 b) {
    func_ov003_021cf36c(2);
    if (func_02009cc8(b) != 0) {
        func_ov003_021cf36c(7);
        return;
    }
    if (func_ov003_021cf8ac(a) == 0) {
        func_0200fd1c();
    }
}

void func_ov003_021cf978(u32 a, u32 b) {
    Unk0200fddc s;
    Unk02009ff4 x;
    Unk021cf5ac z;

    func_0200fddc(&s);
    x.mUnk_00 = (x.mUnk_00 & ~0xf) | (s.mUnk_01 & 0xf);
    x.mUnk_01 = s.mUnk_18;
    func_0214d1fc(s.mUnk_04, x.mUnk_02, s.mUnk_18 * 2);
    x.mUnk_00 &= ~0xf0;
    {
        u16 *p = (u16 *) &z;
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p[4] = 0;
        p[5] = 0;
        p[6] = 0;
    }
    *(Unk021cf5ac *) data_ov003_021da288 = z;
    data_ov003_021da288->mUnk_1b140 = data_ov003_021da288->mUnk_10040;
    if (func_02009ff4(data_ov003_021da288->mUnk_1b140, &x, a, b, 2) != 0) {
        func_0200fd1c();
    }
    func_02009f38(0x100, 1);
    func_02007ea0(func_ov003_021cf378);
    func_ov003_021cf36c(1);
}
