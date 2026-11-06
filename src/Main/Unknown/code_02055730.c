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
    u8 i;
    s32 m;
    u8 j;
    s32 v;

    m = 7;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
            v = func_02060364(i, j);
            if (v == 9 || v < m) {
                m = v;
            }
            if (m == 9 || m < 5) {
                return 0;
            }
        }
    }
    switch (m) {
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

void func_02056158(void *a) {
    data_0217aa04 = HeapAlloc(a, 0x10);
    if (data_021759c0->mUnk_00c == 3 || data_021759c0->mUnk_00c == 5) {
        data_0217aa04->mUnk_04 = HeapAllocAligned(a, 0x400, 0x20);
    } else {
        data_0217aa04->mUnk_04 = NULL;
    }
    data_0217aa04->mUnk_08 = 0;
    data_0217aa04->mUnk_0a = 0;
    data_0217aa04->mUnk_0c = 0x1000;
    data_0217aa04->mUnk_00 = 0;
    if (data_02175614.mUnk_00 == 0) {
        data_0217aa04->mUnk_00 = 0;
    }
}

u32 func_02056144(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217aa04;
    value1 = 0u;
    *(u32 *) ((value0) + (0)) = value1;
    return value0;
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

void func_02056114(s32 a) {
    data_0217aa04->mUnk_00 = a;
    if (data_02175614.mUnk_00 == 0) {
        data_0217aa04->mUnk_00 = 0;
    }
}

void func_02055fc8(void) {
    Unk0217aa04_04 *v1;
    s32 m[4];
    s32 i;
    s32 k;
    s32 j;
    s32 n;
    Unk0217aa04_04 *p;

    v1 = data_0217aa04->mUnk_04;
    if (v1 == NULL) {
        return;
    }
    m[0] = 0x1000;
    m[3] = 0x1000;
    m[1] = 0;
    m[2] = 0;
    G2x_SetBGyAffine_(&reg_G2S_DB_BG2PA, m, 0, 0, 0, 0);
    for (i = 0; i < 0x80; i++) {
        v1[i].mUnk_00 = 0;
        v1[i].mUnk_04 = 0;
    }
    n = 0;
    for (j = 0; j < 3; j++) {
        for (k = 0; k < 4; k++) {
            p = &v1[n++];
            p->mUnk_00 = (u8) (0x40 * j) | 0xc0000c00 | ((k * 0x40 & 0x1ff) << 16);
            p->mUnk_04_h = (0x100 * j + k * 8) | 0xf000;
        }
    }
    DC_FlushRange(v1, 0x400);
    GXS_LoadOAM(v1, 0, 0x400);
    VBlankIntrWait();
    data_0217aa04->mUnk_08 &= ~1;
    reg_GX_POWCNT = reg_GX_POWCNT | 0x8000;
    func_02055e54();
}

void func_02055f68(void) {
    switch (data_0217aa04->mUnk_00) {
        case 1:
            func_02055fc8();
            break;
        case 2:
            GX_SetGraphicsMode(0xe, 0, 1);
            break;
    }
}

void func_02055e54(void) {
    u32 x;
    u32 y;

    GX_ResetBankForSubBG();
    GX_ResetBankForSubOBJ();
    if (data_0217aa04->mUnk_08 & 1) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | 0x300;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1000;
        GX_SetBankForLCDC(4);
        GX_SetBankForSubOBJ(8);
        data_0217aa04->mUnk_08 &= ~1;
        x = 2;
        y = 1;
    } else {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | 0x300;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x400;
        GX_SetBankForSubBG(4);
        GX_SetBankForLCDC(8);
        data_0217aa04->mUnk_08 |= 1;
        x = 3;
        y = 0;
    }
    reg_GX_POWCNT = (reg_GX_POWCNT & ~0x8000) | (y << 15);
    reg_GX_DISPCAPCNT = 0x80300010 | (x << 16);
}

void func_02055d5c(s32 a) {
    u8 x;

    x = data_0217aa04->mUnk_0a + (((16 - data_0217aa04->mUnk_0a) * data_0217aa04->mUnk_0c) >> 12);
    reg_GX_DISPCAPCNT = x | (0xc0330000 | (u8) (16 - x) << 8);
    if (a != 0) {
        return;
    }
    if (data_0217aa04->mUnk_08 & 2) {
        if (data_0217aa04->mUnk_0c <= 0) {
            return;
        }
        data_0217aa04->mUnk_0c -= 0x802;
        if (data_0217aa04->mUnk_0c < 0) {
            data_0217aa04->mUnk_0c = 0;
        }
    } else {
        if (data_0217aa04->mUnk_0c >= 0x1000) {
            return;
        }
        data_0217aa04->mUnk_0c = data_0217aa04->mUnk_0c + 0x19a;
        if (data_0217aa04->mUnk_0c > 0x1000) {
            data_0217aa04->mUnk_0c = 0x1000;
        }
    }
}

void func_02055cbc(s32 a) {
    switch (data_0217aa04->mUnk_00) {
        case 1:
            if (a == 0) {
                func_02055e54();
            }
            break;
        case 2:
            func_02055d5c(a);
            break;
    }
    if (!(data_0217aa04->mUnk_08 & 4)) {
        return;
    }
    if (AreBrightnessFadesClear() == 0) {
        return;
    }
    data_0217aa04->mUnk_08 &= ~4;
    data_0217aa04->mUnk_08 &= ~8;
}

void func_02055c80(u8 a) {
    if (data_0217aa04->mUnk_00 != 2) {
        return;
    }
    data_0217aa04->mUnk_08 |= 2;
    data_0217aa04->mUnk_0c = 0x1000;
    data_0217aa04->mUnk_0a = a;
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

void func_02055c5c(void) {
    if (data_0217aa04->mUnk_00 == 2) {
        data_0217aa04->mUnk_08 &= ~2;
    }
}

void func_02055c18(u32 a) {
    if (func_02049838() != 2) {
        return;
    }
    data_0217aa04->mUnk_08 |= 4;
    StartFadeToFadedNegativeOneScreen(a, 1);
}

void func_02055bd4(u32 a) {
    if (func_02049838() != 2) {
        return;
    }
    data_0217aa04->mUnk_08 |= 4;
    StartFadeToClearNegativeOneScreen(a, 1);
}

BOOL func_02055b1c(void) {
    if (func_02055b1c_inline()) {
        if (func_0204ffbc() != 0) {
            return (data_0217aa00->mUnk_15bc_view.mUnk_0c->mUnk_06_0 & 4) != 0;
        }
        return FALSE;
    }
    return (data_0217aa04->mUnk_08 & 8) != 0;
}

BOOL func_02055afc(void) {
    return (data_0217aa04->mUnk_08 & 8) != 0;
}

void func_02055a94(void) {
    if (func_02055808_inline2() != 0 && func_02055808_inline() != 1) {
        return;
    }
    data_0217aa04->mUnk_08 |= 8;
}

s32 RunRecordScene(SceneNumbers *a) {
    SceneCallbacks b = gRecordSceneCallbacks;

    RunScene(a, &b);
    return 0;
}

void func_020559ec(const void *a, s32 b, s32 c) {
    u8 m;

    m = data_0217aa00->mUnk_043d & c;
    MI_CpuCopy8(a, &data_0217aa00->mUnk_045c[b], 0x14);
    data_0217aa00->mUnk_043d = m | (1 << b);
}

s32 func_02055808(s32 a) {
    BOOL r;

    r = FALSE;
    if (data_0217aa00->mUnk_0010 != 0) {
        return r;
    }
    if (func_02055808_inline4()) {
        return 3;
    }
    switch (data_0217aa00->mUnk_000c) {
        case 0:
        case 21:
            data_0217aa00->mUnk_0454 &= ~0x40;
            data_0217aa00->mUnk_0004 = 1;
            func_020536e0();
            break;
        case 1:
            func_02052ecc();
            break;
        case 2:
        case 36:
            if (a != 0) {
                func_020532dc(0x14);
            } else {
                r = TRUE;
                data_0217aa00->mUnk_0004 = 3;
                StartScan(1, NULL, NULL);
            }
            break;
        case 3:
            func_02053094(0);
            break;
        case 4:
            func_0204f814();
            func_0204fb40(1);
            func_02052bf8();
            break;
        case 5:
            func_02052b60(NULL);
            break;
        case 6:
            StartMP();
            break;
        case 11:
            data_0217aa00->mUnk_0004 = 2;
            data_0217aa00->mUnk_0044.mUnk_3e = 0;
            r = TRUE;
            data_0217aa00->mUnk_008b &= ~8;
            break;
        default:
            func_020533a0();
            break;
    }
    return r;
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
