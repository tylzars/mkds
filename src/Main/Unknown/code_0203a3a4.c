#include "Main/Unknown/code_0203a3a4.h"

#include "Main/Unknown/code_02039e08.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_02045874.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02029aa0.h"
#include "Main/Unknown/code_0204673c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_021832d8.h"
#include "01/code_021956dc.h"
#include "os_printf.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Unknown/code_02039000.h"
#include "Main/Unknown/code_020431e4.h"
#include "Main/Unknown/code_020435c4.h"
#include "Main/Unknown/code_02046000.h"
#include "Main/Unknown/code_020467d0.h"
#include "Main/Unknown/code_02046c10.h"
#include "code_020176b0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02039774.h"
#include "Main/Unknown/code_0204a550.h"
#include "Main/Unknown/code_02053e54.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_02056d40.h"
#include "Main/Unknown/code_02056d54.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_02059bc0.h"
#include "Main/Unknown/code_02060004.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020af66c.h"
#include "Main/Unknown/code_020b03bc.h"
#include "Main/Unknown/code_020b1de4.h"
#include "Main/Unknown/code_020b2e34.h"
#include "Main/Unknown/unk_02164000.h"
#include "code_021458c4.h"
#include "Main/Unknown/code_02046740.h"
#include "registers.h"

static inline u32 func_0203a908_inline(void) {
    InputSlotIndex slotIndex = UNK_02175628_INDEX_8;
    u32 result = 1;
    u32 briefNoPair = 0;
    u16 hasPair = data_02175628[slotIndex].mHasPair;
    if (hasPair == 0 && data_02175628[slotIndex].mNoPairCount < 5) {
        briefNoPair = 1;
    }
    if (briefNoPair == 0 && hasPair == 0) {
        result = 0;
    }
    return result;
}

BOOL TryFormatGhostPath(u32 courseId, void *buffer, u32 size) {
    int cupCourseIndex = FindCupCourseIndex(courseId);
    if (cupCourseIndex == -1) {
        return FALSE;
    }
    OS_SNPrintf(buffer, size, gGhostPathFormat, cupCourseIndex & 0xff);
    return TRUE;
}

static inline u32 func_0203a9ec_inline(void) {
    u8 i;
    u8 j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
            if (IsGrandPrixRecordFilled(i, j) != 0) {
                return 1;
            }
        }
    }
    return 0;
}

// The staff roll waits 0x708 frames before the race runs.
u32 ShouldUpdateRace(u32 sceneFrames) {
    if (gRaceSetup->mRaceKind != RACE_KIND_STAFF_ROLL) {
        return 1;
    }
    return sceneFrames >= 0x708;
}

void SetupRaceDisplay(void *heap) {
    DisplaySettings *settings;
    settings = CreateDisplaySettings(heap, gRaceDisplaySettingsDescs[gRaceSetup->mRaceKind]);
    SetG3xSwapBits(settings, 1, 1);
    SetBg0Record(&settings->mMainBg0, 1, 0, 0, 1, 0, 0, 0);
    switch (gRaceSetup->mRaceKind) {
        case RACE_KIND_NORMAL:
        case 2:
        case RACE_KIND_STAFF_ROLL:
            SetBg2RecordParams(&settings->mMainBg0, 1, 0, 0, 0, 7, 0);
            SetBg0Record(&settings->mSubBg0, 0, 0, 0, 0, 0xd, 0, 0);
            SetBg1Record(&settings->mSubBg0, 1, 0, 0, 0, 0xe, 0, 0);
            SetBg2RecordParams(&settings->mSubBg0, 2, 0, 0, 0, 0xf, 0);
            SetDispCapMode(0);
            break;
        case RACE_KIND_DEMO:
            SetBg2RecordParams(&settings->mMainBg0, 1, 0, 0, 0, 7, 0);
            SetBg0Record(&settings->mSubBg0, 0, 0, 0, 0, 0xd, 0, 0);
            SetBg1Record(&settings->mSubBg0, 1, 0, 0, 0, 0xe, 0, 0);
            SetBg2RecordParams(&settings->mSubBg0, 2, 0, 0, 0, 0xf, 0);
            SetDispCapMode(0);
            break;
        case RACE_KIND_START_GP:
        case RACE_KIND_AWARD:
            SetBg2RecordParams(&settings->mMainBg0, 1, 0, 0, 0, 7, 0);
            SetBg2RecordMode5(&settings->mSubBg0, 0, 0, 1, 0, 0);
            func_02038c94(settings, 0x20);
            SetDispCapMode(1);
            break;
        case 4:
            SetBg2RecordParams(&settings->mMainBg0, 1, 0, 0, 0, 7, 0);
            SetDispCapMode(0);
            break;
    }
    InitDisplayFromSettings(settings);
    SetupDispCap();
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 2;
}

