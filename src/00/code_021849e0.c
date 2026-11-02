#include "00/code_021849e0.h"
#include "Main/Unknown/code_02027000.h"
#include "Main/Unknown/code_02027f68.h"

#include "00/code_02180608.h"
#include "00/unk_021b4000.h"
#include "Main/Unknown/code_02028000.h"
#include "Main/Unknown/code_02122ae4.h"
#include "00/code_02182fdc.h"

void func_ov000_02184a6c(void *a) {
    void *b;
    void *c;

    data_ov000_021b4c7c = func_02036bec(a, 4);
    data_ov000_021b4c7c->mUnk_00 = a;
    func_ov000_02184a50();
    b = func_ov000_021804f4();
    c = func_ov000_021804e0();
    InitSelectKart(a, 2, b, c);
}

void func_ov000_02184a54(void) {
    func_0202808c();
    *(u32 *) &data_ov000_021b4c7c = 0;
    return;
}

void func_ov000_02184a50(void) {
    return;
}

void func_ov000_02184a0c(void) {
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
    value3 = (u32) &func_02027e78;
    func_02027e78();
    return;
}

void func_ov000_021849e0(void) {
    Unk021b0cd4 callbacks = data_ov000_021b0e40;
    SetWiFiStateCallbacks(&callbacks);
}
