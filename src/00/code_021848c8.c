#include "00/code_021848c8.h"
#include "Main/Unknown/code_02026000.h"

#include "00/code_02180608.h"
#include "00/unk_021b4000.h"
#include "Main/Unknown/code_02026120.h"
#include "Main/Unknown/code_02122ae4.h"
#include "00/code_02182fdc.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_02121e84.h"
#include "Main/Unknown/code_02122734.h"
#include "Main/Unknown/code_0212a910.h"

void InitWiFiSelectCharacterState(void *a) {
    void *b;
    void *c;
    s32 i;

    data_ov000_021b4c78 = func_02036bec(a, 4);
    data_ov000_021b4c78->mUnk_00 = a;
    func_ov000_02184934();
    if (GetWiFiPrevState() != 5) {
        func_02122728();
        func_02029454((u8) func_02122778(func_ov000_0219bb50()));
        func_02029440(data_0217d384->mUnk_1f52);
    }
    b = func_ov000_021804f4();
    c = func_ov000_021804e0();
    func_02026910(a, 2, b, c);
    func_0212a910(1, 1);
    data_0217b488->mUnk_6c = 0;
    for (i = 0; i < 4; i++) {
        data_0217b488->mUnk_5c[i] = 0;
    }
}

void func_ov000_02184938(void) {
    func_020260e4();
    *(u32 *) &data_ov000_021b4c78 = 0;
    return;
}

void func_ov000_02184934(void) {
    return;
}

void AdvanceWiFiSelectCharacterState(void) {
    s32 a;

    a = func_02026120();
    if (a == 1 || a == 3) {
        if (func_02122ae4() != 0) {
            RequestWiFiState(7);
            return;
        }
        if (a == 1) {
            RequestWiFiState(5);
        }
        if (a == 3) {
            RequestWiFiState(6);
        }
    }
}

void func_ov000_021848ec(void) {
    u32 value3;
    value3 = (u32) &func_02026058;
    func_02026058();
    return;
}

void RegisterSelectCharacterCallbacks(void) {
    Unk021b0cd4 callbacks = gSelectCharacterCallbacks;
    SetWiFiStateCallbacks(&callbacks);
}
