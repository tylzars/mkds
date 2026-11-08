#include "Main/Unknown/code_020be950.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020ae730.h"

#include "Main/Unknown/code_020b1cf4.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020c7464.h"
#include "Main/Unknown/code_020c8000.h"
#include "Main/Unknown/code_020c9000.h"
#include "code_02147cd8.h"
#include "Main/Unknown/code_020ca534.h"
#include "Main/Unknown/code_020ca670.h"
#include "Main/Unknown/code_020cccd8.h"
#include "Main/Unknown/code_020ce6a8.h"
#include "Main/Unknown/code_020cee0c.h"
#include "Main/Unknown/code_020cf310.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020cffd0.h"
#include "Main/Unknown/code_020d0e3c.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/code_020beb9c.h"
#include "Main/Unknown/code_020c7000.h"
#include "Main/Unknown/code_020ca000.h"
#include "Main/Unknown/code_020cc000.h"
#include "Main/Unknown/code_020cd000.h"
#include "Main/Unknown/code_020ce000.h"
#include "Main/Unknown/code_020cf000.h"
#include "Main/Unknown/code_020d0000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/unk_02169000.h"
#include "01/code_021892ac.h"
#include "01/code_02188e88.h"
#include "Main/Unknown/code_020c06c4.h"
#include "code_020222ec.h"
#include "Main/Unknown/code_020c0b84.h"
#include "Main/Unknown/code_020c0ba8.h"
#include "Main/Unknown/code_02100084.h"
#include "Main/Unknown/code_02100094.h"
#include "Main/Unknown/code_021000c8.h"
#include "Main/Unknown/code_021000d0.h"
#include "Main/Unknown/code_020c0d9c.h"
#include "01/code_021813f4.h"
#include "Main/Unknown/code_02077bc0.h"

u32 func_020c0dc4(void) {
    return (gRaceHudSubScreenCellGroups->mUnk_000);
}

u32 GetRaceHudSubScreenScale(void) {
    return (gRaceHudSubScreenCellGroups->mScale);
}

u32 func_020c0d9c(void) {
    return (gRaceHudSubScreenCellGroups->mUnk_008);
}

BOOL CreateRaceHudSubScreenCells(RaceHudSubScreenCells **outCells, s32 kind) {
    BOOL fromUpdateList;
    void *drawList;
    void *updateList;
    s32 i;
    s32 objectCount;

    fromUpdateList = FALSE;
    drawList = FindMapObjectKindDrawList0(kind);
    updateList = FindMapObjectKindUpdateList(kind);
    if (kind == MAP_OBJECT_KIND_SUN_FIREBALL || kind == 0x1ab) {
        fromUpdateList = TRUE;
    }
    if (fromUpdateList != FALSE) {
        if (updateList == NULL) {
            return FALSE;
        }
        objectCount = GetMapObjectListCount(updateList);
        if (objectCount == 0) {
            return FALSE;
        }
    } else {
        if (drawList == NULL) {
            return FALSE;
        }
        objectCount = func_02100094(drawList);
        if (objectCount == 0) {
            return FALSE;
        }
    }
    *outCells = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x14);
    if (fromUpdateList != FALSE) {
        (*outCells)->mObjects = (Unk0217b498_00 **) GetMapObjects(updateList);
    } else {
        (*outCells)->mObjects = RaceHudSubScreenGetMapObjects(drawList);
    }
    (*outCells)->mCellCount = 0;
    (*outCells)->mObjectCount = objectCount;
    (*outCells)->mUnk_0c = HeapAlloc(GetHeap(GetCurrentHeapCall()), objectCount * 8);
    for (i = 0; i < objectCount; i++) {
        ComputeRaceHudSubScreenCoursePosition(&(*outCells)->mObjects[i]->mPos, &(*outCells)->mUnk_0c[i]);
    }
    (*outCells)->mCells = AllocArrayFromCurrentHeap(objectCount * 2, 0x14);
    return TRUE;
}

