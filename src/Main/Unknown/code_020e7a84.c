#include "Main/Unknown/code_020e7a84.h"

#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_020d4c28.h"
#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0215f000.h"
#include "Main/Unknown/code_020e6fd4.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020d4000.h"
#include "Main/Unknown/code_020ea000.h"
#include "Main/Unknown/code_0210b000.h"
#include "code_0212bcac.h"
#include "code_0212df7c.h"
#include "code_02147288.h"
#include "01/code_02187d14.h"
#include "Main/Unknown/code_0203c5e4.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_020e8a78.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020d3dbc.h"
#include "Main/Unknown/code_020d50ec.h"
#include "Main/Unknown/code_020e66e4.h"
#include "ITCM/code_01ff8000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/code_020d5000.h"
#include "Main/Unknown/code_020d8000.h"
#include "Main/Unknown/code_0203c8c0.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_02088000.h"
#include "Main/Unknown/code_0208ab00.h"
#include "Main/Unknown/code_020d8474.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_020ed5c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "ITCM/code_01ff9000.h"
#include "ITCM/code_01ffcf7c.h"
#include "ITCM/code_01ffd000.h"
#include "Main/Unknown/code_02146000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_02012b30.h"
#include "code_02146cbc.h"
#include "code_02146d78.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_0203c5f8.h"

#pragma thumb off

#pragma thumb on

void CreateModelAnimation(u32 param_1, void *param_2, void **param_3, void *param_4, void *param_5) {
    *param_3 = HeapAlloc(GetHeap(func_020364e8()), 0x38);
    func_0208823c(param_1, *param_3, param_2, 1, GetHeap(func_020364e8()), param_4);
    func_0208805c(*param_3, param_5, GetHeap(func_020364e8()));
    func_02087f84(*param_3, 0);
}

#pragma thumb off

// Stores the two offset constants and the four offset vectors; every x is negated when data_0217b8f8 is 0.
void InitJgOffsets(void) {
    gJgOffsetX = 0xf662;
    gJgOffsetY = 0x1232e;
    gJgKind2Offset = data_02159434;
    gJgKind2Offset.x += 0xf662;
    gJgKind3Offset = data_021593d4;
    gJgKind3Offset.x += 0xf662;
    gJgKind4Offset = data_02159428;
    gJgKind4Offset.x += 0xf662;

    gJgLapOffset = func_0203c5e4() ? data_021593f8 : data_0215941c;
    gJgLapOffset.x += gJgOffsetX;
    if (data_0217b8f8 == 0) {
        gJgKind2Offset.x = -gJgKind2Offset.x;
        gJgKind3Offset.x = -gJgKind3Offset.x;
        gJgLapOffset.x = -gJgLapOffset.x;
        gJgKind4Offset.x = -gJgKind4Offset.x;
    }
    gJgKind4Offset.y += gJgOffsetY;
}

static inline s32 AdvanceJgPointsAndSetTarget_inline(s32 a, s32 b, s32 t) {
    s32 d = b - a;
    return a + (s32) (((s64) d * t) >> 12);
}

// Moves gJgPointPointers along gJgPoints, advances gJgAngle and stores gJgTargetPos.
void AdvanceJgPointsAndSetTarget(Vec3 *param_1, const Vec3 *param_2, const Vec3 *param_3) {
    Vec3 v;
    Vec3 w;
    s32 i;
    s32 c;
    s32 s;
    s32 a;
    s32 b;

    if (func_020d849c(&data_0217bb88.mUnk_00) != FALSE) {
        do {
            for (i = 0; i < 4; i++) {
                gJgPointPointers[i] += 1;
                if (gJgPointPointers[i] > &gJgPoint7) {
                    gJgPointPointers[i] = gJgPoints;
                }
            }
        } while (func_020d7c84(&data_0217bb88.mUnk_00, 0, gJgPointPointers) != FALSE);
    }
    func_020d8488(&data_0217bb88, &v);
    gJgAngle += 0x64;
    i = gJgAngle >> 4;
    c = gPairsByAngle[i * 2];
    s = gPairsByAngle[i * 2 + 1];
    b = AdvanceJgPointsAndSetTarget_inline(param_3->x, param_2->x, (s + 0x1000) >> 2);
    a = AdvanceJgPointsAndSetTarget_inline(param_3->y, param_2->y, (c + 0x1000) >> 2);
    v.x = ((s64) v.x * b) >> 12;
    v.y = ((s64) v.y * a) >> 12;
    v.z = 0;
    VEC_Add(&v, param_1, &v);
    w = v;
    w.x += data_0217b88c;
    MTX_MultVec43(&w, &gJgMatrix, &gJgTargetPos);
}

