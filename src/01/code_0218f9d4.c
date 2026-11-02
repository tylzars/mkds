#include "01/code_0218f9d4.h"

#include "01/code_02185ef4.h"
#include "01/code_0218f000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "01/code_0218155c.h"
#include "01/code_02188158.h"
#include "01/code_02188218.h"
#include "01/code_0219b250.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_02148000.h"
#include "Main/Unknown/code_020a2300.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b502c.h"
#include "01/code_02190000.h"
#include "01/code_02191000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_020a128c.h"
#include "01/code_02192000.h"
#include "01/code_02187000.h"
#include "01/code_02188000.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "01/code_02188e88.h"
#include "01/code_021882b8.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/code_0210b708.h"
#include "01/code_02187e78.h"
#include "01/code_02188cd8.h"
#include "01/code_02188da4.h"
#include "01/code_02188de0.h"
#include "01/code_02188e24.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/code_020d2000.h"
#include "01/code_02193000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_0212a000.h"
#include "Main/Unknown/code_0214a000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061f7c.h"

void func_ov001_02192890(Unk02188950 *param_1) {
    param_1->mUnk_000.mUnk_94 = func_02036bec((void *) func_020364e0(func_020364e8()), 0x44);
    func_02109110((Unk0210bfbc *) (param_1->mUnk_000.mUnk_94), (u32) (0xc), (Vec3 *) (&param_1->mUnk_000.mUnk_04));
    param_1->mUnk_000.mUnk_70 = data_0217cbec[0x14];
}

void func_ov001_02192878(Unk02188950 *param_1) {
    param_1->mUnk_2d8 = 2;
    func_ov001_02188200(param_1, func_ov001_02192878);
}

void func_ov001_021927c0(Unk02188950 *param_1) {
    if (param_1->mUnk_2d0 > 0) {
        param_1->mUnk_2d8 = 2;
        func_ov001_02188200(param_1, func_ov001_021927c0);
        return;
    }
    param_1->mUnk_000.mUnk_10.x =
        ((s64) param_1->mUnk_0a0->mUnk_144 * data_0215d4b4[(u16) param_1->mUnk_1a8 >> 4 << 1]) >> 12;
    param_1->mUnk_000.mUnk_10.y = 0;
    param_1->mUnk_000.mUnk_10.z =
        ((s64) param_1->mUnk_0a0->mUnk_144 * data_0215d4b4[((u16) param_1->mUnk_1a8 >> 4 << 1) + 1]) >> 12;
    param_1->mUnk_2d8 = 0xd;
    func_ov001_02188200(param_1, func_ov001_021927c0);
    func_02073fb0(param_1->mUnk_000.mUnk_78 & 0x3fffffe0, 0x1000);
}

void func_ov001_02192794(int param_1) {
    *(u32 *) (param_1 + 0x2d8) = 0xb;
    func_ov001_02188200((Unk02188950 *) (param_1), func_ov001_02192878);
    *(u32 *) (param_1 + 0x78) = *(u32 *) (param_1 + 0x78) | (*(u32 *) &data_ov001_021a65d4);
}

void func_ov001_02192694(void) {
    Vec3 pos;
    Unk02188950 *obj;
    Unk02188950_a0 *a0;
    Unk0206bcb0 *other;
    int idx;
    u16 ang;

    if (data_021759c0->mUnk_08 == 4) {
        obj = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 2));
    } else {
        obj = 0;
    }
    other = func_0207a974((u16) data_021759c0->mUnk_62);
    if (obj->mUnk_0a8 == 4) {
        a0 = obj->mUnk_0a0;
        ang = func_02148714(other->mUnk_80.z - obj->mUnk_000.mUnk_04.z, other->mUnk_80.x - obj->mUnk_000.mUnk_04.x) -
              a0->mUnk_26c;
    } else {
        a0 = obj->mUnk_0a0;
        ang = a0->mUnk_26c +
              func_02148714(other->mUnk_80.z - obj->mUnk_000.mUnk_04.z, other->mUnk_80.x - obj->mUnk_000.mUnk_04.x);
    }
    idx = (ang >> 4) * 2;
    pos.x = obj->mUnk_000.mUnk_04.x + (s32) (((s64) a0->mUnk_270 * data_0215d4b4[idx + 1]) >> 12);
    pos.y = obj->mUnk_000.mUnk_04.y;
    pos.z = obj->mUnk_000.mUnk_04.z + (s32) (((s64) obj->mUnk_0a0->mUnk_270 * data_0215d4b4[idx]) >> 12);
    func_ov001_02188998(obj, &pos);
}

void func_ov001_021924cc(void) {
    Vec3 b;
    Vec3 c;
    Vec3 a;
    Unk02188950 *objB;
    Unk02188950 *obj;
    Unk02188950 *objC;

    if (data_021759c0->mUnk_08 == 4) {
        objB = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 2));
    } else {
        objB = 0;
    }
    if (data_021759c0->mUnk_08 == 4) {
        obj = func_ov001_02181b68((u16) (data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0));
    } else {
        obj = 0;
    }
    if (data_021759c0->mUnk_08 == 4) {
        objC = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        objC = 0;
    }
    a.x = (s32) (((s64) objB->mUnk_0a0->mUnk_274 * data_0215d4b4[((u16) objB->mUnk_184 >> 4) * 2]) >> 12);
    a.y = objB->mUnk_000.mUnk_04.y;
    a.z = (s32) (((s64) objB->mUnk_0a0->mUnk_274 * data_0215d4b4[((u16) objB->mUnk_184 >> 4) * 2 + 1]) >> 12);
    b.x = -(s32) (((s64) objB->mUnk_0a0->mUnk_278 * data_0215d4b4[((u16) objB->mUnk_184 >> 4) * 2 + 1]) >> 12);
    b.y = objB->mUnk_000.mUnk_04.y;
    b.z = (s32) (((s64) objB->mUnk_0a0->mUnk_278 * data_0215d4b4[((u16) objB->mUnk_184 >> 4) * 2]) >> 12);
    c.x = (s32) (((s64) objB->mUnk_0a0->mUnk_278 * data_0215d4b4[((u16) objB->mUnk_184 >> 4) * 2 + 1]) >> 12);
    c.y = objB->mUnk_000.mUnk_04.y;
    c.z = -(s32) (((s64) objB->mUnk_0a0->mUnk_278 * data_0215d4b4[((u16) objB->mUnk_184 >> 4) * 2]) >> 12);
    func_ov001_02188968(obj, &a);
    func_ov001_02188968(objC, &a);
    func_ov001_02188980(obj, &b);
    func_ov001_02188980(objC, &c);
}

void func_ov001_0219246c(Unk02188950 *param_1) {
    param_1->mUnk_0a8 = 0;
    func_ov001_021881f4(param_1, (UnkFunc *) &func_ov001_0218fee0);
    func_ov001_021884f0(param_1, 0, 0, 0, (u32) (0), (u32) (0), (u32) (0));
    func_ov001_02188644(param_1, (int) (((u32) 0x0002a000u)), (u32) (0), (u32) (((u32) 0x00007000u)),
                        (u32) (((u32) 0x00026000u)), (u32) (((u32) 0x00001000u)), (u32) (((u32) 0x00022000u)));
    return;
}

