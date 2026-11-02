#include "00/code_02181714.h"
#include "Main/Unknown/code_0214a000.h"
#include "01/code_021956dc.h"
#include "Main/Unknown/code_0211f000.h"
#include "Main/Unknown/code_02125f88.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/code_02036c5c.h"
#include "00/unk_021b0000.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ae630.h"
#include "Main/Unknown/code_0204f7f4.h"
#include "Main/Unknown/code_0212a910.h"

#include "00/code_02180608.h"
#include "00/code_ov000_021804e0.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "00/unk_021b4000.h"
#include "Main/Unknown/code_020ae428.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_0211f6cc.h"
#include "Main/Unknown/code_021266e4.h"
#include "Main/Unknown/code_021281b4.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/code_02061250.h"

void func_ov000_02181e98(void *a) {
    s32 i;
    s32 j;
    s32 k;

    data_ov000_021b4c6c = func_02036bec(a, 0x40);
    data_ov000_021b4c6c->mUnk_14 = (s32) a;
    data_ov000_021b4c6c->mUnk_00 = 0;
    data_ov000_021b4c6c->mUnk_04 = 0;
    data_ov000_021b4c6c->mUnk_10 = -1;
    switch (func_ov000_021806d4()) {
        case 0:
        case 2:
            data_ov000_021b4c6c->mUnk_08 = 0;
            break;
        case 8:
            data_ov000_021b4c6c->mUnk_08 = 1;
            break;
        case 13:
            data_ov000_021b4c6c->mUnk_08 = 2;
            break;
    }
    data_ov000_021b4c6c->mUnk_0c = 0;
    data_ov000_021b4c6c->mUnk_18 = 1;
    data_ov000_021b4c6c->mUnk_38 = FindSceneFile("wifi.bmg");
    data_ov000_021b4c6c->mUnk_3c = func_02047a28("common.bmg");
    func_ov000_02181df8();
    for (i = 0; i < 3; i++) {
        func_02124a98(data_ov000_021b05c0[i], 1, data_ov000_021b4c6c->mUnk_20, data_ov000_021b4c6c->mUnk_2c);
    }
    func_020ae6d4(func_ov000_021804f4(), func_ov000_021804e0());
    func_02124ed0(a, data_ov000_021b4c6c->mUnk_2c, 0, &data_ov000_021b4c6c->mUnk_1c);
    for (j = 0; j < 3; j++) {
        for (k = 0; k < data_ov000_021b05cc[j]; k++) {
            data_ov000_021b4c6c->mUnk_1c[data_ov000_021b05d8[j][k]].mUnk_04 = 0xdc;
        }
    }
    func_0212a910(1, 0);
    func_021281c8(0xf);
    func_0204f7f4();
}

void func_ov000_02181e8c(void) {
    data_ov000_021b4c6c = 0;
}

void func_ov000_02181df8(void) {
    void *v1;
    v1 = FindSceneFile((const char *) &data_ov000_021b0af4);
    data_ov000_021b4c6c->mUnk_2c = v1;
    v1 = FindSceneFile((const char *) &data_ov000_021b0b0c);
    data_ov000_021b4c6c->mUnk_30 = v1;
    v1 = FindSceneFile((const char *) &data_ov000_021b0b24);
    LocateNcgr2(&data_ov000_021b4c6c->mUnk_24, v1);
    v1 = FindSceneFile((const char *) &data_ov000_021b0b40);
    LocateNcer(&data_ov000_021b4c6c->mUnk_20, v1);
    v1 = FindSceneFile((const char *) &data_ov000_021b0b5c);
    LocateNclr(&data_ov000_021b4c6c->mUnk_28, v1);
    func_02016468(0x23, 0, (void *) (data_ov000_021b4c6c->mUnk_24->mUnk_14),
                  (u32) (data_ov000_021b4c6c->mUnk_24->mUnk_10));
    func_02016468(0x1e, 0, (void *) (data_ov000_021b4c6c->mUnk_28->mUnk_0c),
                  (u32) (data_ov000_021b4c6c->mUnk_28->mUnk_08));
    return;
}

