#include "01/code_021a4724.h"
#include "01/code_02184f7c.h"
#include "01/code_021a5140.h"
#include "01/code_02185000.h"
#include "01/code_02180ce8.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_020ca670.h"
#include "Main/Unknown/code_020ca6a8.h"
#include "Main/Unknown/code_021108bc.h"
#include "Main/Unknown/code_02148000.h"
#include "code_0200eddc.h"
#include "gx.h"
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
    DC_FlushRange(gEmblem->mEmblemMONclr->mData, gEmblem->mEmblemMONclr->mDataSize);
    GX_LoadOBJPltt(gEmblem->mEmblemMONclr->mData, 0, gEmblem->mEmblemMONclr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemMONcgr->mData, gEmblem->mEmblemMONcgr->mDataSize);
    GX_LoadOBJ(gEmblem->mEmblemMONcgr->mData, 0, gEmblem->mEmblemMONcgr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemMBNclr->mData, gEmblem->mEmblemMBNclr->mDataSize);
    GX_LoadBGPltt(gEmblem->mEmblemMBNclr->mData, 0, gEmblem->mEmblemMBNclr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemMBNcgr->mData, gEmblem->mEmblemMBNcgr->mDataSize);
    GX_LoadBG1Char((gEmblem->mEmblemMBNcgr->mData), 0, gEmblem->mEmblemMBNcgr->mDataSize);
    DC_FlushRange(gEmblem->mUnk_0a7c, 0x200);
    GX_LoadBG2Char(gEmblem->mUnk_0a7c, 0, 0x200);
    DC_FlushRange(gEmblem->mEmblemMNscr->mData, gEmblem->mEmblemMNscr->mDataSize);
    GX_LoadBG1Scr(gEmblem->mEmblemMNscr->mData, 0, gEmblem->mEmblemMNscr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemMBgNscr->mData, gEmblem->mEmblemMBgNscr->mDataSize);
    GX_LoadBG2Scr(gEmblem->mEmblemMBgNscr->mData, 0, gEmblem->mEmblemMBgNscr->mDataSize);
    reg_G2_BG1OFS = 0;
    reg_G2_BG2OFS = 0;
}

void func_ov001_021a4d10(void) {
    GXS_SetGraphicsMode(1);
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
    G2x_SetBGyAffine_(&reg_G2S_DB_BG3PA, data_ov001_021a6fd8, 16, 16, -0x70, -0x40);
    DC_FlushRange(gEmblem->mEmblemSONclr->mData, gEmblem->mEmblemSONclr->mDataSize);
    GXS_LoadOBJPltt(gEmblem->mEmblemSONclr->mData, 0, gEmblem->mEmblemSONclr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemSONcgr->mData, gEmblem->mEmblemSONcgr->mDataSize);
    GXS_LoadOBJ(gEmblem->mEmblemSONcgr->mData, 0, gEmblem->mEmblemSONcgr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemSBNclr->mData, gEmblem->mEmblemSBNclr->mDataSize);
    GXS_LoadBGPltt(gEmblem->mEmblemSBNclr->mData, 0, gEmblem->mEmblemSBNclr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemSBNcgr->mData, gEmblem->mEmblemSBNcgr->mDataSize);
    GXS_LoadBG1Char((gEmblem->mEmblemSBNcgr->mData), 0, gEmblem->mEmblemSBNcgr->mDataSize);
    DC_FlushRange(GetEmblemGridCells(), GetEmblemGridCharSize());
    GXS_LoadBG3Char(GetEmblemGridCells(), func_ov001_02181194(), GetEmblemGridCharSize());
    DC_FlushRange(gEmblem->mEmblemSTemplateFrameNscr->mData, gEmblem->mEmblemSTemplateFrameNscr->mDataSize);
    GXS_LoadBG0Scr(gEmblem->mEmblemSTemplateFrameNscr->mData, 0, gEmblem->mEmblemSTemplateFrameNscr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemSToolNscr->mData, gEmblem->mEmblemSToolNscr->mDataSize);
    GXS_LoadBG1Scr(gEmblem->mEmblemSToolNscr->mData, 0, gEmblem->mEmblemSToolNscr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemSBgNscr->mData, gEmblem->mEmblemSBgNscr->mDataSize);
    GXS_LoadBG2Scr(gEmblem->mEmblemSBgNscr->mData, 0, gEmblem->mEmblemSBgNscr->mDataSize);
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x1010;
    DC_FlushRange(gEmblem->mEmblemSTemplateDarkNscr->mData, gEmblem->mEmblemSTemplateDarkNscr->mDataSize);
    GXS_LoadBG3Scr(gEmblem->mEmblemSTemplateDarkNscr->mData, 0, gEmblem->mEmblemSTemplateDarkNscr->mDataSize);
    reg_G2S_DB_BG3CNT = (reg_G2S_DB_BG3CNT & 0x43) | 0x1218;
    DC_FlushRange((const void *) GetEmblemGridScr(), GetEmblemGridScrSize());
    GXS_LoadBG3Scr((const void *) (GetEmblemGridScr()), func_ov001_021811b8(), GetEmblemGridScrSize());
}

void func_ov001_021a4ba0(void) {
    GXS_SetGraphicsMode(1);
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | 0x1600;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & ~3) | 3;
    reg_G2S_DB_BG1CNT = (reg_G2S_DB_BG1CNT & 0x43) | 0xe10;
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & ~3) | 3;
    reg_G2S_DB_BG2CNT = (reg_G2S_DB_BG2CNT & 0x43) | 0x1010;
    reg_G2S_DB_BG1OFS = 0;
    reg_G2S_DB_BG2OFS = 0;
    reg_G2S_DB_BG3OFS = 0;
    DC_FlushRange(gEmblem->mEmblemSONclr->mData, gEmblem->mEmblemSONclr->mDataSize);
    GXS_LoadOBJPltt(gEmblem->mEmblemSONclr->mData, 0, gEmblem->mEmblemSONclr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemCameraSONcgr->mData, gEmblem->mEmblemCameraSONcgr->mDataSize);
    GXS_LoadOBJ(gEmblem->mEmblemCameraSONcgr->mData, 0, gEmblem->mEmblemCameraSONcgr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemSBNclr->mData, gEmblem->mEmblemSBNclr->mDataSize);
    GXS_LoadBGPltt(gEmblem->mEmblemSBNclr->mData, 0, gEmblem->mEmblemSBNclr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemCameraSBNcgr->mData, gEmblem->mEmblemCameraSBNcgr->mDataSize);
    GXS_LoadBG1Char((gEmblem->mEmblemCameraSBNcgr->mData), 0, gEmblem->mEmblemCameraSBNcgr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemCameraSDSNscr->mData, gEmblem->mEmblemCameraSDSNscr->mDataSize);
    GXS_LoadBG1Scr(gEmblem->mEmblemCameraSDSNscr->mData, 0, gEmblem->mEmblemCameraSDSNscr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemCameraSBgNscr->mData, gEmblem->mEmblemCameraSBgNscr->mDataSize);
    GXS_LoadBG2Scr(gEmblem->mEmblemCameraSBgNscr->mData, 0, gEmblem->mEmblemCameraSBgNscr->mDataSize);
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
    gEmblem->mUnk_10b0 = FALSE;
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
        gEmblem->mUnk_10b0 = FALSE;
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
        gEmblem->mUnk_10b0 = FALSE;
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
        gEmblem->mUnk_10b0 = FALSE;
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
        gEmblem->mUnk_10b0 = FALSE;
    }
}
