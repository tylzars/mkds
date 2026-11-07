#include "Main/Unknown/code_020351c8.h"

#include "Main/Unknown/code_020b3f7c.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_02125ed0.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02126000.h"
#include "Main/Unknown/code_02124094.h"
#include "Main/Unknown/code_0212658c.h"
#include "Main/Unknown/unk_02174000.h"
#include "Main/Unknown/unk_0217d068.h"
#include "code_0212df7c.h"
#include "Main/Unknown/code_02025000.h"
#include "Main/Unknown/code_02126230.h"
#include "Main/Unknown/code_0202578c.h"
#include "Main/Unknown/code_0202d990.h"
#include "Main/Unknown/code_0202dd9c.h"
#include "Main/Unknown/code_0202e4b0.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_0202db04.h"
#include "Main/Unknown/code_0202e468.h"
#include "Main/Unknown/code_02025b84.h"
#include "Main/Unknown/code_02025bb4.h"
#include "Main/Unknown/code_0203434c.h"
#include "Main/Unknown/code_02036000.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_0204f7f4.h"
#include "Main/Unknown/code_020566a8.h"
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
#include "Main/Unknown/code_02124bf0.h"
#include "Main/Unknown/code_02124f4c.h"
#include "Main/Unknown/code_02125ee8.h"
#include "Main/Unknown/code_02125f2c.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02128210.h"
#include "Main/Unknown/code_02128274.h"
#include "Main/Unknown/code_0212775c.h"
#include "code_02148950.h"
#include "Main/Unknown/code_0214d000.h"
#include "Main/Unknown/unk_02153000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "00/code_02181f98.h"
#include "code_0212d214.h"
#include "code_0214cfe4.h"
#include "Main/Unknown/code_02025d5c.h"
#include "01/code_021956dc.h"
#include "code_0214d018.h"
#include "Main/Unknown/code_02025edc.h"
#include "Main/Unknown/code_02025f80.h"
#include "Main/Unknown/code_02025cd0.h"
#include "registers.h"

#pragma thumb on

void func_02035c50(s32 a, s32 b, s32 c, s32 d) {
    Unk02174e14_00 *s;
    s32 i;
    s32 v;
    s32 e;
    u8 x[4];
    s16 w[12];

    s = &data_02174e68->mUnk_2c[1];
    if (a == 1) {
        c += func_0202ddb0();
        func_0212426c(1, b, s->mUnk_14, GetBmgEntry(data_02174e68->mGhostMessages, func_02025d74(func_0202db04(c))),
                      s->mUnk_0c, s->mUnk_18);
        func_0202dcf4(c, x);
        func_02025cd0(w, x[2], x[3], *(u16 *) x);
        func_02124224(1, b + 7, s->mUnk_14, w, s->mUnk_0c, s->mUnk_18, 7);
    } else if (a == 0) {
        for (i = 0; i < 7; i++) {
            e = i + 7;
            if (i == d) {
                v = 14;
            } else {
                v = 15;
            }
            func_02124100(i, v, s->mUnk_14, s->mUnk_18, s->mUnk_0c);
            func_02124100(e, v, s->mUnk_14, s->mUnk_18, s->mUnk_0c);
        }
    }
}

#pragma thumb off

#pragma thumb on

void func_02035c14(void) {
    void *v1;
    v1 = GetBmgEntry(data_02174e68->mGhostMessages, 3);
    SetTxtSystemBgOffsetRequested(0xfffffff4, 0);
    func_02126638(v1, 0, 0, 0, 0, 0, 0);
}

#pragma thumb off

#pragma thumb on

static inline s32 func_0203551c_inline(void) {
    Unk021759d4 *p = data_021759d4;
    if (p->mBackupEnabled != 0) {
        return p->mUnk_10;
    }
    return 0;
}

static inline s32 func_0203551c_inline_2(void) {
    if (data_0217aa08->mUnk_28 == 0) {
        return func_0203551c_inline();
    }
    return 1;
}

