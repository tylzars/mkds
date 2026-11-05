#include "Main/Unknown/code_020a3f2c.h"

#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a10f0.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_020a3fa8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020a10d4.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/code_020a2220.h"
#include "Main/Unknown/code_020a2204.h"
#include "Main/Unknown/code_020a2e4c.h"
#include "Main/Unknown/code_020a2e74.h"
#include "Main/Unknown/code_020d26e0.h"
#include "Main/Unknown/code_020a2000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_02024974.h"
#include "Main/Unknown/code_0208aea8.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_0209b634.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_02081000.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_02024000.h"
#include "Main/Unknown/code_020ac524.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020a1218.h"
#include "Main/Unknown/code_020a12b8.h"
#include "Main/Unknown/code_020a2300.h"
#include "Main/Unknown/code_020a2e88.h"
#include "Main/Unknown/code_020a2f0c.h"
#include "Main/Unknown/code_020a3000.h"
#include "Main/Unknown/code_020a683c.h"
#include "Main/Unknown/code_020a69a0.h"
#include "Main/Unknown/code_020a69b4.h"
#include "Main/Unknown/code_020ac000.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/code_0210b870.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020a02f8.h"
#include "Main/Unknown/code_020a6cb4.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02109110.h"
#include "Main/Unknown/code_020d3c94.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_02039860.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ffdee4.h"
#include "Main/Unknown/code_0210bae8.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020a6000.h"
#include "Main/Unknown/code_020a0000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/code_020e516c.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/unk_02167000.h"
#include "Main/Unknown/code_020a6c64.h"
#include "Main/Unknown/unk_0217c000.h"

void InitShine16(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 value4;
    value4 = value0;
    func_020d2398((void *) value0);
    value0 = (u32) func_020364e8();
    value0 = (u32) GetHeap((void *) value0);
    value1 = 0x44u;
    value0 = (u32) HeapAlloc((void *) value0, value1);
    *(u32 *) ((value4) + (148)) = value0;
    value0 = (u32) * (const u32 *) ((value4) + (148));
    value2 = (value4) + (4u);
    value1 = 0xbu;
    func_02109110((Unk0210bfbc *) value0, value1, (Vec3 *) value2);
    value0 = (u32) * (const u32 *) ((value4) + (148));
    func_0210bae8((Unk0210bfbc *) value0);
    value0 = (u32) &data_0217ca6c;
    value0 = (u32) * (const u32 *) ((value0) + (428));
    *(u32 *) ((value4) + (112)) = value0;
}

u32 func_020a6ae4(Shine16 *p, Kart *o, u8 *a, u8 *b) {
    u8 v1;
    u8 v2;
    s32 r;
    u16 c;
    s32 n;

    v1 = *a;
    v2 = *b;
    if (o->mState != 0 || (o->mUnk_48 & 0x200) != 0 || func_020a1084(o->mIndex) != FALSE) {
        return 0;
    }
    if (v1 == 1) {
        if ((o->mUnk_4c & 0x400000) != 0) {
            return v2;
        }
        if (p->mUnk_c0 > 0) {
            return v2;
        }
        p->mUnk_00.mFlags |= data_021567a0;
        p->mUnk_c0 = 0x19;
        p->mUnk_00.mPos.x = o->mPos.x;
        p->mUnk_00.mPos.y = o->mPos.y + func_020a23a0(o) + 0x7800;
        p->mUnk_00.mPos.z = o->mPos.z;
        p->mUnk_a0 = 0;
        p->mUnk_00.mUnk_10.x = 0;
        p->mUnk_00.mUnk_10.y = 0x3000;
        p->mUnk_00.mUnk_10.z = 0;
        p->mUnk_a8 = 0;
        p->mState = 2;
        p->mUnk_c8 = o->mIndex;
        p->mUnk_ca = o->mIndex;
        func_020a10ac(o->mIndex, 1);
        func_020a10f0(o->mIndex, 1);
        r = o->mIndex == data_021759c0->mEntryIndex ? 1 : 0;
        c = func_020a1180();
        n = func_020a1154(o->mIndex);
        func_0210b98c(p->mUnk_00.mUnk_94, func_02024974(0, r, c, n));
        p->mUnk_e4 = func_0208b7bc(0x7d, &p->mUnk_00.mPos);
        p->mUnk_e8 = 0xe;
    }
    return v2;
}

void CreateShine16(void *a) {
    gShine16 = CreateMapObjectModelNsbmdNsbtp(a, gShine16NsbmdName, gShine16NsbtpName);
    SetMapObjectModelPolygonId(gShine16, 0x3f);
}

void func_020a6a90(void *a) {
    func_0209bbd0(a, gShine16);
}

void DrawShine16(void *a, Shine16 *p) {
    s32 t;
    Vec3 s;
    s32 n;

    if (p->mUnk_a8 <= 0) {
        return;
    }
    t = 0x1e;
    func_01ff9048(0x14, &t, 1);
    func_01ff9048(0x19, func_020e6cbc(&p->mUnk_00.mPos), 0xc);
    n = p->mUnk_a8;
    if (n != 0x1000) {
        s.x = n;
        s.y = n;
        s.z = n;
        func_01ff9048(0x1b, &s, 3);
    }
    func_01ff9048(0x1b, &p->mUnk_00.mScale, 3);
    func_0209b7a0(gShine16, p->mUnk_b8, 0);
    func_0209b688(gShine16, (u16) p->mUnk_b0);
    DrawMapObjectModel(a, gShine16, p);
}

u32 func_020a69a0(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217b220;
    value1 = 0u;
    *(u16 *) ((value0) + (0)) = (u16) value1;
    return value0;
}

void func_020a697c(void) {
    s32 v;

    v = data_0217b220 + 1;
    if (v >= 3) {
        v = 0;
    }
    data_0217b220 = v;
}

