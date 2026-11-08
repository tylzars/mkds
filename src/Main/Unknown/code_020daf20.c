#include "Main/Unknown/code_020daf20.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_0208b484.h"
#include "Main/Unknown/code_020d2dec.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_020d8b88.h"
#include "code_02146cbc.h"
#include "code_02148538.h"
#include "Main/Unknown/code_020ea588.h"
#include "Main/Unknown/code_020ea55c.h"
#include "Main/Unknown/code_02084000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_02046be8.h"
#include "Main/Unknown/unk_02158000.h"
#include "Main/Unknown/unk_0216b000.h"
#include "Main/Unknown/code_020dda38.h"
#include "ITCM/code_01ffba68.h"
#include "ITCM/code_01ffc000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_02146000.h"
#include "code_02146d78.h"
#include "Main/Unknown/code_020ea670.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020d8648.h"
#include "Main/Unknown/code_020d8918.h"
#include "Main/Unknown/code_0208b000.h"
#include "Main/Unknown/code_02073000.h"
#include "Main/Unknown/code_0210b760.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_020d275c.h"
#include "Main/Unknown/code_020d6dc0.h"
#include "Main/Unknown/code_020d849c.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020d8cac.h"
#include "Main/Unknown/code_020d8000.h"
#include "Main/Unknown/code_020d7da8.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020e66e4.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020d88fc.h"
#include "Main/Unknown/code_020e6b58.h"
#include "Main/Unknown/code_020f36d8.h"

#pragma thumb off

Unk020dbf2c *CreateDossunKindData(void) {
    Unk020dbf2c *p;
    p = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *p = data_0215828c;
    return p;
}

Unk020dbed0 *CreateDossunDrawList(void) {
    Unk020dbed0 *p;
    p = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    data_0217b698 = p;
    *p = data_02158260;
    func_020d49d8(&data_0217b698);
    return data_0217b698;
}

Unk020dbe74 *CreateDossunUpdateList(void) {
    Unk020dbe74 *p;
    p = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    data_0217b690 = p;
    *p = data_02158238;
    SetUpdateListSlot(&data_0217b690);
    return data_0217b690;
}

void DrawDossun(void *a, Dossun *p, void *c, s32 d) {
    MtxFx43 *q;
    q = &p->mUnk_00.mMatrix;
    if (p->mUnk_b4 != 0) {
        q = &data_0217b69c;
        MTX_RotY33_((s32 *) &data_0217b69c, gPairsByAngle[((u16) p->mUnk_ba >> 4) * 2],
                    gPairsByAngle[((u16) p->mUnk_ba >> 4) * 2 + 1]);
        MTX_Concat33((const s32 *) &data_0217b69c, (const s32 *) &p->mUnk_00.mMatrix, (s32 *) &data_0217b69c);
    }
    q->mUnk_00[3].x = p->mUnk_00.mPos.x >> 4;
    q->mUnk_00[3].y = p->mUnk_00.mPos.y >> 4;
    q->mUnk_00[3].z = p->mUnk_00.mPos.z >> 4;
    DrawNsbmdWithMatrixAndMaxAlpha(gDossun, q, &p->mUnk_00.mScale, d);
    DrawShadowWithMaxAlpha(gDossunShadow, q, &p->mUnk_00.mScale, d);
}

