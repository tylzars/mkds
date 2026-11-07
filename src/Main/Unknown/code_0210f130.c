#include "Main/Unknown/code_0210f130.h"

#include "Main/Unknown/unk_0217d000.h"
#include "code_0201ec30.h"
#include "mic.h"
#include "pm.h"
#include "Main/Unknown/code_0210f090.h"

u32 data_0217d1bc;

void func_0210f1d4(void) {
    MIC_Init();
    PM_Init();
    PM_SetAmp(1);
    data_0217d1bc = 1;
}

void func_0210f130(Unk0210f090 *p) {
    MICAutoParam *q;
    s32 i;

    if (data_0217d1bc == 0) {
        MIC_Init();
        PM_Init();
        PM_SetAmp(1);
        data_0217d1bc = 1;
    }
    p->mUnk_41c = 0;
    for (i = 0; i < 0x400; i++) {
        p->mUnk_000[i] = 0;
    }
    p->mUnk_400.mType = MIC_SAMPLING_TYPE_SIGNED_8BIT;
    q = &p->mUnk_400;
    q->mBuffer = p;
    q->mSize = 0x400;
    q->mRate = 0x105d;
    q->mLoopEnable = 1;
    q->mFullCallback = 0;
    q->mFullArg = 0;
    func_02020430((Unk02173290 *) q);
    func_020203d4(0);
    PM_SetAmpGain(3);
}
