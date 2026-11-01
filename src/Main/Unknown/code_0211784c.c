#include "Main/Unknown/code_0211784c.h"
#include "Main/Unknown/code_02118000.h"
#include "Main/Unknown/code_02117000.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_021281b4.h"
#include "Main/Unknown/code_0211f378.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_02118088.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "00/code_02182fdc.h"
#include "code_0201ea58.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_02117db0.h"
#include "Main/Unknown/code_02118148.h"
#include "Main/Unknown/code_021185d4.h"
#include "Main/Unknown/code_021185ec.h"
#include "Main/Unknown/unk_0217d000.h"

#pragma thumb on

void func_021178b0(void) {
    Unk02175628Index n;
    s32 s;
    s32 t;
    s32 d;
    int b;
    int a;
    u16 x;
    Unk02175628 *p;
    Unk02175628 *q;

    s = -1;
    n = UNK_02175628_INDEX_8;
    func_021184d4();
    func_02118414();
    b = 0;
    a = 0;
    p = &data_02175674[n];
    x = data_02175674[n].mUnk_00;
    if (x == 0 && data_02175680[n].mUnk_00 < 5) {
        a = 1;
    }
    if (a == 0 && data_0217567c[n].mUnk_00 == 0 && x != 0) {
        b = 1;
    }
    if (b != 0) {
        s = func_0201ea84(data_0217d360->mUnk_14, data_02175670[n].mUnk_00, data_02175672[n].mUnk_00);
    }
    q = &data_02175628[n];
    if ((u16) (data_02175628[n].mUnk_00 & 2) != 0) {
        goto L1;
    }
    b = 0;
    a = 0;
    x = p->mUnk_00;
    if (x == 0 && data_02175680[n].mUnk_00 < 5) {
        a = 1;
    }
    if (a == 0 && data_0217567c[n].mUnk_00 == 0 && x != 0) {
        b = 1;
    }
    if (b == 0) {
        goto L2;
    }
    if (func_02128210(data_02175670[n].mUnk_00, data_02175672[n].mUnk_00) == 0) {
        goto L2;
    }
L1:
    if (func_021185d4() != 0) {
        return;
    }
    func_021281c8(0xe);
    switch (data_0217d360->mUnk_3c) {
        case 0:
        case 1:
            func_02118024();
            data_0217d360->mUnk_88 = 2;
            func_02128310(0);
            return;
        case 2:
        case 3:
        case 4:
            if (data_0217b488->mUnk_08 == 2 || data_0217b488->mUnk_08 == 3) {
                func_02118088();
                if (*(vu16 *) 0x027ffc40 == 2) {
                    func_021281c8(-1);
                }
                func_02128310(0);
                return;
            }
            func_02118024();
            data_0217d360->mUnk_88 = 2;
            if (data_0217d360->mUnk_3c != 2) {
                func_02128310(1);
                if (*(vu16 *) 0x027ffc40 == 2) {
                    func_0211f378();
                }
            } else {
                func_02128310(0);
            }
            return;
    }
    return;
L2:
    if ((u32) s <= 7) {
        d = data_0215c8dc[s];
        if (data_0217d360->mUnk_48[d] == 0) {
            if (*(vu16 *) 0x027ffc40 != 2) {
                func_0212ecc0(&data_0217d068, 0, 0x16);
            }
            return;
        }
        if (data_0217d360->mUnk_44 == d) {
            data_0217d360->mUnk_68 = 0;
        }
        data_0217d360->mUnk_44 = d;
        func_02118184();
        return;
    }
    if ((u16) (q->mUnk_00 & 1) != 0) {
        func_02118184();
        data_0217d360->mUnk_68 = 0;
        return;
    }
    if (func_020ae408(8, 0x40) != 0) {
        a = data_0217d360->mUnk_44;
        b = data_0215c84c[a];
        if (b != 0) {
            t = a + b;
            if (data_0217d360->mUnk_48[t] != 0) {
                data_0217d360->mUnk_44 = t;
                func_02118400();
                if (*(vu16 *) 0x027ffc40 != 2) {
                    func_0212ecc0(&data_0217d068, 0, 0);
                }
            }
        }
    } else if (func_020ae408(8, 0x80) != 0) {
        a = data_0217d360->mUnk_44;
        b = data_0215c7fc[a];
        if (b != 0) {
            t = a + b;
            if (data_0217d360->mUnk_48[t] != 0) {
                data_0217d360->mUnk_44 = t;
                func_02118400();
                if (*(vu16 *) 0x027ffc40 != 2) {
                    func_0212ecc0(&data_0217d068, 0, 0);
                }
            }
        }
    } else if (func_020ae408(8, 0x20) != 0) {
        a = data_0217d360->mUnk_44;
        b = data_0215c80c[a];
        if (b != 0) {
            t = a + b;
            if (data_0217d360->mUnk_48[t] != 0) {
                data_0217d360->mUnk_44 = t;
                func_02118400();
                if (*(vu16 *) 0x027ffc40 != 2) {
                    func_0212ecc0(&data_0217d068, 0, 0);
                }
            }
        }
    } else if (func_020ae408(8, 0x10) != 0) {
        a = data_0217d360->mUnk_44;
        b = data_0215c82c[a];
        if (b != 0) {
            t = a + b;
            if (data_0217d360->mUnk_48[t] != 0) {
                data_0217d360->mUnk_44 = t;
                func_02118400();
                if (*(vu16 *) 0x027ffc40 != 2) {
                    func_0212ecc0(&data_0217d068, 0, 0);
                }
            }
        }
    }
}

void func_0211784c(void) {
    func_021184d4();
    func_02118414();
    if (data_0217d360->mUnk_38 == 5) {
        data_0217d360->mUnk_68 = 1;
    }
    data_0217d360->mUnk_38 = data_0217d360->mUnk_38 + 1;
    if (data_0217d360->mUnk_38 >= 10 && func_021185d4() == 0) {
        if (data_0217d360->mUnk_3c == 0) {
            func_02118148();
            return;
        }
        func_021185ec();
        data_0217d360->mUnk_88 = 1;
        func_02118024();
    }
}

#pragma thumb off
