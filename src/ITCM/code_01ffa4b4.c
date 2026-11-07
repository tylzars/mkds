#include "ITCM/code_01ffa4b4.h"
#include "ITCM/code_01ff9598.h"
#include "ITCM/code_01ffdee4.h"
#include "ITCM/code_01ff9000.h"
#include "Main/Unknown/code_0206f04c.h"
#include "Main/Unknown/code_0208ab98.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_0210f230.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_02090354.h"
#include "Main/Unknown/code_0208c188.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02070398.h"
#include "Main/Unknown/code_020d3d94.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_027e0000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0206e874.h"

void func_01ffa4b4(Kart *p, Vec3 *a) {
    u16 h;
    u32 f;
    u32 w;
    Vec3 v1;
    Vec3 v2;
    Vec3 v3;
    Vec3 v4;
    Vec3 v5;
    Vec3 v6;
    Vec3 v7;
    s32 b1;
    s32 b2;
    u32 m;
    s32 n;
    s32 k;
    s32 d;
    s32 t;
    BOOL e;

    v2 = data_02154f7c;
    b1 = (p->mUnk_44 & 0x100000) ? 1 : 0;
    b2 = (p->mUnk_48 & 0x200000) ? 1 : 0;
    *a = p->mUnk_244;
    if (func_01ffa1f8(p) != FALSE) {
        return;
    }
    if (func_01ffdee4(&p->mCollisionCenter, &p->mPrevCollisionCenter, &p->mTurnedForward, p->mRadius, 1, p->mUnk_2c8,
                      &v1, &v5, &v2, &f, (u32 *) &v3, (s32 *) &v4, &h, &w) != 0) {
        m = f & 0x1e34ef;
        VEC_Add(&p->mPos, &v1, &p->mPos);
        func_0208ab98(&p->mKartModelsEntry->mUnk_040, (f & 0x3c000000) >> 26, p->mVelocityLength);
        func_01ff9c9c(p, f);
        func_0206f694(p, f, &v4, h);
        if (f & 0x200300) {
            func_0206f574(p, f, &v2);
            if (m != 0) {
                d = VEC_DotProduct(&v5, &p->mUnk_2d8);
                p->mUnk_2d8.x -= (s32) (((s64) v5.x * d) >> 12);
                p->mUnk_2d8.y -= (s32) (((s64) v5.y * d) >> 12);
                p->mUnk_2d8.z -= (s32) (((s64) v5.z * d) >> 12);
                d = VEC_DotProduct(&v5, &p->mUnk_2e4);
                p->mUnk_2e4.x -= (s32) (((s64) v5.x * d) >> 12);
                p->mUnk_2e4.y -= (s32) (((s64) v5.y * d) >> 12);
                p->mUnk_2e4.z -= (s32) (((s64) v5.z * d) >> 12);
            }
            p->mUnk_4da = 3;
            if (((s32(*)(Kart *, u32, Vec3 *)) data_0217ac14)(p, f, &v3) != 0 || (p->mUnk_44 & 0x4000000)) {
                n = 0;
                if ((s64) v3.x * v3.x + (s64) v3.y * v3.y + (s64) v3.z * v3.z >= 0x10) {
                    n = Vec3NormalizeAndGetLengthUnchecked(&v3, &v6);
                }
                if (n != 0) {
                    k = 0x802;
                    if (p->mUnk_44 & 0x4000000) {
                        k *= 3;
                    }
                    v6.x = -v6.x;
                    v6.y = -v6.y;
                    v6.z = -v6.z;
                    v6.x = ((s64) v6.x * k) >> 12;
                    v6.y = ((s64) v6.y * k) >> 12;
                    v6.z = ((s64) v6.z * k) >> 12;
                    p->mUnk_374 = v6;
                    p->mUnk_374.y = -0x19a;
                }
                p->mUnk_44 |= 0x200;
            } else {
                p->mUnk_374 = data_02154f94;
                p->mUnk_44 &= ~0x200;
            }
        } else {
            p->mUnk_44 &= ~0x80;
            if (p->mUnk_4da > 0) {
                p->mUnk_4da--;
            }
        }
        if (f & 0x8c10) {
            if ((p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) && (f & 0x10)) {
                if (b2 == 0) {
                    func_0210f458((u16) ((PickCollisionHitValue(0x10) & 0xe0) >> 5));
                }
                p->mUnk_48 |= 0x200000;
            }
            if (f & 0x8c00) {
                if (!(f & 0x400) || !(p->mUnk_44 & 0x80) || (f & 0x800)) {
                    func_0206ff50(p, f);
                }
            }
        }
        if (f & 0x400000) {
            func_020efc74(&(gKartItems)[p->mIndex], (u16) ((PickCollisionHitValue(0x400000) & 0xe0) >> 5));
            if (p->mUnk_4c & 0x10000000) {
                func_02090838(&p->mUnk_538.mUnk_2c, (Unk02080b1c_00 *) (gKartItems)[p->mIndex].mUnk_1f0.mLink);
            }
            if ((p->mUnk_7c & 2) && (f & 0x400000) && p->mState != KART_STATE_LAUNCH_DOUBLE_FLIP) {
                func_0208c1f4(p->mAi);
            }
        }
        if (m != 0) {
            *a = v5;
            if ((s64) a->x * a->x + (s64) a->y * a->y + (s64) a->z * a->z >= 0x10) {
                p->mUnk_48 &= ~0x10000000;
                p->mUnk_3e8 = 0;
                RefreshKartSurface(p);
                if ((f & 0x20000) && !(p->mUnk_4c & 0x10000040) && !(p->mUnk_7c & 0x402000)) {
                    p->mUnk_4c |= 0x40000000;
                    p->mUnk_4d8 = (PickCollisionHitValue(0x20000) & 0xe0) >> 5;
                } else {
                    p->mUnk_4c &= ~0x40000000;
                }
                AdvanceKartQuaternionBlendFactor(p, a);
                if (p->mVerticalSpeed < 0) {
                    p->mVerticalSpeed = (p->mUnk_48 & 1) ? -0x2b9 : -0xd9d;
                }
                func_0206edac(p, a);
                if (f & 0x80000000) {
                    p->mUnk_1fc.y = 0;
                }
                p->mUnk_44 |= KART_44_ON_GROUND;
                if (p->mForwardSpeed != 0 || TryHoldKartStill(p, f, &w) == FALSE) {
                    func_01ff9cb0(p);
                    if (((s32(*)(Kart *, u32, Vec3 *)) data_0217ac14)(p, f, &v3) != 0) {
                        n = 0;
                        if ((s64) v3.x * v3.x + (s64) v3.y * v3.y + (s64) v3.z * v3.z >= 0x10) {
                            n = Vec3NormalizeAndGetLengthUnchecked(&v3, &v7);
                        }
                        if (n != 0) {
                            k = 0x802;
                            if (p->mUnk_44 & 0x4000000) {
                                k *= 3;
                            }
                            v7.x = -v7.x;
                            v7.y = -v7.y;
                            v7.z = -v7.z;
                            v7.x = ((s64) v7.x * k) >> 12;
                            v7.y = ((s64) v7.y * k) >> 12;
                            v7.z = ((s64) v7.z * k) >> 12;
                            p->mUnk_374 = v7;
                            p->mUnk_374.y = -0x19a;
                        }
                        p->mUnk_44 |= 0x200;
                    } else {
                        p->mUnk_374 = data_02154f94;
                        p->mUnk_44 &= ~0x200;
                    }
                }
            }
        } else {
            func_01ffa350(p, 0x10);
        }
    } else {
        func_01ffa350(p, 0x90);
    }
    if (p->mUnk_4dc > 0) {
        p->mUnk_4dc--;
    }
    if (func_020d3d94()) {
        func_0206fe08(p);
    }
    if ((p->mUnk_4c & 0x40000000) && p->mState == KART_STATE_NORMAL) {
        func_0206f824(p, a, b1);
    }
    p->mUnk_274 = ((s64) p->mUnk_274 * 0xf33) >> 12;
    t = p->mUnk_274;
    if ((t > 0 ? t : -t) < 0x29) {
        p->mUnk_274 = 0;
    }
    UpdateKartAirborne(p);
    if (!(p->mUnk_4c & 0x20)) {
        return;
    }
    p->mYRotationAngleSum += p->mYRotationAnglePerFrame;
    e = FALSE;
    t = p->mYRotationAngleSum;
    if ((t > 0 ? t : -t) > p->mYRotationCount * 0xffff) {
        p->mYRotationAngle = 0;
        e = TRUE;
    } else {
        p->mYRotationAngle += p->mYRotationAnglePerFrame;
    }
    p->mUnk_4c |= 2;
    if (e == FALSE) {
        return;
    }
    p->mYRotationAngle = 0;
    p->mUnk_4c &= ~0x20;
}
