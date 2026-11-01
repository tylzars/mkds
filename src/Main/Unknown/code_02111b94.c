#include "Main/Unknown/code_02111b94.h"

#include "code_0201ea58.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_0211130c.h"
#include "Main/Unknown/code_02111450.h"
#include "Main/Unknown/code_02111488.h"
#include "Main/Unknown/code_021128b4.h"
#include "Main/Unknown/code_021128cc.h"
#include "Main/Unknown/code_02112b30.h"
#include "Main/Unknown/code_02112b48.h"
#include "Main/Unknown/code_021137a8.h"
#include "Main/Unknown/code_021138e4.h"
#include "Main/Unknown/code_021139b4.h"
#include "Main/Unknown/code_02113790.h"
#include "Main/Unknown/code_02113ef0.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_020ee684.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "00/code_02182fdc.h"
#include "01/code_02195a6c.h"
#include "Main/Unknown/code_02111b40.h"

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
        a = func_0201ea84(data_0217d348->mUnk_34, data_02175670[i].mUnk_00, data_02175672[i].mUnk_00);
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
        b = func_0201ea84(data_0217d348->mUnk_34, data_02175670[i].mUnk_00, data_02175672[i].mUnk_00);
    }
    if (a != 10) {
        data_0217d348->mUnk_88 = 0;
    }
    if (a != 11) {
        data_0217d348->mUnk_8c = 0;
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
        data_0217d348->mUnk_90 = 6;
        func_02128310(1);
        return;
    }
    data_0217d348->mUnk_90 = 0;
    func_02128310(0);
    return;
