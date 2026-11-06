#include "Main/Unknown/code_0206e874.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0206f04c.h"
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
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02086058.h"
#include "Main/Unknown/code_020c476c.h"
#include "Main/Unknown/code_020d24d8.h"
#include "Main/Unknown/code_020d4104.h"
#include "Main/Unknown/code_020d411c.h"
#include "Main/Unknown/code_020d4130.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/code_020d6538.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_02165000.h"
#include "code_02147cd8.h"

static inline s32 func_0206e874_inline(Vec3 *v, Vec3 *n) {
    if ((s64) v->x * v->x + (s64) v->y * v->y + (s64) v->z * v->z < 0x10) {
        return 0;
    }
    return Vec3NormalizeAndGetLengthUnchecked(v, n);
}

void func_0206edac(Kart *p, Vec3 *a) {
    Vec3 v;
    s32 k;
    s32 s;
    s32 m;
    s32 n;
    u32 f;
    s32 x;
    s32 c;

    if (p->mUnk_44 & 0x40000010) {
        return;
    }
    p->mUnk_44 |= 0x10000;
    if (p->mUnk_4dc <= 0) {
        k = (p->mUnk_7c & KART_7C_INDEX_IS_SELECTED_ENTRY) ? 3 : 2;
        x = data_usa_0216ca38[2];
        c = func_02086080(p->mIndex);
        func_0210ddf4(&data_0217d26c + k, c + x, (void (*)(void *, int)) func_02071958, p, 2);
        func_02071318(p, 0);
    }
    p->mUnk_4dc = 7;
    if (p->mUnk_48 & 0x2000000) {
        p->mUnk_4c &= ~0x800;
        p->mUnk_48 &= ~0x2000000;
        p->mUnk_40c = GetRaceUpdateFrames();
        func_020c4a04(p->mIndex);
        return;
    }
    if ((!(p->mUnk_4c & 0x10000000) && p->mVelocity.y < 0 &&
         (p->mAirborneFrames > 0x19 || p->mLastGroundY - p->mPos.y > 0x1e000)) ||
        p->mState == KART_STATE_LAUNCH_DOUBLE_FLIP) {
        s = VEC_DotProduct(a, &p->mVelocity);
        v.x = ((s64) a->x * s) >> 12;
        v.y = ((s64) a->y * s) >> 12;
        v.z = ((s64) a->z * s) >> 12;
        if (VEC_Mag(&v) > 0x2000) {
            m = ((s64) p->mUnk_dc * 0x1800) >> 12;
            n = v.y;
            if (n <= 0) {
                n = -n;
            }
            p->mVerticalSpeed = ((s64) n * 0x99a) >> 12;
            if (p->mVerticalSpeed > m) {
                p->mVerticalSpeed = m;
            }
            f = p->mUnk_7c;
            if ((f & 0x10) && p->mKartModelsEntry->mUnk_058 == 0) {
                if ((f & 1) || !(f & 0x402000)) {
                    func_0208b748(0x4e, &p->mPos, p, func_0206c2b4);
                }
            }
        }
    }
    if (p->mAirborneFrames <= 0x14) {
        return;
    }
    s = Vec3DotUnrounded(&p->mUnk_138, a);
    if (s >= 0) {
        return;
    }
    if (p->mUnk_234 <= 0x3e8) {
        return;
    }
    p->mForwardSpeed = ((s64) p->mForwardSpeed * (s + 0x1000)) >> 12;
}

