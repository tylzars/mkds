#include "Main/Unknown/code_02029aa0.h"
#include "01/code_021804e0.h"
#include "Main/Unknown/code_02025b84.h"
#include "Main/Unknown/code_02025d5c.h"
#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_0202a340.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_02062000.h"
#include "Main/Unknown/code_02057d10.h"
#include "Main/Unknown/code_020a23a0.h"
#include "Main/Unknown/code_0210f71c.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02125960.h"
#include "Main/Unknown/code_02125de0.h"
#include "Main/Unknown/code_02125ebc.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_021258f0.h"
#include "code_02148950.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "00/code_02181f98.h"
#include "01/code_021956dc.h"
#include "code_02016468.h"
#include "code_0212df7c.h"
#include "code_0214a390.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"
#include "code_021458c4.h"
#include "Main/Unknown/code_02045874.h"
#include "Main/Unknown/code_02090354.h"

#pragma thumb on

void func_02029dcc(void *a, void *b, void *c) {
    s16 v1[10];
    Unk02125de0 s;
    Unk02174e60_00 t1;
    u16 v2[11];
    Unk02174e14_00 w3;
    Unk02174e60_00 t2;
    Unk02174e14_00 w4;
    Unk02174e14_00 *q;
    Unk02174e14_00 *r;
    Unk02180774 *w;
    u32 n;
    u32 m;
    u32 u;
    u32 k;
    u32 f;
    s32 i;
    void *v;
    s32 e;
    s32 j;
    Unk02153918 *p;

    k = 0;
    data_usa_02174e00 = HeapAlloc(a, 0x60);
    MemFillWordsByBlock_inline(data_usa_02174e00, 0x60);
    data_usa_02174e00->mUnk_38[0] = b;
    data_usa_02174e00->mUnk_38[1] = c;
    data_usa_02174e00->mUnk_4c = func_02047a28(data_usa_02162138);
    data_usa_02174e00->mUnk_50 = FindSceneFile(data_usa_02162144);
    data_usa_02174e00->mUnk_40 = data_0217b488->mUnk_84;
    data_usa_02174e00->mUnk_48 = data_0217b488->mUnk_7c;
    if (data_usa_02174e00->mUnk_48 < 0) {
        data_usa_02174e00->mUnk_48 = 0;
    }
    data_usa_02174e00->mUnk_44 = data_0217b488->mUnk_80;
    func_02062860();
    w = func_02038d88(a, data_021547f0);
    func_02038d28(&w->mUnk_28, 2, 0, 0, 0, 0x10, 6, 0);
    func_02038cd8(&w->mUnk_28, 3, 0, 0, 0, 2, 6);
    func_02038cd8(&w->mUnk_70, 3, 0, 0, 0, 1, 6);
    func_02037abc(w);
    s.mUnk_00 = 1;
    s.mUnk_04 = func_020b403c(1);
    s.mUnk_08 = 0;
    s.mUnk_0c = 1;
    s.mUnk_10 = 0;
    s.mUnk_14 = 0;
    s.mUnk_18 = NULL;
    s.mUnk_1c = 0;
    s.mUnk_20 = 0;
    s.mUnk_24 = 0;
    LoadTxtSystemAndSelectChoisesAndSelectReturnData();
    func_02125de0(a, &s);
    func_02025854(0, &t1, data_usa_02162150, data_usa_02162164, data_usa_02162178, 1, FindSceneFile);
    LoadNscrData(&t1.mUnk_14[3], FindSceneFile(data_usa_0216218c));
    CallQueueAppend(0xb, 0, &t1.mUnk_14[3]->mData, t1.mUnk_14[3]->mDataSize);
    n = GX_GetSizeOfOBJ();
    q = &data_usa_02174e00->mUnk_00[0];
    func_02025abc(q, data_usa_021621a0, data_usa_021621b8, data_usa_021621d0, data_usa_021621e4, data_usa_021621f8,
                  NULL, FindSceneFile);
    func_02025a50(0, a, q);
    MIi_CpuCopy16(&data_0217aa08->mUnk_00->mUnk_0c, v2, 0x14);
    v2[10] = 0;
    func_021243ac(a, 0, q->mUnk_14, 0x82, 0xd, 0x14, q->mUnk_08, q->mUnk_0c, q->mUnk_18, n);
    func_0212426c(0, 0, q->mUnk_14, v2, q->mUnk_0c, q->mUnk_18);
    func_02124094(0, 1, q->mUnk_14, q->mUnk_18, q->mUnk_0c);
    for (i = 0; i < 8; i++) {
        if (i == data_usa_02174e00->mUnk_48) {
            f = 1;
        } else {
            f = 0;
        }
        q->mUnk_18[data_usa_02153878[i]].mUnk_00 = f;
    }
    for (i = 0; i < 8; i++) {
        if (i == data_usa_02174e00->mUnk_44) {
            f = 1;
        } else {
            f = 0;
        }
        q->mUnk_18[data_usa_02153888[i]].mUnk_00 = f;
    }
    if (data_usa_02174e00->mUnk_48 >= 3) {
        f = 1;
    } else {
        f = 0;
    }
    q->mUnk_18[3].mUnk_00 = f;
    q->mUnk_18[2].mUnk_00 = q->mUnk_18[3].mUnk_00;
    q->mUnk_18[1].mUnk_00 = (q->mUnk_18[2].mUnk_00 == 0) ? 1 : 0;
    q->mUnk_18[0].mUnk_00 = q->mUnk_18[1].mUnk_00;
    u = data_0217b488->mUnk_90;
    q = &data_usa_02174e00->mUnk_00[0];
    func_02025b84(1, &w3);
    func_0212463c(u, w3.mUnk_08, w3.mUnk_00, w3.mUnk_04, w3.mUnk_0c, 0, 0x14, q->mUnk_08, q->mUnk_0c);
    func_02025854(1, &t2, data_usa_0216220c, data_usa_02162220, data_usa_02162234, 3, FindSceneFile);
    m = GX_GetSizeOfSubOBJ();
    r = &data_usa_02174e00->mUnk_00[1];
    func_02025abc(r, data_usa_02162248, data_usa_02162260, data_usa_02162278, data_usa_0216228c, data_usa_021622a0,
                  NULL, FindSceneFile);
    func_02025a50(1, a, r);
    j = 0;
    p = data_usa_02153918;
    for (; j < 16; j++) {
        m -= func_02025a00(1, a, r, p, m);
        p++;
    }
    v = GetBmgEntry(data_usa_02174e00->mUnk_4c, data_usa_02153860[data_0217b488->mUnk_88]);
    for (j = 0; j < 2; j++) {
        func_0212426c(1, data_usa_02153918[k].mUnk_00, r->mUnk_14, v, r->mUnk_0c, r->mUnk_18);
        k++;
    }
    if (data_0217b488->mUnk_8c != 0) {
        v = GetBmgEntry(data_usa_02174e00->mUnk_4c, 0x71);
        for (j = 0; j < 2; j++) {
            func_0212426c(1, data_usa_02153918[k].mUnk_00, r->mUnk_14, v, r->mUnk_0c, r->mUnk_18);
            k++;
        }
    } else {
        k += 2;
    }
    for (e = 0; e < 4; e++) {
        v = GetBmgEntry(data_usa_02174e00->mUnk_4c, func_02025d8c(data_usa_02153898[data_usa_02174e00->mUnk_40][e]));
        func_0212426c(1, data_usa_02153918[k].mUnk_00, r->mUnk_14, v, r->mUnk_0c, r->mUnk_18);
        k++;
    }
    for (j = 0; j < 4; j++) {
        func_0202a340(v1, j);
        func_02124224(1, data_usa_02153918[k].mUnk_00, r->mUnk_14, v1, r->mUnk_0c, r->mUnk_18, 7);
        func_02124224(1, data_usa_02153918[k + 4].mUnk_00, r->mUnk_14, v1, r->mUnk_0c, r->mUnk_18, 7);
        k++;
    }
    r = &data_usa_02174e00->mUnk_00[1];
    func_02025abc(&w4, data_usa_021622b4, data_usa_021622cc, NULL, data_usa_021622e4, NULL, NULL, FindSceneFile);
    func_02124748(data_usa_02153868[data_usa_02174e00->mUnk_40], w4.mUnk_08, w4.mUnk_00, w4.mUnk_0c, 1, 0, r->mUnk_08,
                  r->mUnk_0c);
    func_020629a4();
    func_020a269c(data_usa_02174e00->mUnk_40, (u16) data_usa_02174e00->mUnk_48);
    i = -1;
    switch (data_usa_02174e00->mUnk_44) {
        case 5:
            i = 0x1e;
            break;
        case 6:
            i = 0x1f;
            break;
        case 7:
            i = 0x20;
            break;
    }
    if (i >= 0) {
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, (u16) i);
    }
    if (func_0203b324()) {
        func_02057d9c();
        if (data_021759d4->mUnk_0c != 0) {
            CARD_WaitBackupAsync();
        }
        data_usa_02174e00->mUnk_58 = func_020911a8();
    }
}

