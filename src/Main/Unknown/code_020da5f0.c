#include "Main/Unknown/code_020da5f0.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d94dc.h"
#include "Main/Unknown/code_020da414.h"

#include "Main/Unknown/code_020da628.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020ebef8.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f49bc.h"
#include "Main/Unknown/code_020f8ddc.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/unk_0216b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020dab98.h"
#include "Main/Unknown/code_020dab9c.h"
#include "Main/Unknown/code_020dabfc.h"
#include "Main/Unknown/code_020dac00.h"
#include "Main/Unknown/code_020dac58.h"
#include "Main/Unknown/code_020dac74.h"
#include "ITCM/code_01ffdee4.h"
#include "Main/Unknown/code_020d7000.h"
#include "Main/Unknown/code_020dade8.h"
#include "Main/Unknown/code_020dadfc.h"
#include "Main/Unknown/code_020d8c74.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020daf0c.h"

void EnterKuriboState0(Unk020daf0c *p0) {
    p0->mUnk_c4 = 0x1000u;
    p0->mUnk_c8 = 0x0u;
}

void UpdateKuriboState0(Kuribo *p) {
    if (p->mUnk_f0 >= 0xa && (p->mUnk_f0 < 0x14 || p->mUnk_f0 >= 0x1e)) {
        func_020d8cc8(&p->mUnk_cc);
    }
    func_020d8c74(&p->mUnk_cc, &p->mUnk_00.mPos);
    if (p->mUnk_c4 == 0x1000 && p->mUnk_c8 == 0) {
        return;
    }
    p->mUnk_c8 += (s32) (((s64) (0x1000 - p->mUnk_c4) * 0x200) >> 12);
    p->mUnk_c8 = (s32) (((s64) p->mUnk_c8 * 0xd99) >> 12);
    p->mUnk_c4 += p->mUnk_c8;
    if (p->mUnk_c4 > 0xfd7 && p->mUnk_c4 < 0x1029 && p->mUnk_c8 > -0x29 && p->mUnk_c8 < 0x29) {
        p->mUnk_c4 = 0x1000;
        p->mUnk_c8 = 0;
    }
}

void EnterKuriboState1(Unk020dade8 *p0) {
    p0->mUnk_c4 = 0x1000u;
    p0->mUnk_c8 = 0x0u;
}

void UpdateKuriboState1(Kuribo *p) {
    u32 f;
    Vec3 v;
    Vec3 w;
    Vec3 x;
    if (p->mUnk_f0 < 0xa || (p->mUnk_f0 >= 0x14 && p->mUnk_f0 < 0x1e)) {
        if (p->mUnk_f0 == 0 || p->mUnk_f0 == 0x14) {
            p->mUnk_102--;
            if (p->mUnk_102 < 0) {
                p->mUnk_102 = 3;
                p->mUnk_104 = p->mUnk_104 == 0;
            }
        }
    }
    p->mUnk_00.mUnk_10.y -= 0x400;
    p->mUnk_00.mPos.y += p->mUnk_00.mUnk_10.y;
    v = p->mUnk_00.mPos;
    v.y += 0xa000;
    if (func_01ffdee4(&v, NULL, 0, 0xa000, 8, -2, &w, &x, NULL, &f, NULL, NULL, NULL, NULL) != 0) {
        Vec3Add(&p->mUnk_00.mPos, &w, &p->mUnk_00.mPos);
        p->mUnk_00.mUnk_10.y = 0;
        if ((f & 0x1e34ef) != 0) {
            func_020d7b88(&x, &p->mUnk_b4);
            p->mUnk_00.mFlags &= ~1;
        }
    }
    func_020d759c(&p->mUnk_a4, &p->mUnk_b4, &p->mUnk_a4, p->mUnk_f8);
    if (p->mUnk_f8 > 0xb4) {
        p->mUnk_f8 = 0xb4;
    }
}

