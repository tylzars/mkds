#include "Main/Unknown/code_02007478.h"
#include "Main/Unknown/code_0200c0d8.h"
#include "Main/Unknown/unk_0216f000.h"
#include "code_0214d018.h"

#pragma thumb on

u32 func_020074d8(void) {
    Unk020074d8_msg message;
    u8 v2[16];
    u16 child;
    u32 v4;
    u16 childMask;
    u8 v6;
    Unk0216fdac *work;
    u8 v8;
    u8 *v9;
    childMask = 0;
    v4 = -1;
    MI_CpuFill8(v2, 0, 16);
    child = 1;
    work = data_0216fdac;
    for (; child <= 15; child++) {
        if (work->mUnk_14e8[child - 1] == 5) {
            v2[work->mUnk_1526[child - 1]]++;
        }
    }
    v6 = data_usa_02161784;
    v8 = 0;
    do {
        v6 = (v6 + 1) % 16;
        if ((OFFSET_PTR(Unk0216fdac, work, v6 * 0x5d4))->mUnk_1d52 != 0 && v2[v6] != 0) {
            v4 = (s8) v6;
            break;
        }
        v8++;
    } while (v8 < 16);
    if (v4 == -1) {
        return 21;
    }
    data_usa_02161784 = v4;
    for (child = 1; child <= 15; child++) {
        if (work->mUnk_14e8[child - 1] == 5 && v4 == work->mUnk_1526[child - 1]) {
            childMask |= 1 << child;
        }
    }
    message.mUnk_00 = 3;
    message.mUnk_02 = v4;
    v9 = WriteParentMessage((u8 *) &message, (u8 *) work);
    if (v9 != NULL) {
        MI_CpuCopy8(data_0216fdac->mUnk_1788 + v4 * 0x5d4, v9, 0xe4);
    }
    return func_02008908(0xea, childMask, *(u32 *) &data_0216fdac);
}

void LoadDataRange(Unk02007478 *job) {
    DataRange *range;
    DataRangeTable *table;
    FSFile file;
    u32 offset;
    range = job->mDataRange;
    table = job->mDataRangeTable;
    FS_InitFile(&file);
    offset = range->mOffset;
    if (FS_OpenFileDirect(&file, FS_FindArchive(table->mUnk_10, table->mUnk_14), offset, offset + range->mSize, -1) !=
        0) {
        if (range->mSize == FS_ReadFile(&file, range->mData, range->mSize)) {
            range->mUnk_0c = 2;
        }
        FS_CloseFile(&file);
    }
    if (range->mUnk_0c != 2) {
        OS_Terminate();
    }
}

#pragma thumb off
