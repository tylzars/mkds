#include "01/code_0219e824.h"
#include "01/unk_021ca000.h"
#include "01/code_02192e78.h"
#include "01/code_0219853c.h"
#include "01/code_0219ea48.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020ae5e4.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "01/code_02192000.h"
#include "01/code_02198000.h"
#include "01/code_0219e000.h"
#include "Main/Unknown/code_02048000.h"
#include "01/code_0219e0a8.h"
#include "01/code_0219f000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02105000.h"

u8 *gNicknameBuffers;
u8 *gOptionBuffers;

static SceneCallbacks gOptionSceneCallbacks = {
    InitOptionScene, UpdateOptionScene, ReleaseOptionScene, func_ov001_0219e9a4, 0, 0, 10, 10, 0};
static SceneCallbacks gEndingSceneCallbacks = {
    InitEndingScene, UpdateEndingScene, ReleaseEndingScene, func_ov001_0219ea6c, 0, 0, 30, 1, 0};

int RunEndingScene(void *a) {
    SceneCallbacks local = gEndingSceneCallbacks;

    RunScene(a, &local);
    return 0;
}

void InitOptionScene(s16 *a) {
    void *heap;

    heap = GetHeap(GetCurrentHeapCall());
    gOptionBuffers = HeapAlloc(heap, 0x808);
    InitOptionStates((heap), *a);
}

void ReleaseOptionScene(void) {
    func_ov001_02192f8c();
    gOptionBuffers = NULL;
}

void func_ov001_0219e9a4(void) {
    func_ov001_02192ec4();
    UploadOamLists(gOptionBuffers, gOptionBuffers + 0x404);
}

void UpdateOptionScene(s16 *a) {
    ClearOamListCounts(gOptionBuffers, gOptionBuffers + 0x404);
    AdvanceOptionStates();
    func_020ae630(gOptionBuffers, gOptionBuffers + 0x404);
    if (a != NULL && func_ov001_02192e84() != -1) {
        a[2] = func_ov001_02192e84();
    }
}

int RunOptionScene(void *a) {
    SceneCallbacks local = gOptionSceneCallbacks;

    RunScene(a, &local);
    return 0;
}

u8 *GetOptionFirstBuffer(void) {
    return gOptionBuffers;
}

u8 *GetOptionSecondBuffer(void) {
    return gOptionBuffers + 0x404;
}

void InitNicknameScene(s16 *a) {
    void *heap;

    heap = GetHeap(GetCurrentHeapCall());
    gNicknameBuffers = HeapAlloc(heap, 0x808);
    func_ov001_021987d4(heap, *a);
}

void ReleaseNicknameScene(void) {
    func_ov001_021987bc();
    gNicknameBuffers = NULL;
}

void func_ov001_0219e89c(void) {
    u8 *p;

    func_ov001_0219854c();
    p = gNicknameBuffers;
    UploadOamLists(p, p + 0x404);
}

void UpdateNicknameScene(s16 *a) {
    ClearOamListCounts(gNicknameBuffers, gNicknameBuffers + 0x404);
    func_ov001_02198554();
    func_020ae630(gNicknameBuffers, gNicknameBuffers + 0x404);
    if (a != NULL && func_ov001_0219853c() != -1) {
        a[2] = func_ov001_0219853c();
    }
}

int RunNicknameScene(void *a) {
    SceneCallbacks callbacks = {
        InitNicknameScene, UpdateNicknameScene, ReleaseNicknameScene, func_ov001_0219e89c, 0, 0, 10, 10, 0,
    };

    RunScene(a, &callbacks);
    return 0;
}
