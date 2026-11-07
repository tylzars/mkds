#include "Main/Unknown/code_02030a20.h"

#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0204f814.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_02125ee8.h"
#include "Main/Unknown/code_0212b000.h"
#include "Main/Unknown/code_0212b1a8.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/code_0202f14c.h"
#include "Main/Unknown/code_0204f000.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02108c1c.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128274.h"
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
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "00/code_02181f98.h"
#include "code_0201ea58.h"
#include "code_0212d214.h"
#include "code_0212df7c.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0204aa04.h"
#include "Main/Unknown/code_0204db48.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02054f58.h"
#include "Main/Unknown/code_02055730.h"
#include "Main/Unknown/code_02058b38.h"
#include "Main/Unknown/code_0205e2cc.h"
#include "Main/Unknown/code_02126230.h"
#include "Main/Unknown/code_02126248.h"
#include "Main/Unknown/code_0212658c.h"
#include "Main/Unknown/code_021262f0.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_0212b928.h"
#include "code_02148950.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/unk_02163000.h"
#include "Main/Unknown/unk_02175000.h"
#include "01/code_021956dc.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_02025edc.h"
#include "Main/Unknown/code_02025f80.h"
#include "registers.h"

#pragma thumb on

void func_02032028(void) {
    void *a;
    void *b;

    a = GetBmgEntry(gMultiSelectMember->mBannerMessages, 0xb);
    b = GetBmgEntry(gMultiSelectMember->mCommonMessages, 4);
    gMultiSelectMember->mUnk_70 = 8;
    gMultiSelectMember->mState = 5;
    func_02126230(a, b);
    func_021282c8();
}

s32 func_02032000(void) {
    s32 i;
    s32 n;

    n = 0;
    for (i = 1; i < 8; i++) {
        if (func_0204fcec(i, NULL) != 0) {
            n++;
        }
    }
    return n;
}

void func_02031f5c(void) {
    Unk02174e58_24 *q;
    Unk02153c1c *t;
    u16 v1[12];
    s32 i;

    q = &gMultiSelectMember->mUnk_24[1];
    for (i = 1, t = data_usa_02153d88; i < 8; t++, i++) {
        v1[0] = 0;
        MIi_CpuClear16(v1[0], &v1[1], 0x16);
        if (func_0204fcec(i, &v1[1]) != 0) {
            v1[11] = 0;
            func_0212426c(1, t->mUnk_00, q->mUnk_14, &v1[1], q->mUnk_0c, q->mUnk_18);
            if (gMultiSelectMember->mUnk_e0[i].mUnk_00 != 2) {
                gMultiSelectMember->mUnk_e0[i].mUnk_00 = 1;
            }
        } else {
            func_021241c0(1, t->mUnk_00, q->mUnk_14, q->mUnk_0c, q->mUnk_18);
            gMultiSelectMember->mUnk_e0[i].mUnk_00 = 0;
        }
    }
}

void func_02031e80(void) {
    Unk02174e58_24 *q;
    Unk02153c1c *t;
    u16 v1[12];
    s32 n;
    s32 i;

    n = 0;
    q = &gMultiSelectMember->mUnk_24[1];
    for (i = 1, t = data_usa_02153d88; i < 8; t++, i++) {
        v1[0] = 0;
        MIi_CpuClear16(v1[0], &v1[1], 0x16);
        if (&data_0217aa00->mUnk_045c[(u16) i] != NULL) {
            MIi_CpuCopy16(&data_0217aa00->mUnk_045c[(u16) i], &v1[1], 0x14);
            if (v1[1] != 0) {
                func_0212426c(1, t->mUnk_00, q->mUnk_14, &v1[1], q->mUnk_0c, q->mUnk_18);
                gMultiSelectMember->mUnk_e0[i].mUnk_00 = 2;
                n++;
            } else {
                func_021241c0(1, t->mUnk_00, q->mUnk_14, q->mUnk_0c, q->mUnk_18);
                gMultiSelectMember->mUnk_e0[i].mUnk_00 = 0;
            }
        }
    }
    gMultiSelectMember->mUnk_74 = n;
    gMultiSelectMember->mUnk_8c = TRUE;
}