void UpdateDossun(void *a, Dossun *p) {
    Unk0210b7a8 s;
    Unk020e0144 *q;
    Unk02042044 *e;
    s32 n;
    s32 v;
    s32 t;
    s32 w;
    p->mUnk_b0 = FALSE;
    q = &p->mUnk_c8;
    if (p->mUnk_b4 != 0) {
        p->mUnk_ba += p->mUnk_b8;
        n = p->mUnk_b8;
        if (n > 0x3e8 || n < -0x3e8) {
            if (p->mState < 4) {
                p->mUnk_b8 = (n * 0xfa00) >> 16;
            } else {
                p->mUnk_b8 = (n * 0xf80c) >> 16;
            }
        } else if (p->mUnk_b4 == 2) {
            if (n * p->mUnk_ba <= 0) {
                return;
            }
            if (n * n <= p->mUnk_ba * p->mUnk_ba) {
                return;
            }
            p->mUnk_b8 = 0;
            p->mUnk_ba = p->mUnk_b8;
            p->mUnk_b4 = 0;
            p->mUnk_c0 = 0;
            p->mTimer = 0x1e;
            p->mState = 0;
            return;
        }
        if (p->mUnk_b4 != 1) {
            return;
        }
        v = q->mUnk_04;
        if (p->mState < 4) {
            if (v > 0x4000) {
                t = ((s64) v * 0xf85) >> 12;
                q->mUnk_04 = t;
                q->mUnk_10 = ((s64) t * q->mUnk_00->mUnk_00[q->mUnk_0c].mUnk_34) >> 12;
            }
        } else {
            if (v > 0x800) {
                t = ((s64) v * 0xe66) >> 12;
                q->mUnk_04 = t;
                q->mUnk_10 = ((s64) t * q->mUnk_00->mUnk_00[q->mUnk_0c].mUnk_34) >> 12;
            }
        }
        if (func_020d8cc8(q) != FALSE) {
            p->mUnk_00.mPos = q->mUnk_1c->mUnk_00;
            p->mUnk_00.mPos.y += p->mUnk_f8;
            if (q->mUnk_18 != 0) {
                q->mUnk_14 = 0;
            } else {
                ReverseGroupFollower(q);
                SetGroupFollowerSegmentEnd(q);
            }
            p->mUnk_b4 = 2;
            return;
        }
        GetGroupFollowerLinearPosition(q, &p->mUnk_00.mPos);
        p->mUnk_00.mPos.y += p->mUnk_f8;
        return;
    }
    switch (p->mState) {
        case 0:
            p->mTimer--;
            if (p->mTimer >= 0) {
                return;
            }
            p->mState++;
            t = p->mUnk_f0 != 0 ? 0xc00 : 0x3000;
            q->mUnk_04 = t;
            q->mUnk_10 = ((s64) t * q->mUnk_00->mUnk_00[q->mUnk_0c].mUnk_34) >> 12;
            return;
        case 1:
            if (p->mUnk_f0 != 0) {
                StartMapObjectSoundWhileRequested(&p->mUnk_00, 0x18b);
            }
            break;
        case 2:
            p->mTimer--;
            if (p->mTimer < 0 && p->mUnk_c2 < 0x1555) {
                p->mState++;
                p->mUnk_a8 = -p->mUnk_100;
                return;
            }
            p->mUnk_c2 += 0x1555;
            p->mUnk_00.mPos.y = p->mUnk_ac;
            w = gPairsByAngle[(p->mUnk_c2 >> 4) * 2];
            p->mUnk_00.mPos.y += (s32) (((s64) w * p->mUnk_c4) >> 12);
            return;
        case 3:
            p->mUnk_a8 += p->mUnk_104;
            p->mUnk_00.mPos.y -= p->mUnk_a8;
            if (p->mUnk_00.mPos.y < p->mUnk_ac) {
                p->mState++;
            }
            return;
        case 4:
            if (p->mUnk_a8 < 0x14000) {
                p->mUnk_a8 += 0x1000;
                t = p->mUnk_a8;
                q->mUnk_04 = t;
                q->mUnk_10 = ((s64) t * q->mUnk_00->mUnk_00[q->mUnk_0c].mUnk_34) >> 12;
            }
            break;
        case 5:
            p->mTimer--;
            if (p->mTimer >= 0) {
                return;
            }
            p->mState++;
            t = p->mUnk_108;
            q->mUnk_04 = t;
            q->mUnk_10 = ((s64) t * q->mUnk_00->mUnk_00[q->mUnk_0c].mUnk_34) >> 12;
            return;
        case 6:
            break;
    }
    if (func_020d8cc8(q) != FALSE) {
        switch (q->mUnk_1c->mUnk_10) {
            case 0:
                n = 0;
                break;
            case 1:
                n = 2;
                break;
            case 2:
                n = 5;
                break;
            default:
                n = 0;
                break;
        }
        p->mState = n;
        if (p->mState == 2) {
            p->mUnk_ac = p->mUnk_00.mPos.y;
            p->mUnk_c2 = 0;
        }
        if (p->mState == 5) {
            e = q->mUnk_1c;
            if (func_020d4ddc(&p->mUnk_00) == FALSE) {
                if (p->mUnk_00.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
                    n = 2;
                } else if (p->mUnk_00.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
                    n = 3;
                } else {
                    n = 4;
                }
                s.mUnk_00 = 0x166;
                s.mUnk_04 = &p->mUnk_00.mPos;
                s.mUnk_08 = n;
                s.mUnk_0c = GetHorizontalCameraDistanceSquared(&p->mUnk_00.mPos);
                func_0210b7a8(&s);
            }
            StartCameraWobbleAtDistance(p->mUnk_00.mDistanceSquaredAndFlags & ~0xc000001f, 0x1000);
            if ((p->mUnk_00.mDistanceSquaredAndFlags & 3) == 0) {
                StartEffect(0x59, &e->mUnk_00);
                StartEffect(0x5a, &e->mUnk_00);
            }
            p->mUnk_b0 = TRUE;
        }
        p->mTimer = q->mUnk_1c->mUnk_0e;
        if (p->mTimer != 0) {
            p->mUnk_00.mPos = q->mUnk_00->mUnk_00[q->mUnk_0c].mUnk_00[0];
            p->mUnk_00.mPos.y += p->mUnk_f8;
            q->mUnk_14 = 0;
            return;
        }
    }
    GetGroupFollowerLinearPosition(q, &p->mUnk_00.mPos);
    p->mUnk_00.mPos.y += p->mUnk_f8;
}

