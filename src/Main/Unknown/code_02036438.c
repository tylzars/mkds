#include "Main/Unknown/code_02036438.h"
#include "Main/Unknown/code_02036264.h"
#include "Main/Unknown/code_02035d18.h"
#include "Main/Unknown/code_020364a8.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020d1630.h"
#include "Main/Unknown/code_020d1640.h"
#include "Main/Unknown/unk_02174000.h"
#include "code_0214b824.h"

#pragma thumb on

void InitWLMenuMessage(void *heap) {
    void *frameHeap;
    int object;
    Ncgr *chars;
    Nclr *palette;
    frameHeap = CreateFrmHeapFromMaxFree(heap);
    object = ((u32) HeapAlloc(frameHeap, (0x00000654u)));
    *(s32 *) &gWLMenuMessage = object;
    func_02036264((void *) object, (0x00000654u));
    gWLMenuMessage->mHeap = frameHeap;
    SetSubBg1Cnt(0, 0, 0x10, 0, 0);
    chars = func_020d1630()->mUnk_24;
    palette = func_020d1630()->mUnk_28;
    GXS_LoadBG1Char(chars->mData, 0, chars->mDataSize);
    GXS_LoadBG3Char(chars->mData, 0, chars->mDataSize);
    GXS_LoadBGPltt(palette->mData, 0, palette->mDataSize);
}

#pragma thumb off
