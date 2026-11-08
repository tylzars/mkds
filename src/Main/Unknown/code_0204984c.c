#include "Main/Unknown/code_0204984c.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_020487fc.h"
#include "Main/Unknown/code_0200f000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02039000.h"
#include "Main/Unknown/code_02054f58.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_0211f6cc.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_02108c1c.h"
#include "Main/Unknown/code_0212b0b8.h"
#include "Main/Unknown/code_0212a910.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_021200a8.h"
#include "Main/Unknown/code_02000000.h"
#include "Main/Unknown/code_0204aa60.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "00/code_02180600.h"
#include "00/code_02180608.h"
#include "00/code_021832d8.h"
#include "01/code_0219e0a8.h"
#include "01/code_021956dc.h"
#include "os_thread.h"
#include "pm.h"
#include "gx.h"
#include "Main/Unknown/code_02039230.h"
#include "registers.h"

#pragma opt_rebuildconditionals off

static inline u32 func_0204984c_inline(void) {
    if (data_0217aa00 == NULL) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

static inline s32 func_0204984c_inline2(void) {
    BOOL r = FALSE;
    if (func_0204984c_inline() != 0 && data_0217aa00->mUnk_0004 != 13) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_0204984c_inline3(void) {
    BOOL r = FALSE;
    if (func_0204984c_inline2() && !(data_0217aa00->mUnk_0454 & 0x80)) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_0204984c_inline4(void) {
    BOOL r = FALSE;
    if (func_0204984c_inline3() && (data_0217aa00->mUnk_0454 & 0x10)) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_0204984c_inline5(void) {
    BOOL r = FALSE;
    if (data_0217aa14 != NULL && (data_0217aa14->mUnk_75c & 0x10)) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_0204984c_inline6(void) {
    BOOL r = FALSE;
    if (gWiFiSession != NULL && gWiFiSession->mHeapCreated != FALSE) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_0204984c_inline7(void) {
    if (data_021759d4->mBackupEnabled) {
        return data_021759d4->mCommandRunning;
    }
    return 0;
}

static inline s32 func_0204984c_inline8(void) {
    if (!data_0217aa08->mUnk_28) {
        return func_0204984c_inline7();
    }
    return 1;
}

static inline s32 func_0204984c_inline9(void) {
    BOOL r = FALSE;
    if (func_0204984c_inline3() && data_0217aa00->mUnk_0008 != 9) {
        r = TRUE;
    }
    return r;
}

static inline void func_02049c3c_inline(OSThreadQueue *q) {
    q->mHead = q->mTail = NULL;
}

static inline void func_02049c3c_inline2(PMSleepCallbackInfo *p, void (*f)(void *)) {
    p->mCallback = f;
    p->mArg = NULL;
}

static inline void func_02049e38_inline(SceneNumbers *a) {
    if (a == 0 || func_0204a340(a->mScene, a->mNextScene)) {
        func_0204ac10();
    }
}

s16 GetSceneFadeToClearFrameCount(void) {
    if (gSceneRunState->mUnk_10c == 6) {
        return -1;
    }
    return gSceneRunState->mSceneCallbacks.mFadeToClearFrameCount;
}

u32 GetSceneFadeToFadedFrameCount(void) {
    if (gSceneRunState->mUnk_10c == 6) {
        return -1;
    }
    return gSceneRunState->mSceneCallbacks.mFadeToFadedFrameCount;
}

void func_0204a4d8(void) {
    func_02120150();
}

s32 func_0204a428(s32 a, s32 *b) {
    BOOL r = FALSE;

    switch (a) {
        case 11:
            *b = 4;
            r = TRUE;
            break;
        case 0:
            *b = 0;
            r = TRUE;
            break;
        case 7:
            *b = 4;
            r = TRUE;
            break;
        case 2:
            if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
                if (gRaceSetup->mCourseId != COURSE_ID_STAFFROLL) {
                    if (gRaceSetup->mCourseId == COURSE_ID_STAFFROLLTRUE) {
                        *b = 0x46;
                    }
                } else {
                    *b = 0x45;
                }
                r = TRUE;
            }
            break;
    }
    return r;
}

s32 func_0204a340(s32 a, s32 b) {
    BOOL r = TRUE;

    switch (a) {
        case 0:
            if (b == 2) {
                r = FALSE;
            }
            break;
        case 11:
            if (b == 14) {
                r = FALSE;
            }
            break;
        case 14:
            if (b == 3 || b == 7) {
                r = FALSE;
            }
            break;
        case 7:
            if (b == 3 || b == 14) {
                r = FALSE;
            }
            break;
        case 3:
            if (b == 7) {
                r = FALSE;
            }
            break;
        case 2:
            if (b != 0) {
                if (b == 15) {
                    if (func_ov001_0219e0b8()) {
                        func_0204ab64(0x78);
                    }
                    r = FALSE;
                }
            } else {
                r = FALSE;
            }
            break;
    }
    return r;
}

void func_0204a1a8(void *a) {
    s32 d;
    BOOL b;
    BOOL c;

    while (1) {
        b = FALSE;
        c = FALSE;
        OS_SleepThread(&gSceneRunState->mThreadQueue);
        gSceneRunState->mNextScene = 0;
        func_0212b144();
        if (gDisplaySettings != NULL) {
            c = TRUE;
        }
        func_02039478();
        func_0203940c();
        VBlankIntrWait();
        if (func_0204984c_inline6()) {
            b = TRUE;
        }
        func_0212ad28(gSceneRunState->mUnk_118, gSceneRunState->mUnk_11c);
        StopAllSeqPlayers();
        if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
            func_02108d00();
        } else {
            func_02108c80();
        }
        if (b != FALSE) {
            switch (gSceneRunState->mUnk_118) {
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                    func_0211fd28();
                    break;
            }
        }
        do {
            if (c != FALSE) {
                PrepareDisplayFrame();
            }
            d = b == FALSE ? func_02054f58() == 1 : 1;
            UpdateSounds();
            VBlankIntrWait();
            if (c != FALSE) {
                RecordFrameTimes();
            }
        } while (d == 0);
        do {
            if (c != FALSE) {
                PrepareDisplayFrame();
            }
            func_0203940c();
            d = func_0212b0b8();
            UpdateSounds();
            VBlankIntrWait();
            if (c != FALSE) {
                RecordFrameTimes();
            }
        } while (d == -1);
        switch (d) {
            case 1:
                gSceneRunState->mNextScene = 12;
                break;
            default:
                gSceneRunState->mNextScene = 0;
                break;
        }
    }
}

void func_02049f60(void) {
    s32 g;
    BOOL a;
    BOOL b;
    BOOL d;
    BOOL e;
    s32 f;

    a = FALSE;
    b = FALSE;
    gSceneRunState->mNextScene = 0;
    func_0212b144();
    if (gDisplaySettings != NULL) {
        b = TRUE;
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        func_0212ad28(gSceneRunState->mUnk_118, gSceneRunState->mUnk_11c);
    }
    func_02039478();
    func_0203940c();
    VBlankIntrWait();
    if (func_0204984c_inline6()) {
        a = TRUE;
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
        func_0212ad28(gSceneRunState->mUnk_118, gSceneRunState->mUnk_11c);
    }
    StopAllSeqPlayers();
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        func_02108d00();
    } else {
        func_02108c80();
    }
    PM_DeletePreSleepCallback(&gSceneRunState->mPreSleepCallback);
    PM_DeletePostSleepCallback(&gSceneRunState->mPostSleepCallback);
    PM_SetLCDPower(1);
    if (a != FALSE) {
        switch (gSceneRunState->mUnk_118) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                func_0211fd28();
                break;
        }
    }
    d = b == FALSE;
    do {
        func_0203940c();
        if (d == FALSE) {
            PrepareDisplayFrame();
        }
        if (a == FALSE) {
            e = func_02054f58() == 1;
            f = e;
        } else {
            e = TRUE;
            f = gWiFiSession->mUnk_0008.mState == 0;
        }
        if (f != 0 && ((*(vu16 *) 0x027fffa8 & 0x8000) >> 15)) {
            PM_GoSleepMode(12, 0, 0);
        }
        g = func_0212b0b8();
        UpdateSounds();
        VBlankIntrWait();
        if (b != FALSE) {
            RecordFrameTimes();
        }
    } while (e == FALSE || g == -1);
    switch (g) {
        case 1:
            gSceneRunState->mNextScene = 12;
            break;
        default:
            gSceneRunState->mNextScene = 0;
            break;
    }
}

void func_02049e38(s32 a) {
    BOOL b;
    BOOL c;

    c = FALSE;
    b = gDisplaySettings != NULL;
    switch (a) {
        case 0:
            if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2) {
                c = TRUE;
            }
            break;
        case 1:
        case 2:
            c = FALSE;
            break;
        case 4:
        case 5:
        case 6:
            c = TRUE;
            break;
        case 3:
            c = FALSE;
            break;
    }
    gSceneRunState->mUnk_118 = a;
    gSceneRunState->mUnk_11c = c;
    func_02049f60();
    StopSceneSounds();
    if (data_021759d0->mUnk_1c_0) {
        func_02049e38_inline(0);
    }
    if (b != FALSE) {
        SetBrightnessFadesClear();
        StartFadeToFadedNegative(10);
        do {
            PrepareDisplayFrame();
            UpdateSounds();
            FinishDisplayFrame();
            RecordFrameTimes();
        } while (AreBrightnessFadesFaded() == 0);
    } else {
        GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, 0x10);
    }
}

