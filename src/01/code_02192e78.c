#include "01/code_02192e78.h"

#include "01/code_02193000.h"
#include "01/code_02199964.h"
#include "01/code_0219d5dc.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02125960.h"
#include "Main/Unknown/code_0212a000.h"
#include "Main/Unknown/code_0212a920.h"
#include "Main/Unknown/code_0212abd0.h"
#include "Main/Unknown/code_0212abdc.h"
#include "Main/Unknown/code_0214a000.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214a2a0.h"
#include "code_0214a2f4.h"
#include "code_0214d018.h"
#include "registers.h"

void ClearOptionStateCallbacks(void) {
    gOptionStates->mCallbacks.mInit = NULL;
    gOptionStates->mCallbacks.mRelease = NULL;
    gOptionStates->mCallbacks.mAdvance = NULL;
    gOptionStates->mCallbacks.mUnk_0c = NULL;
}

void LoadOptionData(void) {
    Unk02111684_v v;
    LoadNcgrData(&v.mNcgr, FindSceneFile("Option_top_menu_m_b.ncgr"));
    LoadNscrData(&v.mNscr, FindSceneFile("Option_top_menu_m.nscr"));
    LoadNclrData(&v.mNclr, FindSceneFile("Option_top_menu_m_b.nclr"));
    LoadNcgrData(&v.mNcgr, FindSceneFile("Option_select_menu_m_b.ncgr"));
    LoadNscrData(&v.mNscr, FindSceneFile("Option_select_menu_m.nscr"));
    LoadNclrData(&v.mNclr, FindSceneFile("Option_select_menu_m_b.nclr"));
    LoadNcgrData2(&v.mNcgr, FindSceneFile("Option_top_menu_s.nce.ncgr"));
    LoadNcerData(&v.mNcer, FindSceneFile("Option_top_menu_s.nce.ncer"));
    LoadNclrData(&v.mNclr, FindSceneFile("Option_top_menu_s_o.nclr"));
    LoadNcgrData2(&v.mNcgr, FindSceneFile("Option_hensyu_menu_s.nce.ncgr"));
    LoadNcerData(&v.mNcer, FindSceneFile("Option_hensyu_menu_s.nce.ncer"));
    LoadNclrData(&v.mNclr, FindSceneFile("Option_hensyu_menu_s_o.nclr"));
    LoadNcgrData2(&v.mNcgr, FindSceneFile("Option_select_menu_m.nce.ncgr"));
    LoadNcerData(&v.mNcer, FindSceneFile("Option_select_menu_m.nce.ncer"));
    LoadNclrData(&v.mNclr, FindSceneFile("Option_select_menu_m_o.nclr"));
    LoadNcgrData2(&v.mNcgr, FindSceneFile("Option_select_menu_s.nce.ncgr"));
    LoadNcerData(&v.mNcer, FindSceneFile("Option_select_menu_s.nce.ncer"));
    LoadNclrData(&v.mNclr, FindSceneFile("Option_select_menu_s_o.nclr"));
    LoadNcgrData2(&v.mNcgr, FindSceneFile("Option_embrem_select_s.nce.ncgr"));
    LoadNcerData(&v.mNcer, FindSceneFile("Option_embrem_select_s.nce.ncer"));
    LoadNclrData(&v.mNclr, FindSceneFile("Option_embrem_select_s_o.nclr"));
}

void func_ov001_021930ac(void) {
    u32 t;
    vu32 a;
    vu32 b;
    void *d1;
    void *d2;
    t = (reg_GX_DISPCNT & 0x1f00) >> 8;
    t |= 1;
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | (t << 8);
    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0x9000;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 2;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & 0x43) | 0x9204;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | 1;
    d1 = (void *) func_0214a2f4();
    a = 0;
    func_0214d05c(a, d1, 0x1000);
    d2 = (void *) func_0214a2a0();
    b = 0;
    func_0214d05c(b, d2, 0x1000);
}

