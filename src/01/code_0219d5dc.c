#include "01/code_0219d5dc.h"

#include "01/code_0219d000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02056d40.h"
#include "code_0201ea58.h"
#include "Main/Unknown/code_02037000.h"

void func_ov001_0219df70(void *a) {
    s32 i;
    Unk021a9bfc *p;
    void *ptr;

    data_ov001_021a9bfc = func_02036bec(a, 0x58);
    data_ov001_021a9bfc->mUnk_30 = a;
    data_ov001_021a9bfc->mUnk_00 = 0;
    data_ov001_021a9bfc->mUnk_04 = 0;
    data_ov001_021a9bfc->mUnk_08 = 0;
    data_ov001_021a9bfc->mUnk_14 = 0;
    data_ov001_021a9bfc->mUnk_24 = 1;
    func_ov001_0219de58();
    for (i = 0; i < 2; i++) {
        func_02124a98(data_ov001_021a6c38[i][0], 1, data_ov001_021a9bfc->mUnk_38, data_ov001_021a9bfc->mUnk_44);
    }
    func_020ae6d4(func_ov001_0219e920(), func_ov001_0219e90c());
    func_02124ed0(a, data_ov001_021a9bfc->mUnk_44, data_ov001_021a9bfc->mUnk_4c, &data_ov001_021a9bfc->mUnk_34);
    data_ov001_021a9bfc->mUnk_50 = FindSceneFile("option.bmg");
    data_ov001_021a9bfc->mUnk_54 = func_02047a28("common.bmg");
    func_021243ac(a, 0, data_ov001_021a9bfc->mUnk_4c, 0xa0, 0xe, 9, data_ov001_021a9bfc->mUnk_38,
                  data_ov001_021a9bfc->mUnk_44, data_ov001_021a9bfc->mUnk_34, 0x4000);
    p = data_ov001_021a9bfc;
    ptr = func_020b3f7c(p->mUnk_50, 8);
    func_0212426c(1, 0, data_ov001_021a9bfc->mUnk_4c, ptr, p->mUnk_44, p->mUnk_34);
    for (i = 0; i < 2; i++) {
        data_ov001_021a9bfc->mUnk_18[i].mUnk_00 = 250;
        data_ov001_021a9bfc->mUnk_18[i].mUnk_02 = 0;
    }
    data_ov001_021a9bfc->mUnk_0c = func_ov001_0219de38();
    data_ov001_021a9bfc->mUnk_10 = data_ov001_021a9bfc->mUnk_0c;
    func_ov001_0219d858();
    func_ov001_0219d810();
    data_ov001_021a9bfc->mUnk_28[0] = 0;
    data_ov001_021a9bfc->mUnk_28[1] = 0;
    func_021281c8(0xe);
}

void func_ov001_0219df64(void) {
    data_ov001_021a9bfc = 0;
}

void func_ov001_0219de58(void) {
    Unk020b4934 *a;
    Unk020b47d8 *b;
    Unk020b4a44 *c;

    func_020b4934(&a, FindSceneFile((const char *) data_ov001_021a8ce0));
    func_020b47d8(&b, FindSceneFile((const char *) data_ov001_021a8cfc));
    func_020b4a44(&c, FindSceneFile((const char *) data_ov001_021a8d14));
    data_ov001_021a9bfc->mUnk_44 = FindSceneFile((const char *) data_ov001_021a8d30);
    data_ov001_021a9bfc->mUnk_48 = FindSceneFile((const char *) data_ov001_021a8d4c);
    data_ov001_021a9bfc->mUnk_4c = FindSceneFile((const char *) data_ov001_021a8d68);
    func_020b49bc(&data_ov001_021a9bfc->mUnk_3c, FindSceneFile((const char *) data_ov001_021a8d84));
    func_020b48b4(&data_ov001_021a9bfc->mUnk_38, FindSceneFile((const char *) data_ov001_021a8da4));
    func_020b4a44(&data_ov001_021a9bfc->mUnk_40, FindSceneFile((const char *) data_ov001_021a8dc4));
    func_02016468(4, 0, a->mUnk_14, a->mUnk_10);
    func_02016468(8, 0, b->mUnk_0c, b->mUnk_08);
    func_02016468(0xf, 0, c->mUnk_0c, 0x100);
    func_02016468(0x23, 0, data_ov001_021a9bfc->mUnk_3c->mUnk_14, data_ov001_021a9bfc->mUnk_3c->mUnk_10);
    func_02016468(0x1e, 0, data_ov001_021a9bfc->mUnk_40->mUnk_0c, data_ov001_021a9bfc->mUnk_40->mUnk_08);
}

