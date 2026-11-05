#include "Main/Unknown/code_0206bcb0.h"
#include "01/code_0218155c.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_02109000.h"
#include "Main/Unknown/code_02080cd0.h"
#include "Main/Unknown/code_0208c188.h"
#include "Main/Unknown/code_0208c534.h"
#include "Main/Unknown/code_02109054.h"
#include "Main/Unknown/code_0206a354.h"
#include "Main/Unknown/code_0206d020.h"
#include "ITCM/code_01ffba68.h"
#include "Main/Unknown/code_020681f0.h"

void func_0206ceb4(s32 *out, Kart *p) {
    int id;
    u32 flags;
    Unk0206ceb4 *q;
    u16 a;
    u16 b;
    u16 c;

    p->mUnk_238 = p->mUnk_238 - 1;
    if (p->mUnk_238 <= 0) {
        p->mUnk_48 &= 0xdfff7fdf;
        p->mUnk_238 = 0;
        if (!(p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
            return;
        }
        if (!(p->mUnk_4c & 0x10000000)) {
            ResetCameraHalfFovAngleGoal();
        }
        func_02055c5c();
        return;
    }
    *out = 0x1000;
    if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        id = (p->mUnk_48 & 0x8000) ? 0xa0 : 0x9e;
        func_0210ddf4(&data_0217d26c, func_02086080(p->mIndex), func_020718c8, p, id);
    }
    if (!(p->mUnk_48 & 0x20000000)) {
        return;
    }
    func_021035ac(p->mIndex);
    flags = p->mUnk_4c;
    if (flags & 0x20000) {
        return;
    }
    if (!(flags & 0x8000000)) {
        return;
    }
    q = &p->mUnk_538;
    if (q->mUnk_1c > 400) {
        return;
    }
    q->mUnk_1c = 400;
    p->mUnk_4c |= 0x20000;
    a = func_0207a134();
    b = func_0207a11c();
    c = func_0207a104();
    func_02079f70(p->mKartModelsEntry, a, b, c);
}

void func_0206cdd4(Kart *p) {
    if (!(p->mUnk_44 & 0x10)) {
        p->mUnk_44 |= 0x8000;
    }
    if (p->mUnk_2fc == 4) {
        func_0206d020(p, 1, p->mPhysicalParam->mUnk_0e);
        p->mUnk_48 |= 0x80000;
        p->mUnk_23c = p->mPhysicalParam->mUnk_0e;
        if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
            func_0207a6b0()->mUnk_04++;
            // placeholder: the same test twice gives the original's two loads and compares
            if (data_021759c0->mMode == MODE_MISSION_RUN && data_021759c0->mMode == MODE_MISSION_RUN) {
                func_ov001_0218171c();
            }
        }
    }
    p->mUnk_44 &= 0xfffff7f4;
    p->mTurnDirection = 0;
    p->mUnk_2fc = 0;
    p->mUnk_302 = 0;
    p->mUnk_300 = p->mUnk_302;
    p->mUnk_30c = 0;
    func_0208c534(func_0208c5b8(p->mIndex));
}

void func_0206cc60(Kart *p, int arg) {
    if (p->mTurnDirection > 0) {
        if (p->mTurnAngle > 11000) {
            p->mTurnAngle = p->mTurnAngle - 200;
            if (p->mTurnAngle < 11000) {
                p->mTurnAngle = 11000;
            }
        } else if (p->mTurnAngle < 11000) {
            p->mTurnAngle += 375;
            if (p->mTurnAngle > 11000) {
                p->mTurnAngle = 11000;
            }
        }
    } else {
        if (p->mTurnAngle < -11000) {
            p->mTurnAngle = p->mTurnAngle + 200;
            if (p->mTurnAngle > -11000) {
                p->mTurnAngle = -11000;
            }
        } else if (p->mTurnAngle > -11000) {
            p->mTurnAngle -= 375;
            if (p->mTurnAngle < -11000) {
                p->mTurnAngle = -11000;
            }
        }
    }
    if (arg != 0) {
        return;
    }
    if (p->mUnk_38a <= 50) {
        p->mUnk_38a = 50;
    } else {
        p->mUnk_38a = (s32) (((s64) p->mUnk_38a * 0xf33) >> 12);
    }
    func_020681f0(p);
    if (!(p->mUnk_44 & 0x10)) {
        return;
    }
    func_01ffc9e8(p, 1);
    p->mUnk_4c |= 0x2;
    if (p->mUnk_2fc < 3) {
        return;
    }
    if (!(p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY)) {
        return;
    }
    func_02109078(&p->mUnk_00, 0xd1, 0x7f, 0);
}

