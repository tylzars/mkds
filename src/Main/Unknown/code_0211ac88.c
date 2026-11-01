#include "Main/Unknown/code_0211ac88.h"
#include "Main/Unknown/code_0211b23c.h"
#include "Main/Unknown/unk_0215c000.h"
#include "Main/Unknown/code_0211d4a8.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/unk_0217d000.h"
#include "code_0201ea58.h"
#include "Main/Unknown/code_0202b000.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_0211d650.h"
#include "Main/Unknown/code_021281b4.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128244.h"
#include "code_0212df7c.h"

#pragma thumb on

void func_0211b07c(void) {
    Unk0217d368 *p;
    s32 i;
    s16 b;
    s32 j;
    s32 c;
    func_0211c818();
    func_0211c14c();
    data_0217d368->mUnk_38++;
    p = data_0217d368;
    c = func_020ae4c0(1, -192, 0, p->mUnk_38, 10);
    b = p->mUnk_58 + c;
    p->mUnk_5c = b;
    c = data_0217d368->mUnk_04->mUnk_06;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 2; j++) {
            data_0217d368->mUnk_14[data_0215cd88[i][j]].mUnk_06 = b;
            data_0217d368->mUnk_14[data_0215cdb0[i][j]].mUnk_06 = b;
            data_0217d368->mUnk_14[data_0215cdc4[i][j]].mUnk_06 = b;
        }
        for (j = 0; j < 2; j++) {
            data_0217d368->mUnk_14[c + data_0215cd4c[i].mUnk_00[j]].mUnk_06 = b;
        }
    }
    data_0217d368->mUnk_14[c + 10].mUnk_06 = b;
    data_0217d368->mUnk_14[c + 12].mUnk_06 = b;
    data_0217d368->mUnk_14[34].mUnk_06 = b;
    data_0217d368->mUnk_14[37].mUnk_06 = b;
    data_0217d368->mUnk_14[35].mUnk_06 = b;
    data_0217d368->mUnk_14[38].mUnk_06 = b;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            data_0217d368->mUnk_14[data_0215ccac[i][j]].mUnk_06 = b;
        }
    }
    if (data_021759d0->mUnk_20 != 2) {
        c += 8;
        data_0217d368->mUnk_14[c].mUnk_06 = b;
        data_0217d368->mUnk_14[30].mUnk_06 = b;
        data_0217d368->mUnk_14[31].mUnk_06 = b;
    }
    if (data_0217d368->mUnk_38 >= 10) {
        func_0211baac();
    }
}

void func_0211afd0(void) {
    s16 a;
    s32 b;
    func_0211c818();
    func_0211c14c();
    data_0217d368->mUnk_38++;
    a = -func_0212825c(data_0217d368->mUnk_38);
    b = data_0217d368->mUnk_04->mUnk_06;
    if (data_021759d0->mUnk_20 != 2) {
        data_0217d368->mUnk_14[0x28].mUnk_06 = a;
        data_0217d368->mUnk_14[0x29].mUnk_06 = a;
        data_0217d368->mUnk_14[b + 13].mUnk_06 = a;
    } else {
        data_0217d368->mUnk_14[0x2a].mUnk_06 = a;
        data_0217d368->mUnk_14[b + 14].mUnk_06 = a;
    }
    switch (data_0217d368->mUnk_2c) {
        case 0:
        case 1:
            if (data_0217d368->mUnk_38 >= 10 && func_02128294() != 0) {
                func_0211ba98();
                return;
            }
            break;
        default:
            if (data_0217d368->mUnk_38 >= 10) {
                func_0211ba98();
            }
            break;
    }
}

