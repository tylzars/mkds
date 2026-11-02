#include "01/code_0218c7a0.h"

#include "01/code_02185ef4.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_0209b000.h"
#include "01/code_02181000.h"
#include "01/code_0218e000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_02068000.h"
#include "Main/Unknown/code_02110000.h"
#include "01/code_0218155c.h"
#include "01/code_0219b250.h"
#include "01/code_0218dce4.h"
#include "01/code_02188484.h"
#include "01/code_02188158.h"
#include "Main/Unknown/code_02148000.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a2300.h"
#include "01/code_02188000.h"
#include "01/code_0218d000.h"
#include "01/code_02188da4.h"
#include "01/code_02187000.h"
#include "01/code_0218d520.h"
#include "01/code_0218ddb4.h"
#include "Main/Unknown/code_02100000.h"
#include "Main/Unknown/code_0210b708.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061f7c.h"
#include "01/code_0218d374.h"

void func_ov001_0218d2c4(Unk02188950 *a) {
    int i;
    Unk0218d87c *list;
    Unk02188950 *p;
    Unk021a7c08 local;

    func_ov001_02187218(a, 8, 0);
    func_ov001_02188d64(a, (s32) (a->mUnk_0a0->mUnk_070), (s32) (a->mUnk_0a0->mUnk_074));
    func_0209b688((void *) (a->mUnk_304), (u16) (0));
    list = func_02100138(0x1fe);
    if (list != 0) {
        for (i = 0; i < list->mUnk_04 && (p = list->mUnk_00[i]) != 0; i++) {
            func_ov001_02187218(p, 1, 0);
            func_ov001_02188d64(p, (s32) (p->mUnk_0a0->mUnk_070), (s32) (p->mUnk_0a0->mUnk_074));
            func_0209b688((void *) (p->mUnk_304), (u16) (0));
        }
    }
    local = data_ov001_021a7c08;
    local.mUnk_04 = &a->mUnk_000.mUnk_04;
    local.mUnk_0c = func_020d4ef4(&a->mUnk_000.mUnk_04);
    func_0210b734(&local, func_02108e7c());
}

void func_ov001_0218d280(void) {
    Unk0218d87c *list;
    Unk02188950 *p;
    int i;

    func_ov001_021882b8();
    list = func_02100138(0x1fe);
    if (list != 0) {
        for (i = 0; i < list->mUnk_04 && (p = list->mUnk_00[i]) != 0; i++) {
            func_ov001_0218dadc(p);
            func_ov001_0218dabc(p);
        }
    }
}

u32 func_ov001_0218d264(Unk02188950 *a) {
    int v1;
    v1 = func_02061fec();
    if (v1 == 1) {
        func_ov001_0218d4c8(a);
    }
    return 0;
}

void func_ov001_0218d23c(int a) {
    func_ov001_02187218((Unk02188950 *) a, 8, (s32(*)(Unk02188950 *))(&func_ov001_0218d264));
    func_ov001_02188d64((Unk02188950 *) a, *(u32 *) (*(s32 *) (a + 0xa0) + 100),
                        *(u32 *) (*(s32 *) (a + 0xa0) + 0x68));
}

void func_ov001_0218d214(Unk02188950 *a) {
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d30(a, (s32) (a->mUnk_0a0->mUnk_058), (s32) (a->mUnk_0a0->mUnk_05c),
                        (UnkFunc *) &func_ov001_0218d23c);
}

void func_ov001_0218d1e0(Unk02188950 *a) {
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(a, (s32) (a->mUnk_0a0->mUnk_04c), (s32) (a->mUnk_0a0->mUnk_050));
    func_ov001_02188e24(a, a->mUnk_0a0->mUnk_054, &func_ov001_0218d214);
}