void InitRaceScene(void) {
    void *p;
    s32 mirrorMode;
    WiFiSession *session;
    BOOL sessionHeapCreated;
    p = GetHeap(GetCurrentHeapCall());
    CreateOverlayExpHeap();
    if (gRaceSetup->mRaceKind == RACE_KIND_START_GP || gRaceSetup->mRaceKind == RACE_KIND_AWARD) {
        StopWvrAndWait();
    } else {
        ClearLcdcBankAndStartWvrAndWait();
        func_02053e74();
    }
    Init3dEngine();
    SetHeapGroupId(7);
    InitDispCap(p);
    SetupRaceDisplay(p);
    func_020431e4();
    SetHeapGroupId(9);
    InitRace();
    SetHeapGroupId(5);
    InitChoisesS();
    func_020b03bc();
    if (gRaceSetup->mRaceKind != RACE_KIND_START_GP) {
        func_020af99c();
    }
    SetHeapGroupId(8);
    mirrorMode = gRaceSetup->mMirrorMode;
    if (mirrorMode == 0 && gRaceSetup->mMode == MODE_MISSION_RUN) {
        if ((gRaceSetup->mUnk_044 & 0x10) != 0) {
            mirrorMode = 1;
        }
    }
    SetLeftRightKeysSwapped(mirrorMode);
    SetHeapGroupId(9);
    if (gRaceSetup->mMode != MODE_BATTLE) {
        if (gRaceSetup->mMode == 5) {
            sessionHeapCreated = FALSE;
            session = gWiFiSession;
            if (session != NULL) {
                if (session->mHeapCreated != FALSE) {
                    sessionHeapCreated = TRUE;
                }
            }
            if (sessionHeapCreated != FALSE) {
                StateMachine *p;
                session->mUnk_1f38 = TRUE;
                p = &gWiFiSession->mUnk_0008;
                p->mNextState = 5;
                p->mNextStateRequested = 1;
            }
        }
    } else {
        if (gRaceSetup->mBattleKind == BATTLE_KIND_BALLOON) {
            StartMicInput(GetHeap(GetCurrentHeapCall()));
        }
    }
}

void func_0203aacc(void) {
    RaceSetup *p;
    WiFiSession *session;
    s32 flagIndex;
    BOOL sessionHeapCreated;
    if (gRaceSetup->mMode == 5) {
        sessionHeapCreated = FALSE;
        session = gWiFiSession;
        if (session != NULL) {
            if (session->mHeapCreated != FALSE) {
                sessionHeapCreated = TRUE;
            }
        }
        if (sessionHeapCreated != FALSE) {
            StateMachine *p;
            session->mUnk_1f38 = FALSE;
            p = &gWiFiSession->mUnk_0008;
            p->mNextState = 4;
            p->mNextStateRequested = 1;
        }
    }
    p = gRaceSetup;
    if (p->mRaceKind == RACE_KIND_STAFF_ROLL) {
        flagIndex = 0x18;
        if (p->mMode != MODE_GRAND_PRIX) {
            if (p->mMode == MODE_MISSION_RUN) {
                flagIndex = 0x1a;
            }
        } else {
            if (p->mCourseId == COURSE_ID_STAFFROLLTRUE) {
                flagIndex = 0x19;
            }
        }
        if (IsBackupFlagSet(flagIndex) == 0) {
            SetBackupFlag(flagIndex);
            func_02056d40();
            WaitThreadFunctionsDone();
            if (gBackupAccess->mBackupEnabled != 0) {
                CARD_WaitBackupAsync();
            }
        }
    }
    StopMicInput();
    ClearChoisesSPointer();
    func_02062004();
    func_020af86c();
    ClearDispCapPointer();
    func_02053e54();
    FreeOverlayExpHeap();
}

