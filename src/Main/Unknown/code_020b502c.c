#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"

#include "code_02147cd8.h"
#include "Main/Unknown/code_020b4dc4.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02073eb8.h"
#include "Main/Unknown/code_02102674.h"
#include "code_02148538.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020b65f0.h"
#include "Main/Unknown/code_020b681c.h"
#include "Main/Unknown/code_020b6800.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02077bc0.h"

const Vec3 data_02156874 = {0, 0, 0};

void InitRaceHudSubScreenProjection(void) {
    UnkPair020b502c a;
    UnkPair020b502c b;
    UnkPair020b502c c;
    UnkPair020b502c d;
    UnkPair020b502c e;
    UnkPair020b502c f;

    gRaceHudSubScreenProjection = HeapAlloc(func_020b6800(), 0x9c);
    gRaceHudSubScreenProjection->mCenter.mUnk_00 = 0;
    gRaceHudSubScreenProjection->mCenter.mUnk_04 = 0;
    gRaceHudSubScreenProjection->mCenterWhole.mUnk_00 = 0;
    gRaceHudSubScreenProjection->mCenterWhole.mUnk_04 = 0;
    gRaceHudSubScreenProjection->mHalfSize = 0;
    gRaceHudSubScreenProjection->mAnglePairSecond = 0;
    gRaceHudSubScreenProjection->mAnglePairFirst = 0;
    gRaceHudSubScreenProjection->mAnglePairSecondScaled = 0;
    gRaceHudSubScreenProjection->mAnglePairFirstScaled = 0;
    func_020b6b54(&a, &b);
    gRaceHudSubScreenProjection->mUnk_2c = a;
    gRaceHudSubScreenProjection->mUnk_34 = b;
    gRaceHudSubScreenProjection->mUnk_3c = FX_InvFx64c(b.mUnk_00 - a.mUnk_00);
    gRaceHudSubScreenProjection->mUnk_44 = FX_InvFx64c(b.mUnk_04 - a.mUnk_04);
    func_020b6a98(&c, &d);
    gRaceHudSubScreenProjection->mCourseMin = c;
    gRaceHudSubScreenProjection->mCourseMax = d;
    gRaceHudSubScreenProjection->mCourseInverseX = FX_InvFx64c(d.mUnk_00 - c.mUnk_00);
    gRaceHudSubScreenProjection->mCourseInverseZ = FX_InvFx64c(d.mUnk_04 - c.mUnk_04);
    gRaceHudSubScreenProjection->mUnk_28 = MulFixed12NoRound(FX_Div(d.mUnk_00 - c.mUnk_00, 0x200000), 0xb0000);
    func_020b681c(&e, &f);
    gRaceHudSubScreenProjection->mUnk_6c = e;
    gRaceHudSubScreenProjection->mUnk_74 = f;
    gRaceHudSubScreenProjection->mUnk_7c = FX_InvFx64c(f.mUnk_00 - e.mUnk_00);
    gRaceHudSubScreenProjection->mUnk_84 = FX_InvFx64c(f.mUnk_04 - e.mUnk_04);
    gRaceHudSubScreenProjection->mScrollTimer = 0;
    gRaceHudSubScreenProjection->mScrollPosition = data_02156874;
}

