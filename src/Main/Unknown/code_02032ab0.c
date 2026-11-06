#include "Main/Unknown/code_02032ab0.h"
#include "Main/Unknown/code_0202578c.h"

#include "00/code_021832d8.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_020336ec.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_0205d0e8.h"
#include "Main/Unknown/code_02033d9c.h"
#include "Main/Unknown/code_02033dd0.h"
#include "Main/Unknown/code_02053e74.h"
#include "Main/Unknown/code_02054f58.h"
#include "Main/Unknown/code_02061654.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_0210f714.h"
#include "Main/Unknown/code_02120610.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bc8.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02125da0.h"
#include "Main/Unknown/code_021258f0.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_021277ac.h"
#include "Main/Unknown/code_020a23a0.h"
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
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "00/code_0219b580.h"
#include "Main/Unknown/code_02025b84.h"
#include "Main/Unknown/code_02033000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02037000.h"
#include "Main/Unknown/code_02038000.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0205d000.h"
#include "Main/Unknown/code_02062000.h"
#include "Main/Unknown/code_020ad000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_020cbad0.h"
#include "Main/Unknown/code_02122734.h"
#include "Main/Unknown/code_02122b14.h"
#include "Main/Unknown/code_02125960.h"
#include "Main/Unknown/code_02125de0.h"
#include "code_02148950.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_02154000.h"
#include "Main/Unknown/unk_02164000.h"
#include "01/code_021804e0.h"
#include "code_0201ea30.h"
#include "code_0214b824.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"

#pragma thumb on

// Fills with 0 through a halfword stack offset of its own.
static inline void func_02032f94_inline(void *p, s32 n) {
    volatile u16 v = 0;
    MIi_CpuClear16(v, p, n);
}

static inline Unk0217aa1c_144_00 *func_02032f94_inline_2(s32 j) {
    return &data_0217aa1c->mUnk_144[func_0205db28()].mUnk_00[j];
}

static inline Unk0217aa1c_144 *func_02032f94_inline_3(void) {
    return &data_0217aa1c->mUnk_144[func_0205db28()];
}

