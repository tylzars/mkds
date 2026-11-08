#include "Main/Unknown/code_0204db48.h"
#include "Main/Unknown/code_0204f814.h"
#include "Main/Unknown/code_02050300.h"
#include "Main/Unknown/code_02050080.h"
#include "Main/Unknown/code_0204df5c.h"
#include "Main/Unknown/code_0204e000.h"
#include "Main/Unknown/code_0204f000.h"
#include "Main/Unknown/code_02051658.h"
#include "Main/Unknown/code_020529b8.h"
#include "Main/Unknown/code_02059878.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0214d018.h"

#pragma thumb on

s32 func_0204dd24(u16 a) {
    s32 result = 0;
    Unk0217aa00 *g = data_0217aa00;

    switch (g->mUnk_000c) {
        case 29:
            if (func_020501b0(a) == 0) {
                func_02050e60(5);
            }
            if (func_0204ff14(a, NULL) != 0) {
                StartRequestEndScan();
            } else {
                func_02050e60(5);
            }
            break;
        case 10:
            g->mUnk_1692 = g->mUnk_1692 + 1;
            if (data_0217aa00->mUnk_1692 > 0x4b0) {
                func_02050e60(5);
                return 3;
            }
            break;
        case 7:
            g->mRequestPending = 0;
            break;
        case 30: {
            s32 scanEntryIndex;
            g->mUnk_1692 = g->mUnk_1692 + 1;
            if (data_0217aa00->mUnk_1692 > 0x4b0) {
                func_02050e60(5);
            } else {
                scanEntryIndex = FindScanEntryIndex(a);
                if (scanEntryIndex != -1) {
                    data_0217aa00->mScanEntryIndex = scanEntryIndex;
                    StartRequestEndScan();
                }
            }
            break;
        }
    }
    g = data_0217aa00;
    if (g->mRequestPending != 0) {
        return 0;
    }
    switch (g->mUnk_000c) {
        case 7:
            g->mUnk_0454 |= 0x40;
            EndScan();
            break;
        case 9:
            SetupScanConnect();
            break;
        case 28:
            g->mUnk_1692 = 0;
            func_0204e474();
            break;
        case 30:
            StartRequestEndScan();
            break;
        case 33:
            if (g->mScanEntryIndex == -1) {
                func_0204e03c(a);
            } else {
                func_0204e03c((u16) g->mScanEntryIndex);
            }
            break;
        case 34:
            if (g->mUnk_169c != 0) {
                if (g->mScanEntryIndex == -1) {
                    func_0204dfe0(a);
                } else {
                    func_0204dfe0((u16) g->mScanEntryIndex);
                }
            } else {
                result = 2;
            }
            break;
        case 35:
            StartCloseScanConnect();
            break;
        case 1:
            g->mUnk_1692 = 0;
        case 2:
            if (*(u16 *) 0x027ffc40 == 2) {
                func_0204df90();
            } else {
                StartConnect(NULL, NULL, NULL, (s32(*)()) func_0204df5c, NULL);
            }
            break;
        case 31:
            if (g->mUnk_1692 < 0x3c) {
                g->mUnk_1692 = g->mUnk_1692 + 1;
            } else {
                g->mUnk_000c = 32;
            }
            break;
        case 26:
        case 32:
            func_02052ecc();
            break;
        case 36:
            StartConnect(NULL, NULL, NULL, (s32(*)()) func_0204df5c, NULL);
            break;
        case 10:
            StartMP();
            break;
        case 11:
            g->mUnk_0004 = 6;
            func_02059878();
            result = 1;
            break;
    }
    return result;
}

u8 CompactMaskBits(u8 mask) {
    u8 packed = mask & 1;
    u32 i = 1;
    u32 nextBit = 1;

    for (; i < 8; i++) {
        if (((1 << i) & mask) != 0) {
            packed = packed | (1 << nextBit);
            nextBit++;
        }
    }
    return packed;
}

s32 func_0204dc8c(void) {
    BOOL result = FALSE;
    Unk0217aa00 *g = data_0217aa00;
    u32 a = g->mUnk_1695;
    u8 childMask = g->mUnk_0044.mChildMask;

    if (a == (a & childMask)) {
        result = TRUE;
    } else if (g->mUnk_1692 > 0x708) {
        if (childMask == 0) {
            func_02050e60(5);
        } else {
            data_0217aa00->mUnk_1695 = CompactMaskBits(childMask);
            result = TRUE;
        }
    } else {
        g->mUnk_1692 = g->mUnk_1692 + 1;
    }
    return result;
}

s32 func_0204db6c(void) {
    BOOL result = FALSE;
    switch (data_0217aa00->mUnk_0004) {
        case 2:
            data_0217aa00->mUnk_0004 = 5;
            break;
        case 5:
            break;
        case 10:
            return 1;
        default:
            return 3;
    }
    if (data_0217aa00->mRequestPending != 0) {
        return 0;
    }
    switch (data_0217aa00->mUnk_000c) {
        case 22:
            func_0204e128();
            break;
        case 24:
            func_0204e0bc();
            break;
        case 25:
            func_0204e090();
            break;
        case 27:
            func_02052ecc();
            break;
        case 36:
            SetLifeTime(0x14);
            break;
        case 3:
            FillParentParameter(1);
            SetParentParameter();
            break;
        case 4:
            func_0204f814();
            FillParentParameter(1);
            SetParentParameter();
            break;
        case 5:
            StartParent(NULL);
            break;
        case 6:
            data_0217aa00->mUnk_1695 = CompactMaskBits(data_0217aa00->mUnk_1695);
            data_0217aa00->mUnk_1692 = 0;
            StartMP();
            break;
        case 11:
        case 15:
            if (func_0204dc8c() != 0) {
                func_02059878();
                result = TRUE;
            }
            break;
    }
    return result;
}

#pragma thumb off

s32 func_0204db48(FSArchive *archive, void *dst, u32 src, u32 length) {
    MI_CpuCopy8((const void *) src, dst, length);
    return 0;
}
