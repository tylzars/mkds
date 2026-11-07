#include "Main/Unknown/code_0202f688.h"
#include "Main/Unknown/code_020302a0.h"

#include "Main/Unknown/unk_02174000.h"
#include "registers.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_0202f14c.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02030000.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02036c5c.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0204f000.h"
#include "Main/Unknown/code_0204f814.h"
#include "Main/Unknown/code_02054000.h"
#include "Main/Unknown/code_02054f58.h"
#include "Main/Unknown/code_02055000.h"
#include "Main/Unknown/code_020ae408.h"
#include "Main/Unknown/code_020ade08.h"
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
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_0212658c.h"
#include "Main/Unknown/code_0212775c.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128274.h"
#include "code_02148950.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_02163000.h"
#include "Main/Unknown/unk_02175000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217a000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212d214.h"
#include "code_0212df7c.h"
#include "code_0213ecf8.h"
#include "code_0214cfe4.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_0203033c.h"

#pragma thumb on

s32 func_02030274(s32 a, s32 b) {
    s32 i;
    BOOL f;

    f = FALSE;
    for (i = 0; i < 3; i++) {
        if (a == data_02153c04[b][i]) {
            f = TRUE;
            break;
        }
    }
    return f;
}

s32 func_0203023c(void) {
    BOOL r;
    s32 i;
    BOOL f;

    r = TRUE;
    i = gMultiSelectMemberGroup->mUnk_48;
    if (i != 4) {
        f = FALSE;
        if (gMultiSelectMemberGroup->mUnk_58[i].mUnk_00 != 0 && gMultiSelectMemberGroup->mUnk_58[i].mUnk_08 < 7) {
            f = TRUE;
        }
        if (f == FALSE) {
            r = FALSE;
        }
    }
    return r;
}

void func_02030200(void) {
    s32 i;
    s32 n;
    Unk02174e50_24 *p;

    p = &gMultiSelectMemberGroup->mGroupSParts;
    n = *OFFSET_PTR(u16, p->mUnk_0c, 6) + *OFFSET_PTR(u16, p->mUnk_14, 6);
    for (i = 0; i < n; i++) {
        p->mUnk_18[i].mUnk_06 = gMultiSelectMemberGroup->mBg3Offset;
    }
}

void func_0203003c(s32 a) {
    Unk02174e50_24 *p;
    Unk021634a8 t;
    s32 i;
    s32 j;
    s32 r4;
    s32 v;
    s32 w;
    s32 x;
    BOOL y;
    BOOL z;
    Unk02153c58 *q;

    p = &gMultiSelectMemberGroup->mGroupSParts;
    t = data_021634a8;
    i = 0;
    r4 = 0;
    q = data_02153c58;
    do {
        v = 0;
        if (gMultiSelectMemberGroup->mUnk_48 == i && a != 0) {
            v = 1;
        }
        x = *(s32 *) ((u8 *) gMultiSelectMemberGroup + r4 + 0x58);
        p->mUnk_18[q->mUnk_00[0]].mUnk_00 = v;
        if (v == 0) {
            w = 1;
        } else {
            w = 0;
        }
        p->mUnk_18[q->mUnk_00[0x18 / 2]].mUnk_00 = w;
        for (j = 1; j < 12; j++) {
            p->mUnk_18[q->mUnk_00[j]].mUnk_00 = v & x;
            p->mUnk_18[(q->mUnk_00 + 12)[j]].mUnk_00 = w & x;
        }
        p->mUnk_18[q->mUnk_00[1]].mUnk_00 &= *(s32 *) ((u8 *) gMultiSelectMemberGroup + r4 + 0x5c);
        p->mUnk_18[q->mUnk_00[13]].mUnk_00 &= *(s32 *) ((u8 *) gMultiSelectMemberGroup + r4 + 0x5c);
        if (*(s32 *) ((u8 *) gMultiSelectMemberGroup + r4 + 0x5c) == 0) {
            y = TRUE;
        } else {
            y = FALSE;
        }
        p->mUnk_18[q->mUnk_00[2]].mUnk_00 &= y;
        if (*(s32 *) ((u8 *) gMultiSelectMemberGroup + r4 + 0x5c) == 0) {
            y = TRUE;
        } else {
            y = FALSE;
        }
        p->mUnk_18[q->mUnk_00[14]].mUnk_00 &= y;
        for (j = 0; j < 8; j++) {
            if (j == *(s32 *) (r4 + (s32) gMultiSelectMemberGroup + 0x60)) {
                z = TRUE;
            } else {
                z = FALSE;
            }
            p->mUnk_18[(q->mUnk_00 + 4)[j]].mUnk_00 &= z;
            p->mUnk_18[(q->mUnk_00 + 16)[j]].mUnk_00 &= z;
        }
        func_02124100(q->mUnk_30, t.mUnk_00[v], p->mUnk_14, p->mUnk_18, p->mUnk_0c);
        r4 += 0xc;
        q = OFFSET_PTR(Unk02153c58, q, 0x32);
        i++;
    } while (i < 4);
    if (gMultiSelectMemberGroup->mUnk_48 == i && a != 0) {
        v = 1;
    } else {
        v = 0;
    }
    p->mUnk_18[89].mUnk_00 = v;
    if (v == 0) {
        w = 1;
    } else {
        w = 0;
    }
    p->mUnk_18[88].mUnk_00 = w;
    func_02124100(4, t.mUnk_00[v], p->mUnk_14, p->mUnk_18, p->mUnk_0c);
}