void func_ov001_021923e0(Unk02188950 *param_1) {
    param_1->mUnk_0a8 = 1;
    func_ov001_021881f4(param_1, (UnkFunc *) &func_ov001_0218fd20);
    func_ov001_02188484(param_1, (int) (((u32) 0xffffc000u)), (u32) (((u32) 0x0001e000u)), (u32) (((u32) 0xffff5000u)),
                        (u32) (((u32) 0x00002000u)), (u32) (((u32) 0x00024000u)), (u32) (((u32) 0x00028000u)),
                        (u32) (((u32) 0x00011000u)), (u32) (((u32) 0x00002000u)));
    func_ov001_021885d4(param_1, (int) (((u32) 0xffff8000u)), (u32) (0), (u32) (((u32) 0xffffa000u)),
                        (u32) (((u32) 0x00002000u)), (u32) (((u32) 0x00020000u)), (u32) (((u32) 0x00001000u)),
                        (u32) (((u32) 0x00014000u)), (u32) (((u32) 0x00002000u)));
    return;
}

void func_ov001_02192358(Unk02188950 *param_1) {
    param_1->mUnk_0a8 = 1;
    func_ov001_021881f4(param_1, (UnkFunc *) &func_ov001_0218fd20);
    func_ov001_02188484(param_1, (int) (((u32) 0xffffc000u)), (u32) (((u32) 0x00028000u)), (u32) (((u32) 0xffff5000u)),
                        (u32) (((u32) 0x00001000u)), (u32) (((u32) 0x00024000u)), (u32) (((u32) 0x00028000u)),
                        (u32) (((u32) 0x00011000u)), (u32) (((u32) 0x00001000u)));
    func_ov001_021885d4(param_1, (int) (((u32) 0xffff8000u)), (u32) (0), (u32) (((u32) 0xffffa000u)),
                        (u32) (((u32) 0x00000800u)), (u32) (((u32) 0x00020000u)), (u32) (((u32) 0x00001000u)),
                        (u32) (((u32) 0x00014000u)), (u32) (((u32) 0x00001000u)));
    return;
}

void func_ov001_021922e0(Unk02188950 *param_1) {
    param_1->mUnk_0a8 = 2;
    func_ov001_021881f4(param_1, (UnkFunc *) &func_ov001_0218fee0);
    func_ov001_02188484(param_1, (int) (((u32) 0x00015000u)), (u32) (((u32) 0x00028000u)), (u32) (((u32) 0x0001c000u)),
                        (u32) (((u32) 0x00001000u)), (u32) (((u32) 0x00013000u)), (u32) (((u32) 0x00028000u)),
                        (u32) (((u32) 0x00028000u)), (u32) (((u32) 0x00001000u)));
    func_ov001_021885d4(param_1, (int) (((u32) 0x00012000u)), (u32) (0), (u32) (((u32) 0x0001c000u)),
                        (u32) (((u32) 0x00001000u)), (u32) (((u32) 0x00011000u)), (u32) (((u32) 0x00001000u)),
                        (u32) (((u32) 0x00024000u)), (u32) (((u32) 0x00001000u)));
    return;
}

void func_ov001_0219226c(Unk02188950 *param_1) {
    param_1->mUnk_0a8 = 3;
    func_ov001_021881f4(param_1, (UnkFunc *) &func_ov001_0218fee0);
    func_ov001_02188484(param_1, 0, (u32) (((u32) 0x00028000u)), (u32) (((u32) 0xfffd1000u)),
                        (u32) (((u32) 0x00002000u)), (u32) (((u32) 0x0001b99au)), (u32) (((u32) 0x00028000u)),
                        (u32) (((u32) 0x0002f000u)), (u32) (((u32) 0x00002000u)));
    func_ov001_021885d4(param_1, 0, (u32) (0), (u32) (((u32) 0xfffd1000u)), (u32) (((u32) 0x00002000u)),
                        (u32) (((u32) 0x0001b99au)), (u32) (((u32) 0x00001000u)), (u32) (((u32) 0x0002f000u)),
                        (u32) (((u32) 0x00002000u)));
    return;
}

void func_ov001_021921e4(Unk02188950 *param_1) {
    param_1->mUnk_0a8 = 1;
    func_ov001_021881f4(param_1, (UnkFunc *) &func_ov001_0218fee0);
    func_ov001_02188484(param_1, (int) (((u32) 0xffffc000u)), (u32) (((u32) 0x00028000u)), (u32) (((u32) 0xffff5000u)),
                        (u32) (((u32) 0x00002000u)), (u32) (((u32) 0x00024000u)), (u32) (((u32) 0x00028000u)),
                        (u32) (((u32) 0x00011000u)), (u32) (((u32) 0x00001000u)));
    func_ov001_021885d4(param_1, (int) (((u32) 0xffff8000u)), (u32) (0), (u32) (((u32) 0xffffa000u)),
                        (u32) (((u32) 0x00001000u)), (u32) (((u32) 0x00020000u)), (u32) (((u32) 0x00001000u)),
                        (u32) (((u32) 0x00014000u)), (u32) (((u32) 0x00001000u)));
    return;
}

void func_ov001_02192174(Unk02188950 *param_1) {
    Vec3 pos = {0, 0, 0};

    func_ov001_02187218(param_1, 1, 0);
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_27c), (s32) (param_1->mUnk_0a0->mUnk_280));
    func_ov001_02188950(param_1, &pos);
    func_ov001_02188c0c(param_1, param_1->mUnk_0a0->mUnk_2c8, 0x270f000);
    func_ov001_02188cd8(param_1, (s32) (param_1->mUnk_0a0->mUnk_2cc), 0x270f000);
}

void func_ov001_021920dc(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 1, 0);
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_254, param_1->mUnk_0a0->mUnk_258);
    func_ov001_02188c0c(param_1, param_1->mUnk_0a0->mUnk_2c8, 0x270f000);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_2cc, 0x270f000);
    func_ov001_021875c0(param_1, 0, 0x44cd, 0x400, 0x42d, 0);
    func_ov001_021875c0(param_1, 0, 0x44cd, 0x400, 0x42e, 0);
}

void func_ov001_02192080(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 1, 0);
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_28c, param_1->mUnk_0a0->mUnk_290);
    func_ov001_02188c0c(param_1, param_1->mUnk_0a0->mUnk_2c8, 0x270f000);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_2cc, 0x270f000);
}

void func_ov001_02191fe8(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 1, 0);
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_294, param_1->mUnk_0a0->mUnk_298);
    func_ov001_02188c0c(param_1, param_1->mUnk_0a0->mUnk_2c8, 0x270f000);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_2cc, 0x270f000);
    func_ov001_021875c0(param_1, 0, 0x44cd, 0x400, 0x42d, 0);
    func_ov001_021875c0(param_1, 0, 0x44cd, 0x400, 0x42e, 0);
}

void func_ov001_02191f70(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 3, 0);
    func_ov001_02188d30(param_1, param_1->mUnk_0a0->mUnk_2ac, param_1->mUnk_0a0->mUnk_2b0, func_ov001_02192080);
    func_ov001_02188c0c(param_1, param_1->mUnk_0a0->mUnk_2c8, 0x270f000);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_2cc, 0x270f000);
    func_ov001_021922e0(param_1);
    func_020d2774(&param_1->mUnk_000, (u32) (0x215));
}

void func_ov001_02191ecc(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 3, 0);
    func_ov001_02188d30(param_1, param_1->mUnk_0a0->mUnk_2b4, param_1->mUnk_0a0->mUnk_2b8, func_ov001_02191fe8);
    func_ov001_02188c0c(param_1, param_1->mUnk_0a0->mUnk_2c8, 0x270f000);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_2cc, 0x270f000);
    func_ov001_02192358(param_1);
    func_ov001_021875c0(param_1, 0, 0x44cd, 0x2000, 0x42d, 0);
    func_ov001_021875c0(param_1, 0, 0x44cd, 0x2000, 0x42e, 0);
}

void func_ov001_02191e90(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 1, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_28c), (s32) (param_1->mUnk_0a0->mUnk_290));
    func_ov001_02188c90(param_1);
    func_ov001_02188cec(param_1, 0);
}

