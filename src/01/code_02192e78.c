#include "01/code_02192e78.h"

#include "01/code_02193000.h"
#include "01/unk_021a9000.h"
#include "Main/Unknown/code_0212a000.h"
#include "Main/Unknown/code_0214a000.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_0214a2a0.h"
#include "Main/Unknown/code_0214a2f4.h"
#include "registers.h"

void func_ov001_021932c8(void) {
    data_ov001_021a9bd0->mUnk_18.mUnk_00 = 0;
    data_ov001_021a9bd0->mUnk_18.mUnk_04 = 0;
    data_ov001_021a9bd0->mUnk_18.mUnk_08 = 0;
    data_ov001_021a9bd0->mUnk_18.mUnk_0c = 0;
}

void func_ov001_02193144(void) {
    Unk02111684_v v;
    func_020b496c(&v.m4934, func_0204799c("Option_top_menu_m_b.ncgr"));
    func_020b4810(&v.m47d8, func_0204799c("Option_top_menu_m.nscr"));
    func_020b4a7c(&v.m4a44, func_0204799c("Option_top_menu_m_b.nclr"));
    func_020b496c(&v.m4934, func_0204799c("Option_select_menu_m_b.ncgr"));
    func_020b4810(&v.m47d8, func_0204799c("Option_select_menu_m.nscr"));
    func_020b4a7c(&v.m4a44, func_0204799c("Option_select_menu_m_b.nclr"));
    func_020b49f4(&v.m4934, func_0204799c("Option_top_menu_s.nce.ncgr"));
    func_020b48ec(&v.m21dc8, func_0204799c("Option_top_menu_s.nce.ncer"));
    func_020b4a7c(&v.m4a44, func_0204799c("Option_top_menu_s_o.nclr"));
    func_020b49f4(&v.m4934, func_0204799c("Option_hensyu_menu_s.nce.ncgr"));
    func_020b48ec(&v.m21dc8, func_0204799c("Option_hensyu_menu_s.nce.ncer"));
    func_020b4a7c(&v.m4a44, func_0204799c("Option_hensyu_menu_s_o.nclr"));
    func_020b49f4(&v.m4934, func_0204799c("Option_select_menu_m.nce.ncgr"));
    func_020b48ec(&v.m21dc8, func_0204799c("Option_select_menu_m.nce.ncer"));
    func_020b4a7c(&v.m4a44, func_0204799c("Option_select_menu_m_o.nclr"));
    func_020b49f4(&v.m4934, func_0204799c("Option_select_menu_s.nce.ncgr"));
    func_020b48ec(&v.m21dc8, func_0204799c("Option_select_menu_s.nce.ncer"));
    func_020b4a7c(&v.m4a44, func_0204799c("Option_select_menu_s_o.nclr"));
    func_020b49f4(&v.m4934, func_0204799c("Option_embrem_select_s.nce.ncgr"));
    func_020b48ec(&v.m21dc8, func_0204799c("Option_embrem_select_s.nce.ncer"));
    func_020b4a7c(&v.m4a44, func_0204799c("Option_embrem_select_s_o.nclr"));
}

void func_ov001_021930ac(void) {
    u32 t;
    vu32 a;
    vu32 b;
    void *d1;
    void *d2;
    t = (reg_GX_DISPCNT & 0x1f00) >> 8;
    t |= 1;
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0x1f00) | (t << 8);
    reg_G2_BG0CNT = (reg_G2_BG0CNT & 0x43) | 0x9000;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 2;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & 0x43) | 0x9204;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & ~3) | 1;
    d1 = (void *) func_0214a2f4();
    a = 0;
    func_0214d05c(a, d1, 0x1000);
    d2 = (void *) func_0214a2a0();
    b = 0;
    func_0214d05c(b, d2, 0x1000);
}