// Runs the position, matrix and state machine; in state 0 it starts the next state from mStatus, lap and mFlags.
void UpdateJg(void) {
    s32 lap;
    u32 kartFlags;

    if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
        return;
    }
    if (gJgKart == NULL) {
        return;
    }
    if (gJgStateMachine.mState != 0) {
        gJgTableIndex++;
        if (gJgTableIndex >= 0x3c) {
            gJgTableIndex = 0;
        }
        if (gJgKind != 4) {
            JgKindRow *p = &gJgKindRows[gJgKind];
            if (gJgKind != 0 && gJgKind != 1) {
                if (p->mNsbcaAnimation != NULL) {
                    func_02087de0(p->mNsbcaAnimation);
                }
                if (p->mNsbmaAnimation != NULL) {
                    func_02087de0(p->mNsbmaAnimation);
                }
            }
        }
        if (gJgStateMachine.mState != 4 && (gJgStateMachine.mState != 5 || gJgKind != 4)) {
            gJgKartPos = gJgKart->mPos;
            gJgKartPos.y -= gJgKart->mHopHeight;
        }
        ComputeJgMatrixAndInverse();
        UpdateJgPosition();
    }
    func_02046b40(&gJgStateMachine);
    if (gJgStateMachine.mState != 0) {
        return;
    }
    if (gRaceSetup->mMode == MODE_BATTLE) {
        return;
    }
    if (gRaceSetup->mMode != MODE_MISSION_RUN && gRaceProgress->mUnk_000[gJgKartIndex].mStatus == 1 &&
        (gJgKart->mUnk_48 & 0x800) == 0) {
        Vec3 v;
        gJgMain.mUnk_18 = 2;
        gJgKartPos = gJgKart->mPos;
        gJgKartPos.y -= gJgKart->mHopHeight;
        ComputeJgMatrixAndInverse();
        v = gJgKind3Offset;
        v.x += data_0217b88c;
        MTX_MultVec43(&v, &gJgMatrix, &gJgTargetPos);
        gJgKind = 3;
        if (func_0203c5e4() == 0) {
            if ((u32) gJgKind <= 1) {
                data_0217b900 = 1;
                data_0217b8ac = 1;
            }
        }
        func_02046bcc(&gJgStateMachine, 6);
        return;
    }
    if (IsKartEnded(gJgKartIndex) != 0) {
        return;
    }
    if (gJgLapAndReverseEnabled != 0) {
        lap = func_0203c8c0(gJgKartIndex);
        if (gJgHighestLap < (u32) lap) {
            Vec3 v;
            gJgHighestLap = lap;
            gJgKartPos = gJgKart->mPos;
            gJgKartPos.y -= gJgKart->mHopHeight;
            ComputeJgMatrixAndInverse();
            v = gJgLapOffset;
            v.x += data_0217b88c;
            MTX_MultVec43(&v, &gJgMatrix, &gJgTargetPos);
            if (gJgHighestLap == gJgFinalLap) {
                gJgKind = 1;
                if (func_0203c5e4() == 0) {
                    if ((u32) gJgKind <= 1) {
                        data_0217b900 = 1;
                        data_0217b8ac = 1;
                    }
                }
                func_02046bcc(&gJgStateMachine, 6);
                return;
            }
            gJgKind = 0;
            if (func_0203c5e4() == 0) {
                if ((u32) gJgKind <= 1) {
                    data_0217b900 = 1;
                    data_0217b8ac = 1;
                }
            }
            func_02046bcc(&gJgStateMachine, 6);
            return;
        }
    }
    kartFlags = gJgKart->mUnk_48;
    if (kartFlags & 1) {
        return;
    }
    if (gJgLapAndReverseEnabled == 0) {
        return;
    }
    if ((gRaceProgress->mUnk_000[gJgKartIndex].mFlags & 4) != 0 && (kartFlags & 0x800) == 0) {
        data_0217b8c4++;
        if (data_0217b8c4 <= 0x3c) {
            return;
        }
        gJgKartPos = gJgKart->mPos;
        gJgKartPos.y -= gJgKart->mHopHeight;
        ComputeJgMatrixAndInverse();
        func_02046bcc(&gJgStateMachine, 1);
        return;
    }
    data_0217b8c4 = 0;
}