void func_ov001_02191e1c(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 1, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_294), (s32) (param_1->mUnk_0a0->mUnk_298));
    func_ov001_02188c90(param_1);
    func_ov001_02188cec(param_1, 0);
    func_ov001_021875c0(param_1, (u32) 0, (u32) (((u32) 0x000044cdu)), (u32) (((u32) 0x00000400u)),
                        (u32) (((u32) 0x0000042du)), (u32) 0);
    func_ov001_021875c0(param_1, (u32) 0, (u32) (((u32) 0x000044cdu)), (u32) (((u32) 0x00000400u)),
                        (u32) (((u32) 0x0000042eu)), (u32) 0);
}

void func_ov001_02191de0(Unk02188950 *param_1) {
    Vec3 v = {0, 0, 0};
    func_ov001_02188e88(param_1);
    func_ov001_02188c90(param_1);
    func_ov001_02188cec(param_1, 0);
    func_ov001_02188950(param_1, &v);
    param_1->mUnk_2c0 = 1;
}

u32 func_ov001_02191dc8(Unk02188950 *param_1) {
    func_020d275c(&param_1->mUnk_000, (u32) (((u32) 0x0000021du)));
    return 0;
}

void func_ov001_02191cf4(Unk02188950 *param_1) {
    Vec3 v = {0, 0, 0};
    v.y = -param_1->mUnk_0a0->mUnk_2a4;
    func_ov001_02187218(param_1, 3, (s32(*)(Unk02188950 *)) func_ov001_02191dc8);
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_29c, param_1->mUnk_0a0->mUnk_2a0);
    func_ov001_02188950(param_1, &v);
    func_ov001_02188c0c(param_1, param_1->mUnk_0a0->mUnk_2c8, 0x270f000);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_2cc, 0x270f000);
    func_ov001_021875c0(param_1, 0, 0x44cd, 0x400, 0x42d, 0);
    func_ov001_021875c0(param_1, 0, 0x44cd, 0x400, 0x42e, 0);
    func_ov001_02188db8(param_1, func_ov001_02191de0);
    param_1->mUnk_2c0 = 0;
}

void func_ov001_02191c14(Unk02188950 *param_1) {
    Vec3 v = {0, 0, 0};
    v.y = param_1->mUnk_0a0->mUnk_2a4;
    func_ov001_02187218(param_1, 3, (s32(*)(Unk02188950 *)) func_ov001_02191dc8);
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_29c, param_1->mUnk_0a0->mUnk_2a0);
    func_ov001_02188950(param_1, &v);
    func_ov001_02188c0c(param_1, param_1->mUnk_0a0->mUnk_2c8, 0x270f000);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_2cc, 0x270f000);
    func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_2a8, func_ov001_02191cf4);
    func_ov001_021875c0(param_1, 0, 0x44cd, 0x400, 0x42d, 0);
    func_ov001_021875c0(param_1, 0, 0x44cd, 0x400, 0x42e, 0);
    param_1->mUnk_2c0 = 0;
}

void func_ov001_02191bc0(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 3, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d30(param_1, (s32) (param_1->mUnk_0a0->mUnk_2ac), (s32) (param_1->mUnk_0a0->mUnk_2b0),
                        (UnkFunc *) &func_ov001_02191e90);
    func_ov001_02188cec(param_1, 0);
    func_ov001_02188c90(param_1);
    func_ov001_021922e0(param_1);
    func_020d2774(&param_1->mUnk_000, (u32) (((u32) 0x00000215u)));
}

void func_ov001_02191b40(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 3, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d30(param_1, (s32) (param_1->mUnk_0a0->mUnk_2b4), (s32) (param_1->mUnk_0a0->mUnk_2b8),
                        (UnkFunc *) &func_ov001_02191e1c);
    func_ov001_02188cec(param_1, 0);
    func_ov001_02188c90(param_1);
    func_ov001_02192358(param_1);
    func_ov001_021875c0(param_1, (u32) 0, (u32) (((u32) 0x000044cdu)), (u32) (((u32) 0x00002000u)),
                        (u32) (((u32) 0x0000042du)), (u32) 0);
    func_ov001_021875c0(param_1, (u32) 0, (u32) (((u32) 0x000044cdu)), (u32) (((u32) 0x00002000u)),
                        (u32) (((u32) 0x0000042eu)), (u32) 0);
}

void func_ov001_02191adc(Unk02188950 *param_1) {
    Vec3 v = {0, 0, 0};
    func_ov001_02187218(param_1, 3, 0);
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_1c0, param_1->mUnk_0a0->mUnk_1c4);
    func_ov001_02188c90(param_1);
    func_ov001_02188cec(param_1, 0);
    func_ov001_02188950(param_1, &v);
    func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_1c8, 0);
}

void func_ov001_02191a3c(Unk02188950 *param_1) {
    Vec3 v = {0, 0, 0};
    v.y = param_1->mUnk_0a0->mUnk_1bc;
    func_ov001_02187218(param_1, 3, 0);
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_1a4, param_1->mUnk_0a0->mUnk_1a8);
    func_ov001_02188950(param_1, &v);
    func_ov001_02188b78(param_1, param_1->mUnk_0a0->mUnk_1b4, param_1->mUnk_0a0->mUnk_1b8);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_1ac, param_1->mUnk_0a0->mUnk_1b0);
    func_ov001_02188db8(param_1, func_ov001_02191adc);
    param_1->mUnk_2c0 = 1;
}

void func_ov001_02191980(Unk02188950 *param_1) {
    Vec3 v = {0, 0, 0};
    func_ov001_02187218(param_1, 3, 0);
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_184, param_1->mUnk_0a0->mUnk_188);
    func_ov001_02188b78(param_1, param_1->mUnk_0a0->mUnk_194, param_1->mUnk_0a0->mUnk_198);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_18c, param_1->mUnk_0a0->mUnk_190);
    func_ov001_02188950(param_1, &v);
    func_ov001_02188de0(param_1, param_1->mUnk_0a0->mUnk_19c, 0, &param_1->mUnk_1ac, func_ov001_02191a3c);
    func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_0ec, func_ov001_02191a3c);
    param_1->mUnk_2c0 = 0;
}

void func_ov001_021918c8(Unk02188950 *param_1) {
    Vec3 v = {0, 0, 0};
    v.y = param_1->mUnk_0a0->mUnk_17c;
    func_ov001_021924cc();
    func_ov001_02187218(param_1, 3, 0);
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_164, param_1->mUnk_0a0->mUnk_168);
    func_ov001_02188950(param_1, &v);
    func_ov001_02188b78(param_1, param_1->mUnk_0a0->mUnk_174, param_1->mUnk_0a0->mUnk_178);
    func_ov001_02188998(param_1, &param_1->mUnk_1ac);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_16c, param_1->mUnk_0a0->mUnk_170);
    func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_180, func_ov001_02191980);
}

int func_ov001_02191888(Unk02188950 *param_1) {
    if (param_1->mUnk_174 > 0) {
        func_020d275c(&param_1->mUnk_000, (u32) (0x219));
    } else {
        func_ov001_02187af4(param_1);
        func_ov001_02188200(param_1, func_ov001_02192878);
        param_1->mUnk_158 = 0;
    }
    return 0;
}

s32 func_ov001_02191870(Unk02188950 *param_1) {
    func_020d275c(&param_1->mUnk_000, (u32) (0x219));
    return 0;
}

void func_ov001_021917d0(Unk02188950 *param_1) {
    func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(param_1, 3, (s32(*)(Unk02188950 *))(func_ov001_02191888));
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_148, param_1->mUnk_0a0->mUnk_14c);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_150, param_1->mUnk_0a0->mUnk_154);
    func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_160, func_ov001_021918c8);
    func_ov001_021875c0(param_1, (u32) (0x1000), (u32) (0), (u32) (0x2000), (u32) (0x433), (u32) (0));
}

