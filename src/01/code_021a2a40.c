#include "01/code_021a2a40.h"

#include "01/code_02184f7c.h"
#include "Main/Unknown/code_02056700.h"
#include "Main/Unknown/code_020ca670.h"
#include "Main/Unknown/code_020ca820.h"
#include "01/code_021a5140.h"
#include "01/code_021928c8.h"
#include "01/code_02185000.h"
#include "01/code_02184000.h"
#include "01/code_021a6000.h"
#include "01/code_02180ce8.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ac2c4.h"
#include "Main/Unknown/code_020ca000.h"
#include "Main/Unknown/code_020ca69c.h"
#include "Main/Unknown/code_020ca844.h"
#include "Main/Unknown/code_02105000.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a7000.h"
#include "Main/Unknown/code_02056000.h"
#include "Main/Unknown/code_02078000.h"
#include "Main/Unknown/code_020ac000.h"
#include "code_0212df7c.h"
#include "01/code_02192000.h"
#include "01/code_021a4000.h"
#include "01/code_021a5000.h"
#include "Main/Unknown/code_02076cd0.h"
#include "Main/Unknown/code_02077000.h"
#include "Main/Unknown/code_02110000.h"
#include "Main/Unknown/code_0214a000.h"
#include "code_0214b824.h"
#include "Main/Unknown/code_020aa81c.h"
#include "01/code_02181000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_020ca6a8.h"
#include "Main/Unknown/code_021108bc.h"
#include "Main/Unknown/code_02148000.h"
#include "code_0200eddc.h"
#include "code_021488e8.h"
#include "code_0214a390.h"
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
    func_0214a428((u32 *) 0x04001030, data_ov001_021a6fd8, 16, 16, -0x70, -0x40);
    DC_FlushRange(gEmblem->mEmblemSONclr->mData, gEmblem->mEmblemSONclr->mDataSize);
    GXS_LoadOBJPltt(gEmblem->mEmblemSONclr->mData, 0, gEmblem->mEmblemSONclr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemSONcgr->mData, gEmblem->mEmblemSONcgr->mDataSize);
    GXS_LoadOBJ(gEmblem->mEmblemSONcgr->mData, 0, gEmblem->mEmblemSONcgr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemSBNclr->mData, gEmblem->mEmblemSBNclr->mDataSize);
    GXS_LoadBGPltt(gEmblem->mEmblemSBNclr->mData, 0, gEmblem->mEmblemSBNclr->mDataSize);
    DC_FlushRange(gEmblem->mEmblemSBNcgr->mData, gEmblem->mEmblemSBNcgr->mDataSize);
    GXS_LoadBG1Char((gEmblem->mEmblemSBNcgr->mData), 0, gEmblem->mEmblemSBNcgr->mDataSize);
    DC_FlushRange((const void *) func_ov001_02181174(), func_ov001_02181180());
    GXS_LoadBG3Char((const void *) (func_ov001_02181174()), func_ov001_02181194(), func_ov001_02181180());
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
    DC_FlushRange((const void *) func_ov001_021811bc(), func_ov001_02181198());
    GXS_LoadBG3Scr((const void *) (func_ov001_021811bc()), func_ov001_021811b8(), func_ov001_02181198());
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

