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

u8 gDispOn[4] = {1, 0, 0, 0};

void GX_VRAMCNT_SetLCDC_(u32 lcdc) {
    if (lcdc & 0x1) {
        *(vu8 *) 0x4000240 = 0x80;
    }
    if (lcdc & 0x2) {
        *(vu8 *) 0x4000241 = 0x80;
    }
    if (lcdc & 0x4) {
        *(vu8 *) 0x4000242 = 0x80;
    }
    if (lcdc & 0x8) {
        *(vu8 *) 0x4000243 = 0x80;
    }
    if (lcdc & 0x10) {
        *(vu8 *) 0x4000244 = 0x80;
    }
    if (lcdc & 0x20) {
        *(vu8 *) 0x4000245 = 0x80;
    }
    if (lcdc & 0x40) {
        *(vu8 *) 0x4000246 = 0x80;
    }
    if (lcdc & 0x80) {
        *(vu8 *) 0x4000248 = 0x80;
    }
    if (lcdc & 0x100) {
        *(vu8 *) 0x4000249 = 0x80;
    }
}

void GX_SetBankForBG(s32 bg) {
    ((u16 *) gVramBankGroups)[0] = (((u16 *) gVramBankGroups)[0] | ((u16 *) gVramBankGroups)[1]) & ~bg;
    ((u16 *) gVramBankGroups)[1] = bg;
    switch (bg) {
        case 8:
            *(vu8 *) 0x4000243 = 0x81;
            break;
        case 12:
            *(vu8 *) 0x4000243 = 0x89;
        case 4:
            *(vu8 *) 0x4000242 = 0x81;
            break;
        case 14:
            *(vu8 *) 0x4000243 = 0x91;
        case 6:
            *(vu8 *) 0x4000242 = 0x89;
        case 2:
            *(vu8 *) 0x4000241 = 0x81;
            break;
        case 15:
            *(vu8 *) 0x4000243 = 0x99;
        case 7:
            *(vu8 *) 0x4000242 = 0x91;
        case 3:
            *(vu8 *) 0x4000241 = 0x89;
        case 1:
            *(vu8 *) 0x4000240 = 0x81;
            break;
        case 11:
            *(vu8 *) 0x4000240 = 0x81;
            *(vu8 *) 0x4000241 = 0x89;
            *(vu8 *) 0x4000243 = 0x91;
            break;
        case 13:
            *(vu8 *) 0x4000243 = 0x91;
        case 5:
            *(vu8 *) 0x4000240 = 0x81;
            *(vu8 *) 0x4000242 = 0x89;
            break;
        case 9:
            *(vu8 *) 0x4000240 = 0x81;
            *(vu8 *) 0x4000243 = 0x89;
            break;
        case 10:
            *(vu8 *) 0x4000241 = 0x81;
            *(vu8 *) 0x4000243 = 0x89;
            break;
        case 0x70:
            *(vu8 *) 0x4000246 = 0x99;
        case 0x30:
            *(vu8 *) 0x4000245 = 0x91;
        case 16:
            *(vu8 *) 0x4000244 = 0x81;
            break;
        case 0x50:
            *(vu8 *) 0x4000246 = 0x91;
            *(vu8 *) 0x4000244 = 0x81;
            break;
        case 0x60:
            *(vu8 *) 0x4000246 = 0x89;
        case 32:
            *(vu8 *) 0x4000245 = 0x81;
            break;
        case 0x40:
            *(vu8 *) 0x4000246 = 0x81;
            break;
    }
    GX_VRAMCNT_SetLCDC_(((u16 *) gVramBankGroups)[0]);
}

void GX_SetBankForOBJ(s32 obj) {
    ((u16 *) gVramBankGroups)[0] = (((u16 *) gVramBankGroups)[0] | ((u16 *) gVramBankGroups)[2]) & ~obj;
    ((u16 *) gVramBankGroups)[2] = obj;
    switch (obj) {
        case 0x40:
            *(vu8 *) 0x4000246 = 0x82;
            break;
        case 0:
            break;
        case 3:
            *(vu8 *) 0x4000241 = 0x8a;
        case 1:
            *(vu8 *) 0x4000240 = 0x82;
            break;
        case 2:
            *(vu8 *) 0x4000241 = 0x82;
            break;
        case 0x70:
            *(vu8 *) 0x4000246 = 0x9a;
        case 0x30:
            *(vu8 *) 0x4000245 = 0x92;
        case 0x10:
            *(vu8 *) 0x4000244 = 0x82;
            break;
        case 0x50:
            *(vu8 *) 0x4000246 = 0x92;
            *(vu8 *) 0x4000244 = 0x82;
            break;
        case 0x60:
            *(vu8 *) 0x4000246 = 0x8a;
        case 0x20:
            *(vu8 *) 0x4000245 = 0x82;
            break;
    }
    GX_VRAMCNT_SetLCDC_(((u16 *) gVramBankGroups)[0]);
}

