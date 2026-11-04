#include "00/code_02180608.h"
#include "00/unk_021b4000.h"
#include "00/code_02180814.h"

#include "00/code_021832d8.h"
#include "00/code_02181f98.h"
#include "00/code_02180c04.h"
#include "00/code_02181714.h"
#include "00/code_021848c8.h"
#include "00/code_021849e0.h"
#include "00/code_02184aa4.h"
#include "00/code_021857b8.h"
#include "00/code_02184ba8.h"
#include "00/code_02185344.h"
#include "00/code_ov000_021804e0.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02027df8.h"
#include "Main/Unknown/code_020296f4.h"
#include "Main/Unknown/code_0202a734.h"
#include "Main/Unknown/code_0202b000.h"
#include "Main/Unknown/code_0202bb80.h"
#include "Main/Unknown/code_0202c000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02078000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_0211f6cc.h"
#include "Main/Unknown/code_0212030c.h"
#include "Main/Unknown/code_02122b14.h"
#include "Main/Unknown/code_02124f4c.h"
#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/code_02125960.h"
#include "Main/Unknown/code_02125da0.h"
#include "Main/Unknown/code_02125de0.h"
#include "Main/Unknown/code_0212a920.h"
#include "Main/Unknown/code_0212abd0.h"
#include "Main/Unknown/code_0212a910.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02029000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_02029a24.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_0202b604.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_02048000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/code_020472a8.h"

void ClearWiFiStateCallbacks(void) {
    gWiFiStates->mUnk_1c.mUnk_00 = NULL;
    gWiFiStates->mUnk_1c.mUnk_04 = NULL;
    gWiFiStates->mUnk_1c.mUnk_08 = NULL;
    gWiFiStates->mUnk_1c.mUnk_0c = NULL;
}

void func_ov000_02180a54(void) {
    Unk02111684_v v;
    LoadNcgrData(&v.mNcgr, FindSceneFile("WiFi_VS_setting_s_b.ncgr"));
    LoadNclrData(&v.mNclr, FindSceneFile("WiFi_VS_setting_s_b.nclr"));
    LoadNscrData(&v.mNscr, FindSceneFile("WiFi_VS_s_setting.nscr"));
    LoadNcgrData(&v.mNcgr, FindSceneFile("WiFi_VS_matching_s_b.ncgr"));
    LoadNclrData(&v.mNclr, FindSceneFile("WiFi_VS_matching_s_b.nclr"));
    LoadNscrData(&v.mNscr, FindSceneFile("WiFi_VS_matching_s.nscr"));
    LoadNcgrData2(&v.mNcgr, FindSceneFile("WiFi_top_menu_s.nce.ncgr"));
    LoadNcerData(&v.mNcer, FindSceneFile("WiFi_top_menu_s.nce.ncer"));
    LoadNclrData(&v.mNclr, FindSceneFile("WiFi_top_menu_s_o.nclr"));
    LoadNcgrData2(&v.mNcgr, FindSceneFile("WiFi_VS_setting_s.nce.ncgr"));
    LoadNcerData(&v.mNcer, FindSceneFile("WiFi_VS_setting_s.nce.ncer"));
    LoadNclrData(&v.mNclr, FindSceneFile("WiFi_VS_setting_s_o.nclr"));
    LoadNcgrData2(&v.mNcgr, FindSceneFile("WiFi_VS_matching_s.nce.ncgr"));
    LoadNcerData(&v.mNcer, FindSceneFile("WiFi_VS_matching_s.nce.ncer"));
    LoadNclrData(&v.mNclr, FindSceneFile("WiFi_VS_matching_s_o.nclr"));
    LoadNcgrData2(&v.mNcgr, FindSceneFile("WiFi_aikotoba_s.nce.ncgr"));
    LoadNcerData(&v.mNcer, FindSceneFile("WiFi_aikotoba_s.nce.ncer"));
    LoadNclrData(&v.mNclr, FindSceneFile("WiFi_aikotoba_s_o.nclr"));
    LoadNcgrData2(&v.mNcgr, FindSceneFile("WiFi_aikotoba_check_m.nce.ncgr"));
    LoadNcerData(&v.mNcer, FindSceneFile("WiFi_aikotoba_check_m.nce.ncer"));
    LoadNclrData(&v.mNclr, FindSceneFile("WiFi_aikotoba_check_m_o.nclr"));
    func_02025f90();
    func_02027df8();
    func_0202a734();
    func_0202b8d8();
}

