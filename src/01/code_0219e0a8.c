#include "01/code_0219e0a8.h"
#include "01/code_0219e000.h"
#include "01/code_0219f000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02105000.h"
#include "Main/Unknown/code_02037000.h"

void func_ov001_0219e6ec(void *a) {
    void *result;

    data_ov001_021ca400 = func_02036bec(a, 0x470);
    data_ov001_021ca400->mUnk_010 = a;
    data_ov001_021ca400->mUnk_01c = func_021250b0(a);
    data_ov001_021ca400->mUnk_014 = -1;
    data_ov001_021ca400->mUnk_000 = 0;
    data_ov001_021ca400->mUnk_004 = data_ov001_021ca400->mUnk_000;
    data_ov001_021ca400->mUnk_008 = 0;
    if (data_021759c0->mUnk_00 == 0x36) {
        data_ov001_021ca400->mUnk_00c = 1;
    } else {
        data_ov001_021ca400->mUnk_00c = 0;
    }
    data_ov001_021ca400->mUnk_018 = 0;
    data_ov001_021ca400->mUnk_46c = func_02047a28("common.bmg");
    func_ov001_0219e660();
    func_ov001_0219e38c();
    func_020ae6d4(data_ov001_021ca400->mUnk_068, 0);
    func_02124ed0(data_ov001_021ca400->mUnk_010, data_ov001_021ca400->mUnk_030, data_ov001_021ca400->mUnk_034,
                  &data_ov001_021ca400->mUnk_020);
    result = 0;
    data_ov001_021ca400->mUnk_020->mUnk_00 = 0;
    {
        u16 table[2][2] = {{200, 24}, {200, 24}};

        switch (data_ov001_021ca400->mUnk_00c) {
            case 0:
                result = func_020b3f7c(data_ov001_021ca400->mUnk_46c, 0x77);
                break;
            case 1:
                result = func_020b3f7c(data_ov001_021ca400->mUnk_46c, 0x78);
                break;
        }
        func_021243ac(data_ov001_021ca400->mUnk_010, 0, data_ov001_021ca400->mUnk_034,
                      table[data_ov001_021ca400->mUnk_00c][0], table[data_ov001_021ca400->mUnk_00c][1], 0,
                      data_ov001_021ca400->mUnk_024, data_ov001_021ca400->mUnk_030, data_ov001_021ca400->mUnk_020,
                      0x8000);
        func_0212426c(0, 0, data_ov001_021ca400->mUnk_034, result, data_ov001_021ca400->mUnk_030,
                      data_ov001_021ca400->mUnk_020);
    }
}

void func_ov001_0219e6e0(void) {
    *(u32 *) &data_ov001_021ca400 = 0;
    return;
}

void func_ov001_0219e660(void) {
    *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffffe0ff) | 0x100;
    *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | 0x100;
    *(vu16 *) 0x4000008 = (*(vu16 *) 0x4000008 & ~3) | 3;
    *(vu16 *) 0x4000008 = (*(vu16 *) 0x4000008 & 0x43) | 0x1f00;
    *(vu16 *) 0x4001008 = (*(vu16 *) 0x4001008 & 0x43) | 0x1000;
    *(vu32 *) 0x4000018 = 0;
    *(vu32 *) 0x4001010 = 0;
    *(vu16 *) 0x5000000 = 0;
    *(vu16 *) 0x5000400 = 0;
}

void func_ov001_0219e5d4(int i) {
    func_02016468(4, 0, data_ov001_021ca400->mUnk_038[i]->mUnk_14, data_ov001_021ca400->mUnk_038[i]->mUnk_10);
    func_02016468(8, 0, data_ov001_021ca400->mUnk_040[i]->mUnk_0c, data_ov001_021ca400->mUnk_040[i]->mUnk_08);
    func_02016468(0xf, 0, data_ov001_021ca400->mUnk_048[i]->mUnk_0c, data_ov001_021ca400->mUnk_048[i]->mUnk_08);
    func_02016468(0x14, 0, data_ov001_021ca400->mUnk_050[i]->mUnk_14, data_ov001_021ca400->mUnk_050[i]->mUnk_10);
    func_02016468(0x18, 0, data_ov001_021ca400->mUnk_058[i]->mUnk_0c, data_ov001_021ca400->mUnk_058[i]->mUnk_08);
    func_02016468(0x1f, 0, data_ov001_021ca400->mUnk_060[i]->mUnk_0c, data_ov001_021ca400->mUnk_060[i]->mUnk_08);
}

