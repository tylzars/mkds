#include "code_02015f98.h"
#include "Main/Unknown/unk_02161000.h"

void NNSi_GfdSetTexNrmSearchArray(int idx1st, int idx2nd, int idx3rd, int idx4th, int idx5th) {
    data_02161a04[0] = &data_02161a18[idx1st];
    data_02161a04[1] = &data_02161a18[idx2nd];
    data_02161a04[2] = &data_02161a18[idx3rd];
    data_02161a04[3] = &data_02161a18[idx4th];
    data_02161a04[4] = &data_02161a18[idx5th];
}

void NNS_GfdInitFrmTexVramManager(u16 numBanks, BOOL useAsDefault) {
    if (numBanks <= 2) {
        NNSi_GfdSetTexNrmSearchArray(4, 3, 2, 0, 1);
    } else {
        NNSi_GfdSetTexNrmSearchArray(4, 3, 0, 2, 1);
    }
    data_02173210 = numBanks;
    NNS_GfdResetFrmTexVramState();
    if (useAsDefault != 0) {
        data_021619ec = (u32(*)(s32, s32, s32)) NNS_GfdAllocFrmTexVram;
        data_021619f0 = (void (*)(void *)) NNS_GfdFreeFrmTexVram;
    }
}

void NNS_GfdResetFrmTexVramState(void) {
    u32 numBanks;
    s32 i;
    NNSGfdFrmTexRegionState *region;

    numBanks = data_02173210;
    region = data_02161a18;
    if (numBanks > 1) {
        numBanks++;
    }
    for (i = 0; i < 5; i++) {
        if (i < (s32) numBanks) {
            region->mBActive = 1;
        } else {
            region->mBActive = 0;
        }
        if (region->mBHalfSize != 0) {
            region->mHead = 0;
            region->mTail = 0x10000;
        } else {
            region->mHead = 0;
            region->mTail = 0x20000;
        }
        region++;
    }
}

u32 NNS_GfdAllocFrmTexVram(u32 szByte, u32 is4x4comp, u32 opt) {
    u32 addr;
    u32 size;
    u32 found;
    s32 i;
    volatile NNSGfdFrmTexRegionState *region;
    NNSGfdFrmTexRegionState *palRegion;
    u32 halfSize;

    if (szByte == 0) {
        size = 0x10;
    } else {
        size = (szByte + 0xf) & ~0xf;
    }
    if (size >= 0x7fff0) {
        return 0;
    }
    if (is4x4comp != 0) {
        halfSize = size >> 1;
        for (i = 0; i < 2; i++) {
            region = data_021619fc[i];
            if (region->mBActive != 0 && region->mTail - region->mHead >= size) {
                switch (region->mIndex) {
                    case 0:
                        palRegion = &data_02161a18[1];
                        break;
                    case 3:
                        palRegion = &data_02161a18[2];
                        break;
                    default:
                        palRegion = 0;
                        break;
                }
                if (palRegion->mBActive != 0 && palRegion->mTail - palRegion->mHead >= halfSize) {
                    found = 1;
                    addr = region->mHead;
                    region->mHead = addr + size;
                    palRegion->mHead += halfSize;
                    addr += region->mBaseAddress;
                    goto done;
                }
            }
        }
        found = 0;
    } else {
        s32 j;
        volatile NNSGfdFrmTexRegionState *normRegion;

        for (j = 0; j < 5; j++) {
            normRegion = data_02161a04[j];
            if (normRegion->mBActive != 0 && normRegion->mTail - normRegion->mHead >= size) {
                normRegion->mTail -= size;
                found = 1;
                addr = normRegion->mTail + normRegion->mBaseAddress;
                goto done;
            }
        }
        found = 0;
    }
done:
    if (found != 0) {
        return ((addr >> 3) & 0xffff) | ((size >> 4) << 16) | (is4x4comp << 31);
    }
    return 0;
}

// Frame managers do not free single blocks.
s32 NNS_GfdFreeFrmTexVram(u32 texKey) {
    return 0;
}