void func_020a683c(void *a, Shine16 *p, void *b, s32 c) {
    s32 t;
    s32 m[9];
    Vec3 s;
    Vec3 u;
    s32 n;
    s32 x;

    if (p->mUnk_a8 <= 0) {
        return;
    }
    if (p->mState == 2) {
        return;
    }
    if (p->mState == 3) {
        return;
    }
    t = 0x1e;
    func_01ff9048(0x14, &t, 1);
    func_01ff9048(0x19, func_020e6cbc(&p->mUnk_00.mPos), 0xc);
    n = p->mUnk_a8;
    if (n < 0x1000) {
        s.x = n;
        s.y = n;
        s.z = n;
        func_01ff9048(0x1b, &s, 3);
    }
    func_01ff9048(0x1b, &p->mUnk_00.mScale, 3);
    x = data_021567a4[data_0217b220] >> 4;
    Matrix3x3FromPairY(m, gPairsByAngle[x * 2 + 1], gPairsByAngle[x * 2]);
    func_01ff9048(0x1a, m, 9);
    u.x = 0x2000;
    u.y = 0x2000;
    u.z = 0x2000;
    func_01ff9048(0x1b, &u, 3);
    func_020e5348(8, c);
}

void UpdateShine16(void *a, Shine16 *p) {
    Vec3 c;
    Vec3 b;
    Vec3 d;
    Vec3 e;
    u32 f;
    Kart *v;
    s32 i;
    Unk02175620_84 *q;
    s32 n;
    s32 x;
    s32 z;
    s32 t;
    u16 r;
    s32 s;
    Unk020f41c4_B *g;

    switch (p->mState) {
        case 0:
            p->mUnk_b4 += 1;
            if (p->mUnk_b4 >= 3) {
                p->mUnk_b4 -= 3;
                p->mUnk_b0++;
                if (p->mUnk_b0 >= func_0209b634(gShine16)) {
                    p->mUnk_b0 -= func_0209b634(gShine16);
                }
                p->mUnk_bc++;
                if (p->mUnk_bc >= 8) {
                    p->mUnk_bc -= 8;
                    p->mUnk_b8 = p->mUnk_b8 == 0;
                }
            }
            p->mUnk_a8 += 0x19a;
            if (p->mUnk_a8 >= 0x1000) {
                p->mUnk_a8 = 0x1000;
            }
            p->mUnk_00.mUnk_10.y -= 0x19a;
            Vec3Add(&p->mUnk_00.mPos, &p->mUnk_00.mUnk_10, &p->mUnk_00.mPos);
            if (p->mUnk_00.mPos.y > p->mUnk_a4) {
                return;
            }
            p->mUnk_00.mPos.y = p->mUnk_a4;
            p->mUnk_00.mUnk_10.y = ((s64) p->mUnk_00.mUnk_10.y * -0x333) >> 12;
            if (p->mUnk_00.mUnk_10.y < 0x1000) {
                p->mUnk_00.mUnk_10.y = 0;
                p->mState = 1;
            }
            func_0210b98c(p->mUnk_00.mUnk_94, 0x139);
            return;
        case 1:
            p->mUnk_b4 += 1;
            if (p->mUnk_b4 >= 3) {
                p->mUnk_b4 -= 3;
                p->mUnk_b0++;
                if (p->mUnk_b0 >= func_0209b634(gShine16)) {
                    p->mUnk_b0 -= func_0209b634(gShine16);
                }
                p->mUnk_bc++;
                if (p->mUnk_bc >= 8) {
                    p->mUnk_bc -= 8;
                    p->mUnk_b8 = p->mUnk_b8 == 0;
                }
            }
            p->mUnk_a8 += 0x19a;
            if (p->mUnk_a8 >= 0x1000) {
                p->mUnk_a8 = 0x1000;
            }
            func_0210ba38(p->mUnk_00.mUnk_94, 0x14e);
            return;
        case 6:
            p->mUnk_b4 += 4;
            if (p->mUnk_b4 >= 3) {
                p->mUnk_b4 -= 3;
                p->mUnk_b0++;
                if (p->mUnk_b0 >= func_0209b634(gShine16)) {
                    p->mUnk_b0 -= func_0209b634(gShine16);
                }
                p->mUnk_bc++;
                if (p->mUnk_bc >= 8) {
                    p->mUnk_bc -= 8;
                    p->mUnk_b8 = p->mUnk_b8 == 0;
                }
            }
            p->mUnk_a8 -= 0x19a;
            if (p->mUnk_a8 > 0) {
                return;
            }
            p->mUnk_a8 = 0;
            func_020d2398(&p->mUnk_00);
            func_020a1218(-1);
            if (p->mUnk_c4 < 0) {
                return;
            }
            func_020a6cb4(p->mUnk_c4);
            return;
        case 2:
            p->mUnk_b4 += 4;
            if (p->mUnk_b4 >= 3) {
                p->mUnk_b4 -= 3;
                p->mUnk_b0++;
                if (p->mUnk_b0 >= func_0209b634(gShine16)) {
                    p->mUnk_b0 -= func_0209b634(gShine16);
                }
                p->mUnk_bc++;
                if (p->mUnk_bc >= 8) {
                    p->mUnk_bc -= 8;
                    p->mUnk_b8 = p->mUnk_b8 == 0;
                }
            }
            v = GetKart(p->mUnk_c8);
            p->mUnk_a0 += p->mUnk_00.mUnk_10.y;
            p->mUnk_00.mPos = *func_020a0ff0(p->mUnk_c8);
            p->mUnk_00.mPos.y += p->mUnk_a0 + (func_020a23a0(v) + 0x7800);
            p->mUnk_00.mUnk_10.y -= 0x333;
            if (p->mUnk_c0-- <= 0) {
                p->mUnk_c0 = 0;
                p->mUnk_a8 -= 0x19a;
                if (p->mUnk_a8 <= 0) {
                    p->mUnk_a8 = 0;
                    func_020d2398(&p->mUnk_00);
                    func_020a1218(-1);
                    if (p->mUnk_c4 >= 0) {
                        func_020a6cb4(p->mUnk_c4);
                    }
                }
                if (p->mUnk_a8 <= 0) {
                    func_02081f10(func_0208b7bc(0x7c, &v->mPos), v->mIndex, 0x16);
                }
            } else {
                p->mUnk_a8 += 0x19a;
                if (p->mUnk_a8 >= 0x1000) {
                    p->mUnk_a8 = 0x1000;
                }
            }
            if (p->mUnk_e4 == NULL) {
                return;
            }
            func_0208b5b0(p->mUnk_e4, &p->mUnk_00.mPos);
            p->mUnk_e8--;
            if (p->mUnk_e8 >= 0) {
                return;
            }
            func_0208b6b0(&p->mUnk_e4);
            return;
        case 3:
            p->mUnk_b4 += 4;
            if (p->mUnk_b4 >= 3) {
                p->mUnk_b4 -= 3;
                p->mUnk_b0++;
                if (p->mUnk_b0 >= func_0209b634(gShine16)) {
                    p->mUnk_b0 -= func_0209b634(gShine16);
                }
                p->mUnk_bc++;
                if (p->mUnk_bc >= 8) {
                    p->mUnk_bc -= 8;
                    p->mUnk_b8 = p->mUnk_b8 == 0;
                }
            }
            for (i = 0; i < 2; i++) {
                q = func_020a0f0c();
                n = q->mUnk_00.y - func_020a0ff0(p->mUnk_c8)->y;
                if (n <= 0) {
                    n = -n;
                }
                if (n < 0x14000) {
                    x = (q->mUnk_00.x - func_020a0ff0(p->mUnk_ca)->x) >> 12;
                    z = (q->mUnk_00.z - func_020a0ff0(p->mUnk_ca)->z) >> 12;
                    n = x * x + z * z;
                    if (p->mUnk_ca == p->mUnk_c8) {
                        if (n < 0x9c400 && n > p->mUnk_d8) {
                            p->mUnk_d8 = n;
                            p->mUnk_cc.x = q->mUnk_00.x;
                            p->mUnk_cc.y = q->mUnk_00.y;
                            p->mUnk_cc.z = q->mUnk_00.z;
                            p->mUnk_dc++;
                        }
                    } else {
                        if (n < 0x9c400 && n < p->mUnk_d8) {
                            p->mUnk_d8 = n;
                            p->mUnk_cc.x = q->mUnk_00.x;
                            p->mUnk_cc.y = q->mUnk_00.y;
                            p->mUnk_cc.z = q->mUnk_00.z;
                            p->mUnk_dc++;
                        }
                    }
                }
            }
            p->mUnk_a0 += p->mUnk_00.mUnk_10.y;
            p->mUnk_00.mPos = *func_020a0ff0(p->mUnk_c8);
            p->mUnk_00.mPos.y += p->mUnk_a0 + (func_020a23a0(GetKart(p->mUnk_c8)) + 0x7800);
            p->mUnk_00.mUnk_10.y -= 0x52;
            p->mUnk_a8 += 0x19a;
            if (p->mUnk_a8 >= 0x1000) {
                p->mUnk_a8 = 0x1000;
            }
            if (p->mUnk_00.mUnk_10.y > 0) {
                return;
            }
            if (p->mUnk_dc > 0) {
                g = &gRaceProgress->mRandom;
                g->mUnk_00 = g->mUnk_08 * g->mUnk_00 + g->mUnk_10;
                r = (u16) (((u64) (u32) (g->mUnk_00 >> 32) * 0x10000) >> 32);
                g = &gRaceProgress->mRandom;
                g->mUnk_00 = g->mUnk_08 * g->mUnk_00 + g->mUnk_10;
                s = ((u64) (u32) (g->mUnk_00 >> 32) * 0x14000) >> 32;
                x = p->mUnk_cc.x + (s32) (((s64) s * gPairsByAngle[(r >> 4) * 2]) >> 12) - p->mUnk_00.mPos.x;
                z = p->mUnk_cc.z + (s32) (((s64) s * gPairsByAngle[(r >> 4) * 2 + 1]) >> 12) - p->mUnk_00.mPos.z;
                p->mState = 4;
                p->mUnk_00.mUnk_10.x = ((s64) x * 0x25) >> 12;
                p->mUnk_00.mUnk_10.y = 0x5000;
                p->mUnk_00.mUnk_10.z = ((s64) z * 0x25) >> 12;
                p->mUnk_a8 = 0x1000;
                p->mUnk_00.mFlags &= ~1;
                return;
            }
            p->mState = 5;
            p->mUnk_00.mUnk_10.x = 0;
            p->mUnk_00.mUnk_10.y = 0x5000;
            p->mUnk_00.mUnk_10.z = 0;
            p->mUnk_a8 = 0x1000;
            p->mUnk_00.mFlags &= ~1;
            return;
        case 5:
            p->mUnk_b4 += 1;
            if (p->mUnk_b4 >= 3) {
                p->mUnk_b4 -= 3;
                p->mUnk_b0++;
                if (p->mUnk_b0 >= func_0209b634(gShine16)) {
                    p->mUnk_b0 -= func_0209b634(gShine16);
                }
                p->mUnk_bc++;
                if (p->mUnk_bc >= 8) {
                    p->mUnk_bc -= 8;
                    p->mUnk_b8 = p->mUnk_b8 == 0;
                }
            }
            p->mUnk_a8 += 0x19a;
            if (p->mUnk_a8 >= 0x1000) {
                p->mUnk_a8 = 0x1000;
            }
            p->mUnk_00.mUnk_10.y -= 0x19a;
            Vec3Add(&p->mUnk_00.mPos, &p->mUnk_00.mUnk_10, &p->mUnk_00.mPos);
            if (p->mUnk_00.mUnk_10.y >= 0) {
                return;
            }
            p->mState = 6;
            p->mUnk_00.mFlags |= data_021567a0;
            return;
        case 4:
            p->mUnk_b4 += 1;
            if (p->mUnk_b4 >= 3) {
                p->mUnk_b4 -= 3;
                p->mUnk_b0++;
                if (p->mUnk_b0 >= func_0209b634(gShine16)) {
                    p->mUnk_b0 -= func_0209b634(gShine16);
                }
                p->mUnk_bc++;
                if (p->mUnk_bc >= 8) {
                    p->mUnk_bc -= 8;
                    p->mUnk_b8 = p->mUnk_b8 == 0;
                }
            }
            p->mUnk_a8 += 0x19a;
            if (p->mUnk_a8 >= 0x1000) {
                p->mUnk_a8 = 0x1000;
            }
            p->mUnk_00.mUnk_10.y -= 0x19a;
            Vec3Add(&p->mUnk_00.mPos, &p->mUnk_00.mUnk_10, &p->mUnk_00.mPos);
            if (p->mUnk_00.mUnk_10.y < 0 && p->mUnk_00.mPos.y <= p->mUnk_cc.y + p->mUnk_00.mUnk_58.x) {
                if (func_020d3c94(&p->mUnk_00, 0, &b)) {
                    t = p->mUnk_00.mUnk_10.y;
                    Vec3Add(&p->mUnk_00.mPos, &b, &p->mUnk_00.mPos);
                    func_020ea94c(&p->mUnk_00.mUnk_10, &b, 0x1000, 0x1000, 0x800, &p->mUnk_00.mUnk_10);
                    p->mUnk_00.mUnk_10.y = 0;
                    if ((s64) p->mUnk_00.mUnk_10.x * p->mUnk_00.mUnk_10.x +
                            (s64) p->mUnk_00.mUnk_10.y * p->mUnk_00.mUnk_10.y +
                            (s64) p->mUnk_00.mUnk_10.z * p->mUnk_00.mUnk_10.z >=
                        0x10) {
                        func_02039860(&p->mUnk_00.mUnk_10, &p->mUnk_00.mUnk_10);
                    }
                    p->mUnk_00.mUnk_10.x = ((s64) p->mUnk_00.mUnk_10.x * 0x1000) >> 12;
                    p->mUnk_00.mUnk_10.y = ((s64) p->mUnk_00.mUnk_10.y * 0x1000) >> 12;
                    p->mUnk_00.mUnk_10.z = ((s64) p->mUnk_00.mUnk_10.z * 0x1000) >> 12;
                    p->mUnk_00.mUnk_10.y = t;
                }
                c.x = p->mUnk_00.mPos.x;
                c.y = p->mUnk_00.mUnk_58.x + (p->mUnk_00.mPos.y - 0x14000);
                c.z = p->mUnk_00.mPos.z;
                if (func_01ffdee4(&c, NULL, 0, p->mUnk_00.mUnk_58.x, 8, -2, &b, &d, &e.x, &f, NULL, NULL, NULL, NULL)) {
                    Vec3Add(&p->mUnk_00.mPos, &b, &p->mUnk_00.mPos);
                    if (f & 0x214300) {
                        t = p->mUnk_00.mUnk_10.y;
                        func_020eaa14(&p->mUnk_00.mUnk_10, &e, 0x1000, 0x1000, 0x800, &p->mUnk_00.mUnk_10);
                        p->mUnk_00.mUnk_10.y = 0;
                        if ((s64) p->mUnk_00.mUnk_10.x * p->mUnk_00.mUnk_10.x +
                                (s64) p->mUnk_00.mUnk_10.y * p->mUnk_00.mUnk_10.y +
                                (s64) p->mUnk_00.mUnk_10.z * p->mUnk_00.mUnk_10.z >=
                            0x10) {
                            func_02039860(&p->mUnk_00.mUnk_10, &p->mUnk_00.mUnk_10);
                        }
                        p->mUnk_00.mUnk_10.x = ((s64) p->mUnk_00.mUnk_10.x * 0x1000) >> 12;
                        p->mUnk_00.mUnk_10.y = ((s64) p->mUnk_00.mUnk_10.y * 0x1000) >> 12;
                        p->mUnk_00.mUnk_10.z = ((s64) p->mUnk_00.mUnk_10.z * 0x1000) >> 12;
                        p->mUnk_00.mUnk_10.y = t;
                    }
                    if (f & 0x1e34ef) {
                        p->mUnk_00.mUnk_10.x = ((s64) p->mUnk_00.mUnk_10.x * 0x19a) >> 12;
                        p->mUnk_00.mUnk_10.y = ((s64) p->mUnk_00.mUnk_10.y * -0x333) >> 12;
                        p->mUnk_00.mUnk_10.z = ((s64) p->mUnk_00.mUnk_10.z * 0x19a) >> 12;
                        if (p->mUnk_00.mUnk_10.y < 0x1000) {
                            p->mUnk_00.mUnk_10.y = 0;
                            p->mState = 1;
                        }
                        func_0210b98c(p->mUnk_00.mUnk_94, 0x139);
                    }
                    if (f & 0x1000000) {
                        p->mUnk_00.mFlags |= data_021567ac;
                    } else {
                        p->mUnk_00.mFlags &= ~0x20;
                    }
                }
            }
            if (p->mUnk_00.mPos.y >= 0) {
                return;
            }
            p->mState = 6;
            p->mUnk_00.mFlags |= data_021567a0;
            return;
    }
}

