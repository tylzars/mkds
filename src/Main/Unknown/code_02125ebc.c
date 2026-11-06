#include "Main/Unknown/code_02125ebc.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_02124f4c.h"

#include "Main/Unknown/code_02125ed0.h"
#include "Main/Unknown/code_02125ee8.h"
#include "Main/Unknown/code_02125f2c.h"
#include "Main/Unknown/code_02125f54.h"
#include "Main/Unknown/code_02125f6c.h"
#include "Main/Unknown/code_02125000.h"
#include "Main/Unknown/code_02126700.h"
#include "Main/Unknown/code_021274ec.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/unk_0217d000.h"
#include "Main/Unknown/code_02126230.h"
#include "Main/Unknown/code_02126248.h"
#include "Main/Unknown/code_021262f0.h"
#include "Main/Unknown/code_0212630c.h"
#include "Main/Unknown/code_02126570.h"
#include "Main/Unknown/code_0212658c.h"
#include "Main/Unknown/code_021266e4.h"
#include "Main/Unknown/code_02126ea8.h"
#include "Main/Unknown/code_020ae4c0.h"
#include "Main/Unknown/code_021059e0.h"
#include "Main/Unknown/unk_0217d068.h"
#include "Main/Unknown/unk_02175628.h"
#include "Main/Unknown/code_020b1dbc.h"
#include "Main/Unknown/code_0207b960.h"
#include "Main/Unknown/code_020b4e5c.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02147000.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_020b47d8.h"
#include "Main/Unknown/code_020b6a18.h"
#include "Main/Unknown/code_0207a880.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_02126f78.h"
#include "code_0200eddc.h"
#include "code_02016468.h"
#include "code_02023374.h"
#include "code_0214a390.h"
#include "code_0212df7c.h"
#include "Main/Unknown/unk_0216e000.h"
#include "Main/Unknown/code_020b4000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_0214d000.h"
#include "code_0214a2f4.h"
#include "code_0214b824.h"
#include "code_0214cfe4.h"
#include "code_0214a054.h"
#include "Main/Unknown/code_021274e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02023000.h"
#include "Main/Unknown/code_02047104.h"
#include "code_0214d018.h"

#pragma thumb on

void func_02127734(void) {
    s32 i;

    for (i = 0; i < 7; i++) {
        gTxtSystem->mUnk_2204[i] = 0;
    }
}

static inline void func_021274ec_inline(Unk0217d3f0_2178 *e, Unk0217d3f0_2098 *o, u32 v) {
    e->mUnk_00 = o;
    e->mUnk_04 = v;
    e->mUnk_08 = 1;
    e->mUnk_0c = 1;
}

s32 InitTxtSystem(void *b, Unk021274ec *c) {
    s32 a;
    s32 i;
    Unk0217d3f0_2098 *o;

    a = c->mUnk_10;
    gTxtSystem = HeapAlloc(b, 0x2278);
    if (c->mUnk_04 != 0) {
        gTxtSystem->mUnk_44 = 1;
    }
    if (c->mUnk_08 != 0) {
        gTxtSystem->mUnk_48 = 1;
    }
    if (c->mUnk_0c != 0) {
        gTxtSystem->mUnk_4c = 1;
    }
    gTxtSystem->mUnk_50 = 1;
    func_0212745c();
    a = func_0212717c(a);
    for (i = 0; i < 7; i++) {
        if (!((i == 1 && gTxtSystem->mUnk_44 == 0) || (i == 2 && gTxtSystem->mUnk_48 == 0) ||
              (i == 3 && gTxtSystem->mUnk_4c == 0))) {
            gTxtSystem->mUnk_21e8[i] = HeapAlloc(b, (data_0215d044[i][0] * data_0215d044[i][1]) << 5);
            func_02023408(&gTxtSystem->mUnk_2098[i], gTxtSystem->mUnk_21e8[i], data_0215d044[i][0], data_0215d044[i][1],
                          4);
            o = &gTxtSystem->mUnk_2098[i];
            o->mUnk_18(o, 0);
            func_021274ec_inline(&gTxtSystem->mUnk_2178[i], &gTxtSystem->mUnk_2098[i], c->mUnk_00);
        }
    }
    func_02127734();
    gTxtSystem->mUnk_00 = 0;
    gTxtSystem->mUnk_04 = 0;
    gTxtSystem->mUnk_08 = 0;
    gTxtSystem->mUnk_0c = 0;
    gTxtSystem->mUnk_10 = 0;
    gTxtSystem->mUnk_14 = 0;
    gTxtSystem->mUnk_18[0] = 0;
    gTxtSystem->mUnk_18[1] = 0;
    gTxtSystem->mUnk_20[0] = 0;
    gTxtSystem->mUnk_20[1] = 0;
    gTxtSystem->mUnk_206c[0] = 0;
    gTxtSystem->mUnk_206c[1] = 0;
    gTxtSystem->mUnk_2074[0] = 0;
    gTxtSystem->mUnk_2074[1] = 0;
    gTxtSystem->mUnk_34 = 0;
    gTxtSystem->mUnk_38 = 0;
    gTxtSystem->mUnk_30 = 0;
    gTxtSystem->mUnk_224c = 0;
    gTxtSystem->mUnk_2250 = 5;
    gTxtSystem->mUnk_2254 = 0x10;
    gTxtSystem->mUnk_2258 = 0x23;
    for (i = 0; i < 2; i++) {
        gTxtSystem->mUnk_2054[i] = -192;
        gTxtSystem->mUnk_205c[i] = 0;
        gTxtSystem->mUnk_2064[i] = 0;
    }
    gTxtSystem->mUnk_2080[0] = 0x19;
    gTxtSystem->mUnk_2080[1] = 0x1a;
    gTxtSystem->mUnk_207c = 0;
    for (i = 0; i < 2; i++) {
        gTxtSystem->mUnk_2088[i] = 6;
        gTxtSystem->mUnk_2090[i] = 10;
    }
    gTxtSystem->mUnk_2248 = 0;
    return a;
}
#pragma thumb off