void func_ov001_0218d1bc(int a) {
    func_ov001_02187218((Unk02188950 *) a, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64((Unk02188950 *) a, *(u32 *) (*(s32 *) (a + 0xa0) + 0x40),
                        *(u32 *) (*(s32 *) (a + 0xa0) + 0x44));
}

void func_ov001_0218d188(Unk02188950 *a) {
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(a, (s32) (a->mUnk_0a0->mUnk_034), (s32) (a->mUnk_0a0->mUnk_038));
    func_ov001_02188e24(a, a->mUnk_0a0->mUnk_03c, &func_ov001_0218d1bc);
}

u32 func_ov001_0218d16c(Unk02188950 *a) {
    int v1;
    v1 = func_02061fec();
    if (v1 == 1) {
        func_ov001_0218d950(a);
    }
    return 0;
}

u32 func_ov001_0218d0fc(Unk02188950 *a) {
    int v1;
    v1 = func_0209b620((s32) (a->mUnk_304));
    if (v1 == 0x33) {
        func_ov001_02187af4(a);
        func_ov001_021875c0(a, (u32) (((u32) 0xfffff666u)), (u32) 0, (u32) (((u32) 0x00000400u)),
                            (u32) (((u32) 0x00000434u)), (u32) 0);
    } else {
        v1 = func_0209b620((s32) (a->mUnk_304));
        if (v1 == 0x66) {
            func_ov001_02187af4(a);
            func_ov001_021875c0(a, (u32) (((u32) 0x0000099au)), (u32) 0, (u32) (((u32) 0x00000400u)),
                                (u32) (((u32) 0x00000434u)), (u32) 0);
        }
    }
    return 0;
}

void func_ov001_0218d0d4(int a) {
    func_ov001_02187218((Unk02188950 *) a, 8, (s32(*)(Unk02188950 *))(&func_ov001_0218d16c));
    func_ov001_02188d64((Unk02188950 *) a, *(u32 *) (*(s32 *) (a + 0xa0) + 100),
                        *(u32 *) (*(s32 *) (a + 0xa0) + 0x68));
}

void func_ov001_0218d0a8(Unk02188950 *a) {
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(&func_ov001_0218d0fc));
    func_ov001_02188d30(a, (s32) (a->mUnk_0a0->mUnk_058), (s32) (a->mUnk_0a0->mUnk_05c),
                        (UnkFunc *) &func_ov001_0218d0d4);
}

void func_ov001_0218d074(Unk02188950 *a) {
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(a, (s32) (a->mUnk_0a0->mUnk_04c), (s32) (a->mUnk_0a0->mUnk_050));
    func_ov001_02188e24(a, a->mUnk_0a0->mUnk_054, &func_ov001_0218d0a8);
}

