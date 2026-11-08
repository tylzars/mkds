#include "03/code_021d1fd0.h"
#include "03/code_021d1cd4.h"
#include "Main/Unknown/code_02023000.h"
#include "03/code_021d3000.h"

#include "03/unk_021da000.h"
#include "03/code_021d1790.h"
#include "03/code_021d1970.h"
#include "Main/Unknown/code_02022000.h"
#include "code_02022aa8.h"
#include "g2d_CharCanvas.h"
#include "03/code_021d27d8.h"
#include "03/code_021d3488.h"
#include "03/unk_021d67d8.h"
#include "code_0200eddc.h"
#include "code_0214a054.h"
#include "code_0214a314.h"
#include "code_0214a2f4.h"
#include "code_0214b824.h"
#include "code_0214cfe4.h"
#include "03/code_021d1000.h"
#include "03/code_021d1d4c.h"
#include "03/code_021d1440.h"
#include "03/unk_021d5000.h"
#include "03/code_021bf4dc.h"
#include "03/code_021d1d60.h"
#include "03/unk_021d7000.h"
#include "registers.h"

void func_ov003_021d2490(void) {
    Unk021d1fd0 *a = func_ov003_021d285c(0x798, 4);
    u32 *b;
    s32 i;

    data_ov003_021da2c4 = a;
    data_ov003_021da2c4->mUnk_788 = func_ov003_021d1d60(0x20, a->mUnk_018, 0x38);
    b = NULL;
    for (i = 0; i < 2; i++) {
        data_ov003_021da2c4->mUnk_78c[i] = func_ov003_021d14b8(data_ov003_021d7c0c[i], b, 4);
        NNS_G2dFontInitUTF16(&data_ov003_021da2c4->mUnk_000[i], data_ov003_021da2c4->mUnk_78c[i]);
    }
}

void func_ov003_021d244c(void) {
    int i;
    for (i = 0; i < 2; i++) {
        func_ov003_021d1490(data_ov003_021da2c4->mUnk_78c[i]);
    }
    func_ov003_021d1d4c(data_ov003_021da2c4->mUnk_788);
    func_ov003_021d2808(&data_ov003_021da2c4);
}

Unk021d23b0 *func_ov003_021d23b0(u32 a, u16 b, u16 c, s32 d, u32 *e, s32 f) {
    Unk021d23b0 *g = func_ov003_021d1cd4(data_ov003_021da2c4->mUnk_788);
    u32 h;
    u32 i;
    Unk02022aa8 *j;

    g->mUnk_36 = b;
    g->mUnk_37 = c;
    g->mUnk_30 = func_ov003_021d309c(a, b * c, d, &h);
    g->mUnk_34 = h;
    *e = NNSi_G2dCalcRequiredOBJ(b, c);
    if (a == 1) {
        i = 0x6600000;
    } else {
        i = 0x6400000;
    }
    i += h << 7;
    NNS_G2dCharCanvasInitForOBJ1D(g, (void *) i, b, c, 4);
    g->mUnk_18(g, 0);
    j = &data_ov003_021da2c4->mUnk_000[f];
    g->mUnk_20 = g;
    g->mUnk_24 = j;
    g->mUnk_28 = 1;
    g->mUnk_2c = 1;
    return g;
}

void func_ov003_021d2388(void *a) {
    func_ov003_021d305c(*OFFSET_PTR(u32, a, 0x30));
    func_ov003_021d1d0c(data_ov003_021da2c4->mUnk_788, a);
}

Unk021d2188 *func_ov003_021d2288(u32 g, u32 h) {
    Unk021d2188 *a = &data_ov003_021da2c4->mUnk_718[g];
    u32 b = data_ov003_021d67e2[g * 2];
    u32 c = data_ov003_021d67e0[g * 2];
    vu16 *d;
    u32 e;
    u8 *f;

    a->mUnk_30 = func_ov003_021d285c((c * b) << 5, 0x20);
    if (g == 1) {
        d = &reg_G2S_DB_BG0CNT;
        *d &= ~0x40;
        *d = (*d & 0x43) | 0xc00;
    } else {
        d = &reg_G2_BG0CNT;
        *d &= ~0x40;
        *d = (*d & 0x43) | 0xc00;
    }
    NNS_G2dCharCanvasInitForBG(a, a->mUnk_30, c, b, 4);
    f = (u8 *) data_ov003_021da2c4->mUnk_000 + h * 12;
    a->mUnk_20.mCharCanvas = a;
    a->mUnk_20.mFont = f;
    a->mUnk_20.mCharSpacing = 1;
    a->mUnk_20.mLineSpacing = 1;
    if (g == 1) {
        e = G2S_GetBG0ScrPtr();
    } else {
        e = G2_GetBG0ScrPtr();
    }
    NNS_G2dMapScrToCharText((u16 *) e, c, b, 0, 0, 0x20, data_ov003_021d67dc[g], 0xf);
    func_ov003_021d2060(a, 0);
    a->mUnk_34 = func_ov003_021d3544(1, func_ov003_021d21f8, &data_ov003_021da2c4->mUnk_794[g], 200);
    return a;
}

