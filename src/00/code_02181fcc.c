#include "00/code_02181fcc.h"
#include "00/code_ov000_021804e0.h"
#include "Main/Unknown/code_020adb04.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_0212b5ec.h"
#include "code_0214a390.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_02125f88.h"
#include "00/unk_021b4000.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02126570.h"
#include "Main/Unknown/code_0212658c.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ae428.h"
#include "Main/Unknown/code_02128244.h"
#include "Main/Unknown/code_021266e4.h"
#include "Main/Unknown/code_0212630c.h"
#include "code_0212df7c.h"
#include "code_0201ea58.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_020ee684.h"

#include "00/code_02180608.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02122ae4.h"
#include "Main/Unknown/code_02122794.h"
#include "Main/Unknown/code_0211f6cc.h"
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

    LocateNcgr(&v1, FindSceneFile("WiFi_VS_setting_s_b.ncgr"));
    LocateNscr(&v2, FindSceneFile("WiFi_VS_s_setting.nscr"));
    LocateNclr(&v3, FindSceneFile("WiFi_VS_setting_s_b.nclr"));
    data_ov000_021b4c70->mUnk_104c = FindSceneFile("WiFi_VS_setting.bncl");
    data_ov000_021b4c70->mUnk_1050 = FindSceneFile("WiFi_VS_setting.bnbl");
    data_ov000_021b4c70->mUnk_1054 = FindSceneFile("WiFi_VS_setting.bnll");
    LocateNcgr2(&data_ov000_021b4c70->mUnk_1044, FindSceneFile("WiFi_VS_setting_s.nce.ncgr"));
    LocateNcer(&data_ov000_021b4c70->mUnk_1040, FindSceneFile("WiFi_VS_setting_s.nce.ncer"));
    LocateNclr(&data_ov000_021b4c70->mUnk_1048, FindSceneFile("WiFi_VS_setting_s_o.nclr"));
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

void func_ov000_02182de8(void) {
    u32 v1;
    v1 = ((int) func_020b3f7c((void *) (data_ov000_021b4c70->mUnk_1058), 0));
    func_02126638((void *) v1, 0, 0, 1, 0, 0, 0);
}

void func_ov000_02182d74(void) {
    if (func_02036d08() != 0) {
        func_02037288(10);
    }
    if (func_02036c5c() != 0) {
        if (func_02122ae4() != 0) {
            data_ov000_021b4c70->mUnk_04 = 1;
            func_02126638(func_020b3f7c(data_ov000_021b4c70->mUnk_1058, 0x1b), 0, 0, 1, 0, 0, 0);
            func_02122ab0();
            func_0211fe44();
            return;
        }
        data_ov000_021b4c70->mUnk_04 = 2;
        func_ov000_02182de8();
        func_0211fe44();
    }
}

void func_ov000_02182d28(void) {
    int v1;
    data_ov000_021b4c70->mUnk_10 = data_ov000_021b4c70->mUnk_10 + 1;
    v1 = func_02125fa4();
    if ((v1 != 0) && (0x78 < data_ov000_021b4c70->mUnk_10)) {
        func_02125fc0();
    }
    v1 = func_02125f88();
    if (v1 != 0) {
        data_ov000_021b4c70->mUnk_04 = 2;
        func_ov000_02182de8();
        data_ov000_021b4c70->mUnk_10 = 0;
    }
    return;
}

void func_ov000_02182cb8(void) {
    s32 v;
    s32 i;

    data_ov000_021b4c70->mUnk_10 = data_ov000_021b4c70->mUnk_10 + 1;
    v = func_020ae4c0(1, 0x100, 0, data_ov000_021b4c70->mUnk_10, 10);
    for (i = 0; i < 2; i++) {
        if (i == 0) {
            data_ov000_021b4c70->mUnk_14[i][0] = v;
        } else {
            data_ov000_021b4c70->mUnk_14[i][0] = -v;
        }
    }
    if (data_ov000_021b4c70->mUnk_10 >= 10) {
        data_ov000_021b4c70->mUnk_04 = 3;
        data_ov000_021b4c70->mUnk_10 = 0;
        func_02128374();
    }
}

