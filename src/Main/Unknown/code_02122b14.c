#include "Main/Unknown/code_02122b14.h"
#include "00/code_0219b000.h"
#include "00/code_0219bb68.h"
#include "00/code_021a2000.h"
#include "00/code_021a2ccc.h"
#include "00/code_021a3000.h"
#include "00/code_021a3264.h"
#include "00/unk_021b5000.h"
#include "00/code_021a31d4.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_02121e84.h"
#include "Main/Unknown/code_02122794.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_0211f6cc.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "01/code_021956dc.h"
#include "code_0200f5ac.h"
#include "code_0214d018.h"

void func_02123a48(u32 a) {
    u8 i;
    u8 c;
    func_0211fe44();
    switch (a) {
        case 0:
            func_0214d168(&data_0217d384->mUnk_1950, 0, 0x60);
            func_0214d168(data_0217d384->mUnk_1e10, 0, 0x110);
            func_0214d168(data_0217d384->mUnk_1d00, 0, 0x110);
            for (i = 0; i < data_0217d384->mUnk_1f53; i++) {
                if (i != func_ov000_0219bb50()) {
                    func_ov000_021a3264(i, &data_0217d384->mUnk_021c[i], 0x244);
                    func_02029930()->mUnk_00[i].mUnk_08 = 3;
                } else {
                    data_0217d384->mUnk_021c[i].mUnk_238 = data_0217aa08->mUnk_00->mUnk_34[4];
                    data_0217d384->mUnk_021c[i].mUnk_23c = data_0217aa08->mUnk_00->mUnk_34[5];
                    func_02029930()->mUnk_00[i].mUnk_08 = 0;
                }
                func_02029930()->mUnk_00[i].mUnk_00 = -1;
                func_02029930()->mUnk_00[i].mUnk_04 = -1;
                func_02029930()->mUnk_d0 = 0;
                data_0217d384->mUnk_1e10[i].mUnk_30 = -1;
                data_0217d384->mUnk_1e10[i].mUnk_34 = -1;
                data_0217d384->mUnk_1e10[i].mUnk_38 = 0;
                data_0217d384->mUnk_1d00[i].mUnk_30 = -1;
                data_0217d384->mUnk_1d00[i].mUnk_34 = -1;
                data_0217d384->mUnk_1d00[i].mUnk_38 = 0;
            }
            data_0217d384->mUnk_1980 = 0;
            data_0217d384->mUnk_19aa = 0;
            data_0217d384->mUnk_19ab = 0;
            func_ov000_021a323c(func_02121f4c);
            c = func_ov000_0219bb50();
            data_0217d384->mUnk_021c[c].mUnk_240 = func_0200f5ac();
            func_02122684();
            data_0217d384->mUnk_1950 = 0;
            func_02029454((u8) data_0217d384->mUnk_1f4e[func_ov000_0219bb50()]);
            func_02029440(data_0217d384->mUnk_1f53);
            break;
        case 1:
            func_02122684();
            data_0217d384->mUnk_1f52 = 0;
            for (i = 0; i < data_0217d384->mUnk_1f53; i++) {
                if ((data_0217d384->mUnk_1f55 & (1 << i)) != 0) {
                    data_0217d384->mUnk_1f52++;
                }
            }
            func_02029454((u8) data_0217d384->mUnk_1f4e[func_ov000_0219bb50()]);
            func_02029440(data_0217d384->mUnk_1f52);
            break;
        case 2:
            for (i = 0; i < data_0217d384->mUnk_1f53; i++) {
                if (i != func_ov000_0219bb50() && (data_0217d384->mUnk_1f55 & (1 << i)) != 0) {
                    func_ov000_021a3264(i, &data_0217d384->mUnk_1d00[i], 0x44);
                }
                func_02029930()->mUnk_d0 = 0;
                data_0217d384->mUnk_1e10[i].mUnk_38 = 0;
                data_0217d384->mUnk_1d00[i].mUnk_38 = 0;
            }
            func_ov000_021a323c(func_02121f4c);
            data_0217d384->mUnk_1950 = 7;
            data_0217d384->mUnk_1980 = 0;
            data_0217d384->mUnk_19aa = 0;
            data_0217d384->mUnk_19ab = 0;
            func_02122684();
            data_0217d384->mUnk_1f52 = 0;
            for (i = 0; i < data_0217d384->mUnk_1f53; i++) {
                if ((data_0217d384->mUnk_1f55 & (1 << i)) != 0) {
                    data_0217d384->mUnk_1f52++;
                }
            }
            func_02029454((u8) data_0217d384->mUnk_1f4e[func_ov000_0219bb50()]);
            func_02029440(data_0217d384->mUnk_1f52);
            break;
        case 3:
            for (i = 0; i < data_0217d384->mUnk_1f53; i++) {
                if (i != func_ov000_0219bb50() && (data_0217d384->mUnk_1f55 & (1 << i)) != 0) {
                    func_ov000_021a3264(i, &data_0217d384->mUnk_1d00[i], 0x44);
                }
                data_0217d384->mUnk_1980 = 0;
                data_0217d384->mUnk_19aa = 0;
                data_0217d384->mUnk_19ab = 0;
                func_02029930()->mUnk_00[i].mUnk_00 = -1;
                func_02029930()->mUnk_00[i].mUnk_04 = -1;
                func_02029930()->mUnk_d0 = 0;
                data_0217d384->mUnk_1e10[i].mUnk_30 = -1;
                data_0217d384->mUnk_1e10[i].mUnk_34 = -1;
                data_0217d384->mUnk_1e10[i].mUnk_38 = 0;
                data_0217d384->mUnk_1e10[i].mUnk_40 = 0;
                data_0217d384->mUnk_1d00[i].mUnk_30 = -1;
                data_0217d384->mUnk_1d00[i].mUnk_34 = -1;
                data_0217d384->mUnk_1d00[i].mUnk_38 = 0;
                data_0217d384->mUnk_1d00[i].mUnk_40 = 0;
            }
            func_ov000_021a323c(func_02121f4c);
            data_0217d384->mUnk_1950 = 3;
            break;
    }
}

