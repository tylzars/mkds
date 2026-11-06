#include "Main/Unknown/code_0210f0d8.h"
#include "Main/Unknown/code_0210f090.h"
#include "code_0201ec30.h"
#include "code_0214eed8.h"

void func_0210f114(Unk0210f090 *p) {
    func_020203e4();
    MIC_StopAutoSampling();
}

void func_0210f0f4(Unk0210f090 *a) {
    MIC_StartAutoSampling(&a->mUnk_400);
    func_0202041c();
}

void func_0210f0d8(Unk0210f090 *p) {
    func_020203e4();
    MIC_StopAutoSampling();
}
