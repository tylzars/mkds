#include "Main/Unknown/code_020de214.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020dda38.h"
#include "Main/Unknown/code_020e43a8.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_020d49d8.h"
#include "Main/Unknown/code_020e6f50.h"
#include "Main/Unknown/code_020ec1fc.h"
#include "Main/Unknown/code_020ec538.h"
#include "Main/Unknown/code_020ec884.h"
#include "Main/Unknown/code_02036bec.h"
#include "code_02147cd8.h"
#include "Main/Unknown/unk_0217b000.h"

#pragma thumb on
void InitEarthenPipe(Unk020e43a8 *pipe) {
    pipe->mUnk_00.mPos.y += (s32) (((s64) pipe->mUnk_00.mScale.y * 0xd000) >> 12);
    InitPushedMotion(pipe, pipe->mUnk_00.mPos.y - 0xc0000, 0x400, 0x400, 0x5000, 0x2000);
    InitPushedObjectStates(pipe);
}
#pragma thumb off

Unk020de390 *CreateWanwanChainKindData(void) {
    Unk020de390 *kindData;

    kindData = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x40);
    *kindData = data_02158460;
    return kindData;
}

Unk020de334 *CreateWanwanChainDrawList(void) {
    data_0217b6dc = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x2c);
    *data_0217b6dc = data_02158434;
    func_020d49d8(&data_0217b6dc);
    return data_0217b6dc;
}

Unk020de2d8 *CreateWanwanChainUpdateList(void) {
    data_0217b6e0 = HeapAlloc(GetHeap(GetCurrentHeapCall()), 0x28);
    *data_0217b6e0 = data_0215840c;
    SetUpdateListSlot(&data_0217b6e0);
    return data_0217b6e0;
}

void DrawWanwanChain(void *unused, Unk020de000 *chainObject, s32 c, u16 d) {
    func_020ddaa0(&chainObject->mUnk_a4, gWanwanChain, c, d);
    if (chainObject->mUnk_f4 == FALSE) {
        return;
    }
    func_020dda38(&chainObject->mUnk_a4, gWanwanKui, &chainObject->mUnk_04, c, d);
}

void UpdateWanwanChain(void *unused, Unk020de000 *chainObject) {
    Vec3 endPoint;
    Wanwan *wanwan;

    wanwan = chainObject->mUnk_a0;
    if (chainObject->mUnk_f4 == FALSE) {
        chainObject->mUnk_04 = wanwan->mUnk_00.mPos;
    }
    VEC_MultAdd(-wanwan->mUnk_f0, &wanwan->mUnk_00.mMatrix.mUnk_00[2], &wanwan->mUnk_00.mPos, &endPoint);
    func_020ddb44(&chainObject->mUnk_a4, &endPoint, &wanwan->mUnk_00.mUnk_10);
}
