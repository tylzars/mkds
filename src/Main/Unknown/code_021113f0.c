#include "Main/Unknown/code_021113f0.h"

#include "Main/Unknown/code_02111428.h"
#include "Main/Unknown/code_021114cc.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_02111450.h"
#include "Main/Unknown/code_02111488.h"
#include "Main/Unknown/code_02111494.h"
#include "Main/Unknown/code_021114b0.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02111a98.h"
#include "Main/Unknown/code_02114158.h"
#include "Main/Unknown/code_021145b4.h"
#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/code_0212a000.h"
#include "01/code_0219a050.h"
#include "Main/Unknown/code_02111584.h"
#include "Main/Unknown/code_021115b0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0211130c.h"
#include "Main/Unknown/code_02111684.h"
#include "Main/Unknown/code_021144c0.h"
#include "Main/Unknown/code_02125000.h"
#include "01/code_02198854.h"
#include "Main/Unknown/code_02111b40.h"
#include "Main/Unknown/code_02111b94.h"
#include "Main/Unknown/code_02112b48.h"
#include "registers.h"
#include "code_0201ea58.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_021128b4.h"
#include "Main/Unknown/code_021128cc.h"
#include "Main/Unknown/code_02112b30.h"
#include "Main/Unknown/code_021137a8.h"
#include "Main/Unknown/code_021138e4.h"
#include "Main/Unknown/code_021139b4.h"
#include "Main/Unknown/code_02113790.h"
#include "Main/Unknown/code_02113ef0.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217d068.h"
#include "00/code_02182fdc.h"
#include "01/code_02193c5c.h"
#include "01/code_021956dc.h"

#pragma thumb on

void func_02112b30(void) {
    int v1;
    v1 = func_02036c5c();
    if (v1 != 0) {
        func_021134b8();
    }
}

#pragma thumb off

#pragma thumb on

void func_02112a0c(void) {
    u16 b;
    u16 a;
    s32 i;
    s32 j;
    s16 v;
    gRecordVS->mUnk_54 = gRecordVS->mUnk_54 + 1;
    v = func_020ae4c0(1, -192, 0, gRecordVS->mUnk_54, 10);
    gRecordVS->mUnk_5c = v;
    gRecordVS->mUnk_64 = v;
    a = gRecordVS->mUnk_08->mUnk_06;
    gRecordVS->mUnk_14[0].mUnk_06 = v;
    gRecordVS->mUnk_14[1].mUnk_06 = v;
    gRecordVS->mUnk_14[2].mUnk_06 = v;
    gRecordVS->mUnk_14[3].mUnk_06 = v;
    gRecordVS->mUnk_14[a].mUnk_06 = v;
    gRecordVS->mUnk_14[a + 1].mUnk_06 = v;
    gRecordVS->mUnk_14[a + 11].mUnk_06 = v;
    gRecordVS->mUnk_14[a + 12].mUnk_06 = v;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            gRecordVS->mUnk_14[a + data_0215c410[i][j]].mUnk_06 = v;
        }
    }
    b = gRecordVS->mUnk_18->mUnk_06;
    gRecordVS->mUnk_24[1].mUnk_06 = v;
    gRecordVS->mUnk_24[0].mUnk_06 = v;
    gRecordVS->mUnk_24[b].mUnk_06 = v;
    gRecordVS->mUnk_24[b + 1].mUnk_06 = v;
    gRecordVS->mUnk_24[b + 14].mUnk_06 = v;
    for (j = 0; j < 12; j++) {
        gRecordVS->mUnk_24[b + data_0215c478[j]].mUnk_06 = v;
    }
    if (gRecordVS->mUnk_54 >= 10) {
        func_0211349c();
    }
}

void func_021128cc(void) {
    s16 v;
    s32 i;
    u16 x;
    func_021137f4();
    gRecordVS->mUnk_54 = gRecordVS->mUnk_54 + 1;
    v = func_020ae4c0(1, 0x100, 0, gRecordVS->mUnk_54, 10);
    x = gRecordVS->mUnk_30->mUnk_06;
    gRecordVS->mUnk_3c[20].mUnk_04 = v;
    gRecordVS->mUnk_3c[21].mUnk_04 = v;
    gRecordVS->mUnk_3c[24].mUnk_04 = v;
    gRecordVS->mUnk_3c[25].mUnk_04 = v;
    gRecordVS->mUnk_3c[26].mUnk_04 = v;
    gRecordVS->mUnk_3c[x + 5].mUnk_04 = v;
    for (i = 0; i < 5; i++) {
        gRecordVS->mUnk_3c[data_0215c3e0[i]].mUnk_04 = v;
        gRecordVS->mUnk_3c[data_0215c3ec[i]].mUnk_04 = v;
        gRecordVS->mUnk_3c[data_0215c3f8[i]].mUnk_04 = v;
        gRecordVS->mUnk_3c[data_0215c404[i]].mUnk_04 = v;
        gRecordVS->mUnk_3c[x + data_0215c3bc[i]].mUnk_04 = v;
    }
    if (gRecordVS->mUnk_54 >= 10) {
        func_02113480();
    }
    if (gRecordVS->mUnk_54 == 4) {
        gRecordVS->mUnk_3c[24].mUnk_00 = 1;
        gRecordVS->mUnk_3c[25].mUnk_00 = 0;
    }
}

