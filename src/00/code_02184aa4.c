#include "00/code_02184aa4.h"
#include "Main/Unknown/code_0202a000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"

#include "00/code_02180608.h"
#include "Main/Unknown/code_0202a820.h"
#include "00/code_021832d8.h"
#include "00/unk_021b4000.h"
#include "Main/Unknown/code_02029758.h"
#include "Main/Unknown/code_02045000.h"
#include "Main/Unknown/code_02060cb4.h"
#include "Main/Unknown/code_02121e84.h"
#include "Main/Unknown/code_02122ae4.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_020296f4.h"
#include "Main/Unknown/code_02045874.h"

void InitWiFiVSCourseSelectState(u32 a) {
    int v1;
    void *v2;
    void *v3;
    v1 = ((u32) HeapAlloc((void *) a, 8));
    *(s32 *) &gWiFiVSCourseSelectState = v1;
    *(u32 *) (v1 + 4) = a;
    func_ov000_02184b4c();
    v2 = func_ov000_021804f4();
    v3 = func_ov000_021804e0();
    InitWiFiVSCourseSelect((void *) a, v2, v3);
    func_0212a910(1, 1);
}

void ReleaseWiFiVSCourseSelectState(void) {
    ReleaseWiFiVSCourseSelect();
    *(u32 *) &gWiFiVSCourseSelectState = 0;
}

void func_ov000_02184b4c(void) {}

void AdvanceWiFiVSCourseSelectState(void) {
    s32 a;
    u8 b;

    a = AdvanceWiFiVSCourseSelect();
    if (GetWiFiNextScene() == -1 && (a == 1 || a == 2)) {
        if (func_02122ae4() != 0) {
            RequestWiFiState(7);
            return;
        }
        b = gWiFiSession->mKartCount;
        func_02029930()->mKartCount = b;
        func_020297bc();
        if ((u32) data_0217b488->mUnk_1c <= 2) {
            func_02045ed0();
            func_020612b0();
            data_0217b488->mUnk_6c = TRUE;
        }
        func_02029758();
        SetWiFiNextScene(2);
        func_02122728();
    }
}

void func_ov000_02184ac8(void) {
    func_0202a820();
}

void RegisterWiFiVSCourseSelectCallbacks(void) {
    WiFiStateCallbacks callbacks = gWiFiVSCourseSelectCallbacks;
    SetWiFiStateCallbacks(&callbacks);
}
