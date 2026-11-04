#include "01/code_0218820c.h"
#include "01/code_0218f9d4.h"

#include "01/code_02185ef4.h"
#include "01/code_0218f000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0208b6b0.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bef0.h"
#include "01/code_0218155c.h"
#include "01/code_02188158.h"
#include "01/code_02188218.h"
#include "01/code_0219b250.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a126c.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_02109110.h"
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

void func_ov001_02192890(Unk02188950 *a) {
    a->mUnk_000.mUnk_94 = HeapAlloc((void *) GetHeap(func_020364e8()), 0x44);
    func_02109110((Unk0210bfbc *) (a->mUnk_000.mUnk_94), (u32) (0xc), (Vec3 *) (&a->mUnk_000.mPos));
    a->mUnk_000.mUnk_70 = data_0217cbec[0x14];
}

void func_ov001_02192878(Unk02188950 *a) {
    a->mUnk_2d8 = 2;
    func_ov001_02188200(a, func_ov001_02192878);
}

void func_ov001_021927c0(Unk02188950 *a) {
    if (a->mTimer > 0) {
        a->mUnk_2d8 = 2;
        func_ov001_02188200(a, func_ov001_021927c0);
        return;
    }
    a->mUnk_000.mUnk_10.x = ((s64) a->mPrm->mUnk_144 * data_0215d4b4[(u16) a->mMoveAngle >> 4 << 1]) >> 12;
    a->mUnk_000.mUnk_10.y = 0;
    a->mUnk_000.mUnk_10.z = ((s64) a->mPrm->mUnk_144 * data_0215d4b4[((u16) a->mMoveAngle >> 4 << 1) + 1]) >> 12;
    a->mUnk_2d8 = 0xd;
    func_ov001_02188200(a, func_ov001_021927c0);
    func_02073fb0(a->mUnk_000.mUnk_78 & 0x3fffffe0, 0x1000);
}

void func_ov001_02192794(int a) {
    *(u32 *) (a + 0x2d8) = 0xb;
    func_ov001_02188200((Unk02188950 *) (a), func_ov001_02192878);
    *(u32 *) (a + 0x78) = *(u32 *) (a + 0x78) | (*(u32 *) &data_ov001_021a65d4);
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
        obj = NULL;
    }
    other = func_0207a974((u16) data_021759c0->mUnk_62);
    if (obj->mUnk_0a8 == 4) {
        a0 = obj->mPrm;
        ang = AngleFromPair(other->mUnk_80.z - obj->mUnk_000.mPos.z, other->mUnk_80.x - obj->mUnk_000.mPos.x) -
              a0->mUnk_26c;
    } else {
        a0 = obj->mPrm;
        ang = a0->mUnk_26c +
              AngleFromPair(other->mUnk_80.z - obj->mUnk_000.mPos.z, other->mUnk_80.x - obj->mUnk_000.mPos.x);
    }
    idx = (ang >> 4) * 2;
    pos.x = obj->mUnk_000.mPos.x + (s32) (((s64) a0->mUnk_270 * data_0215d4b4[idx + 1]) >> 12);
    pos.y = obj->mUnk_000.mPos.y;
    pos.z = obj->mUnk_000.mPos.z + (s32) (((s64) obj->mPrm->mUnk_270 * data_0215d4b4[idx]) >> 12);
    SetAnglePointAndMoveAnglePoint(obj, &pos);
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
        objB = NULL;
    }
    if (data_021759c0->mUnk_08 == 4) {
        obj = func_ov001_02181b68((u16) (data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0));
    } else {
        obj = NULL;
    }
    if (data_021759c0->mUnk_08 == 4) {
        objC = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        objC = NULL;
    }
    a.x = (s32) (((s64) objB->mPrm->mUnk_274 * data_0215d4b4[((u16) objB->mAngle >> 4) * 2]) >> 12);
    a.y = objB->mUnk_000.mPos.y;
    a.z = (s32) (((s64) objB->mPrm->mUnk_274 * data_0215d4b4[((u16) objB->mAngle >> 4) * 2 + 1]) >> 12);
    b.x = -(s32) (((s64) objB->mPrm->mUnk_278 * data_0215d4b4[((u16) objB->mAngle >> 4) * 2 + 1]) >> 12);
    b.y = objB->mUnk_000.mPos.y;
    b.z = (s32) (((s64) objB->mPrm->mUnk_278 * data_0215d4b4[((u16) objB->mAngle >> 4) * 2]) >> 12);
    c.x = (s32) (((s64) objB->mPrm->mUnk_278 * data_0215d4b4[((u16) objB->mAngle >> 4) * 2 + 1]) >> 12);
    c.y = objB->mUnk_000.mPos.y;
    c.z = -(s32) (((s64) objB->mPrm->mUnk_278 * data_0215d4b4[((u16) objB->mAngle >> 4) * 2]) >> 12);
    SetAnglePoint(obj, &a);
    SetAnglePoint(objC, &a);
    SetMoveAnglePoint(obj, &b);
    SetMoveAnglePoint(objC, &c);
}

void func_ov001_0219246c(Unk02188950 *a) {
    a->mUnk_0a8 = 0;
    func_ov001_021881f4(a, (UnkFunc *) &func_ov001_0218fee0);
    func_ov001_021884f0(a, 0, 0, 0, (u32) (0), (u32) (0), (u32) (0));
    func_ov001_02188644(a, (0x0002a000u), 0, (0x00007000u), (u32) (((u32) 0x00026000u)), (u32) (((u32) 0x00001000u)),
                        (u32) (((u32) 0x00022000u)));
    return;
}

void func_ov001_021923e0(Unk02188950 *a) {
    a->mUnk_0a8 = 1;
    func_ov001_021881f4(a, (UnkFunc *) &func_ov001_0218fd20);
    func_ov001_02188484(a, (0xffffc000u), (0x0001e000u), (0xffff5000u), (u32) (((u32) 0x00002000u)),
                        (u32) (((u32) 0x00024000u)), (u32) (((u32) 0x00028000u)), (u32) (((u32) 0x00011000u)),
                        (u32) (((u32) 0x00002000u)));
    func_ov001_021885d4(a, (0xffff8000u), 0, (0xffffa000u), (u32) (((u32) 0x00002000u)), (u32) (((u32) 0x00020000u)),
                        (u32) (((u32) 0x00001000u)), (u32) (((u32) 0x00014000u)), (u32) (((u32) 0x00002000u)));
    return;
}

void func_ov001_02192358(Unk02188950 *a) {
    a->mUnk_0a8 = 1;
    func_ov001_021881f4(a, (UnkFunc *) &func_ov001_0218fd20);
    func_ov001_02188484(a, (0xffffc000u), (0x00028000u), (0xffff5000u), (u32) (((u32) 0x00001000u)),
                        (u32) (((u32) 0x00024000u)), (u32) (((u32) 0x00028000u)), (u32) (((u32) 0x00011000u)),
                        (u32) (((u32) 0x00001000u)));
    func_ov001_021885d4(a, (0xffff8000u), 0, (0xffffa000u), (u32) (((u32) 0x00000800u)), (u32) (((u32) 0x00020000u)),
                        (u32) (((u32) 0x00001000u)), (u32) (((u32) 0x00014000u)), (u32) (((u32) 0x00001000u)));
    return;
}