s32 func_021236f8(void) {
    u8 a;
    u8 b;
    u8 c;
    s32 v;
    Unk0217d384_1d00 *p;
    Unk021759d4 *r;
    func_02122818();
    func_02122960();
    switch (data_0217d384->mUnk_1950) {
        case 0:
            func_0212357c();
            break;
        case 1:
            func_02123384();
            break;
        case 2:
            func_021225ac(0x1c20);
            if (data_0217aa08->mUnk_28 == 0) {
                r = data_021759d4;
                if (r->mUnk_0c != 0) {
                    v = r->mUnk_10;
                } else {
                    v = 0;
                }
            } else {
                v = 1;
            }
            if (v == 0) {
                data_0217d384->mUnk_1980 = 0;
                data_0217d384->mUnk_1950 = 5;
            }
            break;
        case 3:
            func_0212320c();
            break;
        case 4:
            func_02123098();
            break;
        case 5:
            func_02122f38();
            break;
        case 6:
            func_021225ac(0x1c20);
            a = func_021216a8();
            if (a < data_0217d384->mUnk_1f53) {
                b = func_ov000_0219bb50();
                c = func_ov000_0219bb50();
                p = &data_0217d384->mUnk_1e10[c];
                p->mUnk_00 = 4;
                p->mUnk_04 = 0x44;
                p->mUnk_08 = b;
                p->mUnk_09 = a;
                p->mUnk_0a = data_0217d384->mUnk_1f55;
                func_ov000_021a32a0(a, &data_0217d384->mUnk_1e10[func_ov000_0219bb50()], 0x44);
            }
            if (func_02121580() != 0) {
                data_0217d384->mUnk_19aa = 0;
                data_0217d384->mUnk_19ab = 0;
                func_02122b14();
                data_0217d384->mUnk_1950 = 7;
                data_0217d384->mUnk_1980 = 0;
            }
            break;
        case 7:
            func_021225ac(0x1c20);
            a = func_021216a8();
            if (a < data_0217d384->mUnk_1f53) {
                b = func_ov000_0219bb50();
                c = func_ov000_0219bb50();
                p = &data_0217d384->mUnk_1e10[c];
                p->mUnk_00 = 5;
                p->mUnk_04 = 0x44;
                p->mUnk_08 = b;
                p->mUnk_09 = a;
                p->mUnk_0a = data_0217d384->mUnk_1f55;
                func_ov000_021a32a0(a, &data_0217d384->mUnk_1e10[func_ov000_0219bb50()], 0x44);
            }
            if (func_02121580() != 0) {
                c = func_ov000_0219bb50();
                if (data_0217d384->mUnk_1e10[c].mUnk_38 != 0) {
                    data_0217d384->mUnk_19aa = 0;
                    data_0217d384->mUnk_19ab = 0;
                    data_0217d384->mUnk_1950 = 8;
                    data_0217d384->mUnk_1980 = 0;
                }
            }
            break;
        case 8:
            func_02122d74();
            break;
        case 9:
            func_02122bf0();
            break;
        case 11:
            func_021225ac(0x1c20);
            if (func_ov000_0219bb68() <= 1) {
                data_0217d384->mUnk_1980 = 0;
                data_0217d384->mUnk_1950 = 12;
            }
            break;
        case 12:
            break;
    }
    return 0;
}