void func_ov001_021a41c8(s32 a, s32 b) {
    s32 n;
    u8 *p;
    u16 buf[16];

    switch (gEmblem->mUnk_1090) {
        case 0:
            switch (a) {
                case 0x1b:
                case 0x1c:
                case 0x1d:
                case 0x1e:
                case 0x1f:
                case 0x20:
                case 0x21:
                case 0x22:
                case 0x23:
                case 0x24:
                case 0x25:
                case 0x26:
                case 0x27:
                case 0x28:
                case 0x29:
                    if (b) {
                        func_ov001_02184fb4(func_ov001_02185160(gEmblem->mEmblemSLld, 9), 0);
                        func_ov001_02184fb4(func_ov001_02185160(gEmblem->mEmblemSLld, 10), 0x1000);
                        gEmblem->mUnk_1080 = a - 0x1b;
                        func_ov001_021a63c0((u8) (gEmblem->mUnk_1080 + 1));
                        func_0212ecc0(&data_0217d068, 0, 0x1f1);
                    } else {
                        gEmblem->mUnk_1080 = a - 0x1b;
                        func_ov001_021a5df0((gEmblem->mEmblemSLld), (s32) (a));
                        func_ov001_021a63c0((u8) (gEmblem->mUnk_1080 + 1));
                        func_0212ecc0(&data_0217d068, 0, 0x1f0);
                    }
                    if (func_ov001_021a639c() == 1) {
                        func_ov001_021a5ab0(gEmblem->mEmblemSLld, (s32) (func_ov001_021a637c() + 0xe));
                        func_ov001_021a63a8(0);
                    }
                    gEmblem->mUnk_1094 = 3;
                    return;
                case 0x2a:
                    if (b) {
                        func_ov001_02184fb4(func_ov001_02185160(gEmblem->mEmblemSLld, 10), 0x1000);
                    }
                    func_ov001_021a59cc((gEmblem->mEmblemSLld), (s32) (a));
                    if (b) {
                        gEmblem->mUnk_1094 = 3;
                        return;
                    }
                    break;
                case 0xe:
                case 0xf:
                case 0x10:
                    func_ov001_021a5ab0((gEmblem->mEmblemSLld), (s32) (a));
                    func_ov001_021a63a8(0);
                    func_ov001_021a6388((s32) (a - 0xe));
                    func_0212ecc0(&data_0217d068, 0, 0x1f2);
                    gEmblem->mUnk_1094 = 3;
                    return;
                case 0x11:
                case 0x12:
                case 0x13:
                    func_ov001_021a5ab0((gEmblem->mEmblemSLld), (s32) (a));
                    func_ov001_021a63a8(1);
                    func_ov001_021a6388((s32) (a - 0x11));
                    func_0212ecc0(&data_0217d068, 0, 0x1f2);
                    gEmblem->mUnk_1094 = 3;
                    return;
                case 0x14:
                    func_ov001_021a5ab0((gEmblem->mEmblemSLld), (s32) (a));
                    func_ov001_021a63a8(2);
                    func_ov001_021a6388(0);
                    func_0212ecc0(&data_0217d068, 0, 0x1f2);
                    gEmblem->mUnk_1094 = 3;
                    return;
                case 0x15:
                    func_ov001_021a5ab0((gEmblem->mEmblemSLld), (s32) (a));
                    func_ov001_021a63a8(3);
                    func_ov001_021a6388(0);
                    func_0212ecc0(&data_0217d068, 0, 0x1f2);
                    gEmblem->mUnk_1094 = 3;
                    return;
                case 0x16:
                    if (gEmblem->mUnk_108c == NULL) {
                        gEmblem->mUnk_108c = func_ov001_021a4a10;
                        func_ov001_021a5d00((gEmblem->mEmblemSLld), (s32) (a));
                        func_0212ecc0(&data_0217d068, 0, 0x1f3);
                        gEmblem->mUnk_10b0 = TRUE;
                    }
                    gEmblem->mUnk_1094 = 3;
                    return;
                case 0x17:
                    if (func_ov001_02181070()) {
                        if (func_ov001_0218108c()) {
                            func_0212ecc0(&data_0217d068, 0, 0x1fb);
                        } else {
                            func_0212ecc0(&data_0217d068, 0, 0x1fc);
                        }
                        func_ov001_02181098();
                        func_ov001_021a5d00((gEmblem->mEmblemSLld), (s32) (a));
                    }
                    if (b) {
                        gEmblem->mUnk_1094 = 3;
                        return;
                    }
                    break;
                case 0x19:
                    if (gEmblem->mUnk_108c == NULL) {
                        gEmblem->mUnk_108c = func_ov001_021a4878;
                        func_ov001_021a5d00((gEmblem->mEmblemSLld), (s32) (a));
                        func_0212ecc0(&data_0217d068, 0, 0xc);
                        gEmblem->mUnk_10b0 = TRUE;
                        gEmblem->mUnk_10ac = FALSE;
                    }
                    gEmblem->mUnk_1094 = 3;
                    return;
                case 0x1a:
                    if (gEmblem->mUnk_108c == NULL) {
                        gEmblem->mUnk_108c = func_ov001_021a4b28;
                        func_ov001_021a5c28((gEmblem->mEmblemSLld), (s32) (a));
                        func_0212ecc0(&data_0217d068, 0, 4);
                        gEmblem->mUnk_10b0 = TRUE;
                    }
                    gEmblem->mUnk_1094 = 3;
                    return;
            }
            break;
        case 1:
            switch (a) {
                case 0:
                    if (gEmblem->mUnk_108c == NULL) {
                        gEmblem->mUnk_108c = func_ov001_021a4914;
                        func_ov001_021a5a40((gEmblem->mEmblemTemplateSLld), 1);
                        func_0212ecc0(&data_0217d068, 0, 0xe);
                        gEmblem->mUnk_10b0 = TRUE;
                    }
                    gEmblem->mUnk_1094 = 3;
                    return;
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 0xa:
                case 0xb:
                case 0xc:
                case 0xd:
                case 0xe:
                case 0xf:
                case 0x10:
                case 0x11:
                case 0x12:
                case 0x13:
                case 0x14:
                case 0x15:
                case 0x16:
                case 0x17:
                case 0x18:
                case 0x19:
                case 0x1a:
                case 0x1b:
                case 0x1c:
                case 0x1d:
                case 0x1e:
                case 0x1f:
                    if (gEmblem->mUnk_108c == NULL) {
                        n = (s32) (func_ov001_02181268() * func_ov001_02181268()) / 2;
                        p = (u8 *) gEmblem->mEmblemTemplateBNcgr->mData + (a - 3) * n;
                        buf[0] = 0;
                        buf[1] = (func_ov001_021a63b4() == 1) ? 2 : 1;
                        buf[2] = func_ov001_021a63b4();
                        func_020ac284(p, gEmblem->mUnk_0c7c, func_ov001_02181268());
                        func_ov001_021810bc((gEmblem->mUnk_0c7c), (buf));
                        func_ov001_0218107c();
                        gEmblem->mUnk_108c = func_ov001_021a4914;
                        func_ov001_021a5d00((gEmblem->mEmblemTemplateSLld), (s32) (a));
                        gEmblem->mUnk_1084 = a - 3;
                        func_0212ecc0(&data_0217d068, 0, 0x1f6);
                    }
                    gEmblem->mUnk_1094 = 3;
                    return;
            }
            break;
        case 4:
            if (a == 1) {
                if (gEmblem->mUnk_108c == NULL) {
                    gEmblem->mUnk_108c = func_ov001_021a4844;
                    func_ov001_021a5d00((gEmblem->mEmblemCameraSLld), (s32) (a));
                    func_0212ecc0(&data_0217d068, 0, 0xc);
                    gEmblem->mUnk_10ac = TRUE;
                }
                gEmblem->mUnk_1094 = 3;
            }
            break;
    }
}

