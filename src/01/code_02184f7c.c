#include "01/code_02184f7c.h"
#include "Main/Unknown/code_020d2000.h"
#include "Main/Unknown/code_020b502c.h"
#include "Main/Unknown/code_020364e0.h"
#include "Main/Unknown/code_02036bec.h"
#include "Main/Unknown/code_020472a8.h"
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

Unk021ca41c_085c *func_ov001_021852f8(const char *param_1, void *param_2, void *param_3) {
    s16 *box;
    Unk021a5a58 *entry;
    s32 i;
    Unk021ca41c_085c *list;
    Unk021852f8 *data;
    Unk021852f8_02 *rec;
    Unk021a5a58_2c_2c *cell;

    list = func_02036bec((void *) func_020364e0(func_020364e8()), (u32) (0x18));
    data = func_0204799c((const char *) (param_1));
    list->mUnk_00 = data->mUnk_00;
    list->mUnk_04 = func_02036bec((void *) func_020364e0(func_020364e8()), (u32) (list->mUnk_00 * 0x88));
    list->mUnk_08 = param_2;
    list->mUnk_0c = param_3;
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
        func_02022904((Unk02022030 *) &entry->mUnk_2c, func_02021db0(param_3, rec[i].mUnk_00), param_2);
        if (rec[i].mUnk_06 > 1) {
            entry->mUnk_2c.mUnk_08 = 1;
        } else {
            entry->mUnk_2c.mUnk_08 = 0;
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

void func_ov001_0218516c(Unk021ca41c_085c *param_1, Unk0218516c *param_2) {
    s32 i;
    Unk021a5a58 *entry;
    Unk021a5a58_2c *sub;
    s32 x;
    s32 y;
    s32 pos_a[2];
    s32 pos_b[2];
    Unk021a5a58_2c_2c *cell;

    for (i = 0; i < param_1->mUnk_00; i++) {
        entry = &param_1->mUnk_04[i];
        sub = &entry->mUnk_2c;
        if (entry->mUnk_84 != 0) {
            if (entry->mUnk_84(entry) != 0) {
                entry->mUnk_84 = 0;
            }
        }
        if (entry->mUnk_0c != 0 && entry->mUnk_18 > 0) {
            x = (entry->mUnk_04 >> 12) + param_1->mUnk_10;
            y = (entry->mUnk_08 >> 12) + param_1->mUnk_14;
            if (x >= -64 && x <= 0x140 && y >= -48 && y <= 0xf0) {
                if (entry->mUnk_18 != 0x1000) {
                    u16 idx = func_020ae5c4(param_2);
                    s32 mtx[4] = {0, 0, 0, 0};

                    mtx[0] = func_02147f34(0x1000, entry->mUnk_18);
                    mtx[3] = func_02147f34(0x1000, entry->mUnk_18);
                    ((Unk0218516c_000 *) param_2->mUnk_000)[idx].mUnk_06 = mtx[0] >> 4;
                    ((Unk0218516c_000 *) param_2->mUnk_000)[idx].mUnk_0e = mtx[1] >> 4;
                    ((Unk0218516c_000 *) param_2->mUnk_000)[idx].mUnk_16 = mtx[2] >> 4;
                    ((Unk0218516c_000 *) param_2->mUnk_000)[idx].mUnk_1e = mtx[3] >> 4;
                    mtx[0] = entry->mUnk_18;
                    mtx[3] = entry->mUnk_18;
                    cell = entry->mUnk_2c.mUnk_2c;
                    pos_a[0] = x << 12;
                    pos_a[1] = y << 12;
                    param_2->mUnk_400 +=
                        func_020224e0((Unk020224e0_o *) &param_2->mUnk_000[param_2->mUnk_400 * 8],
                                      0x80 - param_2->mUnk_400, (Unk020224e0_c *) cell, mtx, pos_a, idx, 1);
                } else {
                    cell = entry->mUnk_2c.mUnk_2c;
                    pos_b[0] = x << 12;
                    pos_b[1] = y << 12;
                    param_2->mUnk_400 +=
                        func_020224e0((Unk020224e0_o *) &param_2->mUnk_000[param_2->mUnk_400 * 8],
                                      0x80 - param_2->mUnk_400, (Unk020224e0_c *) cell, 0, pos_b, 0, 0);
                }
            }
        }
        if (sub->mUnk_08 != 0) {
            func_02022890((Unk02022030 *) &entry->mUnk_2c, 0x1000);
            func_020228c0((Unk02022030 *) &entry->mUnk_2c, 0x1000);
        }
    }
}

Unk021a5a58 *func_ov001_02185160(Unk021ca41c_085c *param_1, s32 param_2) {
    return &param_1->mUnk_04[param_2];
}

s32 func_ov001_021850b4(Unk021ca41c_085c *param_1, s32 param_2, s32 param_3, s32 param_4) {
    s32 fx;
    s32 fy;
    u16 count;
    Unk021a5a58 *entry;

    fx = (s32) (param_3 > 0 ? 0.5f + (float) (param_3 << 12) : (float) (param_3 << 12) - 0.5f);
    fy = (s32) (param_4 > 0 ? 0.5f + (float) (param_4 << 12) : (float) (param_4 << 12) - 0.5f);
    count = param_1->mUnk_00;
    for (; param_2 < count; param_2++) {
        entry = &param_1->mUnk_04[param_2];
        if (fx > entry->mUnk_04 + entry->mUnk_1c && fx < entry->mUnk_04 + entry->mUnk_20 &&
            fy > entry->mUnk_08 + entry->mUnk_24 && fy < entry->mUnk_08 + entry->mUnk_28) {
            return param_2;
        }
    }
    return -1;
}

void func_ov001_021850a4(Unk021a5a58 *param_1, s32 (*param_2)(Unk021a5a58 *)) {
    param_1->mUnk_84 = param_2;
    param_1->mUnk_10 = 0;
    param_1->mUnk_14 = 0;
}

void func_ov001_02185018(Unk021a5a58 *param_1, s32 param_2) {
    Unk021a5a58_2c *sub = &param_1->mUnk_2c;

    if (param_2 == -1) {
        sub->mUnk_14 = 2;
        param_1->mUnk_2c.mUnk_08 = 1;
    } else if (param_2 == -2) {
        func_02022040((Unk02022030 *) sub);
        sub->mUnk_14 = 1;
        param_1->mUnk_2c.mUnk_08 = 1;
    } else if (param_2 == -3) {
        param_1->mUnk_2c.mUnk_08 = 0;
    } else if (param_2 == -4) {
        param_1->mUnk_0c = 1;
    } else if (param_2 == -5) {
        param_1->mUnk_0c = 0;
    } else if (param_2 >= 0) {
        param_1->mUnk_0c = 1;
        func_02022898((Unk02022030 *) sub, param_2);
    }
}

s32 func_ov001_02184ff8(Unk021a5a58 *param_1) {
    if (param_1->mUnk_0c != 0) {
        return func_020220f0((u32) (&param_1->mUnk_2c));
    }
    return -5;
}

void func_ov001_02184fd8(Unk021a5a58 *param_1, s32 param_2, s32 param_3) {
    param_1->mUnk_04 = (param_2 - param_1->mUnk_80->mUnk_10) << 12;
    param_1->mUnk_08 = (param_3 - param_1->mUnk_80->mUnk_14) << 12;
}

s32 func_ov001_02184fc8(Unk021a5a58 *param_1) {
    return (param_1->mUnk_04 >> 12) + param_1->mUnk_80->mUnk_10;
}

s32 func_ov001_02184fb8(Unk021a5a58 *param_1) {
    return (param_1->mUnk_08 >> 12) + param_1->mUnk_80->mUnk_14;
}

void func_ov001_02184fb4(Unk021a5a58 *param_1, s32 param_2) {
    param_1->mUnk_18 = param_2;
}

s32 func_ov001_02184fb0(Unk021a5a58 *param_1) {
    return param_1->mUnk_18;
}

void func_ov001_02184f9c(Unk021a5a58 *param_1, s32 param_2, s32 param_3, s32 param_4, s32 param_5) {
    param_1->mUnk_1c = param_2 << 12;
    param_1->mUnk_24 = param_3 << 12;
    param_1->mUnk_20 = param_4 << 12;
    param_1->mUnk_28 = param_5 << 12;
}

void func_ov001_02184f8c(Unk02188950 *param_1) {
    func_020d2774(&param_1->mUnk_000, (u32) (0x210));
}

void func_ov001_02184f7c(Unk02188950 *param_1) {
    func_020d2774(&param_1->mUnk_000, (u32) (0x210));
}
