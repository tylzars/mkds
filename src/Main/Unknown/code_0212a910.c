#include "Main/Unknown/code_0212a910.h"
#include "registers.h"

#include "Main/Unknown/code_0212a920.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_0212030c.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_020d1630.h"
#include "Main/Unknown/code_020d1640.h"
#include "Main/Unknown/code_02124094.h"
#include "code_02142eac.h"
#include "code_02016468.h"
#include "code_0214cfe4.h"
#include "code_0201ea30.h"
#include "Main/Unknown/code_0212abd0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_0205e090.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0212b09c.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_020b19a0.h"
#include "Main/Unknown/code_021205f4.h"
#include "Main/Unknown/code_02124f4c.h"
#include "Main/Unknown/code_02024000.h"
#include "code_0200eddc.h"
#include "code_02023374.h"
#include "code_0214a390.h"
#include "code_0214b824.h"
#include "code_0214d018.h"
#include "Main/Unknown/unk_0216e000.h"
#include "Main/Unknown/code_0212b0b8.h"
#include "00/code_02181f98.h"
#include "Main/Unknown/code_02023000.h"
#include "code_021488e8.h"

#pragma thumb on
void func_0212b158(void *a) {
    Unk0217d408 *p;
    Unk02180728 *q;
    p = HeapAlloc(a, 0x1a44);
    data_0217d408 = p;
    NNS_G2dCharCanvasInitForBG(p->mUnk_0014, p->mUnk_0044, 0x20, 5, 4);
    p = data_0217d408;
    q = &p->mUnk_0034;
    p->mUnk_0034.mUnk_00 = p->mUnk_0014;
    q->mUnk_04 = NULL;
    q->mUnk_08 = 1;
    q->mUnk_0c = 2;
    func_0212b144();
}

void func_0212b144(void) {
    data_0217d408->mUnk_000c = FALSE;
    data_0217d408->mUnk_0010 = -1;
}

s32 func_0212b0b8(void) {
    Unk0217d408 *p;
    if (data_0217d408->mUnk_000c == FALSE) {
        return -1;
    }
    GXx_SetMasterBrightness_(&reg_GX_MASTER_BRIGHT, 0);
    GXx_SetMasterBrightness_(&reg_GXS_DB_MASTER_BRIGHT, 0);
    if ((u16) (data_021755dc.mUnk_00 & PAD_KEY_A) != 0) {
        p = data_0217d408;
        if (p->mUnk_0004 != 0) {
            if ((u32) (p->mUnk_0000 - 4) <= 1) {
                data_0217b488->mUnk_58 = TRUE;
                data_0217d408->mUnk_0010 = 1;
            } else if (p->mUnk_0000 == 6) {
                data_0217b488->mUnk_1c = 1;
                data_0217d408->mUnk_0010 = 1;
                func_02120610();
            } else {
                p->mUnk_0010 = 0;
            }
        }
    }
    return data_0217d408->mUnk_0010;
}
#pragma thumb off

#pragma thumb on
void func_0212b09c(void) {
    u32 value0;
    u32 value1;
    u32 value2;
    u32 value3;
    value0 = (u32) &data_0217d408;
    value0 = *(const u32 *) ((value0) + 0u);
    value0 = (value0) + 68u;
    value1 = 0u;
    value2 = 0x1400u;
    MI_CpuFill8((void *) value0, value1, value2);
}
#pragma thumb off

#pragma thumb on

void *func_0212b090(void) {
    return data_0217d408->mUnk_0044;
}

#pragma thumb off

#pragma thumb on
void func_0212b064(void) {
    volatile u16 a;
    a = 0;
    MIi_CpuClear16(a, data_0217d408->mUnk_1444, 0x600);
}

void *func_0212afac(void) {
    void *a;
    s32 v;
    a = NULL;
    if (*(vu16 *) 0x27ffc40 != 2) {
        a = FindFileInLoadedArchives(data_0216ea6c);
    }
    v = data_0217d408->mUnk_0000;
    if (v == 4) {
        return GetBmgEntry(a, 0x86);
    }
    if (v == 5) {
        return GetBmgEntry(a, 0x87);
    }
    if (v == 6) {
        return GetBmgEntry(a, 0x88);
    }
    if (v == 1) {
        return GetBmgEntry(a, 0x83);
    }
    if (v == 2) {
        return GetBmgEntry(a, 0x84);
    }
    if (v == 3) {
        return GetBmgEntry(a, 0x85);
    }
    if (v == 0) {
        if (*(vu16 *) 0x27ffc40 == 2) {
            return GetBmgEntry(func_020d1630()->mUnk_20, 0);
        }
        return GetBmgEntry(a, 0x82);
    }
    return NULL;
}

