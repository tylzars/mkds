#include "Main/Unknown/code_02095f38.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_0209b634.h"
#include "Main/Unknown/code_0209bc5c.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_02042044.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0209bf70.h"
#include "Main/Unknown/code_02100000.h"

#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_0209bef0.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020d22c0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020f9c6c.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_0217c000.h"
#include "ITCM/code_01ff8000.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_020d26f8.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "code_02146cbc.h"
#include "code_02147cd8.h"
#include "01/code_0218155c.h"

u32 func_0209753c(u32 a) {
    Unk0209753c *v1;
    v1 = func_0209bc5c(func_02100138(MAP_OBJECT_KIND_FLIPPER), a);
    v1->mUnk_ebc = 0xaa;
    return 1;
}

void InitCoverPooHole(Unk02097520 *p0) {
    p0->mUnk_02 |= data_021564c0;
}

u32 func_0209702c(CoverPooHole *p, Kart *a, u8 *b, u8 *c) {
    s32 v1;
    s32 g;
    u32 v2 = *b;
    Vec3 v;
    s32 t;
    u8 m = 1 << a->mIndex;
    Unk0210b7a8 s;
    u8 v3 = *c;
    Unk0210b7a8 s2;
    if (v2 == 3 || v2 == 4) {
        g = a->mUnk_29c;
        if (g != 1) {
            if (p->mState == 4 || (p->mState == 5 && p->mUnk_a0 > 0x7800)) {
                p->mUnk_00.mUnk_10.x = 0;
                p->mUnk_00.mUnk_10.y = 0x3800;
                p->mUnk_00.mUnk_10.z = 0;
                return v3;
            }
        }
        if ((((const CoverPooHole *) p)->mUnk_108 & m) == 0) {
            v1 = p->mState;
            if (v1 == 0 || v1 == 3) {
                p->mUnk_108 = p->mUnk_108 | m;
                if (data_021759c0->mCurrentEntries[a->mIndex].mPlayer.mKind != 2) {
                    if ((p->mUnk_00.mDistanceSquaredAndFlags & 4) == 0) {
                        if (p->mUnk_00.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
                            t = 2;
                        } else if (p->mUnk_00.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
                            t = 3;
                        } else {
                            t = 4;
                        }
                        s.mUnk_00 = 0x16e;
                        s.mUnk_04 = &p->mUnk_00.mPos;
                        s.mUnk_08 = t;
                        s.mUnk_0c = func_020d4ef4(&p->mUnk_00.mPos);
                        func_0210b7a8(&s);
                    }
                }
                p->mUnk_00.mDistanceSquaredAndFlags = p->mUnk_00.mDistanceSquaredAndFlags | data_021564bc;
                return 0;
            }
            if (g == 1 && (v1 == 4 || (v1 == 5 && p->mUnk_a0 > 0x7800) || v1 == 1)) {
                p->mUnk_108 = p->mUnk_108 | m;
                if ((p->mUnk_00.mFlags & 0x800) == 0 || a->mIndex == data_021759c0->mEntryIndex) {
                    p->mUnk_104 = 1;
                    p->mUnk_b4 = p->mUnk_a0;
                    p->mUnk_b8 = p->mUnk_a4;
                    p->mUnk_bc = 0x4000;
                    p->mUnk_c0 = 0x1333;
                    p->mUnk_c4 = 0;
                    p->mUnk_d0 = 0;
                    p->mUnk_d4 = 0x2000;
                    p->mUnk_d8 = -0x40;
                    p->mUnk_dc = 0x200;
                    p->mUnk_e0 = 0;
                    p->mUnk_e4 = 0;
                    p->mUnk_f0 = 0;
                    p->mUnk_f4 = 0x1000;
                    p->mUnk_f8 = -0x30;
                    p->mUnk_fc = 0x800;
                    p->mUnk_100 = 0x100;
                    func_020d26f8(&p->mUnk_00, a);
                    if (data_021759c0->mMode == MODE_MISSION_RUN) {
                        v.x = (p->mUnk_00.mPos.x + a->mPos.x) >> 1;
                        v.y = (p->mUnk_00.mPos.y + a->mPos.y) >> 1;
                        v.z = (p->mUnk_00.mPos.z + a->mPos.z) >> 1;
                        StartEffect(0x442, &v);
                        StartEffect(0x443, &v);
                        if (data_021759c0->mMode == MODE_MISSION_RUN) {
                            func_ov001_0218175c(p->mUnk_00.mKind);
                        }
                    }
                }
                if ((p->mUnk_00.mFlags & 0x800) == 0) {
                    if (p->mState == 1) {
                        p->mState = 6;
                    } else if (p->mState == 4) {
                        p->mState = 7;
                    }
                }
                p->mUnk_00.mUnk_10.x = 0;
                p->mUnk_00.mUnk_10.y = 0;
                p->mUnk_00.mUnk_10.z = 0;
                return v3;
            }
            if (v1 == 1) {
                p->mUnk_108 = p->mUnk_108 | m;
                if ((p->mUnk_00.mFlags & 0x800) == 0 || a->mIndex == data_021759c0->mEntryIndex) {
                    p->mUnk_104 = 1;
                    p->mUnk_b4 = p->mUnk_a0;
                    p->mUnk_b8 = p->mUnk_a4;
                    p->mUnk_bc = 0;
                    p->mUnk_c0 = 0;
                    p->mUnk_c4 = 0;
                    p->mUnk_d0 = 0;
                    p->mUnk_d4 = 0x2000;
                    p->mUnk_d8 = -0x40;
                    p->mUnk_dc = 0x200;
                    p->mUnk_e0 = 0;
                    p->mUnk_e4 = 0;
                    p->mUnk_f0 = 0;
                    p->mUnk_f4 = 0x1000;
                    p->mUnk_f8 = -0x30;
                    p->mUnk_fc = 0x800;
                    p->mUnk_100 = 0x100;
                    p->mUnk_00.mDistanceSquaredAndFlags = p->mUnk_00.mDistanceSquaredAndFlags | data_021564bc;
                    if ((p->mUnk_00.mDistanceSquaredAndFlags & 4) == 0) {
                        if (p->mUnk_00.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
                            t = 2;
                        } else if (p->mUnk_00.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
                            t = 3;
                        } else {
                            t = 4;
                        }
                        s2.mUnk_00 = 0x16f;
                        s2.mUnk_04 = &p->mUnk_00.mPos;
                        s2.mUnk_08 = t;
                        s2.mUnk_0c = func_020d4ef4(&p->mUnk_00.mPos);
                        func_0210b7a8(&s2);
                    }
                }
                if ((p->mUnk_00.mFlags & 0x800) == 0) {
                    p->mState = 6;
                }
                p->mUnk_00.mUnk_10.x = (s32) (((s64) a->mVelocity.x * -0x4cd) >> 12);
                p->mUnk_00.mUnk_10.y = (s32) (((s64) a->mVelocity.y * -0x4cd) >> 12);
                p->mUnk_00.mUnk_10.z = (s32) (((s64) a->mVelocity.z * -0x4cd) >> 12);
                p->mUnk_00.mUnk_10.y = 0x3800;
                return 12;
            }
        }
    }
    p->mUnk_00.mDistanceSquaredAndFlags = p->mUnk_00.mDistanceSquaredAndFlags | data_021564bc;
    p->mUnk_00.mUnk_10.x = 0;
    p->mUnk_00.mUnk_10.y = 0;
    p->mUnk_00.mUnk_10.z = 0;
    return 0;
}