u32 CollideKartWithDossun(Dossun *p, Kart *a, u8 *b, u8 *c) {
    Vec3 s0;
    Vec3 s1;
    Vec3 s2;
    Unk020e0144 *q;
    s32 t;
    s64 m;
    s32 y;
    s64 n;
    q = &p->mUnk_c8;
    if (*b == 1) {
        if ((p->mUnk_c0 & (1 << a->mIndex)) == 0 || p->mUnk_bc + 0xf < GetRaceUpdateFrames()) {
            VEC_Subtract(&a->mCollisionCenter, &p->mUnk_00.mPos, &s0);
            VEC_Subtract(&q->mUnk_20->mUnk_00, &p->mUnk_00.mPos, &s1);
            s1.y += p->mUnk_f8;
            if (Vec3DotUnrounded(&s0, &s1) > 0) {
                ReverseGroupFollower(q);
            }
            if (p->mState < 4) {
                t = 0xa800;
            } else {
                t = 0x8000;
            }
            t = t - (s32) (((s64) (0x1000 - p->mUnk_00.mScale.y) * 0x2000) >> 12);
            q->mUnk_04 = t;
            q->mUnk_10 = ((s64) t * q->mUnk_00->mUnk_00[q->mUnk_0c].mUnk_34) >> 12;
            p->mUnk_b4 = 1;
            p->mUnk_b8 = 0x1b58;
            if ((s64) s0.z * a->mVelocity.x - (s64) s0.x * a->mVelocity.z < 0) {
                p->mUnk_b8 = -p->mUnk_b8;
            }
            StartSoundIfKartStarOrKiller(&p->mUnk_00, a);
            p->mUnk_c0 |= 1 << a->mIndex;
            p->mUnk_bc = GetRaceUpdateFrames();
        }
    }
    if (p->mState == 4 || p->mUnk_b0 != FALSE) {
        VEC_Subtract(&a->mCollisionCenter, &p->mUnk_00.mPos, &s2);
        n = ((s64) s2.x * s2.x + (s64) s2.z * s2.z) * 5;
        y = s2.y;
        m = ((s64) y * y) << 2;
        if (y < 0 && n < m) {
            return GetKartMapObjectResponseByKind(p->mUnk_00.mFlags & 0x800, a->mItemEffect, 4, 4);
        }
    }
    return *c;
}

