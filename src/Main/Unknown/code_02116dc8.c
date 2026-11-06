#include "Main/Unknown/code_02116dc8.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020b4000.h"

#include "Main/Unknown/code_02116dd4.h"
#include "Main/Unknown/unk_0216d000.h"

#pragma thumb on

void func_02116e70(void) {
    void *v1;
    Unk02021dc8 *v2;
    Ncgr *v3;
    Nclr *v4[1];
    v2 = NULL;
    v3 = NULL;
    v4[0] = NULL;
    v1 = FindSceneFile(gWaitNcerName);
    LoadNcerData(&v2, v1);
    v1 = FindSceneFile(gWaitNcgrName);
    LoadNcgrData2(&v3, v1);
    v1 = FindSceneFile(gWaitNclrName);
    LoadNclrData(v4, v1);
}

void CreateWait(void *a, Unk02021dc8 *b, Unk0201ea30 *c, u32 d, u16 e, u32 f) {
    Wait *v1;
    Wait *v2;
    void *v3;
    v2 = HeapAlloc(a, (u32) 0x2c);
    gWait = v2;
    v3 = FindSceneFile(gWaitNcerName);
    LocateNcer(&gWait->mNcer, v3);
    v3 = FindSceneFile(gWaitNcgrName);
    LocateNcgr2((Ncgr **) &gWait->mNcgr, v3);
    v3 = FindSceneFile(gWaitNclrName);
    LocateNclr((Nclr **) (((s32) gWait + 8)), v3);
    v3 = FindSceneFile(gWaitBnclName);
    gWait->mBncl = v3;
    gWait->mDestinationNcer = b;
    gWait->mDestinationBncl = c;
    gWait->mDestinationBnclIndex = d;
    gWait->mUnk_1c = e;
    gWait->mUnk_20 = f;
    gWait->mFrameIndex = 2;
    gWait->mFrameIndexFrames = 3;
}

#pragma thumb off

#pragma thumb on
void func_02116dc8(void) {
    u32 value0;
    u32 value1;
    value1 = 0u;
    value0 = (u32) &gWait;
    *(u32 *) ((value0) + 0u) = value1;
}
#pragma thumb off
