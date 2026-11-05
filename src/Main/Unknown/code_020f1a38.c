#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020f1a38.h"

#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020f1d40.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/code_02104a0c.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/unk_0217c000.h"

#pragma thumb on

void func_020f1b10(void) {
    Unk0217bc34 *p;
    enum { K0 } i;
    enum { K1 } j;
    s32 m;
    u32 v;

    p = HeapAlloc(GetHeap(func_020364e8()), 0x930);
    data_0217bc34 = p;
    p[0] = data_02159934;
    p[1] = data_02159854;
    p[2] = data_0215978c;
    p[3] = data_021596bc;
    p[4] = data_021599f8;
    p[5] = data_02159cdc;
    p[6] = data_02159abc;
    p[7] = data_02159f84;
    p[8] = data_0215a4dc;
    p[9] = data_02159e70;
    p[10] = data_0215a308;
    p[11] = data_0215a244;
    p[12] = data_02159dac;
    p[13] = data_0215a5a4;
    for (i = 0; i < 0xe; i++) {
        data_0217bc34[i].mUnk_4c = func_020f1d40(i);
        v = data_0217bc34[i].mUnk_58;
        if (v != 0) {
            v = ((u32(*)(void)) v)();
        } else {
            v = data_0217ca6c[1].mUnk_20;
        }
        data_0217bc34[i].mUnk_a4 = v;
    }
    m = data_021759c0->mMode;
    switch (m) {
        case 2:
            data_0217bc34[8].mUnk_04 = 8;
            break;
        case 4:
            for (j = 0; j < 0xe; j++) {
                data_0217bc34[j].mUnk_04 = data_0217bc34[j].mUnk_08;
            }
            break;
        case 5:
            data_0217bc34[3].mUnk_04 = 0x20;
            break;
    }
}

void func_020f1a38(void) {
    s32 a[14];
    enum { K0 } i;
    enum { K1 } j;
    s32 n;

    for (i = 0; i < 0xe; i++) {
        data_0217bc34[i].mUnk_10 = data_0217bc34[i].mUnk_04 - 1;
        a[i] = 1;
    }
    for (j = 0; j < 0x12; j++) {
        if (data_0217bc48[j].mUnk_00 != 0) {
            i = data_0217bc48[j].mUnk_08;
            n = data_0217bc48[j].mUnk_0c;
            if (a[i] < n) {
                a[i] = n;
            }
        }
    }
    for (i = 0; i < 0xe; i++) {
        data_0217bc34[i].mUnk_10 = data_0217bc34[i].mUnk_10 + a[i];
        data_0217bc34[i].mUnk_0c = data_0217bc34[i].mUnk_10;
    }
    if (data_021759c0->mMode == 5) {
        for (i = 0; i < 0xe; i++) {
            data_0217bc34[i].mUnk_0c = data_0217bc34[i].mUnk_0c + 3;
        }
    } else {
        data_0217bc34[2].mUnk_0c = data_0217bc34[2].mUnk_0c + 0x10;
    }
}

#pragma thumb off