BOOL CreateRaceHudSubScreenCellsWithCount(RaceHudSubScreenCells **outCells, s32 objectCount) {
    if (objectCount == 0) {
        return FALSE;
    }
    *outCells = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x14);
    (*outCells)->mCellCount = 0;
    (*outCells)->mObjectCount = objectCount;
    (*outCells)->mUnk_0c = HeapAlloc(GetHeap(GetCurrentHeapCall()), objectCount * 8);
    (*outCells)->mCells = AllocArrayFromCurrentHeap(objectCount, 0x14);
    return TRUE;
}

void ClearRaceHudSubScreenCells(RaceHudSubScreenCells **cellsPointerAddress) {
    (*cellsPointerAddress)->mObjects = NULL;
    (*cellsPointerAddress)->mUnk_0c = NULL;
    (*cellsPointerAddress)->mCells = NULL;
    *cellsPointerAddress = NULL;
}

void DrawRaceHudSubScreenCells(RaceHudOamBuffer *oamBuffer, RaceHudSubScreenCells *cells, s32 useRotation) {
    s32 i;
    s32 l;
    u16 angle;
    u16 matrixIndex;
    s32 rotationMatrix[4];
    s32 drawPosition[2];
    s32 p;
    s32 q;
    s32 oamIndex;
    RaceHudOamBits *oam;
    RaceHudSubScreenCell *cell;
    s32 screenX;
    s32 screenY;
    void *cellData;

    l = gRaceHudSubScreenCellGroups->mUnk_000;
    if (useRotation != 0) {
        angle = GetSubScreenAngleAndClearScrollTimer();
    }
    for (i = 0; i < cells->mCellCount; i++) {
        p = cells->mCells[i].mUnk_0c;
        if (l <= p) {
            q = cells->mCells[i].mUnk_0e;
            matrixIndex = 0;
            if (useRotation != 0) {
                if (gRaceSetup->mMirrorMode != 0) {
                    Matrix2x2Rotation(rotationMatrix, (u16) (cells->mCells[i].mUnk_10 + 0x8000 - angle));
                } else {
                    Matrix2x2Rotation(rotationMatrix, (u16) (angle + (0x8000 - cells->mCells[i].mUnk_10)));
                }
                matrixIndex = AllocOamMatrixIndex(oamBuffer);
                oamBuffer->mMatrices[matrixIndex].mUnk_06 = rotationMatrix[0] >> 4;
                oamBuffer->mMatrices[matrixIndex].mUnk_0e = rotationMatrix[1] >> 4;
                oamBuffer->mMatrices[matrixIndex].mUnk_16 = rotationMatrix[2] >> 4;
                oamBuffer->mMatrices[matrixIndex].mUnk_1e = rotationMatrix[3] >> 4;
            }
            cell = &cells->mCells[i];
            screenX = cell->mDrawPos.mUnk_00;
            cellData = cell->mCell;
            screenY = cell->mDrawPos.mUnk_04;
            oamIndex = oamBuffer->mOamCount;
            drawPosition[0] = screenX << 12;
            drawPosition[1] = screenY << 12;
            oamBuffer->mOamCount +=
                NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cellData,
                                      useRotation != 0 ? rotationMatrix : 0, drawPosition, matrixIndex, 1);
            oam = &oamBuffer->mOamBits[oamIndex];
            for (; oamIndex < oamBuffer->mOamCount; oamIndex++, oam++) {
                if ((q != 0 ? 1 : -1) != -1) {
                    oam->mUnk_0a = q != 0 ? 1 : -1;
                }
                if (p != -1) {
                    oam->mUnk_0e = p;
                }
            }
        }
    }
}

