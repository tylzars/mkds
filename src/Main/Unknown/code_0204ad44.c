#include "Main/Unknown/code_0204ad44.h"

#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020487fc.h"
#include "gecom.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0202f14c.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0200eddc.h"
#include "code_0200f5ac.h"
#include "code_0200fc8c.h"
#include "code_0214d018.h"
#include "pm.h"
#include "frameheap.h"
#include "Main/Unknown/code_0204aa60.h"

void ReleaseWLMenuSceneCallback(void) {
    u32 unused;
    ReleaseWLMenuScene();
}

void func_0204b024(void) {
    u32 unused;
    func_0202f160();
}

void UpdateWLMenuSceneCallback(void *sceneNumbers) {
    AdvanceWLMenuScene(sceneNumbers);
}

s32 RunWLMenuScene(SceneNumbers *sceneNumbers) {
    SceneCallbacks callbacks = gWLMenuSceneCallbacks;

    RunScene(sceneNumbers, &callbacks);
    return 0;
}

void func_0204af70(void *heap) {
    u8 *arenaLo;
    u8 *arenaHi;

    arenaLo = OS_GetArenaLo(4);
    arenaHi = OS_GetArenaHi(4);
    data_021759d0 = HeapAlloc(heap, 0x7c);
    data_021759d0->mHeap = NNS_FndCreateFrmHeapEx(arenaLo, arenaHi - arenaLo, 1);
    func_0204ad44();
}

void func_0204ad44(void) {
    Unk0200fddc ownerInfo;
    u64 firstTick;
    u64 secondTick;
    Unk021759d0 *p;
    RandomState64 *random;

    OS_GetOwnerInfo(&ownerInfo);
    MI_CpuFill8(data_021759d0->mOwnerText, 0, 0x14);
    data_021759d0->mOwnerCharCount = ownerInfo.mUnk_18;
    MI_CpuCopy8(ownerInfo.mUnk_04, data_021759d0->mOwnerText, data_021759d0->mOwnerCharCount << 1);
    data_021759d0->mUnk_40 = ownerInfo.mUnk_01;
    data_021759d0->mUnk_00 = 1;
    switch (ownerInfo.mUnk_00) {
        case 1:
            data_021759d0->mLanguageIndex = 1;
            break;
        case 2:
            data_021759d0->mLanguageIndex = 2;
            break;
        case 3:
            data_021759d0->mLanguageIndex = 3;
            break;
        case 4:
            data_021759d0->mLanguageIndex = 4;
            break;
        case 5:
            data_021759d0->mLanguageIndex = 5;
            break;
        default:
            data_021759d0->mLanguageIndex = 1;
            break;
    }
    data_021759d0->mUnk_20 = 0;
    data_021759d0->mUnk_28 = -1;
    data_021759d0->mUnk_44 = -1;
    data_021759d0->mSoundSetSeqPlaying = 0;
    data_021759d0->mSoundSetPlayerInitialized = 0;
    data_021759d0->mUnk_58 = 0;
    data_021759d0->mUnk_5c = 0;
    NNS_G3dGeUseFastDma(0);
    data_021759d0->mUnk_1c_3 = 0;
    data_021759d0->mUnk_54 = FALSE;
    data_021759d0->mUnk_50 = 0;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        data_021759d0->mUnk_1c_2 = 1;
    } else {
        data_021759d0->mUnk_1c_2 = 0;
    }
    firstTick = OS_GetTick();
    secondTick = OS_GetTick();
    p = data_021759d0;
    random = &p->mRandom;
    random->mValue = (u32) ((firstTick << 16) + secondTick);
    random->mMultiplier = 0x5d588b656c078965;
    random->mIncrement = 0x269ec3;
    if (PM_GetBackLight(&p->mFirstBackLightOn, &p->mSecondBackLightOn) == 0) {
        return;
    }
    TrySetBackLights(1, 1);
}
