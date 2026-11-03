#include "code_0200eddc.h"
#include "code_0214259c.h"
#include "Main/Unknown/code_0200e000.h"
#include "code_0200fd1c.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_02142c24.h"
#include "code_0214d018.h"
#include "Main/Unknown/unk_0217e000.h"

s32 func_02142a8c(void) {
    if (data_0217eed0 != 0) {
        return 0;
    }
    return 3;
}

s32 func_02142a30(void) {
    s32 r;

    r = func_02142a8c();
    if (r != 0) {
        return r;
    }
    func_0200ee3c(data_0217eed4->mUnk_004, 2);
    if (data_0217eed4->mUnk_004->mUnk_000 <= 1) {
        return 3;
    }
    return 0;
}

s32 func_02142988(s32 n, ...) {
    u32 *ap;
    u16 v;
    s32 r;

    r = func_02142a8c();
    if (r != 0) {
        return r;
    }
    func_0200ee3c(data_0217eed4->mUnk_004, 2);
    v = data_0217eed4->mUnk_004->mUnk_000;
    ap = (u32 *) (((u32) &n & ~3) + 4);
    r = 3;
    while (n != 0) {
        ap++;
        if (ap[-1] == v) {
            r = 0;
        }
        n--;
    }
    return r;
}

void func_021425e8(u32 a, Unk021425e8 *m, s32 c) {
    Unk021425e8Func cb;
    u16 t;
    u16 k;
    u16 v7;
    u16 v6;
    u8 *p5;
    u8 *p4;
    u16 i;
    volatile u16 z;

    if (c != 0) {
        return;
    }
    func_0200ee3c(data_0217eed4->mUnk_010, 0x100);
    if (data_0217eed4->mUnk_016 == 0) {
        func_0200ee3c(data_0217eed4->mUnk_004, 0x800);
    }
    if (m != data_0217eed4->mUnk_010) {
        func_0200ee3c(m, 0x100);
    }
    if (m->mUnk_00 >= 0x2a) {
        if (m->mUnk_00 == 0x80) {
            if (m->mUnk_02 == 0x13) {
                func_0200fd1c();
            }
            cb = data_0217eed4->mUnk_0c0;
            if (cb != 0) {
                cb(m);
            }
        } else if (m->mUnk_00 == 0x82) {
            if (data_0217eed4->mUnk_0c4[m->mUnk_06] != 0) {
                m->mUnk_1c = data_0217eed4->mUnk_104[m->mUnk_06];
                func_0200ee3c(m->mUnk_08, data_0217eed4->mUnk_004->mUnk_046);
                data_0217eed4->mUnk_0c4[m->mUnk_06](m);
            }
        } else if (m->mUnk_00 == 0x81) {
            m->mUnk_00 = 0xf;
            cb = m->mUnk_1c;
            if (cb != 0) {
                cb(m);
            }
        }
    } else {
        if (m->mUnk_00 == 0xe) {
            if ((u16) (m->mUnk_04 + 0xfff5) <= 1) {
                if (m->mUnk_02 == 0) {
                    func_0200ee3c(m->mUnk_08, data_0217eed4->mUnk_004->mUnk_046);
                }
            }
        }
        if (m->mUnk_00 == 2 && m->mUnk_02 == 0) {
            cb = data_0217eed4->mUnk_018[m->mUnk_00];
            func_02142c24();
            if (cb == 0) {
                return;
            }
            cb(m);
            return;
        }
        cb = data_0217eed4->mUnk_018[m->mUnk_00];
        if (cb != 0) {
            cb(m);
            if (data_0217eed0 == 0) {
                return;
            }
        }
        t = m->mUnk_00;
        if (t == 8 || t == 0xc) {
            if (t == 8) {
                p5 = (u8 *) m + 0xa;
                p4 = (u8 *) m + 0x14;
                k = *(u16 *) &m->mUnk_08;
                v7 = m->mUnk_10;
                v6 = 0;
            } else if (t == 0xc) {
                v7 = 0;
                k = *(u16 *) &m->mUnk_08;
                v6 = m->mUnk_10;
                p4 = 0;
                p5 = (u8 *) m + 0xa;
            }
            if (k == 7 || k == 9) {
                data_0217ef20.mUnk_00 = 0x82;
                data_0217ef20.mUnk_02 = 0;
                data_0217ef20.mUnk_04 = k;
                data_0217ef20.mUnk_08 = 0;
                data_0217ef20.mUnk_0c = 0;
                data_0217ef20.mUnk_10 = 0;
                data_0217ef20.mUnk_12 = v7;
                data_0217ef20.mUnk_20 = v6;
                data_0217ef20.mUnk_1a = 0xffff;
                func_0214d1fc(p5, data_0217ef20.mUnk_14, 6);
                if (p4 != 0) {
                    func_0214cffc(p4, data_0217ef20.mUnk_24, 0x18);
                } else {
                    z = 0;
                    func_0214cfe4(z, data_0217ef20.mUnk_24, 0x18);
                }
                for (i = 0; i < 16; i++) {
                    data_0217ef20.mUnk_06 = i;
                    if (data_0217eed4->mUnk_0c4[i] != 0) {
                        data_0217ef20.mUnk_1c = data_0217eed4->mUnk_104[i];
                        data_0217eed4->mUnk_0c4[i](&data_0217ef20);
                    }
                }
            }
        }
    }
    func_0200ee3c(data_0217eed4->mUnk_010, 0x100);
    func_021425cc();
    if (m == data_0217eed4->mUnk_010) {
        return;
    }
    m->mUnk_00 |= 0x8000;
    func_0200ee58(m, 0x100);
}

void func_021425cc(void) {
    if ((*(u16 *) 0x27fff96 & 1) != 0) {
        *(u16 *) 0x27fff96 &= ~1;
    }
}

Unk02142988 *func_0214259c(void) {
    if (func_02142a8c() != 0) {
        return 0;
    }
    return data_0217eed4->mUnk_004;
}
