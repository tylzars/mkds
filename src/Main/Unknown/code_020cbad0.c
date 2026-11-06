#include "Main/Unknown/code_020cbad0.h"
#include "Main/Unknown/code_0202bb80.h"
#include "Main/Unknown/code_0203206c.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_0203be88.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020cae8c.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_020b47b4.h"
#include "Main/Unknown/code_020cae54.h"
#include "Main/Unknown/code_020cb99c.h"
#include "Main/Unknown/code_020cba30.h"
#include "Main/Unknown/code_020cc168.h"
#include "Main/Unknown/code_020cc0e4.h"
#include "Main/Unknown/code_020cc134.h"
#include "Main/Unknown/code_020cc000.h"
#include "Main/Unknown/code_020cc744.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_02029000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020ccc74.h"
#include "Main/Unknown/code_0212a910.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_02029a24.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Unknown/code_0203b000.h"
#include "code_020176b0.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0211e0c4.h"
#include "Main/Unknown/code_020d1108.h"
#include "Main/Unknown/code_02125960.h"
#include "Main/Unknown/code_02125de0.h"
#include "Main/Unknown/code_021281fc.h"
#include "Main/Unknown/code_0212a000.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02116ec0.h"
#include "Main/Unknown/code_0211f240.h"
#include "Main/Unknown/code_0211db90.h"
#include "Main/Unknown/code_021189f4.h"
#include "Main/Unknown/code_02119e14.h"
#include "Main/Unknown/code_02027df8.h"
#include "Main/Unknown/code_020ccc9c.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "01/code_ov001_02197b34.h"
#include "01/code_0219eab4.h"
#include "01/code_0219f8ec.h"
#include "01/code_0219d50c.h"
#include "01/code_021a11a4.h"
#include "01/code_0219b540.h"
#include "Main/Unknown/unk_02156000.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_0202b000.h"
#include "Main/Unknown/code_0202c000.h"
#include "Main/Unknown/code_02032000.h"
#include "Main/Unknown/code_02062000.h"
#include "Main/Unknown/code_02078000.h"
#include "Main/Unknown/code_02025f80.h"