s32 func_020db4c4(Dossun *p) {
    s32 r;
    s32 n;
    r = func_020d8cac(&p->mUnk_c8);
    n = p->mState;
    if (n < 4) {
        if (p->mUnk_f0 != 0) {
            return 0;
        }
        return 0x1000;
    }
    switch (p->mUnk_b4) {
        case 0:
            switch (n) {
                case 4:
                    r = 0x1000 - r;
                    break;
                case 5:
                    r = 0;
                    break;
                case 6:
                    break;
            }
            break;
        case 2:
            r = 0x1000;
            break;
    }
    return r;
}

#pragma thumb on
void func_020db430(Dossun *p) {
    Unk020e0144 *q;
    s32 n;
    q = &p->mUnk_c8;
    func_020d90a8(q, p->mUnk_ec, 1);
    GetGroupFollowerLinearPosition(q, &p->mUnk_00.mPos);
    p->mUnk_00.mPos.y += p->mUnk_f8;
    switch (q->mUnk_1c->mUnk_10) {
        case 0:
            n = 0;
            break;
        case 1:
            n = 2;
            break;
        case 2:
            n = 5;
            break;
        default:
            n = 0;
            break;
    }
    p->mState = n;
    p->mTimer = q->mUnk_1c->mUnk_0e;
    p->mUnk_b4 = 0;
    p->mUnk_ba = 0;
    p->mUnk_b8 = p->mUnk_ba;
    p->mUnk_c0 = 0;
    p->mUnk_ac = p->mUnk_00.mPos.y;
    p->mUnk_b0 = FALSE;
}
#pragma thumb off

#pragma thumb on
void CreateDossunAndDossunShadow(void) {
    CreateNsbmd((void **) &gDossun, FindCourseMapObjFile("dossun.nsbmd"), NULL);
    CreateShadowModel((void **) &gDossunShadow, FindCourseMapObjFile("dossun_shadow.nsbmd"), 0x3f);
    func_02084968(gDossun, 0x3f, 2, 0x294a);
}
#pragma thumb off

#pragma thumb on
void InitDossun(Dossun *p, CourseMapRow *a) {
    p->mUnk_f0 = a->mUnk_28;
    InitGroupFollower(&p->mUnk_c8, a, p->mUnk_f0 != 0 ? 0xc00 : 0x3000);
    p->mUnk_ec = a->mUnk_2a;
    p->mUnk_f4 = ((s64) p->mUnk_00.mScale.x * 0x28000) >> 12;
    p->mUnk_f8 = ((s64) p->mUnk_00.mScale.y * 0x2d000) >> 12;
    p->mUnk_fc = ((s64) p->mUnk_00.mScale.z * 0x1e000) >> 12;
    p->mUnk_100 = ((s64) p->mUnk_00.mScale.y * 0xf000) >> 12;
    p->mUnk_104 = ((s64) p->mUnk_00.mScale.y * 0x1000) >> 12;
    p->mUnk_108 = ((s64) p->mUnk_00.mScale.y * 0x2000) >> 12;
    p->mUnk_c4 = ((s64) p->mUnk_00.mScale.y * 0x3000) >> 12;
    func_020db430(p);
    if (p->mUnk_f0 != 0) {
        CreateMapObjectSoundSourceFalloff3(&p->mUnk_00);
    } else {
        p->mUnk_00.mFarDistanceSquared = gSoundFalloffs[3].mUnk_20;
    }
}
#pragma thumb off