void GX_SetBankForBGExtPltt(s32 bgExtPltt) {
    ((u16 *) gVramBankGroups)[0] = (((u16 *) gVramBankGroups)[0] | ((u16 *) gVramBankGroups)[7]) & ~bgExtPltt;
    ((u16 *) gVramBankGroups)[7] = bgExtPltt;
    switch (bgExtPltt) {
        case 0:
            *(vu32 *) 0x4000000 &= ~0x40000000;
            break;
        case 0x10:
            *(vu32 *) 0x4000000 |= 0x40000000;
            *(vu8 *) 0x4000244 = 0x84;
            break;
        case 0x40:
            *(vu32 *) 0x4000000 |= 0x40000000;
            *(vu8 *) 0x4000246 = 0x8c;
            break;
        case 0x60:
            *(vu8 *) 0x4000246 = 0x8c;
        case 0x20:
            *(vu8 *) 0x4000245 = 0x84;
            *(vu32 *) 0x4000000 |= 0x40000000;
            break;
    }
    GX_VRAMCNT_SetLCDC_(((u16 *) gVramBankGroups)[0]);
}

void GX_SetBankForOBJExtPltt(u32 objExtPltt) {
    ((u16 *) gVramBankGroups)[0] = (((u16 *) gVramBankGroups)[0] | ((u16 *) gVramBankGroups)[8]) & ~objExtPltt;
    ((u16 *) gVramBankGroups)[8] = objExtPltt;
    switch (objExtPltt) {
        case 0x20:
            *(vu32 *) 0x4000000 |= 0x80000000;
            *(vu8 *) 0x4000245 = 0x85;
            break;
        case 0x40:
            *(vu32 *) 0x4000000 |= 0x80000000;
            *(vu8 *) 0x4000246 = 0x85;
            break;
        case 0:
            *(vu32 *) 0x4000000 &= ~0x80000000;
            break;
    }
    GX_VRAMCNT_SetLCDC_(((u16 *) gVramBankGroups)[0]);
}

void GX_SetBankForTex(u32 tex) {
    ((u16 *) gVramBankGroups)[0] = (((u16 *) gVramBankGroups)[0] | ((u16 *) gVramBankGroups)[4]) & ~tex;
    ((u16 *) gVramBankGroups)[4] = tex;
    if (tex == 0) {
        *(vu16 *) 0x4000060 &= 0xcffe;
    } else {
        *(vu16 *) 0x4000060 = (*(vu16 *) 0x4000060 & ~0x3000) | 0x1;
        switch (tex) {
            case 5:
                *(vu8 *) 0x4000240 = 0x83;
                *(vu8 *) 0x4000242 = 0x8b;
                break;
            case 9:
                *(vu8 *) 0x4000240 = 0x83;
                *(vu8 *) 0x4000243 = 0x8b;
                break;
            case 10:
                *(vu8 *) 0x4000241 = 0x83;
                *(vu8 *) 0x4000243 = 0x8b;
                break;
            case 11:
                *(vu8 *) 0x4000240 = 0x83;
                *(vu8 *) 0x4000241 = 0x8b;
                *(vu8 *) 0x4000243 = 0x93;
                break;
            case 13:
                *(vu8 *) 0x4000240 = 0x83;
                *(vu8 *) 0x4000242 = 0x8b;
                *(vu8 *) 0x4000243 = 0x93;
                break;
            case 8:
                *(vu8 *) 0x4000243 = 0x83;
                break;
            case 12:
                *(vu8 *) 0x4000243 = 0x8b;
            case 4:
                *(vu8 *) 0x4000242 = 0x83;
                break;
            case 14:
                *(vu8 *) 0x4000243 = 0x93;
            case 6:
                *(vu8 *) 0x4000242 = 0x8b;
            case 2:
                *(vu8 *) 0x4000241 = 0x83;
                break;
            case 15:
                *(vu8 *) 0x4000243 = 0x9b;
            case 7:
                *(vu8 *) 0x4000242 = 0x93;
            case 3:
                *(vu8 *) 0x4000241 = 0x8b;
            case 1:
                *(vu8 *) 0x4000240 = 0x83;
                break;
        }
    }
    GX_VRAMCNT_SetLCDC_(((u16 *) gVramBankGroups)[0]);
}

