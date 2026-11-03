#include "01/code_02184f7c.h"
#include "01/code_021a4724.h"
#include "01/code_021a5140.h"
#include "01/code_02185000.h"
#include "01/code_02180ce8.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_020ca670.h"
#include "Main/Unknown/code_020ca6a8.h"
#include "Main/Unknown/code_021108bc.h"
#include "Main/Unknown/code_02148000.h"
#include "code_0200eddc.h"
#include "code_021488e8.h"
#include "code_0214a390.h"
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
    func_0200ee74(gEmblem->mEmblemMONclr->mUnk_0c, gEmblem->mEmblemMONclr->mUnk_08);
    func_0214c090((const void *) gEmblem->mEmblemMONclr->mUnk_0c, 0, gEmblem->mEmblemMONclr->mUnk_08);
    func_0200ee74((const void *) gEmblem->mEmblemMONcgr->mUnk_14, gEmblem->mEmblemMONcgr->mUnk_10);
    func_0214bf04((const void *) (gEmblem->mEmblemMONcgr->mUnk_14), 0, gEmblem->mEmblemMONcgr->mUnk_10);
    func_0200ee74(gEmblem->mEmblemMBNclr->mUnk_0c, gEmblem->mEmblemMBNclr->mUnk_08);
    func_0214c160((const void *) gEmblem->mEmblemMBNclr->mUnk_0c, 0, gEmblem->mEmblemMBNclr->mUnk_08);
    func_0200ee74((const void *) gEmblem->mEmblemMBNcgr->mUnk_14, gEmblem->mEmblemMBNcgr->mUnk_10);
    func_0214ba2c((const void *) (gEmblem->mEmblemMBNcgr->mUnk_14), 0, gEmblem->mEmblemMBNcgr->mUnk_10);
    func_0200ee74(gEmblem->mUnk_0a7c, 0x200);
    func_0214b95c((const void *) gEmblem->mUnk_0a7c, 0, 0x200);
    func_0200ee74(gEmblem->mEmblemMNscr->mUnk_0c, gEmblem->mEmblemMNscr->mUnk_08);
    func_0214bd6c((const void *) gEmblem->mEmblemMNscr->mUnk_0c, 0, gEmblem->mEmblemMNscr->mUnk_08);
    func_0200ee74(gEmblem->mEmblemMBgNscr->mUnk_0c, gEmblem->mEmblemMBgNscr->mUnk_08);
    func_0214bc9c((const void *) gEmblem->mEmblemMBgNscr->mUnk_0c, 0, gEmblem->mEmblemMBgNscr->mUnk_08);
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
    func_0200ee74(gEmblem->mEmblemSONclr->mUnk_0c, gEmblem->mEmblemSONclr->mUnk_08);
    func_0214c028((const void *) gEmblem->mEmblemSONclr->mUnk_0c, 0, gEmblem->mEmblemSONclr->mUnk_08);
    func_0200ee74((const void *) gEmblem->mEmblemSONcgr->mUnk_14, gEmblem->mEmblemSONcgr->mUnk_10);
    func_0214bea4((const void *) (gEmblem->mEmblemSONcgr->mUnk_14), 0, gEmblem->mEmblemSONcgr->mUnk_10);
    func_0200ee74(gEmblem->mEmblemSBNclr->mUnk_0c, gEmblem->mEmblemSBNclr->mUnk_08);
    func_0214c0f8((const void *) gEmblem->mEmblemSBNclr->mUnk_0c, 0, gEmblem->mEmblemSBNclr->mUnk_08);
    func_0200ee74((const void *) gEmblem->mEmblemSBNcgr->mUnk_14, gEmblem->mEmblemSBNcgr->mUnk_10);
    func_0214b9c4((const void *) (gEmblem->mEmblemSBNcgr->mUnk_14), 0, gEmblem->mEmblemSBNcgr->mUnk_10);
    func_0200ee74((const void *) func_ov001_02181174(), func_ov001_02181180());
    func_0214b824((const void *) (func_ov001_02181174()), func_ov001_02181194(), func_ov001_02181180());
    func_0200ee74(gEmblem->mEmblemSTemplateFrameNscr->mUnk_0c, gEmblem->mEmblemSTemplateFrameNscr->mUnk_08);
    func_0214bdd4((const void *) gEmblem->mEmblemSTemplateFrameNscr->mUnk_0c, 0,
                  gEmblem->mEmblemSTemplateFrameNscr->mUnk_08);
    func_0200ee74(gEmblem->mEmblemSToolNscr->mUnk_0c, gEmblem->mEmblemSToolNscr->mUnk_08);
    func_0214bd04((const void *) gEmblem->mEmblemSToolNscr->mUnk_0c, 0, gEmblem->mEmblemSToolNscr->mUnk_08);
    func_0200ee74(gEmblem->mEmblemSBgNscr->mUnk_0c, gEmblem->mEmblemSBgNscr->mUnk_08);
    func_0214bc34((const void *) gEmblem->mEmblemSBgNscr->mUnk_0c, 0, gEmblem->mEmblemSBgNscr->mUnk_08);
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x1010;
    func_0200ee74(gEmblem->mEmblemSTemplateDarkNscr->mUnk_0c, gEmblem->mEmblemSTemplateDarkNscr->mUnk_08);
    func_0214bb64((const void *) gEmblem->mEmblemSTemplateDarkNscr->mUnk_0c, 0,
                  gEmblem->mEmblemSTemplateDarkNscr->mUnk_08);
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
    func_0200ee74(gEmblem->mEmblemSONclr->mUnk_0c, gEmblem->mEmblemSONclr->mUnk_08);
    func_0214c028((const void *) gEmblem->mEmblemSONclr->mUnk_0c, 0, gEmblem->mEmblemSONclr->mUnk_08);
    func_0200ee74((const void *) gEmblem->mEmblemCameraSONcgr->mUnk_14, gEmblem->mEmblemCameraSONcgr->mUnk_10);
    func_0214bea4((const void *) (gEmblem->mEmblemCameraSONcgr->mUnk_14), 0, gEmblem->mEmblemCameraSONcgr->mUnk_10);
    func_0200ee74(gEmblem->mEmblemSBNclr->mUnk_0c, gEmblem->mEmblemSBNclr->mUnk_08);
    func_0214c0f8((const void *) gEmblem->mEmblemSBNclr->mUnk_0c, 0, gEmblem->mEmblemSBNclr->mUnk_08);
    func_0200ee74((const void *) gEmblem->mEmblemCameraSBNcgr->mUnk_14, gEmblem->mEmblemCameraSBNcgr->mUnk_10);
    func_0214b9c4((const void *) (gEmblem->mEmblemCameraSBNcgr->mUnk_14), 0, gEmblem->mEmblemCameraSBNcgr->mUnk_10);
    func_0200ee74(gEmblem->mEmblemCameraSDSNscr->mUnk_0c, gEmblem->mEmblemCameraSDSNscr->mUnk_08);
    func_0214bd04((const void *) gEmblem->mEmblemCameraSDSNscr->mUnk_0c, 0, gEmblem->mEmblemCameraSDSNscr->mUnk_08);
    func_0200ee74(gEmblem->mEmblemCameraSBgNscr->mUnk_0c, gEmblem->mEmblemCameraSBgNscr->mUnk_08);
    func_0214bc34((const void *) gEmblem->mEmblemCameraSBgNscr->mUnk_0c, 0, gEmblem->mEmblemCameraSBgNscr->mUnk_08);
}

