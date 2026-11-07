#include "Main/Unknown/code_021031f4.h"
#include "Main/Unknown/code_020ec8bc.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020d3b10.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020d3000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_020f8e3c.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_020e6000.h"
#include "Main/Unknown/code_020e6a74.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_02108e6c.h"
#include "Main/Unknown/unk_0217c000.h"
#include "code_0212bcac.h"
#include "code_0214a748.h"
#include "Main/Unknown/code_02103598.h"
#include "Main/Unknown/code_021035ac.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02103840.h"
#include "Main/Unknown/unk_0215a000.h"
#include "Main/Unknown/code_0210e000.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_0203c5e4.h"
#include "Main/Unknown/code_02108ea0.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "code_0214a4dc.h"
#include "Main/Unknown/code_021053e4.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_02077bc0.h"
#include "registers.h"

#pragma thumb on

void func_021049a4(void) {
    int v1;
    int v2;
    ItemObject *v3;
    ItemObject **v4;
    ItemPool *v6;
    MapObject *v5;
    if (gItemInfos[17].mEnabled != FALSE) {
        v6 = &gItemPools[8];
        v4 = v6->mObjects;
        v1 = v6->mObjectCount;
        v2 = 0;
        if (0 < v1) {
            do {
                v3 = *v4;
                v5 = AllocPooledMapObject();
                *(MapObject **) ((s32) v3 + 0x134) = v5;
                *(s32 *) (*(s32 *) ((s32) v3 + 0x134) + 0xfc) = (s32) v3 + 0x13c;
                v4 = v4 + 1;
                v2 = v2 + 1;
            } while (v2 < v1);
        }
        v6->mUnk_40 = 1;
    }
}

#pragma thumb off

#pragma thumb on

void func_02104970(void) {
    s32 i;
    u32 *p;
    u32 *q;

    if (data_021759c0->mMode != MODE_BATTLE) {
        return;
    }
    i = 0;
    p = data_0217c6e4;
    q = data_0217c704;
    do {
        *p++ = -1;
        *q++ = 0;
        i++;
    } while (i < 8);
}

#pragma thumb off

void func_0210465c(OrthoQuad *p) {
    s16(*q)[2];
    s32 d;
    s32 i;
    s32 k;
    NNSSndSeqPlayer **r;
    s16 x;
    s16 y;
    s32 b;

    q = p->mCornerVelocities;
    d = gOrthoQuadFrames - gOrthoQuadMoveStartFrameCount;
    if (d < 0) {
        for (i = 0; i < 4; i++) {
            p->mCorners[i][1] -= 2;
        }
        return;
    }
    if (d == 0 && gOrthoQuadUseCreamEffect == 0 && p == gOrthoQuads) {
        r = func_02108e6c(6);
        NNS_SndPlayerStopSeq(r, 1);
        if ((data_0217c780 & 1) != 0 && data_0217d084.mUnk_0c != 0) {
            if (*r != NULL) {
                NNS_SndPlayerStopSeq(r, 0);
            }
            if (*r != NULL) {
                NNS_SndPlayerStopSeq(r, 0);
            }
            NNS_SndArcPlayerStartSeqArc(r, 0, 0xef);
        }
    }
    if (p->mVelocityMode != 0) {
        for (i = 0; i < 4; i++) {
            p->mCorners[i][0] += q[i][0];
            p->mCorners[i][1] += q[i][1];
            q[i][0] = ((s64) q[i][0] * 0x10cd) >> 12;
            q[i][1] = ((s64) q[i][1] * 0x10cd) >> 12;
            x = p->mCorners[i][0];
            if (x > 0x3ccd) {
                p->mCorners[i][0] = 0x3ccd;
            } else if (x < -0x3ccd) {
                p->mCorners[i][0] = -0x3ccd;
            }
            y = p->mCorners[i][1];
            if (y > 0x3ccd) {
                p->mCorners[i][1] = 0x3ccd;
            } else if (y < -0x3ccd) {
                p->mCorners[i][1] = -0x3ccd;
            }
        }
    } else {
        i = 0;
        if (i < 4) {
            do {
                x = q[i][0];
                y = q[i][1];
                if (y < 0) {
                    k = y * y > x * x ? 7 : 5;
                    if (i == p->mPickedCornerIndex) {
                        k += (k << 1) + ((k * d) >> 9);
                    }
                } else {
                    k = y * y > x * x ? 2 : 3;
                }
                b = k;
                b += (k * d) >> 8;
                p->mCorners[i][1] = p->mCorners[i][1] - b;
                if (p->mCorners[i][1] < -0x3ccd) {
                    p->mCorners[i][1] = -0x3ccd;
                }
                i++;
            } while (i < 4);
        }
    }
    p->mTimer = p->mTimer - 1;
    if ((p->mTimer & 0xf) == 0) {
        Unk020f41c4_B *a = &gRaceProgress->mLocalRandom;

        a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
        p->mPickedCornerIndex = (u16) (((u64) (u32) (a->mUnk_00 >> 32) * 6) >> 32);
    }
}