#pragma thumb on
void func_021274e0(void) {
    u32 value0;
    u32 value1;
    value1 = 0u;
    value0 = (u32) &gTxtSystem;
    *(u32 *) ((value0) + 0u) = value1;
}
#pragma thumb off

#pragma thumb on

void func_0212745c(void) {
    u32 a;
    u32 b;

    a = (*(vu32 *) 0x4000000 & 0x1f00) >> 8;
    *(vu32 *) 0x4000000 = (*(vu32 *) 0x4000000 & 0xffffe0ff) | ((a | 4) << 8);
    *(vu16 *) 0x400000c &= ~3;
    *(vu16 *) 0x400000c = (*(vu16 *) 0x400000c & 0x43) | 0x9e10;
    b = (*(vu32 *) 0x4001000 & 0x1f00) >> 8;
    *(vu32 *) 0x4001000 = (*(vu32 *) 0x4001000 & 0xffffe0ff) | ((b | 1) << 8);
    *(vu16 *) 0x4001008 &= ~3;
    *(vu16 *) 0x4001008 = (*(vu16 *) 0x4001008 & 0x43) | 0x8b00;
}

static inline void func_0212717c_inline(void *dst, u16 value) {
    vu16 v = value;

    MIi_CpuClear16(v, dst, 0x1000);
}

s32 func_0212717c(s32 d) {
    Ncgr *a;
    Ncgr *b;
    Nclr *c;

    if (*(vu16 *) 0x27ffc40 == 2) {
        LocateNcgr(&a, FindSceneFile(data_0216e708));
        LocateNscr(&gTxtSystem->mBgNscrs[0], FindSceneFile(data_0216e720));
        LocateNclr(&c, FindSceneFile(data_0216e738));
    } else {
        LocateNcgr(&a, func_02047a28(data_0216e750));
        LocateNcgr(&b, func_02047a28(data_0216e768));
        LocateNscr(&gTxtSystem->mBgNscrs[0], func_02047a28(data_0216e780));
        LocateNscr(&gTxtSystem->mBgNscrs[1], func_02047a28(data_0216e798));
        LocateNscr(&gTxtSystem->mBgNscrs[2], func_02047a28(data_0216e7b0));
        LocateNscr(&gTxtSystem->mBgNscrs[3], func_02047a28(data_0216e7c8));
        LocateNscr(&gTxtSystem->mBgNscrs[4], func_02047a28(data_0216e7e0));
        LocateNscr(&gTxtSystem->mBgNscrs[5], func_02047a28(data_0216e7f8));
        LocateNscr(&gTxtSystem->mBgNscrs[6], func_02047a28(data_0216e810));
        LocateNclr(&c, func_02047a28(data_0216e828));
    }
    gTxtSystem->mUnk_2220[0] = 0;
    DC_FlushRange(a->mData, a->mDataSize);
    GX_LoadBG2Char(a->mData, 0, a->mDataSize);
    if (gTxtSystem->mUnk_48 != 0) {
        d = d - a->mDataSize;
        gTxtSystem->mUnk_2220[2] = d >> 5;
        DC_FlushRange(a->mData, a->mDataSize);
        GXS_LoadBG0Char(a->mData, d, a->mDataSize);
    }
    if (*(vu16 *) 0x27ffc40 != 2) {
        if (gTxtSystem->mUnk_44 != 0) {
            gTxtSystem->mUnk_2220[1] = 0;
        }
        gTxtSystem->mUnk_223c[0] = a->mDataSize >> 5;
        DC_FlushRange(b->mData, b->mDataSize);
        GX_LoadBG2Char(b->mData, gTxtSystem->mUnk_223c[0] << 5, b->mDataSize);
        if (gTxtSystem->mUnk_4c != 0) {
            gTxtSystem->mUnk_2220[3] = gTxtSystem->mUnk_2220[2];
        }
        d = d - b->mDataSize;
        gTxtSystem->mUnk_2220[4] = d >> 5;
        gTxtSystem->mUnk_2220[5] = d >> 5;
        gTxtSystem->mUnk_2220[6] = d >> 5;
        gTxtSystem->mUnk_223c[1] = d >> 5;
        DC_FlushRange(b->mData, b->mDataSize);
        GXS_LoadBG0Char(b->mData, d, b->mDataSize);
    }
    DC_FlushRange(c->mData, 0x1c0);
    GX_LoadBGPltt(c->mData + 0xe0, 0x1c0, 0x40);
    GXS_LoadBGPltt(c->mData + 0xe0, 0x1c0, 0x40);
    gTxtSystem->mUnk_2244 = c->mData[0xee];
    gTxtSystem->mUnk_2246 = c->mData[0xdf];
    MemFillWordsByBlock_inline((void *) G2_GetBG2ScrPtr(), 0x1000);
    func_0212717c_inline((void *) G2S_GetBG0ScrPtr(), gTxtSystem->mUnk_2220[4]);
    return d;
}