void func_0206c5e4(Kart *p) {
    u32 f = p->mUnk_44;
    BOOL hasB = (f & 2) != 0;
    u32 g;
    Unk0208c5b8 *t;
    int id;
    enum { K0 } k;

    if (p->mUnk_7c & 0x400) {
        return;
    }
    if (p->mAirborneFrames >= 5 && !(f & 0x1a)) {
        k = p->mEntryIndex;
        if ((u16) (data_02175628[k].mBits & 0x100)) {
            if (f & 1) {
                goto recheck;
            }
            if (p->mTurnDirection != 0) {
                goto recheck;
            }
            g = p->mUnk_48;
            if (g & 0x10) {
                p->mTurnDirection = 1;
                p->mUnk_44 |= 1;
            } else if (g & 8) {
                p->mTurnDirection = -1;
                p->mUnk_44 |= 1;
            }
        } else {
            p->mUnk_44 &= ~1;
        }
    }
recheck:
    if (p->mUnk_44 & 2) {
        if (p->mTurnDirection == 0) {
            g = p->mUnk_48;
            if (g & 0x10) {
                p->mTurnDirection = 1;
            } else if (g & 8) {
                p->mTurnDirection = -1;
            }
        }
    }
    f = p->mUnk_44;
    g = p->mTurnDirection;
    if (!(f & 8) && (f & 0x10)) {
        if ((f & 3) && p->mVelocityLength > (s32) (((s64) p->mPhysicalParam->mBaseSpeedLimit * 0x8cd) >> 12) &&
            g != 0 && (u16) (data_02175628[k = p->mEntryIndex].mBits & 0x100)) {
            p->mUnk_44 |= 8;
            p->mUnk_2fc = 1;
            if (p->mTurnDirection > 0) {
                p->mUnk_304 = &p->mUnk_300;
                p->mUnk_308 = &p->mUnk_302;
            } else {
                p->mUnk_304 = &p->mUnk_302;
                p->mUnk_308 = &p->mUnk_300;
            }
            if (p->mUnk_4c & 0x8000) {
                t = func_0208c5b8(p->mIndex);
                func_0208ccf0(t);
                func_0208d6b0(t);
            }
        } else {
            p->mTurnDirection = 0;
        }
        p->mUnk_44 &= 0xfffff7fc;
    }
    f = p->mUnk_44;
    if (f & 8) {
        k = p->mEntryIndex;
        if (!((u16) (data_02175628[k].mBits & 0x100) && (p->mUnk_48 & 2) &&
              p->mVelocityLength >= p->mPhysicalParam->mBaseSpeedLimit / 2 && !(f & 0x2000c0))) {
            if (!(f & 0x10)) {
                p->mUnk_44 |= 0x8000;
            }
            if (p->mUnk_2fc == 4) {
                func_0206d020(p, 1, p->mPhysicalParam->mUnk_0e);
                p->mUnk_48 |= 0x80000;
                p->mUnk_23c = p->mPhysicalParam->mUnk_0e;
                if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
                    func_0207a6b0()->mUnk_04++;
                    // placeholder: the same test twice gives the original's two loads and compares
                    if (data_021759c0->mMode == MODE_MISSION_RUN && data_021759c0->mMode == MODE_MISSION_RUN) {
                        func_ov001_0218171c();
                    }
                }
            }
            p->mUnk_44 &= 0xfffff7f4;
            p->mTurnDirection = 0;
            p->mUnk_2fc = 0;
            p->mUnk_302 = 0;
            p->mUnk_300 = p->mUnk_302;
            p->mUnk_30c = 0;
            func_0208c534(func_0208c5b8(p->mIndex));
        } else if (f & 0x10) {
            func_0206cc60(p, 0);
        }
    }
    if (hasB && (p->mUnk_44 & 0x10)) {
        int turn = 0;
        int dot;
        int ang;
        int len;
        Vec3 v;
        Vec3 w;
        Vec3 *q = &p->mUnk_138;

        dot = Vec3Dot(&p->mUnk_284, q);
        v.x = p->mUnk_138.x - (s32) (((s64) p->mUnk_284.x * dot) >> 12);
        v.y = q->y - (s32) (((s64) p->mUnk_284.y * dot) >> 12);
        v.z = q->z - (s32) (((s64) p->mUnk_284.z * dot) >> 12);
        if ((s64) v.x * v.x + (s64) v.y * v.y + (s64) v.z * v.z >= 16 ? Vec3NormalizeAndGetLengthUnchecked(&v, &v)
                                                                      : 0) {
            Vec3CrossUnrounded(&p->mUnk_290, &v, &w);
            len = Vec3Length(&w);
            ang = func_02148538(len, Vec3DotUnrounded(&p->mUnk_290, &v));
            turn = (s16) (((s64) ang * 0x28be60db9391LL + 0x80000000LL) >> 44);
        }
        if (p->mForwardSpeed < 0) {
            g = -g;
        }
        p->mTurnAngle += (s16) (turn * g);
        if (p->mTurnAngle > 0x2af8) {
            p->mTurnAngle = 0x2af8;
        } else if (p->mTurnAngle < -0x2af8) {
            p->mTurnAngle = -0x2af8;
        }
        if (!(p->mUnk_44 & 8)) {
            return;
        }
        p->mUnk_38a = (s32) (((s64) p->mVelocityLength * 0x1a) >> 12);
        return;
    }
    k = p->mEntryIndex;
    if (!(u16) (data_02175628[k].mUnk_00 & 0x100)) {
        if (!(p->mUnk_44 & 0x20000000)) {
            return;
        }
    }
    if (p->mUnk_4c & 0x10000000) {
        return;
    }
    if (!(p->mUnk_44 & 0x10)) {
        return;
    }
    if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        id = func_02086080(p->mIndex);
        func_0210ddf4(&data_0217d284, id + func_0210a578(), func_02071944, p, 0xcf);
    }
    p->mUnk_44 |= 0x806;
    p->mUnk_44 &= 0xffff7ff7;
    p->mHopSpeed = 0x1405;
    p->mVerticalSpeed += 0x21a2;
    p->mHopHeight = 0;
    p->mTurnDirection = 0;
    p->mUnk_38a = 0;
    p->mUnk_2fc = 0;
    p->mUnk_302 = 0;
    p->mUnk_300 = p->mUnk_302;
    p->mUnk_30c = 0;
    GetKartForward(p, &p->mUnk_290);
    GetKartUp(p, &p->mUnk_284);
    if (p->mUnk_208->mUnk_00 != FALSE) {
        p->mUnk_208->mUnk_00 = FALSE;
    }
    if (p->mUnk_7c & 0x200) {
        p->mUnk_514->mUnk_2c ^= 0x1;
    }
}

