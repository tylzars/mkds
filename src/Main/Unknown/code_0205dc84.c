#include "Main/Unknown/code_0205dc84.h"
#include "Main/Unknown/code_020365ac.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_02036588.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02001000.h"
#include "Main/Unknown/code_02039000.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_02105ec0.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_0212030c.h"
#include "Main/Unknown/code_02108ed8.h"
#include "Main/Unknown/code_02108ec4.h"
#include "03/code_021c2000.h"
#include "03/code_021c209c.h"
#include "00/code_021a3000.h"
#include "00/code_021a3760.h"
#include "01/code_021956dc.h"
#include "code_02004dc0.h"
#include "code_0200c914.h"
#include "Main/Unknown/code_0200f000.h"
#include "code_0200fc8c.h"
#include "code_02148950.h"
#include "gx.h"
#include "code_021458c4.h"
#include "Main/Unknown/unk_00000000.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "registers.h"

#pragma opt_loop_invariants off

static inline void func_0205dee0_inline(void *c, void *overlayId) {
    u8 languageIndex;
    u32 f;
    if (FS_LoadOverlay(0, (u32) overlayId) != 0) {
        OS_SetIrqFunction(1, NULL);
        OS_DisableIrqMask(1);
        reg_OS_IME;
        reg_OS_IME = 0;
        OS_DisableInterrupts();
        GX_VBlankIntr(0);
        func_ov000_021a397c(2);
        f = 1;
        languageIndex = data_021759d0->mLanguageIndex;
        if (languageIndex < 6) {
            f = data_02154904[languageIndex];
        }
        func_ov003_021c2494(c, f, 0x20);
        func_02036778();
        FS_UnloadOverlay(0, (u32) overlayId);
    }
}

void func_0205dee0(void) {
    void *expHeapFromMaxFree;
    void *c;
    void *a;
    a = GetHeap(GetCurrentHeapCall());
    WaitThreadFunctionsDone();
    if (gBackupAccess->mBackupEnabled != 0) {
        CARD_WaitBackupAsync();
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2 && gRunScenesState->mSndHeapsBuffer != NULL) {
        ReleaseSndHeaps();
        HeapFree(a, gRunScenesState->mSndHeapsBuffer);
        gRunScenesState->mSndHeapsBuffer = NULL;
    }
    func_02108ed8();
    expHeapFromMaxFree = CreateExpHeapFromMaxFree(a);
    c = HeapAllocAligned(expHeapFromMaxFree, 0x40000, 0x20);
    func_0205dee0_inline(c, SDK_OVERLAY_OV003_ID);
    HeapDestroy(expHeapFromMaxFree);
    GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, 0x10);
    GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, 0x10);
    WaitIrqAndTurnOnDisplays();
    SetCurrentSndArc();
    a = HeapAlloc(a, GetSndHeapsBufferSize(1));
    CreateSndHeaps(1, (u32) a);
    gRunScenesState->mSndHeapsBuffer = a;
}

static inline BOOL func_0205dd38_inline(void) {
    if (gRunScenesState->mUnk_04 == 3 || gRunScenesState->mUnk_04 == gRunScenesState->mUnk_00) {
        return TRUE;
    }
    return FALSE;
}

s32 RunScenes(s16 *sceneNumber) {
    HeapCall heapCall;
    void *heap;
    func_0205e0b0();
    while (func_0205dd38_inline()) {
        gRunScenesState->mUnk_04 = 3;
        gSceneNumbers[0] = gSceneNumbers[1];
        gSceneNumbers[1] = *sceneNumber;
        gSceneNumbers[2] = -1;
        InitHeapCall(&heapCall, gSceneFuncs[*sceneNumber]);
        RunHeapCall(&heapCall, (u32) gSceneNumbers);
        if (gSceneNumbers[2] != -1) {
            *sceneNumber = gSceneNumbers[2];
        } else {
            *sceneNumber = 9;
        }
        switch (data_021759d0->mUnk_20) {
            case 0:
            case 1:
            case 2:
                gRunScenesState->mUnk_04 = 0;
                break;
            case 3:
                gRunScenesState->mUnk_04 = 1;
                break;
            case 4:
                func_0205dee0();
                data_021759d0->mUnk_20 = 3;
                break;
        }
    }
    heap = GetHeap(GetCurrentHeapCall());
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 != 2 && gRunScenesState->mSndHeapsBuffer != NULL) {
        ReleaseSndHeaps();
        HeapFree(heap, gRunScenesState->mSndHeapsBuffer);
        gRunScenesState->mSndHeapsBuffer = NULL;
    }
    switch (gRunScenesState->mUnk_00) {
        case 0:
            func_02054330();
            break;
        case 1:
            DeleteWiFiSessionHeap();
            break;
    }
    return 0;
}

void RunScenesForever(void) {
    HeapCall heapCall;
    gRunScenesState->mSceneNumber = 9;
    gRunScenesState->mUnk_00 = 0;
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        data_021759d0->mUnk_20 = 2;
        data_0217b488->mUnk_74 = 0;
        gRunScenesState->mSceneNumber = 6;
    }
    do {
        gRunScenesState->mUnk_04 = 3;
        InitHeapCall(&heapCall, (u32) RunScenes);
        RunHeapCall(&heapCall, (u32) &gRunScenesState->mSceneNumber);
        gRunScenesState->mUnk_00 = gRunScenesState->mUnk_04;
    } while (1);
}
