#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020487fc.h"
#include "Main/Unknown/code_020ae630.h"
#include "Main/Unknown/code_02128884.h"

#include "Main/Unknown/code_021288a4.h"
#include "Main/Unknown/code_02048000.h"
#include "Main/Unknown/code_0212898c.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020ae5e4.h"
#include "Main/Unknown/code_0212a1c4.h"
#include "Main/Unknown/code_0212a1e0.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_02128940.h"
#include "Main/Unknown/code_02128958.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_0212a000.h"

#pragma thumb on
void InitKeyboardScene(s16 *a) {
    void *h;
    h = GetHeap(func_020364e8());
    data_0217d3fc = HeapAlloc(h, 0x808);
    InitKeyboard(h, a[0]);
}
#pragma thumb off

#pragma thumb on
void ReleaseKeyboardScene(void) {
    u32 value0;
    u32 value1;
    func_0212a1c4();
    value1 = 0u;
    value0 = (u32) &data_0217d3fc;
    *(u32 *) ((value0) + 0u) = value1;
}
#pragma thumb off

SceneCallbacks gKeyboardSceneCallbacks = {
    InitKeyboardScene, UpdateKeyboardScene, ReleaseKeyboardScene, func_0212891c, 0, 0, 10, 10, 0};

#pragma thumb on
void func_0212891c(void) {
    func_0212899c();
    func_020ae5f0(data_0217d3fc, &data_0217d3fc->mUnk_404);
}

void UpdateKeyboardScene(s16 *a) {
    func_020ae6ac(data_0217d3fc, &data_0217d3fc->mUnk_404);
    func_021289e0();
    func_020ae630(data_0217d3fc, &data_0217d3fc->mUnk_404);
    if (a != NULL) {
        if (func_0212898c() != -1) {
            a[2] = func_0212898c();
        }
    }
}

s32 RunKeyboardScene(void *a) {
    SceneCallbacks v = gKeyboardSceneCallbacks;
    RunScene(a, &v);
    return 0;
}
#pragma thumb off

#pragma thumb on

Unk0217d3fc_00 *func_02128898(void) {
    return &data_0217d3fc->mUnk_00;
}

Unk0217d3fc_00 *func_02128884(void) {
    return &data_0217d3fc->mUnk_404;
}

#pragma thumb off