// Draws the cloud, gJgMain and the model gJgKind selects; counts gJgAlpha up to 0x1f while visible.
void DrawJg(void) {
    s32 a, b, c, d, e, f, g, h;
    s32 m[9];
    Vec3 v0, v1, v2, v3, v4, v5, v6;
    BOOL n;
    s32 x;
    s32 y;
    Unk020e9810 *p5;
    Unk020e6488 *p4;

    if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
        return;
    }
    if (gJgKart == NULL) {
        return;
    }
    if (gJgVisible == 0) {
        goto reset;
    }
    n = FALSE;
    p5 = NULL;
    p4 = NULL;
    switch (gJgKind) {
        case 2:
        case 3:
            p5 = gJgKindRows[gJgKind].mModel;
            break;
        case 0:
        case 1:
            p4 = gJgKindRowLapModels[gJgKind].mModel;
            break;
    }
    func_0208ab4c(data_0217b8c0);
    gJgAlpha++;
    if (gJgAlpha > 0x1f) {
        gJgAlpha = 0x1f;
    }
    gJgMain.mUnk_14 &= ~0x1f0000;
    gJgMain.mUnk_14 |= gJgAlpha << 16;
    gJgCloud.mUnk_14 &= ~0x1f0000;
    gJgCloud.mUnk_14 |= gJgAlpha << 16;
    if (p5 != NULL) {
        NNS_G3dMdlSetMdlAlphaAll(p5->mUnk_04, gJgAlpha);
    }
    if (p4 != NULL) {
        p4->mUnk_14 &= ~0x1f0000;
        p4->mUnk_14 |= gJgAlpha << 16;
    }
    if (data_0217b900 != 0) {
        a = 0;
        func_01ff9048(0x10, &a, 1);
        func_01ff9048(0x11, NULL, 0);
        v0.x = 0x19a;
        v0.y = 0x19a;
        v0.z = 0x19a;
        func_01ff9048(0x1b, &v0, 3);
        b = 2;
        func_01ff9048(0x10, &b, 1);
        n = TRUE;
    }
    c = 0x1e;
    func_01ff9048(0x14, &c, 1);
    func_01ff9048(0x19, SetViewTransposeMatrixPos(&gJgEasedPos), 0xc);
    v1.y = data_0217b8a4[gJgTableIndex];
    v1.x = 0;
    v1.z = 0;
    func_01ff9048(0x1c, &v1, 3);
    v2.x = data_0217b8f8 != 0 ? 0x1666 : -0x1666;
    v2.y = 0x1666;
    v2.z = 0x1666;
    func_01ff9048(0x1b, &v2, 3);
    func_01ff9048(0x11, NULL, 0);
    x = data_0217b904[gJgTableIndex];
    y = data_0217b8e0[gJgTableIndex];
    v3.x = x;
    v3.y = y;
    v3.z = 0;
    func_01ff9048(0x1b, &v3, 3);
    func_020e6a18(&gJgCloud);
    func_020e6854(&gJgCloud, NULL, 0, 0x1f);
    d = 1;
    func_01ff9048(0x12, &d, 1);
    v4.x = 0;
    v4.y = 0;
    v4.z = 0xa4;
    func_01ff9048(0x1c, &v4, 3);
    MTX_RotZ33_(m, data_0217b8a8[gJgTableIndex], data_0217b8a0[gJgTableIndex]);
    func_01ff9048(0x1a, m, 9);
    func_020e6a18(&gJgMain);
    func_020e6854(&gJgMain, NULL, 0, 0x1f);
    if (p5 != NULL) {
        if (gJgKind == 3) {
            e = 0;
            func_01ff9048(0x12, &e, 1);
            func_01ff8cf0(p5);
        } else {
            func_01ff9048(0x1c, &data_021593c8, 3);
            if (data_0217b8f8 == 0) {
                v5.x = -0x1000;
                v5.y = 0x1000;
                v5.z = 0x1000;
                func_01ff9048(0x1b, &v5, 3);
            }
            func_01ff8cf0(p5);
        }
    }
    if (p4 != NULL) {
        func_01ff9048(0x1c, &data_021593c8, 3);
        if (data_0217b8f8 == 0) {
            v6.x = -0x1000;
            v6.y = 0x1000;
            v6.z = 0x1000;
            func_01ff9048(0x1b, &v6, 3);
        }
        func_020e6a18(p4);
        func_020e6854(p4, NULL, 0, 0x1f);
    }
    if (n != FALSE) {
        f = 0;
        func_01ff9048(0x10, &f, 1);
        g = 1;
        func_01ff9048(0x12, &g, 1);
        h = 2;
        func_01ff9048(0x10, &h, 1);
    }
    goto done;
reset:
    gJgAlpha = 0;
done:;
}

// Rebuilds gJgMatrix at gJgKartPos and its inverse; first keeps the previous inverse and the position change.
void ComputeJgMatrixAndInverse(void) {
    s32 r;
    s64 sq;
    Vec3 *v;

    gJgPreviousInverseMatrix = gJgInverseMatrix;
    VEC_Subtract(&gJgKartPos, &gJgMatrix.mUnk_00[3], &data_0217b9b4);
    gJgMatrix.mUnk_00[3] = gJgKartPos;
    gJgMatrix.mUnk_00[3].y = gJgMatrix.mUnk_00[3].y + (gJgKart->mVelocity.y - gJgKart->mHopSpeed);
    gJgMatrix.mUnk_00[1] = data_02159494;

    if (func_0203c5e4() != 0) {
        v = &gJgKart->mTurnedForward;
        gJgMatrix.mUnk_00[2].x = -v->x;
        gJgMatrix.mUnk_00[2].y = -v->y;
        gJgMatrix.mUnk_00[2].z = -v->z;
    } else {
        gJgMatrix.mUnk_00[2] = ((MtxFx43 *) GetViewTransposeMatrix())->mUnk_00[2];
    }
    Vec3CrossUnrounded(&gJgMatrix.mUnk_00[1], &gJgMatrix.mUnk_00[2], &gJgMatrix.mUnk_00[2]);
    sq = (s64) gJgMatrix.mUnk_00[2].x * gJgMatrix.mUnk_00[2].x + (s64) gJgMatrix.mUnk_00[2].y * gJgMatrix.mUnk_00[2].y +
         (s64) gJgMatrix.mUnk_00[2].z * gJgMatrix.mUnk_00[2].z;
    r = 0;
    if (sq >= 0x10) {
        r = Vec3NormalizeAndGetLengthUnchecked(&gJgMatrix.mUnk_00[2], &gJgMatrix.mUnk_00[2]);
    }
    if (r != 0) {
        gJgMatrix.mUnk_00[0] = gJgMatrix.mUnk_00[2];
    }
    Vec3CrossUnrounded(&gJgMatrix.mUnk_00[0], &gJgMatrix.mUnk_00[1], &gJgMatrix.mUnk_00[2]);
    MTX_Transpose33_(&gJgMatrix, &gJgInverseMatrix);
    MTX_MultVec33(&gJgMatrix.mUnk_00[3], (const s32 *) &gJgInverseMatrix, &gJgInverseMatrixPos);
    gJgInverseMatrix.mUnk_00[3].x = -gJgInverseMatrix.mUnk_00[3].x;
    gJgInverseMatrix.mUnk_00[3].y = -gJgInverseMatrix.mUnk_00[3].y;
    gJgInverseMatrix.mUnk_00[3].z = -gJgInverseMatrix.mUnk_00[3].z;
}