void func_ov001_021a401c(void) {
    int a;
    int b;

    a = func_02077a5c();
    b = func_02077a4c();
    func_02078158();
    if (b >= 10) {
        func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemMLld, 4), 0);
        func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemMLld, 5), -5);
        func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemMLld, 6), b / 10);
        func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemMLld, 7), b % 10);
        if (a >= 10) {
            func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemMLld, 1), a / 10);
            func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemMLld, 2), a % 10);
        } else {
            func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemMLld, 1), -5);
            func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemMLld, 2), a);
        }
        func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemMLld, 3), -5);
    } else {
        func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemMLld, 4), -5);
        func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemMLld, 5), 0);
        func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemMLld, 6), -5);
        func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemMLld, 7), b);
        func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemMLld, 1), -5);
        func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemMLld, 2), -5);
        func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemMLld, 3), a);
    }
}

void func_ov001_021a30e0(void) {
    s32 i;
    s32 x;
    s32 y;
    s32 dx;
    s32 dy;
    s32 dz;
    s32 prev;
    BOOL flag;
    void *entry8;
    void *entry9;
    void *entry;

    flag = FALSE;
    if (func_ov001_02192a54()) {
        y = func_ov001_02192a60();
        x = func_ov001_02192a6c();
        i = func_ov001_021850b4(gEmblem->mEmblemSLld, 0, x, y);
        while (i >= 0) {
            func_ov001_021a41c8(i, 1);
            y = func_ov001_02192a60();
            x = func_ov001_02192a6c();
            i = func_ov001_021850b4(gEmblem->mEmblemSLld, i + 1, x, y);
        }
    }

    if (func_ov001_02192a14(8)) {
        func_ov001_021a41c8(0x1a, 0);
    } else if (func_ov001_02192a14(4)) {
        func_ov001_021a41c8(0x19, 0);
    } else if (func_ov001_02192a14(2)) {
        func_ov001_021a41c8(0x17, 0);
    } else if (func_ov001_02192a14(0x800)) {
        func_ov001_021a41c8(0x2a, 0);
    } else {
        entry8 = func_ov001_02185160(gEmblem->mEmblemSLld, 8);
        func_ov001_02185160(gEmblem->mEmblemSLld, data_ov001_021a6fe8[gEmblem->mUnk_107c]);
        entry9 = func_ov001_02185160(gEmblem->mEmblemSLld, 9);
        func_ov001_02185160(gEmblem->mEmblemSLld, data_ov001_021a7058[gEmblem->mUnk_1080]);
        dx = 0;
        dy = 0;
        dz = 0;
        dx += func_020ae408(8, 0x20) ? -1 : 0;
        dx += func_020ae408(8, 0x10) ? 1 : 0;
        dy += func_020ae408(8, 0x40) ? -1 : 0;
        dy += func_020ae408(8, 0x80) ? 1 : 0;
        dz += func_020ae408(8, 0x200) ? -1 : 0;
        dz += func_020ae408(8, 0x100) ? 1 : 0;

        switch (gEmblem->mUnk_1094) {
            case 0:
                func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 0xb), -5);
                func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 0xc), 0);
                func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 0xd), -5);
                if (dz > 0) {
                    gEmblem->mUnk_1094 = 2;
                    gEmblem->mUnk_1080 = func_ov001_021a63b4() - 1;
                    func_ov001_02184fb4(func_ov001_02185160(gEmblem->mEmblemSLld, 9), 0x1000);
                    func_ov001_02184fb4(func_ov001_02185160(gEmblem->mEmblemSLld, 10), 0);
                    func_ov001_021850a4(func_ov001_02185160(gEmblem->mEmblemSLld, 9), NULL);
                    func_ov001_021850a4(func_ov001_02185160(gEmblem->mEmblemSLld, 10), NULL);
                    func_0212ecc0(&data_0217d068, 0, 0x1ee);
                } else if (dz < 0) {
                    gEmblem->mUnk_1094 = 1;
                    switch (func_ov001_021a639c()) {
                        case 0:
                            gEmblem->mUnk_107c = func_ov001_021a637c() + data_ov001_021a6fc8[func_ov001_021a639c()];
                            break;
                        case 1:
                            gEmblem->mUnk_107c = func_ov001_021a637c() + data_ov001_021a6fc8[func_ov001_021a639c()];
                            break;
                        case 2:
                            gEmblem->mUnk_107c = data_ov001_021a6fc8[func_ov001_021a639c()];
                            break;
                        case 3:
                            gEmblem->mUnk_107c = data_ov001_021a6fc8[func_ov001_021a639c()];
                            break;
                    }
                    func_ov001_02184fb4(func_ov001_02185160(gEmblem->mEmblemSLld, 8), 0x1000);
                    func_ov001_021850a4(func_ov001_02185160(gEmblem->mEmblemSLld, 8), NULL);
                    func_0212ecc0(&data_0217d068, 0, 0x1ee);
                }
                break;
            case 1:
                func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 0xb), 0);
                func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 0xc), -5);
                func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 0xd), -5);
                if (dz < 0) {
                    gEmblem->mUnk_1094 = 2;
                    gEmblem->mUnk_1080 = func_ov001_021a63b4() - 1;
                    func_ov001_02184fb4(func_ov001_02185160(gEmblem->mEmblemSLld, 9), 0x1000);
                    func_ov001_02184fb4(func_ov001_02185160(gEmblem->mEmblemSLld, 10), 0);
                    func_ov001_021850a4(func_ov001_02185160(gEmblem->mEmblemSLld, 9), NULL);
                    func_ov001_021850a4(func_ov001_02185160(gEmblem->mEmblemSLld, 10), NULL);
                    func_ov001_02185018(entry8, -5);
                    func_0212ecc0(&data_0217d068, 0, 0x1ee);
                } else if (dz > 0) {
                    gEmblem->mUnk_1094 = 3;
                    func_ov001_02185018(entry8, -5);
                    func_0212ecc0(&data_0217d068, 0, 0x1ee);
                } else if (func_ov001_02192a14(1)) {
                    if (data_ov001_021a6fe8[gEmblem->mUnk_107c] != 0x17 || func_ov001_02181070()) {
                        func_ov001_021a41c8(data_ov001_021a6fe8[gEmblem->mUnk_107c], 0);
                    }
                } else {
                    prev = gEmblem->mUnk_107c;
                    gEmblem->mUnk_107c = data_ov001_021a710c[dy + 1][prev];
                    gEmblem->mUnk_107c = data_ov001_021a719c[dx + 1][gEmblem->mUnk_107c];
                    entry = func_ov001_02185160(gEmblem->mEmblemSLld, data_ov001_021a6fe8[gEmblem->mUnk_107c]);
                    func_ov001_02185018(entry8, 0);
                    func_ov001_02184fd8(entry8, func_ov001_02184fc8(entry), func_ov001_02184fb8(entry));
                    if (gEmblem->mUnk_107c != prev) {
                        func_02105ac0(0x1ef);
                    }
                }
                func_ov001_021a5f70(0, (s32) (func_ov001_02192a6c()), (s32) (func_ov001_02192a60()), 0, 0, 0);
                break;
            case 2:
                func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 0xb), -5);
                func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 0xc), -5);
                func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 0xd), 0);
                if (dz > 0) {
                    gEmblem->mUnk_1094 = 1;
                    switch (func_ov001_021a639c()) {
                        case 0:
                            gEmblem->mUnk_107c = func_ov001_021a637c() + data_ov001_021a6fb8[func_ov001_021a639c()];
                            break;
                        case 1:
                            gEmblem->mUnk_107c = func_ov001_021a637c() + data_ov001_021a6fb8[func_ov001_021a639c()];
                            break;
                        case 2:
                            gEmblem->mUnk_107c = data_ov001_021a6fb8[func_ov001_021a639c()];
                            break;
                        case 3:
                            gEmblem->mUnk_107c = data_ov001_021a6fb8[func_ov001_021a639c()];
                            break;
                    }
                    func_ov001_02184fb4(func_ov001_02185160(gEmblem->mEmblemSLld, 8), 0x1000);
                    func_ov001_021850a4(func_ov001_02185160(gEmblem->mEmblemSLld, 8), NULL);
                    func_ov001_02184fb4(entry9, 0);
                    func_ov001_02184fb4(func_ov001_02185160(gEmblem->mEmblemSLld, 10), 0x1000);
                    gEmblem->mUnk_1080 = func_ov001_021a63b4() - 1;
                    func_ov001_02185018(entry9, -5);
                    func_0212ecc0(&data_0217d068, 0, 0x1ee);
                } else if (dz < 0) {
                    gEmblem->mUnk_1094 = 3;
                    func_ov001_02184fb4(entry9, 0);
                    func_ov001_02184fb4(func_ov001_02185160(gEmblem->mEmblemSLld, 10), 0x1000);
                    gEmblem->mUnk_1080 = func_ov001_021a63b4() - 1;
                    func_ov001_02185018(entry9, -5);
                    func_0212ecc0(&data_0217d068, 0, 0x1ee);
                } else if (func_ov001_02192a14(1)) {
                    func_ov001_021a41c8(data_ov001_021a7058[gEmblem->mUnk_1080], 0);
                } else {
                    prev = gEmblem->mUnk_1080;
                    gEmblem->mUnk_1080 = data_ov001_021a722c[dy + 1][prev];
                    gEmblem->mUnk_1080 = data_ov001_021a72ec[dx + 1][gEmblem->mUnk_1080];
                    func_ov001_02185160(gEmblem->mEmblemSLld, data_ov001_021a7058[gEmblem->mUnk_1080]);
                    if (gEmblem->mUnk_1080 < 0xf) {
                        func_ov001_02185018(entry9, 0);
                    } else {
                        func_ov001_02185018(entry9, -5);
                    }
                    if (gEmblem->mUnk_1080 != prev) {
                        func_02105ac0(0x1ef);
                    }
                }
                func_ov001_021a5f70(0, (s32) (func_ov001_02192a6c()), (s32) (func_ov001_02192a60()), 0, 0, 0);
                break;
        }
    }

    if (func_ov001_02192a54() && func_ov001_021a62c4((s32) (func_ov001_02192a6c()), (s32) (func_ov001_02192a60()))) {
        func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 0xb), -5);
        func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 0xc), 0);
        func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 0xd), -5);
        gEmblem->mUnk_1080 = func_ov001_021a63b4() - 1;
        if (func_ov001_02184fb0(func_ov001_02185160(gEmblem->mEmblemSLld, 9)) == 0x1000) {
            func_ov001_02184fb4(func_ov001_02185160(gEmblem->mEmblemSLld, 9), 0);
            func_ov001_02184fb4(func_ov001_02185160(gEmblem->mEmblemSLld, 10), 0x1000);
        }
        if (func_ov001_02184fb0(func_ov001_02185160(gEmblem->mEmblemSLld, 8)) == 0x1000) {
            func_ov001_02184fb4(func_ov001_02185160(gEmblem->mEmblemSLld, 8), 0);
        }
        gEmblem->mUnk_1094 = 0;
    } else if (gEmblem->mUnk_1094 == 3) {
        func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 0xb), -5);
        func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 0xc), 0);
        func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 0xd), -5);
        gEmblem->mUnk_1080 = func_ov001_021a63b4() - 1;
        if (func_ov001_02184fb0(func_ov001_02185160(gEmblem->mEmblemSLld, 9)) == 0x1000) {
            func_ov001_02184fb4(func_ov001_02185160(gEmblem->mEmblemSLld, 9), 0);
            func_ov001_02184fb4(func_ov001_02185160(gEmblem->mEmblemSLld, 10), 0x1000);
        }
        if (func_ov001_02184fb0(func_ov001_02185160(gEmblem->mEmblemSLld, 8)) == 0x1000) {
            func_ov001_02184fb4(func_ov001_02185160(gEmblem->mEmblemSLld, 8), 0);
        }
        if (!func_ov001_02192a48() && !func_ov001_02192a04(1) && !func_ov001_02192a04(2)) {
            gEmblem->mUnk_1094 = 0;
        }
    }

    if (gEmblem->mUnk_1094 == 0) {
        dx = 0;
        dy = 0;
        dx += func_ov001_021928c8(0x20) ? -1 : 0;
        dx += func_ov001_021928c8(0x10) ? 1 : 0;
        dy += func_ov001_021928c8(0x40) ? -1 : 0;
        dy += func_ov001_021928c8(0x80) ? 1 : 0;
        if (func_ov001_021a5f70((s32) (func_ov001_02192a48()), (s32) (func_ov001_02192a6c()),
                                (s32) (func_ov001_02192a60()), (s32) (func_ov001_02192a04(1)), (s32) (dx),
                                (s32) (dy))) {
            if (func_ov001_021a639c() == 3) {
                gEmblem->mUnk_1080 = func_ov001_021a63b4() - 1;
                func_0212ecc0(&data_0217d068, 0, 0x1f4);
            } else if (func_ov001_021a639c() == 2) {
                func_0212ecc0(&data_0217d068, 0, 0x1f5);
            }
        } else if (func_ov001_02192a04(0x400)) {
            flag = TRUE;
            if (func_ov001_021a6278()) {
                gEmblem->mUnk_1080 = func_ov001_021a63b4() - 1;
                func_0212ecc0(&data_0217d068, 0, 0x1f4);
            }
        }
        if (func_ov001_02192a48() && !func_ov001_02192a24() &&
            func_ov001_021a62c4((s32) (func_ov001_02192a6c()), (s32) (func_ov001_02192a60()))) {
            gEmblem->mUnk_10b8 = TRUE;
        } else if (func_ov001_02192a48() &&
                   (func_ov001_021a62c4((s32) (func_ov001_02192a6c()), (s32) (func_ov001_02192a60())) ||
                    func_ov001_021a62c4((s32) (func_ov001_02192a3c()), (s32) (func_ov001_02192a30()))) &&
                   (func_ov001_021a633c() != func_ov001_021a6314() || func_ov001_021a6328() != func_ov001_021a6300())) {
            gEmblem->mUnk_10b8 = TRUE;
        } else if (func_ov001_02192a14(1)) {
            gEmblem->mUnk_10b8 = TRUE;
        } else if (func_ov001_02192a04(1) &&
                   (func_ov001_021a633c() != func_ov001_021a6314() || func_ov001_021a6328() != func_ov001_021a6300())) {
            gEmblem->mUnk_10b8 = TRUE;
        }
    } else {
        func_ov001_021a5f70(0, (s32) (func_ov001_02192a6c()), (s32) (func_ov001_02192a60()), 0, 0, 0);
    }

    func_ov001_02184fd8(func_ov001_02185160(gEmblem->mEmblemSLld, 0), func_ov001_021a633c(), func_ov001_021a6328());
    func_ov001_02184fd8(func_ov001_02185160(gEmblem->mEmblemSLld, 1), func_ov001_021a633c(), func_ov001_021a6328());
    func_ov001_02184fd8(func_ov001_02185160(gEmblem->mEmblemSLld, 2), func_ov001_021a633c(), func_ov001_021a6328());
    func_ov001_02184fd8(func_ov001_02185160(gEmblem->mEmblemSLld, 3), func_ov001_021a633c(), func_ov001_021a6328());

    if (gEmblem->mUnk_1094 == 0 && func_ov001_02192a48() &&
        func_ov001_021a62c4((s32) (func_ov001_02192a6c()), (s32) (func_ov001_02192a60()))) {
        func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 0), -5);
        gEmblem->mUnk_1088 = -1;
    } else if (gEmblem->mUnk_1094 == 0 && func_ov001_02192a48() &&
               func_ov001_02184ff8(func_ov001_02185160(gEmblem->mEmblemSLld, 0)) == -5) {
        func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 0), -5);
        gEmblem->mUnk_1088 = -1;
    } else {
        gEmblem->mUnk_1088 = func_ov001_021a637c();
        if (flag) {
            func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 0), 3);
        } else {
            switch (func_ov001_021a639c()) {
                case 0:
                    func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 0), 0);
                    break;
                case 2:
                    func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 0), 1);
                    break;
                case 1:
                    func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 0), 2);
                    break;
                case 3:
                    func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 0), 3);
                    break;
            }
        }
    }

    switch (gEmblem->mUnk_1088) {
        case 0:
            func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 1), -4);
            func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 2), -5);
            func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 3), -5);
            break;
        case 1:
            func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 1), -5);
            func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 2), -4);
            func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 3), -5);
            break;
        case 2:
            func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 1), -5);
            func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 2), -5);
            func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 3), -4);
            break;
    }

    entry = func_ov001_02185160(gEmblem->mEmblemSLld, data_ov001_021a7058[gEmblem->mUnk_1080]);
    func_ov001_02184fd8(func_ov001_02185160(gEmblem->mEmblemSLld, 9), func_ov001_02184fc8(entry),
                        func_ov001_02184fb8(entry));
    func_ov001_02184fd8(func_ov001_02185160(gEmblem->mEmblemSLld, 10), func_ov001_02184fc8(entry),
                        func_ov001_02184fb8(entry));

    if (gEmblem->mUnk_1080 < 0xf) {
        func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 4), -5);
        func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 5), -5);
        func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 6), -5);
        func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 7), -5);
    } else {
        func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 4), 0);
        func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 5), 0);
        func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 6), 0);
        func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 7), 0);
    }

    if (func_ov001_02181070() && func_ov001_02184ff8(func_ov001_02185160(gEmblem->mEmblemSLld, 0x17)) == 2) {
        func_ov001_02185018(func_ov001_02185160(gEmblem->mEmblemSLld, 0x17), 0);
    }
}