u32 func_02096f54(CoverPooHole *p, Kart *a, u8 *b, u8 *c) {
    u8 v1 = *b;
    u8 v2 = *c;
    if (p->mState != 4) {
        return 0;
    }
    if (v1 == 2) {
        p->mUnk_104 = 1;
        p->mUnk_b4 = p->mUnk_a0;
        p->mUnk_b8 = p->mUnk_a4;
        p->mUnk_bc = 0x4000;
        p->mUnk_c0 = 0x1333;
        p->mUnk_00.mUnk_10.x = 0;
        p->mUnk_00.mUnk_10.y = 0;
        p->mUnk_00.mUnk_10.z = 0;
        p->mUnk_c4 = 0;
        p->mUnk_d0 = 0;
        p->mUnk_d4 = 0x2000;
        p->mUnk_d8 = -0x40;
        p->mUnk_dc = 0x200;
        p->mUnk_e0 = 0;
        p->mUnk_e4 = 0;
        p->mUnk_f0 = 0;
        p->mUnk_f4 = 0x1000;
        p->mUnk_f8 = -0x30;
        p->mUnk_fc = 0x800;
        p->mUnk_100 = 0x100;
        p->mUnk_00.mDistanceSquaredAndFlags = p->mUnk_00.mDistanceSquaredAndFlags | data_021564b8;
        if ((p->mUnk_00.mFlags & 0x800) == 0) {
            p->mState = 7;
        }
    }
    return v2;
}