void func_ov001_021922e0(Unk02188950 *a) {
    a->mUnk_0a8 = 2;
    func_ov001_021881f4(a, (UnkFunc *) &func_ov001_0218fee0);
    func_ov001_02188484(a, (0x00015000u), (0x00028000u), (0x0001c000u), (u32) (((u32) 0x00001000u)),
                        (u32) (((u32) 0x00013000u)), (u32) (((u32) 0x00028000u)), (u32) (((u32) 0x00028000u)),
                        (u32) (((u32) 0x00001000u)));
    func_ov001_021885d4(a, (0x00012000u), 0, (0x0001c000u), (u32) (((u32) 0x00001000u)), (u32) (((u32) 0x00011000u)),
                        (u32) (((u32) 0x00001000u)), (u32) (((u32) 0x00024000u)), (u32) (((u32) 0x00001000u)));
    return;
}

void func_ov001_0219226c(Unk02188950 *a) {
    a->mUnk_0a8 = 3;
    func_ov001_021881f4(a, (UnkFunc *) &func_ov001_0218fee0);
    func_ov001_02188484(a, 0, (u32) (((u32) 0x00028000u)), (u32) (((u32) 0xfffd1000u)), (u32) (((u32) 0x00002000u)),
                        (u32) (((u32) 0x0001b99au)), (u32) (((u32) 0x00028000u)), (u32) (((u32) 0x0002f000u)),
                        (u32) (((u32) 0x00002000u)));
    func_ov001_021885d4(a, 0, (u32) (0), (u32) (((u32) 0xfffd1000u)), (u32) (((u32) 0x00002000u)),
                        (u32) (((u32) 0x0001b99au)), (u32) (((u32) 0x00001000u)), (u32) (((u32) 0x0002f000u)),
                        (u32) (((u32) 0x00002000u)));
    return;
}

void func_ov001_021921e4(Unk02188950 *a) {
    a->mUnk_0a8 = 1;
    func_ov001_021881f4(a, (UnkFunc *) &func_ov001_0218fee0);
    func_ov001_02188484(a, (0xffffc000u), (0x00028000u), (0xffff5000u), (u32) (((u32) 0x00002000u)),
                        (u32) (((u32) 0x00024000u)), (u32) (((u32) 0x00028000u)), (u32) (((u32) 0x00011000u)),
                        (u32) (((u32) 0x00001000u)));
    func_ov001_021885d4(a, (0xffff8000u), 0, (0xffffa000u), (u32) (((u32) 0x00001000u)), (u32) (((u32) 0x00020000u)),
                        (u32) (((u32) 0x00001000u)), (u32) (((u32) 0x00014000u)), (u32) (((u32) 0x00001000u)));
    return;
}

void func_ov001_02192174(Unk02188950 *a) {
    Vec3 pos = {0, 0, 0};

    func_ov001_02187218(a, 1, NULL);
    func_ov001_02188d64(a, (s32) (a->mPrm->mUnk_27c), (s32) (a->mPrm->mUnk_280));
    SetVelocity(a, &pos);
    func_ov001_02188c0c(a, a->mPrm->mUnk_2c8, 0x270f000);
    func_ov001_02188cd8(a, (s32) (a->mPrm->mUnk_2cc), 0x270f000);
}

void func_ov001_021920dc(Unk02188950 *a) {
    func_ov001_02187218(a, 1, NULL);
    func_ov001_02188d64(a, a->mPrm->mUnk_254, a->mPrm->mUnk_258);
    func_ov001_02188c0c(a, a->mPrm->mUnk_2c8, 0x270f000);
    func_ov001_02188cd8(a, a->mPrm->mUnk_2cc, 0x270f000);
    func_ov001_021875c0(a, 0, 0x44cd, 0x400, 0x42d, 0);
    func_ov001_021875c0(a, 0, 0x44cd, 0x400, 0x42e, 0);
}

void func_ov001_02192080(Unk02188950 *a) {
    func_ov001_02187218(a, 1, NULL);
    func_ov001_02188d64(a, a->mPrm->mUnk_28c, a->mPrm->mUnk_290);
    func_ov001_02188c0c(a, a->mPrm->mUnk_2c8, 0x270f000);
    func_ov001_02188cd8(a, a->mPrm->mUnk_2cc, 0x270f000);
}

void func_ov001_02191fe8(Unk02188950 *a) {
    func_ov001_02187218(a, 1, NULL);
    func_ov001_02188d64(a, a->mPrm->mUnk_294, a->mPrm->mUnk_298);
    func_ov001_02188c0c(a, a->mPrm->mUnk_2c8, 0x270f000);
    func_ov001_02188cd8(a, a->mPrm->mUnk_2cc, 0x270f000);
    func_ov001_021875c0(a, 0, 0x44cd, 0x400, 0x42d, 0);
    func_ov001_021875c0(a, 0, 0x44cd, 0x400, 0x42e, 0);
}

void func_ov001_02191f70(Unk02188950 *a) {
    func_ov001_02187218(a, 3, NULL);
    func_ov001_02188d30(a, a->mPrm->mUnk_2ac, a->mPrm->mUnk_2b0, func_ov001_02192080);
    func_ov001_02188c0c(a, a->mPrm->mUnk_2c8, 0x270f000);
    func_ov001_02188cd8(a, a->mPrm->mUnk_2cc, 0x270f000);
    func_ov001_021922e0(a);
    func_020d2774(&a->mUnk_000, (u32) (0x215));
}

void func_ov001_02191ecc(Unk02188950 *a) {
    func_ov001_02187218(a, 3, NULL);
    func_ov001_02188d30(a, a->mPrm->mUnk_2b4, a->mPrm->mUnk_2b8, func_ov001_02191fe8);
    func_ov001_02188c0c(a, a->mPrm->mUnk_2c8, 0x270f000);
    func_ov001_02188cd8(a, a->mPrm->mUnk_2cc, 0x270f000);
    func_ov001_02192358(a);
    func_ov001_021875c0(a, 0, 0x44cd, 0x2000, 0x42d, 0);
    func_ov001_021875c0(a, 0, 0x44cd, 0x2000, 0x42e, 0);
}