void func_020a5918(void) {
    Unk0209bfa8 *p;

    p = func_0209bfa8(func_020a6ae4, NULL, NULL, 1, 0);
    p->mUnk_38 = 0x190000;
    p->mUnk_3c = -0x190000;
}

u32 func_020a58f4(void) {
    return func_0209bef0(CreateShine16, DrawShine16, func_020a6a90);
}

u32 func_020a58d0(void) {
    return func_0209bf1c(func_020a69a0, func_020a683c, func_020a697c);
}

u32 func_020a58b4(void) {
    return func_0209bf48(NULL, UpdateShine16, NULL);
}

void func_020a5848(void) {
    s32 i;
    MapObject *o;
    Unk020e6fd4 *l;

    l = func_02100138(0x6a);
    if (l == NULL) {
        return;
    }
    for (i = 0; i < l->mUnk_04 && (o = l->mUnk_00[i]) != NULL; i++) {
        if ((o->mFlags & 0x100) == 0) {
            func_020d2398(o);
        }
    }
}

void func_020a5744(Vec3 *a, s32 b, s32 c) {
    Shine16 *p;

    p = func_0209bbfc(func_02100138(0x6a));
    if (p == NULL) {
        return;
    }
    if (c != 0) {
        p->mUnk_00.mPos.x = a->x;
        p->mUnk_00.mPos.y = a->y + 0x32000;
        p->mUnk_00.mPos.z = a->z;
        p->mUnk_00.mUnk_10.x = 0;
        p->mUnk_00.mUnk_10.y = 0x2800;
        p->mUnk_00.mUnk_10.z = 0;
        p->mUnk_a0 = 0;
        p->mUnk_a4 = a->y + 0x14000;
        p->mState = 0;
    } else {
        p->mUnk_00.mPos.x = a->x;
        p->mUnk_00.mPos.y = a->y + 0x14000;
        p->mUnk_00.mPos.z = a->z;
        p->mUnk_00.mUnk_10.x = 0;
        p->mUnk_00.mUnk_10.y = 0;
        p->mUnk_00.mUnk_10.z = 0;
        p->mUnk_a0 = 0;
        p->mUnk_a4 = 0;
        p->mState = 1;
    }
    p->mUnk_a8 = 0;
    p->mUnk_c0 = 0;
    p->mUnk_c4 = b;
    p->mUnk_00.mFlags &= ~1;
    p->mUnk_00.mFlags &= ~0x20;
    func_020a1218(1);
    func_0210b98c(p->mUnk_00.mUnk_94, 0x138);
}