void InitOptionStates(void *heap, s16 a) {
    Unk02125de0Arg arg;
    gOptionStates = func_02036bec(heap, 0x2c);
    gOptionStates->mHeap = heap;
    gOptionStates->mUnk_28 = func_021250b0(heap);
    func_ov001_021930ac();
    func_0212abdc(heap, func_ov001_0219e920());
    arg.mUnk_00 = 1;
    arg.mUnk_04 = func_020b403c(1);
    arg.mUnk_08 = 0;
    arg.mUnk_0c = 1;
    arg.mUnk_10 = 0;
    arg.mUnk_14 = 0;
    arg.mUnk_18 = 0;
    arg.mUnk_1c = 1;
    arg.mUnk_20 = 1;
    arg.mUnk_24 = 0;
    LoadTxtSystemAndSelectChoisesAndSelectReturnData();
    func_02125de0(heap, &arg);
    gOptionStates->mStateHeap = func_020369fc(gOptionStates->mHeap);
    LoadOptionData();
    ClearOptionStateCallbacks();
    gOptionStates->mUnk_14 = -1;
    switch (a) {
        case 0:
            gOptionStates->mPrevState = 4;
            gOptionStates->mState = 0;
            func_ov001_021932e4();
            break;
        case 14:
            gOptionStates->mPrevState = 5;
            gOptionStates->mState = 2;
            func_ov001_02199964();
            break;
        case 3:
            gOptionStates->mPrevState = 6;
            if (data_0217b488->mUnk_18 == 0) {
                gOptionStates->mState = 2;
                func_ov001_02199964();
            } else {
                gOptionStates->mState = 3;
                RegisterOptionEmbremSelectCallbacks();
            }
            break;
    }
    gOptionStates->mNextState = -1;
    gOptionStates->mCallbacks.mInit(gOptionStates->mStateHeap);
}

void func_ov001_02192f8c(void) {
    if (gOptionStates->mCallbacks.mRelease != NULL) {
        gOptionStates->mCallbacks.mRelease();
    }
    ClearOptionStateCallbacks();
    func_0212abd0();
    func_02125da0();
    gOptionStates = NULL;
}

void AdvanceOptionStates(void) {
    if (gOptionStates->mCallbacks.mAdvance != NULL) {
        gOptionStates->mCallbacks.mAdvance();
    }
    if (gOptionStates->mNextState != -1) {
        gOptionStates->mCallbacks.mRelease();
        ClearOptionStateCallbacks();
        func_02036ab0((void *) gOptionStates->mStateHeap);
        gOptionStates->mStateHeap = func_020369fc(gOptionStates->mHeap);
        switch (gOptionStates->mNextState) {
            case 0:
                func_ov001_021932e4();
                break;
            case 1:
                func_ov001_02198854();
                break;
            case 2:
                func_ov001_02199964();
                break;
            case 3:
                RegisterOptionEmbremSelectCallbacks();
                break;
        }
        gOptionStates->mPrevState = gOptionStates->mState;
        gOptionStates->mState = gOptionStates->mNextState;
        gOptionStates->mNextState = -1;
        if (gOptionStates->mCallbacks.mInit != NULL) {
            gOptionStates->mCallbacks.mInit(gOptionStates->mStateHeap);
        }
    }
    func_02125928();
    func_0212a920();
}

void func_ov001_02192ec4(void) {
    if (gOptionStates->mCallbacks.mUnk_0c != NULL) {
        (*gOptionStates->mCallbacks.mUnk_0c)();
    }
    func_021258f0();
    return;
}

void SetOptionStateCallbacks(UnkFunc **a) {
    gOptionStates->mCallbacks = *(OptionStateCallbacks *) a;
}

void RequestOptionState(u32 a) {
    gOptionStates->mNextState = a;
    return;
}

u32 GetOptionPrevState(void) {
    return (u32) gOptionStates->mPrevState;
}

int func_ov001_02192e84(void) {
    return gOptionStates->mUnk_14;
}

void func_ov001_02192e78(u16 a) {
    gOptionStates->mUnk_14 = a;
    return;
}
