#include "01/code_021a4724.h"
#include "01/code_021a5140.h"
#include "01/code_02185000.h"
#include "01/code_02180ce8.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_02148000.h"
#include "code_0214b824.h"
#include "Main/Unknown/code_020ca000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02077000.h"
#include "Main/Unknown/code_02078000.h"
#include "Main/Unknown/code_02110000.h"
#include "Main/Unknown/code_0214a000.h"
#include "registers.h"

void func_ov001_021a4fa0(void) {
    reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | 0x1700;
    reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffcfffef;
    reg_G2_BG0CNT = (reg_G2_BG0CNT & ~3) | 1;
    reg_G2_BG1CNT = reg_G2_BG1CNT & ~3;
    reg_G2_BG1CNT = (reg_G2_BG1CNT & 0x43) | 0x400;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & ~3) | 3;
    reg_G2_BG2CNT = (reg_G2_BG2CNT & 0x43) | 0x600;
    func_0200ee74(data_ov001_021ca41c->mUnk_0808->mUnk_0c, data_ov001_021ca41c->mUnk_0808->mUnk_08);
    func_0214c090((const void *) data_ov001_021ca41c->mUnk_0808->mUnk_0c, 0, data_ov001_021ca41c->mUnk_0808->mUnk_08);
    func_0200ee74((const void *) data_ov001_021ca41c->mUnk_0810->mUnk_14, data_ov001_021ca41c->mUnk_0810->mUnk_10);
    func_0214bf04((const void *) (data_ov001_021ca41c->mUnk_0810->mUnk_14), 0, data_ov001_021ca41c->mUnk_0810->mUnk_10);
    func_0200ee74(data_ov001_021ca41c->mUnk_080c->mUnk_0c, data_ov001_021ca41c->mUnk_080c->mUnk_08);
    func_0214c160((const void *) data_ov001_021ca41c->mUnk_080c->mUnk_0c, 0, data_ov001_021ca41c->mUnk_080c->mUnk_08);
    func_0200ee74((const void *) data_ov001_021ca41c->mUnk_0814->mUnk_14, data_ov001_021ca41c->mUnk_0814->mUnk_10);
    func_0214ba2c((const void *) (data_ov001_021ca41c->mUnk_0814->mUnk_14), 0, data_ov001_021ca41c->mUnk_0814->mUnk_10);
    func_0200ee74(data_ov001_021ca41c->mUnk_0a7c, 0x200);
    func_0214b95c((const void *) data_ov001_021ca41c->mUnk_0a7c, 0, 0x200);
    func_0200ee74(data_ov001_021ca41c->mUnk_0818->mUnk_0c, data_ov001_021ca41c->mUnk_0818->mUnk_08);
    func_0214bd6c((const void *) data_ov001_021ca41c->mUnk_0818->mUnk_0c, 0, data_ov001_021ca41c->mUnk_0818->mUnk_08);
    func_0200ee74(data_ov001_021ca41c->mUnk_081c->mUnk_0c, data_ov001_021ca41c->mUnk_081c->mUnk_08);
    func_0214bc9c((const void *) data_ov001_021ca41c->mUnk_081c->mUnk_0c, 0, data_ov001_021ca41c->mUnk_081c->mUnk_08);
    reg_G2_BG1OFS = 0;
    reg_G2_BG2OFS = 0;
}

