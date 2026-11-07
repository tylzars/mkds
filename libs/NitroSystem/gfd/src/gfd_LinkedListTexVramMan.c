#include "gfd_LinkedListTexVramMan.h"
#include "gfd_LinkedListPlttVramMan.h"

#include "code_020169a4.h"
#include "code_02016d28.h"
#include "gfd_FrameTexVramMan.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/unk_02173000.h"

int NNS_GfdGetLnkTexVramManagerWorkSize(int numMemBlk) {
    return numMemBlk << 4;
}

void NNS_GfdInitLnkTexVramManager(u32 szByte, u32 szByteFor4x4, void *pManagementWork, u32 szByteManagementWork,
                                  int useAsDefault) {
    data_02173234.mSzByte = szByte;
    data_02173234.mSzByteFor4x4 = szByteFor4x4;
    data_02173234.mWorkHead = pManagementWork;
    data_02173234.mSzByteManagementWork = szByteManagementWork;
    NNS_GfdResetLnkTexVramState();
    if (useAsDefault != 0) {
        data_021619ec = (u32(*)(s32, s32, s32)) NNS_GfdAllocLnkTexVram;
        data_021619f0 = (void (*)(void *)) NNS_GfdFreeLnkTexVram;
    }
}

u32 NNS_GfdAllocLnkTexVram(u32 szByte, s32 is4x4comp, u32 opt) {
    u32 size;
    u32 addr;
    s32 result;

    if (szByte == 0) {
        size = 0x10;
    } else {
        size = (szByte + 0xf) & ~0xf;
    }
    if (size >= 0x7fff0) {
        return 0;
    }
    if (is4x4comp != 0) {
        result = RangeListAlloc(&data_02173238, &data_0217323c, &addr, size);
    } else {
        result = RangeListAlloc(&data_02173234.mMgrNrm, &data_0217323c, &addr, size);
    }
    if (result == 0) {
        return 0;
    }
    return ((size >> 4) << 16) | ((addr >> 3) & 0xffff) | (is4x4comp << 31);
}

s32 NNS_GfdFreeLnkTexVram(u32 texKey) {
    u32 addr;
    u32 size;
    u32 is4x4;
    s32 result;

    addr = (texKey & 0xffff) << 3;
    size = ((texKey & 0x7fff0000) >> 16) << 4;
    is4x4 = (texKey & 0x80000000) >> 31;
    if (size != 0) {
        if (is4x4 != 0) {
            result = RangeListFree(&data_02173238, &data_0217323c, addr, size);
        } else {
            result = RangeListFree(&data_02173234.mMgrNrm, &data_0217323c, addr, size);
        }
        if (result != 0) {
            return 0;
        }
        return 1;
    }
    return 2;
}

void NNS_GfdResetLnkTexVramState(void) {
    LnkTexBankData t[4] = {{0x20000, 0, 0}, {0x20000, 0, 0}, {0x20000, 0, 0}, {0x20000, 0, 0}};
    u32 rest4x4;
    LnkTexBankData *bank;
    u32 bankNo;
    u32 restNrm;
    u32 indexSize;
    u32 amount;
    u32 bank0NrmAddr;
    u32 bank2NrmAddr;
    u32 bank2Nrm;

    rest4x4 = data_02173234.mSzByteFor4x4;
    restNrm = data_02173234.mSzByte;
    indexSize = rest4x4 >> 1;
    restNrm = restNrm - (rest4x4 + indexSize);
    bank = t;
    for (bankNo = 0; bankNo < 4; bankNo++) {
        if (bankNo == 0 || bankNo == 2) {
            if (bank->mSzFree != 0 && rest4x4 != 0) {
                amount = bank->mSzFree;
                if (amount > rest4x4) {
                    amount = rest4x4;
                }
                bank->mSz4x4 += amount;
                rest4x4 -= amount;
                bank->mSzFree -= amount;
            }
        }
        bank++;
    }
    t[1].mSzFree -= indexSize;
    bank = t;
    for (bankNo = 0; bankNo < 4; bankNo++) {
        if (bank->mSzFree != 0 && restNrm != 0) {
            amount = bank->mSzFree;
            if (amount > restNrm) {
                amount = restNrm;
            }
            bank->mSzNrm += amount;
            restNrm -= amount;
            bank->mSzFree -= amount;
        }
        bank++;
    }
    RangeListInit(&data_02173234.mMgrNrm);
    RangeListInit(&data_02173238);
    data_02173234.mBlockList = RangeEntryPoolInit(data_02173234.mWorkHead, data_02173234.mSzByteManagementWork >> 4);
    if (t[0].mSz4x4 != 0) {
        RangeListAdd(&data_02173238, &data_0217323c, 0, t[0].mSz4x4);
    }
    bank0NrmAddr = t[0].mSz4x4;
    if (t[0].mSzNrm != 0) {
        RangeListAdd(&data_02173234.mMgrNrm, &data_0217323c, bank0NrmAddr, t[0].mSzNrm);
    }
    if (t[2].mSz4x4 != 0) {
        RangeListAdd(&data_02173238, &data_0217323c, 0x40000, t[2].mSz4x4);
    }
    bank2Nrm = t[2].mSzNrm;
    bank2NrmAddr = t[2].mSz4x4 + 0x40000;
    if (bank2Nrm != 0) {
        RangeListAdd(&data_02173234.mMgrNrm, &data_0217323c, bank2NrmAddr, bank2Nrm);
    }
    if (t[3].mSzNrm != 0) {
        RangeListAdd(&data_02173234.mMgrNrm, &data_0217323c, 0x60000, t[3].mSzNrm);
    }
    if (t[1].mSzNrm != 0) {
        RangeListAdd(&data_02173234.mMgrNrm, &data_0217323c, indexSize + 0x20000, t[1].mSzNrm);
    }
}