static inline void UpdateJgPosition_inline(Vec3 *o, const Vec3 *a, const Vec3 *b) {
    o->x = a->x < b->x ? a->x : b->x;
    o->y = a->y < b->y ? a->y : b->y;
    o->z = a->z < b->z ? a->z : b->z;
}

static inline void UpdateJgPosition_inline_2(Vec3 *o, const Vec3 *a, const Vec3 *b) {
    o->x = a->x > b->x ? a->x : b->x;
    o->y = a->y > b->y ? a->y : b->y;
    o->z = a->z > b->z ? a->z : b->z;
}

// Steers gJgPos toward gJgTargetPos (damped, pushed out of map objects and the course); snaps in state 4 or hidden.
void UpdateJgPosition(void) {
    s64 sq;
    s32 dz;
    s32 dx;

    if (gJgStateMachine.mState == 4 || gJgVisible == 0) {
        data_0217b90c = gJgTargetPos;
        data_0217b918 = data_0217b90c;
        data_0217b93c = data_0217b918;
        data_0217b99c = data_0217b93c;
        gJgPos = data_0217b99c;
        data_0217b9b4.x = 0;
        data_0217b9b4.y = 0;
        data_0217b9b4.z = 0;
        gJgVelocity.x = 0;
        gJgVelocity.y = 0;
        gJgVelocity.z = 0;
        data_0217b870 = 0;
        data_0217b8b8 = 0;
        data_0217b88c = 0;
        data_0217b8cc = 0;
        data_0217b8ec = 0;
        gJgEasedPos = gJgPos;
        data_0217b8f0 = 1;
        data_0217b8bc = 1;
        data_0217b894 = 0;
    } else {
        void *p;
        Vec3 t;
        Vec3 u;
        Vec3 v;
        s32 i;
        BOOL pushed = FALSE;
        Vec3 lo, hi;
        s32 d;
        s32 w;
        s32 lim;
        s32 n;

        lo = (Vec3){0, 0, 0};
        hi = (Vec3){0, 0, 0};
        if (gJgStateMachine.mState == 6 || gJgStateMachine.mState == 2) {
            p = NULL;
        } else {
            p = &data_0217b918;
        }
        data_0217b918 = data_0217b93c;
        if (data_0217b8f8 != 0) {
            d = -gJgOffsetX >> 1;
            t.x = ((s64) gJgMatrix.mUnk_00[0].x * d) >> 12;
            t.y = ((s64) gJgMatrix.mUnk_00[0].y * d) >> 12;
            t.z = ((s64) gJgMatrix.mUnk_00[0].z * d) >> 12;
        } else {
            d = gJgOffsetX >> 1;
            t.x = ((s64) gJgMatrix.mUnk_00[0].x * d) >> 12;
            t.y = ((s64) gJgMatrix.mUnk_00[0].y * d) >> 12;
            t.z = ((s64) gJgMatrix.mUnk_00[0].z * d) >> 12;
        }
        VEC_Add(&gJgPos, &t, &data_0217b93c);
        d = -gJgOffsetY >> 1;
        t.x = ((s64) gJgMatrix.mUnk_00[1].x * d) >> 12;
        t.y = ((s64) gJgMatrix.mUnk_00[1].y * d) >> 12;
        t.z = ((s64) gJgMatrix.mUnk_00[1].z * d) >> 12;
        VEC_Add(&data_0217b93c, &t, &data_0217b93c);
        data_0217b8fc = 0;
        if (data_0217b900 == 0) {
            if (data_0217b8bc != 0 || data_0217b8f0 != 0) {
                func_020d5180(&data_0217b93c, 0x12000, 0x2000);
                for (i = 0; i < data_0217b5a8; i++) {
                    MapObject *q = data_0217b5c4[i];

                    if ((q->mFlags & 0x40) == 0 && func_020d3e34(&data_0217b93c, 0x12000, q, &t) != FALSE) {
                        UpdateJgPosition_inline(&lo, &t, &lo);
                        UpdateJgPosition_inline_2(&hi, &t, &hi);
                        pushed = TRUE;
                    }
                }
                if (func_01ffdee4(&data_0217b93c, p, 0, 0x12000, 4, -1, &t, NULL, NULL, &data_0217b8fc, NULL, NULL,
                                  NULL, NULL) != 0) {
                    UpdateJgPosition_inline(&lo, &t, &lo);
                    UpdateJgPosition_inline_2(&hi, &t, &hi);
                    pushed = TRUE;
                }
            }
        }
        if (pushed != FALSE) {
            if ((data_0217b8fc & 0x80000) == 0) {
                data_0217b894 = 0;
            }
            t = lo;
            VEC_Add(&t, &hi, &t);
            if (t.y < 0 && gJgStateMachine.mState == 5) {
                t.y = 0;
            }
            VEC_Add(&gJgPos, &t, &gJgPos);
            VEC_Add(&data_0217b93c, &t, &data_0217b93c);
        }
        if (data_0217b900 == 0) {
            data_0217b870++;
            if (data_0217b870 > 0xc) {
                data_0217b870 = 0;
            }
            data_0217b90c.x = gJgPos.x + data_0217b870 * (s32) (((s64) gJgKart->mVelocity.x * 0x5000) >> 12);
            data_0217b90c.z = gJgPos.z + data_0217b870 * (s32) (((s64) gJgKart->mVelocity.z * 0x5000) >> 12);
            data_0217b90c.y = gJgPos.y;
            if (func_01ffdee4(&data_0217b90c, NULL, 0, 0x18e66, 0x10, -1, NULL, NULL, (s32 *) &v, NULL, NULL, NULL,
                              NULL, NULL) != 0) {
                w = gJgKart->mForwardSpeed;
                if (w <= 0) {
                    w = -w;
                }
                if (Vec3DotUnrounded(&v, &gJgMatrix.mUnk_00[0]) > 0) {
                    data_0217b8b8 = ((s64) w << 11) >> 12;
                } else {
                    data_0217b8b8 = -(s32) (((s64) w << 11) >> 12);
                }
                data_0217b908 += 0xc;
                data_0217b870 = 0xc;
            }
            w = data_0217b8b8 - (s32) (((s64) data_0217b88c * 0x29) >> 12);
            data_0217b8b8 = w;
            if (data_0217b88c * (s64) w < 0) {
                data_0217b8b8 = w - (s32) (((s64) w * 0x19a) >> 12);
            }
            data_0217b88c += data_0217b8b8;
            if (data_0217b8bc == 0) {
                data_0217b8cc += 0xcd;
                data_0217b8ec += data_0217b8cc;
            } else {
                if (data_0217b8ec <= 0) {
                    data_0217b8ec = 0;
                    data_0217b8cc = 0;
                } else {
                    data_0217b8ec -= data_0217b8cc;
                    data_0217b8cc -= 0xcd;
                }
            }
        }
        data_0217b99c = gJgPos;
        if (gJgKart->mState >= KART_STATE_PUSH_FLIP) {
            data_0217b8ac = 0;
        }
        if (data_0217b900 != 0 && data_0217b8ac != 0) {
            gJgPos.x = gJgTargetPos.x;
            gJgPos.z = gJgTargetPos.z;
            u.x = u.z = 0;
            t.y = gJgTargetPos.y - gJgPos.y;
            t.y = t.y + data_0217b8ec;
        } else {
            data_0217b908 -= 0x29;
            if (data_0217b908 > data_021593bc.x) {
                data_0217b908 = data_021593bc.x;
            }
            if (data_0217b908 < 0x7b) {
                data_0217b908 = 0x7b;
            }
            VEC_Subtract(&gJgTargetPos, &gJgPos, &t);
            t.y += data_0217b8ec;
            u.x = Vec3DotUnrounded(&t, &gJgMatrix.mUnk_00[0]);
            u.z = Vec3DotUnrounded(&t, &gJgMatrixAxis2);
            gJgVelocity.x = ((s64) data_0217b908 * u.x) >> 12;
            gJgVelocity.z +=
                (s32) (((s64) data_021593bc.z * u.z) >> 12) - (s32) (((s64) data_021593b0.z * gJgVelocity.z) >> 12);
            v.x = Vec3DotUnrounded(&data_0217b9b4, &gJgMatrix.mUnk_00[0]);
            v.z = Vec3DotUnrounded(&data_0217b9b4, &gJgMatrixAxis2);
            gJgVelocity.x -= v.x;
            gJgVelocity.z -= v.z;
            if (data_0217b8f0 != 0 || data_0217b8bc != 0) {
                lim = data_0217b894 != 0 ? 0x1000 : 0x800;
                if (gJgVelocity.x > lim) {
                    gJgVelocity.x = lim;
                } else if (gJgVelocity.x < -lim) {
                    gJgVelocity.x = -lim;
                }
                n = data_0217b894 != 0 ? 0x2000 : 0x1000;
                if (gJgVelocity.z > n) {
                    gJgVelocity.z = n;
                } else if (gJgVelocity.z < -n) {
                    gJgVelocity.z = -n;
                }
            }
            gJgVelocity.x += v.x;
            gJgVelocity.z += v.z;
            MTX_MultVec33(&gJgVelocity, (const s32 *) &gJgMatrix.mUnk_00[0], &u);
        }
        gJgVelocity.y = gJgVelocity.y + ((s32) (((s64) data_021593bc.y * t.y) >> 12) -
                                         (s32) (((s64) data_021593b0.y * gJgVelocity.y) >> 12));
        u.y = gJgVelocity.y;
        VEC_Add(&gJgPos, &u, &gJgPos);
        VEC_Subtract(&gJgPos, &gJgEasedPos, &v);
        VEC_MultAdd(0xd9a, &v, &gJgEasedPos, &gJgEasedPos);
    }
    if (gJgVisible == 0) {
        return;
    }
    data_0217b8f0 = (func_01ffd648(&gJgPos, 0x12000, 0x708000, 0x5f592e1, 0x1f) & 3) == 0 ? 1 : 0;
    dx = gJgPos.x - gJgMatrix.mUnk_00[3].x;
    dz = gJgPos.z - gJgMatrix.mUnk_00[3].z;
    sq = (s64) dx * dx + (s64) dz * dz;
    data_0217b8bc = sq < 0x57e4000000LL ? 1 : 0;
    if (data_0217b8bc != 0) {
        data_0217b8f4 = 0;
        return;
    }
    data_0217b8f4 = sq >= 0x3d090000000LL ? 1 : 0;
}