void func_0212357c(void) {
    u8 a;
    u8 b;
    u8 c;
    u32 m;
    Unk0217d384_021c *q;
    Unk02123384 t;
    func_021225ac(0x1c20);
    a = func_021216a8();
    if (a < data_0217d384->mUnk_1f53) {
        m = 1 << a;
        if ((data_0217d384->mUnk_19aa & m) != 0) {
            b = func_ov000_0219bb50();
            c = func_ov000_0219bb50();
            q = &data_0217d384->mUnk_021c[c];
            q->mUnk_000 = 1;
            q->mUnk_004 = 0x244;
            q->mUnk_008 = b;
            q->mUnk_009 = a;
            q->mUnk_00a = data_0217d384->mUnk_1f55;
            c = func_ov000_0219bb50();
            func_ov000_021a32a0(a, &data_0217d384->mUnk_021c[c], 0x244);
            data_0217d384->mUnk_19aa &= ~m;
        } else if ((data_0217d384->mUnk_19ab & m) == 0) {
            t.mUnk_08 = func_ov000_0219bb50();
            t.mUnk_04 = 0xc;
            t.mUnk_09 = a;
            t.mUnk_00 = 0;
            t.mUnk_0a = data_0217d384->mUnk_1f55;
            func_ov000_021a32a0(a, &t, 0xc);
        }
    }
    if (func_02121580() == 0) {
        return;
    }
    data_0217d384->mUnk_19aa = 0;
    data_0217d384->mUnk_19ab = 0;
    data_0217d384->mUnk_1980 = 0;
    data_0217d384->mUnk_1950 = 1;
}

void func_02123384(void) {
    u8 a;
    u8 b;
    u8 c;
    u8 i;
    u32 m;
    u32 n;
    Unk0217d384 *p;
    Unk0217d384_021c *q;
    Unk0217d384_1954 *r;
    Unk02123384 t;
    func_021225ac(0x1c20);
    a = func_021216a8();
    if (a < data_0217d384->mUnk_1f53) {
        m = 1 << a;
        if ((data_0217d384->mUnk_19aa & m) != 0) {
            b = func_ov000_0219bb50();
            c = func_ov000_0219bb50();
            q = &data_0217d384->mUnk_021c[c];
            q->mUnk_000 = 1;
            q->mUnk_004 = 0x244;
            q->mUnk_008 = b;
            q->mUnk_009 = a;
            q->mUnk_00a = data_0217d384->mUnk_1f55;
            c = func_ov000_0219bb50();
            func_ov000_021a32a0(a, &data_0217d384->mUnk_021c[c], 0x244);
            data_0217d384->mUnk_19aa &= ~m;
        } else {
            t.mUnk_08 = func_ov000_0219bb50();
            t.mUnk_04 = 0xc;
            t.mUnk_09 = a;
            t.mUnk_00 = 2;
            t.mUnk_0a = data_0217d384->mUnk_1f55;
            func_ov000_021a32a0(a, &t, 0xc);
        }
    }
    if (func_02121580() == 0) {
        return;
    }
    p = data_0217d384;
    n = 0;
    for (i = 0; i < p->mUnk_1f53; i++) {
        n += p->mUnk_021c[i].mUnk_240;
    }
    r = &p->mUnk_1954;
    r->mValue = n;
    r->mMultiplier = 0x5d588b656c078965;
    r->mIncrement = 0x269ec3;
    func_0205e5c4(0);
    data_0217d384->mUnk_19aa = 0;
    data_0217d384->mUnk_19ab = 0;
    data_0217d384->mUnk_1980 = 0;
    data_0217d384->mUnk_1950 = 2;
}