void ScenePreSleepCallback(void *a) {
    BOOL b;
    s32 c;
    BOOL d;

    do {
        PrepareDisplayFrame();
        b = func_02054f58() != 1;
        c = func_0204984c_inline8();
        if (b == FALSE && c == 0) {
            d = TRUE;
        } else {
            d = FALSE;
        }
        FinishDisplayFrame();
        RecordFrameTimes();
    } while (d == FALSE);
    if (gSceneRunState->mSceneCallbacks.mPreSleep != NULL) {
        gSceneRunState->mSceneCallbacks.mPreSleep();
    }
}

void ScenePostSleepCallback(void) {
    if (gSceneRunState->mSceneCallbacks.mPostSleep != NULL) {
        gSceneRunState->mSceneCallbacks.mPostSleep();
    }
}

void InitSceneRunState(void *a) {
    gSceneRunState = HeapAlloc(a, 0x124);
    gSceneRunState->mThreadStack = HeapAllocAligned(a, 0x400, 0x20);
    gSceneRunState->mUnk_10c = 6;
    gSceneRunState->mLcdOff = FALSE;
    gSceneRunState->mUnk_118 = -1;
    gSceneRunState->mUnk_11c = 0;
    func_02049c3c_inline(&gSceneRunState->mThreadQueue);
    OS_CreateThread(&gSceneRunState->mThread, (void (*)(void *)) func_0204a1a8, NULL,
                    (u8 *) gSceneRunState->mThreadStack + 0x400, 0x400, 15);
    OS_WakeupThreadDirect(&gSceneRunState->mThread);
    func_02049c3c_inline2(&gSceneRunState->mPreSleepCallback, ScenePreSleepCallback);
    func_02049c3c_inline2(&gSceneRunState->mPostSleepCallback, (void (*)(void *)) ScenePostSleepCallback);
    PM_AppendPreSleepCallback(&gSceneRunState->mPreSleepCallback);
    PM_AppendPostSleepCallback(&gSceneRunState->mPostSleepCallback);
}