BOOL func_02096df0(CoverPooHole *p, const Vec3 *a, s32 b, Vec3 *c) {
    Vec3 s;
    s32 d;
    VEC_Subtract(a, &p->mUnk_00.mPos, &s);
    if (s.y >= p->mUnk_a0 + b) {
        return FALSE;
    }
    d = VEC_Mag(&s);
    if (d >= p->mUnk_00.mExtent.x + b) {
        return FALSE;
    }
    if (p->mState == 1) {
        c->x = 0;
        c->y = 0;
        c->z = 0;
        return TRUE;
    }
    if (p->mState == 4 || (p->mState == 5 && p->mUnk_a0 > 0x7800)) {
        if ((s64) s.x * s.x + (s64) s.y * s.y + (s64) s.z * s.z >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(&s, &s);
        }
        d = p->mUnk_00.mExtent.x + b - d;
        c->x = (s32) (((s64) s.x * d) >> 12);
        c->y = (s32) (((s64) s.y * d) >> 12);
        c->z = (s32) (((s64) s.z * d) >> 12);
        return TRUE;
    }
    c->x = 0;
    c->y = 0;
    c->z = 0;
    return TRUE;
}

void CreateCoverPooHole(void *a) {
    gCover = CreateMapObjectModelNsbmd(a, "cover.nsbmd");
    gPoo = CreateMapObjectModelNsbmdNsbtp(a, "poo.nsbmd", "poo.nsbtp");
    gHole = CreateMapObjectModelNsbmd(a, "hole.nsbmd");
    SetMapObjectModelPolygonId(gPoo, 0x3f);
    SetMapObjectModelPolygonId(gHole, 0x3f);
}

