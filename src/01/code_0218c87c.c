#include "01/code_0218c87c.h"
#include "01/code_02181b54.h"
#include "01/code_02187098.h"
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
#include "01/code_02181000.h"
#include "01/code_0218e000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_02061000.h"
#include "Main/Unknown/code_02068000.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_02110000.h"

void func_ov001_0218cdb8(Unk02188950 *param_1) {
    Unk02188950 *a;
    Unk02188950 *b;
    Unk02188950 *c;
    Unk02188950 *d;

    a = (Unk02188950 *) func_020d34d4(&param_1->mUnk_000, 0x1fe);
    b = (Unk02188950 *) func_020d34d4(&param_1->mUnk_000, 0x1fe);
    c = (Unk02188950 *) func_020d34d4(&param_1->mUnk_000, 0x1fe);
    d = (Unk02188950 *) func_020d34d4(&param_1->mUnk_000, 0x1fe);
    a->mUnk_0a4 = (struct Unk0218dabc *) param_1;
    b->mUnk_0a4 = (struct Unk0218dabc *) a;
    c->mUnk_0a4 = (struct Unk0218dabc *) b;
    d->mUnk_0a4 = (struct Unk0218dabc *) c;
    param_1->mUnk_000.mUnk_94 = func_02036bec((void *) func_020364e0(func_020364e8()), 0x44);
    func_02109110((Unk0210bfbc *) (param_1->mUnk_000.mUnk_94), (u32) (0xd), (Vec3 *) (&param_1->mUnk_000.mUnk_04));
    param_1->mUnk_000.mUnk_70 = data_0217cbec[0x1d];
}

void func_ov001_0218cd80(Unk02188950 *param_1) {
    param_1->mUnk_000.mUnk_94 = func_02036bec((void *) func_020364e0(func_020364e8()), 0x44);
    func_02109110((Unk0210bfbc *) (param_1->mUnk_000.mUnk_94), (u32) (0xd), (Vec3 *) (&param_1->mUnk_000.mUnk_04));
    param_1->mUnk_000.mUnk_70 = data_0217cbec[0x1d];
}

void func_ov001_0218cbdc(Unk02188950 *param_1, Unk02188950_a0 *param_2) {
    s32 r4;
    s32 diff;

    if (param_2->mUnk_29c == 1) {
        if (param_1->mUnk_2d0 > 0) {
            param_1->mUnk_2d8 = 0xc;
        } else {
            r4 = param_1->mUnk_1a8;
            diff = (u16) (func_02148714(param_2->mUnk_080 - param_1->mUnk_000.mUnk_04.x,
                                        param_2->mUnk_088 - param_1->mUnk_000.mUnk_04.z) -
                          r4);
            if (diff > 0x8000) {
                diff -= 0x10000;
            }
            if (diff > 0) {
                param_1->mUnk_000.mUnk_10.x =
                    ((s64) param_1->mUnk_0a0->mUnk_0fc * data_0215d4b4[(((u16) r4 + 0x4000) >> 4) * 2]) >> 12;
                param_1->mUnk_000.mUnk_10.y = 0;
                param_1->mUnk_000.mUnk_10.z = ((s64) param_1->mUnk_0a0->mUnk_0fc *
                                               data_0215d4b4[(((u16) param_1->mUnk_1a8 + 0x4000) >> 4) * 2 + 1]) >>
                                              12;
            } else {
                param_1->mUnk_000.mUnk_10.x =
                    ((s64) param_1->mUnk_0a0->mUnk_0fc * data_0215d4b4[(((u16) r4 - 0x4000) >> 4) * 2]) >> 12;
                param_1->mUnk_000.mUnk_10.y = 0;
                param_1->mUnk_000.mUnk_10.z = ((s64) param_1->mUnk_0a0->mUnk_0fc *
                                               data_0215d4b4[(((u16) param_1->mUnk_1a8 - 0x4000) >> 4) * 2 + 1]) >>
                                              12;
            }
            param_1->mUnk_2d8 = 0xc;
            func_02073fb0(param_1->mUnk_000.mUnk_78 & 0x3fffffe0, 0x1000);
            param_1->mUnk_000.mUnk_78 |= data_ov001_021a65ac;
            func_020d26ec(param_2, (u32) (0x252));
        }
    } else {
        param_1->mUnk_2d8 = 0xa;
        func_02073fb0(param_1->mUnk_000.mUnk_78 & 0x3fffffe0, 0x1000);
        param_1->mUnk_000.mUnk_78 |= data_ov001_021a65ac;
        func_020d26ec(param_2, (u32) (0x251));
    }
    func_ov001_02188200(param_1, func_ov001_0218cbdc);
}

