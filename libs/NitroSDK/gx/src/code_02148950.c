#include "code_02148950.h"

#include "Main/Unknown/unk_0216f000.h"
#include "Main/Unknown/unk_02180000.h"
#include "code_0200cd1c.h"
#include "code_0200fc8c.h"
#include "code_0214c778.h"
#include "Main/Unknown/code_0200c000.h"
#include "Main/Unknown/code_0214d000.h"
#include "00/code_02188720.h"
#include "Main/Unknown/code_02148cd0.h"
#include "Main/Unknown/code_02148d24.h"
#include "code_0200fe74.h"
#include "registers.h"

u8 gDispOn[4] = {1, 0, 0, 0};

void GX_VRAMCNT_SetLCDC_(u32 lcdc) {
    if (lcdc & 0x1) {
        reg_GX_VRAMCNT_A = 0x80;
    }
    if (lcdc & 0x2) {
        reg_GX_VRAMCNT_B = 0x80;
    }
    if (lcdc & 0x4) {
        reg_GX_VRAMCNT_C = 0x80;
    }
    if (lcdc & 0x8) {
        reg_GX_VRAMCNT_D = 0x80;
    }
    if (lcdc & 0x10) {
        reg_GX_VRAMCNT_E = 0x80;
    }
    if (lcdc & 0x20) {
        reg_GX_VRAMCNT_F = 0x80;
    }
    if (lcdc & 0x40) {
        reg_GX_VRAMCNT_G = 0x80;
    }
    if (lcdc & 0x80) {
        reg_GX_VRAMCNT_H = 0x80;
    }
    if (lcdc & 0x100) {
        reg_GX_VRAMCNT_I = 0x80;
    }
}

void GX_SetBankForBG(s32 bg) {
    gVramBankGroups[0] = (gVramBankGroups[0] | gVramBankGroups[1]) & ~bg;
    gVramBankGroups[1] = bg;
    switch (bg) {
        case 8:
            reg_GX_VRAMCNT_D = 0x81;
            break;
        case 12:
            reg_GX_VRAMCNT_D = 0x89;
        case 4:
            reg_GX_VRAMCNT_C = 0x81;
            break;
        case 14:
            reg_GX_VRAMCNT_D = 0x91;
        case 6:
            reg_GX_VRAMCNT_C = 0x89;
        case 2:
            reg_GX_VRAMCNT_B = 0x81;
            break;
        case 15:
            reg_GX_VRAMCNT_D = 0x99;
        case 7:
            reg_GX_VRAMCNT_C = 0x91;
        case 3:
            reg_GX_VRAMCNT_B = 0x89;
        case 1:
            reg_GX_VRAMCNT_A = 0x81;
            break;
        case 11:
            reg_GX_VRAMCNT_A = 0x81;
            reg_GX_VRAMCNT_B = 0x89;
            reg_GX_VRAMCNT_D = 0x91;
            break;
        case 13:
            reg_GX_VRAMCNT_D = 0x91;
        case 5:
            reg_GX_VRAMCNT_A = 0x81;
            reg_GX_VRAMCNT_C = 0x89;
            break;
        case 9:
            reg_GX_VRAMCNT_A = 0x81;
            reg_GX_VRAMCNT_D = 0x89;
            break;
        case 10:
            reg_GX_VRAMCNT_B = 0x81;
            reg_GX_VRAMCNT_D = 0x89;
            break;
        case 0x70:
            reg_GX_VRAMCNT_G = 0x99;
        case 0x30:
            reg_GX_VRAMCNT_F = 0x91;
        case 16:
            reg_GX_VRAMCNT_E = 0x81;
            break;
        case 0x50:
            reg_GX_VRAMCNT_G = 0x91;
            reg_GX_VRAMCNT_E = 0x81;
            break;
        case 0x60:
            reg_GX_VRAMCNT_G = 0x89;
        case 32:
            reg_GX_VRAMCNT_F = 0x81;
            break;
        case 0x40:
            reg_GX_VRAMCNT_G = 0x81;
            break;
    }
    GX_VRAMCNT_SetLCDC_(gVramBankGroups[0]);
}