u32 EnterJgState0(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    u32 value3;
    u32 value4;
    u32 value12;
    u32 value14;
    value12 = (u32) &gJgKind;
    value4 = 4u;
    value3 = (u32) &gJgVisible;
    value14 = 0u;
    value2 = (u32) &data_0217b8c4;
    value1 = (u32) &data_0217b900;
    value0 = (u32) &data_0217b8ac;
    *(u32 *) ((value12) + (0)) = value4;
    *(u32 *) ((value3) + (0)) = value14;
    *(u32 *) ((value2) + (0)) = value14;
    *(u32 *) ((value1) + (0)) = value14;
    *(u32 *) ((value0) + (0)) = value14;
    return value0;
}

u32 func_020e8a74(u32 p0) {
    return p0;
}

void EnterJgState1(void) {
    Unk020e6514 *p;
    s32 t;

    // Written through a cast: a plain store changes the test below.
    *(s32 *) &gJgKind = 2;
    gJgVisible = 1;
    data_0217b8c4 = 0;
    data_0217b900 = 0;
    data_0217b8ac = 0;
    gJgTableIndex = 0;
    if (gJgKind != 4) {
        p = gJgKindRowNsbcaAnimations[gJgKind].mUnk_00;
        if (p != NULL) {
            p->mUnk_00c = 0;
            p->mUnk_1c[p->mUnk_1a]->mFrame = p->mUnk_00c;
        }
        p = gJgKindRowNsbmaAnimations[gJgKind].mUnk_00;
        if (p != NULL) {
            p->mUnk_00c = 0;
            p->mUnk_1c[p->mUnk_1a]->mFrame = p->mUnk_00c;
        }
    }
    gJgPointPointers[0] = &gJgPoint7;
    gJgPointPointers[1] = gJgPoints;
    gJgPointPointers[2] = &gJgPoint1;
    gJgPointPointers[3] = &gJgPoint2;
    func_020d7d18(&data_0217bb88.mUnk_00, 0, gJgPointPointers, 0x1ec);
    gJgAngle = 0;
    t = (s32) (((s64) gJgKind2Offset.z * data_0215f4b4[1]) >> 12) -
        (s32) (((s64) gJgKind2Offset.x * data_0215f4b4[0]) >> 12);
    data_0217b8b4 = 0x8000;
    gJgTargetPos.z = t;
    if (t > 0) {
        gJgTargetPos.z = t * 3;
    }
    gJgTargetPos.x = (s32) (((s64) gJgKind2Offset.z * data_0215f4b4[0]) >> 12) +
                     (s32) (((s64) gJgKind2Offset.x * data_0215f4b4[1]) >> 12);
    gJgTargetPos.y = gJgKind2Offset.y;
    MTX_MultVec43(&gJgTargetPos, &gJgMatrix, &gJgTargetPos);
    data_0217b90c = gJgTargetPos;
    data_0217b918 = data_0217b90c;
    data_0217b93c = data_0217b918;
    data_0217b99c = data_0217b93c;
    gJgPos = data_0217b99c;
    data_0217b9b4.x = 0;
    data_0217b9b4.y = 0;
    data_0217b9b4.z = 0;
    gJgVelocity.x = 0;
    data_0217b870 = 0;
    gJgVelocity.y = 0;
    gJgVelocity.z = 0;
    data_0217b8b8 = 0;
    data_0217b88c = 0;
    data_0217b8cc = 0;
    gJgEasedPos = gJgPos;
    data_0217b8ec = 0;
    data_0217b8f0 = 1;
    data_0217b8bc = 1;
    data_0217b894 = 0;
}