void func_0203aaa8(void) {
    AdvanceDispCap(GetChoisesSPrevOpenDuringRace());
    func_02062000();
    func_020b0b8c();
}

// The award scene ends after 0x564 frames, or on a new key press once some Grand Prix record is filled.
u32 ShouldEndAwardRace(u32 sceneFrames) {
    if (sceneFrames > 0x564) {
        return 1;
    }
    if (AreBrightnessFadesClear() == 0) {
        return 0;
    }
    if (func_0203a9ec_inline() != 0) {
        InputSlotIndex slotIndex = UNK_02175628_INDEX_8;
        if ((u16) (data_02175628[slotIndex].mPressedBits & PAD_KEY_A) != 0) {
            return 1;
        }
    }
    return 0;
}

// The staff roll can end early on input after 0xb4 frames when its flag for the mode is set.
u32 ShouldEndStaffRoll(u32 sceneFrames) {
    u32 result;
    s32 flagIndex = 0x18;
    if (gRaceSetup->mMode != MODE_GRAND_PRIX) {
        if (gRaceSetup->mMode == MODE_MISSION_RUN) {
            flagIndex = 0x1a;
        }
    } else {
        if (gRaceSetup->mCourseId == COURSE_ID_STAFFROLLTRUE) {
            flagIndex = 0x19;
        }
    }
    result = 0;
    if (IsBackupFlagSet(flagIndex) != 0 && sceneFrames > 0xb4) {
        InputSlotIndex slotIndex = UNK_02175628_INDEX_8;
        if ((u16) (data_02175628[slotIndex].mBits & 0xc0f) != 0 || func_0203a908_inline() != 0) {
            result = 1;
        }
    }
    return result;
}

u32 func_0203a8f4(void) {
    return (gRaceSetup->mMode);
}

void func_0203a8e0(u32 pickedValue) {
    data_021759d0->mUnk_44 = pickedValue;
}

// Turns the value picked on the choice screen into the next scene and the settings that go with it.
void SetNextSceneFromPickedValue(Unk0203a0dc *sceneNumbers, u32 pickedValue) {
    s32 nextScene;
    data_0217b488->mUnk_08 = 0;
    nextScene = -1;
    switch (pickedValue) {
        case 10:
            SetupStaffRollRace(0);
            nextScene = 2;
            break;
        case 9:
            if (gRaceSetup->mMode != 5) {
                u32 t;
                u32 f;
                ConnectionWork *q;
                f = 0;
                q = data_0217aa00;
                if (q == NULL) {
                    t = 0;
                } else {
                    t = q->mUnk_0000;
                }
                if (t != 0) {
                    if (q->mUnk_0004 != 0xd) {
                        f = 1;
                    }
                }
                if (f != 0) {
                    if (data_021759d0->mUnk_1c_2 != 0) {
                        nextScene = 6;
                        data_0217b488->mUnk_74 = 3;
                    } else {
                        nextScene = 1;
                    }
                    data_0217b488->mUnk_08 = 4;
                    data_0217b488->mUnk_04 = 1;
                } else {
                    nextScene = 0;
                }
                if (gRaceSetup->mMode == MODE_TIME_ATTACK) {
                    func_0204673c();
                }
            } else {
                nextScene = 0xc;
                data_0217b488->mUnk_1c = 0;
            }
            break;
        case 1:
        case 3:
            nextScene = 2;
            gRaceSetup->mNextHeader.mRaceKind = RACE_KIND_NORMAL;
            break;
        case 8:
            nextScene = 2;
            gRaceSetup->mNextHeader.mRaceKind = nextScene;
            break;
        case 2:
            switch (gRaceSetup->mMode) {
                case MODE_GRAND_PRIX:
                    SetNextGrandPrixCourse();
                    nextScene = 2;
                    break;
                case MODE_VS:
                    if (func_02045914() != 0) {
                        if (data_021759d0->mUnk_1c_2 == 0) {
                            nextScene = 2;
                        } else {
                            nextScene = 6;
                            data_0217b488->mUnk_74 = 1;
                        }
                    } else {
                        if (gRaceSetup->mCourseListMode == 0) {
                            data_0217b488->mUnk_08 = 2;
                        }
                        if (data_021759d0->mUnk_1c_2 == 0) {
                            nextScene = 1;
                        } else {
                            nextScene = 6;
                            data_0217b488->mUnk_74 = 3;
                        }
                    }
                    break;
                case 5:
                    if (func_02045874() != FALSE) {
                        nextScene = 0xc;
                        data_0217b488->mUnk_1c = 3;
                    } else {
                        nextScene = 0xa;
                        data_0217b488->mUnk_1c = 2;
                    }
                    break;
                case MODE_BATTLE:
                    if (func_020458cc() != 0) {
                        if (data_021759d0->mUnk_1c_2 == 0) {
                            nextScene = 2;
                        } else {
                            nextScene = 6;
                            data_0217b488->mUnk_74 = 1;
                        }
                    } else {
                        if (gRaceSetup->mCourseListMode == 0) {
                            data_0217b488->mUnk_08 = 2;
                        }
                        if (data_021759d0->mUnk_1c_2 == 0) {
                            nextScene = 1;
                        } else {
                            nextScene = 6;
                            data_0217b488->mUnk_74 = 3;
                        }
                    }
                    break;
            }
            break;
        case 7:
            switch (gRaceSetup->mMode) {
                case MODE_GRAND_PRIX:
                    if (func_02045bd4() != FALSE) {
                        nextScene = 2;
                    } else {
                        nextScene = 0xa;
                    }
                    break;
                case MODE_MISSION_RUN:
                    nextScene = 0;
                    break;
                case MODE_BATTLE:
                case MODE_VS:
                    if (data_021759d0->mUnk_1c_2 != 0) {
                        nextScene = 6;
                        data_0217b488->mUnk_74 = 2;
                    } else {
                        nextScene = 0xa;
                    }
                    break;
            }
            break;
        case 5:
            nextScene = 1;
            data_0217b488->mUnk_08 = nextScene;
            break;
        case 4:
            data_0217b488->mUnk_08 = 2;
            nextScene = 1;
            break;
        case 6:
            data_0217b488->mUnk_08 = 3;
            nextScene = 1;
            break;
    }
    if (nextScene != -1) {
        sceneNumbers->mNextScene = nextScene;
    }
}