void GX_SetBankForOBJ(s32 obj) {
    gVramBankGroups[0] = (gVramBankGroups[0] | gVramBankGroups[2]) & ~obj;
    gVramBankGroups[2] = obj;
    switch (obj) {
        case 0x40:
            reg_GX_VRAMCNT_G = 0x82;
            break;
        case 0:
            break;
        case 3:
            reg_GX_VRAMCNT_B = 0x8a;
        case 1:
            reg_GX_VRAMCNT_A = 0x82;
            break;
        case 2:
            reg_GX_VRAMCNT_B = 0x82;
            break;
        case 0x70:
            reg_GX_VRAMCNT_G = 0x9a;
        case 0x30:
            reg_GX_VRAMCNT_F = 0x92;
        case 0x10:
            reg_GX_VRAMCNT_E = 0x82;
            break;
        case 0x50:
            reg_GX_VRAMCNT_G = 0x92;
            reg_GX_VRAMCNT_E = 0x82;
            break;
        case 0x60:
            reg_GX_VRAMCNT_G = 0x8a;
        case 0x20:
            reg_GX_VRAMCNT_F = 0x82;
            break;
    }
    GX_VRAMCNT_SetLCDC_(gVramBankGroups[0]);
}

void GX_SetBankForBGExtPltt(s32 bgExtPltt) {
    gVramBankGroups[0] = (gVramBankGroups[0] | gVramBankGroups[7]) & ~bgExtPltt;
    gVramBankGroups[7] = bgExtPltt;
    switch (bgExtPltt) {
        case 0:
            reg_GX_DISPCNT &= ~0x40000000;
            break;
        case 0x10:
            reg_GX_DISPCNT |= 0x40000000;
            reg_GX_VRAMCNT_E = 0x84;
            break;
        case 0x40:
            reg_GX_DISPCNT |= 0x40000000;
            reg_GX_VRAMCNT_G = 0x8c;
            break;
        case 0x60:
            reg_GX_VRAMCNT_G = 0x8c;
        case 0x20:
            reg_GX_VRAMCNT_F = 0x84;
            reg_GX_DISPCNT |= 0x40000000;
            break;
    }
    GX_VRAMCNT_SetLCDC_(gVramBankGroups[0]);
}

void GX_SetBankForOBJExtPltt(u32 objExtPltt) {
    gVramBankGroups[0] = (gVramBankGroups[0] | gVramBankGroups[8]) & ~objExtPltt;
    gVramBankGroups[8] = objExtPltt;
    switch (objExtPltt) {
        case 0x20:
            reg_GX_DISPCNT |= 0x80000000;
            reg_GX_VRAMCNT_F = 0x85;
            break;
        case 0x40:
            reg_GX_DISPCNT |= 0x80000000;
            reg_GX_VRAMCNT_G = 0x85;
            break;
        case 0:
            reg_GX_DISPCNT &= ~0x80000000;
            break;
    }
    GX_VRAMCNT_SetLCDC_(gVramBankGroups[0]);
}

