#include "Main/Unknown/code_02055730.h"

#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_0204f814.h"
#include "Main/Unknown/code_02000000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_020497f0.h"
#include "Main/Unknown/code_0204db40.h"
#include "Main/Unknown/code_0204db48.h"
#include "Main/Unknown/code_0204e000.h"
#include "Main/Unknown/code_0204f000.h"
#include "Main/Unknown/code_02050300.h"
#include "Main/Unknown/code_02051658.h"
#include "Main/Unknown/code_020529b8.h"
#include "Main/Unknown/code_02054f58.h"
#include "Main/Unknown/code_02055710.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02165000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "code_0200eddc.h"
#include "code_02148950.h"
#include "code_0214a390.h"
#include "code_0214b824.h"
#include "code_0214d018.h"
#include "registers.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02060000.h"
#include "Main/Unknown/code_02060004.h"
#include "Main/Unknown/unk_021759c0.h"

#pragma thumb on

u8 func_02056208(void) {
    u8 cupIndex;
    s32 lowestValue;
    u8 engineClass;
    s32 recordValue;

    lowestValue = 7;
    for (cupIndex = 0; cupIndex < 8; cupIndex++) {
        for (engineClass = 0; engineClass < 4; engineClass++) {
            recordValue = func_02060364(cupIndex, engineClass);
            if (recordValue == 9 || recordValue < lowestValue) {
                lowestValue = recordValue;
            }
            if (lowestValue == 9 || lowestValue < 5) {
                return 0;
            }
        }
    }
    switch (lowestValue) {
        case 5:
            return 1;
        case 6:
            return 2;
        case 7:
            return 3;
        default:
            return 0;
    }
}

#pragma thumb off

void InitDispCap(void *heap) {
    gDispCap = HeapAlloc(heap, 0x10);
    if (gRaceSetup->mRaceKind == RACE_KIND_START_GP || gRaceSetup->mRaceKind == RACE_KIND_AWARD) {
        gDispCap->mOamBuffer = HeapAllocAligned(heap, 0x400, 0x20);
    } else {
        gDispCap->mOamBuffer = NULL;
    }
    gDispCap->mFlags = 0;
    gDispCap->mBlendMin = 0;
    gDispCap->mBlendFactor = 0x1000;
    gDispCap->mMode = 0;
    if (data_02175614.mUnk_00 == 0) {
        gDispCap->mMode = 0;
    }
}

u32 ClearDispCapPointer(void) {
    u32 pointerAddress;
    u32 nullValue;
    pointerAddress = (u32) &gDispCap;
    nullValue = 0u;
    *(u32 *) ((pointerAddress) + (0)) = nullValue;
    return pointerAddress;
}

static inline u32 func_02055808_inline(void) {
    if (data_0217aa00 == NULL) {
        return 0;
    }
    return data_0217aa00->mUnk_0000;
}

