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

void UpdateRaceScene(Unk0203a0dc *a, u32 b) {
    RaceSetup *q;
    u32 c;
    if (func_02049b6c() == 0) {
        if (func_0204359c() == 0) {
            if (a != NULL) {
                if (func_0203a8f4() == 5) {
                    c = func_0205bba8();
                } else {
                    c = func_020b2e34();
                }
                if (c != 0) {
                    func_0203a8e0(c);
                    SetNextSceneFromPickedValue(a, c);
                }
                switch (GetCurrentRaceKind()) {
                    case RACE_KIND_DEMO:
                        c = 0;
                        if (b > func_0210f72c()) {
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
                            a->mNextScene = 0;
                        }
                        break;
                    case RACE_KIND_START_GP:
                    case 4:
                        if (IsCameraChainEnded() != 0 || (b > 0x5a && (GetDownBits(func_0203a4cc(), 0xc0f) != 0 ||
                                                                       func_0203a3cc(func_0203a4cc()) != 0))) {
                            a->mNextScene = 2;
                            SetNextRaceKind(0);
                        }
                        break;
                    case 2:
                        switch (func_0203a8f4()) {
                            case MODE_GRAND_PRIX:
                            case MODE_TIME_ATTACK:
                                if (func_0203c0bc() != 0) {
                                    a->mNextScene = 2;
                                }
                                break;
                        }
                        break;
                    case RACE_KIND_AWARD:
                        if (ShouldEndAwardRace(b) != 0) {
                            a->mNextScene = 0xa;
                        }
                        break;
                    case RACE_KIND_STAFF_ROLL:
                        c = 0x2a5a;
                        if (func_0203a3a4() == COURSE_ID_STAFFROLLTRUE) {
                            c = 0x2b02;
                        }
                        if (b > c) {
                            a->mNextScene = 0xf;
                            break;
                        }
                        if (ShouldEndStaffRoll(b) != 0) {
                            func_ov001_0219e0c4();
                            a->mNextScene = 0xf;
                        }
                        break;
                }
            }
            if (ShouldUpdateRace(b) != 0) {
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
                func_020b2574();
                break;
        }
        if (func_020b2ec0() != 0) {
            func_020435d4(1);
        } else {
            func_020435d4(0);
        }
    }
    q = gRaceSetup;
    if (q->mRaceKind != RACE_KIND_STAFF_ROLL) {
        c = 1;
    } else {
        if (b < 0x708) {
            c = 0;
        } else {
            c = 1;
        }
    }
    if (c != 0) {
        if (q->mMode != 5 || func_02037a20() == 0) {
            DrawRace();
        }
    }
    func_020ae824();
    func_020b255c();
}

void func_0203a05c(void) {
    data_021759d0->mUnk_54 = FALSE;
    if (gRaceSetup->mRaceKind == RACE_KIND_NORMAL) {
        func_020b2e64(1);
    }
    func_02046e84();
    while ((u32) data_0217c7ac != 0) {
        PrepareDisplayFrame();
        func_020b2574();
        UpdateSounds();
        FinishDisplayFrame();
        func_020b255c();
        RecordFrameTimes();
    }
}

void func_0203a050(void) {
    func_02046e24();
}

u32 RunRaceScene(SceneNumbers *a) {
    SceneCallbacks b = gRaceSceneCallbacks;
    SetCurrentRaceFromNext();
    if (gRaceSetup->mMode == 5) {
        b.mUnk_1c = 1;
    }
    if (gRaceSetup->mRaceKind != RACE_KIND_AWARD) {
        if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
            b.mUnk_18 = 1;
            b.mUnk_1a = 0x78;
        }
    } else {
        b.mUnk_18 = 0x3c;
        b.mUnk_1a = 0x78;
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        func_02043f28(1);
    }
    RunScene(a, &b);
    return 0;
}

void InitMenuScene(void) {
    func_020cbb10();
}

void ReleaseMenuScene(void) {
    func_020cb9b8();
    data_021759d0->mUnk_50 &= ~1;
    ResetTimeAttackNextEntries();
}

void func_02039f50(void) {
    func_020cc36c();
}

void UpdateMenuScene(void) {
    func_020cb51c();
    func_020cb4c0();
}

u32 RunMenuScene(SceneNumbers *a) {
    SceneCallbacks b = gMenuSceneCallbacks;
    RunScene(a, &b);
    return 0;
}

u32 func_02039e08(NNSiFndHeapHead *a, void **b, void **c, void **d, void **e, void **f) {
    u32 r;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        *b = CreateFrmHeapFromBack(a, 0x19000);
    } else {
        *b = CreateFrmHeapFromBack(a, 0x1b800);
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        *d = NULL;
        *e = NULL;
        *f = NULL;
    } else {
        *d = CreateFrmHeapFromFront(a, 0x19000);
        *e = CreateFrmHeapFromFront(a, 0x4b000);
        *f = CreateFrmHeapFromFront(a, 0x1b800);
    }
    r = GetSndInitBufferSize(((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2 ? 2 : 0);
    *c = HeapAlloc(a, r);
    NNS_FndGetTotalFreeSizeForExpHeap(a);
    return r;
}
