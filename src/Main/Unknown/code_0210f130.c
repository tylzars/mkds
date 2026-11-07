#include "Main/Unknown/code_0210f130.h"

#include "Main/Unknown/unk_0217d000.h"
#include "code_0201ec30.h"
#include "mic.h"
#include "pm.h"
#include "Main/Unknown/code_0210f090.h"

u32 gMicInitialized;

void InitMicAndAmp(void) {
    MIC_Init();
    PM_Init();
    PM_SetAmp(1);
    gMicInitialized = 1;
}

void SetupMicAutoSampling(MicBuffer *micBuffer) {
    MICAutoParam *autoParam;
    s32 i;

    if (gMicInitialized == 0) {
        MIC_Init();
        PM_Init();
        PM_SetAmp(1);
        gMicInitialized = 1;
    }
    micBuffer->mUnk_41c = 0;
    for (i = 0; i < 0x400; i++) {
        micBuffer->mSamples[i] = 0;
    }
    micBuffer->mAutoParam.mType = MIC_SAMPLING_TYPE_SIGNED_8BIT;
    autoParam = &micBuffer->mAutoParam;
    autoParam->mBuffer = micBuffer;
    autoParam->mSize = 0x400;
    autoParam->mRate = 0x105d;
    autoParam->mLoopEnable = 1;
    autoParam->mFullCallback = 0;
    autoParam->mFullArg = 0;
    func_02020430((Unk02173290 *) autoParam);
    func_020203d4(0);
    PM_SetAmpGain(3);
}