int func_0206c494(Kart *p) {
    BOOL result = FALSE;
    BOOL pending = TRUE;
    BOOL dir = FALSE;
    int delta;
    u16 bits;
    Unk0208c5b8 *t;
    enum { K0 } k;

    if (p->mVelocityLength < 0x1800 && (p->mUnk_48 & 0x80)) {
        p->mTurnDirection = 0;
        result = TRUE;
        pending = FALSE;
        k = p->mEntryIndex;
        bits = data_02175628[k].mBits;
        if ((u16) (bits & 0x20)) {
            dir = TRUE;
            p->mTurnDirection = -1;
            delta = 500;
        } else if ((u16) (bits & 0x10)) {
            dir = TRUE;
            p->mTurnDirection = 1;
            delta = -500;
        }
        if (p->mUnk_44 & 0x10) {
            if (func_0208c5b8(p->mIndex)->mUnk_3c == 0 && (p->mUnk_4c & 0x8000)) {
                t = func_0208c5b8(p->mIndex);
                func_0208ccf0(t);
                func_0208d6b0(t);
            }
            p->mUnk_48 |= 0x100;
            if (p->mTurnDirection != 0) {
                p->mUnk_44 |= 0x8000000;
                p->mHeadingAngle += delta;
                func_0206cc60(p, 1);
            }
        }
        func_0210b4e0(p, dir, p->mSurfaceKind, p->mSurfaceVariant);
    }
    if (pending) {
        func_0208d650(func_0208c5b8(p->mIndex));
    }
    return result;
}