void AdvanceOrthoQuadCornersByTable(OrthoQuad *p) {
    s16(*q)[2] = p->mCornerVelocities;
    s32 i;
    s32 k;
    s16 a;
    s16 b;
    s32 v;

    k = data_0215a48c[-p->mTimer];
    a = p->mStartPair[0];
    b = p->mStartPair[1];
    for (i = 0; i < 4; i++) {
        v = q[i][0];
        p->mCorners[i][0] = a + (s32) (((s64) v * k) >> 12);
        v = q[i][1];
        p->mCorners[i][1] = b + (s32) (((s64) v * k) >> 12);
    }
    p->mTimer = p->mTimer - 1;
    if (p->mTimer == -13) {
        p->mUpdateFunction = func_0210465c;
    }
}

void AdvanceOrthoQuadDelayAndStartSound(OrthoQuad *p) {
    NNSSndSeqPlayer **r;
    u32 v;

    p->mTimer = p->mTimer - 1;
    if (p->mTimer != 0) {
        return;
    }
    p->mUpdateFunction = AdvanceOrthoQuadCornersByTable;
    if (func_0203c5e4() != 0) {
        return;
    }
    v = gOrthoQuadUseCreamEffect != 0 ? 0x157 : 0xee;
    if (v == 1) {
        return;
    }
    if ((data_0217c780 & 1) == 0) {
        return;
    }
    r = func_0210e128(func_02108ea0(0));
    if (data_0217d084.mUnk_0c == 0) {
        return;
    }
    if (*r != NULL) {
        NNS_SndPlayerStopSeq(r, 0);
    }
    if (*r != NULL) {
        NNS_SndPlayerStopSeq(r, 0);
    }
    NNS_SndArcPlayerStartSeqArc(r, 0, (u16) v);
}

void UpdateOrthoQuads(void) {
    s32 i;
    OrthoQuadModel *p;
    s32 n;
    u16 h;

    if (gOrthoQuadCount == 0) {
        return;
    }
    for (i = 0; i < gOrthoQuadCount; i++) {
        OrthoQuad *e = &gOrthoQuads[i];

        e->mUpdateFunction(e);
    }
    n = gOrthoQuadFrames + 1;
    gOrthoQuadFrames = n;
    if (n <= gOrthoQuadHoldFrameCount) {
        return;
    }
    if (n & 1) {
        return;
    }
    h = gOrthoQuadAlpha;
    gOrthoQuadAlpha = h - 1;
    h = gOrthoQuadAlpha;
    if (h == 0) {
        gOrthoQuadCount = 0;
        gOrthoQuadUseCreamEffect = FALSE;
        NNS_SndPlayerStopSeq(func_02108e6c(6), 1);
        return;
    }
    p = gOrthoQuadUseCreamEffect != 0 ? &gOrthoQuadCreamEffect : &gOrthoQuadGesoSumi;
    p->mPolygonAttr = p->mPolygonAttr & ~0x1f0000;
    p->mPolygonAttr = p->mPolygonAttr | (h << 16);
}