void func_02031ba4(void) {
    Unk02174e58_24 *p;
    Unk02174e58_24 *q;
    s32 n0;
    s32 n1;
    s32 n2;
    s32 n3;
    s32 i;
    s16 v;
    BOOL e;
    s32 d;
    Unk02174e58_e0 *t;

    p = &gMultiSelectMember->mUnk_24[0];
    q = &gMultiSelectMember->mUnk_24[1];
    n0 = p->mUnk_14->mUnk_06;
    n1 = p->mUnk_0c->mUnk_06;
    n2 = q->mUnk_14->mUnk_06;
    n3 = q->mUnk_0c->mUnk_06;
    func_02025edc(&gMultiSelectMember->mUnk_a0[0]);
    p->mUnk_18[2].mUnk_06 = func_02025ebc(&gMultiSelectMember->mUnk_a0[0]);
    p->mUnk_18[1].mUnk_06 = p->mUnk_18[2].mUnk_06;
    p->mUnk_18[0].mUnk_06 = p->mUnk_18[1].mUnk_06;
    gMultiSelectMember->mUnk_144 = gMultiSelectMember->mUnk_144 + 1;
    if (gMultiSelectMember->mUnk_144 > data_usa_02153d46[gMultiSelectMember->mUnk_140][0]) {
        gMultiSelectMember->mUnk_140 = gMultiSelectMember->mUnk_140 + 1;
        if (gMultiSelectMember->mUnk_140 == 4) {
            gMultiSelectMember->mUnk_140 = 0;
        }
        gMultiSelectMember->mUnk_144 = 0;
    }
    if (data_usa_02153d44[gMultiSelectMember->mUnk_140][0] == 0) {
        d = 1;
    } else {
        d = 0;
    }
    p->mUnk_18[0].mUnk_00 = d;
    if (data_usa_02153d44[gMultiSelectMember->mUnk_140][0] == 1) {
        d = 1;
    } else {
        d = 0;
    }
    p->mUnk_18[1].mUnk_00 = d;
    if (data_usa_02153d44[gMultiSelectMember->mUnk_140][0] == 2) {
        d = 1;
    } else {
        d = 0;
    }
    p->mUnk_18[2].mUnk_00 = d;
    func_02025edc(&gMultiSelectMember->mUnk_a0[1]);
    v = func_02025ebc(&gMultiSelectMember->mUnk_a0[1]);
    p->mUnk_18[0xb].mUnk_06 = v;
    p->mUnk_18[0xa].mUnk_06 = p->mUnk_18[0xb].mUnk_06;
    p->mUnk_18[9].mUnk_06 = p->mUnk_18[0xa].mUnk_06;
    p->mUnk_18[8].mUnk_06 = p->mUnk_18[9].mUnk_06;
    p->mUnk_18[7].mUnk_06 = p->mUnk_18[8].mUnk_06;
    p->mUnk_18[6].mUnk_06 = p->mUnk_18[7].mUnk_06;
    p->mUnk_18[5].mUnk_06 = p->mUnk_18[6].mUnk_06;
    p->mUnk_18[4].mUnk_06 = p->mUnk_18[5].mUnk_06;
    p->mUnk_18[3].mUnk_06 = p->mUnk_18[4].mUnk_06;
    for (i = 0; i < n0; i++) {
        p->mUnk_18[i + n1].mUnk_06 = v;
    }
    func_02025edc(&gMultiSelectMember->mUnk_a0[2]);
    v = func_02025ebc(&gMultiSelectMember->mUnk_a0[2]);
    i = 0;
    d = n3 + n2;
    for (; i < d; i++) {
        q->mUnk_18[i].mUnk_06 = v;
    }
    if (gMultiSelectMember->mUnk_74 > 0) {
        func_02025f14(&gMultiSelectMember->mUnk_a0[3], 0);
    } else {
        func_02025f14(&gMultiSelectMember->mUnk_a0[3], 2);
    }
    func_02025edc(&gMultiSelectMember->mUnk_a0[3]);
    v = func_02025ebc(&gMultiSelectMember->mUnk_a0[3]);
    n3 = n3 + 8;
    q->mUnk_18[n3].mUnk_06 = v;
    q->mUnk_18[0x11].mUnk_06 = q->mUnk_18[n3].mUnk_06;
    q->mUnk_18[0x10].mUnk_06 = q->mUnk_18[0x11].mUnk_06;
    if (gMultiSelectMember->mUnk_84 == 0) {
        for (i = 0; i < 8; i++) {
            t = &gMultiSelectMember->mUnk_e0[i];
            switch (t->mUnk_00) {
                case 0:
                    q->mUnk_18[t->mUnk_0a].mUnk_00 = 0;
                    q->mUnk_18[t->mUnk_08].mUnk_00 = q->mUnk_18[t->mUnk_0a].mUnk_00;
                    t->mUnk_04 = 0;
                    break;
                case 1:
                    t->mUnk_04 = t->mUnk_04 + 1;
                    if (t->mUnk_04 > 0x14) {
                        t->mUnk_00 = 2;
                    } else {
                        if (t->mUnk_04 / 4 % 2 == 0) {
                            e = TRUE;
                        } else {
                            e = FALSE;
                        }
                        q->mUnk_18[t->mUnk_08].mUnk_00 = e;
                        if (e == FALSE) {
                            e = TRUE;
                        } else {
                            e = FALSE;
                        }
                        q->mUnk_18[t->mUnk_0a].mUnk_00 = e;
                    }
                    break;
                case 2:
                    q->mUnk_18[t->mUnk_0a].mUnk_00 = 1;
                    q->mUnk_18[t->mUnk_08].mUnk_00 = q->mUnk_18[t->mUnk_0a].mUnk_00;
                    t->mUnk_04 = 0;
                    break;
            }
        }
    }
}

