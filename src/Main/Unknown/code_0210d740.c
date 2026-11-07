#include "Main/Unknown/code_0210d740.h"

#include "Main/Unknown/code_0210d73c.h"
#include "Main/Unknown/code_0210dc60.h"
#include "code_0212bcac.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "code_0212df7c.h"
#include "code_0212d214.h"
#include "output_effect.h"
#include "code_0212ba68.h"
#include "Main/Unknown/code_0210d890.h"
#include "Main/Unknown/code_0210d894.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/code_0210d960.h"

void func_0210d990(u32 flag) {
    data_0217d064 = flag;
}

u32 func_0210d980(void) {
    return data_0217d064;
}

void SetSoundFadeSteps(u32 fadeSteps) {
    gSoundFadeSteps = fadeSteps;
}

u32 GetSoundFadeSteps(void) {
    return gSoundFadeSteps;
}

void func_0210d894(void *heapMemory, u32 heapSize, const u8 *filePath) {
    NNS_SndInit();
    data_0217d130 = NNS_SndHeapCreate(heapMemory, heapSize);
    data_0217d06c = NNS_SndHeapAlloc(data_0217d130, 0x1020, func_0210d890, NULL, 0);
    if (filePath != NULL) {
        NNS_SndArcInit(&data_0217d0a0, filePath, data_0217d130, 0);
        data_0217d064 = 1;
        NNS_SndArcPlayerSetup(data_0217d130);
    }
    NNS_SndHandleInit(&data_0217d068);
    SetupSoundMode(&data_0217d084, &data_0217d070, 0);
}

void func_0210d890(void *memory, u32 size, void *data1, u32 data2) {}

void StartSoundOutputEffect(u32 type) {
    NNS_SndCaptureStartOutputEffect((void *) (((u32) data_0217d06c + 0x1f) & ~0x1f), 0x1000, type);
    gSoundOutputEffectType = type;
}

void ChangeSoundOutputEffect(s32 type) {
    NNS_SndCaptureChangeOutputEffect(type);
    gSoundOutputEffectType = type;
}

void StartSeqAtVolume(u32 seqNo, u32 volume, NNSSndSeqPlayer **handle) {
    if (*handle != NULL) {
        NNS_SndPlayerStopSeq(handle, 0);
    }
    NNS_SndArcGetFileAddress(NNS_SndArcGetSeqInfo(seqNo)->mFileId);
    NNS_SndArcPlayerStartSeq(handle, seqNo);
    NNS_SndPlayerSetVolume(handle, volume);
}

void func_0210d7ac(void) {
    if (data_0217d070.mUnk_00 != 0) {
        func_0210d73c(&data_0217d070);
    }
    NNS_SndMain();
}

void func_0210d740(Unk0217d070 *scenePlayers, SceneSoundState *sceneSoundState, u32 c, Unk021073ec d) {
    SetupSoundMode(&data_0217d084, scenePlayers, 0);
    *(Unk021073ec *) &scenePlayers->mUnk_09 = d;
    scenePlayers->mUnk_04 = sceneSoundState;
    scenePlayers->mUnk_08 = c;
    NNS_SndHandleInit(&scenePlayers->mUnk_0c);
    NNS_SndHandleInit(&scenePlayers->mUnk_10);
    scenePlayers->mUnk_00 = 1;
}