#pragma thumb off

#pragma thumb on

void func_021128b4(void) {
    int v1;
    v1 = func_02128294();
    if (v1 != 0) {
        func_0211346c();
    }
}

#pragma thumb off

#pragma thumb on

void func_0211256c(void) {
    s32 a;
    s32 b;
    Unk02175628Index i;
    s32 g;
    s32 f;
    u16 x;
    Unk02175628 *p;
    Unk02175628 *q;
    s16 t;
    a = -1;
    b = -1;
    i = UNK_02175628_INDEX_8;
    func_021137f4();
    func_021136f8();
    g = 1;
    f = 0;
    p = &data_02175674[i];
    x = data_02175674[i].mUnk_00;
    if (x == 0 && data_02175680[i].mUnk_00 < 5) {
        f = 1;
    }
    if (f == 0 && x == 0) {
        g = 0;
    }
    if (g != 0) {
        a = func_0201ea84(gRecordVS->mUnk_34, data_02175670[i].mUnk_00, data_02175672[i].mUnk_00);
    }
    g = 0;
    f = 0;
    x = p->mUnk_00;
    if (x == 0 && data_02175680[i].mUnk_00 < 5) {
        f = 1;
    }
    if (f == 0 && data_0217567c[i].mUnk_00 == 0 && x != 0) {
        g = 1;
    }
    if (g != 0) {
        b = func_0201ea84(gRecordVS->mUnk_34, data_02175670[i].mUnk_00, data_02175672[i].mUnk_00);
    }
    if (a != 10) {
        gRecordVS->mUnk_88 = 0;
    }
    if (a != 11) {
        gRecordVS->mUnk_8c = 0;
    }
    q = &data_02175628[i];
    if ((u16) (data_02175628[i].mUnk_00 & 2) == 0) {
        g = 0;
        f = 0;
        x = p->mUnk_00;
        if (x == 0 && data_02175680[i].mUnk_00 < 5) {
            f = 1;
        }
        if (f == 0 && data_0217567c[i].mUnk_00 == 0 && x != 0) {
            g = 1;
        }
        if (g == 0 || func_02128210(data_02175670[i].mUnk_00, data_02175672[i].mUnk_00) == 0) {
            goto l1;
        }
    }
    if (func_02113790() != 0) {
        return;
    }
    func_0211340c();
    if (func_0211146c() == 12) {
        gRecordVS->mUnk_90 = 6;
        func_02128310(1);
        return;
    }
    gRecordVS->mUnk_90 = 0;
    func_02128310(0);
    return;
l1:
    if ((a == 10 && gRecordVS->mUnk_88 != 0) || (b == 10 && gRecordVS->mUnk_88 == 0) ||
        (u16) (data_0217562a[i].mUnk_00 & 0x20) != 0) {
        if (func_02113790() != 0) {
            return;
        }
        if (gRecordVS->mUnk_3c[20].mUnk_00 == 0) {
            return;
        }
        gRecordVS->mUnk_6c = 1;
        gRecordVS->mUnk_80[0] = 6;
        gRecordVS->mUnk_88 = 1;
        func_02113458();
        func_0212ecc0(&data_0217d068, 0, 2);
        return;
    }
    if ((a == 11 && gRecordVS->mUnk_8c != 0) || (b == 11 && gRecordVS->mUnk_8c == 0) ||
        (u16) (data_0217562a[i].mUnk_00 & 0x10) != 0) {
        if (func_02113790() != 0) {
            return;
        }
        if (gRecordVS->mUnk_3c[21].mUnk_00 == 0) {
            return;
        }
        gRecordVS->mUnk_6c = 0;
        gRecordVS->mUnk_80[1] = 6;
        gRecordVS->mUnk_8c = 1;
        func_02113458();
        func_0212ecc0(&data_0217d068, 0, 2);
        return;
    }
    if ((u32) (b - 5) <= 4) {
        t = data_0215c44c[b];
        if (func_02113ef0(t) == 0) {
            return;
        }
        gRecordVS->mUnk_68 = t;
        func_021137a8(t);
        return;
    }
    if ((u32) b <= 4) {
        t = data_0215c44c[b];
        if (t == gRecordVS->mUnk_68) {
            func_021137a8(t);
            return;
        }
        if (func_02113ef0(t) == 0) {
            return;
        }
        gRecordVS->mUnk_68 = t;
        func_0212ecc0(&data_0217d068, 0, 0);
        return;
    }
    if (b == 12 || (u16) (q->mUnk_00 & 0x400) != 0) {
        func_021132b4();
        gRecordVS->mUnk_90 = 4;
        return;
    }
    if ((u16) (q->mUnk_00 & 1) != 0) {
        func_021137a8(gRecordVS->mUnk_68);
        return;
    }
    if (func_020ae408(8, 0x40) != 0) {
        func_021138e4();
        return;
    }
    if (func_020ae408(8, 0x80) != 0) {
        func_02113940();
    }
}