void func_020a5608(Kart *a, Kart *b) {
    Shine16 *p;
    s32 r;
    u16 c;
    s32 n;

    p = func_0209bbfc(func_02100138(0x6a));
    if (p == NULL) {
        return;
    }
    p->mUnk_00.mFlags = p->mUnk_00.mFlags | data_021567a0;
    p->mUnk_00.mFlags &= ~0x20;
    p->mUnk_00.mPos.x = a->mPos.x;
    p->mUnk_00.mPos.y = a->mPos.y;
    p->mUnk_00.mPos.z = a->mPos.z;
    p->mUnk_00.mUnk_10.x = 0;
    p->mUnk_00.mUnk_10.y = 0x1000;
    p->mUnk_00.mUnk_10.z = 0;
    p->mUnk_c8 = a->mIndex;
    p->mUnk_ca = b->mIndex;
    p->mUnk_a0 = 0;
    p->mUnk_a4 = 0;
    p->mUnk_a8 = 0;
    p->mUnk_c0 = 0;
    p->mState = 3;
    p->mUnk_cc = b->mPos;
    if (b == a) {
        p->mUnk_d8 = 0;
    } else {
        p->mUnk_d8 = 0x9c400;
    }
    p->mUnk_dc = 0;
    p->mUnk_c4 = -1;
    func_020a1218(1);
    r = a->mIndex == data_021759c0->mEntryIndex ? 1 : 0;
    c = func_020a1180();
    n = func_020a1154(a->mIndex);
    func_0210b98c(p->mUnk_00.mUnk_94, func_02024974(1, r, c, n));
}