void func_ov001_02191e90(Unk02188950 *a) {
    func_ov001_02187218(a, 1, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(a, (s32) (a->mPrm->mUnk_28c), (s32) (a->mPrm->mUnk_290));
    func_ov001_02188c90(a);
    func_ov001_02188cec(a, 0);
}

void func_ov001_02191e1c(Unk02188950 *a) {
    func_ov001_02187218(a, 1, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(a, (s32) (a->mPrm->mUnk_294), (s32) (a->mPrm->mUnk_298));
    func_ov001_02188c90(a);
    func_ov001_02188cec(a, 0);
    func_ov001_021875c0(a, (u32) 0, (u32) (((u32) 0x000044cdu)), (u32) (((u32) 0x00000400u)),
                        (u32) (((u32) 0x0000042du)), (u32) 0);
    func_ov001_021875c0(a, (u32) 0, (u32) (((u32) 0x000044cdu)), (u32) (((u32) 0x00000400u)),
                        (u32) (((u32) 0x0000042eu)), (u32) 0);
}

void func_ov001_02191de0(Unk02188950 *a) {
    Vec3 v = {0, 0, 0};
    func_ov001_02188e88(a);
    func_ov001_02188c90(a);
    func_ov001_02188cec(a, 0);
    SetVelocity(a, &v);
    a->mUnk_2c0 = 1;
}

u32 func_ov001_02191dc8(Unk02188950 *a) {
    func_020d275c(&a->mUnk_000, (u32) (((u32) 0x0000021du)));
    return 0;
}

void func_ov001_02191cf4(Unk02188950 *a) {
    Vec3 v = {0, 0, 0};
    v.y = -a->mPrm->mUnk_2a4;
    func_ov001_02187218(a, 3, (s32(*)(Unk02188950 *)) func_ov001_02191dc8);
    func_ov001_02188d64(a, a->mPrm->mUnk_29c, a->mPrm->mUnk_2a0);
    SetVelocity(a, &v);
    func_ov001_02188c0c(a, a->mPrm->mUnk_2c8, 0x270f000);
    func_ov001_02188cd8(a, a->mPrm->mUnk_2cc, 0x270f000);
    func_ov001_021875c0(a, 0, 0x44cd, 0x400, 0x42d, 0);
    func_ov001_021875c0(a, 0, 0x44cd, 0x400, 0x42e, 0);
    func_ov001_02188db8(a, func_ov001_02191de0);
    a->mUnk_2c0 = 0;
}

void func_ov001_02191c14(Unk02188950 *a) {
    Vec3 v = {0, 0, 0};
    v.y = a->mPrm->mUnk_2a4;
    func_ov001_02187218(a, 3, (s32(*)(Unk02188950 *)) func_ov001_02191dc8);
    func_ov001_02188d64(a, a->mPrm->mUnk_29c, a->mPrm->mUnk_2a0);
    SetVelocity(a, &v);
    func_ov001_02188c0c(a, a->mPrm->mUnk_2c8, 0x270f000);
    func_ov001_02188cd8(a, a->mPrm->mUnk_2cc, 0x270f000);
    func_ov001_02188e24(a, a->mPrm->mUnk_2a8, func_ov001_02191cf4);
    func_ov001_021875c0(a, 0, 0x44cd, 0x400, 0x42d, 0);
    func_ov001_021875c0(a, 0, 0x44cd, 0x400, 0x42e, 0);
    a->mUnk_2c0 = 0;
}

void func_ov001_02191bc0(Unk02188950 *a) {
    func_ov001_02187218(a, 3, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d30(a, (s32) (a->mPrm->mUnk_2ac), (s32) (a->mPrm->mUnk_2b0), (UnkFunc *) &func_ov001_02191e90);
    func_ov001_02188cec(a, 0);
    func_ov001_02188c90(a);
    func_ov001_021922e0(a);
    func_020d2774(&a->mUnk_000, (u32) (((u32) 0x00000215u)));
}

void func_ov001_02191b40(Unk02188950 *a) {
    func_ov001_02187218(a, 3, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d30(a, (s32) (a->mPrm->mUnk_2b4), (s32) (a->mPrm->mUnk_2b8), (UnkFunc *) &func_ov001_02191e1c);
    func_ov001_02188cec(a, 0);
    func_ov001_02188c90(a);
    func_ov001_02192358(a);
    func_ov001_021875c0(a, (u32) 0, (u32) (((u32) 0x000044cdu)), (u32) (((u32) 0x00002000u)),
                        (u32) (((u32) 0x0000042du)), (u32) 0);
    func_ov001_021875c0(a, (u32) 0, (u32) (((u32) 0x000044cdu)), (u32) (((u32) 0x00002000u)),
                        (u32) (((u32) 0x0000042eu)), (u32) 0);
}

void func_ov001_02191adc(Unk02188950 *a) {
    Vec3 v = {0, 0, 0};
    func_ov001_02187218(a, 3, NULL);
    func_ov001_02188d64(a, a->mPrm->mUnk_1c0, a->mPrm->mUnk_1c4);
    func_ov001_02188c90(a);
    func_ov001_02188cec(a, 0);
    SetVelocity(a, &v);
    func_ov001_02188e24(a, a->mPrm->mUnk_1c8, NULL);
}

void func_ov001_02191a3c(Unk02188950 *a) {
    Vec3 v = {0, 0, 0};
    v.y = a->mPrm->mUnk_1bc;
    func_ov001_02187218(a, 3, NULL);
    func_ov001_02188d64(a, a->mPrm->mUnk_1a4, a->mPrm->mUnk_1a8);
    SetVelocity(a, &v);
    func_ov001_02188b78(a, a->mPrm->mUnk_1b4, a->mPrm->mUnk_1b8);
    func_ov001_02188cd8(a, a->mPrm->mUnk_1ac, a->mPrm->mUnk_1b0);
    func_ov001_02188db8(a, func_ov001_02191adc);
    a->mUnk_2c0 = 1;
}

void func_ov001_02191980(Unk02188950 *a) {
    Vec3 v = {0, 0, 0};
    func_ov001_02187218(a, 3, NULL);
    func_ov001_02188d64(a, a->mPrm->mUnk_184, a->mPrm->mUnk_188);
    func_ov001_02188b78(a, a->mPrm->mUnk_194, a->mPrm->mUnk_198);
    func_ov001_02188cd8(a, a->mPrm->mUnk_18c, a->mPrm->mUnk_190);
    SetVelocity(a, &v);
    func_ov001_02188de0(a, a->mPrm->mUnk_19c, 0, &a->mMoveAnglePoint, func_ov001_02191a3c);
    func_ov001_02188e24(a, a->mPrm->mUnk_0ec, func_ov001_02191a3c);
    a->mUnk_2c0 = 0;
}

void func_ov001_021918c8(Unk02188950 *a) {
    Vec3 v = {0, 0, 0};
    v.y = a->mPrm->mUnk_17c;
    func_ov001_021924cc();
    func_ov001_02187218(a, 3, NULL);
    func_ov001_02188d64(a, a->mPrm->mUnk_164, a->mPrm->mUnk_168);
    SetVelocity(a, &v);
    func_ov001_02188b78(a, a->mPrm->mUnk_174, a->mPrm->mUnk_178);
    SetAnglePointAndMoveAnglePoint(a, &a->mMoveAnglePoint);
    func_ov001_02188cd8(a, a->mPrm->mUnk_16c, a->mPrm->mUnk_170);
    func_ov001_02188e24(a, a->mPrm->mUnk_180, func_ov001_02191980);
}

int func_ov001_02191888(Unk02188950 *a) {
    if (a->mSpeed > 0) {
        func_020d275c(&a->mUnk_000, (u32) (0x219));
    } else {
        func_ov001_02187af4(a);
        func_ov001_02188200(a, func_ov001_02192878);
        a->mUnk_158 = NULL;
    }
    return 0;
}

s32 func_ov001_02191870(Unk02188950 *a) {
    func_020d275c(&a->mUnk_000, (u32) (0x219));
    return 0;
}

void func_ov001_021917d0(Unk02188950 *a) {
    func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(a, 3, (s32(*)(Unk02188950 *))(func_ov001_02191888));
    func_ov001_02188d64(a, a->mPrm->mUnk_148, a->mPrm->mUnk_14c);
    func_ov001_02188cd8(a, a->mPrm->mUnk_150, a->mPrm->mUnk_154);
    func_ov001_02188e24(a, a->mPrm->mUnk_160, func_ov001_021918c8);
    func_ov001_021875c0(a, (u32) (0x1000), (u32) (0), (u32) (0x2000), (u32) (0x433), (u32) (0));
}

void func_ov001_021916e0(Unk02188950 *a) {
    Unk0206bcb0 *v1 = func_0207a974((u16) data_021759c0->mUnk_62);
    Vec3 local = {0, 0, 0};

    if ((a->mUnk_000.mFlags & 0x400) == 0) {
        a->mMoveAngle = a->mAngle + 0x4000;
    } else {
        a->mMoveAngle = a->mAngle - 0x4000;
    }
    func_ov001_02187218(a, 3, (s32(*)(Unk02188950 *))(func_ov001_02191870));
    func_ov001_02188d64(a, a->mPrm->mUnk_128, a->mPrm->mUnk_12c);
    func_ov001_02188cd8(a, a->mPrm->mUnk_130, a->mPrm->mUnk_134);
    func_ov001_021889c8(a);
    func_ov001_02188e24(a, a->mPrm->mUnk_140, func_ov001_021917d0);
    func_ov001_02188200(a, func_ov001_021927c0);
    func_ov001_021875c0(a, (u32) (0x1000), (u32) (0), (u32) (0x2000), (u32) (0x433), (u32) (0));
}

void func_ov001_02191618(Unk02188950 *a) {
    Vec3 local = {0, 0, 0};

    func_ov001_02187218(a, 3, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(a, a->mPrm->mUnk_118, a->mPrm->mUnk_11c);
    func_ov001_02188e24(a, a->mPrm->mUnk_120, func_ov001_021916e0);
    func_ov001_02188c90(a);
    func_ov001_02188cec(a, 0);
    SetVelocity(a, &local);
    func_ov001_02188200(a, func_ov001_02192878);
    func_02073fb0(a->mUnk_000.mUnk_78 & 0x3fffffe0, 0x1000);
    func_ov001_02187518(a, (u32) (0x1000), (u32) (0), (u32) (0x2000), (u32) (0x414), (u32) (0));
    func_ov001_02187518(a, (u32) (0x1000), (u32) (0), (u32) (0x2000), (u32) (0x415), (u32) (0));
    func_020d2774(&a->mUnk_000, (u32) (0x218));
}

void func_ov001_02191550(Unk02188950 *a) {
    Vec3 local = {0, 0, 0};

    func_ov001_02187218(a, 3, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(a, a->mPrm->mUnk_10c, a->mPrm->mUnk_110);
    func_ov001_02188e24(a, a->mPrm->mUnk_114, func_ov001_021918c8);
    func_ov001_02188c90(a);
    func_ov001_02188cec(a, 0);
    SetVelocity(a, &local);
    func_ov001_02188200(a, func_ov001_02192878);
    func_02073fb0(a->mUnk_000.mUnk_78 & 0x3fffffe0, 0x1000);
    func_ov001_02187518(a, (u32) (0x1000), (u32) (0), (u32) (0x2000), (u32) (0x414), (u32) (0));
    func_ov001_02187518(a, (u32) (0x1000), (u32) (0), (u32) (0x2000), (u32) (0x415), (u32) (0));
    func_020d2774(&a->mUnk_000, (u32) (0x218));
}

void func_ov001_02191488(Unk02188950 *a) {
    Vec3 local = {0, 0, 0};

    local.y = a->mPrm->mUnk_108;
    func_ov001_02187218(a, 3, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(a, a->mPrm->mUnk_0f0, a->mPrm->mUnk_0f4);
    SetVelocity(a, &local);
    func_ov001_02188c90(a);
    func_ov001_02188cd8(a, a->mPrm->mUnk_0f8, a->mPrm->mUnk_0fc);
    if (func_ov001_02188220(
            data_021759c0->mUnk_08 == 4
                ? func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 2))
                : 0) >= 1) {
        func_ov001_02188db8(a, func_ov001_02191618);
    } else {
        func_ov001_02188db8(a, func_ov001_02191550);
    }
    a->mUnk_2c0 = 1;
    func_ov001_02188200(a, func_ov001_02192794);
}

s32 func_ov001_02191470(Unk02188950 *a) {
    func_020d275c(&a->mUnk_000, (u32) (0x21c));
    return 0;
}

void func_ov001_021913b8(Unk02188950 *a) {
    Unk0206bcb0 *v1 = func_0207a974((u16) data_021759c0->mUnk_62);
    Vec3 local = {0, 0, 0};

    func_ov001_02187e78(a);
    func_ov001_02187218(a, 3, (s32(*)(Unk02188950 *))(func_ov001_02191470));
    func_ov001_02188d64(a, a->mPrm->mUnk_0d0, a->mPrm->mUnk_0d4);
    SetVelocity(a, &local);
    func_ov001_02188c90(a);
    func_ov001_02188cd8(a, a->mPrm->mUnk_0d8, a->mPrm->mUnk_0dc);
    func_ov001_02188de0(a, a->mPrm->mUnk_0e8, 0, &v1->mUnk_80, func_ov001_02191488);
    func_ov001_02188e24(a, a->mPrm->mUnk_0ec, func_ov001_02191488);
    a->mUnk_2c0 = 0;
}

void func_ov001_02191318(Unk02188950 *a) {
    Unk0206bcb0 *v1 = func_0207a974((u16) data_021759c0->mUnk_62);
    Vec3 local = {0, 0, 0};

    local.y = a->mPrm->mUnk_0a4;
    func_ov001_02187218(a, 3, (s32(*)(Unk02188950 *))(func_ov001_02191470));
    func_ov001_02188d64(a, a->mPrm->mUnk_08c, a->mPrm->mUnk_090);
    SetVelocity(a, &local);
    func_ov001_02188c90(a);
    SetAnglePointAndMoveAnglePoint(a, &v1->mUnk_80);
    func_ov001_02188cd8(a, a->mPrm->mUnk_094, a->mPrm->mUnk_098);
    func_ov001_02188e24(a, a->mPrm->mUnk_0a8, func_ov001_021913b8);
}

void func_ov001_02191258(Unk02188950 *a) {
    Vec3 local = {0, 0, 0};

    func_ov001_02187218(a, 3, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(a, a->mPrm->mUnk_210, a->mPrm->mUnk_214);
    func_ov001_02188e24(a, a->mPrm->mUnk_218, NULL);
    func_ov001_02188c90(a);
    func_ov001_02188cec(a, 0);
    SetVelocity(a, &local);
    func_ov001_02188200(a, func_ov001_02192878);
    func_02073fb0(a->mUnk_000.mUnk_78 & 0x3fffffe0, 0x1000);
    func_ov001_02187518(a, (u32) (0x1000), (u32) (0), (u32) (0x2000), (u32) (0x414), (u32) (0));
    func_ov001_02187518(a, (u32) (0x1000), (u32) (0), (u32) (0x2000), (u32) (0x415), (u32) (0));
    func_020d2774(&a->mUnk_000, (u32) (0x218));
}

void func_ov001_021911a8(Unk02188950 *a) {
    Unk0206bcb0 *v1 = func_0207a974((u16) data_021759c0->mUnk_62);
    Vec3 local = {0, 0, 0};

    local.y = a->mPrm->mUnk_1e4;
    func_ov001_02187218(a, 3, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(a, a->mPrm->mUnk_1cc, a->mPrm->mUnk_1d0);
    SetVelocity(a, &local);
    func_ov001_02188c90(a);
    SetAnglePointAndMoveAnglePoint(a, &v1->mUnk_80);
    func_ov001_02188cd8(a, a->mPrm->mUnk_1d4, a->mPrm->mUnk_1d8);
    func_ov001_02188db8(a, func_ov001_02191258);
    func_ov001_02188200(a, func_ov001_02192794);
}

void func_ov001_0219116c(Unk02188950 *a) {
    func_ov001_02187218(a, 7, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d30(a, (s32) (a->mPrm->mUnk_234), (s32) (a->mPrm->mUnk_238), (UnkFunc *) &func_ov001_021918c8);
    func_ov001_021922e0(a);
}

void func_ov001_02191130(Unk02188950 *a) {
    func_ov001_02187218(a, 7, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d30(a, (s32) (a->mPrm->mUnk_22c), (s32) (a->mPrm->mUnk_230), (UnkFunc *) &func_ov001_0219116c);
    func_ov001_021921e4(a);
}

s32 func_ov001_021910fc(Unk02188950 *a) {
    if ((a->mUnk_2c8 & 0x001e34ef) != 0) {
        func_020d2774(&a->mUnk_000, (u32) 0x218);
        a->mUnk_158 = NULL;
    }
    return 0;
}

s32 func_ov001_021910d4(Unk02188950 *a) {
    if (a->mUnk_2c8 & 0x1e34ef) {
        a->mUnk_158 = (s32(*)(Unk02188950 *)) func_ov001_021910fc;
    }
    return 0;
}

void func_ov001_02191064(Unk02188950 *a) {
    func_ov001_02187218(a, 7, &func_ov001_021910d4);
    func_ov001_02188d30(a, (s32) (a->mPrm->mUnk_21c), (s32) (a->mPrm->mUnk_220), func_ov001_02191130);
    func_ov001_02188c90(a);
    func_ov001_02188cec(a, 0);
    a->mUnk_2c0 = 1;
    func_ov001_0219226c(a);
    func_ov001_02188200(a, func_ov001_02192878);
    func_020d2774(&a->mUnk_000, (u32) (((u32) 0x00000216u)));
}

void func_ov001_02191034(Unk02188950 *a) {
    func_ov001_02187218(a, 7, NULL);
    func_ov001_02188d64(a, a->mPrm->mUnk_24c, a->mPrm->mUnk_250);
}

void func_ov001_02190fc4(Unk02188950 *a) {
    func_ov001_02187218(a, 7, &func_ov001_021910d4);
    func_ov001_02188d30(a, (s32) (a->mPrm->mUnk_23c), (s32) (a->mPrm->mUnk_240), (UnkFunc *) &func_ov001_02191034);
    func_ov001_02188c90(a);
    func_ov001_02188cec(a, 0);
    a->mUnk_2c0 = 1;
    func_ov001_0219226c(a);
    func_ov001_02188200(a, func_ov001_02192878);
    func_020d2774(&a->mUnk_000, (u32) (((u32) 0x00000216u)));
}

void func_ov001_02190ee0(Unk02188950 *a) {
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02187af4(a);
    func_ov001_021875c0(a, (u32) 0, (u32) 0x1000, (u32) 0xffffdccd, (u32) 0x3ef, (u32) 0);
    func_ov001_021875c0(a, (u32) 0, (u32) 0x1000, (u32) 0xffffdccd, (u32) 0x3ee, (u32) 0);
    func_ov001_021875c0(a, (u32) 0, (u32) 0x1000, (u32) 0xffffdccd, (u32) 0x3f0, (u32) 0);
    func_ov001_021875c0(a, (u32) 0, (u32) 0x1000, (u32) 0xffffdccd, (u32) 0x3f1, (u32) 0);
    func_ov001_021875c0(a, (u32) 0, (u32) 0x1000, (u32) 0xffffdccd, (u32) 0x3f2, (u32) 0);
    {
        Unk02190ee0 local = data_ov001_021a7de8;

        local.mUnk_04 = &a->mUnk_000.mPos;
        local.mUnk_0c = func_020d4ef4(&a->mUnk_000.mPos);
        func_0210b734(&local, (u32) (func_02108e7c()));
    }
    a->mUnk_000.mFlags |= data_ov001_021a65c8;
    a->mUnk_000.mFlags |= data_ov001_021a65cc;
    a->mUnk_000.mFlags |= data_ov001_021a65d0;
}

void func_ov001_02190eb0(Unk02188950 *a) {
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(a, (s32) (a->mPrm->mUnk_070), (s32) (a->mPrm->mUnk_074));
    func_ov001_02188e24(a, 0x3c, &func_ov001_02190ee0);
}

void func_ov001_02190df8(Unk02188950 *a) {
    if (a->mUnk_0a8 == 1) {
        func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
        func_ov001_02188d64(a, (s32) (a->mPrm->mUnk_078), (s32) (a->mPrm->mUnk_07c));
        func_ov001_02188c90(a);
        func_ov001_02188cec(a, 0);
        return;
    }
    func_ov001_02187218(a, 3, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d30(a, (s32) (a->mPrm->mUnk_2b4), (s32) (a->mPrm->mUnk_2b8), (UnkFunc *) &func_ov001_02190df8);
    func_ov001_02188c90(a);
    func_ov001_02188cec(a, 0);
    func_ov001_02192358(a);
    func_ov001_021875c0(a, (u32) 0, (u32) (((u32) 0x000044cdu)), (u32) (((u32) 0x00002000u)),
                        (u32) (((u32) 0x0000042du)), (u32) 0);
    func_ov001_021875c0(a, (u32) 0, (u32) (((u32) 0x000044cdu)), (u32) (((u32) 0x00002000u)),
                        (u32) (((u32) 0x0000042eu)), (u32) 0);
}

void func_ov001_02190df0(void) {
    func_ov001_021882b8();
}

s32 func_ov001_02190d78(Unk02188950 *a) {
    Unk02188950 *v1;
    Unk02188950 *v2;

    v1 = data_021759c0->mUnk_08 == 4
             ? func_ov001_02181b68((u16) (data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0))
             : 0;
    v2 = data_021759c0->mUnk_08 == 4
             ? func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1))
             : 0;
    if (func_ov001_021871f8(v1, 3) != 0 && func_ov001_021871f8(v2, 3) != 0) {
        func_ov001_02188e88(a);
    }
    return 0;
}

s32 func_ov001_02190d00(Unk02188950 *c) {
    Unk02188950 *a;
    Unk02188950 *b;

    a = (data_021759c0->mUnk_08 == 4
             ? func_ov001_02181b68((u16) (data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0))
             : 0);
    b = (data_021759c0->mUnk_08 == 4
             ? func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1))
             : 0);
    if (func_ov001_021871f8(a, 3) && func_ov001_021871f8(b, 3)) {
        func_ov001_02190c08(c);
    }
    return 0;
}

void func_ov001_02190c08(Unk02188950 *c) {
    Unk02188950 *a;
    Unk02188950 *b;

    if (func_ov001_0218820c(c)) {
        func_ov001_02187218(c, 3, func_ov001_02190d00);
        func_ov001_02188c90(c);
        a = (data_021759c0->mUnk_08 == 4
                 ? func_ov001_02181b68((u16) (data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0))
                 : 0);
        b = (data_021759c0->mUnk_08 == 4
                 ? func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1))
                 : 0);
        func_ov001_021911a8(a);
        func_ov001_021911a8(b);
    } else {
        func_ov001_02187218(c, 3, func_ov001_02190d78);
        func_ov001_02188c90(c);
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

s32 func_ov001_02190b58(Unk02188950 *c) {
    Unk02188950 *a;
    Unk02188950 *b;

    a = (data_021759c0->mUnk_08 == 4
             ? func_ov001_02181b68((u16) (data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0))
             : 0);
    b = (data_021759c0->mUnk_08 == 4
             ? func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1))
             : 0);
    SetAnglePointAndMoveAnglePoint(c, &func_0207a974((u16) data_021759c0->mUnk_62)->mUnk_80);
    func_ov001_021924cc();
    if (func_ov001_021871f8(a, 3) && func_ov001_021871f8(b, 3)) {
        func_ov001_02188218(c, (s32) ((u16) c->mPrm->mUnk_1ec));
        func_ov001_02190c08(c);
    }
    return 0;
}

void func_ov001_02190acc(Unk02188950 *c) {
    Unk02188950 *a;
    Unk02188950 *b;

    func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(c, 3, func_ov001_02190b58);
    func_ov001_02188c90(c);
    a = (data_021759c0->mUnk_08 == 4
             ? func_ov001_02181b68((u16) (data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0))
             : 0);
    b = (data_021759c0->mUnk_08 == 4
             ? func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1))
             : 0);
    func_ov001_02191bc0(a);
    func_ov001_02191bc0(b);
}

s32 func_ov001_02190a20(Unk02188950 *c) {
    Unk02188950 *a;
    Unk02188950 *b;

    a = (data_021759c0->mUnk_08 == 4
             ? func_ov001_02181b68((u16) (data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0))
             : 0);
    b = (data_021759c0->mUnk_08 == 4
             ? func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1))
             : 0);
    SetAnglePointAndMoveAnglePoint(c, &func_0207a974((u16) data_021759c0->mUnk_62)->mUnk_80);
    func_ov001_021924cc();
    if (func_ov001_021871f8(a, 3) && func_ov001_021871f8(b, 3)) {
        c->mUnk_0a8 = c->mUnk_0a8 == 4 ? 5 : 4;
        func_ov001_02190948(c);
    }
    return 0;
}