s32 func_ov001_0219de38(void) {
    if (data_0217aa08->mUnk_00->mUnk_31_3 == 0) {
        return 0;
    }
    if (data_0217aa08->mUnk_00->mUnk_31_3 != 0) {
        return 1;
    }
    return 1;
}

void func_ov001_0219de18(void) {
    int v1;
    v1 = func_02036c5c();
    if (v1 != 0) {
        data_ov001_021a9bfc->mUnk_04 = 1;
    }
    return;
}

void func_ov001_0219dd94(void) {
    s32 i;
    s32 j;
    s16 v;

    data_ov001_021a9bfc->mUnk_14++;
    v = func_020ae4c0(1, 250, 0, data_ov001_021a9bfc->mUnk_14, 10);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov001_021a6c28[i]; j++) {
            if (i == 1) {
                data_ov001_021a9bfc->mUnk_18[i].mUnk_00 = v;
            } else {
                data_ov001_021a9bfc->mUnk_18[i].mUnk_00 = -v;
            }
        }
    }
    if (data_ov001_021a9bfc->mUnk_14 >= 10) {
        data_ov001_021a9bfc->mUnk_04 = 2;
        data_ov001_021a9bfc->mUnk_14 = 0;
        func_02128374();
    }
}

void func_ov001_0219dd74(void) {
    int v1;
    v1 = func_02128294();
    if (v1 != 0) {
        data_ov001_021a9bfc->mUnk_04 = 3;
    }
    return;
}