void func_ov001_0218d050(int a) {
    func_ov001_02187218((Unk02188950 *) a, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64((Unk02188950 *) a, *(u32 *) (*(s32 *) (a + 0xa0) + 0x40),
                        *(u32 *) (*(s32 *) (a + 0xa0) + 0x44));
}

void func_ov001_0218d01c(Unk02188950 *a) {
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(a, (s32) (a->mUnk_0a0->mUnk_034), (s32) (a->mUnk_0a0->mUnk_038));
    func_ov001_02188e24(a, a->mUnk_0a0->mUnk_03c, &func_ov001_0218d050);
}

void func_ov001_0218cfe8(int a) {
    func_ov001_02187218((Unk02188950 *) a, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64((Unk02188950 *) a, *(u32 *) (*(s32 *) (a + 0xa0) + 100),
                        *(u32 *) (*(s32 *) (a + 0xa0) + 0x68));
    func_ov001_02188e24((Unk02188950 *) (a), *(u32 *) (*(s32 *) (a + 0xa0) + 0x54),
                        (UnkFunc *) (&func_ov001_0218d0a8));
}

void func_ov001_0218cf94(Unk0218d87c *a) {
    int i;
    Unk02188950 *p;

    if (a != 0) {
        for (i = 0; i < a->mUnk_04 && (p = a->mUnk_00[i]) != 0; i++) {
            p->mUnk_2c4 = 1;
            if (func_02062ec4() != 0) {
                func_ov001_0218d188(p);
            } else {
                func_ov001_0218d1e0(p);
            }
        }
    }
    func_020a2314((void (*)(void)) func_ov001_0218d280);
}

void func_ov001_0218cedc(u32 a, Unk02188950 *b) {
    int r;

    if (data_021759c0->mUnk_08 == 4) {
        r = func_020a126c();
    } else {
        r = 0;
    }
    if (r != 0) {
        if (func_ov001_021871f8(b, 1) != 0) {
            if (data_021759c0->mUnk_08 == 4) {
                r = func_020a1084((u16) data_021759c0->mUnk_62);
            } else {
                r = 0;
            }
            if (r != 0) {
                func_ov001_0218d374(b);
            } else {
                func_ov001_0218d2c4(b);
            }
        }
    } else {
        if (func_ov001_021871f8(b, 1) != 0) {
            func_ov001_0218d3ec(b);
        }
    }
    if (func_020d2c2c((Vec3 *) &b->mUnk_238, &b->mUnk_000.mUnk_10, b->mUnk_0a0->mUnk_100, b->mUnk_000.mUnk_64, 9, 0) ==
        2) {
        func_020d2774(&b->mUnk_000, (u32) (0x253));
    }
    func_ov001_021864ac(a, b);
}

void func_ov001_0218ce90(Unk0218d87c *a) {
    int i;
    Unk02188950 *p;

    if (a != 0) {
        for (i = 0; i < a->mUnk_04 && (p = a->mUnk_00[i]) != 0; i++) {
            if (func_02062ec4() != 0) {
                func_ov001_0218d01c(p);
            } else if (i == 0) {
                func_ov001_0218d074(p);
            } else {
                func_ov001_0218cfe8((s32) p);
            }
        }
    }
}

void func_ov001_0218ce30(u32 a, int b) {
    int v1;
    func_ov001_0218dc20((Unk02188950 *) (b));
    func_ov001_0218dba8((Unk02188950 *) (b));
    v1 = func_020d2c2c((Vec3 *) ((u32 *) (u32) (b + 0x238)), (Vec3 *) ((u32 *) (u32) (b + 0x10)),
                       *(u32 *) (*(s32 *) (b + 0xa0) + 0x100), *(s16 *) (b + 100), 9,
                       NULL);
    if (v1 == 2) {
        func_020d2774((Unk020e71a0 *) (b), (u32) (((u32) 0x00000253u)));
    }
    func_ov001_021864ac(a, (Unk02188950 *) (b));
}

void func_ov001_0218cdb8(Unk02188950 *e) {
    Unk02188950 *a;
    Unk02188950 *b;
    Unk02188950 *c;
    Unk02188950 *d;

    a = (Unk02188950 *) func_020d34d4(&e->mUnk_000, 0x1fe);
    b = (Unk02188950 *) func_020d34d4(&e->mUnk_000, 0x1fe);
    c = (Unk02188950 *) func_020d34d4(&e->mUnk_000, 0x1fe);
    d = (Unk02188950 *) func_020d34d4(&e->mUnk_000, 0x1fe);
    a->mUnk_0a4 = (struct Unk0218dabc *) e;
    b->mUnk_0a4 = (struct Unk0218dabc *) a;
    c->mUnk_0a4 = (struct Unk0218dabc *) b;
    d->mUnk_0a4 = (struct Unk0218dabc *) c;
    e->mUnk_000.mUnk_94 = func_02036bec((void *) func_020364e0(func_020364e8()), 0x44);
    func_02109110((Unk0210bfbc *) (e->mUnk_000.mUnk_94), (u32) (0xd), (Vec3 *) (&e->mUnk_000.mUnk_04));
    e->mUnk_000.mUnk_70 = data_0217cbec[0x1d];
}

void func_ov001_0218cd80(Unk02188950 *a) {
    a->mUnk_000.mUnk_94 = func_02036bec((void *) func_020364e0(func_020364e8()), 0x44);
    func_02109110((Unk0210bfbc *) (a->mUnk_000.mUnk_94), (u32) (0xd), (Vec3 *) (&a->mUnk_000.mUnk_04));
    a->mUnk_000.mUnk_70 = data_0217cbec[0x1d];
}

void func_ov001_0218cbdc(Unk02188950 *a, Unk02188950_a0 *b) {
    s32 r4;
    s32 diff;

    if (b->mUnk_29c == 1) {
        if (a->mUnk_2d0 > 0) {
            a->mUnk_2d8 = 0xc;
        } else {
            r4 = a->mUnk_1a8;
            diff = (u16) (func_02148714(b->mUnk_080 - a->mUnk_000.mUnk_04.x, b->mUnk_088 - a->mUnk_000.mUnk_04.z) - r4);
            if (diff > 0x8000) {
                diff -= 0x10000;
            }
            if (diff > 0) {
                a->mUnk_000.mUnk_10.x =
                    ((s64) a->mUnk_0a0->mUnk_0fc * data_0215d4b4[(((u16) r4 + 0x4000) >> 4) * 2]) >> 12;
                a->mUnk_000.mUnk_10.y = 0;
                a->mUnk_000.mUnk_10.z =
                    ((s64) a->mUnk_0a0->mUnk_0fc * data_0215d4b4[(((u16) a->mUnk_1a8 + 0x4000) >> 4) * 2 + 1]) >> 12;
            } else {
                a->mUnk_000.mUnk_10.x =
                    ((s64) a->mUnk_0a0->mUnk_0fc * data_0215d4b4[(((u16) r4 - 0x4000) >> 4) * 2]) >> 12;
                a->mUnk_000.mUnk_10.y = 0;
                a->mUnk_000.mUnk_10.z =
                    ((s64) a->mUnk_0a0->mUnk_0fc * data_0215d4b4[(((u16) a->mUnk_1a8 - 0x4000) >> 4) * 2 + 1]) >> 12;
            }
            a->mUnk_2d8 = 0xc;
            func_02073fb0(a->mUnk_000.mUnk_78 & 0x3fffffe0, 0x1000);
            a->mUnk_000.mUnk_78 |= data_ov001_021a65ac;
            func_020d26ec(b, (u32) (0x252));
        }
    } else {
        a->mUnk_2d8 = 0xa;
        func_02073fb0(a->mUnk_000.mUnk_78 & 0x3fffffe0, 0x1000);
        a->mUnk_000.mUnk_78 |= data_ov001_021a65ac;
        func_020d26ec(b, (u32) (0x251));
    }
    func_ov001_02188200(a, func_ov001_0218cbdc);
}

void func_ov001_0218cb14(Unk0218d87c *a) {
    Unk02188950 *obj;
    s32 i;

    if (a != 0) {
        for (i = 0; i < a->mUnk_04 && (obj = a->mUnk_00[i]) != 0; i++) {
            if (data_021759c0->mUnk_08 == 4) {
                func_ov001_02181b8c(obj);
            }
            func_ov001_021870e4(a, obj, data_ov001_021a7d0c, data_ov001_021a7d1c,
                                data_ov001_021a7d2c);
            func_ov001_021870b0(a, obj, data_ov001_021a7d3c);
            func_ov001_0219b2e8(obj->mUnk_304, data_ov001_021a7d4c);
            func_ov001_0218875c(obj, (s32) (obj->mUnk_0a0->mUnk_008), (s32) (obj->mUnk_0a0->mUnk_00c),
                                (s32) (obj->mUnk_0a0->mUnk_00c));
            func_ov001_021888a4(obj, 0x5000, 0xc000);
            func_ov001_02188200(obj, func_ov001_0218cbdc);
            func_ov001_021881f4(obj, (UnkFunc *) func_ov001_0218dd9c);
            obj->mUnk_0a8 = obj->mUnk_0a0->mUnk_12c;
        }
    }
}

void func_ov001_0218c87c(Unk0218d87c *d) {
    void *a;
    void *b;
    void *c;
    Unk02188950 *obj;
    Unk02188950 *src;

    a = func_ov001_0219b4d8(data_ov001_021a7c80);
    b = func_ov001_0219b4d8(data_ov001_021a7c94);
    c = func_ov001_0219b4d8(data_ov001_021a7ca8);
    if (data_021759c0->mUnk_08 == 4) {
        src = func_ov001_02181b68(data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0);
    } else {
        src = 0;
    }

    obj = d->mUnk_00[0];
    obj->mUnk_0a0 = src->mUnk_0a0;
    obj->mUnk_308 = src->mUnk_308;
    if (data_021759c0->mUnk_08 == 4) {
        func_ov001_02181b8c(obj);
    }
    func_ov001_021870e4(d, obj, data_ov001_021a7cbc, 0, 0);
    func_ov001_0219b28c(obj->mUnk_304, a);
    func_ov001_0219b25c(obj->mUnk_304, c);
    obj->mUnk_0a8 = 1;
    func_ov001_0218875c(obj, (s32) (obj->mUnk_0a0->mUnk_0dc), (s32) (obj->mUnk_0a0->mUnk_00c),
                        (s32) (src->mUnk_0a0->mUnk_00c));
    func_ov001_021888a4(obj, 0x5000, 0xc000);
    func_ov001_02188200(obj, func_ov001_0218cbdc);
    func_ov001_021881f4(obj, (UnkFunc *) func_ov001_0218dd9c);

    obj = d->mUnk_00[1];
    obj->mUnk_0a0 = src->mUnk_0a0;
    obj->mUnk_308 = src->mUnk_308;
    if (data_021759c0->mUnk_08 == 4) {
        func_ov001_02181b8c(obj);
    }
    func_ov001_021870e4(d, obj, data_ov001_021a7cd0, 0, 0);
    func_ov001_0219b28c(obj->mUnk_304, b);
    func_ov001_0219b25c(obj->mUnk_304, c);
    obj->mUnk_0a8 = 2;
    func_ov001_0218875c(obj, (s32) (obj->mUnk_0a0->mUnk_0e4), (s32) (obj->mUnk_0a0->mUnk_00c),
                        (s32) (src->mUnk_0a0->mUnk_00c));
    func_ov001_021888a4(obj, 0x5000, 0xd000);
    func_ov001_02188200(obj, func_ov001_0218cbdc);
    func_ov001_021881f4(obj, (UnkFunc *) func_ov001_0218dd9c);

    obj = d->mUnk_00[2];
    obj->mUnk_0a0 = src->mUnk_0a0;
    obj->mUnk_308 = src->mUnk_308;
    if (data_021759c0->mUnk_08 == 4) {
        func_ov001_02181b8c(obj);
    }
    func_ov001_021870e4(d, obj, data_ov001_021a7ce4, 0, 0);
    func_ov001_0219b28c(obj->mUnk_304, a);
    func_ov001_0219b25c(obj->mUnk_304, c);
    obj->mUnk_0a8 = 3;
    func_ov001_0218875c(obj, (s32) (obj->mUnk_0a0->mUnk_0ec), (s32) (obj->mUnk_0a0->mUnk_00c),
                        (s32) (src->mUnk_0a0->mUnk_00c));
    func_ov001_021888a4(obj, 0x5000, 0xc000);
    func_ov001_02188200(obj, func_ov001_0218cbdc);
    func_ov001_021881f4(obj, (UnkFunc *) func_ov001_0218dd9c);

    obj = d->mUnk_00[3];
    obj->mUnk_0a0 = src->mUnk_0a0;
    obj->mUnk_308 = src->mUnk_308;
    if (data_021759c0->mUnk_08 == 4) {
        func_ov001_02181b8c(obj);
    }
    func_ov001_021870e4(d, obj, data_ov001_021a7cf8, 0, 0);
    func_ov001_0219b28c(obj->mUnk_304, b);
    func_ov001_0219b25c(obj->mUnk_304, c);
    obj->mUnk_0a8 = 4;
    func_ov001_0218875c(obj, (s32) (obj->mUnk_0a0->mUnk_0f4), (s32) (obj->mUnk_0a0->mUnk_00c),
                        (s32) (src->mUnk_0a0->mUnk_00c));
    func_ov001_021888a4(obj, 0x5000, 0xd000);
    func_ov001_02188200(obj, func_ov001_0218cbdc);
    func_ov001_021881f4(obj, (UnkFunc *) func_ov001_0218dd9c);
}

void func_ov001_0218c85c(u32 a, u32 b) {
    func_ov001_02186368((void *) a, (Unk02188950 *) b);
    func_ov001_021861f4((void *) a, (Unk02188950 *) b, 0);
}

void func_ov001_0218c830(void) {
    void *v7 = &func_ov001_02185fb0;
    void *v8 = &func_ov001_02185f04;
    void *v9 = &func_ov001_021860cc;
    u32 v11 =
        (u32) func_ov001_0219b510(v7, v8, v9, (u32) 0x2u, (u16) ((u32) 0x1u), (u16) ((u32) 0x0u), (u16) ((u32) 0x0u));
}

void *func_ov001_0218c818(void) {
    return (void *) func_0209bf1c(func_ov001_0218cb14, func_ov001_0218c85c, 0);
}

void *func_ov001_0218c800(void) {
    return (void *) func_0209bf48(func_ov001_0218cf94, func_ov001_0218cedc, 0);
}

void func_ov001_0218c7d4(void) {
    void *v7 = &func_ov001_02185fb0;
    void *v8 = &func_ov001_02185f04;
    void *v9 = &func_ov001_021860cc;
    u32 v11 =
        (u32) func_ov001_0219b510(v7, v8, v9, (u32) 0x2u, (u16) ((u32) 0x1u), (u16) ((u32) 0x0u), (u16) ((u32) 0x0u));
}

void *func_ov001_0218c7b8(void) {
    return (void *) func_0209bf1c(func_ov001_0218c87c, func_ov001_0218c85c, func_ov001_02187098);
}

void *func_ov001_0218c7a0(void) {
    return (void *) func_0209bf48(func_ov001_0218ce90, func_ov001_0218ce30, 0);
}
