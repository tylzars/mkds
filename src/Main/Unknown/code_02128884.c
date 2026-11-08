#include "Main/Unknown/code_02128884.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020487fc.h"
#include "Main/Unknown/code_020ae630.h"

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
void InitKeyboardScene(s16 *sceneNumbers) {
    void *heap;
    heap = GetHeap(GetCurrentHeapCall());
    data_0217d3fc = HeapAlloc(heap, 0x808);
    InitKeyboard(heap, sceneNumbers[0]);
}
#pragma thumb off

#pragma thumb on
void ReleaseKeyboardScene(void) {
    u32 address;
    u32 zero;
    ReleaseKeyboard();
    zero = 0u;
    address = (u32) &data_0217d3fc;
    *(u32 *) ((address) + 0u) = zero;
}
#pragma thumb off

SceneCallbacks gKeyboardSceneCallbacks = {
    InitKeyboardScene, UpdateKeyboardScene, ReleaseKeyboardScene, func_0212891c, 0, 0, 10, 10, 0};

#pragma thumb on
void func_0212891c(void) {
    func_0212899c();
    func_020ae5f0(data_0217d3fc, &data_0217d3fc->mUnk_404);
}

void UpdateKeyboardScene(s16 *sceneNumbers) {
    func_020ae6ac(data_0217d3fc, &data_0217d3fc->mUnk_404);
    AdvanceKeyboard();
    func_020ae630(data_0217d3fc, &data_0217d3fc->mUnk_404);
    if (sceneNumbers != NULL) {
        if (GetKeyboardNextScene() != -1) {
            sceneNumbers[2] = GetKeyboardNextScene();
        }
    }
}

s32 RunKeyboardScene(void *sceneNumbers) {
    SceneCallbacks callbacks = gKeyboardSceneCallbacks;
    RunScene(sceneNumbers, &callbacks);
    return 0;
}
#pragma thumb off

#pragma thumb on

OamList *GetKeyboardFirstBuffer(void) {
    return &data_0217d3fc->mUnk_00;
}

OamList *GetKeyboardSecondBuffer(void) {
    return &data_0217d3fc->mUnk_404;
}

#pragma thumb off