void func_ov000_02182c60(void) {
    s16 v;

    data_ov000_021b4c70->mUnk_10 = data_ov000_021b4c70->mUnk_10 + 1;
    if (data_ov000_021b4c70->mUnk_10 < 3) {
        v = -func_0212825c(0);
    } else {
        v = -func_0212825c(data_ov000_021b4c70->mUnk_10 - 3);
    }
    data_ov000_021b4c70->mUnk_14[2][1] = v;
    if (data_ov000_021b4c70->mUnk_10 >= 10 && data_ov000_021b4c70->mUnk_10 >= 13) {
        data_ov000_021b4c70->mUnk_04 = 4;
        data_ov000_021b4c70->mUnk_10 = 0;
    }
}

void func_ov000_021828e4(void) {
    s32 v1 = data_ov000_021b4c70->mUnk_08;
    s32 v2 = data_ov000_021b4c70->mUnk_0c;
    Unk02175628Index i = UNK_02175628_INDEX_8;
    s32 v3 = 0;
    u32 v4 = -1;
    s32 v5 = 0;
    s32 v6;
    s32 v7;
    s32 v8;
    Unk02175628 *e;
    u32 t;

    if (data_02175674[i].mUnk_00 == 0 && data_02175680[i].mUnk_00 < 5) {
        v5 = 1;
    }
    if (v5 == 0 && data_0217567c[i].mUnk_00 == 0 && data_02175674[i].mUnk_00 != 0) {
        v3 = 1;
    }
    if (v3 != 0) {
        v4 = func_0201ea84(data_ov000_021b4c70->mUnk_1050, data_02175670[i].mUnk_00, data_02175672[i].mUnk_00);
    }
    e = &data_02175628[i];
    v8 = e->mUnk_00 & 2;
    if ((u16) v8 == 0) {
        v7 = v6 = 0;
        if (data_02175674[i].mUnk_00 == 0 && data_02175680[i].mUnk_00 < 5) {
            v7 = 1;
        }
        if (v7 == 0 && data_0217567c[i].mUnk_00 == 0 && data_02175674[i].mUnk_00 != 0) {
            v6 = 1;
        }
        if (v6 == 0 || func_02128210(data_02175670[i].mUnk_00, data_02175672[i].mUnk_00) == 0) {
            goto next;
        }
    }
    data_ov000_021b4c70->mUnk_04 = 6;
    data_ov000_021b4c70->mUnk_20 = 1;
    func_02128310(1);
    data_ov000_021b4c70->mUnk_28 = 1;
    func_02125fc0();
    goto end;
next:
    v8 = e->mUnk_00 & 1;
    if (((u16) v8 != 0 && data_ov000_021b4c70->mUnk_08 == 2) || v4 == 2) {
        data_ov000_021b4c70->mUnk_04 = 5;
        if (data_ov000_021b4c70->mUnk_08 == 2) {
            data_ov000_021b4c70->mUnk_24 = 0;
        }
        data_ov000_021b4c70->mUnk_20 = 3;
        data_ov000_021b4c70->mUnk_08 = 2;
        data_0217b488->mUnk_54 = data_ov000_021b05ec[data_ov000_021b4c70->mUnk_0c];
        if ((u16) (data_0217562a[i].mUnk_00 & 0x100) != 0) {
            func_ov000_02180638(1);
        }
        func_ov000_02180650(data_ov000_021b4c70->mUnk_0c);
        func_02105ac0(5);
    } else if (((u16) v8 != 0 && data_ov000_021b4c70->mUnk_08 == 0) || v4 == 0) {
        data_ov000_021b4c70->mUnk_04 = 5;
        if (data_ov000_021b4c70->mUnk_08 == 0) {
            data_ov000_021b4c70->mUnk_24 = 0;
        }
        data_ov000_021b4c70->mUnk_20 = 14;
        data_ov000_021b4c70->mUnk_08 = 0;
        data_0217b488->mUnk_50 = 0;
        func_02125fc0();
        func_02105ac0(5);
        data_0217b488->mUnk_54 = data_ov000_021b05ec[data_ov000_021b4c70->mUnk_0c];
        func_0211fe44();
    } else if (v4 == 1) {
        data_ov000_021b4c70->mUnk_08 = 1;
        data_ov000_021b4c70->mUnk_0c = data_ov000_021b4c70->mUnk_0c + 1;
        func_02105ac0(1);
    } else if (func_020ae408(8, 0x40) != 0) {
        data_ov000_021b4c70->mUnk_08 = data_ov000_021b4c70->mUnk_08 - 1;
        if (data_ov000_021b4c70->mUnk_08 < 0) {
            data_ov000_021b4c70->mUnk_08 = 2;
        }
        func_02105ac0(0);
    } else if (func_020ae408(8, 0x80) != 0 || (data_ov000_021b4c70->mUnk_08 == 1 && (u16) (e->mUnk_00 & 1) != 0)) {
        data_ov000_021b4c70->mUnk_08 = data_ov000_021b4c70->mUnk_08 + 1;
        if (data_ov000_021b4c70->mUnk_08 > 2) {
            data_ov000_021b4c70->mUnk_08 = 0;
        }
        func_02105ac0(0);
    } else if (data_ov000_021b4c70->mUnk_08 == 1 && func_020ae408(8, 0x20) != 0) {
        data_ov000_021b4c70->mUnk_0c = data_ov000_021b4c70->mUnk_0c - 1;
        data_ov000_021b4c70->mUnk_2c = 6;
        func_02105ac0(1);
    } else if (data_ov000_021b4c70->mUnk_08 == 1 && func_020ae408(8, 0x10) != 0) {
        data_ov000_021b4c70->mUnk_0c = data_ov000_021b4c70->mUnk_0c + 1;
        if (func_020ae408(8, 0x10) != 0) {
            data_ov000_021b4c70->mUnk_30 = 6;
        }
        func_02105ac0(1);
    } else if (v4 == 3) {
        data_ov000_021b4c70->mUnk_08 = 1;
        data_ov000_021b4c70->mUnk_0c = data_ov000_021b4c70->mUnk_0c - 1;
        data_ov000_021b4c70->mUnk_2c = 6;
        func_02105ac0(1);
    } else if (v4 == 4) {
        data_ov000_021b4c70->mUnk_08 = 1;
        data_ov000_021b4c70->mUnk_0c = data_ov000_021b4c70->mUnk_0c + 1;
        data_ov000_021b4c70->mUnk_30 = 6;
        func_02105ac0(1);
    }
end:
    if (data_ov000_021b4c70->mUnk_0c < 0) {
        data_ov000_021b4c70->mUnk_0c = 3;
    }
    if (data_ov000_021b4c70->mUnk_0c > 3) {
        data_ov000_021b4c70->mUnk_0c = 0;
    }
    if (v2 != data_ov000_021b4c70->mUnk_0c) {
        t = func_ov000_02180668(data_ov000_021b4c70->mUnk_0c);
        func_0212426c(1, data_ov000_021b05e8[1], data_ov000_021b4c70->mUnk_1054,
                      func_020b3f7c(data_ov000_021b4c70->mUnk_1058, t), data_ov000_021b4c70->mUnk_104c,
                      data_ov000_021b4c70->mUnk_103c);
    }
    if (data_ov000_021b4c70->mUnk_08 == 2 && v1 != 2) {
        func_0212b7fc();
    }
}