void func_021270bc(void) {
    s32 r;
    s32 i;
    s32 c;
    s32 n;
    u16 *d;

    n = gTxtSystem->mUnk_14 + 4;
    for (i = 0; i < 2; i++) {
        if (gTxtSystem->mUnk_18[i] != 0) {
            d = gTxtSystem->mUnk_54;
            if (i == 1) {
                d = gTxtSystem->mUnk_1054;
            }
            for (r = data_0215d080[n].mUnk_02; r <= data_0215d080[n].mUnk_03; r++) {
                for (c = data_0215d080[n].mUnk_00; c <= data_0215d080[n].mUnk_01; c++) {
                    *(d + r * 32 + c) =
                        gTxtSystem->mUnk_223c[i] + *((u16 *) gTxtSystem->mBgNscrs[n]->mData + r * 32 + c);
                }
            }
        }
    }
}

void func_02126f78(u32 *b) {
    u8 a[9] = {0, 1, 0, 1, 2, 3, 0, 0, 0};
    s32 i;
    s32 r;
    s32 c;
    s32 k;
    u16 *d;

    MemFillWordsByBlock_inline(gTxtSystem->mUnk_54, 0x1000);
    func_0212717c_inline(&gTxtSystem->mUnk_1054, gTxtSystem->mUnk_2220[4]);
    for (i = 0; i < 9; i++) {
        if (*b != 0) {
            if ((u32) (i - 7) <= 1) {
                func_021270bc();
            } else if (i != 6) {
                k = a[i];
                d = gTxtSystem->mUnk_1054;
                if ((u32) i <= 1) {
                    d = gTxtSystem->mUnk_54;
                }
                for (r = data_0215d080[k].mUnk_02; r <= data_0215d080[k].mUnk_03; r++) {
                    for (c = data_0215d080[k].mUnk_00; c <= data_0215d080[k].mUnk_01; c++) {
                        *(d + r * 32 + c) =
                            gTxtSystem->mUnk_2220[i] + *((u16 *) gTxtSystem->mBgNscrs[k]->mData + r * 32 + c);
                    }
                }
            }
        }
        b++;
    }
}
#pragma thumb off

#pragma thumb on

void func_02126ef8(void) {
    TxtSystem *v1;
    v1 = gTxtSystem;
    if (0 < v1->mUnk_28) {
        CallQueueAppend(0x1f, ((0xee - v1->mUnk_2c) * 2), &v1->mUnk_2246, 2);
        CallQueueAppend((u32) 0x1f, (u32) ((0xfe - gTxtSystem->mUnk_2c) * 2), &gTxtSystem->mUnk_2246, (u32) 2);
        v1 = gTxtSystem;
        if (v1->mUnk_28 == 2) {
            CallQueueAppend(0x1f, ((v1->mUnk_2c + 0xed) * 2), &v1->mUnk_2244, 2);
            CallQueueAppend((u32) 0x1f, (u32) ((gTxtSystem->mUnk_2c + 0xfd) * 2), &gTxtSystem->mUnk_2244, (u32) 2);
        }
    }
}

void func_02126ea8(void) {
    int v2;
    if (0 < gTxtSystem->mUnk_28) {
        v2 = 0;
        do {
            CallQueueAppend(0x1f, ((v2 + 0xed) * 2), &gTxtSystem->mUnk_2244, 2);
            CallQueueAppend(0x1f, ((v2 + 0xfd) * 2), &gTxtSystem->mUnk_2244, 2);
            v2 = v2 + 1;
        } while (v2 < 2);
    }
}

#pragma thumb off

#pragma thumb on