void func_ov001_021916e0(Unk02188950 *param_1) {
    Unk0206bcb0 *v1 = func_0207a974((u16) data_021759c0->mUnk_62);
    Vec3 local = {0, 0, 0};

    if ((param_1->mUnk_000.mUnk_02 & 0x400) == 0) {
        param_1->mUnk_1a8 = param_1->mUnk_184 + 0x4000;
    } else {
        param_1->mUnk_1a8 = param_1->mUnk_184 - 0x4000;
    }
    func_ov001_02187218(param_1, 3, (s32(*)(Unk02188950 *))(func_ov001_02191870));
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_128, param_1->mUnk_0a0->mUnk_12c);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_130, param_1->mUnk_0a0->mUnk_134);
    func_ov001_021889c8(param_1);
    func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_140, func_ov001_021917d0);
    func_ov001_02188200(param_1, func_ov001_021927c0);
    func_ov001_021875c0(param_1, (u32) (0x1000), (u32) (0), (u32) (0x2000), (u32) (0x433), (u32) (0));
}

void func_ov001_02191618(Unk02188950 *param_1) {
    Vec3 local = {0, 0, 0};

    func_ov001_02187218(param_1, 3, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_118, param_1->mUnk_0a0->mUnk_11c);
    func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_120, func_ov001_021916e0);
    func_ov001_02188c90(param_1);
    func_ov001_02188cec(param_1, 0);
    func_ov001_02188950(param_1, &local);
    func_ov001_02188200(param_1, func_ov001_02192878);
    func_02073fb0(param_1->mUnk_000.mUnk_78 & 0x3fffffe0, 0x1000);
    func_ov001_02187518(param_1, (u32) (0x1000), (u32) (0), (u32) (0x2000), (u32) (0x414), (u32) (0));
    func_ov001_02187518(param_1, (u32) (0x1000), (u32) (0), (u32) (0x2000), (u32) (0x415), (u32) (0));
    func_020d2774(&param_1->mUnk_000, (u32) (0x218));
}

void func_ov001_02191550(Unk02188950 *param_1) {
    Vec3 local = {0, 0, 0};

    func_ov001_02187218(param_1, 3, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_10c, param_1->mUnk_0a0->mUnk_110);
    func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_114, func_ov001_021918c8);
    func_ov001_02188c90(param_1);
    func_ov001_02188cec(param_1, 0);
    func_ov001_02188950(param_1, &local);
    func_ov001_02188200(param_1, func_ov001_02192878);
    func_02073fb0(param_1->mUnk_000.mUnk_78 & 0x3fffffe0, 0x1000);
    func_ov001_02187518(param_1, (u32) (0x1000), (u32) (0), (u32) (0x2000), (u32) (0x414), (u32) (0));
    func_ov001_02187518(param_1, (u32) (0x1000), (u32) (0), (u32) (0x2000), (u32) (0x415), (u32) (0));
    func_020d2774(&param_1->mUnk_000, (u32) (0x218));
}

void func_ov001_02191488(Unk02188950 *param_1) {
    Vec3 local = {0, 0, 0};

    local.y = param_1->mUnk_0a0->mUnk_108;
    func_ov001_02187218(param_1, 3, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_0f0, param_1->mUnk_0a0->mUnk_0f4);
    func_ov001_02188950(param_1, &local);
    func_ov001_02188c90(param_1);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_0f8, param_1->mUnk_0a0->mUnk_0fc);
    if (func_ov001_02188220(
            data_021759c0->mUnk_08 == 4
                ? func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 2))
                : 0) >= 1) {
        func_ov001_02188db8(param_1, func_ov001_02191618);
    } else {
        func_ov001_02188db8(param_1, func_ov001_02191550);
    }
    param_1->mUnk_2c0 = 1;
    func_ov001_02188200(param_1, func_ov001_02192794);
}

s32 func_ov001_02191470(Unk02188950 *param_1) {
    func_020d275c(&param_1->mUnk_000, (u32) (0x21c));
    return 0;
}

void func_ov001_021913b8(Unk02188950 *param_1) {
    Unk0206bcb0 *v1 = func_0207a974((u16) data_021759c0->mUnk_62);
    Vec3 local = {0, 0, 0};

    func_ov001_02187e78(param_1);
    func_ov001_02187218(param_1, 3, (s32(*)(Unk02188950 *))(func_ov001_02191470));
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_0d0, param_1->mUnk_0a0->mUnk_0d4);
    func_ov001_02188950(param_1, &local);
    func_ov001_02188c90(param_1);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_0d8, param_1->mUnk_0a0->mUnk_0dc);
    func_ov001_02188de0(param_1, param_1->mUnk_0a0->mUnk_0e8, 0, &v1->mUnk_80, func_ov001_02191488);
    func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_0ec, func_ov001_02191488);
    param_1->mUnk_2c0 = 0;
}

void func_ov001_02191318(Unk02188950 *param_1) {
    Unk0206bcb0 *v1 = func_0207a974((u16) data_021759c0->mUnk_62);
    Vec3 local = {0, 0, 0};

    local.y = param_1->mUnk_0a0->mUnk_0a4;
    func_ov001_02187218(param_1, 3, (s32(*)(Unk02188950 *))(func_ov001_02191470));
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_08c, param_1->mUnk_0a0->mUnk_090);
    func_ov001_02188950(param_1, &local);
    func_ov001_02188c90(param_1);
    func_ov001_02188998(param_1, &v1->mUnk_80);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_094, param_1->mUnk_0a0->mUnk_098);
    func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_0a8, func_ov001_021913b8);
}

void func_ov001_02191258(Unk02188950 *param_1) {
    Vec3 local = {0, 0, 0};

    func_ov001_02187218(param_1, 3, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_210, param_1->mUnk_0a0->mUnk_214);
    func_ov001_02188e24(param_1, param_1->mUnk_0a0->mUnk_218, 0);
    func_ov001_02188c90(param_1);
    func_ov001_02188cec(param_1, 0);
    func_ov001_02188950(param_1, &local);
    func_ov001_02188200(param_1, func_ov001_02192878);
    func_02073fb0(param_1->mUnk_000.mUnk_78 & 0x3fffffe0, 0x1000);
    func_ov001_02187518(param_1, (u32) (0x1000), (u32) (0), (u32) (0x2000), (u32) (0x414), (u32) (0));
    func_ov001_02187518(param_1, (u32) (0x1000), (u32) (0), (u32) (0x2000), (u32) (0x415), (u32) (0));
    func_020d2774(&param_1->mUnk_000, (u32) (0x218));
}

