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
#include "g3imm.h"
#include "Main/Unknown/code_021053e4.h"
#include "Main/Unknown/code_0203c8dc.h"
#include "Main/Unknown/code_02077bc0.h"
#include "registers.h"

#pragma thumb on

void InitBouncingItemBoxMapObjects(void) {
    int objectCount;
    int index;
    ItemObject *box;
    ItemObject **objectCursor;
    ItemPool *pool;
    MapObject *mapObject;
    if (gItemInfos[17].mEnabled != FALSE) {
        pool = &gItemPools[8];
        objectCursor = pool->mObjects;
        objectCount = pool->mObjectCount;
        index = 0;
        if (0 < objectCount) {
            do {
                box = *objectCursor;
                mapObject = AllocPooledMapObject();
                *(MapObject **) ((s32) box + 0x134) = mapObject;
                *(s32 *) (*(s32 *) ((s32) box + 0x134) + 0xfc) = (s32) box + 0x13c;
                objectCursor = objectCursor + 1;
                index = index + 1;
            } while (index < objectCount);
        }
        pool->mUnk_40 = 1;
    }
}

#pragma thumb off

#pragma thumb on

void InitBouncingItemBoxTimers(void) {
    s32 i;
    u32 *timerCursor;
    u32 *runningFlagCursor;

    if (gRaceSetup->mMode != MODE_BATTLE) {
        return;
    }
    i = 0;
    timerCursor = gBouncingItemBoxTimers;
    runningFlagCursor = gBouncingItemBoxTimerRunning;
    do {
        *timerCursor++ = -1;
        *runningFlagCursor++ = 0;
        i++;
    } while (i < 8);
}

#pragma thumb off

void AdvanceOrthoQuadCornersByVelocity(OrthoQuad *quad) {
    s16(*velocities)[2];
    s32 framesFromMoveStart;
    s32 i;
    s32 k;
    NNSSndSeqPlayer **sndHandle;
    s16 x;
    s16 y;
    s32 b;

    velocities = quad->mCornerVelocities;
    framesFromMoveStart = gOrthoQuadFrames - gOrthoQuadMoveStartFrameCount;
    if (framesFromMoveStart < 0) {
        for (i = 0; i < 4; i++) {
            quad->mCorners[i][1] -= 2;
        }
        return;
    }
    if (framesFromMoveStart == 0 && gOrthoQuadUseCreamEffect == 0 && quad == gOrthoQuads) {
        sndHandle = GetSndHandleSlot(6);
        NNS_SndPlayerStopSeq(sndHandle, 1);
        if ((data_0217c780 & 1) != 0 && data_0217d084.mUnk_0c != 0) {
            if (*sndHandle != NULL) {
                NNS_SndPlayerStopSeq(sndHandle, 0);
            }
            if (*sndHandle != NULL) {
                NNS_SndPlayerStopSeq(sndHandle, 0);
            }
            NNS_SndArcPlayerStartSeqArc(sndHandle, 0, 0xef);
        }
    }
    if (quad->mVelocityMode != 0) {
        for (i = 0; i < 4; i++) {
            quad->mCorners[i][0] += velocities[i][0];
            quad->mCorners[i][1] += velocities[i][1];
            velocities[i][0] = ((s64) velocities[i][0] * 0x10cd) >> 12;
            velocities[i][1] = ((s64) velocities[i][1] * 0x10cd) >> 12;
            x = quad->mCorners[i][0];
            if (x > 0x3ccd) {
                quad->mCorners[i][0] = 0x3ccd;
            } else if (x < -0x3ccd) {
                quad->mCorners[i][0] = -0x3ccd;
            }
            y = quad->mCorners[i][1];
            if (y > 0x3ccd) {
                quad->mCorners[i][1] = 0x3ccd;
            } else if (y < -0x3ccd) {
                quad->mCorners[i][1] = -0x3ccd;
            }
        }
    } else {
        i = 0;
        if (i < 4) {
            do {
                x = velocities[i][0];
                y = velocities[i][1];
                if (y < 0) {
                    k = y * y > x * x ? 7 : 5;
                    if (i == quad->mPickedCornerIndex) {
                        k += (k << 1) + ((k * framesFromMoveStart) >> 9);
                    }
                } else {
                    k = y * y > x * x ? 2 : 3;
                }
                b = k;
                b += (k * framesFromMoveStart) >> 8;
                quad->mCorners[i][1] = quad->mCorners[i][1] - b;
                if (quad->mCorners[i][1] < -0x3ccd) {
                    quad->mCorners[i][1] = -0x3ccd;
                }
                i++;
            } while (i < 4);
        }
    }
    quad->mTimer = quad->mTimer - 1;
    if ((quad->mTimer & 0xf) == 0) {
        Unk020f41c4_B *a = &gRaceProgress->mLocalRandom;

        a->mValue = a->mMultiplier * a->mValue + a->mIncrement;
        quad->mPickedCornerIndex = (u16) (((u64) (u32) (a->mValue >> 32) * 6) >> 32);
    }
}