void DrawCoverPooHole(void *a, CoverPooHole *p) {
    s32 w0;
    s32 w1;
    s32 w2;
    s32 m[9];
    s32 f0[3];
    s32 f1[3];
    s32 f2[3];
    s32 f3[3];
    s32 f4[3];
    u16 e;
    s32 k;
    s32 v1;
    s32 j;
    s32 r;
    s32 t;
    w0 = 0x1e;
    func_01ff9048(0x14, &w0, 1);
    func_01ff9048(0x11, NULL, 0);
    f0[1] = p->mUnk_a8 >> 4;
    f0[0] = 0;
    f0[2] = 0;
    func_01ff9048(0x1c, f0, 3);
    func_01ff9048(0x19, func_020e6cbc(&p->mUnk_00.mPos), 12);
    func_0209bbd0(a, gHole);
    DrawMapObjectModel(a, gHole, p);
    w1 = 1;
    func_01ff9048(0x12, &w1, 1);
    switch (p->mState) {
        case 1:
        case 2:
        case 6:
            func_0209b688(gPoo, 0);
            break;
        case 4:
        case 5:
        case 7:
            func_0209b688(gPoo, 1);
            break;
    }
    if (p->mState != 0) {
        func_01ff9048(0x11, NULL, 0);
        if (p->mUnk_104 != 0) {
            t = p->mUnk_b8 >> 4;
            f1[0] = 0;
            f1[1] = t;
            f1[2] = 0;
            func_01ff9048(0x1c, f1, 3);
        } else {
            t = p->mUnk_a4 >> 4;
            f2[0] = 0;
            f2[1] = t;
            f2[2] = 0;
            func_01ff9048(0x1c, f2, 3);
        }
        func_01ff9048(0x19, func_020e6cbc(&p->mUnk_00.mPos), 12);
        func_0209bbd0(a, gPoo);
        DrawMapObjectModel(a, gPoo, p);
        w2 = 1;
        func_01ff9048(0x12, &w2, 1);
    }
    if (p->mUnk_104 == 1) {
        goto L;
    }
    if (p->mUnk_104 == 2) {
    L:
        e = p->mUnk_c8;
        k = ((u16) p->mUnk_e8 >> 4) * 2;
        v1 = gPairsByAngle[k];
        r = (s32) (((s64) v1 * 0x7000) >> 12);
        if (r <= 0) {
            r = -r;
        }
        t = p->mUnk_b4 + r;
        func_01ff9048(0x19, func_020e6cbc(&p->mUnk_00.mPos), 12);
        f3[1] = t >> 4;
        f3[0] = 0;
        f3[2] = 0;
        func_01ff9048(0x1c, f3, 3);
        j = (e >> 4) * 2;
        MTX_RotY33_(m, gPairsByAngle[j], gPairsByAngle[j + 1]);
        func_01ff9048(0x1a, m, 9);
        MTX_RotZ33_(m, v1, gPairsByAngle[k + 1]);
        func_01ff9048(0x1a, m, 9);
    } else {
        t = p->mUnk_a0 >> 4;
        f4[0] = 0;
        f4[1] = t;
        f4[2] = 0;
        func_01ff9048(0x1c, f4, 3);
        func_01ff9048(0x19, func_020e6cbc(&p->mUnk_00.mPos), 12);
    }
    func_0209bbd0(a, gCover);
    DrawMapObjectModel(a, gCover, p);
}

void func_020968f4(Unk020968f4 *p) {
    s32 i;
    CoverPooHole *o;
    Unk020f41c4_B *v1;
    if (p == NULL) {
        return;
    }
    for (i = 0; i < p->mUnk_04 && (o = p->mUnk_00[i]) != NULL; i++) {
        o->mUnk_a8 = 0x1000;
        v1 = func_020d22d0();
        v1->mUnk_00 = (s64) v1->mUnk_08 * (s64) v1->mUnk_00 + v1->mUnk_10;
        o->mTimer =
            (u16) (o->mUnk_00.mCourseMapRow->mUnk_28 + (u16) (((u64) (u32) (v1->mUnk_00 >> 32) * 60) >> 32) - 30);
        if (data_021759c0->mMode == MODE_MISSION_RUN) {
            o->mState = 3;
            o->mUnk_a0 = 0x2000;
            o->mUnk_a4 = -0xd000;
        } else {
            o->mState = 0;
            o->mUnk_a0 = 0x2000;
            o->mUnk_a4 = -0xd000;
        }
    }
}

s32 func_020968dc(s32 a) {
    return gPairsByAngle[(a >> 4) * 2];
}

s32 func_020968c0(s32 a, s32 b) {
    return (s32) (((s64) a * b + 0x800) >> 12);
}

static inline u16 func_02095fec_inline(u32 n) {
    Unk020f41c4_B *b;

    b = func_020d22d0();
    b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
    return (u32) (((b->mUnk_00 >> 32) * n) >> 32);
}