s32 func_ov000_02181df0(void) {
    return func_02061250();
}

void func_ov000_02181dd0(void) {
    int v1;
    v1 = func_02036c5c();
    if (v1 != 0) {
        data_ov000_021b4c6c->mUnk_04 = 1;
    }
    return;
}

void func_ov000_02181d44(void) {
    s32 v = 0;
    s32 i;
    s32 j;

    data_ov000_021b4c6c->mUnk_0c = data_ov000_021b4c6c->mUnk_0c + 1;
    if (data_ov000_021b4c6c->mUnk_0c >= 20) {
        data_ov000_021b4c6c->mUnk_04 = 2;
        data_ov000_021b4c6c->mUnk_0c = v;
        func_02128374();
    } else if (data_ov000_021b4c6c->mUnk_0c >= 10) {
        v = func_020ae488(data_ov000_021b4c6c->mUnk_0c - 10);
    } else {
        v = func_020ae4c0(1, 0xdc, v, data_ov000_021b4c6c->mUnk_0c, 10);
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < data_ov000_021b05cc[i]; j++) {
            data_ov000_021b4c6c->mUnk_1c[data_ov000_021b05d8[i][j]].mUnk_04 = v;
        }
    }
}

void func_ov000_02181d20(void) {
    int v1;
    v1 = func_02128294();
    if (v1 != 0) {
        data_ov000_021b4c6c->mUnk_04 = 3;
        func_021281c8(0xf);
    }
    return;
}

