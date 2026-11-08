#include "Main/Unknown/code_0210d590.h"
#include "Main/Unknown/code_0210d740.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_0212bcac.h"

static inline void func_0210d614_inline(ScenePlayers *scenePlayers, u32 seqNo, NNSSndSeqPlayer **handle) {
    if (handle == NULL) {
        handle = &data_0217d07c;
    }
    if (scenePlayers->mUnk_0b == 0xff) {
        return;
    }
    StartSeqAtVolume(seqNo, data_0216cb28, handle);
}

void func_0210d6cc(ScenePlayers *scenePlayers) {
    scenePlayers->mUnk_00 = 2;
    if (scenePlayers->mUnk_0a != 2) {
        return;
    }
    func_0210d614_inline(scenePlayers, data_0217d070.mUnk_0b, (NNSSndSeqPlayer **) (u32) &data_0217d07c);
}

void func_0210d65c(ScenePlayers *scenePlayers) {
    scenePlayers->mUnk_00 = 3;
    if (scenePlayers->mUnk_0a != 3) {
        return;
    }
    func_0210d614_inline(scenePlayers, data_0217d070.mUnk_0b, (NNSSndSeqPlayer **) (u32) &data_0217d07c);
}

void func_0210d614(ScenePlayers *scenePlayers, u32 seqNo, NNSSndSeqPlayer **handle) {
    func_0210d614_inline(scenePlayers, seqNo, handle);
}

void func_0210d5c0(ScenePlayers *scenePlayers) {
    func_0210d614_inline(scenePlayers, data_0217d070.mUnk_0b, (NNSSndSeqPlayer **) (u32) &data_0217d07c);
}

void func_0210d590(ScenePlayers *scenePlayers, u32 fadeSteps) {
    if (scenePlayers->mUnk_0b == 0xff) {
        return;
    }
    NNS_SndPlayerStopSeq(&scenePlayers->mUnk_0c, fadeSteps);
}
