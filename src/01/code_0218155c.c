#include "01/code_0218155c.h"

#include "01/code_02188950.h"
#include "01/code_02188e88.h"
#include "01/unk_021a9000.h"
#include "01/code_02181000.h"
#include "03/code_021b94b8.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0203e74c.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a10f0.h"
#include "Main/Unknown/code_020a126c.h"
#include "Main/Unknown/code_020a1748.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b837c.h"
#include "Main/Unknown/code_020c0000.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_02108edc.h"
#include "Main/Unknown/code_0214d000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020e5000.h"
#include "Main/Unknown/code_0210b000.h"
#include "01/code_02182000.h"
#include "01/code_02183000.h"
#include "Main/Unknown/code_0203e000.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_02108000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"

void func_ov001_02181b8c(Unk02188950 *a) {
    u8 n;
    u16 k;

    n = data_021759c0->mKartCount;
    k = data_ov001_021a9b90->mUnk_44 + n;
    data_ov001_021a9b90->mUnk_48[k - n] = a;
    func_020a1728(k);
    data_ov001_021a9b90->mUnk_44++;
}

Unk02188950 *func_ov001_02181b68(int a) {
    return data_ov001_021a9b90->mUnk_48[a - data_021759c0->mKartCount];
}

u8 func_ov001_02181b54(void) {
    return data_021759c0->mKartCount;
}

u16 func_ov001_02181b30(void) {
    return data_ov001_021a9b90->mUnk_44 + data_021759c0->mKartCount - 1;
}

void func_ov001_02181aa0(void) {
    Unk021a9b90 *p;
    u32 n;

    if ((data_021759c0->mUnk_08 == 4 ? func_020a126c() : 0) != 0) {
        return;
    }
    p = data_ov001_021a9b90;
    n = func_ov001_0218180c();
    if (p->mUnk_04 >= n) {
        return;
    }
    p->mUnk_04 = p->mUnk_04 + 1;
    func_02108edc(data_ov001_021a9b90->mUnk_04, func_ov001_0218180c());
    switch (data_021759c0->mUnk_2f) {
        case 0:
        case 1:
        case 3:
        case 5:
        case 7:
            n = func_ov001_0218180c();
            if (data_ov001_021a9b90->mUnk_04 >= n) {
                func_0203e74c(data_021759c0->mUnk_62);
            }
            break;
    }
}

Vec3 *func_ov001_02181a94(void) {
    return &data_ov001_021a9b90->mUnk_28;
}

Vec3 *func_ov001_02181a88(void) {
    return &data_ov001_021a9b90->mUnk_34;
}

u16 func_ov001_02181a78(void) {
    return (u16) ((u32) data_ov001_021a9b90->mUnk_40);
}

u16 func_ov001_02181a68(void) {
    return (u16) ((u32) data_ov001_021a9b90->mUnk_42);
}

void func_ov001_021819f4(void) {
    Unk0206bcb0 *c;
    Unk021a9b90 *o;

    data_ov001_021a9b90 = func_02036bec((void *) func_020364e0(func_020364e8()), 0x68);
    c = func_0207a974((u16) data_021759c0->mUnk_62);
    o = data_ov001_021a9b90;
    o->mUnk_34 = c->mUnk_80;
    o->mUnk_28 = o->mUnk_34;
    o->mUnk_42 = c->mUnk_236;
    o = data_ov001_021a9b90;
    o->mUnk_40 = o->mUnk_42;
}