void func_021123a0(void) {
    s32 i;
    u16 b;
    u16 x;
    s32 l;
    u16 a;
    s32 j;
    s16 c;
    s16 v;
    c = 0;
    func_021137f4();
    switch (gRecordVS->mUnk_6c) {
        case 0:
            c = -256;
            break;
        case 1:
            c = 0x100;
            break;
    }
    gRecordVS->mUnk_54 = gRecordVS->mUnk_54 + 1;
    a = gRecordVS->mUnk_08->mUnk_06;
    b = gRecordVS->mUnk_18->mUnk_06;
    x = gRecordVS->mUnk_30->mUnk_06;
    v = func_020ae4c0(1, 0, c, gRecordVS->mUnk_54, 10);
    gRecordVS->mUnk_58 = v;
    gRecordVS->mUnk_60 = v;
    gRecordVS->mUnk_14[1].mUnk_04 = v;
    gRecordVS->mUnk_14[2].mUnk_04 = v;
    gRecordVS->mUnk_14[3].mUnk_04 = v;
    gRecordVS->mUnk_14[a].mUnk_04 = v;
    gRecordVS->mUnk_14[a + 1].mUnk_04 = v;
    gRecordVS->mUnk_14[a + 11].mUnk_04 = v;
    gRecordVS->mUnk_14[a + 12].mUnk_04 = v;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            gRecordVS->mUnk_14[a + data_0215c410[i][j]].mUnk_04 = v;
        }
    }
    gRecordVS->mUnk_24[1].mUnk_04 = v;
    gRecordVS->mUnk_24[b].mUnk_04 = v;
    gRecordVS->mUnk_24[b + 1].mUnk_04 = v;
    gRecordVS->mUnk_24[b + 14].mUnk_04 = v;
    for (j = 0; j < 12; j++) {
        gRecordVS->mUnk_24[b + data_0215c478[j]].mUnk_04 = v;
    }
    for (l = 0; l < 5; l++) {
        gRecordVS->mUnk_3c[data_0215c3e0[l]].mUnk_04 = v;
        gRecordVS->mUnk_3c[data_0215c3ec[l]].mUnk_04 = v;
        gRecordVS->mUnk_3c[data_0215c3f8[l]].mUnk_04 = v;
        gRecordVS->mUnk_3c[data_0215c404[l]].mUnk_04 = v;
        gRecordVS->mUnk_3c[x + data_0215c3bc[l]].mUnk_04 = v;
    }
    if (gRecordVS->mUnk_54 >= 10) {
        func_02113420();
    }
}

void func_021121d4(void) {
    s32 i;
    u16 b;
    u16 x;
    s32 l;
    u16 a;
    s32 j;
    s16 c;
    s16 v;
    c = 0;
    func_021137f4();
    switch (gRecordVS->mUnk_6c) {
        case 0:
            c = 0x100;
            break;
        case 1:
            c = -256;
            break;
    }
    gRecordVS->mUnk_54 = gRecordVS->mUnk_54 + 1;
    a = gRecordVS->mUnk_08->mUnk_06;
    b = gRecordVS->mUnk_18->mUnk_06;
    x = gRecordVS->mUnk_30->mUnk_06;
    v = func_020ae4c0(1, c, 0, gRecordVS->mUnk_54, 10);
    gRecordVS->mUnk_58 = v;
    gRecordVS->mUnk_60 = v;
    gRecordVS->mUnk_14[1].mUnk_04 = v;
    gRecordVS->mUnk_14[2].mUnk_04 = v;
    gRecordVS->mUnk_14[3].mUnk_04 = v;
    gRecordVS->mUnk_14[a].mUnk_04 = v;
    gRecordVS->mUnk_14[a + 1].mUnk_04 = v;
    gRecordVS->mUnk_14[a + 11].mUnk_04 = v;
    gRecordVS->mUnk_14[a + 12].mUnk_04 = v;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            gRecordVS->mUnk_14[a + data_0215c410[i][j]].mUnk_04 = v;
        }
    }
    gRecordVS->mUnk_24[1].mUnk_04 = v;
    gRecordVS->mUnk_24[b].mUnk_04 = v;
    gRecordVS->mUnk_24[b + 1].mUnk_04 = v;
    gRecordVS->mUnk_24[b + 14].mUnk_04 = v;
    for (j = 0; j < 12; j++) {
        gRecordVS->mUnk_24[b + data_0215c478[j]].mUnk_04 = v;
    }
    for (l = 0; l < 5; l++) {
        gRecordVS->mUnk_3c[data_0215c3e0[l]].mUnk_04 = v;
        gRecordVS->mUnk_3c[data_0215c3ec[l]].mUnk_04 = v;
        gRecordVS->mUnk_3c[data_0215c3f8[l]].mUnk_04 = v;
        gRecordVS->mUnk_3c[data_0215c404[l]].mUnk_04 = v;
        gRecordVS->mUnk_3c[x + data_0215c3bc[l]].mUnk_04 = v;
    }
    if (gRecordVS->mUnk_54 >= 10) {
        func_0211346c();
    }
}