void EnterKuriboState2(Kuribo *p0) {
    p0->mUnk_00.mFlags = (u16) (((((u32) p0->mUnk_00.mFlags)) | (((u32) data_02158160))));
}

void UpdateKuriboState2(Kuribo *p) {
    p->mUnk_c4 = (s32) (((s64) p->mUnk_c4 * 0x1266) >> 12);
    if (p->mUnk_c4 > 0x1800) {
        p->mUnk_00.mUnk_80.mNextState = 3;
        p->mUnk_00.mUnk_80.mNextStateRequested = 1;
    }
}

u32 func_020dabfc(u32 p0) {
    return p0;
}

void UpdateKuriboState3(Kuribo *p) {
    p->mUnk_c4 = (s32) (((s64) p->mUnk_c4 * 0xd99) >> 12);
    if (p->mUnk_c4 < 0x333) {
        p->mUnk_00.mUnk_80.mNextState = 4;
        p->mUnk_00.mUnk_80.mNextStateRequested = 1;
    }
}

u32 func_020dab98(u32 p0) {
    return p0;
}

void UpdateKuriboState4(Kuribo *p) {
    if (p->mUnk_fc != 0) {
        if (p->mUnk_00.mUnk_80.mStateFrames > 0x12c) {
            p->mUnk_00.mUnk_80.mNextState = 5;
            p->mUnk_00.mUnk_80.mNextStateRequested = 1;
        }
        return;
    }
    p->mUnk_100--;
    if (p->mUnk_100 == 0) {
        ParkMapObject(&p->mUnk_00);
    }
}

void EnterKuriboState5(Kuribo *p) {
    Unk0210b7a8 s;
    s32 a;
    if ((p->mUnk_00.mUnk_78 & 4) == 0) {
        if (p->mUnk_00.mUnk_70 == data_0217ca6c[2].mUnk_20) {
            a = 2;
        } else if (p->mUnk_00.mUnk_70 == data_0217ca6c[3].mUnk_20) {
            a = 3;
        } else {
            a = 4;
        }
        s.mUnk_00 = 0x183;
        s.mUnk_04 = &p->mUnk_00.mPos;
        s.mUnk_08 = a;
        s.mUnk_0c = func_020d4ef4(&p->mUnk_00.mPos);
        func_0210b7a8(&s);
    }
    p->mUnk_00.mFlags &= ~1;
    p->mUnk_c8 = 0;
}

void UpdateKuriboState5(Kuribo *p) {
    p->mUnk_c8 += (s32) (((s64) (0x1000 - p->mUnk_c4) * 0x200) >> 12);
    p->mUnk_c8 = (s32) (((s64) p->mUnk_c8 * 0xd99) >> 12);
    p->mUnk_c4 += p->mUnk_c8;
    if (p->mUnk_00.mUnk_80.mStateFrames > 0x3c) {
        p->mUnk_00.mUnk_80.mNextState = 0;
        p->mUnk_00.mUnk_80.mNextStateRequested = 1;
    }
}

