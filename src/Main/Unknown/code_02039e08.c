#include "Main/Unknown/code_02039e08.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02039774.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/code_020487fc.h"
#include "Main/Unknown/code_0204984c.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02045874.h"
#include "Main/Unknown/code_0203a3a4.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_0204673c.h"
#include "Main/Unknown/code_020435c4.h"
#include "Main/Unknown/code_02046c10.h"
#include "Main/Unknown/code_02049000.h"
#include "Main/Unknown/code_020431e4.h"
#include "Main/Unknown/code_0205b0f4.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020ae824.h"
#include "Main/Unknown/code_020aeb7c.h"
#include "Main/Unknown/code_020af66c.h"
#include "Main/Unknown/code_020b2574.h"
#include "Main/Unknown/code_020b255c.h"
#include "Main/Unknown/code_020b2e34.h"
#include "Main/Unknown/code_020b2ec0.h"
#include "Main/Unknown/code_020cb4c0.h"
#include "Main/Unknown/code_020cb9b8.h"
#include "Main/Unknown/code_020cbad0.h"
#include "Main/Unknown/code_020cc168.h"
#include "Main/Unknown/code_0210f72c.h"
#include "Main/Unknown/code_0210f744.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "01/code_0219e0a8.h"
#include "code_020176c0.h"
#include "Main/Unknown/code_02044618.h"

void UpdateRaceScene(Unk0203a0dc *sceneNumbers, u32 sceneFrames) {
    RaceSetup *raceSetup;
    u32 c;
    if (func_02049b6c() == 0) {
        if (func_0204359c() == 0) {
            if (sceneNumbers != NULL) {
                if (func_0203a8f4() == 5) {
                    c = func_0205bba8();
                } else {
                    c = func_020b2e34();
                }
                if (c != 0) {
                    func_0203a8e0(c);
                    SetNextSceneFromPickedValue(sceneNumbers, c);
                }
                switch (GetCurrentRaceKind()) {
                    case RACE_KIND_DEMO:
                        c = 0;
                        if (sceneFrames > func_0210f72c()) {
                            if (IsSeqVariableChanged(1) != 0) {
                                c = 1;
                                func_0203a4d4(0);
                            }
                        }
                        if (c == 0) {
                            if (GetDownBits(func_0203a4cc(), 0x2fff) != 0) {
                                c = 1;
                                func_0203a48c(5);
                                func_0203a4d4(1);
                            } else if (func_0203a440(func_0203a4cc()) != 0) {
                                c = 1;
                                func_0203a48c(5);
                                func_0203a4d4(1);
                            }
                        }
                        if (c != 0) {
                            sceneNumbers->mNextScene = 0;
                        }
                        break;
                    case RACE_KIND_START_GP:
                    case 4:
                        if (IsCameraChainEnded() != 0 ||
                            (sceneFrames > 0x5a &&
                             (GetDownBits(func_0203a4cc(), 0xc0f) != 0 || func_0203a3cc(func_0203a4cc()) != 0))) {
                            sceneNumbers->mNextScene = 2;
                            SetNextRaceKind(0);
                        }
                        break;
                    case 2:
                        switch (func_0203a8f4()) {
                            case MODE_GRAND_PRIX:
                            case MODE_TIME_ATTACK:
                                if (func_0203c0bc() != 0) {
                                    sceneNumbers->mNextScene = 2;
                                }
                                break;
                        }
                        break;
                    case RACE_KIND_AWARD:
                        if (ShouldEndAwardRace(sceneFrames) != 0) {
                            sceneNumbers->mNextScene = 0xa;
                        }
                        break;
                    case RACE_KIND_STAFF_ROLL:
                        c = 0x2a5a;
                        if (func_0203a3a4() == COURSE_ID_STAFFROLLTRUE) {
                            c = 0x2b02;
                        }
                        if (sceneFrames > c) {
                            sceneNumbers->mNextScene = 0xf;
                            break;
                        }
                        if (ShouldEndStaffRoll(sceneFrames) != 0) {
                            func_ov001_0219e0c4();
                            sceneNumbers->mNextScene = 0xf;
                        }
                        break;
                }
            }
            if (ShouldUpdateRace(sceneFrames) != 0) {
                UpdateRace();
            }
            func_020af66c();
        }
        func_020aeb7c();
        switch (GetCurrentRaceKind()) {
            case RACE_KIND_NORMAL:
            case 2:
            case RACE_KIND_START_GP:
            case 4:
                UpdateChoisesS();
                break;
        }
        if (GetChoisesSOpenDuringRace() != 0) {
            SetInputOpenDuringRace(1);
        } else {
            SetInputOpenDuringRace(0);
        }
    }
    raceSetup = gRaceSetup;
    if (raceSetup->mRaceKind != RACE_KIND_STAFF_ROLL) {
        c = 1;
    } else {
        if (sceneFrames < 0x708) {
            c = 0;
        } else {
            c = 1;
        }
    }
    if (c != 0) {
        if (raceSetup->mMode != 5 || func_02037a20() == 0) {
            DrawRace();
        }
    }
    func_020ae824();
    func_020b255c();
}

