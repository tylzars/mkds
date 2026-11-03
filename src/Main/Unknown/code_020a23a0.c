#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0204984c.h"
#include "Main/Unknown/code_020a23a0.h"
#include "code_02010c84.h"
#include "code_02010fac.h"
#include "code_02146cbc.h"
#include "code_0214a748.h"
#include "code_02010f98.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02038c94.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_0204a000.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_02088000.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_02018000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_0208b6b0.h"
#include "Main/Unknown/code_02146000.h"
#include "code_02147cd8.h"
#include "code_0214a390.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_02167000.h"
#include "Main/Unknown/unk_02170000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b200.h"

s32 func_020a23a0(Unk0206bcb0 *a) {
    Unk0206bcb0_590 *p;

    p = a->mKartModelsEntry;
    return data_02156600[p->mUnk_000] + p->mUnk_020->mUnk_48[p->mUnk_000].x;
}

void func_020a23cc(void) {
    s32 m1[9];
    s32 m2[9];
    s32 m3[9];
    s32 v1[3];
    s32 v2[3];
    s32 v3[3];
    u16 v4;

    if (data_0217b200->mUnk_002 >= 3) {
        return;
    }
    func_0208b870(&data_0217b200->mUnk_0cc);
    func_02011034();
    func_01ff9048(0x15, NULL, 0);
    v1[0] = 0x1000;
    v1[1] = 0x1000;
    v1[2] = 0x1000;
    func_01ff9048(0x1b, v1, 3);
    v2[0] = 0;
    v2[1] = -0xcd;
    v2[2] = -0x2000;
    func_01ff9048(0x1c, v2, 3);
    v4 = data_0217b200->mUnk_008.mUnk_04;
    func_02146d28(m1, data_0215d6b4[0x76], data_0215d6b4[0x77]);
    func_02146d44(m2, data_0215d4b4[(data_0217b200->mUnk_004 >> 4) * 2],
                  data_0215d4b4[(data_0217b200->mUnk_004 >> 4) * 2 + 1]);
    func_02146d60(m3, data_0215d4b4[(v4 >> 4) * 2], data_0215d4b4[(v4 >> 4) * 2 + 1]);
    func_01ff9048(0x1a, m1, 9);
    func_01ff9048(0x1a, m2, 9);
    func_01ff9048(0x1a, m3, 9);
    v3[0] = 0;
    v3[1] = 0;
    v3[2] = 0;
    func_01ff9048(0x1c, v3, 3);
    func_020849d0(&data_0217b200->mUnk_028);
    func_01ff9234();
}

void func_020a2558(void) {
    Unk0217b200 *d;
    Unk0217b200_08 *p;
    s32 v;

    if (data_0217b200->mUnk_002 >= 3) {
        return;
    }
    func_0208b8c8();
    data_0217b200->mUnk_004 += 0x6d;
    d = data_0217b200;
    p = &d->mUnk_008;
    d->mUnk_008.mUnk_00 += p->mUnk_18;
    p->mUnk_08 = p->mUnk_0c + func_020a2668(p->mUnk_10, func_020a2684(d->mUnk_008.mUnk_00)) - p->mUnk_04;
    p->mUnk_04 += p->mUnk_08;
    if (p->mUnk_10 > 0) {
        v = p->mUnk_10 + p->mUnk_14;
        if (v <= 0) {
            v = 0;
        }
        p->mUnk_10 = v;
    } else if (p->mUnk_10 < 0) {
        v = p->mUnk_10 + p->mUnk_14;
        if (v >= 0) {
            v = 0;
        }
        p->mUnk_10 = v;
    }
    if (p->mUnk_18 > 0) {
        v = p->mUnk_18 + p->mUnk_1c;
        if (v <= 0) {
            v = 0;
        }
        p->mUnk_18 = v;
    } else if (p->mUnk_18 < 0) {
        v = p->mUnk_18 + p->mUnk_1c;
        if (v >= 0) {
            v = 0;
        }
        p->mUnk_18 = v;
    }
}

s32 func_020a2668(s32 a, s32 b) {
    return (s32) (((s64) a * b + 0x800) >> 12);
}