void func_ov001_021911a8(Unk02188950 *param_1) {
    Unk0206bcb0 *v1 = func_0207a974((u16) data_021759c0->mUnk_62);
    Vec3 local = {0, 0, 0};

    local.y = param_1->mUnk_0a0->mUnk_1e4;
    func_ov001_02187218(param_1, 3, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(param_1, param_1->mUnk_0a0->mUnk_1cc, param_1->mUnk_0a0->mUnk_1d0);
    func_ov001_02188950(param_1, &local);
    func_ov001_02188c90(param_1);
    func_ov001_02188998(param_1, &v1->mUnk_80);
    func_ov001_02188cd8(param_1, param_1->mUnk_0a0->mUnk_1d4, param_1->mUnk_0a0->mUnk_1d8);
    func_ov001_02188db8(param_1, func_ov001_02191258);
    func_ov001_02188200(param_1, func_ov001_02192794);
}

void func_ov001_0219116c(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 7, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d30(param_1, (s32) (param_1->mUnk_0a0->mUnk_234), (s32) (param_1->mUnk_0a0->mUnk_238),
                        (UnkFunc *) &func_ov001_021918c8);
    func_ov001_021922e0(param_1);
}

void func_ov001_02191130(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 7, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d30(param_1, (s32) (param_1->mUnk_0a0->mUnk_22c), (s32) (param_1->mUnk_0a0->mUnk_230),
                        (UnkFunc *) &func_ov001_0219116c);
    func_ov001_021921e4(param_1);
}

s32 func_ov001_021910fc(Unk02188950 *param_1) {
    if ((param_1->mUnk_2c8 & 0x001e34ef) != 0) {
        func_020d2774(&param_1->mUnk_000, (u32) 0x218);
        param_1->mUnk_158 = 0;
    }
    return 0;
}

s32 func_ov001_021910d4(Unk02188950 *param_1) {
    if (param_1->mUnk_2c8 & 0x1e34ef) {
        param_1->mUnk_158 = (s32(*)(Unk02188950 *)) func_ov001_021910fc;
    }
    return 0;
}

void func_ov001_02191064(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 7, (s32(*)(Unk02188950 *))((int) &func_ov001_021910d4));
    func_ov001_02188d30(param_1, (s32) (param_1->mUnk_0a0->mUnk_21c), (s32) (param_1->mUnk_0a0->mUnk_220),
                        (UnkFunc *) &func_ov001_02191130);
    func_ov001_02188c90(param_1);
    func_ov001_02188cec(param_1, 0);
    param_1->mUnk_2c0 = 1;
    func_ov001_0219226c(param_1);
    func_ov001_02188200(param_1, func_ov001_02192878);
    func_020d2774(&param_1->mUnk_000, (u32) (((u32) 0x00000216u)));
}

void func_ov001_02191034(int param_1) {
    func_ov001_02187218((Unk02188950 *) param_1, 7, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64((Unk02188950 *) param_1, (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x24c)),
                        (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x250)));
}

void func_ov001_02190fc4(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 7, (s32(*)(Unk02188950 *))((int) &func_ov001_021910d4));
    func_ov001_02188d30(param_1, (s32) (param_1->mUnk_0a0->mUnk_23c), (s32) (param_1->mUnk_0a0->mUnk_240),
                        (UnkFunc *) &func_ov001_02191034);
    func_ov001_02188c90(param_1);
    func_ov001_02188cec(param_1, 0);
    param_1->mUnk_2c0 = 1;
    func_ov001_0219226c(param_1);
    func_ov001_02188200(param_1, func_ov001_02192878);
    func_020d2774(&param_1->mUnk_000, (u32) (((u32) 0x00000216u)));
}

void func_ov001_02190ee0(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02187af4(param_1);
    func_ov001_021875c0(param_1, (u32) 0, (u32) 0x1000, (u32) 0xffffdccd, (u32) 0x3ef, (u32) 0);
    func_ov001_021875c0(param_1, (u32) 0, (u32) 0x1000, (u32) 0xffffdccd, (u32) 0x3ee, (u32) 0);
    func_ov001_021875c0(param_1, (u32) 0, (u32) 0x1000, (u32) 0xffffdccd, (u32) 0x3f0, (u32) 0);
    func_ov001_021875c0(param_1, (u32) 0, (u32) 0x1000, (u32) 0xffffdccd, (u32) 0x3f1, (u32) 0);
    func_ov001_021875c0(param_1, (u32) 0, (u32) 0x1000, (u32) 0xffffdccd, (u32) 0x3f2, (u32) 0);
    {
        Unk02190ee0 local = data_ov001_021a7de8;

        local.mUnk_04 = &param_1->mUnk_000.mUnk_04;
        local.mUnk_0c = func_020d4ef4(&param_1->mUnk_000.mUnk_04);
        func_0210b734(&local, (u32) (func_02108e7c()));
    }
    param_1->mUnk_000.mUnk_02 |= data_ov001_021a65c8;
    param_1->mUnk_000.mUnk_02 |= data_ov001_021a65cc;
    param_1->mUnk_000.mUnk_02 |= data_ov001_021a65d0;
}

void func_ov001_02190eb0(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_070), (s32) (param_1->mUnk_0a0->mUnk_074));
    func_ov001_02188e24(param_1, (s32) ((u32) 0x3c), (UnkFunc *) ((int) &func_ov001_02190ee0));
}

void func_ov001_02190df8(Unk02188950 *param_1) {
    if (param_1->mUnk_0a8 == 1) {
        func_ov001_02187218(param_1, 8, (s32(*)(Unk02188950 *))(0));
        func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_078), (s32) (param_1->mUnk_0a0->mUnk_07c));
        func_ov001_02188c90(param_1);
        func_ov001_02188cec(param_1, 0);
        return;
    }
    func_ov001_02187218(param_1, 3, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d30(param_1, (s32) (param_1->mUnk_0a0->mUnk_2b4), (s32) (param_1->mUnk_0a0->mUnk_2b8),
                        (UnkFunc *) &func_ov001_02190df8);
    func_ov001_02188c90(param_1);
    func_ov001_02188cec(param_1, 0);
    func_ov001_02192358(param_1);
    func_ov001_021875c0(param_1, (u32) 0, (u32) (((u32) 0x000044cdu)), (u32) (((u32) 0x00002000u)),
                        (u32) (((u32) 0x0000042du)), (u32) 0);
    func_ov001_021875c0(param_1, (u32) 0, (u32) (((u32) 0x000044cdu)), (u32) (((u32) 0x00002000u)),
                        (u32) (((u32) 0x0000042eu)), (u32) 0);
}

void func_ov001_02190df0(void) {
    func_ov001_021882b8();
}

s32 func_ov001_02190d78(Unk02188950 *param_1) {
    Unk02188950 *v1;
    Unk02188950 *v2;

    v1 = data_021759c0->mUnk_08 == 4
             ? func_ov001_02181b68((u16) (data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0))
             : 0;
    v2 = data_021759c0->mUnk_08 == 4
             ? func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1))
             : 0;
    if (func_ov001_021871f8(v1, 3) != 0 && func_ov001_021871f8(v2, 3) != 0) {
        func_ov001_02188e88(param_1);
    }
    return 0;
}

s32 func_ov001_02190d00(Unk02188950 *param_1) {
    Unk02188950 *a;
    Unk02188950 *b;

    a = (data_021759c0->mUnk_08 == 4
             ? func_ov001_02181b68((u16) (data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0))
             : 0);
    b = (data_021759c0->mUnk_08 == 4
             ? func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1))
             : 0);
    if (func_ov001_021871f8(a, 3) && func_ov001_021871f8(b, 3)) {
        func_ov001_02190c08(param_1);
    }
    return 0;
}

void func_ov001_02190c08(Unk02188950 *param_1) {
    Unk02188950 *a;
    Unk02188950 *b;

    if (func_ov001_0218820c(param_1)) {
        func_ov001_02187218(param_1, 3, func_ov001_02190d00);
        func_ov001_02188c90(param_1);
        a = (data_021759c0->mUnk_08 == 4
                 ? func_ov001_02181b68((u16) (data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0))
                 : 0);
        b = (data_021759c0->mUnk_08 == 4
                 ? func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1))
                 : 0);
        func_ov001_021911a8(a);
        func_ov001_021911a8(b);
    } else {
        func_ov001_02187218(param_1, 3, func_ov001_02190d78);
        func_ov001_02188c90(param_1);
        a = (data_021759c0->mUnk_08 == 4
                 ? func_ov001_02181b68((u16) (data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0))
                 : 0);
        b = (data_021759c0->mUnk_08 == 4
                 ? func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1))
                 : 0);
        func_ov001_021918c8(a);
        func_ov001_021918c8(b);
    }
}

