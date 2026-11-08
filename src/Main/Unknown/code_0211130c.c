#include "Main/Unknown/code_0211130c.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ae5e4.h"
#include "Main/Unknown/code_020ae630.h"

#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_02111450.h"
#include "Main/Unknown/code_021114b0.h"
#include "Main/Unknown/code_021114cc.h"
#include "Main/Unknown/code_02111584.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_02111368.h"
#include "Main/Unknown/code_021113ac.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_021115b0.h"

#pragma thumb on

void InitRecordScene(s16 *sceneNumbers) {
    void *heap;
    heap = GetHeap(GetCurrentHeapCall());
    gRecordMainOam = HeapAlloc(heap, 0x404);
    gRecordSubOam = HeapAlloc(heap, 0x404);
    InitRecordSceneObject(heap, *sceneNumbers);
}

#pragma thumb off

#pragma thumb on
void ReleaseRecordScene(void) {
    u32 address;
    u32 zero;
    ReleaseRecordSceneObject();
    zero = 0u;
    address = (u32) &gRecordMainOam;
    *(u32 *) ((address) + 0u) = zero;
    address = (u32) &gRecordSubOam;
    *(u32 *) ((address) + 0u) = zero;
}
#pragma thumb off

#pragma thumb on
void func_02111368(void) {
    u32 mainOam;
    u32 subOam;
    WriteRecordSceneRegisters();
    mainOam = (u32) &gRecordMainOam;
    mainOam = *(const u32 *) ((mainOam) + 0u);
    subOam = (u32) &gRecordSubOam;
    subOam = *(const u32 *) ((subOam) + 0u);
    func_020ae5f0((void *) mainOam, (void *) subOam);
}
#pragma thumb off

#pragma thumb on

void UpdateRecordScene(Unk02111324 *sceneNumbers) {
    func_020ae6ac(gRecordMainOam, gRecordSubOam);
    AdvanceRecordScene();
    func_020ae630(gRecordMainOam, gRecordSubOam);
    if (sceneNumbers != NULL && GetRecordNextScene() != -1) {
        sceneNumbers->mUnk_04 = GetRecordNextScene();
    }
}

void *GetRecordMainOam(void) {
    return gRecordMainOam;
}

void *GetRecordSubOam(void) {
    return gRecordSubOam;
}

#pragma thumb off