Unk020db268 *CreateKuriboKindData(void) {
    Unk020db268 *p;
    p = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *p = data_021581b8;
    return p;
}

Unk020db20c *CreateKuriboDrawList(void) {
    Unk020db20c *p;
    p = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    data_0217b680 = p;
    *p = data_0215818c;
    func_020d49d8(&data_0217b680);
    return data_0217b680;
}

Unk020db1b0 *CreateKuriboUpdateList(void) {
    Unk020db1b0 *p;
    p = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    data_0217b684 = p;
    *p = data_02158164;
    SetUpdateListSlot(&data_0217b684);
    return data_0217b684;
}

void SetupDrawKuribo(void) {
    func_020e6a18(gKuribo);
}

void DrawKuribo(void *a, Kuribo *p, void *c, u16 d) {
    Vec3 s;
    Quaternion t;
    u16 e;
    Unk020e6488 *q;
    if (p->mUnk_cc.mUnk_08 == 0xffff) {
        func_020d7938(&p->mUnk_a4, &gViewYawQuaternion, &t);
        Matrix3x3FromQuaternion(&p->mUnk_00.mMatrix, &t);
    } else {
        func_020e6d34(func_020d88fc(&p->mUnk_cc), &p->mUnk_00.mMatrix);
    }
    s.z = p->mUnk_00.mScale.z;
    s.y = ((s64) p->mUnk_00.mScale.y * p->mUnk_c4) >> 12;
    s.x = ((s64) p->mUnk_00.mScale.x * (((0x1000 - p->mUnk_c4) >> 1) + 0x1000)) >> 12;
    p->mUnk_00.mMatrix.mUnk_00[3].x = p->mUnk_00.mPos.x >> 4;
    p->mUnk_00.mMatrix.mUnk_00[3].y = p->mUnk_00.mPos.y >> 4;
    p->mUnk_00.mMatrix.mUnk_00[3].z = p->mUnk_00.mPos.z >> 4;
    if (p->mUnk_f0 < 0x14) {
        gKuribo->mFrameIndex = p->mUnk_f0;
    } else {
        s.x = -s.x;
        gKuribo->mFrameIndex = p->mUnk_f0 - 0x14;
    }
    e = p->mUnk_100;
    q = gKuribo;
    q->mUnk_14 &= ~0x1f0000;
    q->mUnk_14 |= e << 16;
    func_020e67c4(gKuribo, &p->mUnk_00.mMatrix, &s, 0, d);
}

void UpdateKuribo(void *a, Kuribo *p) {
    Unk0210b7a8 s;
    Unk020f41c4_B *r;
    s32 n;
    p->mUnk_f0++;
    if (p->mUnk_f0 == 0x14 || p->mUnk_f0 == 0x28) {
        if ((p->mUnk_00.mDistanceSquaredAndFlags & 4) == 0) {
            if (p->mUnk_00.mFarDistanceSquared == gSoundFalloffs[2].mUnk_20) {
                n = 2;
            } else if (p->mUnk_00.mFarDistanceSquared == gSoundFalloffs[3].mUnk_20) {
                n = 3;
            } else {
                n = 4;
            }
            s.mUnk_00 = 0x182;
            s.mUnk_04 = &p->mUnk_00.mPos;
            s.mUnk_08 = n;
            s.mUnk_0c = GetHorizontalCameraDistanceSquared(&p->mUnk_00.mPos);
            func_0210b7a8(&s);
        }
    }
    if (p->mUnk_f0 >= 0x28) {
        if (p->mUnk_f4 != 0) {
            p->mUnk_f0 = 0;
        } else {
            r = &gRaceProgress->mRandom;
            r->mValue = r->mMultiplier * r->mValue + r->mIncrement;
            p->mUnk_f0 = ((u64) (u32) (r->mValue >> 32) * 0x28) >> 32;
            p->mUnk_f4 = 1;
        }
    }
    AdvanceStateMachine(&p->mUnk_00.mStateMachine);
}