void func_02126d28(void) {
    u32 a[9];
    s32 i;
    s32 n;
    s32 m;

    if (gTxtSystem->mUnk_34 != 0) {
        for (i = 0; i < 9; i++) {
            if (i <= 6) {
                if (gTxtSystem->mUnk_2204[i] != 0) {
                    a[i] = 1;
                } else {
                    a[i] = 0;
                }
            } else {
                if ((&gTxtSystem->mUnk_04)[i] != 0) {
                    (&gTxtSystem->mUnk_04)[i] = 0;
                    *(&gTxtSystem->mUnk_00 + i - 1) = 1;
                    a[i] = 1;
                } else {
                    a[i] = 0;
                }
            }
        }
        func_02126f78(a);
        CallQueueAppend(10, 0, gTxtSystem->mUnk_54, 0x1000);
        CallQueueAppend(0x18, 0, &gTxtSystem->mUnk_1054, 0x1000);
        gTxtSystem->mUnk_04 = 1;
        gTxtSystem->mUnk_0c = 0;
        for (i = 0; i < 2; i++) {
            gTxtSystem->mUnk_205c[i] = gTxtSystem->mUnk_2064[i];
        }
        for (i = 0; i < 2; i++) {
            gTxtSystem->mUnk_206c[i] = gTxtSystem->mUnk_2074[i];
        }
        for (i = 0; i < 7; i++) {
            if (gTxtSystem->mUnk_2204[i] != 0) {
                n = (data_0215d044[i][0] * data_0215d044[i][1]) << 5;
                m = 0x14;
                if ((u32) i <= 1) {
                    m = 6;
                }
                CallQueueAppend(m, (gTxtSystem->mUnk_2220[i] + data_0215d054[i]) << 5, gTxtSystem->mUnk_21e8[i], n);
            }
        }
        if (gTxtSystem->mUnk_28 > 0) {
            func_02126ef8();
        }
        if (gTxtSystem->mUnk_18[0] == 0 && gTxtSystem->mUnk_18[1] == 0) {
            if (gTxtSystem->mUnk_2258 != -1) {
                func_0212ecc0(&data_0217d068, 0, (u16) gTxtSystem->mUnk_2258);
            }
        }
    }
}

void func_02126c90(void) {
    TxtSystem *p;
    s32 i;

    gTxtSystem->mUnk_0c++;
    for (i = 0; i < 2; i++) {
        gTxtSystem->mUnk_2054[i] = func_020ae4c0(1, data_0215d040[gTxtSystem->mUnk_3c], (s16) -gTxtSystem->mUnk_205c[i],
                                                 gTxtSystem->mUnk_0c, 0xf);
    }
    p = gTxtSystem;
    p->mUnk_207c = (p->mUnk_0c * -10) / 15;
    if (gTxtSystem->mUnk_0c >= 15) {
        if (gTxtSystem->mUnk_38 == 0) {
            gTxtSystem->mUnk_34 = 0;
        }
        gTxtSystem->mUnk_04 = 2;
        gTxtSystem->mUnk_0c = 0;
    }
}

static inline BOOL func_02126a00_inline(u16 a, u16 b, u8 c, u8 d, u8 e, u8 f) {
    if (a >= c && a <= d && b >= e && b <= f) {
        return TRUE;
    }
    return FALSE;
}

static inline s32 func_02126a00_inline2(u32 v) {
    BOOL r = FALSE;
    BOOL s = FALSE;

    if (data_02175674[v].mUnk_00 == 0 && data_02175680[v].mUnk_00 < 5) {
        s = TRUE;
    }
    if (s == FALSE && data_0217567c[v].mUnk_00 == 0 && data_02175674[v].mUnk_00 != 0) {
        r = TRUE;
    }
    return r;
}