void SetupGhostNameSubTextTwoButtons(void) {
    void *e;
    void *f;
    void *g;
    u8 y[0x14];
    u16 w[11];
    u16 h[0x100];

    e = GetBmgEntry(data_02174e68->mGhostMessages, 0x12);
    f = GetBmgEntry(data_02174e68->mCommonMessages, 0);
    g = GetBmgEntry(data_02174e68->mCommonMessages, 1);
    func_0202dc68(data_02174e68->mSelectedIndex + func_0202ddb0(), y);
    MIi_CpuCopy16(y, w, 0x14);
    w[10] = 0;
    func_0212513c(w, e, h, 0x100);
    SetTxtSystemSoundId(0, -1);
    SetupTxtSystemSubTextTwoButtonsEx(h, f, g, 1, 0, 1, 1, 0);
}

void func_02035b0c(void) {
    Unk02174e14_00 *s;
    Unk02174e14_00 *t;
    s32 n;
    s32 m;
    s32 i;
    s16 c;

    s = &data_02174e68->mUnk_2c[0];
    t = &data_02174e68->mUnk_2c[1];
    n = s->mUnk_0c->mUnk_06 + s->mUnk_14->mUnk_06;
    m = t->mUnk_0c->mUnk_06 + t->mUnk_14->mUnk_06;
    c = func_02025ebc(&data_02174e68->mUnk_90);
    for (i = 0; i < n; i++) {
        s->mUnk_18[i].mUnk_06 = -c;
    }
    for (i = 0; i < m; i++) {
        t->mUnk_18[i].mUnk_06 = c;
    }
}

void PrintSelectedGhostRecord(void) {
    s32 n;
    u32 d;
    u32 e;
    u32 f;
    u32 x;
    u8 y[0x14];
    u16 w[11];

    n = func_0202ddb0() + data_02174e68->mSelectedIndex;
    func_0202dcf4(n, &x);
    func_0202dc68(n, y);
    MIi_CpuCopy16(y, w, 0x14);
    w[10] = 0;
    d = func_0202dbe8(n);
    e = func_0202db68(n);
    f = func_0202db04(n);
    func_0202de00((Unk02174e14 *) &data_02174e68->mUnk_2c[0], data_0215404c, w, d, e, f, (Unk0202de00_g *) &x);
}

