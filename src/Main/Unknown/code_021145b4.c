#include "Main/Unknown/code_021145b4.h"

#include "Main/Unknown/code_02111000.h"
#include "Main/Unknown/code_02111488.h"
#include "Main/Unknown/code_02114158.h"
#include "Main/Unknown/code_02114c98.h"
#include "Main/Unknown/code_02114cb0.h"
#include "Main/Unknown/code_02116244.h"
#include "Main/Unknown/code_02116870.h"
#include "Main/Unknown/code_0211568c.h"
#include "Main/Unknown/code_021156d4.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02125f88.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "00/code_02182fdc.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/code_02114000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_02116084.h"
#include "Main/Unknown/code_0211606c.h"
#include "Main/Unknown/code_02116174.h"
#include "Main/Unknown/code_02116844.h"
#include "code_0212df7c.h"
#include "code_0201ea58.h"
#include "Main/Unknown/unk_0216d000.h"
#include "Main/Unknown/code_02077000.h"
#include "Main/Unknown/code_02116000.h"
#include "Main/Unknown/code_021113f0.h"
#include "Main/Unknown/code_02116888.h"
#include "Main/Unknown/code_02116a4c.h"
#include "Main/Unknown/code_0211621c.h"
#include "Main/Unknown/code_0212426c.h"
#include "Main/Unknown/code_02124000.h"
#include "Main/Unknown/code_02126000.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_02125ed0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "code_02148ca0.h"
#include "Main/Unknown/code_020472a8.h"

#pragma thumb on

u32 func_0211606c(void) {
    if (data_0217d350->mUnk_7c != 0) {
        return 1;
    }
    return 0;
}

#pragma thumb off

#pragma thumb on

void func_02115fd4(void) {
    s32 a;
    s32 b;
    s16 v;

    if (func_0211606c()) {
        if (data_0217d350->mUnk_7c == 7) {
            data_0217d350->mUnk_80 = data_0217d350->mUnk_74;
            func_021162cc();
        } else {
            a = data_0217d350->mUnk_08->mUnk_06;
            b = data_0217d350->mUnk_18->mUnk_06;
            v = func_02116d10(7 - data_0217d350->mUnk_7c, 0);
            data_0217d350->mUnk_64 = v;
            data_0217d350->mUnk_14[3].mUnk_06 = v;
            data_0217d350->mUnk_14[a].mUnk_06 = v;
            data_0217d350->mUnk_24[1].mUnk_06 = v;
            data_0217d350->mUnk_24[b].mUnk_06 = v;
        }
        data_0217d350->mUnk_7c--;
    } else {
        if (data_0217d350->mUnk_74 != 5 && data_0217d350->mUnk_74 != data_0217d350->mUnk_80) {
            data_0217d350->mUnk_7c = 7;
        }
    }
}

void func_02115e74(void) {
    s32 i;
    u16 n;

    i = 0;
    data_0217d350->mUnk_58 = 0;
    data_0217d350->mUnk_5c = 0;
    data_0217d350->mUnk_70 = ~0xbf;
    n = data_0217d350->mUnk_30->mUnk_06;
    data_0217d350->mUnk_3c[30].mUnk_04 = 0x100;
    data_0217d350->mUnk_3c[31].mUnk_04 = 0x100;
    data_0217d350->mUnk_3c[n + 5].mUnk_06 = ~0xbf;
    for (; i < 5; i++) {
        data_0217d350->mUnk_3c[data_0215c4e8[i]].mUnk_04 = 0x100;
        data_0217d350->mUnk_3c[data_0215c4f4[i]].mUnk_04 = 0x100;
        data_0217d350->mUnk_3c[data_0215c500[i]].mUnk_04 = 0x100;
        data_0217d350->mUnk_3c[data_0215c50c[i]].mUnk_04 = 0x100;
        data_0217d350->mUnk_3c[data_0215c518[i]].mUnk_04 = 0x100;
        data_0217d350->mUnk_3c[data_0215c524[i]].mUnk_04 = 0x100;
        data_0217d350->mUnk_3c[n + data_0215c4b8[i]].mUnk_04 = 0x100;
    }
    func_021162cc();
    func_02126138((u32) GetBmgEntry(data_0217d350->mUnk_48, 4), (u32) GetBmgEntry(data_0217d350->mUnk_44, 6), 0, 1, 1,
                  1);
    for (i = 0; i < 2; i++) {
        data_0217d350->mUnk_3c[data_0215c4a8[i]].mUnk_00 = 0;
    }
}