void func_02126a00(void) {
    s32 m;
    s32 t;
    u16 y;
    s32 hit;
    u16 x;
    TxtSystem *p;
    u32 v;
    u16 w;

    switch (gTxtSystem->mUnk_2248) {
        case 0:
            v = 8;
            break;
        case 1:
            v = func_020435bc();
            break;
    }
    x = data_02175670[v].mUnk_00;
    p = gTxtSystem;
    t = p->mUnk_2054[1] + data_02175672[v].mUnk_00;
    if (t < 0) {
        t = 0xff;
    }
    if (t > 0xff) {
        t = 0xff;
    }
    y = t;
    if (p->mUnk_38 != 0) {
        p->mUnk_04 = 4;
        return;
    }
    m = p->mUnk_28;
    if (m <= 0) {
        return;
    }
    hit = -1;
    if (m == 2) {
        if (func_02126a00_inline2(v) != 0) {
            if (func_02126a00_inline(x, y, data_0215d064[5].mUnk_00, data_0215d064[5].mUnk_01, data_0215d064[5].mUnk_02,
                                     data_0215d064[5].mUnk_03) != FALSE) {
                hit = 0;
            }
            if (func_02126a00_inline(x, y, data_0215d064[6].mUnk_00, data_0215d064[6].mUnk_01, data_0215d064[6].mUnk_02,
                                     data_0215d064[6].mUnk_03) != FALSE) {
                hit = 1;
            }
        }
    }
    w = data_02175628[v].mUnk_00;
    if ((u16) (w & 1) == 0) {
        if (func_02126a00_inline2(v) == 0 || m != 1 ||
            func_02126a00_inline(x, y, data_0215d064[4].mUnk_00, data_0215d064[4].mUnk_01, data_0215d064[4].mUnk_02,
                                 data_0215d064[4].mUnk_03) == FALSE) {
            if (hit == -1) {
                goto L;
            }
        }
    }
    if (m == 1) {
        func_02126ea8();
    } else {
        if (hit == -1 || p->mUnk_2c == hit) {
            func_02126ea8();
        } else {
            p->mUnk_2c = hit;
            func_02126ef8();
        }
    }
    gTxtSystem->mUnk_04 = 3;
    if (gTxtSystem->mUnk_28 == 2 && gTxtSystem->mUnk_2c == 1) {
        if (gTxtSystem->mUnk_2254 != -1) {
            func_0212ecc0(&data_0217d068, 0, (u16) gTxtSystem->mUnk_2254);
        }
    } else {
        if (gTxtSystem->mUnk_2250 != -1) {
            func_0212ecc0(&data_0217d068, 0, (u16) gTxtSystem->mUnk_2250);
        }
    }
    gTxtSystem->mUnk_224c = 1;
    return;
L:
    if (m == 2) {
        if ((u16) (w & 0x20) != 0 && p->mUnk_2c == 1) {
            p->mUnk_2c = 0;
            func_02126ef8();
            func_02105ac0(0);
            return;
        }
        if ((u16) (w & 0x10) != 0 && p->mUnk_2c == 0) {
            p->mUnk_2c = 1;
            func_02126ef8();
            func_02105ac0(0);
        }
    }
}

void func_021269b8(void) {
    gTxtSystem->mUnk_0c++;
    gTxtSystem->mUnk_224c = 0;
    if (gTxtSystem->mUnk_0c >= 10) {
        gTxtSystem->mUnk_30 = 1;
        gTxtSystem->mUnk_04 = 2;
        gTxtSystem->mUnk_0c = 0;
    } else if (gTxtSystem->mUnk_0c >= 5) {
        func_02126ef8();
    }
}

void func_021268f8(void) {
    TxtSystem *p;
    s32 i;

    gTxtSystem->mUnk_0c++;
    for (i = 0; i < 2; i++) {
        gTxtSystem->mUnk_2054[i] =
            func_020ae4c0(1, -gTxtSystem->mUnk_205c[i], data_0215d040[gTxtSystem->mUnk_40], gTxtSystem->mUnk_0c, 0xf);
    }
    p = gTxtSystem;
    p->mUnk_207c = -10 - (p->mUnk_0c * -10) / 15;
    if (gTxtSystem->mUnk_0c >= 15) {
        for (i = 0; i < 2; i++) {
            gTxtSystem->mUnk_2054[i] = -192;
        }
        gTxtSystem->mUnk_04 = 0;
        func_02126ea8();
        gTxtSystem->mUnk_0c = 0;
        gTxtSystem->mUnk_38 = 0;
        gTxtSystem->mUnk_30 = 0;
        gTxtSystem->mUnk_18[0] = 0;
        gTxtSystem->mUnk_18[1] = 0;
    }
}

void func_02126834(void) {
    if (gTxtSystem->mUnk_50 != 0) {
        gTxtSystem->mUnk_08 = gTxtSystem->mUnk_00;
        gTxtSystem->mUnk_00 = gTxtSystem->mUnk_04;
        switch (gTxtSystem->mUnk_00) {
            case 0:
                func_02126d28();
                break;
            case 1:
                func_02126c90();
                break;
            case 2:
                func_02126a00();
                break;
            case 3:
                func_021269b8();
                break;
            case 4:
                func_021268f8();
                break;
        }
        if (gTxtSystem->mUnk_18[0] != 0 || gTxtSystem->mUnk_18[1] != 0) {
            gTxtSystem->mUnk_10++;
            if (gTxtSystem->mUnk_10 >= 4) {
                gTxtSystem->mUnk_10 = 0;
                gTxtSystem->mUnk_14++;
                if (gTxtSystem->mUnk_14 >= 3) {
                    gTxtSystem->mUnk_14 = 0;
                }
                func_021270bc();
                CallQueueAppend(10, 0, gTxtSystem->mUnk_54, 0x1000);
                CallQueueAppend(0x18, 0, &gTxtSystem->mUnk_1054, 0x1000);
            }
        }
    }
}