void func_0211209c(void) {
    s16 v;
    s32 i;
    u16 x;
    gRecordVS->mUnk_54 = gRecordVS->mUnk_54 + 1;
    v = func_020ae4c0(1, 0, 0x100, gRecordVS->mUnk_54, 10);
    x = gRecordVS->mUnk_30->mUnk_06;
    gRecordVS->mUnk_3c[20].mUnk_04 = v;
    gRecordVS->mUnk_3c[21].mUnk_04 = v;
    gRecordVS->mUnk_3c[24].mUnk_04 = v;
    gRecordVS->mUnk_3c[25].mUnk_04 = v;
    gRecordVS->mUnk_3c[26].mUnk_04 = v;
    gRecordVS->mUnk_3c[x + 5].mUnk_04 = v;
    for (i = 0; i < 5; i++) {
        gRecordVS->mUnk_3c[data_0215c3e0[i]].mUnk_04 = v;
        gRecordVS->mUnk_3c[data_0215c3ec[i]].mUnk_04 = v;
        gRecordVS->mUnk_3c[data_0215c3f8[i]].mUnk_04 = v;
        gRecordVS->mUnk_3c[data_0215c404[i]].mUnk_04 = v;
        gRecordVS->mUnk_3c[x + data_0215c3bc[i]].mUnk_04 = v;
    }
    if (gRecordVS->mUnk_54 >= 10) {
        func_021132e4();
    }
    if (gRecordVS->mUnk_54 == 6) {
        gRecordVS->mUnk_3c[24].mUnk_00 = 0;
        gRecordVS->mUnk_3c[25].mUnk_00 = 0;
    }
}

void func_02111f54(void) {
    u16 b;
    u16 a;
    s32 i;
    s32 j;
    s16 v;
    if (func_0211145c() == -1 && gRecordVS->mUnk_90 == 6) {
        func_02111450(12);
    }
    gRecordVS->mUnk_54 = gRecordVS->mUnk_54 + 1;
    v = func_020ae4c0(1, 0, -192, gRecordVS->mUnk_54, 10);
    gRecordVS->mUnk_5c = v;
    gRecordVS->mUnk_64 = v;
    a = gRecordVS->mUnk_08->mUnk_06;
    gRecordVS->mUnk_14[0].mUnk_06 = v;
    gRecordVS->mUnk_14[1].mUnk_06 = v;
    gRecordVS->mUnk_14[2].mUnk_06 = v;
    gRecordVS->mUnk_14[3].mUnk_06 = v;
    gRecordVS->mUnk_14[a].mUnk_06 = v;
    gRecordVS->mUnk_14[a + 1].mUnk_06 = v;
    gRecordVS->mUnk_14[a + 11].mUnk_06 = v;
    gRecordVS->mUnk_14[a + 12].mUnk_06 = v;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            gRecordVS->mUnk_14[a + data_0215c410[i][j]].mUnk_06 = v;
        }
    }
    b = gRecordVS->mUnk_18->mUnk_06;
    gRecordVS->mUnk_24[1].mUnk_06 = v;
    gRecordVS->mUnk_24[0].mUnk_06 = v;
    gRecordVS->mUnk_24[b].mUnk_06 = v;
    gRecordVS->mUnk_24[b + 1].mUnk_06 = v;
    gRecordVS->mUnk_24[b + 14].mUnk_06 = v;
    for (j = 0; j < 12; j++) {
        gRecordVS->mUnk_24[b + data_0215c478[j]].mUnk_06 = v;
    }
    if (gRecordVS->mUnk_54 >= 10 && gRecordVS->mUnk_90 != 6) {
        func_02111488(gRecordVS->mUnk_90);
    }
}

