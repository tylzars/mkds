#include "Main/Unknown/code_0203c07c.h"
#include "Main/Unknown/code_020af66c.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0203c000.h"
#include "Main/Unknown/code_020b03bc.h"
#include "Main/Unknown/code_020b32ec.h"
#include "Main/Unknown/code_020b33d8.h"
#include "Main/Unknown/code_020b36c8.h"
#include "Main/Unknown/code_020b3728.h"
#include "Main/Unknown/code_020b3adc.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020b65dc.h"
#include "Main/Unknown/code_020b85f0.h"
#include "Main/Unknown/code_020b8610.h"
#include "Main/Unknown/code_020b8624.h"
#include "Main/Unknown/code_020b9994.h"
#include "Main/Unknown/code_020ba50c.h"
#include "Main/Unknown/code_020bb5cc.h"
#include "Main/Unknown/code_020bb5ec.h"
#include "Main/Unknown/code_020bc108.h"
#include "Main/Unknown/code_020bc11c.h"
#include "Main/Unknown/code_020bcb60.h"
#include "Main/Unknown/code_020bd850.h"
#include "Main/Unknown/code_020be7e8.h"
#include "Main/Unknown/code_020be950.h"
#include "Main/Unknown/code_020c31c0.h"
#include "Main/Unknown/code_020c31ec.h"
#include "Main/Unknown/code_020c3e00.h"
#include "Main/Unknown/code_020c3e44.h"
#include "Main/Unknown/code_020c476c.h"
#include "Main/Unknown/code_020c4bd8.h"
#include "Main/Unknown/code_020c53c4.h"
#include "Main/Unknown/code_020c5ccc.h"
#include "Main/Unknown/code_020c5e30.h"
#include "Main/Unknown/code_020cf310.h"
#include "Main/Unknown/code_020d0280.h"
#include "Main/Unknown/code_020d0bbc.h"
#include "Main/Unknown/code_020d129c.h"
#include "Main/Unknown/code_020d12e0.h"
#include "Main/Unknown/code_020d1298.h"
#include "Main/Unknown/code_020d1450.h"
#include "Main/Unknown/code_020d2090.h"
#include "Main/Unknown/code_020d2094.h"
#include "Main/Unknown/code_0212b1c0.h"
#include "Main/Unknown/code_0212b5d8.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217b000.h"
#include "code_0200eddc.h"
#include "code_021488e8.h"
#include "code_02148950.h"
#include "code_0214a390.h"
#include "code_0214b338.h"
#include "code_0214b824.h"
#include "registers.h"

void func_020af99c(void) {
    u32 v;
    u16 w;

    v = data_021759c0->mUnk_00c;
    if (v == 3) {
        return;
    }
    if (v == 5 || v == 6) {
        return;
    }
    w = gCourseMap->mUnk_018->mUnk_14 & 0x7fff;
    *(vu16 *) 0x05000000 = w;
    data_0217b350->mNclrs[0]->mData[0] = w;
    func_0200ee74(data_0217b350->mNclrs[0]->mData, data_0217b350->mNclrs[0]->mDataSize);
    func_0214c160(data_0217b350->mNclrs[0]->mData, 0, data_0217b350->mNclrs[0]->mDataSize);
    MemCopyWordsToG2Bg2CntBits2To5Address(data_0217b350->mNcgrs[0]->mData, 0, data_0217b350->mNcgrs[0]->mDataSize);
    MemCopyHalfwordsToG2Bg2CntBits8To12Address(data_0217b350->mNscrs[0]->mData, 0, data_0217b350->mNscrs[0]->mDataSize);
    func_0214c090(GetRaceNclrNcgr(0)->mNclr->mData, 0, GetRaceNclrNcgr(0)->mNclr->mDataSize);
    func_0214bf04(GetRaceNclrNcgr(0)->mNcgr->mData, 0, 0x4000);
    reg_GX_DISPCNT = (reg_GX_DISPCNT & ~0xe000) | 0xe000;
    w = reg_G2_WININ;
    reg_G2_WININ = (u32) ((w & ~0x3f) | 0x1f) | 0x20;
    reg_G2_WIN0H = 0xff;
    reg_G2_WIN0V = 0x60c0;
    reg_G2_WININ = (u32) ((reg_G2_WININ & ~0x3f00) | 0x1f00) | 0x2000;
    reg_G2_WIN1H = 0x40ff;
    reg_G2_WIN1V = 0x60;
    reg_G2_WINOUT = (u32) ((reg_G2_WINOUT & ~0x3f00) | 0x1200) | 0x2000;
    reg_G2_WINOUT = (u32) ((reg_G2_WINOUT & ~0x3f) | 0xf) | 0x20;
    reg_GXS_DB_DISPCNT &= ~0xe000;
    GxsDispCntBits0To2Write(5);
    func_0214c028(GetRaceNclrNcgr(6)->mNclr->mData, 0, GetRaceNclrNcgr(6)->mNclr->mDataSize);
    func_0214bea4(GetRaceNclrNcgr(6)->mNcgr->mData, 0, 0x4000);
    func_020b17a4();
    MemCopyHalfwordsToG2sBg1CntBits8To12Address(func_020c3e14(0)->mData, 0, func_020c3e14(0)->mDataSize);
    MemCopyHalfwordsToG2sBg2CntBits8To12Address(func_020c3e14(1)->mData, 0, func_020c3e14(1)->mDataSize);
    MemCopyHalfwordsToG2sBg3CntBits8To12Address(func_020c3e14(2)->mData, 0, func_020c3e14(2)->mDataSize);
    func_0214c0f8(data_0217b34c + 0x100, 0, 0x200);
    func_020cfca4();
    func_02149124(0x80);
    func_0214b4dc();
    func_0214b468(data_0217b34c + 0x100, 0x4000, 0x200);
    func_0214b468(data_0217b34c + 0x100, 0x6000, 0x200);
    func_0214b41c();
    func_0214c0f8(func_020b33c4()->mData, 0, 0x200);
    reg_G2S_DB_BG0OFS = 0;
    reg_G2S_DB_BG0CNT = reg_G2S_DB_BG0CNT & ~3;
    reg_G2S_DB_BG0CNT &= ~0x40;
    reg_G2S_DB_BG0CNT = (reg_G2S_DB_BG0CNT & 0x43) | 0x10c;
    MemCopyWordsToG2sBg0CntBits2To5Address(func_020b3374()->mData, 0, func_020b3374()->mDataSize);
    MemCopyHalfwordsToG2sBg0CntBits8To12Address(func_020b32f8(), 0, 0x600);
    func_020b18b0();
    data_0217b350->mUnk_898 = 1;
}

