#include "Main/Unknown/code_020afd68.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_020b03bc.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6368.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_021488e8.h"
#include "code_02148d34.h"
#include "code_0214b338.h"
#include "code_0214b824.h"
#include "registers.h"

static inline void func_020afd68_inline(u16 *v1) {
    s32 j;
    s32 i;
    u16 *v2 = v1;

    for (i = 3; i < 24; i++) {
        s32 v3 = i * 32;
        for (j = 14; j < 32; j++) {
            s32 x = j + v3;
            s32 y = v3 + (45 - j);
            if (x < y) {
                u16 t = v2[y];
                v2[y] = v2[x];
                v2[x] = t;
            }
            v2[x] ^= 0x400;
        }
    }
}

void func_020afd68(void) {
    Unk020b4a44 *a[3];
    Unk020b4934 *b[3];
    Unk020b47d8 *c[4];
    s32 v1;
    s32 i;
    s32 k;

    v1 = data_021759c0->mUnk_08 != 4;
    if (data_021759c0->mUnk_00c == 3) {
        return;
    }
    if (data_021759c0->mUnk_00c == 5 || data_021759c0->mUnk_00c == 6) {
        return;
    }
    data_0217b34c = func_02036bec(func_020364e0(func_020364e8()), 0x400);
    for (i = 0; i < 2; i++) {
        a[i] = 0;
        b[i] = 0;
    }
    for (i = 0; i < 3; i++) {
        c[i] = 0;
    }

    if (func_02047250()) {
        if (v1) {
            func_020b4a7c(&a[0], func_020b47b4("Map2D/global.NCLR"));
            func_020b4a7c(&a[1], func_020b47b4("Map2D/global2.NCLR"));
        }
        func_020b4a7c(&a[2], func_020b47b4("Map2D/local.NCLR"));
    } else {
        if (v1) {
            func_020b4a44(&a[0], func_020b47b4("Map2D/global.NCLR"));
            func_020b4a44(&a[1], func_020b47b4("Map2D/global.NCLR"));
        }
        func_020b4a44(&a[2], func_020b47b4("Map2D/local.NCLR"));
    }

    if (func_02047250()) {
        if (v1) {
            func_020b496c(&b[0], func_020b47b4("Map2D/global.NCGR"));
            func_020b496c(&b[1], func_020b47b4("Map2D/global2.NCGR"));
        }
        func_020b496c(&b[2], func_020b47b4("Map2D/local.NCGR"));
    } else {
        if (v1) {
            func_020b4934(&b[0], func_020b47b4("Map2D/global.NCGR"));
            func_020b4934(&b[1], func_020b47b4("Map2D/global2.NCGR"));
        }
        func_020b4934(&b[2], func_020b47b4("Map2D/local.NCGR"));
    }

    if (func_02047250()) {
        if (v1) {
            func_020b4810(&c[0], func_020b47b4("Map2D/global1.NSCR"));
            func_020b4810(&c[1], func_020b47b4("Map2D/global2.NSCR"));
        }
        func_020b4810(&c[2], func_020b47b4("Map2D/local2.NSCR"));
        if (func_020b64e8()) {
            func_020b4810(&c[3], func_020b47b4("Map2D/local3.NSCR"));
        }
    } else {
        if (v1) {
            func_020b47d8(&c[0], func_020b47b4("Map2D/global1.NSCR"));
            func_020b47d8(&c[1], func_020b47b4("Map2D/global2.NSCR"));
        }
        func_020b47d8(&c[2], func_020b47b4("Map2D/local2.NSCR"));
        if (func_020b64e8()) {
            func_020b47d8(&c[3], func_020b47b4("Map2D/local3.NSCR"));
        }
    }

    if (v1) {
        if (data_021759c0->mUnk_57 != 0) {
            func_020afd68_inline(c[0]->mUnk_0c);
        }
        k = 0;
        if (data_021759c0->mUnk_08 == 2 && data_021759c0->mUnk_18 == 1) {
            k = 1;
        }
        for (i = 0; i < 16; i++) {
            a[0]->mUnk_0c[i + 16] = a[1]->mUnk_0c[(k + 1) * 16 + i];
        }
        for (i = 0; i < 0x400; i++) {
            s32 r = c[1]->mUnk_0c[i];
            r %= 0x400;
            c[1]->mUnk_0c[i] = (u16) (c[1]->mUnk_0c[i] & 0xfc00) | (r + ((k + 6) << 5));
        }
        func_0200eddc();
        func_02148934(5);
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1c00;
        func_02148934(0);
        reg_G2S_DB_BG2OFS = 0;
        reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~3) | 2;
        reg_G2S_DB_BG2CNT = reg_G2S_DB_BG2CNT & ~0x40;
        reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & 0x43) | 0x208;
        reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~3) | 3;
        reg_G2S_DB_BG3CNT = reg_G2S_DB_BG3CNT & ~0x40;
        reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x308;
        func_0214c0f8(a[0]->mUnk_0c, 0, a[0]->mUnk_08);
        func_0214b8f4(b[0]->mUnk_14, 0, b[0]->mUnk_10);
        func_0214b8f4(b[1]->mUnk_14, 0x1800, b[1]->mUnk_10);
        func_0214bc34(c[0]->mUnk_0c, 0, c[0]->mUnk_08);
        func_0214bb64(c[1]->mUnk_0c, 0, c[1]->mUnk_08);
    }

    func_020b18b0();
    func_0214c0f8(a[2]->mUnk_0c, 0, 0x200);
    func_0214b824(b[2]->mUnk_14, 0, b[2]->mUnk_10);
    func_0214bc34(c[2]->mUnk_0c, 0, c[2]->mUnk_08);
    if (func_020b64e8()) {
        func_0214bb64(c[3]->mUnk_0c, 0, c[3]->mUnk_08);
    }
    func_02149124(0x80);
    func_0214b4dc();
    func_0214b468(a[2]->mUnk_0c, 0x4000, 0x200);
    func_0214b468(a[2]->mUnk_0c, 0x6000, 0x200);
    func_0214b41c();
    for (i = 0; i < 0x100; i++) {
        if (v1) {
            data_0217b34c[i] = a[0]->mUnk_0c[i];
        }
        (data_0217b34c + i)[0x100] = a[2]->mUnk_0c[i];
    }
    if (v1) {
        func_0200ee74(data_0217b34c, 0x200);
    }
    func_0200ee74(data_0217b34c + 0x100, 0x200);
}