void func_ov001_02190948(Unk02188950 *c) {
    Unk0206bcb0 *r4;
    Unk02188950 *a;
    Unk02188950 *b;

    if (func_ov001_0218820c(c)) {
        r4 = func_0207a974((u16) data_021759c0->mUnk_62);
        func_ov001_02187218(c, 3, func_ov001_02190a20);
        func_ov001_02188c48(c, c->mPrm->mUnk_2c4, 0x270f000);
        SetAnglePointAndMoveAnglePoint(c, &r4->mUnk_80);
        if (data_021759c0->mUnk_08 == 4) {
            a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
        } else {
            a = NULL;
        }
        if (data_021759c0->mUnk_08 == 4) {
            b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
        } else {
            b = NULL;
        }
        if (c->mUnk_0a8 == 4) {
            func_ov001_02191c14(a);
            func_ov001_021920dc(b);
        } else {
            func_ov001_021920dc(a);
            func_ov001_02191c14(b);
        }
    } else {
        func_ov001_02190acc(c);
    }
}

int func_ov001_021908a8(Unk02188950 *c) {
    Unk0206bcb0 *r4;
    Unk02188950 *a;
    Unk02188950 *b;

    if (data_021759c0->mUnk_08 == 4) {
        a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
    } else {
        a = NULL;
    }
    if (data_021759c0->mUnk_08 == 4) {
        b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        b = NULL;
    }
    r4 = func_0207a974((u16) data_021759c0->mUnk_62);
    SetAnglePointAndMoveAnglePoint(c, &r4->mUnk_80);
    func_ov001_021924cc();
    if (func_ov001_021871f8(a, 3) && func_ov001_021871f8(b, 3)) {
        func_ov001_02188218(c, 4);
        func_ov001_02190948(c);
    }
    return 0;
}