void GX_SetBankForTexPltt(s32 texPltt) {
    ((u16 *) gVramBankGroups)[0] = (((u16 *) gVramBankGroups)[0] | ((u16 *) gVramBankGroups)[5]) & ~texPltt;
    ((u16 *) gVramBankGroups)[5] = texPltt;
    switch (texPltt) {
        case 0:
            break;
        case 0x40:
            *(vu8 *) 0x4000246 = 0x83;
            break;
        case 0x60:
            *(vu8 *) 0x4000246 = 0x8b;
        case 0x20:
            *(vu8 *) 0x4000245 = 0x83;
            break;
        case 0x70:
            *(vu8 *) 0x4000246 = 0x9b;
        case 0x30:
            *(vu8 *) 0x4000245 = 0x93;
        case 0x10:
            *(vu8 *) 0x4000244 = 0x83;
            break;
    }
    GX_VRAMCNT_SetLCDC_(((u16 *) gVramBankGroups)[0]);
}

void GX_SetBankForClearImage(u32 clrImg) {
    ((u16 *) gVramBankGroups)[0] = (((u16 *) gVramBankGroups)[0] | ((u16 *) gVramBankGroups)[6]) & ~clrImg;
    ((u16 *) gVramBankGroups)[6] = clrImg;
    switch (clrImg) {
        case 3:
            *(vu8 *) 0x4000240 = 0x93;
        case 2:
            *(vu8 *) 0x4000241 = 0x9b;
            *(vu16 *) 0x4000060 |= 0x4000;
            break;
        case 12:
            *(vu8 *) 0x4000242 = 0x93;
        case 8:
            *(vu8 *) 0x4000243 = 0x9b;
            *(vu16 *) 0x4000060 |= 0x4000;
            break;
        case 0:
            *(vu16 *) 0x4000060 &= ~0x4000;
            break;
        case 1:
            *(vu8 *) 0x4000240 = 0x9b;
            *(vu16 *) 0x4000060 |= 0x4000;
            break;
        case 4:
            *(vu8 *) 0x4000242 = 0x9b;
            *(vu16 *) 0x4000060 |= 0x4000;
            break;
    }
    GX_VRAMCNT_SetLCDC_(((u16 *) gVramBankGroups)[0]);
}

void GX_SetBankForARM7(s32 arm7) {
    ((u16 *) gVramBankGroups)[0] = (((u16 *) gVramBankGroups)[0] | ((u16 *) gVramBankGroups)[3]) & ~arm7;
    ((u16 *) gVramBankGroups)[3] = arm7;
    switch (arm7) {
        case 0:
            break;
        case 12:
            *(vu8 *) 0x4000243 = 0x8a;
            *(vu8 *) 0x4000242 = 0x82;
            break;
        case 4:
            *(vu8 *) 0x4000242 = 0x82;
            break;
        case 8:
            *(vu8 *) 0x4000243 = 0x82;
            break;
    }
    GX_VRAMCNT_SetLCDC_(((u16 *) gVramBankGroups)[0]);
}

void GX_SetBankForLCDC(u32 lcdc) {
    ((u16 *) gVramBankGroups)[0] = ((u16 *) gVramBankGroups)[0] | lcdc;
    GX_VRAMCNT_SetLCDC_(lcdc);
}

void GX_SetBankForSubBG(s32 subBg) {
    ((u16 *) gVramBankGroups)[0] = (((u16 *) gVramBankGroups)[0] | ((u16 *) gVramBankGroups)[9]) & ~subBg;
    ((u16 *) gVramBankGroups)[9] = subBg;
    switch (subBg) {
        case 0:
            break;
        case 4:
            *(vu8 *) 0x4000242 = 0x84;
            break;
        case 0x180:
            *(vu8 *) 0x4000249 = 0x81;
        case 0x80:
            *(vu8 *) 0x4000248 = 0x81;
            break;
    }
    GX_VRAMCNT_SetLCDC_(((u16 *) gVramBankGroups)[0]);
}

void GX_SetBankForSubOBJ(u32 subObj) {
    ((u16 *) gVramBankGroups)[0] = (((u16 *) gVramBankGroups)[0] | ((u16 *) gVramBankGroups)[10]) & ~subObj;
    ((u16 *) gVramBankGroups)[10] = subObj;
    if (subObj != 0) {
        switch (subObj) {
            case 0x100:
                *(vu8 *) 0x4000249 = 0x82;
                break;
            case 8:
                *(vu8 *) 0x4000243 = 0x84;
                break;
        }
    }
    GX_VRAMCNT_SetLCDC_(((u16 *) gVramBankGroups)[0]);
}