static inline s32 func_02055808_inline2(void) {
    BOOL r = FALSE;
    if (func_02055808_inline() != 0 && data_0217aa00->mUnk_0004 != 13) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_02055808_inline3(void) {
    BOOL r = FALSE;
    if (func_02055808_inline2() && !(data_0217aa00->mUnk_0454 & 0x80)) {
        r = TRUE;
    }
    return r;
}

static inline s32 func_02055808_inline4(void) {
    BOOL r = FALSE;
    if (func_02055808_inline3() && data_0217aa00->mUnk_0008 != 9) {
        r = TRUE;
    }
    return r;
}

void SetDispCapMode(s32 mode) {
    gDispCap->mMode = mode;
    if (data_02175614.mUnk_00 == 0) {
        gDispCap->mMode = 0;
    }
}

void SetupDispCapMode1(void) {
    DispCapOamEntry *oamBuffer;
    s32 affineMatrix[4];
    s32 clearIndex;
    s32 column;
    s32 row;
    s32 entryIndex;
    DispCapOamEntry *oamEntry;

    oamBuffer = gDispCap->mOamBuffer;
    if (oamBuffer == NULL) {
        return;
    }
    affineMatrix[0] = 0x1000;
    affineMatrix[3] = 0x1000;
    affineMatrix[1] = 0;
    affineMatrix[2] = 0;
    G2x_SetBGyAffine_(&reg_G2S_DB_BG2PA, affineMatrix, 0, 0, 0, 0);
    for (clearIndex = 0; clearIndex < 0x80; clearIndex++) {
        oamBuffer[clearIndex].mUnk_00 = 0;
        oamBuffer[clearIndex].mUnk_04 = 0;
    }
    entryIndex = 0;
    for (row = 0; row < 3; row++) {
        for (column = 0; column < 4; column++) {
            oamEntry = &oamBuffer[entryIndex++];
            oamEntry->mUnk_00 = (u8) (0x40 * row) | 0xc0000c00 | ((column * 0x40 & 0x1ff) << 16);
            oamEntry->mUnk_04_h = (0x100 * row + column * 8) | 0xf000;
        }
    }
    DC_FlushRange(oamBuffer, 0x400);
    GXS_LoadOAM(oamBuffer, 0, 0x400);
    VBlankIntrWait();
    gDispCap->mFlags &= ~1;
    reg_GX_POWCNT = reg_GX_POWCNT | 0x8000;
    ToggleDispCapBanks();
}

void SetupDispCap(void) {
    switch (gDispCap->mMode) {
        case 1:
            SetupDispCapMode1();
            break;
        case 2:
            GX_SetGraphicsMode(0xe, 0, 1);
            break;
    }
}

// Alternates the VRAM banks used for the display capture each time it runs.
void ToggleDispCapBanks(void) {
    u32 captureBits;
    u32 powerBit;

    GX_ResetBankForSubBG();
    GX_ResetBankForSubOBJ();
    if (gDispCap->mFlags & 1) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | 0x300;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1000;
        GX_SetBankForLCDC(4);
        GX_SetBankForSubOBJ(8);
        gDispCap->mFlags &= ~1;
        captureBits = 2;
        powerBit = 1;
    } else {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | 0x300;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x400;
        GX_SetBankForSubBG(4);
        GX_SetBankForLCDC(8);
        gDispCap->mFlags |= 1;
        captureBits = 3;
        powerBit = 0;
    }
    reg_GX_POWCNT = (reg_GX_POWCNT & ~0x8000) | (powerBit << 15);
    reg_GX_DISPCAPCNT = 0x80300010 | (captureBits << 16);
}

// Writes the capture blend weights; with a 0 it also moves the blend factor toward 0 (bit 2 of mFlags set) or 0x1000.
void AdvanceDispCapBlend(s32 a) {
    u8 weight;

    weight = gDispCap->mBlendMin + (((16 - gDispCap->mBlendMin) * gDispCap->mBlendFactor) >> 12);
    reg_GX_DISPCAPCNT = weight | (0xc0330000 | (u8) (16 - weight) << 8);
    if (a != 0) {
        return;
    }
    if (gDispCap->mFlags & 2) {
        if (gDispCap->mBlendFactor <= 0) {
            return;
        }
        gDispCap->mBlendFactor -= 0x802;
        if (gDispCap->mBlendFactor < 0) {
            gDispCap->mBlendFactor = 0;
        }
    } else {
        if (gDispCap->mBlendFactor >= 0x1000) {
            return;
        }
        gDispCap->mBlendFactor = gDispCap->mBlendFactor + 0x19a;
        if (gDispCap->mBlendFactor > 0x1000) {
            gDispCap->mBlendFactor = 0x1000;
        }
    }
}

void AdvanceDispCap(s32 a) {
    switch (gDispCap->mMode) {
        case 1:
            if (a == 0) {
                ToggleDispCapBanks();
            }
            break;
        case 2:
            AdvanceDispCapBlend(a);
            break;
    }
    if (!(gDispCap->mFlags & 4)) {
        return;
    }
    if (AreBrightnessFadesClear() == 0) {
        return;
    }
    gDispCap->mFlags &= ~4;
    gDispCap->mFlags &= ~8;
}

