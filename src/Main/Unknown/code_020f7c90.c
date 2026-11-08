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

void func_020f80c0(ItemSlotTable *table, s32 kartCount) {
    u16(*tab)[0x12];
    s32 i;
    s32 j;
    u16 sourceRow;
    u16 *sourceRows;

    sourceRows = (u16 *) &gItemSlotRowRemaps[kartCount - 1];
    tab = table->mRows;
    if (kartCount == 8) {
        return;
    }
    for (i = 0; i < kartCount; i++) {
        sourceRow = sourceRows[i] - 1;
        for (j = 0; j < 0x12; j++) {
            tab[i][j] = tab[sourceRow][j];
        }
    }
    for (; i < 8; i++) {
        for (j = 0; j < 0x12; j++) {
            tab[i][j] = 0;
        }
    }
}

void CreateItemSlotTables(void) {
    u8 *data;
    enum { K0 } i;
    s32 j;
    s32 rowCount;
    s32 *entry;
    enum { K1 } k;

    data = FindMainRaceOrMainEffectFile(data_0216c680);
    switch (gRaceSetup->mMode) {
        case MODE_GRAND_PRIX:
        case MODE_TIME_ATTACK:
        case MODE_MISSION_RUN:
            data = LoadItemSlotTableData(&data_0217bc6c, data + 1);
            data = LoadItemSlotTableData(&data_0217bc64, data);
            data = ComputeItemSlotTableDataEnd(data);
            data = ComputeItemSlotTableDataEnd(data);
            data = ComputeItemSlotTableDataEnd(data);
            data = ComputeItemSlotTableDataEnd(data);
            data = LoadItemSlotTableData(&data_0217bc74, data);
            break;
        case MODE_BATTLE:
            data = ComputeItemSlotTableDataEnd(data + 1);
            data = ComputeItemSlotTableDataEnd(data);
            data = ComputeItemSlotTableDataEnd(data);
            data = ComputeItemSlotTableDataEnd(data);
            data = ComputeItemSlotTableDataEnd(data);
            data = ComputeItemSlotTableDataEnd(data);
            data = LoadItemSlotTableData(&data_0217bc74, data);
            switch (gRaceSetup->mBattleKind) {
                case BATTLE_KIND_BALLOON:
                default:
                    data = LoadItemSlotTableData(&data_0217bc6c, data);
                    data = LoadItemSlotTableData(&data_0217bc64, data);
                    break;
                case BATTLE_KIND_SHINE:
                    data = ComputeItemSlotTableDataEnd(data);
                    data = ComputeItemSlotTableDataEnd(data);
                    data = LoadItemSlotTableData(&data_0217bc6c, data);
                    data = LoadItemSlotTableData(&data_0217bc64, data);
                    break;
            }
            break;
        case MODE_VS:
            data = ComputeItemSlotTableDataEnd(data + 1);
            data = ComputeItemSlotTableDataEnd(data);
            data = LoadItemSlotTableData(&data_0217bc6c, data);
            data = LoadItemSlotTableData(&data_0217bc64, data);
            data = ComputeItemSlotTableDataEnd(data);
            data = ComputeItemSlotTableDataEnd(data);
            data = LoadItemSlotTableData(&data_0217bc74, data);
            if (gRaceSetup->mCpuDifficulty == 0) {
                func_020f80c0(&data_0217bc6c, gRaceSetup->mKartCount);
                func_020f80c0(&data_0217bc64, gRaceSetup->mKartCount);
            }
            break;
        case 5:
            data = ComputeItemSlotTableDataEnd(data + 1);
            data = ComputeItemSlotTableDataEnd(data);
            data = ComputeItemSlotTableDataEnd(data);
            data = ComputeItemSlotTableDataEnd(data);
            data = LoadItemSlotTableData(&data_0217bc6c, data);
            data = LoadItemSlotTableData(&data_0217bc64, data);
            data = LoadItemSlotTableData(&data_0217bc74, data);
            if (gRaceSetup->mCpuDifficulty == 0) {
                func_020f80c0(&data_0217bc6c, gRaceSetup->mKartCount);
                func_020f80c0(&data_0217bc64, gRaceSetup->mKartCount);
            }
            break;
    }
    rowCount = data_0217bc6c.mRowCount;
    for (i = 0; i < 0x12; i++) {
        gItemSlotPossibleItems[i] = 0x12;
        for (j = 0; j < rowCount; j++) {
            if (data_0217bc6c.mRows[j][i] != 0 || data_0217bc64.mRows[j][i] != 0) {
                gItemSlotPossibleItems[i] = i;
            }
        }
    }
    gItemSlotPossibleItemCount = 0;
    for (k = 0; k < 0x12; k++) {
        entry = &gItemSlotPossibleItems[k];
        if (gItemSlotPossibleItems[k] != 0x12) {
            gItemSlotPossibleItems[gItemSlotPossibleItemCount++] = *entry;
        }
    }
    gItemSlotSpinItemCount = 0;
}

#pragma thumb off

u8 GetItemObjectHitType(ItemObject *itemParam, ItemObject *otherParam) {
    ItemObject *item = itemParam;
    ItemObject *other = otherParam;

    return (gItemHitTypes + item->mKind * 0xe)[other->mKind];
}

void func_020f7c90(ItemObject *item, Vec3 *otherPos, Vec3 *normal) {
    RandomState64 *random;
    s64 distanceSquared;
    s32 angleIndex;

    if (item->mFlags & 0x2000000) {
        if ((s64) normal->x * normal->x + (s64) normal->y * normal->y + (s64) normal->z * normal->z >= 0x10) {
            Vec3NormalizeAndGetLengthUnchecked(normal, normal);
        }
        if (Vec3DotUnrounded(normal, &item->mUnk_108) > 0x800) {
            item->mVelocity.z = ((s64) normal->z * 0x14cd) >> 12;
            item->mVelocity.x = ((s64) normal->x * 0x14cd) >> 12;
        }
    }
    distanceSquared = (s64) (item->mPos.x - otherPos->x) * (item->mPos.x - otherPos->x) +
                      (s64) (item->mPos.y - otherPos->y) * (item->mPos.y - otherPos->y) +
                      (s64) (item->mPos.z - otherPos->z) * (item->mPos.z - otherPos->z);
    if (distanceSquared >= (s64) item->mRadius * item->mRadius) {
        return;
    }
    item->mFlags |= 0x4000000;
    if (item->mFlags & 0x2000000) {
        return;
    }
    if (Vec3DotUnrounded(&item->mVelocity, normal) >= 0) {
        return;
    }
    random = &gRaceProgress->mRandom;
    random->mValue = random->mMultiplier * random->mValue + random->mIncrement;
    angleIndex = (u16) ((((u64) (u32) (random->mValue >> 32) * 0x10000) >> 32)) >> 4;
    item->mUnk_108.z = gPairsByAngle[angleIndex * 2 + 1];
    item->mUnk_108.x = gPairsByAngle[angleIndex * 2];
    item->mVelocity.z = ((s64) item->mUnk_108.z * 0x14cd) >> 12;
    item->mVelocity.x = ((s64) item->mUnk_108.x * 0x14cd) >> 12;
    item->mFlags |= 0x2000000;
}