void func_ov001_021a4b28(void) {
    func_020ca6a8();
    func_020ca688(1);
    gEmblem->mUnk_1090 = 10;
    gEmblem->mUnk_1098 = 14;
    func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 1), -3);
    func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 2), -3);
    func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 3), -3);
}

void func_ov001_021a4aac(void) {
    func_020ca688(0);
    gEmblem->mUnk_1090 = 0;
    gEmblem->mUnk_1098 = 15;
    gEmblem->mUnk_10b0 = 0;
    func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 1), -1);
    func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 2), -1);
    func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 3), -1);
}

void func_ov001_021a4a10(void) {
    gEmblem->mUnk_1090 = 2;
    gEmblem->mUnk_1098 = 2;
    gEmblem->mUnk_10a0 = 0;
    gEmblem->mUnk_10a4 = 32;
    func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemTemplateSLld, 1), 0);
    func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 1), -3);
    func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 2), -3);
    func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 3), -3);
}

void func_ov001_021a499c(void) {
    gEmblem->mUnk_10a0 += gEmblem->mUnk_10a4;
    gEmblem->mUnk_10a4 -= 2;
    if (gEmblem->mUnk_10a0 >= 0xc0) {
        gEmblem->mUnk_10a0 = 0xc0;
        gEmblem->mUnk_1090 = 1;
        gEmblem->mUnk_1098 = 3;
        gEmblem->mUnk_10b0 = 0;
    }
    gEmblem->mEmblemTemplateSLld->mUnk_14 = gEmblem->mUnk_10a0 - 0xc0;
}

