#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_02028864.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02025df4.h"
#include "Main/Unknown/code_02025e28.h"
#include "Main/Unknown/code_02028d9c.h"
#include "Main/Unknown/code_02028f20.h"
#include "Main/Unknown/code_02027e78.h"
#include "Main/Unknown/code_020291f0.h"
#include "Main/Unknown/code_02029440.h"
#include "Main/Unknown/code_02029890.h"
#include "Main/Unknown/code_0202bb80.h"
#include "Main/Unknown/code_0202c000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02056444.h"
#include "Main/Unknown/code_02148000.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/code_02077bc0.h"
#include "Main/Unknown/code_02078000.h"
#include "Main/Unknown/code_0211f394.h"
#include "Main/Unknown/code_0211f4b0.h"
#include "Main/Unknown/code_02116ec0.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_0212b928.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "code_02148950.h"
#include "Main/Unknown/unk_02161000.h"

#pragma optimize_for_size on

#pragma thumb on
void InitSelectKart(void *a, s32 b, void *c, void *d) {
    void *h;
    Unk02174e50_24 *p;
    Unk02174e50_24 e;
    Unk02174e50_24 f;
    SelectKart *g;
    s32 i;
    s32 m;
    s32 n;
    u32 v;
    void *w;
    h = CreateFrmHeapFromMaxFree(a);
    gSelectKart = HeapAlloc(h, 0x118);
    func_02028e00(gSelectKart, 0x118);
    gSelectKart->mHeap = h;
    gSelectKart->mMode = b;
    gSelectKart->mUnk_110 = -1;
    switch (func_02029930()->mUnk_108) {
        case 1:
            func_02025f80(&gSelectKart->mUnk_0ac[0], 1, 10, -0x80, 0);
            func_02025f80(&gSelectKart->mUnk_0ac[2], 1, 10, 0x60, 0);
            break;
        case 0:
            func_02025f80(&gSelectKart->mUnk_0ac[0], 0, 10, -0x80, 0);
            func_02025f80(&gSelectKart->mUnk_0ac[2], 0, 10, 0x60, 0);
            if (func_020280dc() == 0) {
                func_020789e4();
                func_02077f48(0);
            }
            break;
    }
    func_02025f80(&gSelectKart->mUnk_0ac[1], 0, 10, -0x40, 0);
    func_02025f80(&gSelectKart->mUnk_0ac[3], 0, 10, 0x40, 0);
    func_02025f80(&gSelectKart->mUnk_0ac[4], 0, 10, -0xc0, 0);
    gSelectKart->mUnk_080 = c;
    gSelectKart->mUnk_084 = d;
    if (gSelectKart->mMode != 0 || func_02029930()->mUnk_c8 == 3 || func_02029930()->mUnk_c8 == 2) {
        v = 1;
    } else {
        v = 0;
    }
    gSelectKart->mUnk_104 = v;
    if (gSelectKart->mUnk_104 != FALSE) {
        switch (gSelectKart->mMode) {
            case 0:
                m = 0;
                break;
            case 1:
                m = 1;
                break;
            case 2:
                m = 2;
                break;
        }
        func_0202c0d4(m, 1);
    }
    switch (gSelectKart->mMode) {
        case 0:
            gSelectKart->mUnk_0a0 = 0;
            break;
        case 1:
            gSelectKart->mUnk_0a0 = func_02028d9c();
            break;
        case 2:
            gSelectKart->mUnk_0a0 = func_020295e4();
            break;
    }
    if (func_020280dc() == 0) {
        gSelectKart->mUnk_088 = func_02047a28(gKartSelectBmgName);
        gSelectKart->mUnk_098 = func_02056444(gSelectKart->mHeap);
    }
    g = gSelectKart;
    g->mCharacterIndex = func_02029930()->mUnk_00[g->mUnk_0a0].mCharacterIndex;
    g = gSelectKart;
    g->mKartIndex = func_02029930()->mUnk_00[g->mUnk_0a0].mKartIndex;
    if (gSelectKart->mCharacterIndex == -1) {
        gSelectKart->mCharacterIndex = 0;
    }
    if (gSelectKart->mKartIndex == -1) {
        gSelectKart->mKartIndex = 0;
    }
    func_02029930()->mUnk_00[gSelectKart->mUnk_0a0].mKartIndex = -1;
    func_02029930()->mUnk_00[gSelectKart->mUnk_0a0].mUnk_14 = 0;
    gSelectKart->mUnk_09c = func_02025e34(gSelectKart->mKartIndex);
    if (func_020280dc() == 0) {
        g = gSelectKart;
        if (g->mUnk_104 == FALSE) {
            p = &g->mUnk_048;
            func_02025b20(p, gSelectCharacterGpMNcgrName2, gSelectCharacterGpMNcerName2, gSelectCharacterGpMONclrName2,
                          gSelectCharacterGpMBnclName2, NULL, NULL, func_02047a28);
            func_02025a50(0, gSelectKart->mHeap, p);
            func_02025b20(&e, gSelectCharacterGpTitleMNcgrName2, gSelectCharacterGpTitleMNcerName2, NULL,
                          gSelectCharacterGpTitleMBnclName2, NULL, NULL, func_02047a28);
            func_02124748(1, e.mUnk_08, (void *) e.mUnk_00, e.mUnk_0c, 0, 0, p->mUnk_08, p->mUnk_0c);
            func_02025b20(&f, gSelectCharacterGpNameMNcgrName2, gSelectCharacterGpNameMNcerName2, NULL,
                          gSelectCharacterGpNameMBnclName2, NULL, NULL, func_02047a28);
            func_02124748(data_usa_021537dc[gSelectKart->mCharacterIndex], f.mUnk_08, (void *) f.mUnk_00, f.mUnk_0c, 0,
                          2, p->mUnk_08, p->mUnk_0c);
            func_02124748(data_usa_021537dc[gSelectKart->mCharacterIndex], f.mUnk_08, (void *) f.mUnk_00, f.mUnk_0c, 0,
                          1, p->mUnk_08, p->mUnk_0c);
        }
    }
    if (func_020280dc() == 0) {
        func_020258d4(1, &gSelectKart->mUnk_024, gSelectKartSBNcgrName, gSelectKartSBNclrName, gSelectKartSNscrName, 3,
                      func_02047a28);
    }
    if (func_020280dc() == 0) {
        n = func_02148ca0();
        p = &gSelectKart->mUnk_064;
        func_02025b20(p, gSelectKartSNcgrName, gSelectKartSNcerName, gSelectKartSONclrName, gSelectKartSBnclName,
                      gSelectKartSBnllName, gSelectKartSBnblName, func_02047a28);
        func_02025a50(1, gSelectKart->mHeap, p);
        for (i = 0; i < 9; i++) {
            n -= func_02025a00(1, gSelectKart->mHeap, p, &data_usa_021537f4[i], n);
        }
        for (i = 0; i < 6; i++) {
            w = GetBmgEntry(gSelectKart->mUnk_088, data_usa_021537f4[i].mUnk_08);
            n = data_usa_021537f4[i].mUnk_00;
            func_0212426c(1, n, p->mUnk_14, w, p->mUnk_0c, p->mUnk_18);
            func_02124094(n, 1, p->mUnk_14, p->mUnk_18, p->mUnk_0c);
        }
        w = GetBmgEntry(func_02047a28(gCommonBmgName2), data_usa_021537f4[6].mUnk_08);
        i = data_usa_02153834[4];
        func_0212426c(1, i, p->mUnk_14, w, p->mUnk_0c, p->mUnk_18);
        func_02124100(i, 1, p->mUnk_14, p->mUnk_18, p->mUnk_0c);
        func_0212b928(gSelectKart->mHeap, (Nclr *) p->mUnk_04, 1);
        p->mUnk_18[2].mUnk_00 = 0;
        p->mUnk_18[3].mUnk_00 = p->mUnk_18[2].mUnk_00;
    } else {
        func_0211f4b0(gSelectKart->mHeap, gSelectKart->mUnk_084);
        func_0211f394();
    }
    func_02028e38();
    func_02029330();
    func_02028f20();
    if (func_020280dc() == 0) {
        func_02128374();
    }
    if (func_0202811c() == 2) {
        SetSelectReturnDisplayBitOn();
    }
    if (gSelectKart->mMode == 0) {
        func_02117060();
    }
    FrmHeapShrinkInParent(h);
}
#pragma thumb off