void func_ov001_0219dadc(void) {
    Unk02175628Index index = UNK_02175628_INDEX_8;
    s32 result = -1;
    s32 cond2 = 0;
    s32 cond1 = 0;
    u16 value;
    u16 flags;

    value = data_02175628[index].mUnk_4c;
    if (value == 0 && data_02175628[index].mUnk_58 < 5) {
        cond1 = 1;
    }
    if (cond1 == 0 && data_02175628[index].mUnk_54 == 0 && value != 0) {
        cond2 = 1;
    }
    if (cond2 != 0) {
        result =
            func_0201ea84(data_ov001_021a9bfc->mUnk_48, data_02175628[index].mUnk_48, data_02175628[index].mUnk_4a);
    }
    flags = data_02175628[index].mUnk_00 & 2;
    if (flags != 0) {
        goto next;
    }
    cond2 = 0;
    cond1 = 0;
    value = data_02175628[index].mUnk_4c;
    if (value == 0 && data_02175628[index].mUnk_58 < 5) {
        cond1 = 1;
    }
    if (cond1 == 0 && data_02175628[index].mUnk_54 == 0 && value != 0) {
        cond2 = 1;
    }
    if (cond2 != 0 && func_02128210(data_02175628[index].mUnk_48, data_02175628[index].mUnk_4a) != 0) {
    next:
        data_ov001_021a9bfc->mUnk_04 = 5;
        data_ov001_021a9bfc->mUnk_20 = 2;
        if (data_ov001_021a9bfc->mUnk_0c != data_ov001_021a9bfc->mUnk_10) {
            func_02128310(1);
        } else {
            func_02128310(0);
        }
        if (data_ov001_021a9bfc->mUnk_0c == 0) {
            data_0217aa08->mUnk_00->mUnk_31_3 = 0;
        } else {
            data_0217aa08->mUnk_00->mUnk_31_3 = 1;
        }
        func_02056d40();
    } else {
        flags = data_02175628[index].mUnk_00 & 1;
        if ((flags != 0 && data_ov001_021a9bfc->mUnk_08 == 0) || result == 0) {
            if (data_ov001_021a9bfc->mUnk_08 == 0) {
                data_ov001_021a9bfc->mUnk_24 = 0;
            }
            data_ov001_021a9bfc->mUnk_04 = 4;
            data_ov001_021a9bfc->mUnk_20 = 6;
            data_ov001_021a9bfc->mUnk_08 = 0;
            data_0217b488->mUnk_18 = 1;
            func_02105ac0(5);
        } else if (result == 1) {
            data_ov001_021a9bfc->mUnk_08 = 1;
            data_ov001_021a9bfc->mUnk_0c++;
            func_02105ac0(1);
        } else if (func_020ae408(8, 0x40) != 0 && data_ov001_021a9bfc->mUnk_08 > 0) {
            data_ov001_021a9bfc->mUnk_08--;
            func_02105ac0(0);
        } else if (func_020ae408(8, 0x80) != 0 && data_ov001_021a9bfc->mUnk_08 < 1) {
            data_ov001_021a9bfc->mUnk_08++;
            func_02105ac0(0);
        } else if (data_ov001_021a9bfc->mUnk_08 == 1 && func_020ae408(8, 0x20) != 0) {
            data_ov001_021a9bfc->mUnk_0c--;
            data_ov001_021a9bfc->mUnk_28[0] = 6;
            func_02105ac0(1);
        } else if (data_ov001_021a9bfc->mUnk_08 == 1 && func_020ae408(8, 0x10) != 0) {
            data_ov001_021a9bfc->mUnk_0c++;
            if (func_020ae408(8, 0x10) != 0) {
                data_ov001_021a9bfc->mUnk_28[1] = 6;
            }
            func_02105ac0(1);
        } else if (result == 2) {
            data_ov001_021a9bfc->mUnk_08 = 1;
            data_ov001_021a9bfc->mUnk_0c--;
            data_ov001_021a9bfc->mUnk_28[0] = 6;
            func_02105ac0(1);
        } else if (result == 3) {
            data_ov001_021a9bfc->mUnk_08 = 1;
            data_ov001_021a9bfc->mUnk_0c++;
            data_ov001_021a9bfc->mUnk_28[1] = 6;
            func_02105ac0(1);
        }
    }
    if (data_ov001_021a9bfc->mUnk_0c < 0) {
        data_ov001_021a9bfc->mUnk_0c = 1;
    }
    if (data_ov001_021a9bfc->mUnk_0c > 1) {
        data_ov001_021a9bfc->mUnk_0c = 0;
    }
}

void func_ov001_0219daa0(void) {
    int *v1;
    int v2;
    v1 = (int *) &data_ov001_021a9bfc;
    data_ov001_021a9bfc->mUnk_14 = data_ov001_021a9bfc->mUnk_14 + 1;
    v2 = *v1;
    if (10 <= *(int *) (v2 + 0x14)) {
        *(u32 *) (v2 + 4) = 5;
        *(u32 *) (*v1 + 0x14) = 0;
        func_021282c8();
        return;
    }
    if (5 <= *(int *) (v2 + 0x14)) {
        *(u32 *) (v2 + 0x24) = 1;
    }
    return;
}