void func_020da820(Kuribo *p, Vec3 *a) {
    Vec3 s;
    ItemObject *r;
    s32 d;
    if (p->mUnk_00.mCourseMapRow == NULL || p->mUnk_00.mCourseMapRow->mUnk_2c != 0) {
        return;
    }
    Vec3Sub(&p->mUnk_cc.mUnk_1c->mUnk_00, &p->mUnk_cc.mUnk_20->mUnk_00, &s);
    if ((s64) s.x * s.x + (s64) s.y * s.y + (s64) s.z * s.z >= 0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&s, &s);
    }
    {
        Vec3 t = {0, 0, 0};
        t.x = a->x;
        t.z = a->z;
        d = Vec3Dot(&s, &t);
        s.x = t.x - (s32) (((s64) s.x * d) >> 12);
        s.y = t.y - (s32) (((s64) s.y * d) >> 12);
        s.z = t.z - (s32) (((s64) s.z * d) >> 12);
    }
    if ((s64) s.x * s.x + (s64) s.y * s.y + (s64) s.z * s.z >= 0x10) {
        Vec3NormalizeAndGetLengthUnchecked(&s, &s);
    }
    r = StartItemObjectOrZero(3, 8, &p->mUnk_00.mPos, &data_021581f8);
    if (r == NULL) {
        return;
    }
    r->mUnk_68.x = 0xcd;
    r->mUnk_68.y = 0xcd;
    r->mUnk_68.z = 0xcd;
    d = Vec3Length(a) + 0x5000;
    r->mVelocity.x = (s32) (((s64) s.x * d) >> 12);
    r->mVelocity.y = (s32) (((s64) s.y * d) >> 12);
    r->mVelocity.z = (s32) (((s64) s.z * d) >> 12);
    r->mVelocity.y += 0xf000;
    Vec3Add(&r->mPos, &r->mVelocity, &r->mPos);
    func_020f6630(r, 0, &p->mUnk_00.mPos, a, &data_021581f8);
}

u32 func_020da73c(Kuribo *p, Kart *a, u8 *b, u8 *c) {
    switch (*b) {
        case 0:
            if (p->mUnk_c4 == 0x1000) {
                if (p->mUnk_c8 == 0) {
                    p->mUnk_c8 = (s32) (((s64) a->mVelocityLength * 0x52) >> 12);
                }
            }
            break;
        case 1:
            if (p->mUnk_00.mUnk_80.mState == 0 || p->mUnk_00.mUnk_80.mState == 5 || p->mUnk_00.mUnk_80.mState == 1) {
                p->mUnk_00.mUnk_80.mNextState = 2;
                p->mUnk_00.mUnk_80.mNextStateRequested = 1;
                func_020d26ec(&a->mUnk_00, 0x185);
                func_020d26f8(&p->mUnk_00, a);
                func_020da820(p, &a->mVelocity);
                p->mUnk_00.mFlags = p->mUnk_00.mFlags | data_02158160;
            }
            break;
    }
    return *c;
}

u32 func_020da684(Kuribo *p, Kart *a, u8 *b, u8 *c) {
    switch (*b) {
        case 0:
            if (p->mUnk_c4 == 0x1000) {
                if (p->mUnk_c8 == 0) {
                    p->mUnk_c8 = 0x19a;
                }
            }
            break;
        case 1:
            if (p->mUnk_00.mUnk_80.mState == 0 || p->mUnk_00.mUnk_80.mState == 5 || p->mUnk_00.mUnk_80.mState == 1) {
                p->mUnk_00.mUnk_80.mNextState = 2;
                p->mUnk_00.mUnk_80.mNextStateRequested = 1;
                func_020f8ddc(a);
                if (a != NULL) {
                    func_020da820(p, &a->mUnk_05c);
                }
                p->mUnk_00.mFlags = p->mUnk_00.mFlags | data_02158160;
            }
            break;
    }
    return *c;
}

void func_020da628(Kuribo *p) {
    p->mUnk_f8 = 0x1000;
    p->mUnk_a4 = data_02158140;
    p->mUnk_b4 = data_02158150;
    func_02046bcc(&p->mUnk_00.mUnk_80, 1);
    p->mUnk_00.mUnk_10.x = 0;
    p->mUnk_00.mUnk_10.y = 0;
    p->mUnk_00.mUnk_10.z = 0;
}

#pragma thumb on

void CreateKuribo(void) {
    void *v1;
    u32 v2;
    v1 = FindCourseMapObjFile(gKuriboNsbmdName);
    v2 = (u32) FindCourseMapObjFile(gKuriboNsbtpName);
    func_020e6488((Unk020e6488 **) (((u32 *) &gKuribo)), v1, v2, (u32) 0);
    func_020e6ab8(gKuribo);
}

#pragma thumb off