void func_ov001_0219081c(Unk02188950 *c) {
    Unk02188950 *a;
    Unk02188950 *b;

    func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(c, 3, func_ov001_021908a8);
    func_ov001_02188c90(c);
    if (data_021759c0->mUnk_08 == 4) {
        a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
    } else {
        a = NULL;
    }
    if (data_021759c0->mUnk_08 == 4) {
        b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        b = NULL;
    }
    func_ov001_02191b40(a);
    func_ov001_02191b40(b);
}

int func_ov001_0219079c(Unk02188950 *c) {
    Unk02188950 *a;
    Unk02188950 *b;

    if (data_021759c0->mUnk_08 == 4) {
        a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
    } else {
        a = NULL;
    }
    if (data_021759c0->mUnk_08 == 4) {
        b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        b = NULL;
    }
    func_ov001_02192694();
    func_ov001_021924cc();
    if (func_ov001_021871f8(a, 3) && func_ov001_021871f8(b, 3)) {
        func_ov001_02188e88(c);
    }
    return 0;
}

int func_ov001_02190688(Unk02188950 *c) {
    Unk0206bcb0 *r4;
    Unk02188950 *a;
    Unk02188950 *b;

    r4 = func_0207a974((u16) data_021759c0->mUnk_62);
    if (data_021759c0->mUnk_08 == 4) {
        a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
    } else {
        a = NULL;
    }
    if (data_021759c0->mUnk_08 == 4) {
        b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        b = NULL;
    }
    if (c->mUnk_0a8 == 4) {
        if (func_ov001_021871f8(a, 3)) {
            c->mUnk_0a8 = 5;
            func_ov001_02187218(c, 3, func_ov001_0219079c);
            func_ov001_02188c48(c, c->mPrm->mUnk_2c4, 0x270f000);
            SetAnglePointAndMoveAnglePoint(c, &r4->mUnk_80);
            func_ov001_02191ecc(a);
            func_ov001_02191f70(b);
        }
    } else if (func_ov001_021871f8(b, 3)) {
        c->mUnk_0a8 = 4;
        func_ov001_02187218(c, 3, func_ov001_0219079c);
        func_ov001_02188c48(c, c->mPrm->mUnk_2c4, 0x270f000);
        SetAnglePointAndMoveAnglePoint(c, &r4->mUnk_80);
        func_ov001_02191f70(a);
        func_ov001_02191ecc(b);
    }
    return 0;
}

