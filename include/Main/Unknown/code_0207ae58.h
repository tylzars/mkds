#pragma once

#include "types.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_0207adf8.h" // ShadowModel

struct KartModelsEntry;

void func_0207ae58(ShadowModel *a);
void DrawShadowWithMatrix(void *a, const void *b, Vec3 *c);
NNSG3dResMdl *InitShadowModel(void *a, NNSG3dResFileHeader *b, u32 c);
void InitShadowModelFromResMdl(Nsbmd *a, void *b, u32 c);
void StartKartCharacterAnimationOnce(Kart *p, s32 a, s32 b);
void func_0207b0d0(Kart *p);
void func_0207b13c(Kart *p);
void func_0207b1a8(Kart *p);
void func_0207b284(Kart *p);
void func_0207b354(Kart *p);
void StartKartWinOrLoseAnimation(Kart *p);
void SetCharacterAnimation(struct KartModelsEntry *a, s32 b, s32 c);
void SetCharacterFaceFrameIndex(struct KartModelsEntry *a, s32 b);
void AdvanceKartCharacterAnimation(Kart *p);
void func_0207b8c4(struct KartModelsEntry *a);
u32 GetCharacterAnimationLoopFlag(int a);
char *BuildCharacterNsbcaPath(u16 a, s32 b);