void func_02029aa0(Unk02029aa0 *a) {
    u32 v1;
    void *v;
    s32 i;
    v1 = func_020435bc();
    v = NULL;
    for (i = 0; i < 2; i++) {
        func_02124c30(data_usa_02174e00->mUnk_00[i].mUnk_0c, data_usa_02174e00->mUnk_00[i].mUnk_08,
                      data_usa_02174e00->mUnk_00[i].mUnk_14, data_usa_02174e00->mUnk_38[i],
                      data_usa_02174e00->mUnk_00[i].mUnk_18);
    }
    if (data_usa_02174e00->mUnk_48 < 3) {
        func_020a2558();
        func_020a23cc();
    }
    switch (data_usa_02174e00->mUnk_54) {
        case 0: {
            s32 t;
            s32 w;
            t = func_0210f71c(data_usa_02174e00->mUnk_48);
            w = data_usa_02174e00->mUnk_5c;
            data_usa_02174e00->mUnk_5c = w + 1;
            if (w >= t) {
                void *q;
                u32 f;
                if (!(u16) (data_02175628[v1].mUnk_00 & 1)) {
                    BOOL y;
                    BOOL x;
                    u16 z;
                    y = FALSE;
                    x = FALSE;
                    z = data_02175674[v1].mUnk_00;
                    if (z == 0) {
                        if (data_02175680[v1].mUnk_00 < 5) {
                            x = TRUE;
                        }
                    }
                    if (x == FALSE) {
                        if (data_0217567c[v1].mUnk_00 == 0) {
                            if (z != 0) {
                                y = TRUE;
                            }
                        }
                    }
                    if (y == FALSE) {
                        break;
                    }
                }
                q = GetBmgEntry(data_usa_02174e00->mUnk_4c, 4);
                f = data_usa_02174e00->mUnk_58;
                if (f != 0) {
                    if (f & 0x1) {
                        v = GetBmgEntry(data_usa_02174e00->mUnk_50, 0);
                        data_usa_02174e00->mUnk_58 &= ~0x1;
                    } else if (f & 0x2) {
                        v = GetBmgEntry(data_usa_02174e00->mUnk_50, 1);
                        data_usa_02174e00->mUnk_58 &= ~0x2;
                    } else if (f & 0x4) {
                        v = GetBmgEntry(data_usa_02174e00->mUnk_50, 2);
                        data_usa_02174e00->mUnk_58 &= ~0x4;
                    } else if (f & 0x8) {
                        v = GetBmgEntry(data_usa_02174e00->mUnk_50, 3);
                        data_usa_02174e00->mUnk_58 &= ~0x8;
                    } else if (f & 0x10) {
                        v = GetBmgEntry(data_usa_02174e00->mUnk_50, 4);
                        data_usa_02174e00->mUnk_58 &= ~0x10;
                    } else if (f & 0x20) {
                        v = GetBmgEntry(data_usa_02174e00->mUnk_50, 5);
                        data_usa_02174e00->mUnk_58 &= ~0x20;
                    } else if (f & 0x40) {
                        v = GetBmgEntry(data_usa_02174e00->mUnk_50, 6);
                        data_usa_02174e00->mUnk_58 &= ~0x40;
                    } else if (f & 0x80) {
                        v = GetBmgEntry(data_usa_02174e00->mUnk_50, 7);
                        data_usa_02174e00->mUnk_58 &= ~0x80;
                    } else if (f & 0x100) {
                        v = GetBmgEntry(data_usa_02174e00->mUnk_50, 8);
                        data_usa_02174e00->mUnk_58 &= ~0x100;
                    } else if (f & 0x200) {
                        v = GetBmgEntry(data_usa_02174e00->mUnk_50, 9);
                        data_usa_02174e00->mUnk_58 &= ~0x200;
                    } else if (f & 0x400) {
                        v = GetBmgEntry(data_usa_02174e00->mUnk_50, 10);
                        data_usa_02174e00->mUnk_58 &= ~0x400;
                    } else if (f & 0x800) {
                        v = GetBmgEntry(data_usa_02174e00->mUnk_50, 11);
                        data_usa_02174e00->mUnk_58 &= ~0x800;
                    }
                    func_02125ebc(0x53);
                    func_02126138(v, q, 0, 1, 1, 0);
                    data_usa_02174e00->mUnk_54 = 1;
                } else {
                    switch (func_020909cc()) {
                        case 0:
                            if (a != NULL) {
                                a->mUnk_04 = 0;
                            }
                            break;
                        case 1:
                            func_02045a2c(0);
                            if (a != NULL) {
                                a->mUnk_04 = 2;
                            }
                            break;
                        case 2:
                            func_02045a2c(1);
                            if (a != NULL) {
                                a->mUnk_04 = 2;
                            }
                            break;
                    }
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 5);
                    data_usa_02174e00->mUnk_54 = 2;
                }
            }
        } break;
        case 1:
            if (func_02125f54()) {
                func_02125fc0();
                data_usa_02174e00->mUnk_54 = 0;
            }
            break;
    }
    func_02125928();
}

#pragma thumb off