void func_020357dc(void *a, void *b, void *c) {
    void *h;
    Unk02174e14_00 *s;
    s32 i;
    u32 n;
    s32 j;
    s32 k;
    s32 m;
    s32 x;
    s32 y;
    s32 z;
    s16 *t;
    void *g;
    u16 w[3];

    h = CreateFrmHeapFromMaxFree(a);
    data_02174e68 = HeapAlloc(h, 0xa8);
    MemFillWordsByBlock_inline(data_02174e68, 0xa8);
    data_02174e68->mHeap = h;
    data_02174e68->mUnk_24[0] = b;
    data_02174e68->mUnk_24[1] = c;
    data_02174e68->mCommonMessages = FindFileInLoadedArchives(data_021644e0);
    data_02174e68->mGhostMessages = FindSceneFile(data_021644ec);
    s = &data_02174e68->mUnk_2c[0];
    n = GX_GetSizeOfOBJ();
    func_02025b20(s, data_021644f8, data_02164518, data_02164538, data_02164558, data_02164574, NULL, FindSceneFile);
    func_02025a50(0, data_02174e68->mHeap, s);
    for (i = 0; i < s->mUnk_14->mUnk_06; i++) {
        n -= func_02025a00(0, data_02174e68->mHeap, s, data_0215404c[i], n);
    }
    func_020258d4(1, data_02174e68, data_02164590, data_021645b0, data_021645d0, 3, FindSceneFile);
    s = &data_02174e68->mUnk_2c[1];
    n = GX_GetSizeOfSubOBJ();
    k = 0;
    func_02025b20(s, data_021645ec, data_0216460c, data_0216462c, gTimeAttackGhostGetSBnclName,
                  gTimeAttackGhostGetSBnllName, gTimeAttackGhostGetSBnblName, FindSceneFile);
    func_02025a50(1, data_02174e68->mHeap, s);
    m = s->mUnk_0c->mUnk_06;
    j = 0;
    if (j < s->mUnk_14->mUnk_06) {
        t = data_02164470[0];
        do {
            if (t[3] < 0) {
                t[3] = m + k++;
            }
            n -= func_02025a00(1, data_02174e68->mHeap, s, data_02164470[j], n);
            t += 4;
            j++;
        } while (j < s->mUnk_14->mUnk_06);
    }
    for (i = 0; i < 8; i++) {
        func_021249a8(i, 3, s->mUnk_08, s->mUnk_0c);
    }
    for (j = 0, t = data_02164470[0]; j < 7; j++) {
        x = t[3];
        y = t[0];
        z = data_02164470[j + 7][0];
        g = s->mUnk_18;
        func_02025c1c(x, (u8 *) g + (x << 6), s->mUnk_0c);
        func_02025bf0(y, (u8 *) g + (y << 6) + (m << 6), s->mUnk_14);
        func_02025bf0(z, (u8 *) g + (z << 6) + (m << 6), s->mUnk_14);
        t += 4;
    }
    func_02025c1c(7, (u8 *) s->mUnk_18 + 0x1c0, s->mUnk_0c);
    w[0] = 0;
    w[1] = m;
    w[2] = m + 7;
    func_0202e530(data_02174e68->mHeap, 3, w, 7, 8, 0x7c, s->mUnk_18, s->mUnk_10, data_02174e68->mUnk_20 + 0xc, 0, 1, 2,
                  10, func_02035c50);
    func_02025b84(0, &data_02174e68->mUnk_64);
    PrintSelectedGhostRecord();
    func_02025f80(&data_02174e68->mUnk_90, 0, 10, -0xc0, 0);
    RequestSelectReturnState1();
    SetSelectReturnSoundId(0xf);
    func_02035c14();
    FrmHeapShrinkInParent(data_02174e68->mHeap);
}