void func_02031b6c(void) {
    s32 i;
    Unk02174e58_24 *p;
    BOOL f;

    p = &gMultiSelectMember->mUnk_24[0];
    for (i = 0; i < 8; i++) {
        if (i == gMultiSelectMember->mUnk_74) {
            f = TRUE;
        } else {
            f = FALSE;
        }
        p->mUnk_18[data_usa_02153d54[i]].mUnk_00 = f;
    }
}

void func_02031b30(s32 a) {
    Unk02174e58_24 *q;
    s32 f;

    q = &gMultiSelectMember->mUnk_24[1];
    if (a != 0) {
        f = 1;
    } else {
        f = 0;
    }
    q->mUnk_18[0x11].mUnk_00 = a;
    func_02124100(8, f, q->mUnk_14, q->mUnk_18, q->mUnk_0c);
}

void func_02031960(void) {
    s32 v;

    switch (gMultiSelectMember->mUnk_70) {
        case 0:
            if (func_0205579c(1, data_021759d0->mUnk_1c_2) == 1) {
                gMultiSelectMember->mUnk_70 = 1;
            }
            break;
        case 1:
            if (gMultiSelectMember->mUnk_78 != FALSE) {
                gMultiSelectMember->mUnk_78 = FALSE;
                gMultiSelectMember->mUnk_70 = 3;
                gMultiSelectMember->mTimer = 0x78;
                SetupTxtSystemSubTextEx(GetBmgEntry(gMultiSelectMember->mCommonMessages, 0x79), 0, 1, 1, 0, 1);
                func_02025f14(&gMultiSelectMember->mUnk_a0[0], 2);
            } else if (gMultiSelectMember->mUnk_7c != FALSE) {
                gMultiSelectMember->mUnk_7c = FALSE;
                gMultiSelectMember->mUnk_70 = 7;
            } else {
                func_020554e4();
            }
            break;
        case 3:
            switch (func_0204db6c()) {
                case 1:
                    gMultiSelectMember->mUnk_70 = 4;
                    break;
                case 2:
                    func_02032028();
                    break;
            }
            break;
        case 4:
            switch (func_02058cac()) {
                case 1:
                    if (gMultiSelectMember->mTimer == 0) {
                        if ((u8) ((data_0217aa00->mUnk_15f6 & ~data_0217aa00->mUnk_0457) & 0xfe) != 0) {
                            SetupTxtSystemSubText(GetBmgEntry(gMultiSelectMember->mCommonMessages, 0x81));
                            gMultiSelectMember->mTimer = 0x78;
                        } else {
                            RequestTxtSystemClose();
                        }
                        func_02108d80();
                        func_0205e5c4(1);
                        gMultiSelectMember->mUnk_148 = FALSE;
                        gMultiSelectMember->mUnk_70 = 6;
                    }
                    break;
                case 2:
                    func_02032028();
                    break;
            }
            break;
        case 7:
        case 8:
            if (func_02054f58() == 1) {
                gMultiSelectMember->mUnk_70 = 11;
            }
            break;
        case 6:
            if (data_0217aa08->mUnk_28 == 0) {
                if (data_021759d4->mUnk_0c != 0) {
                    v = data_021759d4->mUnk_10;
                } else {
                    v = 0;
                }
            } else {
                v = 1;
            }
            if (v == 0 && gMultiSelectMember->mTimer == 0) {
                gMultiSelectMember->mUnk_70 = 11;
            }
            break;
    }
}