void func_0212320c(void) {
    u8 a;
    u8 b;
    u8 c;
    Unk0217d384_1d00 *p;
    func_021225ac(0x1c20);
    c = func_ov000_0219bb50();
    if (data_0217d384->mUnk_1e10[c].mUnk_40 == 2) {
        func_ov000_021a2ccc();
        func_ov000_0219bbfc();
        data_0217d384->mUnk_1950 = 11;
        return;
    }
    a = func_021216a8();
    if (a < data_0217d384->mUnk_1f53) {
        b = func_ov000_0219bb50();
        c = func_ov000_0219bb50();
        p = &data_0217d384->mUnk_1e10[c];
        p->mUnk_00 = 8;
        p->mUnk_04 = 0x44;
        p->mUnk_08 = b;
        p->mUnk_09 = a;
        p->mUnk_0a = data_0217d384->mUnk_1f55;
        func_ov000_021a32a0(a, &data_0217d384->mUnk_1e10[func_ov000_0219bb50()], 0x44);
    }
    if (func_02121580() == 0) {
        return;
    }
    c = func_ov000_0219bb50();
    if (data_0217d384->mUnk_1e10[c].mUnk_40 == 0) {
        return;
    }
    data_0217d384->mUnk_19aa = 0;
    data_0217d384->mUnk_19ab = 0;
    data_0217d384->mUnk_1950 = 4;
    data_0217d384->mUnk_1980 = 0;
}

void func_02123098(void) {
    u8 a;
    u8 b;
    u8 c;
    Unk0217d384_1d00 *p;
    Unk0217d384_08 *q;
    func_021225ac(0x1c20);
    a = func_021216a8();
    if (a < data_0217d384->mUnk_1f53) {
        b = func_ov000_0219bb50();
        c = func_ov000_0219bb50();
        p = &data_0217d384->mUnk_1e10[c];
        p->mUnk_00 = 9;
        p->mUnk_04 = 0x44;
        p->mUnk_08 = b;
        p->mUnk_09 = a;
        p->mUnk_0a = data_0217d384->mUnk_1f55;
        func_ov000_021a32a0(a, &data_0217d384->mUnk_1e10[func_ov000_0219bb50()], 0x44);
    }
    if (func_02121580() == 0) {
        return;
    }
    if (data_0217d384->mUnk_1f52 == 1) {
        func_ov000_021a2ccc();
        func_ov000_0219bbfc();
        q = &data_0217d384->mUnk_0008;
        q->mUnk_10 = 2;
        q->mUnk_12 = 1;
        return;
    }
    data_0217d384->mUnk_19aa = 0;
    data_0217d384->mUnk_19ab = 0;
    data_0217d384->mUnk_1950 = 5;
    data_0217d384->mUnk_1980 = 0;
    c = func_ov000_0219bb50();
    func_02029454((u8) data_0217d384->mUnk_1f4e[c]);
    func_02029440(data_0217d384->mUnk_1f52);
}

void func_02122f38(void) {
    u8 a;
    u8 b;
    u8 c;
    Unk0217d384_1d00 *p;
    func_021225ac(0x1c20);
    a = func_021216a8();
    if (a < data_0217d384->mUnk_1f53) {
        b = func_ov000_0219bb50();
        c = func_ov000_0219bb50();
        p = &data_0217d384->mUnk_1e10[c];
        p->mUnk_00 = 3;
        p->mUnk_04 = 0x44;
        p->mUnk_08 = b;
        p->mUnk_09 = a;
        p->mUnk_0a = data_0217d384->mUnk_1f55;
        func_ov000_021a32a0(a, &data_0217d384->mUnk_1e10[func_ov000_0219bb50()], 0x44);
    }
    if (func_02121580() == 0) {
        return;
    }
    c = func_ov000_0219bb50();
    if (data_0217d384->mUnk_1e10[c].mUnk_30 == -1) {
        return;
    }
    c = func_ov000_0219bb50();
    if (data_0217d384->mUnk_1e10[c].mUnk_34 == -1) {
        return;
    }
    data_0217d384->mUnk_19aa = 0;
    data_0217d384->mUnk_19ab = 0;
    data_0217d384->mUnk_1950 = 6;
    data_0217d384->mUnk_1980 = 0;
}