void func_ov000_02182878(void) {
    data_ov000_021b4c70->mUnk_10 = data_ov000_021b4c70->mUnk_10 + 1;
    if (data_ov000_021b4c70->mUnk_10 >= 10) {
        data_ov000_021b4c70->mUnk_04 = 6;
        data_ov000_021b4c70->mUnk_10 = 0;
        func_02125fc0();
        if (func_ov000_021832f0() != 0 || (data_ov000_021b4c70->mUnk_20 == 3 && data_ov000_021b4c70->mUnk_0c != 0)) {
            func_021282c8();
            data_ov000_021b4c70->mUnk_28 = 1;
            return;
        }
        data_ov000_021b4c70->mUnk_28 = 0;
    } else if (data_ov000_021b4c70->mUnk_10 >= 5) {
        data_ov000_021b4c70->mUnk_24 = 1;
    }
}

void func_ov000_02182688(void) {
    s32 v;
    s16 u;
    s32 i;

    if (func_ov000_021806c4() == -1 && data_ov000_021b4c70->mUnk_20 == 14 && func_ov000_021832f0() != 0) {
        func_ov000_021806b8(8);
    }
    data_ov000_021b4c70->mUnk_10 = data_ov000_021b4c70->mUnk_10 + 1;
    if (data_ov000_021b4c70->mUnk_10 <= 10) {
        v = func_020ae4c0(1, 0, 0x100, data_ov000_021b4c70->mUnk_10, 10);
    } else {
        v = 0x100;
    }
    for (i = 0; i < 2; i++) {
        if (i == 0) {
            data_ov000_021b4c70->mUnk_14[i][0] = v;
        } else {
            data_ov000_021b4c70->mUnk_14[i][0] = -v;
        }
    }
    if (data_ov000_021b4c70->mUnk_10 < 3) {
        u = -func_020ae584(0);
    } else {
        u = -func_02128244(data_ov000_021b4c70->mUnk_10 - 3);
    }
    for (i = 0; i < data_ov000_021b0600[2]; i++) {
        data_ov000_021b4c70->mUnk_14[2][1] = u;
    }
    if (data_ov000_021b4c70->mUnk_10 >= 10 && data_ov000_021b4c70->mUnk_10 >= 13 && func_02125f88() != 0 &&
        ((data_ov000_021b4c70->mUnk_28 != 0 && func_02128274() != 0) || func_02128294() != 0) &&
        func_ov000_021806c4() == -1) {
        if (data_ov000_021b4c70->mUnk_20 == 14 && func_ov000_021832f0() == 0) {
            data_ov000_021b4c70->mUnk_04 = 7;
            data_ov000_021b4c70->mUnk_20 = -1;
            func_021266e4(func_020b3f7c(data_ov000_021b4c70->mUnk_105c, 0x76));
            data_ov000_021b4c70->mUnk_10 = 0;
            return;
        }
        if (data_ov000_021b4c70->mUnk_20 == 3 && data_ov000_021b4c70->mUnk_0c == 0 && func_ov000_021832f0() == 0) {
            data_ov000_021b4c70->mUnk_04 = 8;
            data_ov000_021b4c70->mUnk_20 = -1;
            func_021266e4(func_020b3f7c(data_ov000_021b4c70->mUnk_1058, 14));
            data_ov000_021b4c70->mUnk_10 = 0;
            return;
        }
        if (data_ov000_021b4c70->mUnk_20 == 1) {
            void *a;
            void *b;
            void *c;

            data_ov000_021b4c70->mUnk_04 = 9;
            data_ov000_021b4c70->mUnk_10 = 0;
            data_ov000_021b4c70->mUnk_34 = 0;
            a = func_020b3f7c(data_ov000_021b4c70->mUnk_1058, 0x17);
            b = func_020b3f7c(data_ov000_021b4c70->mUnk_105c, 0);
            c = func_020b3f7c(data_ov000_021b4c70->mUnk_105c, 1);
            func_02126454(a, b, c, 0);
            return;
        }
        func_ov000_021806e0(data_ov000_021b4c70->mUnk_20);
    }
}