void func_ov001_021905f8(Unk02188950 *c) {
    Unk02188950 *a;
    Unk02188950 *b;

    func_ov001_02187218(c, 3, func_ov001_02190688);
    func_ov001_02188c90(c);
    if (data_021759c0->mUnk_08 == 4) {
        a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
    } else {
        a = NULL;
    }
    if (data_021759c0->mUnk_08 == 4) {
        b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        b = NULL;
    }
    if (c->mUnk_0a8 == 4) {
        func_ov001_02191318(a);
        func_ov001_02191e1c(b);
    } else {
        func_ov001_02191e1c(a);
        func_ov001_02191318(b);
    }
}

int func_ov001_0219052c(Unk02188950 *c) {
    Unk02188950 *a;
    Unk02188950 *b;

    if (data_021759c0->mUnk_08 == 4) {
        a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
    } else {
        a = NULL;
    }
    if (data_021759c0->mUnk_08 == 4) {
        b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        b = NULL;
    }
    func_ov001_02192694();
    func_ov001_021924cc();
    if (func_ov001_021881a8(c, &c->mAnglePoint, 0, (s32) (c->mPrm->mUnk_2bc)) &&
        func_ov001_021881a8(a, &a->mMoveAnglePoint, (s32) (c->mPrm->mUnk_2c0), 0) &&
        func_ov001_021881a8(b, &b->mMoveAnglePoint, (s32) (c->mPrm->mUnk_2c0), 0)) {
        func_ov001_021905f8(c);
    }
    return 0;
}