void func_02115e60(void) {
    data_0217d350->mUnk_58 = 1;
    data_0217d350->mUnk_5c = 0;
}

void func_02115e44(void) {
    data_0217d350->mUnk_58 = 2;
    data_0217d350->mUnk_5c = 0;
    func_02125fc0();
}

void func_02115e20(void) {
    data_0217d350->mUnk_58 = 3;
    data_0217d350->mUnk_5c = 0;
    func_02128374();
    func_02116244();
}

void func_02115e0c(void) {
    data_0217d350->mUnk_58 = 4;
    data_0217d350->mUnk_5c = 0;
}

void func_02115df8(void) {
    data_0217d350->mUnk_58 = 5;
    data_0217d350->mUnk_5c = 0;
}

void func_02115dc0(void) {
    data_0217d350->mUnk_58 = 6;
    data_0217d350->mUnk_5c = 0;
    switch (data_0217d350->mUnk_78) {
        case 0:
            func_02116230();
            break;
        case 1:
            func_0211621c();
            break;
    }
    func_02116244();
}

void func_02115d90(void) {
    data_0217d350->mUnk_58 = 7;
    data_0217d350->mUnk_5c = 0;
    func_021282c8();
    func_0212ecc0(&data_0217d068, 0, 5);
}

void func_02115d08(void) {
    u16 buf[0x10];
    u16 buf2[0x100];
    u16 v;

    data_0217d350->mUnk_58 = 8;
    data_0217d350->mUnk_5c = 0;
    v = func_02116870();
    func_02114298((u16) (v + data_0217d350->mUnk_74), buf, 0x20);
    func_0212513c(buf, GetBmgEntry(data_0217d350->mUnk_48, 5), buf2, 0x200);
    func_02125fd4((u32) buf2, (u32) GetBmgEntry(data_0217d350->mUnk_44, 0),
                  (u32) GetBmgEntry(data_0217d350->mUnk_44, 1), 1, 0, 1, 1, 1);
}

void func_02115cec(void) {
    data_0217d350->mUnk_58 = 9;
    data_0217d350->mUnk_5c = 0;
    func_02125ed0(0, 0xb);
}

void func_02115cc4(void) {
    data_0217d350->mUnk_58 = 0xa;
    data_0217d350->mUnk_5c = 0;
    func_02125fc0();
    func_02125ed0(0, 5);
}

void func_02115ca0(void) {
    data_0217d350->mUnk_58 = 0xb;
    data_0217d350->mUnk_5c = 0;
    func_02128374();
    func_02116244();
}

void func_02115c8c(void) {
    data_0217d350->mUnk_58 = 0xc;
    data_0217d350->mUnk_5c = 0;
}