void func_020317a0(void) {
    s32 v;

    switch (gMultiSelectMember->mUnk_70) {
        case 2:
            if (gMultiSelectMember->mUnk_7c != FALSE) {
                gMultiSelectMember->mUnk_7c = FALSE;
                gMultiSelectMember->mUnk_70 = 7;
                return;
            }
            switch (func_02055730(func_0202f14c()->mUnk_00)) {
                case 1:
                    if (data_021759d0->mUnk_20 == 2) {
                        func_0204aa28((data_0217aa00->mUnk_0454 & 0x40) != 0 ? 1 : 0);
                    }
                    gMultiSelectMember->mUnk_70 = 4;
                    if (gMultiSelectMember->mUnk_84 == 0) {
                        gMultiSelectMember->mUnk_74 = func_02032000();
                        func_02031f5c();
                        gMultiSelectMember->mUnk_88 = TRUE;
                    }
                    break;
                case 2:
                    func_02032028();
                    break;
            }
            break;
        case 4:
            if (gMultiSelectMember->mUnk_7c != FALSE) {
                gMultiSelectMember->mUnk_7c = FALSE;
                gMultiSelectMember->mUnk_70 = 7;
                return;
            }
            switch (func_02058cac()) {
                case 1:
                    if (gMultiSelectMember->mUnk_84 == 0 && gMultiSelectMember->mUnk_8c == FALSE) {
                        func_02031e80();
                        func_02031b6c();
                    }
                    if (gMultiSelectMember->mTimer == 0) {
                        SetupTxtSystemSubText(GetBmgEntry(gMultiSelectMember->mCommonMessages, 0x81));
                        func_02108d80();
                        func_0205e5c4(1);
                        gMultiSelectMember->mUnk_148 = FALSE;
                        gMultiSelectMember->mTimer = 0x78;
                        gMultiSelectMember->mUnk_70 = 6;
                    }
                    break;
                case 2:
                    func_02032028();
                    break;
            }
            break;
        case 7:
        case 8:
            if (func_02054f58() == 1) {
                gMultiSelectMember->mUnk_70 = 11;
            }
            break;
        case 6:
            if (data_0217aa08->mUnk_28 == 0) {
                if (data_021759d4->mUnk_0c != 0) {
                    v = data_021759d4->mUnk_10;
                } else {
                    v = 0;
                }
            } else {
                v = 1;
            }
            if (v == 0 && gMultiSelectMember->mTimer == 0) {
                gMultiSelectMember->mUnk_70 = 11;
            }
            break;
    }
}

void InitMultiSelectMember(void *a, void *b, void *c) {
    Unk02174e58_24 *p;
    Unk02174e58_24 *q;
    u32 v;
    s32 i;
    u32 r;
    void *h;
    volatile u32 z;
    Unk02153c1c *t;
    Unk02153c1c *g;

    h = CreateFrmHeapFromMaxFree(a);
    gMultiSelectMember = HeapAlloc(h, 0x154);
    z = 0;
    MIi_CpuClearFast(z, gMultiSelectMember, 0x154);
    gMultiSelectMember->mHeap = h;
    gMultiSelectMember->mUnk_5c = b;
    gMultiSelectMember->mUnk_60 = c;
    gMultiSelectMember->mBannerMessages = FindSceneFile(data_usa_021636f4);
    gMultiSelectMember->mCommonMessages = FindFileInLoadedArchives(data_usa_02163700);
    gMultiSelectMember->mUnk_6c = -1;
    v = GX_GetSizeOfOBJ();
    p = &gMultiSelectMember->mUnk_24[0];
    func_02025b20(p, gMultiSelectMemberMNcgrName2, gMultiSelectMemberMNcerName2, gMultiSelectMemberMONclrName2,
                  gMultiSelectMemberMBnclName, gMultiSelectMemberMBnllName, NULL, FindSceneFile);
    func_02025a50(0, gMultiSelectMember->mHeap, p);
    i = 0;
    t = data_usa_02153d64;
    g = t;
    for (; i < 2; i++) {
        v -= func_02025a00(0, gMultiSelectMember->mHeap, p, t, v);
        func_0212426c(0, g->mUnk_00, p->mUnk_14, GetBmgEntry(gMultiSelectMember->mBannerMessages, g->mUnk_08),
                      p->mUnk_0c, p->mUnk_18);
        t++;
        g++;
    }
    func_02031b6c();
    func_020258d4(1, gMultiSelectMember, gMultiSelectMemberSBNcgrName3, gMultiSelectMemberSBNclrName3,
                  gMultiSelectMemberSRegisterNscrName2, 3, FindSceneFile);
    r = GX_GetSizeOfSubOBJ();
    q = &gMultiSelectMember->mUnk_24[1];
    func_02025b20(q, gMultiSelectMemberRegisterSNcgrName2, gMultiSelectMemberRegisterSNcerName2,
                  gMultiSelectMemberRegisterSONclrName2, gMultiSelectMemberSRegisterBnclName,
                  gMultiSelectMemberSRegisterBnllName, gMultiSelectMemberSRegisterBnblName, FindSceneFile);
    func_02025a50(1, gMultiSelectMember->mHeap, q);
    for (i = 0; i < 9; i++) {
        r -= func_02025a00(1, gMultiSelectMember->mHeap, q, &data_usa_02153d7c[i], r);
    }
    func_02025f80(&gMultiSelectMember->mUnk_a0[3], 3, 10, 0x40, 0);
    InitPaletteBlend(gMultiSelectMember->mHeap, q->mUnk_04, 3);
    func_02031b30(1);
    func_02025f80(&gMultiSelectMember->mUnk_a0[0], 0, 10, -0x40, 0);
    func_02025f80(&gMultiSelectMember->mUnk_a0[1], 0, 10, 0x40, 0);
    func_02025f80(&gMultiSelectMember->mUnk_a0[2], 0, 10, -0xc0, 0);
    gMultiSelectMember->mUnk_e0[0].mUnk_00 = 2;
    for (i = 0; i < 8; i++) {
        gMultiSelectMember->mUnk_e0[i].mUnk_08 = i * 2;
        gMultiSelectMember->mUnk_e0[i].mUnk_0a = i * 2 + 1;
    }
    SetTxtSystemBgOffsetRequested(0x20, 0);
}