void func_02032f94(void *a, s32 b, s32 c) {
    Unk02180774 *r;
    Unk02174e14_00 *s;
    Unk02174e14_00 *q;
    Unk02174e60 *p;
    Unk02174e60_00 *t;
    Unk0201ea30 *u;
    u32 n;
    s32 j;
    s32 k;
    s32 e;
    u16 i;
    u16 m;
    u16 w[11];
    Unk02125de0 v;
    s32 f[8];

    data_02174e60 = HeapAlloc(a, 0x154);
    MemFillWordsByBlock_inline(data_02174e60, 0x154);
    data_02174e60->mUnk_0b8[0] = b;
    data_02174e60->mUnk_0b8[1] = c;
    data_02174e60->mUnk_0e0 = data_021759d0->mUnk_20;
    if (data_02174e60->mUnk_0e0 == 3) {
        func_02123a48(3);
    }
    func_02062860();
    r = func_02038d88(a, data_021547f0);
    func_02038d58(r->mUnk_28, 3, 0, 0, 0, 0xd, 2, 0);
    func_02038d28(r->mUnk_28, 0, 0, 0, 0, 0xc, 0, 0);
    func_02038d00(r->mUnk_28, 2, 0, 0, 0, 0x1e, 6);
    func_02038cd8(r->mUnk_28, 3, 0, 0, 0, 0x1d, 6);
    func_02038cd8(r->mUnk_70, 3, 0, 0, 0, 1, 6);
    func_02037abc(r);
    v.mUnk_00 = 0;
    v.mUnk_04 = NULL;
    v.mUnk_08 = 0;
    v.mUnk_0c = 0;
    v.mUnk_10 = 0;
    v.mUnk_14 = 1;
    v.mUnk_18 = func_020b403c(2);
    v.mUnk_1c = 0;
    v.mUnk_20 = 0;
    v.mUnk_24 = 0;
    LoadTxtSystemAndSelectChoisesAndSelectReturnData();
    func_02125de0(a, &v);
    func_020629a4();
    data_02174e60->mUnk_0c8 = func_02047a28(data_0216416c);
    switch (data_02174e60->mUnk_0e0) {
        case 0:
            data_02174e60->mUnk_0d0 = 0;
            data_02174e60->mUnk_0d8 = data_021759c0->mKartCount;
            data_02174e60->mUnk_150 = 2;
            break;
        case 1:
        case 2:
            func_0212775c(1, 0xf);
            data_02174e60->mUnk_0d0 =
                data_0217aa00->mUnk_1e52[(u16) (data_0217aa00->mUnk_0000 == 2 ? data_0217aa00->mUnk_0432 : 0)].mUnk_00;
            data_02174e60->mUnk_0d8 = data_021759c0->mKartCount;
            data_02174e60->mUnk_150 = 0;
            break;
        case 3:
            data_02174e60->mUnk_0d0 = func_02122778(func_ov000_0219bb50());
            data_02174e60->mUnk_0d8 = gWiFiSession->mKartCount;
            data_02174e60->mUnk_148 = TRUE;
            data_02174e60->mUnk_14c = 0x384;
            data_02174e60->mUnk_150 = 2;
            break;
    }
    func_02033e6c();
    if (data_021759c0->mUseTeams != 0) {
        j = 0;
        k = 0;
        switch (data_021759c0->mUnk_1c) {
            case 1:
                j = func_02032f94_inline_2(0)->mUnk_02;
                k = func_02032f94_inline_2(1)->mUnk_02;
                break;
            case 2:
                j = func_02032f94_inline_3()->mUnk_00[0].mUnk_00;
                k = func_02032f94_inline_3()->mUnk_00[1].mUnk_00;
                break;
        }
        if (j == k) {
            data_02174e60->mUnk_0d4 = data_02174e60->mUnk_0d8;
            data_02174e60->mUnk_0dc = 2;
        } else if (j > k) {
            data_02174e60->mUnk_0d4 = data_021759c0->mTeamKartCounts[0];
            data_02174e60->mUnk_0dc = 3;
        } else if (k > j) {
            data_02174e60->mUnk_0d4 = data_021759c0->mTeamKartCounts[1];
            data_02174e60->mUnk_0dc = 4;
        }
    } else if (func_02033e24() != 0) {
        data_02174e60->mUnk_0d4 = data_02174e60->mUnk_0d8;
        data_02174e60->mUnk_0dc = 2;
    } else if (data_02174e60->mUnk_0e4[data_02174e60->mUnk_0d0].mUnk_00 == 0) {
        data_02174e60->mUnk_0dc = 0;
    } else {
        data_02174e60->mUnk_0dc = 1;
    }
    func_02025b84(1, &data_02174e60->mUnk_048[2]);
    func_02025b84(0, &data_02174e60->mUnk_048[3]);
    data_02174e60->mUnk_0c0 = func_020b4024(1);
    data_02174e60->mUnk_0c4 = func_020b4024(0);
    t = &data_02174e60->mUnk_000[0];
    func_02025884(t, data_02153f80[data_02174e60->mUnk_0dc][0], data_02153f84[data_02174e60->mUnk_0dc][0],
                  data_02153f8c[data_02174e60->mUnk_0dc][0], 3, FindSceneFile);
    LoadNscrData(&t->mUnk_14[2], FindSceneFile(data_02153f88[data_02174e60->mUnk_0dc][0]));
    MemCopyWordsToG2Bg3CntBits2To5Address(t->mUnk_00[3]->mData, 0, t->mUnk_00[3]->mDataSize);
    GX_LoadBGPltt(t->mUnk_10->mData, 0, 0x140);
    MemCopyHalfwordsToG2Bg2CntBits8To12Address(t->mUnk_14[2]->mData, 0, t->mUnk_14[2]->mDataSize);
    MemCopyHalfwordsToG2Bg3CntBits8To12Address(t->mUnk_14[3]->mData, 0, t->mUnk_14[3]->mDataSize);
    s = &data_02174e60->mUnk_048[0];
    func_02025abc(s, data_02153f90[data_02174e60->mUnk_0dc][0], data_02153f94[data_02174e60->mUnk_0dc][0],
                  data_02153f98[data_02174e60->mUnk_0dc][0], data_02153f9c[data_02174e60->mUnk_0dc][0],
                  data_02153fa0[data_02174e60->mUnk_0dc][0], NULL, FindSceneFile);
    func_02025a50(0, a, s);
    switch (data_02174e60->mUnk_0dc) {
        case 0:
            func_02033a0c(a);
            break;
        case 1:
            func_020338f8(a);
            break;
        case 2:
            func_02033840(a);
            break;
        case 3:
        case 4:
            func_020336ec(a);
            break;
    }
    u = s->mUnk_0c;
    for (i = 0; i < u->mUnk_06; i++) {
        func_0201ea30(s->mUnk_0c, i);
    }
    t = &data_02174e60->mUnk_000[1];
    func_02025884(t, data_02164178, data_02164190, data_021641a8, 3, FindSceneFile);
    MemCopyWordsToG2sBg3CntBits2To5Address(t->mUnk_00[3]->mData, 0, t->mUnk_00[3]->mDataSize);
    GXS_LoadBGPltt(t->mUnk_10->mData, 0, 0x140);
    MemCopyHalfwordsToG2sBg3CntBits8To12Address(t->mUnk_14[3]->mData, 0, t->mUnk_14[3]->mDataSize);
    n = GX_GetSizeOfSubOBJ();
    p = data_02174e60;
    q = &p->mUnk_048[1];
    func_02025abc(q, data_021641c4, data_021641e0, data_021641fc, data_02164214, data_0216422c, NULL, FindSceneFile);
    func_02124ed0(a, q->mUnk_0c, q->mUnk_14, &q->mUnk_18);
    GXS_LoadOBJ(((Ncgr *) p->mUnk_048[1].mUnk_00)->mData, 0, ((Ncgr *) p->mUnk_048[1].mUnk_00)->mDataSize);
    GXS_LoadOBJPltt(((Nclr *) q->mUnk_04)->mData, 0, ((Nclr *) q->mUnk_04)->mDataSize);
    for (i = 0; i < q->mUnk_14->mUnk_06; i++) {
        n -= func_02025a00(1, a, q, data_02153f00[i], n);
    }
    for (i = 0; i < q->mUnk_0c->mUnk_06; i++) {
        func_021249a8(i, 2, q->mUnk_08, q->mUnk_0c);
    }
    for (i = 0; i < 8; i++) {
        f[i] = 0;
    }
    for (m = 0; m < 8; m++) {
        e = data_02174e60->mUnk_0e4[m].mUnk_08;
        k = data_021759c0->mCurrentEntries[m].mPlayer.mKind;
        if ((k == 0 || k == 1 || k == 3) && (data_02174e60->mUnk_0e0 != 3 || data_02174e60->mUnk_0e4[m].mUnk_04 != 0)) {
            func_02033ab8(1, m, e + 0x30, 1);
            func_02032f94_inline(w, 0x16);
            func_020adff0(m, w, 0);
            func_0212426c(1, e, q->mUnk_14, w, q->mUnk_0c, q->mUnk_18);
            func_02033b80(m);
            func_02033c80(m);
            f[e] = 1;
        }
    }
    for (i = 0; i < 8; i++) {
        if (f[i] == 0) {
            q->mUnk_18[i + 0x48].mUnk_00 = 0;
            q->mUnk_18[i + 0x30].mUnk_00 = q->mUnk_18[i + 0x48].mUnk_00;
            q->mUnk_18[i + 0x38].mUnk_00 = q->mUnk_18[i + 0x30].mUnk_00;
            q->mUnk_18[i + 0x28].mUnk_00 = q->mUnk_18[i + 0x38].mUnk_00;
            q->mUnk_18[i + 0x20].mUnk_00 = q->mUnk_18[i + 0x28].mUnk_00;
            q->mUnk_18[i + 0x18].mUnk_00 = q->mUnk_18[i + 0x20].mUnk_00;
            q->mUnk_18[i + 0x10].mUnk_00 = q->mUnk_18[i + 0x18].mUnk_00;
            q->mUnk_18[i + 0x08].mUnk_00 = q->mUnk_18[i + 0x10].mUnk_00;
            q->mUnk_18[i].mUnk_00 = q->mUnk_18[i + 0x08].mUnk_00;
        }
    }
    switch (data_02174e60->mUnk_0dc) {
        case 3:
            if (data_021759c0->mCurrentEntries[(u16) data_02174e60->mUnk_0d0].mPlayer.mTeamIndex == 0) {
                k = 0;
            } else {
                k = 7;
            }
            break;
        case 4:
            if (data_021759c0->mCurrentEntries[(u16) data_02174e60->mUnk_0d0].mPlayer.mTeamIndex == 1) {
                k = 0;
            } else {
                k = 7;
            }
            break;
        case 0:
            k = 0;
            break;
        default:
            k = 7;
            break;
    }
    func_020a269c(8, (u16) k);
}