void DrawOrthoQuadsWithModel(OrthoQuadModel *p) {
    s32 i;

    if (gOrthoQuadCount == 0) {
        return;
    }
    if (func_0203c5e4() != 0) {
        return;
    }
    reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~0x3000) | 8;
    reg_G3_TEXIMAGE_PARAM = p->mTeximageParam;
    reg_G3_PLTT_BASE = p->mPlttBase;
    reg_G3_DIF_AMB = p->mDifAmb;
    reg_G3_SPE_EMI = p->mSpeEmi;
    reg_G3_MTX_MODE = 0;
    G3_LoadMtx44(gOrthoQuadMatrix);
    reg_G3_MTX_MODE = 3;
    reg_G3_MTX_IDENTITY = 0;
    reg_G3_MTX_MODE = 2;
    reg_G3_MTX_IDENTITY = 0;
    reg_G3_MTX_SCALE = 0x64000;
    reg_G3_MTX_SCALE = 0x64000;
    reg_G3_MTX_SCALE = 0x64000;
    i = 0;
    if (gOrthoQuadCount <= 0) {
        return;
    }
    do {
        OrthoQuad *e = &gOrthoQuads[i];

        reg_G3_POLYGON_ATTR = p->mPolygonAttr | (gOrthoQuadFirstPolygonId + i) << 24;
        reg_G3_BEGIN_VTXS = 1;
        reg_G3_TEXCOORD = 0;
        reg_G3_VTX_16 = *(u32 *) &e->mCorners[0];
        reg_G3_VTX_16 = 0;
        reg_G3_TEXCOORD = (u16) ((s32) (p->mUnk_1c << 8) >> 16) << 16;
        *(u32 *) 0x4000494 = *(u32 *) &e->mCorners[1];
        reg_G3_TEXCOORD = (u16) ((s32) (p->mUnk_18 << 8) >> 16) | ((u16) ((s32) (p->mUnk_1c << 8) >> 16) << 16);
        *(u32 *) 0x4000494 = *(u32 *) &e->mCorners[2];
        reg_G3_TEXCOORD = (u16) ((s32) (p->mUnk_18 << 8) >> 16);
        *(u32 *) 0x4000494 = *(u32 *) &e->mCorners[3];
        reg_G3_END_VTXS = 0;
        i++;
    } while (i < gOrthoQuadCount);
}

void DrawOrthoQuads(void) {
    DrawOrthoQuadsWithModel(gOrthoQuadUseCreamEffect != 0 ? &gOrthoQuadCreamEffect : &gOrthoQuadGesoSumi);
}

// Marks the cells in rows row - 2 to row + 2 next to column; returns the bits that were already marked.
u8 MarkOrthoQuadCellsAndGetOverlap(s32 column, s32 row) {
    u8 y;
    s32 m5;
    s32 m3;
    u8 x;

    m3 = (1 << (column + 1)) | (1 << (column + 2)) | (1 << (column + 3));
    m5 = m3 | (1 << column) | (1 << (column + 4));
    y = 0;
    if (row > 1) {
        y |= gOrthoQuadCells[row - 2] & (u8) (m3 >> 3);
        gOrthoQuadCells[row - 2] |= (u8) (m3 >> 3);
    }
    if (row > 0) {
        y |= gOrthoQuadCells[row - 1] & (u8) (m5 >> 3);
        gOrthoQuadCells[row - 1] |= (u8) (m5 >> 3);
    }
    x = y | (gOrthoQuadCells[row] & (u8) (m5 >> 3));
    gOrthoQuadCells[row] |= (u8) (m5 >> 3);
    if (row < 7) {
        x |= gOrthoQuadCells[row + 1] & (u8) (m5 >> 3);
        gOrthoQuadCells[row + 1] |= (u8) (m5 >> 3);
    }
    if (row < 6) {
        x |= gOrthoQuadCells[row + 2] & (u8) (m3 >> 3);
        gOrthoQuadCells[row + 2] |= (u8) (m3 >> 3);
    }
    return x;
}

void SetupOrthoQuad(s32 index, Unk021035ac_Pair startPair, s32 overlap) {
    RaceProgress *b;
    Unk020f41c4_B *a;
    OrthoQuad *e;
    s16(*q)[2];
    s32 i;
    s16 c;
    s16 s;
    s32 t;
    s16 f0;
    s16 f1;

    b = gRaceProgress;
    e = &gOrthoQuads[index];
    a = &b->mLocalRandom;
    q = e->mCornerVelocities;
    a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
    t = (s32) (u16) (((u64) (u32) (a->mUnk_00 >> 32) * 0x10000) >> 32) >> 4;
    c = gPairsByAngle[2 * t];
    s = gPairsByAngle[2 * t + 1];
    if (overlap != 0) {
        a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
        t = (s16) (((u64) (u32) (a->mUnk_00 >> 32) * 0xcd) >> 32) + 0x800;
    } else {
        a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
        t = 0xa66 + (s16) (((u64) (u32) (a->mUnk_00 >> 32) * 0x52) >> 32);
    }
    t = (s16) t;
    if (gOrthoQuadUseCreamEffect != 0) {
        t = (s16) (((s64) t * 0x800) >> 12);
    }
    e->mTimer = data_0215a47c[index];
    q[0][0] = -t;
    q[0][1] = -t;
    q[1][0] = -t;
    q[1][1] = t;
    q[2][0] = t;
    q[2][1] = t;
    q[3][0] = t;
    q[3][1] = -t;
    for (i = 0; i < 4; i++) {
        f1 = q[i][1];
        f0 = q[i][0];
        q[i][0] = (s * f0 - c * f1) >> 12;
        q[i][1] = (c * f0 + s * f1) >> 12;
        *(Unk021035ac_Pair *) e->mCorners[(u32) i] = startPair;
    }
    *(Unk021035ac_Pair *) e->mStartPair = startPair;
    e->mUpdateFunction = AdvanceOrthoQuadDelayAndStartSound;
    e->mPickedCornerIndex = -1;
    e->mVelocityMode = 0;
}