void func_0203147c(void *a, void *b, void *c) {
    Unk02174e58_24 *q;
    u16 v1[11];

    InitMultiSelectMember(a, b, c);
    q = &gMultiSelectMember->mUnk_24[1];
    MIi_CpuCopy16(data_0217aa08->mUnk_00->mUnk_0c, v1, 0x14);
    v1[10] = 0;
    func_0212426c(1, data_usa_02153d7c[0].mUnk_00, q->mUnk_14, v1, q->mUnk_0c, q->mUnk_18);
    func_0212426c(1, data_usa_02153dbc[16], q->mUnk_14,
                  GetBmgEntry(gMultiSelectMember->mBannerMessages, data_usa_02153d7c[8].mUnk_08), q->mUnk_0c,
                  q->mUnk_18);
    data_021759d0->mUnk_20 = 1;
    func_02126638(GetBmgEntry(gMultiSelectMember->mBannerMessages, 9), 0, 0, 1, 0, 0, 0);
    q->mUnk_18[0x11].mUnk_00 = 0;
    q->mUnk_18[0x10].mUnk_00 = q->mUnk_18[0x11].mUnk_00;
    func_021281c8(-1);
    FrmHeapShrinkInParent(gMultiSelectMember->mHeap);
}

void func_02031280(void *a, void *b, void *c) {
    Unk02174e58_24 *p;
    Unk02174e58_24 *q;
    u16 v1[12];
    s32 n0;
    s32 n1;
    s32 n2;
    s32 n3;
    s32 i;
    void *v;

    InitMultiSelectMember(a, b, c);
    p = &gMultiSelectMember->mUnk_24[0];
    q = &gMultiSelectMember->mUnk_24[1];
    gMultiSelectMember->mUnk_70 = 2;
    gMultiSelectMember->mUnk_84 = func_0204fe90(func_0202f14c()->mUnk_00);
    v1[0] = 0;
    MIi_CpuClear16(v1[0], &v1[1], 0x16);
    if (gMultiSelectMember->mUnk_84 == 0 && func_0204ff14(func_0202f14c()->mUnk_00, &v1[1]) != 0) {
        v1[11] = 0;
        func_0212426c(1, data_usa_02153d7c[0].mUnk_00, q->mUnk_14, &v1[1], q->mUnk_0c, q->mUnk_18);
        gMultiSelectMember->mUnk_80 = TRUE;
    }
    q->mUnk_18[0x11].mUnk_00 = 0;
    q->mUnk_18[0x10].mUnk_00 = q->mUnk_18[0x11].mUnk_00;
    v = GetBmgEntry(gMultiSelectMember->mBannerMessages, 10);
    if (gMultiSelectMember->mUnk_84 != 0) {
        SetupTxtSystemSubTextEx(v, 0, 0, 1, 0, 1);
    } else {
        func_02126638(v, 0, 0, 1, 0, 0, 0);
    }
    if (gMultiSelectMember->mUnk_84 != 0) {
        n0 = p->mUnk_14->mUnk_06;
        n1 = p->mUnk_0c->mUnk_06;
        n2 = q->mUnk_14->mUnk_06;
        n3 = q->mUnk_0c->mUnk_06;
        i = 0;
        p->mUnk_18[0xb].mUnk_00 = 0;
        p->mUnk_18[0xa].mUnk_00 = p->mUnk_18[0xb].mUnk_00;
        p->mUnk_18[9].mUnk_00 = p->mUnk_18[0xa].mUnk_00;
        p->mUnk_18[8].mUnk_00 = p->mUnk_18[9].mUnk_00;
        p->mUnk_18[7].mUnk_00 = p->mUnk_18[8].mUnk_00;
        p->mUnk_18[6].mUnk_00 = p->mUnk_18[7].mUnk_00;
        p->mUnk_18[5].mUnk_00 = p->mUnk_18[6].mUnk_00;
        p->mUnk_18[4].mUnk_00 = p->mUnk_18[5].mUnk_00;
        p->mUnk_18[3].mUnk_00 = p->mUnk_18[4].mUnk_00;
        for (i = 0; i < 8; i++) {
            q->mUnk_18[gMultiSelectMember->mUnk_e0[i].mUnk_0a].mUnk_00 = 0;
            q->mUnk_18[gMultiSelectMember->mUnk_e0[i].mUnk_08].mUnk_00 =
                q->mUnk_18[gMultiSelectMember->mUnk_e0[i].mUnk_0a].mUnk_00;
        }
        for (i = 0; i < n0; i++) {
            p->mUnk_18[i + n1].mUnk_00 = 0;
        }
        i = 0;
        n0 = n3 + n2;
        for (; i < n0; i++) {
            q->mUnk_18[i].mUnk_00 = 0;
        }
    }
    func_021281c8(-1);
    FrmHeapShrinkInParent(gMultiSelectMember->mHeap);
}

