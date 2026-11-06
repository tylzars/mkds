#include "00/code_021849e0.h"
#include "Main/Unknown/code_02027000.h"
#include "Main/Unknown/code_02027e78.h"

#include "00/code_02180608.h"
#include "00/unk_021b4000.h"
#include "Main/Unknown/code_02028000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02122ae4.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02028130.h"
#include "Main/Unknown/code_02028864.h"

void InitWiFiSelectKartState(void *a) {
    void *b;
    void *c;

    gWiFiSelectKartState = HeapAlloc(a, 4);
    gWiFiSelectKartState->mHeap = a;
    func_ov000_02184a50();
    b = func_ov000_021804f4();
    c = func_ov000_021804e0();
    InitSelectKart(a, 2, b, c);
}

void ReleaseWiFiSelectKartState(void) {
    ReleaseSelectKart();
    *(u32 *) &gWiFiSelectKartState = 0;
}

void func_ov000_02184a50(void) {}

void AdvanceWiFiSelectKartState(void) {
    s32 a;

    a = AdvanceSelectKart();
    if (a == 1 || a == 2) {
        if (func_02122ae4() != 0) {
            RequestWiFiState(7);
            return;
        }
        if (a == 1) {
            RequestWiFiState(6);
            return;
        }
        if (a == 2) {
            RequestWiFiState(4);
        }
    }
}

void func_ov000_02184a04(void) {
    u32 value3;
    func_02027e78();
}

void RegisterSelectKartCallbacks(void) {
    WiFiStateCallbacks callbacks = gSelectKartCallbacks;
    SetWiFiStateCallbacks(&callbacks);
}