#pragma thumb on
#pragma optimize_for_size on
void func_020cbb10(void) {
    Unk0217b43c *p;
    Unk02125de0 s;
    Unk02180774 *r;

    data_0217b43c = HeapAlloc(func_020cb99c(), 0x960);
    func_02029a70(func_020cb99c());
    r = CreateDisplaySettings(func_020cb99c(), data_0215688c);
    func_020cc330(r, 1, 0, 0, 0, 0xd, 2, 0);
    func_020cc2f4(r, 0, 0, 0, 0, 0xc, 0, 0);
    func_020cc2c0(r, 0, 0, 0, 0, 0x1e, 6);
    func_020cc28c(r, 3, 0, 0, 0, 0x1d, 4);
    func_020cc250(r, 0, 0, 0, 0, 0xb, 0, 0);
    func_020cc214(r, 3, 0, 0, 0, 0xd, 0, 0);
    func_020cc1e0(r, 0, 0, 0, 0, 0xe, 0);
    func_020cc1ac(r, 2, 0, 0, 0, 0xf, 0);
    InitDisplayFromSettings(r);
    data_0217b43c->mUnk_000 = 0;
    data_0217b43c->mUnk_004 = 1;
    data_0217b43c->mUnk_008 = 0x1f;
    data_0217b43c->mUnk_00c = 0x1f;
    data_0217b43c->mUnk_010 = 0x1f;
    data_0217b43c->mUnk_104 = TRUE;
    data_0217b43c->mUnk_958 = TRUE;
    data_0217b43c->mUnk_95c = TRUE;
    func_020cc3b8();
    func_020ae6d4(data_0217b43c->mUnk_108, data_0217b43c->mUnk_50c);
    func_02047b6c(9);
    func_02062860();
    func_02047b6c(5);
    func_020629a4();
    func_02047b6c(9);
    if (func_020cbad0() == 0) {
        func_02078d64(func_020cb99c());
        func_02078a9c(-1);
        func_02078a34(-1);
    }
    func_02047b6c(5);
    if (func_020cbad0() == 0) {
        func_0211e480(func_020cb99c());
        InitCupPicture();
        LoadNclrData(&data_0217b43c->mSinglePlaySelectModeMONclr,
                     FindSceneFileWrapper("common/single_play_select_mode_m_o.NCLR"));
        LoadNcgrData2(&data_0217b43c->mSinglePlaySelectModeMNcgr,
                      FindSceneFileWrapper("common/single_play_select_mode_m.nce.ncgr"));
        LoadNcerData(&data_0217b43c->mSinglePlaySelectModeMNcer,
                     FindSceneFileWrapper("common/single_play_select_mode_m.nce.ncer"));
        data_0217b43c->mSinglePlaySelectModeMBncl = FindSceneFileWrapper("common/single_play_select_mode_m.bncl");
        data_0217b43c->mUnk_944 = 0;
        LoadNclrData(&data_0217b43c->mSinglePlaySelectModeSONclr,
                     FindSceneFileWrapper("common/single_play_select_mode_s_o.NCLR"));
        LoadNcgrData2(&data_0217b43c->mSinglePlaySelectModeSNcgr,
                      FindSceneFileWrapper("common/single_play_select_mode_s.nce.ncgr"));
        LoadNcerData(&data_0217b43c->mSinglePlaySelectModeSNcer,
                     FindSceneFileWrapper("common/single_play_select_mode_s.nce.ncer"));
        data_0217b43c->mSinglePlaySelectModeSBncl = FindSceneFileWrapper("common/single_play_select_mode_s.bncl");
        data_0217b43c->mSinglePlaySelectModeSBnbl = FindSceneFileWrapper("common/single_play_select_mode_s.bnbl");
        p = data_0217b43c;
        func_02124ed0(func_020cb99c(), p->mSinglePlaySelectModeMBncl, NULL, &p->mUnk_93c);
        p = data_0217b43c;
        func_02124ed0(func_020cb99c(), p->mSinglePlaySelectModeSBncl, NULL, &p->mUnk_948);
        p = data_0217b43c;
        func_02124a98(0, 1, p->mSinglePlaySelectModeSNcer, p->mSinglePlaySelectModeSBncl);
        p = data_0217b43c;
        func_02124a98(1, 1, p->mSinglePlaySelectModeSNcer, p->mSinglePlaySelectModeSBncl);
        p = data_0217b43c;
        func_02124a98(2, 1, p->mSinglePlaySelectModeSNcer, p->mSinglePlaySelectModeSBncl);
        p = data_0217b43c;
        func_02124a98(3, 1, p->mSinglePlaySelectModeSNcer, p->mSinglePlaySelectModeSBncl);
        p = data_0217b43c;
        func_02124a98(4, 1, p->mSinglePlaySelectModeSNcer, p->mSinglePlaySelectModeSBncl);
    }
    func_0202b8d8();
    func_0202c65c(func_020cb99c(), data_0217b43c->mUnk_108);
    data_0217b43c->mUnk_954 = func_0203bedc(func_020cb99c());
    func_020cc18c(0x10);
    func_020cc168(0x10);
    func_020cba6c(0, 0x3f, 6, 10);
    func_020cba30(0, 0x3f, 6, 10);
    func_020cc150(0);
    func_020cc134(0);
    if (func_020cbad0() == 0) {
        func_02025f90();
        func_02027df8();
        LoadTimeAttackTopMenuData();
        LoadSelectGhostAndKartIconData();
        LoadMissionRunLVselData();
        func_ov001_021a10b8();
        func_ov001_0219d50c();
        LoadSelectEngineData();
        func_02118d44();
        func_0211f240();
        func_0211a6bc();
    }
    LoadSelectGameData();
    func_0211dd44();
    s.mUnk_00 = func_020cbad0();
    s.mUnk_04 = func_020b403c(1);
    s.mUnk_08 = 0;
    s.mUnk_0c = 1;
    s.mUnk_10 = 0;
    s.mUnk_14 = 1;
    s.mUnk_18 = func_020b403c(2);
    s.mUnk_1c = 1;
    s.mUnk_20 = 1;
    s.mUnk_24 = 0;
    LoadTxtSystemAndSelectChoisesAndSelectReturnData();
    func_02125de0(func_020cb99c(), &s);
    if (func_020cae54() == 2) {
        ClearSelectReturnDisplayBitOn();
    }
    func_0212abdc(func_020cb99c(), data_0217b43c->mUnk_108);
    switch (func_020cc120()) {
        case 0:
            func_020ccc74(0, 0x1f);
            func_020cc10c(1);
            break;
        case 1:
            func_020cc3e8();
            switch (func_02029930()->mUnk_c8) {
                case 0:
                    func_020ccc74(5, 0x1f);
                    func_020cbabc(0);
                    func_020cc10c(1);
                    break;
                case 3:
                    func_020ccc74(8, 0x1f);
                    break;
                case 2:
                    func_020ccc74(0xf, 0x1f);
                    break;
                case 1:
                    func_020ccc74(0x15, 0x1f);
                    func_020cbabc(0);
                    func_020cc10c(1);
                    break;
            }
            break;
        case 2:
            func_020cc3e8();
            switch (func_02029930()->mUnk_c8) {
                case 3:
                    func_020ccc74(0xb, 0x1f);
                    break;
                case 2:
                    func_020ccc74(SCREEN_SELECT_BATTLE_STAGE, 0x1f);
                    break;
                case 1:
                    func_020ccc74(0x17, 0x1f);
                    func_020cbabc(0);
                    func_020cc10c(1);
                    break;
            }
            break;
        case 3:
            func_020cc3e8();
            if (func_020cc0f8() != 0 || func_020cc0e4() != 0) {
                func_020ccc74(SCREEN_MISSION_RUN_LVSEL, 0x1f);
            } else {
                func_020ccc74(SCREEN_MISSION_RUN_MSSEL, 0x1f);
            }
            func_020cbabc(0);
            func_020cc10c(1);
            break;
        case 4:
            func_020ccc74(0xe, 0x1f);
            break;
        case 5:
            func_020cc3e8();
            func_02029930()->mUnk_c8 = 1;
            func_020ccc74(SCREEN_TIME_ATTACK_TOP_MENU, 0x1f);
            func_020cbabc(0);
            func_020cc10c(1);
            break;
    }
    func_0211717c(func_020cb99c());
    switch (func_02029930()->mUnk_c8) {
        case 0:
        default:
            data_0217b43c->mUnk_930 = 0;
            break;
        case 1:
            data_0217b43c->mUnk_930 = 1;
            break;
        case 2:
            data_0217b43c->mUnk_930 = 3;
            break;
        case 3:
            data_0217b43c->mUnk_930 = 2;
            break;
        case 4:
            data_0217b43c->mUnk_930 = 4;
            break;
    }
    data_0217b43c->mUnk_934 = FALSE;
    data_0217b43c->mUnk_938 = 0;
}
#pragma thumb off

u16 *func_020cbb04(void) {
    return (u16 *) 0x27ffc40;
}

BOOL func_020cbadc(void) {
    return *func_020cbb04() == 2;
}

s32 func_020cbad0(void) {
    return func_020cbadc();
}
