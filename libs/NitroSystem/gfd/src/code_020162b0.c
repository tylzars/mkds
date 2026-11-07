#include "code_020162b0.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/unk_02173000.h"

void NNS_GfdInitFrmPlttVramManager(u32 szByte, s32 useAsDefault) {
    data_02173214.mSzTotal = szByte;
    NNS_GfdResetFrmPlttVramState();
    if (useAsDefault != 0) {
        data_021619f4 = (u32(*)(s32, s32, s32)) NNS_GfdAllocFrmPlttVram;
        data_021619f8 = (void (*)(void *)) NNS_GfdFreeFrmPlttVram;
    }
}

u32 NNS_GfdAllocFrmPlttVram(u32 szByte, s32 bPltt4, s32 allocFrom) {
    u32 addr = 0;
    u32 increase;
    u32 current;
    u32 alignment;
    u32 found;
    if (szByte == 0) {
        szByte = 8;
    } else {
        szByte = (szByte + 7) & ~7;
    }
    if (szByte >= 0x7fff8) {
        return 0;
    }
    if (allocFrom == 1) {
        current = data_02173214.mLoAddr;
        if (bPltt4 != 0) {
            alignment = (8 - (current & 7)) & 7;
        } else {
            alignment = (16 - (current & 0xf)) & 0xf;
        }
        increase = szByte + alignment;
        if (data_02173214.mHiAddr - current >= increase) {
            found = current + increase;
            if (bPltt4 != 0 && found > 0x10000) {
                found = 0;
            } else {
                addr = current + alignment;
                found = 1;
                data_02173214.mLoAddr += increase;
            }
        } else {
            found = 0;
        }
    } else {
        current = data_02173214.mHiAddr;
        if (current >= szByte) {
            increase = current - szByte;
            if (bPltt4 != 0) {
                alignment = increase & 7;
            } else {
                alignment = increase & 0xf;
            }
            increase = szByte + alignment;
            if (current - data_02173214.mLoAddr >= increase) {
                if (bPltt4 != 0 && current > 0x10000) {
                    found = 0;
                } else {
                    found = 1;
                    data_02173214.mHiAddr -= increase;
                    addr = data_02173214.mHiAddr;
                }
                goto done;
            }
        }
        found = 0;
    }
done:
    if (found != 0) {
        return ((szByte >> 3) << 16) | ((addr >> 3) & 0xffff);
    }
    return 0;
}

// Frame managers do not free single blocks.
s32 NNS_GfdFreeFrmPlttVram(u32 plttKey) {
    return 0;
}

void NNS_GfdResetFrmPlttVramState(void) {
    data_02173214.mLoAddr = 0;
    data_02173214.mHiAddr = data_02173214.mSzTotal;
}
