#include "Main/Unknown/code_020f7c90.h"

#include "Main/Unknown/unk_02159000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217b000.h"
#include "Main/Unknown/unk_0215d000.h"
#include "Main/Unknown/code_020f36d8.h"
#include "Main/Unknown/unk_021759c0.h"
#include "Main/Unknown/code_0206bcb0.h"
#include "Main/Unknown/code_02039860.h"
#include "Main/Unknown/code_02047000.h"
#include "Main/Unknown/unk_02164000.h"
#include "Main/Unknown/code_020472a8.h"
#include "Main/Unknown/code_020f813c.h"
#include "Main/Unknown/code_020f8148.h"
#include "Main/Unknown/code_020f6be8.h"

#pragma thumb on

void func_020f80c0(Unk0217bc6c *param_1, s32 param_2) {
    u16(*tab)[0x12];
    s32 i;
    s32 j;
    u16 v;
    u16 *e;

    e = (u16 *) &data_02159c3c[param_2 - 1];
    tab = param_1->mUnk_04;
    if (param_2 == 8) {
        return;
    }
    for (i = 0; i < param_2; i++) {
        v = (u16) (e[i] - 1);
        for (j = 0; j < 0x12; j++) {
            tab[i][j] = tab[v][j];
        }
    }
    for (; i < 8; i++) {
        for (j = 0; j < 0x12; j++) {
            tab[i][j] = 0;
        }
    }
}

void func_020f7ec8(void) {
    u8 *p;
    enum { K0 } i;
    s32 j;
    s32 n;
    s32 *q;
    enum { K1 } k;

    p = (u8 *) func_02047b08((const char *) data_0216c680);
    switch (data_021759c0->mUnk_08) {
        case 0:
        case 1:
        case 4:
            p = func_020f8148(&data_0217bc6c, p + 1);
            p = func_020f8148(&data_0217bc64, p);
            p = (u8 *) func_020f813c((u32) p);
            p = (u8 *) func_020f813c((u32) p);
            p = (u8 *) func_020f813c((u32) p);
            p = (u8 *) func_020f813c((u32) p);
            p = func_020f8148(&data_0217bc74, p);
            break;
        case 2:
            p = (u8 *) func_020f813c((u32) (p + 1));
            p = (u8 *) func_020f813c((u32) p);
            p = (u8 *) func_020f813c((u32) p);
            p = (u8 *) func_020f813c((u32) p);
            p = (u8 *) func_020f813c((u32) p);
            p = (u8 *) func_020f813c((u32) p);
            p = func_020f8148(&data_0217bc74, p);
            switch (data_021759c0->mUnk_18) {
                case 0:
                default:
                    p = func_020f8148(&data_0217bc6c, p);
                    p = func_020f8148(&data_0217bc64, p);
                    break;
                case 1:
                    p = (u8 *) func_020f813c((u32) p);
                    p = (u8 *) func_020f813c((u32) p);
                    p = func_020f8148(&data_0217bc6c, p);
                    p = func_020f8148(&data_0217bc64, p);
                    break;
            }
            break;
        case 3:
            p = (u8 *) func_020f813c((u32) (p + 1));
            p = (u8 *) func_020f813c((u32) p);
            p = func_020f8148(&data_0217bc6c, p);
            p = func_020f8148(&data_0217bc64, p);
            p = (u8 *) func_020f813c((u32) p);
            p = (u8 *) func_020f813c((u32) p);
            p = func_020f8148(&data_0217bc74, p);
            if (data_021759c0->mUnk_014 == 0) {
                func_020f80c0(&data_0217bc6c, data_021759c0->mUnk_3d0);
                func_020f80c0(&data_0217bc64, data_021759c0->mUnk_3d0);
            }
            break;
        case 5:
            p = (u8 *) func_020f813c((u32) (p + 1));
            p = (u8 *) func_020f813c((u32) p);
            p = (u8 *) func_020f813c((u32) p);
            p = (u8 *) func_020f813c((u32) p);
            p = func_020f8148(&data_0217bc6c, p);
            p = func_020f8148(&data_0217bc64, p);
            p = func_020f8148(&data_0217bc74, p);
            if (data_021759c0->mUnk_014 == 0) {
                func_020f80c0(&data_0217bc6c, data_021759c0->mUnk_3d0);
                func_020f80c0(&data_0217bc64, data_021759c0->mUnk_3d0);
            }
            break;
    }
    n = data_0217bc6c.mUnk_00;
    for (i = 0; i < 0x12; i++) {
        data_0217bce8[i] = 0x12;
        for (j = 0; j < n; j++) {
            if (data_0217bc6c.mUnk_04[j][i] != 0 || data_0217bc64.mUnk_04[j][i] != 0) {
                data_0217bce8[i] = i;
            }
        }
    }
    data_0217bc54 = 0;
    for (k = 0; k < 0x12; k++) {
        q = &data_0217bce8[k];
        if (data_0217bce8[k] != 0x12) {
            data_0217bce8[data_0217bc54++] = *q;
        }
    }
    data_0217bc50 = 0;
}

#pragma thumb off

u8 func_020f7ea8(void *param_1, void *param_2) {
    Unk020f41c4_A *p = param_1;
    Unk020f41c4_A *q = param_2;

    return (data_02159b78 + p->mUnk_44 * 0xe)[q->mUnk_44];
}

void func_020f7c90(Unk020f41c4_A *param_1, Vec3 *param_2, Vec3 *param_3) {
    Unk020f41c4_B *q;
    s64 d;
    s32 i;

    if (param_1->mUnk_74 & 0x2000000) {
        if ((s64) param_3->x * param_3->x + (s64) param_3->y * param_3->y + (s64) param_3->z * param_3->z >= 0x10) {
            func_02039860(param_3, param_3);
        }
        if (func_02039828(param_3, &param_1->mUnk_108) > 0x800) {
            param_1->mUnk_5c.z = (s32) (((s64) param_3->z * 0x14cd) >> 12);
            param_1->mUnk_5c.x = (s32) (((s64) param_3->x * 0x14cd) >> 12);
        }
    }
    d = (s64) (param_1->mUnk_50.x - param_2->x) * (param_1->mUnk_50.x - param_2->x) +
        (s64) (param_1->mUnk_50.y - param_2->y) * (param_1->mUnk_50.y - param_2->y) +
        (s64) (param_1->mUnk_50.z - param_2->z) * (param_1->mUnk_50.z - param_2->z);
    if (d >= (s64) param_1->mUnk_e0 * param_1->mUnk_e0) {
        return;
    }
    param_1->mUnk_74 |= 0x4000000;
    if (param_1->mUnk_74 & 0x2000000) {
        return;
    }
    if (func_02039828(&param_1->mUnk_5c, param_3) >= 0) {
        return;
    }
    q = &data_0217561c->mUnk_47c;
    q->mUnk_00 = q->mUnk_08 * q->mUnk_00 + q->mUnk_10;
    i = (u16) ((((u64) (u32) (q->mUnk_00 >> 32) * 0x10000) >> 32)) >> 4;
    param_1->mUnk_108.z = data_0215d4b4[i * 2 + 1];
    param_1->mUnk_108.x = data_0215d4b4[i * 2];
    param_1->mUnk_5c.z = (s32) (((s64) param_1->mUnk_108.z * 0x14cd) >> 12);
    param_1->mUnk_5c.x = (s32) (((s64) param_1->mUnk_108.x * 0x14cd) >> 12);
    param_1->mUnk_74 |= 0x2000000;
}