void PreSleepRaceScene(void) {
    data_021759d0->mUnk_54 = FALSE;
    if (gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
        func_020b2e64(1);
    }
    func_02046e84();
    while ((u32) data_0217c7ac != 0) {
        PrepareDisplayFrame();
        UpdateChoisesS();
        UpdateSounds();
        FinishDisplayFrame();
        func_020b255c();
        RecordFrameTimes();
    }
}

void PostSleepRaceScene(void) {
    func_02046e24();
}

u32 RunRaceScene(SceneNumbers *sceneNumbers) {
    SceneCallbacks callbacks = gRaceSceneCallbacks;
    SetCurrentRaceFromNext();
    if (gRaceSetup->mMode == 5) {
        callbacks.mUnk_1c = 1;
    }
    if (gRaceSetup->mRaceKind != RACE_KIND_AWARD) {
        if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
            callbacks.mFadeToClearFrameCount = 1;
            callbacks.mFadeToFadedFrameCount = 0x78;
        }
    } else {
        callbacks.mFadeToClearFrameCount = 0x3c;
        callbacks.mFadeToFadedFrameCount = 0x78;
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        func_02043f28(1);
    }
    RunScene(sceneNumbers, &callbacks);
    return 0;
}

void InitMenuScene(void) {
    InitMenu();
}

void ReleaseMenuScene(void) {
    ReleaseMenu();
    data_021759d0->mUnk_50 &= ~1;
    ResetTimeAttackNextEntries();
}

void func_02039f50(void) {
    func_020cc36c();
}

void UpdateMenuScene(void) {
    UpdateMenuScreen();
    func_020cb4c0();
}

u32 RunMenuScene(SceneNumbers *sceneNumbers) {
    SceneCallbacks callbacks = gMenuSceneCallbacks;
    RunScene(sceneNumbers, &callbacks);
    return 0;
}

u32 func_02039e08(NNSiFndHeapHead *heap, void **outBackHeap, void **outSoundBuffer, void **outFirstFrontHeap,
                  void **outSecondFrontHeap, void **outThirdFrontHeap) {
    u32 soundBufferSize;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        *outBackHeap = CreateFrmHeapFromBack(heap, 0x19000);
    } else {
        *outBackHeap = CreateFrmHeapFromBack(heap, 0x1b800);
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        *outFirstFrontHeap = NULL;
        *outSecondFrontHeap = NULL;
        *outThirdFrontHeap = NULL;
    } else {
        *outFirstFrontHeap = CreateFrmHeapFromFront(heap, 0x19000);
        *outSecondFrontHeap = CreateFrmHeapFromFront(heap, 0x4b000);
        *outThirdFrontHeap = CreateFrmHeapFromFront(heap, 0x1b800);
    }
    soundBufferSize = GetSndInitBufferSize(((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2 ? 2 : 0);
    *outSoundBuffer = HeapAlloc(heap, soundBufferSize);
    NNS_FndGetTotalFreeSizeForExpHeap(heap);
    return soundBufferSize;
}