s32 func_ov001_02190b58(Unk02188950 *param_1) {
    Unk02188950 *a;
    Unk02188950 *b;

    a = (data_021759c0->mUnk_08 == 4
             ? func_ov001_02181b68((u16) (data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0))
             : 0);
    b = (data_021759c0->mUnk_08 == 4
             ? func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1))
             : 0);
    func_ov001_02188998(param_1, &func_0207a974((u16) data_021759c0->mUnk_62)->mUnk_80);
    func_ov001_021924cc();
    if (func_ov001_021871f8(a, 3) && func_ov001_021871f8(b, 3)) {
        func_ov001_02188218(param_1, (s32) ((u16) param_1->mUnk_0a0->mUnk_1ec));
        func_ov001_02190c08(param_1);
    }
    return 0;
}

void func_ov001_02190acc(Unk02188950 *param_1) {
    Unk02188950 *a;
    Unk02188950 *b;

    func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(param_1, 3, func_ov001_02190b58);
    func_ov001_02188c90(param_1);
    a = (data_021759c0->mUnk_08 == 4
             ? func_ov001_02181b68((u16) (data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0))
             : 0);
    b = (data_021759c0->mUnk_08 == 4
             ? func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1))
             : 0);
    func_ov001_02191bc0(a);
    func_ov001_02191bc0(b);
}

s32 func_ov001_02190a20(Unk02188950 *param_1) {
    Unk02188950 *a;
    Unk02188950 *b;

    a = (data_021759c0->mUnk_08 == 4
             ? func_ov001_02181b68((u16) (data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0))
             : 0);
    b = (data_021759c0->mUnk_08 == 4
             ? func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1))
             : 0);
    func_ov001_02188998(param_1, &func_0207a974((u16) data_021759c0->mUnk_62)->mUnk_80);
    func_ov001_021924cc();
    if (func_ov001_021871f8(a, 3) && func_ov001_021871f8(b, 3)) {
        param_1->mUnk_0a8 = param_1->mUnk_0a8 == 4 ? 5 : 4;
        func_ov001_02190948(param_1);
    }
    return 0;
}

void func_ov001_02190948(Unk02188950 *param_1) {
    Unk0206bcb0 *r4;
    Unk02188950 *a;
    Unk02188950 *b;

    if (func_ov001_0218820c(param_1)) {
        r4 = func_0207a974((u16) data_021759c0->mUnk_62);
        func_ov001_02187218(param_1, 3, func_ov001_02190a20);
        func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_2c4, 0x270f000);
        func_ov001_02188998(param_1, &r4->mUnk_80);
        if (data_021759c0->mUnk_08 == 4) {
            a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
        } else {
            a = 0;
        }
        if (data_021759c0->mUnk_08 == 4) {
            b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
        } else {
            b = 0;
        }
        if (param_1->mUnk_0a8 == 4) {
            func_ov001_02191c14(a);
            func_ov001_021920dc(b);
        } else {
            func_ov001_021920dc(a);
            func_ov001_02191c14(b);
        }
    } else {
        func_ov001_02190acc(param_1);
    }
}

int func_ov001_021908a8(Unk02188950 *param_1) {
    Unk0206bcb0 *r4;
    Unk02188950 *a;
    Unk02188950 *b;

    if (data_021759c0->mUnk_08 == 4) {
        a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
    } else {
        a = 0;
    }
    if (data_021759c0->mUnk_08 == 4) {
        b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        b = 0;
    }
    r4 = func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02188998(param_1, &r4->mUnk_80);
    func_ov001_021924cc();
    if (func_ov001_021871f8(a, 3) && func_ov001_021871f8(b, 3)) {
        func_ov001_02188218(param_1, 4);
        func_ov001_02190948(param_1);
    }
    return 0;
}

void func_ov001_0219081c(Unk02188950 *param_1) {
    Unk02188950 *a;
    Unk02188950 *b;

    func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(param_1, 3, func_ov001_021908a8);
    func_ov001_02188c90(param_1);
    if (data_021759c0->mUnk_08 == 4) {
        a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
    } else {
        a = 0;
    }
    if (data_021759c0->mUnk_08 == 4) {
        b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        b = 0;
    }
    func_ov001_02191b40(a);
    func_ov001_02191b40(b);
}

int func_ov001_0219079c(Unk02188950 *param_1) {
    Unk02188950 *a;
    Unk02188950 *b;

    if (data_021759c0->mUnk_08 == 4) {
        a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
    } else {
        a = 0;
    }
    if (data_021759c0->mUnk_08 == 4) {
        b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        b = 0;
    }
    func_ov001_02192694();
    func_ov001_021924cc();
    if (func_ov001_021871f8(a, 3) && func_ov001_021871f8(b, 3)) {
        func_ov001_02188e88(param_1);
    }
    return 0;
}

int func_ov001_02190688(Unk02188950 *param_1) {
    Unk0206bcb0 *r4;
    Unk02188950 *a;
    Unk02188950 *b;

    r4 = func_0207a974((u16) data_021759c0->mUnk_62);
    if (data_021759c0->mUnk_08 == 4) {
        a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
    } else {
        a = 0;
    }
    if (data_021759c0->mUnk_08 == 4) {
        b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        b = 0;
    }
    if (param_1->mUnk_0a8 == 4) {
        if (func_ov001_021871f8(a, 3)) {
            param_1->mUnk_0a8 = 5;
            func_ov001_02187218(param_1, 3, func_ov001_0219079c);
            func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_2c4, 0x270f000);
            func_ov001_02188998(param_1, &r4->mUnk_80);
            func_ov001_02191ecc(a);
            func_ov001_02191f70(b);
        }
    } else if (func_ov001_021871f8(b, 3)) {
        param_1->mUnk_0a8 = 4;
        func_ov001_02187218(param_1, 3, func_ov001_0219079c);
        func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_2c4, 0x270f000);
        func_ov001_02188998(param_1, &r4->mUnk_80);
        func_ov001_02191f70(a);
        func_ov001_02191ecc(b);
    }
    return 0;
}

void func_ov001_021905f8(Unk02188950 *param_1) {
    Unk02188950 *a;
    Unk02188950 *b;

    func_ov001_02187218(param_1, 3, func_ov001_02190688);
    func_ov001_02188c90(param_1);
    if (data_021759c0->mUnk_08 == 4) {
        a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
    } else {
        a = 0;
    }
    if (data_021759c0->mUnk_08 == 4) {
        b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        b = 0;
    }
    if (param_1->mUnk_0a8 == 4) {
        func_ov001_02191318(a);
        func_ov001_02191e1c(b);
    } else {
        func_ov001_02191e1c(a);
        func_ov001_02191318(b);
    }
}

int func_ov001_0219052c(Unk02188950 *param_1) {
    Unk02188950 *a;
    Unk02188950 *b;

    if (data_021759c0->mUnk_08 == 4) {
        a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
    } else {
        a = 0;
    }
    if (data_021759c0->mUnk_08 == 4) {
        b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        b = 0;
    }
    func_ov001_02192694();
    func_ov001_021924cc();
    if (func_ov001_021881a8(param_1, &param_1->mUnk_188, 0, (s32) (param_1->mUnk_0a0->mUnk_2bc)) &&
        func_ov001_021881a8(a, &a->mUnk_1ac, (s32) (param_1->mUnk_0a0->mUnk_2c0), 0) &&
        func_ov001_021881a8(b, &b->mUnk_1ac, (s32) (param_1->mUnk_0a0->mUnk_2c0), 0)) {
        func_ov001_021905f8(param_1);
    }
    return 0;
}

