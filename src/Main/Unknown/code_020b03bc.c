#include "Main/Unknown/code_020b03bc.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020b3adc.h"
#include "Main/Unknown/code_020b32ec.h"
#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_020b6d98.h"
#include "Main/Unknown/code_020b85f0.h"
#include "Main/Unknown/code_020b8624.h"
#include "00/code_02182fdc.h"
#include "Main/Unknown/code_020beb9c.h"
#include "Main/Unknown/code_020c3200.h"
#include "Main/Unknown/code_020c3e00.h"
#include "Main/Unknown/code_020c4780.h"
#include "Main/Unknown/code_020c4bec.h"
#include "Main/Unknown/code_020cffa0.h"
#include "Main/Unknown/code_020d0bd0.h"
#include "Main/Unknown/code_020d12b0.h"
#include "Main/Unknown/code_020d1464.h"
#include "Main/Unknown/code_020d20a8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_020b2000.h"
#include "Main/Unknown/code_020b2ec0.h"
#include "Main/Unknown/code_020c5db0.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "code_0214b824.h"
#include "code_021488e8.h"
#include "code_0214a390.h"
#include "code_0214c778.h"
#include "Main/Unknown/code_020ad000.h"
#include "Main/Unknown/code_020b3000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b6000.h"
#include "Main/Unknown/code_020ba000.h"
#include "Main/Unknown/code_020bb000.h"
#include "Main/Unknown/code_020bc11c.h"
#include "Main/Unknown/code_020bcb74.h"
#include "Main/Unknown/code_020be7fc.h"
#include "Main/Unknown/code_020c53c4.h"
#include "Main/Unknown/code_020c5ce0.h"
#include "Main/Unknown/code_020c5e30.h"
#include "Main/Unknown/code_020cf310.h"
#include "Main/Unknown/code_0212b1c0.h"
#include "Main/Unknown/code_0212b5ec.h"
#include "registers.h"

void func_020b18b0(void) {
    if (func_020b64e8() != 0) {
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1c00;
    } else {
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1400;
    }
    func_02148934(5);
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~3) | 2;
    reg_G2S_DB_BG2CNT &= ~0x40;
    reg_G2S_DB_BG3CNT &= ~0x40;
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & 0x43) | 0x8410;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | 3;
    reg_G2S_DB_BG3CNT &= ~0x40;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x8810 | ((func_020b6430() != 0) << 13);
}

void func_020b17a4(void) {
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1e00;
    func_02148934(0);
    reg_G2S_DB_BG1OFS = 0;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~3) | 3;
    reg_G2S_DB_BG1CNT &= ~0x40;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & 0x43) | 8;
    reg_G2S_DB_BG2OFS = 0x100;
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~3) | 2;
    reg_G2S_DB_BG2CNT &= ~0x40;
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & 0x43) | 0x4c08;
    reg_G2S_DB_BG3OFS = 0x100;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | 2;
    reg_G2S_DB_BG3CNT &= ~0x40;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x4e08;
}