void DrawRaceHudSubScreenCellsScaled(RaceHudOamBuffer *oamBuffer, RaceHudSubScreenCells *cells, s32 useRotation) {
    s32 i;
    s32 l;
    u16 angle;
    s32 matrix[4];
    s32 drawPosition[2];
    s32 p;
    s32 q;
    s32 oamIndex;
    u16 matrixIndex;
    RaceHudOamBits *oam;
    RaceHudSubScreenCell *cell;
    s32 screenX;
    s32 screenY;
    void *cellData;

    l = gRaceHudSubScreenCellGroups->mUnk_000;
    if (useRotation != 0) {
        angle = GetSubScreenAngleAndClearScrollTimer();
    }
    for (i = 0; i < cells->mCellCount; i++) {
        p = cells->mCells[i].mUnk_0c;
        if (l <= p) {
            q = cells->mCells[i].mUnk_0e;
            if (useRotation != 0) {
                if (gRaceSetup->mMirrorMode != 0) {
                    Matrix2x2RotationReciprocalScale(matrix, cells->mUnk_0c[i].mUnk_00,
                                                     (u16) (cells->mCells[i].mUnk_10 - angle));
                } else {
                    Matrix2x2RotationReciprocalScale(matrix, cells->mUnk_0c[i].mUnk_00,
                                                     (u16) (angle - cells->mCells[i].mUnk_10));
                }
            } else {
                Matrix2x2ReciprocalScale(matrix, cells->mUnk_0c[i].mUnk_00);
            }
            matrixIndex = AllocOamMatrixIndex(oamBuffer);
            oamBuffer->mMatrices[matrixIndex].mUnk_06 = matrix[0] >> 4;
            oamBuffer->mMatrices[matrixIndex].mUnk_0e = matrix[1] >> 4;
            oamBuffer->mMatrices[matrixIndex].mUnk_16 = matrix[2] >> 4;
            oamBuffer->mMatrices[matrixIndex].mUnk_1e = matrix[3] >> 4;
            cell = &cells->mCells[i];
            screenX = cell->mDrawPos.mUnk_00;
            cellData = cell->mCell;
            screenY = cell->mDrawPos.mUnk_04;
            oamIndex = oamBuffer->mOamCount;
            drawPosition[0] = screenX << 12;
            drawPosition[1] = screenY << 12;
            oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamIndex], 0x80 - oamIndex, cellData,
                                                          matrix, drawPosition, matrixIndex, 1);
            oam = &oamBuffer->mOamBits[oamIndex];
            for (; oamIndex < oamBuffer->mOamCount; oamIndex++, oam++) {
                if ((q != 0 ? 1 : -1) != -1) {
                    oam->mUnk_0a = q != 0 ? 1 : -1;
                }
                if (p != -1) {
                    oam->mUnk_0e = p;
                }
            }
        }
    }
}

