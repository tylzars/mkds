#include "code_0214c1bc.h"
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
    u32 i;
    u32 o;

    i = GX_ResetBankForTex();
    o = i * 6;
    gTextureLoadBankMask = i;
    gTextureLoadFirstBase = *(u16 *) (gTextureBlockTable + o) << 12;
    gTextureLoadSecondBase = *(u16 *) (data_021616ce + o) << 12;
    gTextureLoadFirstSize = *(u16 *) (data_021616d0 + o) << 12;
}

void GX_LoadTex(const void *a, u32 b, u32 c) {
    u8 *p;
    u32 q;
    u32 n;
    u8 *dst;

    p = (u8 *) gTextureLoadSecondBase;
    if (p == 0) {
        dst = (u8 *) gTextureLoadFirstBase + b;
    } else {
        q = gTextureLoadFirstSize;
        if (b + c < q) {
            dst = (u8 *) gTextureLoadFirstBase + b;
        } else if (b >= q) {
            dst = p + b - q;
        } else {
            n = q - b;
            dst = (u8 *) gTextureLoadFirstBase + b;
            if (data_0216f074[0] != -1 && n > 0x30) {
                MI_DmaCopy32(data_0216f074[0], a, dst, n);
            } else {
                MemCopyWords(a, dst, n);
            }
            if (data_0216f074[0] != -1) {
                MI_DmaCopy32Async(data_0216f074[0], (const u8 *) a + n, p, c - n, 0, 0);
            } else {
                MemCopyWords((const u8 *) a + n, p, c - n);
            }
            return;
        }
    }
    if (data_0216f074[0] != -1) {
        MI_DmaCopy32Async(data_0216f074[0], a, dst, c, 0, 0);
    } else {
        MemCopyWords(a, dst, c);
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
    s32 v = GX_ResetBankForTexPltt();
    gTexturePaletteLoadBankMask = v;
    gTexturePaletteLoadBase = (u8 *) (gTexturePaletteBaseTable[v >> 4] << 12);
}

void GX_LoadTexPltt(const void *a, u32 b, u32 c) {
    u8 *p = gTexturePaletteLoadBase + b;
    if (data_0216f074[0] != -1) {
        MI_DmaCopy32Async(data_0216f074[0], a, p, c, 0, 0);
    } else {
        MemCopyWords(a, p, c);
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
    u32 v = GX_ResetBankForClearImage();
    gClearImageLoadBankMask = v;
    switch (v) {
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

void GX_LoadClearImageColor(const void *a, u32 b) {
    u8 *p = gClearImageLoadBase;
    if (data_0216f074[0] != -1) {
        MI_DmaCopy32Async(data_0216f074[0], a, p, b, 0, 0);
    } else {
        MemCopyWords(a, p, b);
    }
}

void GX_LoadClearImageDepth(const void *a, u32 b) {
    u8 *p = gClearImageLoadBase + 0x20000;
    if (data_0216f074[0] != -1) {
        MI_DmaCopy32Async(data_0216f074[0], a, p, b, 0, 0);
    } else {
        MemCopyWords(a, p, b);
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
