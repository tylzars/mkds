#include "00/code_02180724.h"
#include "00/code_02180be8.h"
#include "00/code_02180c04.h"
#include "00/code_02181714.h"
#include "00/code_02181fcc.h"
#include "00/code_02182fdc.h"
#include "00/code_021848c8.h"
#include "00/code_021849e0.h"
#include "00/code_02184aa4.h"
#include "00/code_021857b8.h"
#include "00/code_02184ba8.h"
#include "00/code_02185344.h"
#include "00/code_021804f4.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02027df8.h"
#include "Main/Unknown/code_020296f4.h"
#include "Main/Unknown/code_02029a70.h"
#include "Main/Unknown/code_0202a734.h"
#include "Main/Unknown/code_0202b000.h"
#include "Main/Unknown/code_0202bb60.h"
#include "Main/Unknown/code_0202c000.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020476ac.h"
#include "Main/Unknown/code_0204799c.h"
#include "Main/Unknown/code_02078000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_0211f6cc.h"
#include "Main/Unknown/code_0212030c.h"
#include "Main/Unknown/code_02122b14.h"
#include "Main/Unknown/code_02124f4c.h"
#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/code_02125960.h"
#include "Main/Unknown/code_02125da0.h"
#include "Main/Unknown/code_02125de0.h"
#include "Main/Unknown/code_0212a920.h"
#include "Main/Unknown/code_0212abd0.h"
#include "Main/Unknown/code_0212abdc.h"
#include "Main/Unknown/unk_0217a000.h"

void func_ov000_02180724(void) {
    if (data_ov000_021b4c64->mUnk_1c.mUnk_08 != 0) {
        data_ov000_021b4c64->mUnk_1c.mUnk_08();
    }
    if (data_ov000_021b4c64->mUnk_0c != -1) {
        data_ov000_021b4c64->mUnk_1c.mUnk_04();
        func_ov000_02180be8();
        func_02036ab0(data_ov000_021b4c64->mUnk_04);
        data_ov000_021b4c64->mUnk_04 = func_020369fc(data_ov000_021b4c64->mUnk_00);
        switch (data_ov000_021b4c64->mUnk_0c) {
            case 0:
                func_ov000_02180c04();
                break;
            case 1:
                func_ov000_02181714();
                break;
            case 2:
                func_ov000_02181fcc();
                break;
            case 3:
                func_ov000_0218330c();
                break;
            case 4:
                func_ov000_021848c8();
                break;
            case 5:
                func_ov000_021849e0();
                break;
            case 6:
                func_ov000_02184aa4();
                break;
            case 7:
                func_ov000_021857b8();
                break;
            case 8:
                func_ov000_02184ba8();
                break;
            case 9:
                func_ov000_02185344();
                break;
        }
        data_ov000_021b4c64->mUnk_10 = data_ov000_021b4c64->mUnk_08;
        data_ov000_021b4c64->mUnk_08 = data_ov000_021b4c64->mUnk_0c;
        data_ov000_021b4c64->mUnk_0c = -1;
        if (data_ov000_021b4c64->mUnk_1c.mUnk_00 != 0) {
            data_ov000_021b4c64->mUnk_1c.mUnk_00(data_ov000_021b4c64->mUnk_04);
        }
    }
    func_02125928();
    func_0212a920();
    data_ov000_021b4c64->mUnk_14++;
    if (data_ov000_021b4c64->mUnk_14 > 0) {
        data_ov000_021b4c64->mUnk_14 = 0;
    }
}

void func_ov000_02180814(void) {
    if (data_ov000_021b4c64->mUnk_1c.mUnk_04 != 0) {
        data_ov000_021b4c64->mUnk_1c.mUnk_04();
    }
    func_ov000_02180be8();
    func_0202bb60();
    func_0212abd0();
    func_02125da0();
    data_ov000_021b4c64 = 0;
}