void func_ov001_021a4914(void) {
    gEmblem->mUnk_1090 = 3;
    gEmblem->mUnk_1098 = 6;
    gEmblem->mUnk_10a0 = 0xc0;
    gEmblem->mUnk_10a4 = -0x20;
    func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 1), -1);
    func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 2), -1);
    func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 3), -1);
}

void func_ov001_021a48a4(void) {
    gEmblem->mUnk_10a0 += gEmblem->mUnk_10a4;
    gEmblem->mUnk_10a4 += 2;
    if (gEmblem->mUnk_10a0 <= 0) {
        gEmblem->mUnk_10a0 = 0;
        gEmblem->mUnk_1090 = 0;
        gEmblem->mUnk_1098 = 7;
        gEmblem->mUnk_10b0 = 0;
    }
    gEmblem->mEmblemTemplateSLld->mUnk_14 = gEmblem->mUnk_10a0 - 0xc0;
}

void func_ov001_021a4878(void) {
    gEmblem->mUnk_1090 = 5;
    gEmblem->mUnk_1098 = 13;
    gEmblem->mUnk_109c = 0;
}

void func_ov001_021a4844(void) {
    gEmblem->mUnk_1090 = 7;
    gEmblem->mUnk_1098 = 10;
    gEmblem->mUnk_109c = 0;
    func_02110aac(2, 0);
}

void func_ov001_021a4804(void) {
    gEmblem->mUnk_109c += 2;
    if (gEmblem->mUnk_109c > 16) {
        gEmblem->mUnk_109c = 16;
        gEmblem->mUnk_1090 = 6;
        gEmblem->mUnk_1098 = 9;
    }
}

void func_ov001_021a47b4(void) {
    gEmblem->mUnk_109c -= 2;
    if (gEmblem->mUnk_109c < 0) {
        gEmblem->mUnk_109c = 0;
        gEmblem->mUnk_1090 = 4;
        gEmblem->mUnk_1098 = 11;
        gEmblem->mUnk_10b0 = 0;
    }
}

void func_ov001_021a4774(void) {
    gEmblem->mUnk_109c += 2;
    if (gEmblem->mUnk_109c > 16) {
        gEmblem->mUnk_109c = 16;
        gEmblem->mUnk_1090 = 8;
        gEmblem->mUnk_1098 = 12;
    }
}

void func_ov001_021a4724(void) {
    gEmblem->mUnk_109c -= 2;
    if (gEmblem->mUnk_109c < 0) {
        gEmblem->mUnk_109c = 0;
        gEmblem->mUnk_1090 = 0;
        gEmblem->mUnk_1098 = 8;
        gEmblem->mUnk_10b0 = 0;
    }
}