u32 GetCurrentRaceKind(void) {
    return gRaceSetup->mRaceKind;
}

void func_0203a4d4(u32 a) {
    if (a != 0) {
        data_021759d0->mUnk_50 |= 1;
    } else {
        data_021759d0->mUnk_50 &= ~1;
    }
}

u32 func_0203a4cc(void) {
    return 0x8u;
}

u16 GetDownBits(u32 slotIndex, u32 mask) {
    u32 bits;
    bits = data_02175628[slotIndex].mBits;
    return bits & mask;
}

u32 func_0203a48c(u32 index) {
    u32 value0 = index;
    u32 value1;
    u32 value2;
    u32 value12;
    value12 = (u32) &NNS_SndArcPlayerStartSeqArc;
    value2 = value0;
    value0 = (u32) &data_0217d068;
    value1 = 0u;
    value0 = NNS_SndArcPlayerStartSeqArc((const void *) value0, value1, value2);
    return value0;
}

u32 func_0203a440(u32 slotIndex) {
    u32 result;
    u32 briefNoPair;
    u16 hasPair;
    result = 1;
    briefNoPair = 0;
    hasPair = data_02175628[slotIndex].mHasPair;
    if (hasPair == 0 && data_02175628[slotIndex].mNoPairCount < 5) {
        briefNoPair = 1;
    }
    if (briefNoPair == 0 && hasPair == 0) {
        result = 0;
    }
    return result;
}

u32 IsCameraChainEnded(void) {
    return gRaceProgress->mCameraChainEnded;
}

u32 func_0203a3cc(u32 slotIndex) {
    u32 result;
    u32 briefNoPair;
    result = 0;
    briefNoPair = 0;
    if (data_02175628[slotIndex].mHasPair == 0 && data_02175628[slotIndex].mNoPairCount < 5) {
        briefNoPair = 1;
    }
    if (briefNoPair == 0 && data_02175628[slotIndex].mPrevHasPair == 0 && data_02175628[slotIndex].mHasPair != 0) {
        result = 1;
    }
    return result;
}

void SetNextRaceKind(u32 raceKind) {
    gRaceSetup->mNextHeader.mRaceKind = raceKind;
}

u32 func_0203a3a4(void) {
    return (gRaceSetup->mCourseId);
}