static inline void func_02095fec_inline_2(CoverPooHole *p, s32 n) {
    Unk0210b7a8 s;
    s32 v;

    if (p->mUnk_00.mDistanceSquaredAndFlags & 4) {
        return;
    }
    if (p->mUnk_00.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
        v = 2;
    } else if (p->mUnk_00.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
        v = 3;
    } else {
        v = 4;
    }
    s.mUnk_00 = n;
    s.mUnk_04 = &p->mUnk_00.mPos;
    s.mUnk_08 = v;
    s.mUnk_0c = func_020d4ef4(&p->mUnk_00.mPos);
    func_0210b7a8(&s);
}

void UpdateCoverPooHole(void *a, CoverPooHole *p) {
    s32 v;

    p->mUnk_00.mUnk_10.y = 0;
    switch (p->mUnk_104) {
        case 0:
            break;
        case 1:
            p->mUnk_b8 += p->mUnk_c0;
            p->mUnk_c0 -= 0x800;
            if (p->mUnk_b4 >= 0x2000) {
                p->mUnk_b4 += p->mUnk_bc;
                p->mUnk_bc -= 0x19a;
            } else {
                p->mUnk_b4 = 0x2000;
                p->mUnk_104 = 2;
                func_02095fec_inline_2(p, 0x16c);
            }
            break;
        case 2:
            if (p->mUnk_b8 >= 0x2000) {
                p->mUnk_b8 += p->mUnk_c0;
                p->mUnk_c0 -= 0x800;
            }
            p->mUnk_c4 += p->mUnk_dc;
            p->mUnk_cc = p->mUnk_d0 + func_020968c0(p->mUnk_d4, func_020968dc(p->mUnk_c4)) - p->mUnk_c8;
            p->mUnk_c8 += p->mUnk_cc;
            if (p->mUnk_d4 > 0) {
                v = p->mUnk_d4 + p->mUnk_d8;
                if (v <= 0) {
                    v = 0;
                }
                p->mUnk_d4 = v;
            } else if (p->mUnk_d4 < 0) {
                v = p->mUnk_d4 + p->mUnk_d8;
                if (v >= 0) {
                    v = 0;
                }
                p->mUnk_d4 = v;
            }
            if (p->mUnk_dc > 0) {
                v = p->mUnk_dc + p->mUnk_e0;
                if (v <= 0) {
                    v = 0;
                }
                p->mUnk_dc = v;
            } else if (p->mUnk_dc < 0) {
                v = p->mUnk_dc + p->mUnk_e0;
                if (v >= 0) {
                    v = 0;
                }
                p->mUnk_dc = v;
            }
            p->mUnk_e4 += p->mUnk_fc;
            p->mUnk_ec = p->mUnk_f0 + func_020968c0(p->mUnk_f4, func_020968dc(p->mUnk_e4)) - p->mUnk_e8;
            p->mUnk_e8 += p->mUnk_ec;
            if (p->mUnk_f4 > 0) {
                v = p->mUnk_f4 + p->mUnk_f8;
                if (v <= 0) {
                    v = 0;
                }
                p->mUnk_f4 = v;
            } else if (p->mUnk_f4 < 0) {
                v = p->mUnk_f4 + p->mUnk_f8;
                if (v >= 0) {
                    v = 0;
                }
                p->mUnk_f4 = v;
            }
            if (p->mUnk_fc > 0) {
                v = p->mUnk_fc + p->mUnk_100;
                if (v <= 0) {
                    v = 0;
                }
                p->mUnk_fc = v;
            } else if (p->mUnk_fc < 0) {
                v = p->mUnk_fc + p->mUnk_100;
                if (v >= 0) {
                    v = 0;
                }
                p->mUnk_fc = v;
            }
            if (p->mUnk_f4 == 0 && p->mState != 2 && p->mState != 5) {
                p->mUnk_104 = 0;
            }
            break;
    }
    if ((p->mState == 6 || p->mState == 7) && p->mUnk_104 == 0) {
        if (data_021759c0->mMode == MODE_MISSION_RUN) {
            p->mState = 3;
            p->mUnk_a0 = 0x2000;
            p->mUnk_a4 = -0xd000;
        } else {
            p->mState = 0;
            p->mUnk_a0 = 0x2000;
            p->mUnk_a4 = -0xd000;
        }
    }
    switch (p->mState) {
        case 0:
            if (p->mTimer-- > 0) {
                return;
            }
            p->mTimer = (u16) (func_02095fec_inline(30) + 30);
            p->mState = 1;
            p->mUnk_104 = 0;
            p->mUnk_108 = 0;
            func_02095fec_inline_2(p, 0x1d3);
            break;
        case 1:
            if (p->mUnk_a0 < 0x7800) {
                p->mUnk_a0 += 0x400;
                p->mUnk_a4 = p->mUnk_a0 - 0xf000;
                return;
            }
            if (p->mTimer-- > 0) {
                p->mUnk_a0 = 0x7800;
                p->mUnk_a4 = -0x7800;
                return;
            }
            p->mUnk_a0 = 0x7800;
            p->mUnk_a4 = -0x7800;
            p->mState = 2;
            break;
        case 2:
            if (p->mUnk_a0 > 0x2000) {
                p->mUnk_a0 -= 0x400;
                p->mUnk_a4 = p->mUnk_a0 - 0xf000;
                return;
            }
            p->mUnk_a0 = 0x2000;
            p->mUnk_a4 = -0xd000;
            p->mTimer = (u16) (func_02095fec_inline(15) + 15);
            p->mState = 3;
            p->mUnk_108 = 0;
            func_02095fec_inline_2(p, 0x1d4);
            break;
        case 3:
            if (p->mTimer-- > 0) {
                return;
            }
            p->mUnk_a0 = 0x2000;
            p->mUnk_a4 = -0xd000;
            p->mTimer = (u16) (func_02095fec_inline(90) + 90);
            p->mState = 4;
            p->mUnk_104 = 0;
            p->mUnk_108 = 0;
            func_02095fec_inline_2(p, 0x1d3);
            break;
        case 4:
            if (p->mUnk_a0 < 0x124cd) {
                p->mUnk_a0 += 0xc00;
                p->mUnk_a4 = p->mUnk_a0 - 0xf000;
                return;
            }
            if (p->mTimer-- > 0) {
                p->mUnk_a0 = 0x124cd;
                p->mUnk_a4 = 0x34cd;
                return;
            }
            p->mUnk_a0 = 0x124cd;
            p->mUnk_a4 = 0x34cd;
            p->mState = 5;
            break;
        case 5:
            if (p->mUnk_a0 > 0x2000) {
                p->mUnk_a0 -= 0xc00;
                p->mUnk_a4 = p->mUnk_a0 - 0xf000;
                return;
            }
            p->mTimer = (u16) (p->mUnk_00.mCourseMapRow->mUnk_28 + func_02095fec_inline(60) - 30);
            if (data_021759c0->mMode == MODE_MISSION_RUN) {
                p->mState = 3;
                p->mUnk_a0 = 0x2000;
                p->mUnk_a4 = -0xd000;
            } else {
                p->mState = 0;
                p->mUnk_a0 = 0x2000;
                p->mUnk_a4 = -0xd000;
            }
            p->mUnk_108 = 0;
            func_02095fec_inline_2(p, 0x1d4);
            break;
    }
}

void func_02095f9c(void) {
    Unk0209bf70 *o;
    o = func_0209bf70(func_0209702c, func_02096f54, func_02096df0, 0, 1, 0x16d);
    o->mUnk_28 = 0x1b0;
}

u32 func_02095f7c(void) {
    return func_0209bef0(CreateCoverPooHole, DrawCoverPooHole, NULL);
}

u32 func_02095f5c(void) {
    return func_0209bf48(func_020968f4, UpdateCoverPooHole, NULL);
}

BOOL func_02095f38(Unk0217b498_00 *a) {
    if (a->mUnk_b0 == 1 || a->mUnk_b0 == 4) {
        return TRUE;
    }
    return FALSE;
}
