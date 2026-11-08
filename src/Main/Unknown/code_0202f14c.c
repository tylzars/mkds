#include "Main/Unknown/code_0202f14c.h"

#include "Main/Unknown/code_0202f000.h"
#include "Main/Unknown/code_020ae5e4.h"
#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/code_0212abd0.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_02125da0.h"
#include "Main/Unknown/code_0212a000.h"
#include "Main/Unknown/code_0202f498.h"
#include "Main/Unknown/code_0202f4ac.h"
#include "Main/Unknown/code_0202f554.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Unknown/code_0203b000.h"
#include "Main/Unknown/code_0203b0a0.h"
#include "Main/Unknown/code_020529b8.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020cbad0.h"
#include "Main/Unknown/code_02125960.h"
#include "Main/Unknown/code_02125de0.h"
#include "Main/Unknown/code_0212a920.h"
#include "Main/Unknown/code_0212a910.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02163000.h"
#include "registers.h"

void func_0202f478(u32 bits) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffcfffef) | bits;
}

void func_0202f454(u32 bits) {
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffcfffef) | bits;
}

#pragma thumb on

void InitWLMenuScene(void *heap) {
    Unk02180774 *displaySettings;
    Unk02125de0Arg v1;

    gWLMenuScene = HeapAllocAligned(heap, 0x874, 0x20);
    func_0202f51c(gWLMenuScene, 0x874);
    displaySettings = CreateDisplaySettings(heap, data_02154818);
    func_0202f4e0(displaySettings, 0, 0, 0, 0, 0xc, 0, 0);
    func_0202f4ac(displaySettings, 2, 0, 0, 0, 0xf, 6);
    InitDisplayFromSettings(displaySettings);
    if (func_0202f19c() == 0) {
        v1.mUnk_00 = 1;
        v1.mUnk_04 = func_020b403c(1);
        v1.mUnk_08 = 0;
        v1.mUnk_0c = 1;
        v1.mUnk_10 = 0;
        v1.mUnk_14 = 0;
        v1.mUnk_18 = NULL;
        v1.mUnk_1c = 1;
        v1.mUnk_20 = func_0202f498() == 0;
        v1.mUnk_24 = 0;
        LoadTxtSystemAndSelectChoisesAndSelectReturnData();
        func_02125de0(heap, &v1);
    }
    func_0212abdc(heap, gWLMenuScene);
    switch (func_0202f498()) {
        case 0:
            gWLMenuScene->mRequestedCallbacksIndex = func_0202f19c() != 0 ? 4 : 0;
            func_0203b0f8(heap);
            func_02053d00();
            break;
        case 1:
            gWLMenuScene->mRequestedCallbacksIndex = 5;
            func_0203b1fc(heap);
            break;
        case 2:
            gWLMenuScene->mRequestedCallbacksIndex = 6;
            func_0203b1c8(heap);
            break;
        case 3:
            gWLMenuScene->mRequestedCallbacksIndex = 7;
            func_0203b194(heap);
            break;
    }
    gWLMenuScene->mCurrentCallbacksIndex = gWLMenuScene->mRequestedCallbacksIndex;
    gWLMenuScene->mCurrentCallbacks = gWLMenuCallbacks[gWLMenuScene->mRequestedCallbacksIndex];
    gWLMenuScene->mHeap = CreateExpHeapFromMaxFree(heap);
    if (func_0202f19c() == 0) {
        LoadMultiSelectFiles();
    }
    func_020ae6d4(gWLMenuScene, gWLMenuScene->mSubOam);
    func_0202f478(0x10);
    func_0202f454(0x10);
    gWLMenuScene->mCurrentCallbacks->mUnk_00(gWLMenuScene->mHeap, gWLMenuScene, gWLMenuScene->mSubOam);
}

void AdvanceWLMenuScene(void *a) {
    s32 callbacksIndex = gWLMenuScene->mRequestedCallbacksIndex;
    Unk02174e4c_80c *previousCallbacks;

    if (gWLMenuScene->mCurrentCallbacksIndex != callbacksIndex) {
        previousCallbacks = gWLMenuScene->mCurrentCallbacks;
        gWLMenuScene->mCurrentCallbacks = gWLMenuCallbacks[callbacksIndex];
        gWLMenuScene->mCurrentCallbacksIndex = gWLMenuScene->mRequestedCallbacksIndex;
        previousCallbacks->mUnk_08();
        gWLMenuScene->mCurrentCallbacks->mUnk_00(gWLMenuScene->mHeap, gWLMenuScene, gWLMenuScene->mSubOam);
    } else {
        func_020ae6ac(gWLMenuScene, gWLMenuScene->mSubOam);
        callbacksIndex = gWLMenuScene->mCurrentCallbacks->mUnk_04(a);
        if (callbacksIndex != -1) {
            gWLMenuScene->mRequestedCallbacksIndex = callbacksIndex;
        }
        func_0212a920();
        func_020ae630(gWLMenuScene, gWLMenuScene->mSubOam);
    }
    if (func_0202f19c() == 0) {
        func_02125928();
    }
}

#pragma thumb off

#pragma thumb on

void ReleaseWLMenuScene(void) {
    int v1;
    gWLMenuScene->mCurrentCallbacks->mUnk_08();
    v1 = func_0202f19c();
    if (v1 == 0) {
        func_02125da0();
    }
    func_0212abd0();
}

#pragma thumb off

u16 *func_0202f1d0(void) {
    return (u16 *) 0x027ffc40;
}

u32 func_0202f1a8(void) {
    return *func_0202f1d0() == 2;
}

u32 func_0202f19c(void) {
    return func_0202f1a8();
}

#pragma thumb on

void func_0202f160(void) {
    int v1;
    v1 = func_0202f19c();
    if (v1 == 0) {
        func_021258f0();
    }
    gWLMenuScene->mCurrentCallbacks->mUnk_0c();
    func_020ae5f0(gWLMenuScene, gWLMenuScene->mSubOam);
}

Unk02174e4c_818 *func_0202f14c(void) {
    return &gWLMenuScene->mUnk_818;
}

#pragma thumb off