void AdvanceOrthoQuadCornersByTable(OrthoQuad *quad) {
    s16(*velocities)[2] = quad->mCornerVelocities;
    s32 i;
    s32 tableScale;
    s16 startX;
    s16 startY;
    s32 v;

    tableScale = data_0215a48c[-quad->mTimer];
    startX = quad->mStartPair[0];
    startY = quad->mStartPair[1];
    for (i = 0; i < 4; i++) {
        v = velocities[i][0];
        quad->mCorners[i][0] = startX + (s32) (((s64) v * tableScale) >> 12);
        v = velocities[i][1];
        quad->mCorners[i][1] = startY + (s32) (((s64) v * tableScale) >> 12);
    }
    quad->mTimer = quad->mTimer - 1;
    if (quad->mTimer == -13) {
        quad->mUpdateFunction = AdvanceOrthoQuadCornersByVelocity;
    }
}

void AdvanceOrthoQuadDelayAndStartSound(OrthoQuad *quad) {
    NNSSndSeqPlayer **sndHandle;
    u32 seqNo;

    quad->mTimer = quad->mTimer - 1;
    if (quad->mTimer != 0) {
        return;
    }
    quad->mUpdateFunction = AdvanceOrthoQuadCornersByTable;
    if (func_0203c5e4() != 0) {
        return;
    }
    seqNo = gOrthoQuadUseCreamEffect != 0 ? 0x157 : 0xee;
    if (seqNo == 1) {
        return;
    }
    if ((data_0217c780 & 1) == 0) {
        return;
    }
    sndHandle = func_0210e128(func_02108ea0(0));
    if (data_0217d084.mUnk_0c == 0) {
        return;
    }
    if (*sndHandle != NULL) {
        NNS_SndPlayerStopSeq(sndHandle, 0);
    }
    if (*sndHandle != NULL) {
        NNS_SndPlayerStopSeq(sndHandle, 0);
    }
    NNS_SndArcPlayerStartSeqArc(sndHandle, 0, (u16) seqNo);
}

void UpdateOrthoQuads(void) {
    s32 i;
    OrthoQuadModel *model;
    s32 frames;
    u16 alpha;

    if (gOrthoQuadCount == 0) {
        return;
    }
    for (i = 0; i < gOrthoQuadCount; i++) {
        OrthoQuad *e = &gOrthoQuads[i];

        e->mUpdateFunction(e);
    }
    frames = gOrthoQuadFrames + 1;
    gOrthoQuadFrames = frames;
    if (frames <= gOrthoQuadHoldFrameCount) {
        return;
    }
    if (frames & 1) {
        return;
    }
    alpha = gOrthoQuadAlpha;
    gOrthoQuadAlpha = alpha - 1;
    alpha = gOrthoQuadAlpha;
    if (alpha == 0) {
        gOrthoQuadCount = 0;
        gOrthoQuadUseCreamEffect = FALSE;
        NNS_SndPlayerStopSeq(GetSndHandleSlot(6), 1);
        return;
    }
    model = gOrthoQuadUseCreamEffect != 0 ? &gOrthoQuadCreamEffect : &gOrthoQuadGesoSumi;
    model->mPolygonAttr = model->mPolygonAttr & ~0x1f0000;
    model->mPolygonAttr = model->mPolygonAttr | (alpha << 16);
}