// Local entry only: places up to count quads at random cells; the cream effect does not restart while quads show.
void StartOrthoQuads(s32 kartIndex, s32 count, s32 useCreamEffect) {
    Unk021035ac_Pair v;
    s32 i;
    s32 j;
    s32 m;
    s32 t8;
    s32 t10;
    Unk020f41c4_B *a;

    a = &gRaceProgress->mLocalRandom;
    GetKart(kartIndex);
    if (kartIndex != data_021759c0->mEntryIndex) {
        return;
    }
    data_0217c638 = kartIndex;
    if (gOrthoQuadCount != 0) {
        if (useCreamEffect != 0) {
            return;
        }
    }
    gOrthoQuadCount = 0;
    gOrthoQuadUseCreamEffect = FALSE;
    NNS_SndPlayerStopSeq(func_02108e6c(6), 1);
    gOrthoQuadUseCreamEffect = useCreamEffect;
    for (i = 0; i < 8; i++) {
        gOrthoQuadCells[i] = 0;
    }
    m = 1;
    for (i = 0, j = 0; i < 0x10 && j < count; i++) {
        if (gOrthoQuadUseCreamEffect != 0) {
            a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
            v.mHalf.mUnk_00 = (s16) (((u64) (u32) (a->mUnk_00 >> 32) * 0x1000) >> 32) * 2;
            a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
            v.mHalf.mUnk_02 = (s16) (((u64) (u32) (a->mUnk_00 >> 32) * 0xc00) >> 32) * 2;
        } else if (gOrthoQuadCount == 0) {
            a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
            v.mHalf.mUnk_00 = ((u64) (u32) (a->mUnk_00 >> 32) * 0x1000) >> 32;
            a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
            v.mHalf.mUnk_00 = v.mHalf.mUnk_00 + (s16) (((u64) (u32) (a->mUnk_00 >> 32) * 0x1000) >> 32);
            a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
            v.mHalf.mUnk_02 = ((u64) (u32) (a->mUnk_00 >> 32) * 0xc00) >> 32;
            a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
            v.mHalf.mUnk_02 = v.mHalf.mUnk_02 + (s16) (((u64) (u32) (a->mUnk_00 >> 32) * 0xc00) >> 32);
        } else {
            a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
            v.mHalf.mUnk_00 = ((u64) (u32) (a->mUnk_00 >> 32) * 0x2000) >> 32;
            a->mUnk_00 = a->mUnk_08 * a->mUnk_00 + a->mUnk_10;
            v.mHalf.mUnk_02 = ((u64) (u32) (a->mUnk_00 >> 32) * 0x1800) >> 32;
        }
        t8 = v.mHalf.mUnk_00 >> 10;
        t10 = v.mHalf.mUnk_02 >> 10;
        if (t10 >= 3 || t8 < 3 || t8 > 4) {
            if ((gOrthoQuadCells[t10] & (m << t8)) == 0) {
                s32 r = MarkOrthoQuadCellsAndGetOverlap(t8, t10);

                v.mHalf.mUnk_00 -= 0x1000;
                v.mHalf.mUnk_02 -= 0x600;
                SetupOrthoQuad(j, v, r);
                j++;
            }
        }
    }
    gOrthoQuadCount = j;
    gOrthoQuadFrames = 0;
    gOrthoQuadAlpha = 0x1f;
    if (gOrthoQuadUseCreamEffect != 0) {
        gOrthoQuadHoldFrameCount = 0x96;
        gOrthoQuadMoveStartFrameCount = 0x1e;
        gOrthoQuadCreamEffect.mPolygonAttr &= ~0x1f0000;
        gOrthoQuadCreamEffect.mPolygonAttr |= 0x1f0000;
    } else {
        gOrthoQuadHoldFrameCount = 0x184;
        gOrthoQuadMoveStartFrameCount = 0x2d;
        gOrthoQuadGesoSumi.mPolygonAttr &= ~0x1f0000;
        gOrthoQuadGesoSumi.mPolygonAttr |= 0x1f0000;
    }
}

