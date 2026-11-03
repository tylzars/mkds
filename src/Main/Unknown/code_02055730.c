#include "Main/Unknown/code_02036c90.h"
#include "Main/Unknown/code_0204f814.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_02000000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036c5c.h"
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

s32 func_02055730(u16 a) {
    if (data_0217aa00->mUnk_0436 & 1) {
        data_0217aa00->mUnk_0436 &= ~1;
    }
    if (((Unk027ffc40 *) 0x027ffc40)->mUnk_00 == 2 || func_0204fe90(a) != 0) {
        return func_0204dd24(a);
    }
    return func_02055564(a);
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
                func_020527c0(1, NULL, NULL);
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
            func_02051a24();
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

void func_020559ec(const void *a, s32 b, s32 c) {
    u8 m;

    m = data_0217aa00->mUnk_043d & c;
    func_0214d1fc(a, &data_0217aa00->mUnk_045c[b], 0x14);
    data_0217aa00->mUnk_043d = m | (1 << b);
}

s32 func_02055a4c(Unk020487fc *a) {
    Unk021a9034 b = data_0216524c;

    func_020487fc(a, &b);
    return 0;
}

void func_02055a94(void) {
    if (func_02055808_inline2() != 0 && func_02055808_inline() != 1) {
        return;
    }
    data_0217aa04->mUnk_08 |= 8;
}

BOOL func_02055afc(void) {
    return (data_0217aa04->mUnk_08 & 8) != 0;
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

BOOL func_02055b1c(void) {
    if (func_02055b1c_inline()) {
        if (func_0204ffbc() != 0) {
            return (data_0217aa00->mUnk_15bc_view.mUnk_0c->mUnk_06_0 & 4) != 0;
        }
        return FALSE;
    }
    return (data_0217aa04->mUnk_08 & 8) != 0;
}

void func_02055bd4(u32 a) {
    if (func_02049838() != 2) {
        return;
    }
    data_0217aa04->mUnk_08 |= 4;
    func_020371a8(a, 1);
}

void func_02055c18(u32 a) {
    if (func_02049838() != 2) {
        return;
    }
    data_0217aa04->mUnk_08 |= 4;
    func_02036fec(a, 1);
}

void func_02055c5c(void) {
    if (data_0217aa04->mUnk_00 == 2) {
        data_0217aa04->mUnk_08 &= ~2;
    }
}

void func_02055c80(u8 a) {
    if (data_0217aa04->mUnk_00 != 2) {
        return;
    }
    data_0217aa04->mUnk_08 |= 2;
    data_0217aa04->mUnk_0c = 0x1000;
    data_0217aa04->mUnk_0a = a;
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
    if (func_02036c5c() == 0) {
        return;
    }
    data_0217aa04->mUnk_08 &= ~4;
    data_0217aa04->mUnk_08 &= ~8;
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

void func_02055e54(void) {
    u32 x;
    u32 y;

    func_02148fc8();
    func_02148fb4();
    if (data_0217aa04->mUnk_08 & 1) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | 0x300;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1000;
        func_021492d8(4);
        func_021491b0(8);
        data_0217aa04->mUnk_08 &= ~1;
        x = 2;
        y = 1;
    } else {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | 0x300;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x400;
        func_0214922c(4);
        func_021492d8(8);
        data_0217aa04->mUnk_08 |= 1;
        x = 3;
        y = 0;
    }
    reg_GX_POWCNT = (reg_GX_POWCNT & ~0x8000) | (y << 15);
    reg_GX_DISPCAPCNT = 0x80300010 | (x << 16);
}

void func_02055f68(void) {
    switch (data_0217aa04->mUnk_00) {
        case 1:
            func_02055fc8();
            break;
        case 2:
            func_02148950(0xe, 0, 1);
            break;
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
    func_0214a428((u32 *) 0x04001020, m, 0, 0, 0, 0);
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
    func_0200ee74(v1, 0x400);
    func_0214bf64(v1, 0, 0x400);
    VBlankIntrWait();
    data_0217aa04->mUnk_08 &= ~1;
    reg_GX_POWCNT = reg_GX_POWCNT | 0x8000;
    func_02055e54();
}

void func_02056114(s32 a) {
    data_0217aa04->mUnk_00 = a;
    if (data_02175614.mUnk_00 == 0) {
        data_0217aa04->mUnk_00 = 0;
    }
}
