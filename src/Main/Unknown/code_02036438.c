#include "Main/Unknown/code_02036264.h"
#include "Main/Unknown/code_02036438.h"
#include "Main/Unknown/code_02035d18.h"
#include "Main/Unknown/code_020364a8.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020d1630.h"
#include "Main/Unknown/code_020d1640.h"
#include "Main/Unknown/unk_02174000.h"
#include "code_0214b824.h"

#pragma thumb on

void func_02036438(void *heap) {
    void *v1;
    int v2;
    Ncgr *v3;
    Nclr *v4;
    v1 = CreateFrmHeapFromMaxFree(heap);
    v2 = ((u32) HeapAlloc(v1, (u32) (((u32) 0x00000654u))));
    *(s32 *) &data_02174e6c = v2;
    func_02036264((void *) v2, (u32) (((u32) 0x00000654u)));
    data_02174e6c->mHeap = v1;
    func_020364a8(0, 0, 0x10, 0, 0);
    v3 = func_020d1630()->mUnk_24;
    v4 = func_020d1630()->mUnk_28;
    MemCopyWordsToG2sBg1CntBits2To5Address(v3->mData, 0, v3->mDataSize);
    MemCopyWordsToG2sBg3CntBits2To5Address(v3->mData, 0, v3->mDataSize);
    func_0214c0f8(v4->mData, 0, v4->mDataSize);
}

#pragma thumb off
