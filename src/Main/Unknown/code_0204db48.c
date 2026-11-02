#include "Main/Unknown/code_0204db48.h"
#include "Main/Unknown/code_02050300.h"
#include "Main/Unknown/code_02050080.h"
#include "Main/Unknown/code_0204df5c.h"
#include "Main/Unknown/code_0204e000.h"
#include "Main/Unknown/code_0204f000.h"
#include "Main/Unknown/code_02051658.h"
#include "Main/Unknown/code_020529b8.h"
#include "Main/Unknown/code_02059878.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_0217a000.h"

s32 func_0204db48(Unk02003a6c *a, void *b, u32 c, u32 d) {
    func_0214d1fc((const void *) c, b, d);
    return 0;
}

#pragma thumb on

s32 func_0204db6c(void) {
    BOOL r = FALSE;
    switch (data_0217aa00->mUnk_0004) {
        case 2:
            data_0217aa00->mUnk_0004 = 5;
            break;
        case 5:
            break;
        case 10:
            return 1;
        default:
            return 3;
    }
    if (data_0217aa00->mUnk_0010 != 0) {
        return 0;
    }
    switch (data_0217aa00->mUnk_000c) {
        case 22:
            func_0204e128();
            break;
        case 24:
            func_0204e0bc();
            break;
        case 25:
            func_0204e090();
            break;
        case 27:
            func_02052ecc();
            break;
        case 36:
            func_020532dc(0x14);
            break;
        case 3:
            func_0204fb40(1);
            func_02052bf8();
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
            data_0217aa00->mUnk_1695 = func_0204dcf0(data_0217aa00->mUnk_1695);
            data_0217aa00->mUnk_1692 = 0;
            func_02051a24();
            break;
        case 11:
        case 15:
            if (func_0204dc8c() != 0) {
                func_02059878();
                r = TRUE;
            }
            break;
    }
    return r;
}

s32 func_0204dc8c(void) {
    BOOL r = FALSE;
    Unk0217aa00 *g = data_0217aa00;
    u32 a = g->mUnk_1695;
    u8 b = g->mUnk_0044.mUnk_43;

    if (a == (a & b)) {
        r = TRUE;
    } else if (g->mUnk_1692 > 0x708) {
        if (b == 0) {
            func_02050e60(5);
        } else {
            data_0217aa00->mUnk_1695 = func_0204dcf0(b);
            r = TRUE;
        }
    } else {
        g->mUnk_1692 = g->mUnk_1692 + 1;
    }
    return r;
}

u8 func_0204dcf0(u8 a) {
    u8 r = a & 1;
    u32 i = 1;
    u32 n = 1;

    for (; i < 8; i++) {
        if (((1 << i) & a) != 0) {
            r = r | (1 << n);
            n++;
        }
    }
    return r;
}

s32 func_0204dd24(u16 a) {
    s32 r = 0;
    Unk0217aa00 *g = data_0217aa00;

    switch (g->mUnk_000c) {
        case 29:
            if (func_020501b0(a) == 0) {
                func_02050e60(5);
            }
            if (func_0204ff14(a, NULL) != 0) {
                func_0204e074();
            } else {
                func_02050e60(5);
            }
            break;
        case 10:
            g->mUnk_1692 = g->mUnk_1692 + 1;
            if (data_0217aa00->mUnk_1692 > 0x4b0) {
                func_02050e60(5);
                return 3;
            }
            break;
        case 7:
            g->mUnk_0010 = 0;
            break;
        case 30: {
            s32 v;
            g->mUnk_1692 = g->mUnk_1692 + 1;
            if (data_0217aa00->mUnk_1692 > 0x4b0) {
                func_02050e60(5);
            } else {
                v = func_0204e3f0(a);
                if (v != -1) {
                    data_0217aa00->mUnk_169a = v;
                    func_0204e074();
                }
            }
            break;
        }
    }
    g = data_0217aa00;
    if (g->mUnk_0010 != 0) {
        return 0;
    }
    switch (g->mUnk_000c) {
        case 7:
            g->mUnk_0454 |= 0x40;
            func_02051e98();
            break;
        case 9:
            func_0204e4d8();
            break;
        case 28:
            g->mUnk_1692 = 0;
            func_0204e474();
            break;
        case 30:
            func_0204e074();
            break;
        case 33:
            if (g->mUnk_169a == -1) {
                func_0204e03c(a);
            } else {
                func_0204e03c((u16) g->mUnk_169a);
            }
            break;
        case 34:
            if (g->mUnk_169c != 0) {
                if (g->mUnk_169a == -1) {
                    func_0204dfe0(a);
                } else {
                    func_0204dfe0((u16) g->mUnk_169a);
                }
            } else {
                r = 2;
            }
            break;
        case 35:
            func_0204e4bc();
            break;
        case 1:
            g->mUnk_1692 = 0;
        case 2:
            if (*(u16 *) 0x027ffc40 == 2) {
                func_0204df90();
            } else {
                func_02051d24(NULL, NULL, NULL, (s32(*)()) func_0204df5c, NULL);
            }
            break;
        case 31:
            if (g->mUnk_1692 < 0x3c) {
                g->mUnk_1692 = g->mUnk_1692 + 1;
            } else {
                g->mUnk_000c = 32;
            }
            break;
        case 26:
        case 32:
            func_02052ecc();
            break;
        case 36:
            func_02051d24(NULL, NULL, NULL, (s32(*)()) func_0204df5c, NULL);
            break;
        case 10:
            func_02051a24();
            break;
        case 11:
            g->mUnk_0004 = 6;
            func_02059878();
            r = 1;
            break;
    }
    return r;
}

#pragma thumb off