#pragma thumb off

#pragma thumb on

u32 func_02031268(void) {
    if (gMultiSelectMember->mUnk_a0[2].mUnk_00 == 1) {
        return 1;
    }
    return 0;
}

u32 func_02031250(void) {
    if (gMultiSelectMember->mUnk_a0[2].mUnk_00 == 3) {
        return 1;
    }
    return 0;
}

void func_02031208(void) {
    int v1;
    Unk02174e58_24 *v2;
    if (gMultiSelectMember->mState != 6) {
        v1 = 0;
        do {
            v2 = &gMultiSelectMember->mUnk_24[v1];
            func_02124c30(v2->mUnk_0c, v2->mUnk_08, v2->mUnk_14, (&gMultiSelectMember->mUnk_5c)[v1], v2->mUnk_18);
            v1++;
        } while (v1 < 2);
    }
}

#pragma thumb off

#pragma thumb on

s32 func_02030ea4(Unk02030b18 *a) {
    Unk02174e58_24 *p;
    s32 v1;
    s32 v2;
    u16 k;
    s32 m;
    s32 z;
    u32 b1;
    u32 a1;
    u32 w;
    s32 x;
    s32 y;

    v1 = -1;
    k = func_020435bc();
    p = &gMultiSelectMember->mUnk_24[1];
    v2 = gMultiSelectMember->mUnk_74;
    if (gMultiSelectMember->mTimer > 0) {
        gMultiSelectMember->mTimer = gMultiSelectMember->mTimer - 1;
    }
    func_02031960();
    if (gMultiSelectMember->mState != 0 && gMultiSelectMember->mState != 3 && gMultiSelectMember->mState != 4 &&
        gMultiSelectMember->mState != 5 && gMultiSelectMember->mState != 6) {
        if (data_0217aa00 == NULL) {
            x = 0;
        } else {
            x = data_0217aa00->mUnk_0000;
        }
        if (x == 1) {
            if ((data_0217aa00->mUnk_0454 & 0x40) != 0) {
                x = data_0217aa00->mUnk_1699;
            } else {
                x = data_0217aa00->mUnk_0044.mUnk_40;
            }
        } else {
            x = 0;
        }
        gMultiSelectMember->mUnk_74 = x;
        if (gMultiSelectMember->mUnk_74 != v2) {
            func_02031f5c();
            if (gMultiSelectMember->mUnk_74 > v2) {
                NNS_SndArcSetCurrent(&data_0217c868);
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 2);
                NNS_SndArcSetCurrent(&data_0217d0a0);
            } else {
                NNS_SndArcSetCurrent(&data_0217c868);
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 3);
                NNS_SndArcSetCurrent(&data_0217d0a0);
            }
        }
    }
    func_02031b6c();
    func_02031ba4();
    AdvancePaletteBlend();
    if (gMultiSelectMember->mUnk_148 != FALSE) {
        gMultiSelectMember->mUnk_14c = gMultiSelectMember->mUnk_14c + 1;
        if (gMultiSelectMember->mUnk_14c > 0x96) {
            func_02108ddc();
            gMultiSelectMember->mUnk_148 = FALSE;
        }
    }
    switch (gMultiSelectMember->mState) {
        case 0:
            if (func_02031268() != 0) {
                gMultiSelectMember->mState = 1;
                p->mUnk_18[0x10].mUnk_00 = 1;
                func_02031b30(1);
            }
            break;
        case 1:
            z = 0;
            m = -1;
            b1 = 0;
            a1 = 0;
            w = data_02175674[k].mUnk_00;
            if (w == 0 && data_02175680[k].mUnk_00 < 5) {
                a1 = 1;
            }
            if (a1 == 0 && data_0217567c[k].mUnk_00 == 0 && w != 0) {
                b1 = 1;
            }
            if (b1 != 0) {
                x = data_02175670[k].mUnk_00;
                y = data_02175672[k].mUnk_00;
                z = IsSelectReturnState2NoState3Or4RequestAndInRect(x, y);
                m = RectTableFindContaining(p->mUnk_10, x, y);
            }
            if ((u16) (data_02175628[k].mUnk_00 & 1) != 0 || m == 0) {
                if (gMultiSelectMember->mUnk_74 > 0 && gMultiSelectMember->mUnk_a0[3].mUnk_00 == 1) {
                    func_02031b30(0);
                    func_021282c8();
                    StopPaletteBlend();
                    NNS_SndArcSetCurrent(&data_0217c868);
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 6);
                    NNS_SndArcSetCurrent(&data_0217d0a0);
                    gMultiSelectMember->mUnk_78 = TRUE;
                    gMultiSelectMember->mUnk_148 = TRUE;
                    gMultiSelectMember->mState = 2;
                    break;
                }
            }
            if ((u16) (data_02175628[k].mUnk_00 & 2) != 0 || z != 0) {
                gMultiSelectMember->mUnk_6c = 1;
                gMultiSelectMember->mState = 3;
                gMultiSelectMember->mUnk_7c = TRUE;
                RequestTxtSystemClose();
                func_02128310(0);
                NNS_SndArcSetCurrent(&data_0217c868);
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 5);
                NNS_SndArcSetCurrent(&data_0217d0a0);
            }
            break;
        case 2:
            gMultiSelectMember->mUnk_98 = gMultiSelectMember->mUnk_98 + 1;
            if (gMultiSelectMember->mUnk_98 >= 5) {
                func_02031b30(1);
                if (gMultiSelectMember->mUnk_70 == 11) {
                    data_0217b488->mUnk_04 = 1;
                    data_0217b488->mUnk_08 = 4;
                    if (a != NULL) {
                        a->mUnk_04 = 1;
                    }
                    gMultiSelectMember->mUnk_98 = 0;
                    gMultiSelectMember->mState = 7;
                }
            }
            break;
        case 5:
            if (func_02125f6c() != 0) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x15);
            }
            if (func_02125f54() != 0) {
                RequestTxtSystemClose();
                gMultiSelectMember->mUnk_6c = 0;
                gMultiSelectMember->mState = 3;
            }
            break;
        case 3:
            if (gMultiSelectMember->mUnk_70 == 11) {
                func_02025f14(&gMultiSelectMember->mUnk_a0[0], 2);
                func_02025f14(&gMultiSelectMember->mUnk_a0[1], 2);
                func_02025f14(&gMultiSelectMember->mUnk_a0[2], 2);
                gMultiSelectMember->mState = 4;
            }
            break;
        case 4:
            if (func_02031250() != 0) {
                gMultiSelectMember->mState = 6;
            }
            break;
        case 6:
            v1 = gMultiSelectMember->mUnk_6c;
            break;
    }
    func_02031208();
    return v1;
}