s16 func_020a2684(s32 a) {
    return data_0215d4b4[(a >> 4) * 2];
}

void func_020a269c(s32 a, u32 b) {
    void *v1;
    void *v2;
    void *v3;
    float f;
    s32 x;
    Unk0219b250_Item *s;

    data_0217b200 = func_02036bec(func_020364e0(func_020364e8()), 0x124);
    data_0217b200->mUnk_002 = b;
    data_0217b200->mUnk_000 = a;
    if (a < 9 && b < 3) {
        v1 = FindSceneFile(data_021677fc[a]);
        v2 = FindSceneFile(data_02167820[a]);
        data_0217b200->mUnk_0fc = data_02156640[a];
        data_0217b200->mUnk_100 = data_02156654[a];
        data_0217b200->mUnk_104 = data_02156668[a];
        data_0217b200->mUnk_0fe = data_0215667c[a];
        data_0217b200->mUnk_102 = data_02156690[a];
        data_0217b200->mUnk_106 = data_021566a4[a];
        data_0217b200->mUnk_108.x = 0;
        data_0217b200->mUnk_108.y = data_021566dc[a];
        data_0217b200->mUnk_108.z = -0x2000;
        data_0217b200->mUnk_114 = data_021566b8[a];
        func_02084e28(&data_0217b200->mUnk_028, v1);
        func_020849b0(&data_0217b200->mUnk_028, 3);
        if (data_021759c0->mUnk_57 != 0) {
            func_02084958(&data_0217b200->mUnk_028, 1);
        } else {
            func_02084958(&data_0217b200->mUnk_028, 2);
        }
        v3 = func_020364e0(func_020364e8());
        func_0208823c(2, &data_0217b200->mUnk_094, &data_0217b200->mUnk_028, 1, v3, v1);
        func_0208805c(&data_0217b200->mUnk_094, v2, func_020364e0(func_020364e8()));
        func_02087f84(&data_0217b200->mUnk_094, 0);
        x = data_0217b200->mUnk_002;
        if (x != 0) {
            f = 0.5f + (float) (x << 12);
        } else {
            f = (float) (x << 12) - 0.5f;
        }
        s = &data_0217b200->mUnk_094;
        s->mUnk_0c = (s32) f;
        *s->mUnk_1c[s->mUnk_1a] = s->mUnk_0c;
        func_0208b934(func_020364e0(func_020364e8()));
        if (b == 0) {
            Vec3 w0 = {0, 0, 0};

            data_0217b200->mUnk_118 = func_0208b7bc(0, &w0);
            {
                Vec3 w1 = {0, 0, 0};

                data_0217b200->mUnk_11c = func_0208b7bc(4, &w1);
                {
                    Vec3 w2 = {0, 0, 0};

                    data_0217b200->mUnk_120 = func_0208b7bc(5, &w2);
                }
            }
        } else if (b == 1) {
            Vec3 w3 = {0, 0, 0};

            data_0217b200->mUnk_118 = func_0208b7bc(0, &w3);
        }
    }
    func_020a29cc();
}