void func_ov001_021a2e0c(void) {
    void *entry_a;
    void *entry_b;
    s32 i;
    s32 h;
    s32 v;
    s32 w;
    s32 sel;
    s32 u;
    s32 t;
    u32 y;
    s32 x;
    void *entry_c;
    void *entry_d;

    if (func_ov001_02192a54() != 0) {
        y = func_ov001_02192a60();
        x = func_ov001_02192a6c();
        i = func_ov001_021850b4(gEmblem->mEmblemTemplateSLld, 0, x, y);
        while (i >= 0) {
            func_ov001_021a41c8(i, 1);
            y = func_ov001_02192a60();
            x = func_ov001_02192a6c();
            i = func_ov001_021850b4(gEmblem->mEmblemTemplateSLld, i + 1, x, y);
        }
    }
    if (func_ov001_02192a14(1) != 0) {
        func_ov001_021a41c8(data_ov001_021a7098[gEmblem->mUnk_1084], 0);
        return;
    }
    if (func_ov001_02192a14(2) != 0) {
        func_ov001_021a41c8(0, 0);
        return;
    }
    h = 0;
    v = 0;
    w = 0;
    h += (func_020ae408(8, 0x20) != 0) ? -1 : 0;
    h += (func_020ae408(8, 0x10) != 0) ? 1 : 0;
    v += (func_020ae408(8, 0x40) != 0) ? -1 : 0;
    v += (func_020ae408(8, 0x80) != 0) ? 1 : 0;
    w += (func_020ae408(8, 0x200) != 0) ? -1 : 0;
    w += (func_020ae408(8, 0x100) != 0) ? 1 : 0;
    gEmblem->mUnk_1080 = w + (func_ov001_021a63b4() - 1);
    t = gEmblem->mUnk_1080;
    if (t < 0) {
        t = 0xe;
    }
    gEmblem->mUnk_1080 = t;
    u = gEmblem->mUnk_1080;
    if (u > 0xe) {
        u = 0;
    }
    gEmblem->mUnk_1080 = u;
    sel = gEmblem->mUnk_1080;
    if (sel != func_ov001_021a63b4() - 1) {
        entry_c = func_ov001_02185160(gEmblem->mEmblemSLld, data_ov001_021a7018[sel]);
        entry_d = func_ov001_02185160(gEmblem->mEmblemSLld, 9);
        func_ov001_02184fd8(entry_d, func_ov001_02184fc8(entry_c), func_ov001_02184fb8(entry_c));
        entry_d = func_ov001_02185160(gEmblem->mEmblemSLld, 10);
        func_ov001_02184fd8(entry_d, func_ov001_02184fc8(entry_c), func_ov001_02184fb8(entry_c));
        func_ov001_021a63c0((u8) (gEmblem->mUnk_1080 + 1));
        func_0212ecc0(&data_0217d068, 0, 0x1f1);
    }
    sel = gEmblem->mUnk_1084;
    gEmblem->mUnk_1084 = data_ov001_021a73ac[v + 1][sel];
    gEmblem->mUnk_1084 = data_ov001_021a7508[h + 1][gEmblem->mUnk_1084];
    entry_a = func_ov001_02185160(gEmblem->mEmblemTemplateSLld, 2);
    entry_b = func_ov001_02185160(gEmblem->mEmblemTemplateSLld, data_ov001_021a7098[gEmblem->mUnk_1084]);
    func_ov001_02185018(entry_a, 0);
    func_ov001_02184fd8(entry_a, func_ov001_02184fc8(entry_b), func_ov001_02184fb8(entry_b));
    if (gEmblem->mUnk_1084 != sel) {
        func_02105ac0(0x1ef);
    }
    {
        s32 k;
        void *q;

        for (k = 0; k < 0x1d; k++) {
            q = func_ov001_02185160(gEmblem->mEmblemTemplateSLld, data_ov001_021a7098[k]);
            func_ov001_02185018(q, k == gEmblem->mUnk_1084 ? 1 : 0);
        }
    }
}

