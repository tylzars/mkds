#include "Main/Unknown/code_020d18d4.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020b33d8.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b85dc.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "code_020222ec.h"
#include "Main/Unknown/code_020b3000.h"
#include "Main/Unknown/code_020b4000.h"

void DrawRaceMNumberPair(RaceHudOamBuffer *oamBuffer) {
    s32 startFrames;

    startFrames = GetRaceStartSequenceFrames();
    if (gRaceSetup->mRaceKind == 4 || gRaceSetup->mRaceKind == RACE_KIND_DEMO) {
        return;
    }
    if (startFrames >= 0xb4) {
        return;
    }
    if (gRaceSetup->mMode != 5 && (gRaceSetup->mMode != MODE_VS || gRaceSetup->mRuleKind != 2)) {
        return;
    }
    func_020d1de8(oamBuffer, startFrames);
    if (gRaceMNumberPair->mScale == 0) {
        return;
    }
    if (gRaceMNumberPair->mCourseCount >= 10) {
        DrawRaceMNumberPairTwoDigit(oamBuffer);
        return;
    }
    DrawRaceMNumberPairOneDigit(oamBuffer);
}

void func_020d1de8(RaceHudOamBuffer *oamBuffer, s32 startFrames) {
    s32 scaleTable[20] = {0,    205,  410,  614,  819,  1638, 2253, 2867, 3891, 4506,
                          4710, 4915, 5120, 5325, 5325, 5120, 4915, 4710, 4506, 4096};
    s32 scale;
    GXOamAttr *matrixOams;

    if (startFrames < 0) {
        gRaceMNumberPair->mOffsetX = 0;
        gRaceMNumberPair->mCellMatrix = NULL;
        gRaceMNumberPair->mScale = 0;
        gRaceMNumberPair->mMatrixIndex = 0;
        return;
    }
    if (startFrames < 0x14) {
        s32 *matrix;

        scale = scaleTable[startFrames];
        Matrix2x2ReciprocalScale(gRaceMNumberPair->mScaleMatrix, scale);
        gRaceMNumberPair->mOffsetX = 0;
        gRaceMNumberPair->mCellMatrix = gRaceMNumberPair->mScaleMatrix;
        gRaceMNumberPair->mScale = scale;
        gRaceMNumberPair->mMatrixIndex = func_020ae5c4(oamBuffer);
        matrix = gRaceMNumberPair->mCellMatrix;
        matrixOams = &oamBuffer->mOams[gRaceMNumberPair->mMatrixIndex * 4];
        matrixOams[0].mUnk_00[3] = matrix[0] >> 4;
        matrixOams[1].mUnk_00[3] = matrix[1] >> 4;
        matrixOams[2].mUnk_00[3] = matrix[2] >> 4;
        matrixOams[3].mUnk_00[3] = matrix[3] >> 4;
        gRaceMNumberPair->mCellMatrix[3] = gRaceMNumberPair->mScale;
        gRaceMNumberPair->mCellMatrix[0] = gRaceMNumberPair->mCellMatrix[3];
        gRaceMNumberPair->mCellMatrix[2] = 0;
        gRaceMNumberPair->mCellMatrix[1] = gRaceMNumberPair->mCellMatrix[2];
        return;
    }
    if (startFrames < 0x78) {
        gRaceMNumberPair->mOffsetX = 0;
        gRaceMNumberPair->mCellMatrix = NULL;
        gRaceMNumberPair->mScale = 0x1000;
        gRaceMNumberPair->mMatrixIndex = 0;
        return;
    }
    gRaceMNumberPair->mOffsetX = InterpolateS16(1, 0, 0x80, startFrames - 0x78, 0x14);
    gRaceMNumberPair->mCellMatrix = NULL;
    gRaceMNumberPair->mScale = 0x1000;
    gRaceMNumberPair->mMatrixIndex = 0;
}