void GX_SetBankForSubBGExtPltt(u32 subBgExtPltt) {
    ((u16 *) gVramBankGroups)[0] = (((u16 *) gVramBankGroups)[0] | ((u16 *) gVramBankGroups)[11]) & ~subBgExtPltt;
    ((u16 *) gVramBankGroups)[11] = subBgExtPltt;
    if (subBgExtPltt != 0) {
        if (subBgExtPltt == 0x80) {
            *(vu32 *) 0x4001000 |= 0x40000000;
            *(vu8 *) 0x4000248 = 0x82;
        }
    } else {
        *(vu32 *) 0x4001000 &= ~0x40000000;
    }
    GX_VRAMCNT_SetLCDC_(((u16 *) gVramBankGroups)[0]);
}

void GX_SetBankForSubOBJExtPltt(u32 subObjExtPltt) {
    ((u16 *) gVramBankGroups)[0] = (((u16 *) gVramBankGroups)[0] | ((u16 *) gVramBankGroups)[12]) & ~subObjExtPltt;
    ((u16 *) gVramBankGroups)[12] = subObjExtPltt;
    if (subObjExtPltt != 0) {
        if (subObjExtPltt == 0x100) {
            *(vu32 *) 0x4001000 |= 0x80000000;
            *(vu8 *) 0x4000249 = 0x83;
        }
    } else {
        *(vu32 *) 0x4001000 &= ~0x80000000;
    }
    GX_VRAMCNT_SetLCDC_(((u16 *) gVramBankGroups)[0]);
}

u16 resetBankForX_(u16 *group) {
    u16 mask;

    mask = *group;
    *group = 0;
    ((u16 *) gVramBankGroups)[0] = ((u16 *) gVramBankGroups)[0] | mask;
    GX_VRAMCNT_SetLCDC_(mask);
    return mask;
}

u16 GX_ResetBankForBGExtPltt(void) {
    *(vu32 *) 0x4000000 &= ~0x40000000;
    return resetBankForX_(&data_021802be);
}

u16 GX_ResetBankForOBJExtPltt(void) {
    *(vu32 *) 0x4000000 &= ~0x80000000;
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
    *(vu32 *) 0x4001000 &= ~0x40000000;
    return resetBankForX_(&data_021802c6);
}

u16 GX_ResetBankForSubOBJExtPltt(void) {
    *(vu32 *) 0x4001000 &= ~0x80000000;
    return resetBankForX_(&data_021802c8);
}