#pragma thumb off

#pragma thumb on

// Fills with 0 through a halfword stack offset of its own.
static inline void func_0202f764_inline(void *p, s32 v1) {
    volatile u16 zero = 0;
    MIi_CpuClear16(zero, p, v1);
}

void func_0202fd2c(void) {
    s32 v1;
    Unk02174e50_24 *q;
    s32 v2;
    s32 v3;
    s32 v4;
    BOOL v5;
    s32 i;
    s32 j;
    Unk02174e4c_818_04 v6;

    q = &gMultiSelectMemberGroup->mGroupSParts;
    v1 = 0;
    switch (gMultiSelectMemberGroup->mUnk_50) {
        case 0:
            if (func_0205579c(0, 0) == 1) {
                gMultiSelectMemberGroup->mUnk_50 = 1;
            }
            return;
        case 1:
            if (gMultiSelectMemberGroup->mUnk_88 != FALSE) {
                if (gMultiSelectMemberGroup->mUnk_48 < 4) {
                    for (i = 0; i < 4; i++) {
                        if (func_0204ff14(i, &func_0202f14c()->mUnk_04[i]) != 0) {
                            func_0202f14c()->mUnk_04[i].mUnk_14 = 0;
                        } else {
                            func_0202f764_inline(&func_0202f14c()->mUnk_04[i], 0x16);
                        }
                    }
                    if (func_0204ff14(gMultiSelectMemberGroup->mUnk_48, NULL) != 0) {
                        func_0202f14c()->mUnk_00 = gMultiSelectMemberGroup->mUnk_48;
                        gMultiSelectMemberGroup->mUnk_54 = 3;
                        gMultiSelectMemberGroup->mUnk_50 = 0xb;
                        return;
                    }
                    gMultiSelectMemberGroup->mUnk_58[gMultiSelectMemberGroup->mUnk_48].mUnk_00 = 0;
                    return;
                }
                gMultiSelectMemberGroup->mUnk_54 = 1;
                gMultiSelectMemberGroup->mUnk_50 = 5;
                return;
            }
            if (gMultiSelectMemberGroup->mState != 1) {
                return;
            }
            for (i = 0; i < 4; i++) {
                v2 = gMultiSelectMemberGroup->mUnk_58[i].mUnk_00;
                v3 = gMultiSelectMemberGroup->mUnk_58[i].mUnk_08;
                v4 = gMultiSelectMemberGroup->mUnk_58[i].mUnk_04;
                func_0202f764_inline(&v6, 0x16);
                gMultiSelectMemberGroup->mUnk_58[i].mUnk_00 = func_0204ff14(i, &v6);
                if (gMultiSelectMemberGroup->mUnk_58[i].mUnk_00 != 0) {
                    v6.mUnk_14 = 0;
                    func_0212426c(1, data_02153c58[i].mUnk_30, q->mUnk_14, &v6, q->mUnk_0c, q->mUnk_18);
                    gMultiSelectMemberGroup->mUnk_58[i].mUnk_08 = func_0204fe1c(i);
                    gMultiSelectMemberGroup->mUnk_58[i].mUnk_04 = func_0204fe90(i);
                } else {
                    func_0212426c(1, data_02153c58[i].mUnk_30, q->mUnk_14,
                                  GetBmgEntry(gMultiSelectMemberGroup->mBannerMessages, 8), q->mUnk_0c, q->mUnk_18);
                    gMultiSelectMemberGroup->mUnk_58[i].mUnk_08 = 0;
                    gMultiSelectMemberGroup->mUnk_58[i].mUnk_04 = 0;
                }
                if (v2 == 0 && gMultiSelectMemberGroup->mUnk_58[i].mUnk_00 != 0) {
                    v5 = TRUE;
                    for (j = 0; j < 4; j++) {
                        if (wcsncmp(v6.mUnk_00, func_0202f14c()->mUnk_04[j].mUnk_00, 0xb) == 0) {
                            v5 = FALSE;
                        }
                    }
                    if (v5 != FALSE) {
                        NNS_SndArcSetCurrent(&data_0217c868);
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 4);
                        NNS_SndArcSetCurrent(&data_0217d0a0);
                    }
                } else if (v2 != 0 && gMultiSelectMemberGroup->mUnk_58[i].mUnk_00 == 0) {
                    NNS_SndArcSetCurrent(&data_0217c868);
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 5);
                    NNS_SndArcSetCurrent(&data_0217d0a0);
                }
                v1 |= v2 != gMultiSelectMemberGroup->mUnk_58[i].mUnk_00 ? 1 : 0;
                v1 |= v3 != gMultiSelectMemberGroup->mUnk_58[i].mUnk_08 ? 1 : 0;
                v1 |= v4 != gMultiSelectMemberGroup->mUnk_58[i].mUnk_04 ? 1 : 0;
            }
            if (v1 != 0) {
                func_0203003c(1);
            }
            return;
        case 5:
        case 8:
            if (func_02054f58() == 1) {
                gMultiSelectMemberGroup->mUnk_50 = 0xb;
            }
            return;
    }
}

