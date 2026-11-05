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

#pragma thumb on

void func_02032028(void) {
    void *a;
    void *b;

    a = GetBmgEntry(data_02174e58->mUnk_64, 0xb);
    b = GetBmgEntry(data_02174e58->mUnk_68, 4);
    data_02174e58->mUnk_70 = 8;
    data_02174e58->mUnk_94 = 5;
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

    q = &data_02174e58->mUnk_24[1];
    for (i = 1, t = data_usa_02153d88; i < 8; t++, i++) {
        v1[0] = 0;
        MemFillHalfwords(v1[0], &v1[1], 0x16);
        if (func_0204fcec(i, &v1[1]) != 0) {
            v1[11] = 0;
            func_0212426c(1, t->mUnk_00, q->mUnk_14, &v1[1], q->mUnk_0c, q->mUnk_18);
            if (data_02174e58->mUnk_e0[i].mUnk_00 != 2) {
                data_02174e58->mUnk_e0[i].mUnk_00 = 1;
            }
        } else {
            func_021241c0(1, t->mUnk_00, q->mUnk_14, q->mUnk_0c, q->mUnk_18);
            data_02174e58->mUnk_e0[i].mUnk_00 = 0;
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
    q = &data_02174e58->mUnk_24[1];
    for (i = 1, t = data_usa_02153d88; i < 8; t++, i++) {
        v1[0] = 0;
        MemFillHalfwords(v1[0], &v1[1], 0x16);
        if (&data_0217aa00->mUnk_045c[(u16) i] != NULL) {
            MemCopyHalfwords(&data_0217aa00->mUnk_045c[(u16) i], &v1[1], 0x14);
            if (v1[1] != 0) {
                func_0212426c(1, t->mUnk_00, q->mUnk_14, &v1[1], q->mUnk_0c, q->mUnk_18);
                data_02174e58->mUnk_e0[i].mUnk_00 = 2;
                n++;
            } else {
                func_021241c0(1, t->mUnk_00, q->mUnk_14, q->mUnk_0c, q->mUnk_18);
                data_02174e58->mUnk_e0[i].mUnk_00 = 0;
            }
        }
    }
    data_02174e58->mUnk_74 = n;
    data_02174e58->mUnk_8c = TRUE;
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

    p = &data_02174e58->mUnk_24[0];
    q = &data_02174e58->mUnk_24[1];
    n0 = p->mUnk_14->mUnk_06;
    n1 = p->mUnk_0c->mUnk_06;
    n2 = q->mUnk_14->mUnk_06;
    n3 = q->mUnk_0c->mUnk_06;
    func_02025edc(&data_02174e58->mUnk_a0[0]);
    p->mUnk_18[2].mUnk_06 = func_02025ebc(&data_02174e58->mUnk_a0[0]);
    p->mUnk_18[1].mUnk_06 = p->mUnk_18[2].mUnk_06;
    p->mUnk_18[0].mUnk_06 = p->mUnk_18[1].mUnk_06;
    data_02174e58->mUnk_144 = data_02174e58->mUnk_144 + 1;
    if (data_02174e58->mUnk_144 > data_usa_02153d46[data_02174e58->mUnk_140][0]) {
        data_02174e58->mUnk_140 = data_02174e58->mUnk_140 + 1;
        if (data_02174e58->mUnk_140 == 4) {
            data_02174e58->mUnk_140 = 0;
        }
        data_02174e58->mUnk_144 = 0;
    }
    if (data_usa_02153d44[data_02174e58->mUnk_140][0] == 0) {
        d = 1;
    } else {
        d = 0;
    }
    p->mUnk_18[0].mUnk_00 = d;
    if (data_usa_02153d44[data_02174e58->mUnk_140][0] == 1) {
        d = 1;
    } else {
        d = 0;
    }
    p->mUnk_18[1].mUnk_00 = d;
    if (data_usa_02153d44[data_02174e58->mUnk_140][0] == 2) {
        d = 1;
    } else {
        d = 0;
    }
    p->mUnk_18[2].mUnk_00 = d;
    func_02025edc(&data_02174e58->mUnk_a0[1]);
    v = func_02025ebc(&data_02174e58->mUnk_a0[1]);
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
    func_02025edc(&data_02174e58->mUnk_a0[2]);
    v = func_02025ebc(&data_02174e58->mUnk_a0[2]);
    i = 0;
    d = n3 + n2;
    for (; i < d; i++) {
        q->mUnk_18[i].mUnk_06 = v;
    }
    if (data_02174e58->mUnk_74 > 0) {
        func_02025f14(&data_02174e58->mUnk_a0[3], 0);
    } else {
        func_02025f14(&data_02174e58->mUnk_a0[3], 2);
    }
    func_02025edc(&data_02174e58->mUnk_a0[3]);
    v = func_02025ebc(&data_02174e58->mUnk_a0[3]);
    n3 = n3 + 8;
    q->mUnk_18[n3].mUnk_06 = v;
    q->mUnk_18[0x11].mUnk_06 = q->mUnk_18[n3].mUnk_06;
    q->mUnk_18[0x10].mUnk_06 = q->mUnk_18[0x11].mUnk_06;
    if (data_02174e58->mUnk_84 == 0) {
        for (i = 0; i < 8; i++) {
            t = &data_02174e58->mUnk_e0[i];
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

    p = &data_02174e58->mUnk_24[0];
    for (i = 0; i < 8; i++) {
        if (i == data_02174e58->mUnk_74) {
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

    q = &data_02174e58->mUnk_24[1];
    if (a != 0) {
        f = 1;
    } else {
        f = 0;
    }
    q->mUnk_18[0x11].mUnk_00 = a;
    func_02124100(8, (u8) f, q->mUnk_14, q->mUnk_18, q->mUnk_0c);
}

void func_02031960(void) {
    s32 v;

    switch (data_02174e58->mUnk_70) {
        case 0:
            if (func_0205579c(1, data_021759d0->mUnk_1c_2) == 1) {
                data_02174e58->mUnk_70 = 1;
            }
            break;
        case 1:
            if (data_02174e58->mUnk_78 != FALSE) {
                data_02174e58->mUnk_78 = FALSE;
                data_02174e58->mUnk_70 = 3;
                data_02174e58->mUnk_9c = 0x78;
                func_02126248(GetBmgEntry(data_02174e58->mUnk_68, 0x79), 0, 1, 1, 0, 1);
                func_02025f14(&data_02174e58->mUnk_a0[0], 2);
            } else if (data_02174e58->mUnk_7c != FALSE) {
                data_02174e58->mUnk_7c = FALSE;
                data_02174e58->mUnk_70 = 7;
            } else {
                func_020554e4();
            }
            break;
        case 3:
            switch (func_0204db6c()) {
                case 1:
                    data_02174e58->mUnk_70 = 4;
                    break;
                case 2:
                    func_02032028();
                    break;
            }
            break;
        case 4:
            switch (func_02058cac()) {
                case 1:
                    if (data_02174e58->mUnk_9c == 0) {
                        if ((u8) ((data_0217aa00->mUnk_15f6 & ~data_0217aa00->mUnk_0457) & 0xfe) != 0) {
                            func_021262f0(GetBmgEntry(data_02174e58->mUnk_68, 0x81));
                            data_02174e58->mUnk_9c = 0x78;
                        } else {
                            func_02125fc0();
                        }
                        func_02108d80();
                        func_0205e5c4(1);
                        data_02174e58->mUnk_148 = FALSE;
                        data_02174e58->mUnk_70 = 6;
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
                data_02174e58->mUnk_70 = 11;
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
            if (v == 0 && data_02174e58->mUnk_9c == 0) {
                data_02174e58->mUnk_70 = 11;
            }
            break;
    }
}

void func_020317a0(void) {
    s32 v;

    switch (data_02174e58->mUnk_70) {
        case 2:
            if (data_02174e58->mUnk_7c != FALSE) {
                data_02174e58->mUnk_7c = FALSE;
                data_02174e58->mUnk_70 = 7;
                return;
            }
            switch (func_02055730(func_0202f14c()->mUnk_00)) {
                case 1:
                    if (data_021759d0->mUnk_20 == 2) {
                        func_0204aa28((data_0217aa00->mUnk_0454 & 0x40) != 0 ? 1 : 0);
                    }
                    data_02174e58->mUnk_70 = 4;
                    if (data_02174e58->mUnk_84 == 0) {
                        data_02174e58->mUnk_74 = func_02032000();
                        func_02031f5c();
                        data_02174e58->mUnk_88 = TRUE;
                    }
                    break;
                case 2:
                    func_02032028();
                    break;
            }
            break;
        case 4:
            if (data_02174e58->mUnk_7c != FALSE) {
                data_02174e58->mUnk_7c = FALSE;
                data_02174e58->mUnk_70 = 7;
                return;
            }
            switch (func_02058cac()) {
                case 1:
                    if (data_02174e58->mUnk_84 == 0 && data_02174e58->mUnk_8c == FALSE) {
                        func_02031e80();
                        func_02031b6c();
                    }
                    if (data_02174e58->mUnk_9c == 0) {
                        func_021262f0(GetBmgEntry(data_02174e58->mUnk_68, 0x81));
                        func_02108d80();
                        func_0205e5c4(1);
                        data_02174e58->mUnk_148 = FALSE;
                        data_02174e58->mUnk_9c = 0x78;
                        data_02174e58->mUnk_70 = 6;
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
                data_02174e58->mUnk_70 = 11;
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
            if (v == 0 && data_02174e58->mUnk_9c == 0) {
                data_02174e58->mUnk_70 = 11;
            }
            break;
    }
}

void func_0203154c(void *a, void *b, void *c) {
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
    data_02174e58 = HeapAlloc(h, 0x154);
    z = 0;
    MemFillWordsByBlock(z, data_02174e58, 0x154);
    data_02174e58->mHeap = h;
    data_02174e58->mUnk_5c = b;
    data_02174e58->mUnk_60 = c;
    data_02174e58->mUnk_64 = FindSceneFile(data_usa_021636f4);
    data_02174e58->mUnk_68 = func_02047a28(data_usa_02163700);
    data_02174e58->mUnk_6c = -1;
    v = GX_GetSizeOfOBJ();
    p = &data_02174e58->mUnk_24[0];
    func_02025b20(p, data_usa_0216370c, data_usa_0216372c, data_usa_0216374c, data_usa_0216376c, data_usa_02163788,
                  NULL, FindSceneFile);
    func_02025a50(0, data_02174e58->mHeap, p);
    i = 0;
    t = data_usa_02153d64;
    g = t;
    for (; i < 2; i++) {
        v -= func_02025a00(0, data_02174e58->mHeap, p, t, v);
        func_0212426c(0, g->mUnk_00, p->mUnk_14, GetBmgEntry(data_02174e58->mUnk_64, g->mUnk_08), p->mUnk_0c,
                      p->mUnk_18);
        t++;
        g++;
    }
    func_02031b6c();
    func_020258d4(1, data_02174e58, data_usa_021637a4, data_usa_021637c4, data_usa_021637e4, 3, FindSceneFile);
    r = GX_GetSizeOfSubOBJ();
    q = &data_02174e58->mUnk_24[1];
    func_02025b20(q, data_usa_02163808, data_usa_02163830, data_usa_02163858, data_usa_02163880, data_usa_021638a4,
                  data_usa_021638c8, FindSceneFile);
    func_02025a50(1, data_02174e58->mHeap, q);
    for (i = 0; i < 9; i++) {
        r -= func_02025a00(1, data_02174e58->mHeap, q, &data_usa_02153d7c[i], r);
    }
    func_02025f80(&data_02174e58->mUnk_a0[3], 3, 10, 0x40, 0);
    func_0212b928(data_02174e58->mHeap, q->mUnk_04, 3);
    func_02031b30(1);
    func_02025f80(&data_02174e58->mUnk_a0[0], 0, 10, -0x40, 0);
    func_02025f80(&data_02174e58->mUnk_a0[1], 0, 10, 0x40, 0);
    func_02025f80(&data_02174e58->mUnk_a0[2], 0, 10, -0xc0, 0);
    data_02174e58->mUnk_e0[0].mUnk_00 = 2;
    for (i = 0; i < 8; i++) {
        data_02174e58->mUnk_e0[i].mUnk_08 = i * 2;
        data_02174e58->mUnk_e0[i].mUnk_0a = i * 2 + 1;
    }
    func_02125ee8(0x20, 0);
}

void func_0203147c(void *a, void *b, void *c) {
    Unk02174e58_24 *q;
    u16 v1[11];

    func_0203154c(a, b, c);
    q = &data_02174e58->mUnk_24[1];
    MemCopyHalfwords(data_0217aa08->mUnk_00->mUnk_0c, v1, 0x14);
    v1[10] = 0;
    func_0212426c(1, data_usa_02153d7c[0].mUnk_00, q->mUnk_14, v1, q->mUnk_0c, q->mUnk_18);
    func_0212426c(1, data_usa_02153dbc[16], q->mUnk_14,
                  GetBmgEntry(data_02174e58->mUnk_64, data_usa_02153d7c[8].mUnk_08), q->mUnk_0c, q->mUnk_18);
    data_021759d0->mUnk_20 = 1;
    func_02126638(GetBmgEntry(data_02174e58->mUnk_64, 9), 0, 0, 1, 0, 0, 0);
    q->mUnk_18[0x11].mUnk_00 = 0;
    q->mUnk_18[0x10].mUnk_00 = q->mUnk_18[0x11].mUnk_00;
    func_021281c8(-1);
    FrmHeapShrinkInParent(data_02174e58->mHeap);
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

    func_0203154c(a, b, c);
    p = &data_02174e58->mUnk_24[0];
    q = &data_02174e58->mUnk_24[1];
    data_02174e58->mUnk_70 = 2;
    data_02174e58->mUnk_84 = func_0204fe90(func_0202f14c()->mUnk_00);
    v1[0] = 0;
    MemFillHalfwords(v1[0], &v1[1], 0x16);
    if (data_02174e58->mUnk_84 == 0 && func_0204ff14(func_0202f14c()->mUnk_00, &v1[1]) != 0) {
        v1[11] = 0;
        func_0212426c(1, data_usa_02153d7c[0].mUnk_00, q->mUnk_14, &v1[1], q->mUnk_0c, q->mUnk_18);
        data_02174e58->mUnk_80 = TRUE;
    }
    q->mUnk_18[0x11].mUnk_00 = 0;
    q->mUnk_18[0x10].mUnk_00 = q->mUnk_18[0x11].mUnk_00;
    v = GetBmgEntry(data_02174e58->mUnk_64, 10);
    if (data_02174e58->mUnk_84 != 0) {
        func_02126248(v, 0, 0, 1, 0, 1);
    } else {
        func_02126638(v, 0, 0, 1, 0, 0, 0);
    }
    if (data_02174e58->mUnk_84 != 0) {
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
            q->mUnk_18[data_02174e58->mUnk_e0[i].mUnk_0a].mUnk_00 = 0;
            q->mUnk_18[data_02174e58->mUnk_e0[i].mUnk_08].mUnk_00 =
                q->mUnk_18[data_02174e58->mUnk_e0[i].mUnk_0a].mUnk_00;
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
    FrmHeapShrinkInParent(data_02174e58->mHeap);
}

#pragma thumb off

#pragma thumb on

u32 func_02031268(void) {
    if (data_02174e58->mUnk_a0[2].mUnk_00 == 1) {
        return 1;
    }
    return 0;
}

u32 func_02031250(void) {
    if (data_02174e58->mUnk_a0[2].mUnk_00 == 3) {
        return 1;
    }
    return 0;
}

void func_02031208(void) {
    int v1;
    Unk02174e58_24 *v2;
    if (data_02174e58->mUnk_94 != 6) {
        v1 = 0;
        do {
            v2 = &data_02174e58->mUnk_24[v1];
            func_02124c30(v2->mUnk_0c, v2->mUnk_08, v2->mUnk_14, (&data_02174e58->mUnk_5c)[v1], v2->mUnk_18);
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
    p = &data_02174e58->mUnk_24[1];
    v2 = data_02174e58->mUnk_74;
    if (data_02174e58->mUnk_9c > 0) {
        data_02174e58->mUnk_9c = data_02174e58->mUnk_9c - 1;
    }
    func_02031960();
    if (data_02174e58->mUnk_94 != 0 && data_02174e58->mUnk_94 != 3 && data_02174e58->mUnk_94 != 4 &&
        data_02174e58->mUnk_94 != 5 && data_02174e58->mUnk_94 != 6) {
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
        data_02174e58->mUnk_74 = x;
        if (data_02174e58->mUnk_74 != v2) {
            func_02031f5c();
            if (data_02174e58->mUnk_74 > v2) {
                func_0212d5e0(&data_0217c868);
                func_0212ecc0(&data_0217d068, 0, 2);
                func_0212d5e0(&data_0217d0a0);
            } else {
                func_0212d5e0(&data_0217c868);
                func_0212ecc0(&data_0217d068, 0, 3);
                func_0212d5e0(&data_0217d0a0);
            }
        }
    }
    func_02031b6c();
    func_02031ba4();
    func_0212b80c();
    if (data_02174e58->mUnk_148 != FALSE) {
        data_02174e58->mUnk_14c = data_02174e58->mUnk_14c + 1;
        if (data_02174e58->mUnk_14c > 0x96) {
            func_02108ddc();
            data_02174e58->mUnk_148 = FALSE;
        }
    }
    switch (data_02174e58->mUnk_94) {
        case 0:
            if (func_02031268() != 0) {
                data_02174e58->mUnk_94 = 1;
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
                if (data_02174e58->mUnk_74 > 0 && data_02174e58->mUnk_a0[3].mUnk_00 == 1) {
                    func_02031b30(0);
                    func_021282c8();
                    func_0212b7e8();
                    func_0212d5e0(&data_0217c868);
                    func_0212ecc0(&data_0217d068, 0, 6);
                    func_0212d5e0(&data_0217d0a0);
                    data_02174e58->mUnk_78 = TRUE;
                    data_02174e58->mUnk_148 = TRUE;
                    data_02174e58->mUnk_94 = 2;
                    break;
                }
            }
            if ((u16) (data_02175628[k].mUnk_00 & 2) != 0 || z != 0) {
                data_02174e58->mUnk_6c = 1;
                data_02174e58->mUnk_94 = 3;
                data_02174e58->mUnk_7c = TRUE;
                func_02125fc0();
                func_02128310(0);
                func_0212d5e0(&data_0217c868);
                func_0212ecc0(&data_0217d068, 0, 5);
                func_0212d5e0(&data_0217d0a0);
            }
            break;
        case 2:
            data_02174e58->mUnk_98 = data_02174e58->mUnk_98 + 1;
            if (data_02174e58->mUnk_98 >= 5) {
                func_02031b30(1);
                if (data_02174e58->mUnk_70 == 11) {
                    data_0217b488->mUnk_04 = 1;
                    data_0217b488->mUnk_08 = 4;
                    if (a != NULL) {
                        a->mUnk_04 = 1;
                    }
                    data_02174e58->mUnk_98 = 0;
                    data_02174e58->mUnk_94 = 7;
                }
            }
            break;
        case 5:
            if (func_02125f6c() != 0) {
                func_0212ecc0(&data_0217d068, 0, 0x15);
            }
            if (func_02125f54() != 0) {
                func_02125fc0();
                data_02174e58->mUnk_6c = 0;
                data_02174e58->mUnk_94 = 3;
            }
            break;
        case 3:
            if (data_02174e58->mUnk_70 == 11) {
                func_02025f14(&data_02174e58->mUnk_a0[0], 2);
                func_02025f14(&data_02174e58->mUnk_a0[1], 2);
                func_02025f14(&data_02174e58->mUnk_a0[2], 2);
                data_02174e58->mUnk_94 = 4;
            }
            break;
        case 4:
            if (func_02031250() != 0) {
                data_02174e58->mUnk_94 = 6;
            }
            break;
        case 6:
            v1 = data_02174e58->mUnk_6c;
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
    p = &data_02174e58->mUnk_24[1];
    if (data_02174e58->mUnk_9c > 0) {
        data_02174e58->mUnk_9c = data_02174e58->mUnk_9c - 1;
    }
    func_020317a0();
    v2 = data_02174e58->mUnk_74;
    if (data_02174e58->mUnk_84 == 0 && data_02174e58->mUnk_8c == FALSE) {
        data_02174e58->mUnk_74 = func_02032000();
        if (data_02174e58->mUnk_74 != v2) {
            func_02031f5c();
            if (data_02174e58->mUnk_88 == FALSE) {
                if (data_02174e58->mUnk_74 > v2) {
                    func_0212d5e0(&data_0217c868);
                    func_0212ecc0(&data_0217d068, 0, 2);
                    func_0212d5e0(&data_0217d0a0);
                } else if (data_02174e58->mUnk_74 < v2) {
                    func_0212d5e0(&data_0217c868);
                    func_0212ecc0(&data_0217d068, 0, 3);
                    func_0212d5e0(&data_0217d0a0);
                }
                data_02174e58->mUnk_88 = FALSE;
            }
        }
        func_02031b6c();
    }
    if (data_02174e58->mUnk_84 == 0 && data_02174e58->mUnk_80 == FALSE) {
        v3[0] = 0;
        MemFillHalfwords(v3[0], &v3[1], 0x16);
        if (func_0204ff14(func_0202f14c()->mUnk_00, &v3[1]) != 0) {
            v3[11] = 0;
            func_0212426c(1, data_usa_02153d7c[0].mUnk_00, p->mUnk_14, &v3[1], p->mUnk_0c, p->mUnk_18);
            data_02174e58->mUnk_80 = TRUE;
        }
    }
    func_02031ba4();
    if (data_02174e58->mUnk_148 != FALSE) {
        data_02174e58->mUnk_14c = data_02174e58->mUnk_14c + 1;
        if (data_02174e58->mUnk_14c > 0x96) {
            func_02108ddc();
            data_02174e58->mUnk_148 = FALSE;
        }
    }
    switch (data_02174e58->mUnk_94) {
        case 0:
            if (func_02031268() != 0) {
                data_02174e58->mUnk_94 = 1;
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
            y = data_02174e58->mUnk_90;
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
                    func_02025f14(&data_02174e58->mUnk_a0[0], 2);
                    func_0212d5e0(&data_0217c868);
                    func_0212ecc0(&data_0217d068, 0, 6);
                    func_0212d5e0(&data_0217d0a0);
                    data_02174e58->mUnk_148 = TRUE;
                    data_02174e58->mUnk_90 = 1;
                    break;
                }
            }
            if (data_02174e58->mUnk_70 == 11) {
                data_0217b488->mUnk_04 = 1;
                data_0217b488->mUnk_08 = 4;
                if (a != NULL) {
                    a->mUnk_04 = 1;
                }
                data_02174e58->mUnk_94 = 7;
            } else if (y == 0) {
                if ((u16) (data_02175628[k].mUnk_00 & 2) != 0 || v != 0) {
                    data_02174e58->mUnk_6c = 0;
                    data_02174e58->mUnk_94 = 3;
                    data_02174e58->mUnk_7c = TRUE;
                    func_02125fc0();
                    func_02128310(0);
                    func_0212d5e0(&data_0217c868);
                    func_0212ecc0(&data_0217d068, 0, 3);
                    func_0212d5e0(&data_0217d0a0);
                }
            }
            break;
        case 5:
            if (func_02125f6c() != 0) {
                func_0212ecc0(&data_0217d068, 0, 0x15);
            }
            if (func_02125f54() != 0) {
                data_02174e58->mUnk_6c = 0;
                data_02174e58->mUnk_94 = 3;
                func_02125fc0();
            }
            break;
        case 3:
            if (data_02174e58->mUnk_70 == 11) {
                func_02025f14(&data_02174e58->mUnk_a0[0], 2);
                func_02025f14(&data_02174e58->mUnk_a0[1], 2);
                func_02025f14(&data_02174e58->mUnk_a0[2], 2);
                data_02174e58->mUnk_94 = 4;
            }
            break;
        case 4:
            if (func_02031250() != 0) {
                data_02174e58->mUnk_94 = 6;
            }
            break;
        case 6:
            v1 = data_02174e58->mUnk_6c;
            break;
    }
    func_02031208();
    return v1;
}

#pragma thumb off

#pragma thumb on

void func_02030ae8(void) {
    func_02125ee8(0, 0);
    func_0212b91c();
    HeapDestroy(data_02174e58->mHeap);
    *&data_02174e58 = NULL;
}

#pragma thumb off

#pragma thumb on

void func_02030a20(void) {
    s32 a;
    s32 r;

    a = 0x17;
    r = func_02025ebc(&data_02174e58->mUnk_a0[2]);
    if (data_02174e58->mUnk_84 == 0 && data_02174e58->mUnk_94 != 6) {
        a |= 8;
    }
    *(u32 *) 0x4001000 = (*(u32 *) 0x4001000 & 0xffffe0ff) | (a << 8);
    *(u32 *) 0x400101c = (-r << 16) & 0x1ff0000;
    if (r != 0) {
        *(u32 *) 0x4001000 = (*(u32 *) 0x4001000 & 0xffff1fff) | 0x2000;
        *(u16 *) 0x4001048 = (u32) ((*(u16 *) 0x4001048 & ~0x3f) | 0x1f) | 0x20;
        *(u16 *) 0x400104a = (u32) ((*(u16 *) 0x400104a & ~0x3f) | 7) | 0x20;
        *(u16 *) 0x4001040 = 0xff;
        *(u16 *) 0x4001044 = (r + 0xc0) & 0xff;
    } else {
        *(u32 *) 0x4001000 = *(u32 *) 0x4001000 & 0xffff1fff;
    }
}

#pragma thumb off