void func_02115728(void *a) {
    s32 v;
    u16 *p;
    s32 w;
    u16 n;
    u16 z;
    s32 j;
    s32 i;
    u32 p0;
    u32 p1;
    u32 p2;
    u32 p3;
    u32 p4;

    *(volatile u16 *) 0x400100e = (*(volatile u16 *) 0x400100e & ~3) | 1;
    *(volatile u16 *) 0x400100a = (*(volatile u16 *) 0x400100a & 0x43) | 0x1018;
    *(volatile u16 *) 0x400100e = (*(volatile u16 *) 0x400100e & 0x43) | 0x9810;
    data_0217d350 = func_02036bec(a, 0xa4);
    data_0217d350->mUnk_50 = a;
    data_0217d350->mUnk_54 = 3;
    data_0217d350->mUnk_76 = func_02111418();
    data_0217d350->mUnk_74 = func_02111408();
    data_0217d350->mUnk_78 = 0;
    data_0217d350->mUnk_7c = 0;
    data_0217d350->mUnk_80 = data_0217d350->mUnk_74;
    data_0217d350->mUnk_40 = 0;
    data_0217d350->mUnk_84 = 0;
    data_0217d350->mUnk_98 = 0;
    data_0217d350->mUnk_9c = 0;
    for (i = 0; i < 2; i++) {
        data_0217d350->mUnk_90[i] = 0;
    }
    func_02077a28(a);
    func_02116888();
    func_02124ed0(a, data_0217d350->mUnk_08, data_0217d350->mUnk_0c, &data_0217d350->mUnk_14);
    func_02124ed0(a, data_0217d350->mUnk_18, data_0217d350->mUnk_1c, &data_0217d350->mUnk_24);
    func_02124ed0(a, data_0217d350->mUnk_30, data_0217d350->mUnk_38, &data_0217d350->mUnk_3c);
    data_0217d350->mUnk_44 = func_02047a28(data_0216d4a4);
    data_0217d350->mUnk_48 = FindSceneFile(data_0216d4b0);
    v = 0x8000;
    v -= func_021243ac(a, 0, data_0217d350->mUnk_0c, 0x8c, 0x10, 0, data_0217d350->mUnk_04, data_0217d350->mUnk_08,
                       data_0217d350->mUnk_14, v);
    v -= func_021243ac(a, 1, data_0217d350->mUnk_0c, 0xaa, 0xe, 1, data_0217d350->mUnk_04, data_0217d350->mUnk_08,
                       data_0217d350->mUnk_14, v);
    func_0212426c(0, 1, data_0217d350->mUnk_0c, GetBmgEntry(data_0217d350->mUnk_48, 0), data_0217d350->mUnk_08,
                  data_0217d350->mUnk_14);
    v -= func_021243ac(a, 0xb, data_0217d350->mUnk_0c, 0x96, 0xe, 2, data_0217d350->mUnk_04, data_0217d350->mUnk_08,
                       data_0217d350->mUnk_14, v);
    func_0212426c(0, 0xb, data_0217d350->mUnk_0c, GetBmgEntry(data_0217d350->mUnk_48, 1), data_0217d350->mUnk_08,
                  data_0217d350->mUnk_14);
    v -= func_021243ac(a, 0xc, data_0217d350->mUnk_0c, 0x46, 0x10, 3, data_0217d350->mUnk_04, data_0217d350->mUnk_08,
                       data_0217d350->mUnk_14, v);
    z = 4;
    n = data_0217d350->mUnk_08->mUnk_06;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            v -= func_021243ac(a, data_0215c530[i][j], data_0217d350->mUnk_0c, data_0215c544[i][j], data_0215c558[i][j],
                               z, data_0217d350->mUnk_04, data_0217d350->mUnk_08, data_0217d350->mUnk_14, v);
            z = (u16) (n + data_0215c530[i][j]);
        }
    }
    for (i = 0; i < 3; i++) {
        func_0212426c(0, data_0215c530[0][i], data_0217d350->mUnk_0c,
                      GetBmgEntry(data_0217d350->mUnk_48, data_0215c4b0[i]), data_0217d350->mUnk_08,
                      data_0217d350->mUnk_14);
    }
    v -= func_021243ac(a, 0, data_0217d350->mUnk_1c, 0x8c, 0x10, 0, data_0217d350->mUnk_04, data_0217d350->mUnk_18,
                       data_0217d350->mUnk_24, v);
    v -= func_021243ac(a, 1, data_0217d350->mUnk_1c, 0x70, 0x10, 1, data_0217d350->mUnk_04, data_0217d350->mUnk_18,
                       data_0217d350->mUnk_24, v);
    func_0212426c(0, 1, data_0217d350->mUnk_1c, GetBmgEntry(data_0217d350->mUnk_48, 0xb), data_0217d350->mUnk_18,
                  data_0217d350->mUnk_24);
    v -= func_021243ac(a, 0xe, data_0217d350->mUnk_1c, 0xe0, 0x38, 2, data_0217d350->mUnk_04, data_0217d350->mUnk_18,
                       data_0217d350->mUnk_24, v);
    func_0212426c(0, 0xe, data_0217d350->mUnk_1c, GetBmgEntry(data_0217d350->mUnk_48, 0xc), data_0217d350->mUnk_18,
                  data_0217d350->mUnk_24);
    for (i = 0; i < 12; i++) {
        v -= func_021243ac(a, data_0215c584[i], data_0217d350->mUnk_1c, data_0215c59c[i], data_0215c56c[i], i + 3,
                           data_0217d350->mUnk_04, data_0217d350->mUnk_18, data_0217d350->mUnk_24, v);
    }
    w = func_02148ca0();
    for (i = 0, p = data_0215c50c; i < 5; i++) {
        w -= func_021243ac(a, data_0215c4b8[i], data_0217d350->mUnk_38, data_0215c4c4[i], data_0215c4dc[i], *p,
                           data_0217d350->mUnk_2c, data_0217d350->mUnk_30, data_0217d350->mUnk_3c, w);
        p++;
    }
    func_021243ac(a, 5, data_0217d350->mUnk_38, 0xfa, 0x10, 5, data_0217d350->mUnk_2c, data_0217d350->mUnk_30,
                  data_0217d350->mUnk_3c, w);
    func_0212426c(1, 5, data_0217d350->mUnk_38, GetBmgEntry(data_0217d350->mUnk_48, 2), data_0217d350->mUnk_30,
                  data_0217d350->mUnk_3c);
    p0 = 0;
    p1 = 0;
    p2 = 0;
    p3 = 0;
    p4 = 0;
    for (i = 0; i < 5; i++) {
        func_02124a98(data_0215c4e8[i], p0, data_0217d350->mUnk_2c, data_0217d350->mUnk_30);
        func_02124a98(data_0215c4f4[i], p1, data_0217d350->mUnk_2c, data_0217d350->mUnk_30);
        func_02124a98(data_0215c500[i], p2, data_0217d350->mUnk_2c, data_0217d350->mUnk_30);
        func_02124a98(data_0215c50c[i], p3, data_0217d350->mUnk_2c, data_0217d350->mUnk_30);
        func_02124140(data_0215c4b8[i], p4, data_0217d350->mUnk_38, data_0217d350->mUnk_3c, data_0217d350->mUnk_30);
    }
    func_02124140(5, 0, data_0217d350->mUnk_38, data_0217d350->mUnk_3c, data_0217d350->mUnk_30);
    data_0217d350->mUnk_88 = func_02036bec(a, 0x201);
    data_0217d350->mUnk_8c = func_02036bec(a, 0x200);
    func_02115e74();
}