void func_020a29cc(void) {
    s32 x;
    s32 y;
    s32 v;
    Unk0217b200 *d;
    Unk0217b200_08 *p;

    func_0214a40c((u32 *) 0x4000050, 1, 0x1f, 0x10, 0x10);
    func_02010fac(0, data_0217b200->mUnk_0fc, data_0217b200->mUnk_100, data_0217b200->mUnk_104);
    func_02010fac(1, data_0217b200->mUnk_0fe, data_0217b200->mUnk_102, data_0217b200->mUnk_106);
    func_02010f98(0, 0x7fff);
    func_02010f98(1, 0x7fff);
    x = (s32) (((s64) func_02147f34(data_0215d6b4[0x54], data_0215d6b4[0x55]) * 0x19a) >> 12);
    y = (s32) (((s64) -x * 0x1555) >> 12);
    if (data_021759c0->mUnk_57 != 0) {
        func_0214b048(x, -x, -y, y, 0x19a, 0x1388000, 0x200, 0, (Unk0214ad4c *) data_0217029c.mUnk_08);
        data_0217029c.mUnk_fc &= ~0x50;
    } else {
        func_0214b048(x, -x, y, -y, 0x19a, 0x1388000, 0x200, 0, (Unk0214ad4c *) data_0217029c.mUnk_08);
        data_0217029c.mUnk_fc &= ~0x50;
    }
    {
        Vec3 v3;
        Vec3 v2;
        Vec3 v1 = {0, 0, 0};

        v2 = data_021676d0;
        v3 = data_021676c4;
        __memcpy(&data_021704dc, &v3, sizeof(Vec3));
        data_021704e8 = v2;
        data_021704f4 = v1;
        func_0214abb4(&v3, &v2, &v1, 0, &data_0217029c.mUnk_4c);
        data_0217029c.mUnk_fc &= ~0xe8;
        func_02038c9c(data_021755a0, 1, 1);
        data_0217029c.mUnk_a0 = 0xbfff0000;
        func_02011034();
        if (data_0217b200->mUnk_002 >= 3) {
            return;
        }
        data_0217b200->mUnk_004 = -func_0204a508() * 0x6d;
        v = -func_0204a508() * 0x36;
        d = data_0217b200;
        d->mUnk_008.mUnk_00 = v;
        p = &d->mUnk_008;
        p->mUnk_0c = 0;
        p->mUnk_10 = 0xaab;
        p->mUnk_14 = 0;
        p->mUnk_18 = 0x36;
        p->mUnk_1c = 0;
        func_021471bc(&data_0217b200->mUnk_0cc);
        if (data_0217b200->mUnk_002 == 0) {
            data_0217b200->mUnk_118->mUnk_5c = data_0217b200->mUnk_114;
            data_0217b200->mUnk_118->mUnk_28.x =
                data_0217b200->mUnk_108.x + data_0217b200->mUnk_118->mUnk_20->mUnk_00->mUnk_04.x;
            data_0217b200->mUnk_118->mUnk_28.y =
                data_0217b200->mUnk_108.y + data_0217b200->mUnk_118->mUnk_20->mUnk_00->mUnk_04.y;
            data_0217b200->mUnk_118->mUnk_28.z =
                data_0217b200->mUnk_108.z + data_0217b200->mUnk_118->mUnk_20->mUnk_00->mUnk_04.z;
            data_0217b200->mUnk_11c->mUnk_28.x = data_0217b200->mUnk_11c->mUnk_20->mUnk_00->mUnk_04.x;
            data_0217b200->mUnk_11c->mUnk_28.y = data_0217b200->mUnk_11c->mUnk_20->mUnk_00->mUnk_04.y - 0xcd;
            data_0217b200->mUnk_11c->mUnk_28.z = data_0217b200->mUnk_11c->mUnk_20->mUnk_00->mUnk_04.z - 0x21ec;
            data_0217b200->mUnk_120->mUnk_28.x = data_0217b200->mUnk_120->mUnk_20->mUnk_00->mUnk_04.x;
            data_0217b200->mUnk_120->mUnk_28.y = data_0217b200->mUnk_120->mUnk_20->mUnk_00->mUnk_04.y - 0xcd;
            data_0217b200->mUnk_120->mUnk_28.z = data_0217b200->mUnk_120->mUnk_20->mUnk_00->mUnk_04.z - 0x21ec;
        } else if (data_0217b200->mUnk_002 == 1) {
            data_0217b200->mUnk_118->mUnk_5c = data_0217b200->mUnk_114;
            data_0217b200->mUnk_118->mUnk_28.x =
                data_0217b200->mUnk_108.x + data_0217b200->mUnk_118->mUnk_20->mUnk_00->mUnk_04.x;
            data_0217b200->mUnk_118->mUnk_28.y =
                data_0217b200->mUnk_108.y + data_0217b200->mUnk_118->mUnk_20->mUnk_00->mUnk_04.y;
            data_0217b200->mUnk_118->mUnk_28.z =
                data_0217b200->mUnk_108.z + data_0217b200->mUnk_118->mUnk_20->mUnk_00->mUnk_04.z;
        }
    }
}