void InitWiFiStates(void *heap, s32 b) {
    Unk02125de0Arg c;
    Unk0217d384_08 *q;
    gWiFiStates = HeapAlloc(heap, 0x3c);
    gWiFiStates->mUnk_00 = heap;
    gWiFiStates->mUnk_14 = 0;
    func_02029a70(heap);
    gWiFiStates->mUnk_2c = func_02125028(heap);
    func_0212abdc(heap, func_ov000_021804f4());
    c.mUnk_00 = 1;
    c.mUnk_04 = func_020b403c(1);
    c.mUnk_08 = 0;
    c.mUnk_0c = 0;
    c.mUnk_10 = 0;
    c.mUnk_14 = 0;
    c.mUnk_18 = 0;
    c.mUnk_1c = 1;
    c.mUnk_20 = 1;
    c.mUnk_24 = 1;
    LoadTxtSystemAndSelectChoisesAndSelectReturnData();
    func_02125de0(heap, &c);
    func_ov000_02180a54();
    func_0202c65c(heap, func_ov000_021804f4());
    func_02078d64(GetHeap(func_020364e8()));
    func_02078a9c(-1);
    func_02078a34(-1);
    func_020476ac();
    gWiFiStates->mUnk_04 = CreateExpHeapFromMaxFree(heap);
    ClearWiFiStateCallbacks();
    gWiFiStates->mUnk_18 = -1;
    if (data_0217b488->mUnk_58 != 0) {
        b = 0;
        data_0217b488->mUnk_58 = 0;
    }
    switch (b) {
        case 0:
            gWiFiStates->mUnk_10 = 10;
            gWiFiStates->mUnk_08 = 1;
            RegisterWiFiTopMenuCallbacks();
            func_021204d0();
            data_0217b488->mUnk_1c = 0;
            break;
        case 12:
            gWiFiStates->mUnk_10 = 13;
            gWiFiStates->mUnk_08 = 1;
            RegisterWiFiTopMenuCallbacks();
            break;
        case 2:
        case 10:
            switch (data_0217b488->mUnk_1c) {
                case 0:
                    gWiFiStates->mUnk_08 = 1;
                    RegisterWiFiTopMenuCallbacks();
                    break;
                case 1:
                    q = &data_0217d384->mUnk_0008;
                    q->mNextState = 2;
                    q->mNextStateRequested = 1;
                    gWiFiStates->mUnk_08 = 2;
                    RegisterWiFiVSSettingCallbacks();
                    break;
                case 2:
                    func_02123a48(1);
                    gWiFiStates->mUnk_08 = 4;
                    RegisterSelectCharacterCallbacks();
                    break;
                case 3:
                    func_02123a48(2);
                    func_020296f4();
                    gWiFiStates->mUnk_08 = 6;
                    RegisterWiFiVSCourseSelectCallbacks();
                    break;
            }
            break;
        case 14:
            gWiFiStates->mUnk_10 = 11;
            gWiFiStates->mUnk_08 = 8;
            RegisterWiFiAikotobaCallbacks();
            break;
        case 8:
            switch (data_0217b488->mUnk_50) {
                case 0:
                    gWiFiStates->mUnk_10 = 14;
                    gWiFiStates->mUnk_08 = 2;
                    RegisterWiFiVSSettingCallbacks();
                    break;
                case 1:
                    gWiFiStates->mUnk_10 = 14;
                    gWiFiStates->mUnk_08 = 8;
                    RegisterWiFiAikotobaCallbacks();
                    break;
            }
            break;
    }
    gWiFiStates->mUnk_0c = -1;
    gWiFiStates->mUnk_1c.mUnk_00(gWiFiStates->mUnk_04);
    data_0217b488->mUnk_78 = 1;
}

void func_ov000_02180814(void) {
    if (gWiFiStates->mUnk_1c.mUnk_04 != NULL) {
        gWiFiStates->mUnk_1c.mUnk_04();
    }
    ClearWiFiStateCallbacks();
    func_0202bb60();
    func_0212abd0();
    func_02125da0();
    gWiFiStates = NULL;
}