void InitMultiSelectMemberGroup(void *a, void *b, void *c) {
    void *v1;
    u32 v2;
    Unk02174e50_24 *q;
    s32 i;
    Unk02153c1c *v3;
    void *v4;

    v1 = CreateFrmHeapFromMaxFree(a);
    gMultiSelectMemberGroup = HeapAlloc(v1, 0xa8);
    MemFillWordsByBlock_inline(gMultiSelectMemberGroup, 0xa8);
    gMultiSelectMemberGroup->mHeap = v1;
    gMultiSelectMemberGroup->mUnk_40 = b;
    gMultiSelectMemberGroup->mUnk_44 = c;
    gMultiSelectMemberGroup->mBannerMessages = FindSceneFile(gBannerBmgName);
    gMultiSelectMemberGroup->mState = 0;
    gMultiSelectMemberGroup->mBg3Offset = -0xc0;
    func_020258d4(1, gMultiSelectMemberGroup, gMultiSelectMemberSBNcgrName2, gMultiSelectMemberSBNclrName2,
                  gMultiSelectMemberSGroupNscrName2, 3, FindSceneFile);
    v2 = GX_GetSizeOfSubOBJ();
    q = &gMultiSelectMemberGroup->mGroupSParts;
    func_02025b20(q, gMultiSelectMemberGroupSNcgrName2, gMultiSelectMemberGroupSNcerName2,
                  gMultiSelectMemberGroupSONclrName2, gMultiSelectMemberSGroupBnclName,
                  gMultiSelectMemberSGroupBnllName, gMultiSelectMemberSGroupBnblName, FindSceneFile);
    func_02025a50(1, gMultiSelectMemberGroup->mHeap, q);
    for (i = 0, v3 = data_02153c1c; i < 5; v3++, i++) {
        v2 -= func_02025a00(1, gMultiSelectMemberGroup->mHeap, q, v3, v2);
        if (data_02153c1c[i].mUnk_08 < 0) {
            v4 = data_02163610;
        } else {
            v4 = GetBmgEntry(gMultiSelectMemberGroup->mBannerMessages, data_02153c1c[i].mUnk_08);
        }
        func_0212426c(1, data_02153c1c[i].mUnk_00, q->mUnk_14, v4, q->mUnk_0c, q->mUnk_18);
    }
    func_0203003c(1);
    SetSelectReturnSoundId(0xf);
    data_021759d0->mUnk_20 = 2;
    FrmHeapShrinkInParent(gMultiSelectMemberGroup->mHeap);
}