void func_ov001_021a2d90(void) {
    s32 i;
    u32 y;
    s32 x;

    if (func_ov001_02192a54() != 0) {
        y = func_ov001_02192a60();
        x = func_ov001_02192a6c();
        i = func_ov001_021850b4(gEmblem->mEmblemCameraSLld, 0, x, y);
        while (i >= 0) {
            func_ov001_021a41c8(i, 1);
            y = func_ov001_02192a60();
            x = func_ov001_02192a6c();
            i = func_ov001_021850b4(gEmblem->mEmblemCameraSLld, i + 1, x, y);
        }
    }
    if (func_ov001_02192a14(4) != 0) {
        func_ov001_021a41c8(1, 0);
    }
}

void func_ov001_021a2cf0(void) {
    s32 v;

    v = func_020ca69c();
    switch (v) {
        case -2:
        case 0:
            func_ov001_021a4aac();
            break;
        case 1:
            func_020ca688(0);
            func_020ac390((void *) func_ov001_02181174(), gEmblem->mUnk_087c, func_ov001_02181268());
            func_020569a8(gEmblem->mUnk_087c);
            gEmblem->mUnk_1090 = 0xb;
            gEmblem->mUnk_1098 = 1;
            break;
        case 2:
            func_020ca688(0);
            gEmblem->mUnk_1090 = 0xb;
            gEmblem->mUnk_1098 = 1;
            break;
    }
    func_020ca844();
    func_020ca83c();
}