void func_020af86c(void) {
    u32 v;

    v = data_021759c0->mUnk_00c;
    if (v == 3) {
        func_020c4bd8();
        return;
    }
    if (v == 5) {
        return;
    }
    if (v == 6) {
        func_0212b5d8();
        func_020d1450();
        return;
    }
    func_0214a40c((u32 *) 0x04000050, 0, 0, 0x10, 0x10);
    func_0214a40c((u32 *) 0x04001050, 0, 0, 0x10, 0x10);
    data_0217b350 = NULL;
    func_020b36c8();
    func_020b3af4();
    func_020b65dc();
    func_020b8610();
    if (data_021759c0->mUnk_00c == 4) {
        func_020d129c();
    }
    func_020bb51c();
    func_020c53b0();
    func_020ba50c();
    func_020c5ccc();
    func_020bc108();
    func_020bcb60();
    func_020d2094();
    func_020d0bbc();
    func_020be7e8();
    func_020beb40();
    func_020c31ec();
    func_020c6f84();
    func_020c476c();
    reg_GX_DISPCNT &= ~0xe000;
    reg_GXS_DB_DISPCNT &= ~0xe000;
}

void func_020af66c(void) {
    u32 v;

    if (data_0217b350 != NULL) {
        data_0217b350->mUnk_908 = 1;
    }
    v = data_021759c0->mUnk_00c;
    if (v == 3) {
        func_020c4bb0();
        return;
    }
    if (v == 5) {
        return;
    }
    if (v == 6) {
        func_020d13f8();
        func_0212b204();
        return;
    }
    if (data_0217b350->mUnk_898 == 0) {
        return;
    }
    if (data_0217b350->mUnk_8dc != 0) {
        data_0217b350->mUnk_8e0++;
        if (data_0217b350->mUnk_8e0 >= 0x80) {
            data_0217b350->mUnk_8dc = 0;
            data_0217b350->mUnk_8e0 = -1;
        }
    }
    func_020b3584();
    func_020b3728();
    if (data_021759c0->mUnk_00c == 4) {
        func_020d1298();
    }
    v = data_021759c0->mUnk_08;
    if ((v == 2   ? data_0217561c->mUnk_4cc
         : v == 4 ? func_0203c174()
                  : (func_0203c880(func_020b4d9c()) != 0 && data_0217b350->mUnk_8dc == 0)) == 0) {
        func_020bab54();
        func_020bc958();
        func_020d2090();
        func_020d0a18();
        func_020ba3ec();
        func_020c5940();
    } else {
        func_020bb5cc();
        func_020bc958();
        func_020d0a18();
        func_020c5940();
    }
    func_020bbbb4();
    func_020be3e4();
    switch (data_0217b350->mUnk_828) {
        case 0:
        case 1:
        case 2:
        case 3:
            func_020be9d4();
            func_020c43c4();
            break;
        case 4:
        case 5:
            func_020c31c0();
            break;
        case 6:
            break;
    }
    func_020c6f14();
    data_0217b350->mUnk_000++;
    if (data_0217b350->mUnk_000 >= 0xc00) {
        data_0217b350->mUnk_000 = 0;
    }
}