u32 disableBankForX_(u16 *group) {
    u32 mask;

    mask = *group;
    *group = 0;
    if (mask & 0x1) {
        *(vu8 *) 0x4000240 = 0;
    }
    if (mask & 0x2) {
        *(vu8 *) 0x4000241 = 0;
    }
    if (mask & 0x4) {
        *(vu8 *) 0x4000242 = 0;
    }
    if (mask & 0x8) {
        *(vu8 *) 0x4000243 = 0;
    }
    if (mask & 0x10) {
        *(vu8 *) 0x4000244 = 0;
    }
    if (mask & 0x20) {
        *(vu8 *) 0x4000245 = 0;
    }
    if (mask & 0x40) {
        *(vu8 *) 0x4000246 = 0;
    }
    if (mask & 0x80) {
        *(vu8 *) 0x4000248 = 0;
    }
    if (mask & 0x100) {
        *(vu8 *) 0x4000249 = 0;
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
    *(vu32 *) 0x4000000 &= ~0x40000000;
    return disableBankForX_(&data_021802be);
}

u32 GX_DisableBankForOBJExtPltt(void) {
    *(vu32 *) 0x4000000 &= ~0x80000000;
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
    return disableBankForX_((u16 *) gVramBankGroups);
}

u32 GX_DisableBankForSubBG(void) {
    return disableBankForX_(&data_021802c2);
}

u32 GX_DisableBankForSubOBJ(void) {
    return disableBankForX_(&data_021802c4);
}

u32 GX_DisableBankForSubBGExtPltt(void) {
    *(vu32 *) 0x4001000 &= ~0x40000000;
    return disableBankForX_(&data_021802c6);
}

u32 GX_DisableBankForSubOBJExtPltt(void) {
    *(vu32 *) 0x4001000 &= ~0x80000000;
    return disableBankForX_(&data_021802c8);
}

u32 GX_GetBankForTex(void) {
    return ((u16 *) gVramBankGroups)[4];
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
    return GX_GetSizeOfX_(((u16 *) gVramBankGroups)[2]);
}

u32 GX_GetSizeOfSubOBJ(void) {
    return GX_GetSizeOfX_(((u16 *) gVramBankGroups)[10]);
}

void GX_InitGXState(void) {
    ((u16 *) gVramBankGroups)[0] = 0;
    ((u16 *) gVramBankGroups)[1] = 0;
    ((u16 *) gVramBankGroups)[2] = 0;
    ((u16 *) gVramBankGroups)[3] = 0;
    ((u16 *) gVramBankGroups)[4] = 0;
    ((u16 *) gVramBankGroups)[5] = 0;
    ((u16 *) gVramBankGroups)[6] = 0;
    ((u16 *) gVramBankGroups)[7] = 0;
    ((u16 *) gVramBankGroups)[8] = 0;
    ((u16 *) gVramBankGroups)[9] = 0;
    ((u16 *) gVramBankGroups)[10] = 0;
    ((u16 *) gVramBankGroups)[11] = 0;
    ((u16 *) gVramBankGroups)[12] = 0;
    *(vu32 *) 0x4000240 = 0;
    *(vu8 *) 0x4000244 = 0;
    *(vu8 *) 0x4000245 = 0;
    *(vu8 *) 0x4000246 = 0;
    *(vu16 *) 0x4000248 = 0;
}

void GX_Init(void) {
    s32 lockResult;

    *(vu16 *) 0x4000304 |= 0x8000;
    *(vu16 *) 0x4000304 = (*(vu16 *) 0x4000304 & ~0x20e) | 0x20e;
    *(vu16 *) 0x4000304 |= 0x1;
    GX_InitGXState();
    while (*(vu16 *) &gVramLockId == 0) {
        lockResult = OS_GetLockID();
        if (lockResult == -3) {
            OS_Terminate();
        }
        *(vu16 *) &gVramLockId = lockResult;
    }
    *(vu16 *) 0x4000004 = 0;
    *(vu32 *) 0x4000000 = 0;
    if (data_0216f074[0] != -1) {
        MI_DmaFill32(data_0216f074[0], (void *) 0x4000008, 0, 0x60);
        *(vu16 *) 0x400006c = 0;
        MI_DmaFill32(data_0216f074[0], (void *) 0x4001000, 0, 0x70);
    } else {
        volatile u32 z0 = 0;
        volatile u32 z1;

        MIi_CpuClear32(z0, (void *) 0x4000008, 0x60);
        *(vu16 *) 0x400006c = 0;
        z1 = 0;
        MIi_CpuClear32(z1, (void *) 0x4001000, 0x70);
    }
    *(vu16 *) 0x4000020 = 0x100;
    *(vu16 *) 0x4000026 = 0x100;
    *(vu16 *) 0x4000030 = 0x100;
    *(vu16 *) 0x4000036 = 0x100;
    *(vu16 *) 0x4001020 = 0x100;
    *(vu16 *) 0x4001026 = 0x100;
    *(vu16 *) 0x4001030 = 0x100;
    *(vu16 *) 0x4001036 = 0x100;
}

u32 GX_VBlankIntr(s32 enable) {
    u32 previous;

    previous = *(vu16 *) 0x4000004 & 0x8;
    if (enable != 0) {
        *(vu16 *) 0x4000004 |= 0x8;
    } else {
        *(vu16 *) 0x4000004 &= ~0x8;
    }
    return previous;
}

void GX_DispOff(void) {
    u32 cnt = *(vu32 *) 0x4000000;

    *(u16 *) gDispOn = 0;
    *(u16 *) gSavedDispMode = (cnt & 0x30000) >> 16;
    *(vu32 *) 0x4000000 = cnt & ~0x30000;
}

void GX_DispOn(void) {
    u32 mode;

    *(u16 *) gDispOn = 1;
    mode = *(u16 *) gSavedDispMode;
    if (mode != 0) {
        *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & ~0x30000) | (mode << 16);
    } else {
        *(vu32 *) 0x4000000 |= 0x10000;
    }
}

void GX_SetGraphicsMode(u16 dispMode, u32 bgMode, s32 bg0As) {
    u32 isDispOn;
    u32 dispCtrl;

    dispCtrl = *(vu32 *) 0x4000000;
    isDispOn = *(u16 *) gDispOn;
    *(u16 *) gSavedDispMode = dispMode;
    if (isDispOn == 0) {
        dispMode = 0;
    }
    *(vu32 *) 0x4000000 = ((dispCtrl & 0xfff0fff0) | (dispMode << 16) | bgMode) | (bg0As << 3);
    if (*(u16 *) gSavedDispMode == 0) {
        *(u16 *) gDispOn = 0;
    }
}