void func_02126730(void) {
    if (gTxtSystem->mUnk_50 != 0) {
        *(vu32 *) 0x4000018 = (gTxtSystem->mUnk_2054[0] << 16) & 0x1ff0000;
        *(vu32 *) 0x4001010 = (gTxtSystem->mUnk_2054[1] << 16) & 0x1ff0000;
        if (gTxtSystem->mUnk_206c[0] != 0) {
            G2x_SetBlendBrightnessExt_((u16 *) 0x4000050, gTxtSystem->mUnk_2080[0], 0x1f, gTxtSystem->mUnk_2088[0],
                                       gTxtSystem->mUnk_2090[0], gTxtSystem->mUnk_207c);
        } else {
            G2x_SetBlendBrightnessExt_((u16 *) 0x4000050, 0, 0x1f, gTxtSystem->mUnk_2088[0], gTxtSystem->mUnk_2090[0],
                                       gTxtSystem->mUnk_207c);
        }
        if (gTxtSystem->mUnk_206c[1] != 0) {
            G2x_SetBlendBrightnessExt_((u16 *) 0x4001050, gTxtSystem->mUnk_2080[1], 0x1f, gTxtSystem->mUnk_2088[1],
                                       gTxtSystem->mUnk_2090[1], gTxtSystem->mUnk_207c);
        } else {
            G2x_SetBlendBrightnessExt_((u16 *) 0x4001050, 0, 0x1f, gTxtSystem->mUnk_2088[1], gTxtSystem->mUnk_2090[1],
                                       gTxtSystem->mUnk_207c);
        }
    }
}

void func_02126700(void) {
    if ((gTxtSystem->mUnk_00 == 0 && gTxtSystem->mUnk_34 != 0) || gTxtSystem->mUnk_00 == 1 ||
        gTxtSystem->mUnk_00 == 2) {
        gTxtSystem->mUnk_38 = 1;
    } else {
        gTxtSystem->mUnk_38 = 0;
    }
    gTxtSystem->mUnk_34 = 1;
}
#pragma thumb off

#pragma thumb on

void func_021266e4(void *a) {
    func_02126638(a, 1, 1, 1, 0, 0, 0);
}

#pragma thumb off

#pragma thumb on

void func_02126638(void *a, s32 b, s32 c, s32 d, s32 e, s32 f, s32 g) {
    Unk0217d3f0_2098 *p;

    p = &gTxtSystem->mUnk_2098[0];
    p->mUnk_18(p, 0xf);
    func_0212583c(&gTxtSystem->mUnk_2178[0], 0, 0, data_0215d044[0][0] << 3, data_0215d044[0][1] << 3, 1, 0x480, 1, a);
    func_02127734();
    gTxtSystem->mUnk_2204[0] = 1;
    func_02126700();
    gTxtSystem->mUnk_28 = 0;
    gTxtSystem->mUnk_30 = 0;
    gTxtSystem->mUnk_20[0] = f;
    gTxtSystem->mUnk_20[1] = g;
    gTxtSystem->mUnk_2074[0] = b;
    gTxtSystem->mUnk_2074[1] = c;
    gTxtSystem->mUnk_3c = d;
    gTxtSystem->mUnk_40 = e;
}

void func_0212658c(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    Unk0217d3f0_2098 *p;

    p = &gTxtSystem->mUnk_2098[1];
    p->mUnk_18(p, 0xf);
    func_0212583c(&gTxtSystem->mUnk_2178[1], 0, 0, data_0215d044[1][0] << 3, data_0215d044[1][1] << 3, 1, 0x480, 1, a);
    func_02127734();
    gTxtSystem->mUnk_2204[1] = 1;
    func_02126700();
    gTxtSystem->mUnk_28 = 0;
    gTxtSystem->mUnk_30 = 0;
    gTxtSystem->mUnk_20[0] = f;
    gTxtSystem->mUnk_20[1] = g;
    gTxtSystem->mUnk_2074[0] = b;
    gTxtSystem->mUnk_2074[1] = c;
    gTxtSystem->mUnk_3c = d;
    gTxtSystem->mUnk_40 = e;
}
#pragma thumb off

#pragma thumb on

void func_02126570(void *p0, void *p1) {
    u32 v7 = ((0x1u) + (0x0u));
    func_02126474(p0, p1, (u32) 0x1u, v7, (u32) 0x1u, (u32) 0x0u, (u32) 0x0u);
}

#pragma thumb off

#pragma thumb on

void func_02126474(void *a, void *b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    Unk0217d3f0_2098 *p;

    p = &gTxtSystem->mUnk_2098[0];
    p->mUnk_18(p, 0xf);
    p = &gTxtSystem->mUnk_2098[4];
    p->mUnk_18(p, 0xe);
    func_0212583c(&gTxtSystem->mUnk_2178[0], 0, 0, data_0215d044[0][0] << 3, data_0215d044[0][1] << 3, 1, 0x480, 1, a);
    func_021257d8(&gTxtSystem->mUnk_2178[4], 0, 0, data_0215d044[4][0] << 3, data_0215d044[4][1] << 3, 2, 0x480, 1, b);
    func_02127734();
    gTxtSystem->mUnk_2204[0] = 1;
    gTxtSystem->mUnk_2204[4] = 1;
    func_02126700();
    gTxtSystem->mUnk_28 = 1;
    gTxtSystem->mUnk_2c = 0;
    gTxtSystem->mUnk_30 = 0;
    gTxtSystem->mUnk_20[0] = g;
    gTxtSystem->mUnk_20[1] = 0;
    gTxtSystem->mUnk_2074[0] = c;
    gTxtSystem->mUnk_2074[1] = d;
    gTxtSystem->mUnk_3c = e;
    gTxtSystem->mUnk_40 = f;
}

