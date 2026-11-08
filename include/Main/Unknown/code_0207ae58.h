#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0207adf8.h" // ShadowModel

struct KartModelsEntry;

void func_0207ae58(ShadowModel *shadowModel);
void DrawShadowWithMatrix(void *shadowModel, const void *matrix, Vec3 *extraVector);
NNSG3dResMdl *InitShadowModel(void *shadowModel, NNSG3dResFileHeader *resFileHeader, u32 polygonId);
void InitShadowModelFromResMdl(Nsbmd *nsbmd, void *resFile, u32 polygonId);
void StartKartCharacterAnimationOnce(Kart *kart, s32 animationIndex, s32 nextAnimationIndex);
void func_0207b0d0(Kart *kart);
void func_0207b13c(Kart *kart);
void StopKartStarModels(Kart *kart);
void StartKartStarModels(Kart *kart);
void AdvanceKartAnimationChangeTimer(Kart *kart);
void StartKartWinOrLoseAnimation(Kart *p);
void SetCharacterAnimation(struct KartModelsEntry *kartModelsEntry, s32 animationIndex, s32 useBlend);
void SetCharacterFaceFrameIndex(struct KartModelsEntry *kartModelsEntry, s32 faceFrameIndex);
void AdvanceKartCharacterAnimation(Kart *animationState);
void ClearCharacterTurnAndNextAnimation(struct KartModelsEntry *kartModelsEntry);
u32 GetCharacterAnimationLoopFlag(int animationIndex);
char *BuildCharacterNsbcaPath(u16 characterIndex, s32 animationIndex);