BOOL func_020a5268(u16 a, u16 b) {
    Kart *o;
    Unk020a3fa8_a4 *e;
    Balloon *f;
    Balloon *l;
    Vec3 v;
    s32 n;

    o = GetKart(a);
    func_020a2378();
    if (func_020a1154(b) >= 3 || func_020a1154(a) == 0) {
        e = func_020a2378() + a;
        f = func_020a2204(a) != 0 ? e->mUnk_10[func_020a1154(a)] : 0;
        l = func_020a1154(a) != 0 ? e->mUnk_10[func_020a1154(a) - 1] : 0;
        if (func_020a1154(a) != 0 && l != NULL) {
            if (func_020a2204(a) != 0 && f != NULL) {
                e->mUnk_10[func_020a1154(a)] = l;
                func_020a10f0(a, -1);
                e->mUnk_10[func_020a1154(a)] = f;
            } else {
                func_020a10f0(a, -1);
            }
        }
        if (l != NULL) {
            if (a == data_021759c0->mEntryIndex) {
                func_020a2ebc(l, NULL);
            } else {
                v.x = o->mPos.x;
                v.y = o->mPos.y + func_020a23a0(o) - 0xf666;
                v.z = o->mPos.z;
                l->mUnk_00.mFlags &= ~4;
                l->mUnk_00.mFlags &= ~2;
                l->mUnk_00.mFlags &= ~8;
                l->mUnk_00.mUnk_66 = 0x1f;
                func_020a2ebc(l, &v);
            }
            func_020d26ec(o, 0x153);
            if (func_020a1154(a) == 0) {
                func_020a16d0(a);
            }
            return FALSE;
        }
    } else {
        e = func_020a2378() + a;
        f = func_020a2204(a) != 0 ? e->mUnk_10[func_020a1154(a)] : 0;
        l = func_020a1154(a) != 0 ? e->mUnk_10[func_020a1154(a) - 1] : 0;
        if (func_020a1154(a) != 0 && l != NULL) {
            if (func_020a2204(a) != 0 && f != NULL) {
                e->mUnk_10[func_020a1154(a)] = l;
                func_020a10f0(a, -1);
                e->mUnk_10[func_020a1154(a)] = f;
            } else {
                func_020a10f0(a, -1);
            }
        }
        if (l != NULL) {
            e = func_020a2378() + b;
            n = func_020a1154(b);
            e->mUnk_10[n + 1] = e->mUnk_10[func_020a1154(b)];
            e->mUnk_10[func_020a1154(b)] = l;
            func_020a10f0(b, 1);
            func_020a2e68(l);
            func_020a2e58(l, b);
            if (func_020a1154(b) >= 2 && func_020a2204(b) != 0) {
                e->mUnk_34 = 4;
            }
            func_02081f10(func_0208b7bc(0x7a, &o->mPos), o->mIndex, 0x20);
            func_02081f10(func_0208b7bc(0x7b, &o->mPos), o->mIndex, 0x20);
            func_020d26ec(GetKart(b), 0x14f);
            if (func_020a1154(a) == 0) {
                func_020a16d0(a);
            }
            return TRUE;
        }
    }
    return FALSE;
}