void UpdateJgState1(void) {
    Unk020e6514 *animation;
    s32 n;
    u32 frame;
    s32 i;
    s32 s;
    s32 c;
    s32 t;
    NNSSndSeqPlayer **player;
    s32 b;
    enum { K0 } d;

    animation = gJgKindRowNsbmaAnimations[gJgKind].mUnk_00;
    d = animation->mUnk_00c;
    n = data_0217b8b4;
    frame = ((u32) d << 4) >> 16;
    if (n > 0 && n < 0x10000) {
        i = (n >> 4) << 1;
        s = gPairsByAngle[i];
        c = gPairsByAngle[i + 1];
        b = ((s64) gJgKind2Offset.z * c) >> 12;
        t = b - (s32) (((s64) gJgKind2Offset.x * s) >> 12);
        gJgTargetPos.z = t;
        if (t > 0) {
            gJgTargetPos.z = t * 3;
        }
        gJgTargetPos.x = (s32) (((s64) gJgKind2Offset.z * s) >> 12) + (s32) (((s64) gJgKind2Offset.x * c) >> 12);
        gJgTargetPos.y = gJgKind2Offset.y;
        MTX_MultVec43(&gJgTargetPos, &gJgMatrix, &gJgTargetPos);
        if (data_0217b8f8 != 0) {
            data_0217b8b4 -= 0xf0;
        } else {
            data_0217b8b4 += 0xf0;
        }
        data_0217b908 = data_021593bc.x;
        data_0217b894 = 1;
    } else {
        data_0217b894 = 0;
        AdvanceJgPointsAndSetTarget(&gJgKind2Offset, &data_02159404, &data_02159410);
        if (data_0217b8f0 == 0 && data_0217b8bc == 0) {
            func_02046bcc(&gJgStateMachine, 1);
        }
    }
    if (frame == 0xa || frame == 0x28) {
        player = func_02108e6c(4);
        data_0217b9dc.mUnk_0c = func_020d4ef4(&gJgPos);
        NNS_SndPlayerStopSeq(player, 0);
        func_0210b760(&data_0217b9dc, player);
    }
    if (IsKartEnded(gJgKartIndex) != 0 || (gJgKart->mUnk_48 & 0x800) != 0) {
        func_02046bcc(&gJgStateMachine, 5);
        return;
    }
    if ((gRaceProgress->mUnk_000[gJgKartIndex].mFlags & 4) == 0) {
        if (++data_0217b8c4 > 0x3c) {
            func_02046bcc(&gJgStateMachine, 5);
            return;
        }
    } else {
        data_0217b8c4 = 0;
    }
    if ((gJgKart->mUnk_48 & 1) == 0) {
        return;
    }
    func_02046bcc(&gJgStateMachine, 5);
}