void GX_SetBankForTex(u32 tex) {
    gVramBankGroups[0] = (gVramBankGroups[0] | gVramBankGroups[4]) & ~tex;
    gVramBankGroups[4] = tex;
    if (tex == 0) {
        reg_G3X_DISP3DCNT &= 0xcffe;
    } else {
        reg_G3X_DISP3DCNT = (reg_G3X_DISP3DCNT & ~0x3000) | 0x1;
        switch (tex) {
            case 5:
                reg_GX_VRAMCNT_A = 0x83;
                reg_GX_VRAMCNT_C = 0x8b;
                break;
            case 9:
                reg_GX_VRAMCNT_A = 0x83;
                reg_GX_VRAMCNT_D = 0x8b;
                break;
            case 10:
                reg_GX_VRAMCNT_B = 0x83;
                reg_GX_VRAMCNT_D = 0x8b;
                break;
            case 11:
                reg_GX_VRAMCNT_A = 0x83;
                reg_GX_VRAMCNT_B = 0x8b;
                reg_GX_VRAMCNT_D = 0x93;
                break;
            case 13:
                reg_GX_VRAMCNT_A = 0x83;
                reg_GX_VRAMCNT_C = 0x8b;
                reg_GX_VRAMCNT_D = 0x93;
                break;
            case 8:
                reg_GX_VRAMCNT_D = 0x83;
                break;
            case 12:
                reg_GX_VRAMCNT_D = 0x8b;
            case 4:
                reg_GX_VRAMCNT_C = 0x83;
                break;
            case 14:
                reg_GX_VRAMCNT_D = 0x93;
            case 6:
                reg_GX_VRAMCNT_C = 0x8b;
            case 2:
                reg_GX_VRAMCNT_B = 0x83;
                break;
            case 15:
                reg_GX_VRAMCNT_D = 0x9b;
            case 7:
                reg_GX_VRAMCNT_C = 0x93;
            case 3:
                reg_GX_VRAMCNT_B = 0x8b;
            case 1:
                reg_GX_VRAMCNT_A = 0x83;
                break;
        }
    }
    GX_VRAMCNT_SetLCDC_(gVramBankGroups[0]);
}

void GX_SetBankForTexPltt(s32 texPltt) {
    gVramBankGroups[0] = (gVramBankGroups[0] | gVramBankGroups[5]) & ~texPltt;
    gVramBankGroups[5] = texPltt;
    switch (texPltt) {
        case 0:
            break;
        case 0x40:
            reg_GX_VRAMCNT_G = 0x83;
            break;
        case 0x60:
            reg_GX_VRAMCNT_G = 0x8b;
        case 0x20:
            reg_GX_VRAMCNT_F = 0x83;
            break;
        case 0x70:
            reg_GX_VRAMCNT_G = 0x9b;
        case 0x30:
            reg_GX_VRAMCNT_F = 0x93;
        case 0x10:
            reg_GX_VRAMCNT_E = 0x83;
            break;
    }
    GX_VRAMCNT_SetLCDC_(gVramBankGroups[0]);
}

void GX_SetBankForClearImage(u32 clrImg) {
    gVramBankGroups[0] = (gVramBankGroups[0] | gVramBankGroups[6]) & ~clrImg;
    gVramBankGroups[6] = clrImg;
    switch (clrImg) {
        case 3:
            reg_GX_VRAMCNT_A = 0x93;
        case 2:
            reg_GX_VRAMCNT_B = 0x9b;
            reg_G3X_DISP3DCNT |= 0x4000;
            break;
        case 12:
            reg_GX_VRAMCNT_C = 0x93;
        case 8:
            reg_GX_VRAMCNT_D = 0x9b;
            reg_G3X_DISP3DCNT |= 0x4000;
            break;
        case 0:
            reg_G3X_DISP3DCNT &= ~0x4000;
            break;
        case 1:
            reg_GX_VRAMCNT_A = 0x9b;
            reg_G3X_DISP3DCNT |= 0x4000;
            break;
        case 4:
            reg_GX_VRAMCNT_C = 0x9b;
            reg_G3X_DISP3DCNT |= 0x4000;
            break;
    }
    GX_VRAMCNT_SetLCDC_(gVramBankGroups[0]);
}

void GX_SetBankForARM7(s32 arm7) {
    gVramBankGroups[0] = (gVramBankGroups[0] | gVramBankGroups[3]) & ~arm7;
    gVramBankGroups[3] = arm7;
    switch (arm7) {
        case 0:
            break;
        case 12:
            reg_GX_VRAMCNT_D = 0x8a;
            reg_GX_VRAMCNT_C = 0x82;
            break;
        case 4:
            reg_GX_VRAMCNT_C = 0x82;
            break;
        case 8:
            reg_GX_VRAMCNT_D = 0x82;
            break;
    }
    GX_VRAMCNT_SetLCDC_(gVramBankGroups[0]);
}