void DrawOrthoQuadsWithModel(OrthoQuadModel *model) {
    s32 i;

    if (gOrthoQuadCount == 0) {
        return;
    }
    if (func_0203c5e4() != 0) {
        return;
    }
    reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~0x3000) | 8;
    reg_G3_TEXIMAGE_PARAM = model->mTeximageParam;
    reg_G3_PLTT_BASE = model->mPlttBase;
    reg_G3_DIF_AMB = model->mDifAmb;
    reg_G3_SPE_EMI = model->mSpeEmi;
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

        reg_G3_POLYGON_ATTR = model->mPolygonAttr | (gOrthoQuadFirstPolygonId + i) << 24;
        reg_G3_BEGIN_VTXS = 1;
        reg_G3_TEXCOORD = 0;
        reg_G3_VTX_16 = *(u32 *) &e->mCorners[0];
        reg_G3_VTX_16 = 0;
        reg_G3_TEXCOORD = (u16) ((s32) (model->mUnk_1c << 8) >> 16) << 16;
        *(u32 *) 0x4000494 = *(u32 *) &e->mCorners[1];
        reg_G3_TEXCOORD = (u16) ((s32) (model->mUnk_18 << 8) >> 16) | ((u16) ((s32) (model->mUnk_1c << 8) >> 16) << 16);
        *(u32 *) 0x4000494 = *(u32 *) &e->mCorners[2];
        reg_G3_TEXCOORD = (u16) ((s32) (model->mUnk_18 << 8) >> 16);
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
    u8 overlapAbove;
    s32 fiveCellMask;
    s32 threeCellMask;
    u8 overlap;

    threeCellMask = (1 << (column + 1)) | (1 << (column + 2)) | (1 << (column + 3));
    fiveCellMask = threeCellMask | (1 << column) | (1 << (column + 4));
    overlapAbove = 0;
    if (row > 1) {
        overlapAbove |= gOrthoQuadCells[row - 2] & (u8) (threeCellMask >> 3);
        gOrthoQuadCells[row - 2] |= (u8) (threeCellMask >> 3);
    }
    if (row > 0) {
        overlapAbove |= gOrthoQuadCells[row - 1] & (u8) (fiveCellMask >> 3);
        gOrthoQuadCells[row - 1] |= (u8) (fiveCellMask >> 3);
    }
    overlap = overlapAbove | (gOrthoQuadCells[row] & (u8) (fiveCellMask >> 3));
    gOrthoQuadCells[row] |= (u8) (fiveCellMask >> 3);
    if (row < 7) {
        overlap |= gOrthoQuadCells[row + 1] & (u8) (fiveCellMask >> 3);
        gOrthoQuadCells[row + 1] |= (u8) (fiveCellMask >> 3);
    }
    if (row < 6) {
        overlap |= gOrthoQuadCells[row + 2] & (u8) (threeCellMask >> 3);
        gOrthoQuadCells[row + 2] |= (u8) (threeCellMask >> 3);
    }
    return overlap;
}

