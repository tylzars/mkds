#include "03/code_021cdbd0.h"
#include "code_0212bcac.h"
#include "03/code_021d3000.h"

#include "03/unk_021da000.h"
#include "03/code_021d27d8.h"
#include "03/code_021d1440.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021cdbc8.h"
#include "03/code_021d3488.h"
#include "code_0212ba68.h"
#include "code_0212d214.h"
#include "code_0212df7c.h"

void CreateSoundData(void) {
    u32 a;
    gSoundData = AllocExpHeapBlock(0x9c, 4);
    gSoundData->mFileData = LoadFile(gSoundDataSdatName, &a, 0x20);
    NNS_SndInit();
    NNS_SndArcInitOnMemory(&gSoundData->mArc, gSoundData->mFileData);
    NNS_SndArcPlayerSetup(NULL);
    NNS_SndHandleInit(&gSoundData->mSeqPlayer);
    gSoundData->mTask = AddTask(0, UpdateSound, NULL, 0xc8);
}

void func_ov003_021cdc28(void) {
    RequestTaskRemoval(0, gSoundData->mTask);
    FreeExpHeapBlockAndClearPointer(&gSoundData);
}

void StartSoundSeq(u32 index) {
    u32 value0 = index;
    u32 value1;
    u32 value2;
    u32 value3;
    value2 = (value0) + (0u);
    value0 = (u32) &gSoundData;
    value0 = *(const u32 *) ((value0) + 0u);
    value0 = (value0) + 144u;
    value1 = 0u;
    value0 = NNS_SndArcPlayerStartSeqArc((const void *) value0, value1, value2);
}

u32 SetSoundSeqVolume(u32 volume) {
    u32 value0 = volume;
    u32 value1;
    u32 value3;
    value1 = (value0) + (0u);
    value0 = (u32) &gSoundData;
    value0 = *(const u32 *) ((value0) + 0u);
    value0 = (value0) + 144u;
    value3 = (u32) &NNS_SndPlayerSetVolume;
    value0 = (u32) NNS_SndPlayerSetVolume((NNSSndSeqPlayer **) value0, value1);
    return value0;
}

void SetSoundSeqTrackPitch(u32 tracks, u32 pitch) {
    NNS_SndPlayerSetTrackPitch(OFFSET_PTR(NNSSndSeqPlayer *, gSoundData, 0x90), tracks, pitch);
}

void StopSoundSeq(void) {
    NNS_SndPlayerStopSeq(OFFSET_PTR(NNSSndSeqPlayer *, gSoundData, 0x90), 0);
}