void func_ov001_02192fb8(void *heap, s16 param_2) {
    Unk02125de0Arg arg;
    data_ov001_021a9bd0 = func_02036bec(heap, 0x2c);
    data_ov001_021a9bd0->mUnk_00 = heap;
    data_ov001_021a9bd0->mUnk_28 = func_021250b0(heap);
    func_ov001_021930ac();
    func_0212abdc(heap, func_ov001_0219e920());
    arg.mUnk_00 = 1;
    arg.mUnk_04 = func_020b403c(1);
    arg.mUnk_08 = 0;
    arg.mUnk_0c = 1;
    arg.mUnk_10 = 0;
    arg.mUnk_14 = 0;
    arg.mUnk_18 = 0;
    arg.mUnk_1c = 1;
    arg.mUnk_20 = 1;
    arg.mUnk_24 = 0;
    func_02125c2c();
    func_02125de0(heap, &arg);
    data_ov001_021a9bd0->mUnk_04 = func_020369fc(data_ov001_021a9bd0->mUnk_00);
    func_ov001_02193144();
    func_ov001_021932c8();
    data_ov001_021a9bd0->mUnk_14 = -1;
    switch (param_2) {
        case 0:
            data_ov001_021a9bd0->mUnk_10 = 4;
            data_ov001_021a9bd0->mUnk_08 = 0;
            func_ov001_021932e4();
            break;
        case 14:
            data_ov001_021a9bd0->mUnk_10 = 5;
            data_ov001_021a9bd0->mUnk_08 = 2;
            func_ov001_02199964();
            break;
        case 3:
            data_ov001_021a9bd0->mUnk_10 = 6;
            if (data_0217b488->mUnk_18 == 0) {
                data_ov001_021a9bd0->mUnk_08 = 2;
                func_ov001_02199964();
            } else {
                data_ov001_021a9bd0->mUnk_08 = 3;
                func_ov001_0219d5dc();
            }
            break;
    }
    data_ov001_021a9bd0->mUnk_0c = -1;
    data_ov001_021a9bd0->mUnk_18.mUnk_00(data_ov001_021a9bd0->mUnk_04);
}

void func_ov001_02192f8c(void) {
    if (data_ov001_021a9bd0->mUnk_18.mUnk_04 != 0) {
        data_ov001_021a9bd0->mUnk_18.mUnk_04();
    }
    func_ov001_021932c8();
    func_0212abd0();
    func_02125da0();
    data_ov001_021a9bd0 = 0;
}

void func_ov001_02192ee4(void) {
    if (data_ov001_021a9bd0->mUnk_18.mUnk_08 != 0) {
        data_ov001_021a9bd0->mUnk_18.mUnk_08();
    }
    if (data_ov001_021a9bd0->mUnk_0c != -1) {
        data_ov001_021a9bd0->mUnk_18.mUnk_04();
        func_ov001_021932c8();
        func_02036ab0((void *) data_ov001_021a9bd0->mUnk_04);
        data_ov001_021a9bd0->mUnk_04 = func_020369fc(data_ov001_021a9bd0->mUnk_00);
        switch (data_ov001_021a9bd0->mUnk_0c) {
            case 0:
                func_ov001_021932e4();
                break;
            case 1:
                func_ov001_02198854();
                break;
            case 2:
                func_ov001_02199964();
                break;
            case 3:
                func_ov001_0219d5dc();
                break;
        }
        data_ov001_021a9bd0->mUnk_10 = data_ov001_021a9bd0->mUnk_08;
        data_ov001_021a9bd0->mUnk_08 = data_ov001_021a9bd0->mUnk_0c;
        data_ov001_021a9bd0->mUnk_0c = -1;
        if (data_ov001_021a9bd0->mUnk_18.mUnk_00 != 0) {
            data_ov001_021a9bd0->mUnk_18.mUnk_00(data_ov001_021a9bd0->mUnk_04);
        }
    }
    func_02125928();
    func_0212a920();
}

void func_ov001_02192ec4(void) {
    if (data_ov001_021a9bd0->mUnk_18.mUnk_0c != (UnkFunc *) 0x0) {
        (*data_ov001_021a9bd0->mUnk_18.mUnk_0c)();
    }
    func_021258f0();
    return;
}

void func_ov001_02192eac(UnkFunc **param_1) {
    data_ov001_021a9bd0->mUnk_18 = *(Unk021a9bd0_18 *) param_1;
}

void func_ov001_02192ea0(u32 param_1) {
    data_ov001_021a9bd0->mUnk_0c = param_1;
    return;
}

u32 func_ov001_02192e94(void) {
    return (u32) data_ov001_021a9bd0->mUnk_10;
}

int func_ov001_02192e84(void) {
    return (int) data_ov001_021a9bd0->mUnk_14;
}

void func_ov001_02192e78(u16 param_1) {
    data_ov001_021a9bd0->mUnk_14 = param_1;
    return;
}