s32 func_020a4f54(u16 a, u16 b) {
    Unk020a3fa8_a4 *v1;
    Unk020a3fa8_a4 *v2;
    Balloon *f;
    Balloon *l;
    Balloon *g;
    Balloon *m;
    Unk0210b7a8 s;
    s32 n;

    v1 = func_020a2378();
    v1 += a;
    f = func_020a2204(a) != 0 ? v1->mUnk_10[func_020a1154(a)] : 0;
    l = func_020a1154(a) != 0 ? v1->mUnk_10[func_020a1154(a) - 1] : 0;
    if (func_020a1154(a) != 0 && l != NULL) {
        if (func_020a2204(a) != 0 && f != NULL) {
            v1->mUnk_10[func_020a1154(a)] = l;
            func_020a10f0(a, -1);
            v1->mUnk_10[func_020a1154(a)] = f;
        } else {
            func_020a10f0(a, -1);
        }
    }
    v2 = func_020a2378();
    v2 += b;
    g = func_020a2204(b) != 0 ? v2->mUnk_10[func_020a1154(b)] : 0;
    m = func_020a1154(b) != 0 ? v2->mUnk_10[func_020a1154(b) - 1] : 0;
    if (func_020a1154(b) != 0 && m != NULL) {
        if (func_020a2204(b) != 0 && g != NULL) {
            v2->mUnk_10[func_020a1154(b)] = m;
            func_020a10f0(b, -1);
            v2->mUnk_10[func_020a1154(b)] = g;
        } else {
            func_020a10f0(b, -1);
        }
    }
    if (l != NULL) {
        v2 = func_020a2378();
        v2 += b;
        n = func_020a1154(b);
        v2->mUnk_10[n + 1] = v2->mUnk_10[func_020a1154(b)];
        v2->mUnk_10[func_020a1154(b)] = l;
        func_020a10f0(b, 1);
        func_020a2e68(l);
        func_020a2e58(l, b);
        if (func_020a1154(b) >= 2 && func_020a2204(b) != 0) {
            v2->mUnk_34 = 4;
        }
    }
    if (m != NULL) {
        v1 = func_020a2378();
        v1 += a;
        n = func_020a1154(a);
        v1->mUnk_10[n + 1] = v1->mUnk_10[func_020a1154(a)];
        v1->mUnk_10[func_020a1154(a)] = m;
        func_020a10f0(a, 1);
        func_020a2e68(m);
        func_020a2e58(m, a);
        if (func_020a1154(a) >= 2 && func_020a2204(a) != 0) {
            v1->mUnk_34 = 4;
        }
    }
    if (a == data_021759c0->mEntryIndex || b == data_021759c0->mEntryIndex) {
        s.mUnk_00 = 0x14f;
        s.mUnk_04 = NULL;
        s.mUnk_08 = 2;
        s.mUnk_0c = func_020d4ef4(NULL);
        func_0210b7a8(&s);
    }
    return 1;
}

BOOL func_020a4d94(u16 a, u16 b) {
    Kart *o;
    Unk020a3fa8_a4 *e;
    Balloon *f;
    Balloon *l;
    Vec3 v;

    e = func_020a2378() + a;
    f = func_020a2204(a) != 0 ? e->mUnk_10[func_020a1154(a)] : 0;
    l = func_020a1154(a) != 0 ? e->mUnk_10[func_020a1154(a) - 1] : 0;
    if (func_020a1154(a) != 0 && l != NULL) {
        if (func_020a2204(a) != 0 && f != NULL) {
            e->mUnk_10[func_020a1154(a)] = l;
            func_020a10f0(a, -1);
            e->mUnk_10[func_020a1154(a)] = f;
        } else {
            func_020a10f0(a, -1);
        }
    }
    if (l != NULL) {
        o = GetKart(a);
        func_020a2378();
        if (a == data_021759c0->mEntryIndex) {
            func_020a2ebc(l, NULL);
        } else {
            v.x = o->mPos.x;
            v.y = o->mPos.y + func_020a23a0(o) - 0xf666;
            v.z = o->mPos.z;
            l->mUnk_00.mFlags &= ~4;
            l->mUnk_00.mFlags &= ~2;
            l->mUnk_00.mFlags &= ~8;
            l->mUnk_00.mUnk_66 = 0x1f;
            func_020a2ebc(l, &v);
        }
        func_020d26ec(o, 0x153);
        if (func_020a1154(a) == 0) {
            func_020a16d0(a);
        }
        return TRUE;
    }
    return FALSE;
}