void func_020b0b8c(void) {
    s32 i;
    u32 v;
    s32 w;
    s32 a;

    v = data_021759c0->mUnk_00c;
    if (v == 3) {
        func_020c4e48();
        return;
    }
    if (v == 5) {
        return;
    }
    if (v == 6) {
        *(vu16 *) 0x05000000 = 0;
        func_020d159c();
        func_0212b1c0();
        return;
    }
    if (data_0217b350->mUnk_898 == 0) {
        return;
    }
    if (data_0217b350->mUnk_840 != 0) {
        func_0214ba94(func_020b3374()->mUnk_14, 0, 0x3000);
        data_0217b350->mUnk_840 = 0;
        func_0214c090(func_020b85f0(1)->mUnk_00->mUnk_0c, 0, func_020b85f0(1)->mUnk_00->mUnk_08);
        func_0214bf04(func_020b85f0(1)->mUnk_04->mUnk_14, 0, 0x4000);
        data_0217b350->mUnk_848 = 1;
        data_0217b350->mUnk_844 = 1;
        reg_GX_DISPCNT &= ~0xe000;
    } else if (data_0217b350->mUnk_844 != 0) {
        if (func_020b2ec0() == 0) {
            if (data_0217b350->mUnk_844++ >= data_0217b350->mUnk_850) {
                if (data_021759c0->mUnk_08 == 0 && data_021759c0->mUnk_00c == 0) {
                    w = (reg_GX_DISPCNT & 0x1f00) >> 8;
                    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | ((w | 8) << 8);
                    reg_G2_BG3CNT = (reg_G2_BG3CNT & ~3) | 1;
                    reg_G2_BG3CNT &= ~0x40;
                    reg_G2_BG3CNT = (reg_G2_BG3CNT & 0x43) | 0x500;
                    func_0214c160(data_0217b350->mUnk_80c[0]->mUnk_0c, 0, data_0217b350->mUnk_80c[0]->mUnk_08);
                    func_0214b88c(data_0217b350->mUnk_814[0]->mUnk_14, 0, data_0217b350->mUnk_814[0]->mUnk_10);
                    func_0214bbcc(data_0217b350->mUnk_81c[1]->mUnk_0c, 0, 0x600);
                    func_0214a40c((u32 *) 0x04000050, 8, 0x27, 5, 9);
                }
                data_0217b350->mUnk_844 = 0;
                data_0217b350->mUnk_84c = 1;
            }
        }
    }
    v = data_021759c0->mUnk_08;
    if (v == 0 && data_0217b350->mUnk_84c != 0) {
        reg_G2_BG3OFS = 0x01ff0000 & (func_020ae4c0(1, -64, 0, func_020c5db0(), 20) << 16);
    } else if (v == 4 && data_0217b350->mUnk_84c != 0) {
        func_0214ba94(func_020b3374()->mUnk_14, 0, 0x3000);
        func_0214bdd4(func_020b32f8(), 0, 0x600);
    }
    func_0200ee74(data_0217b350->mUnk_004, 0x400);
    func_0214bfcc(data_0217b350->mUnk_004, 0, 0x400);
    func_0200ee74(data_0217b350->mUnk_408, 0x400);
    func_0214bf64(data_0217b350->mUnk_408, 0, 0x400);
    if (data_0217b350->mUnk_82c != 0) {
        switch (data_0217b350->mUnk_828) {
            case 0:
                reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1c00;
                func_02148934(0);
                reg_G2S_DB_BG2OFS = 0;
                reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~3) | 2;
                reg_G2S_DB_BG2CNT &= ~0x40;
                reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & 0x43) | 0x208;
                reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~3) | 3;
                reg_G2S_DB_BG3CNT &= ~0x40;
                reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x308;
                func_0214c0f8(data_0217b34c, 0, 0x200);
                break;
            case 1:
            case 2:
            case 3:
                func_020b18b0();
                func_0214c0f8(func_020b33c4()->mUnk_0c, 0, 0x200);
                break;
            case 4:
            case 5:
                reg_G2S_DB_BG0OFS = 0;
                reg_G2S_DB_BG0CNT = reg_G2S_DB_BG0CNT & ~3;
                reg_G2S_DB_BG0CNT &= ~0x40;
                reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & 0x43) | 0x10c;
                func_020b17a4();
                func_0214c0f8(func_020c3e2c(0)->mUnk_00->mUnk_0c, 0, func_020c3e2c(0)->mUnk_00->mUnk_08);
                func_0214b9c4(func_020c3e2c(0)->mUnk_04->mUnk_14, 0, func_020c3e2c(0)->mUnk_04->mUnk_10);
                func_0214c028(func_020b85f0(7)->mUnk_00->mUnk_0c, 0, 0x80);
                func_0214bea4(func_020b85f0(7)->mUnk_04->mUnk_14, 0, 0x4000);
                func_0214ba94(func_020b3374()->mUnk_14, 0, 0x3000);
                func_0214bdd4(func_020b32f8(), 0, 0x600);
                break;
            case 6:
                break;
        }
    }
    switch (data_0217b350->mUnk_828) {
        case 0:
            reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1c00;
            a = data_0217b350->mUnk_000 / 6;
            reg_G2S_DB_BG3OFS = (a & 0x1ff) | (((0x200 - a) << 16) & 0x01ff0000);
            break;
        case 1:
        case 2:
        case 3:
            if (data_021759c0->mUnk_08 == 4) {
                func_0214c028(func_020b85f0(6)->mUnk_00->mUnk_0c, 0, func_020b85f0(6)->mUnk_00->mUnk_08);
            }
            func_0214a428((u32 *) 0x04001020, data_0217b350->mUnk_858[0].mUnk_00, data_0217b350->mUnk_858[0].mUnk_10,
                          data_0217b350->mUnk_858[0].mUnk_14, data_0217b350->mUnk_858[0].mUnk_18,
                          data_0217b350->mUnk_858[0].mUnk_1c);
            if (func_020b64e8() != 0) {
                func_0214a428((u32 *) 0x04001030, data_0217b350->mUnk_858[1].mUnk_00,
                              data_0217b350->mUnk_858[1].mUnk_10, data_0217b350->mUnk_858[1].mUnk_14,
                              data_0217b350->mUnk_858[1].mUnk_18, data_0217b350->mUnk_858[1].mUnk_1c);
            }
            func_020cf340((Unk020cf340 *) &data_0217b34c[0x100]);
            if (func_020b64e8() != 0) {
                if (func_020b4e0c() != 0) {
                    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1c00;
                } else {
                    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1800;
                }
            } else {
                reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1400;
            }
            break;
        case 4:
            reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1e00;
            switch (data_021759c0->mUnk_08) {
                case 2:
                case 3:
                    func_0214ba94(func_020b3374()->mUnk_14, 0, 0x800);
                    break;
            }
            w = func_020c3e00();
            if (w < 0x100) {
                a = -w & 0x1ff;
                reg_G2S_DB_BG2OFS = a;
                reg_G2S_DB_BG3OFS = a;
                func_0214bc34(func_020c3e14(1)->mUnk_0c, 0, 0x600);
                func_0214bb64(func_020c3e14(2)->mUnk_0c, 0, 0x600);
            }
            break;
        case 5:
            reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1e00;
            switch (data_021759c0->mUnk_08) {
                case 2:
                case 3:
                    func_0214ba94(func_020b3374()->mUnk_14, 0, 0x800);
                    break;
            }
            w = func_020c3e00();
            if (data_0217b350->mUnk_830 != 0) {
                func_0214bd04(func_020c3e14(3)->mUnk_0c, 0, func_020c3e14(3)->mUnk_08);
                func_0214bc34(func_020c3e14(4)->mUnk_0c, 0, func_020c3e14(4)->mUnk_08);
                func_0214bb64(func_020c3e14(5)->mUnk_0c, 0, func_020c3e14(5)->mUnk_08);
                func_0214c028(func_020b85f0(8)->mUnk_00->mUnk_0c, 0, 0x20);
                func_0214c028(func_020b85f0(8)->mUnk_00->mUnk_0c + 0xc0, 0x180, 0x80);
                func_0214bea4(func_020b85f0(8)->mUnk_04->mUnk_14, 0, 0x4000);
                data_0217b350->mUnk_830 = 0;
            }
            if (w < 0x100) {
                reg_G2S_DB_BG2OFS = w & 0x1ff;
                reg_G2S_DB_BG3OFS = -w & 0x1ff;
            }
            break;
        case 6:
            if (data_0217b350->mUnk_834 != 0) {
                reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | 0x1200;
                func_02148934(0);
                reg_G2S_DB_BG1OFS = 0;
                reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~3) | 3;
                reg_G2S_DB_BG1CNT &= ~0x40;
                reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & 0x43) | 8;
                func_0214c0f8(data_0217b350->mUnk_80c[1]->mUnk_0c, 0, 0x20);
                func_0214b9c4(data_0217b350->mUnk_814[1]->mUnk_14, 0, data_0217b350->mUnk_814[1]->mUnk_10);
                func_0214bd04(data_0217b350->mUnk_81c[2]->mUnk_0c, 0, data_0217b350->mUnk_81c[2]->mUnk_08);
                func_0214c028(func_020b85f0(9)->mUnk_00->mUnk_0c, 0, 0xa0);
                func_0214c028(func_020b85f0(9)->mUnk_00->mUnk_0c + 0xb0, 0x160, 0xa0);
                func_0214bea4(func_020b85f0(9)->mUnk_04->mUnk_14, 0, 0x4000);
                data_0217b350->mUnk_834 = 0;
            }
            break;
    }
    if (func_020b2e98() != 0) {
        if (data_0217561c->mUnk_4cc == 0) {
            w = (reg_GX_DISPCNT & 0x1f00) >> 8;
            reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | ((w | 4) << 8);
            func_0214bc9c(data_0217b350->mUnk_81c[0]->mUnk_0c, 0, 0x600);
        }
        func_0214bdd4(func_020b32f8(), 0, 0x600);
        w = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | ((w | 1) << 8);
        func_0214a390((u16 *) 0x04001050, 0x3e, 0x3f, 8, 8, -7);
    } else {
        w = (reg_GXS_DB_DISPCNT & 0x1f00) >> 8;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & ~0x1f00) | ((w & ~1) << 8);
        w = (reg_GX_DISPCNT & 0x1f00) >> 8;
        reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | ((w & ~4) << 8);
        func_0214a40c((u32 *) 0x04001050, 0, 0x3f, 6, 10);
    }
    for (i = 0; i < data_021759c0->mUnk_3d0; i++) {
        if (data_0217b350->mUnk_89c[i] != 0 && data_0217b350->mUnk_8bc[i] == 0) {
            func_0212ecc0(&data_0217d068, 0, 0x52);
            data_0217b350->mUnk_8bc[i] = 1;
        }
    }
}