s32 func_02030b18(Unk02030b18 *a) {
    Unk02174e58_24 *p;
    s32 v1;
    s32 v;
    s32 v2;
    u16 k;
    u16 v3[12];
    BOOL x;
    u32 b1;
    u32 a1;
    u32 w;
    s32 y;

    v1 = -1;
    k = func_020435bc();
    v = 0;
    p = &gMultiSelectMember->mUnk_24[1];
    if (gMultiSelectMember->mTimer > 0) {
        gMultiSelectMember->mTimer = gMultiSelectMember->mTimer - 1;
    }
    func_020317a0();
    v2 = gMultiSelectMember->mUnk_74;
    if (gMultiSelectMember->mUnk_84 == 0 && gMultiSelectMember->mUnk_8c == FALSE) {
        gMultiSelectMember->mUnk_74 = func_02032000();
        if (gMultiSelectMember->mUnk_74 != v2) {
            func_02031f5c();
            if (gMultiSelectMember->mUnk_88 == FALSE) {
                if (gMultiSelectMember->mUnk_74 > v2) {
                    NNS_SndArcSetCurrent(&data_0217c868);
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 2);
                    NNS_SndArcSetCurrent(&data_0217d0a0);
                } else if (gMultiSelectMember->mUnk_74 < v2) {
                    NNS_SndArcSetCurrent(&data_0217c868);
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 3);
                    NNS_SndArcSetCurrent(&data_0217d0a0);
                }
                gMultiSelectMember->mUnk_88 = FALSE;
            }
        }
        func_02031b6c();
    }
    if (gMultiSelectMember->mUnk_84 == 0 && gMultiSelectMember->mUnk_80 == FALSE) {
        v3[0] = 0;
        MIi_CpuClear16(v3[0], &v3[1], 0x16);
        if (func_0204ff14(func_0202f14c()->mUnk_00, &v3[1]) != 0) {
            v3[11] = 0;
            func_0212426c(1, data_usa_02153d7c[0].mUnk_00, p->mUnk_14, &v3[1], p->mUnk_0c, p->mUnk_18);
            gMultiSelectMember->mUnk_80 = TRUE;
        }
    }
    func_02031ba4();
    if (gMultiSelectMember->mUnk_148 != FALSE) {
        gMultiSelectMember->mUnk_14c = gMultiSelectMember->mUnk_14c + 1;
        if (gMultiSelectMember->mUnk_14c > 0x96) {
            func_02108ddc();
            gMultiSelectMember->mUnk_148 = FALSE;
        }
    }
    switch (gMultiSelectMember->mState) {
        case 0:
            if (func_02031268() != 0) {
                gMultiSelectMember->mState = 1;
            }
            break;
        case 1:
            b1 = 0;
            a1 = 0;
            w = data_02175674[k].mUnk_00;
            if (w == 0 && data_02175680[k].mUnk_00 < 5) {
                a1 = 1;
            }
            if (a1 == 0 && data_0217567c[k].mUnk_00 == 0 && w != 0) {
                b1 = 1;
            }
            if (b1 != 0) {
                v = IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175670[k].mUnk_00, data_02175672[k].mUnk_00);
            }
            y = gMultiSelectMember->mUnk_90;
            if (y == 0) {
                switch (data_0217aa00->mUnk_0004) {
                    case 7:
                    case 8:
                    case 9:
                    case 10:
                    case 11:
                        x = TRUE;
                        break;
                    default:
                        x = FALSE;
                        break;
                }
                if (x != FALSE) {
                    func_021282c8();
                    func_02025f14(&gMultiSelectMember->mUnk_a0[0], 2);
                    NNS_SndArcSetCurrent(&data_0217c868);
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 6);
                    NNS_SndArcSetCurrent(&data_0217d0a0);
                    gMultiSelectMember->mUnk_148 = TRUE;
                    gMultiSelectMember->mUnk_90 = 1;
                    break;
                }
            }
            if (gMultiSelectMember->mUnk_70 == 11) {
                data_0217b488->mUnk_04 = 1;
                data_0217b488->mUnk_08 = 4;
                if (a != NULL) {
                    a->mUnk_04 = 1;
                }
                gMultiSelectMember->mState = 7;
            } else if (y == 0) {
                if ((u16) (data_02175628[k].mUnk_00 & 2) != 0 || v != 0) {
                    gMultiSelectMember->mUnk_6c = 0;
                    gMultiSelectMember->mState = 3;
                    gMultiSelectMember->mUnk_7c = TRUE;
                    RequestTxtSystemClose();
                    func_02128310(0);
                    NNS_SndArcSetCurrent(&data_0217c868);
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 3);
                    NNS_SndArcSetCurrent(&data_0217d0a0);
                }
            }
            break;
        case 5:
            if (func_02125f6c() != 0) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x15);
            }
            if (func_02125f54() != 0) {
                gMultiSelectMember->mUnk_6c = 0;
                gMultiSelectMember->mState = 3;
                RequestTxtSystemClose();
            }
            break;
        case 3:
            if (gMultiSelectMember->mUnk_70 == 11) {
                func_02025f14(&gMultiSelectMember->mUnk_a0[0], 2);
                func_02025f14(&gMultiSelectMember->mUnk_a0[1], 2);
                func_02025f14(&gMultiSelectMember->mUnk_a0[2], 2);
                gMultiSelectMember->mState = 4;
            }
            break;
        case 4:
            if (func_02031250() != 0) {
                gMultiSelectMember->mState = 6;
            }
            break;
        case 6:
            v1 = gMultiSelectMember->mUnk_6c;
            break;
    }
    func_02031208();
    return v1;
}