void func_02126454(void *a, void *b, void *c, s32 d) {
    func_0212630c(a, b, c, d, 1, 1, 1, 0, 0);
}

void func_0212630c(void *a, void *b, void *c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 i) {
    Unk0217d3f0_2098 *p;

    p = &gTxtSystem->mUnk_2098[0];
    p->mUnk_18(p, 0xf);
    p = &gTxtSystem->mUnk_2098[5];
    p->mUnk_18(p, 0xe);
    p = &gTxtSystem->mUnk_2098[6];
    p->mUnk_18(p, 0xd);
    func_0212583c(&gTxtSystem->mUnk_2178[0], 0, 0, data_0215d044[0][0] << 3, data_0215d044[0][1] << 3, 1, 0x480, 1, a);
    func_021257d8(&gTxtSystem->mUnk_2178[5], 0, 0, data_0215d044[5][0] << 3, data_0215d044[5][1] << 3, 2, 0x480, 1, b);
    func_021257d8(&gTxtSystem->mUnk_2178[6], 0, 0, data_0215d044[6][0] << 3, data_0215d044[6][1] << 3, 2, 0x480, 1, c);
    func_02127734();
    gTxtSystem->mUnk_2204[0] = 1;
    gTxtSystem->mUnk_2204[5] = 1;
    gTxtSystem->mUnk_2204[6] = 1;
    func_02126700();
    gTxtSystem->mUnk_28 = 2;
    gTxtSystem->mUnk_2c = d;
    gTxtSystem->mUnk_30 = 0;
    gTxtSystem->mUnk_20[0] = i;
    gTxtSystem->mUnk_20[1] = 0;
    gTxtSystem->mUnk_2074[0] = e;
    gTxtSystem->mUnk_2074[1] = f;
    gTxtSystem->mUnk_3c = g;
    gTxtSystem->mUnk_40 = h;
}

#pragma thumb off

#pragma thumb on

void func_021262f0(void *a) {
    func_02126248(a, (u32) 1, (u32) 1, (u32) 1, (u32) 0, (u32) 0);
}

#pragma thumb off

#pragma thumb on

void func_02126248(void *a, u32 b, u32 c, u32 d, u32 e, u32 f) {
    Unk0217d3f0_2098 *p;

    p = &gTxtSystem->mUnk_2098[2];
    p->mUnk_18(p, 0xf);
    func_0212583c(&gTxtSystem->mUnk_2178[2], 0, 0, data_0215d044[2][0] << 3, data_0215d044[2][1] << 3, 1, 0x480, 1, a);
    func_02127734();
    gTxtSystem->mUnk_2204[2] = 1;
    func_02126700();
    gTxtSystem->mUnk_28 = 0;
    gTxtSystem->mUnk_30 = 0;
    gTxtSystem->mUnk_20[0] = 0;
    gTxtSystem->mUnk_20[1] = f;
    gTxtSystem->mUnk_2074[0] = b;
    gTxtSystem->mUnk_2074[1] = c;
    gTxtSystem->mUnk_3c = d;
    gTxtSystem->mUnk_40 = e;
}

#pragma thumb off

#pragma thumb on

void func_02126230(void *p0, void *p1) {
    u32 v6 = ((0x1u) + (0x0u));
    func_02126138(p0, p1, (u32) 0x1u, v6, (u32) 0x1u, (u32) 0x0u);
}

#pragma thumb off

#pragma thumb on

void func_02126138(void *a, void *b, u32 c, u32 d, u32 e, u32 f) {
    Unk0217d3f0_2098 *p;

    p = &gTxtSystem->mUnk_2098[2];
    p->mUnk_18(p, 0xf);
    p = &gTxtSystem->mUnk_2098[4];
    p->mUnk_18(p, 0xe);
    func_0212583c(&gTxtSystem->mUnk_2178[2], 0, 0, data_0215d044[2][0] << 3, data_0215d044[2][1] << 3, 1, 0x480, 1, a);
    func_021257d8(&gTxtSystem->mUnk_2178[4], 0, 0, data_0215d044[4][0] << 3, data_0215d044[4][1] << 3, 2, 0x480, 1, b);
    func_02127734();
    gTxtSystem->mUnk_2204[2] = 1;
    gTxtSystem->mUnk_2204[4] = 1;
    func_02126700();
    gTxtSystem->mUnk_28 = 1;
    gTxtSystem->mUnk_2c = 0;
    gTxtSystem->mUnk_30 = 0;
    gTxtSystem->mUnk_20[0] = 0;
    gTxtSystem->mUnk_20[1] = 0;
    gTxtSystem->mUnk_2074[0] = c;
    gTxtSystem->mUnk_2074[1] = d;
    gTxtSystem->mUnk_3c = e;
    gTxtSystem->mUnk_40 = f;
}

