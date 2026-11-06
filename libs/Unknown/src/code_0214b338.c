#include "code_0214b338.h"
#include "Main/Unknown/code_02148000.h"
#include "code_02148950.h"
#include "code_02149e90.h"
#include "code_0214c778.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/unk_02180000.h"

void GX_BeginLoadBGExtPltt(void) {
    s32 v;

    v = GX_ResetBankForBGExtPltt();
    gBgExtPaletteLoadBankMask = v;
    switch (v) {
        case 0:
            break;
        case 0x10:
            gBgExtPaletteLoadBase = 0x6880000;
            gBgExtPaletteLoadBaseOffset = 0;
            break;
        case 0x40:
            gBgExtPaletteLoadBase = 0x6894000;
            gBgExtPaletteLoadBaseOffset = 0x4000;
            break;
        case 0x20:
        case 0x60:
            gBgExtPaletteLoadBase = 0x6890000;
            gBgExtPaletteLoadBaseOffset = 0;
            break;
    }
}

void GX_LoadBGExtPltt(const void *a, u32 b, u32 c) {
    u32 d;

    d = gBgExtPaletteLoadBase + b - gBgExtPaletteLoadBaseOffset;
    if (data_0216f074[0] != -1) {
        MI_DmaCopy32Async(data_0216f074[0], a, (void *) d, c, 0, 0);
    } else {
        MIi_CpuCopy32(a, (void *) d, c);
    }
}

void GX_EndLoadBGExtPltt(void) {
    if (data_0216f074[0] != -1) {
        MI_WaitDma(data_0216f074[0]);
    }
    GX_SetBankForBGExtPltt(gBgExtPaletteLoadBankMask);
    gBgExtPaletteLoadBankMask = 0;
    gBgExtPaletteLoadBase = 0;
    gBgExtPaletteLoadBaseOffset = 0;
}

void GX_BeginLoadOBJExtPltt(void) {
    s32 v;

    v = GX_ResetBankForOBJExtPltt();
    gObjExtPaletteLoadBankMask = v;
    if (v == 0) {
        return;
    }
    switch (v) {
        case 0x20:
            gObjExtPaletteLoadBase = 0x6890000;
            break;
        case 0x40:
            gObjExtPaletteLoadBase = 0x6894000;
            break;
    }
}

void GX_LoadOBJExtPltt(const void *a, u32 b, u32 c) {
    u32 d;

    d = gObjExtPaletteLoadBase + b;
    if (data_0216f074[0] != -1) {
        MI_DmaCopy32Async(data_0216f074[0], a, (void *) d, c, 0, 0);
    } else {
        MIi_CpuCopy32(a, (void *) d, c);
    }
}

void GX_EndLoadOBJExtPltt(void) {
    if (data_0216f074[0] != -1) {
        MI_WaitDma(data_0216f074[0]);
    }
    GX_SetBankForOBJExtPltt(gObjExtPaletteLoadBankMask);
    gObjExtPaletteLoadBankMask = 0;
    gObjExtPaletteLoadBase = 0;
}

void GXS_BeginLoadBGExtPltt(void) {
    gSubBgExtPaletteLoadBankMask = GX_ResetBankForSubBGExtPltt();
}

void GXS_LoadBGExtPltt(const void *a, u32 b, u32 c) {
    if (data_0216f074[0] != -1) {
        MI_DmaCopy32Async(data_0216f074[0], a, (void *) (b + 0x6898000), c, 0, 0);
    } else {
        MIi_CpuCopy32(a, (void *) (b + 0x6898000), c);
    }
}

void GXS_EndLoadBGExtPltt(void) {
    if (data_0216f074[0] != -1) {
        MI_WaitDma(data_0216f074[0]);
    }
    GX_SetBankForSubBGExtPltt(gSubBgExtPaletteLoadBankMask);
    gSubBgExtPaletteLoadBankMask = 0;
}

void GXS_BeginLoadOBJExtPltt(void) {
    gSubObjExtPaletteLoadBankMask = GX_ResetBankForSubOBJExtPltt();
}

void GXS_LoadOBJExtPltt(const void *a, u32 b, u32 c) {
    if (data_0216f074[0] != -1) {
        MI_DmaCopy32Async(data_0216f074[0], a, (void *) (b + 0x68a0000), c, 0, 0);
    } else {
        MIi_CpuCopy32(a, (void *) (b + 0x68a0000), c);
    }
}

void GXS_EndLoadOBJExtPltt(void) {
    if (data_0216f074[0] != -1) {
        MI_WaitDma(data_0216f074[0]);
    }
    GX_SetBankForSubOBJExtPltt(gSubObjExtPaletteLoadBankMask);
    gSubObjExtPaletteLoadBankMask = 0;
}