s32 AdvanceMultiSelectMemberGroup(Unk0202f764 *a) {
    Unk02174e50_24 *q;
    s32 v1;
    u16 v2;
    s32 i;
    s32 v3;
    s32 v4;
    BOOL v5;
    BOOL v6;
    u16 v;
    s32 x;
    s32 y;
    s32 v7;

    v1 = -1;
    v2 = func_020435bc();
    q = &gMultiSelectMemberGroup->mGroupSParts;
    if (gMultiSelectMemberGroup->mUnk_9c == FALSE) {
        gMultiSelectMemberGroup->mUnk_94++;
        if (gMultiSelectMemberGroup->mUnk_94 > 0x78) {
            for (i = 0; i < 4; i++) {
                func_0202f764_inline(&func_0202f14c()->mUnk_04[i], 0x16);
            }
            gMultiSelectMemberGroup->mUnk_9c = TRUE;
        }
    }
    if (gMultiSelectMemberGroup->mState != -1) {
        func_0202fd2c();
    }
    switch (gMultiSelectMemberGroup->mState) {
        case 0:
            if (AreBrightnessFadesClear() == 0) {
                break;
            }
            if (gMultiSelectMemberGroup->mUnk_8c == 0) {
                RequestSelectReturnState1();
                func_02126638(GetBmgEntry(gMultiSelectMemberGroup->mBannerMessages, 7), 0, 0, 1, 0, 0, 0);
            }
            gMultiSelectMemberGroup->mUnk_8c++;
            if (gMultiSelectMemberGroup->mUnk_8c < 10) {
                gMultiSelectMemberGroup->mBg3Offset = InterpolateS16(1, -0xc0, 0, gMultiSelectMemberGroup->mUnk_8c, 10);
            } else {
                gMultiSelectMemberGroup->mUnk_8c = 0;
                gMultiSelectMemberGroup->mBg3Offset = 0;
                gMultiSelectMemberGroup->mState = 1;
            }
            func_02030200();
            break;
        case 1:
            v3 = 0;
            v4 = -1;
            v5 = FALSE;
            v6 = FALSE;
            v = data_02175628[v2].mHasPair;
            if (v == 0 && data_02175628[v2].mNoPairCount < 5) {
                v6 = TRUE;
            }
            if (v6 == FALSE && data_02175628[v2].mPrevHasPair == 0 && v != 0) {
                v5 = TRUE;
            }
            if (v5 != FALSE) {
                x = data_02175628[v2].mPairX;
                y = data_02175628[v2].mPairY;
                v3 = IsSelectReturnState2NoState3Or4RequestAndInRect(x, y);
                v4 = RectTableFindContaining(q->mUnk_10, x, y);
            }
            v = data_02175628[v2].mUnk_00;
            if ((u16) (v & PAD_KEY_A) != 0) {
                if (func_0203023c() != 0) {
                    gMultiSelectMemberGroup->mUnk_88 = TRUE;
                    gMultiSelectMemberGroup->mState = 2;
                    gMultiSelectMemberGroup->mUnk_98 = 0;
                    func_0203003c(0);
                    if (gMultiSelectMemberGroup->mUnk_48 == 4) {
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x4e);
                    } else {
                        if ((data_0217aa00 == NULL ? 0 : data_0217aa00->mUnk_0000) == 2) {
                            data_0217aa00->mUnk_0436 |= 1;
                        }
                        NNS_SndArcSetCurrent(&data_0217c868);
                        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 2);
                        NNS_SndArcSetCurrent(&data_0217d0a0);
                    }
                } else {
                    NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x4f);
                }
            } else if ((u16) (v & PAD_KEY_B) != 0 || v3 != 0) {
                if (a != NULL) {
                    a->mUnk_04 = 0;
                }
                gMultiSelectMemberGroup->mState = 3;
                RequestSelectReturnState3WithSound(1);
            } else if (GetNewOrRepeatBits(v2, PAD_KEY_UP) != 0) {
                gMultiSelectMemberGroup->mUnk_48--;
                if (gMultiSelectMemberGroup->mUnk_48 < 0) {
                    gMultiSelectMemberGroup->mUnk_48 = 4;
                }
                func_0203003c(1);
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
            } else if (GetNewOrRepeatBits(v2, PAD_KEY_DOWN) != 0) {
                gMultiSelectMemberGroup->mUnk_48++;
                if (gMultiSelectMemberGroup->mUnk_48 > 4) {
                    gMultiSelectMemberGroup->mUnk_48 = 0;
                }
                func_0203003c(1);
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
            } else if (v4 == 0xc) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x4e);
                func_0203003c(gMultiSelectMemberGroup->mUnk_48 != 4 ? 1 : 0);
                gMultiSelectMemberGroup->mUnk_98 = 0;
                gMultiSelectMemberGroup->mState = 2;
                gMultiSelectMemberGroup->mUnk_48 = 4;
                gMultiSelectMemberGroup->mUnk_88 = TRUE;
            } else {
                for (i = 0; i < 4; i++) {
                    if (func_02030274(v4, i) != 0) {
                        v7 = gMultiSelectMemberGroup->mUnk_48 != i ? 1 : 0;
                        if (gMultiSelectMemberGroup->mUnk_58[i].mUnk_00 != 0 &&
                            gMultiSelectMemberGroup->mUnk_58[i].mUnk_08 < 7) {
                            NNS_SndArcSetCurrent(&data_0217c868);
                            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 2);
                            NNS_SndArcSetCurrent(&data_0217d0a0);
                            gMultiSelectMemberGroup->mUnk_48 = i;
                            func_0203003c(v7);
                            gMultiSelectMemberGroup->mUnk_98 = 0;
                            gMultiSelectMemberGroup->mState = 2;
                            gMultiSelectMemberGroup->mUnk_88 = TRUE;
                        } else {
                            NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0x4f);
                        }
                    }
                }
            }
            break;
        case 2:
            gMultiSelectMemberGroup->mUnk_98++;
            if (gMultiSelectMemberGroup->mUnk_98 >= 5) {
                gMultiSelectMemberGroup->mUnk_98 = 0;
                func_0203003c(1);
                if (gMultiSelectMemberGroup->mUnk_48 < 4 &&
                    gMultiSelectMemberGroup->mUnk_58[gMultiSelectMemberGroup->mUnk_48].mUnk_00 == 0) {
                    gMultiSelectMemberGroup->mState = 1;
                } else {
                    gMultiSelectMemberGroup->mState = 3;
                    RequestTxtSystemClose();
                }
            }
            break;
        case 3:
            gMultiSelectMemberGroup->mUnk_8c++;
            if (gMultiSelectMemberGroup->mUnk_8c < 10) {
                gMultiSelectMemberGroup->mBg3Offset = InterpolateS16(1, 0, -0xc0, gMultiSelectMemberGroup->mUnk_8c, 10);
            } else {
                gMultiSelectMemberGroup->mUnk_8c = 0;
                gMultiSelectMemberGroup->mBg3Offset = 0;
                gMultiSelectMemberGroup->mState = 4;
            }
            func_02030200();
            break;
        case 4:
            if (gMultiSelectMemberGroup->mUnk_50 == 0xb) {
                v1 = gMultiSelectMemberGroup->mUnk_54;
            }
            break;
    }
    if (gMultiSelectMemberGroup->mState != 4) {
        DrawLayoutTable(q->mUnk_0c, q->mUnk_08, q->mUnk_14, gMultiSelectMemberGroup->mUnk_44, q->mUnk_18);
    }
    return v1;
}

