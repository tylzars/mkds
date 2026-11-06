#pragma once

#include "types.h"
#include "code_02010804.h"

u32 NNS_G3dPlttGetRequiredSize(const NNSG3dResTex *pTex);
void NNS_G3dTexReleaseTexKey(NNSG3dResTex *pTex, NNSG3dTexKey *texKey, NNSG3dTexKey *tex4x4Key);