void func_ov001_02190468(Unk02188950 *param_1) {
    Unk0206bcb0 *r4;
    Unk02188950 *a;
    Unk02188950 *b;

    r4 = func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(param_1, 3, func_ov001_0219052c);
    func_ov001_02188c48(param_1, param_1->mUnk_0a0->mUnk_2c4, 0x270f000);
    func_ov001_02188998(param_1, &r4->mUnk_80);
    if (data_021759c0->mUnk_08 == 4) {
        a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
    } else {
        a = 0;
    }
    if (data_021759c0->mUnk_08 == 4) {
        b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        b = 0;
    }
    if (param_1->mUnk_0a8 == 4) {
        func_ov001_02192174(a);
        func_ov001_021920dc(b);
    } else {
        func_ov001_021920dc(a);
        func_ov001_02192174(b);
    }
}

int func_ov001_021903e0(Unk02188950 *param_1) {
    Unk02188950 *a;
    Unk02188950 *b;

    func_0207a974((u16) data_021759c0->mUnk_62);
    if (data_021759c0->mUnk_08 == 4) {
        a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
    } else {
        a = 0;
    }
    if (data_021759c0->mUnk_08 == 4) {
        b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        b = 0;
    }
    if (func_ov001_021871f8(a, 3) && func_ov001_021871f8(b, 3)) {
        func_ov001_02188e88(param_1);
    }
    return 0;
}

void func_ov001_02190328(Unk02188950 *param_1) {
    Unk02188950 *a;
    Unk02188950 *b;

    func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(param_1, 3, func_ov001_021903e0);
    func_ov001_02188c90(param_1);
    param_1->mUnk_0a8 = (param_1->mUnk_0a8 == 5) ? 4 : 5;
    if (data_021759c0->mUnk_08 == 4) {
        a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
    } else {
        a = 0;
    }
    if (data_021759c0->mUnk_08 == 4) {
        b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        b = 0;
    }
    if (param_1->mUnk_0a8 == 4) {
        func_ov001_02191bc0(a);
        func_ov001_02191e1c(b);
    } else {
        func_ov001_02191e1c(a);
        func_ov001_02191bc0(b);
    }
}

void func_ov001_02190270(Unk02188950 *param_1) {
    Unk02188950 *a;
    Unk02188950 *b;

    func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(param_1, 3, func_ov001_021903e0);
    func_ov001_02188c90(param_1);
    param_1->mUnk_0a8 = (param_1->mUnk_0a8 == 5) ? 4 : 5;
    if (data_021759c0->mUnk_08 == 4) {
        a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
    } else {
        a = 0;
    }
    if (data_021759c0->mUnk_08 == 4) {
        b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        b = 0;
    }
    if (param_1->mUnk_0a8 == 4) {
        func_ov001_02191e90(a);
        func_ov001_02191b40(b);
    } else {
        func_ov001_02191b40(a);
        func_ov001_02191e90(b);
    }
}

void func_ov001_02190248(Unk02188950 *param_1) {
    func_ov001_02188218(param_1, (s32) ((u16) param_1->mUnk_0a0->mUnk_1ec));
    func_ov001_02190c08(param_1);
}

int func_ov001_02190168(Unk02188950 *param_1) {
    Unk02188950 *a;
    Unk02188950 *b;

    if (data_021759c0->mUnk_08 == 4) {
        a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
    } else {
        a = 0;
    }
    if (data_021759c0->mUnk_08 == 4) {
        b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        b = 0;
    }
    if (func_ov001_021871f8(a, 3) && func_ov001_021871f8(b, 3)) {
        if (func_ov001_02188220((Unk02188950 *) ((
                data_021759c0->mUnk_08 == 4
                    ? func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 2))
                    : 0))) == 1) {
            func_ov001_02190270(param_1);
        } else if (func_ov001_02188220((Unk02188950 *) ((
                       data_021759c0->mUnk_08 == 4
                           ? func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 2))
                           : 0))) == 2) {
            func_ov001_02190248(param_1);
        } else {
            func_ov001_02188e88(param_1);
        }
    }
    return 0;
}

void func_ov001_021900ac(Unk02188950 *param_1) {
    Unk02188950 *a;
    Unk02188950 *b;

    func_ov001_02187218(param_1, 3, func_ov001_02190168);
    func_ov001_02188c90(param_1);
    if (data_021759c0->mUnk_08 == 4) {
        a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
    } else {
        a = 0;
    }
    if (data_021759c0->mUnk_08 == 4) {
        b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        b = 0;
    }
    if (func_ov001_02188220((Unk02188950 *) ((
            data_021759c0->mUnk_08 == 4
                ? func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 2))
                : 0))) >= 2) {
        func_ov001_02190fc4(a);
        func_ov001_02190fc4(b);
    } else {
        func_ov001_02191064(a);
        func_ov001_02191064(b);
    }
}

u32 func_ov001_02190090(Unk02188950 *param_1) {
    int v1;
    v1 = func_02061fec();
    if (v1 == 1) {
        func_ov001_02190328(param_1);
    }
    return 0;
}

void func_ov001_02190080(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 8, (s32(*)(Unk02188950 *)) func_ov001_02190090);
}

void func_ov001_0219006c(Unk02188950 *param_1) {
    func_ov001_021900ac(param_1);
    func_ov001_02188260(param_1);
    return;
}

void func_ov001_02190030(Unk02188950 *param_1) {
    func_ov001_02187518(param_1, (u32) (((u32) 0x00002ccdu)), (u32) (0), (u32) (0), (u32) (((u32) 0x00000411u)),
                        (u32) (0));
    func_ov001_02187518(param_1, (u32) (((u32) 0x00002ccdu)), (u32) (0), (u32) (0), (u32) (((u32) 0x00000412u)),
                        (u32) (0));
    return;
}

void func_ov001_0218ffd4(int param_1) {
    func_ov001_02187218((Unk02188950 *) (param_1), 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64((Unk02188950 *) (param_1), (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 100)),
                        (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x68)));
    func_ov001_021875c0((Unk02188950 *) (param_1), (u32) (0), (u32) (((u32) 0x000044cdu)), (u32) (((u32) 0x00000400u)),
                        (u32) (((u32) 0x0000042du)), (u32) (0));
    func_ov001_021875c0((Unk02188950 *) (param_1), (u32) (0), (u32) (((u32) 0x000044cdu)), (u32) (((u32) 0x00000400u)),
                        (u32) (((u32) 0x0000042eu)), (u32) (0));
    return;
}

void func_ov001_0218ff98(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d30(param_1, (s32) (param_1->mUnk_0a0->mUnk_058), (s32) (param_1->mUnk_0a0->mUnk_05c),
                        (UnkFunc *) &func_ov001_0218ffd4);
    func_ov001_021923e0(param_1);
    func_020d2774(&param_1->mUnk_000, (u32) (((u32) 0x0000021bu)));
    return;
}

void func_ov001_0218ff64(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_04c), (s32) (param_1->mUnk_0a0->mUnk_050));
    func_ov001_02188e24(param_1, (s32) ((u32) (param_1->mUnk_0a0->mUnk_054)), (UnkFunc *) ((int) &func_ov001_0218ff98));
    return;
}

void func_ov001_0218ff34(int param_1) {
    func_ov001_02187218((Unk02188950 *) (param_1), 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64((Unk02188950 *) (param_1), (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x40)),
                        (s32) (*(u32 *) (*(int *) (param_1 + 0xa0) + 0x44)));
    func_ov001_02188db8((Unk02188950 *) ((int) (param_1)), (UnkFunc *) ((int) &func_ov001_02190030));
    return;
}