u32 func_02049b6c(void) {
    u32 r = 0;

    if (gRaceSetup->mMode == 5 && func_0204984c_inline5()) {
        r = 1;
    }
    if (func_0204984c_inline4()) {
        r = 1;
    }
    return r;
}

BOOL ShouldGoSleepMode(void) {
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2 || func_0204984c_inline2() ||
        (GetCurrentSceneNumber() == 12 && func_ov000_02180600() == FALSE) ||
        (GetCurrentSceneNumber() != 12 && gWiFiSession->mUnk_0008.mState != 0) || GetCurrentSceneNumber() == 13 ||
        GetCurrentSceneNumber() == 6) {
        return FALSE;
    }
    return TRUE;
}

u32 func_0204998c(void) {
    s32 v;

    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2 || func_0204984c_inline2() || GetCurrentSceneNumber() == 6 ||
        GetCurrentSceneNumber() == 13 || (GetCurrentSceneNumber() == 12 && func_ov000_02180608() == FALSE) ||
        (GetCurrentSceneNumber() != 12 && gWiFiSession->mUnk_0008.mState != 0)) {
        return 1;
    }
    switch (GetCurrentSceneNumber()) {
        case 9:
        case 15:
            return 1;
        case 2:
            if (gRaceSetup->mRaceKind == RACE_KIND_STAFF_ROLL) {
                return 1;
            }
            break;
    }
    return 0;
}

void func_02049980(s32 a) {
    func_02049e38(a);
}

s32 func_0204984c(SceneNumbers *a, s32 b) {
    BOOL r;
    s32 v;

    r = FALSE;
    if (func_0204984c_inline6()) {
        v = func_02120644();
        if (b != 0 && v != 0) {
            switch (v) {
                case 1:
                    v = 5;
                    break;
                case 2:
                    v = 6;
                    break;
                case 3:
                default:
                    v = 4;
                    break;
            }
            func_02049e38(v);
            r = TRUE;
        }
    } else if (b != 0 && func_0204984c_inline9()) {
        func_02049e38(0);
        r = TRUE;
        data_0217aa00->mUnk_0008 = 9;
    } else {
        func_02055340();
    }
    return r;
}