void func_02111ef4(void) {
    s16 v;
    u16 i;
    gRecordVS->mUnk_54 = gRecordVS->mUnk_54 + 1;
    v = func_020ae488(gRecordVS->mUnk_54);
    i = gRecordVS->mUnk_30->mUnk_06;
    gRecordVS->mUnk_3c[24].mUnk_04 = v;
    gRecordVS->mUnk_3c[25].mUnk_04 = v;
    gRecordVS->mUnk_3c[26].mUnk_04 = v;
    gRecordVS->mUnk_3c[i + 5].mUnk_04 = v;
    if (gRecordVS->mUnk_54 >= 10) {
        func_02113298();
    }
}

void func_02111db8(void) {
    s16 v;
    s32 i;
    u16 x;
    gRecordVS->mUnk_54 = gRecordVS->mUnk_54 + 1;
    v = func_020ae4c0(1, 0, 0x100, gRecordVS->mUnk_54, 10);
    x = gRecordVS->mUnk_30->mUnk_06;
    gRecordVS->mUnk_3c[20].mUnk_04 = v;
    gRecordVS->mUnk_3c[21].mUnk_04 = v;
    gRecordVS->mUnk_3c[24].mUnk_04 = v;
    gRecordVS->mUnk_3c[25].mUnk_04 = v;
    gRecordVS->mUnk_3c[26].mUnk_04 = v;
    gRecordVS->mUnk_3c[x + 5].mUnk_04 = v;
    for (i = 0; i < 5; i++) {
        gRecordVS->mUnk_3c[data_0215c3e0[i]].mUnk_04 = v;
        gRecordVS->mUnk_3c[data_0215c3ec[i]].mUnk_04 = v;
        gRecordVS->mUnk_3c[data_0215c3f8[i]].mUnk_04 = v;
        gRecordVS->mUnk_3c[data_0215c404[i]].mUnk_04 = v;
        gRecordVS->mUnk_3c[x + data_0215c3bc[i]].mUnk_04 = v;
    }
    if (gRecordVS->mUnk_54 >= 10) {
        func_02111488(gRecordVS->mUnk_90);
    }
    if (gRecordVS->mUnk_54 == 6) {
        gRecordVS->mUnk_3c[24].mUnk_00 = 0;
        gRecordVS->mUnk_3c[25].mUnk_00 = 0;
    }
}

void func_02111c78(void) {
    s16 v;
    s32 i;
    u16 x;
    func_021137f4();
    gRecordVS->mUnk_54 = gRecordVS->mUnk_54 + 1;
    v = func_020ae4c0(1, 0x100, 0, gRecordVS->mUnk_54, 10);
    x = gRecordVS->mUnk_30->mUnk_06;
    gRecordVS->mUnk_3c[20].mUnk_04 = v;
    gRecordVS->mUnk_3c[21].mUnk_04 = v;
    gRecordVS->mUnk_3c[24].mUnk_04 = v;
    gRecordVS->mUnk_3c[25].mUnk_04 = v;
    gRecordVS->mUnk_3c[26].mUnk_04 = v;
    gRecordVS->mUnk_3c[x + 5].mUnk_04 = v;
    for (i = 0; i < 5; i++) {
        gRecordVS->mUnk_3c[data_0215c3e0[i]].mUnk_04 = v;
        gRecordVS->mUnk_3c[data_0215c3ec[i]].mUnk_04 = v;
        gRecordVS->mUnk_3c[data_0215c3f8[i]].mUnk_04 = v;
        gRecordVS->mUnk_3c[data_0215c404[i]].mUnk_04 = v;
        gRecordVS->mUnk_3c[x + data_0215c3bc[i]].mUnk_04 = v;
    }
    if (gRecordVS->mUnk_54 >= 10) {
        func_0211346c();
    }
    if (gRecordVS->mUnk_54 == 2) {
        gRecordVS->mUnk_3c[24].mUnk_00 = 1;
        gRecordVS->mUnk_3c[25].mUnk_00 = 0;
    }
}

void func_02111b94(void) {
    Unk0217d348 *p;
    gRecordVS->mUnk_4c = gRecordVS->mUnk_50;
    switch (gRecordVS->mUnk_4c) {
        case 0:
            func_02112b30();
            break;
        case 1:
            func_02112a0c();
            break;
        case 2:
            func_021128cc();
            break;
        case 3:
            func_021128b4();
            break;
        case 4:
            func_0211256c();
            break;
        case 5:
            func_021123a0();
            break;
        case 6:
            func_021121d4();
            break;
        case 7:
            func_0211209c();
            break;
        case 8:
            func_02111f54();
            break;
        case 9:
            func_02111ef4();
            break;
        case 10:
            func_02111db8();
            break;
        case 11:
            func_02111c78();
            break;
    }
    func_02113d84();
    p = gRecordVS;
    switch (p->mUnk_40) {
        case 0:
            func_02124c30(p->mUnk_08, p->mUnk_04, p->mUnk_0c, func_02111318(), p->mUnk_14);
            break;
        case 1:
            func_02124c30(p->mUnk_18, p->mUnk_04, p->mUnk_1c, func_02111318(), p->mUnk_24);
            break;
    }
    p = gRecordVS;
    func_02124c30(p->mUnk_30, p->mUnk_2c, p->mUnk_38, func_0211130c(), p->mUnk_3c);
}

