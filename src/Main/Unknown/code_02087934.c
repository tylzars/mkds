#include "Main/Unknown/code_02087934.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_02087d0c.h"
#include "Main/Unknown/unk_02155000.h"
#include "Main/Unknown/unk_02165000.h"
#include "registers.h"

void ResetModelAnimationWithLoopFlag(ModelAnimation *modelAnimation, s32 frameCountFixed, u16 loopFlag) {
    modelAnimation->mLoopMode = loopFlag == 0 ? UNK_02087CFC_KIND_0 : UNK_02087CFC_KIND_1;
    modelAnimation->mDone = 0;
    modelAnimation->mFrameStep = 0x1000;
    modelAnimation->mFrameCountFixed = frameCountFixed;
    modelAnimation->mFrameIndex = 0;
    modelAnimation->mLoopsDone = 0;
    modelAnimation->mLoopCount = 0;
}

void func_02087b9c(ModelAnimation *modelAnimation) {
    s32 frameIndex;
    switch (modelAnimation->mLoopMode) {
        case 1:
            if (modelAnimation->mFrameIndex >= modelAnimation->mFrameCountFixed) {
                modelAnimation->mFrameIndex = modelAnimation->mFrameIndex - modelAnimation->mFrameCountFixed;
            } else if (modelAnimation->mFrameIndex <= 0) {
                frameIndex = modelAnimation->mFrameIndex;
                modelAnimation->mFrameIndex = modelAnimation->mFrameCountFixed - 0x1000 + frameIndex;
            }
            break;
        case 0:
            if (modelAnimation->mFrameIndex >= modelAnimation->mFrameCountFixed - 0x1000) {
                modelAnimation->mFrameIndex = modelAnimation->mFrameCountFixed - 0x1000;
                modelAnimation->mFrameStep = 0;
                modelAnimation->mDone = 1;
            }
            break;
        case 2:
            if (modelAnimation->mLoopsDone >= modelAnimation->mLoopCount) {
                return;
            }
            if (modelAnimation->mFrameIndex >= modelAnimation->mFrameCountFixed) {
                modelAnimation->mFrameIndex = modelAnimation->mFrameIndex - modelAnimation->mFrameCountFixed;
                modelAnimation->mLoopsDone++;
            } else if (modelAnimation->mFrameIndex <= 0) {
                frameIndex = modelAnimation->mFrameIndex;
                modelAnimation->mFrameIndex = modelAnimation->mFrameCountFixed - 0x1000 + frameIndex;
                modelAnimation->mLoopsDone++;
            }
            if (modelAnimation->mLoopsDone >= modelAnimation->mLoopCount) {
                modelAnimation->mFrameIndex = modelAnimation->mFrameCountFixed - 0x1000;
                modelAnimation->mFrameStep = 0;
                modelAnimation->mDone = 1;
            }
            break;
    }
}

void AdvanceModelAnimationFrame(ModelAnimation *modelAnimation) {
    modelAnimation->mDone = 0;
    modelAnimation->mFrameIndex = modelAnimation->mFrameIndex + modelAnimation->mFrameStep;
    func_02087b9c(modelAnimation);
}

void func_02087ab0(s32 texWidthFixed, s32 texHeightFixed) {
    u32 heightTexCoord;
    reg_G3_TEXCOORD = 0;
    reg_G3_VTX_16 = data_02155a74[0] | data_02155a74[1] << 16;
    reg_G3_VTX_16 = data_02155a74[2];
    heightTexCoord = (u16) ((texHeightFixed << 8) >> 16);
    reg_G3_TEXCOORD = heightTexCoord << 16;
    reg_G3_VTX_16 = data_02155a74[3] | data_02155a74[4] << 16;
    reg_G3_VTX_16 = data_02155a74[5];
    reg_G3_TEXCOORD = (u16) ((texWidthFixed << 8) >> 16) | heightTexCoord << 16;
    reg_G3_VTX_16 = data_02155a74[6] | data_02155a74[7] << 16;
    reg_G3_VTX_16 = data_02155a74[8];
    reg_G3_TEXCOORD = (u16) ((texWidthFixed << 8) >> 16);
    reg_G3_VTX_16 = data_02155a74[9] | data_02155a74[10] << 16;
    reg_G3_VTX_16 = data_02155a74[11];
}

void func_020879e8(s32 texWidthFixed, s32 texHeightFixed) {
    u32 heightTexCoord;
    reg_G3_TEXCOORD = 0;
    reg_G3_VTX_16 = data_02155a74[0] | data_02155a74[1] << 16;
    reg_G3_VTX_16 = data_02155a74[2];
    heightTexCoord = (u16) ((texHeightFixed << 8) >> 16);
    reg_G3_TEXCOORD = heightTexCoord << 16;
    reg_G3_VTX_16 = data_02155a74[3] | data_02155a74[4] << 16;
    reg_G3_VTX_16 = data_02155a74[5];
    reg_G3_TEXCOORD = (u16) ((texWidthFixed << 8) >> 16) | heightTexCoord << 16;
    reg_G3_VTX_16 = data_02155a74[6] | data_02155a74[7] << 16;
    reg_G3_VTX_16 = data_02155a74[8];
    reg_G3_TEXCOORD = (u16) ((texWidthFixed << 8) >> 16);
    reg_G3_VTX_16 = data_02155a74[9] | data_02155a74[10] << 16;
    reg_G3_VTX_16 = data_02155a74[11];
}

void func_02087934(u32 color) {
    s32 x;
    s32 y;
    reg_G3_COLOR = color;
    x = data_021659b4;
    y = data_021659c0;
    reg_G3_MTX_SCALE = y;
    reg_G3_MTX_SCALE = x;
    reg_G3_MTX_SCALE = 0x1333;
    reg_G3_VTX_16 = data_02155a74[0] | data_02155a74[1] << 16;
    reg_G3_VTX_16 = data_02155a74[2];
    reg_G3_VTX_16 = data_02155a74[3] | data_02155a74[4] << 16;
    reg_G3_VTX_16 = data_02155a74[5];
    reg_G3_VTX_16 = data_02155a74[6] | data_02155a74[7] << 16;
    reg_G3_VTX_16 = data_02155a74[8];
    reg_G3_VTX_16 = data_02155a74[9] | data_02155a74[10] << 16;
    reg_G3_VTX_16 = data_02155a74[11];
}