void StartOrthoQuadsGesoSumi(u32 param_1, u32 param_2) {
    StartOrthoQuads(param_1, param_2, 0);
}

void StopOrthoQuads(int v1) {
    if (v1 != data_021759c0->mEntryIndex) {
        return;
    }
    gOrthoQuadCount = 0;
    gOrthoQuadUseCreamEffect = FALSE;
    NNS_SndPlayerStopSeq(func_02108e6c(6), 1);
}

// Local entry only: moves the frame counter up to the hold count so the alpha starts to fall.
u32 SkipOrthoQuadsHold(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 compareLeft0;
    u32 compareRight0;
    u32 compareLeft1;
    u32 compareRight1;
    s32 compareLeft2;
    s32 compareRight2;
    value1 = data_021759c0->mEntryIndex;
    compareLeft0 = value0;
    compareRight0 = value1;
    if (compareLeft0 != compareRight0) {
        return value0;
    }
    value0 = (u32) &gOrthoQuadCount;
    value0 = *(const u32 *) ((value0) + (0));
    compareLeft1 = value0;
    compareRight1 = 0u;
    if (compareLeft1 == compareRight1) {
        return value0;
    }
    value1 = (u32) &gOrthoQuadHoldFrameCount;
    value0 = (u32) &gOrthoQuadFrames;
    value2 = *(const u32 *) ((value1) + (0));
    value1 = *(const u32 *) ((value0) + (0));
    compareLeft2 = value1;
    compareRight2 = value2;
    if (compareLeft2 < compareRight2) {
        *(u32 *) ((value0) + (0)) = value2;
    }
    return value0;
}

// Derives the corner velocities from the corner positions and switches the quad to velocity mode.
void SetOrthoQuadVelocitiesFromCorners(OrthoQuad *p) {
    s32 i;
    s32 a;
    s32 b;
    s32 vb;
    s32 va;
    s32 j;
    s16(*q)[2] = p->mCornerVelocities;

    for (i = 0; i < 4; i++) {
        q[i][0] = 0;
        q[i][1] = 0;
    }
    for (i = 0; i < 4; i++) {
        a = p->mCorners[i][0];
        b = p->mCorners[i][1];
        if (a > 0) {
            if (a > 0x4cd) {
                va = ((s64) a * a) >> 12;
            } else {
                va = 0x171;
            }
        } else {
            if (a < 0x4cd) {
                va = -(s32) (((s64) a * a) >> 12);
            } else {
                va = -0x171;
            }
        }
        if (b > 0) {
            if (b > 0x4cd) {
                vb = ((s64) b * b) >> 12;
            } else {
                vb = 0x171;
            }
        } else {
            if (b < 0x4cd) {
                vb = -(s32) (((s64) b * b) >> 12);
            } else {
                vb = -0x171;
            }
        }
        for (j = 0; j < 4; j++) {
            if (i == j) {
                q[j][0] += (s32) (((s64) va * 12) >> 12);
                q[j][1] += (s32) (((s64) vb * 12) >> 12);
            } else {
                q[j][0] += (s32) (((s64) va * 8) >> 12);
                q[j][1] += (s32) (((s64) vb * 8) >> 12);
            }
        }
    }
    for (i = 0; i < 4; i++) {
        if (q[i][1] < 0) {
            q[i][1] = 0;
        }
    }
    p->mVelocityMode = 1;
}

void SkipOrthoQuadsHoldAndSetVelocities(int b2) {
    OrthoQuad *e;
    s32 i;
    s32 n;
    s32 a;
    s32 b;

    if (b2 != data_021759c0->mEntryIndex) {
        return;
    }
    n = gOrthoQuadCount;
    if (n == 0) {
        return;
    }
    a = gOrthoQuadHoldFrameCount;
    b = gOrthoQuadFrames;
    if (b < a) {
        gOrthoQuadFrames = a;
    }
    i = 0;
    if (n <= 0) {
        return;
    }
    do {
        e = &gOrthoQuads[i];
        if (e->mVelocityMode == 0 && e->mUpdateFunction == func_0210465c) {
            SetOrthoQuadVelocitiesFromCorners(e);
        }
        i++;
    } while (i < gOrthoQuadCount);
}