void EnterJgState2(void) {
    Vec3 v;

    if (gJgHighestLap != gJgFinalLap) {
        gJgKindRows[0].mLapModel->mUnk_18 = gJgHighestLap - 2;
    }
    data_0217b8b4 = 0;
    v = gJgLapOffset;
    v.x += data_0217b88c;
    MTX_MultVec43(&v, &gJgMatrix, &gJgTargetPos);
}

void UpdateJgState2(void) {
    Vec3 v;

    v = gJgLapOffset;
    v.x += data_0217b88c;
    MTX_MultVec43(&v, &gJgMatrix, &gJgTargetPos);
    if (++data_0217b8b4 > gJgState2FrameCount || (gJgKart->mUnk_48 & 0x800) != 0) {
        func_02046bcc(&gJgStateMachine, 5);
    }
}

void EnterJgState3(void) {
    gJgPointPointers[0] = &gJgPoint7;
    gJgPointPointers[1] = gJgPoints;
    gJgPointPointers[2] = &gJgPoint1;
    gJgPointPointers[3] = &gJgPoint2;
    func_020d7d18(&data_0217bb88.mUnk_00, 0, gJgPointPointers, 0x1ec);
    gJgAngle = 0;
    AdvanceJgPointsAndSetTarget(&gJgKind3Offset, &data_021593e0, &data_021593ec);
}

void UpdateJgState3(void) {
    AdvanceJgPointsAndSetTarget(&gJgKind3Offset, &data_021593e0, &data_021593ec);
    if ((gJgKart->mUnk_48 & 0x800) == 0) {
        return;
    }
    func_02046bcc(&gJgStateMachine, 5);
}

void EnterJgState4(void) {
    Unk020e6514 *p;
    NNSSndSeqPlayer **player;
    MtxFx43 *matrix;

    data_0217b8c4 = 0;
    // Written through a cast: a plain store changes the test below.
    *(s32 *) &gJgKind = 4;
    gJgVisible = 1;
    gJgAlpha = 0x1f;
    data_0217b900 = 0;
    data_0217b8ac = 0;
    gJgTableIndex = 0;
    if (gJgKind != 4) {
        p = gJgKindRowNsbcaAnimations[gJgKind].mUnk_00;
        if (p != NULL) {
            p->mUnk_00c = 0;
            p->mUnk_1c[p->mUnk_1a]->mFrame = p->mUnk_00c;
        }
        p = gJgKindRowNsbmaAnimations[gJgKind].mUnk_00;
        if (p != NULL) {
            p->mUnk_00c = 0;
            p->mUnk_1c[p->mUnk_1a]->mFrame = p->mUnk_00c;
        }
    }
    gJgMain.mUnk_18 = 1;
    data_0217b8b4 = 0;
    if (func_0203c5e4() != 0) {
        matrix = func_020e6b48();
        matrix->mUnk_00[3] = gJgKartPos;
        MTX_MultVec43(&gJgKind4Offset, matrix, &gJgTargetPos);
    } else {
        MTX_MultVec43(&gJgKind4Offset, &gJgMatrix, &gJgTargetPos);
    }
    data_0217b90c = gJgTargetPos;
    data_0217b918 = data_0217b90c;
    data_0217b93c = data_0217b918;
    data_0217b99c = data_0217b93c;
    gJgPos = data_0217b99c;
    data_0217b9b4.x = 0;
    data_0217b9b4.y = 0;
    data_0217b9b4.z = 0;
    gJgVelocity.x = 0;
    data_0217b870 = 0;
    data_0217b8b8 = 0;
    gJgVelocity.y = 0;
    gJgVelocity.z = 0;
    data_0217b88c = 0;
    data_0217b8cc = 0;
    data_0217b8ec = 0;
    gJgEasedPos = gJgPos;
    data_0217b8f0 = 1;
    data_0217b8bc = 1;
    data_0217b894 = 0;
    NNS_SndPlayerStopSeq(func_02108e6c(4), 1);
    player = func_02108e6c(4);
    if ((data_0217c780 & 1) == 0) {
        return;
    }
    if (data_0217d084.mUnk_0c == 0) {
        return;
    }
    if (*player != NULL) {
        NNS_SndPlayerStopSeq(player, 0);
    }
    if (*player != NULL) {
        NNS_SndPlayerStopSeq(player, 0);
    }
    NNS_SndArcPlayerStartSeqArc(player, 0, 0x102);
}