l1:
    if ((a == 10 && data_0217d348->mUnk_88 != 0) || (b == 10 && data_0217d348->mUnk_88 == 0) ||
        (u16) (data_0217562a[i].mUnk_00 & 0x20) != 0) {
        if (func_02113790() != 0) {
            return;
        }
        if (data_0217d348->mUnk_3c[20].mUnk_00 == 0) {
            return;
        }
        data_0217d348->mUnk_6c = 1;
        data_0217d348->mUnk_80[0] = 6;
        data_0217d348->mUnk_88 = 1;
        func_02113458();
        func_0212ecc0(&data_0217d068, 0, 2);
        return;
    }
    if ((a == 11 && data_0217d348->mUnk_8c != 0) || (b == 11 && data_0217d348->mUnk_8c == 0) ||
        (u16) (data_0217562a[i].mUnk_00 & 0x10) != 0) {
        if (func_02113790() != 0) {
            return;
        }
        if (data_0217d348->mUnk_3c[21].mUnk_00 == 0) {
            return;
        }
        data_0217d348->mUnk_6c = 0;
        data_0217d348->mUnk_80[1] = 6;
        data_0217d348->mUnk_8c = 1;
        func_02113458();
        func_0212ecc0(&data_0217d068, 0, 2);
        return;
    }
    if ((u32) (b - 5) <= 4) {
        t = data_0215c44c[b];
        if (func_02113ef0(t) == 0) {
            return;
        }
        data_0217d348->mUnk_68 = t;
        func_021137a8(t);
        return;
    }
    if ((u32) b <= 4) {
        t = data_0215c44c[b];
        if (t == data_0217d348->mUnk_68) {
            func_021137a8(t);
            return;
        }
        if (func_02113ef0(t) == 0) {
            return;
        }
        data_0217d348->mUnk_68 = t;
        func_0212ecc0(&data_0217d068, 0, 0);
        return;
    }
    if (b == 12 || (u16) (q->mUnk_00 & 0x400) != 0) {
        func_021132b4();
        data_0217d348->mUnk_90 = 4;
        return;
    }
    if ((u16) (q->mUnk_00 & 1) != 0) {
        func_021137a8(data_0217d348->mUnk_68);
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
    s32 c;
    s16 v;
    c = 0;
    func_021137f4();
    switch (data_0217d348->mUnk_6c) {
        case 0:
            c = -256;
            break;
        case 1:
            c = 0x100;
            break;
    }
    data_0217d348->mUnk_54 = data_0217d348->mUnk_54 + 1;
    a = data_0217d348->mUnk_08->mUnk_06;
    b = data_0217d348->mUnk_18->mUnk_06;
    x = data_0217d348->mUnk_30->mUnk_06;
    v = func_020ae4c0(1, 0, c, data_0217d348->mUnk_54, 10);
    data_0217d348->mUnk_58 = v;
    data_0217d348->mUnk_60 = v;
    data_0217d348->mUnk_14[1].mUnk_04 = v;
    data_0217d348->mUnk_14[2].mUnk_04 = v;
    data_0217d348->mUnk_14[3].mUnk_04 = v;
    data_0217d348->mUnk_14[a].mUnk_04 = v;
    data_0217d348->mUnk_14[a + 1].mUnk_04 = v;
    data_0217d348->mUnk_14[a + 11].mUnk_04 = v;
    data_0217d348->mUnk_14[a + 12].mUnk_04 = v;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            data_0217d348->mUnk_14[a + data_0215c410[i][j]].mUnk_04 = v;
        }
    }
    data_0217d348->mUnk_24[1].mUnk_04 = v;
    data_0217d348->mUnk_24[b].mUnk_04 = v;
    data_0217d348->mUnk_24[b + 1].mUnk_04 = v;
    data_0217d348->mUnk_24[b + 14].mUnk_04 = v;
    for (j = 0; j < 12; j++) {
        data_0217d348->mUnk_24[b + data_0215c478[j]].mUnk_04 = v;
    }
    for (l = 0; l < 5; l++) {
        data_0217d348->mUnk_3c[data_0215c3e0[l]].mUnk_04 = v;
        data_0217d348->mUnk_3c[data_0215c3ec[l]].mUnk_04 = v;
        data_0217d348->mUnk_3c[data_0215c3f8[l]].mUnk_04 = v;
        data_0217d348->mUnk_3c[data_0215c404[l]].mUnk_04 = v;
        data_0217d348->mUnk_3c[x + data_0215c3bc[l]].mUnk_04 = v;
    }
    if (data_0217d348->mUnk_54 >= 10) {
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
    s32 c;
    s16 v;
    c = 0;
    func_021137f4();
    switch (data_0217d348->mUnk_6c) {
        case 0:
            c = 0x100;
            break;
        case 1:
            c = -256;
            break;
    }
    data_0217d348->mUnk_54 = data_0217d348->mUnk_54 + 1;
    a = data_0217d348->mUnk_08->mUnk_06;
    b = data_0217d348->mUnk_18->mUnk_06;
    x = data_0217d348->mUnk_30->mUnk_06;
    v = func_020ae4c0(1, c, 0, data_0217d348->mUnk_54, 10);
    data_0217d348->mUnk_58 = v;
    data_0217d348->mUnk_60 = v;
    data_0217d348->mUnk_14[1].mUnk_04 = v;
    data_0217d348->mUnk_14[2].mUnk_04 = v;
    data_0217d348->mUnk_14[3].mUnk_04 = v;
    data_0217d348->mUnk_14[a].mUnk_04 = v;
    data_0217d348->mUnk_14[a + 1].mUnk_04 = v;
    data_0217d348->mUnk_14[a + 11].mUnk_04 = v;
    data_0217d348->mUnk_14[a + 12].mUnk_04 = v;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            data_0217d348->mUnk_14[a + data_0215c410[i][j]].mUnk_04 = v;
        }
    }
    data_0217d348->mUnk_24[1].mUnk_04 = v;
    data_0217d348->mUnk_24[b].mUnk_04 = v;
    data_0217d348->mUnk_24[b + 1].mUnk_04 = v;
    data_0217d348->mUnk_24[b + 14].mUnk_04 = v;
    for (j = 0; j < 12; j++) {
        data_0217d348->mUnk_24[b + data_0215c478[j]].mUnk_04 = v;
    }
    for (l = 0; l < 5; l++) {
        data_0217d348->mUnk_3c[data_0215c3e0[l]].mUnk_04 = v;
        data_0217d348->mUnk_3c[data_0215c3ec[l]].mUnk_04 = v;
        data_0217d348->mUnk_3c[data_0215c3f8[l]].mUnk_04 = v;
        data_0217d348->mUnk_3c[data_0215c404[l]].mUnk_04 = v;
        data_0217d348->mUnk_3c[x + data_0215c3bc[l]].mUnk_04 = v;
    }
    if (data_0217d348->mUnk_54 >= 10) {
        func_0211346c();
    }
}