void func_0206c488(Unk0206c1ac *obj, Kart *p) {
    func_02080e88(obj, p);
}

void func_0206c450(Unk0206c1ac *obj, Kart *p) {
    obj->mUnk_40 = p->mEffectVelocity;
    func_02080e88(obj, p);
}

BOOL func_0206c354(Kart *p, const Vec3 *a, int flag) {
    if (p->mUnk_7c & KART_7C_MODELS_ENTRY_008_SET) {
        int arr[4] = {0x77, 0x76, 0x78, 0x79};
        u16 i = 0;
        u32 n = 1;
        int *list = data_02154f10;
        Vec3 tmp;

        if (flag) {
            list = arr;
            n = 4;
        }
        Vec3AddScaled(-p->mRadius, a, &p->mPos, &tmp);
        Vec3AddScaled((s32) (((s64) p->mScale.y * 0x8000 + 0x800) >> 12), &p->mUnk_12c, &tmp, &tmp);
        for (; i < n; i++) {
            func_0208b748(list[i], &tmp, p, func_0206c450);
        }
        return TRUE;
    }
    return FALSE;
}

void func_0206c2b4(Unk0206c1ac *obj, Kart *p) {
    Vec3 v = p->mEffectVelocity;

    v.y = 0;
    v.x = (s32) (((s64) v.x * 0xe66) >> 12);
    v.y = (s32) (((s64) v.y * 0xe66) >> 12);
    v.z = (s32) (((s64) v.z * 0xe66) >> 12);
    obj->mUnk_40 = v;
}

void func_0206c1ac(Unk0206c1ac *obj, Kart *p) {
    Vec3 v = p->mPos;
    UnkVec16 rot;
    Vec3 *q;

    Vec3AddScaled((s32) (((s64) p->mRadius * -0x1333 + 0x800) >> 12), &p->mUnk_138, &v, &v);
    v.x >>= 4;
    v.y >>= 4;
    v.z >>= 4;
    obj->mUnk_28.x = obj->mUnk_20->mUnk_00->mUnk_04.x + v.x;
    obj->mUnk_28.y = v.y + obj->mUnk_20->mUnk_00->mUnk_04.y;
    obj->mUnk_28.z = v.z + obj->mUnk_20->mUnk_00->mUnk_04.z;
    q = &p->mUnk_138;
    rot.x = q->x;
    rot.y = q->y;
    rot.z = q->z;
    obj->mUnk_50 = rot;
}

void func_0206c17c(Kart *p) {
    if (p->mUnk_7c & 0x40000) {
        return;
    }
    p->mUnk_4c |= 0x400000;
    p->mUnk_506 = 0;
    p->mUnk_504 = p->mUnk_506;
}

void func_0206c14c(Kart *p) {
    if (p->mUnk_7c & 0x2) {
        func_0208c1ac(p->mUnk_310);
    }
}

void func_0206c11c(Kart *p) {
    if (p->mUnk_7c & 0x2) {
        func_0208c188(p->mUnk_310);
    }
}

BOOL func_0206c0e0(Kart *p) {
    if ((p->mUnk_7c & 0x402020) || (p->mUnk_4c & 0x800) || p->mState != 0) {
        return TRUE;
    }
    return FALSE;
}

BOOL func_0206c0b0(Kart *p) {
    if ((p->mUnk_7c & 0x400020) || (p->mUnk_4c & 0x800)) {
        return TRUE;
    }
    return FALSE;
}

int func_0206c0a8(Kart *p) {
    return p->mUnk_4c0;
}

BOOL func_0206c094(Kart *p) {
    return (p->mUnk_4c & 0x800000) != 0;
}

