#include "01/code_0219348c.h"
#include "01/code_02195000.h"
#include "01/unk_021a6000.h"
#include "01/unk_021a8000.h"
#include "Main/Unknown/code_02057000.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_02126000.h"
#include "Main/Unknown/code_02125f54.h"
#include "code_0201ea58.h"

void func_ov001_02193774(void) {
    Unk02175628Index idx = UNK_02175628_INDEX_8;
    u32 result = -1;
    s32 b = 0;
    s32 a = 0;
    u16 flagA;
    s32 old;
    s32 flagB;

    if (data_02175628[idx].mUnk_4c == 0 && data_02175628[idx].mUnk_58 < 5) {
        a = 1;
    }
    if (a == 0 && data_02175628[idx].mUnk_54 == 0 && data_02175628[idx].mUnk_4c != 0) {
        b = 1;
    }
    if (b != 0) {
        result = func_0201ea84(data_ov001_021a9bd4->mUnk_34, data_02175628[idx].mUnk_48, data_02175628[idx].mUnk_4a);
    }
    flagA = data_02175628[idx].mUnk_00 & 2;
    if (flagA == 0) {
        s32 b2 = 0;
        s32 a2 = 0;
        if (data_02175628[idx].mUnk_4c == 0 && data_02175628[idx].mUnk_58 < 5) {
            a2 = 1;
        }
        if (a2 == 0 && data_02175628[idx].mUnk_54 == 0 && data_02175628[idx].mUnk_4c != 0) {
            b2 = 1;
        }
        if (b2 != 0 && func_02128210(data_02175628[idx].mUnk_48, data_02175628[idx].mUnk_4a) != 0) {
            goto leave;
        }
    } else {
    leave:
        data_ov001_021a9bd4->mUnk_04 = 5;
        data_ov001_021a9bd4->mUnk_10 = 4;
        func_02128310(1);
        return;
    }
    flagB = data_02175628[idx].mUnk_00 & 1;
    if ((u16) flagB != 0 || result <= 2) {
        old = data_ov001_021a9bd4->mUnk_08;
        if ((u16) flagB == 0) {
            switch (result) {
                case 0:
                    data_ov001_021a9bd4->mUnk_08 = 0;
                    break;
                case 1:
                    data_ov001_021a9bd4->mUnk_08 = 1;
                    break;
                case 2:
                    data_ov001_021a9bd4->mUnk_08 = 2;
                    break;
            }
        }
        data_ov001_021a9bd4->mUnk_04 = 4;
        switch (data_ov001_021a9bd4->mUnk_08) {
            case 0:
                data_ov001_021a9bd4->mUnk_10 = 1;
                break;
            case 1:
                data_ov001_021a9bd4->mUnk_10 = 2;
                break;
            case 2:
                break;
        }
        if (data_ov001_021a9bd4->mUnk_08 == old) {
            data_ov001_021a9bd4->mUnk_14 = 0;
        }
        func_02105ac0(5);
    } else if (func_020ae408(8, 0x40) != 0) {
        data_ov001_021a9bd4->mUnk_08--;
        if (data_ov001_021a9bd4->mUnk_08 < 0) {
            data_ov001_021a9bd4->mUnk_08 = 2;
        }
        func_02105ac0(0);
    } else if (func_020ae408(8, 0x80) != 0) {
        data_ov001_021a9bd4->mUnk_08++;
        if (data_ov001_021a9bd4->mUnk_08 > 2) {
            data_ov001_021a9bd4->mUnk_08 = 0;
        }
        func_02105ac0(0);
    }
}

void func_ov001_02193730(void) {
    data_ov001_021a9bd4->mUnk_0c++;
    if (data_ov001_021a9bd4->mUnk_0c >= 10) {
        data_ov001_021a9bd4->mUnk_04 = 5;
        data_ov001_021a9bd4->mUnk_0c = 0;
        if (data_ov001_021a9bd4->mUnk_08 == 2) {
            func_021282c8();
        }
    } else if (data_ov001_021a9bd4->mUnk_0c >= 5) {
        data_ov001_021a9bd4->mUnk_14 = 1;
    }
}

