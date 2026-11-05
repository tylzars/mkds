#include "01/code_02184f7c.h"
#include "Main/Unknown/code_02036820.h"
#include "Main/Unknown/code_020ade08.h"
#include "Main/Unknown/code_020d2000.h"
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
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_02047104.h"
#include "code_02012b30.h"
#include "code_02021db0.h"
#include "Main/Unknown/code_02021000.h"
#include "code_02022030.h"
#include "code_020222ec.h"
#include "Main/Unknown/code_0209b000.h"
#include "Main/Unknown/code_020ae000.h"
#include "Main/Unknown/code_020e6000.h"
#include "code_020220f0.h"
#include "code_02147cd8.h"

Unk021ca41c_085c *func_ov001_021852f8(const char *a, void *b, void *c) {
    s16 *box;
    Unk021a5a58 *entry;
    s32 i;
    Unk021ca41c_085c *list;
    Unk021852f8 *data;
    Unk021852f8_02 *rec;
    Unk021a5a58_2c_2c *cell;

    list = HeapAlloc(GetHeap(func_020364e8()), (u32) (0x18));
    data = FindSceneFile((a));
    list->mUnk_00 = data->mUnk_00;
    list->mUnk_04 = HeapAlloc(GetHeap(func_020364e8()), (u32) (list->mUnk_00 * 0x88));
    list->mUnk_08 = b;
    list->mUnk_0c = c;
    rec = data->mUnk_02;
    for (i = 0; i < list->mUnk_00; i++) {
        entry = &list->mUnk_04[i];
        entry->mUnk_80 = list;
        entry->mUnk_00 = rec[i].mUnk_00;
        entry->mUnk_04 =
            (s32) (rec[i].mUnk_02 > 0 ? 0.5f + (float) (rec[i].mUnk_02 << 12) : (float) (rec[i].mUnk_02 << 12) - 0.5f);
        entry->mUnk_08 =
            (s32) (rec[i].mUnk_04 > 0 ? 0.5f + (float) (rec[i].mUnk_04 << 12) : (float) (rec[i].mUnk_04 << 12) - 0.5f);
        entry->mUnk_18 = 0x1000;
        entry->mUnk_0c = rec[i].mUnk_06 != 0;
        func_02022904((Unk02022030 *) &entry->mUnk_2c, func_02021db0(c, rec[i].mUnk_00), b);
        if (rec[i].mUnk_06 > 1) {
            entry->mUnk_2c.mUnk_08 = TRUE;
        } else {
            entry->mUnk_2c.mUnk_08 = FALSE;
        }
        cell = entry->mUnk_2c.mUnk_2c;
        if ((cell->mUnk_02 >> 11) & 1) {
            box = cell->mUnk_08;
            entry->mUnk_1c = box[2] << 12;
            entry->mUnk_24 = box[3] << 12;
            entry->mUnk_20 = box[0] << 12;
            entry->mUnk_28 = box[1] << 12;
        }
    }
    return list;
}

void func_ov001_0218516c(Unk021ca41c_085c *a, Unk0218516c *b) {
    s32 i;
    Unk021a5a58 *entry;
    Unk021a5a58_2c *sub;
    s32 x;
    s32 y;
    s32 pos_a[2];
    s32 pos_b[2];
    Unk021a5a58_2c_2c *cell;

    for (i = 0; i < a->mUnk_00; i++) {
        entry = &a->mUnk_04[i];
        sub = &entry->mUnk_2c;
        if (entry->mUnk_84 != NULL) {
            if (entry->mUnk_84(entry) != 0) {
                entry->mUnk_84 = NULL;
            }
        }
        if (entry->mUnk_0c != FALSE && entry->mUnk_18 > 0) {
            x = (entry->mUnk_04 >> 12) + a->mUnk_10;
            y = (entry->mUnk_08 >> 12) + a->mUnk_14;
            if (x >= -64 && x <= 0x140 && y >= -48 && y <= 0xf0) {
                if (entry->mUnk_18 != 0x1000) {
                    u16 idx = func_020ae5c4(b);
                    s32 mtx[4] = {0, 0, 0, 0};

                    mtx[0] = DivFixed12(0x1000, entry->mUnk_18);
                    mtx[3] = DivFixed12(0x1000, entry->mUnk_18);
                    ((Unk0218516c_000 *) b->mUnk_000)[idx].mUnk_06 = mtx[0] >> 4;
                    ((Unk0218516c_000 *) b->mUnk_000)[idx].mUnk_0e = mtx[1] >> 4;
                    ((Unk0218516c_000 *) b->mUnk_000)[idx].mUnk_16 = mtx[2] >> 4;
                    ((Unk0218516c_000 *) b->mUnk_000)[idx].mUnk_1e = mtx[3] >> 4;
                    mtx[0] = entry->mUnk_18;
                    mtx[3] = entry->mUnk_18;
                    cell = entry->mUnk_2c.mUnk_2c;
                    pos_a[0] = x << 12;
                    pos_a[1] = y << 12;
                    b->mUnk_400 += func_020224e0((Unk020224e0_o *) &b->mUnk_000[b->mUnk_400 * 8], 0x80 - b->mUnk_400,
                                                 (Unk020224e0_c *) cell, mtx, pos_a, idx, 1);
                } else {
                    cell = entry->mUnk_2c.mUnk_2c;
                    pos_b[0] = x << 12;
                    pos_b[1] = y << 12;
                    b->mUnk_400 += func_020224e0((Unk020224e0_o *) &b->mUnk_000[b->mUnk_400 * 8], 0x80 - b->mUnk_400,
                                                 (Unk020224e0_c *) cell, NULL, pos_b, 0, 0);
                }
            }
        }
        if (sub->mUnk_08 != FALSE) {
            func_02022890((Unk02022030 *) &entry->mUnk_2c, 0x1000);
            func_020228c0((Unk02022030 *) &entry->mUnk_2c, 0x1000);
        }
    }
}

