#include "01/code_0219b574.h"
#include "01/code_0219bb48.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128244.h"
#include "Main/Unknown/code_0212775c.h"
#include "01/code_0219b81c.h"
#include "01/code_0219b834.h"
#include "01/code_0219c000.h"
#include "01/unk_021a6000.h"
#include "Main/Unknown/code_02087000.h"
#include "Main/Unknown/code_0212b000.h"

void func_ov001_0219b7c8(void) {
    s32 r;

    if (func_021277ac() == 0) {
        return;
    }
    r = func_02127794();
    switch (r) {
        case 0:
            func_ov001_0219bfc0();
            data_ov001_021a9bf4->mUnk_6c = 1;
            func_ov001_0219c3a8();
            func_021282c8();
            break;
        case -1:
        case 1:
            func_0212b7d8();
            func_ov001_0219c458();
            break;
    }
}

void func_ov001_0219b64c(void) {
    s32 flag;
    s16 v;
    s16 w;
    u16 n;
    s32 i;

    flag = data_ov001_021a9bf4->mUnk_6c == 1;
    data_ov001_021a9bf4->mUnk_50++;
    v = func_020ae4c0(1, 0, ~0xbf, data_ov001_021a9bf4->mUnk_50, 10);
    if (flag) {
        n = data_ov001_021a9bf4->mUnk_04->mUnk_06;
        data_ov001_021a9bf4->mUnk_58 = v;
        data_ov001_021a9bf4->mUnk_30[0].mUnk_06 = v;
        data_ov001_021a9bf4->mUnk_30[2].mUnk_06 = v;
        data_ov001_021a9bf4->mUnk_30[1].mUnk_06 = v;
        data_ov001_021a9bf4->mUnk_30[4].mUnk_06 = v;
        data_ov001_021a9bf4->mUnk_30[3].mUnk_06 = v;
        data_ov001_021a9bf4->mUnk_30[5].mUnk_06 = v;
        data_ov001_021a9bf4->mUnk_30[n].mUnk_06 = v;
        data_ov001_021a9bf4->mUnk_30[n + 1].mUnk_06 = v;
        data_ov001_021a9bf4->mUnk_30[n + 2].mUnk_06 = v;
        data_ov001_021a9bf4->mUnk_30[n + 3].mUnk_06 = v;
        data_ov001_021a9bf4->mUnk_30[n + 4].mUnk_06 = v;
        data_ov001_021a9bf4->mUnk_30[n + 5].mUnk_06 = v;
    }
    n = data_ov001_021a9bf4->mUnk_10->mUnk_06;
    w = -func_02128244(data_ov001_021a9bf4->mUnk_50);
    data_ov001_021a9bf4->mUnk_5c = v;
    for (i = 0; i < 6; i++) {
        data_ov001_021a9bf4->mUnk_34[data_ov001_021a6b6c[i]].mUnk_06 = v;
    }
    data_ov001_021a9bf4->mUnk_34[10].mUnk_06 = w;
    data_ov001_021a9bf4->mUnk_34[11].mUnk_06 = w;
    for (i = 0; i < 5; i++) {
        data_ov001_021a9bf4->mUnk_34[n + data_ov001_021a6b54[i]].mUnk_06 = v;
    }
    for (i = 0; i < 2; i++) {
        data_ov001_021a9bf4->mUnk_34[data_ov001_021a6b3c[i]].mUnk_06 = v;
        data_ov001_021a9bf4->mUnk_34[data_ov001_021a6b38[i]].mUnk_06 = v;
    }
    data_ov001_021a9bf4->mUnk_34[n + 5].mUnk_06 = w;
}

int func_ov001_0219b574(void) {
    data_ov001_021a9bf4->mUnk_48 = data_ov001_021a9bf4->mUnk_4c;
    switch (data_ov001_021a9bf4->mUnk_48) {
        case 0:
            func_ov001_0219ba3c();
            break;
        case 1:
            func_ov001_0219b9dc();
            break;
        case 2:
            func_ov001_0219b874();
            break;
        case 3:
            func_ov001_0219b84c();
            break;
        case 4:
            func_ov001_0219b834();
            break;
        case 5:
            func_ov001_0219b81c();
            break;
        case 6:
            func_ov001_0219b7c8();
            break;
        case 7:
            func_ov001_0219b64c();
            break;
    }
    func_0212b80c();
    func_ov001_0219c358();
    func_02124c30(data_ov001_021a9bf4->mUnk_04, data_ov001_021a9bf4->mUnk_00, data_ov001_021a9bf4->mUnk_08,
                  (void *) data_ov001_021a9bf4->mUnk_64, data_ov001_021a9bf4->mUnk_30);
    func_02124c30(data_ov001_021a9bf4->mUnk_10, data_ov001_021a9bf4->mUnk_0c, data_ov001_021a9bf4->mUnk_18,
                  (void *) data_ov001_021a9bf4->mUnk_68, data_ov001_021a9bf4->mUnk_34);
    if (data_ov001_021a9bf4->mUnk_48 == 7) {
        switch (data_ov001_021a9bf4->mUnk_6c) {
            case 1:
                if (data_ov001_021a9bf4->mUnk_50 >= 10) {
                    if (func_02128274() != 0) {
                        return 1;
                    }
                }
                break;
            case 2:
                if (data_ov001_021a9bf4->mUnk_50 >= 10) {
                    return 2;
                }
                break;
        }
    }
    return 0;
}