void func_ov000_02181b4c(void) {
    Unk02175628Index i = UNK_02175628_INDEX_8;
    s32 v1 = 0;
    u32 v2 = -1;
    s32 v3 = 0;
    s32 v4;
    s32 v5;
    s32 v6;
    s32 v7;

    if (data_02175674[i].mUnk_00 == 0 && data_02175680[i].mUnk_00 < 5) {
        v3 = 1;
    }
    if (v3 == 0 && data_0217567c[i].mUnk_00 == 0 && data_02175674[i].mUnk_00 != 0) {
        v1 = 1;
    }
    if (v1 != 0) {
        v2 = func_0201ea84(data_ov000_021b4c6c->mUnk_30, data_02175670[i].mUnk_00, data_02175672[i].mUnk_00);
    }
    v5 = data_02175628[i].mUnk_00 & 2;
    if ((u16) v5 == 0) {
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
    data_ov000_021b4c6c->mUnk_04 = 5;
    data_ov000_021b4c6c->mUnk_10 = 10;
    if (data_ov000_021b4c6c->mUnk_10 == 10) {
        func_02128310(1);
    }
    return;
next:
    v5 = data_02175628[i].mUnk_00 & 1;
    if ((u16) v5 != 0 || v2 <= 2) {
        v4 = data_ov000_021b4c6c->mUnk_08;
        if ((u16) v5 == 0) {
            switch (v2) {
                case 0:
                    data_ov000_021b4c6c->mUnk_08 = 0;
                    break;
                case 1:
                    data_ov000_021b4c6c->mUnk_08 = 1;
                    break;
                case 2:
                    data_ov000_021b4c6c->mUnk_08 = 2;
                    break;
            }
        }
        if (data_ov000_021b4c6c->mUnk_08 == v4) {
            data_ov000_021b4c6c->mUnk_18 = 0;
        }
        data_ov000_021b4c6c->mUnk_04 = 4;
        switch (data_ov000_021b4c6c->mUnk_08) {
            case 0:
                if (func_0211fd68() == 1) {
                    data_ov000_021b4c6c->mUnk_10 = 2;
                } else {
                    data_ov000_021b4c6c->mUnk_10 = 0;
                }
                break;
            case 1:
                data_ov000_021b4c6c->mUnk_10 = 8;
                break;
            case 2:
                data_ov000_021b4c6c->mUnk_10 = 13;
                break;
        }
        func_02105ac0(5);
    } else {
        if (func_020ae408(8, 0x40) != 0) {
            data_ov000_021b4c6c->mUnk_08--;
            if (data_ov000_021b4c6c->mUnk_08 < 0) {
                data_ov000_021b4c6c->mUnk_08 = 2;
            }
            func_02105ac0(0);
        } else if (func_020ae408(8, 0x80) != 0) {
            data_ov000_021b4c6c->mUnk_08++;
            if (data_ov000_021b4c6c->mUnk_08 > 2) {
                data_ov000_021b4c6c->mUnk_08 = 0;
            }
            func_02105ac0(0);
        }
    }
}

void func_ov000_02181ab8(void) {
    s32 i;
    s32 v;

    data_ov000_021b4c6c->mUnk_0c = data_ov000_021b4c6c->mUnk_0c + 1;
    v = func_020ae488(data_ov000_021b4c6c->mUnk_0c);
    for (i = 0; i < data_ov000_021b05cc[data_ov000_021b4c6c->mUnk_08]; i++) {
        data_ov000_021b4c6c->mUnk_1c[data_ov000_021b05d8[data_ov000_021b4c6c->mUnk_08][i]].mUnk_04 = v;
    }
    if (data_ov000_021b4c6c->mUnk_0c >= 10) {
        data_ov000_021b4c6c->mUnk_04 = 5;
        if (data_ov000_021b4c6c->mUnk_08 == 0 || data_ov000_021b4c6c->mUnk_08 == 2) {
            func_021282c8();
        }
        data_ov000_021b4c6c->mUnk_0c = 0;
    } else if (data_ov000_021b4c6c->mUnk_0c >= 5) {
        data_ov000_021b4c6c->mUnk_18 = 1;
    }
}

void func_ov000_0218198c(void) {
    s32 i;
    s32 j;
    s32 v;
    if (func_ov000_021806c4() == -1) {
        if (data_ov000_021b4c6c->mUnk_10 == 10 && func_0211fd68() != 1) {
            func_ov000_021806b8(0);
        } else if (data_ov000_021b4c6c->mUnk_10 == 13) {
            data_021759d0->mUnk_20 = 4;
            func_ov000_021806b8(12);
        }
    }
    data_ov000_021b4c6c->mUnk_0c++;
    v = data_ov000_021b4c6c->mUnk_0c;
    if (v <= 10) {
        v = func_020ae4c0(1, 0xdc, 0, 10 - v, 10);
    } else {
        v = 0xdc;
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < data_ov000_021b05cc[i]; j++) {
            data_ov000_021b4c6c->mUnk_1c[data_ov000_021b05d8[i][j]].mUnk_04 = v;
        }
    }
    if (data_ov000_021b4c6c->mUnk_0c >= 10) {
        if ((data_ov000_021b4c6c->mUnk_10 == 10 || data_ov000_021b4c6c->mUnk_10 == 13) && func_02128274() == 0) {
            return;
        }
        if (func_ov000_021806c4() == -1) {
            if (data_ov000_021b4c6c->mUnk_10 == 8 && func_ov000_02181df0() == 0) {
                data_ov000_021b4c6c->mUnk_04 = 8;
                data_ov000_021b4c6c->mUnk_10 = -1;
                func_021266e4(func_020b3f7c(data_ov000_021b4c6c->mUnk_38, 0x12));
                data_ov000_021b4c6c->mUnk_0c = 0;
                func_021281c8(0xe);
                return;
            }
            func_ov000_021806e0(data_ov000_021b4c6c->mUnk_10);
        }
    }
}

