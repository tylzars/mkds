#include "Main/Unknown/code_0210bafc.h"

#include "Main/Unknown/unk_0215a000.h"
#include "Main/Unknown/unk_0216c000.h"
#include "Main/Unknown/unk_0217c000.h"
#include "Main/Unknown/code_0210bbec.h"
#include "code_0212d214.h"
#include "code_020172d0.h"

u32 TryAppendListObject(void *list, void *object) {
    BOOL willAppend;
    Unk0210bc54 *link;

    link = OFFSET_PTR(Unk0210bc54, object, ((NNSFndList *) list)->mLinkOffset);
    if (link->mUnk_08 != 0) {
        willAppend = FALSE;
    } else {
        willAppend = TRUE;
        link->mUnk_08 = list;
    }
    if (willAppend != FALSE) {
        NNS_FndAppendListObject(list, object);
    } else {
        return 0;
    }
    return 1;
}

void RemoveListObject(NNSFndList *list, void *object) {
    Unk0210bc54 *link;

    NNS_FndRemoveListObject(list, object);
    link = OFFSET_PTR(Unk0210bc54, object, list->mLinkOffset);
    if (link->mUnk_08 != 0) {
        link->mUnk_08 = 0;
    }
}

void func_0210bc14(void) {
    __clear(data_0217cd30, 0x17 * sizeof(Unk0217cd30));
}

u32 func_0210bc00(u32 rowIndex, u32 columnIndex, void *entries) {
    u32 value0 = rowIndex;
    u32 value1 = columnIndex;
    u32 value2 = (u32) entries;
    u32 table;
    table = (u32) &data_0217cd30;
    value0 = (table) + ((value0 << 5));
    *(u32 *) ((value0) + ((value1 << 2))) = value2;
    return value0;
}

u32 func_0210bbec(u32 rowIndex, u32 columnIndex, Unk0216c860 *entries) {
    u32 value0 = rowIndex;
    u32 value1 = columnIndex;
    u32 value2 = (u32) entries;
    u32 table;
    table = (u32) &data_0217cd30;
    value0 = (table) + ((value0 << 5));
    *(u32 *) ((value0) + ((value1 << 2))) = value2;
    return value0;
}

u32 GetSurfaceSoundId(s32 entryIndex, s32 surfaceKind, s32 surfaceVariant) {
    s32 idArray;
    s32 v;

    idArray = ((Unk0217cd30 *) data_0217cd30)[surfaceKind].mUnk_00[surfaceVariant];
    v = idArray != 0 ? ((u32 *) idArray)[entryIndex] : 0xffff;
    if (v != 0xffff) {
        return (u16) v;
    }
    v = data_0215a6fc[surfaceKind][surfaceVariant];
    if (v == 0x14) {
        v = 0xffff;
    }
    if (v == 0xffff) {
        return 0xffff;
    }
    return *(u16 *) (data_0216ca84 + entryIndex * 0x26 + v * 2);
}

u32 func_0210bafc(s32 entryIndex, s32 rowIndex, s32 columnIndex) {
    s32 idArray;
    s32 v;

    idArray = ((Unk0217cd30 *) data_0217cd30)[rowIndex].mUnk_00[columnIndex];
    v = idArray != 0 ? ((u32 *) idArray)[entryIndex] : 0xffff;
    if (v != 0xffff) {
        return (u16) v;
    }
    v = data_0215a6fc[rowIndex][columnIndex];
    if (v == 0xe) {
        v = 0xffff;
    }
    if (v == 0xffff) {
        return 0xffff;
    }
    return *(u16 *) (data_0216ca68 + entryIndex * 0x1a + v * 2);
}