void func_0206e874(Kart *p) {
    MapObject *v1[2] = {0};
    s32 i;
    MapObject *e;
    Vec3 t;
    Vec3 v;
    Vec3 w;
    Vec3 z;
    Vec3 *q;
    Vec3 *u;
    s32 v2;
    BOOL v3;
    u16 n;
    BOOL v4;
    s32 g;
    s32 h;
    s32 k;
    s32 r;
    s32 s;
    s32 d;
    s32 m;
    s32 v5;
    s32 v6;
    s32 v7;
    u16 j;

    v3 = FALSE;
    e = NULL;
    n = 0;
    p->mUnk_3a0 = p->mUnk_39c = 0;
    k = func_020d41e0(p, &p->mCollisionCenter, &t);
    if (k != 0) {
        if (!(p->mUnk_48 & 0x40)) {
            i = k - 1;
            p->mUnk_44 |= 0x40000;
            if (i >= 0) {
                z = data_02154f94;
                do {
                    s = 0;
                    v4 = FALSE;
                    e = GetFoundMapObject(i);
                    h = func_020d6be0(p, e);
                    r = ((s32(*)(Kart *, s32 *, MapObject *)) data_0217ac18[h])(p, &v2, e);
                    if (r != 0) {
                        v = z;
                        u = &e->mUnk_10;
                        q = func_020d4104(i);
                        d = func_0206e874_inline(q, &v);
                        if (d != 0) {
                            if (v2 != 2) {
                                ((void (*)(Kart *, Vec3 *, MapObject *)) data_0217ac54[h])(p, &v, e);
                            }
                            if (r & 8) {
                                func_0206f04c(p, &v, (p->mUnk_44 & 0x40) ? 1 : 0, 0x1000, -1, -1, v2);
                            } else if (r & 2) {
                                s = Vec3DotUnrounded(&p->mUnk_50, &v) + 0x1000;
                                if (s > 0x1000) {
                                    s = 0x1000;
                                } else if (s < 0x29) {
                                    s = 0x29;
                                }
                                p->mUnk_38c = ((s64) p->mUnk_38c * s) >> 12;
                            }
                        }
                        if (r & 1) {
                            if (u->x != 0 || u->y != 0 || u->z != 0) {
                                w = z;
                                m = 1;
                                if (r & 4) {
                                    w = *u;
                                } else {
                                    if (d != 0) {
                                        s = VEC_DotProduct(&v, u);
                                        w.x = ((s64) v.x * s) >> 12;
                                        w.y = ((s64) v.y * s) >> 12;
                                        w.z = ((s64) v.z * s) >> 12;
                                    }
                                    if (Vec3DotUnrounded(&v, &w) < 0) {
                                        m = 0;
                                    }
                                }
                                p->mUnk_39c = VEC_Mag(&w);
                                if (p->mUnk_39c > 0x1000 && m != 0) {
                                    p->mUnk_3a0 = Vec3DotUnrounded(&p->mUnk_50, &w);
                                    s = VEC_DotProduct(&p->mUnk_50, &w);
                                    v6 = w.y - (s32) (((s64) p->mUnk_50.y * s) >> 12);
                                    v7 = w.z - (s32) (((s64) p->mUnk_50.z * s) >> 12);
                                    v5 = w.x - (s32) (((s64) p->mUnk_50.x * s) >> 12);
                                    p->mUnk_2d8.x += v5;
                                    p->mUnk_2d8.z += v7;
                                    p->mVerticalSpeed += v6;
                                }
                            }
                        }
                        s = p->mUnk_38c;
                        if (r & 8) {
                            v3 = TRUE;
                        }
                    }
                    g = e->mFlags & 0x200;
                    if (g != 0) {
                        m = 0x1000;
                    } else {
                        m = ((s64) (0x1000 - s) * (s32) (((s64) p->mVelocityLength * data_usa_021654ec) >> 12)) >> 12;
                    }
                    if (p->mVelocityLength > 0x2000 || g != 0) {
                        if (n < 2) {
                            for (j = 0; j < 2; j++) {
                                if (e == p->mUnk_438[j]) {
                                    v4 = TRUE;
                                    break;
                                }
                            }
                            if (v4 == FALSE) {
                                for (j = 0; j < 2; j++) {
                                    if (e == p->mUnk_438[j] || p->mUnk_444[j] != 0) {
                                        continue;
                                    }
                                    func_020d2668(e, &p->mSoundSource, v2, m);
                                    p->mUnk_444[j] = 1;
                                    break;
                                }
                            }
                            v1[n] = e;
                            n++;
                        }
                    }
                    if (h == 0xb) {
                        p->mUnk_44c = e;
                    }
                } while (--i >= 0);
            }
        }
        if (p->mUnk_48 & 0x4000000) {
            if (p->mUnk_44c == e) {
                t.z = 0;
                t.x = 0;
            }
        }
        VEC_Add(&p->mPos, &t, &p->mPos);
    }
    for (j = 0; j < 2; j++) {
        p->mUnk_438[j] = v1[j];
        if (p->mUnk_444[j] != 0) {
            p->mUnk_440[j]++;
            if (p->mUnk_440[j] > 10) {
                p->mUnk_444[j] = 0;
                p->mUnk_440[j] = 0;
            }
        }
    }
    if (v3 != FALSE) {
        p->mUnk_44 |= 0x40;
    } else {
        p->mUnk_44 &= ~0x40;
    }
}