u32 ClearRaceHudSubScreenProjection(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &gRaceHudSubScreenProjection;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

s32 func_020b64e8(void) {
    BOOL r = FALSE;

    switch (func_020b4e5c()) {
        case COURSE_ID_OLD_YOSHI_GC:
        case COURSE_ID_OLD_MOMO_64:
        case COURSE_ID_OLD_LUIGI_GC:
        case COURSE_ID_OLD_FRAPPE_64:
        case COURSE_ID_CLOCK:
        case COURSE_ID_MANSION:
        case COURSE_ID_AIRSHIP:
        case COURSE_ID_CROSS:
        case COURSE_ID_OLD_HYUDORO_64:
        case COURSE_ID_RIDGE:
        case COURSE_ID_MARIO:
        case COURSE_ID_GARDEN:
        case COURSE_ID_DESERT:
        case COURSE_ID_TOWN:
        case COURSE_ID_SNOW:
        case COURSE_ID_PINBALL:
        case COURSE_ID_STADIUM:
        case COURSE_ID_OLD_KINOKO_GC:
        case COURSE_ID_OLD_SKY_AGB:
        case COURSE_ID_MR_STAGE1:
        case COURSE_ID_MR_STAGE3:
            r = TRUE;
            break;
    }
    return r;
}

s32 func_020b6430(void) {
    BOOL r = FALSE;

    switch (func_020b4e5c()) {
        case COURSE_ID_OLD_YOSHI_GC:
        case COURSE_ID_OLD_MOMO_64:
        case COURSE_ID_OLD_FRAPPE_64:
        case COURSE_ID_OLD_HYUDORO_64:
        case COURSE_ID_RIDGE:
        case COURSE_ID_MARIO:
        case COURSE_ID_GARDEN:
        case COURSE_ID_DESERT:
        case COURSE_ID_STADIUM:
        case COURSE_ID_OLD_SKY_AGB:
        case COURSE_ID_MR_STAGE1:
        case COURSE_ID_MR_STAGE3:
            r = TRUE;
            break;
    }
    return r;
}

u16 func_020b6368(void) {
    u16 r = 0;
    Unk020748a8 *p;
    s32 a;

    switch (GetRaceHudSubScreenState()) {
        case 1:
            if (func_020b4df8() == MODE_BATTLE) {
                p = GetCurrentCamera();
            } else {
                p = GetChaseCamera();
            }
            a = FX_Atan2Idx(p->mViewMatrix[8], p->mViewMatrix[2]);
            r = (0x14000 - a) % 0x10000;
            gRaceHudSubScreenProjection->mScrollTimer = 0;
            break;
        case 2:
            r = 0;
            break;
        case 3:
            a = GetFixed12Whole(func_020b57e4()->mUnk_10);
            r = (a << 16) / 360 + 0x8000;
            break;
        default:
            break;
    }
    return r;
}

u16 func_020b6338(s32 idx) {
    return (0x18000 - GetKartHeadingAngle(idx)) % 0x10000;
}

void func_020b6078(s32 idx, UnkPair020b502c *out) {
    UnkPair020b502c a = gRaceHudSubScreenProjection->mUnk_2c;
    Vec3 v;

    GetKartPos(&v, (u8) idx);
    switch (func_020b4e5c()) {
        case COURSE_ID_OLD_MOMO_64:
        case COURSE_ID_CROSS:
        case COURSE_ID_OLD_KINOKO_GC:
            if (func_020b523c() != 0) {
                out->mUnk_00 = GetFixed12Whole(MulFixed12NoRound(
                                   0x80000, MulFx64c(a.mUnk_00 - v.z, gRaceHudSubScreenProjection->mUnk_3c))) +
                               0xf8;
            } else {
                out->mUnk_00 = GetFixed12Whole(MulFixed12NoRound(
                                   0x80000, MulFx64c(v.z - a.mUnk_00, gRaceHudSubScreenProjection->mUnk_3c))) +
                               0x78;
            }
            out->mUnk_04 = GetFixed12Whole(MulFixed12NoRound(
                               0x98000, MulFx64c(v.x - a.mUnk_04, gRaceHudSubScreenProjection->mUnk_44))) +
                           0x28;
            break;
        case COURSE_ID_BANK:
            if (func_020b523c() != 0) {
                out->mUnk_00 = GetFixed12Whole(MulFixed12NoRound(
                                   0x80000, MulFx64c(a.mUnk_00 - v.z, gRaceHudSubScreenProjection->mUnk_3c))) +
                               0xf8;
            } else {
                out->mUnk_00 = GetFixed12Whole(MulFixed12NoRound(
                                   0x80000, MulFx64c(v.z - a.mUnk_00, gRaceHudSubScreenProjection->mUnk_3c))) +
                               0x78;
            }
            out->mUnk_04 = GetFixed12Whole(MulFixed12NoRound(
                               0x98000, MulFx64c(v.x - a.mUnk_04, gRaceHudSubScreenProjection->mUnk_44))) +
                           0x28;
            break;
        default:
            if (func_020b523c() != 0) {
                out->mUnk_00 = GetFixed12Whole(MulFixed12NoRound(
                                   0x80000, MulFx64c(a.mUnk_00 - v.x, gRaceHudSubScreenProjection->mUnk_3c))) +
                               0xf8;
            } else {
                out->mUnk_00 = GetFixed12Whole(MulFixed12NoRound(
                                   0x80000, MulFx64c(v.x - a.mUnk_00, gRaceHudSubScreenProjection->mUnk_3c))) +
                               0x78;
            }
            out->mUnk_04 = GetFixed12Whole(MulFixed12NoRound(
                               0x98000, MulFx64c(v.z - a.mUnk_04, gRaceHudSubScreenProjection->mUnk_44))) +
                           0x28;
            break;
    }
}

void ComputeRaceHudSubScreenCoursePosition(const Vec3 *pos, UnkPair020b502c *out) {
    UnkPair020b502c o = gRaceHudSubScreenProjection->mCourseMin;

    out->mUnk_00 = GetFixed12Whole(
        MulFixed12NoRound(0x200000, MulFx64c(pos->x - o.mUnk_00, gRaceHudSubScreenProjection->mCourseInverseX)));
    out->mUnk_04 = GetFixed12Whole(
        MulFixed12NoRound(0x200000, MulFx64c(pos->z - o.mUnk_04, gRaceHudSubScreenProjection->mCourseInverseZ)));
}

BOOL IsRaceHudSubScreenPairNearCenter(const UnkPair020b502c *p) {
    UnkPair020b502c c = gRaceHudSubScreenProjection->mCenterWhole;
    s32 r = gRaceHudSubScreenProjection->mHalfSize;

    if (p->mUnk_00 - r < c.mUnk_00 && c.mUnk_00 < p->mUnk_00 + r && p->mUnk_04 - r < c.mUnk_04 &&
        c.mUnk_04 < p->mUnk_04 + r) {
        return TRUE;
    }
    return FALSE;
}

void ComputeRaceHudSubScreenKartPosition(s32 idx, UnkPair020b502c *out, s32 v1) {
    UnkPair020b502c a = gRaceHudSubScreenProjection->mCenter;
    s32 ay = a.mUnk_04;
    s32 v20 = gRaceHudSubScreenProjection->mAnglePairSecondScaled;
    s32 v24 = gRaceHudSubScreenProjection->mAnglePairFirstScaled;
    UnkPair020b502c o = gRaceHudSubScreenProjection->mCourseMin;
    Vec3 v;
    s32 px;
    s32 py;
    s32 dx;
    s32 dy;

    GetKartPos(&v, (u8) idx);
    px = MulFixed12NoRound(0x200000, MulFx64c(v.x - o.mUnk_00, gRaceHudSubScreenProjection->mCourseInverseX));
    py = MulFixed12NoRound(0x200000, MulFx64c(v.z - o.mUnk_04, gRaceHudSubScreenProjection->mCourseInverseZ));
    if (func_020b523c() != 0) {
        dy = py - ay;
        dx = px - a.mUnk_00;
        out->mUnk_00 = GetFixed12Whole(MulFixed12NoRound(-v20, dx) + MulFixed12NoRound(v24, dy)) + 0x80;
        out->mUnk_04 = GetFixed12Whole(MulFixed12NoRound(v24, dx) + MulFixed12NoRound(v20, dy)) + 0x60;
    } else {
        dx = px - a.mUnk_00;
        dy = py - ay;
        out->mUnk_00 = GetFixed12Whole(MulFixed12NoRound(v20, dx) - MulFixed12NoRound(v24, dy)) + 0x80;
        out->mUnk_04 = GetFixed12Whole(MulFixed12NoRound(v24, dx) + MulFixed12NoRound(v20, dy)) + 0x60;
    }
}

static inline s32 func_020b5ae8_inline(s32 v) {
    float f;

    if (GetFixed12Whole(v) > 0) {
        f = 0.5f + (GetFixed12Whole(v) << 12);
    } else {
        f = (GetFixed12Whole(v) << 12) - 0.5f;
    }
    return f;
}

BOOL ComputeRaceHudSubScreenPosition(const Vec3 *pos, UnkPair020b502c *out, s32 unk, s32 flag, s32 flag2) {
    UnkPair020b502c a = gRaceHudSubScreenProjection->mCenter;
    s32 v20 = gRaceHudSubScreenProjection->mAnglePairSecondScaled;
    s32 v24 = gRaceHudSubScreenProjection->mAnglePairFirstScaled;
    UnkPair020b502c o = gRaceHudSubScreenProjection->mCourseMin;
    s32 x;
    s32 y;
    s32 dx;
    s32 px;
    s32 py;
    s32 dy;
    s32 e;
    s32 ox;
    s32 oy;
    UnkPair020b502c c;
    s32 r;
    s32 tx;
    s32 ty;

    px = MulFixed12NoRound(0x200000, MulFx64c(pos->x - o.mUnk_00, gRaceHudSubScreenProjection->mCourseInverseX));
    py = MulFixed12NoRound(0x200000, MulFx64c(pos->z - o.mUnk_04, gRaceHudSubScreenProjection->mCourseInverseZ));
    if (flag != 0) {
        c = gRaceHudSubScreenProjection->mCenterWhole;
        r = gRaceHudSubScreenProjection->mHalfSize;
        tx = GetFixed12Whole(px);
        ty = GetFixed12Whole(py);

        if (tx - r >= c.mUnk_00 || c.mUnk_00 >= tx + r || ty - r >= c.mUnk_04 || c.mUnk_04 >= ty + r) {
            return FALSE;
        }
    }
    if (flag2 != 0) {
        x = a.mUnk_00;
        y = a.mUnk_04;
    } else {
        x = func_020b5ae8_inline(a.mUnk_00);
        y = func_020b5ae8_inline(a.mUnk_04);
    }
    if (func_020b523c() != 0) {
        dx = px - x;
        dy = py - y;
        ox = GetFixed12Whole(MulFixed12NoRound(-v20, dx) + MulFixed12NoRound(v24, dy)) + 0x80;
        oy = GetFixed12Whole(MulFixed12NoRound(v24, dx) + MulFixed12NoRound(v20, dy)) + 0x60;
    } else {
        dx = px - x;
        e = py - y;
        ox = GetFixed12Whole(MulFixed12NoRound(v20, dx) - MulFixed12NoRound(v24, e)) + 0x80;
        oy = GetFixed12Whole(MulFixed12NoRound(v24, dx) + MulFixed12NoRound(v20, e)) + 0x60;
    }
    if (ox > -32 && ox < 0x120 && oy > -32 && oy < 0xe0) {
        out->mUnk_00 = ox;
        out->mUnk_04 = oy;
        return TRUE;
    }
    out->mUnk_00 = ox;
    out->mUnk_04 = oy;
    return FALSE;
}

void UpdateRaceHudSubScreenCenter(RaceHudSubScreenBgAffine *out) {
    UnkPair020b502c a = gRaceHudSubScreenProjection->mCourseMin;
    Vec3 pos;
    float f;

    if (gRaceHudSubScreenProjection->mScrollTimer != 0) {
        pos = gRaceHudSubScreenProjection->mScrollPosition;
    } else {
        func_0207a91c(&pos, func_020b4d9c());
    }
    if (GetRaceHudSubScreenState() == 3) {
        pos = func_020b57e4()->mUnk_00;
    }
    gRaceHudSubScreenProjection->mCenter.mUnk_00 =
        MulFixed12NoRound(0x200000, MulFx64c(pos.x - a.mUnk_00, gRaceHudSubScreenProjection->mCourseInverseX));
    gRaceHudSubScreenProjection->mCenter.mUnk_04 =
        MulFixed12NoRound(0x200000, MulFx64c(pos.z - a.mUnk_04, gRaceHudSubScreenProjection->mCourseInverseZ));
    gRaceHudSubScreenProjection->mCenterWhole.mUnk_00 = GetFixed12Whole(gRaceHudSubScreenProjection->mCenter.mUnk_00);
    out->mCenterX = gRaceHudSubScreenProjection->mCenterWhole.mUnk_00;
    gRaceHudSubScreenProjection->mCenterWhole.mUnk_04 = GetFixed12Whole(gRaceHudSubScreenProjection->mCenter.mUnk_04);
    out->mCenterY = gRaceHudSubScreenProjection->mCenterWhole.mUnk_04;
    out->mX1 = out->mCenterX - 0x80;
    out->mY1 = out->mCenterY - 0x60;
    if (gRaceHudSubScreenProjection->mCenterWhole.mUnk_00 > 0) {
        f = 0.5f + (gRaceHudSubScreenProjection->mCenterWhole.mUnk_00 << 12);
    } else {
        f = (gRaceHudSubScreenProjection->mCenterWhole.mUnk_00 << 12) - 0.5f;
    }
    gRaceHudSubScreenProjection->mCenterRemainderX = gRaceHudSubScreenProjection->mCenter.mUnk_00 - (s32) f;
    if (gRaceHudSubScreenProjection->mCenterWhole.mUnk_04 > 0) {
        f = 0.5f + (gRaceHudSubScreenProjection->mCenterWhole.mUnk_04 << 12);
    } else {
        f = (gRaceHudSubScreenProjection->mCenterWhole.mUnk_04 << 12) - 0.5f;
    }
    gRaceHudSubScreenProjection->mCenterRemainderY = gRaceHudSubScreenProjection->mCenter.mUnk_04 - (s32) f;
}

void func_020b57f8(RaceHudSubScreenBgAffine *out) {
    UnkPair020b502c a = gRaceHudSubScreenProjection->mUnk_6c;
    Vec3 pos;

    if (gRaceHudSubScreenProjection->mScrollTimer != 0) {
        pos = gRaceHudSubScreenProjection->mScrollPosition;
    } else {
        func_0207a91c(&pos, func_020b4d9c());
    }
    if (GetRaceHudSubScreenState() == 3) {
        pos = func_020b57e4()->mUnk_00;
    }
    out->mCenterX =
        GetFixed12Whole(MulFixed12NoRound(0x200000, MulFx64c(pos.x - a.mUnk_00, gRaceHudSubScreenProjection->mUnk_7c)));
    out->mCenterY =
        GetFixed12Whole(MulFixed12NoRound(0x200000, MulFx64c(pos.z - a.mUnk_04, gRaceHudSubScreenProjection->mUnk_84)));
    out->mX1 = out->mCenterX - 0x80;
    out->mY1 = out->mCenterY - 0x60;
}

Unk020b57e4 *func_020b57e4(void) {
    return gCourseMap->mUnk_2c;
}

s32 MulFx64c(s32 a, s64 k) {
    return (k * a + 0x80000000) >> 32;
}

void func_020b5658(RaceHudSubScreenBgAffine *out) {
    UnkPair020b502c a = gRaceHudSubScreenProjection->mUnk_6c;
    UnkPair020b502c b = gRaceHudSubScreenProjection->mUnk_74;
    Vec3 pos;
    s32 n;
    s32 ex;
    s32 ez;
    s32 dx;
    s32 dz;

    if (gRaceHudSubScreenProjection->mScrollTimer != 0) {
        pos = gRaceHudSubScreenProjection->mScrollPosition;
    } else {
        func_0207a91c(&pos, func_020b4d9c());
    }
    if (GetRaceHudSubScreenState() == 3) {
        pos = func_020b57e4()->mUnk_00;
    }
    ex = b.mUnk_00 - a.mUnk_00;
    ez = b.mUnk_04 - a.mUnk_04;
    n = GetRaceHudUpdateFrames() / 32;
    dx = ex * n;
    dz = ez * n;
    pos.x -= dx / 512;
    pos.z -= dz / 512;
    out->mCenterX =
        GetFixed12Whole(MulFixed12NoRound(0x200000, MulFx64c(pos.x - a.mUnk_00, gRaceHudSubScreenProjection->mUnk_7c)));
    out->mCenterY =
        GetFixed12Whole(MulFixed12NoRound(0x200000, MulFx64c(pos.z - a.mUnk_04, gRaceHudSubScreenProjection->mUnk_84)));
    out->mX1 = out->mCenterX - 0x80;
    out->mY1 = out->mCenterY - 0x60;
}

u16 func_020b5644(Unk02175628 *p, s32 mask) {
    return p->mBits & mask;
}

u16 func_020b5628(s32 idx, s32 mask) {
    return func_020b5644(&data_02175628[idx], mask);
}

void UpdateRaceHudSubScreenScroll(void) {
    UnkPair020b502c lo;
    UnkPair020b502c hi;
    Vec3 target;
    Vec3 dir;

    func_020b6a18(&lo, &hi);
    if (func_020b5628(func_020435bc(), 0x20) != 0) {
        if (gRaceHudSubScreenProjection->mScrollTimer != 0) {
            gRaceHudSubScreenProjection->mScrollPosition.x -= 0xa000;
            if (gRaceHudSubScreenProjection->mScrollPosition.x < lo.mUnk_00) {
                gRaceHudSubScreenProjection->mScrollPosition.x = lo.mUnk_00;
            }
        } else {
            func_0207a91c(&gRaceHudSubScreenProjection->mScrollPosition, func_020b4d9c());
        }
        gRaceHudSubScreenProjection->mScrollTimer = 600;
    }
    if (func_020b5628(func_020435bc(), 0x10) != 0) {
        if (gRaceHudSubScreenProjection->mScrollTimer != 0) {
            gRaceHudSubScreenProjection->mScrollPosition.x += 0xa000;
            if (gRaceHudSubScreenProjection->mScrollPosition.x > hi.mUnk_00) {
                gRaceHudSubScreenProjection->mScrollPosition.x = hi.mUnk_00;
            }
        } else {
            func_0207a91c(&gRaceHudSubScreenProjection->mScrollPosition, func_020b4d9c());
        }
        gRaceHudSubScreenProjection->mScrollTimer = 600;
    }
    if (func_020b5628(func_020435bc(), 0x40) != 0) {
        if (gRaceHudSubScreenProjection->mScrollTimer != 0) {
            gRaceHudSubScreenProjection->mScrollPosition.z -= 0xa000;
            if (gRaceHudSubScreenProjection->mScrollPosition.z < lo.mUnk_04) {
                gRaceHudSubScreenProjection->mScrollPosition.z = lo.mUnk_04;
            }
        } else {
            func_0207a91c(&gRaceHudSubScreenProjection->mScrollPosition, func_020b4d9c());
        }
        gRaceHudSubScreenProjection->mScrollTimer = 600;
    }
    if (func_020b5628(func_020435bc(), 0x80) != 0) {
        if (gRaceHudSubScreenProjection->mScrollTimer != 0) {
            gRaceHudSubScreenProjection->mScrollPosition.z += 0xa000;
            if (gRaceHudSubScreenProjection->mScrollPosition.z > hi.mUnk_04) {
                gRaceHudSubScreenProjection->mScrollPosition.z = hi.mUnk_04;
            }
        } else {
            func_0207a91c(&gRaceHudSubScreenProjection->mScrollPosition, func_020b4d9c());
        }
        gRaceHudSubScreenProjection->mScrollTimer = 600;
    }
    if (gRaceHudSubScreenProjection->mScrollTimer != 0) {
        gRaceHudSubScreenProjection->mScrollTimer--;
        if (gRaceHudSubScreenProjection->mScrollTimer < 300) {
            func_0207a91c(&target, func_020b4d9c());
            gRaceHudSubScreenProjection->mScrollTimer = 300;
            VEC_Subtract(&target, &gRaceHudSubScreenProjection->mScrollPosition, &dir);
            Vec3NormalizeAndGetLengthUnchecked(&dir, &dir);
            VEC_MultAdd(0xa000, &dir, &gRaceHudSubScreenProjection->mScrollPosition,
                        &gRaceHudSubScreenProjection->mScrollPosition);
            if (GetFixed12Whole(target.x - gRaceHudSubScreenProjection->mScrollPosition.x) *
                        GetFixed12Whole(target.x - gRaceHudSubScreenProjection->mScrollPosition.x) +
                    GetFixed12Whole(target.z - gRaceHudSubScreenProjection->mScrollPosition.z) *
                        GetFixed12Whole(target.z - gRaceHudSubScreenProjection->mScrollPosition.z) <
                GetFixed12Whole(0xa000) * GetFixed12Whole(0xa000)) {
                gRaceHudSubScreenProjection->mScrollPosition = target;
                gRaceHudSubScreenProjection->mScrollTimer = 0;
            }
        }
    }
    if (gRaceHudSubScreenProjection->mScrollPosition.x < lo.mUnk_00) {
        gRaceHudSubScreenProjection->mScrollPosition.x = lo.mUnk_00;
    }
    if (gRaceHudSubScreenProjection->mScrollPosition.x > hi.mUnk_00) {
        gRaceHudSubScreenProjection->mScrollPosition.x = hi.mUnk_00;
    }
    if (gRaceHudSubScreenProjection->mScrollPosition.z < lo.mUnk_04) {
        gRaceHudSubScreenProjection->mScrollPosition.z = lo.mUnk_04;
    }
    if (gRaceHudSubScreenProjection->mScrollPosition.z > hi.mUnk_04) {
        gRaceHudSubScreenProjection->mScrollPosition.z = hi.mUnk_04;
    }
}

s32 GetAnglePairSecond(s32 x) {
    return gPairsByAngle[(x >> 4) * 2 + 1];
}

s32 GetAnglePairFirst(s32 x) {
    return gPairsByAngle[(x >> 4) * 2];
}

s32 GetFixed12Whole(s32 x) {
    return x >> 12;
}

s32 func_020b523c(void) {
    return data_021759c0->mUnk_57;
}

void UpdateRaceHudSubScreenProjectionAndBgAffine(RaceHudSubScreenBgAffine *p, s32 scale) {
    s32 angle = func_020b6368();
    s32 a;
    s32 b;

    gRaceHudSubScreenProjection->mAnglePairSecond = GetAnglePairSecond(angle);
    gRaceHudSubScreenProjection->mAnglePairFirst = GetAnglePairFirst(angle);
    gRaceHudSubScreenProjection->mAnglePairSecondScaled =
        MulFixed12NoRound(gRaceHudSubScreenProjection->mAnglePairSecond, scale);
    gRaceHudSubScreenProjection->mAnglePairFirstScaled =
        MulFixed12NoRound(gRaceHudSubScreenProjection->mAnglePairFirst, scale);
    if (GetRaceHudSubScreenState() == 2) {
        UpdateRaceHudSubScreenScroll();
    }
    gRaceHudSubScreenProjection->mHalfSize = GetFixed12Whole(FX_Div(0xb0000, scale));
    scale = FX_Inv(scale);
    a = MulFixed12NoRound(gRaceHudSubScreenProjection->mAnglePairSecond, scale);
    b = MulFixed12NoRound(gRaceHudSubScreenProjection->mAnglePairFirst, scale);
    if (func_020b523c() != 0) {
        p[0].mMatrix0 = p[1].mMatrix0 = -a;
        p[0].mMatrix2 = p[1].mMatrix2 = b;
    } else {
        p[0].mMatrix0 = p[1].mMatrix0 = a;
        p[0].mMatrix2 = p[1].mMatrix2 = -b;
    }
    p[0].mMatrix1 = p[1].mMatrix1 = b;
    p[0].mMatrix3 = p[1].mMatrix3 = a;
    UpdateRaceHudSubScreenCenter(p);
    switch (func_020b4e5c()) {
        default:
            p[1] = p[0];
            break;
        case COURSE_ID_OLD_LUIGI_GC:
        case COURSE_ID_MANSION:
        case COURSE_ID_CROSS:
        case COURSE_ID_TOWN:
        case COURSE_ID_SNOW:
        case COURSE_ID_PINBALL:
        case COURSE_ID_OLD_KINOKO_GC:
            func_020b57f8(&p[1]);
            break;
        case COURSE_ID_MR_STAGE1:
        case COURSE_ID_MR_STAGE3:
            func_020b5658(&p[1]);
            break;
    }
}

s32 MulFixed12NoRound(s32 a, s32 b) {
    return ((s64) a * b) >> 12;
}