void func_0211209c(void) {
    s16 v;
    s32 i;
    u16 x;
    data_0217d348->mUnk_54 = data_0217d348->mUnk_54 + 1;
    v = func_020ae4c0(1, 0, 0x100, data_0217d348->mUnk_54, 10);
    x = data_0217d348->mUnk_30->mUnk_06;
    data_0217d348->mUnk_3c[20].mUnk_04 = v;
    data_0217d348->mUnk_3c[21].mUnk_04 = v;
    data_0217d348->mUnk_3c[24].mUnk_04 = v;
    data_0217d348->mUnk_3c[25].mUnk_04 = v;
    data_0217d348->mUnk_3c[26].mUnk_04 = v;
    data_0217d348->mUnk_3c[x + 5].mUnk_04 = v;
    for (i = 0; i < 5; i++) {
        data_0217d348->mUnk_3c[data_0215c3e0[i]].mUnk_04 = v;
        data_0217d348->mUnk_3c[data_0215c3ec[i]].mUnk_04 = v;
        data_0217d348->mUnk_3c[data_0215c3f8[i]].mUnk_04 = v;
        data_0217d348->mUnk_3c[data_0215c404[i]].mUnk_04 = v;
        data_0217d348->mUnk_3c[x + data_0215c3bc[i]].mUnk_04 = v;
    }
    if (data_0217d348->mUnk_54 >= 10) {
        func_021132e4();
    }
    if (data_0217d348->mUnk_54 == 6) {
        data_0217d348->mUnk_3c[24].mUnk_00 = 0;
        data_0217d348->mUnk_3c[25].mUnk_00 = 0;
    }
}

void func_02111f54(void) {
    u16 b;
    u16 a;
    s32 i;
    s32 j;
    s16 v;
    if (func_0211145c() == -1 && data_0217d348->mUnk_90 == 6) {
        func_02111450(12);
    }
    data_0217d348->mUnk_54 = data_0217d348->mUnk_54 + 1;
    v = func_020ae4c0(1, 0, -192, data_0217d348->mUnk_54, 10);
    data_0217d348->mUnk_5c = v;
    data_0217d348->mUnk_64 = v;
    a = data_0217d348->mUnk_08->mUnk_06;
    data_0217d348->mUnk_14[0].mUnk_06 = v;
    data_0217d348->mUnk_14[1].mUnk_06 = v;
    data_0217d348->mUnk_14[2].mUnk_06 = v;
    data_0217d348->mUnk_14[3].mUnk_06 = v;
    data_0217d348->mUnk_14[a].mUnk_06 = v;
    data_0217d348->mUnk_14[a + 1].mUnk_06 = v;
    data_0217d348->mUnk_14[a + 11].mUnk_06 = v;
    data_0217d348->mUnk_14[a + 12].mUnk_06 = v;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            data_0217d348->mUnk_14[a + data_0215c410[i][j]].mUnk_06 = v;
        }
    }
    b = data_0217d348->mUnk_18->mUnk_06;
    data_0217d348->mUnk_24[1].mUnk_06 = v;
    data_0217d348->mUnk_24[0].mUnk_06 = v;
    data_0217d348->mUnk_24[b].mUnk_06 = v;
    data_0217d348->mUnk_24[b + 1].mUnk_06 = v;
    data_0217d348->mUnk_24[b + 14].mUnk_06 = v;
    for (j = 0; j < 12; j++) {
        data_0217d348->mUnk_24[b + data_0215c478[j]].mUnk_06 = v;
    }
    if (data_0217d348->mUnk_54 >= 10 && data_0217d348->mUnk_90 != 6) {
        func_02111488(data_0217d348->mUnk_90);
    }
}

void func_02111ef4(void) {
    s16 v;
    u16 i;
    data_0217d348->mUnk_54 = data_0217d348->mUnk_54 + 1;
    v = func_020ae488(data_0217d348->mUnk_54);
    i = data_0217d348->mUnk_30->mUnk_06;
    data_0217d348->mUnk_3c[24].mUnk_04 = v;
    data_0217d348->mUnk_3c[25].mUnk_04 = v;
    data_0217d348->mUnk_3c[26].mUnk_04 = v;
    data_0217d348->mUnk_3c[i + 5].mUnk_04 = v;
    if (data_0217d348->mUnk_54 >= 10) {
        func_02113298();
    }
}