void DrawRaceMNumberPairTwoDigit(RaceHudOamBuffer *oamBuffer) {
    s32 spriteX[5] = {175, 190, 203, 216, 231};
    Unk020224e0_c *cell;
    s32 *matrix = NULL;
    u16 matrixIndex;
    s32 position0[2];
    s32 position1[2];
    s32 position2[2];
    s32 position3[2];
    s32 position4[2];

    if (gRaceMNumberPair->mCourseNumber / 10 != 0) {
        matrixIndex = gRaceMNumberPair->mMatrixIndex;
        matrix = gRaceMNumberPair->mCellMatrix;
        cell = GetRaceMNcerEntry(gRaceMNumberPair->mCourseNumber / 10 + 0x2d);
        position0[0] = (spriteX[0] + gRaceMNumberPair->mOffsetX) << 12;
        position0[1] = 0xb1000;
        oamBuffer->mOamCount +=
            NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount, cell, matrix,
                                  position0, matrixIndex, 1);
    }
    matrixIndex = gRaceMNumberPair->mMatrixIndex;
    matrix = gRaceMNumberPair->mCellMatrix;
    cell = GetRaceMNcerEntry(gRaceMNumberPair->mCourseNumber % 10 + 0x2d);
    position1[0] = (spriteX[1] + gRaceMNumberPair->mOffsetX) << 12;
    position1[1] = 0xb1000;
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, matrix, position1, matrixIndex, 1);
    matrixIndex = gRaceMNumberPair->mMatrixIndex;
    matrix = gRaceMNumberPair->mCellMatrix;
    cell = GetRaceMNcerEntry(0x37);
    position2[0] = (spriteX[2] + gRaceMNumberPair->mOffsetX) << 12;
    position2[1] = 0xb1000;
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, matrix, position2, matrixIndex, 1);
    matrixIndex = gRaceMNumberPair->mMatrixIndex;
    matrix = gRaceMNumberPair->mCellMatrix;
    cell = GetRaceMNcerEntry(gRaceMNumberPair->mCourseCount / 10 + 0x2d);
    position3[0] = (spriteX[3] + gRaceMNumberPair->mOffsetX) << 12;
    position3[1] = 0xb1000;
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, matrix, position3, matrixIndex, 1);
    matrixIndex = gRaceMNumberPair->mMatrixIndex;
    matrix = gRaceMNumberPair->mCellMatrix;
    cell = GetRaceMNcerEntry(gRaceMNumberPair->mCourseCount % 10 + 0x2d);
    position4[0] = (spriteX[4] + gRaceMNumberPair->mOffsetX) << 12;
    position4[1] = 0xb1000;
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, matrix, position4, matrixIndex, 1);
}

void DrawRaceMNumberPairOneDigit(RaceHudOamBuffer *oamBuffer) {
    s32 spriteX[3] = {205, 218, 231};
    Unk020224e0_c *cell;
    s32 *matrix;
    u16 matrixIndex;
    s32 position0[2];
    s32 position1[2];
    s32 position2[2];

    matrixIndex = gRaceMNumberPair->mMatrixIndex;
    matrix = gRaceMNumberPair->mCellMatrix;
    cell = GetRaceMNcerEntry(gRaceMNumberPair->mCourseNumber + 0x2d);
    position0[0] = (spriteX[0] + gRaceMNumberPair->mOffsetX) << 12;
    position0[1] = 0xb1000;
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, matrix, position0, matrixIndex, 1);
    matrixIndex = gRaceMNumberPair->mMatrixIndex;
    matrix = gRaceMNumberPair->mCellMatrix;
    cell = GetRaceMNcerEntry(0x37);
    position1[0] = (spriteX[1] + gRaceMNumberPair->mOffsetX) << 12;
    position1[1] = 0xb1000;
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, matrix, position1, matrixIndex, 1);
    matrixIndex = gRaceMNumberPair->mMatrixIndex;
    matrix = gRaceMNumberPair->mCellMatrix;
    cell = GetRaceMNcerEntry(gRaceMNumberPair->mCourseCount + 0x2d);
    position2[0] = (spriteX[2] + gRaceMNumberPair->mOffsetX) << 12;
    position2[1] = 0xb1000;
    oamBuffer->mOamCount += NNS_G2dMakeCellToOams(&oamBuffer->mOams[oamBuffer->mOamCount], 0x80 - oamBuffer->mOamCount,
                                                  cell, matrix, position2, matrixIndex, 1);
}