void func_ov001_0219d998(void) {
    s32 i;
    s32 j;
    s32 value;

    if (func_ov001_02192e84() == -1 && data_ov001_021a9bfc->mUnk_20 == 6) {
        func_ov001_02192e78(3);
    }
    data_ov001_021a9bfc->mUnk_14++;
    value = func_020ae4c0(1, 0, 250, data_ov001_021a9bfc->mUnk_14, 10);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov001_021a6c28[i]; j++) {
            if (i == 0) {
                data_ov001_021a9bfc->mUnk_18[i].mUnk_00 = -value;
            } else {
                data_ov001_021a9bfc->mUnk_18[i].mUnk_00 = value;
            }
        }
    }
    if (data_ov001_021a9bfc->mUnk_14 >= 10) {
        if (data_ov001_021a9bfc->mUnk_14 >= 10 && (func_02128294() != 0 || func_02128274() != 0)) {
            if (func_ov001_02192e84() == -1) {
                Unk021a9bfc *obj = data_ov001_021a9bfc;
                s32 arg;
                void *first;

                if (obj->mUnk_0c == obj->mUnk_10) {
                    func_ov001_02192ea0(obj->mUnk_20);
                    return;
                }
                arg = 9;
                if (obj->mUnk_0c == 1) {
                    arg = 10;
                }
                obj->mUnk_04 = 6;
                func_02125ebc(0x21);
                first = func_020b3f7c(data_ov001_021a9bfc->mUnk_50, arg);
                func_02126230(first, func_020b3f7c(data_ov001_021a9bfc->mUnk_54, 4));
                data_ov001_021a9bfc->mUnk_14 = 0;
            }
        }
    }
}

void func_ov001_0219d934(void) {
    s32 value;

    if (func_02125f54() != 0) {
        if (data_0217aa08->mUnk_28 == 0) {
            if (data_021759d4->mUnk_0c != 0) {
                value = data_021759d4->mUnk_10;
            } else {
                value = 0;
            }
        } else {
            value = 1;
        }
        if (value == 0) {
            func_02125ebc(0x23);
            func_02125fc0();
            return;
        }
    }
    if (func_02125f88() != 0) {
        func_ov001_02192ea0(data_ov001_021a9bfc->mUnk_20);
    }
}

void func_ov001_0219d858(void) {
    s32 i;
    s32 j;
    s32 index;
    s32 k;

    index = data_ov001_021a9bfc->mUnk_44->mUnk_06;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < data_ov001_021a6c28[i]; j++) {
            data_ov001_021a9bfc->mUnk_34[data_ov001_021a6c38[i][j]].mUnk_04 = data_ov001_021a9bfc->mUnk_18[i].mUnk_00;
            data_ov001_021a9bfc->mUnk_34[data_ov001_021a6c38[i][j]].mUnk_06 = data_ov001_021a9bfc->mUnk_18[i].mUnk_02;
        }
    }
    data_ov001_021a9bfc->mUnk_34[index].mUnk_04 = data_ov001_021a9bfc->mUnk_18[1].mUnk_00;
    data_ov001_021a9bfc->mUnk_34[index].mUnk_06 = data_ov001_021a9bfc->mUnk_18[1].mUnk_02;
    for (k = 0; k < 3; k++) {
        data_ov001_021a9bfc->mUnk_34[data_ov001_021a6c20[k][0]].mUnk_04 -=
            func_020adc64(6 - data_ov001_021a9bfc->mUnk_28[0]);
        data_ov001_021a9bfc->mUnk_34[data_ov001_021a6c20[k][1]].mUnk_04 +=
            func_020adc64(6 - data_ov001_021a9bfc->mUnk_28[1]);
    }
}

void func_ov001_0219d810(void) {
    s32 i;

    for (i = 0; i < data_ov001_021a6c30[1]; i++) {
        if (i == data_ov001_021a9bfc->mUnk_0c) {
            data_ov001_021a9bfc->mUnk_34[data_ov001_021a6c1c[1][i]].mUnk_00 = 1;
        } else {
            data_ov001_021a9bfc->mUnk_34[data_ov001_021a6c1c[1][i]].mUnk_00 = 0;
        }
    }
}