void func_ov001_0219e5a0(void) {
    *((u16 *) 0x04000008u) = *((u16 *) 0x04000008u) & 0x43 | (u16) 0x00001f80u;
    func_ov001_0219e5d4(1);
    data_ov001_021ca400->mUnk_018 = 1;
    return;
}

void func_ov001_0219e38c(void) {
#ifdef version_EUR
    func_020b496c(&data_ov001_021ca400->mUnk_038[0], func_0204799c("logo_end_marioKart_m_b_02.ncgr"));
    func_020b4810(&data_ov001_021ca400->mUnk_040[0], func_0204799c("logo_end_marioKart_m_bg_02.nscr"));
#else
    func_020b496c(&data_ov001_021ca400->mUnk_038[0], func_0204799c("logo_end_marioKart_m_b_01.ncgr"));
    func_020b4810(&data_ov001_021ca400->mUnk_040[0], func_0204799c("logo_end_marioKart_m_bg_01.nscr"));
#endif
    func_020b4a7c(&data_ov001_021ca400->mUnk_048[0], func_0204799c("logo_end_marioKart_m_b.nclr"));
    switch (data_ov001_021ca400->mUnk_00c) {
        case 0:
            func_020b496c(&data_ov001_021ca400->mUnk_038[1], func_0204799c("thanksYou_m_b_00.ncgr"));
            func_020b4810(&data_ov001_021ca400->mUnk_040[1], func_0204799c("thanksYou_m_bg_00.nscr"));
            func_020b4a7c(&data_ov001_021ca400->mUnk_048[1], func_0204799c("thanksYou_m_b_00.nclr"));
            break;
        case 1:
            func_020b496c(&data_ov001_021ca400->mUnk_038[1], func_0204799c("thanksYou_m_b_01_2.ncgr"));
            func_020b4810(&data_ov001_021ca400->mUnk_040[1], func_0204799c("thanksYou_m_bg_01_2.nscr"));
            func_020b4a7c(&data_ov001_021ca400->mUnk_048[1], func_0204799c("thanksYou_m_b_01.nclr"));
            break;
    }
    func_020b496c(&data_ov001_021ca400->mUnk_050[0], func_0204799c("end_allRightsReserved_s_b.ncgr"));
    func_020b4810(&data_ov001_021ca400->mUnk_058[0], func_0204799c("end_allRightsReserved_s_bg.nscr"));
    func_020b4a7c(&data_ov001_021ca400->mUnk_060[0], func_0204799c("end_allRightsReserved_s_b.nclr"));
    func_020b496c(&data_ov001_021ca400->mUnk_050[1], func_0204799c("logo_end_Nintendo_s_b.ncgr"));
    func_020b4810(&data_ov001_021ca400->mUnk_058[1], func_0204799c("logo_end_Nintendo_s_bg.nscr"));
    func_020b4a7c(&data_ov001_021ca400->mUnk_060[1], func_0204799c("logo_end_Nintendo_s_b.nclr"));
    func_020b48ec(&data_ov001_021ca400->mUnk_024, func_0204799c("thanksYou_m.nce.ncer"));
    func_020b4a7c(&data_ov001_021ca400->mUnk_02c, func_0204799c("thanksYou_m_o_00.nclr"));
    switch (data_ov001_021ca400->mUnk_00c) {
        case 0:
            data_ov001_021ca400->mUnk_030 = func_0204799c("ending_thanks_00.bncl");
            data_ov001_021ca400->mUnk_034 = func_0204799c("ending_thanks_00.bnll");
            break;
        case 1:
            data_ov001_021ca400->mUnk_030 = func_0204799c("ending_thanks_01.bncl");
            data_ov001_021ca400->mUnk_034 = func_0204799c("ending_thanks_01.bnll");
            break;
    }
    if (data_0217b488->mUnk_70 != 0) {
        func_ov001_0219e5a0();
    } else {
        func_ov001_0219e5d4(0);
    }
    func_02016468(0xe, 0, data_ov001_021ca400->mUnk_02c->mUnk_0c, data_ov001_021ca400->mUnk_02c->mUnk_08);
}

void func_ov001_0219e34c(void) {
    if (func_02036c5c() != 0) {
        if (data_0217b488->mUnk_70 != 0) {
            data_ov001_021ca400->mUnk_004 = 5;
            data_0217b488->mUnk_70 = 0;
            return;
        }
        data_ov001_021ca400->mUnk_004 = 1;
    }
}

void func_ov001_0219e310(void) {
    data_ov001_021ca400->mUnk_008++;
    if (data_ov001_021ca400->mUnk_008 > data_ov001_021a6c50[data_ov001_021ca400->mUnk_000]) {
        data_ov001_021ca400->mUnk_004 = 2;
        data_ov001_021ca400->mUnk_008 = 0;
        func_02036f10((s16) (data_ov001_021a6c50[2]));
    }
}