void func_ov001_021a4d10(void) {
    func_02148934(1);
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | 0x1e00;
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & ~3) | 1;
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & 0x43) | 0x8a10;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~3) | 2;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & 0x43) | 0xc10;
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~3) | 3;
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & 0x43) | 0xe10;
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & ~3) | 2;
    reg_G2S_DB_BG0OFS = 0;
    reg_G2S_DB_BG1OFS = 0;
    reg_G2S_DB_BG2OFS = 0;
    func_0214a428((u32 *) 0x04001030, data_ov001_021a6fd8, 16, 16, -0x70, -0x40);
    func_0200ee74(data_ov001_021ca41c->mUnk_082c->mUnk_0c, data_ov001_021ca41c->mUnk_082c->mUnk_08);
    func_0214c028((const void *) data_ov001_021ca41c->mUnk_082c->mUnk_0c, 0, data_ov001_021ca41c->mUnk_082c->mUnk_08);
    func_0200ee74((const void *) data_ov001_021ca41c->mUnk_0834->mUnk_14, data_ov001_021ca41c->mUnk_0834->mUnk_10);
    func_0214bea4((const void *) (data_ov001_021ca41c->mUnk_0834->mUnk_14), 0, data_ov001_021ca41c->mUnk_0834->mUnk_10);
    func_0200ee74(data_ov001_021ca41c->mUnk_0830->mUnk_0c, data_ov001_021ca41c->mUnk_0830->mUnk_08);
    func_0214c0f8((const void *) data_ov001_021ca41c->mUnk_0830->mUnk_0c, 0, data_ov001_021ca41c->mUnk_0830->mUnk_08);
    func_0200ee74((const void *) data_ov001_021ca41c->mUnk_0838->mUnk_14, data_ov001_021ca41c->mUnk_0838->mUnk_10);
    func_0214b9c4((const void *) (data_ov001_021ca41c->mUnk_0838->mUnk_14), 0, data_ov001_021ca41c->mUnk_0838->mUnk_10);
    func_0200ee74((const void *) func_ov001_02181174(), func_ov001_02181180());
    func_0214b824((const void *) (func_ov001_02181174()), func_ov001_02181194(), func_ov001_02181180());
    func_0200ee74(data_ov001_021ca41c->mUnk_0848->mUnk_0c, data_ov001_021ca41c->mUnk_0848->mUnk_08);
    func_0214bdd4((const void *) data_ov001_021ca41c->mUnk_0848->mUnk_0c, 0, data_ov001_021ca41c->mUnk_0848->mUnk_08);
    func_0200ee74(data_ov001_021ca41c->mUnk_0840->mUnk_0c, data_ov001_021ca41c->mUnk_0840->mUnk_08);
    func_0214bd04((const void *) data_ov001_021ca41c->mUnk_0840->mUnk_0c, 0, data_ov001_021ca41c->mUnk_0840->mUnk_08);
    func_0200ee74(data_ov001_021ca41c->mUnk_0844->mUnk_0c, data_ov001_021ca41c->mUnk_0844->mUnk_08);
    func_0214bc34((const void *) data_ov001_021ca41c->mUnk_0844->mUnk_0c, 0, data_ov001_021ca41c->mUnk_0844->mUnk_08);
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x1010;
    func_0200ee74(data_ov001_021ca41c->mUnk_084c->mUnk_0c, data_ov001_021ca41c->mUnk_084c->mUnk_08);
    func_0214bb64((const void *) data_ov001_021ca41c->mUnk_084c->mUnk_0c, 0, data_ov001_021ca41c->mUnk_084c->mUnk_08);
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x1218;
    func_0200ee74((const void *) func_ov001_021811bc(), func_ov001_02181198());
    func_0214bb64((const void *) (func_ov001_021811bc()), func_ov001_021811b8(), func_ov001_02181198());
}

void func_ov001_021a4ba0(void) {
    func_02148934(1);
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | 0x1600;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~3) | 3;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & 0x43) | 0xe10;
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~3) | 3;
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & 0x43) | 0x1010;
    reg_G2S_DB_BG1OFS = 0;
    reg_G2S_DB_BG2OFS = 0;
    reg_G2S_DB_BG3OFS = 0;
    func_0200ee74(data_ov001_021ca41c->mUnk_082c->mUnk_0c, data_ov001_021ca41c->mUnk_082c->mUnk_08);
    func_0214c028((const void *) data_ov001_021ca41c->mUnk_082c->mUnk_0c, 0, data_ov001_021ca41c->mUnk_082c->mUnk_08);
    func_0200ee74((const void *) data_ov001_021ca41c->mUnk_0860->mUnk_14, data_ov001_021ca41c->mUnk_0860->mUnk_10);
    func_0214bea4((const void *) (data_ov001_021ca41c->mUnk_0860->mUnk_14), 0, data_ov001_021ca41c->mUnk_0860->mUnk_10);
    func_0200ee74(data_ov001_021ca41c->mUnk_0830->mUnk_0c, data_ov001_021ca41c->mUnk_0830->mUnk_08);
    func_0214c0f8((const void *) data_ov001_021ca41c->mUnk_0830->mUnk_0c, 0, data_ov001_021ca41c->mUnk_0830->mUnk_08);
    func_0200ee74((const void *) data_ov001_021ca41c->mUnk_0864->mUnk_14, data_ov001_021ca41c->mUnk_0864->mUnk_10);
    func_0214b9c4((const void *) (data_ov001_021ca41c->mUnk_0864->mUnk_14), 0, data_ov001_021ca41c->mUnk_0864->mUnk_10);
    func_0200ee74(data_ov001_021ca41c->mUnk_0868->mUnk_0c, data_ov001_021ca41c->mUnk_0868->mUnk_08);
    func_0214bd04((const void *) data_ov001_021ca41c->mUnk_0868->mUnk_0c, 0, data_ov001_021ca41c->mUnk_0868->mUnk_08);
    func_0200ee74(data_ov001_021ca41c->mUnk_086c->mUnk_0c, data_ov001_021ca41c->mUnk_086c->mUnk_08);
    func_0214bc34((const void *) data_ov001_021ca41c->mUnk_086c->mUnk_0c, 0, data_ov001_021ca41c->mUnk_086c->mUnk_08);
}

void func_ov001_021a4b28(void) {
    func_020ca6a8();
    func_020ca688(1);
    data_ov001_021ca41c->mUnk_1090 = 10;
    data_ov001_021ca41c->mUnk_1098 = 14;
    func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 1), -3);
    func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 2), -3);
    func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 3), -3);
}