void func_ov001_021a2a40(void) {
    s32 t;

    func_ov001_02192a78();
    gEmblem->mUnk_10a8 += 0x4cd;
    t = gEmblem->mUnk_10a8;
    if (t >= 0x100000) {
        t -= 0x100000;
    }
    gEmblem->mUnk_10a8 = t;
    func_020ae6ac(gEmblem, gEmblem->mUnk_0404);
    func_ov001_0218516c(gEmblem->mEmblemMLld, (Unk0218516c *) gEmblem->mUnk_0000);
    switch (gEmblem->mUnk_1090) {
        case 0:
            if (gEmblem->mUnk_10b0 == FALSE) {
                func_ov001_021a30e0();
            }
            func_ov001_0218516c(gEmblem->mEmblemSLld, (Unk0218516c *) gEmblem->mUnk_0404);
            break;
        case 1:
            if (gEmblem->mUnk_10b0 == FALSE) {
                func_ov001_021a2e0c();
            }
            func_ov001_0218516c(gEmblem->mEmblemTemplateSLld, (Unk0218516c *) gEmblem->mUnk_0404);
            func_ov001_0218516c(gEmblem->mEmblemSLld, (Unk0218516c *) gEmblem->mUnk_0404);
            break;
        case 2:
            func_ov001_021a499c();
            func_ov001_0218516c(gEmblem->mEmblemTemplateSLld, (Unk0218516c *) gEmblem->mUnk_0404);
            func_ov001_0218516c(gEmblem->mEmblemSLld, (Unk0218516c *) gEmblem->mUnk_0404);
            break;
        case 3:
            func_ov001_021a48a4();
            func_ov001_0218516c(gEmblem->mEmblemTemplateSLld, (Unk0218516c *) gEmblem->mUnk_0404);
            func_ov001_0218516c(gEmblem->mEmblemSLld, (Unk0218516c *) gEmblem->mUnk_0404);
            break;
        case 4:
            if (gEmblem->mUnk_10ac == FALSE) {
                func_ov001_021a401c();
            }
            if (gEmblem->mUnk_10b0 == FALSE) {
                func_ov001_021a2d90();
            }
            func_ov001_0218516c(gEmblem->mEmblemCameraSLld, (Unk0218516c *) gEmblem->mUnk_0404);
            break;
        case 5:
            if (gEmblem->mUnk_10ac == FALSE) {
                func_ov001_021a401c();
            }
            func_ov001_021a4804();
            func_ov001_0218516c(gEmblem->mEmblemSLld, (Unk0218516c *) gEmblem->mUnk_0404);
            break;
        case 6:
            if (gEmblem->mUnk_10ac == FALSE) {
                func_ov001_021a401c();
            }
            func_ov001_021a47b4();
            func_ov001_0218516c(gEmblem->mEmblemCameraSLld, (Unk0218516c *) gEmblem->mUnk_0404);
            break;
        case 7:
            if (gEmblem->mUnk_10b0 == FALSE) {
                func_ov001_021a30e0();
            }
            func_ov001_021a4774();
            func_ov001_0218516c(gEmblem->mEmblemCameraSLld, (Unk0218516c *) gEmblem->mUnk_0404);
            break;
        case 8:
            if (gEmblem->mUnk_10b0 == FALSE) {
                func_ov001_021a30e0();
            }
            func_ov001_021a4724();
            func_ov001_0218516c(gEmblem->mEmblemSLld, (Unk0218516c *) gEmblem->mUnk_0404);
            break;
        case 10:
            func_ov001_021a2cf0();
            func_ov001_0218516c(gEmblem->mEmblemSLld, (Unk0218516c *) gEmblem->mUnk_0404);
            break;
        case 11:
            func_ov001_0218516c(gEmblem->mEmblemSLld, (Unk0218516c *) gEmblem->mUnk_0404);
            if (data_0217aa08->mUnk_28 == 0) {
                if (data_021759d4->mUnk_0c != 0) {
                    t = data_021759d4->mUnk_10;
                } else {
                    t = 0;
                }
            } else {
                t = 1;
            }
            if (t == 0) {
                gEmblem->mUnk_1090 = 0xc;
            }
            break;
        case 12:
            func_ov001_0218516c(gEmblem->mEmblemSLld, (Unk0218516c *) gEmblem->mUnk_0404);
            break;
    }
    func_020ae630(gEmblem, gEmblem->mUnk_0404);
    func_020783c8();
    func_020780b0();
    func_020ac390((void *) func_ov001_02181174(), gEmblem->mUnk_087c, func_ov001_02181268());
    func_020ac2c4((const u8 *) func_ov001_02181174(), gEmblem->mUnk_0a7c, func_ov001_02181268());
}
