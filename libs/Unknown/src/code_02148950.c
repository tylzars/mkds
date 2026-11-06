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

void WriteVramControlDirect(u32 a) {
    if (a & 0x1) {
        *(vu8 *) 0x4000240 = 0x80;
    }
    if (a & 0x2) {
        *(vu8 *) 0x4000241 = 0x80;
    }
    if (a & 0x4) {
        *(vu8 *) 0x4000242 = 0x80;
    }
    if (a & 0x8) {
        *(vu8 *) 0x4000243 = 0x80;
    }
    if (a & 0x10) {
        *(vu8 *) 0x4000244 = 0x80;
    }
    if (a & 0x20) {
        *(vu8 *) 0x4000245 = 0x80;
    }
    if (a & 0x40) {
        *(vu8 *) 0x4000246 = 0x80;
    }
    if (a & 0x80) {
        *(vu8 *) 0x4000248 = 0x80;
    }
    if (a & 0x100) {
        *(vu8 *) 0x4000249 = 0x80;
    }
}

void GX_SetBankForBG(s32 a) {
    ((u16 *) gVramBankGroups)[0] = (((u16 *) gVramBankGroups)[0] | ((u16 *) gVramBankGroups)[1]) & ~a;
    ((u16 *) gVramBankGroups)[1] = a;
    switch (a) {
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
    WriteVramControlDirect(((u16 *) gVramBankGroups)[0]);
}

void GX_SetBankForOBJ(s32 a) {
    ((u16 *) gVramBankGroups)[0] = (((u16 *) gVramBankGroups)[0] | ((u16 *) gVramBankGroups)[2]) & ~a;
    ((u16 *) gVramBankGroups)[2] = a;
    switch (a) {
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
    WriteVramControlDirect(((u16 *) gVramBankGroups)[0]);
}

void GX_SetBankForBGExtPltt(s32 a) {
    ((u16 *) gVramBankGroups)[0] = (((u16 *) gVramBankGroups)[0] | ((u16 *) gVramBankGroups)[7]) & ~a;
    ((u16 *) gVramBankGroups)[7] = a;
    switch (a) {
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
    WriteVramControlDirect(((u16 *) gVramBankGroups)[0]);
}

void GX_SetBankForOBJExtPltt(u32 a) {
    ((u16 *) gVramBankGroups)[0] = (((u16 *) gVramBankGroups)[0] | ((u16 *) gVramBankGroups)[8]) & ~a;
    ((u16 *) gVramBankGroups)[8] = a;
    switch (a) {
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
    WriteVramControlDirect(((u16 *) gVramBankGroups)[0]);
}

void GX_SetBankForTex(u32 a) {
    ((u16 *) gVramBankGroups)[0] = (((u16 *) gVramBankGroups)[0] | ((u16 *) gVramBankGroups)[4]) & ~a;
    ((u16 *) gVramBankGroups)[4] = a;
    if (a == 0) {
        *(vu16 *) 0x4000060 &= 0xcffe;
    } else {
        *(vu16 *) 0x4000060 = (*(vu16 *) 0x4000060 & ~0x3000) | 0x1;
        switch (a) {
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
    WriteVramControlDirect(((u16 *) gVramBankGroups)[0]);
}

void GX_SetBankForTexPltt(s32 a) {
    ((u16 *) gVramBankGroups)[0] = (((u16 *) gVramBankGroups)[0] | ((u16 *) gVramBankGroups)[5]) & ~a;
    ((u16 *) gVramBankGroups)[5] = a;
    switch (a) {
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
    WriteVramControlDirect(((u16 *) gVramBankGroups)[0]);
}

void GX_SetBankForClearImage(u32 a) {
    ((u16 *) gVramBankGroups)[0] = (((u16 *) gVramBankGroups)[0] | ((u16 *) gVramBankGroups)[6]) & ~a;
    ((u16 *) gVramBankGroups)[6] = a;
    switch (a) {
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
    WriteVramControlDirect(((u16 *) gVramBankGroups)[0]);
}

void GX_SetBankForARM7(s32 a) {
    ((u16 *) gVramBankGroups)[0] = (((u16 *) gVramBankGroups)[0] | ((u16 *) gVramBankGroups)[3]) & ~a;
    ((u16 *) gVramBankGroups)[3] = a;
    switch (a) {
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
    WriteVramControlDirect(((u16 *) gVramBankGroups)[0]);
}

void GX_SetBankForLCDC(u32 a) {
    ((u16 *) gVramBankGroups)[0] = ((u16 *) gVramBankGroups)[0] | a;
    WriteVramControlDirect(a);
}

void GX_SetBankForSubBG(s32 a) {
    ((u16 *) gVramBankGroups)[0] = (((u16 *) gVramBankGroups)[0] | ((u16 *) gVramBankGroups)[9]) & ~a;
    ((u16 *) gVramBankGroups)[9] = a;
    switch (a) {
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
    WriteVramControlDirect(((u16 *) gVramBankGroups)[0]);
}

void GX_SetBankForSubOBJ(u32 a) {
    ((u16 *) gVramBankGroups)[0] = (((u16 *) gVramBankGroups)[0] | ((u16 *) gVramBankGroups)[10]) & ~a;
    ((u16 *) gVramBankGroups)[10] = a;
    if (a != 0) {
        switch (a) {
            case 0x100:
                *(vu8 *) 0x4000249 = 0x82;
                break;
            case 8:
                *(vu8 *) 0x4000243 = 0x84;
                break;
        }
    }
    WriteVramControlDirect(((u16 *) gVramBankGroups)[0]);
}

void GX_SetBankForSubBGExtPltt(u32 a) {
    ((u16 *) gVramBankGroups)[0] = (((u16 *) gVramBankGroups)[0] | ((u16 *) gVramBankGroups)[11]) & ~a;
    ((u16 *) gVramBankGroups)[11] = a;
    if (a != 0) {
        if (a == 0x80) {
            *(vu32 *) 0x4001000 |= 0x40000000;
            *(vu8 *) 0x4000248 = 0x82;
        }
    } else {
        *(vu32 *) 0x4001000 &= ~0x40000000;
    }
    WriteVramControlDirect(((u16 *) gVramBankGroups)[0]);
}

void GX_SetBankForSubOBJExtPltt(u32 a) {
    ((u16 *) gVramBankGroups)[0] = (((u16 *) gVramBankGroups)[0] | ((u16 *) gVramBankGroups)[12]) & ~a;
    ((u16 *) gVramBankGroups)[12] = a;
    if (a != 0) {
        if (a == 0x100) {
            *(vu32 *) 0x4001000 |= 0x80000000;
            *(vu8 *) 0x4000249 = 0x83;
        }
    } else {
        *(vu32 *) 0x4001000 &= ~0x80000000;
    }
    WriteVramControlDirect(((u16 *) gVramBankGroups)[0]);
}

u16 SetVramBankGroupDirect(u16 *p) {
    u16 v;

    v = *p;
    *p = 0;
    ((u16 *) gVramBankGroups)[0] = ((u16 *) gVramBankGroups)[0] | v;
    WriteVramControlDirect(v);
    return v;
}

u16 GX_ResetBankForBGExtPltt(void) {
    *(vu32 *) 0x4000000 &= ~0x40000000;
    return SetVramBankGroupDirect(&data_021802be);
}

u16 GX_ResetBankForOBJExtPltt(void) {
    *(vu32 *) 0x4000000 &= ~0x80000000;
    return SetVramBankGroupDirect(&data_021802c0);
}

u16 GX_ResetBankForTex(void) {
    return SetVramBankGroupDirect(&data_021802b8);
}

u16 GX_ResetBankForTexPltt(void) {
    return SetVramBankGroupDirect(&data_021802ba);
}

u16 GX_ResetBankForClearImage(void) {
    return SetVramBankGroupDirect(&data_021802bc);
}

u16 GX_ResetBankForSubBG(void) {
    return SetVramBankGroupDirect(&data_021802c2);
}

u16 GX_ResetBankForSubOBJ(void) {
    return SetVramBankGroupDirect(&data_021802c4);
}

u16 GX_ResetBankForSubBGExtPltt(void) {
    *(vu32 *) 0x4001000 &= ~0x40000000;
    return SetVramBankGroupDirect(&data_021802c6);
}

u16 GX_ResetBankForSubOBJExtPltt(void) {
    *(vu32 *) 0x4001000 &= ~0x80000000;
    return SetVramBankGroupDirect(&data_021802c8);
}

u32 ReleaseVramBankGroup(u16 *p) {
    u32 v;

    v = *p;
    *p = 0;
    if (v & 0x1) {
        *(vu8 *) 0x4000240 = 0;
    }
    if (v & 0x2) {
        *(vu8 *) 0x4000241 = 0;
    }
    if (v & 0x4) {
        *(vu8 *) 0x4000242 = 0;
    }
    if (v & 0x8) {
        *(vu8 *) 0x4000243 = 0;
    }
    if (v & 0x10) {
        *(vu8 *) 0x4000244 = 0;
    }
    if (v & 0x20) {
        *(vu8 *) 0x4000245 = 0;
    }
    if (v & 0x40) {
        *(vu8 *) 0x4000246 = 0;
    }
    if (v & 0x80) {
        *(vu8 *) 0x4000248 = 0;
    }
    if (v & 0x100) {
        *(vu8 *) 0x4000249 = 0;
    }
    OSi_UnlockVram((u16) v, gVramLockId);
    return v;
}

u32 GX_DisableBankForBG(void) {
    return ReleaseVramBankGroup(&data_021802b2);
}

u32 GX_DisableBankForOBJ(void) {
    return ReleaseVramBankGroup(&data_021802b4);
}

u32 GX_DisableBankForBGExtPltt(void) {
    *(vu32 *) 0x4000000 &= ~0x40000000;
    return ReleaseVramBankGroup(&data_021802be);
}

u32 GX_DisableBankForOBJExtPltt(void) {
    *(vu32 *) 0x4000000 &= ~0x80000000;
    return ReleaseVramBankGroup(&data_021802c0);
}

u32 GX_DisableBankForTex(void) {
    return ReleaseVramBankGroup(&data_021802b8);
}

u32 GX_DisableBankForTexPltt(void) {
    return ReleaseVramBankGroup(&data_021802ba);
}

u32 GX_DisableBankForClearImage(void) {
    return ReleaseVramBankGroup(&data_021802bc);
}

u32 GX_DisableBankForARM7(void) {
    return ReleaseVramBankGroup(&data_021802b6);
}

u32 GX_DisableBankForLCDC(void) {
    return ReleaseVramBankGroup((u16 *) gVramBankGroups);
}

u32 GX_DisableBankForSubBG(void) {
    return ReleaseVramBankGroup(&data_021802c2);
}

u32 GX_DisableBankForSubOBJ(void) {
    return ReleaseVramBankGroup(&data_021802c4);
}

u32 GX_DisableBankForSubBGExtPltt(void) {
    *(vu32 *) 0x4001000 &= ~0x40000000;
    return ReleaseVramBankGroup(&data_021802c6);
}

u32 GX_DisableBankForSubOBJExtPltt(void) {
    *(vu32 *) 0x4001000 &= ~0x80000000;
    return ReleaseVramBankGroup(&data_021802c8);
}

u32 GX_GetBankForTex(void) {
    u32 value0;
    value0 = (u32) &gVramBankGroups;
    value0 = (u32) * (const u16 *) ((value0) + (8));
    return value0;
}

u32 ComputeVramBankSize(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    u32 value2;
    u32 compareLeft0;
    u32 compareRight0;
    u32 compareLeft1;
    u32 compareRight1;
    u32 compareLeft2;
    u32 compareRight2;
    u32 compareLeft3;
    u32 compareRight3;
    u32 compareLeft4;
    u32 compareRight4;
    u32 compareLeft5;
    u32 compareRight5;
    u32 compareLeft6;
    u32 compareRight6;
    u32 compareLeft7;
    u32 compareRight7;
    u32 compareLeft8;
    u32 compareRight8;
    value2 = 0u;
    value1 = (value0) & (1u);
    compareLeft0 = value1;
    compareRight0 = 0u;
    if (compareLeft0 != compareRight0) {
        value2 = (value2) + (0x20000u);
    }
    value1 = (value0) & (2u);
    compareLeft1 = value1;
    compareRight1 = 0u;
    if (compareLeft1 != compareRight1) {
        value2 = (value2) + (0x20000u);
    }
    value1 = (value0) & (4u);
    compareLeft2 = value1;
    compareRight2 = 0u;
    if (compareLeft2 != compareRight2) {
        value2 = (value2) + (0x20000u);
    }
    value1 = (value0) & (8u);
    compareLeft3 = value1;
    compareRight3 = 0u;
    if (compareLeft3 != compareRight3) {
        value2 = (value2) + (0x20000u);
    }
    value1 = (value0) & (0x10u);
    compareLeft4 = value1;
    compareRight4 = 0u;
    if (compareLeft4 != compareRight4) {
        value2 = (value2) + (0x10000u);
    }
    value1 = (value0) & (0x20u);
    compareLeft5 = value1;
    compareRight5 = 0u;
    if (compareLeft5 != compareRight5) {
        value2 = (value2) + (0x4000u);
    }
    value1 = (value0) & (0x40u);
    compareLeft6 = value1;
    compareRight6 = 0u;
    if (compareLeft6 != compareRight6) {
        value2 = (value2) + (0x4000u);
    }
    value1 = (value0) & (0x80u);
    compareLeft7 = value1;
    compareRight7 = 0u;
    if (compareLeft7 != compareRight7) {
        value2 = (value2) + (0x8000u);
    }
    value0 = (value0) & (0x100u);
    compareLeft8 = value0;
    compareRight8 = 0u;
    if (compareLeft8 != compareRight8) {
        value2 = (value2) + (0x4000u);
    }
    value0 = value2;
    return value0;
}

u32 GX_GetSizeOfOBJ(void) {
    u32 value0;
    u32 value12;
    value0 = (u32) &gVramBankGroups;
    value12 = (u32) &ComputeVramBankSize;
    value0 = (u32) * (const u16 *) ((value0) + (4));
    value0 = (u32) ComputeVramBankSize(value0);
    return value0;
}

u32 GX_GetSizeOfSubOBJ(void) {
    u32 value0;
    u32 value12;
    value0 = (u32) &gVramBankGroups;
    value12 = (u32) &ComputeVramBankSize;
    value0 = (u32) * (const u16 *) ((value0) + (20));
    value0 = (u32) ComputeVramBankSize(value0);
    return value0;
}

void ClearVramBankState(void) {
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
    s32 r;

    *(vu16 *) 0x4000304 |= 0x8000;
    *(vu16 *) 0x4000304 = (*(vu16 *) 0x4000304 & ~0x20e) | 0x20e;
    *(vu16 *) 0x4000304 |= 0x1;
    ClearVramBankState();
    while (*(vu16 *) &gVramLockId == 0) {
        r = OS_GetLockID();
        if (r == -3) {
            OS_Terminate();
        }
        *(vu16 *) &gVramLockId = r;
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

u32 GX_VBlankIntr(s32 a) {
    u32 old;

    old = *(vu16 *) 0x4000004 & 0x8;
    if (a != 0) {
        *(vu16 *) 0x4000004 |= 0x8;
    } else {
        *(vu16 *) 0x4000004 &= ~0x8;
    }
    return old;
}

void GX_DispOff(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    u32 value3;
    u32 value12;
    u32 value14;
    value14 = 0x4000000u;
    value12 = (u32) * (const u32 *) ((value14) + (0));
    value1 = (u32) &gDispOn;
    value2 = (value12) & (0x30000u);
    value3 = 0u;
    value0 = (u32) &gSavedDispMode;
    value2 = (value2 >> 16);
    *(u16 *) ((value1) + (0)) = (u16) value3;
    *(u16 *) ((value0) + (0)) = (u16) value2;
    value0 = (value12) & ~(0x30000u);
    *(u32 *) ((value14) + (0)) = value0;
}

void GX_DispOn(void) {
    u32 a;

    *(u16 *) gDispOn = 1;
    a = *(u16 *) gSavedDispMode;
    if (a != 0) {
        *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & ~0x30000) | (a << 16);
    } else {
        *(vu32 *) 0x4000000 |= 0x10000;
    }
}

void GX_SetGraphicsMode(u16 a, u32 b, s32 c) {
    u32 v;
    u32 x;

    x = *(vu32 *) 0x4000000;
    v = *(u16 *) gDispOn;
    *(u16 *) gSavedDispMode = a;
    if (v == 0) {
        a = 0;
    }
    *(vu32 *) 0x4000000 = ((x & 0xfff0fff0) | (a << 16) | b) | (c << 3);
    if (*(u16 *) gSavedDispMode == 0) {
        *(u16 *) gDispOn = 0;
    }
}