void func_ov000_02180844(void *a, s32 b) {
    Unk02125de0Arg c;
    Unk0217d384_08 *q;
    data_ov000_021b4c64 = func_02036bec(a, 0x3c);
    data_ov000_021b4c64->mUnk_00 = a;
    data_ov000_021b4c64->mUnk_14 = 0;
    func_02029a70(a);
    data_ov000_021b4c64->mUnk_2c = func_02125028(a);
    func_0212abdc(a, func_ov000_021804f4());
    c.mUnk_00 = 1;
    c.mUnk_04 = func_020b403c(1);
    c.mUnk_08 = 0;
    c.mUnk_0c = 0;
    c.mUnk_10 = 0;
    c.mUnk_14 = 0;
    c.mUnk_18 = 0;
    c.mUnk_1c = 1;
    c.mUnk_20 = 1;
    c.mUnk_24 = 1;
    func_02125c2c();
    func_02125de0(a, &c);
    func_ov000_02180a54();
    func_0202c65c(a, func_ov000_021804f4());
    func_02078d64(func_020364e0(func_020364e8()));
    func_02078a9c(-1);
    func_02078a34(-1);
    func_020476ac();
    data_ov000_021b4c64->mUnk_04 = func_020369fc(a);
    func_ov000_02180be8();
    data_ov000_021b4c64->mUnk_18 = -1;
    if (data_0217b488->mUnk_58 != 0) {
        b = 0;
        data_0217b488->mUnk_58 = 0;
    }
    switch (b) {
        case 0:
            data_ov000_021b4c64->mUnk_10 = 10;
            data_ov000_021b4c64->mUnk_08 = 1;
            func_ov000_02181714();
            func_021204d0();
            data_0217b488->mUnk_1c = 0;
            break;
        case 12:
            data_ov000_021b4c64->mUnk_10 = 13;
            data_ov000_021b4c64->mUnk_08 = 1;
            func_ov000_02181714();
            break;
        case 2:
        case 10:
            switch (data_0217b488->mUnk_1c) {
                case 0:
                    data_ov000_021b4c64->mUnk_08 = 1;
                    func_ov000_02181714();
                    break;
                case 1:
                    q = &data_0217d384->mUnk_0008;
                    q->mUnk_10 = 2;
                    q->mUnk_12 = 1;
                    data_ov000_021b4c64->mUnk_08 = 2;
                    func_ov000_02181fcc();
                    break;
                case 2:
                    func_02123a48(1);
                    data_ov000_021b4c64->mUnk_08 = 4;
                    func_ov000_021848c8();
                    break;
                case 3:
                    func_02123a48(2);
                    func_020296f4();
                    data_ov000_021b4c64->mUnk_08 = 6;
                    func_ov000_02184aa4();
                    break;
            }
            break;
        case 14:
            data_ov000_021b4c64->mUnk_10 = 11;
            data_ov000_021b4c64->mUnk_08 = 8;
            func_ov000_02184ba8();
            break;
        case 8:
            switch (data_0217b488->mUnk_50) {
                case 0:
                    data_ov000_021b4c64->mUnk_10 = 14;
                    data_ov000_021b4c64->mUnk_08 = 2;
                    func_ov000_02181fcc();
                    break;
                case 1:
                    data_ov000_021b4c64->mUnk_10 = 14;
                    data_ov000_021b4c64->mUnk_08 = 8;
                    func_ov000_02184ba8();
                    break;
            }
            break;
    }
    data_ov000_021b4c64->mUnk_0c = -1;
    data_ov000_021b4c64->mUnk_1c.mUnk_00(data_ov000_021b4c64->mUnk_04);
    data_0217b488->mUnk_78 = 1;
}

void func_ov000_02180a54(void) {
    Unk02111684_v v;
    func_020b496c(&v.m4934, func_0204799c("WiFi_VS_setting_s_b.ncgr"));
    func_020b4a7c(&v.m4a44, func_0204799c("WiFi_VS_setting_s_b.nclr"));
    func_020b4810(&v.m47d8, func_0204799c("WiFi_VS_s_setting.nscr"));
    func_020b496c(&v.m4934, func_0204799c("WiFi_VS_matching_s_b.ncgr"));
    func_020b4a7c(&v.m4a44, func_0204799c("WiFi_VS_matching_s_b.nclr"));
    func_020b4810(&v.m47d8, func_0204799c("WiFi_VS_matching_s.nscr"));
    func_020b49f4(&v.m4934, func_0204799c("WiFi_top_menu_s.nce.ncgr"));
    func_020b48ec(&v.m21dc8, func_0204799c("WiFi_top_menu_s.nce.ncer"));
    func_020b4a7c(&v.m4a44, func_0204799c("WiFi_top_menu_s_o.nclr"));
    func_020b49f4(&v.m4934, func_0204799c("WiFi_VS_setting_s.nce.ncgr"));
    func_020b48ec(&v.m21dc8, func_0204799c("WiFi_VS_setting_s.nce.ncer"));
    func_020b4a7c(&v.m4a44, func_0204799c("WiFi_VS_setting_s_o.nclr"));
    func_020b49f4(&v.m4934, func_0204799c("WiFi_VS_matching_s.nce.ncgr"));
    func_020b48ec(&v.m21dc8, func_0204799c("WiFi_VS_matching_s.nce.ncer"));
    func_020b4a7c(&v.m4a44, func_0204799c("WiFi_VS_matching_s_o.nclr"));
    func_020b49f4(&v.m4934, func_0204799c("WiFi_aikotoba_s.nce.ncgr"));
    func_020b48ec(&v.m21dc8, func_0204799c("WiFi_aikotoba_s.nce.ncer"));
    func_020b4a7c(&v.m4a44, func_0204799c("WiFi_aikotoba_s_o.nclr"));
    func_020b49f4(&v.m4934, func_0204799c("WiFi_aikotoba_check_m.nce.ncgr"));
    func_020b48ec(&v.m21dc8, func_0204799c("WiFi_aikotoba_check_m.nce.ncer"));
    func_020b4a7c(&v.m4a44, func_0204799c("WiFi_aikotoba_check_m_o.nclr"));
    func_02025f90();
    func_02027df8();
    func_0202a734();
    func_0202b8d8();
}