void GX_SetBankForLCDC(u32 lcdc) {
    gVramBankGroups[0] = gVramBankGroups[0] | lcdc;
    GX_VRAMCNT_SetLCDC_(lcdc);
}

void GX_SetBankForSubBG(s32 subBg) {
    gVramBankGroups[0] = (gVramBankGroups[0] | gVramBankGroups[9]) & ~subBg;
    gVramBankGroups[9] = subBg;
    switch (subBg) {
        case 0:
            break;
        case 4:
            reg_GX_VRAMCNT_C = 0x84;
            break;
        case 0x180:
            reg_GX_VRAMCNT_I = 0x81;
        case 0x80:
            reg_GX_VRAMCNT_H = 0x81;
            break;
    }
    GX_VRAMCNT_SetLCDC_(gVramBankGroups[0]);
}

void GX_SetBankForSubOBJ(u32 subObj) {
    gVramBankGroups[0] = (gVramBankGroups[0] | gVramBankGroups[10]) & ~subObj;
    gVramBankGroups[10] = subObj;
    if (subObj != 0) {
        switch (subObj) {
            case 0x100:
                reg_GX_VRAMCNT_I = 0x82;
                break;
            case 8:
                reg_GX_VRAMCNT_D = 0x84;
                break;
        }
    }
    GX_VRAMCNT_SetLCDC_(gVramBankGroups[0]);
}

void GX_SetBankForSubBGExtPltt(u32 subBgExtPltt) {
    gVramBankGroups[0] = (gVramBankGroups[0] | gVramBankGroups[11]) & ~subBgExtPltt;
    gVramBankGroups[11] = subBgExtPltt;
    if (subBgExtPltt != 0) {
        if (subBgExtPltt == 0x80) {
            reg_GXS_DB_DISPCNT |= 0x40000000;
            reg_GX_VRAMCNT_H = 0x82;
        }
    } else {
        reg_GXS_DB_DISPCNT &= ~0x40000000;
    }
    GX_VRAMCNT_SetLCDC_(gVramBankGroups[0]);
}

void GX_SetBankForSubOBJExtPltt(u32 subObjExtPltt) {
    gVramBankGroups[0] = (gVramBankGroups[0] | gVramBankGroups[12]) & ~subObjExtPltt;
    gVramBankGroups[12] = subObjExtPltt;
    if (subObjExtPltt != 0) {
        if (subObjExtPltt == 0x100) {
            reg_GXS_DB_DISPCNT |= 0x80000000;
            reg_GX_VRAMCNT_I = 0x83;
        }
    } else {
        reg_GXS_DB_DISPCNT &= ~0x80000000;
    }
    GX_VRAMCNT_SetLCDC_(gVramBankGroups[0]);
}

u16 resetBankForX_(u16 *group) {
    u16 mask;

    mask = *group;
    *group = 0;
    gVramBankGroups[0] = gVramBankGroups[0] | mask;
    GX_VRAMCNT_SetLCDC_(mask);
    return mask;
}

u16 GX_ResetBankForBGExtPltt(void) {
    reg_GX_DISPCNT &= ~0x40000000;
    return resetBankForX_(&data_021802be);
}

u16 GX_ResetBankForOBJExtPltt(void) {
    reg_GX_DISPCNT &= ~0x80000000;
    return resetBankForX_(&data_021802c0);
}

u16 GX_ResetBankForTex(void) {
    return resetBankForX_(&data_021802b8);
}

u16 GX_ResetBankForTexPltt(void) {
    return resetBankForX_(&data_021802ba);
}

u16 GX_ResetBankForClearImage(void) {
    return resetBankForX_(&data_021802bc);
}

u16 GX_ResetBankForSubBG(void) {
    return resetBankForX_(&data_021802c2);
}

u16 GX_ResetBankForSubOBJ(void) {
    return resetBankForX_(&data_021802c4);
}

u16 GX_ResetBankForSubBGExtPltt(void) {
    reg_GXS_DB_DISPCNT &= ~0x40000000;
    return resetBankForX_(&data_021802c6);
}