void func_ov003_021d21f8(u32 c, u8 *d) {
    Unk021d1fd0 *a;
    u32 b;

    if (*d != 0) {
        a = data_ov003_021da2c4;
        if (d == &a->mUnk_794[0]) {
            b = (data_ov003_021d67e0[0] * data_ov003_021d67e0[1]) << 5;
            DC_FlushRange(a->mUnk_718[0].mUnk_30, b);
            GX_LoadBG0Char(data_ov003_021da2c4->mUnk_718[0].mUnk_30, data_ov003_021d67dc[0] << 5, b);
        } else {
            b = (data_ov003_021d67e0[2] * data_ov003_021d67e0[3]) << 5;
            DC_FlushRange(a->mUnk_718[1].mUnk_30, b);
            GXS_LoadBG0Char(data_ov003_021da2c4->mUnk_718[1].mUnk_30, data_ov003_021d67dc[1] << 5, b);
        }
        *d = 0;
    }
}

void func_ov003_021d2188(Unk021d2188 *d) {
    // placeholders: the values are sent through the stack
    volatile u16 a;
    volatile u16 b;
    void *c;

    func_ov003_021d34c0(1, d->mUnk_34);
    if (d == data_ov003_021da2c4->mUnk_718) {
        c = (void *) G2_GetBG0CharPtr();
        a = 0;
        MIi_CpuClear16(a, c, (data_ov003_021d67e0[0] * data_ov003_021d67e0[1]) << 5);
    } else {
        c = (void *) G2_GetBG0CharPtr();
        b = 0;
        MIi_CpuClear16(b, c, (data_ov003_021d67e0[2] * data_ov003_021d67e0[3]) << 5);
    }
    func_ov003_021d2808(&d->mUnk_30);
}

void func_ov003_021d2168(u32 index) {
    func_ov003_021d2188(&data_ov003_021da2c4->mUnk_718[index]);
}

void func_ov003_021d214c(u32 p0, u32 p1, u32 p2, u32 p3, u32 p4, u32 p5) {
    u32 v2 = p4;
    u32 v4 = p5;
    u32 v6 = ((p0) + (0x20u));
    u32 v7 = NNSi_G2dTextCanvasDrawText((TextCanvas *) v6, p1, p2, p3, v2, (void *) v4);
}

void func_ov003_021d211c(void *a, u32 b, u32 c, u32 d, u16 e, int f) {
    NNS_G2dCharCanvasDrawChar(a, data_ov003_021da2c4->mUnk_000 + f, b, c, d, e);
}

void func_ov003_021d2094(void *e, s32 f, u32 g, u32 h, s32 l, u16 *m, s32 n) {
    Unk02022aa8 *a;
    u32 b;
    NNSG2dCharWidths *c;
    s32 d;

    while (*m != 0) {
        a = data_ov003_021da2c4->mUnk_000 + n;
        b = NNS_G2dFontFindGlyphIndex(a, *m);
        if (b == 0xffff) {
            b = a->mUnk_00->mUnk_02;
        }
        c = NNS_G2dFontGetCharWidthsFromIndex(a, b);
        if (a->mUnk_08 != 0) {
            d = c->mLeft + c->mGlyphWidth;
        } else {
            d = c->mCharWidth;
        }
        func_ov003_021d211c(e, f + ((l - d) >> 1), g, h, *m, n);
        f += l;
        m++;
    }
}

void func_ov003_021d2070(Unk021d2188 *a, s32 b, s32 c, s32 d, s32 e, u32 f, u32 g, void *h) {
    NNSi_G2dTextCanvasDrawTextRect(&a->mUnk_20, b, c, d, e, f, g, h);
}

void func_ov003_021d2060(Unk021d2188 *object, u32 value) {
    object->mUnk_00.mUnk_18(&object->mUnk_00, value);
}

void func_ov003_021d1ffc(Unk021d1ffc *b, s32 c, s32 d, Unk021d1770 *e, s32 f) {
    void *a = func_ov003_021d1974(e, 0);

    func_ov003_021d18f0(e, -1, 0, 0);
    func_ov003_021d1890(e, -1, 0, 0xf);
    func_ov003_021d1790(e, -1, f);
    NNS_G2dArrangeOBJ1D(a, b->mUnk_36, b->mUnk_37, c, d, 0, b->mUnk_34, 2);
}

void func_ov003_021d1fd0(void *object) {
    Unk021d1fd0 *state = data_ov003_021da2c4;
    if (object == state->mUnk_718) {
        state->mUnk_794[0] = 1;
    } else {
        state->mUnk_794[1] = 1;
    }
}