u32 ClearOrthoQuadCreamEffectPointer(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &gOrthoQuadCreamEffect;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
}

void CreateOrthoQuadCreamEffect(const char *a) {
    u32 v;

    func_020e6488((Unk020e6488 **) &v, FindCourseMapObjFile(a), 0, 0);
    func_020e6ab8((Unk020e6488 *) v);
    SetupOrthoQuadModel(&gOrthoQuadCreamEffect, (Unk020e6488 *) v);
}

void StartOrthoQuadsCreamEffect(u32 a, u32 b) {
    StartOrthoQuads(a, b, 1);
}

#pragma thumb on
void InitOrthoQuads(void) {
    Unk020e6488 *q;
    s32 i;

    gOrthoQuads = HeapAlloc(GetHeap(func_020364e8()), 0xd0);
    data_0217c638 = 0xffff;
    gOrthoQuadCount = 0;
    gOrthoQuadUseCreamEffect = FALSE;
    NNS_SndPlayerStopSeq(func_02108e6c(6), 1);
    q = func_020ed4d0(data_0216c7b4, NULL, data_0216c7c4);
    SetupOrthoQuadModel(&gOrthoQuadGesoSumi, q);
    gOrthoQuadFirstPolygonId = AllocPolygonId();
    for (i = 0; i < 3; i++) {
        AllocPolygonId();
    }
    reg_G3_MTX_MODE = 0;
    reg_G3_MTX_PUSH = 0;
    G3i_OrthoW_(0x60000, 0xfffa0000, 0xfff80000, 0x80000, 0, 0x1000, 0x1fb, 1, (Unk0214ad4c *) gOrthoQuadMatrix);
    reg_G3_MTX_POP = 1;
}

void SetupOrthoQuadModel(OrthoQuadModel *p, Unk020e6488 *q) {
    u32 t;

    p->mModel = q;
    p->mPolygonAttr = 0x51f80c0;
    p->mPolygonAttr = p->mPolygonAttr & 0xc0ffffff;
    p->mTeximageParam = *q->mUnk_1c;
    p->mPlttBase = *q->mUnk_20;
    p->mDifAmb = q->mUnk_0c;
    p->mSpeEmi = q->mUnk_10;
    t = p->mTeximageParam;
    p->mUnk_18 = 1 << (((t & 0x3800000) >> 0x17) + 0xf);
    p->mUnk_1c = 1 << (((t & 0x700000) >> 0x14) + 0xf);
}
#pragma thumb off

void func_021031f4(ItemGesso *p) {
    s32 b3;
    s32 a;
    s32 b2;
    s32 i;
    RaceProgress *q;
    Unk020f41c4_B *b;
    Kart *r;
    u16 j;
    u32 n;
    u16 v;

    b2 = (u16) ((p->mUnk_000.mUnk_78 & 0x8000) == 0 ? (u16) (p->mUnk_000.mUnk_78 & ~0xff00) : 8);
    a = data_021759c0->mEntryIndex;
    if (data_021759c0->mMode == MODE_BATTLE) {
        b3 = data_021759c0->mKartCount;
        for (i = 0; i < b3; i++) {
            if (i == b2) {
                continue;
            }
            r = GetKart(i);
            if (r->mUnk_7c & 0x402020) {
                continue;
            }
            if (r->mUnk_4c & 0x10000840) {
                continue;
            }
            if (r->mUnk_48 & 0x10000) {
                continue;
            }
            q = gRaceProgress;
            b = &q->mLocalRandom;
            b->mUnk_00 = b->mUnk_08 * b->mUnk_00 + b->mUnk_10;
            p->mUnk_130[i] = (u16) (((b->mUnk_00 >> 32) * 4) >> 32) + 1;
        }
    } else {
        j = 1;
        n = GetKartRank(b2);
        do {
            v = gRaceProgress->mKartAtRank[(u8) j - 1];
            r = GetKart(v);
            if ((r->mUnk_7c & 0x402020) == 0 && (r->mUnk_4c & 0x10000840) == 0 && (r->mUnk_48 & 0x10000) == 0) {
                p->mUnk_130[v] = 4 - ((j - 1) >> 1);
            }
            j++;
        } while (j < n);
    }
    if (a < 0 || p->mUnk_130[a] == 0) {
        p->mUnk_198 = FALSE;
        return;
    }
    p->mUnk_198 = TRUE;
    p->mKart = GetKart(a);
    func_020f8e3c((u32) p->mKart, 0xf3);
}