s32 func_0203551c(u16 *a) {
    Unk02174e68 *p;
    enum { K0 = -1 } r;
    s32 z;
    BOOL f;
    BOOL g;
    s32 i;
    u16 k;
    u16 w;
    void *e;
    Unk02174e14_00 *t;
    void *h;

    r = K0;
    k = func_020435bc();
    z = 0;
    func_02025edc(&data_02174e68->mUnk_90);
    f = FALSE;
    g = FALSE;
    w = data_02175674[k].mUnk_00;
    if (w == 0 && data_02175680[k].mUnk_00 < 5) {
        g = TRUE;
    }
    if (g == FALSE && data_0217567c[k].mUnk_00 == 0 && w != 0) {
        f = TRUE;
    }
    if (f != FALSE) {
        z = IsSelectReturnState2NoState3Or4RequestAndInRect(data_02175670[k].mUnk_00, data_02175672[k].mUnk_00);
    }
    p = data_02174e68;
    switch (p->mState) {
        case 0:
            if (p->mUnk_90.mUnk_00 == 1) {
                p->mState = 1;
            } else {
                func_02035b0c();
            }
            break;
        case 1:
            if (IsTxtSystemState0NoOpenRequest() != 0) {
                func_02035c14();
            }
            func_0202e4b0();
            i = GetScrollListSelectedRow();
            if (data_02174e68->mSelectedIndex != i) {
                data_02174e68->mSelectedIndex = i;
                PrintSelectedGhostRecord();
            }
            if (IsScrollListPickStarted() != 0) {
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 5);
            }
            if (IsScrollListPickFinished() != 0) {
                SetupGhostNameSubTextTwoButtons();
                RequestSelectReturnState4();
                data_02174e68->mState = 2;
            } else if ((u16) (data_02175628[k].mUnk_00 & PAD_KEY_B) != 0 || z != 0) {
                e = GetBmgEntry(data_02174e68->mGhostMessages, 0x54);
                h = GetBmgEntry(data_02174e68->mCommonMessages, 4);
                SetTxtSystemSoundId(0, 5);
                SetupTxtSystemSubTextButton(e, h);
                RequestSelectReturnState3WithSound(1);
                data_02174e68->mUnk_a0 = FALSE;
                data_02174e68->mState = 4;
            }
            break;
        case 2:
            if (GetTxtSystemInputAccepted() != 0 && GetTxtSystemSelectedIndex() == 0) {
                NNS_SndArcSetCurrent(&data_0217c868);
                NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 10);
                NNS_SndArcSetCurrent(&data_0217d0a0);
            }
            if (GetTxtSystemDone() != 0) {
                if (GetTxtSystemSelectedIndex() == 0) {
                    ((Unk0202ddd8 *) func_0202ddd8())->mUnk_08_0 = 1;
                    func_020566a8((u8) data_02174e68->mSelectedIndex, func_0202ddd8());
                    data_02174e68->mState = 3;
                } else {
                    RequestSelectReturnState1();
                    data_02174e68->mState = 1;
                }
                RequestTxtSystemClose();
            }
            break;
        case 3:
            if (func_0203551c_inline_2() != 0) {
                e = GetBmgEntry(p->mGhostMessages, 0x10);
                h = GetBmgEntry(data_02174e68->mCommonMessages, 4);
                SetTxtSystemSoundId(0, 5);
                SetupTxtSystemSubTextButton(e, h);
                data_02174e68->mUnk_a0 = FALSE;
                data_02174e68->mState = 4;
            }
            break;
        case 4:
            if (GetTxtSystemDone() != 0) {
                data_0217b488->mUnk_08 = 5;
                if (a != NULL) {
                    a[2] = 1;
                }
                data_02174e68->mState = 5;
            }
            break;
    }
    for (i = 0; i < 2; i++) {
        t = data_02174e68->mUnk_2c;
        DrawLayoutTable(t[i].mUnk_0c, t[i].mUnk_08, t[i].mUnk_14, data_02174e68->mUnk_24[i], t[i].mUnk_18);
    }
    return r;
}

#pragma thumb off

#pragma thumb on

void func_020354fc(void) {
    HeapDestroy(data_02174e68->mHeap);
    *(int *) &data_02174e68 = 0;
}

#pragma thumb off

#pragma thumb on

void func_020353f8(void) {
    s32 r;
    s32 n;

    r = func_02025ebc(&data_02174e68->mUnk_90);
    reg_G2_BG0OFS = (r << 16) & 0x1ff0000;
    n = -r;
    reg_G2S_DB_BG3OFS = (n << 16) & 0x1ff0000;
    if (r != 0) {
        reg_GX_DISPCNT = (reg_GX_DISPCNT & 0xffff1fff) | 0x2000;
        reg_G2_WININ = (u32) ((reg_G2_WININ & ~0x3f) | 0x1f) | 0x20;
        reg_G2_WINOUT = (u32) ((reg_G2_WINOUT & ~0x3f) | 0xe) | 0x20;
        reg_G2_WIN0H = 0xff;
        reg_G2_WIN0V = ((n << 8) & 0xff00) | 0xc0;
        reg_GXS_DB_DISPCNT = (reg_GXS_DB_DISPCNT & 0xffff1fff) | 0x2000;
        reg_G2S_DB_WININ = (u32) ((reg_G2S_DB_WININ & ~0x3f) | 0x1f) | 0x20;
        reg_G2S_DB_WINOUT = (u32) ((reg_G2S_DB_WINOUT & ~0x3f) | 7) | 0x20;
        reg_G2S_DB_WIN0H = 0xff;
        reg_G2S_DB_WIN0V = (r + 0xc0) & 0xff;
    } else {
        reg_GX_DISPCNT = reg_GX_DISPCNT & 0xffff1fff;
        reg_GXS_DB_DISPCNT = reg_GXS_DB_DISPCNT & 0xffff1fff;
    }
}