void func_ov001_02181860(void) {
    Unk0206bcb0 *c;
    Unk021a9b90 *o;

    c = func_0207a974((u16) data_021759c0->mUnk_62);
    if ((c->mUnk_48 & 0x200) == 0) {
        o = data_ov001_021a9b90;
        o->mUnk_34 = o->mUnk_28;
        o->mUnk_42 = o->mUnk_40;
        o = data_ov001_021a9b90;
        o->mUnk_28 = c->mUnk_80;
        o->mUnk_40 = c->mUnk_236;
    }
    if (data_021759c0->mUnk_08 == 4 ? func_020a126c() : 0) {
        if (data_021759c0->mUnk_08 == 4 ? func_020a1084((u16) data_021759c0->mUnk_62) : 0) {
            if (func_020a1154((u16) data_021759c0->mUnk_62)) {
                data_ov001_021a9b90->mUnk_00 += 1;
                if (data_ov001_021a9b90->mUnk_00 > 0xf) {
                    data_ov001_021a9b90->mUnk_00 = 0;
                    func_020a1748((u16) data_021759c0->mUnk_62);
                    return;
                }
            }
        }
        return;
    }
    {
        u32 m = data_021759c0->mUnk_2f;
        if (m == 1 || m == 5) {
            if (func_02061f90() == 0) {
                o = data_ov001_021a9b90;
                if (o->mUnk_0c != 0) {
                    o->mUnk_0c -= 1;
                    o = data_ov001_021a9b90;
                    if (o->mUnk_04 != 0) {
                        o->mUnk_04 -= 1;
                        data_ov001_021a9b90->mUnk_06 += 1;
                    }
                    if (data_ov001_021a9b90->mUnk_20 != NULL) {
                        data_ov001_021a9b90->mUnk_20();
                    }
                    data_ov001_021a9b90->mUnk_0e = 0;
                } else if (o->mUnk_0a != 0) {
                    o->mUnk_0a -= 1;
                    o = data_ov001_021a9b90;
                    if (o->mUnk_04 != 0) {
                        o->mUnk_04 -= 1;
                    }
                    if (data_ov001_021a9b90->mUnk_1c != NULL) {
                        data_ov001_021a9b90->mUnk_1c();
                    }
                    data_ov001_021a9b90->mUnk_0e = 0;
                } else if (o->mUnk_08 != 0) {
                    o->mUnk_08 -= 1;
                    func_ov001_02181aa0();
                    if (data_ov001_021a9b90->mUnk_18 != NULL) {
                        data_ov001_021a9b90->mUnk_18();
                    }
                }
            }
            o = data_ov001_021a9b90;
            if (o->mUnk_0e != 0) {
                o->mUnk_0e -= 1;
                o = data_ov001_021a9b90;
                if (o->mUnk_0e == 0) {
                    if (o->mUnk_24 != NULL) {
                        o->mUnk_24();
                    }
                }
            }
        }
    }
}

void func_ov001_02181844(u16 a, u16 b, u16 c, u16 d) {
    data_ov001_021a9b90->mUnk_10 = a;
    data_ov001_021a9b90->mUnk_12 = b;
    data_ov001_021a9b90->mUnk_14 = c;
    data_ov001_021a9b90->mUnk_16 = d;
}

u32 func_ov001_02181838(void) {
    return ((u32) data_ov001_021a9b90->mUnk_0e);
}

void func_ov001_0218182c(u32 p0) {
    data_ov001_021a9b90->mUnk_0e = (u16) p0;
}

u32 func_ov001_02181820(void) {
    return ((u32) data_ov001_021a9b90->mUnk_04);
}

u32 func_ov001_0218180c(void) {
    u32 v = data_021759c0->mUnk_37;
    if (v == 0) {
        v = 1;
    }
    return v;
}

u32 func_ov001_02181800(void) {
    return ((u32) data_ov001_021a9b90->mUnk_06);
}

void func_ov001_021817e0(void) {
    if (data_021759c0->mUnk_2f == '\a') {
        func_ov001_02181aa0();
    }
}

void func_ov001_0218175c(s32 b) {
    Unk021759c0 *p = data_021759c0;
    u32 m = p->mUnk_2f;
    if (m == 3 || m == 7 || m == 0) {
        u32 a = p->mUnk_3c;
        if (a == 0 && p->mUnk_3e == 0 && p->mUnk_40 == 0 && p->mUnk_42 == 0 && b > 400 && b < 500) {
            func_ov001_02181aa0();
            return;
        }
        if (b == a || b == p->mUnk_3e || b == p->mUnk_40 || b == p->mUnk_42) {
            func_ov001_02181aa0();
        }
    }
}

