#include "gfd_LinkedListPlttVramMan.h"

#include "code_020169a4.h"
#include "code_02016d28.h"
#include "gfd_FrameTexVramMan.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/unk_02173000.h"

void NNS_GfdInitLnkPlttVramManager(u32 szByte, void *pManagementWork, u32 szByteManagementWork, int useAsDefault) {
    data_02173250.mSzByte = szByte;
    data_02173250.mWorkHead = pManagementWork;
    data_02173250.mSzByteManagementWork = szByteManagementWork;
    NNS_GfdResetLnkPlttVramState();
    if (useAsDefault != 0) {
        data_021619f4 = (u32(*)(s32, s32, s32)) NNS_GfdAllocLnkPlttVram;
        data_021619f8 = (void (*)(void *)) NNS_GfdFreeLnkPlttVram;
    }
}

u32 NNS_GfdAllocLnkPlttVram(u32 szByte, s32 b4Pltt, u32 opt) {
    u32 size;
    u32 addr;
    s32 result;

    if (szByte == 0) {
        size = 8;
    } else {
        size = (szByte + 7) & ~7;
    }
    if (size >= 0x7fff8) {
        return 0;
    }
    if (b4Pltt != 0) {
        result = RangeListAllocAligned(&data_02173250.mMgr, &data_02173254, &addr, size, 8);
        if (addr + size > 0x10000) {
            RangeListFree(&data_02173250.mMgr, &data_02173254, addr, size);
            return 0;
        }
    } else {
        result = RangeListAllocAligned(&data_02173250.mMgr, &data_02173254, &addr, size, 0x10);
    }
    if (result != 0) {
        return ((size >> 3) << 16) | ((addr >> 3) & 0xffff);
    }
    return 0;
}

s32 NNS_GfdFreeLnkPlttVram(u32 plttKey) {
    return RangeListFree(&data_02173250.mMgr, &data_02173254, (plttKey & 0xffff) << 3,
                         ((plttKey & -0x10000) >> 0x10) << 3) == 0;
}

void NNS_GfdResetLnkPlttVramState(void) {
    data_02173250.mBlockList = RangeEntryPoolInit(data_02173250.mWorkHead, data_02173250.mSzByteManagementWork >> 4);
    RangeListInit(&data_02173250.mMgr);
    RangeListAdd(&data_02173250.mMgr, &data_02173254, 0, data_02173250.mSzByte);
}