void func_0212ae80(void) {
    s32 i;
    func_0212b09c();
    if (*(vu16 *) 0x27ffc40 == 2) {
        data_0217d408->mUnk_0034.mUnk_04 = &func_020d1630()->mUnk_14;
    } else {
        data_0217d408->mUnk_0034.mUnk_04 = func_020b403c(0);
    }
    NNSi_G2dTextCanvasDrawText(&data_0217d408->mUnk_0034, 0x80, 0x14, 0xe, 0x412, data_0217d408->mUnk_0008);
    func_0212b064();
    for (i = 0; i < 0x300; i++) {
        if (i >= 0x120 && i < 0x1c0) {
            data_0217d408->mUnk_1444[i] = (i - 0x120) | 0xf000;
        } else {
            data_0217d408->mUnk_1444[i] = 0xf09f;
        }
    }
    *(vu16 *) 0x50001fc = 0xffff;
    *(vu16 *) 0x5000000 = 0;
    reg_G2_BG1OFS = 0;
    reg_G2_BG1CNT = reg_G2_BG1CNT & ~3;
    reg_G2_BG1CNT = reg_G2_BG1CNT & ~0x40;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & 0x43) | 0x400;
    DC_FlushRange(data_0217d408->mUnk_0044, 0x1400);
    DC_FlushRange(data_0217d408->mUnk_1444, 0x600);
    GX_LoadBG1Char(data_0217d408->mUnk_0044, 0, 0x1400);
    GX_LoadBG1Scr(data_0217d408->mUnk_1444, 0, 0x600);
}

void func_0212ae2c(void) {
    u16 a[11];
    a[0] = 0;
    MIi_CpuClear16(a[0], &a[1], 0x14);
    func_02124fac(func_021205f4(), &a[1]);
    func_0212513c(&a[1], data_0217d408->mUnk_0008, data_0217d408->mUnk_1444, 0x600);
    data_0217d408->mUnk_0008 = data_0217d408->mUnk_1444;
}

void func_0212ad28(s32 a, s32 b) {
    u32 t;
    if (data_0217d408->mUnk_000c == FALSE && a != -1) {
        data_0217d408->mUnk_000c = TRUE;
        data_0217d408->mUnk_0004 = b;
        data_0217d408->mUnk_0000 = a;
        data_0217d408->mUnk_0008 = func_0212afac();
        if (data_0217d408->mUnk_0000 == 4) {
            func_0212ae2c();
        }
        func_0212ae80();
        if (GetCurrentSceneNumber() == 2) {
            if (func_020b19a0() == 0) {
                reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | 0x200;
                reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffffe0ff;
                *(vu16 *) 0x5000400 = 0;
                reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffff1fff;
            } else {
                t = (reg_GX_DISPCNT & 0x1f00) >> 8;
                t |= 2;
                reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | (t << 8);
            }
            G2x_SetBlendBrightnessExt_(&reg_G2_BLDCNT, 0x1d, 0, 8, 8, -11);
        } else {
            reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | 0x200;
            reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffffe0ff;
            *(vu16 *) 0x5000400 = 0;
            reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffff1fff;
            reg_G2_BLDCNT = 0;
            reg_G2S_DB_BLDCNT = 0;
        }
    }
}

void func_0212abdc(void *a, void *b) {
    s32 i;
    Unk0217d404 *p;
    Unk0217d3fc_00_00 *q;
    data_0217d404 = HeapAlloc(a, 0x11c);
    data_0217d404->mUnk_038 = b;
    MI_CpuFill8(data_0217d404->mUnk_03c, 0, 0x20);
    data_0217d404->mUnk_024 = 0;
    for (i = 0; i < 5; i++) {
        data_0217d404->mUnk_000[i] = 0;
    }
    switch (GetCurrentSceneNumber()) {
        case 1:
            if ((u32) (data_021759d0->mUnk_20 - 1) <= 1) {
                data_0217d404->mUnk_000[0] = 1;
            }
            break;
        case 6:
        case 13:
            data_0217d404->mUnk_000[0] = 1;
            break;
        case 12:
            data_0217d404->mUnk_000[4] = 1;
            break;
        case 10:
            if (data_021759d0->mUnk_20 == 3) {
                data_0217d404->mUnk_000[1] = 1;
                data_0217d404->mUnk_000[4] = 1;
            } else if ((u32) (data_021759d0->mUnk_20 - 1) <= 1) {
                data_0217d404->mUnk_000[0] = 1;
            }
            break;
        case 8:
            if (data_021759d0->mUnk_20 == 3) {
                data_0217d404->mUnk_000[1] = 1;
                data_0217d404->mUnk_000[4] = 1;
            }
            break;
    }
    for (i = 0; i < 2; i++) {
        data_0217d404->mUnk_014[i] = -1;
    }
    func_0212aaa4();
    for (i = 0; i < 2; i++) {
        p = data_0217d404;
        q = &p->mUnk_10c[i];
        q->mUnk_00 = ((p->mUnk_028[i].mUnk_00 & 0x1ff) << 16) | ((p->mUnk_028[i].mUnk_04 & 0xff) | 0x40000000);
        q->mUnk_04 = (0x400 - (i + 1) * 4) | 0xd000;
    }
}
#pragma thumb off