void func_0211acec(void) {
    Unk02175628 *p;
    Unk02175628 *q;
    Unk02175628 *r;
    u32 a;
    s32 c;
    s32 b;
    Unk02175628Index i;
    u32 d;
    u16 x;
    a = -1;
    i = UNK_02175628_INDEX_8;
    func_0211c818();
    func_0211c14c();
    c = 0;
    b = 0;
    p = &data_02175674[i];
    x = data_02175674[i].mUnk_00;
    if (x == 0 && data_02175680[i].mUnk_00 < 5) {
        b = 1;
    }
    if (b == 0 && data_0217567c[i].mUnk_00 == 0 && x != 0) {
        c = 1;
    }
    if (c != 0) {
        r = &data_02175672[i];
        q = &data_02175670[i];
        a = func_0201ea84(data_0217d368->mUnk_08, data_02175670[i].mUnk_00, data_02175672[i].mUnk_00);
        if (a != 0x13) {
            a = func_0201ea84(data_0217d368->mUnk_08, q->mUnk_00, r->mUnk_00 - data_0217d368->mUnk_58);
            if (a == 0x13) {
                a = -1;
            }
        }
    }
    r = &data_02175628[i];
    if ((u16) (r->mUnk_00 & 2) == 0) {
        c = 0;
        b = 0;
        x = p->mUnk_00;
        if (x == 0 && data_02175680[i].mUnk_00 < 5) {
            b = 1;
        }
        if (b == 0 && data_0217567c[i].mUnk_00 == 0 && x != 0) {
            c = 1;
        }
        if (c == 0 || func_02128210(data_02175670[i].mUnk_00, data_02175672[i].mUnk_00) == 0) {
            goto chain;
        }
    }
    switch (data_0217d368->mUnk_2c) {
        case 0:
        case 1:
            func_021281c8(0xe);
            func_0211b9d8();
            data_0217d368->mUnk_b8 = 2;
            func_02128310(0);
            func_0202b7c0(1);
            break;
    }
    goto end;
chain:
    if (a <= 4) {
        d = data_0215cdd8[a];
        if (func_0211d650() == 8 && d == 1) {
            goto end;
        }
        data_0217d368->mUnk_60 = d;
        data_0217d368->mUnk_7c = 0;
        func_0211cb6c(1);
    } else if (a - 5 <= 4) {
        d = data_0215cd24[a];
        if (func_0211d650() == 8 && d == 1) {
            goto end;
        }
        data_0217d368->mUnk_60 = d;
        data_0217d368->mUnk_7c = 0;
        func_0211ccac(1);
    } else if (a == 0x13) {
        if (data_0217d368->mUnk_7c != 0) {
            data_0217d368->mUnk_84 = 0;
        }
        data_0217d368->mUnk_7c = 1;
        func_0211ba58();
    } else if (a - 10 <= 4) {
        d = data_0215cd74[a].mUnk_00;
        if (func_0211d650() == 8 && d == 1) {
            goto end;
        }
        data_0217d368->mUnk_60 = d;
        data_0217d368->mUnk_7c = 0;
        func_0212ecc0(&data_0217d068, 0, 0);
    } else if ((u16) (r->mUnk_00 & 1) != 0) {
        if (data_0217d368->mUnk_7c != 0) {
            func_0211ba58();
            data_0217d368->mUnk_84 = 0;
        } else {
            func_0211d56c();
        }
    } else if (a == 0xf) {
        if (data_0217d368->mUnk_68[3] != 2) {
            data_0217d368->mUnk_60 = 3;
            data_0217d368->mUnk_7c = 0;
            func_0211ca8c();
        }
    } else if (a == 0x10) {
        if (data_0217d368->mUnk_68[3] != 2) {
            data_0217d368->mUnk_60 = 3;
            data_0217d368->mUnk_7c = 0;
            func_0211cafc();
        }
    } else if (func_020ae408(8, 0x40) != 0) {
        func_0211d4a8();
    } else if (func_020ae408(8, 0x80) != 0) {
        func_0211d56c();
    } else if (func_020ae408(8, 0x20) != 0) {
        if (data_0217d368->mUnk_7c == 0) {
            func_0211cb6c(1);
        }
    } else if (func_020ae408(8, 0x10) != 0) {
        if (data_0217d368->mUnk_7c == 0) {
            func_0211ccac(1);
        }
    } else if (func_020ae408(8, 0x200) != 0) {
        func_0211ca8c();
    } else if (func_020ae408(8, 0x100) != 0) {
        func_0211cafc();
    }
end:
    if (data_0217d368->mUnk_34 != 4) {
        func_0211bf94();
    }
}

void func_0211ac88(void) {
    func_0211c818();
    func_0211c14c();
    data_0217d368->mUnk_38++;
    if (data_0217d368->mUnk_38 == 5) {
        data_0217d368->mUnk_84 = 1;
    }
    if (data_0217d368->mUnk_38 >= 10) {
        if (data_0217d368->mUnk_2c == 3 || data_0217d368->mUnk_68[2] == 1) {
            func_0211ba1c();
            return;
        }
        func_0211b9d8();
        data_0217d368->mUnk_b8 = 1;
        func_0202b7c0(3);
    }
}

#pragma thumb off
