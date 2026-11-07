#include "gx_load3d.h"
#include "code_0214c778.h"
#include "Main/Unknown/code_02148000.h"
#include "code_02148950.h"
#include "code_02149e90.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/unk_02180000.h"

void GX_BeginLoadTex(void) {
    u32 mask;
    u32 row;

    mask = GX_ResetBankForTex();
    row = mask * 6;
    gTextureLoadBankMask = mask;
    gTextureLoadFirstBase = *(u16 *) (gTextureBlockTable + row) << 12;
    gTextureLoadSecondBase = *(u16 *) (data_021616ce + row) << 12;
    gTextureLoadFirstSize = *(u16 *) (data_021616d0 + row) << 12;
}

void GX_LoadTex(const void *src, u32 offset, u32 size) {
    u8 *second;
    u32 firstSize;
    u32 firstCount;
    u8 *dest;

    second = (u8 *) gTextureLoadSecondBase;
    if (second == 0) {
        dest = (u8 *) gTextureLoadFirstBase + offset;
    } else {
        firstSize = gTextureLoadFirstSize;
        if (offset + size < firstSize) {
            dest = (u8 *) gTextureLoadFirstBase + offset;
        } else if (offset >= firstSize) {
            dest = second + offset - firstSize;
        } else {
            firstCount = firstSize - offset;
            dest = (u8 *) gTextureLoadFirstBase + offset;
            if (data_0216f074[0] != -1 && firstCount > 0x30) {
                MI_DmaCopy32(data_0216f074[0], src, dest, firstCount);
            } else {
                MIi_CpuCopy32(src, dest, firstCount);
            }
            if (data_0216f074[0] != -1) {
                MI_DmaCopy32Async(data_0216f074[0], (const u8 *) src + firstCount, second, size - firstCount, 0, 0);
            } else {
                MIi_CpuCopy32((const u8 *) src + firstCount, second, size - firstCount);
            }
            return;
        }
    }
    if (data_0216f074[0] != -1) {
        MI_DmaCopy32Async(data_0216f074[0], src, dest, size, 0, 0);
    } else {
        MIi_CpuCopy32(src, dest, size);
    }
}

void GX_EndLoadTex(void) {
    if (data_0216f074[0] != -1) {
        MI_WaitDma(data_0216f074[0]);
    }
    GX_SetBankForTex(gTextureLoadBankMask);
    gTextureLoadFirstSize = 0;
    gTextureLoadSecondBase = 0;
    gTextureLoadFirstBase = 0;
    gTextureLoadBankMask = 0;
}

void GX_BeginLoadTexPltt(void) {
    s32 mask = GX_ResetBankForTexPltt();
    gTexturePaletteLoadBankMask = mask;
    gTexturePaletteLoadBase = (u8 *) (gTexturePaletteBaseTable[mask >> 4] << 12);
}

void GX_LoadTexPltt(const void *src, u32 offset, u32 size) {
    u8 *dest = gTexturePaletteLoadBase + offset;
    if (data_0216f074[0] != -1) {
        MI_DmaCopy32Async(data_0216f074[0], src, dest, size, 0, 0);
    } else {
        MIi_CpuCopy32(src, dest, size);
    }
}

void GX_EndLoadTexPltt(void) {
    if (data_0216f074[0] != -1) {
        MI_WaitDma(data_0216f074[0]);
    }
    GX_SetBankForTexPltt(gTexturePaletteLoadBankMask);
    gTexturePaletteLoadBankMask = 0;
    gTexturePaletteLoadBase = 0;
}

void GX_BeginLoadClearImage(void) {
    u32 mask = GX_ResetBankForClearImage();
    gClearImageLoadBankMask = mask;
    switch (mask) {
        case 2:
        case 3:
            gClearImageLoadBase = (u8 *) 0x6800000;
            break;
        case 8:
        case 12:
            gClearImageLoadBase = (u8 *) 0x6840000;
            break;
        case 1:
            gClearImageLoadBase = (u8 *) 0x67e0000;
            break;
        case 4:
            gClearImageLoadBase = (u8 *) 0x6820000;
            break;
    }
}

void GX_LoadClearImageColor(const void *src, u32 size) {
    u8 *dest = gClearImageLoadBase;
    if (data_0216f074[0] != -1) {
        MI_DmaCopy32Async(data_0216f074[0], src, dest, size, 0, 0);
    } else {
        MIi_CpuCopy32(src, dest, size);
    }
}

void GX_LoadClearImageDepth(const void *src, u32 size) {
    u8 *dest = gClearImageLoadBase + 0x20000;
    if (data_0216f074[0] != -1) {
        MI_DmaCopy32Async(data_0216f074[0], src, dest, size, 0, 0);
    } else {
        MIi_CpuCopy32(src, dest, size);
    }
}

void GX_EndLoadClearImage(void) {
    if (data_0216f074[0] != -1) {
        MI_WaitDma(data_0216f074[0]);
    }
    GX_SetBankForClearImage(gClearImageLoadBankMask);
    gClearImageLoadBankMask = 0;
    gClearImageLoadBase = 0;
}