#pragma thumb off

#pragma thumb on

void ReleaseMultiSelectMember(void) {
    SetTxtSystemBgOffsetRequested(0, 0);
    func_0212b91c();
    HeapDestroy(gMultiSelectMember->mHeap);
    *&gMultiSelectMember = NULL;
}

#pragma thumb off

#pragma thumb on

void func_02030a20(void) {
    s32 a;
    s32 r;

    a = 0x17;
    r = func_02025ebc(&gMultiSelectMember->mUnk_a0[2]);
    if (gMultiSelectMember->mUnk_84 == 0 && gMultiSelectMember->mState != 6) {
        a |= 8;
    }
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | (a << 8);
    reg_G2S_DB_BG3OFS = (-r << 16) & 0x1ff0000;
    if (r != 0) {
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffff1fff) | 0x2000;
        reg_G2S_DB_WININ = (u32) ((reg_G2S_DB_WININ & ~0x3f) | 0x1f) | 0x20;
        reg_G2S_DB_WINOUT = (u32) ((reg_G2S_DB_WINOUT & ~0x3f) | 7) | 0x20;
        reg_G2S_DB_WIN0H = 0xff;
        reg_G2S_DB_WIN0V = (r + 0xc0) & 0xff;
    } else {
        reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffff1fff;
    }
}

#pragma thumb off
