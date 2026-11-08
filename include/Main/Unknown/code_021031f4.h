#pragma once

#include "types.h"
#include "Main/Unknown/code_02102674.h"

// The register words and texture sizes DrawOrthoQuadsWithModel uses, filled from one model.
typedef struct {
    /* 00 */ void *mModel;
    /* 04 */ u32 mPolygonAttr;
    /* 08 */ u32 mTeximageParam;
    /* 0c */ u32 mPlttBase;
    /* 10 */ u32 mDifAmb;
    /* 14 */ u32 mSpeEmi;
    // Texture size values computed from mTeximageParam; they go into the texture coordinates of the quads.
    /* 18 */ u32 mUnk_18;
    /* 1c */ u32 mUnk_1c;
} OrthoQuadModel;

#include "Main/Unknown/code_021035ac.h"

// The cream record; gOrthoQuadUseCreamEffect picks which of the two records is drawn.
extern OrthoQuadModel gOrthoQuadCreamEffect;
// GesoSumi: the screen overlay the Gesso item starts for a hit kart.
extern OrthoQuadModel gOrthoQuadGesoSumi;

void func_021031f4(ItemGesso *gesso);
void SetupOrthoQuadModel(OrthoQuadModel *quadModel, Unk020e6488 *model);
void InitOrthoQuads(void);
void StartOrthoQuadsCreamEffect(u32 kartIndex, u32 count);
void CreateOrthoQuadCreamEffect(const char *fileName);
void StopOrthoQuads(int idx);
void StartOrthoQuadsGesoSumi(u32 kartIndex, u32 count);
void StartOrthoQuads(s32 idx, s32 count, s32 flag);
void SetupOrthoQuad(s32 idx, Unk021035ac_Pair startPair, s32 overlap);
u8 MarkOrthoQuadCellsAndGetOverlap(s32 column, s32 row);
void DrawOrthoQuads(void);
void DrawOrthoQuadsWithModel(OrthoQuadModel *model);
void UpdateOrthoQuads(void);
void AdvanceOrthoQuadDelayAndStartSound(OrthoQuad *quad);
void AdvanceOrthoQuadCornersByTable(OrthoQuad *quad);
void AdvanceOrthoQuadCornersByVelocity(OrthoQuad *quad);
void InitBouncingItemBoxTimers(void);
void InitBouncingItemBoxMapObjects(void);