void func_ov001_0218173c(void) {
    if (data_021759c0->mUnk_08 == 4) {
        func_ov001_02181678((u32) (5));
    }
    return;
}

void func_ov001_0218171c(void) {
    if (data_021759c0->mUnk_2f == 4) {
        func_ov001_02181aa0();
    }
}

void func_ov001_021816fc(void) {
    if (data_021759c0->mUnk_2f == 0) {
        func_ov001_02181aa0();
    }
}

BOOL func_ov001_021816b4(void) {
    Unk021816b4 *list;
    Unk020a2fe4 *e;
    s32 i;

    list = func_02100138(0x6c);
    if (list != NULL) {
        for (i = 0; i < list->mUnk_04 && (e = list->mUnk_00[i]) != NULL; i++) {
            if ((e->mUnk_00.mUnk_02 & 0x100) == 0) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

void func_ov001_021816a8(UnkFunc *p0) {
    data_ov001_021a9b90->mUnk_18 = p0;
}

void func_ov001_0218169c(UnkFunc *p0) {
    data_ov001_021a9b90->mUnk_1c = p0;
}

void func_ov001_02181690(UnkFunc *p0) {
    data_ov001_021a9b90->mUnk_20 = p0;
}

void func_ov001_02181678(u32 a) {
    Unk021a9b90 *p = data_ov001_021a9b90;
    u16 lim = p->mUnk_04;
    if (a >= lim) {
        a = lim;
    }
    p->mUnk_0a += a;
}

void func_ov001_02181660(u16 a) {
    Unk021a9b90 *p = data_ov001_021a9b90;
    u16 lim = p->mUnk_04;
    if (a >= lim) {
        a = lim;
    }
    p->mUnk_0c += a;
}

void func_ov001_02181630(short a) {
    data_ov001_021a9b90->mUnk_06 += a;
    if (data_ov001_021a9b90->mUnk_06 > func_ov001_0218180c()) {
        data_ov001_021a9b90->mUnk_06 = func_ov001_0218180c();
    }
}

void func_ov001_021815d0(s32 p0) {
    s32 i;

    for (i = 0; i < p0; i++) {
        if (++data_ov001_021a9b90->mUnk_08 > func_ov001_0218180c()) {
            data_ov001_021a9b90->mUnk_08 = func_ov001_0218180c();
            return;
        }
        if (data_ov001_021a9b90->mUnk_0e == 0) {
            data_ov001_021a9b90->mUnk_0e = data_ov001_021a9b90->mUnk_10;
        } else {
            data_ov001_021a9b90->mUnk_0e += data_ov001_021a9b90->mUnk_14;
            if (data_ov001_021a9b90->mUnk_0e > data_ov001_021a9b90->mUnk_12) {
                data_ov001_021a9b90->mUnk_0e = data_ov001_021a9b90->mUnk_12;
            }
        }
    }
}

void func_ov001_0218155c(s32 p0) {
    s32 i;

    if ((u32) p0 >= data_ov001_021a9b90->mUnk_06) {
        p0 = data_ov001_021a9b90->mUnk_06;
    }
    for (i = 0; i < p0; i++) {
        data_ov001_021a9b90->mUnk_06--;
        if (++data_ov001_021a9b90->mUnk_08 > func_ov001_0218180c()) {
            data_ov001_021a9b90->mUnk_08 = func_ov001_0218180c();
            return;
        }
        if (data_ov001_021a9b90->mUnk_0e == 0) {
            data_ov001_021a9b90->mUnk_0e = data_ov001_021a9b90->mUnk_10;
        } else {
            data_ov001_021a9b90->mUnk_0e += data_ov001_021a9b90->mUnk_16;
            if (data_ov001_021a9b90->mUnk_0e > data_ov001_021a9b90->mUnk_12) {
                data_ov001_021a9b90->mUnk_0e = data_ov001_021a9b90->mUnk_12;
            }
        }
    }
}