void AdvanceWiFiStates(void) {
    if (gWiFiStates->mUnk_1c.mUnk_08 != NULL) {
        gWiFiStates->mUnk_1c.mUnk_08();
    }
    if (gWiFiStates->mUnk_0c != -1) {
        gWiFiStates->mUnk_1c.mUnk_04();
        ClearWiFiStateCallbacks();
        HeapDestroy(gWiFiStates->mUnk_04);
        gWiFiStates->mUnk_04 = CreateExpHeapFromMaxFree(gWiFiStates->mUnk_00);
        switch (gWiFiStates->mUnk_0c) {
            case 0:
                func_ov000_02180c04();
                break;
            case 1:
                RegisterWiFiTopMenuCallbacks();
                break;
            case 2:
                RegisterWiFiVSSettingCallbacks();
                break;
            case 3:
                RegisterWiFiVSMatchingCallbacks();
                break;
            case 4:
                RegisterSelectCharacterCallbacks();
                break;
            case 5:
                func_ov000_021849e0();
                break;
            case 6:
                RegisterWiFiVSCourseSelectCallbacks();
                break;
            case 7:
                func_ov000_021857b8();
                break;
            case 8:
                RegisterWiFiAikotobaCallbacks();
                break;
            case 9:
                RegisterWiFiAikotobaCheckCallbacks();
                break;
        }
        gWiFiStates->mUnk_10 = gWiFiStates->mUnk_08;
        gWiFiStates->mUnk_08 = gWiFiStates->mUnk_0c;
        gWiFiStates->mUnk_0c = -1;
        if (gWiFiStates->mUnk_1c.mUnk_00 != NULL) {
            gWiFiStates->mUnk_1c.mUnk_00(gWiFiStates->mUnk_04);
        }
    }
    func_02125928();
    func_0212a920();
    gWiFiStates->mUnk_14++;
    if (gWiFiStates->mUnk_14 > 0) {
        gWiFiStates->mUnk_14 = 0;
    }
}

void func_ov000_02180704(void) {
    if (gWiFiStates->mUnk_1c.mUnk_0c != NULL) {
        gWiFiStates->mUnk_1c.mUnk_0c();
    }
    func_021258f0();
    return;
}

void SetWiFiStateCallbacks(const Unk021b0cd4 *callbacks) {
    gWiFiStates->mUnk_1c = *callbacks;
}

void RequestWiFiState(s32 nextState) {
    u32 value0 = (u32) nextState;
    u32 value1;
    value1 = (u32) &gWiFiStates;
    value1 = (u32) * (const u32 *) ((value1) + 0u);
    *(u32 *) ((value1) + 12u) = value0;
    return;
}

s32 GetWiFiPrevState(void) {
    return gWiFiStates->mUnk_10;
}

u32 func_ov000_021806c4(void) {
    return ((u32) gWiFiStates->mUnk_18);
}

void func_ov000_021806b8(u32 p0) {
    gWiFiStates->mUnk_18 = (u16) p0;
}

u32 func_ov000_021806a0(void) {
    if (0 <= gWiFiStates->mUnk_14) {
        return TRUE;
    }
    return FALSE;
}

u32 LookupWiFiVSSettingMessageIndex(u32 settingIndex) {
    u32 messageIndices[4] = {2, 3, 4, 5};
    return messageIndices[settingIndex];
}

u32 GetWiFiVSSettingIndex(void) {
    return gWiFiStates->mUnk_30;
}

void SetWiFiVSSettingIndex(u32 settingIndex) {
    gWiFiStates->mUnk_30 = settingIndex;
}

s32 func_ov000_02180644(void) {
    u32 value0;
    value0 = (u32) &gWiFiStates;
    value0 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = (u32) * (const u32 *) ((value0) + 52u);
    return (s32) value0;
}

void func_ov000_02180638(s32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (u32) &gWiFiStates;
    value1 = (u32) * (const u32 *) ((value1) + 0u);
    *(u32 *) ((value1) + 52u) = value0;
    return;
}

BOOL func_ov000_02180608(void) {
    BOOL valid = TRUE;
    if (gWiFiStates != NULL && gWiFiStates->mUnk_08 == 0) {
        valid = FALSE;
    }
    if (data_0217d384->mUnk_0008.mState == 0 && valid != FALSE) {
        return TRUE;
    }
    return FALSE;
}