void func_ov001_0218fef8(Unk02188950 *param_1) {
    func_ov001_02187218(param_1, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(param_1, (s32) (param_1->mUnk_0a0->mUnk_034), (s32) (param_1->mUnk_0a0->mUnk_038));
    func_ov001_0218720c(param_1);
    func_ov001_02188e24(param_1, (s32) ((u32) (param_1->mUnk_0a0->mUnk_03c)), (UnkFunc *) ((int) &func_ov001_0218ff34));
    return;
}

void func_ov001_0218fee0(Unk02188950 *param_1) {
    param_1->mUnk_2e0 = 2;
    func_ov001_021881f4(param_1, (UnkFunc *) func_ov001_0218fee0);
}

void func_ov001_0218fd20(Unk02188950 *param_1, Unk0218fd20 *param_2) {
    int diff;
    int limit;
    Vec3 vec;

    diff = (u16) (func_02148714(param_2->mUnk_50.x - param_1->mUnk_000.mUnk_04.x,
                                param_2->mUnk_50.z - param_1->mUnk_000.mUnk_04.z) -
                  param_1->mUnk_184);
    if (diff > 0x8000) {
        diff -= 0x10000;
    }
    limit = param_1->mUnk_0a0->mUnk_088;
    if (diff <= limit && diff >= -limit && func_ov001_021871f8(param_1, 7)) {
        vec.x = (s32) (((s64) -param_1->mUnk_0a0->mUnk_224 * data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2]) >> 12);
        vec.y = param_1->mUnk_0a0->mUnk_228;
        vec.z =
            (s32) (((s64) -param_1->mUnk_0a0->mUnk_224 * data_0215d4b4[((u16) param_1->mUnk_184 >> 4) * 2 + 1]) >> 12);
        func_ov001_02188950((data_021759c0->mUnk_08 == 4
                                 ? func_ov001_02181b68((u16) (data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0))
                                 : 0),
                            &vec);
        func_ov001_02188950(
            (data_021759c0->mUnk_08 == 4
                 ? func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1))
                 : 0),
            &vec);
        func_0208b7bc(0x3eb, &param_2->mUnk_50);
        func_0208b7bc(0x3ec, &param_2->mUnk_50);
        func_0208b7bc(0x3ed, &param_2->mUnk_50);
        param_1->mUnk_000.mUnk_78 |= data_ov001_021a65c4;
        func_ov001_0219006c(
            data_021759c0->mUnk_08 == 4
                ? func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 2))
                : 0);
        func_ov001_021881f4(param_1, (UnkFunc *) func_ov001_0218fee0);
        param_1->mUnk_2e0 = 2;
    } else {
        param_1->mUnk_2e0 = 2;
        func_ov001_021881f4(param_1, (UnkFunc *) func_ov001_0218fd20);
    }
}

void func_ov001_0218fcc4(Unk0218fa78 *param_1) {
    int i;
    Unk02188950 *obj;
    int zero;

    if (param_1 != 0) {
        zero = 0;
        for (i = 0; i < param_1->mUnk_04 && (obj = param_1->mUnk_00[i]) != 0; i++) {
            func_ov001_021870e4((void *) zero, obj, (const char *) zero, (const char *) zero,
                                (const char *) data_ov001_021a7eb0);
            if (data_021759c0->mUnk_08 == 4) {
                func_ov001_02181b8c(obj);
            }
            func_ov001_02190080(obj);
        }
    }
}

void func_ov001_0218fc4c(u32 param_1, Unk02188950 *param_2) {
    if ((data_021759c0->mUnk_08 == 4 ? func_020a126c() : 0) == 0 && func_ov001_021871f8(param_2, 1)) {
        if (func_ov001_02188220(
                (data_021759c0->mUnk_08 == 4
                     ? func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 2))
                     : 0)) < 2) {
            func_ov001_02190468(param_2);
        } else {
            func_ov001_0219081c(param_2);
        }
    }
    func_ov001_021864ac(param_1, param_2);
}

void func_ov001_0218fbe0(Unk0218fa78 *param_1) {
    int i;
    Unk02188950 *obj;

    if (param_1 != 0) {
        for (i = 0; i < param_1->mUnk_04 && (obj = param_1->mUnk_00[i]) != 0; i++) {
            if (func_02062ec4()) {
                obj->mUnk_000.mUnk_04.y += obj->mUnk_0a0->mUnk_080;
                func_ov001_0218fef8(obj);
            } else {
                func_ov001_0218ff64(obj);
            }
            func_ov001_0219246c(obj);
            func_ov001_02188200(obj, func_ov001_02192878);
        }
    }
    func_020a2314((void (*)(void)) func_ov001_02190df0);
}

void func_ov001_0218fb24(u32 param_1, Unk02188950 *param_2) {
    s32 value;

    if ((data_021759c0->mUnk_08 == 4 ? func_020a128c() : 0) && func_ov001_021871f8(param_2, 3)) {
        if (data_021759c0->mUnk_08 == 4 ? func_020a1084((u16) data_021759c0->mUnk_62) : 0) {
            func_ov001_02190df8(param_2);
        } else {
            func_ov001_02190eb0(param_2);
        }
    }
    if (param_2->mUnk_0a8 == 1) {
        value = param_2->mUnk_134 + 1;
        if (value >= func_0209b634(param_2->mUnk_304) - 1) {
            value = func_0209b634(param_2->mUnk_304) - 1;
        }
        param_2->mUnk_134 = value;
    } else {
        value = param_2->mUnk_134 - 1;
        if (value <= 0) {
            value = 0;
        }
        param_2->mUnk_134 = value;
    }
    func_0209b688((void *) (param_2->mUnk_304), (u16) param_2->mUnk_134);
    func_ov001_021864ac(param_1, param_2);
}

void func_ov001_0218fa78(Unk0218fa78 *param_1) {
    int i;
    Unk02188950 *obj;

    if (param_1 != 0) {
        for (i = 0; i < param_1->mUnk_04 && (obj = param_1->mUnk_00[i]) != 0; i++) {
            if (data_021759c0->mUnk_08 == 4) {
                func_ov001_02181b8c(obj);
            }
            func_ov001_021870e4(param_1, obj, (const char *) data_ov001_021a7e60, (const char *) data_ov001_021a7e70,
                                (const char *) data_ov001_021a7e80);
            func_ov001_021870b0(param_1, obj, (const char *) data_ov001_021a7e90);
            func_ov001_0219b2e8(obj->mUnk_304, data_ov001_021a7ea0);
            obj->mUnk_234 = 1;
            if (i == 0) {
                obj->mUnk_000.mUnk_02 |= data_ov001_021a65c0;
            } else if (i == 1) {
                obj->mUnk_000.mUnk_02 &= 0xfffffbff;
            }
        }
    }
}

void func_ov001_0218fa58(u32 param_1, u32 param_2) {
    func_ov001_02186368((void *) param_1, (Unk02188950 *) param_2);
    func_ov001_021861f4((void *) param_1, (Unk02188950 *) param_2, 0);
}

void func_ov001_0218fa20(void) {
    u32 v4 = 0x21au;
    u32 v6 = 0x216u;
    void *v8 = &func_ov001_02185fb0;
    void *v9 = &func_ov001_02185f04;
    void *v10 = &func_ov001_021860cc;
    u32 v12 = (u32) func_ov001_0219b510(v8, v9, v10, (u32) 0x2u, (u16) ((u32) 0x1u), (u16) (v4), (u16) (v6));
}

void *func_ov001_0218fa04(void) {
    return (void *) func_0209bf1c(func_ov001_0218fa78, func_ov001_0218fa58, func_ov001_02187098);
}

void *func_ov001_0218f9ec(void) {
    return (void *) func_0209bf48(func_ov001_0218fbe0, func_ov001_0218fb24, 0);
}

void *func_ov001_0218f9d4(void) {
    return (void *) func_0209bf48(func_ov001_0218fcc4, func_ov001_0218fc4c, 0);
}
