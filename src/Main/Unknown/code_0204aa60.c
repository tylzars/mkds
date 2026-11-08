#include "Main/Unknown/code_0204aa60.h"
#include "Main/Unknown/code_0204ad24.h"
#include "Main/Unknown/code_0210dc7c.h"
#include "Main/Unknown/code_0210d960.h"
#include "Main/Unknown/code_0210f868.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "pm.h"

void InitSceneSoundSetPlayer(s32 seqId) {
    if (data_021759d0->mSoundSetPlayerInitialized) {
        return;
    }
    data_021759d0->mSoundSetPlayerInitialized = 1;
    func_0210f8b0(&data_021759d0->mSoundSetPlayer, seqId, 0xff);
}

void StartSceneSoundSetSeq(void) {
    if (!data_021759d0->mSoundSetPlayerInitialized) {
        return;
    }
    if (data_021759d0->mSoundSetSeqPlaying) {
        return;
    }
    data_021759d0->mSoundSetSeqPlaying = 1;
    StartSoundSetSeq(&data_021759d0->mSoundSetPlayer, data_0216cb28);
}

void StopSceneSoundSetSeq(void) {
    Unk021759d0 *p = data_021759d0;

    if (!p->mSoundSetSeqPlaying) {
        return;
    }
    StopSoundSetSeq(&p->mSoundSetPlayer, GetSoundFadeSteps());
    data_021759d0->mSoundSetSeqPlaying = 0;
}

void ReleaseSceneSoundSetPlayer(void) {
    if (data_021759d0->mSoundSetSeqPlaying) {
        return;
    }
    if (!data_021759d0->mSoundSetPlayerInitialized) {
        return;
    }
    ReleaseSoundSetPlayer(&data_021759d0->mSoundSetPlayer);
    data_021759d0->mSoundSetPlayerInitialized = 0;
}

void StopSceneSoundSetSeqWithSteps(u32 fadeSteps) {
    if (!data_021759d0->mSoundSetSeqPlaying) {
        return;
    }
    StopSoundSetSeq(&data_021759d0->mSoundSetPlayer, fadeSteps);
}

BOOL TrySetBackLights(s32 firstRequest, s32 secondRequest) {
    Unk021759d0 *p = data_021759d0;
    s32 firstBackLightOn = p->mFirstBackLightOn;
    s32 secondBackLightOn = p->mSecondBackLightOn;
    BOOL allSet = TRUE;

    if (firstRequest == 0) {
        firstBackLightOn = 1;
    } else if (firstRequest == 1) {
        firstBackLightOn = 0;
    }
    if (secondRequest == 0) {
        secondBackLightOn = 1;
    } else if (secondRequest == 1) {
        secondBackLightOn = 0;
    }
    if (firstBackLightOn != p->mFirstBackLightOn) {
        if (PM_SetBackLight(0, firstBackLightOn) == 0) {
            data_021759d0->mFirstBackLightOn = firstBackLightOn;
        } else {
            allSet = FALSE;
        }
    }
    if (secondBackLightOn != data_021759d0->mSecondBackLightOn) {
        if (PM_SetBackLight(1, secondBackLightOn) == 0) {
            data_021759d0->mSecondBackLightOn = secondBackLightOn;
        } else {
            allSet = FALSE;
        }
    }
    return allSet;
}

RandomState64 *GetRandomState(void) {
    void *random = NULL;
    Unk021759d0 *p = data_021759d0;

    switch (p->mUnk_20) {
        case 0:
        case 3:
            random = &p->mRandom;
            break;
        case 1:
        case 2:
            random = &data_0217aa00->mUnk_1ee8;
            break;
    }
    return random;
}