#pragma thumb off

#pragma thumb on

void ReleaseMultiSelectMemberGroup(void) {
    HeapDestroy(gMultiSelectMemberGroup->mHeap);
    *&gMultiSelectMemberGroup = NULL;
}

#pragma thumb off

#pragma thumb on

void func_0202f688(void) {
    u32 v = 0x16;
    s32 y;

    if (gMultiSelectMemberGroup->mState != 4) {
        v |= 8;
    }
    reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffffe0ff) | (v << 8);
    reg_G2S_DB_BG3OFS = (-gMultiSelectMemberGroup->mBg3Offset << 16) & 0x1ff0000;
    if (gMultiSelectMemberGroup->mBg3Offset != 0) {
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffff1fff) | 0x2000;
        reg_G2S_DB_WININ = (u32) ((reg_G2S_DB_WININ & ~0x3f) | 0x1f) | 0x20;
        reg_G2S_DB_WINOUT = (u32) ((reg_G2S_DB_WINOUT & ~0x3f) | 7) | 0x20;
        y = gMultiSelectMemberGroup->mBg3Offset + 0xc0;
        reg_G2S_DB_WIN0H = 0xff;
        reg_G2S_DB_WIN0V = y & 0xff;
    } else {
        reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffff1fff;
    }
}

#pragma thumb off