void func_ov001_02190468(Unk02188950 *c) {
    Unk0206bcb0 *r4;
    Unk02188950 *a;
    Unk02188950 *b;

    r4 = func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(c, 3, func_ov001_0219052c);
    func_ov001_02188c48(c, c->mPrm->mUnk_2c4, 0x270f000);
    SetAnglePointAndMoveAnglePoint(c, &r4->mUnk_80);
    if (data_021759c0->mUnk_08 == 4) {
        a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
    } else {
        a = NULL;
    }
    if (data_021759c0->mUnk_08 == 4) {
        b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        b = NULL;
    }
    if (c->mUnk_0a8 == 4) {
        func_ov001_02192174(a);
        func_ov001_021920dc(b);
    } else {
        func_ov001_021920dc(a);
        func_ov001_02192174(b);
    }
}

int func_ov001_021903e0(Unk02188950 *c) {
    Unk02188950 *a;
    Unk02188950 *b;

    func_0207a974((u16) data_021759c0->mUnk_62);
    if (data_021759c0->mUnk_08 == 4) {
        a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
    } else {
        a = NULL;
    }
    if (data_021759c0->mUnk_08 == 4) {
        b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        b = NULL;
    }
    if (func_ov001_021871f8(a, 3) && func_ov001_021871f8(b, 3)) {
        func_ov001_02188e88(c);
    }
    return 0;
}

void func_ov001_02190328(Unk02188950 *c) {
    Unk02188950 *a;
    Unk02188950 *b;

    func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(c, 3, func_ov001_021903e0);
    func_ov001_02188c90(c);
    c->mUnk_0a8 = (c->mUnk_0a8 == 5) ? 4 : 5;
    if (data_021759c0->mUnk_08 == 4) {
        a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
    } else {
        a = NULL;
    }
    if (data_021759c0->mUnk_08 == 4) {
        b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        b = NULL;
    }
    if (c->mUnk_0a8 == 4) {
        func_ov001_02191bc0(a);
        func_ov001_02191e1c(b);
    } else {
        func_ov001_02191e1c(a);
        func_ov001_02191bc0(b);
    }
}

void func_ov001_02190270(Unk02188950 *c) {
    Unk02188950 *a;
    Unk02188950 *b;

    func_0207a974((u16) data_021759c0->mUnk_62);
    func_ov001_02187218(c, 3, func_ov001_021903e0);
    func_ov001_02188c90(c);
    c->mUnk_0a8 = (c->mUnk_0a8 == 5) ? 4 : 5;
    if (data_021759c0->mUnk_08 == 4) {
        a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
    } else {
        a = NULL;
    }
    if (data_021759c0->mUnk_08 == 4) {
        b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        b = NULL;
    }
    if (c->mUnk_0a8 == 4) {
        func_ov001_02191e90(a);
        func_ov001_02191b40(b);
    } else {
        func_ov001_02191b40(a);
        func_ov001_02191e90(b);
    }
}

void func_ov001_02190248(Unk02188950 *a) {
    func_ov001_02188218(a, (s32) ((u16) a->mPrm->mUnk_1ec));
    func_ov001_02190c08(a);
}

int func_ov001_02190168(Unk02188950 *c) {
    Unk02188950 *a;
    Unk02188950 *b;

    if (data_021759c0->mUnk_08 == 4) {
        a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
    } else {
        a = NULL;
    }
    if (data_021759c0->mUnk_08 == 4) {
        b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        b = NULL;
    }
    if (func_ov001_021871f8(a, 3) && func_ov001_021871f8(b, 3)) {
        if (func_ov001_02188220((Unk02188950 *) ((
                data_021759c0->mUnk_08 == 4
                    ? func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 2))
                    : 0))) == 1) {
            func_ov001_02190270(c);
        } else if (func_ov001_02188220((Unk02188950 *) ((
                       data_021759c0->mUnk_08 == 4
                           ? func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 2))
                           : 0))) == 2) {
            func_ov001_02190248(c);
        } else {
            func_ov001_02188e88(c);
        }
    }
    return 0;
}

void func_ov001_021900ac(Unk02188950 *c) {
    Unk02188950 *a;
    Unk02188950 *b;

    func_ov001_02187218(c, 3, func_ov001_02190168);
    func_ov001_02188c90(c);
    if (data_021759c0->mUnk_08 == 4) {
        a = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0)));
    } else {
        a = NULL;
    }
    if (data_021759c0->mUnk_08 == 4) {
        b = func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1));
    } else {
        b = NULL;
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

u32 func_ov001_02190090(Unk02188950 *a) {
    int v1;
    v1 = func_02061fec();
    if (v1 == 1) {
        func_ov001_02190328(a);
    }
    return 0;
}

void func_ov001_02190080(Unk02188950 *a) {
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *)) func_ov001_02190090);
}

void func_ov001_0219006c(Unk02188950 *a) {
    func_ov001_021900ac(a);
    func_ov001_02188260(a);
    return;
}

void func_ov001_02190030(Unk02188950 *a) {
    func_ov001_02187518(a, (u32) (((u32) 0x00002ccdu)), (u32) (0), (u32) (0), (u32) (((u32) 0x00000411u)), (u32) (0));
    func_ov001_02187518(a, (u32) (((u32) 0x00002ccdu)), (u32) (0), (u32) (0), (u32) (((u32) 0x00000412u)), (u32) (0));
    return;
}

void func_ov001_0218ffd4(Unk02188950 *a) {
    func_ov001_02187218(a, 8, NULL);
    func_ov001_02188d64(a, a->mPrm->mUnk_064, a->mPrm->mUnk_068);
    func_ov001_021875c0(a, (u32) (0), (u32) (((u32) 0x000044cdu)), (u32) (((u32) 0x00000400u)),
                        (u32) (((u32) 0x0000042du)), (u32) (0));
    func_ov001_021875c0(a, (u32) (0), (u32) (((u32) 0x000044cdu)), (u32) (((u32) 0x00000400u)),
                        (u32) (((u32) 0x0000042eu)), (u32) (0));
    return;
}

void func_ov001_0218ff98(Unk02188950 *a) {
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d30(a, (s32) (a->mPrm->mUnk_058), (s32) (a->mPrm->mUnk_05c), (UnkFunc *) &func_ov001_0218ffd4);
    func_ov001_021923e0(a);
    func_020d2774(&a->mUnk_000, (u32) (((u32) 0x0000021bu)));
    return;
}