void func_ov001_0218cb14(Unk0218d87c *param_1) {
    Unk02188950 *obj;
    s32 i;

    if (param_1 != 0) {
        for (i = 0; i < param_1->mUnk_04 && (obj = param_1->mUnk_00[i]) != 0; i++) {
            if (data_021759c0->mUnk_08 == 4) {
                func_ov001_02181b8c(obj);
            }
            func_ov001_021870e4(param_1, obj, (const char *) data_ov001_021a7d0c, (const char *) data_ov001_021a7d1c,
                                (const char *) data_ov001_021a7d2c);
            func_ov001_021870b0(param_1, obj, (const char *) data_ov001_021a7d3c);
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

void func_ov001_0218c87c(Unk0218d87c *param_1) {
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

    obj = param_1->mUnk_00[0];
    obj->mUnk_0a0 = src->mUnk_0a0;
    obj->mUnk_308 = src->mUnk_308;
    if (data_021759c0->mUnk_08 == 4) {
        func_ov001_02181b8c(obj);
    }
    func_ov001_021870e4(param_1, obj, (const char *) data_ov001_021a7cbc, 0, 0);
    func_ov001_0219b28c(obj->mUnk_304, a);
    func_ov001_0219b25c(obj->mUnk_304, c);
    obj->mUnk_0a8 = 1;
    func_ov001_0218875c(obj, (s32) (obj->mUnk_0a0->mUnk_0dc), (s32) (obj->mUnk_0a0->mUnk_00c),
                        (s32) (src->mUnk_0a0->mUnk_00c));
    func_ov001_021888a4(obj, 0x5000, 0xc000);
    func_ov001_02188200(obj, func_ov001_0218cbdc);
    func_ov001_021881f4(obj, (UnkFunc *) func_ov001_0218dd9c);

    obj = param_1->mUnk_00[1];
    obj->mUnk_0a0 = src->mUnk_0a0;
    obj->mUnk_308 = src->mUnk_308;
    if (data_021759c0->mUnk_08 == 4) {
        func_ov001_02181b8c(obj);
    }
    func_ov001_021870e4(param_1, obj, (const char *) data_ov001_021a7cd0, 0, 0);
    func_ov001_0219b28c(obj->mUnk_304, b);
    func_ov001_0219b25c(obj->mUnk_304, c);
    obj->mUnk_0a8 = 2;
    func_ov001_0218875c(obj, (s32) (obj->mUnk_0a0->mUnk_0e4), (s32) (obj->mUnk_0a0->mUnk_00c),
                        (s32) (src->mUnk_0a0->mUnk_00c));
    func_ov001_021888a4(obj, 0x5000, 0xd000);
    func_ov001_02188200(obj, func_ov001_0218cbdc);
    func_ov001_021881f4(obj, (UnkFunc *) func_ov001_0218dd9c);

    obj = param_1->mUnk_00[2];
    obj->mUnk_0a0 = src->mUnk_0a0;
    obj->mUnk_308 = src->mUnk_308;
    if (data_021759c0->mUnk_08 == 4) {
        func_ov001_02181b8c(obj);
    }
    func_ov001_021870e4(param_1, obj, (const char *) data_ov001_021a7ce4, 0, 0);
    func_ov001_0219b28c(obj->mUnk_304, a);
    func_ov001_0219b25c(obj->mUnk_304, c);
    obj->mUnk_0a8 = 3;
    func_ov001_0218875c(obj, (s32) (obj->mUnk_0a0->mUnk_0ec), (s32) (obj->mUnk_0a0->mUnk_00c),
                        (s32) (src->mUnk_0a0->mUnk_00c));
    func_ov001_021888a4(obj, 0x5000, 0xc000);
    func_ov001_02188200(obj, func_ov001_0218cbdc);
    func_ov001_021881f4(obj, (UnkFunc *) func_ov001_0218dd9c);

    obj = param_1->mUnk_00[3];
    obj->mUnk_0a0 = src->mUnk_0a0;
    obj->mUnk_308 = src->mUnk_308;
    if (data_021759c0->mUnk_08 == 4) {
        func_ov001_02181b8c(obj);
    }
    func_ov001_021870e4(param_1, obj, (const char *) data_ov001_021a7cf8, 0, 0);
    func_ov001_0219b28c(obj->mUnk_304, b);
    func_ov001_0219b25c(obj->mUnk_304, c);
    obj->mUnk_0a8 = 4;
    func_ov001_0218875c(obj, (s32) (obj->mUnk_0a0->mUnk_0f4), (s32) (obj->mUnk_0a0->mUnk_00c),
                        (s32) (src->mUnk_0a0->mUnk_00c));
    func_ov001_021888a4(obj, 0x5000, 0xd000);
    func_ov001_02188200(obj, func_ov001_0218cbdc);
    func_ov001_021881f4(obj, (UnkFunc *) func_ov001_0218dd9c);
}