void UpdateJgState4(void) {
    MtxFx43 *matrix;

    if (data_0217b8b4 == 0) {
        gJgKartPos = gJgKart->mPos;
    } else if (--data_0217b8b4 <= 0) {
        gJgMain.mUnk_18 = 0;
        func_02046bcc(&gJgStateMachine, 5);
    }
    if (func_0203c5e4() != 0) {
        matrix = func_020e6b48();
        matrix->mUnk_00[3] = gJgKartPos;
        MTX_MultVec43(&gJgKind4Offset, matrix, &gJgTargetPos);
    } else {
        MTX_MultVec43(&gJgKind4Offset, &gJgMatrix, &gJgTargetPos);
    }
}

void EnterJgState5(void) {
    s32 a;

    gJgVisible = 1;
    MTX_MultVec43(&gJgTargetPos, &gJgPreviousInverseMatrix, &data_0217b984);
    data_0217b89c = 0;
    a = 0;
    if ((gJgKart->mUnk_48 & 1) == 0) {
        a = 0xffffbccd;
    }
    data_0217b8d8 = a;
}

void UpdateJgState5(void) {
    s32 a;

    MTX_MultVec43(&data_0217b984, &gJgMatrix, &gJgTargetPos);
    if ((gJgKart->mUnk_48 & 1) != 0) {
        a = 0x2000;
    } else {
        a = 0x800;
    }
    data_0217b8d8 += a;
    data_0217b89c += data_0217b8d8;
    gJgTargetPos.y += data_0217b89c;
    if (data_0217b89c <= 0x5dc000) {
        return;
    }
    if (data_0217b8f0 != 0) {
        return;
    }
    NNS_SndPlayerStopSeq(func_02108e6c(4), 1);
    func_02046bcc(&gJgStateMachine, 0);
}

void EnterJgState6(void) {
    Unk020e6514 *p;
    s32 b;
    s32 a;
    s32 i;
    s32 t;

    gJgVisible = 1;
    gJgTableIndex = 0;
    if (gJgKind != 4) {
        p = gJgKindRowNsbcaAnimations[gJgKind].mUnk_00;
        if (p != NULL) {
            p->mUnk_00c = 0;
            p->mUnk_1c[p->mUnk_1a]->mFrame = p->mUnk_00c;
        }
        p = gJgKindRowNsbmaAnimations[gJgKind].mUnk_00;
        if (p != NULL) {
            p->mUnk_00c = 0;
            p->mUnk_1c[p->mUnk_1a]->mFrame = p->mUnk_00c;
        }
    }
    MTX_MultVec43(&gJgTargetPos, &gJgPreviousInverseMatrix, &data_0217b96c);
    for (i = 0, b = 0, a = 0; i < 0x1e; i++) {
        t = (b > -0x3000) ? -0x3000 : b;
        a -= t;
        b += 0x19a;
    }
    gJgTargetPos.y += a;
    data_0217b90c = gJgTargetPos;
    data_0217b918 = data_0217b90c;
    data_0217b93c = data_0217b918;
    data_0217b898 = a;
    data_0217b99c = data_0217b93c;
    data_0217b8d0 = b;
    gJgPos = data_0217b99c;
    data_0217b9b4.x = 0;
    data_0217b9b4.y = 0;
    data_0217b9b4.z = 0;
    gJgVelocity.x = 0;
    gJgVelocity.y = 0;
    gJgVelocity.z = 0;
    data_0217b870 = 0;
    data_0217b8b8 = 0;
    data_0217b88c = 0;
    data_0217b8cc = 0;
    data_0217b8ec = 0;
    gJgEasedPos = gJgPos;
    data_0217b8f0 = 1;
    data_0217b8bc = 1;
    data_0217b894 = 0;
}

// Lowers the target from above; when the height reaches 0 it picks state 2 (kinds 0, 1), 3 (kind 3) or 5.
void UpdateJgState6(void) {
    s32 a;
    s32 b;

    MTX_MultVec43(&data_0217b96c, &gJgMatrix, &gJgTargetPos);
    data_0217b8d0 -= 0x19a;
    a = data_0217b8d0;
    if (a > -0x3000) {
        a = -0x3000;
    }
    b = data_0217b898 + a;
    data_0217b898 = b;
    gJgTargetPos.y += b;
    if (b <= 0) {
        switch (gJgKind) {
            case 0:
            case 1:
                func_02046bcc(&gJgStateMachine, 2);
                break;
            case 3:
                func_02046bcc(&gJgStateMachine, 3);
                break;
            default:
                func_02046bcc(&gJgStateMachine, 5);
                break;
        }
    }
    data_0217b908 = data_021593bc.x;
}