void SetupOrthoQuad(s32 index, Unk021035ac_Pair startPair, s32 overlap) {
    RaceProgress *raceProgress;
    Unk020f41c4_B *random;
    OrthoQuad *quad;
    s16(*velocities)[2];
    s32 i;
    s16 c;
    s16 s;
    s32 t;
    s16 velocityX;
    s16 velocityY;

    raceProgress = gRaceProgress;
    quad = &gOrthoQuads[index];
    random = &raceProgress->mLocalRandom;
    velocities = quad->mCornerVelocities;
    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
    t = (s32) (u16) (((u64) (u32) (random->mValue >> 32) * 0x10000) >> 32) >> 4;
    c = gPairsByAngle[2 * t];
    s = gPairsByAngle[2 * t + 1];
    if (overlap != 0) {
        random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
        t = (s16) (((u64) (u32) (random->mValue >> 32) * 0xcd) >> 32) + 0x800;
    } else {
        random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
        t = 0xa66 + (s16) (((u64) (u32) (random->mValue >> 32) * 0x52) >> 32);
    }
    t = (s16) t;
    if (gOrthoQuadUseCreamEffect != 0) {
        t = (s16) (((s64) t * 0x800) >> 12);
    }
    quad->mTimer = data_0215a47c[index];
    velocities[0][0] = -t;
    velocities[0][1] = -t;
    velocities[1][0] = -t;
    velocities[1][1] = t;
    velocities[2][0] = t;
    velocities[2][1] = t;
    velocities[3][0] = t;
    velocities[3][1] = -t;
    for (i = 0; i < 4; i++) {
        velocityY = velocities[i][1];
        velocityX = velocities[i][0];
        velocities[i][0] = (s * velocityX - c * velocityY) >> 12;
        velocities[i][1] = (c * velocityX + s * velocityY) >> 12;
        *(Unk021035ac_Pair *) quad->mCorners[(u32) i] = startPair;
    }
    *(Unk021035ac_Pair *) quad->mStartPair = startPair;
    quad->mUpdateFunction = AdvanceOrthoQuadDelayAndStartSound;
    quad->mPickedCornerIndex = -1;
    quad->mVelocityMode = 0;
}