void func_020b03bc(void) {
    s32 i;
    u32 v;
    u16 *p;
    u32 j;
    u16 w;

    v = data_021759c0->mUnk_00c;
    if (v == 3) {
        func_020c4bec();
        return;
    }
    if (v == 5) {
        return;
    }
    if (v == 6) {
        func_020d1464();
        func_0212b5ec(func_020364e0(func_020364e8()));
        return;
    }
    data_0217b350 = func_02036bec(func_020364e0(func_020364e8()), 0x914);
    func_020b36dc();
    func_020b3b08();
    func_020b65f0();
    func_020b8624();
    func_020cffa0();
    if (data_021759c0->mUnk_00c == 4) {
        func_020d12b0();
    }
    func_020bb530();
    func_020c53c4();
    func_020ba520();
    func_020c5ce0();
    func_020bc11c();
    func_020bcb74();
    func_020d20a8();
    func_020d0bd0();
    func_020be7fc();
    func_020beb9c();
    func_020c3200();
    func_020c6fac();
    func_020c4780();
    data_0217b350->mUnk_000 = 0;
    for (i = 0; i < 7; i++) {
        data_0217b350->mUnk_80c[i] = 0;
        data_0217b350->mUnk_814[i] = 0;
    }
    data_0217b350->mUnk_828 = 1;
    data_0217b350->mUnk_82c = 0;
    data_0217b350->mUnk_830 = 0;
    data_0217b350->mUnk_838 = 0;
    data_0217b350->mUnk_83c = 0;
    data_0217b350->mUnk_840 = 0;
    data_0217b350->mUnk_844 = 0;
    data_0217b350->mUnk_848 = 0;
    data_0217b350->mUnk_84c = 0;
    data_0217b350->mUnk_850 = 0;
    if (data_021759c0->mUnk_08 == 2) {
        switch (data_021759c0->mUnk_00) {
            case 0x2e:
                data_0217b350->mUnk_854 = 0x40;
                break;
            default:
                data_0217b350->mUnk_854 = 0x64;
                break;
        }
    } else if (data_021759c0->mUnk_08 == 4) {
        switch (data_021759c0->mUnk_00) {
            case 0x30:
            case 0x31:
            case 0x32:
            case 0x33:
                data_0217b350->mUnk_854 = 0x64;
                break;
            default:
                data_0217b350->mUnk_854 = 0x86;
                break;
        }
    } else {
        data_0217b350->mUnk_854 = 0x86;
    }
    data_0217b350->mUnk_898 = 0;
    for (i = 0; i < 8; i++) {
        data_0217b350->mUnk_89c[i] = 0;
        data_0217b350->mUnk_8bc[i] = 0;
    }
    data_0217b350->mUnk_8dc = 0;
    data_0217b350->mUnk_8e0 = -1;
    if (data_021759c0->mUnk_08 == 1 && data_021759c0->mUnk_3d0 > 1) {
        data_0217b350->mUnk_8e4 = 1;
    } else {
        data_0217b350->mUnk_8e4 = 0;
    }
    data_0217b350->mUnk_908 = 0;
    data_0217b350->mUnk_90c = 0;
    data_0217b350->mUnk_910 = data_021759c0->mUnk_08 == 4 ? func_020adc04() : 0;
    func_0214cc04(3, data_0217b350->mUnk_004, 0xc0, 0x400);
    func_0214cc04(3, data_0217b350->mUnk_408, 0xc0, 0x400);
    func_020b4a7c(&data_0217b350->mUnk_80c[0], func_020b47c0("race_m_b.NCLR"));
    func_020b496c(&data_0217b350->mUnk_814[0], func_020b47c0("race_m_b.NCGR"));
    func_020b4810(&data_0217b350->mUnk_81c[0], func_020b47c0("race_m_pause.NSCR"));
    func_020b4810(&data_0217b350->mUnk_81c[1], func_020b47c0("race_m_goal.NSCR"));
    if (data_021759c0->mUnk_08 == 1) {
        func_020b4a7c(&data_0217b350->mUnk_80c[1], func_020b47c0("race_new_record_ta_s_b.NCLR"));
        func_020b496c(&data_0217b350->mUnk_814[1], func_020b47c0("race_new_record_ta_s_b.NCGR"));
        func_020b4810(&data_0217b350->mUnk_81c[2], func_020b47c0("race_new_record_ta_s_bg.NSCR"));
        func_0200ee74(((Unk020b4934 *) data_0217b350->mUnk_81c[0])->mUnk_14,
                      ((Unk020b4934 *) data_0217b350->mUnk_81c[0])->mUnk_10);
        func_0200ee74(data_0217b350->mUnk_81c[2]->mUnk_0c, data_0217b350->mUnk_81c[2]->mUnk_08);
    }
    p = func_020b33c4()->mUnk_0c;
    for (i = 0; i < 0x80; i++) {
        data_0217b34c[i + 0x80] = p[i + 0x80];
    }
    func_020b33c4()->mUnk_0c[0] = data_0217b34c[0x100];
    func_0200ee74(func_020b33c4()->mUnk_0c, 0x200);
    for (i = 0; i < 0x20; i++) {
        w = func_020b33c4()->mUnk_0c[i + 0xe0];
        func_020c3e2c(0)->mUnk_00->mUnk_0c[i + 0xe0] = w;
    }
    func_0214a40c((u32 *) 0x04001050, 0, 0x3f, 6, 10);
    if (data_021759c0->mUnk_08 == 0) {
        func_020b6dc4(func_020b85f0(1)->mUnk_00->mUnk_0c, func_020b85f0(1)->mUnk_04->mUnk_14);
        func_0200ee74(func_020b85f0(1)->mUnk_00->mUnk_0c, func_020b85f0(1)->mUnk_00->mUnk_08);
        func_0200ee74(func_020b85f0(1)->mUnk_04->mUnk_14, func_020b85f0(1)->mUnk_04->mUnk_10);
    }
    func_020b6d98(func_020b85f0(6)->mUnk_00->mUnk_0c, func_020b85f0(6)->mUnk_04->mUnk_14);
    func_0200ee74(func_020b85f0(6)->mUnk_00->mUnk_0c, func_020b85f0(6)->mUnk_00->mUnk_08);
    func_0200ee74(func_020b85f0(6)->mUnk_04->mUnk_14, func_020b85f0(6)->mUnk_04->mUnk_10);
    func_020b46d0(func_020b85f0(6)->mUnk_04->mUnk_14, 0x10, 0, 0x10, 2, func_020b85f0(7)->mUnk_04->mUnk_14, 0x10, 0);
    func_0200ee74(func_020b85f0(7)->mUnk_04->mUnk_14, func_020b85f0(7)->mUnk_04->mUnk_10);
    func_020b46d0(func_020b85f0(6)->mUnk_04->mUnk_14, 0x10, 0, 0x10, 2, func_020b85f0(8)->mUnk_04->mUnk_14, 0x10, 0);
    func_0200ee74(func_020b85f0(8)->mUnk_04->mUnk_14, func_020b85f0(8)->mUnk_04->mUnk_10);
    if (data_021759c0->mUnk_08 == 1) {
        func_020b46d0(func_020b85f0(6)->mUnk_04->mUnk_14, 0x10, 0, 0x10, 2, func_020b85f0(9)->mUnk_04->mUnk_14, 0x10,
                      0);
        func_0200ee74(func_020b85f0(9)->mUnk_04->mUnk_14, func_020b85f0(9)->mUnk_04->mUnk_10);
    }
    func_020b36a4();
    func_020b3adc();
    if (data_021759c0->mUnk_08 == 4) {
        data_0217b488->mUnk_10 = 0;
    }
}