#pragma thumb on
void func_0212abd0(void) {
    u32 value0;
    u32 value1;
    value1 = 0u;
    value0 = (u32) &data_0217d404;
    *(u32 *) ((value0) + 0u) = value1;
}
#pragma thumb off

#pragma thumb on
void func_0212aaa4(void) {
    s32 i;
    Ncgr *c;
    Unk02021dc8 *d;
    Nclr *e;
    void *a;
    Unk0201ea30 *b;
    Unk0217b4b0 *x;
    Unk0201ea30_08 *p;
    s32 j;
    x = func_020d1630();
    a = x->mUnk_00;
    b = x->mUnk_04;
    c = x->mUnk_08;
    d = x->mUnk_0c;
    e = x->mUnk_10;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < data_0215d168[i]; j++) {
            data_0217d404->mUnk_0bc[i][j] = (Unk0217d404_bc *) c->mData + func_0212497c(data_0215d170[i][j], d, a);
        }
    }
    for (i = 0; i < 2; i++) {
        p = func_0201ea30(b, data_0215d164[i]);
        data_0217d404->mUnk_028[i].mUnk_00 = func_0201ebe8(p->mUnk_00_0, 0x10);
        data_0217d404->mUnk_028[i].mUnk_04 = func_0201eba0(p->mUnk_00_2, 0x10);
    }
    for (i = 0; i < 2; i++) {
        CallQueueAppend(0x13, (0x400 - (i + 1) * 4) << 5, data_0217d404->mUnk_03c, 0x80);
    }
    CallQueueAppend(0xe, 0x1a0, e->mData + 0xd0, 0x20);
}

void func_0212a99c(void) {
    s32 n;
    s32 i;
    s32 v;
    BOOL r;
    n = 0;
    for (i = 0; i < 2; i++) {
        data_0217d404->mUnk_014[i] = -1;
        data_0217d404->mUnk_01c[i] = 0;
    }
    if (data_0217d404->mUnk_000[1] != 0) {
        data_0217d404->mUnk_014[0] = 1;
        data_0217d404->mUnk_01c[0] = func_021205e8();
        n = 1;
    }
    if (data_0217d404->mUnk_000[0] != 0) {
        data_0217d404->mUnk_014[n] = 0;
        v = 0;
        if (data_0217aa00->mUnk_0004 != 0) {
            v = WM_GetLinkLevel();
        }
        data_0217d404->mUnk_01c[n] = v;
    } else if (data_0217d404->mUnk_000[4] != 0) {
        r = FALSE;
        if (!data_0217aa08->mUnk_00->mLocateFriendOff) {
            if (func_021213f4() != FALSE) {
                r = TRUE;
            }
        }
        if (r != FALSE) {
            data_0217d404->mUnk_014[n] = 4;
        }
    }
    for (i = 0; i < 2; i++) {
        if (data_0217d404->mUnk_014[i] == -1) {
            CallQueueAppend(0x13, (0x400 - (i + 1) * 4) << 5, data_0217d404->mUnk_03c, 0x80);
        } else {
            CallQueueAppend(0x13, (0x400 - (i + 1) * 4) << 5,
                            data_0217d404->mUnk_0bc[data_0217d404->mUnk_014[i]][data_0217d404->mUnk_01c[i]], 0x80);
        }
    }
}

void func_0212a920(void) {
    s32 i;
    u32 v;
    data_0217d404->mUnk_024++;
    if (data_0217d404->mUnk_024 > 0x78) {
        data_0217d404->mUnk_024 = 0;
    }
    func_0212a99c();
    for (i = 0; i < 2; i++) {
        v = data_0217d404->mUnk_014[i];
        if (data_0217d404->mUnk_024 < 0x69 || v <= 1) {
            MIi_CpuCopy16(&data_0217d404->mUnk_10c[i],
                          &data_0217d404->mUnk_038->mUnk_00[data_0217d404->mUnk_038->mUnk_400], 6);
            data_0217d404->mUnk_038->mUnk_400++;
        }
    }
}
#pragma thumb off

#pragma thumb on
void func_0212a910(u32 arg0, u32 arg1) {
    u32 value0 = arg0;
    u32 value1 = arg1;
    u32 value2;
    value2 = (u32) &data_0217d404;
    value2 = *(const u32 *) ((value2) + 0u);
    value0 = (value0 << 2);
    *(u32 *) ((value2) + (value0)) = value1;
}
#pragma thumb off