void func_020a4c58(u16 a) {
    Unk020a3fa8_a4 *e;
    Balloon *f;
    Balloon *l;

    if (data_021759c0->mMode != 2) {
        return;
    }
    func_020a4d94(a, a);
    if (func_020a1154(a) == 0) {
        return;
    }
    do {
        e = func_020a2378() + a;
        f = func_020a2204(a) != 0 ? e->mUnk_10[func_020a1154(a)] : 0;
        l = func_020a1154(a) != 0 ? e->mUnk_10[func_020a1154(a) - 1] : 0;
        if (func_020a1154(a) != 0 && l != NULL) {
            if (func_020a2204(a) != 0 && f != NULL) {
                e->mUnk_10[func_020a1154(a)] = l;
                func_020a10f0(a, -1);
                e->mUnk_10[func_020a1154(a)] = f;
            } else {
                func_020a10f0(a, -1);
            }
        }
        if (l != NULL) {
            func_020a2f0c(l, a);
        }
    } while (func_020a1154(a) != 0);
}

void func_020a4c20(void) {
    if (data_021759c0->mMode != 2) {
        return;
    }
    func_020a305c();
}

void func_020a4b70(u16 a, Vec3 *b) {
    Unk020a3fa8_a4 *e;
    Balloon *p;
    s32 i;
    s32 n;

    e = func_020a2378() + a;
    if (b == NULL) {
        return;
    }
    n = (func_020a2204(a) != 0 ? 1 : 0) + func_020a1154(a);
    i = 0;
    if (n <= 0) {
        return;
    }
    do {
        p = e->mUnk_10[i];
        p->mUnk_00.mPos.x += b->x;
        p->mUnk_00.mPos.y += b->y;
        p->mUnk_00.mPos.z += b->z;
        i++;
    } while (i < n);
}

void func_020a49d4(Unk020a3fa8 *a) {
    Unk021759c0 *d;
    s32 n;
    s32 i;
    Unk020a3fa8_a4 *p;
    s32 j;
    s32 w;
    s32 v;

    if (func_020d3bf8(0x6c) == 0) {
        d = data_021759c0;
        n = d->mKartCount;
        if (d->mMode == 2) {
            func_020ac588(0x6c, 0x20, a);
        } else {
            func_020ac588(0x6c, 4, a);
        }
        for (i = 0; i < n; i++) {
            p = &a->mUnk_0a4[i];
            if (a->mUnk_000.mCourseMapRow->mUnk_2c != 0) {
                p->mUnk_30 = a->mUnk_000.mCourseMapRow->mUnk_2c;
            } else {
                switch (data_021759c0->mCurrentEntries[(u16) i].mPlayer.mTeamIndex) {
                    case 0:
                        p->mUnk_30 = 1;
                        break;
                    case 1:
                        p->mUnk_30 = 3;
                        break;
                    default:
                        p->mUnk_30 = i;
                        break;
                }
            }
        }
        for (i = 0, w = 0; i < 8; i++, w -= 0x600) {
            for (j = 0, v = w; j < 8; j++, v += 0xc00) {
                a->mUnk_264[i][j] = v;
            }
        }
        if (func_02062ec4() != 0) {
            a->mUnk_0a0 = 0xffff;
        } else {
            a->mUnk_0a0 = 0x3c;
        }
        func_020a238c(a->mUnk_0a4);
        func_020a2364((u32) func_020a5268);
        func_020a2350((u32) func_020a4f54);
        func_020a233c(func_020a4d94);
        func_020a2328(func_020a4c58);
        func_020a2314(func_020a4c20);
        func_020a2300((u32) func_020a4b70);
    } else {
        func_020d2398(&a->mUnk_000);
    }
}

