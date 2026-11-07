#include "01/code_0219ea48.h"
#include "01/code_0219e0a8.h"

#include "01/code_0219e000.h"
#include "01/code_0219f000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02105000.h"
#include "01/code_0219f8ec.h"
#include "01/unk_021ca000.h"

void *data_ov001_021ca40c;

void InitEndingScene(void) {
    void *heap = GetHeap(GetCurrentHeapCall());

    data_ov001_021ca40c = HeapAlloc(heap, 4);
    CreateEndingScene(heap);
}

void ReleaseEndingScene(void) {
    func_ov001_0219e6e0();
    *(u32 *) &data_ov001_021ca40c = 0;
}

void func_ov001_0219ea6c(void) {
    func_ov001_0219e0d4();
}

void UpdateEndingScene(int a) {
    u16 v1;
    int v2;
    AdvanceEndingScene();
    if ((a != 0) && (v2 = GetEndingSceneNextScene(), v2 != -1)) {
        v1 = GetEndingSceneNextScene();
        *(u16 *) (a + 4) = v1;
    }
}