void func_02111db8(void) {
    s16 v;
    s32 i;
    u16 x;
    data_0217d348->mUnk_54 = data_0217d348->mUnk_54 + 1;
    v = func_020ae4c0(1, 0, 0x100, data_0217d348->mUnk_54, 10);
    x = data_0217d348->mUnk_30->mUnk_06;
    data_0217d348->mUnk_3c[20].mUnk_04 = v;
    data_0217d348->mUnk_3c[21].mUnk_04 = v;
    data_0217d348->mUnk_3c[24].mUnk_04 = v;
    data_0217d348->mUnk_3c[25].mUnk_04 = v;
    data_0217d348->mUnk_3c[26].mUnk_04 = v;
    data_0217d348->mUnk_3c[x + 5].mUnk_04 = v;
    for (i = 0; i < 5; i++) {
        data_0217d348->mUnk_3c[data_0215c3e0[i]].mUnk_04 = v;
        data_0217d348->mUnk_3c[data_0215c3ec[i]].mUnk_04 = v;
        data_0217d348->mUnk_3c[data_0215c3f8[i]].mUnk_04 = v;
        data_0217d348->mUnk_3c[data_0215c404[i]].mUnk_04 = v;
        data_0217d348->mUnk_3c[x + data_0215c3bc[i]].mUnk_04 = v;
    }
    if (data_0217d348->mUnk_54 >= 10) {
        func_02111488(data_0217d348->mUnk_90);
    }
    if (data_0217d348->mUnk_54 == 6) {
        data_0217d348->mUnk_3c[24].mUnk_00 = 0;
        data_0217d348->mUnk_3c[25].mUnk_00 = 0;
    }
}

void func_02111c78(void) {
    s16 v;
    s32 i;
    u16 x;
    func_021137f4();
    data_0217d348->mUnk_54 = data_0217d348->mUnk_54 + 1;
    v = func_020ae4c0(1, 0x100, 0, data_0217d348->mUnk_54, 10);
    x = data_0217d348->mUnk_30->mUnk_06;
    data_0217d348->mUnk_3c[20].mUnk_04 = v;
    data_0217d348->mUnk_3c[21].mUnk_04 = v;
    data_0217d348->mUnk_3c[24].mUnk_04 = v;
    data_0217d348->mUnk_3c[25].mUnk_04 = v;
    data_0217d348->mUnk_3c[26].mUnk_04 = v;
    data_0217d348->mUnk_3c[x + 5].mUnk_04 = v;
    for (i = 0; i < 5; i++) {
        data_0217d348->mUnk_3c[data_0215c3e0[i]].mUnk_04 = v;
        data_0217d348->mUnk_3c[data_0215c3ec[i]].mUnk_04 = v;
        data_0217d348->mUnk_3c[data_0215c3f8[i]].mUnk_04 = v;
        data_0217d348->mUnk_3c[data_0215c404[i]].mUnk_04 = v;
        data_0217d348->mUnk_3c[x + data_0215c3bc[i]].mUnk_04 = v;
    }
    if (data_0217d348->mUnk_54 >= 10) {
        func_0211346c();
    }
    if (data_0217d348->mUnk_54 == 2) {
        data_0217d348->mUnk_3c[24].mUnk_00 = 1;
        data_0217d348->mUnk_3c[25].mUnk_00 = 0;
    }
}

void func_02111b94(void) {
    Unk0217d348 *p;
    data_0217d348->mUnk_4c = data_0217d348->mUnk_50;
    switch (data_0217d348->mUnk_4c) {
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
    p = data_0217d348;
    switch (p->mUnk_40) {
        case 0:
            func_02124c30(p->mUnk_08, p->mUnk_04, p->mUnk_0c, func_02111318(), p->mUnk_14);
            break;
        case 1:
            func_02124c30(p->mUnk_18, p->mUnk_04, p->mUnk_1c, func_02111318(), p->mUnk_24);
            break;
    }
    p = data_0217d348;
    func_02124c30(p->mUnk_30, p->mUnk_2c, p->mUnk_38, func_0211130c(), p->mUnk_3c);
}

#pragma thumb off