// Local entry only: places up to count quads at random cells; the cream effect does not restart while quads show.
void StartOrthoQuads(s32 kartIndex, s32 count, s32 useCreamEffect) {
    Unk021035ac_Pair startPair;
    s32 i;
    s32 placedCount;
    s32 m;
    s32 column;
    s32 row;
    Unk020f41c4_B *random;

    random = &gRaceProgress->mLocalRandom;
    GetKart(kartIndex);
    if (kartIndex != gRaceSetup->mEntryIndex) {
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
    NNS_SndPlayerStopSeq(GetSndHandleSlot(6), 1);
    gOrthoQuadUseCreamEffect = useCreamEffect;
    for (i = 0; i < 8; i++) {
        gOrthoQuadCells[i] = 0;
    }
    m = 1;
    for (i = 0, placedCount = 0; i < 0x10 && placedCount < count; i++) {
        if (gOrthoQuadUseCreamEffect != 0) {
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            startPair.mHalf.mUnk_00 = (s16) (((u64) (u32) (random->mValue >> 32) * 0x1000) >> 32) * 2;
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            startPair.mHalf.mUnk_02 = (s16) (((u64) (u32) (random->mValue >> 32) * 0xc00) >> 32) * 2;
        } else if (gOrthoQuadCount == 0) {
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            startPair.mHalf.mUnk_00 = ((u64) (u32) (random->mValue >> 32) * 0x1000) >> 32;
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            startPair.mHalf.mUnk_00 =
                startPair.mHalf.mUnk_00 + (s16) (((u64) (u32) (random->mValue >> 32) * 0x1000) >> 32);
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            startPair.mHalf.mUnk_02 = ((u64) (u32) (random->mValue >> 32) * 0xc00) >> 32;
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            startPair.mHalf.mUnk_02 =
                startPair.mHalf.mUnk_02 + (s16) (((u64) (u32) (random->mValue >> 32) * 0xc00) >> 32);
        } else {
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            startPair.mHalf.mUnk_00 = ((u64) (u32) (random->mValue >> 32) * 0x2000) >> 32;
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            startPair.mHalf.mUnk_02 = ((u64) (u32) (random->mValue >> 32) * 0x1800) >> 32;
        }
        column = startPair.mHalf.mUnk_00 >> 10;
        row = startPair.mHalf.mUnk_02 >> 10;
        if (row >= 3 || column < 3 || column > 4) {
            if ((gOrthoQuadCells[row] & (m << column)) == 0) {
                s32 r = MarkOrthoQuadCellsAndGetOverlap(column, row);

                startPair.mHalf.mUnk_00 -= 0x1000;
                startPair.mHalf.mUnk_02 -= 0x600;
                SetupOrthoQuad(placedCount, startPair, r);
                placedCount++;
            }
        }
    }
    gOrthoQuadCount = placedCount;
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

void StartOrthoQuadsGesoSumi(u32 kartIndex, u32 count) {
    StartOrthoQuads(kartIndex, count, 0);
}

void StopOrthoQuads(int kartIndex) {
    if (kartIndex != gRaceSetup->mEntryIndex) {
        return;
    }
    gOrthoQuadCount = 0;
    gOrthoQuadUseCreamEffect = FALSE;
    NNS_SndPlayerStopSeq(GetSndHandleSlot(6), 1);
}

// Local entry only: moves the frame counter up to the hold count so the alpha starts to fall.
u32 SkipOrthoQuadsHold(u32 kartIndex) {
    u32 value0 = kartIndex;
    u32 value1;
    u32 value2;
    u32 compareLeft0;
    u32 compareRight0;
    u32 compareLeft1;
    u32 compareRight1;
    s32 compareLeft2;
    s32 compareRight2;
    value1 = gRaceSetup->mEntryIndex;
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
void SetOrthoQuadVelocitiesFromCorners(OrthoQuad *quad) {
    s32 i;
    s32 cornerX;
    s32 cornerY;
    s32 pushY;
    s32 pushX;
    s32 j;
    s16(*velocities)[2] = quad->mCornerVelocities;

    for (i = 0; i < 4; i++) {
        velocities[i][0] = 0;
        velocities[i][1] = 0;
    }
    for (i = 0; i < 4; i++) {
        cornerX = quad->mCorners[i][0];
        cornerY = quad->mCorners[i][1];
        if (cornerX > 0) {
            if (cornerX > 0x4cd) {
                pushX = ((s64) cornerX * cornerX) >> 12;
            } else {
                pushX = 0x171;
            }
        } else {
            if (cornerX < 0x4cd) {
                pushX = -(s32) (((s64) cornerX * cornerX) >> 12);
            } else {
                pushX = -0x171;
            }
        }
        if (cornerY > 0) {
            if (cornerY > 0x4cd) {
                pushY = ((s64) cornerY * cornerY) >> 12;
            } else {
                pushY = 0x171;
            }
        } else {
            if (cornerY < 0x4cd) {
                pushY = -(s32) (((s64) cornerY * cornerY) >> 12);
            } else {
                pushY = -0x171;
            }
        }
        for (j = 0; j < 4; j++) {
            if (i == j) {
                velocities[j][0] += (s32) (((s64) pushX * 12) >> 12);
                velocities[j][1] += (s32) (((s64) pushY * 12) >> 12);
            } else {
                velocities[j][0] += (s32) (((s64) pushX * 8) >> 12);
                velocities[j][1] += (s32) (((s64) pushY * 8) >> 12);
            }
        }
    }
    for (i = 0; i < 4; i++) {
        if (velocities[i][1] < 0) {
            velocities[i][1] = 0;
        }
    }
    quad->mVelocityMode = 1;
}

void SkipOrthoQuadsHoldAndSetVelocities(int kartIndex) {
    OrthoQuad *quad;
    s32 i;
    s32 quadCount;
    s32 holdFrameCount;
    s32 frames;

    if (kartIndex != gRaceSetup->mEntryIndex) {
        return;
    }
    quadCount = gOrthoQuadCount;
    if (quadCount == 0) {
        return;
    }
    holdFrameCount = gOrthoQuadHoldFrameCount;
    frames = gOrthoQuadFrames;
    if (frames < holdFrameCount) {
        gOrthoQuadFrames = holdFrameCount;
    }
    i = 0;
    if (quadCount <= 0) {
        return;
    }
    do {
        quad = &gOrthoQuads[i];
        if (quad->mVelocityMode == 0 && quad->mUpdateFunction == AdvanceOrthoQuadCornersByVelocity) {
            SetOrthoQuadVelocitiesFromCorners(quad);
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

void CreateOrthoQuadCreamEffect(const char *fileName) {
    u32 model;

    func_020e6488((Unk020e6488 **) &model, FindCourseMapObjFile(fileName), 0, 0);
    func_020e6ab8((Unk020e6488 *) model);
    SetupOrthoQuadModel(&gOrthoQuadCreamEffect, (Unk020e6488 *) model);
}

void StartOrthoQuadsCreamEffect(u32 kartIndex, u32 count) {
    StartOrthoQuads(kartIndex, count, 1);
}

#pragma thumb on
void InitOrthoQuads(void) {
    Unk020e6488 *model;
    s32 i;

    gOrthoQuads = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0xd0);
    data_0217c638 = 0xffff;
    gOrthoQuadCount = 0;
    gOrthoQuadUseCreamEffect = FALSE;
    NNS_SndPlayerStopSeq(GetSndHandleSlot(6), 1);
    model = CreateItemModel(data_0216c7b4, NULL, data_0216c7c4);
    SetupOrthoQuadModel(&gOrthoQuadGesoSumi, model);
    gOrthoQuadFirstPolygonId = AllocPolygonId();
    for (i = 0; i < 3; i++) {
        AllocPolygonId();
    }
    reg_G3_MTX_MODE = 0;
    reg_G3_MTX_PUSH = 0;
    G3i_OrthoW_(0x60000, 0xfffa0000, 0xfff80000, 0x80000, 0, 0x1000, 0x1fb, 1, (Unk0214ad4c *) gOrthoQuadMatrix);
    reg_G3_MTX_POP = 1;
}

void SetupOrthoQuadModel(OrthoQuadModel *quadModel, Unk020e6488 *model) {
    u32 teximageParam;

    quadModel->mModel = model;
    quadModel->mPolygonAttr = 0x51f80c0;
    quadModel->mPolygonAttr = quadModel->mPolygonAttr & 0xc0ffffff;
    quadModel->mTeximageParam = *model->mUnk_1c;
    quadModel->mPlttBase = *model->mUnk_20;
    quadModel->mDifAmb = model->mUnk_0c;
    quadModel->mSpeEmi = model->mUnk_10;
    teximageParam = quadModel->mTeximageParam;
    quadModel->mUnk_18 = 1 << (((teximageParam & 0x3800000) >> 0x17) + 0xf);
    quadModel->mUnk_1c = 1 << (((teximageParam & 0x700000) >> 0x14) + 0xf);
}
#pragma thumb off

void func_021031f4(ItemGesso *gesso) {
    s32 kartCount;
    s32 entryIndex;
    s32 ownerIndex;
    s32 i;
    RaceProgress *raceProgress;
    Unk020f41c4_B *random;
    Kart *kart;
    u16 rank;
    u32 ownerRank;
    u16 kartIndex;

    ownerIndex = (u16) ((gesso->mUnk_000.mUnk_78 & 0x8000) == 0 ? (u16) (gesso->mUnk_000.mUnk_78 & ~0xff00) : 8);
    entryIndex = gRaceSetup->mEntryIndex;
    if (gRaceSetup->mMode == MODE_BATTLE) {
        kartCount = gRaceSetup->mKartCount;
        for (i = 0; i < kartCount; i++) {
            if (i == ownerIndex) {
                continue;
            }
            kart = GetKart(i);
            if (kart->mUnk_7c & 0x402020) {
                continue;
            }
            if (kart->mUnk_4c & 0x10000840) {
                continue;
            }
            if (kart->mUnk_48 & 0x10000) {
                continue;
            }
            raceProgress = gRaceProgress;
            random = &raceProgress->mLocalRandom;
            random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
            gesso->mUnk_130[i] = (u16) (((random->mValue >> 32) * 4) >> 32) + 1;
        }
    } else {
        rank = 1;
        ownerRank = GetKartRank(ownerIndex);
        do {
            kartIndex = gRaceProgress->mKartAtRank[(u8) rank - 1];
            kart = GetKart(kartIndex);
            if ((kart->mUnk_7c & 0x402020) == 0 && (kart->mUnk_4c & 0x10000840) == 0 &&
                (kart->mUnk_48 & 0x10000) == 0) {
                gesso->mUnk_130[kartIndex] = 4 - ((rank - 1) >> 1);
            }
            rank++;
        } while (rank < ownerRank);
    }
    if (entryIndex < 0 || gesso->mUnk_130[entryIndex] == 0) {
        gesso->mVisible = FALSE;
        return;
    }
    gesso->mVisible = TRUE;
    gesso->mKart = GetKart(entryIndex);
    func_020f8e3c((u32) gesso->mKart, 0xf3);
}
