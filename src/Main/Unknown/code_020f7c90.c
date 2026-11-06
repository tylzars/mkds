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
#include "Main/Unknown/code_02047104.h"
#include "Main/Unknown/code_020f813c.h"
#include "Main/Unknown/code_020f6be8.h"

#pragma thumb on

void func_020f80c0(ItemSlotTable *a, s32 b) {
    u16(*tab)[0x12];
    s32 i;
    s32 j;
    u16 v;
    u16 *e;

    e = (u16 *) &data_02159c3c[b - 1];
    tab = a->mRows;
    if (b == 8) {
        return;
    }
    for (i = 0; i < b; i++) {
        v = e[i] - 1;
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

void CreateItemSlotTables(void) {
    u8 *p;
    enum { K0 } i;
    s32 j;
    s32 n;
    s32 *q;
    enum { K1 } k;

    p = FindMainRaceOrMainEffectFile(data_0216c680);
    switch (data_021759c0->mMode) {
        case MODE_GRAND_PRIX:
        case MODE_TIME_ATTACK:
        case MODE_MISSION_RUN:
            p = LoadItemSlotTableData(&data_0217bc6c, p + 1);
            p = LoadItemSlotTableData(&data_0217bc64, p);
            p = ComputeItemSlotTableDataEnd(p);
            p = ComputeItemSlotTableDataEnd(p);
            p = ComputeItemSlotTableDataEnd(p);
            p = ComputeItemSlotTableDataEnd(p);
            p = LoadItemSlotTableData(&data_0217bc74, p);
            break;
        case MODE_BATTLE:
            p = ComputeItemSlotTableDataEnd(p + 1);
            p = ComputeItemSlotTableDataEnd(p);
            p = ComputeItemSlotTableDataEnd(p);
            p = ComputeItemSlotTableDataEnd(p);
            p = ComputeItemSlotTableDataEnd(p);
            p = ComputeItemSlotTableDataEnd(p);
            p = LoadItemSlotTableData(&data_0217bc74, p);
            switch (data_021759c0->mUnk_18) {
                case 0:
                default:
                    p = LoadItemSlotTableData(&data_0217bc6c, p);
                    p = LoadItemSlotTableData(&data_0217bc64, p);
                    break;
                case 1:
                    p = ComputeItemSlotTableDataEnd(p);
                    p = ComputeItemSlotTableDataEnd(p);
                    p = LoadItemSlotTableData(&data_0217bc6c, p);
                    p = LoadItemSlotTableData(&data_0217bc64, p);
                    break;
            }
            break;
        case MODE_VS:
            p = ComputeItemSlotTableDataEnd(p + 1);
            p = ComputeItemSlotTableDataEnd(p);
            p = LoadItemSlotTableData(&data_0217bc6c, p);
            p = LoadItemSlotTableData(&data_0217bc64, p);
            p = ComputeItemSlotTableDataEnd(p);
            p = ComputeItemSlotTableDataEnd(p);
            p = LoadItemSlotTableData(&data_0217bc74, p);
            if (data_021759c0->mUnk_014 == 0) {
                func_020f80c0(&data_0217bc6c, data_021759c0->mKartCount);
                func_020f80c0(&data_0217bc64, data_021759c0->mKartCount);
            }
            break;
        case 5:
            p = ComputeItemSlotTableDataEnd(p + 1);
            p = ComputeItemSlotTableDataEnd(p);
            p = ComputeItemSlotTableDataEnd(p);
            p = ComputeItemSlotTableDataEnd(p);
            p = LoadItemSlotTableData(&data_0217bc6c, p);
            p = LoadItemSlotTableData(&data_0217bc64, p);
            p = LoadItemSlotTableData(&data_0217bc74, p);
            if (data_021759c0->mUnk_014 == 0) {
                func_020f80c0(&data_0217bc6c, data_021759c0->mKartCount);
                func_020f80c0(&data_0217bc64, data_021759c0->mKartCount);
            }
            break;
    }
    n = data_0217bc6c.mRowCount;
    for (i = 0; i < 0x12; i++) {
        gItemSlotPossibleItems[i] = 0x12;
        for (j = 0; j < n; j++) {
            if (data_0217bc6c.mRows[j][i] != 0 || data_0217bc64.mRows[j][i] != 0) {
                gItemSlotPossibleItems[i] = i;
            }
        }
    }
    gItemSlotPossibleItemCount = 0;
    for (k = 0; k < 0x12; k++) {
        q = &gItemSlotPossibleItems[k];
        if (gItemSlotPossibleItems[k] != 0x12) {
            gItemSlotPossibleItems[gItemSlotPossibleItemCount++] = *q;
        }
    }
    gItemSlotSpinItemCount = 0;
}

#pragma thumb off

u8 func_020f7ea8(ItemObject *a, ItemObject *b) {
    ItemObject *p = a;
    ItemObject *q = b;

    return (data_02159b78 + p->mKind * 0xe)[q->mKind];
}

void func_020f7c90(ItemObject *a, Vec3 *b, Vec3 *c) {
    Unk020f41c4_B *q;
    s64 d;
    s32 i;

    if (a->mFlags & 0x2000000) {
        if ((s64) c->x * c->x + (s64) c->y * c->y + (s64) c->z * c->z >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(c, c);
        }
        if (Vec3DotUnrounded(c, &a->mUnk_108) > 0x800) {
            a->mVelocity.z = ((s64) c->z * 0x14cd) >> 12;
            a->mVelocity.x = ((s64) c->x * 0x14cd) >> 12;
        }
    }
    d = (s64) (a->mPos.x - b->x) * (a->mPos.x - b->x) + (s64) (a->mPos.y - b->y) * (a->mPos.y - b->y) +
        (s64) (a->mPos.z - b->z) * (a->mPos.z - b->z);
    if (d >= (s64) a->mUnk_e0 * a->mUnk_e0) {
        return;
    }
    a->mFlags |= 0x4000000;
    if (a->mFlags & 0x2000000) {
        return;
    }
    if (Vec3DotUnrounded(&a->mVelocity, c) >= 0) {
        return;
    }
    q = &gRaceProgress->mRandom;
    q->mUnk_00 = q->mUnk_08 * q->mUnk_00 + q->mUnk_10;
    i = (u16) ((((u64) (u32) (q->mUnk_00 >> 32) * 0x10000) >> 32)) >> 4;
    a->mUnk_108.z = gPairsByAngle[i * 2 + 1];
    a->mUnk_108.x = gPairsByAngle[i * 2];
    a->mVelocity.z = ((s64) a->mUnk_108.z * 0x14cd) >> 12;
    a->mVelocity.x = ((s64) a->mUnk_108.x * 0x14cd) >> 12;
    a->mFlags |= 0x2000000;
}