void func_ov001_021a4aac(void) {
    func_020ca688(0);
    data_ov001_021ca41c->mUnk_1090 = 0;
    data_ov001_021ca41c->mUnk_1098 = 15;
    data_ov001_021ca41c->mUnk_10b0 = 0;
    func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 1), -1);
    func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 2), -1);
    func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 3), -1);
}

void func_ov001_021a4a10(void) {
    data_ov001_021ca41c->mUnk_1090 = 2;
    data_ov001_021ca41c->mUnk_1098 = 2;
    data_ov001_021ca41c->mUnk_10a0 = 0;
    data_ov001_021ca41c->mUnk_10a4 = 32;
    func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_085c, 1), 0);
    func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 1), -3);
    func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 2), -3);
    func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 3), -3);
}

void func_ov001_021a499c(void) {
    data_ov001_021ca41c->mUnk_10a0 += data_ov001_021ca41c->mUnk_10a4;
    data_ov001_021ca41c->mUnk_10a4 -= 2;
    if (data_ov001_021ca41c->mUnk_10a0 >= 0xc0) {
        data_ov001_021ca41c->mUnk_10a0 = 0xc0;
        data_ov001_021ca41c->mUnk_1090 = 1;
        data_ov001_021ca41c->mUnk_1098 = 3;
        data_ov001_021ca41c->mUnk_10b0 = 0;
    }
    data_ov001_021ca41c->mUnk_085c->mUnk_14 = data_ov001_021ca41c->mUnk_10a0 - 0xc0;
}

void func_ov001_021a4914(void) {
    data_ov001_021ca41c->mUnk_1090 = 3;
    data_ov001_021ca41c->mUnk_1098 = 6;
    data_ov001_021ca41c->mUnk_10a0 = 0xc0;
    data_ov001_021ca41c->mUnk_10a4 = -0x20;
    func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 1), -1);
    func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 2), -1);
    func_ov001_02185018(func_ov001_02185160(data_ov001_021ca41c->mUnk_0858, 3), -1);
}

void func_ov001_021a48a4(void) {
    data_ov001_021ca41c->mUnk_10a0 += data_ov001_021ca41c->mUnk_10a4;
    data_ov001_021ca41c->mUnk_10a4 += 2;
    if (data_ov001_021ca41c->mUnk_10a0 <= 0) {
        data_ov001_021ca41c->mUnk_10a0 = 0;
        data_ov001_021ca41c->mUnk_1090 = 0;
        data_ov001_021ca41c->mUnk_1098 = 7;
        data_ov001_021ca41c->mUnk_10b0 = 0;
    }
    data_ov001_021ca41c->mUnk_085c->mUnk_14 = data_ov001_021ca41c->mUnk_10a0 - 0xc0;
}

void func_ov001_021a4878(void) {
    data_ov001_021ca41c->mUnk_1090 = 5;
    data_ov001_021ca41c->mUnk_1098 = 13;
    data_ov001_021ca41c->mUnk_109c = 0;
}

void func_ov001_021a4844(void) {
    data_ov001_021ca41c->mUnk_1090 = 7;
    data_ov001_021ca41c->mUnk_1098 = 10;
    data_ov001_021ca41c->mUnk_109c = 0;
    func_02110aac(2, 0);
}

void func_ov001_021a4804(void) {
    data_ov001_021ca41c->mUnk_109c += 2;
    if (data_ov001_021ca41c->mUnk_109c > 16) {
        data_ov001_021ca41c->mUnk_109c = 16;
        data_ov001_021ca41c->mUnk_1090 = 6;
        data_ov001_021ca41c->mUnk_1098 = 9;
    }
}

void func_ov001_021a47b4(void) {
    data_ov001_021ca41c->mUnk_109c -= 2;
    if (data_ov001_021ca41c->mUnk_109c < 0) {
        data_ov001_021ca41c->mUnk_109c = 0;
        data_ov001_021ca41c->mUnk_1090 = 4;
        data_ov001_021ca41c->mUnk_1098 = 11;
        data_ov001_021ca41c->mUnk_10b0 = 0;
    }
}

void func_ov001_021a4774(void) {
    data_ov001_021ca41c->mUnk_109c += 2;
    if (data_ov001_021ca41c->mUnk_109c > 16) {
        data_ov001_021ca41c->mUnk_109c = 16;
        data_ov001_021ca41c->mUnk_1090 = 8;
        data_ov001_021ca41c->mUnk_1098 = 12;
    }
}

void func_ov001_021a4724(void) {
    data_ov001_021ca41c->mUnk_109c -= 2;
    if (data_ov001_021ca41c->mUnk_109c < 0) {
        data_ov001_021ca41c->mUnk_109c = 0;
        data_ov001_021ca41c->mUnk_1090 = 0;
        data_ov001_021ca41c->mUnk_1098 = 8;
        data_ov001_021ca41c->mUnk_10b0 = 0;
    }
}