void func_020353a4(void) {
    void *e;
    void *f;

    e = GetBmgEntry(data_02174e64->mGhostMessages, 0x11);
    f = GetBmgEntry(data_02174e64->mCommonMessages, 4);
    SetTxtSystemSoundId(0, 5);
    SetupTxtSystemSubTextButton(e, f);
    data_02174e64->mUnk_090 = 0;
    data_02174e64->mState = 15;
}

#pragma thumb off

#pragma thumb on

void func_02035378(void) {
    void *v1;
    v1 = GetBmgEntry(data_02174e64->mGhostMessages, 1);
    func_0212658c(v1, 0, 0, 0, 0, 0, 0);
}

#pragma thumb off

#pragma thumb on

// Selects the previous filled entry whose counter has run up to its end; a nonzero argument wraps from the first entry
// to the last.
void MoveSelectedGhostUp(s32 a) {
    BOOL f;
    s32 c;
    s32 i;
    Unk02174e64 *p;

    f = FALSE;
    p = data_02174e64;
    c = p->mUnk_080;
    i = c - 1;
    if (i < 0) {
        if (a == 0) {
            return;
        }
        i = 3;
    }
    if (i != c) {
        do {
            if (p->mUnk_09c[i].mUnk_28 == TRUE && p->mUnk_09c[i].mUnk_2c.mUnk_00 == 1) {
                f = TRUE;
                p->mUnk_080 = i;
                break;
            }
            i--;
            if (i < 0) {
                if (a == 0) {
                    return;
                }
                i = 3;
            }
        } while (i != p->mUnk_080);
    }
    if (f != FALSE) {
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
    }
}

// Selects the next filled entry whose counter has run up to its end; a nonzero argument wraps from the last entry to
// the first.
void MoveSelectedGhostDown(s32 a) {
    BOOL f;
    s32 c;
    s32 i;
    Unk02174e64 *p;

    f = FALSE;
    p = data_02174e64;
    c = p->mUnk_080;
    i = c + 1;
    if (i >= 4) {
        if (a == 0) {
            return;
        }
        i = 0;
    }
    if (i != c) {
        do {
            if (p->mUnk_09c[i].mUnk_28 == TRUE && p->mUnk_09c[i].mUnk_2c.mUnk_00 == 1) {
                f = TRUE;
                p->mUnk_080 = i;
                break;
            }
            i++;
            if (i >= 4) {
                if (a == 0) {
                    return;
                }
                i = 0;
            }
        } while (i != p->mUnk_080);
    }
    if (f != FALSE) {
        NNS_SndArcPlayerStartSeqArc(&data_0217d068, 0, 0);
    }
}

void func_02035228(s32 a) {
    Unk02174e14_00 *q;
    s32 m;
    s32 w;
    s32 v;

    q = &data_02174e64->mUnk_02c[1];
    m = data_02174e64->mUnk_080;
    w = m + 4;
    if (a != 0) {
        v = 0xe;
    } else {
        v = 0xf;
    }
    q->mUnk_18[4].mUnk_00 = a;
    func_02124100(w, v, q->mUnk_14, q->mUnk_18, q->mUnk_0c);
    func_02124100(m, v, q->mUnk_14, q->mUnk_18, q->mUnk_0c);
}

#pragma thumb off

#pragma thumb on

void SetupGhostSubTextTwoButtons(void) {
    void *v1;
    void *v2;
    void *v3;
    v1 = GetBmgEntry(data_02174e64->mGhostMessages, 8);
    v2 = GetBmgEntry(data_02174e64->mCommonMessages, 0);
    v3 = GetBmgEntry(data_02174e64->mCommonMessages, 1);
    SetTxtSystemSoundId(0, 5);
    SetupTxtSystemSubTextTwoButtonsEx(v1, v2, v3, 0, 0, 1, 1, 0);
}

#pragma thumb off
