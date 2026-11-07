#include "Main/Unknown/code_0210f0d8.h"
#include "Main/Unknown/code_0210f090.h"
#include "code_0201ec30.h"
#include "mic.h"

void func_0210f114(MicBuffer *micBuffer) {
    func_020203e4();
    MIC_StopAutoSampling();
}

void StartMicAutoSampling(MicBuffer *micBuffer) {
    MIC_StartAutoSampling(&micBuffer->mAutoParam);
    func_0202041c();
}

void StopMicAutoSampling(MicBuffer *micBuffer) {
    func_020203e4();
    MIC_StopAutoSampling();
}
