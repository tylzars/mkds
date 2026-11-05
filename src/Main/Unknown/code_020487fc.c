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
#include "code_0214f4a4.h"
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
    if (data_021759c0->mMode == 5 && func_020487fc_inline5()) {
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
        if (!func_02049aa4()) {
            if (PM_GetLCDPower() == 1) {
                t = IrqDisable();
                data_021759cc->mUnk_110 = TRUE;
                PM_SetLCDPower(0);
                IrqRestore(t);
            }
        } else {
            PM_GoSleepMode(12, 0, 0);
        }
    } else {
        if (PM_GetLCDPower() == 0) {
            t = IrqDisable();
            PM_SetLCDPower(1);
            if (func_02036c5c()) {
                func_02049808(0);
                func_020497f0(0);
            }
            data_021759cc->mUnk_110 = FALSE;
            IrqRestore(t);
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
        func_02037498(!func_020487fc_inline12() || !func_020487fc_inline6());
    } else {
        func_02037658(b->mUnk_1c);
    }
}

static inline s32 func_020487fc_inline10(void) {
    if (data_021759d4->mUnk_0c) {
        return data_021759d4->mUnk_10;
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
    if (!data_0217aa08->mUnk_28) {
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
    data_021759cc->mSceneFrames = v;
    data_021759cc->mUnk_0e8 = v;
    data_021759cc->mSceneCallbacks = *b;
    data_021759cc->mUnk_10c = 6;
    data_021759cc->mUnk_120 = 0;
    data_021759cc->mUnk_118 = -1;
    data_021759cc->mUnk_11c = 0;
    t = IrqDisable();
    if (PM_GetLCDPower() == 1) {
        data_021759cc->mUnk_110 = FALSE;
    } else {
        data_021759cc->mUnk_110 = TRUE;
    }
    IrqRestore(t);
    data_021759cc->mUnk_10c = 0;
    func_02047b6c(0);
    func_02047ba0(a->mScene);
    func_02047b6c(9);
    GetHeap(func_020364e8());
    CallQueueInit(HeapAlloc(GetHeap(func_020364e8()), 0x800), 0x80);
    if (func_0204a428(a->mScene, &n)) {
        func_0204acd0(n);
    }
    func_021074ac(0);
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
    data_021755a0->mUnk_b8 = func_0204a4d8;
    func_0204ac60();
    func_02107010();
    func_02039044();
    data_021759cc->mUnk_10c = 1;
    do {
        func_02037a40();
        func_020487fc_inline7();
        func_0210823c();
        func_020487fc_inline8();
        func_020487fc_inline9(b);
        r = func_0204984c(a, data_021759cc->mUnk_10c != 4);
        CallQueueDrain();
        if (r) {
            a->mNextScene = data_021759cc->mUnk_120;
            goto end;
        }
        UpdateWiFiSession();
        data_021759cc->mUnk_0e8++;
        func_020373ec();
    } while (func_02054754() != 1);
    func_02043b04();
    func_02037288(b->mUnk_18);
    data_021759cc->mUnk_10c = 2;
    do {
        func_02037a40();
        func_020487fc_inline7();
        if (b->mUpdate != NULL) {
            b->mUpdate(a, data_021759cc->mSceneFrames);
        }
        func_0210823c();
        v = func_020487fc_inline8();
        func_020487fc_inline9(b);
        r = func_0204984c(a, data_021759cc->mUnk_10c != 4);
        CallQueueDrain();
        if (r) {
            a->mNextScene = data_021759cc->mUnk_120;
            goto end;
        }
        if (b->mUnk_0c != NULL) {
            b->mUnk_0c(a, data_021759cc->mSceneFrames);
        }
        UpdateWiFiSession();
        if (!func_020487fc_inline6()) {
            data_021759cc->mSceneFrames++;
        }
        data_021759cc->mUnk_0e8++;
        func_020373ec();
    } while (a->mNextScene == -1 && v == 0);
    data_021759cc->mUnk_10c = 3;
    func_02105fcc();
    if (data_021759d0->mUnk_1c_0) {
        if (a == NULL || func_0204a340(a->mScene, a->mNextScene)) {
            func_0204ac10();
        }
    }
    if ((v != 0 || GetNextSceneNumber() == 0) && ((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        func_02049e38(0);
    }
    if (data_021759d0->mUnk_20 == 4) {
        func_02036d3c(b->mUnk_1a);
    } else {
        func_02036f10(b->mUnk_1a);
    }
    do {
        func_02037a40();
        func_020487fc_inline7();
        if (b->mUpdate != NULL) {
            b->mUpdate(0, data_021759cc->mSceneFrames);
        }
        func_0210823c();
        func_020487fc_inline8();
        func_020487fc_inline9(b);
        func_0204984c(a, data_021759cc->mUnk_10c != 4);
        CallQueueDrain();
        if (b->mUnk_0c != NULL) {
            b->mUnk_0c(0, data_021759cc->mSceneFrames);
        }
        UpdateWiFiSession();
        if (!func_020487fc_inline6()) {
            data_021759cc->mSceneFrames++;
        }
        data_021759cc->mUnk_0e8++;
        func_020373ec();
    } while (!func_02036d08());
end:
    func_02043ae0();
    if (func_020487fc_inline13() && (v != 0 || GetNextSceneNumber() == 0)) {
        data_021759cc->mUnk_10c = 4;
        data_021759d0->mUnk_20 = 0;
        c = FALSE;
        func_0204f7f4();
        do {
            func_02037a40();
            func_0210823c();
            func_020487fc_inline8();
            func_020487fc_inline9(b);
            if (func_02054f58() == 1) {
                if (!func_020487fc_inline14()) {
                    c = TRUE;
                }
            }
            func_0204984c(a, data_021759cc->mUnk_10c != 4);
            CallQueueDrain();
            UpdateWiFiSession();
            func_020373ec();
        } while (!c);
    }
    data_021759cc->mUnk_10c = 5;
    data_021755a0->mUnk_b8 = NULL;
    if (func_020487fc_inline2()) {
        data_0217aa00->mUnk_0454 &= ~4;
    }
    func_020546d8();
    func_02055340();
    if (b->mRelease != NULL) {
        b->mRelease(a);
    }
    CARD_SetPulledOutCallback(func_0204a548);
    if (data_021755a0 != NULL) {
        func_02037a94();
    }
    func_02043b3c();
    ClearFontAndPlayerCharacterTables();
    func_02039a1c();
    func_02105ec0();
    if (data_021759d0->mUnk_1c_1 && func_0204a340(a->mScene, a->mNextScene)) {
        func_0204aba8();
    }
    func_02047b88();
    if (v != 0) {
        a->mNextScene = 0;
    } else {
        w = data_021759cc->mUnk_118;
        if (w != -1) {
            switch (w) {
                case 4:
                case 5:
                case 6:
                    a->mNextScene = data_021759cc->mUnk_120;
                    break;
                default:
                    a->mNextScene = 0;
                    break;
            }
        }
    }
    func_0204ad24();
    data_021759cc->mSceneFrames = 0;
    data_021759cc->mUnk_10c = 6;
}