u16 GX_ResetBankForSubOBJExtPltt(void) {
    reg_GXS_DB_DISPCNT &= ~0x80000000;
    return resetBankForX_(&data_021802c8);
}

u32 disableBankForX_(u16 *group) {
    u32 mask;

    mask = *group;
    *group = 0;
    if (mask & 0x1) {
        reg_GX_VRAMCNT_A = 0;
    }
    if (mask & 0x2) {
        reg_GX_VRAMCNT_B = 0;
    }
    if (mask & 0x4) {
        reg_GX_VRAMCNT_C = 0;
    }
    if (mask & 0x8) {
        reg_GX_VRAMCNT_D = 0;
    }
    if (mask & 0x10) {
        reg_GX_VRAMCNT_E = 0;
    }
    if (mask & 0x20) {
        reg_GX_VRAMCNT_F = 0;
    }
    if (mask & 0x40) {
        reg_GX_VRAMCNT_G = 0;
    }
    if (mask & 0x80) {
        reg_GX_VRAMCNT_H = 0;
    }
    if (mask & 0x100) {
        reg_GX_VRAMCNT_I = 0;
    }
    OSi_UnlockVram((u16) mask, gVramLockId);
    return mask;
}

u32 GX_DisableBankForBG(void) {
    return disableBankForX_(&data_021802b2);
}

u32 GX_DisableBankForOBJ(void) {
    return disableBankForX_(&data_021802b4);
}

u32 GX_DisableBankForBGExtPltt(void) {
    reg_GX_DISPCNT &= ~0x40000000;
    return disableBankForX_(&data_021802be);
}

u32 GX_DisableBankForOBJExtPltt(void) {
    reg_GX_DISPCNT &= ~0x80000000;
    return disableBankForX_(&data_021802c0);
}

u32 GX_DisableBankForTex(void) {
    return disableBankForX_(&data_021802b8);
}

u32 GX_DisableBankForTexPltt(void) {
    return disableBankForX_(&data_021802ba);
}

u32 GX_DisableBankForClearImage(void) {
    return disableBankForX_(&data_021802bc);
}

u32 GX_DisableBankForARM7(void) {
    return disableBankForX_(&data_021802b6);
}

u32 GX_DisableBankForLCDC(void) {
    return disableBankForX_(gVramBankGroups);
}

u32 GX_DisableBankForSubBG(void) {
    return disableBankForX_(&data_021802c2);
}

u32 GX_DisableBankForSubOBJ(void) {
    return disableBankForX_(&data_021802c4);
}

u32 GX_DisableBankForSubBGExtPltt(void) {
    reg_GXS_DB_DISPCNT &= ~0x40000000;
    return disableBankForX_(&data_021802c6);
}

u32 GX_DisableBankForSubOBJExtPltt(void) {
    reg_GXS_DB_DISPCNT &= ~0x80000000;
    return disableBankForX_(&data_021802c8);
}

u32 GX_GetBankForTex(void) {
    return gVramBankGroups[4];
}

u32 GX_GetSizeOfX_(u32 bits) {
    u32 size = 0;

    if (bits & 0x1) {
        size += 0x20000;
    }
    if (bits & 0x2) {
        size += 0x20000;
    }
    if (bits & 0x4) {
        size += 0x20000;
    }
    if (bits & 0x8) {
        size += 0x20000;
    }
    if (bits & 0x10) {
        size += 0x10000;
    }
    if (bits & 0x20) {
        size += 0x4000;
    }
    if (bits & 0x40) {
        size += 0x4000;
    }
    if (bits & 0x80) {
        size += 0x8000;
    }
    if (bits & 0x100) {
        size += 0x4000;
    }
    return size;
}

u32 GX_GetSizeOfOBJ(void) {
    return GX_GetSizeOfX_(gVramBankGroups[2]);
}

u32 GX_GetSizeOfSubOBJ(void) {
    return GX_GetSizeOfX_(gVramBankGroups[10]);
}

