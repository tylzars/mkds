#include "Main/Unknown/code_020487fc.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_020431e4.h"
#include "Main/Unknown/code_020435c4.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200fc8c.h"
#include "code_02016468.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "00/code_021832d8.h"
#include "code_020176b0.h"
#include "Main/Unknown/code_020497f0.h"
#include "Main/Unknown/code_02049000.h"
#include "Main/Unknown/code_0204984c.h"
#include "Main/Unknown/code_0204a52c.h"
#include "Main/Unknown/code_0204aa60.h"
#include "Main/Unknown/code_0204ad24.h"
#include "Main/Unknown/code_0204f7f4.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_02054f58.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_0212030c.h"
#include "code_02146af4.h"
#include "pm.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02039000.h"
#include "Main/Unknown/code_02043000.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0204a000.h"
#include "Main/Unknown/code_02054000.h"
#include "Main/Unknown/code_02055000.h"
#include "Main/Unknown/code_020b4000.h"

#pragma opt_rebuildconditionals off

static inline u32 func_020487fc_inline(void) {
    if (data_0217aa00 == NULL) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

static inline s32 func_020487fc_inline2(void) {
    BOOL r = FALSE;
    if (func_020487fc_inline() != 0 && data_0217aa00->mUnk_0004 != 13) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_020487fc_inline3(void) {
    BOOL r = FALSE;
    if (func_020487fc_inline2() && !(data_0217aa00->mUnk_0454 & 0x80)) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_020487fc_inline4(void) {
    BOOL r = FALSE;
    if (func_020487fc_inline3() && (data_0217aa00->mUnk_0454 & 0x10)) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_020487fc_inline5(void) {
    BOOL r = FALSE;
    if (data_0217aa14 != NULL && (data_0217aa14->mUnk_75c & 0x10)) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_020487fc_inline6(void) {
    BOOL r = FALSE;
    if (gRaceSetup->mMode == 5 && func_020487fc_inline5()) {
        r = TRUE;
    }
    if (func_020487fc_inline4()) {
        r = TRUE;
    }
    return r;
}

static inline void func_020487fc_inline7(void) {
    u32 t;
    if (CARD_IsPulledOut()) {
        if (func_02049820() == 1) {
            PM_ForceToPowerOff();
        }
        func_02049e38(3);
    }
    func_02043a34();
    if (!func_02049b6c()) {
        func_02043648();
    }
    if (func_02049820() == 1) {
        if (!ShouldGoSleepMode()) {
            if (PM_GetLCDPower() == 1) {
                t = OS_DisableInterrupts();
                gSceneRunState->mLcdOff = TRUE;
                PM_SetLCDPower(0);
                OS_RestoreInterrupts(t);
            }
        } else {
            PM_GoSleepMode(12, 0, 0);
        }
    } else {
        if (PM_GetLCDPower() == 0) {
            t = OS_DisableInterrupts();
            PM_SetLCDPower(1);
            if (AreBrightnessFadesClear()) {
                SetMainMasterBrightness(0);
                SetSubMasterBrightness(0);
            }
            gSceneRunState->mLcdOff = FALSE;
            OS_RestoreInterrupts(t);
        }
    }
}

static inline u32 func_020487fc_inline8(void) {
    if (func_0204998c()) {
        return 0;
    }
    return func_020435c4();
}

static inline BOOL func_020487fc_inline12(void) {
    return func_020487fc_inline() != 0 && data_0217aa00->mUnk_0004 != 13;
}

static inline void func_020487fc_inline9(const SceneCallbacks *b) {
    int v = GetCurrentSceneNumber();
    if (v == 1 || v == 10) {
        FinishDisplayFrameSwapIf(!func_020487fc_inline12() || !func_020487fc_inline6());
    } else {
        func_02037658(b->mUnk_1c);
    }
}

static inline s32 func_020487fc_inline10(void) {
    if (gBackupAccess->mBackupEnabled) {
        return gBackupAccess->mCommandRunning;
    }
    return 0;
}

static inline s32 func_020487fc_inline11(void) {
    BOOL r = FALSE;
    if (gWiFiSession != NULL && gWiFiSession->mHeapCreated != FALSE) {
        r = TRUE;
    }
    return r;
}

static inline BOOL func_020487fc_inline13(void) {
    if (func_020487fc_inline11()) {
        if (gWiFiSession->mUnk_0008.mState != 0) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}

static inline s32 func_020487fc_inline14(void) {
    if (!data_0217aa08->mBusy) {
        return func_020487fc_inline10();
    }
    return 1;
}

void RunScene(SceneNumbers *a, const SceneCallbacks *b) {
    u32 v;
    u32 t;
    s32 n;
    s32 r;
    BOOL c;
    s32 w;

    v = 0;
    gSceneRunState->mSceneFrames = v;
    gSceneRunState->mPassCount = v;
    gSceneRunState->mSceneCallbacks = *b;
    gSceneRunState->mUnk_10c = 6;
    gSceneRunState->mNextScene = 0;
    gSceneRunState->mUnk_118 = -1;
    gSceneRunState->mUnk_11c = 0;
    t = OS_DisableInterrupts();
    if (PM_GetLCDPower() == 1) {
        gSceneRunState->mLcdOff = FALSE;
    } else {
        gSceneRunState->mLcdOff = TRUE;
    }
    OS_RestoreInterrupts(t);
    gSceneRunState->mUnk_10c = 0;
    SetHeapGroupId(0);
    LoadArchiveSlotsForScene(a->mScene);
    SetHeapGroupId(9);
    GetHeap(GetCurrentHeapCall());
    CallQueueInit(HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x800), 0x80);
    if (func_0204a428(a->mScene, &n)) {
        InitSceneSoundSetPlayer(n);
    }
    InitSceneSounds(0);
    func_02043410();
    if (func_020487fc_inline2()) {
        data_0217aa00->mUnk_0454 |= 4;
    }
    LoadFontAndPlayerCharacterData();
    func_02043b48();
    CARD_SetPulledOutCallback(func_0204a540);
    data_021759d0->mUnk_78 = 0;
    if (b->mInit != NULL) {
        b->mInit(a);
    }
    func_02047274();
    gDisplaySettings->mIrqCallback = func_0204a4d8;
    StartSceneSoundSetSeq();
    StartSceneSounds();
    WaitIrqAndTurnOnDisplays();
    gSceneRunState->mUnk_10c = 1;
    do {
        PrepareDisplayFrame();
        func_020487fc_inline7();
        UpdateSounds();
        func_020487fc_inline8();
        func_020487fc_inline9(b);
        r = func_0204984c(a, gSceneRunState->mUnk_10c != 4);
        CallQueueDrain();
        if (r) {
            a->mNextScene = gSceneRunState->mNextScene;
            goto end;
        }
        UpdateWiFiSession();
        gSceneRunState->mPassCount++;
        RecordFrameTimes();
    } while (FinishDataSharingSync() != 1);
    func_02043b04();
    StartFadeToClear(b->mFadeToClearFrameCount);
    gSceneRunState->mUnk_10c = 2;
    do {
        PrepareDisplayFrame();
        func_020487fc_inline7();
        if (b->mUpdate != NULL) {
            b->mUpdate(a, gSceneRunState->mSceneFrames);
        }
        UpdateSounds();
        v = func_020487fc_inline8();
        func_020487fc_inline9(b);
        r = func_0204984c(a, gSceneRunState->mUnk_10c != 4);
        CallQueueDrain();
        if (r) {
            a->mNextScene = gSceneRunState->mNextScene;
            goto end;
        }
        if (b->mUnk_0c != NULL) {
            b->mUnk_0c(a, gSceneRunState->mSceneFrames);
        }
        UpdateWiFiSession();
        if (!func_020487fc_inline6()) {
            gSceneRunState->mSceneFrames++;
        }
        gSceneRunState->mPassCount++;
        RecordFrameTimes();
    } while (a->mNextScene == -1 && v == 0);
    gSceneRunState->mUnk_10c = 3;
    StopSceneSounds();
    if (data_021759d0->mSoundSetSeqPlaying) {
        if (a == NULL || func_0204a340(a->mScene, a->mNextScene)) {
            StopSceneSoundSetSeq();
        }
    }
    if ((v != 0 || GetNextSceneNumber() == 0) && ((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        func_02049e38(0);
    }
    if (data_021759d0->mUnk_20 == 4) {
        StartFadeToFadedPositive(b->mFadeToFadedFrameCount);
    } else {
        StartFadeToFadedNegative(b->mFadeToFadedFrameCount);
    }
    do {
        PrepareDisplayFrame();
        func_020487fc_inline7();
        if (b->mUpdate != NULL) {
            b->mUpdate(0, gSceneRunState->mSceneFrames);
        }
        UpdateSounds();
        func_020487fc_inline8();
        func_020487fc_inline9(b);
        func_0204984c(a, gSceneRunState->mUnk_10c != 4);
        CallQueueDrain();
        if (b->mUnk_0c != NULL) {
            b->mUnk_0c(0, gSceneRunState->mSceneFrames);
        }
        UpdateWiFiSession();
        if (!func_020487fc_inline6()) {
            gSceneRunState->mSceneFrames++;
        }
        gSceneRunState->mPassCount++;
        RecordFrameTimes();
    } while (!AreBrightnessFadesFaded());
end:
    func_02043ae0();
    if (func_020487fc_inline13() && (v != 0 || GetNextSceneNumber() == 0)) {
        gSceneRunState->mUnk_10c = 4;
        data_021759d0->mUnk_20 = 0;
        c = FALSE;
        func_0204f7f4();
        do {
            PrepareDisplayFrame();
            UpdateSounds();
            func_020487fc_inline8();
            func_020487fc_inline9(b);
            if (func_02054f58() == 1) {
                if (!func_020487fc_inline14()) {
                    c = TRUE;
                }
            }
            func_0204984c(a, gSceneRunState->mUnk_10c != 4);
            CallQueueDrain();
            UpdateWiFiSession();
            RecordFrameTimes();
        } while (!c);
    }
    gSceneRunState->mUnk_10c = 5;
    gDisplaySettings->mIrqCallback = NULL;
    if (func_020487fc_inline2()) {
        data_0217aa00->mUnk_0454 &= ~4;
    }
    StartDataSharingSync();
    func_02055340();
    if (b->mRelease != NULL) {
        b->mRelease(a);
    }
    CARD_SetPulledOutCallback(func_0204a548);
    if (gDisplaySettings != NULL) {
        DisableAllBanksAndNullDisplaySettings();
    }
    func_02043b3c();
    ClearFontAndPlayerCharacterTables();
    ClearLcdcBankAndStartWvrAndWait();
    StopSceneSoundsAtOnce();
    if (data_021759d0->mSoundSetPlayerInitialized && func_0204a340(a->mScene, a->mNextScene)) {
        ReleaseSceneSoundSetPlayer();
    }
    ReleaseArchiveSlots();
    if (v != 0) {
        a->mNextScene = 0;
    } else {
        w = gSceneRunState->mUnk_118;
        if (w != -1) {
            switch (w) {
                case 4:
                case 5:
                case 6:
                    a->mNextScene = gSceneRunState->mNextScene;
                    break;
                default:
                    a->mNextScene = 0;
                    break;
            }
        }
    }
    func_0204ad24();
    gSceneRunState->mSceneFrames = 0;
    gSceneRunState->mUnk_10c = 6;
}