void func_ov001_0219e2f0(void) {
    int v1;
    v1 = func_02036d08();
    if (v1 != 0) {
        data_ov001_021ca400->mUnk_004 = 3;
    }
    return;
}

void func_ov001_0219e2b4(void) {
    Unk021ca400 *p;

    data_ov001_021ca400->mUnk_008++;
    p = data_ov001_021ca400;
    if (p->mUnk_008 > data_ov001_021a6c50[3]) {
        p->mUnk_004 = 4;
        data_ov001_021ca400->mUnk_008 = 0;
        func_020370d4(data_ov001_021a6c50[4]);
        func_ov001_0219e5a0();
    }
}

void func_ov001_0219e294(void) {
    int v1;
    v1 = func_02036c5c();
    if (v1 != 0) {
        data_ov001_021ca400->mUnk_004 = 5;
    }
    return;
}

void func_ov001_0219e1f8(void) {
    Unk02175628Index idx = UNK_02175628_INDEX_8;
    u16 flags;
    s32 a;
    s32 b;
    u16 x;

    data_ov001_021ca400->mUnk_008++;
    if (data_ov001_021ca400->mUnk_008 > data_ov001_021a6c50[data_ov001_021ca400->mUnk_000]) {
        data_ov001_021ca400->mUnk_008 = data_ov001_021a6c50[data_ov001_021ca400->mUnk_000];
        flags = data_02175628[idx].mUnk_00 & 0xc0f;
        if (flags == 0) {
            a = 0;
            b = 0;
            x = data_02175628[idx].mUnk_4c;
            if (x == 0 && data_02175628[idx].mUnk_58 < 5) {
                b = 1;
            }
            if (b == 0 && data_02175628[idx].mUnk_54 == 0 && x != 0) {
                a = 1;
            }
            if (a == 0) {
                return;
            }
        }
        data_ov001_021ca400->mUnk_004 = 6;
        data_ov001_021ca400->mUnk_008 = 0;
        func_02036f10((s16) (data_ov001_021a6c50[6]));
    }
}

void func_ov001_0219e1d4(void) {
    if (func_02036d08() != 0) {
        data_ov001_021ca400->mUnk_004 = 7;
        data_ov001_021ca400->mUnk_008 = 0;
    }
}

void func_ov001_0219e1b0(void) {
    data_ov001_021ca400->mUnk_008++;
    if (data_ov001_021ca400->mUnk_008 > data_ov001_021a6c50[7]) {
        data_ov001_021ca400->mUnk_014 = 0;
    }
}

void func_ov001_0219e118(void) {
    data_ov001_021ca400->mUnk_000 = data_ov001_021ca400->mUnk_004;
    func_020ae6ac((void *) (data_ov001_021ca400->mUnk_068), (void *) (0));
    switch (data_ov001_021ca400->mUnk_000) {
        case 0:
            func_ov001_0219e34c();
            break;
        case 1:
            func_ov001_0219e310();
            break;
        case 2:
            func_ov001_0219e2f0();
            break;
        case 3:
            func_ov001_0219e2b4();
            break;
        case 4:
            func_ov001_0219e294();
            break;
        case 5:
            func_ov001_0219e1f8();
            break;
        case 6:
            func_ov001_0219e1d4();
            break;
        case 7:
            func_ov001_0219e1b0();
            break;
    }
    func_02124c30(data_ov001_021ca400->mUnk_030, data_ov001_021ca400->mUnk_024, data_ov001_021ca400->mUnk_034,
                  data_ov001_021ca400->mUnk_068, data_ov001_021ca400->mUnk_020);
    func_020ae630((void *) (data_ov001_021ca400->mUnk_068), (void *) (0));
}

void func_ov001_0219e0d4(void) {
    u32 bits;

    if (data_ov001_021ca400->mUnk_018 != 0) {
        bits = (*(vu32 *) 0x4000000 & 0x1f00) >> 8;
        *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffffe0ff) | ((bits | 0x10) << 8);
    }
    func_020ae5f0((void *) (data_ov001_021ca400->mUnk_068), (void *) (0));
}

void func_ov001_0219e0c4(void) {
    data_0217b488->mUnk_70 = 1;
}

s32 func_ov001_0219e0b8(void) {
    return data_0217b488->mUnk_70;
}

int func_ov001_0219e0a8(void) {
    return (int) data_ov001_021ca400->mUnk_014;
}