void func_020a3fa8(void *b, Unk020a3fa8 *c) {
    Balloon *o;
    s32 i;
    s32 j;
    s32 n;
    s32 m;
    s32 a;
    s32 s;
    s32 d;
    Vec3 v;
    Vec3 t;
    Vec3 t2;
    Vec3 *q;

    n = data_021759c0->mKartCount;
    if (c->mUnk_0a0 > 0) {
        c->mUnk_0a0--;
        if (c->mUnk_0a0 > 0) {
            return;
        }
        for (i = 0; i < n; i++) {
            Unk020a3fa8_a4 *e = &c->mUnk_0a4[i];
            GetKart((u16) i);
            e->mUnk_34 = 1;
            if (c->mUnk_000.mCourseMapRow->mUnk_28 != 0 || c->mUnk_000.mCourseMapRow->mUnk_2a != 0) {
                e->mUnk_04 = c->mUnk_000.mCourseMapRow->mUnk_28;
                func_020a10ac(i, c->mUnk_000.mCourseMapRow->mUnk_28 + c->mUnk_000.mCourseMapRow->mUnk_2a);
            } else {
                e->mUnk_04 = 1;
                func_020a10ac(i, 5);
            }
        }
        return;
    }
    for (i = 0; i < n; i++) {
        Kart *p;
        Unk020a3fa8_a4 *e = &c->mUnk_0a4[i];
        func_020748a8();
        p = GetKart((u16) i);
        v.x = p->mPos.x;
        v.y = p->mPos.y + func_020a23a0(p) - 0xf666;
        v.z = p->mPos.z;
        switch (e->mUnk_34) {
            case 0:
                if (e->mUnk_00 > 0) {
                    e->mUnk_00--;
                    break;
                }
                if (func_020a10d4(i) == 0) {
                    break;
                }
                if (func_020a1154(i) >= 3) {
                    break;
                }
                if (func_020a2264(i) <= 0 && func_020a223c(i) <= 0) {
                    break;
                }
                o = func_020a2fe4(e->mUnk_30, &v);
                if (o == NULL) {
                    break;
                }
                e->mUnk_10[func_020a1154(i)] = o;
                func_020a2f9c(o, i, 0xcd);
                e->mUnk_34 = 2;
                func_020a2220(i, 1);
                func_020a10ac(i, -1);
                break;
            case 1:
                if (func_020a2204(i) != 0) {
                    func_020a2f9c(e->mUnk_10[func_020a1154(i)], i, 0x266);
                    break;
                }
                if (func_020a10d4(i) != 0 && func_020a1154(i) < 3) {
                    if (e->mUnk_04 > 0) {
                        o = func_020a2fe4(e->mUnk_30, &v);
                        if (o != NULL) {
                            e->mUnk_10[func_020a1154(i)] = o;
                            func_020a2f9c(o, i, 0x266);
                            func_020a2220(i, 1);
                            func_020a10ac(i, -1);
                            e->mUnk_04--;
                        }
                    }
                } else {
                    e->mUnk_34 = 0;
                }
                break;
            case 2:
                if (func_020a2264(i) < 0) {
                    e->mUnk_34 = 4;
                    break;
                }
                o = e->mUnk_10[func_020a1154(i)];
                func_020a2f9c(o, i, 0xcd);
                if (func_020a2e60(o) >= 0x800) {
                    e->mUnk_34 = 3;
                }
                break;
            case 3:
                if (func_020a2264(i) < 0) {
                    e->mUnk_34 = 4;
                    break;
                }
                if (func_020a223c(i) > 0) {
                    func_020a2f9c(e->mUnk_10[func_020a1154(i)], i, 0x10);
                } else if (func_020a2264(i) > 0) {
                    func_020a2f9c(e->mUnk_10[func_020a1154(i)], i, 0x29);
                } else {
                    o = e->mUnk_10[func_020a1154(i)];
                    func_020a2f30(o, i, 0xe);
                    if (func_020a2e60(o) <= 0x400) {
                        e->mUnk_34 = 4;
                    }
                }
                break;
            case 4:
                func_020a2f30(e->mUnk_10[func_020a1154(i)], i, 0x19a);
                break;
        }
        if (func_020a2204(i) != 0) {
            o = e->mUnk_10[func_020a1154(i)];
            if (func_020a2e60(o) <= 0) {
                e->mUnk_10[func_020a1154(i)] = NULL;
                func_020a2220(i, 0);
                func_020a10ac(i, 1);
                e->mUnk_00 = 0;
                e->mUnk_34 = 0;
            } else if (func_020a2e60(o) >= 0x1000) {
                func_020a2220(i, 0);
                func_020a10f0(i, 1);
                if (e->mUnk_04 <= 0) {
                    e->mUnk_00 = 30;
                    e->mUnk_34 = 0;
                }
                func_020d26ec(GetKart((u16) i), 0x152);
            }
        } else if (e->mUnk_04 <= 0) {
            e->mUnk_34 = 0;
        }
        if (i == data_021759c0->mEntryIndex) {
            if (func_020a2264(i) > 0 || func_020a223c(i) > 0) {
                s = func_020a1154(i) >= 3 ? 600 : 300;
                d = func_020a1154(i) >= 3 ? 200 : 100;
                e->mUnk_08 += e->mUnk_0c;
                if (e->mUnk_08 >= 0) {
                    if (e->mUnk_0c < 0) {
                        e->mUnk_0c = -s;
                    } else {
                        e->mUnk_0c -= d;
                    }
                } else {
                    if (e->mUnk_0c >= 0) {
                        e->mUnk_0c = s;
                    } else {
                        e->mUnk_0c += d;
                    }
                }
            } else {
                s = func_020a1154(i) >= 3 ? 600 : 300;
                if (e->mUnk_08 >= 0) {
                    e->mUnk_08 = e->mUnk_08 < s ? 0 : e->mUnk_08 - s;
                } else {
                    e->mUnk_08 = e->mUnk_08 > -s ? 0 : e->mUnk_08 + s;
                }
            }
            m = func_020a1154(i) + (func_020a2204(i) != 0 ? 1 : 0);
            for (j = 0; j < m; j++) {
                Balloon *o = e->mUnk_10[j];
                a = e->mUnk_08 + c->mUnk_264[m - 1][j];
                if (a != 0) {
                    q = &p->mUnk_150;
                    t.x = (s32) (((s64) q->x * a) >> 12);
                    t.y = (s32) (((s64) q->y * a) >> 12);
                    t.z = (s32) (((s64) q->z * a) >> 12);
                    func_020a2e74(o, &t);
                }
                if ((j & 1) == 1) {
                    q = &p->mUnk_168;
                    t2.x = (s32) (((s64) q->x * -0xcd) >> 12);
                    t2.y = (s32) (((s64) q->y * -0xcd) >> 12);
                    t2.z = (s32) (((s64) q->z * -0xcd) >> 12);
                    func_020a2e74(o, &t2);
                }
                func_020a2e88(o, &v, &p->mVelocity);
                func_020a2e58(o, i);
                func_020a2e4c(o, 1, NULL);
                o->mUnk_00.mFlags &= ~4;
                o->mUnk_00.mFlags &= ~2;
                o->mUnk_00.mFlags &= ~8;
                o->mUnk_00.mUnk_66 = 0x1f;
            }
        } else {
            m = func_020a1154(i) + (func_020a2204(i) != 0 ? 1 : 0);
            for (j = 0; j < m; j++) {
                o = e->mUnk_10[j];
                func_020a2e88(o, &v, &p->mVelocity);
                func_020a2e58(o, i);
                if (j == 0) {
                    func_020a2e4c(o, m, e->mUnk_10);
                    o->mUnk_00.mFlags &= ~4;
                    o->mUnk_00.mFlags &= ~2;
                    o->mUnk_00.mFlags &= ~8;
                    o->mUnk_00.mUnk_66 = 0x1f;
                } else {
                    func_020a2e4c(o, 0, NULL);
                    o->mUnk_00.mFlags |= data_02156794;
                    o->mUnk_00.mFlags |= data_02156798;
                    o->mUnk_00.mFlags |= data_0215679c;
                }
            }
        }
    }
}

u32 func_020a3f48(void) {
    Unk021759c0 *d;
    s32 k;

    d = data_021759c0;
    k = d->mMode;
    if (k == 2 && d->mUnk_18 == 0) {
        return func_0209bf8c();
    }
    if (k != 4) {
        return 0;
    }
    return func_0209bf8c();
}

u32 func_020a3f2c(void) {
    return func_0209bf48(NULL, func_020a3fa8, NULL);
}
