#include "ITCM/code_01ff9598.h"
#include "ITCM/code_01ffad14.h"
#include "ITCM/code_01ffb130.h"
#include "ITCM/code_01ff9000.h"
#include "ITCM/code_01ffb000.h"
#include "ITCM/code_01ffb930.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02068eac.h"
#include "Main/Unknown/code_02069000.h"
#include "Main/Unknown/code_0206a000.h"
#include "Main/Unknown/code_0206d000.h"
#include "Main/Unknown/code_0206d020.h"
#include "Main/Unknown/code_0206dfd0.h"
#include "Main/Unknown/code_0206e000.h"
#include "Main/Unknown/code_020720dc.h"
#include "Main/Unknown/code_0207a000.h"
#include "Main/Unknown/code_0207a74c.h"
#include "Main/Unknown/code_0207b000.h"
#include "Main/Unknown/code_02080cd0.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02086058.h"
#include "Main/Unknown/code_020e73b4.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"

void func_01ffb130(Unk0206bcb0 *p) {
    s32 k;
    s32 a;
    s32 b;
    Vec3 v1;
    Vec3 v2;
    Matrix3x3 m1;
    Matrix3x3 m2;
    Vec3 v3;
    Vec3 v4;
    Unk0206ceb4 *q;
    s32 d;
    s32 f;
    u32 w;

    b = p->mUnk_3f8;
    if (p->mUnk_4c & 0x8000000) {
        func_02069134(p);
    }
    w = p->mUnk_4c;
    if (w & 0x10000000) {
        func_0206938c(p);
    } else {
        if (w & 0x80) {
            func_0206a354(p);
        }
        if (p->mUnk_4c & 0x10000) {
            func_02069f6c(p);
        }
        if (p->mUnk_7c & 0x402000) {
            func_0206988c(p);
        }
    }
    if (p->mUnk_4c & 0x2000) {
        q = &p->mUnk_538;
        if (p->mUnk_7c & 1) {
            func_0210ddf4(&data_0217d26c, func_02086080(p->mIndex), func_020718c8, p, 0xa3);
        }
        q->mUnk_0a++;
        if (q->mUnk_0a > 0xb4 && (p->mUnk_4c & 0x2000)) {
            p->mUnk_4c &= ~0x2000;
            p->mUnk_d8 = 0x1000;
            if (!(p->mUnk_4c & 0x8000000)) {
                func_0207b0d0(p);
            }
            func_02080ee4(p);
        }
    }
    if (p->mUnk_4c & 0x40) {
        q = &p->mUnk_538;
        func_0208181c(p->mIndex);
        if ((p->mUnk_7c & 0x10) && p->mKartModelsEntry->mUnk_008->mUnk_1a == 0) {
            func_02068a64(p, 2, 1);
        }
        q->mUnk_06++;
        if (q->mUnk_06 > 0x1c2) {
            p->mUnk_4c &= ~0x40;
            func_0207b1a8(p);
            p->mUnk_29c = 0;
            func_020817b8(p->mIndex);
            func_02068a64(p, 0, 1);
            if ((p->mUnk_7c & 1) && data_021759c0->mUnk_00c == 0) {
                func_02106dc8();
            }
            if (p->mUnk_4c & 0x2000) {
                func_0207b13c(p);
            }
        }
    }
    if ((p->mUnk_48 & 0x800) && func_02072d84(p, &b) != 0) {
        return;
    }
    if (p->mUnk_7c & 0x20) {
        return;
    }
    data_usa_021655c4[p->mState](p);
    func_01ffb9e0(p);
    if (p->mUnk_48 & 0x40) {
        p->mUnk_3ac++;
        if (p->mUnk_3ac > 0x41) {
            p->mUnk_48 &= ~0x240;
            if (p->mUnk_7c & 1) {
                func_020e7a18();
            }
        } else {
            p->mUnk_80.y -= 0x19a;
        }
    } else {
        func_01ffb9cc(p);
    }
    if (p->mUnk_44 & 0x10) {
        func_02063b10(p, &v2);
        if (!(p->mUnk_48 & 6) && p->mUnk_244.y > 0 && (v2.y > 0 ? v2.y : -v2.y) > 0xcd && p->mUnk_38c <= 0) {
            p->mUnk_2a8 += (s32) (((s64) -v2.y * 0x19a) >> 12);
        }
    }
    if ((p->mUnk_44 & 0x10) || (p->mUnk_4c & 0x10000000)) {
        Matrix4x3FirstThreeRowsFromVec3AndPair((Unk02012f58 *) &m1, &p->mUnk_244,
                                               data_0215d4b4[((u16) p->mUnk_388 >> 4) * 2],
                                               data_0215d4b4[((u16) p->mUnk_388 >> 4) * 2 + 1]);
        if (p->mUnk_48 & 1) {
            Matrix4x3FirstThreeRowsFromVec3AndPair((Unk02012f58 *) &m2, &p->mUnk_120, data_0215d4b4[0xba],
                                                   data_0215d4b4[0xbb]);
            Matrix3x3Multiply(m2.mUnk_00, m1.mUnk_00, m1.mUnk_00);
        }
        Vec3MultiplyMatrix3x3(&p->mUnk_278, m1.mUnk_00, &p->mUnk_50);
        d = Vec3Dot(&p->mUnk_244, &p->mUnk_50);
        v3.x = p->mUnk_50.x - (s32) (((s64) p->mUnk_244.x * d) >> 12);
        v3.y = p->mUnk_50.y - (s32) (((s64) p->mUnk_244.y * d) >> 12);
        v3.z = p->mUnk_50.z - (s32) (((s64) p->mUnk_244.z * d) >> 12);
        p->mUnk_d4 = Vec3Length(&v3);
    } else {
        d = func_02039828(&p->mUnk_278, &p->mUnk_244);
        p->mUnk_50 = p->mUnk_278;
        if (p->mUnk_3e8 > 0) {
            p->mUnk_d4 = 0x1000;
        } else if (d < 0) {
            p->mUnk_d4 = 0x1000 - d;
        } else {
            p->mUnk_d4 = 0x1000;
        }
    }
    a = func_01ffaf18(p);
    func_01ffb930(&a, p);
    if ((p->mUnk_44 & 0x90) || (p->mUnk_4c & 0x10000000)) {
        k = p->mUnk_240;
        Vec3Sub(&p->mUnk_50, &p->mUnk_68, &v4);
        v4.x = (s32) (((s64) v4.x * k) >> 12);
        v4.y = (s32) (((s64) v4.y * k) >> 12);
        v4.z = (s32) (((s64) v4.z * k) >> 12);
        Vec3Add(&p->mUnk_68, &v4, &p->mUnk_68);
        p->mUnk_68.y = p->mUnk_50.y;
    }
    v1.x = (s32) (((s64) p->mUnk_68.x * a) >> 12);
    v1.y = (s32) (((s64) p->mUnk_68.y * a) >> 12);
    v1.z = (s32) (((s64) p->mUnk_68.z * a) >> 12);
    if (a >= 0) {
        p->mUnk_05c = p->mUnk_50;
    } else {
        p->mUnk_05c.x = -p->mUnk_50.x;
        p->mUnk_05c.y = -p->mUnk_50.y;
        p->mUnk_05c.z = -p->mUnk_50.z;
    }
    if (p->mState == 6) {
        v1.y = 0;
    }
    p->mUnk_a4 = v1;
    Vec3Add(&p->mUnk_a4, &p->mUnk_374, &p->mUnk_a4);
    p->mUnk_a4.y += p->mUnk_260;
    Vec3AddScaled(p->mUnk_274, &p->mUnk_268, &p->mUnk_a4, &p->mUnk_a4);
    if (!(p->mUnk_44 & 0x10) && p->mUnk_380 > 5 && p->mUnk_a4.y < -0x6000) {
        p->mUnk_a4.y = -0x6000;
    }
    Vec3Add(&p->mUnk_a4, &p->mUnk_2f0, &p->mUnk_a4);
    Vec3Add(&p->mUnk_a4, &p->mUnk_1fc, &p->mUnk_a4);
    func_01ff9c40(p);
    func_01ffae14(p, b);
    if (p->mUnk_7c & 1) {
        func_0207a74c(func_02039828(&p->mUnk_a4, &p->mUnk_50));
        if ((p->mUnk_44 & 0x1000000) && p->mUnk_4d4 != 0) {
            p->mUnk_4d4 = (s32) (((s64) p->mUnk_4d4 * 0xfae) >> 12);
            if (p->mUnk_4d4 < 0xcd) {
                p->mUnk_4d4 = 0;
            }
        }
    }
    if (!(p->mUnk_7c & 0x20)) {
        Vec3Add(&p->mUnk_80, &p->mUnk_a4, &p->mUnk_80);
        p->mUnk_38c = 0x1000;
    }
    f = (p->mUnk_44 & 0x10) ? 0xee1 : 0xfae;
    p->mUnk_2d8.x = (s32) (((s64) p->mUnk_2d8.x * f) >> 12);
    p->mUnk_2d8.y = (s32) (((s64) p->mUnk_2d8.y * f) >> 12);
    p->mUnk_2d8.z = (s32) (((s64) p->mUnk_2d8.z * f) >> 12);
    if ((s64) p->mUnk_2d8.x * p->mUnk_2d8.x + (s64) p->mUnk_2d8.y * p->mUnk_2d8.y +
            (s64) p->mUnk_2d8.z * p->mUnk_2d8.z >=
        0xa429) {
        p->mUnk_44 |= 0x2000;
    } else {
        p->mUnk_2d8 = data_02154f94;
        p->mUnk_44 &= ~0x2000;
    }
    func_01ffd900(p->mUnk_2c8, 0xe800);
    func_0206e874(p);
    if (p->mUnk_7c & 0x8000000) {
        return;
    }
    func_01ffc064(&p->mUnk_1d8, p->mUnk_510, p->mUnk_2cc->mUnk_04, p);
    func_0206d18c(p);
    func_0206dfd0(p);
    func_0206d578(p);
}