void func_ov001_0218ff64(Unk02188950 *a) {
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(a, (s32) (a->mPrm->mUnk_04c), (s32) (a->mPrm->mUnk_050));
    func_ov001_02188e24(a, a->mPrm->mUnk_054, &func_ov001_0218ff98);
    return;
}

void func_ov001_0218ff34(Unk02188950 *a) {
    func_ov001_02187218(a, 8, NULL);
    func_ov001_02188d64(a, a->mPrm->mUnk_040, a->mPrm->mUnk_044);
    func_ov001_02188db8(a, func_ov001_02190030);
    return;
}

void func_ov001_0218fef8(Unk02188950 *a) {
    func_ov001_02187218(a, 8, (s32(*)(Unk02188950 *))(0));
    func_ov001_02188d64(a, (s32) (a->mPrm->mUnk_034), (s32) (a->mPrm->mUnk_038));
    func_ov001_0218720c(a);
    func_ov001_02188e24(a, a->mPrm->mUnk_03c, &func_ov001_0218ff34);
    return;
}

void func_ov001_0218fee0(Unk02188950 *a) {
    a->mUnk_2e0 = 2;
    func_ov001_021881f4(a, (UnkFunc *) func_ov001_0218fee0);
}

void func_ov001_0218fd20(Unk02188950 *a, Unk0218fd20 *b) {
    int diff;
    int limit;
    Vec3 vec;

    diff = (u16) (AngleFromPair(b->mUnk_50.x - a->mUnk_000.mPos.x, b->mUnk_50.z - a->mUnk_000.mPos.z) - a->mAngle);
    if (diff > 0x8000) {
        diff -= 0x10000;
    }
    limit = a->mPrm->mUnk_088;
    if (diff <= limit && diff >= -limit && func_ov001_021871f8(a, 7)) {
        vec.x = (s32) (((s64) -a->mPrm->mUnk_224 * data_0215d4b4[((u16) a->mAngle >> 4) * 2]) >> 12);
        vec.y = a->mPrm->mUnk_228;
        vec.z = (s32) (((s64) -a->mPrm->mUnk_224 * data_0215d4b4[((u16) a->mAngle >> 4) * 2 + 1]) >> 12);
        SetVelocity((data_021759c0->mUnk_08 == 4
                         ? func_ov001_02181b68((u16) (data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0))
                         : 0),
                    &vec);
        SetVelocity((data_021759c0->mUnk_08 == 4
                         ? func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 1))
                         : 0),
                    &vec);
        func_0208b7bc(0x3eb, &b->mUnk_50);
        func_0208b7bc(0x3ec, &b->mUnk_50);
        func_0208b7bc(0x3ed, &b->mUnk_50);
        a->mUnk_000.mUnk_78 |= data_ov001_021a65c4;
        func_ov001_0219006c(
            data_021759c0->mUnk_08 == 4
                ? func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 2))
                : 0);
        func_ov001_021881f4(a, (UnkFunc *) func_ov001_0218fee0);
        a->mUnk_2e0 = 2;
    } else {
        a->mUnk_2e0 = 2;
        func_ov001_021881f4(a, (UnkFunc *) func_ov001_0218fd20);
    }
}

void func_ov001_0218fcc4(Unk0218fa78 *a) {
    int i;
    Unk02188950 *obj;
    int zero;

    if (a != NULL) {
        zero = 0;
        for (i = 0; i < a->mUnk_04 && (obj = a->mUnk_00[i]) != NULL; i++) {
            func_ov001_021870e4((void *) zero, obj, (const char *) zero, (const char *) zero, data_ov001_021a7eb0);
            if (data_021759c0->mUnk_08 == 4) {
                func_ov001_02181b8c(obj);
            }
            func_ov001_02190080(obj);
        }
    }
}

void func_ov001_0218fc4c(u32 a, Unk02188950 *b) {
    if ((data_021759c0->mUnk_08 == 4 ? func_020a126c() : 0) == 0 && func_ov001_021871f8(b, 1)) {
        if (func_ov001_02188220(
                (data_021759c0->mUnk_08 == 4
                     ? func_ov001_02181b68((u16) ((data_021759c0->mUnk_08 == 4 ? func_ov001_02181b54() : 0) + 2))
                     : 0)) < 2) {
            func_ov001_02190468(b);
        } else {
            func_ov001_0219081c(b);
        }
    }
    func_ov001_021864ac(a, b);
}

void func_ov001_0218fbe0(Unk0218fa78 *a) {
    int i;
    Unk02188950 *obj;

    if (a != NULL) {
        for (i = 0; i < a->mUnk_04 && (obj = a->mUnk_00[i]) != NULL; i++) {
            if (func_02062ec4()) {
                obj->mUnk_000.mPos.y += obj->mPrm->mUnk_080;
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

void func_ov001_0218fb24(u32 a, Unk02188950 *b) {
    s32 value;

    if ((data_021759c0->mUnk_08 == 4 ? func_020a128c() : 0) && func_ov001_021871f8(b, 3)) {
        if (data_021759c0->mUnk_08 == 4 ? func_020a1084((u16) data_021759c0->mUnk_62) : 0) {
            func_ov001_02190df8(b);
        } else {
            func_ov001_02190eb0(b);
        }
    }
    if (b->mUnk_0a8 == 1) {
        value = b->mUnk_134 + 1;
        if (value >= func_0209b634(b->mNsbmd) - 1) {
            value = func_0209b634(b->mNsbmd) - 1;
        }
        b->mUnk_134 = value;
    } else {
        value = b->mUnk_134 - 1;
        if (value <= 0) {
            value = 0;
        }
        b->mUnk_134 = value;
    }
    func_0209b688((void *) (b->mNsbmd), (u16) b->mUnk_134);
    func_ov001_021864ac(a, b);
}

void func_ov001_0218fa78(Unk0218fa78 *a) {
    int i;
    Unk02188950 *obj;

    if (a != NULL) {
        for (i = 0; i < a->mUnk_04 && (obj = a->mUnk_00[i]) != NULL; i++) {
            if (data_021759c0->mUnk_08 == 4) {
                func_ov001_02181b8c(obj);
            }
            func_ov001_021870e4(a, obj, data_ov001_021a7e60, data_ov001_021a7e70, data_ov001_021a7e80);
            func_ov001_021870b0(a, obj, data_ov001_021a7e90);
            func_ov001_0219b2e8(obj->mNsbmd, data_ov001_021a7ea0);
            obj->mUnk_234 = 1;
            if (i == 0) {
                obj->mUnk_000.mFlags |= data_ov001_021a65c0;
            } else if (i == 1) {
                obj->mUnk_000.mFlags &= 0xfffffbff;
            }
        }
    }
}

void func_ov001_0218fa58(u32 a, u32 b) {
    func_ov001_02186368((void *) a, (Unk02188950 *) b);
    func_ov001_021861f4((void *) a, (Unk02188950 *) b, 0);
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
    return (void *) func_0209bf48(func_ov001_0218fbe0, func_ov001_0218fb24, NULL);
}

void *func_ov001_0218f9d4(void) {
    return (void *) func_0209bf48(func_ov001_0218fcc4, func_ov001_0218fc4c, NULL);
}
