#include "00/code_ov000_021804e0.h"

#include "00/code_02180814.h"
#include "00/unk_021b4000.h"
#include "00/code_02180608.h"
#include "Main/Unknown/code_02077000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_020487fc.h"
#include "Main/Unknown/code_020ae5e4.h"
#include "Main/Unknown/code_020ae630.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02077bc0.h"

void InitWiFiMenuScene(s16 *a) {
    void *b;
    b = GetHeap(GetCurrentHeapCall());
    data_ov000_021b4c60 = HeapAlloc(b, 0x808);
    InitWiFiStates(b, *a);
}

void ReleaseWiFiMenuScene(void) {
    ReleaseWiFiStates();
    data_ov000_021b4c60 = NULL;
}

void func_ov000_0218058c(void) {
    AdvanceKartModelMenuLoad();
    func_ov000_02180704();
    UploadOamLists(data_ov000_021b4c60, data_ov000_021b4c60 + 0x404);
}

void UpdateWiFiMenuScene(SceneNumbers *a) {
    ClearOamListCounts(data_ov000_021b4c60, data_ov000_021b4c60 + 0x404);
    AdvanceWiFiStates();
    func_020ae630(data_ov000_021b4c60, data_ov000_021b4c60 + 0x404);
    if (a != NULL) {
        if (GetWiFiNextScene() != -1) {
            if (GetWiFiNextScene() == 0) {
                data_021759d0->mUnk_20 = 0;
            }
            a->mNextScene = GetWiFiNextScene();
        }
    }
}

s32 RunWiFiMenuScene(SceneNumbers *a) {
    SceneCallbacks b = {
        InitWiFiMenuScene, UpdateWiFiMenuScene, ReleaseWiFiMenuScene, func_ov000_0218058c, 0, 0, 10, 10, 0};
    RunScene(a, &b);
    return 0;
}

void *func_ov000_021804f4(void) {
    return data_ov000_021b4c60;
}

void *func_ov000_021804e0(void) {
    return data_ov000_021b4c60 + 0x404;
}