#pragma thumb off

#pragma thumb on

void func_02111b40(void) {
    *(vu32 *) 0x4000010 = (-gRecordVS->mUnk_58 & 0x1ff) | ((-gRecordVS->mUnk_5c << 16) & 0x1ff0000);
    *(vu32 *) 0x4000014 = (-gRecordVS->mUnk_60 & 0x1ff) | ((-gRecordVS->mUnk_64 << 16) & 0x1ff0000);
    func_02111428();
}

#pragma thumb off

#pragma thumb on

void func_02111adc(void) {
    u32 v;
    if (func_0211146c() == 12) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | 0x1b00;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | 0x1600;
    } else {
        v = (reg_GX_DISPCNT & 0x1f00) >> 8;
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffffe0ff) | ((v | 0x13) << 8);
    }
}

void func_02111ab4(void) {
    Unk0217d344_18 v = {InitRecordVS, func_02112b48, func_02111b94, func_02111b40, func_02111adc};
    func_02111494(&v);
}

void func_02111a98(void) {
    data_0217d344->mUnk_18.mUnk_00 = 0;
    data_0217d344->mUnk_18.mUnk_04 = 0;
    data_0217d344->mUnk_18.mUnk_08 = 0;
    data_0217d344->mUnk_18.mUnk_0c = 0;
}

#pragma thumb off

#pragma thumb on