void func_02122d74(void) {
    u8 a;
    u8 b;
    u8 c;
    u8 i;
    Unk0217d384_1d00 *p;
    func_021225ac(0x1c20);
    a = func_021216a8();
    if (a < data_0217d384->mUnk_1f53) {
        b = func_ov000_0219bb50();
        c = func_ov000_0219bb50();
        p = &data_0217d384->mUnk_1e10[c];
        p->mUnk_00 = 6;
        p->mUnk_04 = 0x44;
        p->mUnk_08 = b;
        p->mUnk_09 = a;
        p->mUnk_0a = data_0217d384->mUnk_1f55;
        func_ov000_021a32a0(a, &data_0217d384->mUnk_1e10[func_ov000_0219bb50()], 0x44);
    }
    if (func_02121580() == 0) {
        return;
    }
    data_0217d384->mUnk_19aa = 0;
    data_0217d384->mUnk_19ab = 0;
    func_02122b14();
    func_02121af4();
    for (i = 0; i < data_0217d384->mUnk_1f53; i++) {
        c = func_ov000_0219bb50();
        data_0217d384->mUnk_1e10[c].mUnk_1c[i] = data_0217d384->mUnk_1e10[i].mUnk_34;
        c = func_ov000_0219bb50();
        data_0217d384->mUnk_1e10[c].mUnk_0c[i] = data_0217d384->mUnk_1e10[i].mUnk_30;
    }
    c = func_ov000_0219bb50();
    data_0217d384->mUnk_1e10[c].mUnk_2c = func_02029930()->mUnk_d0;
    data_0217d384->mUnk_1950 = 9;
    data_0217d384->mUnk_1980 = 0;
}

void func_02122bf0(void) {
    u8 a;
    u8 b;
    u8 c;
    u8 i;
    Unk0217d384_1d00 *p;
    a = func_021216a8();
    if (a < data_0217d384->mUnk_1f53) {
        b = func_ov000_0219bb50();
        c = func_ov000_0219bb50();
        p = &data_0217d384->mUnk_1e10[c];
        p->mUnk_00 = 7;
        p->mUnk_04 = 0x44;
        p->mUnk_08 = b;
        p->mUnk_09 = a;
        p->mUnk_0a = data_0217d384->mUnk_1f55;
        func_ov000_021a32a0(a, &data_0217d384->mUnk_1e10[func_ov000_0219bb50()], 0x44);
    }
    if (func_021225ac(0x78) == 0) {
        return;
    }
    for (i = 0; i < data_0217d384->mUnk_1f53; i++) {
        if (i != func_ov000_0219bb50() && (data_0217d384->mUnk_1f55 & (1 << i)) != 0) {
            if (func_ov000_021a3264(i, data_0217d384->mUnk_001c[i], 0x80) == 0) {
                return;
            }
        }
    }
    data_0217d384->mUnk_19aa = 0;
    data_0217d384->mUnk_19ab = 0;
    data_0217d384->mUnk_1950 = 10;
    data_0217d384->mUnk_1980 = 0;
}

void func_02122b14(void) {
    u8 i;
    u8 m = 0xff;
    if (data_0217d384->mUnk_1950 < 5) {
        return;
    }
    if (data_0217d384->mUnk_1950 >= 9) {
        return;
    }
    for (i = 0; i < data_0217d384->mUnk_1f53; i++) {
        if ((data_0217d384->mUnk_1f55 & (1 << i)) != 0) {
            m &= data_0217d384->mUnk_1e10[i].mUnk_0a;
        }
    }
    for (i = 0; i < data_0217d384->mUnk_1f53; i++) {
        if ((data_0217d384->mUnk_1f55 & (1 << i)) != 0) {
            if ((m & (1 << i)) == 0) {
                data_0217d384->mUnk_1f56 |= 1 << i;
            }
        }
    }
}