void StartDispCapBlend(u8 blendMin) {
    if (gDispCap->mMode != 2) {
        return;
    }
    gDispCap->mFlags |= 2;
    gDispCap->mBlendFactor = 0x1000;
    gDispCap->mBlendMin = blendMin;
}

static inline s32 func_02055b1c_inline(void) {
    BOOL r = FALSE;
    u32 t;
    if (data_0217aa00 == NULL) {
        t = 0;
        r = FALSE;
    } else {
        t = data_0217aa00->mUnk_0000;
    }
    if (t != 0 && data_0217aa00->mUnk_0004 != 13) {
        r = TRUE;
    }
    return r;
}

void StopDispCapBlend(void) {
    if (gDispCap->mMode == 2) {
        gDispCap->mFlags &= ~2;
    }
}

void func_02055c18(u32 frameCount) {
    if (func_02049838() != 2) {
        return;
    }
    gDispCap->mFlags |= 4;
    StartFadeToFadedNegativeOneScreen(frameCount, 1);
}

void func_02055bd4(u32 frameCount) {
    if (func_02049838() != 2) {
        return;
    }
    gDispCap->mFlags |= 4;
    StartFadeToClearNegativeOneScreen(frameCount, 1);
}

BOOL func_02055b1c(void) {
    if (func_02055b1c_inline()) {
        if (func_0204ffbc() != 0) {
            return (data_0217aa00->mUnk_15bc_view.mUnk_0c->mUnk_06_0 & 4) != 0;
        }
        return FALSE;
    }
    return (gDispCap->mFlags & 8) != 0;
}

BOOL func_02055afc(void) {
    return (gDispCap->mFlags & 8) != 0;
}

void func_02055a94(void) {
    if (func_02055808_inline2() != 0 && func_02055808_inline() != 1) {
        return;
    }
    gDispCap->mFlags |= 8;
}

s32 RunRecordScene(SceneNumbers *sceneNumbers) {
    SceneCallbacks recordSceneCallbacks = gRecordSceneCallbacks;

    RunScene(sceneNumbers, &recordSceneCallbacks);
    return 0;
}

void func_020559ec(const void *entryName, s32 entryIndex, s32 keepMask) {
    u8 keptBits;

    keptBits = data_0217aa00->mUnk_043d & keepMask;
    MI_CpuCopy8(entryName, &data_0217aa00->mUnk_045c[entryIndex], 0x14);
    data_0217aa00->mUnk_043d = keptBits | (1 << entryIndex);
}

s32 func_02055808(s32 a) {
    BOOL result;

    result = FALSE;
    if (data_0217aa00->mRequestPending != 0) {
        return result;
    }
    if (func_02055808_inline4()) {
        return 3;
    }
    switch (data_0217aa00->mUnk_000c) {
        case 0:
        case 21:
            data_0217aa00->mUnk_0454 &= ~0x40;
            data_0217aa00->mUnk_0004 = 1;
            Initialize();
            break;
        case 1:
            StartRomArchiveTransfer();
            break;
        case 2:
        case 36:
            if (a != 0) {
                SetLifeTime(0x14);
            } else {
                result = TRUE;
                data_0217aa00->mUnk_0004 = 3;
                StartScan(1, NULL, NULL);
            }
            break;
        case 3:
            MeasureChannel(0);
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
            StartMP();
            break;
        case 11:
            data_0217aa00->mUnk_0004 = 2;
            data_0217aa00->mUnk_0044.mUnk_3e = 0;
            result = TRUE;
            data_0217aa00->mUnk_008b &= ~8;
            break;
        default:
            func_020533a0();
            break;
    }
    return result;
}

s32 func_0205579c(s32 a, s32 b) {
    if (a != 0) {
        if (b != 0) {
            return func_0204e1a8(a);
        }
        return func_02055808(a);
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2) {
        return func_0204e1a8(a);
    }
    return func_02055808(a);
}

s32 func_02055730(u16 a) {
    if (data_0217aa00->mUnk_0436 & 1) {
        data_0217aa00->mUnk_0436 &= ~1;
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2 || func_0204fe90(a) != 0) {
        return func_0204dd24(a);
    }
    return func_02055564(a);
}