void func_021156d4(void) {
    u32 v;

    func_021113fc(data_0217d350->mUnk_76);
    func_021113f0(data_0217d350->mUnk_74);
    data_0217d350 = NULL;
    v = (*(volatile u32 *) 0x4001000 & 0x1f00) >> 8;
    v &= ~9;
    *(volatile u32 *) 0x4001000 = (*(volatile u32 *) 0x4001000 & 0xffffe0ff) | (v << 8);
}

#pragma thumb off

#pragma thumb on

void func_021156bc(void) {
    int v1;
    v1 = func_02125fa4();
    if (v1 != 0) {
        func_02115e60();
    }
}

void func_021156a4(void) {
    int v1;
    v1 = func_02125f54();
    if (v1 != 0) {
        func_02115e44();
    }
}

void func_0211568c(void) {
    int v1;
    v1 = func_02125f88();
    if (v1 != 0) {
        func_02115e20();
    }
}

#pragma thumb off

#pragma thumb on

void func_0211553c(void) {
    s16 v;
    u32 w;
    u16 n;
    s32 i;

    func_02116084();
    data_0217d350->mUnk_5c++;
    v = func_020ae4c0(1, 0x100, 0, data_0217d350->mUnk_5c, 0xa);
    w = func_020ae4c0(1, ~0xbf, 0, data_0217d350->mUnk_5c, 0xa);
    n = data_0217d350->mUnk_30->mUnk_06;
    data_0217d350->mUnk_70 = w;
    data_0217d350->mUnk_3c[30].mUnk_04 = v;
    data_0217d350->mUnk_3c[31].mUnk_04 = v;
    data_0217d350->mUnk_3c[n + 5].mUnk_06 = w;
    for (i = 0; i < 5; i++) {
        data_0217d350->mUnk_3c[data_0215c4e8[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c4f4[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c500[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c50c[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c518[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c524[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[n + data_0215c4b8[i]].mUnk_04 = v;
    }
    if (data_0217d350->mUnk_5c >= 0xa) {
        if (func_02128294() != 0) {
            func_02115e0c();
        }
    }
}

void func_02115204(void) {
    s32 s;
    s32 v;
    u32 w;
    Unk02175628Index i;
    BOOL n;

    v = -1;
    w = v;
    i = UNK_02175628_INDEX_8;
    func_02116084();
    func_02115fd4();
    s = func_02116870();
    n = (data_02175674[i].mUnk_00 == 0 && data_02175680[i].mUnk_00 < 5) || data_02175674[i].mUnk_00 != 0;
    if (n) {
        v = func_0201ea84(data_0217d350->mUnk_34, data_02175670[i].mUnk_00, data_02175672[i].mUnk_00);
    }
    n = !(data_02175674[i].mUnk_00 == 0 && data_02175680[i].mUnk_00 < 5) &&
        (data_0217567c[i].mUnk_00 == 0 && data_02175674[i].mUnk_00 != 0);
    if (n) {
        w = func_0201ea84(data_0217d350->mUnk_34, data_02175670[i].mUnk_00, data_02175672[i].mUnk_00);
    }
    if (v != 5) {
        data_0217d350->mUnk_98 = 0;
    }
    if (v != 6) {
        data_0217d350->mUnk_9c = 0;
    }
    if ((u16) (data_02175628[i].mUnk_00 & 2) != 0 ||
        ((n = !(data_02175674[i].mUnk_00 == 0 && data_02175680[i].mUnk_00 < 5) &&
              (data_0217567c[i].mUnk_00 == 0 && data_02175674[i].mUnk_00 != 0)) &&
         func_02128210(data_02175670[i].mUnk_00, data_02175672[i].mUnk_00) != 0)) {
        if (func_0211606c() != 0) {
            return;
        }
        func_02115c8c();
        data_0217d350->mUnk_a0 = 3;
        func_02128310(0);
        return;
    }
    if ((v == 5 && data_0217d350->mUnk_98 != 0) || (w == 5 && data_0217d350->mUnk_98 == 0) ||
        (u16) (data_0217562a[i].mUnk_00 & 0x20) != 0) {
        if (func_0211606c() != 0) {
            return;
        }
        if (data_0217d350->mUnk_3c[30].mUnk_00 == 0) {
            return;
        }
        data_0217d350->mUnk_78 = 1;
        data_0217d350->mUnk_90[0] = 6;
        data_0217d350->mUnk_98 = 1;
        func_02115df8();
        func_0212ecc0(&data_0217d068, 0, 2);
        return;
    }
    if ((v == 6 && data_0217d350->mUnk_9c != 0) || (w == 6 && data_0217d350->mUnk_9c == 0) ||
        (u16) (data_0217562a[i].mUnk_00 & 0x10) != 0) {
        if (func_0211606c() != 0) {
            return;
        }
        if (data_0217d350->mUnk_3c[31].mUnk_00 == 0) {
            return;
        }
        data_0217d350->mUnk_78 = 0;
        data_0217d350->mUnk_90[1] = 6;
        data_0217d350->mUnk_9c = 1;
        func_02115df8();
        func_0212ecc0(&data_0217d068, 0, 2);
        return;
    }
    if (w <= 4) {
        i = (Unk02175628Index) data_0215c4d0[w];
        if (i == data_0217d350->mUnk_74) {
            if (func_02114398(s + i) == 0) {
                if (func_0211606c() == 0) {
                    func_02115d90();
                }
                return;
            }
            if (func_0211606c() == 0) {
                func_0212ecc0(&data_0217d068, 0, 0x16);
            }
            return;
        }
        if (func_02116844(i) != 0) {
            data_0217d350->mUnk_74 = i;
            func_0212ecc0(&data_0217d068, 0, 0);
        }
    } else {
        if ((u16) (data_02175628[i].mUnk_00 & 1) != 0) {
            if (func_02114398(s + data_0217d350->mUnk_74) == 0) {
                if (func_0211606c() == 0) {
                    func_02115d90();
                }
                return;
            }
            if (func_0211606c() == 0) {
                func_0212ecc0(&data_0217d068, 0, 0x16);
            }
            return;
        }
        if (func_020ae408(8, 0x40) != 0) {
            func_02116174();
            return;
        }
        if (func_020ae408(8, 0x80) != 0) {
            func_021161d0();
        }
    }
}

void func_02115000(void) {
    s16 k;
    u16 a;
    s32 i;
    u16 b;
    u16 c;
    s32 j;
    s16 v;

    k = 0;
    func_02116084();
    switch (data_0217d350->mUnk_78) {
        case 0:
            k = ~0xff;
            break;
        case 1:
            k = 0x100;
            break;
    }
    data_0217d350->mUnk_5c++;
    a = data_0217d350->mUnk_08->mUnk_06;
    b = data_0217d350->mUnk_18->mUnk_06;
    c = data_0217d350->mUnk_30->mUnk_06;
    v = func_020ae4c0(1, 0, k, data_0217d350->mUnk_5c, 0xa);
    data_0217d350->mUnk_60 = v;
    data_0217d350->mUnk_68 = v;
    data_0217d350->mUnk_14[1].mUnk_04 = v;
    data_0217d350->mUnk_14[2].mUnk_04 = v;
    data_0217d350->mUnk_14[3].mUnk_04 = v;
    data_0217d350->mUnk_14[a].mUnk_04 = v;
    data_0217d350->mUnk_14[a + 1].mUnk_04 = v;
    data_0217d350->mUnk_14[a + 0xb].mUnk_04 = v;
    data_0217d350->mUnk_14[a + 0xc].mUnk_04 = v;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            data_0217d350->mUnk_14[a + data_0215c530[i][j]].mUnk_04 = v;
        }
    }
    data_0217d350->mUnk_24[1].mUnk_04 = v;
    data_0217d350->mUnk_24[b].mUnk_04 = v;
    data_0217d350->mUnk_24[b + 1].mUnk_04 = v;
    data_0217d350->mUnk_24[b + 0xe].mUnk_04 = v;
    for (i = 0; i < 0xc; i++) {
        data_0217d350->mUnk_24[b + data_0215c584[i]].mUnk_04 = v;
    }
    for (i = 0; i < 5; i++) {
        data_0217d350->mUnk_3c[data_0215c4e8[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c4f4[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c500[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c50c[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c518[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c524[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[c + data_0215c4b8[i]].mUnk_04 = v;
    }
    if (data_0217d350->mUnk_5c >= 0xa) {
        func_02115dc0();
    }
}

void func_02114dfc(void) {
    s16 k;
    u16 a;
    s32 i;
    u16 b;
    u16 c;
    s32 j;
    s16 v;

    k = 0;
    func_02116084();
    switch (data_0217d350->mUnk_78) {
        case 0:
            k = 0x100;
            break;
        case 1:
            k = ~0xff;
            break;
    }
    data_0217d350->mUnk_5c++;
    a = data_0217d350->mUnk_08->mUnk_06;
    b = data_0217d350->mUnk_18->mUnk_06;
    c = data_0217d350->mUnk_30->mUnk_06;
    v = func_020ae4c0(1, k, 0, data_0217d350->mUnk_5c, 0xa);
    data_0217d350->mUnk_60 = v;
    data_0217d350->mUnk_68 = v;
    data_0217d350->mUnk_14[1].mUnk_04 = v;
    data_0217d350->mUnk_14[2].mUnk_04 = v;
    data_0217d350->mUnk_14[3].mUnk_04 = v;
    data_0217d350->mUnk_14[a].mUnk_04 = v;
    data_0217d350->mUnk_14[a + 1].mUnk_04 = v;
    data_0217d350->mUnk_14[a + 0xb].mUnk_04 = v;
    data_0217d350->mUnk_14[a + 0xc].mUnk_04 = v;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            data_0217d350->mUnk_14[a + data_0215c530[i][j]].mUnk_04 = v;
        }
    }
    data_0217d350->mUnk_24[1].mUnk_04 = v;
    data_0217d350->mUnk_24[b].mUnk_04 = v;
    data_0217d350->mUnk_24[b + 1].mUnk_04 = v;
    data_0217d350->mUnk_24[b + 0xe].mUnk_04 = v;
    for (i = 0; i < 0xc; i++) {
        data_0217d350->mUnk_24[b + data_0215c584[i]].mUnk_04 = v;
    }
    for (i = 0; i < 5; i++) {
        data_0217d350->mUnk_3c[data_0215c4e8[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c4f4[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c500[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c50c[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c518[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c524[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[c + data_0215c4b8[i]].mUnk_04 = v;
    }
    if (data_0217d350->mUnk_5c >= 0xa) {
        func_02115e0c();
    }
}

void func_02114cb0(void) {
    s16 v;
    u32 w;
    u16 n;
    s32 i;

    data_0217d350->mUnk_5c++;
    v = func_020ae4c0(1, 0, 0x100, data_0217d350->mUnk_5c, 0xa);
    w = func_020ae4c0(1, 0, ~0xbf, data_0217d350->mUnk_5c, 0xa);
    n = data_0217d350->mUnk_30->mUnk_06;
    data_0217d350->mUnk_70 = w;
    data_0217d350->mUnk_3c[30].mUnk_04 = v;
    data_0217d350->mUnk_3c[31].mUnk_04 = v;
    data_0217d350->mUnk_3c[n + 5].mUnk_06 = w;
    for (i = 0; i < 5; i++) {
        data_0217d350->mUnk_3c[data_0215c4e8[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c4f4[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c500[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c50c[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c518[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[data_0215c524[i]].mUnk_04 = v;
        data_0217d350->mUnk_3c[n + data_0215c4b8[i]].mUnk_04 = v;
    }
    if (data_0217d350->mUnk_5c > 0xa) {
        if (func_02128274() != 0) {
            func_02115d08();
        }
    }
}

#pragma thumb off

#pragma thumb on

void func_02114c98(void) {
    int v1;
    v1 = func_02125fa4();
    if (v1 != 0) {
        func_02115cec();
    }
}

#pragma thumb off

#pragma thumb on

void func_02114c48(void) {
    u16 a;

    a = func_02116870();
    if (func_02125f54()) {
        if (func_02125f60() == 0) {
            func_02114174(a + data_0217d350->mUnk_74);
            data_0217d350->mUnk_84 = 1;
        } else {
            data_0217d350->mUnk_84 = 0;
        }
        func_02115cc4();
    }
}

void func_02114ad8(void) {
    s32 i;
    s32 j;
    s16 a;
    u16 x;
    u16 y;
    u16 v;

    data_0217d350->mUnk_5c++;
    a = func_020ae4c0(1, 0, -0x100, data_0217d350->mUnk_5c, 10);
    x = data_0217d350->mUnk_08->mUnk_06;
    y = data_0217d350->mUnk_18->mUnk_06;
    if (func_021143b4() != 0 && data_0217d350->mUnk_84 != 0) {
        data_0217d350->mUnk_68 = a;
        data_0217d350->mUnk_14[1].mUnk_04 = a;
        data_0217d350->mUnk_14[2].mUnk_04 = a;
        data_0217d350->mUnk_14[3].mUnk_04 = a;
        data_0217d350->mUnk_14[x].mUnk_04 = a;
        data_0217d350->mUnk_14[x + 1].mUnk_04 = a;
        data_0217d350->mUnk_14[x + 0xb].mUnk_04 = a;
        data_0217d350->mUnk_14[x + 0xc].mUnk_04 = a;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                data_0217d350->mUnk_14[x + data_0215c530[i][j]].mUnk_04 = a;
            }
        }
        data_0217d350->mUnk_24[1].mUnk_04 = a;
        data_0217d350->mUnk_24[y].mUnk_04 = a;
        data_0217d350->mUnk_24[y + 1].mUnk_04 = a;
        data_0217d350->mUnk_24[y + 0xe].mUnk_04 = a;
        for (i = 0; i < 12; i++) {
            data_0217d350->mUnk_24[y + data_0215c584[i]].mUnk_04 = a;
        }
    }
    if (func_02125f88()) {
        v = func_02116870();
        if (func_021143b4() <= v) {
            data_0217d350->mUnk_76--;
        }
        if (data_0217d350->mUnk_76 < 0) {
            data_0217d350->mUnk_a0 = 3;
            func_02111488(data_0217d350->mUnk_a0);
        } else {
            func_02115ca0();
        }
    }
}

void func_0211489c(void) {
    s32 i;
    s32 j;
    s16 a;
    s16 b;
    u16 x;
    u16 y;
    u16 z;

    data_0217d350->mUnk_5c++;
    a = func_020ae4c0(1, 0x100, 0, data_0217d350->mUnk_5c, 10);
    b = func_020ae4c0(1, -0xc0, 0, data_0217d350->mUnk_5c, 10);
    x = data_0217d350->mUnk_08->mUnk_06;
    y = data_0217d350->mUnk_18->mUnk_06;
    z = data_0217d350->mUnk_30->mUnk_06;
    if (data_0217d350->mUnk_84 != 0) {
        data_0217d350->mUnk_68 = a;
        data_0217d350->mUnk_14[1].mUnk_04 = a;
        data_0217d350->mUnk_14[2].mUnk_04 = a;
        data_0217d350->mUnk_14[3].mUnk_04 = a;
        data_0217d350->mUnk_14[x].mUnk_04 = a;
        data_0217d350->mUnk_14[x + 1].mUnk_04 = a;
        data_0217d350->mUnk_14[x + 0xb].mUnk_04 = a;
        data_0217d350->mUnk_14[x + 0xc].mUnk_04 = a;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                data_0217d350->mUnk_14[x + data_0215c530[i][j]].mUnk_04 = a;
            }
        }
        data_0217d350->mUnk_24[1].mUnk_04 = a;
        data_0217d350->mUnk_24[y].mUnk_04 = a;
        data_0217d350->mUnk_24[y + 1].mUnk_04 = a;
        data_0217d350->mUnk_24[y + 0xe].mUnk_04 = a;
        for (i = 0; i < 12; i++) {
            data_0217d350->mUnk_24[y + data_0215c584[i]].mUnk_04 = a;
        }
    }
    data_0217d350->mUnk_70 = b;
    data_0217d350->mUnk_3c[30].mUnk_04 = a;
    data_0217d350->mUnk_3c[31].mUnk_04 = a;
    data_0217d350->mUnk_3c[z + 5].mUnk_06 = b;
    for (i = 0; i < 5; i++) {
        data_0217d350->mUnk_3c[data_0215c4e8[i]].mUnk_04 = a;
        data_0217d350->mUnk_3c[data_0215c4f4[i]].mUnk_04 = a;
        data_0217d350->mUnk_3c[data_0215c500[i]].mUnk_04 = a;
        data_0217d350->mUnk_3c[data_0215c50c[i]].mUnk_04 = a;
        data_0217d350->mUnk_3c[data_0215c518[i]].mUnk_04 = a;
        data_0217d350->mUnk_3c[data_0215c524[i]].mUnk_04 = a;
        data_0217d350->mUnk_3c[z + data_0215c4b8[i]].mUnk_04 = a;
    }
    if (data_0217d350->mUnk_5c > 10) {
        if (func_02128294()) {
            func_02115e0c();
        }
    }
}

void func_02114754(void) {
    s32 i;
    s16 a;
    s16 b;
    u16 z;

    data_0217d350->mUnk_5c++;
    a = func_020ae4c0(1, 0, 0x100, data_0217d350->mUnk_5c, 10);
    b = func_020ae4c0(1, 0, -0xc0, data_0217d350->mUnk_5c, 10);
    z = data_0217d350->mUnk_30->mUnk_06;
    data_0217d350->mUnk_70 = b;
    data_0217d350->mUnk_3c[30].mUnk_04 = a;
    data_0217d350->mUnk_3c[31].mUnk_04 = a;
    data_0217d350->mUnk_3c[z + 5].mUnk_06 = b;
    for (i = 0; i < 5; i++) {
        data_0217d350->mUnk_3c[data_0215c4e8[i]].mUnk_04 = a;
        data_0217d350->mUnk_3c[data_0215c4f4[i]].mUnk_04 = a;
        data_0217d350->mUnk_3c[data_0215c500[i]].mUnk_04 = a;
        data_0217d350->mUnk_3c[data_0215c50c[i]].mUnk_04 = a;
        data_0217d350->mUnk_3c[data_0215c518[i]].mUnk_04 = a;
        data_0217d350->mUnk_3c[data_0215c524[i]].mUnk_04 = a;
        data_0217d350->mUnk_3c[z + data_0215c4b8[i]].mUnk_04 = a;
    }
    if (data_0217d350->mUnk_5c >= 10) {
        func_02111488(data_0217d350->mUnk_a0);
    }
}

void func_02114668(void) {
    data_0217d350->mUnk_54 = data_0217d350->mUnk_58;
    switch (data_0217d350->mUnk_54) {
        case 0:
            func_021156bc();
            break;
        case 1:
            func_021156a4();
            break;
        case 2:
            func_0211568c();
            break;
        case 3:
            func_0211553c();
            break;
        case 4:
            func_02115204();
            break;
        case 5:
            func_02115000();
            break;
        case 6:
            func_02114dfc();
            break;
        case 7:
            func_02114cb0();
            break;
        case 8:
            func_02114c98();
            break;
        case 9:
            func_02114c48();
            break;
        case 10:
            func_02114ad8();
            break;
        case 11:
            func_0211489c();
            break;
        case 12:
            func_02114754();
            break;
    }
    func_02116624();
    switch (data_0217d350->mUnk_40) {
        case 0:
            func_02124c30(data_0217d350->mUnk_08, data_0217d350->mUnk_04, data_0217d350->mUnk_0c, func_02111318(),
                          data_0217d350->mUnk_14);
            break;
        case 1:
            func_02124c30(data_0217d350->mUnk_18, data_0217d350->mUnk_04, data_0217d350->mUnk_1c, func_02111318(),
                          data_0217d350->mUnk_24);
            break;
    }
    func_02124c30(data_0217d350->mUnk_30, data_0217d350->mUnk_2c, data_0217d350->mUnk_38, func_0211130c(),
                  data_0217d350->mUnk_3c);
}

void func_02114604(void) {
    *(vu32 *) 0x4000010 = (-data_0217d350->mUnk_60 & 0x1ff) | ((-data_0217d350->mUnk_64 << 16) & 0x1ff0000);
    *(vu32 *) 0x4000014 = (-data_0217d350->mUnk_68 & 0x1ff) | ((-data_0217d350->mUnk_6c << 16) & 0x1ff0000);
    *(vu32 *) 0x400101c = (-data_0217d350->mUnk_70 << 16) & 0x1ff0000;
    func_02111428();
}

void func_021145dc(void) {
    u32 a;

    a = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
    *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & ~0x1f00) | ((a | 9) << 8);
}

void func_021145b4(void) {
    void (*a[5])() = {func_02115728, func_021156d4, func_02114668, func_02114604, func_021145dc};

    func_02111494(a);
}

#pragma thumb off