void func_0206bf88(Kart *p, int mode) {
    p->mUnk_48 &= 0xdfe77fdf;
    p->mUnk_238 = 0;
    p->mUnk_538.mUnk_00 = 0;
    p->mUnk_23c = 0;
    if (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) {
        if (!(p->mUnk_4c & 0x10000000) && !(p->mUnk_48 & 0x4000000)) {
            ResetCameraHalfFovAngleGoal();
        }
        func_02055c5c();
    }
    func_02068a64(p, 1, 0);
    p->mState = mode;
    p->mUnk_44 &= 0xfffff7f4;
    p->mTurnDirection = 0;
    p->mUnk_2fc = 0;
    p->mUnk_302 = 0;
    p->mUnk_300 = p->mUnk_302;
    p->mUnk_30c = 0;
    func_0208c534(func_0208c5b8(p->mIndex));
    if (p->mUnk_4c & 0x2000) {
        p->mUnk_4c &= ~0x2000;
        p->mUnk_d8 = 0x1000;
        if (!(p->mUnk_4c & 0x8000000)) {
            func_0207b0d0(p);
        }
        func_02080ee4(p);
    }
}

BOOL func_0206be54(Kart *p, int a) {
    BOOL ok;
    BOOL res;
    BOOL t;
    int v;
    u32 f = p->mUnk_4c;

    if (f & 0x400000) {
        ok = FALSE;
    } else if (p->mUnk_7c & 0x200) {
        if (p->mState == 0 && !(p->mUnk_48 & 0x1800) && !(f & 0x10000040)) {
            ok = TRUE;
        } else {
            ok = FALSE;
        }
    } else {
        switch (a) {
            case 1:
            case 2:
                res = TRUE;
                if (!(f & 0x10000040) && !(p->mUnk_48 & 0x1800)) {
                    v = p->mState;
                    t = FALSE;
                    if (v != 0 && v != 1 && v != 2) {
                        t = TRUE;
                    }
                    if (t == FALSE) {
                        res = FALSE;
                    }
                }
                ok = res == FALSE;
                break;
            default:
                res = TRUE;
                if (!(f & 0x10000040) && !(p->mUnk_48 & 0x1800)) {
                    v = p->mState;
                    t = FALSE;
                    if (v != 0 && v != 1 && v != 2) {
                        t = TRUE;
                    }
                    if (t == FALSE) {
                        res = FALSE;
                    }
                }
                ok = res == FALSE;
                break;
        }
    }
    if (!ok) {
        return FALSE;
    }
    func_0206bf88(p, a);
    return TRUE;
}

BOOL func_0206bcb0(Kart *p, int a, int b) {
    int s = p->mState;
    BOOL x;
    BOOL ok;
    BOOL res;
    BOOL t;
    int v;
    u32 f;

    x = s != 1 && s != 2;
    if (x == FALSE) {
        if (p->mUnk_366 * 0xffff - p->mUnk_368 > 0xffff || (p->mUnk_7c & 0x200)) {
            return FALSE;
        }
    }
    f = p->mUnk_4c;
    if (f & 0x400000) {
        ok = FALSE;
    } else if (p->mUnk_7c & 0x200) {
        if (p->mState == 0 && !(p->mUnk_48 & 0x1800) && !(f & 0x10000040)) {
            ok = TRUE;
        } else {
            ok = FALSE;
        }
    } else {
        res = TRUE;
        if (!(f & 0x10000040) && !(p->mUnk_48 & 0x1800)) {
            v = p->mState;
            t = FALSE;
            if (v != 0 && s != 1 && s != 2) {
                t = TRUE;
            }
            if (t == FALSE) {
                res = FALSE;
            }
        }
        ok = res == FALSE;
    }
    if (!ok) {
        return FALSE;
    }
    if (x) {
        StartKartState2(p, a, b);
        if (b == 0) {
            if (a == 1) {
                if (p->mUnk_7c & 0x200) {
                    p->mUnk_514->mUnk_2c ^= 0x4;
                }
            } else if (a == 2) {
                if (p->mUnk_7c & 0x200) {
                    p->mUnk_514->mUnk_2c ^= 0x8;
                }
            }
        }
    } else {
        p->mUnk_366++;
    }
    return TRUE;
}
