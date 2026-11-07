#pragma once

#include "types.h"
#include "code_02012b30.h" // MtxFx43, NNSG3dResFileHeader
#include "Main/Unknown/code_020846c0.h"
#include "Main/Unknown/code_02087d0c.h"
#include "Main/Unknown/code_02017000.h"
#include "Main/Unknown/code_0208eb10.h"
#include "Main/Unknown/unk_02166000.h"
#include "Main/Unknown/unk_0217b000.h"

// A pooled effect object: a model, up to three animation objects, a position and a Start and an Update function.
typedef struct ModelEffect {
    /* 00 */ u8 mUnk_00[8];
    /* 08 */ Nsbmd mNsbmd;
    /* 74 */ Vec3 mPos;
    // Called at each start with the object and a flag; most kinds start particle effects only when it is non-zero.
    /* 80 */ void (*mStart)(struct ModelEffect *, s32);
    /* 84 */ void (*mUpdate)(struct ModelEffect *);
    /* 88 */ s32 mFinished;
    /* 8c */ u32 mKind;
    // [0] .nsbca, [1] .nsbma, [2] .nsbta animation object; NULL when the kind has no such file.
    /* 90 */ ModelAnimation *mAnimations[3];
    // Scale on x, y and z (three equal values, 0x1000 = 1.0), passed to the draw call.
    /* 9c */ s32 mScale[3];
    /* a8 */ u32 mSinceStartFrames;
    // Frame count at which mFinished is set; 0 for the kinds whose update uses a fixed frame number.
    /* ac */ u32 mFinishFrameCount;
    /* b0 */ u16 mPolygonId;
    /* b4 */ s32 mVisible;
} ModelEffect;

void func_0208d978(const Vec3 *position, s32 startModel);
void UpdateModelEffectBombcore2(ModelEffect *a);
void StartModelEffectBombcore2(ModelEffect *a, s32 b);
void UpdateModelEffectBkWave(ModelEffect *a);
void StartModelEffectBkWave(ModelEffect *a, s32 b);
void UpdateWaterEfctKinds(ModelEffect *a);
void StartWaterEfctKind4(ModelEffect *a);
void StartWaterEfctKind2(ModelEffect *a);
void UpdateModelEffectBombcore(ModelEffect *a);
void StartModelEffectBombcore(ModelEffect *a, s32 b);
void SetupModelEffectKind(void *heap, s32 kind, NNSG3dResFileHeader *modelFile, void *nsbcaFile, void *nsbmaFile,
                          void *nsbtaFile);
void InitModelEffectObjects(void *heap);
void SetupBkWaveKind(void);
void SetupWaterEfctKindRow(ModelEffectKind *kindRow, s32 objectCount);
void DrawModelEffects(void);
void UpdateModelEffects(void);
ModelEffect *StartModelEffect(u32 kind, const Vec3 *position, s32 startEffects);
void InitModelEffects(void *heap);
void func_0208e808(s32 a);
void DrawPosStripQuad(const MtxFx43 *a, PosStripPoint *b, PosStripPoint *c, PosStripTexture *d);
void UpdatePosStrip(PosStrip *a);