void func_ov000_021825b8(void) {
    Unk02175628Index v1 = UNK_02175628_INDEX_8;
    s32 a;
    s32 b;
    u16 v;

    if (func_02125f6c() != 0) {
        func_0212ecc0(&data_0217d068, 0, 0x15);
    }
    if (func_02125f88() != 0 && func_02128294() != 0) {
        data_ov000_021b4c70->mUnk_04 = 2;
        func_ov000_02182de8();
        data_ov000_021b4c70->mUnk_08 = 1;
        return;
    }
    if (func_02125fa4() != 0 && func_02128294() != 0) {
        if ((u16) (data_02175628[v1].mUnk_00 & 2) == 0) {
            a = 0;
            b = 0;
            v = data_02175674[v1].mUnk_00;
            if (v == 0 && data_02175680[v1].mUnk_00 < 5) {
                b = 1;
            }
            if (b == 0 && data_0217567c[v1].mUnk_00 == 0 && v != 0) {
                a = 1;
            }
            if (a == 0) {
                return;
            }
            if (func_02128210(data_02175670[v1].mUnk_00, data_02175672[v1].mUnk_00) == 0) {
                return;
            }
        }
        func_02125fc0();
        func_02128310(0);
    }
}

void func_ov000_021824e8(void) {
    Unk02175628Index v1 = UNK_02175628_INDEX_8;
    s32 a;
    s32 b;
    u16 v;

    if (func_02125f6c() != 0) {
        func_0212ecc0(&data_0217d068, 0, 0x15);
    }
    if (func_02125f88() != 0 && func_02128294() != 0) {
        data_ov000_021b4c70->mUnk_04 = 2;
        func_ov000_02182de8();
        data_ov000_021b4c70->mUnk_08 = 1;
        return;
    }
    if (func_02125fa4() != 0 && func_02128294() != 0) {
        if ((u16) (data_02175628[v1].mUnk_00 & 2) == 0) {
            a = 0;
            b = 0;
            v = data_02175674[v1].mUnk_00;
            if (v == 0 && data_02175680[v1].mUnk_00 < 5) {
                b = 1;
            }
            if (b == 0 && data_0217567c[v1].mUnk_00 == 0 && v != 0) {
                a = 1;
            }
            if (a == 0) {
                return;
            }
            if (func_02128210(data_02175670[v1].mUnk_00, data_02175672[v1].mUnk_00) == 0) {
                return;
            }
        }
        func_02125fc0();
        func_02128310(0);
    }
}