#pragma thumb off

#pragma thumb on

void func_02032ac4(Unk02032ac4 *a) {
    Unk02174e14_00 *s;
    Unk02174e14_00 *t;
    Unk02175628Index v1;
    s32 x;
    s32 j;
    void *m;
    void *n;
    void *m2;
    void *n2;
    s32 i;
    s32 r;

    t = &data_02174e60->mUnk_048[1];
    s = &data_02174e60->mUnk_048[0];
    if (data_02174e60->mUnk_148 != FALSE) {
        if (data_02174e60->mUnk_14c != 0) {
            data_02174e60->mUnk_14c = data_02174e60->mUnk_14c - 1;
            x = (data_02174e60->mUnk_14c + 0x3c) / 0x3c;
            s->mUnk_18[data_02174e60->mUnk_0ce].mUnk_00 = x >= 10 ? 1 : 0;
            if (data_02174e60->mUnk_14c == 0) {
                func_0212ecc0(&data_0217d068, 0, 0x51);
            } else if ((data_02174e60->mUnk_14c + 0x3c) % 0x3c == 0 && x <= 4) {
                func_0212ecc0(&data_0217d068, 0, 0x50);
            }
        } else {
            x = 0;
        }
        m = s->mUnk_0c;
        n = s->mUnk_08;
        func_02124748(data_02174e60->mUnk_0cc + (x / 10) % 10, n, s->mUnk_00, m, 0, data_02174e60->mUnk_0ce, n, m);
        m2 = s->mUnk_0c;
        n2 = s->mUnk_08;
        func_02124748(data_02174e60->mUnk_0cc + x % 10, n2, s->mUnk_00, m2, 0, data_02174e60->mUnk_0ce + 1, n2, m2);
    } else {
        s->mUnk_18[data_02174e60->mUnk_0ce + 1].mUnk_00 = 0;
        s->mUnk_18[data_02174e60->mUnk_0ce].mUnk_00 = s->mUnk_18[data_02174e60->mUnk_0ce + 1].mUnk_00;
    }
    switch (data_02174e60->mUnk_150) {
        case 0:
            data_02174e60->mUnk_144 = data_02174e60->mUnk_144 + 1;
            if (func_020546d8() == 1) {
                data_02174e60->mUnk_150 = 1;
            }
            break;
        case 1:
            data_02174e60->mUnk_144 = data_02174e60->mUnk_144 + 1;
            if (func_02054754() == 1) {
                data_02174e60->mUnk_150 = 2;
            }
            break;
        case 2:
            r = func_0210f714();
            data_02174e60->mUnk_144 = data_02174e60->mUnk_144 + 1;
            if (data_02174e60->mUnk_144 > r) {
                data_02174e60->mUnk_144 = 0;
                data_02174e60->mUnk_150 = 3;
            }
            break;
        case 3:
            switch (data_02174e60->mUnk_0e0) {
                case 0:
                    if ((u16) (data_02175628[func_020435bc()].mUnk_00 & 1) != 0) {
                        func_0212ecc0(&data_0217d068, 0, 5);
                        if (a != NULL) {
                            a->mUnk_04 = 1;
                        }
                        data_02174e60->mUnk_150 = 7;
                    }
                    break;
                case 1:
                case 2:
                    v1 = UNK_02175628_INDEX_8;
                    if ((u16) (data_02175628[v1].mUnk_00 & 1) != 0) {
                        func_02033d9c();
                        data_02174e60->mUnk_150 = 4;
                        func_0212ecc0(&data_0217d068, 0, 5);
                    }
                    break;
                case 3:
                    if (func_02033dfc() != 0) {
                        func_02121dec(1);
                        data_02174e60->mUnk_150 = 5;
                    } else if ((u16) (data_02175628[func_020435bc()].mUnk_00 & 1) != 0 || func_02033dd0() != 0) {
                        func_02033d9c();
                        func_0212ecc0(&data_0217d068, 0, 5);
                        data_02174e60->mUnk_150 = 4;
                    }
                    break;
            }
            break;
        case 4:
            switch (data_02174e60->mUnk_0e0) {
                case 1:
                case 2:
                    if (func_02127788() != 0) {
                        switch (func_02127794()) {
                            case 0:
                                if (data_021759d0->mUnk_1c_2 != 0) {
                                    data_0217b488->mUnk_74 = 3;
                                    data_0217b488->mUnk_08 = 4;
                                    if (a != NULL) {
                                        a->mUnk_04 = 6;
                                    }
                                } else {
                                    data_0217b488->mUnk_08 = 4;
                                    if (a != NULL) {
                                        a->mUnk_04 = 1;
                                    }
                                }
                                data_02174e60->mUnk_150 = 7;
                                break;
                            case 1:
                                data_0217aa00->mUnk_0454 = data_0217aa00->mUnk_0454 | 0x80;
                                data_02174e60->mUnk_150 = 6;
                                break;
                            case -1:
                                data_02174e60->mUnk_150 = 3;
                                break;
                        }
                        func_021277e4();
                    }
                    break;
                case 3:
                    if (func_02127788() != 0 || func_02033dfc() != 0) {
                        switch (func_02127794()) {
                            case 0:
                                data_02174e60->mUnk_150 = 5;
                                func_02121dec(1);
                                break;
                            case 1:
                                func_02121dec(0);
                                data_0217b488->mUnk_1c = 1;
                                if (a != NULL) {
                                    a->mUnk_04 = 0xc;
                                }
                                data_02174e60->mUnk_150 = 7;
                                break;
                            case -1:
                                data_02174e60->mUnk_150 = 3;
                                break;
                        }
                        func_021277e4();
                    }
                    break;
            }
            break;
        case 5:
            if (func_02121c78() != 0) {
                switch (func_02121c78()) {
                    case 1:
                        data_0217b488->mUnk_1c = 2;
                        break;
                    case 2:
                        data_0217b488->mUnk_1c = 1;
                        break;
                }
                if (a != NULL) {
                    a->mUnk_04 = 0xc;
                }
                data_02174e60->mUnk_150 = 7;
            }
            break;
        case 6:
            if (func_02054f58() == 1) {
                if (a != NULL) {
                    a->mUnk_04 = 0;
                }
                data_02174e60->mUnk_150 = 7;
            }
            break;
    }
    func_020a2558();
    func_020a23cc();
    for (i = 0; i < 2; i++) {
        func_02124c30(data_02174e60->mUnk_048[i].mUnk_0c, data_02174e60->mUnk_048[i].mUnk_08,
                      data_02174e60->mUnk_048[i].mUnk_14, (void *) data_02174e60->mUnk_0b8[i],
                      data_02174e60->mUnk_048[i].mUnk_18);
    }
    j = t->mUnk_0c->mUnk_06;
    for (i = 0; i < 8; i++) {
        t->mUnk_18[i + j].mUnk_06 = t->mUnk_18[i + j].mUnk_06 + 1;
        func_02124100(i, 0xe, t->mUnk_14, t->mUnk_18, t->mUnk_0c);
        func_02124bc8(i + j, t->mUnk_0c, t->mUnk_08, t->mUnk_14, (void *) data_02174e60->mUnk_0b8[1], t->mUnk_18);
        func_02124100(i, 0xf, t->mUnk_14, t->mUnk_18, t->mUnk_0c);
        t->mUnk_18[i + j].mUnk_06 = t->mUnk_18[i + j].mUnk_06 - 1;
    }
    func_02125928();
}

void func_02032ab0(void) {
    data_0217b488->mUnk_04 = 1;
    func_02125da0();
}

#pragma thumb off