Unk021a5a58 *func_ov001_02185160(Unk021ca41c_085c *a, s32 b) {
    return &a->mUnk_04[b];
}

s32 func_ov001_021850b4(Unk021ca41c_085c *a, s32 b, s32 c, s32 d) {
    s32 fx;
    s32 fy;
    u16 count;
    Unk021a5a58 *entry;

    fx = (s32) (c > 0 ? 0.5f + (float) (c << 12) : (float) (c << 12) - 0.5f);
    fy = (s32) (d > 0 ? 0.5f + (float) (d << 12) : (float) (d << 12) - 0.5f);
    count = a->mUnk_00;
    for (; b < count; b++) {
        entry = &a->mUnk_04[b];
        if (fx > entry->mUnk_04 + entry->mUnk_1c && fx < entry->mUnk_04 + entry->mUnk_20 &&
            fy > entry->mUnk_08 + entry->mUnk_24 && fy < entry->mUnk_08 + entry->mUnk_28) {
            return b;
        }
    }
    return -1;
}

void func_ov001_021850a4(Unk021a5a58 *a, s32 (*b)(Unk021a5a58 *)) {
    a->mUnk_84 = b;
    a->mUnk_10 = 0;
    a->mUnk_14 = 0;
}

void func_ov001_02185018(Unk021a5a58 *a, s32 b) {
    Unk021a5a58_2c *sub = &a->mUnk_2c;

    if (b == -1) {
        sub->mUnk_14 = 2;
        a->mUnk_2c.mUnk_08 = TRUE;
    } else if (b == -2) {
        func_02022040((Unk02022030 *) sub);
        sub->mUnk_14 = 1;
        a->mUnk_2c.mUnk_08 = TRUE;
    } else if (b == -3) {
        a->mUnk_2c.mUnk_08 = FALSE;
    } else if (b == -4) {
        a->mUnk_0c = TRUE;
    } else if (b == -5) {
        a->mUnk_0c = FALSE;
    } else if (b >= 0) {
        a->mUnk_0c = TRUE;
        func_02022898((Unk02022030 *) sub, b);
    }
}

s32 func_ov001_02184ff8(Unk021a5a58 *a) {
    if (a->mUnk_0c != FALSE) {
        return func_020220f0((u32) (&a->mUnk_2c));
    }
    return -5;
}

void func_ov001_02184fd8(Unk021a5a58 *a, s32 b, s32 c) {
    a->mUnk_04 = (b - a->mUnk_80->mUnk_10) << 12;
    a->mUnk_08 = (c - a->mUnk_80->mUnk_14) << 12;
}

s32 func_ov001_02184fc8(Unk021a5a58 *a) {
    return (a->mUnk_04 >> 12) + a->mUnk_80->mUnk_10;
}

s32 func_ov001_02184fb8(Unk021a5a58 *a) {
    return (a->mUnk_08 >> 12) + a->mUnk_80->mUnk_14;
}

void func_ov001_02184fb4(Unk021a5a58 *a, s32 b) {
    a->mUnk_18 = b;
}

s32 func_ov001_02184fb0(Unk021a5a58 *a) {
    return a->mUnk_18;
}

void func_ov001_02184f9c(Unk021a5a58 *a, s32 b, s32 c, s32 d, s32 e) {
    a->mUnk_1c = b << 12;
    a->mUnk_24 = c << 12;
    a->mUnk_20 = d << 12;
    a->mUnk_28 = e << 12;
}

void func_ov001_02184f8c(Unk02188950 *a) {
    func_020d2774(&a->mUnk_000, (u32) (0x210));
}

void func_ov001_02184f7c(Unk02188950 *a) {
    func_020d2774(&a->mUnk_000, (u32) (0x210));
}