void func_02111684(void) {
    void *v1;
    Unk02111684_v v2;
    v2.m4934 = 0;
    v1 = FindSceneFile(gRecordTopMenuMBNcgrName);
    LoadNcgrData(&v2.m4934, v1);
    v1 = FindSceneFile(gRecordTopMenuMBNclrName);
    LoadNclrData(&v2.m4a44, v1);
    v1 = FindSceneFile(gRecordTopMenuMNscrName);
    LoadNscrData(&v2.m47d8, v1);
    v1 = FindSceneFile(gRecordTopMenuMNcgrName);
    LoadNcgrData2(&v2.m4934, v1);
    v1 = FindSceneFile(gRecordTopMenuMNcerName);
    LoadNcerData(&v2.m21dc8, v1);
    v1 = FindSceneFile(gRecordTopMenuMONclrName);
    LoadNclrData(&v2.m4a44, v1);
    v1 = FindSceneFile(gRecordTopMenuSNcgrName);
    LoadNcgrData2(&v2.m4934, v1);
    v1 = FindSceneFile(gRecordTopMenuSNcerName);
    LoadNcerData(&v2.m21dc8, v1);
    v1 = FindSceneFile(gRecordTopMenuSONclrName);
    LoadNclrData(&v2.m4a44, v1);
    v1 = FindSceneFile(data_0216cc98);
    LoadNcgrData(&v2.m4934, v1);
    v1 = FindSceneFile(data_0216ccd0);
    LoadNcerData(&v2.m21dc8, v1);
    v1 = FindSceneFile(data_0216ccec);
    LoadNclrData(&v2.m4a44, v1);
    v1 = FindSceneFile(data_0216cc6c);
    LoadNcgrData2(&v2.m4934, v1);
    v1 = FindSceneFile(data_0216ccc8);
    LoadNclrData(&v2.m4a44, v1);
    v1 = FindSceneFile(data_0216cc9c);
    LoadNscrData(&v2.m47d8, v1);
    v1 = FindSceneFile(data_0216cc94);
    LoadNcgrData(&v2.m4934, v1);
    v1 = FindSceneFile(data_0216cc70);
    LoadNcerData(&v2.m21dc8, v1);
    v1 = FindSceneFile(data_0216cc68);
    LoadNclrData(&v2.m4a44, v1);
    v1 = FindSceneFile(data_0216cd14);
    LoadNcgrData2(&v2.m4934, v1);
    v1 = FindSceneFile(data_0216ccbc);
    LoadNclrData(&v2.m4a44, v1);
    v1 = FindSceneFile(data_0216ccf8);
    LoadNscrData(&v2.m47d8, v1);
    v1 = FindSceneFile(data_0216cd18);
    LoadNcgrData(&v2.m4934, v1);
    v1 = FindSceneFile(data_0216cd28);
    LoadNcerData(&v2.m21dc8, v1);
    v1 = FindSceneFile(data_0216ccb8);
    LoadNclrData(&v2.m4a44, v1);
    v1 = FindSceneFile(gRecordTAttMNcgrName);
    LoadNcgrData(&v2.m4934, v1);
    v1 = FindSceneFile(gRecordTAttMNcerName);
    LoadNcerData(&v2.m21dc8, v1);
    v1 = FindSceneFile(gRecordTAttMONclrName);
    LoadNclrData(&v2.m4a44, v1);
    v1 = FindSceneFile(gRecordTAttMBNcgrName);
    LoadNcgrData2(&v2.m4934, v1);
    v1 = FindSceneFile(gRecordTAttMNscrName);
    LoadNscrData(&v2.m47d8, v1);
    v1 = FindSceneFile(gRecordTAttMScoreNscrName);
    LoadNscrData(&v2.m47d8, v1);
    v1 = FindSceneFile(gRecordTAttMBNclrName);
    LoadNclrData(&v2.m4a44, v1);
    v1 = FindSceneFile(gRecordTAttSNcgrName);
    LoadNcgrData(&v2.m4934, v1);
    v1 = FindSceneFile(gRecordTAttSNcerName);
    LoadNcerData(&v2.m21dc8, v1);
    v1 = FindSceneFile(gRecordTAttSONclrName);
    LoadNclrData(&v2.m4a44, v1);
    v1 = FindSceneFile(gRecordTAttSBNcgrName);
    LoadNcgrData2(&v2.m4934, v1);
    v1 = FindSceneFile(gRecordTAttSBNclrName);
    LoadNclrData(&v2.m4a44, v1);
    v1 = FindSceneFile(gRecordTAttSNscrName);
    LoadNscrData(&v2.m47d8, v1);
    v1 = FindSceneFile(gRecordVSMNcgrName);
    LoadNcgrData(&v2.m4934, v1);
    v1 = FindSceneFile(gRecordVSMNcerName);
    LoadNcerData(&v2.m21dc8, v1);
    v1 = FindSceneFile(gRecordVSMONclrName);
    LoadNclrData(&v2.m4a44, v1);
    v1 = FindSceneFile(gRecordVSMBNcgrName);
    LoadNcgrData2(&v2.m4934, v1);
    v1 = FindSceneFile(gRecordVSMNscrName);
    LoadNscrData(&v2.m47d8, v1);
    v1 = FindSceneFile(gRecordVSM02NscrName);
    LoadNscrData(&v2.m47d8, v1);
    v1 = FindSceneFile(gRecordVSMBNclrName);
    LoadNclrData(&v2.m4a44, v1);
    v1 = FindSceneFile(gRecordVSSNcgrName);
    LoadNcgrData(&v2.m4934, v1);
    v1 = FindSceneFile(gRecordVSSNcerName);
    LoadNcerData(&v2.m21dc8, v1);
    v1 = FindSceneFile(gRecordVSSONclrName);
    LoadNclrData(&v2.m4a44, v1);
    v1 = FindSceneFile(gRecordVSM03NscrName);
    LoadNscrData(&v2.m47d8, v1);
    v1 = FindSceneFile(data_0216d3f4);
    LoadNcgrData2(&v2.m4934, v1);
    v1 = FindSceneFile(data_0216d400);
    LoadNscrData(&v2.m47d8, v1);
    v1 = FindSceneFile(data_0216d404);
    LoadNclrData(&v2.m4a44, v1);
    func_02117388();
    func_0211e074();
}

#pragma thumb off

#pragma thumb on

void func_021115b0(void *a, s16 b) {
    Unk02125de0Arg v;
    data_0217d344 = func_02036bec(a, 0x34);
    data_0217d344->mUnk_00 = a;
    data_0217d344->mUnk_30 = 0;
    data_0217d344->mUnk_32 = 0;
    func_021250b0(a);
    func_0212abdc(a, func_02111318());
    v.mUnk_00 = 1;
    v.mUnk_04 = func_020b403c(1);
    v.mUnk_08 = 0;
    v.mUnk_0c = 1;
    v.mUnk_10 = 0;
    v.mUnk_14 = 0;
    v.mUnk_1c = 1;
    v.mUnk_20 = 1;
    v.mUnk_24 = 0;
    func_02125c2c();
    func_02125de0(a, &v);
    func_021144c0(data_0217d344->mUnk_00);
    func_021143f4();
    data_0217d344->mUnk_04 = func_020369fc(data_0217d344->mUnk_00);
    func_02111684();
    func_02111a98();
    data_0217d344->mUnk_14 = b;
    data_0217d344->mUnk_16 = -1;
    data_0217d344->mUnk_0c = -1;
    data_0217d344->mUnk_2c = 2;
    if (data_0217d344->mUnk_14 == 12) {
        data_0217d344->mUnk_10 = 6;
        data_0217d344->mUnk_08 = 3;
        func_02111ab4();
    } else {
        data_0217d344->mUnk_10 = 5;
        data_0217d344->mUnk_08 = 0;
        RegisterRecordTopMenuCallbacks();
    }
    data_0217d344->mUnk_18.mUnk_00(data_0217d344->mUnk_04);
}