void func_0212611c(void *a, void *b, void *c, s32 d) {
    func_02125fd4(a, b, c, d, 1, 1, 1, 0);
}

void func_02125fd4(void *a, void *b, void *c, u32 d, u32 e, u32 f, u32 g, u32 h) {
    Unk0217d3f0_2098 *p;

    p = &gTxtSystem->mUnk_2098[2];
    p->mUnk_18(p, 0xf);
    p = &gTxtSystem->mUnk_2098[5];
    p->mUnk_18(p, 0xe);
    p = &gTxtSystem->mUnk_2098[6];
    p->mUnk_18(p, 0xd);
    func_0212583c(&gTxtSystem->mUnk_2178[2], 0, 0, data_0215d044[2][0] << 3, data_0215d044[2][1] << 3, 1, 0x480, 1, a);
    func_021257d8(&gTxtSystem->mUnk_2178[5], 0, 0, data_0215d044[5][0] << 3, data_0215d044[5][1] << 3, 2, 0x480, 1, b);
    func_021257d8(&gTxtSystem->mUnk_2178[6], 0, 0, data_0215d044[6][0] << 3, data_0215d044[6][1] << 3, 2, 0x480, 1, c);
    func_02127734();
    gTxtSystem->mUnk_2204[2] = 1;
    gTxtSystem->mUnk_2204[5] = 1;
    gTxtSystem->mUnk_2204[6] = 1;
    func_02126700();
    gTxtSystem->mUnk_28 = 2;
    gTxtSystem->mUnk_2c = d;
    gTxtSystem->mUnk_30 = 0;
    gTxtSystem->mUnk_20[0] = 0;
    gTxtSystem->mUnk_20[1] = 0;
    gTxtSystem->mUnk_2074[0] = e;
    gTxtSystem->mUnk_2074[1] = f;
    gTxtSystem->mUnk_3c = g;
    gTxtSystem->mUnk_40 = h;
}

void func_02125fc0(void) {
    gTxtSystem->mUnk_34 = 0;
    gTxtSystem->mUnk_38 = 1;
}

s32 func_02125fa4(void) {
    BOOL r;

    r = FALSE;
    if (gTxtSystem->mUnk_00 == 2 && gTxtSystem->mUnk_38 == 0) {
        r = TRUE;
    }
    return r;
}

s32 func_02125f88(void) {
    BOOL r;

    r = FALSE;
    if (gTxtSystem->mUnk_00 == 0 && gTxtSystem->mUnk_34 == 0) {
        r = TRUE;
    }
    return r;
}

s32 func_02125f6c(void) {
    BOOL r;

    r = FALSE;
    if (gTxtSystem->mUnk_08 == 1 && gTxtSystem->mUnk_00 == 2) {
        r = TRUE;
    }
    return r;
}

#pragma thumb off

#pragma thumb on
s32 func_02125f60(void) {
    u32 value0;
    value0 = (u32) gTxtSystem->mUnk_2c;
    return (s32) value0;
}
#pragma thumb off

#pragma thumb on
s32 func_02125f54(void) {
    u32 value0;
    value0 = (u32) gTxtSystem->mUnk_30;
    return (s32) value0;
}
#pragma thumb off

#pragma thumb on

u32 func_02125f40(void) {
    return gTxtSystem->mUnk_224c;
}

void func_02125f2c(u32 p0) {
    gTxtSystem->mUnk_2248 = p0;
}

#pragma thumb off

#pragma thumb on

void func_02125ee8(int a, int b) {
    if (a < -0x96) {
        a = -0x96;
    }
    if (a > 0x96) {
        a = 0x96;
    }
    if (b < -0x96) {
        b = -0x96;
    }
    if (b > 0x96) {
        b = 0x96;
    }
    gTxtSystem->mUnk_2064[0] = a;
    gTxtSystem->mUnk_2064[1] = b;
}

#pragma thumb off

#pragma thumb on
void func_02125ed0(int arg0, u32 arg1) {
    u32 value0 = (u32) arg0;
    u32 value1 = arg1;
    u32 value2;
    value2 = (u32) &gTxtSystem;
    value2 = (u32) * (const u32 *) ((value2) + 0u);
    value0 = (value0 << 2);
    value2 = (value2) + (value0);
    value0 = 0x2250u;
    *(u32 *) ((value2) + (value0)) = value1;
}
#pragma thumb off

#pragma thumb on

void func_02125ebc(u32 p0) {
    gTxtSystem->mUnk_2258 = p0;
}

#pragma thumb off