void GX_InitGXState(void) {
    gVramBankGroups[0] = 0;
    gVramBankGroups[1] = 0;
    gVramBankGroups[2] = 0;
    gVramBankGroups[3] = 0;
    gVramBankGroups[4] = 0;
    gVramBankGroups[5] = 0;
    gVramBankGroups[6] = 0;
    gVramBankGroups[7] = 0;
    gVramBankGroups[8] = 0;
    gVramBankGroups[9] = 0;
    gVramBankGroups[10] = 0;
    gVramBankGroups[11] = 0;
    gVramBankGroups[12] = 0;
    *(vu32 *) 0x4000240 = 0;
    reg_GX_VRAMCNT_E = 0;
    reg_GX_VRAMCNT_F = 0;
    reg_GX_VRAMCNT_G = 0;
    *(vu16 *) 0x4000248 = 0;
}

void GX_Init(void) {
    s32 lockResult;

    reg_GX_POWCNT |= 0x8000;
    reg_GX_POWCNT = (reg_GX_POWCNT & ~0x20e) | 0x20e;
    reg_GX_POWCNT |= 0x1;
    GX_InitGXState();
    while (gVramLockId == 0) {
        lockResult = OS_GetLockID();
        if (lockResult == -3) {
            OS_Terminate();
        }
        gVramLockId = lockResult;
    }
    reg_GX_DISPSTAT = 0;
    reg_GX_DISPCNT = 0;
    if (data_0216f074[0] != -1) {
        MI_DmaFill32(data_0216f074[0], (void *) 0x4000008, 0, 0x60);
        reg_GX_MASTER_BRIGHT = 0;
        MI_DmaFill32(data_0216f074[0], (void *) 0x4001000, 0, 0x70);
    } else {
        volatile u32 z0 = 0;
        volatile u32 z1;

        MIi_CpuClear32(z0, (void *) 0x4000008, 0x60);
        reg_GX_MASTER_BRIGHT = 0;
        z1 = 0;
        MIi_CpuClear32(z1, (void *) 0x4001000, 0x70);
    }
    reg_G2_BG2PA = 0x100;
    reg_G2_BG2PD = 0x100;
    reg_G2_BG3PA = 0x100;
    reg_G2_BG3PD = 0x100;
    reg_G2S_DB_BG2PA = 0x100;
    reg_G2S_DB_BG2PD = 0x100;
    reg_G2S_DB_BG3PA = 0x100;
    reg_G2S_DB_BG3PD = 0x100;
}

u32 GX_VBlankIntr(s32 enable) {
    u32 previous;

    previous = reg_GX_DISPSTAT & 0x8;
    if (enable != 0) {
        reg_GX_DISPSTAT |= 0x8;
    } else {
        reg_GX_DISPSTAT &= ~0x8;
    }
    return previous;
}

void GX_DispOff(void) {
    u32 cnt = reg_GX_DISPCNT;

    *(u16 *) gDispOn = 0;
    gSavedDispMode = (cnt & 0x30000) >> 16;
    reg_GX_DISPCNT = cnt & ~0x30000;
}

void GX_DispOn(void) {
    u32 mode;

    *(u16 *) gDispOn = 1;
    mode = gSavedDispMode;
    if (mode != 0) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x30000) | (mode << 16);
    } else {
        reg_GX_DISPCNT |= 0x10000;
    }
}

void GX_SetGraphicsMode(u16 dispMode, u32 bgMode, s32 bg0As) {
    u32 isDispOn;
    u32 dispCtrl;

    dispCtrl = reg_GX_DISPCNT;
    isDispOn = *(u16 *) gDispOn;
    gSavedDispMode = dispMode;
    if (isDispOn == 0) {
        dispMode = 0;
    }
    reg_GX_DISPCNT = ((dispCtrl & 0xfff0fff0) | (dispMode << 16) | bgMode) | (bg0As << 3);
    if (gSavedDispMode == 0) {
        *(u16 *) gDispOn = 0;
    }
}