void func_ov000_02181940(void) {
    int v1;
    v1 = func_02125f54();
    if (v1 != 0) {
        func_02125fc0();
        return;
    }
    v1 = func_02125f88();
    if (v1 != 0) {
        v1 = func_02125f60();
        if (v1 == 0) {
            func_0211fd28();
            data_ov000_021b4c6c->mUnk_04 = 7;
            return;
        }
        data_ov000_021b4c6c->mUnk_04 = 1;
    }
}

void func_ov000_02181904(void) {
    int v1;
    v1 = func_ov000_021806c4();
    if ((v1 == -1) && (data_ov000_021b4c6c->mUnk_10 == 10)) {
        func_ov000_021806b8((u32) 0);
    }
    v1 = func_0211fd68();
    if (v1 != 1) {
        data_ov000_021b4c6c->mUnk_10 = 10;
    }
}

void func_ov000_02181854(void) {
    Unk02175628Index i = UNK_02175628_INDEX_8;
    s32 a;
    s32 b;
    u32 v;
    if (func_02125f6c() != 0) {
        func_0212ecc0(&data_0217d068, 0, 0x15);
    }
    if (func_02125fa4() != 0 && func_02128294() != 0) {
        if ((u16) (data_02175628[i].mUnk_00 & 2) == 0) {
            a = b = 0;
            v = data_02175628[i].mUnk_4c;
            if (v == 0 && data_02175628[i].mUnk_58 < 5) {
                a = 1;
            }
            if (a == 0 && data_02175628[i].mUnk_54 == 0 && v != 0) {
                b = 1;
            }
            if (b == 0 || func_02128210(data_02175628[i].mUnk_48, data_02175628[i].mUnk_4a) == 0) {
                return;
            }
        }
        data_ov000_021b4c6c->mUnk_04 = 1;
        func_02128310(0);
        func_02125fc0();
    }
}

void func_ov000_021817e8(void) {
    s32 i = 0;
    s32 v1 = 0;
    const u8 *p = data_ov000_021b05c4;
    const u8 *q = data_ov000_021b05c8;
    for (; i < 3; i++) {
        if (i == data_ov000_021b4c6c->mUnk_08 && data_ov000_021b4c6c->mUnk_18 != 0) {
            data_ov000_021b4c6c->mUnk_1c[*p].mUnk_00 = 1;
            func_02124a20(*q, 0xe, data_ov000_021b4c6c->mUnk_20, data_ov000_021b4c6c->mUnk_2c);
        } else {
            data_ov000_021b4c6c->mUnk_1c[*p].mUnk_00 = v1;
            func_02124a20(*q, 0xf, data_ov000_021b4c6c->mUnk_20, data_ov000_021b4c6c->mUnk_2c);
        }
        p++;
        q++;
    }
}

void func_ov000_02181758(void) {
    Unk021b4c6c *p;
    data_ov000_021b4c6c->mUnk_00 = data_ov000_021b4c6c->mUnk_04;
    switch (data_ov000_021b4c6c->mUnk_00) {
        case 0:
            func_ov000_02181dd0();
            break;
        case 1:
            func_ov000_02181d44();
            break;
        case 2:
            func_ov000_02181d20();
            break;
        case 3:
            func_ov000_02181b4c();
            break;
        case 4:
            func_ov000_02181ab8();
            break;
        case 5:
            func_ov000_0218198c();
            break;
        case 6:
            func_ov000_02181940();
            break;
        case 7:
            func_ov000_02181904();
            break;
        case 8:
            func_ov000_02181854();
            break;
    }
    func_ov000_021817e8();
    p = data_ov000_021b4c6c;
    func_02124c30(p->mUnk_2c, p->mUnk_20, 0, func_ov000_021804e0(), p->mUnk_1c);
}

void func_ov000_02181738(void) {
    func_0214a40c((u32 *) ((u32 *) (u32) (((u32) 0x04001050u))), (u32) (0), 2, (u32) (6), 10);
    return;
}

void func_ov000_02181714(void) {
    Unk021b0cd4 callbacks = data_ov000_021b0ae4;
    func_ov000_021806ec(&callbacks);
}