#pragma thumb off

#pragma thumb on

void func_02111584(void) {
    func_021144b4();
    data_0217d344->mUnk_18.mUnk_04();
    func_02111a98();
    func_0212abd0();
    func_02125da0();
    *(int *) &data_0217d344 = 0;
}

#pragma thumb off

#pragma thumb on

void func_021114cc(void) {
    if (data_0217d344->mUnk_0c != -1) {
        data_0217d344->mUnk_18.mUnk_04();
        func_02111a98();
        func_02036ab0(data_0217d344->mUnk_04);
        data_0217d344->mUnk_04 = func_020369fc(data_0217d344->mUnk_00);
        switch (data_0217d344->mUnk_0c) {
            case 0:
                if (data_0217d344->mUnk_08 == 3) {
                    func_021143f4();
                }
                RegisterRecordTopMenuCallbacks();
                break;
            case 1:
                func_ov001_02193c5c();
                break;
            case 2:
                RegisterRecordTAttCallbacks();
                break;
            case 3:
                func_02111ab4();
                break;
            case 4:
                func_021145b4();
                break;
        }
        data_0217d344->mUnk_10 = data_0217d344->mUnk_08;
        data_0217d344->mUnk_08 = data_0217d344->mUnk_0c;
        data_0217d344->mUnk_0c = -1;
        data_0217d344->mUnk_2c = 2;
        data_0217d344->mUnk_18.mUnk_00(data_0217d344->mUnk_04);
    }
    data_0217d344->mUnk_18.mUnk_08();
    func_02125928();
    func_0212a920();
}

#pragma thumb off

#pragma thumb on

void func_021114b0(void) {
    data_0217d344->mUnk_18.mUnk_0c();
    func_021258f0();
}

#pragma thumb off

#pragma thumb on

void func_02111494(const void *a) {
    data_0217d344->mUnk_18 = *(const Unk0217d344_18 *) a;
}

#pragma thumb off

#pragma thumb on
void func_02111488(s32 arg0) {
    u32 value0 = (u32) arg0;
    u32 value1;
    value1 = (u32) &data_0217d344;
    value1 = (u32) * (const u32 *) ((value1) + 0u);
    *(u32 *) ((value1) + 12u) = value0;
}
#pragma thumb off

#pragma thumb on

u32 func_0211147c(void) {
    return ((u32) data_0217d344->mUnk_10);
}

u32 func_0211146c(void) {
    return ((u32) data_0217d344->mUnk_14);
}

u32 func_0211145c(void) {
    return ((u32) data_0217d344->mUnk_16);
}

void func_02111450(u32 p0) {
    data_0217d344->mUnk_16 = (u16) p0;
}

#pragma thumb off

#pragma thumb on

void func_02111428(void) {
    if (data_0217d344->mUnk_2c > 0) {
        data_0217d344->mUnk_2c = data_0217d344->mUnk_2c - 1;
        if (data_0217d344->mUnk_2c == 0) {
            data_0217d344->mUnk_18.mUnk_10();
        }
    }
}

#pragma thumb off

#pragma thumb on
u32 func_02111418(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217d344;
    value1 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = 48u;
    value0 = (u32) * (const s16 *) ((value1) + (value0));
    return value0;
}
#pragma thumb off

#pragma thumb on
u32 func_02111408(void) {
    u32 value0;
    u32 value1;
    value0 = (u32) &data_0217d344;
    value1 = (u32) * (const u32 *) ((value0) + 0u);
    value0 = 50u;
    value0 = (u32) * (const s16 *) ((value1) + (value0));
    return value0;
}
#pragma thumb off

#pragma thumb on
void func_021113fc(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    value1 = (u32) &data_0217d344;
    value1 = (u32) * (const u32 *) ((value1) + 0u);
    *(u16 *) ((value1) + 48u) = (u16) value0;
}
#pragma thumb off

#pragma thumb on
void func_021113f0(u32 arg0) {
    u32 value0 = arg0;
    u32 value1;
    value1 = (u32) &data_0217d344;
    value1 = (u32) * (const u32 *) ((value1) + 0u);
    *(u16 *) ((value1) + 50u) = (u16) value0;
}
#pragma thumb off