void func_ov000_02182474(void) {
    if (func_02125f54() != 0) {
        func_02125fc0();
        return;
    }
    if (func_02125f88() != 0) {
        if (func_02125f60() == 0) {
            data_ov000_021b4c70->mUnk_04 = 10;
            func_02126638(func_020b3f7c(data_ov000_021b4c70->mUnk_1058, 0x18), 1, 1, 1, 0, 1, 0);
            return;
        }
        data_ov000_021b4c70->mUnk_04 = 2;
        func_ov000_02182de8();
        data_ov000_021b4c70->mUnk_08 = 1;
    }
}

void func_ov000_021823e4(void) {
    data_ov000_021b4c70->mUnk_10 = data_ov000_021b4c70->mUnk_10 + 1;
    if (func_02125fa4() != 0 && data_ov000_021b4c70->mUnk_34 == 0) {
        data_ov000_021b4c70->mUnk_34 = 1;
        func_0211fe18();
    }
    if (data_ov000_021b4c70->mUnk_34 != 0 && func_0211fda8() != 0 && data_ov000_021b4c70->mUnk_10 > 90 &&
        func_02125fa4() != 0) {
        void *t;

        data_ov000_021b4c70->mUnk_04 = 11;
        t = func_020b3f7c(data_ov000_021b4c70->mUnk_1058, 0x19);
        func_02126570(t, func_020b3f7c(data_ov000_021b4c70->mUnk_105c, 4));
        data_ov000_021b4c70->mUnk_10 = 0;
    }
}

void func_ov000_021823b0(void) {
    int v1;
    v1 = func_02125f54();
    if (v1 != 0) {
        func_02125fc0();
        return;
    }
    v1 = func_02125f88();
    if (v1 != 0) {
        func_ov000_021806e0((s32) data_ov000_021b4c70->mUnk_20);
    }
}

void func_ov000_02182270(void) {
    s32 i;
    s32 j;
    s32 k;
    s32 v;

    v = data_ov000_021b4c70->mUnk_104c->mUnk_06;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < data_ov000_021b0600[i]; j++) {
            data_ov000_021b4c70->mUnk_103c[data_ov000_021b060c[i][j]].mUnk_04 = data_ov000_021b4c70->mUnk_14[i][0];
            data_ov000_021b4c70->mUnk_103c[data_ov000_021b060c[i][j]].mUnk_06 = data_ov000_021b4c70->mUnk_14[i][1];
        }
    }
    for (i = 0; i < 3; i++) {
        (data_ov000_021b4c70->mUnk_103c + v)[data_ov000_021b05e8[i]].mUnk_04 = data_ov000_021b4c70->mUnk_14[i][0];
        (data_ov000_021b4c70->mUnk_103c + v)[data_ov000_021b05e8[i]].mUnk_06 = data_ov000_021b4c70->mUnk_14[i][1];
    }
    for (k = 0; k < 3; k++) {
        (data_ov000_021b4c70->mUnk_103c + v)[1].mUnk_04 = data_ov000_021b4c70->mUnk_14[1][0];
        (data_ov000_021b4c70->mUnk_103c + v)[1].mUnk_06 = data_ov000_021b4c70->mUnk_14[1][1];
    }
    for (i = 0; i < 3; i++) {
        data_ov000_021b4c70->mUnk_103c[data_ov000_021b05f8[i][0]].mUnk_04 -=
            func_020adc64(6 - data_ov000_021b4c70->mUnk_2c);
        data_ov000_021b4c70->mUnk_103c[data_ov000_021b05f8[i][1]].mUnk_04 +=
            func_020adc64(6 - data_ov000_021b4c70->mUnk_30);
    }
}