void InitRaceHudSubScreenCellGroups(void) {
    gRaceHudSubScreenCellGroups = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x25c);
    gRaceHudSubScreenCellGroups->mUnk_000 = 0;
    gRaceHudSubScreenCellGroups->mScale = 0;
    gRaceHudSubScreenCellGroups->mUnk_008 = 0;
    gRaceHudSubScreenCellGroups->mGroupCount = 0;
    if (CreateRaceHudSubScreenKarts()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenKarts && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenItemCells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenItemCells && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenBombKouraWCells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenBombKouraWCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenItemBoxCells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenItemBoxCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenEarthenPipeCells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenEarthenPipeCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenWanwanCells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenWanwanCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenDossunCells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenDossunCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenCrabCells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenCrabCells && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenSmanCells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenSmanCells && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenMoveTreeCells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenMoveTreeCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenPukupukuCells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenPukupukuCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenChoropuCells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenChoropuCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenCarCells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenCarCells && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenSecondHand()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenSecondHand && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenShine16Cells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenShine16Cells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenPendulumCells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenPendulumCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenNsKiller2Cells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenNsKiller2Cells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenFlipperCells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenFlipperCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenMkdEfBubbleCells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenMkdEfBubbleCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenKuriboCells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenKuriboCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenObPakkunSfCells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenObPakkunSfCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenRock2Cells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenRock2Cells && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenRockCells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenRockCells && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenWoodbox1Cells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenWoodbox1Cells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenRainStarCells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenRainStarCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenMkdEfBurnerCells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenMkdEfBurnerCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenCoverPooHoleCells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenCoverPooHoleCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenBoundCells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenBoundCells && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenSunFireballCells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenSunFireballCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenFireball2Cells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenFireball2Cells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenIronBallCells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenIronBallCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenSanboCells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenSanboCells && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenBasabasaCells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenBasabasaCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (func_020cee0c()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != func_020cee0c && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenBerryCells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenBerryCells && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenCreamCells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenCreamCells && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (gRaceSetup->mMode != MODE_MISSION_RUN) {
        return;
    }
    if (CreateRaceHudSubScreenCoinCells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenCoinCells && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenMissionGateCells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenMissionGateCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenStopSignCells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenStopSignCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenBossDonketuCells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenBossDonketuCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenKingIceDonketuCells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0;
             gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenKingIceDonketuCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenKurikingCells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenKurikingCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenBombKingCells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenBombKingCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenIwanteCells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenIwanteCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (CreateRaceHudSubScreenHanachanCells()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != CreateRaceHudSubScreenHanachanCells && i < 49;
             i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
    if (func_ov001_02189128()) {
        s32 groupIndex;
        s32 i;

        groupIndex = gRaceHudSubScreenCellGroups->mGroupCount++;
        for (i = 0; gRaceHudSubScreenCellGroupFunctions[i].mCreate != func_ov001_02189128 && i < 49; i++) {
        }
        if (i < 49) {
            gRaceHudSubScreenCellGroups->mClearFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mClear;
            gRaceHudSubScreenCellGroups->mUpdateFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mUpdate;
            gRaceHudSubScreenCellGroups->mDrawFunctions[groupIndex] = gRaceHudSubScreenCellGroupFunctions[i].mDraw;
        }
    }
}

void ClearRaceHudSubScreenCellGroups(void) {
    s32 i;

    for (i = 0; i < gRaceHudSubScreenCellGroups->mGroupCount; i++) {
        gRaceHudSubScreenCellGroups->mClearFunctions[i]();
    }
    gRaceHudSubScreenCellGroups = NULL;
}

void UpdateRaceHudSubScreenCellGroups(void) {
    Vec3 followedKartPosition;
    s32 i;
    s32 n;
    float f;

    switch (GetRaceHudSubScreenState()) {
        case 0:
            UpdateRaceHudSubScreenKarts();
            break;
        case 1:
        case 2:
        case 3:
            if (GetRaceHudSubScreenCourseScale() * 3 > 0) {
                f = 0.5f + (GetRaceHudSubScreenCourseScale() * 0x3000);
            } else {
                f = (GetRaceHudSubScreenCourseScale() * 0x3000) - 0.5f;
            }
            n = f;
            gRaceHudSubScreenCellGroups->mScale = ((s64) n * 20) >> 12;
            gRaceHudSubScreenCellGroups->mUnk_008 = FX_Div(0x2400, gRaceHudSubScreenCellGroups->mScale);
            UpdateRaceHudSubScreenProjectionAndBgAffine(GetRaceHudSubScreenBgAffine(),
                                                        gRaceHudSubScreenCellGroups->mScale);
            GetKartPosFromPosSourceCopy(&followedKartPosition, GetFollowedKartOrEntryIndex());
            gRaceHudSubScreenCellGroups->mUnk_000 = IsPositionOutsideBox(&followedKartPosition) != 0 ? 0 : 3;
            for (i = 0; i < gRaceHudSubScreenCellGroups->mGroupCount; i++) {
                gRaceHudSubScreenCellGroups->mUpdateFunctions[i]();
            }
            break;
    }
}

void DrawRaceHudSubScreenCellGroups(void *oamBuffer) {
    s32 i;

    switch (GetRaceHudSubScreenState()) {
        case 0:
            DrawRaceHudSubScreenKarts(oamBuffer);
            break;
        case 1:
        case 2:
        case 3:
            for (i = 0; i < gRaceHudSubScreenCellGroups->mGroupCount; i++) {
                gRaceHudSubScreenCellGroups->mDrawFunctions[i](oamBuffer);
            }
            break;
    }
}