void func_ov001_0219d730(void) {
    s32 i;
    s32 j;

    for (i = 0; i < 2; i++) {
        if (i == data_ov001_021a9bfc->mUnk_08 && data_ov001_021a9bfc->mUnk_24 != 0) {
            data_ov001_021a9bfc->mUnk_34[data_ov001_021a6c38[i][1]].mUnk_00 = 1;
            if (i == 1) {
                func_02124100(0, 14, data_ov001_021a9bfc->mUnk_4c, data_ov001_021a9bfc->mUnk_34,
                              data_ov001_021a9bfc->mUnk_44);
            }
            for (j = 0; j < data_ov001_021a6c30[i]; j++) {
                func_02124a20(data_ov001_021a6c1c[i][j], 14, data_ov001_021a9bfc->mUnk_38,
                              data_ov001_021a9bfc->mUnk_44);
            }
        } else {
            data_ov001_021a9bfc->mUnk_34[data_ov001_021a6c38[i][1]].mUnk_00 = 0;
            if (i == 1) {
                func_02124100(0, 15, data_ov001_021a9bfc->mUnk_4c, data_ov001_021a9bfc->mUnk_34,
                              data_ov001_021a9bfc->mUnk_44);
            }
            for (j = 0; j < data_ov001_021a6c30[i]; j++) {
                func_02124a20(data_ov001_021a6c1c[i][j], 15, data_ov001_021a9bfc->mUnk_38,
                              data_ov001_021a9bfc->mUnk_44);
            }
        }
    }
}

void func_ov001_0219d6ac(void) {
    s32 i;

    for (i = 0; i < 2; i++) {
        if (data_ov001_021a9bfc->mUnk_08 == 1) {
            if (data_ov001_021a9bfc->mUnk_28[i] > 0) {
                data_ov001_021a9bfc->mUnk_34[data_ov001_021a6c20[0][i]].mUnk_00 = 1;
                data_ov001_021a9bfc->mUnk_34[data_ov001_021a6c20[1][i]].mUnk_00 = 1;
                data_ov001_021a9bfc->mUnk_28[i]--;
            } else {
                data_ov001_021a9bfc->mUnk_34[data_ov001_021a6c20[0][i]].mUnk_00 = 0;
                data_ov001_021a9bfc->mUnk_34[data_ov001_021a6c20[1][i]].mUnk_00 = 1;
            }
        } else {
            data_ov001_021a9bfc->mUnk_34[data_ov001_021a6c20[0][i]].mUnk_00 = 0;
            data_ov001_021a9bfc->mUnk_34[data_ov001_021a6c20[1][i]].mUnk_00 = 0;
        }
    }
}

void func_ov001_0219d620(void) {
    data_ov001_021a9bfc->mUnk_00 = data_ov001_021a9bfc->mUnk_04;
    switch (data_ov001_021a9bfc->mUnk_00) {
        case 0:
            func_ov001_0219de18();
            break;
        case 1:
            func_ov001_0219dd94();
            break;
        case 2:
            func_ov001_0219dd74();
            break;
        case 3:
            func_ov001_0219dadc();
            break;
        case 4:
            func_ov001_0219daa0();
            break;
        case 5:
            func_ov001_0219d998();
            break;
        case 6:
            func_ov001_0219d934();
            break;
    }
    func_ov001_0219d858();
    func_ov001_0219d810();
    func_ov001_0219d730();
    func_ov001_0219d6ac();
    func_02124c30(data_ov001_021a9bfc->mUnk_44, data_ov001_021a9bfc->mUnk_38, data_ov001_021a9bfc->mUnk_4c,
                  func_ov001_0219e90c(), data_ov001_021a9bfc->mUnk_34);
}

void func_ov001_0219d600(void) {
    func_0214a40c((u32 *) ((u32 *) (u32) (((u32) 0x04001050u))), (u32) (0), 2, (u32) (6), 10);
    return;
}

void func_ov001_0219d5dc(void) {
    Unk021a8cd0 local = data_ov001_021a8cd0;

    func_ov001_02192eac((UnkFunc **) (local.mUnk_00));
}