void func_ov000_021821e0(void) {
    s32 i;
    s32 z = 0;

    for (i = 0; i < 3; i++) {
        if (i == data_ov000_021b4c70->mUnk_08 && data_ov000_021b4c70->mUnk_24 != 0) {
            data_ov000_021b4c70->mUnk_103c[data_ov000_021b060c[i][1]].mUnk_00 = 1;
            func_02124100(data_ov000_021b05e8[i], 14, data_ov000_021b4c70->mUnk_1054, data_ov000_021b4c70->mUnk_103c,
                          data_ov000_021b4c70->mUnk_104c);
        } else {
            data_ov000_021b4c70->mUnk_103c[data_ov000_021b060c[i][1]].mUnk_00 = z;
            func_02124100(data_ov000_021b05e8[i], 15, data_ov000_021b4c70->mUnk_1054, data_ov000_021b4c70->mUnk_103c,
                          data_ov000_021b4c70->mUnk_104c);
        }
    }
}

void func_ov000_02182150(void) {
    s32 i;
    s32 z = 0;
    s32 y = 0;

    for (i = 0; i < 2; i++) {
        if (data_ov000_021b4c70->mUnk_08 == 1) {
            if ((&data_ov000_021b4c70->mUnk_2c)[i] > 0) {
                data_ov000_021b4c70->mUnk_103c[data_ov000_021b05f8[0][i]].mUnk_00 = 1;
                data_ov000_021b4c70->mUnk_103c[data_ov000_021b05f8[1][i]].mUnk_00 = 1;
                (&data_ov000_021b4c70->mUnk_2c)[i]--;
            } else {
                data_ov000_021b4c70->mUnk_103c[data_ov000_021b05f8[0][i]].mUnk_00 = y;
                data_ov000_021b4c70->mUnk_103c[data_ov000_021b05f8[1][i]].mUnk_00 = 1;
            }
        } else {
            data_ov000_021b4c70->mUnk_103c[data_ov000_021b05f8[0][i]].mUnk_00 = z;
            data_ov000_021b4c70->mUnk_103c[data_ov000_021b05f8[1][i]].mUnk_00 = z;
        }
    }
}

void func_ov000_02182084(void) {
    data_ov000_021b4c70->mUnk_00 = data_ov000_021b4c70->mUnk_04;
    switch (data_ov000_021b4c70->mUnk_00) {
        case 0:
            func_ov000_02182d74();
            break;
        case 1:
            func_ov000_02182d28();
            break;
        case 2:
            func_ov000_02182cb8();
            break;
        case 3:
            func_ov000_02182c60();
            break;
        case 4:
            func_ov000_021828e4();
            break;
        case 5:
            func_ov000_02182878();
            break;
        case 6:
            func_ov000_02182688();
            break;
        case 7:
            func_ov000_021825b8();
            break;
        case 8:
            func_ov000_021824e8();
            break;
        case 9:
            func_ov000_02182474();
            break;
        case 10:
            func_ov000_021823e4();
            break;
        case 11:
            func_ov000_021823b0();
            break;
    }
    func_0212b80c();
    func_ov000_02182270();
    func_ov000_021821e0();
    func_ov000_02182150();
    func_02124c30(data_ov000_021b4c70->mUnk_104c, data_ov000_021b4c70->mUnk_1040, data_ov000_021b4c70->mUnk_1054,
                  func_ov000_021804e0(), data_ov000_021b4c70->mUnk_103c);
}

void func_ov000_02181ff0(void) {
    u32 a;
    u32 b;
    s32 v;

    a = (*(vu32 *) 0x4000000 & 0x1f00) >> 8;
    a |= 4;
    *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffffe0ff) | (a << 8);
    b = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
    b |= 9;
    *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | (b << 8);
    func_0214a40c((u32 *) 0x4000050, 0, 2, 6, 10);
    v = -data_ov000_021b4c70->mUnk_14[1][0];
    if (v <= -256) {
        v = -256;
    }
    if (v >= 0x100) {
        v = 0x100;
    }
    *(vu32 *) 0x400101c = v & 0x1ff;
}

void func_ov000_02181fcc(void) {
    Unk021b0cd4 callbacks = data_ov000_021b0ba0;
    func_ov000_021806ec(&callbacks);
}
