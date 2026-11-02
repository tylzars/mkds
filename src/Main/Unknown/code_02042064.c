#include "Main/Unknown/code_02042064.h"
#include "Main/Unknown/unk_021759c0.h"

#include "Main/Unknown/code_02042fd8.h"
#include "Main/Unknown/code_020429c8.h"
#include "Main/Unknown/code_020431bc.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/code_0205e000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_020472a8.h"
#include "code_02135014.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"

#pragma thumb on

Unk02175620_74 *func_020423fc(u32 param_1) {
    return &data_02175620->mUnk_74[param_1];
}

#pragma thumb off

#pragma thumb on
void func_0204236c(void) {
    void *h;
    Unk02175620_74 *e;
    Unk02175620_d8 **q;
    u16 i;
    u16 j;

    h = func_020364e0(func_020364e8());
    i = 0;
    for (j = 0; j < 8; j++) {
        data_02175620->mUnk_d8[j] = 0;
    }
    for (i = 0; i < data_02175620->mUnk_78; i++) {
        e = func_020423fc(i);
        if (e->mUnk_44 == 3) {
            q = &data_02175620->mUnk_d8[(s16) e->mUnk_3c];
            while (*q != 0) {
                q = &(*q)->mUnk_04;
            }
            *q = func_02036bec(h, 8);
            (*q)->mUnk_00 = e;
            (*q)->mUnk_04 = 0;
        }
    }
}
#pragma thumb off

#pragma thumb on

void func_02042320(void) {
    u16 count;
    u16 i;
    count = 0;
    for (i = 0; i < data_02175620->mUnk_78; i++) {
        if (func_020423fc(i)->mUnk_44 == 4) {
            count++;
        }
    }
    data_02175620->mUnk_102 = count;
}

void func_020422c4(void) {
    u8 count;
    u16 i;
    count = 0;
    if (data_021759c0->mUnk_08 == 4) {
        for (i = 0; i < data_02175620->mUnk_78; i++) {
            if (func_020423fc(i)->mUnk_44 == 2) {
                count++;
            }
        }
    }
    data_02175620->mUnk_10f = count;
}

#pragma thumb off

#pragma thumb on
s32 func_02042280(void *a, ...) {
    data_02175620->mUnk_78 = func_020431a4(&a);
    if (data_02175620->mUnk_78 == 0) {
        data_02175620->mUnk_74 = 0;
    } else {
        data_02175620->mUnk_74 = a;
    }
    func_0204236c();
    func_02042320();
    func_020422c4();
    return 1;
}

s32 func_02042170(void *a, ...) {
    u16 i;
    Unk02175620_7c *e;

    data_02175620->mUnk_80 = func_020431a4(&a);
    if (data_02175620->mUnk_80 == 0) {
        data_02175620->mUnk_7c = 0;
        return 1;
    }
    data_02175620->mUnk_7c = a;
    data_02175620->mUnk_c4 = 0;
    data_02175620->mUnk_c8 = 0;
    data_02175620->mUnk_cc = 0;
    data_02175620->mUnk_d0 = 0;
    for (i = 0; i < data_02175620->mUnk_80; i++) {
        e = data_02175620->mUnk_7c + i;
        if (data_02175620->mUnk_c4 == 0 && e->mUnk_4a == 1) {
            data_02175620->mUnk_c4 = e;
        }
        if (data_02175620->mUnk_c8 == 0 && e->mUnk_4a == 2) {
            data_02175620->mUnk_c8 = e;
        }
        if (data_02175620->mUnk_cc == 0 && e->mUnk_3e == 6) {
            data_02175620->mUnk_cc = e;
        }
        if (data_021759c0->mUnk_08 == 2 && data_02175620->mUnk_d0 == 0 && e->mUnk_3e == 7) {
            data_02175620->mUnk_d0 = e;
        }
        if (data_021759c0->mUnk_08 == 4 && data_02175620->mUnk_d4 == 0 && e->mUnk_3e == 8) {
            data_02175620->mUnk_d4 = e;
        }
    }
    return 1;
}

void func_02042064(void *a) {
    char v1[0x100];
    Unk02042064 *d;
    Unk02175620 *p;
    s32 *q;
    u8 *b;
    s32 i;
    u16 j;

    switch (data_021759c0->mUnk_08) {
        case 4:
            if (data_021759c0->mUnk_00c == 6) {
                d = func_02047974("/course_map.nkm");
            } else {
                snprintf(v1, 0x100, "/MissionRun/%s_tool.nkm", data_021759c0->mUnk_048);
                d = func_02047974(v1);
            }
            break;
        case 5:
            d = func_02047974("/Net/net_course_map.nkm");
            if (d == 0) {
                d = func_02047974("/course_map.nkm");
            }
            break;
        default:
            d = func_02047974("/course_map.nkm");
            break;
    }
    p = func_020431bc((u32) a);
    data_02175620 = p;
    p->mUnk_10c = d->mUnk_04;
    q = d->mUnk_08;
    b = (u8 *) d + d->mUnk_06;
    for (i = 0; i < 17; i++) {
        if (data_usa_0215407c[i](b + *q) != 0) {
            q++;
        }
    }
    func_02042fd8(a);
    func_020429c8(a);
    data_02175620->mUnk_9c = 0;
    for (j = 0; j < data_02175620->mUnk_50; j++) {
        if (data_02175620->mUnk_4c[j].mUnk_0a > data_02175620->mUnk_9c) {
            data_02175620->mUnk_9c = data_02175620->mUnk_4c[j].mUnk_0a;
        }
    }
}
#pragma thumb off
