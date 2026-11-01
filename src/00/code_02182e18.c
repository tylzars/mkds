#include "00/code_02182e18.h"
#include "00/code_02182fdc.h"
#include "Main/Unknown/code_0212b91c.h"

void func_ov000_02182f88(void) {
    u32 a;

    a = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
    a &= ~8;
    *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | (a << 8);
    *(vu16 *) 0x400100e = (*(vu16 *) 0x400100e & 0x43) | 0xf00;
    func_0212b91c();
    data_ov000_021b4c70 = 0;
}

void func_ov000_02182e18(void) {
    Unk020b4934 *v1;
    Unk020b47d8 *v2;
    Unk020b4a44 *v3;
    vu16 v4;

    func_020b4934(&v1, func_0204799c("WiFi_VS_setting_s_b.ncgr"));
    func_020b47d8(&v2, func_0204799c("WiFi_VS_s_setting.nscr"));
    func_020b4a44(&v3, func_0204799c("WiFi_VS_setting_s_b.nclr"));
    data_ov000_021b4c70->mUnk_104c = func_0204799c("WiFi_VS_setting.bncl");
    data_ov000_021b4c70->mUnk_1050 = func_0204799c("WiFi_VS_setting.bnbl");
    data_ov000_021b4c70->mUnk_1054 = func_0204799c("WiFi_VS_setting.bnll");
    func_020b49bc(&data_ov000_021b4c70->mUnk_1044, func_0204799c("WiFi_VS_setting_s.nce.ncgr"));
    func_020b48b4(&data_ov000_021b4c70->mUnk_1040, func_0204799c("WiFi_VS_setting_s.nce.ncer"));
    func_020b4a44(&data_ov000_021b4c70->mUnk_1048, func_0204799c("WiFi_VS_setting_s_o.nclr"));
    *(vu16 *) 0x400100e = (*(vu16 *) 0x400100e & 0x43) | 0x4400;
    v4 = 0;
    func_0214cfe4(v4, data_ov000_021b4c70->mUnk_38, 0x1000);
    func_0214cffc(v2->mUnk_0c, data_ov000_021b4c70->mUnk_38, 0x800);
    func_02016468(0x17, 0, v1->mUnk_14, v1->mUnk_10);
    func_02016468(0x1b, 0, data_ov000_021b4c70->mUnk_38, 0x1000);
    func_02016468(0x1f, 0, v3->mUnk_0c, 0x80);
    func_02016468(0x23, 0, data_ov000_021b4c70->mUnk_1044->mUnk_14, data_ov000_021b4c70->mUnk_1044->mUnk_10);
    func_02016468(0x1e, 0, data_ov000_021b4c70->mUnk_1048->mUnk_0c, data_ov000_021b4c70->mUnk_1048->mUnk_08);
}