void func_ov001_021935f8(void) {
    s32 amount;
    s32 i;
    s32 j;

    if (func_ov001_02192e84() == -1 && data_ov001_021a9bd4->mUnk_10 == 4) {
        func_ov001_02192e78(0);
    }
    data_ov001_021a9bd4->mUnk_0c++;
    if (data_ov001_021a9bd4->mUnk_0c <= 10) {
        amount = func_020ae4c0(1, 0, 250, data_ov001_021a9bd4->mUnk_0c, 10);
    } else {
        amount = 250;
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < data_ov001_021a65e4[i]; j++) {
            if (i == 1) {
                data_ov001_021a9bd4->mUnk_20[data_ov001_021a65f0[i][j]].mUnk_04 = amount;
            } else {
                data_ov001_021a9bd4->mUnk_20[data_ov001_021a65f0[i][j]].mUnk_04 = -amount;
            }
        }
    }
    if (data_ov001_021a9bd4->mUnk_10 == 1) {
        data_ov001_021a9bd4->mUnk_18 = func_020ae4c0(1, 0, 50, data_ov001_021a9bd4->mUnk_0c, 10);
    }
    if (data_ov001_021a9bd4->mUnk_0c >= 10 && (data_ov001_021a9bd4->mUnk_08 != 2 || func_02128274() != 0) &&
        func_ov001_02192e84() == -1) {
        if (data_ov001_021a9bd4->mUnk_08 == 2) {
            data_ov001_021a9bd4->mUnk_04 = 6;
            data_ov001_021a9bd4->mUnk_0c = 0;
            func_0212611c(func_020b3f7c(data_ov001_021a9bd4->mUnk_38, 3),
                          func_020b3f7c(data_ov001_021a9bd4->mUnk_3c, 0),
                          func_020b3f7c(data_ov001_021a9bd4->mUnk_3c, 1), 1);
        } else {
            func_ov001_02192ea0(data_ov001_021a9bd4->mUnk_10);
        }
    }
}

void func_ov001_02193578(void) {
    if (func_02125f54() != 0) {
        func_02125fc0();
        return;
    }
    if (func_02125f88() != 0) {
        if (func_02125f60() == 0) {
            func_0212611c(func_020b3f7c(data_ov001_021a9bd4->mUnk_38, 4),
                          func_020b3f7c(data_ov001_021a9bd4->mUnk_3c, 0),
                          func_020b3f7c(data_ov001_021a9bd4->mUnk_3c, 1), 1);
            data_ov001_021a9bd4->mUnk_04 = 7;
        } else {
            data_ov001_021a9bd4->mUnk_04 = 1;
        }
    }
}

void func_ov001_02193514(void) {
    if (func_02125f54() != 0) {
        func_02125fc0();
        return;
    }
    if (func_02125f88() != 0) {
        if (func_02125f60() == 0) {
            func_02057130();
            data_ov001_021a9bd4->mUnk_04 = 8;
            func_02126248((u32) func_020b3f7c(data_ov001_021a9bd4->mUnk_38, 5), 1, 1, 1, 0, 1);
        } else {
            data_ov001_021a9bd4->mUnk_04 = 1;
        }
    }
}

void func_ov001_0219348c(void) {
    s32 flag;

    if (func_02125f6c() != 0) {
        func_0212ecc0(&data_0217d068, 0, 0x22);
    }
    if (data_0217aa08->mUnk_28 == 0) {
        if (data_021759d4->mUnk_0c != 0) {
            flag = data_021759d4->mUnk_10;
        } else {
            flag = 0;
        }
    } else {
        flag = 1;
    }
    if (flag == 0 && func_02125fa4() != 0) {
        data_ov001_021a9bd4->mUnk_04 = 9;
        func_02125ebc(0x21);
        func_02126230(func_020b3f7c(data_ov001_021a9bd4->mUnk_38, 6), func_020b3f7c(data_ov001_021a9bd4->mUnk_3c, 4));
    }
}
