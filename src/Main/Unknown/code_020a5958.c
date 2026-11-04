#include "Main/Unknown/code_02024974.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0208b498.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_020a02f8.h"
#include "Main/Unknown/code_020a100c.h"
#include "Main/Unknown/code_020a10f0.h"
#include "Main/Unknown/code_020a5958.h"

#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020a6cb4.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_0209b000.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02109110.h"
#include "Main/Unknown/code_0210b870.h"
#include "Main/Unknown/code_020d22e0.h"
#include "Main/Unknown/code_020a1218.h"
#include "Main/Unknown/code_020a0ff0.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_02081000.h"
#include "Main/Unknown/code_02081618.h"
#include "Main/Unknown/code_0208b6b0.h"
#include "Main/Unknown/code_020d3c94.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_02039860.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ffdee4.h"
#include "Main/Unknown/code_0210bae8.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020a6000.h"
#include "Main/Unknown/code_020a2000.h"
#include "Main/Unknown/code_020a0000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/code_020a683c.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/code_020e516c.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020a69a0.h"
#include "Main/Unknown/code_020a69b4.h"
#include "Main/Unknown/code_02024000.h"
#include "Main/Unknown/code_020a1000.h"
#include "Main/Unknown/unk_02167000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020a6c64.h"
#include "Main/Unknown/unk_0217c000.h"

void func_020a6c64(u32 arg0) {
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
    func_0210bae8(value0);
    value0 = (u32) &data_0217ca6c;
    value0 = (u32) * (const u32 *) ((value0) + (428));
    *(u32 *) ((value4) + (112)) = value0;
}

u32 func_020a6ae4(Unk020a5958 *p, Unk0206bcb0 *o, u8 *a, u8 *b) {
    u8 v1;
    u8 v2;
    s32 r;
    u16 c;
    s32 n;

    v1 = *a;
    v2 = *b;
    if (o->mState != 0 || (o->mUnk_48 & 0x200) != 0 || func_020a1084(o->mIndex) != 0) {
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
        p->mUnk_00.mPos.x = o->mUnk_80.x;
        p->mUnk_00.mPos.y = o->mUnk_80.y + func_020a23a0(o) + 0x7800;
        p->mUnk_00.mPos.z = o->mUnk_80.z;
        p->mUnk_a0 = 0;
        p->mUnk_00.mUnk_10.x = 0;
        p->mUnk_00.mUnk_10.y = 0x3000;
        p->mUnk_00.mUnk_10.z = 0;
        p->mUnk_a8 = 0;
        p->mUnk_e0 = 2;
        p->mUnk_c8 = o->mIndex;
        p->mUnk_ca = o->mIndex;
        func_020a10ac(o->mIndex, 1);
        func_020a10f0(o->mIndex, 1);
        r = o->mIndex == data_021759c0->mUnk_62 ? 1 : 0;
        c = func_020a1180();
        n = func_020a1154(o->mIndex);
        func_0210b98c(p->mUnk_00.mUnk_94, func_02024974(0, r, c, n));
        p->mUnk_e4 = func_0208b7bc(0x7d, &p->mUnk_00.mPos);
        p->mUnk_e8 = 0xe;
    }
    return v2;
}

void CreateShine16(void *a) {
    gShine16 = func_0209bc74(a, gShine16NsbmdName, gShine16NsbtpName);
    func_0209b940(gShine16, 0x3f);
}

void func_020a6a90(void *a) {
    func_0209bbd0(a, gShine16);
}

void func_020a69b4(void *a, Unk020a5958 *p) {
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
    func_01ff9048(0x1b, &p->mUnk_00.mUnk_1c, 3);
    func_0209b7a0(gShine16, p->mUnk_b8, 0);
    func_0209b688(gShine16, (u16) p->mUnk_b0);
    func_0209bb2c(a, gShine16, p);
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

void func_020a683c(void *a, Unk020a5958 *p, void *b, s32 c) {
    s32 t;
    s32 m[9];
    Vec3 s;
    Vec3 u;
    s32 n;
    s32 x;

    if (p->mUnk_a8 <= 0) {
        return;
    }
    if (p->mUnk_e0 == 2) {
        return;
    }
    if (p->mUnk_e0 == 3) {
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
    func_01ff9048(0x1b, &p->mUnk_00.mUnk_1c, 3);
    x = data_021567a4[data_0217b220] >> 4;
    Matrix3x3FromPairY(m, data_0215d4b4[x * 2 + 1], data_0215d4b4[x * 2]);
    func_01ff9048(0x1a, m, 9);
    u.x = 0x2000;
    u.y = 0x2000;
    u.z = 0x2000;
    func_01ff9048(0x1b, &u, 3);
    func_020e5348(8, c);
}

void func_020a5958(void *a, Unk020a5958 *p) {
    Vec3 c;
    Vec3 b;
    Vec3 d;
    Vec3 e;
    u32 f;
    Unk0206bcb0 *v;
    s32 i;
    Unk02175620_84 *q;
    s32 n;
    s32 x;
    s32 z;
    s32 t;
    u16 r;
    s32 s;
    Unk020f41c4_B *g;

    switch (p->mUnk_e0) {
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
                p->mUnk_e0 = 1;
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
            v = func_0207a974(p->mUnk_c8);
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
                    func_02081f10(func_0208b7bc(0x7c, &v->mUnk_80), v->mIndex, 0x16);
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
            p->mUnk_00.mPos.y += p->mUnk_a0 + (func_020a23a0(func_0207a974(p->mUnk_c8)) + 0x7800);
            p->mUnk_00.mUnk_10.y -= 0x52;
            p->mUnk_a8 += 0x19a;
            if (p->mUnk_a8 >= 0x1000) {
                p->mUnk_a8 = 0x1000;
            }
            if (p->mUnk_00.mUnk_10.y > 0) {
                return;
            }
            if (p->mUnk_dc > 0) {
                g = &data_0217561c->mUnk_47c;
                g->mUnk_00 = g->mUnk_08 * g->mUnk_00 + g->mUnk_10;
                r = (u16) (((u64) (u32) (g->mUnk_00 >> 32) * 0x10000) >> 32);
                g = &data_0217561c->mUnk_47c;
                g->mUnk_00 = g->mUnk_08 * g->mUnk_00 + g->mUnk_10;
                s = ((u64) (u32) (g->mUnk_00 >> 32) * 0x14000) >> 32;
                x = p->mUnk_cc.x + (s32) (((s64) s * data_0215d4b4[(r >> 4) * 2]) >> 12) - p->mUnk_00.mPos.x;
                z = p->mUnk_cc.z + (s32) (((s64) s * data_0215d4b4[(r >> 4) * 2 + 1]) >> 12) - p->mUnk_00.mPos.z;
                p->mUnk_e0 = 4;
                p->mUnk_00.mUnk_10.x = ((s64) x * 0x25) >> 12;
                p->mUnk_00.mUnk_10.y = 0x5000;
                p->mUnk_00.mUnk_10.z = ((s64) z * 0x25) >> 12;
                p->mUnk_a8 = 0x1000;
                p->mUnk_00.mFlags &= ~1;
                return;
            }
            p->mUnk_e0 = 5;
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
            p->mUnk_e0 = 6;
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
                            p->mUnk_e0 = 1;
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
            p->mUnk_e0 = 6;
            p->mUnk_00.mFlags |= data_021567a0;
            return;
    }
}
