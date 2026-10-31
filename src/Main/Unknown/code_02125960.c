#include "Main/Unknown/code_02125960.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0204799c.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_02016468.h"
#include "registers.h"

const char *data_0216e37c[1] = {"back_screen_s_b_00.nclr"};
const char *data_0216e380[1] = {"back_screen_s_b_00.ncgr"};
const char *data_0216e384[1] = {"back_screen_s_bg_00.nscr"};
const char *data_0216e388[2] = {"back_screen_m_bg_00.nscr", "back_screen_m_bg_01.nscr"};
const char *data_0216e390[2] = {"back_screen_m_b_00.ncgr", "back_screen_m_b_01.ncgr"};
const char *data_0216e398[2] = {"back_screen_m_b_00.nclr", "back_screen_m_b_01.nclr"};

#pragma thumb on

void func_02125c2c(void) {
    Unk02111684_v p;

    if (((Unk027ffc40 *)0x027ffc40)->mUnk_00 == 2) {
        func_020b496c(&p.m4934, func_0204799c("txt_system_b_00.ncgr"));
        func_020b4810(&p.m47d8, func_0204799c("txt_system_bg_00.nscr"));
        func_020b4a7c(&p.m4a44, func_0204799c("txt_system_b_00.nclr"));
    } else {
        func_020b496c(&p.m4934, func_02047a28("txt_system_b_00.ncgr"));
        func_020b496c(&p.m4934, func_02047a28("txt_system_b_01.ncgr"));
        func_020b4810(&p.m47d8, func_02047a28("txt_system_bg_00.nscr"));
        func_020b4810(&p.m47d8, func_02047a28("txt_system_bg_00_2.nscr"));
        func_020b4810(&p.m47d8, func_02047a28("txt_system_bg_01.nscr"));
        func_020b4810(&p.m47d8, func_02047a28("txt_system_bg_01_2.nscr"));
        func_020b4810(&p.m47d8, func_02047a28("txt_system_bg_02.nscr"));
        func_020b4810(&p.m47d8, func_02047a28("txt_system_bg_02_2.nscr"));
        func_020b4810(&p.m47d8, func_02047a28("txt_system_bg_02_3.nscr"));
        func_020b4a7c(&p.m4a44, func_02047a28("txt_system_b_00.nclr"));
        func_020b496c(&p.m4934, func_02047a28("select_choises_s_b.ncgr"));
        func_020b4810(&p.m47d8, func_02047a28("select_choises_s_bg.nscr"));
        func_020b4a7c(&p.m4a44, func_02047a28("select_choises_s_b.nclr"));
        func_020b496c(&p.m4934, func_02047a28("select_return_s_b_00.ncgr"));
        func_020b4810(&p.m47d8, func_02047a28("select_return_s_bg_00.nscr"));
        func_020b4a7c(&p.m4a44, func_02047a28("select_return_s_b_00.nclr"));
    }
}

void func_02125ba4(void) {
    u32 v;
    u32 w;

    v = (reg_GX_DISPCNT & 0x1f00) >> 8;
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | ((v | 8) << 8);
    reg_G2_BG3CNT = (reg_G2_BG3CNT & ~3) | 3;
    reg_G2_BG3CNT = (reg_G2_BG3CNT & 0x43) | 0x1d18;
    w = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | ((w | 2) << 8);
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~3) | 3;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & 0x43) | 0xd00;
}

s32 func_02125960(s32 a) {
    s32 i;
    s32 k8;
    s32 kc;
    Unk020b4934 *p14;
    Unk020b47d8 *p18;
    Unk020b4a44 *p1c;
    Unk020b4934 *p20;
    Unk020b47d8 *p24;
    Unk020b4a44 *p28;
    s32 v;
    u8 x;
    u8 y;
    s32 j;
    s32 r6;
    s32 r7;

    v = data_0217d3ec->mUnk_0c;
    x = data_0215d03c[v * 2];
    y = data_0215d03d[v * 2];
    r6 = data_0215d034[x] << 5;
    r7 = (0xe - data_0215d034[x]) << 5;
    k8 = data_0215d030[y] << 5;
    kc = (0xc - data_0215d030[y]) << 5;
    if (((Unk027ffc40 *)0x027ffc40)->mUnk_00 == 2) {
        func_020b4934(&p14, func_0204799c("common/select_race_rule_s_b.NCGR"));
        func_020b4810(&p18, func_0204799c("common/select_race_rule_download_bg_m.NSCR"));
        func_020b4a44(&p1c, func_0204799c("common/select_race_rule_s_b.NCLR"));
        p20 = p14;
        func_020b4810(&p24, func_0204799c("common/select_race_rule_download_bg_s.NSCR"));
        p28 = p1c;
    } else {
        if (data_0215d038[x] != 0) {
            func_020b496c(&p14, func_02047a28(data_0216e390[x]));
            func_020b4810(&p18, func_02047a28(data_0216e388[x]));
            func_020b4a7c(&p1c, func_02047a28(data_0216e398[x]));
        } else {
            func_020b496c(&p14, func_0204799c(data_0216e390[x]));
            func_020b4810(&p18, func_0204799c(data_0216e388[x]));
            func_020b4a7c(&p1c, func_0204799c(data_0216e398[x]));
        }
        if (data_0215d038[y] != 0) {
            func_020b496c(&p20, func_02047a28(data_0216e380[y]));
            func_020b4810(&p24, func_02047a28(data_0216e384[y]));
            func_020b4a7c(&p28, func_02047a28(data_0216e37c[y]));
        } else {
            func_020b496c(&p20, func_0204799c(data_0216e380[y]));
            func_020b4810(&p24, func_0204799c(data_0216e384[y]));
            func_020b4a7c(&p28, func_0204799c(data_0216e37c[y]));
        }
    }
    func_02016468(7, 0, p14->mUnk_14, p14->mUnk_10);
    func_02016468(0xb, 0, p18->mUnk_0c, p18->mUnk_08);
    func_02016468(0xf, r6, (void *)((u32)p1c->mUnk_0c + r6), r7);
    a -= p20->mUnk_10;
    func_02016468(0x15, a, p20->mUnk_14, p20->mUnk_10);
    for (i = 0; i < 0x20; i++) {
        for (j = 0; j < 0x20; j++) {
            *(data_0217d3ec->mUnk_10 + i * 0x20 + j) = (a >> 5) + *((u16 *)p24->mUnk_0c + i * 0x20 + j);
        }
    }
    func_02016468(0x19, 0, data_0217d3ec->mUnk_10, p24->mUnk_08);
    func_02016468(0x1f, k8, (void *)((u32)p28->mUnk_0c + k8), kc);
    return a;
}

#pragma thumb off
